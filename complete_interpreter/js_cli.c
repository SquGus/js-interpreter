/*
 *	js_cli -> Utilities for the command line interface
 */

#include <unistd.h>

#include "js_interpreter.h"
#include "js_cli.h"


void js_print_help() {
  printf("Usage: my_js_interpreter [options] [script.js] \n"
         "\n"
         "Options:\n"
         "  -v, --version       print version info\n"
         "  -h, --help          print this help text\n"
         "  -i, --interactive   force REPL\n"
         "  -n, --nodes         print the AST\n"
         "  -t, --tokens        print tokens\n");
}

void js_print_startup() {
  printf(ANSI_BLUE);
  printf(" *** MY_JS_INTERPRETER ***\n");
  printf(ANSI_RESET);
  // printf("\nVersion %s (<ctrl-d> to quit)          \n", JS_VERSION);
}

// void JS_print_version() {
//   printf("%s\n", JS_VERSION);
// }

void cfprintf(FILE *stream, const char *color, const char *tpl, ...) {
  bool use_colors = js->opt_interactive || isatty(fileno(stdin));

  if (use_colors) fputs(color, stream);

  va_list ap;
  va_start(ap, tpl);
  vfprintf(stream, tpl, ap);
  va_end(ap);

  if (use_colors) fputs(ANSI_RESET, stream);
}
