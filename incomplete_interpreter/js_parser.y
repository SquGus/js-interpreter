/*
    Parser for JavaScript
*/
%require  "3.0"
%debug

/* Import libraries, symbol table and other C code */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
  #include "js_types.h"
  #include "js_symbol_table.h"
	#include "js_tree.h"
	#define YYDEBUG 1

  int yylex(void);
  void yyerror(const char *s);
	
	int errors;

	// /* Install identifier in table */
	// void install(char *sym_name) {
	// 	Symbol *s;
	// 	s = get_symbol(sym_name);
	// 	if (s == 0) {
	// 		s = put_symbol(sym_name);
	// 	} else {
	// 		errors++;
	// 		printf("%s is already defined\n", sym_name);
	// 	}
	// }

	//  If identifier is defined, generate code 
	// void context_check(char *sym_name) {
	// 	Symbol *identifier;
	// 	identifier = get_symbol(sym_name);
	// 	if (identifier == 0) {
	// 		errors++;
	// 		printf("%s is an undeclared identifier\n", sym_name);
	// 	} else {
	// 		//gen_code(operation, identifier->offset);
	// 	}
	// }
%}

/* Semantic records */
%union {
  int ival;
  float fval;
  char *sval;
  char *id;
  void *nval;
  struct Node *node;
}

/* Tokens */
%start Program
%token END    0   "end of file"

%token<id> ID
%token<nval> NULL_V
%token<ival> TRUE_V
%token<ival> FALSE_V
%token<fval> FLT_V
%token<ival> INT_V
%token<sval> STRING_V

%type<node> Program Statements Statement CodeStatement Definition ExpressionStatement
            Block IfStatement DoStatement WhileStatement ForStatement ForInitializer ContinueStatement
            BreakStatement ReturnStatement VariableDefinition VariableBindingList
            VariableBinding VariableInitializer FunctionDefinition FunctionSignature ParameterSignature
            Parameters RequiredParameters RequiredParameter Expression OptionalExpression AssignmentExpression
            CompoundAssignment ParenthesizedExpression ConditionalExpression PostfixExpression FullPostfixExpression
            FullNewExpression ShortNewExpression FullNewSubexpression ShortNewSubexpression MemberOperator Arguments
            ArgumentList ArgumentListPrefix PrimaryExpression SimpleExpression NamedFunction ObjectLiteral FieldList
            LiteralField ArrayLiteral ElementList LiteralElement LogicalOrExpression LogicalAndExpression
            BitwiseOrExpression BitwiseXorExpression BitwiseAndExpression EqualityExpression RelationalExpression
            ShiftExpression AdditiveExpression MultiplicativeExpression UnaryExpression

%type<id>   Identifier TypedIdentifier QualifiedIdentifier OptionalLabel

// %token BIT_NOT_OP
%token CLOSE_C
%token OPEN_C
%token CLOSE_B
%token OPEN_B
%token CLOSE_P
%token OPEN_P
%token TERNARY_OP
%token LOGIC_OR_OP
%token SHORT_BIT_OR_OP
%token BIT_OR_OP
%token SHORT_BIT_XOR_OP
%token BIT_XOR_OP
%token SHORT_BIT_SHIFT_Z_R_OP
%token BIT_SHIFT_Z_R_OP
%token SHORT_BIT_SHIFT_S_R_OP
%token BIT_SHIFT_S_R_OP
%token GE_OP
%token G_OP
%token EQ_VT_OP
%token EQ_V_OP
%token VA_OP
%token LE_OP
%token SHORT_BIT_SHIFT_L_OP
%token BIT_SHIFT_L_OP
%token L_OP
%token STMT_TER_OP
%token PA_OP
%token SHORT_DIV_OP
%token DIV_OP
%token MEM_ACC_OP
%token SHORT_SUB_OP
%token UNIT_SUB_OP
%token SUB_OP
%token SEP_OP
%token SHORT_ADD_OP
%token UNIT_ADD_OP
%token ADD_OP
%token SHORT_MUL_OP
%token MUL_OP
%token SHORT_BIT_AND_OP
%token LOGIC_AND_OP
%token BIT_AND_OP
%token SHORT_MOD_OP
%token MOD_OP
%token NEG_VT_OP
%token NEG_V_OP
%token LOGIC_NOT_OP
%token BREAK
%token CASE
// %token CATCH
// %token CLASS
// %token CONST
%token CONTINUE
// %token DEBUGGER
%token DEFAULT
// %token DELETE
%token DO
%token ELSE
// %token ENUM
// %token EXPORT
// %token EXTENDS
// %token FINALLY
%token FOR
%token FUNCTION
%token IF
// %token IMPLEMENTS
// %token IMPORT
// %token IN
%token INSTANCEOF
// %token INTERFACE
// %token LET
%token NEW
// %token PACKAGE
// %token PRIVATE
// %token PROTECTED
// %token PUBLIC
%token RETURN
// %token STATIC
// %token SUPER
// %token SWITCH
// %token THIS
// %token THROW
// %token TRY
// %token TYPEOF
%token VAR
// %token VOID
%token WHILE
// %token WITH
// %token YIELD

// Operator precedence
%nonassoc "then"
%nonassoc ELSE

// Parse options
%locations

%%
// Gramar rules
Program
  : Statements END
  ;

Statements
  : Statements Statement
  | Statement
  ;

Statement
  : CodeStatement
  | Definition
  ;

CodeStatement
  // : EmptyStatement
  : ExpressionStatement STMT_TER_OP
  | Block
  | IfStatement
  // | SwitchStatement
  | DoStatement STMT_TER_OP
  | WhileStatement
  | ForStatement
  | ContinueStatement STMT_TER_OP
  | BreakStatement STMT_TER_OP
  | ReturnStatement STMT_TER_OP
  ;

Definition
  : VariableDefinition STMT_TER_OP
  | FunctionDefinition
  ;

// EmptyStatement
//   : STMT_TER_OP {
//     $$ = $1;
//   }
//   ;

ExpressionStatement
  : Expression {
    $$ = $1;
  }
  ;

Block
  : OPEN_C Statements CLOSE_C {
    $$ = $2;
  }
  ;

IfStatement
  : IF ParenthesizedExpression CodeStatement %prec "then"
  | IF ParenthesizedExpression CodeStatement ELSE CodeStatement {

  }
  ;

// SwitchStatement
//   : SWITCH ParenthesizedExpression OPEN_C CLOSE_C
//   | SWITCH ParenthesizedExpression OPEN_C  CaseGroups LastCaseGroup CLOSE_C
//   ;

// CaseGroups
//   : %empty
//   | CaseGroups CaseGroup
//   ;

// CaseGroup
//   : CaseGuards CaseStatementsPrefix
//   ;

// LastCaseGroup
//   : CaseGuards CaseStatements
//   ;

// CaseGuards
//   : CASE Expression PA_OP
//   | DEFAULT PA_OP
//   ;

// CaseStatements
//   : CodeStatement
//   | CaseStatementsPrefix CodeStatement
//   ;

// CaseStatementsPrefix
//   : CodeStatement
//   | CaseStatementsPrefix CodeStatement
//   ;

DoStatement
  : DO CodeStatement WHILE ParenthesizedExpression
  ;

WhileStatement
  : WHILE ParenthesizedExpression CodeStatement
  ;

ForStatement
  : FOR OPEN_P ForInitializer STMT_TER_OP OptionalExpression STMT_TER_OP OptionalExpression CLOSE_P CodeStatement
  ;

ForInitializer
  : %empty
  | Expression
  | VAR VariableBinding
  ;

ContinueStatement
  : CONTINUE OptionalLabel
  ;

BreakStatement
  : BREAK OptionalLabel
  ;

OptionalLabel
  : %empty
  | Identifier
  ;

ReturnStatement
  : RETURN OptionalExpression
  ;

VariableDefinition
  : VAR VariableBindingList
  ;

// VariableDefinitionKind
//   : VAR {
//     $$ = 
//   }
//   | CONST
//   ;

VariableBindingList
  : VariableBinding
  | VariableBindingList SEP_OP VariableBinding
  ;

VariableBinding
  : TypedIdentifier VariableInitializer
  ;

TypedIdentifier
  : Identifier
  // | TypeExpression Identifier
  ;

VariableInitializer
  : %empty
  | VA_OP AssignmentExpression
  ;

FunctionDefinition
  : NamedFunction
  ;

FunctionSignature
  : ParameterSignature //ResultSignature
  ;

ParameterSignature
  : OPEN_P Parameters CLOSE_P
  ;

Parameters
  : %empty
  | RequiredParameters
  ;

RequiredParameters
  : RequiredParameter
  | RequiredParameters SEP_OP RequiredParameter
  ;

RequiredParameter
  : TypedIdentifier
  ;

// ResultSignature
//   : %empty
//   | TypeExpression
//   ;

Expression
  : AssignmentExpression
  | Expression SEP_OP AssignmentExpression
  ;

OptionalExpression
  : Expression
  | %empty
  ;

AssignmentExpression
  : ConditionalExpression {

  }
  | PostfixExpression VA_OP AssignmentExpression {

  }
  | PostfixExpression CompoundAssignment AssignmentExpression {

  }
  ;

CompoundAssignment
  : SHORT_MUL_OP
  | SHORT_DIV_OP
  | SHORT_MOD_OP
  | SHORT_ADD_OP
  | SHORT_SUB_OP
  | SHORT_BIT_SHIFT_L_OP
  | SHORT_BIT_SHIFT_S_R_OP
  | SHORT_BIT_SHIFT_Z_R_OP
  | SHORT_BIT_AND_OP
  | SHORT_BIT_XOR_OP
  | SHORT_BIT_OR_OP
  ;

ParenthesizedExpression
  : OPEN_P Expression CLOSE_P {
    $$ = $2;
  }
  ;

Identifier
  : ID {
    strcpy($$, $1);
  }
  ;

// TypeExpression
//   : NonAssignmentExpression
//   ;

ConditionalExpression
  : LogicalOrExpression
  | LogicalOrExpression TERNARY_OP AssignmentExpression PA_OP AssignmentExpression
  ;

// NonAssignmentExpression
//   : LogicalOrExpression
//   | LogicalOrExpression TERNARY_OP NonAssignmentExpression PA_OP NonAssignmentExpression
//   ;

PostfixExpression
  : FullPostfixExpression
  | ShortNewExpression
  ;

FullPostfixExpression
  : PrimaryExpression {
    $$ = $1;
  }
  | FullNewExpression {

  }
  | FullPostfixExpression MemberOperator {

  }
  | FullPostfixExpression Arguments {

  }
  | PostfixExpression UNIT_ADD_OP {
  }
  | PostfixExpression UNIT_SUB_OP {
  }
  | PostfixExpression LOGIC_NOT_OP {
  }
  // | PostfixExpression BIT_NOT_OP
  ;

FullNewExpression
  : NEW FullNewSubexpression Arguments
  ;

ShortNewExpression
  : NEW ShortNewSubexpression
  ;

FullNewSubexpression
  : PrimaryExpression
  | FullNewSubexpression MemberOperator
  | FullNewExpression
  ;

ShortNewSubexpression
  : FullNewSubexpression
  | ShortNewExpression
  ;

MemberOperator
  : OPEN_B ArgumentList CLOSE_B
  | MEM_ACC_OP QualifiedIdentifier
  | MEM_ACC_OP ParenthesizedExpression
  ;

Arguments
  : OPEN_P ArgumentList CLOSE_P
  ;

ArgumentList
  : %empty
  | ArgumentListPrefix
  ;

ArgumentListPrefix
  : AssignmentExpression
  | ArgumentListPrefix SEP_OP AssignmentExpression
  ;

PrimaryExpression
  : SimpleExpression {
    $$ = $1;
  }
  // | FunctionExpression
  | ObjectLiteral {

  }
  ;

SimpleExpression
  : NULL_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->nval = (void *)0;
    l->literal_type = VOID_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | TRUE_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = $1;
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | FALSE_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = $1;
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | INT_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->ival = $1;
    l->literal_type = INTEGER_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | FLT_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    l->fval = $1;
    l->literal_type = FLOAT_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | STRING_V {
    Literal *l = (Literal*)malloc(sizeof(Literal));
    strcpy(l->sval, $1);
    l->literal_type = STRING_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->literal_expression = l;
    node->type = l->literal_type;
    $$ = node;
  }
  | QualifiedIdentifier {

  }
  | ParenthesizedExpression {

  }
  | ArrayLiteral {

  }
  ;

// FunctionExpression
//   : AnonymousFunction
//   | NamedFunction
//   ;

// AnonymousFunction
//   : FUNCTION FunctionSignature Block
//   ;

NamedFunction
  : FUNCTION Identifier FunctionSignature Block
  ;

QualifiedIdentifier
  : Identifier {
    strcpy($$, $1);
  }
  ;

ObjectLiteral
  : OPEN_C CLOSE_C
  | OPEN_C FieldList CLOSE_C
  ;

FieldList
  : LiteralField
  | FieldList SEP_OP LiteralField
  ;

LiteralField
  : QualifiedIdentifier PA_OP AssignmentExpression
  ;

ArrayLiteral
  : OPEN_B CLOSE_B
  | OPEN_B ElementList CLOSE_B
  ;

ElementList
  : LiteralElement
  | ElementList SEP_OP LiteralElement
  ;

LiteralElement
  : AssignmentExpression
  ;

LogicalOrExpression
  : LogicalAndExpression
  | LogicalOrExpression LOGIC_OR_OP LogicalAndExpression
  ;

LogicalAndExpression
  : BitwiseOrExpression
  | LogicalAndExpression LOGIC_AND_OP BitwiseOrExpression
  ;

BitwiseOrExpression
  : BitwiseXorExpression
  | BitwiseOrExpression BIT_OR_OP BitwiseXorExpression
  ;

BitwiseXorExpression
  : BitwiseAndExpression
  | BitwiseXorExpression BIT_XOR_OP BitwiseAndExpression
  ;

BitwiseAndExpression
  : EqualityExpression
  | BitwiseAndExpression BIT_AND_OP EqualityExpression
  ;

EqualityExpression
  : RelationalExpression
  | EqualityExpression EQ_V_OP RelationalExpression
  | EqualityExpression NEG_V_OP RelationalExpression
  | EqualityExpression EQ_VT_OP RelationalExpression
  | EqualityExpression NEG_VT_OP RelationalExpression
  ;

RelationalExpression
  : ShiftExpression
  | RelationalExpression L_OP ShiftExpression
  | RelationalExpression G_OP ShiftExpression
  | RelationalExpression LE_OP ShiftExpression
  | RelationalExpression GE_OP ShiftExpression
  | RelationalExpression INSTANCEOF ShiftExpression
  ;

ShiftExpression
  : AdditiveExpression
  | ShiftExpression BIT_SHIFT_L_OP AdditiveExpression
  | ShiftExpression BIT_SHIFT_S_R_OP AdditiveExpression
  | ShiftExpression BIT_SHIFT_Z_R_OP AdditiveExpression
  ;

AdditiveExpression
  : MultiplicativeExpression
  | AdditiveExpression ADD_OP MultiplicativeExpression
  | AdditiveExpression SUB_OP MultiplicativeExpression
  ;

MultiplicativeExpression
  : UnaryExpression {
    $$ = $1;
  }
  | MultiplicativeExpression MUL_OP UnaryExpression
  | MultiplicativeExpression DIV_OP UnaryExpression
  | MultiplicativeExpression MOD_OP UnaryExpression
  ;

UnaryExpression
  : PostfixExpression {
    $$ = $1;
  }
  | UNIT_ADD_OP UnaryExpression {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = INCREMENT_T;
    if ($2->type != INTEGER_T) {
      // TO-DO
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    $$ = node;
  }
  | UNIT_SUB_OP UnaryExpression {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = DECREMENT_T;
    if ($2->type != INTEGER_T) {
      // TO-DO
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    $$ = node;
  }
  | ADD_OP UnaryExpression {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = ADDITION_UNARY_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    if ($2->type == INTEGER_T) {
      node->type = INTEGER_T;
    } else if ($2->type == FLOAT_T) {
      node->type = FLOAT_T;
    } else if ($2->type == STRING_T) {
      node->type = STRING_T;
    } else {
      // TO-DO
      yyerror("Cannot cast type");
      exit(0);
    }
    $$ = node;
  }
  | SUB_OP UnaryExpression {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = SUBTRACTION_UNARY_T;
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    if ($2->type == INTEGER_T) {
      node->type = INTEGER_T;
    } else if ($2->type == FLOAT_T) {
      node->type = FLOAT_T;
    } else {
      // TO-DO
      yyerror("NaN");
      exit(0);
    }
    $$ = node;
  }
  // | BIT_NOT_OP UnaryExpression {
  // }
  | LOGIC_NOT_OP UnaryExpression {
    UnaryExpression *unary_exp = (UnaryExpression*)malloc(sizeof(UnaryExpression));
    unary_exp->unary_type = LOGIC_NOT_T;
    if ($2->type != INTEGER_T) {
      yyerror("An INT type is expected, must cast.");
      exit(0);
    }
    Node *node = (Node*)malloc(sizeof(Node));
    node->unary_expression = unary_exp;
    node->type = INTEGER_T;
    $$ = node;
  }
  ;
%%

// Main
int main(int argc, char *argv[]) {
	extern FILE *yyin;
	++argv; --argc;
	yyin = fopen( argv[0], "r");
	errors = 0;
	yyparse();
	printf("Parse completed\n");
	if (errors == 0) {
		printf("Must generate code\n");
	}
}

void yyerror(const char *s) {
	errors++;
	printf("%s\n", s);
}