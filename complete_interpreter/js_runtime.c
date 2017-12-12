/*
 *	js_runtime -> Bootstrap global object and other stuff
 */

#include <math.h>
#include <unistd.h>
#include <ctype.h>

#include "js_runtime.h"
#include "lib/console.h"
#include "lib/gc.h"
#include "lib/Math.h"
#include "lib/Object.h"
#include "lib/Function.h"
#include "lib/Array.h"
#include "lib/String.h"
#include "lib/Number.h"
#include "lib/Boolean.h"
#include "lib/Date.h"
#include "lib/RegExp.h"
#include "lib/Error.h"


// isNaN(value)
js_val *global_is_nan(js_val *instance, js_args *args, eval_state *state) {
  js_val *num = TO_NUM(ARG(args, 0));
  return JSBOOL(num->number.is_nan);
}

// isFinite(number)
js_val *global_is_finite(js_val *instance, js_args *args, eval_state *state) {
  js_val *num = TO_NUM(ARG(args, 0));
  return JSBOOL(!(num->number.is_nan || num->number.is_inf));
}

/* Returns the numeric value (0-35) of a given alphanumeric character, or 36
 * if the character is not alphanumeric. */
static unsigned radix_val(char x) {
  if (x >= '0' && x <= '9') return x - '0';
  if (x >= 'a' && x <= 'z') return 10 + (x - 'a');
  if (x >= 'A' && x <= 'Z') return 10 + (x - 'A');
  return 36;
}

static char *slice_with_free(char *input, unsigned start, unsigned end) {
  char *tmp = input;
  input = js_str_slice(input, start, end);
  free(tmp);
  return input;
}

// parseInt(string[, radix])
js_val *global_parse_int(js_val *instance, js_args *args, eval_state *state) {
  char *input = TO_STR(ARG(args, 0))->string.ptr;
  js_val *radix = TO_INT32(ARG(args, 1));

  int sign = 1;
  unsigned len = strlen(input);
  unsigned offset = 0;

  while (isspace(input[offset]) && offset < len)
    offset++;
  char *s = js_str_slice(input, offset, len);
  len = strlen(s);
  if (len > 0 && s[0] == '-')
    sign = -1;
  if (len > 0 && (s[0] == '-' || s[0] == '+')) {
    s = slice_with_free(s, 1, len);
    len = strlen(s);
  }

  bool strip_prefix = true;
  unsigned r = 10;
  if (radix->number.val != 0) {
    if (radix->number.val < 2 || radix->number.val > 32)
      return JSNAN();
    if (radix->number.val != 16)
      strip_prefix = false;
    r = radix->number.val;
  }

  if (strip_prefix) {
    if (len >= 2 && s[0] == '0' && (s[1] == 'X' || s[1] == 'x')) {
      s = slice_with_free(s, 2, len);
      len = strlen(s);
      r = 16;
    }
  }

  for (offset = 0; offset < len; offset++)
    if (radix_val(s[offset]) > r) break;

  if (offset == 0)
    return JSNAN();
  else {
    s = slice_with_free(s, 0, offset);
    len = strlen(s);
  }

  double sum = 0;
  unsigned i;
  for (i = 0; i < len; i++)
    sum += radix_val(s[i]) * pow(r, len - i - 1);

  return JSNUM(sign * sum);
}

// parseFloat(string)
js_val *global_parse_float(js_val *instance, js_args *args, eval_state *state) {
  return TO_NUM(ARG(args, 0));
}

// eval(string)
js_val *global_eval(js_val *instance, js_args *args, eval_state *state) {
  js_val *code = TO_STR(ARG(args, 0));
  return js_eval_string(code->string.ptr, state->ctx);
}

// print()
js_val *global_print(js_val *instance, js_args *args, eval_state *state) {
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++)
    js_debug(stdout, js_to_primitive(ARG(args, i), T_STRING), 0, 1);
  return JSUNDEF();
}

static int load_file(char *name) {
  if (access(name, R_OK) == -1)
    return -1;

  FILE *file = fopen(name, "r");

  fseek(file, 0, SEEK_END);
  unsigned size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char *fcontent = malloc(size + 1);
  size_t result = fread(fcontent, 1, size, file);
  fclose(file);

  if (result != size) {
    if (fcontent != NULL)
      free(fcontent);
    return -1;
  }

  char *prev_script = js->script_name;
  js->script_name = name;
  fcontent[size] = '\0';
  js_eval_string(fcontent, js->global);
  free(fcontent);
  js->script_name = prev_script;
  return 0;
}

// load(filename)
//
// Execute the file with the given name in the global scope. Compatible
// with the function of the same name in V8, SpiderMonkey and Rhino.
js_val *global_load(js_val *instance, js_args *args, eval_state *state) {
  unsigned i;
  for (i = 0; i < ARGLEN(args); i++) {
    if (load_file(TO_STR(ARG(args, i))->string.ptr) == -1)
      js_throw(state, js_new_error(E_ERROR, "File could not be read"));
  }
  return JSUNDEF();
}

// Helper function that attaches a given prototype to all properties of the
// given object that are native functions.
void js_attach_prototype(js_val *obj, js_val *proto) {
  js_prop *prop;
  OBJ_ITER(obj, prop) {
    if (prop->ptr && IS_FUNC(prop->ptr) && prop->ptr->object.native)
      prop->ptr->proto = proto;
  }
}

js_val *js_bootstrap() {
  js_val *global = JSOBJ();
  js_val *object_cons = bootstrap_object();

  DEF(global, "Object",   object_cons);
  DEF(global, "Function", bootstrap_function());
  DEF(global, "Array",    bootstrap_array());
  DEF(global, "String",   bootstrap_string());
  DEF(global, "Number",   bootstrap_number());
  DEF(global, "Boolean",  bootstrap_boolean());
  DEF(global, "Date",     bootstrap_date());
  DEF(global, "RegExp",   bootstrap_regexp());
  DEF(global, "Error",    bootstrap_error(global));
  DEF(global, "Math",     bootstrap_math());
  DEF(global, "console",  bootstrap_console());
#ifdef JS_GC_EXPOSE
  DEF(global, "gc",       bootstrap_gc());
#endif

  // The Object constructor and its methods are created before the Function
  // constructor exists, so we need connect the prototypes manually.
  object_cons->proto = js->function_proto;
  js_attach_prototype(object_cons, js->function_proto);
  js_attach_prototype(js->object_proto, js->function_proto);

  // Likewise for the Function prototype.
  js_attach_prototype(js->function_proto, js->function_proto);

  DEF(global, "NaN",       JSNAN());
  DEF(global, "Infinity",  JSINF());
  DEF(global, "undefined", JSUNDEF());
  DEF(global, "this",      global);

  // These aren't currently optimized, just here for compatibility's sake.
  DEF(global, "Float32Array", JSNFUNC(arr_new, 1));
  DEF(global, "Float64Array", JSNFUNC(arr_new, 1));
  DEF(global, "Uint8Array",   JSNFUNC(arr_new, 1));
  DEF(global, "Uint16Array",  JSNFUNC(arr_new, 1));
  DEF(global, "Uint32Array",  JSNFUNC(arr_new, 1));
  DEF(global, "Int8Array",    JSNFUNC(arr_new, 1));
  DEF(global, "Int16Array",   JSNFUNC(arr_new, 1));
  DEF(global, "Int32Array",   JSNFUNC(arr_new, 1));

  DEF(global, "isNaN",      JSNFUNC(global_is_nan, 1));
  DEF(global, "isFinite",   JSNFUNC(global_is_finite, 1));
  DEF(global, "parseInt",   JSNFUNC(global_parse_int, 2));
  DEF(global, "parseFloat", JSNFUNC(global_parse_float, 1));
  DEF(global, "eval",       JSNFUNC(global_eval, 1));

  // Extras
  // DEF(global, "JS_VERSION", JSSTR(JS_VERSION));
  DEF(global, "load",       JSNFUNC(global_load, 1));
  DEF(global, "print",      JSNFUNC(global_print, 1));

  return global;
}
