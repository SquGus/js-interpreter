%{
/*
    Lexer for JavaScript
*/

/* Import libraries and variables needed */
    #include <string.h>
    #include <stdlib.h>
    #include "js_parser.tab.h"
    int line_num = 1;
%}

/* Lexer options */
%option noyywrap

/* Regular expressions that define accepted tokens */
%%
"//".*[^\n]                                         { line_num++; }
"/*"([^(\\*\\/)])*"*/"                              { line_num++; }
"}"                                                 { return ( CLOSE_C ); }
"{"                                                 { return ( OPEN_C ); }
"]"                                                 { return ( CLOSE_B ); }
"["                                                 { return ( OPEN_B ); }
")"                                                 { return ( CLOSE_P ); }
"("                                                 { return ( OPEN_P ); }
"?"                                                 { return ( TERNARY_OP ); }
"||"                                                { return ( LOGIC_OR_OP ); }
"|="                                                { return ( SHORT_BIT_OR_OP ); }
"|"                                                 { return ( BIT_OR_OP ); }
"^="                                                { return ( SHORT_BIT_XOR_OP ); }
"^"                                                 { return ( BIT_XOR_OP ); }
">>>="                                              { return ( SHORT_BIT_SHIFT_Z_R_OP ); }
">>>"                                               { return ( BIT_SHIFT_Z_R_OP ); }
">>="                                               { return ( SHORT_BIT_SHIFT_S_R_OP ); }
">>"                                                { return ( BIT_SHIFT_S_R_OP ); }
">="                                                { return ( GE_OP ); }
">"                                                 { return ( G_OP ); }
"==="                                               { return ( EQ_VT_OP ); }
"=="                                                { return ( EQ_V_OP ); }
"="                                                 { return ( VA_OP ); }
"<="                                                { return ( LE_OP ); }
"<<="                                               { return ( SHORT_BIT_SHIFT_L_OP ); }
"<<"                                                { return ( BIT_SHIFT_L_OP ); }
"<"                                                 { return ( L_OP ); }
";"                                                 { return ( STMT_TER_OP ); }
":"                                                 { return ( PA_OP ); }
"/="                                                { return ( SHORT_DIV_OP ); }
"/"                                                 { return ( DIV_OP ); }
"."                                                 { return ( MEM_ACC_OP ); }
"-="                                                { return ( SHORT_SUB_OP ); }
"--"                                                { return ( UNIT_SUB_OP ); }
"-"                                                 { return ( SUB_OP ); }
","                                                 { return ( SEP_OP ); }
"+="                                                { return ( SHORT_ADD_OP ); }
"++"                                                { return ( UNIT_ADD_OP ); }
"+"                                                 { return ( ADD_OP ); }
"*="                                                { return ( SHORT_MUL_OP ); }
"*"                                                 { return ( MUL_OP ); }
"&="                                                { return ( SHORT_BIT_AND_OP ); }
"&&"                                                { return ( LOGIC_AND_OP ); }
"&"                                                 { return ( BIT_AND_OP ); }
"%="                                                { return ( SHORT_MOD_OP ); }
"%"                                                 { return ( MOD_OP ); }
"!=="                                               { return ( NEG_VT_OP ); }
"!="                                                { return ( NEG_V_OP ); }
"!"                                                 { return ( LOGIC_NOT_OP ); }
"break"                                             { return ( BREAK ); }
"continue"                                          { return ( CONTINUE ); }
"default"                                           { return ( DEFAULT ); }
"do"                                                { return ( DO ); }
"else"                                              { return ( ELSE ); }
"for"                                               { return ( FOR ); }
"function"                                          { return ( FUNCTION ); }
"if"                                                { return ( IF ); }
"instanceof"                                        { return ( INSTANCEOF ); }
"new"                                               { return ( NEW ); }
"return"                                            { return ( RETURN ); }
"var"                                               { return ( VAR ); }
"while"                                             { return ( WHILE ); }
"null"                                              { return ( NULL_V ); }
"true"                                              { yylval.ival = 1; return ( TRUE_V ); }
"false"                                             { yylval.ival = 0; return ( FALSE_V ); }
[-]?([0-9])*[.]([0-9])+((E|e)([+]|[-])([0-9])+)?    { yylval.fval = atof(yytext); return ( FLT_V ); }
[-]?([0-9])+                                        { yylval.ival = atoi(yytext); return ( INT_V ); }
"\'"([^\n\t\r"\'"\\]*(\\[.\n])*)*"\'"               { yylval.sval = strdup(yytext); return ( STRING_V ); }
"\""([^\n\t\r"\""\\]*(\\[.\n])*)*"\""               { yylval.sval = strdup(yytext); return ( STRING_V ); }
([a-zA-Z]|$|_)+([a-zA-Z]|[0-9])*                    { yylval.id = (char *) strdup(yytext); return ( ID ); }
[|\r\t|\v|\f| ]                                     { ; }
\n                                                  { line_num++; }
.                                                   { printf("Couldn't parse %s", yytext); exit(-1); }
%%