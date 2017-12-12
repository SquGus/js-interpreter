/*
 *	js_gc -> Slotted memory management and mark-sweep garbage collection
 */

#ifndef JS_GC_H
#define JS_GC_H

#include "js_interpreter.h"

#define SLOTS_PER_ARENA 10000

typedef struct gc_arena {
  int num_slots;
  int used_slots;
  bool freelist[SLOTS_PER_ARENA];
  js_val slots[SLOTS_PER_ARENA];
} gc_arena;

js_val *js_malloc(bool);
void js_gc(void);

#endif
