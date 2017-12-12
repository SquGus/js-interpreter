// RegExp.c
// --------

#include "RegExp.h"


// ----------------------------------------------------------------------------
// RegExp Constructor
// ----------------------------------------------------------------------------

// [new] RegExp(pattern)
js_val *
regexp_new(js_val *instance, js_args *args, eval_state *state)
{
  // TODO: Could this be done with js_new_regexp?
  js_val *pattern = ARG(args, 0);
  js_val *flags = ARG(args, 1);

  js_val *regexp = JSOBJ();

  js_set_class(regexp, "RegExp");
  js_set(regexp, "source", IS_UNDEF(pattern) ? JSSTR("(?:)") : TO_STR(pattern));

  if (ARGLEN(args) <= 1)
    return regexp;
  if (!IS_STR(flags))
    js_throw(state, js_new_error(E_TYPE, "Invalid flags supplied to RegExp constructor"));
  int i, n;
  for (i = 0, n = strlen(flags->string.ptr); i < n; i++) {
    switch (flags->string.ptr[i]) {
      case 'g': js_set(regexp, "global", JSBOOL(1)); break;
      case 'i': js_set(regexp, "ignoreCase", JSBOOL(1)); break;
      case 'm': js_set(regexp, "multiline", JSBOOL(1)); break;
      case 'y': js_set(regexp, "sticky", JSBOOL(1)); break;
    }
  }

  regexp->proto = js_try_get_proto("RegExp");
  return regexp;
}


// ----------------------------------------------------------------------------
// RegExp Prototype
// ----------------------------------------------------------------------------

// RegExp.prototype.exec(str)
js_val *
regexp_proto_exec(js_val *instance, js_args *args, eval_state *state)
{
  js_val *pattern = js_get_proto(instance, "source"),
         *last_ind = js_get_proto(instance, "lastIndex"),
         *str = TO_STR(ARG(args, 0));

  bool global   = js_get_proto(instance, "global")->boolean.val;
  bool caseless = js_get_proto(instance, "ignoreCase")->boolean.val;

  bool matched = false;
  int *matches = NULL;

  int count;
  int length = strlen(str->string.ptr);
  int i = js_to_int32(last_ind)->number.val;

  if (!global)
    i = 0;

  while (!matched) {
    if (i < 0 || i > length) {
      js_set(instance, "lastIndex", JSNUM(0));
      free(matches);
      return JSNULL();
    }
    matches = js_regexp(str->string.ptr, pattern->string.ptr, &count, i, caseless);
    if (count == 0)
      i++;
    else
      matched = true;
  }

  char *substr = js_str_slice(str->string.ptr, matches[0], matches[1]);

  if (global)
    js_set(instance, "lastIndex", JSNUM(matches[1]));

  js_val *res = JSARR();

  js_set(res, "index", JSNUM(matches[0]));
  js_set(res, "input", str);

  js_set(res, "0", JSSTR(substr));

  for (i = 1; i <= count; i++) {
    substr = js_str_slice(str->string.ptr, matches[2*i], matches[2*i+1]);
    js_set(res, JSNUMKEY(i)->string.ptr, JSSTR(substr ? substr : ""));
  }

  free(matches);
  js_set_len(res, count);

  return res;
}

// RegExp.prototype.test([str])
js_val *
regexp_proto_test(js_val *instance, js_args *args, eval_state *state)
{
  char *str = TO_STR(ARG(args, 0))->string.ptr;
  char *pattern = TO_STR(js_get(instance, "source"))->string.ptr;
  bool caseless = js_get_proto(instance, "ignoreCase")->boolean.val;
  int count;
  js_regexp(str, pattern, &count, 0, caseless);
  return JSBOOL(count > 0);
}

// RegExp.prototype.toString()
js_val *
regexp_proto_to_string(js_val *instance, js_args *args, eval_state *state)
{
  js_val *pattern = js_get_proto(instance, "source"),
         *g = js_get_proto(instance, "global"),
         *i = js_get_proto(instance, "ignoreCase"),
         *m = js_get_proto(instance, "multiline"),
         *y = js_get_proto(instance, "sticky");

  size_t size = strlen(pattern->string.ptr) + 7; // space for 2 slashes and imgy
  char *new = malloc(size);
  snprintf(
    new,
    size,
    "/%s/%s%s%s%s",
    pattern->string.ptr,
    g->boolean.val ? "g" : "",
    i->boolean.val ? "i" : "",
    m->boolean.val ? "m" : "",
    y->boolean.val ? "y" : ""
  );

  js_val *res = JSSTR(new);
  free(new);
  return res;
}

js_val *
bootstrap_regexp()
{
  js_val *regexp = JSNFUNC(regexp_new, 2);
  js_val *prototype = JSOBJ();
  prototype->proto = js->object_proto;

  // RegExp
  // ------

  // Properties
  DEF(regexp, "prototype", prototype);

  // RegExp.prototype
  // ----------------

  // Properties
  DEF(prototype, "constructor", JSNFUNC(regexp_new, 2));
  DEF2(prototype, "global", JSBOOL(0), P_NONE);
  DEF2(prototype, "ignoreCase", JSBOOL(0), P_NONE);
  DEF2(prototype, "lastIndex", JSBOOL(0), P_WRITE);
  DEF2(prototype, "multiline", JSBOOL(0), P_NONE);
  DEF2(prototype, "source", JSSTR(""), P_NONE);
  DEF2(prototype, "sticky", JSBOOL(0), P_NONE);

  // Methods
  DEF(prototype, "exec", JSNFUNC(regexp_proto_exec, 1));
  DEF(prototype, "test", JSNFUNC(regexp_proto_test, 1));
  DEF(prototype, "toString", JSNFUNC(regexp_proto_to_string, 0));

  js_attach_prototype(prototype, js->function_proto);

  return regexp;
}
