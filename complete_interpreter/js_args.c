/*
 *	js_args -> singly linked list used internally to represent arguments
 */

#include "js_args.h"
#include "js_interpreter.h"

js_args *args_new() {
  js_args *args = malloc(sizeof(js_args));
  args->arg = NULL;
  args->next = NULL;
  return args;
}

void args_append(js_args *args, js_val *val)
{
  if (args->arg == NULL)
    args->arg = val;
  else {
    while (args->next != NULL) args = args->next;
    args->next = args_new();
    args->next->arg = val;
  }
}

js_val *args_get(js_args *args, int n) {
  int i;
  for (i = 0; i <= n; i++) {
    if (i == n)
      return args->arg ? args->arg : JSUNDEF();
    if (args->next == NULL)
      break;
    args = args->next;
  }
  return JSUNDEF();
}

unsigned int args_len(js_args *args) {
  if (args == NULL) return 0;

  // Although arrays can be up to 2^32 - 1 in length, we limit
  // the number of arguments to 2^16 - 1 (UINT_MAX).
  unsigned long i = 0;
  while (i < UINT_MAX) {
    if (args->arg) i++;
    if (args->next == NULL) break;
    args = args->next;
  }
  if (i >= UINT_MAX)
    js_throw(NULL, js_new_error(E_RANGE, "too many arguments"));
  return i;
}
