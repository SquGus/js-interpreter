/*
 *	js_props -> Property access and prototype/scope traversals
 */

#ifndef JS_PROP_H
#define JS_PROP_H

#include "js_interpreter.h"

void js_set(js_val *, char *, js_val *);
void js_set_prop(js_val *, char *, js_val *, js_prop_flags);
void js_set_rec(js_val *, char *, js_val *);
bool js_del_prop(js_val *, char *);
js_prop * js_get_prop(js_val *, char *);
js_prop * js_get_prop_rec(js_val *, char *);
js_prop * js_get_prop_proto(js_val *, char *);
js_val * js_get(js_val *, char *);
js_val * js_get_proto(js_val *, char *);
js_val * js_get_rec(js_val *, char *);

#endif
