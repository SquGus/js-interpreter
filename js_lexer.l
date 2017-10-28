%{

#include <iostream>
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */ 
#include "js_scanner.hpp"
#undef  YY_DECL
//#define YY_DECL extern "C" int yylex()
#define YY_DECL int JS::JS_Scanner::yylex( JS::JS_Parser::semantic_type * const lval, JS::JS_Parser::location_type *location )

using namespace std;
/* using "token" to make the returns for the tokens shorter to type */
using token = JS::JS_Parser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="JS::JS_Scanner"
%option noyywrap
%option c++

%%
%{
	/** Code executed at the beginning of yylex **/
	yylval = lval;

	/* IGNORED TOKENS

// "catch"                                             { return ( token::CATCH ); }
// "class"                                             { return ( token::CLASS ); }
// "debugger"                                          { return ( token::DEBUGGER ); }
// "delete"                                            { return ( token::DELETE ); }
// "enum"                                              { return ( token::ENUM ); }
// "export"                                            { return ( token::EXPORT ); }
// "extends"                                           { return ( token::EXTENDS ); }
// "finally"                                           { return ( token::FINALLY ); }
// "implements"                                        { return ( token::IMPLEMENTS ); }
// "import"                                            { return ( token::IMPORT ); }
// "in"                                                { return ( token::IN ); }
// "interface"                                         { return ( token::INTERFACE ); }
// "let"                                               { return ( token::LET ); }
// "package"                                           { return ( token::PACKAGE ); }
// "private"                                           { return ( token::PRIVATE ); }
// "protected"                                         { return ( token::PROTECTED ); }
// "public"                                            { return ( token::PUBLIC ); }
// "static"                                            { return ( token::STATIC ); }
// "super"                                             { return ( token::SUPER ); }
// "this"                                              { return ( token::THIS ); }
// "throw"                                             { return ( token::THROW ); }
// "try"                                               { return ( token::TRY ); }
// "typeof"                                            { return ( token::TYPEOF ); }
// "void"                                              { return ( token::VOID ); }
// "with"                                              { return ( token::WITH ); }
// "yield"                                             { return ( token::YIELD ); }
// "undefined"                                         { return ( token::UNDEFINED_V ); }
//"'\\x"([0-9]|[A-F]|[a-f]){2}"'"                     { return ( token::HEX_SEQ ); }
//"'\\u"([0-9]|[A-F]|[a-f]){4}"'"                     { return ( token::UNI_SEQ ); }
// 0[X|x]([0-9]|[A-F]|[a-f])+                          { return ( token::HEX_V ); }
// (0[O|o][0-7]+)|([-]?0[0-7]+)                        { return ( token::OCT_V ); }
// 0b(0|1)+                                            { return ( token::BIN_V ); }


	*/
%}

"//".*                                              {  }
"/*"[^(\\*\\/)]*"*/"                                {  }
"~"                                                 { return ( token::BIT_NOT_OP ); }
"}"                                                 { return ( token::CLOSE_C ); }
"{"                                                 { return ( token::OPEN_C ); }
"]"                                                 { return ( token::CLOSE_B ); }
"["                                                 { return ( token::OPEN_B ); }
")"                                                 { return ( token::CLOSE_P ); }
"("                                                 { return ( token::OPEN_P ); }
"?"                                                 { return ( token::TERNARY_OP ); }
"||"                                                { return ( token::LOGIC_OR_OP ); }
"|="                                                { return ( token::SHORT_BIT_OR_OP ); }
"|"                                                 { return ( token::BIT_OR_OP ); }
"^="                                                { return ( token::SHORT_BIT_XOR_OP ); }
"^"                                                 { return ( token::BIT_XOR_OP ); }
">>>="                                              { return ( token::SHORT_BIT_SHIFT_Z_R_OP ); }
">>>"                                               { return ( token::BIT_SHIFT_Z_R_OP ); }
">>="                                               { return ( token::SHORT_BIT_SHIFT_S_R_OP ); }
">>"                                                { return ( token::BIT_SHIFT_S_R_OP ); }
">="                                                { return ( token::GE_OP ); }
">"                                                 { return ( token::G_OP ); }
"==="                                               { return ( token::EQ_VT_OP ); }
"=="                                                { return ( token::EQ_V_OP ); }
"="                                                 { return ( token::VA_OP ); }
"<="                                                { return ( token::LE_OP ); }
"<<="                                               { return ( token::SHORT_BIT_SHIFT_L_OP ); }
"<<"                                                { return ( token::BIT_SHIFT_L_OP ); }
"<"                                                 { return ( token::L_OP ); }
";"                                                 { return ( token::STMT_TER_OP ); }
":"                                                 { return ( token::PA_OP ); }
"/="                                                { return ( token::SHORT_DIV_OP ); }
"/"                                                 { return ( token::DIV_OP ); }
"."                                                 { return ( token::MEM_ACC_OP ); }
"-="                                                { return ( token::SHORT_SUB_OP ); }
"--"                                                { return ( token::UNIT_SUB_OP ); }
"-"                                                 { return ( token::SUB_OP ); }
","                                                 { return ( token::SEP_OP ); }
"+="                                                { return ( token::SHORT_ADD_OP ); }
"++"                                                { return ( token::UNIT_ADD_OP ); }
"+"                                                 { return ( token::ADD_OP ); }
"*="                                                { return ( token::SHORT_MUL_OP ); }
"*"                                                 { return ( token::MUL_OP ); }
"&="                                                { return ( token::SHORT_BIT_AND_OP ); }
"&&"                                                { return ( token::LOGIC_AND_OP ); }
"&"                                                 { return ( token::BIT_AND_OP ); }
"%="                                                { return ( token::SHORT_MOD_OP ); }
"%"                                                 { return ( token::MOD_OP ); }
"!=="                                               { return ( token::NEG_VT_OP ); }
"!="                                                { return ( token::NEG_V_OP ); }
"!"                                                 { return ( token::LOGIC_NOT_OP ); }
"break"                                             { return ( token::BREAK ); }
"case"                                              { return ( token::CASE ); }
"const"                                             { return ( token::CONST ); }
"continue"                                          { return ( token::CONTINUE ); }
"default"                                           { return ( token::DEFAULT ); }
"do"                                                { return ( token::DO ); }
"else"                                              { return ( token::ELSE ); }
"for"                                               { return ( token::FOR ); }
"function"                                          { return ( token::FUNCTION ); }
"if"                                                { return ( token::IF ); }
"instanceof"                                        { return ( token::INSTANCEOF ); }
"new"                                               { return ( token::NEW ); }
"return"                                            { return ( token::RETURN ); }
"switch"                                            { return ( token::SWITCH ); }
"var"                                               { return ( token::VAR ); }
"while"                                             { return ( token::WHILE ); }
"null"                                              { return ( token::NULL_V ); }
"true"                                              { return ( token::TRUE_V ); }
"false"                                             { return ( token::FALSE_V ); }
[-]?([0-9])*[.]([0-9])+((E|e)([+]|[-])([0-9])+)?    { yylval->fval = atof(yytext); return ( token::FLT_V ); }
[-]?([0-9])+                                        { yylval->ival = atoi(yytext); return ( token::INT_V ); }
(\"([^\"\n\t\r])*\"+)|(\'([^\'\n\t\r])*\')          { yylval->sval = strdup(yytext); return ( token::STRING ); }
([a-zA-Z]|$|_)+([a-zA-Z]|[0-9])*                    { yylval->sval = strdup(yytext); return ( token::ID ); }
[\n|\r\t|\v|\f| ]                                   { ; }
.                                                   { cout << "Couldn't parse \"" << yytext << endl; exit(-1); }

%%