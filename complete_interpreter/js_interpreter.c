/*
 * js_intepreter -> Core types, constructors, casting, and debug.
 */

#include <math.h>

#include "js_interpreter.h"
#include "js_props.h"
#include "js_debug.h"
#include "js_string.h"
#include "js_gc.h"
#include "js_eval.h"
#include "js_args.h"


// ----------------------------------------------------------------------------
// Value Constructors
// ----------------------------------------------------------------------------

js_val * js_new_val(js_type type) {
  js_val *val = js_malloc(true);

  val->map = NULL;
  val->type = type;
  val->signal = S_NONE;
  val->proto = NULL;
  val->marked = false;
  val->flagged = false;

  return val;
}

js_val * js_new_number(double x, bool is_nan, bool is_inf, bool is_neg) {
  js_val *val = js_new_val(T_NUMBER);

  if (isnan(x))
    is_nan = true;
  if (isinf(x)) {
    is_inf = true;
    is_neg = x < 0;
  }

  val->number.val = x;
  val->number.is_nan = is_nan;
  val->number.is_inf = is_inf;
  val->number.is_neg = is_neg;
  val->proto = js_try_get_proto("Number");

  return val;
}

js_val * js_new_string(char *x) {
  js_val *val = js_new_val(T_STRING);

  val->string.ptr = malloc((strlen(x) + 1) * sizeof(char));
  val->string.ptr[strlen(x)] = '\0';
  strcpy(val->string.ptr, x);
  js_set_len(val, strlen(x));
  val->proto = js_try_get_proto("String");

  return val;
}

js_val *js_new_boolean(bool x) {
  js_val *val = js_new_val(T_BOOLEAN);

  val->boolean.val = x;
  val->proto = js_try_get_proto("Boolean");

  return val;
}

js_val *js_new_object() {
  js_val *val = js_new_val(T_OBJECT);

  js_set_class(val, "Object");
  val->object.length = 0;
  val->object.extensible = false;
  val->object.parent = NULL;
  val->object.primitive = NULL;
  val->object.bound_this = NULL;
  val->object.bound_args = NULL;
  val->object.scope = NULL;
  val->object.instance = NULL;
  val->object.node = NULL;
  val->proto = js->object_proto;

  return val;
}

js_val *js_new_array() {
  js_val *val = js_new_object();

  js_set_class(val, "Array");
  js_set_len(val, 0);
  val->proto = js->array_proto;

  return val;
}

js_val *js_new_function(struct ast_node *node) {
  js_val *val = js_new_object();

  js_set_class(val, "Function");
  js_set_prop(val, "prototype", JSOBJ(), P_WRITE);

  js_set(val, "name", JSSTR(""));
  js_set(val, "arguments", JSNULL());
  js_set(val, "caller", JSNULL());

  val->object.native = false;
  val->object.provide_this = false;
  val->object.generator = false;
  val->object.node = node;
  val->object.scope = NULL;
  val->object.instance = NULL;
  val->object.bound_this = NULL;
  val->object.bound_args = NULL;
  val->proto = js->function_proto;

  // Set the function length. Native functions must do this manually.
  js_set_len(val, (node && node->e1) ? node_count(node->e1) : 0);

  return val;
}

js_val *js_new_native_function(js_native_function func, int length){
  js_val *val = js_new_function(NULL);

  val->object.native = true;
  val->object.nativefn = func;
  js_set_len(val, length);

  return val;
}

js_val *js_new_regexp(char *re) {
  js_val *val = js_new_val(T_OBJECT);

  val->proto = js_try_get_proto("RegExp");

  // Process the trailing options: re = /pattern/[imgy]{0,4}
  int i = strlen(re) - 1;
  while (re[i] != '/' && i > 0) {
    switch (re[i]) {
      case 'g': js_set(val, "global", JSBOOL(1)); break;
      case 'i': js_set(val, "ignoreCase", JSBOOL(1)); break;
      case 'm': js_set(val, "multiline", JSBOOL(1)); break;
      case 'y': js_set(val, "sticky", JSBOOL(1)); break;
    }
    i--;
  }

  // Store the inner pattern
  if (i > 1)
    js_set(val, "source", JSSTR(js_str_slice(re, 1, i)));

  js_set_class(val, "RegExp");
  return val;
}

js_val *js_new_error(char *name, const char *tpl, ...) {
  js_val *val = js_new_val(T_OBJECT);
  val->proto = js_try_get_proto("Error");
  js_set_class(val, "Error");

  va_list ap;

  // Multiple va_list traversals
  // First figure out size
  va_start(ap, tpl);
  size_t size = vsnprintf(NULL, 0, tpl, ap);
  va_end(ap);

  char *msg = malloc(size + 1);
  msg[size] = '\0';

  // Now build the error message
  va_start(ap, tpl);
  vsnprintf(msg, size + 1, tpl, ap);
  va_end(ap);

  js_set(val, "name", JSSTR(name));
  js_set(val, "message", JSSTR(msg));
  return val;
}

js_prop *js_new_prop(js_prop_flags flags) {
  js_prop *prop = malloc(sizeof(js_prop));

  prop->writable = flags & P_WRITE;
  prop->configurable = flags & P_CONF;
  prop->enumerable = flags & P_ENUM;
  prop->circular = false;
  prop->ptr = NULL;

  return prop;
}

void js_pop_state() {
  if (js->callstack) {
    eval_state *pop = js->callstack;
    js->callstack = pop->parent;
    free(pop);
  }
}

void js_push_state(eval_state *state) {
  state->parent = js->callstack;
  js->callstack = state;
}

eval_state *js_new_state(int line, int column) {
  eval_state *state = malloc(sizeof(eval_state));
  memset(state, 0, sizeof(eval_state));

  state->line = line;
  state->column = column;
  state->caller_info = NULL;
  state->script_name = js->script_name;

  state->ctx = NULL;
  state->this = NULL;
  state->scope = NULL;
  state->parent = NULL;
  state->construct = false;
  state->catch = false;

  return state;
}

js_state *js_new_global_state() {
  js_state *state = malloc(sizeof(js_state));

  state->gc_state = GC_STATE_NONE;
  memset(state->gc_arenas, 0, sizeof(state->gc_arenas));
  state->gc_num_arenas = 0;
  state->gc_runs = 0;
  state->gc_time = 0;
  state->gc_last_start = 0;

  state->global = NULL;
  state->function_proto = NULL;
  state->object_proto = NULL;
  state->callstack = NULL;

  state->script_name = "main";

  state->opt_interactive = false;
  state->opt_print_tokens = false;
  state->opt_print_ast = false;
  state->opt_keep_history_file = true;
  state->opt_history_filename = ".js_intepreter_history";

  return state;
}


// ----------------------------------------------------------------------------
// Value Checks & Casting
// ----------------------------------------------------------------------------

bool js_is_callable(js_val *val) {
  return IS_FUNC(val);
}

js_val *js_to_primitive(js_val *val, js_type hint) {
  if (!IS_OBJ(val)) return val;

  // This is the [[DefaultValue]] implementation.
  //
  // We'll look for the 'valueOf' and 'toString' props, using the hint to
  // determine that order, and return with the result of calling the first of
  // them that is callable, or a type error otherwise.

  js_val *maybe_func, *res;
  js_args *args;
  char *types[2] = {"valueOf", "toString"};
  int reverse = hint == T_STRING;

  // Without a hint, objects default to Number, except Date
  if (hint == 0 && IS_DATE(val))
    reverse = true;

  int i;
  for (i = reverse; i <= 1 && i >= 0; reverse ? i-- : i++) {
    maybe_func = js_get_proto(val, types[i]);
    if (js_is_callable(maybe_func)) {
      args = args_new();
      res = js_call(js->global, val, maybe_func, args);
      if (!IS_OBJ(res)) return res;
    }
  }
  js_throw(NULL, js_new_error(E_TYPE, "cannot convert %s to primitive", js_typeof(val)));
  UNREACHABLE();
}

js_val * js_to_number(js_val *val) {
  if (IS_UNDEF(val)) return JSNAN();
  if (IS_NULL(val)) return JSNUM(0);
  if (IS_BOOL(val)) {
    if (val->boolean.val == 0) return JSNUM(0);
    return JSNUM(1);
  }
  if (IS_STR(val)) {
    char *err;
    double d = strtod(val->string.ptr, &err);
    if (*err != 0) return JSNAN();
    return JSNUM(d);
  }
  if (IS_OBJ(val))
    return js_to_number(js_to_primitive(val, T_NUMBER));

  return val;
}

js_val *js_to_int(js_val *val) {
  long long int_val;

  val = js_to_number(val);
  if (IS_NAN(val))
    return JSNUM(0);
  if (IS_INF(val) || val->number.val == 0)
    return val;
  int sign = val->number.val < 0 ? -1 : 1;
  int_val = sign * floor(fabs(val->number.val));
  return JSNUM(int_val);
}

js_val *js_to_int32(js_val *val) {
  long long int32_bit = js_to_uint32(val)->number.val;

  if (int32_bit >= pow(2, 31))
    return JSNUM(int32_bit - pow(2, 32));
  return JSNUM(int32_bit);
}

js_val *js_to_uint32(js_val *val) {
  long long pos_int, int32_bit;

  val = js_to_number(val);
  if (IS_NAN(val) || IS_INF(val) || val->number.val == 0)
    return JSNUM(0);

  int sign = val->number.val < 0 ? -1 : 1;
  pos_int = sign * floor(fabs(val->number.val));
  int32_bit = fmod(pos_int, pow(2, 32));

  return JSNUM(int32_bit);
}

js_val *js_to_string(js_val *val) {
  if (IS_UNDEF(val)) return JSSTR("undefined");
  if (IS_NULL(val)) return JSSTR("null");
  if (IS_BOOL(val)) {
    if (val->boolean.val == 1) return JSSTR("true");
    return JSSTR("false");
  }
  if (IS_NUM(val)) {
    // TODO: check spec
    if (val->number.is_nan) return JSSTR("NaN");
    if (val->number.is_inf) return JSSTR("Infinity");
    char *fmt = "%f";
    if (fmod(val->number.val, 1) == 0)
      fmt = "%.0f";
    if (fabs(val->number.val) > 1e21)
      fmt = "%g";
    int size = snprintf(NULL, 0, fmt, val->number.val) + 1;
    char *num = malloc(size);
    snprintf(num, size, fmt, val->number.val);
    num[size - 1] = '\0';
    return JSSTR(num);
  }
  if (IS_OBJ(val))
    return js_to_string(js_to_primitive(val, T_STRING));

  return val;
}

js_val *js_to_object(js_val *val) {
  if (IS_UNDEF(val) || IS_NULL(val))
    js_throw(NULL, js_new_error(E_TYPE, "cannot convert %s to object", js_typeof(val)));
  if (IS_OBJ(val))
    return val;

  js_val *obj = JSOBJ();
  obj->object.primitive = val;
  if (IS_BOOL(val)) {
    js_set_class(obj, "Boolean");
    obj->proto = js_try_get_proto("Boolean");
  }
  if (IS_NUM(val)) {
    js_set_class(obj, "Number");
    obj->proto = js_try_get_proto("Number");
  }
  if (IS_STR(val)) {
    js_set_class(obj, "String");
    obj->proto = js_try_get_proto("String");
  }
  return obj;
}

js_val *js_to_boolean(js_val *val) {
  if (IS_UNDEF(val) || IS_NULL(val))
    return JSBOOL(0);
  if (IS_NUM(val))
    return JSBOOL(!IS_NAN(val) && val->number.val != 0);
  if (IS_STR(val))
    return JSBOOL(val->string.length != 0);
  if (IS_OBJ(val))
    return JSBOOL(1);
  return val;
}

js_val *js_cast(js_val *val, js_type type) {
  if (val->type == type) return val;

  switch (type) {
    case T_NULL: return JSNULL();
    case T_UNDEF: return JSUNDEF();
    case T_STRING: return js_to_string(val);
    case T_NUMBER: return js_to_number(val);
    case T_BOOLEAN: return js_to_boolean(val);
    default: return js_to_object(val);
  }
}


// ----------------------------------------------------------------------------
// Error Handling
// ----------------------------------------------------------------------------

void js_throw(eval_state *state, js_val *error) {
  // Search the callstack for a catch
  eval_state *tmp = state;
  while(tmp != NULL) {
    if (tmp->catch) {
      js_set(tmp->ctx, "JS_LAST_ERROR", error);

      // Pop all frames up to and including the catch.
      while (js->callstack != tmp)
        js_pop_state();
      js_pop_state();

      longjmp(tmp->jmp, 1);
      UNREACHABLE();
    }
    tmp = tmp->parent;
  }

  fprintf(stderr, "%s\n", TO_STR(js_to_primitive(error, T_STRING))->string.ptr);

  while (state != NULL) {
    if (state->caller_info)
      fprintf(stderr, "  at %s in %s:%u:%u\n",
          state->caller_info, state->script_name, state->line, state->column);
    else
      fprintf(stderr, "  at %s:%u:%u\n",
          state->script_name, state->line, state->column);
    if (!state->parent) break;
    state = state->parent;
  }

  // Catch errors within REPL: clear callstack and start over.
  if (js->opt_interactive) {
    js->callstack = NULL;
    longjmp(js->repl_jmp, 1);
  }
  exit(1);
}


// ----------------------------------------------------------------------------
// Utilities
// ----------------------------------------------------------------------------

char *js_typeof(js_val *value) {
  /* Per Table 20 of the ECMA5 spec: */
  switch (value->type) {
    case T_OBJECT:
    case T_NULL:
      return IS_FUNC(value) ? "function" : "object";
    case T_BOOLEAN:
      return "boolean";
    case T_NUMBER:
      return "number";
    case T_STRING:
      return "string";
    default:
      return "undefined";
  }
}

js_val *js_has_instance(js_val *func, js_val *val) {
  if (!IS_FUNC(func))
    js_throw(NULL, js_new_error(E_TYPE, "%s is not a function", js_typeof(func)));
  js_val *fproto = js_get(func, "prototype");
  if (!IS_UNDEF(fproto) && IS_OBJ(val)) {
    js_val *proto = val->proto;
    while (proto) {
      if (proto == fproto)
        return JSBOOL(1);
      proto = proto->proto;
    }
  }
  return JSBOOL(0);
}

js_val *js_implicit_this_value(js_val *obj) {
  return obj->object.provide_this ? obj->object.bound_this : JSUNDEF();
}

js_val *js_has_property(js_val *obj, char *prop) {
  js_val *val = js_get_proto(obj, prop);
  return JSBOOL(!IS_UNDEF(val));
}

js_val *js_try_get_proto(char *type) {
  // Try to avoid a lookup.
  if (STREQ(type, "Function") && js->function_proto)
    return js->function_proto;
  if (STREQ(type, "Object") && js->object_proto)
    return js->object_proto;
  if (STREQ(type, "Array") && js->array_proto)
    return js->array_proto;

  js_val *global = js->global;
  if (global != NULL) {
    js_val *obj = js_get(global, type);
    if (!IS_UNDEF(obj))
      return js_get(obj, "prototype");
  }
  return NULL;
}

void js_set_len(js_val *val, unsigned long len) {
  if (IS_STR(val))
    val->string.length = len;
  if (IS_ARR(val))
    val->object.length = len;
  js_set_prop(val, "length", JSNUM(len), 0);
}

void js_set_class(js_val *obj, char *class) {
  strcpy(obj->object.class, class);
}
