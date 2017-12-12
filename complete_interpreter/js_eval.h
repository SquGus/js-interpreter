/*
 *	js_eval -> Abstract Syntax Tree walker
 */

#ifndef JS_EVAL_H
#define JS_EVAL_H

#include "js_interpreter.h"
#include "js_nodes.h"
#include "js_args.h"

#define T_BOTH(a,b,t)     ((a)->type == (t) && (b)->type == (t))
#define T_XOR(a,b,t1,t2)  (((a)->type == (t1) && (b)->type == (t2)) || \
                           ((a)->type == (t2) && (b)->type == (t1)))

js_val * js_eval(js_val *, ast_node *);
js_val * js_call(js_val *, js_val *, js_val *, js_args *);
js_val * js_eq(js_val *, js_val *, bool);

#endif
