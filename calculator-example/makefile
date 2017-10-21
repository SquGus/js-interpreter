# Makefile: A simple makefile for ex1.
default:
	/usr/local/opt/bison/bin/bison -d ex1.ypp
	/usr/local/opt/flex/bin/flex ex1.l
	g++ -o mycalc ex1.tab.cpp lex.yy.c