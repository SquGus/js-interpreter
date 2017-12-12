/*
 *	js_cli -> Utilities for the command line interface
 */

#ifndef JS_CLI_H
#define JS_CLI_H

#define ANSI_RED     "\033[31m"
#define ANSI_YELLOW  "\033[32m"
#define ANSI_ORANGE  "\033[33m"
#define ANSI_BLUE    "\033[34m"
#define ANSI_PINK    "\033[35m"
#define ANSI_GRAY    "\033[32;1m"
#define ANSI_WHITE   "\033[37;1m"
#define ANSI_RESET   "\033[0m"

void js_print_help(void);
void js_print_startup(void);
// void js_print_version(void);
void cfprintf(FILE *, const char *, const char *, ...);

#endif
