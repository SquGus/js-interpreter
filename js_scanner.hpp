#ifndef __JSSCANNER_HPP__
#define __JSSCANNER_HPP__ 1

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "js_parser.tab.hh"
#include "location.hh"

namespace JS{

class JS_Scanner : public yyFlexLexer{
public:
   
   JS_Scanner(std::istream *in) : yyFlexLexer(in)
   {
      loc = new JS::JS_Parser::location_type();
   };
  
   //get rid of override virtual function warning
   using FlexLexer::yylex;

   virtual
   int yylex( JS::JS_Parser::semantic_type * const lval, 
              JS::JS_Parser::location_type *location );
   // YY_DECL defined in js_lexer.l
   // Method body created by flex in js_lexer.yy.cc


private:
   /* yyval ptr */
   JS::JS_Parser::semantic_type *yylval = nullptr;
   /* location ptr */
   JS::JS_Parser::location_type *loc    = nullptr;
};

} /* end namespace JS */

#endif /* END __JSSCANNER_HPP__ */