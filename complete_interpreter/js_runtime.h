/*
 *	js_runtime -> Bootstrap global object and other stuff
 */

#ifndef JS_RUNTIME_H
#define JS_RUNTIME_H

#include "js_interpreter.h"
#include "js_props.h"
#include "js_string.h"
#include "js_regexp.h"
#include "js_debug.h"
#include "js_eval.h"
#include "js_gc.h"
#include "js_args.h"

js_val * global_is_nan(js_val *, js_args *, eval_state *);
js_val * global_is_finite(js_val *, js_args *, eval_state *);
js_val * global_parse_float(js_val *, js_args *, eval_state *);
js_val * glboal_parse_int(js_val *, js_args *, eval_state *);
js_val * global_eval(js_val *, js_args *, eval_state *);
js_val * global_gc(js_val *, js_args *, eval_state *);
js_val * global_load(js_val *, js_args *, eval_state *);
js_val * global_print(js_val *, js_args *, eval_state *);

void js_attach_prototype(js_val *, js_val *);
js_val * js_bootstrap(void);

#endif
