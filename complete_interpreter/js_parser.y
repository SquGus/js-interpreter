/*
    Parser for JavaScript
*/
%{
/* IMPORT LIBRARIES, SYMBOL TABLE AND OTHER C CODE HERE */
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <math.h>
    #include <getopt.h>
    #include <setjmp.h>

    #ifndef JS_NO_REPL
        #include <readline/readline.h>
        #include <readline/history.h>
    #endif

    #include "lex.yy.h"
    #include "js_interpreter.h"
    #include "js_nodes.h"
    #include "js_eval.h"
    #include "js_runtime.h"
    #include "js_debug.h"
    #include "js_cli.h"

    /* Does not equips parser with tracing code */
    #define YYDEBUG 0

    /* Defines macros to create each ast_node struct that will build
     * the Abstract Syntax Tree. Each node has slot for three child
     * nodes, a double, a string and a type.
     */

    #define NEW_NODE(t,e1,e2,e3,d,s)   node_new(t,e1,e2,e3,d,s,yylloc.first_line,yylloc.first_column)

    #define NEW_ARGLST(head,tail)      NEW_NODE(NODE_ARG_LST,head,tail,0,0,0)
    #define NEW_ARR(ellst)             NEW_NODE(NODE_ARR,ellst,0,0,0,0)
    #define NEW_ASGN(a,b,op)           NEW_NODE(NODE_ASGN,a,b,0,0,op)
    #define NEW_BLOCK(stmtlst)         NEW_NODE(NODE_BLOCK,stmtlst,0,0,0,0)
    #define NEW_BOOL(x)                NEW_NODE(NODE_BOOL,0,0,0,x,0)
    #define NEW_BREAK()                NEW_NODE(NODE_BREAK,0,0,0,0,0)
    #define NEW_CALL(call,args)        NEW_NODE(NODE_CALL,call,args,0,0,0);
    // #define NEW_CASEBLOCK(c1,def,c2)   NEW_NODE(NODE_CASE_BLOCK,c1,def,c2,0,0)
    // #define NEW_CATCH(id,block)        NEW_NODE(NODE_CATCH,id,block,0,0,0)
    // #define NEW_CLAUSE(exp,stmtlst)    NEW_NODE(NODE_CLAUSE,exp,stmtlst,0,0,0)
    // #define NEW_CLAUSELST(head,tail)   NEW_NODE(NODE_CLAUSE_LST,head,tail,0,0,0)
    #define NEW_CONT()                 NEW_NODE(NODE_CONT,0,0,0,0,0)
    // #define NEW_DEBUGGER()             NEW_NODE(NODE_DEBUG_STMT,0,0,0,0,0)
    #define NEW_DOWHILE(cnd,blck)      NEW_NODE(NODE_DOWHILE,cnd,blck,0,0,0)
    #define NEW_ELISION()              NEW_NODE(NODE_ELISION,0,0,0,0,0)
    #define NEW_ELLST(head,tail)       NEW_NODE(NODE_EL_LST,head,tail,0,0,0)
    #define NEW_EMPTSTMT()             NEW_NODE(NODE_EMPT_STMT,0,0,0,0,0)
    #define NEW_EXP(a,b,op)            NEW_NODE(NODE_EXP,a,b,0,0,op)
    #define NEW_EXPGRP(e1,e2,e3)       NEW_NODE(NODE_EXPGRP,e1,e2,e3,0,0)
    #define NEW_EXPSTMT(exp)           NEW_NODE(NODE_EXP_STMT,exp,0,0,0,0)
    // #define NEW_FINALLY(block)         NEW_NODE(NODE_FINALLY,block,0,0,0,0)
    #define NEW_FOR(exps,stmt)         NEW_NODE(NODE_FOR,exps,stmt,0,0,0)
    // #define NEW_FORIN(lhs,in,stmt)     NEW_NODE(NODE_FORIN,lhs,in,stmt,0,0)
    #define NEW_FUNC(params,body,id)   NEW_NODE(NODE_FUNC,params,body,id,0,0)
    #define NEW_IDENT(name)            NEW_NODE(NODE_IDENT,0,0,0,0,name)
    #define NEW_IF(p,q,r)              NEW_NODE(NODE_IF,p,q,r,0,0)
    #define NEW_MEMBER(head,tail,exp)  NEW_NODE(NODE_MEMBER,head,tail,0,exp,0)
    #define NEW_NEW(exp)               NEW_NODE(NODE_NEW,exp,0,0,0,0);
    #define NEW_NULL()                 NEW_NODE(NODE_NULL,0,0,0,0,0)
    #define NEW_NUM(x)                 NEW_NODE(NODE_NUM,0,0,0,x,0)
    #define NEW_OBJ(proplst)           NEW_NODE(NODE_OBJ,proplst,0,0,0,0)
    #define NEW_PARAMLST(head,tail)    NEW_NODE(NODE_PARAM_LST,head,tail,0,0,0)
    #define NEW_PROP(name,exp)         NEW_NODE(NODE_PROP,name,exp,0,0,0)
    #define NEW_PROPLST(head,tail)     NEW_NODE(NODE_PROP_LST,head,tail,0,0,0)
    // #define NEW_REGEXP(x)              NEW_NODE(NODE_REGEXP,0,0,0,0,x)
    #define NEW_RETURN(exp)            NEW_NODE(NODE_RETURN,exp,0,0,0,0)
    #define NEW_SRCLST(head,tail)      NEW_NODE(NODE_SRC_LST,head,tail,0,0,0)
    #define NEW_STMTLST(head,tail)     NEW_NODE(NODE_STMT_LST,head,tail,0,0,0)
    #define NEW_STR(x)                 NEW_NODE(NODE_STR,0,0,0,0,x)
    #define NEW_SWITCH(exp,cases)      NEW_NODE(NODE_SWITCH_STMT,exp,cases,0,0,0)
    #define NEW_TERN(p,q,r)            NEW_NODE(NODE_TERN,p,q,r,0,0)
    // #define NEW_THIS()                 NEW_NODE(NODE_THIS,0,0,0,0,0)
    // #define NEW_THROW(exp)             NEW_NODE(NODE_THROW,exp,0,0,0,0)
    // #define NEW_TRY(block,catch,final) NEW_NODE(NODE_TRY_STMT,block,catch,final,0,0)
    #define NEW_UNPOST(a,op)           NEW_NODE(NODE_UNARY_POST,a,0,0,0,op)
    #define NEW_UNPRE(a,op)            NEW_NODE(NODE_UNARY_PRE,a,0,0,0,op)
    #define NEW_VARDEC(id,exp)         NEW_NODE(NODE_VAR_DEC,id,exp,0,0,0)
    #define NEW_VARDECLST(head,tail)   NEW_NODE(NODE_VAR_DEC_LST,head,tail,0,0,0)
    #define NEW_VARSTMT(declst)        NEW_NODE(NODE_VAR_STMT,declst,0,0,0,0)
    #define NEW_WHILE(cnd,blck)        NEW_NODE(NODE_WHILE,cnd,blck,0,0,0)
    // #define NEW_WITH(exp,stmt)         NEW_NODE(NODE_WITH_STMT,exp,stmt,0,0,0)

    void yyerror(const char *);
    int yycolumn;
    int yydebug;
    int js_get_input(char *, int);
    ast_node *root;
    eval_state *state;
    js_state *js;
%}

/* PARSE OPTIONS */
/* Directive standing for ‘%define parse.error verbose’ */
%error-verbose
/* Allows for more accurate syntax error messages. */
%locations

/* LITERALS */
%token<floatval> NUMBER
%token<val> IDENT STRING TRUE FALSE

/* OPERATORS */
%token<val> LOGIC_AND_OP LOGIC_OR_OP
%token<val> UNIT_ADD_OP UNIT_SUB_OP TYPEOF
%token<val> EQ_V_OP GE_OP LE_OP NEG_V_OP EQ_VT_OP NEG_VT_OP INSTANCEOF
%token<val> BIT_SHIFT_L_OP BIT_SHIFT_S_R_OP BIT_SHIFT_Z_R_OP
%token<val> SHORT_ADD_OP SHORT_SUB_OP SHORT_MUL_OP SHORT_DIV_OP SHORT_MOD_OP
%token<val> SHORT_BIT_SHIFT_L_OP SHORT_BIT_SHIFT_S_R_OP SHORT_BIT_SHIFT_Z_R_OP
%token<val> SHORT_BIT_AND_OP SHORT_BIT_XOR_OP SHORT_BIT_OR_OP

/* KEYWORDS */
%token<val> WHILE DO FOR
%token<val> IF ELSE
%token<val> BREAK CONTINUE RETURNT
%token<val> VAR NULLT FUNCTION NEW

/* ASSOCIATIVITY */
%left '+' '-' '*' '%' '/' LOGIC_AND_OP LOGIC_OR_OP

/* SEMANTIC RECORDS */
%union {
    char *val;
    int intval;
    double floatval;
    struct ast_node *node;
}

/* TYPE OF PRODUCTIONS */
%type<val> AssignmentOperator

%type<node> AdditiveExpression
%type<node> AdditiveExpressionNoFn
// %type<node> AnonymousFunction
%type<node> ArgumentList
%type<node> Arguments
%type<node> ArrayLiteral
%type<node> AssignmentExpression
%type<node> AssignmentExpressionNoIn
%type<node> AssignmentExpressionNoFn
%type<node> BitwiseANDExpression
%type<node> BitwiseANDExpressionNoIn
%type<node> BitwiseANDExpressionNoFn
%type<node> BitwiseORExpression
%type<node> BitwiseORExpressionNoIn
%type<node> BitwiseORExpressionNoFn
%type<node> BitwiseXORExpression
%type<node> BitwiseXORExpressionNoIn
%type<node> BitwiseXORExpressionNoFn
%type<node> Block
%type<node> BooleanLiteral
%type<node> BreakStatement
%type<node> CallExpression
%type<node> CallExpressionNoFn
// %type<node> CaseBlock
// %type<node> CaseClause
// %type<node> CaseClauses
// %type<node> Catch
%type<node> ConditionalExpression
%type<node> ConditionalExpressionNoIn
%type<node> ConditionalExpressionNoFn
%type<node> ContinueStatement
// %type<node> DebuggerStatement
// %type<node> DefaultClause
%type<node> ElementList
%type<node> Elision
%type<node> EmptyStatement
%type<node> EqualityExpression
%type<node> EqualityExpressionNoIn
%type<node> EqualityExpressionNoFn
%type<node> Expression
%type<node> ExpressionNoIn
%type<node> ExpressionNoFn
%type<node> ExpressionStatement
// %type<node> Finally
%type<node> FormalParameterList
%type<node> FunctionBody
%type<node> FunctionDeclaration
%type<node> FunctionExpression
%type<node> Identifier
%type<node> IfStatement
%type<node> Initializer
%type<node> InitializerNoIn
%type<node> IterationStatement
%type<node> LeftHSExpression
%type<node> LeftHSExpressionNoFn
%type<node> Literal
%type<node> LiteralNoObj
%type<node> LogicalANDExpression
%type<node> LogicalANDExpressionNoIn
%type<node> LogicalANDExpressionNoFn
%type<node> LogicalORExpression
%type<node> LogicalORExpressionNoIn
%type<node> LogicalORExpressionNoFn
%type<node> MemberExpression
%type<node> MemberExpressionNoFn
%type<node> MultiExpression
%type<node> MultiExpressionNoFn
%type<node> NamedFunction
%type<node> NewExpression
%type<node> NewExpressionNoFn
%type<node> NullLiteral
%type<node> NumericLiteral
%type<node> ObjectLiteral
%type<node> PostfixExpression
%type<node> PostfixExpressionNoFn
%type<node> PrimaryExpression
%type<node> PrimaryExpressionNoObj
%type<node> Program
%type<node> PropertyAssignment
%type<node> PropertyName
%type<node> PropertyNameAndValueList
// %type<node> RegularExpressionLiteral
%type<node> RelationalExpression
%type<node> RelationalExpressionNoIn
%type<node> RelationalExpressionNoFn
%type<node> ReturnStatement
%type<node> ShiftExpression
%type<node> ShiftExpressionNoFn
%type<node> SourceElement
%type<node> SourceElements
%type<node> Statement
%type<node> StatementList
%type<node> StringLiteral
// %type<node> SwitchStatement
// %type<node> ThrowStatement
// %type<node> TryStatement
%type<node> UnaryExpression
%type<node> UnaryExpressionNoFn
%type<node> VariableDecList
%type<node> VariableDecListNoIn
%type<node> VariableDeclaration
%type<node> VariableDeclarationNoIn
%type<node> VariableStatement
// %type<node> WithStatement

/* GRAMMAR RULES */
%%

Program                  : SourceElements
                             { root = $1; }
                         ;

SourceElements           : SourceElement
                             { $$ = NEW_SRCLST($1, NULL); }
                         | SourceElements SourceElement
                             { $$ = NEW_SRCLST($2, $1); }
                         ;

SourceElement            : Statement
                             { $$ = $1; }
                         | FunctionDeclaration
                             { $$ = $1; }
                         ;

Statement                : Block
                             { $$ = $1; }
                         | VariableStatement
                             { $$ = $1; }
                         | EmptyStatement
                             { $$ = $1; }
                         | ExpressionStatement
                             { $$ = $1; }
                         | IfStatement
                             { $$ = $1; }
                         | IterationStatement
                             { $$ = $1; }
                         | ContinueStatement
                             { $$ = $1; }
                         | BreakStatement
                             { $$ = $1; }
                         | ReturnStatement
                             { $$ = $1; }
                         // | ThrowStatement
                         //     { $$ = $1; }
                         // | TryStatement
                         //     { $$ = $1; }
                         // | WithStatement
                         //     { $$ = $1; }
                         // | SwitchStatement
                         //     { $$ = $1; }
                         // | DebuggerStatement
                         //     { $$ = $1; }
                         ;

Block                    : '{' '}'
                             { $$ = NEW_BLOCK(NULL); }
                         | '{' StatementList '}'
                             { $$ = NEW_BLOCK($2); }
                         ;

StatementList            : Statement
                             { $$ = NEW_STMTLST($1, NULL); }
                         | StatementList Statement
                             { $$ = NEW_STMTLST($2, $1); }
                         ;

VariableStatement        : VAR VariableDecList ';'
                             { $$ = NEW_VARSTMT($2); }
                         ;

VariableDecList          : VariableDeclaration
                             { $$ = NEW_VARDECLST($1, NULL); }
                         | VariableDecList ',' VariableDeclaration
                             { $$ = NEW_VARDECLST($3, $1); }
                         ;

VariableDecListNoIn      : VariableDeclarationNoIn
                             { $$ = NEW_VARDECLST($1, NULL); }
                         | VariableDecListNoIn ',' VariableDeclarationNoIn
                             { $$ = NEW_VARDECLST($3, $1); }
                         ;

VariableDeclaration      : Identifier Initializer
                             { $$ = NEW_VARDEC($1, $2); }
                         | Identifier
                             { $$ = NEW_VARDEC($1, NULL); }
                         ;

VariableDeclarationNoIn  : Identifier InitializerNoIn
                             { $$ = NEW_VARDEC($1, $2); }
                         | Identifier
                             { $$ = NEW_VARDEC($1, NULL); }
                         ;

Initializer              : '=' AssignmentExpression
                             { $$ = $2; }
                         ;

InitializerNoIn          : '=' AssignmentExpressionNoIn
                             { $$ = $2; }
                         ;

EmptyStatement           : ';'
                             { $$ = NEW_EMPTSTMT(); }
                         ;

ExpressionStatement      : ExpressionNoFn ';'
                             { $$ = NEW_EXPSTMT($1); }
                         ;

IfStatement              : IF '(' Expression ')' Statement ELSE Statement
                             { $$ = NEW_IF($3, $5, $7); }
                         | IF '(' Expression ')' Statement
                             { $$ = NEW_IF($3, $5, NULL); }
                         ;

IterationStatement       : DO Statement WHILE '(' Expression ')' ';'
                             { $$ = NEW_DOWHILE($2, $5); }
                         | WHILE '(' Expression ')' Statement
                             { $$ = NEW_WHILE($3, $5); }

                         /* for ( LHS/VarDecl in Expression ) Statement */

                         // | FOR '(' LeftHSExpression IN Expression ')' Statement
                         //     { $$ = NEW_FORIN($3, $5, $7); }
                         // | FOR '(' VAR VariableDeclarationNoIn IN Expression ')' Statement
                         //     { $$ = NEW_FORIN($4, $6, $8); }

                         /* for ( Expression/VarDecl ; Expresion ; Expression ) Statement */

                         | FOR '(' ExpressionNoIn ';' Expression ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($3, $5, $7), $9); }
                         | FOR '(' VAR VariableDecListNoIn ';' Expression ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($4, $6, $8), $10); }
                         | FOR '(' ExpressionNoIn ';' Expression ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($3, $5, NULL), $8); }
                         | FOR '(' VAR VariableDecListNoIn ';' Expression ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($4, $6, NULL), $9); }
                         | FOR '(' ExpressionNoIn ';' ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($3, NULL, $6), $8); }
                         | FOR '(' VAR VariableDecListNoIn ';' ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($4, NULL, $7), $9); }
                         | FOR '(' ExpressionNoIn ';' ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($3, NULL, NULL), $7); }
                         | FOR '(' VAR VariableDecListNoIn ';' ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP($4, NULL, NULL), $8); }
                         | FOR '(' ';' Expression ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP(NULL, $4, $6), $8); }
                         | FOR '(' ';' Expression ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP(NULL, $4, NULL), $7); }
                         | FOR '(' ';' ';' Expression ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP(NULL, NULL, $5), $7); }
                         | FOR '(' ';' ';' ')' Statement
                             { $$ = NEW_FOR(NEW_EXPGRP(NULL, NULL, NULL), $6); }
                         ;

ContinueStatement        : CONTINUE ';'
                             { $$ = NEW_CONT(); }
                         ;

BreakStatement           : BREAK ';'
                             { $$ = NEW_BREAK(); }
                         ;

ReturnStatement          : RETURNT ';'
                             { $$ = NEW_RETURN(NULL); }
                         | RETURNT Expression ';'
                             { $$ = NEW_RETURN($2); }
                         ;

// WithStatement            : WITH '(' Expression ')' Statement
//                              { $$ = NEW_WITH($3, $5); }
//                          ;

// TryStatement             : TRY Block Catch
//                              { $$ = NEW_TRY($2, $3, NULL); }
//                          | TRY Block Finally
//                              { $$ = NEW_TRY($2, NULL, $3); }
//                          | TRY Block Catch Finally
//                              { $$ = NEW_TRY($2, $3, $4); }
//                          ;

// Catch                    : CATCH '(' Identifier ')' Block
//                              { $$ = NEW_CATCH($3, $5); }
//                          ;

// Finally                  : FINALLY Block
//                              { $$ = NEW_FINALLY($2); }
//                          ;

// DebuggerStatement        : DEBUGGER ';'
//                              { $$ = NEW_DEBUGGER(); }
//                          ;

// ThrowStatement           : THROW Expression ';'
//                              { $$ = NEW_THROW($2); }
//                          ;

// SwitchStatement          : SWITCH '(' Expression ')' CaseBlock
//                              { $$ = NEW_SWITCH($3, $5); }
//                          ;

// CaseBlock                : '{' CaseClauses '}'
//                              { $$ = NEW_CASEBLOCK($2, NULL, NULL); }
//                          | '{' DefaultClause '}'
//                              { $$ = NEW_CASEBLOCK(NULL, $2, NULL); }
//                          | '{' CaseClauses DefaultClause '}'
//                              { $$ = NEW_CASEBLOCK($2, $3, NULL); }
//                          | '{' CaseClauses DefaultClause CaseClauses '}'
//                              { $$ = NEW_CASEBLOCK($2, $3, $4); }
//                          ;

// CaseClauses              : CaseClause
//                              { $$ = NEW_CLAUSELST($1, NULL); }
//                          | CaseClauses CaseClause
//                              { $$ = NEW_CLAUSELST($2, $1); }

// CaseClause               : CASE Expression ':' StatementList
//                              { $$ = NEW_CLAUSE($2, $4); }
//                          | CASE Expression ':'
//                              { $$ = NEW_CLAUSE($2, NULL); }
//                          ;

// DefaultClause            : DEFAULT ':' StatementList
//                              { $$ = NEW_CLAUSE(NULL, $3); }
//                          | DEFAULT ':'
//                              { $$ = NEW_CLAUSE(NULL, NULL); }
//                          ;

Literal                  : NullLiteral
                             { $$ = $1; }
                         | BooleanLiteral
                             { $$ = $1; }
                         | NumericLiteral
                             { $$ = $1; }
                         | StringLiteral
                             { $$ = $1; }
                         | ObjectLiteral
                             { $$ = $1; }
                         // | RegularExpressionLiteral
                         //     { $$ = $1; }
                         ;

LiteralNoObj             : NullLiteral
                             { $$ = $1; }
                         | BooleanLiteral
                             { $$ = $1; }
                         | NumericLiteral
                             { $$ = $1; }
                         | StringLiteral
                             { $$ = $1; }
                         // | RegularExpressionLiteral
                         //     { $$ = $1; }
                         ;

ArrayLiteral             : '[' ']'
                             { $$ = NEW_ARR(NULL); }
                         | '[' Elision ']'
                             { $$ = NEW_ARR(NULL); }
                         | '[' ElementList ']'
                             { $$ = NEW_ARR($2); }
                         | '[' ElementList ',' ']'
                             { $$ = NEW_ARR($2); }
                         | '[' ElementList ',' Elision ']'
                             { $$ = NEW_ARR($2); }
                         ;

Elision                  : ','
                             { $$ = NEW_ELISION(); }
                         | Elision ','
                             { $$ = NEW_ELISION(); }
                         ;

ElementList              : AssignmentExpression
                             { $$ = NEW_ELLST($1, NULL); }
                         | Elision AssignmentExpression
                             { $$ = NEW_ELLST($2, NULL); }
                         | ElementList ',' AssignmentExpression
                             { $$ = NEW_ELLST($3, $1); }
                         | ElementList ',' Elision AssignmentExpression
                             { $$ = NEW_ELLST($4, $1); }
                         ;

BooleanLiteral           : TRUE
                             { $$ = NEW_BOOL(1); }
                         | FALSE
                             { $$ = NEW_BOOL(0); }
                         ;

StringLiteral            : STRING
                             { $$ = NEW_STR($1); }
                         ;

NullLiteral              : NULLT
                             { $$ = NEW_NULL(); }
                         ;

NumericLiteral           : NUMBER
                             { $$ = NEW_NUM($1); }
                         ;

ObjectLiteral            : '{' '}'
                             { $$ = NEW_OBJ(NULL); }
                         | '{' PropertyNameAndValueList '}'
                             { $$ = NEW_OBJ($2); }
                         | '{' PropertyNameAndValueList ',' '}'
                             { $$ = NEW_OBJ($2); }
                         ;

PropertyNameAndValueList : PropertyAssignment
                             { $$ = NEW_PROPLST($1, NULL); }
                         | PropertyNameAndValueList ',' PropertyAssignment
                             { $$ = NEW_PROPLST($3, $1); }
                         ;

PropertyAssignment       : PropertyName ':' AssignmentExpression
                             { $$ = NEW_PROP($1, $3); }
                         ;

PropertyName             : Identifier
                             { $$ = $1; }
                         | StringLiteral
                             { $$ = $1; }
                         | NumericLiteral
                             { $$ = $1; }
                         ;

// RegularExpressionLiteral : REGEXP
//                              { $$ = NEW_REGEXP($1); }
//                          ;

                         /* Whether a named function is a declaration or expression is ambiguous
                            here. We'll decide that on evaluation. */
NamedFunction            : FUNCTION Identifier '(' FormalParameterList ')' '{' FunctionBody '}'
                             { $$ = NEW_FUNC($4, $7, $2); }
                         | FUNCTION Identifier '(' ')' '{' FunctionBody '}'
                             { $$ = NEW_FUNC(NULL, $6, $2); }
                         ;

                         /* Anonymous functions, OTOH, can readily be labeled expressions. */
// AnonymousFunction        : FUNCTION '(' FormalParameterList ')' '{' FunctionBody '}'
//                              { $$ = NEW_FUNC($3, $6, NULL); }
//                          | FUNCTION '(' ')' '{' FunctionBody '}'
//                              { $$ = NEW_FUNC(NULL, $5, NULL); }
//                          ;

FunctionDeclaration      : NamedFunction
                             { $$ = $1; }
                         ;

FunctionExpression       : NamedFunction
                             { $$ = $1; }
                         // | AnonymousFunction
                         //     { $$ = $1; }
                         ;

FormalParameterList      : Identifier
                             { $$ = NEW_PARAMLST($1, NULL); }
                         | FormalParameterList ',' Identifier
                             { $$ = NEW_PARAMLST($3, $1); }
                         ;

FunctionBody             : SourceElements
                             { $$ = $1; }
                         |
                             { $$ = NULL; }
                         ;

Identifier               : IDENT
                             { $$ = NEW_IDENT($1); }
                         ;

PrimaryExpression        : Identifier
                             { $$ = $1; }
                         // | THIS
                         //     { $$ = NEW_THIS(); }
                         | Literal
                             { $$ = $1; }
                         | ArrayLiteral
                             { $$ = $1; }
                         | '(' Expression ')'
                             { $$ = $2; }
                         ;

PrimaryExpressionNoObj   : Identifier
                             { $$ = $1; }
                         // | THIS
                         //     { $$ = NEW_THIS(); }
                         | LiteralNoObj
                             { $$ = $1; }
                         | ArrayLiteral
                             { $$ = $1; }
                         | '(' Expression ')'
                             { $$ = $2; }
                         ;

ConditionalExpression    : LogicalORExpression
                             { $$ = $1; }
                         | LogicalORExpression '?' AssignmentExpression ':' AssignmentExpression
                             { $$ = NEW_TERN($1, $3, $5); }
                         ;

ConditionalExpressionNoIn: LogicalORExpressionNoIn
                             { $$ = $1; }
                         | LogicalORExpressionNoIn '?' AssignmentExpression ':' AssignmentExpressionNoIn
                             { $$ = NEW_TERN($1, $3, $5); }
                         ;

ConditionalExpressionNoFn: LogicalORExpressionNoFn
                             { $$ = $1; }
                         | LogicalORExpressionNoFn '?' AssignmentExpression ':' AssignmentExpression
                             { $$ = NEW_TERN($1, $3, $5); }
                         ;

LogicalORExpression      : LogicalANDExpression
                             { $$ = $1; }
                         | LogicalORExpression LOGIC_OR_OP LogicalANDExpression
                             { $$ = NEW_EXP($1, $3, "||"); }
                         ;

LogicalORExpressionNoIn  : LogicalANDExpressionNoIn
                             { $$ = $1; }
                         | LogicalORExpressionNoIn LOGIC_OR_OP LogicalANDExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "||"); }
                         ;

LogicalORExpressionNoFn  : LogicalANDExpressionNoFn
                             { $$ = $1; }
                         | LogicalORExpressionNoFn LOGIC_OR_OP LogicalANDExpression
                             { $$ = NEW_EXP($1, $3, "||"); }
                         ;

LogicalANDExpression     : BitwiseORExpression
                             { $$ = $1; }
                         | LogicalANDExpression LOGIC_AND_OP BitwiseORExpression
                             { $$ = NEW_EXP($1, $3, "&&"); }
                         ;

LogicalANDExpressionNoIn : BitwiseORExpressionNoIn
                             { $$ = $1; }
                         | LogicalANDExpressionNoIn LOGIC_AND_OP BitwiseORExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "&&"); }
                         ;

LogicalANDExpressionNoFn : BitwiseORExpressionNoFn
                             { $$ = $1; }
                         | LogicalANDExpressionNoFn LOGIC_AND_OP BitwiseORExpression
                             { $$ = NEW_EXP($1, $3, "&&"); }
                         ;

BitwiseORExpression      : BitwiseXORExpression
                             { $$ = $1; }
                         | BitwiseORExpression '|' BitwiseXORExpression
                             { $$ = NEW_EXP($1, $3, "|"); }
                         ;

BitwiseORExpressionNoIn  : BitwiseXORExpressionNoIn
                             { $$ = $1; }
                         | BitwiseORExpressionNoIn '|' BitwiseXORExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "|"); }
                         ;

BitwiseORExpressionNoFn  : BitwiseXORExpressionNoFn
                             { $$ = $1; }
                         | BitwiseORExpressionNoFn '|' BitwiseXORExpression
                             { $$ = NEW_EXP($1, $3, "|"); }
                         ;

BitwiseXORExpression     : BitwiseANDExpression
                             { $$ = $1; }
                         | BitwiseXORExpression '^' BitwiseANDExpression
                             { $$ = NEW_EXP($1, $3, "^"); }
                         ;

BitwiseXORExpressionNoIn : BitwiseANDExpressionNoIn
                             { $$ = $1; }
                         | BitwiseXORExpressionNoIn '^' BitwiseANDExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "^"); }
                         ;

BitwiseXORExpressionNoFn : BitwiseANDExpressionNoFn
                             { $$ = $1; }
                         | BitwiseXORExpressionNoFn '^' BitwiseANDExpression
                             { $$ = NEW_EXP($1, $3, "^"); }
                         ;

BitwiseANDExpression     : EqualityExpression
                             { $$ = $1; }
                         | BitwiseANDExpression '&' EqualityExpression
                             { $$ = NEW_EXP($1, $3, "&"); }
                         ;

BitwiseANDExpressionNoIn : EqualityExpressionNoIn
                             { $$ = $1; }
                         | BitwiseANDExpressionNoIn '&' EqualityExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "&"); }
                         ;

BitwiseANDExpressionNoFn : EqualityExpressionNoFn
                             { $$ = $1; }
                         | BitwiseANDExpressionNoFn '&' EqualityExpression
                             { $$ = NEW_EXP($1, $3, "&"); }
                         ;

EqualityExpression       : RelationalExpression
                             { $$ = $1; }
                         | EqualityExpression EQ_V_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "=="); }
                         | EqualityExpression NEG_V_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "!="); }
                         | EqualityExpression EQ_VT_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "==="); }
                         | EqualityExpression NEG_VT_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "!=="); }
                         ;

EqualityExpressionNoIn   : RelationalExpressionNoIn
                             { $$ = $1; }
                         | EqualityExpressionNoIn EQ_V_OP RelationalExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "=="); }
                         | EqualityExpressionNoIn NEG_V_OP RelationalExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "!="); }
                         | EqualityExpressionNoIn EQ_VT_OP RelationalExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "==="); }
                         | EqualityExpressionNoIn NEG_VT_OP RelationalExpressionNoIn
                             { $$ = NEW_EXP($1, $3, "!=="); }
                         ;

EqualityExpressionNoFn   : RelationalExpressionNoFn
                             { $$ = $1; }
                         | EqualityExpressionNoFn EQ_V_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "=="); }
                         | EqualityExpressionNoFn NEG_V_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "!="); }
                         | EqualityExpressionNoFn EQ_VT_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "==="); }
                         | EqualityExpressionNoFn NEG_VT_OP RelationalExpression
                             { $$ = NEW_EXP($1, $3, "!=="); }
                         ;

RelationalExpression     : ShiftExpression
                             { $$ = $1; }
                         | RelationalExpression '<' ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<"); }
                         | RelationalExpression '>' ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">"); }
                         | RelationalExpression LE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<="); }
                         | RelationalExpression GE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">="); }
                         | RelationalExpression INSTANCEOF ShiftExpression
                             { $$ = NEW_EXP($1, $3, "instanceof"); }
                         // | RelationalExpression IN ShiftExpression
                         //     { $$ = NEW_EXP($1, $3, "in"); }
                         ;

RelationalExpressionNoIn : ShiftExpression
                             { $$ = $1; }
                         | RelationalExpressionNoIn '<' ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<"); }
                         | RelationalExpressionNoIn '>' ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">"); }
                         | RelationalExpressionNoIn LE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<="); }
                         | RelationalExpressionNoIn GE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">="); }
                         | RelationalExpressionNoIn INSTANCEOF ShiftExpression
                             { $$ = NEW_EXP($1, $3, "instanceof"); }
                         ;

RelationalExpressionNoFn : ShiftExpressionNoFn
                             { $$ = $1; }
                         | RelationalExpressionNoFn '<' ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<"); }
                         | RelationalExpressionNoFn '>' ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">"); }
                         | RelationalExpressionNoFn LE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, "<="); }
                         | RelationalExpressionNoFn GE_OP ShiftExpression
                             { $$ = NEW_EXP($1, $3, ">="); }
                         | RelationalExpressionNoFn INSTANCEOF ShiftExpression
                             { $$ = NEW_EXP($1, $3, "instanceof"); }
                         ;

ShiftExpression          : AdditiveExpression
                             { $$ = $1; }
                         | ShiftExpression BIT_SHIFT_L_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, "<<"); }
                         | ShiftExpression BIT_SHIFT_S_R_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, ">>"); }
                         | ShiftExpression BIT_SHIFT_Z_R_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, ">>>"); }
                         ;

ShiftExpressionNoFn      : AdditiveExpressionNoFn
                             { $$ = $1; }
                         | ShiftExpressionNoFn BIT_SHIFT_L_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, "<<"); }
                         | ShiftExpressionNoFn BIT_SHIFT_S_R_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, ">>"); }
                         | ShiftExpressionNoFn BIT_SHIFT_Z_R_OP AdditiveExpression
                             { $$ = NEW_EXP($1, $3, ">>>"); }
                         ;

AdditiveExpression       : MultiExpression
                             { $$ = $1; }
                         | AdditiveExpression '+' MultiExpression
                             { $$ = NEW_EXP($1, $3, "+"); }
                         | AdditiveExpression '-' MultiExpression
                             { $$ = NEW_EXP($1, $3, "-"); }
                         ;

AdditiveExpressionNoFn   : MultiExpressionNoFn
                             { $$ = $1; }
                         | AdditiveExpressionNoFn '+' MultiExpression
                             { $$ = NEW_EXP($1, $3, "+"); }
                         | AdditiveExpressionNoFn '-' MultiExpression
                             { $$ = NEW_EXP($1, $3, "-"); }
                         ;

MultiExpression          : UnaryExpression
                             { $$ = $1; }
                         | MultiExpression '*' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "*"); }
                         | MultiExpression '/' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "/"); }
                         | MultiExpression '%' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "%"); }
                         ;

MultiExpressionNoFn      : UnaryExpressionNoFn
                             { $$ = $1; }
                         | MultiExpressionNoFn '*' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "*"); }
                         | MultiExpressionNoFn '/' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "/"); }
                         | MultiExpressionNoFn '%' UnaryExpression
                             { $$ = NEW_EXP($1, $3, "%"); }
                         ;

UnaryExpression          : PostfixExpression
                             { $$ = $1; }
                         // | DELETE UnaryExpression
                         //     { $$ = NEW_UNPRE($2, "delete"); }
                         // | VOID UnaryExpression
                         //     { $$ = NEW_UNPRE($2, "void"); }
                         | TYPEOF UnaryExpression
                             { $$ = NEW_UNPRE($2, "typeof"); }
                         | UNIT_ADD_OP UnaryExpression
                             { $$ = NEW_UNPRE($2, "++"); }
                         | UNIT_SUB_OP UnaryExpression
                             { $$ = NEW_UNPRE($2, "--"); }
                         | '+' UnaryExpression
                             { $$ = NEW_UNPRE($2, "+"); }
                         | '-' UnaryExpression
                             { $$ = NEW_UNPRE($2, "-"); }
                         | '!' UnaryExpression
                             { $$ = NEW_UNPRE($2, "!"); }
                         | '~' UnaryExpression
                             { $$ = NEW_UNPRE($2, "~"); }
                         ;

UnaryExpressionNoFn      : PostfixExpressionNoFn
                             { $$ = $1; }
                         // | DELETE UnaryExpression
                         //     { $$ = NEW_UNPRE($2, "delete"); }
                         // | VOID UnaryExpression
                         //     { $$ = NEW_UNPRE($2, "void"); }
                         | TYPEOF UnaryExpression
                             { $$ = NEW_UNPRE($2, "typeof"); }
                         | UNIT_ADD_OP UnaryExpression
                             { $$ = NEW_UNPRE($2, "++"); }
                         | UNIT_SUB_OP UnaryExpression
                             { $$ = NEW_UNPRE($2, "--"); }
                         | '+' UnaryExpression
                             { $$ = NEW_UNPRE($2, "+"); }
                         | '-' UnaryExpression
                             { $$ = NEW_UNPRE($2, "-"); }
                         | '!' UnaryExpression
                             { $$ = NEW_UNPRE($2, "!"); }
                         | '~' UnaryExpression
                             { $$ = NEW_UNPRE($2, "~"); }
                         ;

PostfixExpression        : LeftHSExpression
                             { $$ = $1; }
                         | LeftHSExpression UNIT_ADD_OP
                             { $$ = NEW_UNPOST($1, "++"); }
                         | LeftHSExpression UNIT_SUB_OP
                             { $$ = NEW_UNPOST($1, "--"); }
                         ;

PostfixExpressionNoFn    : LeftHSExpressionNoFn
                             { $$ = $1; }
                         | LeftHSExpressionNoFn UNIT_ADD_OP
                             { $$ = NEW_UNPOST($1, "++"); }
                         | LeftHSExpressionNoFn UNIT_SUB_OP
                             { $$ = NEW_UNPOST($1, "--"); }
                         ;

Expression               : AssignmentExpression
                             { $$ = $1; }
                         | Expression ',' AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, 0); }
                         ;

ExpressionNoIn           : AssignmentExpressionNoIn
                             { $$ = $1; }
                         | ExpressionNoIn ',' AssignmentExpressionNoIn
                             { $$ = NEW_ASGN($1, $3, 0); }
                         ;

ExpressionNoFn           : AssignmentExpressionNoFn
                             { $$ = $1; }
                         | ExpressionNoFn ',' AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, 0); }
                         ;

AssignmentExpression     : ConditionalExpression
                             { $$ = $1; }
                         | LeftHSExpression '=' AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, "="); }
                         | LeftHSExpression AssignmentOperator AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, $2); }
                         ;

AssignmentExpressionNoIn : ConditionalExpressionNoIn
                             { $$ = $1; }
                         | LeftHSExpression '=' AssignmentExpressionNoIn
                             { $$ = NEW_ASGN($1, $3, "="); }
                         | LeftHSExpression AssignmentOperator AssignmentExpressionNoIn
                             { $$ = NEW_ASGN($1, $3, $2); }
                         ;

AssignmentExpressionNoFn : ConditionalExpressionNoFn
                             { $$ = $1; }
                         | LeftHSExpressionNoFn '=' AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, "="); }
                         | LeftHSExpressionNoFn AssignmentOperator AssignmentExpression
                             { $$ = NEW_ASGN($1, $3, $2); }
                         ;

AssignmentOperator       : SHORT_ADD_OP
                             { $$ = "+="; }
                         | SHORT_SUB_OP
                             { $$ = "-="; }
                         | SHORT_MUL_OP
                             { $$ = "*="; }
                         | SHORT_DIV_OP
                             { $$ = "/="; }
                         | SHORT_MOD_OP
                             { $$ = "%="; }
                         | SHORT_BIT_SHIFT_L_OP
                             { $$ = "<<="; }
                         | SHORT_BIT_SHIFT_S_R_OP
                             { $$ = ">>="; }
                         | SHORT_BIT_SHIFT_Z_R_OP
                             { $$ = ">>>="; }
                         | SHORT_BIT_AND_OP
                             { $$ = "&="; }
                         | SHORT_BIT_XOR_OP
                             { $$ = "^="; }
                         | SHORT_BIT_OR_OP
                             { $$ = "|="; }
                         ;

LeftHSExpression         : NewExpression
                             { $$ = $1; }
                         | CallExpression
                             { $$ = $1; }
                         ;

LeftHSExpressionNoFn     : NewExpressionNoFn
                             { $$ = $1; }
                         | CallExpressionNoFn
                             { $$ = $1; }
                         ;

CallExpression           : MemberExpression Arguments
                             { $$ = NEW_CALL($1, $2); }
                         | CallExpression Arguments
                             { $$ = NEW_CALL($1, $2); }
                         | CallExpression '[' Expression ']'
                             { $$ = NEW_CALL($1, $3); }
                         | CallExpression '.' Identifier
                             { $$ = NEW_CALL($1, $3); }
                         ;

CallExpressionNoFn       : MemberExpressionNoFn Arguments
                             { $$ = NEW_CALL($1, $2); }
                         | CallExpressionNoFn Arguments
                             { $$ = NEW_CALL($1, $2); }
                         | CallExpressionNoFn '[' Expression ']'
                             { $$ = NEW_CALL($1, $3); }
                         | CallExpressionNoFn '.' Identifier
                             { $$ = NEW_CALL($1, $3); }
                         ;

NewExpression            : MemberExpression
                             { $$ = $1; }
                         | NEW NewExpression
                             { $$ = NEW_NEW($2); }
                         ;

NewExpressionNoFn        : MemberExpressionNoFn
                             { $$ = $1; }
                         | NEW NewExpression
                             { $$ = NEW_NEW($2); }
                         ;

MemberExpression         : PrimaryExpression
                             { $$ = $1; }
                         | FunctionExpression
                             { $$ = $1; }
                         | MemberExpression '[' Expression ']'
                             { $$ = NEW_MEMBER($3, $1, 42); }
                         | MemberExpression '.' Identifier
                             { $$ = NEW_MEMBER($3, $1, false); }
                         | NEW MemberExpression Arguments
                             { $$ = NEW_NEW(NEW_MEMBER($3, $2, false)); }
                         ;

MemberExpressionNoFn     : PrimaryExpressionNoObj
                             { $$ = $1; }
                         | MemberExpressionNoFn '[' Expression ']'
                             { $$ = NEW_MEMBER($3, $1, 42); }
                         | MemberExpressionNoFn '.' Identifier
                             { $$ = NEW_MEMBER($3, $1, false); }
                         | NEW MemberExpression Arguments
                             { $$ = NEW_NEW(NEW_MEMBER($3, $2, false)); }
                         ;

Arguments                : '(' ')'
                             { $$ = NEW_ARGLST(NULL, NULL); }
                         | '(' ArgumentList ')'
                             { $$ = $2; }
                         ;

ArgumentList             : AssignmentExpression
                             { $$ = NEW_ARGLST($1, NULL); }
                         | ArgumentList ',' AssignmentExpression
                             { $$ = NEW_ARGLST($3, $1); }
                         ;

%%

void
yyerror(const char *s)
{
  eval_state *state = js_new_state(yylloc.first_line, yylloc.first_column);
  js_push_state(state);
  // Show the offending line.
  if (yyin) {
    char buf[1000];
    int i = 1;
    rewind(yyin);
    while (fgets(buf, sizeof buf, yyin) != NULL) {
      if (yylloc.first_line == i++) {
        cfprintf(stderr, ANSI_RED, "%s", buf);
        cfprintf(stderr, ANSI_GRAY, "%*s\n", yylloc.first_column + 1, "^");
      }
    }
  }
  // Trim the "syntax error: " prefix so we can use `js_throw`.
  js_throw(state, js_new_error(E_SYNTAX, strlen(s) >= 14 ? s + 14 : s));
}

// This is our replacement function when we redefine YY_INPUT
int
js_get_input(char *buf, int size)
{
  // For the REPL:
  if (js->opt_interactive) {
#ifdef JS_NO_REPL
    fprintf(stderr, "Error: REPL not available. Build with readline.");
    exit(1);
#else
    if (js->opt_keep_history_file) {
      read_history(js->opt_history_filename);
    }

    char *line;
    line = readline("> ");
    if (!line)
      return 0;
    if ((int)strlen(line) > size - 3) {
      js_throw(NULL, js_new_error(E_ERROR, "input line too long"));
      return 0;
    }
    strcpy(buf, line);

    add_history(buf);

    // Use the file
    if (js->opt_keep_history_file) {
      write_history(js->opt_history_filename);
      history_truncate_file(js->opt_history_filename, 1000);
      clear_history();
    }

    // Poor man's ASI:
    if (!strchr(buf, ';')) strcat(buf, ";");

    strcat(buf, "\n");
    free(line);
#endif
  }
  // For file or stdin:
  else {
    if (!yyin)
      js_throw(NULL, js_new_error(E_ERROR, "invalid input file"));
    int result = fread(buf, sizeof(char), size, yyin);
    if (result == 0 && ferror(yyin))
      js_throw(NULL, js_new_error(E_ERROR, "error while reading input file"));
    return result;
  }
  return strlen(buf);
}

js_val *
js_eval_file(FILE *file, js_val *ctx)
{
  yyrestart(file);
  yyparse();

  if (js->opt_print_ast)
    node_print(root, true, 0);

  return js_eval(ctx, root);
}

js_val *
js_eval_string(char *string, js_val *ctx)
{
  // Save the current interactive setting and set it to false.
  bool tmp = js->opt_interactive;
  js->opt_interactive = false;

  eval_state *prior_state = js_new_state(yylloc.first_line, yylloc.last_line);
  yycolumn = 0;
  yylineno = 1;

  YY_BUFFER_STATE buffer = yy_scan_string(string);
  yyparse();

  if (js->opt_print_ast)
    node_print(root, true, 0);

  js_val *res = js_eval(ctx, root);
  yy_delete_buffer(buffer);
  js->opt_interactive = tmp;
  yylineno = prior_state->line;
  yycolumn = prior_state->column;
  return res;
}

int
main(int argc, char **argv)
{
  // Create the global state object
  js = js_new_global_state();

  int c = 0, fakeind = 0, optind = 1;
  static struct option long_options[] = {
    {"version", no_argument, NULL, 'v'},
    {"help", no_argument, NULL, 'h'},
    {"interactive", no_argument, NULL, 'i'},
    {"nodes", no_argument, NULL, 'n'},
    {"tokens", no_argument, NULL, 't'},
    {NULL, 0, NULL, 0}
  };

  while ((c = getopt_long(argc, argv, "vhint", long_options, &fakeind)) != -1) {
    switch (c) {
      case 0: break;
      // case 'v': js_print_version(); return 0;
      case 'h': js_print_help(); return 0;
      case 'i': js->opt_interactive = true; break;
      case 'n': js->opt_print_ast = true; break;
      case 't': js->opt_print_tokens = true; break;
      default: break;
    }
    optind++;
  }

  static FILE *source = NULL;
  if (optind < argc) {
    source = fopen(argv[optind], "r");
    js->script_name = argv[optind];
  }
  else if (!isatty(fileno(stdin)) && !js->opt_interactive) {
    source = stdin;
  }
  else {
    js->opt_interactive = true;
    js->script_name = "(repl)";
  }

  // Bootstrap our runtime
  js->global = js_bootstrap();

  // We can operate as a REPL or in file/stdin mode.
  if (js->opt_interactive) {
    js_print_startup();
    while (true) {
      // Normally errors cause the program to exit, but we'd like the REPL to
      // continue. Use setjmp here and longjmp in `js_throw` to simulate
      // exception handling.
      if (!setjmp(js->repl_jmp))
        DEBUG(js_eval_file(source, js->global));
    }
  }
  else
    js_eval_file(source, js->global);

  return 0;
}