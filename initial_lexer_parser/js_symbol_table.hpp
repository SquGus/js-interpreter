#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Data {
	int ival;
	float fval;
	char sval[128];
};

struct Symbol {
	char* name;
	struct Symbol* next;
	// struct Node* node;
	// LiteralType type;
};

typedef struct Symbol Symbol;

Symbol *symbol_table = (Symbol *)0;
Symbol *put_symbol();
Symbol *get_symbol();

Symbol *put_symbol(char *symbol_name) {
	Symbol *ptr;
	ptr = (Symbol *) malloc(sizeof(Symbol));
	ptr->name = (char *) malloc(strlen(symbol_name)+1);
	strcpy(ptr->name, symbol_name);
	ptr->next = (Symbol *)symbol_table;
	symbol_table = ptr;
	return ptr;
}

Symbol *get_symbol(char *symbol_name) {
	Symbol *ptr;
	for (ptr = symbol_table; ptr != (Symbol *)0; ptr = (Symbol *)ptr->next) {
		if (strcmp(ptr->name, symbol_name) == 0) {
			return ptr;
		}
	}
	return 0;
}

// struct Scope {
// 	struct Symbol* head_symbol;
// 	struct Scope* prev;
// 	int depth;
// 	LiteralType ret_type;
// }