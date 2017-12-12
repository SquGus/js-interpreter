%skeleton "lalr1.cc"
%require  "3.0"
%debug 
%defines 
%define api.namespace {JS}
%define parser_class_name {JS_Parser}

%code requires{
   namespace JS {
      class JS_Driver;
      class JS_Scanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { JS_Scanner  &scanner  }
%parse-param { JS_Driver  &driver  }

%code{
  #include <iostream>
  #include <cstdlib>
  #include <fstream>
  #include <string>
  #include <cstdio>

  /* include for all driver functions */
  #include "js_driver.hpp"

  #undef yylex
  #define yylex scanner.yylex

  // void install(char *symbol_name) {
  //   Symbol *s;
  //   s = get_symbol(symbol_name);
  //   if (s == 0) {
  //     s = put_symbol(symbol_name);
  //   } else {
  //     driver.errors++;
  //     printf("%s is already defined\n", symbol_name);
  //   }
  // }

  // void context_check(char *symbol_name) {
  //   if (get_symbol(symbol_name) == 0) {
  //     printf("%s is an undeclared identifier\n", symbol_name);
  //   }
  // }
}

//%define api.value.type variant
%define parse.assert

/*
%token               END    0     "end of file"
%token               UPPER
%token               LOWER
%token <std::string> WORD
%token               NEWLINE
%token               CHAR
*/

%union {
  int ival;
  float fval;
  char *sval;
  char *idval;
  int nval;
  // char cval;
}

%nonassoc "then"
%nonassoc ELSE

%token END    0   "end of file"

%token <nval> NULL_V
%token <ival> TRUE_V
%token <ival> FALSE_V
%token <fval> FLT_V
%token <ival> INT_V
%token <sval> STRING

// %token L_COMMENT
// %token B_COMMENT
%token BIT_NOT_OP
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
%token CONST
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
%token SWITCH
// %token THIS
// %token THROW
// %token TRY
// %token TYPEOF
%token VAR
// %token VOID
%token WHILE
// %token WITH
// %token YIELD

// ************* DOUBTS HERE ****************
// %token UNDEFINED_V
// %token HEX_V
// %token OCT_V
// %token BIN_V
// %token HEX_SEQ
// %token UNI_SEQ
%token<idval> ID

%locations

%start Program

%%

/*
list_option : END | list END;

list
  : item
  | list item
  ;

item
  : UPPER
  | LOWER
  | WORD
  | NEWLINE
  | CHAR
  ;
*/

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
  : EmptyStatement
  | ExpressionStatement STMT_TER_OP
  | Block
  | IfStatement
  | SwitchStatement
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

EmptyStatement
  : STMT_TER_OP
  ;

ExpressionStatement
  : Expression
  ;

Block
  : OPEN_C Statements CLOSE_C
  ;

IfStatement
  : IF ParenthesizedExpression CodeStatement %prec "then"
  | IF ParenthesizedExpression CodeStatement ELSE CodeStatement
  ;

SwitchStatement
  : SWITCH ParenthesizedExpression OPEN_C CLOSE_C
  | SWITCH ParenthesizedExpression OPEN_C  CaseGroups LastCaseGroup CLOSE_C
  ;

CaseGroups
  : %empty
  | CaseGroups CaseGroup
  ;

CaseGroup
  : CaseGuards CaseStatementsPrefix
  ;

LastCaseGroup
  : CaseGuards CaseStatements
  ;

CaseGuards
  : CASE Expression PA_OP
  | DEFAULT PA_OP
  ;

CaseStatements
  : CodeStatement
  | CaseStatementsPrefix CodeStatement
  ;

CaseStatementsPrefix
  : CodeStatement
  | CaseStatementsPrefix CodeStatement
  ;

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
  | VariableDefinitionKind VariableBinding
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
  : VariableDefinitionKind VariableBindingList
  ;

VariableDefinitionKind
  : VAR
  | CONST
  ;

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
  : ConditionalExpression
  | PostfixExpression VA_OP AssignmentExpression
  | PostfixExpression CompoundAssignment AssignmentExpression
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
  : OPEN_P Expression CLOSE_P
  ;

Identifier
  : ID
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
  : PrimaryExpression
  | FullNewExpression
  | FullPostfixExpression MemberOperator
  | FullPostfixExpression Arguments
  | PostfixExpression UNIT_ADD_OP
  | PostfixExpression UNIT_SUB_OP
  | PostfixExpression LOGIC_NOT_OP
  | PostfixExpression BIT_NOT_OP
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
  : SimpleExpression
  // | FunctionExpression
  | ObjectLiteral
  ;

SimpleExpression
  : NULL_V
  | TRUE_V
  | FALSE_V
  | INT_V
  | FLT_V
  | STRING
  | QualifiedIdentifier
  | ParenthesizedExpression
  | ArrayLiteral
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
  : Identifier
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
  : UnaryExpression
  | MultiplicativeExpression MUL_OP UnaryExpression
  | MultiplicativeExpression DIV_OP UnaryExpression
  | MultiplicativeExpression MOD_OP UnaryExpression
  ;

UnaryExpression
  : PostfixExpression
  | UNIT_ADD_OP PostfixExpression
  | UNIT_SUB_OP PostfixExpression
  | ADD_OP UnaryExpression
  | SUB_OP UnaryExpression
  | BIT_NOT_OP UnaryExpression
  | LOGIC_NOT_OP UnaryExpression
  ;

%%
void 
JS::JS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}