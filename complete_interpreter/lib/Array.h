// Array.h
// -------

#ifndef JS_ARR_H
#define JS_ARR_H

#include "../js_runtime.h"

js_val * arr_new(js_val *, js_args *, eval_state *);
js_val * arr_is_array(js_val *, js_args *, eval_state *);

js_val * arr_proto_pop(js_val *, js_args *, eval_state *);
js_val * arr_proto_push(js_val *, js_args *, eval_state *);
js_val * arr_proto_reverse(js_val *, js_args *, eval_state *);
js_val * arr_proto_shift(js_val *, js_args *, eval_state *);
js_val * arr_proto_sort(js_val *, js_args *, eval_state *);
js_val * arr_proto_splice(js_val *, js_args *, eval_state *);
js_val * arr_proto_unshift(js_val *, js_args *, eval_state *);

js_val * arr_proto_concat(js_val *, js_args *, eval_state *);
js_val * arr_proto_join(js_val *, js_args *, eval_state *);
js_val * arr_proto_slice(js_val *, js_args *, eval_state *);
js_val * arr_proto_to_string(js_val *, js_args *, eval_state *);
js_val * arr_proto_index_of(js_val *, js_args *, eval_state *);
js_val * arr_proto_last_index_of(js_val *, js_args *, eval_state *);

js_val * arr_proto_filter(js_val *, js_args *, eval_state *);
js_val * arr_proto_for_each(js_val *, js_args *, eval_state *);
js_val * arr_proto_every(js_val *, js_args *, eval_state *);
js_val * arr_proto_map(js_val *, js_args *, eval_state *);
js_val * arr_proto_some(js_val *, js_args *, eval_state *);
js_val * arr_proto_reduce(js_val *, js_args *, eval_state *);
js_val * arr_proto_reduce_right(js_val *, js_args *, eval_state *);

js_val * bootstrap_array(void);

#endif
