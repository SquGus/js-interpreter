// RegExp.h
// --------

#ifndef JS_I_REGEXP_H
#define JS_I_REGEXP_H

#include "../js_runtime.h"

js_val * regexp_new(js_val *, js_args *, eval_state *);
js_val * regexp_proto_exec(js_val *, js_args *, eval_state *);
js_val * regexp_proto_test(js_val *, js_args *, eval_state *);
js_val * regexp_proto_to_string(js_val *, js_args *, eval_state *);

js_val * bootstrap_regexp(void);

#endif
