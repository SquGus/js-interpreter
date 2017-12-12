/*
 *	js_debug -> Debugging functions
 */

#ifndef JS_DEBUG_H
#define JS_DEBUG_H

#include "js_interpreter.h"

void js_debug(FILE *, js_val *, int, bool);
void js_debug_verbose(FILE *, js_val *, int);

#endif
