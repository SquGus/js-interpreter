%{
#include "lexer.tab.hpp"
#include <iostream>
using namespace std;
#define YY_DECL extern "C" int yylex()
%}

%option noyywrap

%%

"//".*                                              { cout << "Found <L_COMMENT>: " << yytext << endl; return L_COMMENT; }
"/*"[^(\\*\\/)]*"*/"                                { cout << "Found <B_COMMENT>: " << yytext << endl; return B_COMMENT; }
"~"                                                 { cout << "Found <BIT_NOT>:" <<  yytext << endl; return BIT_NOT; }
"}"                                                 { cout << "Found <CLOSE_C>: " << yytext << endl; return CLOSE_C; }
"{"                                                 { cout << "Found <OPEN_C>: " <<  yytext << endl; return OPEN_C; }
"]"                                                 { cout << "Found <CLOSE_B>:" << yytext << endl; return CLOSE_B; }
"["                                                 { cout << "Found <OPEN_B>: " <<  yytext << endl; return OPEN_B; }
")"                                                 { cout << "Found <CLOSE_P>: " << yytext << endl; return CLOSE_P; }
"("                                                 { cout << "Found <OPEN_P>: " <<  yytext << endl; return OPEN_P; }
"?"                                                 { cout << "Found <TERNARY_OP>: " <<  yytext << endl; return TERNARY_OP; }
"||"                                                { cout << "Found <LOGIC_OR_OP>: " <<  yytext << endl; return LOGIC_OR_OP; }
"|="                                                { cout << "Found <SHORT_BIT_OR_OP>: " <<  yytext << endl; return SHORT_BIT_OR_OP; }
"|"                                                 { cout << "Found <BIT_OR_OP>: " <<  yytext << endl; return BIT_OR_OP; }
"^="                                                { cout << "Found <SHORT_BIT_XOR_OP>: " <<  yytext << endl; return SHORT_BIT_XOR_OP; }
"^"                                                 { cout << "Found <BIT_XOR_OP>: " <<  yytext << endl; return BIT_XOR_OP; }
">>>="                                              { cout << "Found <SHORT_BIT_SHIFT_Z_R_OP>: " <<  yytext << endl; return SHORT_BIT_SHIFT_Z_R_OP; }
">>>"                                               { cout << "Found <BIT_SHIFT_Z_R_OP>: " <<  yytext << endl; return BIT_SHIFT_Z_R_OP; }
">>="                                               { cout << "Found <SHORT_BIT_SHIFT_S_R_OP>: " <<  yytext << endl; return SHORT_BIT_SHIFT_S_R_OP; }
">>"                                                { cout << "Found <BIT_SHIFT_S_R_OP>: " <<  yytext << endl; return BIT_SHIFT_S_R_OP; }
">="                                                { cout << "Found <GE_OP>: " <<  yytext << endl; return GE_OP; }
">"                                                 { cout << "Found <G_OP>: " <<  yytext << endl; return G_OP; }
"==="                                               { cout << "Found <EQ_VT_OP>: " <<  yytext << endl; return EQ_VT_OP; }
"=="                                                { cout << "Found <EQ_V_OP>: " <<  yytext << endl; return EQ_V_OP; }
"="                                                 { cout << "Found <VA_OP>: " <<  yytext << endl; return VA_OP; }
"<="                                                { cout << "Found <LE_OP>: " <<  yytext << endl; return LE_OP; }
"<<="                                               { cout << "Found <SHORT_BIT_SHIFT_L_OP>: " <<  yytext << endl; return SHORT_BIT_SHIFT_L_OP; }
"<<"                                                { cout << "Found <BIT_SHIFT_L_OP>: " <<  yytext << endl; return BIT_SHIFT_L_OP; }
"<"                                                 { cout << "Found <L_OP>: " <<  yytext << endl; return L_OP; }
";"                                                 { cout << "Found <STMT_TER_OP>: " <<  yytext << endl; return STMT_TER_OP; }
":"                                                 { cout << "Found <PA_OP>: " <<  yytext << endl; return PA_OP; }
"/="                                                { cout << "Found <SHORT_DIV_OP>: " <<  yytext << endl; return SHORT_DIV_OP; }
"/"                                                 { cout << "Found <DIV_OP>: " <<  yytext << endl; return DIV_OP; }
"."                                                 { cout << "Found <MEM_ACC_OP>: " <<  yytext << endl; return MEM_ACC_OP; }
"-="                                                { cout << "Found <SHORT_SUB_OP>: " <<  yytext << endl; return SHORT_SUB_OP; }
"--"                                                { cout << "Found <UNIT_SUB_OP>: " <<  yytext << endl; return UNIT_SUB_OP; }
"-"                                                 { cout << "Found <SUB_OP>: " <<  yytext << endl; return SUB_OP; }
","                                                 { cout << "Found <SEP_OP>:" << yytext << endl; return SEP_OP; }
"+="                                                { cout << "Found <SHORT_ADD_OP>: " <<  yytext << endl; return SHORT_ADD_OP; }
"++"                                                { cout << "Found <UNIT_ADD_OP>: " <<  yytext << endl; return UNIT_ADD_OP; }
"+"                                                 { cout << "Found <ADD_OP>: " <<  yytext << endl; return ADD_OP; }
"*="                                                { cout << "Found <SHORT_MUL_OP>: " <<  yytext << endl; return SHORT_MUL_OP; }
"*"                                                 { cout << "Found <MUL_OP>: " <<  yytext << endl; return MUL_OP; }
"&="                                                { cout << "Found <SHORT_BIT_AND_OP>: " <<  yytext << endl; return SHORT_BIT_AND_OP; }
"&&"                                                { cout << "Found <LOGIC_AND_OP>: " <<  yytext << endl; return LOGIC_AND_OP; }
"&"                                                 { cout << "Found <BIT_AND_OP>: " <<  yytext << endl; return BIT_AND_OP; }
"%="                                                { cout << "Found <SHORT_MOD_OP>: " <<  yytext << endl; return SHORT_MOD_OP; }
"%"                                                 { cout << "Found <MOD_OP>: " <<  yytext << endl; return MOD_OP; }
"!=="                                               { cout << "Found <NEG_VT_OP>: " <<  yytext << endl; return NEG_VT_OP; }
"!="                                                { cout << "Found <NEG_V_OP>: " <<  yytext << endl; return NEG_V_OP; }
"!"                                                 { cout << "Found <LOGIC_NOT_OP>: " <<  yytext << endl; return LOGIC_NOT_OP; }
"break"                                             { cout << "Found <BREAK>: " << yytext << endl; return BREAK; }
"case"                                              { cout << "Found <CASE>: " << yytext << endl; return CASE; }
"catch"                                             { cout << "Found <CATCH>: " << yytext << endl; return CATCH; }
"class"                                             { cout << "Found <CLASS>: " << yytext << endl; return CLASS; }
"const"                                             { cout << "Found <CONS>: " << yytext << endl; return CONS; }
"continue"                                          { cout << "Found <CONTINUE>: " << yytext << endl; return CONTINUE; }
"debugger"                                          { cout << "Found <DEBUGGER>: " << yytext << endl; return DEBUGGER; }
"default"                                           { cout << "Found <DEFAULT>: " << yytext << endl; return DEFAULT; }
"delete"                                            { cout << "Found <DELETE>: " << yytext << endl; return DELETE; }
"do"                                                { cout << "Found <DO>: " << yytext << endl; return DO; }
"else"                                              { cout << "Found <ELSE>: " << yytext << endl; return ELSE; }
"enum"                                              { cout << "Found <ENUM>: " << yytext << endl; return ENUM; }
"export"                                            { cout << "Found <EXPORT>: " << yytext << endl; return EXPORT; }
"extends"                                           { cout << "Found <EXTENDS>: " << yytext << endl; return EXTENDS; }
"finally"                                           { cout << "Found <FINALLY>: " << yytext << endl; return FINALLY; }
"for"                                               { cout << "Found <FOR>: " << yytext << endl; return FOR; }
"function"                                          { cout << "Found <FUNCTION>: " << yytext << endl; return FUNCTION; }
"if"                                                { cout << "Found <IF>: " << yytext << endl; return IF; }
"implements"                                        { cout << "Found <IMPLEMENTS>: " << yytext << endl; return IMPLEMENTS; }
"import"                                            { cout << "Found <IMPORT>: " << yytext << endl; return IMPORT; }
"in"                                                { cout << "Found <IN>: " << yytext << endl; return IN; }
"instanceof"                                        { cout << "Found <INSTANCEOF>: " << yytext << endl; return INSTANCEOF; }
"interface"                                         { cout << "Found <INTERFACE>: " << yytext << endl; return INTERFACE; }
"let"                                               { cout << "Found <LET>: " << yytext << endl; return LET; }
"new"                                               { cout << "Found <NEW>: " << yytext << endl; return NEW; }
"package"                                           { cout << "Found <PACKAGE>: " << yytext << endl; return PACKAGE; }
"private"                                           { cout << "Found <PRIVATE>: " << yytext << endl; return PRIVATE; }
"protected"                                         { cout << "Found <PROTECTED>: " << yytext << endl; return PROTECTED; }
"public"                                            { cout << "Found <PUBLIC>: " << yytext << endl; return PUBLIC; }
"return"                                            { cout << "Found <RETURN>: " << yytext << endl; return RETURN; }
"static"                                            { cout << "Found <STATIC>: " << yytext << endl; return STATIC; }
"super"                                             { cout << "Found <SUPER>: " << yytext << endl; return SUPER; }
"switch"                                            { cout << "Found <SWITCH>: " << yytext << endl; return SWITCH; }
"this"                                              { cout << "Found <THIS>: " << yytext << endl; return THIS; }
"throw"                                             { cout << "Found <THROW>: " << yytext << endl; return THROW; }
"try"                                               { cout << "Found <TRY>: " << yytext << endl; return TRY; }
"typeof"                                            { cout << "Found <TYPEOF>: " << yytext << endl; return TYPEOF; }
"var"                                               { cout << "Found <VAR>: " << yytext << endl; return VAR; }
"void"                                              { cout << "Found <VOID>: " << yytext << endl; return VOID; }
"while"                                             { cout << "Found <WHILE>: " << yytext << endl; return WHILE; }
"with"                                              { cout << "Found <WITH>: " << yytext << endl; return WITH; }
"yield"                                             { cout << "Found <YIELD>: " << yytext << endl; return YIELD; }
"null"                                              { cout << "Found <NULL_V>: " << yytext << endl; return NULL_V; }
"undefined"                                         { cout << "Found <UNDEFINED_V>: " << yytext << endl; return UNDEFINED_V; }
"true"                                              { cout << "Found <TRUE_V>: " << yytext << endl; return TRUE_V; }
"false"                                             { cout << "Found <FALSE_V>: " << yytext << endl; return FALSE_V; }
0[X|x]([0-9]|[A-F]|[a-f])+                          { cout << "Found <HEX_T>: " << yytext << endl; return HEX_T; }
(0[O|o][0-7]+)|([-]?0[0-7]+)                        { cout << "Found <OCT_T>: " << yytext << endl; return OCT_T; }
0b(0|1)+                                            { cout << "Found <BIN_T>: " << yytext << endl; return BIN_T; }
[-]?([0-9])*[.]([0-9])+((E|e)([+]|[-])([0-9])+)?    { cout << "Found <FLT_T>: " << yytext << endl; return FLT_T; }
[-]?([0-9])+                                        { cout << "Found <INT_T>: " << yytext << endl; return INT_T; }
"'\\x"([0-9]|[A-F]|[a-f]){2}"'"                     { cout << "Found <HEX_SEQ>: " << yytext << endl; return HEX_SEQ; }
"'\\u"([0-9]|[A-F]|[a-f]){4}"'"                     { cout << "Found <UNI_SEQ>: " << yytext << endl; return UNI_SEQ; }
(\"([^\"\n\t\r])*\"+)|(\'([^\'\n\t\r])*\')          { cout << "Found <STRING>: " << yytext << endl; return STRING; }
([a-zA-Z]|$|_)+([a-zA-Z]|[0-9])*                    { cout << "Found <ID>: " << yytext << endl; return ID; }
[\n|\r\t|\v|\f| ]                                   { ; }
.                                                   { cout << "Error -> " << yytext << endl; exit(1); }

%%

int main()
{
  yylex();
}