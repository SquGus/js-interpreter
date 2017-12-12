/*
 *  Lexer for JavaScript
 */

%{
/* IMPORT LIBRARIES AND VARIABLES NEEDED */
    #include <stdlib.h>
    #include "js_interpreter.h"
    #include "y.tab.h"

    int yycolumn = 1;
    int prev_token = 0;

    void yyuseraction(void);
    YY_BUFFER_STATE yy_scan_string(const char *);
    void yy_delete_budfer(YY_BUFFER_STATE);

    char * js_extract_string(char *);
    void js_parse_error(char *);
    int js_get_input(char *, int);
    int js_token(char *, int);

    #define TOKEN(name, token) js_token((name), (token))
    #define OP(token) js_token("OP", (token))
    #define KEYWORD(token) js_token("KEYWORD", (token))

    // Code run each time a pattern is matched.
    #define YY_USER_ACTION yyuseraction();
    // Undefines YY_INPUT macro
    #undef YY_INPUT
    // Redefines YY_INPUT
    #define YY_INPUT(buffer, result, max_size) result = js_get_input(buffer, max_size);
%}

/* LEXER OPTIONS */
/* Generate a scanner that maintains the number of the current line read from its input
 * in the global variable yylineno
 */
%option yylineno
/* Because there is no #include-like feature we don’t need unput and we parse an actual
 * file, this is not an interactive session with the user
 */
%option nounput
%option noinput
/* Exclusive start conditions activated using the BEGIN action */
%x BLOCK_COMMENT

%%
    /* TOKEN DEFINITIONS */
    /* Keywords */
"while"                                             { return KEYWORD(WHILE); }
"do"                                                { return KEYWORD(DO); }
"for"                                               { return KEYWORD(FOR); }
"if"                                                { return KEYWORD(IF); }
    /* "in"                                                { return KEYWORD(IN); } */
"else"                                              { return KEYWORD(ELSE); }
"break"                                             { return KEYWORD(BREAK); }
"continue"                                          { return KEYWORD(CONTINUE); }
"return"                                            { return KEYWORD(RETURNT); }
    /* "throw"                                             { return KEYWORD(THROW); } */
    /* "try"                                               { return KEYWORD(TRY); } */
    /* "catch"                                             { return KEYWORD(CATCH); } */
    /* "finally"                                           { return KEYWORD(FINALLY); } */
    /* "with"                                              { return KEYWORD(WITH); } */
"function"                                          { return KEYWORD(FUNCTION); }
    /* "delete"                                            { return KEYWORD(DELETE); } */
    /* "void"                                              { return KEYWORD(VOID); } */
"typeof"                                            { return KEYWORD(TYPEOF); }
"instanceof"                                        { return KEYWORD(INSTANCEOF); }
    /* "switch"                                            { return KEYWORD(SWITCH); } */
    /* "case"                                              { return KEYWORD(CASE); } */
    /* "default"                                           { return KEYWORD(DEFAULT); } */
    /* "debugger"                                          { return KEYWORD(DEBUGGER); } */
"new"                                               { return KEYWORD(NEW); }
"var"                                               { return KEYWORD(VAR); }
"null"                                              { return KEYWORD(NULLT); }
"true"                                              { return KEYWORD(TRUE); }
"false"                                             { return KEYWORD(FALSE); }

    /* Comments */
\/\/.                                               { ; }
<INITIAL>{
"/*"                                                { BEGIN(BLOCK_COMMENT); }
}
<BLOCK_COMMENT>{
"*/"                                                { BEGIN(INITIAL); }
[^*\n]+                                             // consume comments by block
"*"                                                 // consume lone stars
\n                                                  { yylineno++; }
}

    /* Strings */
"\'"([^\n\t\r"\'"\\]*(\\[.\n])*)*"\'"               { yylval.val = js_extract_string(yytext); return TOKEN("STR", STRING); }
"\""([^\n\t\r"\""\\]*(\\[.\n])*)*"\""               { yylval.val = js_extract_string(yytext); return TOKEN("STR", STRING); }

    /* Identifiers */
([a-zA-Z]|$|_)+([a-zA-Z]|[0-9])*                    { yylval.val = yytext; return TOKEN("IDENT", IDENT); }

    /* Integers */
[-]?([0-9])+                                        { yylval.floatval = atof(yytext); return TOKEN("INT", NUMBER); }

    /* Floats */
[-]?([0-9])*[.]([0-9])+((E|e)([+]|[-])([0-9])+)?    { yylval.floatval = atof(yytext); return TOKEN("FLOAT", NUMBER); }

    /* Operators */
"}"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"{"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"]"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"["                                                 { TOKEN("LITERAL", 0); return *yytext; }
")"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"("                                                 { TOKEN("LITERAL", 0); return *yytext; }
"?"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"||"                                                { return OP(LOGIC_OR_OP); }
"|="                                                { return OP(SHORT_BIT_OR_OP); }
"|"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"^="                                                { return OP(SHORT_BIT_XOR_OP); }
"^"                                                 { TOKEN("LITERAL", 0); return *yytext; }
">>>="                                              { return OP(SHORT_BIT_SHIFT_Z_R_OP); }
">>>"                                               { return OP(BIT_SHIFT_Z_R_OP); }
">>="                                               { return OP(SHORT_BIT_SHIFT_S_R_OP); }
">>"                                                { return OP(BIT_SHIFT_S_R_OP); }
">="                                                { return OP(GE_OP); }
">"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"==="                                               { return OP(EQ_VT_OP); }
"=="                                                { return OP(EQ_V_OP); }
"="                                                 { TOKEN("LITERAL", 0); return *yytext; }
"<="                                                { return OP(LE_OP); }
"<<="                                               { return OP(SHORT_BIT_SHIFT_L_OP); }
"<<"                                                { return OP(BIT_SHIFT_L_OP); }
"<"                                                 { TOKEN("LITERAL", 0); return *yytext; }
";"                                                 { TOKEN("LITERAL", 0); return *yytext; }
":"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"/="                                                { return OP(SHORT_DIV_OP); }
"/"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"."                                                 { TOKEN("LITERAL", 0); return *yytext; }
"-="                                                { return OP(SHORT_SUB_OP); }
"--"                                                { return OP(UNIT_SUB_OP); }
"-"                                                 { TOKEN("LITERAL", 0); return *yytext; }
","                                                 { TOKEN("LITERAL", 0); return *yytext; }
"+="                                                { return OP(SHORT_ADD_OP); }
"++"                                                { return OP(UNIT_ADD_OP); }
"+"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"*="                                                { return OP(SHORT_MUL_OP); }
"*"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"&="                                                { return OP(SHORT_BIT_AND_OP); }
"&&"                                                { return OP(LOGIC_AND_OP); }
"&"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"%="                                                { return OP(SHORT_MOD_OP); }
"%"                                                 { TOKEN("LITERAL", 0); return *yytext; }
"!=="                                               { return OP(NEG_VT_OP); }
"!="                                                { return OP(NEG_V_OP); }
"!"                                                 { TOKEN("LITERAL", 0); return *yytext; }

    /* Whitespace */
[ \t\v\f]+                                          { ; }

    /* Newlines */
\n                                                  { yycolumn = 0; yytext = NULL; TOKEN("NEWLINE", 0); if(js->opt_interactive) return EOF; }

    /* End of file */
<<EOF>>                                             { yycolumn = 0; if(js->opt_interactive) exit(0); return EOF;}

    /* Anything else */
.                                                   { js_parse_error(yytext); }
%%

// Scanner terminates, returning 0 to its caller
int yywrap(void) {
    return 1;
}

// Code run each time a pattern is matched.
void yyuseraction(void) {
    yylloc.first_line = yylloc.last_line = yylineno;
    yylloc.first_column = yycolumn;
    yylloc.last_column = yycolumn + yyleng - 1;
    yycolumn += yyleng;
}

// Print parsing error
void js_parse_error(char *val) {
    eval_state *state = js_new_state(yylloc.first_line, yylloc.first_column);
    js_push_state(state);
    js_throw(state, js_new_error("ParsingError", "unexpected '%s'", val));
}

// Wrap tokens
int js_token(char *name, int token) {
    prev_token = token;
    if (js->opt_print_tokens) {
        if (yytext) {
            printf("(%s %s)\n", name, yytext);
        } else {
            printf("(%s)\n", name);
        }
    }
    return token;
}

// Remove first and last chars
char * js_extract_string(char *str) {
    str[strlen(str) - 1] = '\0';
    return str + 1;
}