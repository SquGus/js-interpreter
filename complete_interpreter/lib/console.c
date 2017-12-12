// console.c
// ---------
// Native implementations for the `console` property of the global object.

#include <time.h>

#include "console.h"
#include "Date.h"

// console.log(obj1[, obj2, ..., objN])
js_val *
console_log(js_val *instance, js_args *args, eval_state *state)
{
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    js_debug(stdout, ARG(args, i), 0, 1);
  return JSUNDEF();
}

// console.error(obj1[, obj2, ..., objN])
js_val *
console_error(js_val *instance, js_args *args, eval_state *state)
{
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    js_debug(stderr, ARG(args, i), 0, 1);
  return JSUNDEF();
}

// console.info(obj1[, obj2, ..., objN])
js_val *
console_info(js_val *instance, js_args *args, eval_state *state)
{
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    js_debug_verbose(stdout, ARG(args, i), 0);
  return JSUNDEF();
}

// console.assert(expression)
js_val *
console_assert(js_val *instance, js_args *args, eval_state *state)
{
  // Non-standard, found in new Webkit builds and Firebug
  if (TO_BOOL(ARG(args, 0))->boolean.val)
    return JSUNDEF();
  js_throw(state, js_new_error("AssertionError", "assertion failed"));
  UNREACHABLE();
}

// console.time(name)
js_val *
console_time(js_val *instance, js_args *args, eval_state *state)
{
  js_val *name = TO_STR(ARG(args, 0));
  js_val *timers = js_get(instance, "__timers__");
  if (IS_UNDEF(timers)) {
    timers = JSOBJ();
    js_set(instance, "__timers__", timers);
  }
  js_set(timers, name->string.ptr, JSNUM(utc_now()));
  return JSUNDEF();
}

// console.timeEnd(name)
js_val *
console_time_end(js_val *instance, js_args *args, eval_state *state)
{
  js_val *name = TO_STR(ARG(args, 0));
  js_val *timers = js_get(instance, "__timers__");
  if (IS_OBJ(timers)) {
    js_val *timer = js_get(timers, name->string.ptr);
    if (IS_NUM(timer)) {
      long old = timer->number.val;
      long cur = utc_now();
      fprintf(stdout, "%s: %ldms\n", name->string.ptr, cur - old);
    }
    js_del_prop(timers, name->string.ptr);
  }
  return JSUNDEF();
}

js_val *
bootstrap_console()
{
  js_val *console = JSOBJ();

  DEF(console, "log", JSNFUNC(console_log, 1));
  DEF(console, "error", JSNFUNC(console_error, 1));
  DEF(console, "info", JSNFUNC(console_info, 1));
  DEF(console, "assert", JSNFUNC(console_assert, 1));
  DEF(console, "time", JSNFUNC(console_time, 1));
  DEF(console, "timeEnd", JSNFUNC(console_time_end, 1));

  js_attach_prototype(console, js->function_proto);

  return console;
}
