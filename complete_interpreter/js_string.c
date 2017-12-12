/*
 *	js_string -> String functions
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#include "js_string.h"


/* Returns a newly allocated string that is the concatenation of the two
 * argument strings */
char *js_str_concat(char *a, char *b) {
  size_t size = strlen(a) + strlen(b) + 1;
  char *new = malloc(size);
  new[size - 1] = '\0';
  snprintf(new, size, "%s%s", a, b);
  return new;
}

/* Returns a newly allocated substring from start and end indices provided */
char * js_str_slice(char *str, unsigned start, unsigned end) {
  if (str == NULL || start > end || end > strlen(str))
    return NULL;
  size_t size = end - start + 1;
  char *new = malloc(size);
  new[size - 1] = '\0';
  snprintf(new, size, "%.*s", end - start, str + start);
  return new;
}

/* Replace a substring in the given string with a new string. The limit
 * argument indicates the maximum number of replacements that should be made.
 * Pass 0 to for unlimited replacements. The return is a newly allocated string
 * unless no replacements could be made, in which case the original is
 * returned. */
char *js_str_replace(char *orig, char *repl, char *new, int limit) {
  char *result, *ins, *tmp;
  int count, dist;
  bool has_limit = limit > 0;

  if (!(orig && repl && strlen(repl) && new)) return orig;
  if (!(ins = strstr(orig, repl))) return orig;

  int len_new = strlen(new), len_repl = strlen(repl);
  for (count = 0; (tmp = strstr(ins, repl)) && (!has_limit || limit); count++, limit--)
    ins = tmp + len_repl;

  tmp = result = malloc(strlen(orig) + (len_new - len_repl) * count + 1);
  if (!result) return orig;

  while (count--) {
    ins = strstr(orig, repl);
    dist = ins - orig;
    tmp = strncpy(tmp, orig, dist) + dist;
    tmp = strcpy(tmp, new) + len_new;
    orig += dist + len_repl;
  }

  strcpy(tmp, orig);
  return result;
}
