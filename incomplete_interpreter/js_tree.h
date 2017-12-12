/*
    Abstract syntax tree for JavaScript
*/
#ifndef TREE_H
#define TREE_H

struct Node;

struct UnaryExpression {
	UnaryExpressionType unary_type;
	struct Node* expression;
};
typedef struct UnaryExpression UnaryExpression;

struct PostfixExpression;
typedef struct PostfixExpression PostfixExpression;

struct IdExpression {
	char *id;
};
typedef struct IdExpression IdExpression;

struct Literal {
	LiteralType literal_type;
	union {
		void *nval;
		int ival;
		float fval;
		char *sval;
	};
};
typedef struct Literal Literal;

struct PrimaryExpression {
	PrimaryExpressionType primary_type;
	struct Node* which;
};
typedef struct PrimaryExpression PrimaryExpression;

struct BinaryExpression {
	BinaryExpressionType binary_type;
	struct Node* left;
	struct Node* right;
};
typedef struct BinaryExpression BinaryExpression;

struct Declarator {
	DeclaratorType declarator_type;
	char id[32];
	struct Node* params;
};
typedef struct Declarator Declarator;

struct Node {
	NodeType node_type;
	LiteralType type;
	union {
		Literal* literal_expression;
		Declarator* declarator;
		IdExpression* id_expression;
		UnaryExpression* unary_expression;
		BinaryExpression* binary_expression;
		PrimaryExpression* primary_expression;
		PostfixExpression* postfix_expression;
		struct Symbol* sym;
	};
	struct Node* next;
};
typedef struct Node Node;

#endif