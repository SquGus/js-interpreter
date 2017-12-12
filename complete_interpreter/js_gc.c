/*
 *	js_gc -> Slotted memory management and mark-sweep garbage collection
 */

#include <stddef.h>
#include <time.h>

#include "js_gc.h"
#include "js_debug.h"

#ifdef JS_GC_PROFILE
#define GC_PRINT(indent, ...) printf("%*s", indent, ""); printf(__VA_ARGS__)
#define GC_DEBUG(indent, val) js_debug(stdout, val, indent, true)
#else
#define GC_PRINT(indent, ...)
#define GC_DEBUG(indent, val)
#endif

#ifdef JS_GC_PROFILE_VERBOSE
#define GC_PRINT_VERBOSE(indent, ...) GC_PRINT(indent, ...)
#define GC_DEBUG_VERBOSE(indent, val) GC_DEBUG(indent, val)
#else
#define GC_PRINT_VERBOSE(indent, ...)
#define GC_DEBUG_VERBOSE(indent, val)
#endif

/* GC Overview
 *
 * Bi-color, non-incremental, mark & sweep, stop-the-world garbage collection.
 *
 * Arenas
 * ------
 * The global state object keeps an array of pointers to arenas – big
 * contiguous blocks of memory which are slotted to hold js_interpreters's js_val
 * structs. The arena size is determined by the SLOTS_PER_ARENA define. The
 * size is then that number of slots multiplied by the size of a js_val struct.
 * The system will create arenas on demand, when space cannot be freed from an
 * existing arena, and the MAX_ARENAS define has not been exceeded.
 *
 * At the start of each arena is a metadata section which stores usage
 * information and the list of vacant slots.
 *
 * Allocation
 * ----------
 *
 * Mark Phase
 * ----------
 *
 * Sweep Phase
 * -----------
 *
 * Issues & Enhancement Ideas
 * --------------------------
 * - Arena free lists should be bitmaps. Integer arrays are a huge waste of
 *   space.
 * - Store the color (e.g. black or white) of the js_val instead of explicitly
 *   labeling them marked or unmarked. Then we can flip the color semantics
 *   after each run and save some time unmarking.
 * - Tri- or quad-color incremental algorithm a la LuaJIT.
 * - Utility structs (e.g. js_args, js_prop, eval_state, ast_nodes) need to be
 *   garbage collected or freed by hand, whichever is more appropriate.
 * - Strings need to be stored within the arena somehow. Maybe they can be
 *   broken into js_val-sized pieces and be read and written to through an API
 *   that handles any needed reassembly.
 */


static gc_arena *js_new_arena() {
  gc_arena *arena = malloc(sizeof(gc_arena));

  arena->num_slots = SLOTS_PER_ARENA;
  arena->used_slots = 0;

  memset(arena->freelist, 0, sizeof(arena->freelist));
  return arena;
}

static gc_arena *js_get_arena() {
  // Currently 1 arena, but room for more.
  gc_arena *arena = NULL;
  if (js->gc_num_arenas == 0) {
    arena = js_new_arena();
    js->gc_arenas[0] = arena;
    js->gc_num_arenas++;
  }
  else
    arena = js->gc_arenas[0];
  return arena;
}

js_val *js_malloc(bool first_attempt) {
  if (js->gc_state != GC_STATE_NONE) {
    fprintf(stderr, "Error: politely refusing to allocate during garbage collection");
    exit(EXIT_FAILURE);
  }

  gc_arena *arena = js_get_arena();
  int i;
  for (i = 0; i < arena->num_slots; i++) {
    if (!arena->freelist[i]) {
      arena->freelist[i] = true;
      arena->used_slots++;
      return &arena->slots[i];
    }
  }
  if (first_attempt) {
    js_gc();
    return js_malloc(false);
  }
  fprintf(stderr, "Error: process out of memory");
  exit(EXIT_FAILURE);
  UNREACHABLE();
}

static void js_gc_debug() {
#ifdef JS_GC_PROFILE

  gc_state state = js->gc_state;
  long clockt = clock() / (CLOCKS_PER_SEC / 1000);

  if (state == GC_STATE_STARTING) {
    puts("GC: starting");
    js->gc_last_start = clockt;
    js->gc_runs++;
  }
  if (state == GC_STATE_MARK) {
    puts("GC: mark phase");
  }
  if (state == GC_STATE_SWEEP) {
    puts("GC: sweep phase");
  }
  if (state == GC_STATE_NONE) {
    long delta = clockt - js->gc_last_start;
    printf("GC: finished|inactive (last run: %ld ms)\n", delta);
    js->gc_time += delta;
  }

  long total_slots = 0, used_slots = 0;
  int i;
  for (i = 0; i < js->gc_num_arenas; i++) {
    total_slots += js->gc_arenas[i]->num_slots;
    used_slots += js->gc_arenas[i]->used_slots;
  }

  printf(
    "  %ld slots | %ld/%ld used slots | %ld/%ld vacant slots | %ld usage KB | %d runs\n",
    total_slots,
    used_slots, total_slots,
    total_slots - used_slots, total_slots,
    (total_slots * sizeof(js_val)) / 1000,
    js->gc_runs
  );

#endif
}

static void js_gc_debug_arena(gc_arena *arena) {
#ifdef JS_GC_PROFILE_VERBOSE
  for (int i = 0; i < arena->num_slots; i++) {
    printf("slot[%4d]: (USED %d) (MARKED %d)\n", i, arena->freelist[i], arena->freelist[i] && arena->slots[i].marked);
  }
#endif
}

static void js_gc_mark(js_val *val, int depth) {
  if (val && val->flagged) puts("Attempting to mark flagged val");
  if (!val || val->marked) return;

  val->marked = true;

  GC_DEBUG_VERBOSE(depth, val);

  GC_PRINT_VERBOSE(depth, "Marking prototype\n");
  js_gc_mark(val->proto, depth + 1);

  if (IS_OBJ(val)) {
    GC_PRINT_VERBOSE(depth, "Marking primitive\n");
    js_gc_mark(val->object.primitive, depth + 1);

    GC_PRINT_VERBOSE(depth, "Marking bound this\n");
    js_gc_mark(val->object.bound_this, depth + 1);

    GC_PRINT_VERBOSE(depth, "Marking scope\n");
    js_gc_mark(val->object.scope, depth + 1);

    GC_PRINT_VERBOSE(depth, "Marking instance\n");
    js_gc_mark(val->object.instance, depth + 1);

    GC_PRINT_VERBOSE(depth, "Marking parent\n");
    js_gc_mark(val->object.parent, depth + 1);
  }

  if (val->map) {
    js_prop *prop;
    OBJ_ITER(val, prop) {
      if (prop->ptr && !prop->circular) {
        GC_PRINT_VERBOSE(depth, "Marking %s\n", prop->name);
        js_gc_mark(prop->ptr, depth + 1);
      }
    }
  }
}

static void js_gc_free_val(js_val *val) {
  // Free any strings (dynamically alloc-ed outside slots)
  if (IS_STR(val) && val->string.ptr != NULL) {
    free(val->string.ptr);
  }

  memset(val, 0, sizeof(js_val));
}

static void js_gc_sweep(gc_arena *arena) {
  js_val val;
  int sweeped_count = 0;
  for (int i = 0; i < arena->num_slots; i++) {
    if (!arena->freelist[i]) return;
    val = arena->slots[i];
    if (!val.marked) {
      if (val.flagged) puts("GC: freeing flagged val");
      arena->freelist[i] = false;
      js_gc_free_val(&val);
      arena->used_slots--;
      sweeped_count++;
    } else {
      arena->slots[i].marked = false;
    }
  }
}

void js_gc()
{
  gc_arena *arena = js_get_arena();

  js_gc_debug_arena(arena);

  // Start
  js->gc_state = GC_STATE_STARTING;
  js_gc_debug();

  // Mark
  js->gc_state = GC_STATE_MARK;
  js_gc_mark(js->global, 0);
  if (js->callstack) {
    eval_state *top = js->callstack;
    while (top) {
      js_gc_mark(top->scope, 0);
      top = top->parent;
    }
  }
  js_gc_debug();

  // Sweep
  js->gc_state = GC_STATE_SWEEP;
  js_gc_sweep(arena);
  js_gc_debug();

  // Stop
  js->gc_state = GC_STATE_NONE;
  js_gc_debug();

  js_gc_debug_arena(arena);
}
