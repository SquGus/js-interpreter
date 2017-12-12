/*
 *	js_string -> String functions
 */

#ifndef JS_STR_H
#define JS_STR_H

char * js_str_concat(char *, char *);
char * js_str_slice(char *, unsigned, unsigned);
char * js_str_replace(char *, char *, char *, int);

#endif
