/*
 * regexp -> String functions
 */

#ifndef JS_NO_REGEXP
#include <pcre.h>
#endif

#include "js_regexp.h"
#include "js_interpreter.h"


const int regexp_vector_len = 30;


/* Gateway to the PCRE library. Compiles a regular expression pattern and
 * returns matches. When compiled with JS_NO_REGEXP, this function is still
 * available, but will throw an error when called. */
int *js_regexp(char *str, char *pattern, int *count, int offset, bool caseless) {
#ifndef JS_NO_REGEXP
  const char *error;
  int rc;
  int error_offset;
  int *output_vector = malloc(regexp_vector_len * sizeof(int));
  int options = PCRE_JAVASCRIPT_COMPAT;
  if (caseless)
    options |= PCRE_CASELESS;

  pcre *regexp = pcre_compile(pattern, options, &error, &error_offset, NULL);
  if (!regexp) {
    char *fmt = "Invalid Regular Expression:\n  %s at offset %d";
    js_throw(NULL, js_new_error(E_SYNTAX, fmt, error, error_offset));
  }

  rc = pcre_exec(regexp, NULL, str, strlen(str), offset, 0,
                 output_vector, regexp_vector_len);

  if (count != NULL)
    *count = rc > 0 ? rc : 0;

  pcre_free(regexp);

  if (rc < 0) {
    free(output_vector);
    return NULL;
  }

  return output_vector;
#else
  js_throw(NULL, js_new_error(E_ERROR, "Regular expressions are not available"));
  UNREACHABLE();
#endif
}

/* Get the number of capturing subpatterns in the regular expression. This is
 * used to get the `NCapturingParens` value used in parts of the ECMA spec */
int js_regexp_ncaptures(char *pattern) {
#ifndef JS_NO_REGEXP
  const char *error;
  int error_offset;
  int options = PCRE_JAVASCRIPT_COMPAT;
  int captures;
  pcre *regexp = pcre_compile(pattern, options, &error, &error_offset, NULL);
  if (!regexp) {
    char *fmt = "Invalid Regular Expression:\n  %s at offset %d";
    js_throw(NULL, js_new_error(E_SYNTAX, fmt, error, error_offset));
  }
  pcre_fullinfo(regexp, NULL, PCRE_INFO_CAPTURECOUNT, &captures);
  return captures;
#else
  js_throw(NULL, js_new_error(E_ERROR, "Regular expressions are not available"));
  UNREACHABLE();
#endif
}
