/*
 * regexp -> String functions
 */

#include <stdbool.h>

#ifndef JS_REGEXP_H
#define JS_REGEXP_H

int * js_regexp(char *, char *, int *, int, bool);
int js_regexp_ncaptures(char *);

#endif
