/*
    Symbol table for JavaScript
*/
#ifndef ST_H
#define ST_H

union Data {
	int ival;
	float fval;
	char *sval;
	char *id;
};
typedef union Data Data;

struct Symbol {
	Data data;
	struct Node *node;
	LiteralType type;
	char *name;
	struct Symbol *next;
};
typedef struct Symbol Symbol;

struct Scope {
	Symbol *head_symbol;
	struct Scope *prev;
	int depth;
	LiteralType ret_type;
};
typedef struct Scope Scope;

struct SymbolTable {
	Scope cur_scope;
};
typedef struct SymbolTable SymbolTable;

Scope *cur_scope;

/* Function to create scope with void return type */
Scope *create_scope() {
	Scope *new_scope = (Scope*)malloc(sizeof(Scope));
	new_scope->prev = cur_scope;
	cur_scope = new_scope;
	if (cur_scope->prev) {
		cur_scope->depth = cur_scope->prev->depth;
	} else {
		cur_scope->depth = 0;
	}
	cur_scope->ret_type = VOID_T;
	return new_scope;
}

/* Fuction to create scope with specific return type */
Scope *create_scope_type(int type) {
	Scope *new_scope = (Scope*)malloc(sizeof(Scope));
	new_scope->prev = cur_scope;
	cur_scope = new_scope;
	if (cur_scope->prev) {
		cur_scope->depth = cur_scope->prev->depth;
	} else {
		cur_scope->depth = 0;
	}
	cur_scope->ret_type = type;
	return new_scope;
}

/* Function to delete scope */
Scope *delete_scope() {
	Scope *cur = cur_scope;
	cur_scope = cur_scope->prev;
	free(cur);	// MAYBE COMMENT?
	return cur_scope;
}

/* Function to check if symbol is in scope */
int is_symbol_in_scope(char *name) {
	Symbol *cur_sym = cur_scope->head_symbol;
	while (cur_sym) {
		if (strcmp(cur_sym->name, name) == 0) {
			return 1;
		}
		cur_sym = cur_sym->next;
	}
	return 0;
}

/* Function to get scope of symbol */
Symbol *get_symbol_scope(char *name, Scope *scope) {
	Symbol *cur_sym = scope->head_symbol;
	while (cur_sym) {
		if (strcmp(cur_sym->name, name) == 0) {
			return cur_sym;
		}
		cur_sym = cur_sym->next;
	}
	if (scope->prev) {
		return get_symbol_scope(name, scope->prev);
	}
	return 0;
}

/* Function to add symbol to scope */
Symbol *add_symbol_scope(char *name, Data data, int type, Scope *scope) {
	Symbol *new_sym = (Symbol*)malloc(sizeof(Symbol));
	strcpy(new_sym->name, name);
	new_sym->data = data;
	new_sym->type = type;
	new_sym->next = scope->head_symbol;
	scope->head_symbol = new_sym;
	return new_sym;
}

/* Symbol table entry */
//Symbol *identifier;

/* Symbol table implementation: linked list of symbols */
//Symbol *symbol_table = (Symbol *)0;

/* Function to put symbol into table */
Symbol *put_symbol(char *symbol_name, Data data, int type) {
	return add_symbol_scope(symbol_name, data, type, cur_scope);
	// // Declares pointer to new symbol
	// Symbol *ptr;
	// ptr = (Symbol *)malloc(sizeof(Symbol));
	// // Copies name to new symbol
	// ptr->name = (char *)malloc(sizeof(symbol_name) + 1);
	// strcpy(ptr->name, symbol_name);
	// ptr->next = (struct Symbol*)symbol_table;
	// symbol_table = ptr;
	// return ptr;
}

/* Function to get symbol from table */
Symbol *get_symbol(char *symbol_name) {
	return get_symbol_scope(symbol_name, cur_scope);
	// Symbol *ptr;
	// for (ptr = symbol_table; ptr != (Symbol *)0; ptr = ptr->next) {
	// 	if (strcmp(ptr->name, symbol_name) == 0) {
	// 		return ptr;
	// 	}
	// }
	// return 0;
}

void init() {
	cur_scope = (Scope*)malloc(sizeof(Scope));
}

#endif