make:
	bison -dv js_parser.y
	gcc -Wno-deprecated-register -O0 -g -Wall -std=c99 -c -o js_parser.o js_parser.tab.c

	flex --outfile=js_lexer.yy.c js_lexer.l
	gcc -Wno-deprecated-register -O0 -g -Wall -std=c99 -c js_lexer.yy.c -o js_lexer.o

	gcc -o my_js_interpreter js_parser.o js_lexer.o -lm