/*
 *	js_args -> singly linked list used internally to represent arguments
 */

#ifndef JS_ARGS_H
#define JS_ARGS_H

struct js_val;

typedef struct js_args {
  struct js_val *arg;
  struct js_args *next;
} js_args;

js_args * args_new();
void args_append(js_args *, struct js_val *);
struct js_val * args_get(js_args *, int);
unsigned args_len(js_args *);

#endif
