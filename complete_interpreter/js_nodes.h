/*
 *	js_nodes -> AST node definitions and traversal helpers
 */

#ifndef JS_NODES_H
#define JS_NODES_H

#include <stdbool.h>

enum ast_node_type {
  NODE_ARG_LST,
  NODE_ARR,
  NODE_ASGN,
  NODE_BLOCK,
  NODE_BOOL,
  NODE_BREAK,
  NODE_CALL,
  NODE_CASE_BLOCK,
  NODE_CATCH,
  NODE_CLAUSE,
  NODE_CLAUSE_LST,
  NODE_CONT,
  NODE_DEBUG_STMT,
  NODE_DOWHILE,
  NODE_ELISION,
  NODE_EL_LST,
  NODE_EMPT_STMT,
  NODE_EXP,
  NODE_EXPGRP,
  NODE_EXP_STMT,
  NODE_FINALLY,
  NODE_FOR,
  NODE_FORIN,
  NODE_FUNC,
  NODE_IDENT,
  NODE_IF,
  NODE_MEMBER,
  NODE_NEW,
  NODE_NULL,
  NODE_NUM,
  NODE_OBJ,
  NODE_PARAM_LST,
  NODE_PROP,
  NODE_PROP_LST,
  NODE_REGEXP,
  NODE_RETURN,
  NODE_SRC_LST,
  NODE_STMT_LST,
  NODE_STR,
  NODE_SWITCH_STMT,
  NODE_TERN,
  NODE_THIS,
  NODE_THROW,
  NODE_TRY_STMT,
  NODE_UNARY_POST,
  NODE_UNARY_PRE,
  NODE_UNKNOWN,
  NODE_VAR_DEC,
  NODE_VAR_DEC_LST,
  NODE_VAR_STMT,
  NODE_WITH_STMT,
  NODE_WHILE,
};

typedef struct ast_node {
  struct ast_node *e1;
  struct ast_node *e2;
  struct ast_node *e3;
  char *sval;
  double val;
  enum ast_node_type type;
  enum ast_node_type sub_type;
  bool visited;
  int line;
  int column;
} ast_node;

ast_node * node_alloc(void);
ast_node * node_new(enum ast_node_type, ast_node *, ast_node *, ast_node *,
                    double, char *, int, int);
ast_node * node_pop(ast_node *);
void node_rewind(ast_node *);
bool node_empty(ast_node *);
int node_count(ast_node *);
void node_print(ast_node *, bool, int);

#endif
