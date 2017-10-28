// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.

#line 37 "js_parser.tab.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "js_parser.tab.hh"

// User implementation prologue.

#line 51 "js_parser.tab.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 28 "js_parser.yy" // lalr1.cc:413

   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   
   /* include for all driver functions */
   #include "js_driver.hpp"

#undef yylex
#define yylex scanner.yylex

#line 65 "js_parser.tab.cc" // lalr1.cc:413


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "js_parser.yy" // lalr1.cc:479
namespace JS {
#line 151 "js_parser.tab.cc" // lalr1.cc:479

  /// Build a parser object.
  JS_Parser::JS_Parser (JS_Scanner  &scanner_yyarg, JS_Driver  &driver_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      scanner (scanner_yyarg),
      driver (driver_yyarg)
  {}

  JS_Parser::~JS_Parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  JS_Parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  JS_Parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  JS_Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  JS_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  JS_Parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  JS_Parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  JS_Parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  JS_Parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  JS_Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  JS_Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  JS_Parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  JS_Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  JS_Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  JS_Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  JS_Parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  JS_Parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  JS_Parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  JS_Parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  JS_Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  JS_Parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  JS_Parser::symbol_number_type
  JS_Parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  JS_Parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  JS_Parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  JS_Parser::stack_symbol_type&
  JS_Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  JS_Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  JS_Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    YYUSE (yytype);
    yyo << ')';
  }
#endif

  inline
  void
  JS_Parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  JS_Parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  JS_Parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  JS_Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  JS_Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  JS_Parser::debug_level_type
  JS_Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  JS_Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline JS_Parser::state_type
  JS_Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  JS_Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  JS_Parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  JS_Parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {

#line 592 "js_parser.tab.cc" // lalr1.cc:859
            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  JS_Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  JS_Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const short int JS_Parser::yypact_ninf_ = -199;

  const signed char JS_Parser::yytable_ninf_ = -59;

  const short int
  JS_Parser::yypact_[] =
  {
     491,  -199,  -199,  -199,  -199,  -199,  -199,   646,   349,   633,
     646,  -199,   301,   646,   301,   646,   646,   -37,  -199,   -37,
     562,    23,    11,    34,   301,   646,    34,  -199,    34,  -199,
      60,   491,  -199,  -199,  -199,  -199,    40,  -199,  -199,  -199,
      45,  -199,  -199,    55,    59,    64,    69,   646,  -199,    72,
    -199,  -199,  -199,  -199,   685,    48,  -199,  -199,  -199,  -199,
    -199,  -199,   278,  -199,  -199,  -199,    93,    74,   109,   110,
      82,    68,    28,   102,    70,    -5,  -199,     5,    32,  -199,
    -199,  -199,   420,   108,     8,  -199,  -199,  -199,    -6,  -199,
      38,    32,  -199,    32,  -199,  -199,  -199,  -199,  -199,    80,
      61,   646,   135,   646,   139,   562,  -199,  -199,    48,  -199,
    -199,    72,  -199,   144,   562,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,   113,  -199,   128,    78,   -37,  -199,   126,
     646,  -199,  -199,  -199,  -199,  -199,   646,  -199,  -199,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,   646,   646,   646,
      20,  -199,  -199,   646,   646,   646,   646,   646,   646,   646,
     646,   646,   646,   646,   646,   646,   646,   646,   646,   646,
     646,   646,   646,   646,   646,   646,   108,  -199,   646,  -199,
     -37,  -199,   646,  -199,    34,   125,   646,    72,  -199,   151,
     124,  -199,   491,  -199,  -199,  -199,   135,   106,  -199,  -199,
     165,  -199,   646,   646,  -199,  -199,   646,  -199,  -199,  -199,
    -199,   164,   134,   173,  -199,  -199,   152,    74,   109,   110,
      82,    68,    28,    28,    28,    28,   102,   102,   102,   102,
     102,    70,    70,    70,    -5,    -5,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,   646,  -199,  -199,   646,  -199,   562,  -199,
      -8,  -199,  -199,   154,  -199,   646,  -199,   646,   156,  -199,
    -199,   646,   158,  -199,   188,   562,   646,  -199,  -199,   646,
       4,  -199,  -199,   189,  -199,   562,  -199,   190,  -199,   192,
     562,  -199
  };

  const unsigned char
  JS_Parser::yydefact_[] =
  {
       0,   121,   122,   123,   125,   124,   126,     0,     0,     0,
       0,    20,     0,     0,     0,     0,     0,    45,    50,    45,
       0,     0,     0,     0,     0,    71,     0,    49,     0,    87,
       0,     2,     4,     5,     6,     7,     0,     9,    10,    11,
       0,    13,    14,     0,     0,     0,     0,     0,    19,    21,
      68,   128,   134,    72,   177,    93,    96,    94,    95,   118,
     119,   130,   131,   127,   120,   129,    89,   145,   147,   149,
     151,   153,   155,   160,   166,   170,   173,     0,   177,   131,
     182,   135,     0,   127,     0,   137,   140,   144,     0,   142,
       0,   179,   181,   178,   180,   183,    44,    46,    43,     0,
      40,    61,     0,     0,     0,     0,   107,   109,   108,   104,
     105,    70,    47,     0,     0,     1,     3,     8,    12,    15,
      16,    17,    18,    48,    51,    56,   134,     0,    88,    91,
       0,   102,    85,    84,    82,    81,     0,    80,    76,    79,
     100,    78,    99,    75,    83,    77,   101,     0,   114,   114,
       0,    97,    98,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    22,     0,   136,
       0,   141,     0,    86,     0,     0,     0,    41,    65,     0,
      62,    63,     0,   132,    59,    67,     0,    23,   106,   103,
      27,    38,     0,     0,    53,    55,     0,    69,    73,    74,
     116,     0,   115,     0,   112,   111,     0,   146,   148,   150,
     152,   154,   158,   156,   159,   157,   164,   162,   163,   161,
     165,   169,   168,   167,   172,   171,   175,   174,   176,   139,
     138,   143,    37,    71,    42,    60,     0,   133,     0,    25,
       0,    52,    57,     0,   110,     0,   113,     0,     0,    64,
      24,     0,     0,    28,     0,     0,     0,   117,    90,    71,
       0,    32,    26,    35,    30,    29,    92,     0,    31,    36,
       0,    39
  };

  const short int
  JS_Parser::yypgoto_[] =
  {
    -199,  -199,   205,    -3,   -16,  -199,  -199,  -199,   -95,  -199,
    -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,  -199,
    -199,  -199,  -199,   187,  -199,  -199,   107,  -199,  -156,   -96,
    -199,  -199,   104,  -199,  -199,  -199,   -36,  -199,    -9,  -198,
      15,  -199,    16,    10,   111,  -199,  -183,     0,  -199,   185,
     191,  -199,  -199,   103,   105,    67,  -199,   193,  -199,  -199,
    -199,     3,     9,  -199,  -199,    39,  -199,  -199,    41,   -45,
      66,    71,    73,    65,    75,    24,     7,   -30,   -53,     6
  };

  const short int
  JS_Parser::yydefgoto_[] =
  {
      -1,    30,    82,    32,    33,    34,    35,    36,    37,    38,
      39,   250,   263,   264,   265,   274,   275,    40,    41,    42,
     185,    43,    44,    96,    45,    46,    47,   123,   124,   125,
     204,    48,   102,   103,   189,   190,   191,   194,    49,   112,
      50,   147,    51,    52,   127,    53,   128,    78,    55,    56,
      57,   108,   109,   151,   152,   211,   212,    58,    59,    60,
      61,    79,    63,    64,    84,    85,    65,    88,    89,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76
  };

  const short int
  JS_Parser::yytable_[] =
  {
      54,    90,   129,    62,    99,   188,   181,   193,    54,    54,
      54,    62,    91,    80,    93,    81,   111,    83,   179,    92,
      54,    94,    95,   253,    87,    54,   101,    97,   116,    97,
     244,    54,   104,   173,    62,    10,    29,   182,   100,   105,
     278,   131,   113,   174,   114,   258,   251,   130,   175,    10,
     261,   180,   183,   262,   163,   164,   129,   126,   129,   165,
     115,   148,   166,   149,     1,     2,     3,     4,     5,     6,
       7,   277,    77,   140,     9,   117,    10,   142,    29,   116,
     118,   130,    54,   276,    29,    62,   176,   150,   146,   197,
     119,   187,   -54,    29,   120,   167,   159,   160,   201,   121,
      54,   247,    12,    13,   122,    54,    14,    15,   -54,   153,
     154,   126,   171,   -54,    54,   130,   172,    16,   234,   235,
      18,   -54,   161,   162,   155,   168,    22,   169,   156,    24,
      54,   157,    27,   158,    29,   170,    54,   205,   231,   232,
     233,   129,   206,   154,   178,   207,   192,    54,    54,    54,
     188,   208,   184,    54,   101,   200,   202,   129,   203,   215,
     243,   129,   209,   210,   210,   245,   214,   246,   216,   248,
     226,   227,   228,   229,   230,   249,   254,   255,    54,   236,
     237,   238,    54,   222,   223,   224,   225,   256,   257,   176,
     266,   269,    54,   239,   271,    62,   126,    87,   272,   -33,
     242,   129,   -34,    54,   280,    31,    98,   186,   196,   106,
     259,   198,   126,   199,   195,   107,   213,   110,   252,   240,
     217,   129,   220,   241,     0,     0,   218,     0,     0,   219,
       0,     0,   260,   221,   111,     0,     0,     0,     0,     0,
       0,     0,     0,    54,     0,     0,     0,     0,    54,   273,
       0,     0,   270,     0,     0,    54,   126,    54,     0,   279,
     111,    54,     0,     0,   281,    54,     0,     0,     0,    54,
     267,     0,   268,     0,     0,    54,     0,     0,   -58,     0,
      54,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,   -58,
       0,   -58,     0,   -58,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     1,     2,     3,     4,     5,     6,
       0,     0,    77,   -58,     9,     0,    10,     0,     0,   -58,
     -58,     0,     0,   -58,   -58,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -58,   -58,     0,   -58,   -58,     0,
     -58,     0,   -58,   -58,   -58,     0,   -58,   -58,   -58,   -58,
     -58,   -58,     1,     2,     3,     4,     5,     6,     7,    81,
       8,     0,     9,     0,    10,     0,    22,     0,     0,    24,
       0,     0,     0,     0,    29,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,     0,     0,     0,     0,     0,
      12,    13,     0,     0,    14,    15,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    16,    17,     0,    18,    19,
       0,    20,     0,    21,    22,    23,     0,    24,    25,    26,
      27,    28,    29,     1,     2,     3,     4,     5,     6,     7,
     177,     8,     0,     9,     0,    10,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
       0,    12,    13,     0,     0,    14,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    16,    17,     0,    18,
      19,     0,    20,     0,    21,    22,    23,     0,    24,    25,
      26,    27,    28,    29,     1,     2,     3,     4,     5,     6,
       7,     0,     8,     0,     9,     0,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,    12,    13,     0,     0,    14,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    16,    17,     0,
      18,    19,     0,    20,     0,    21,    22,    23,     0,    24,
      25,    26,    27,    28,    29,     1,     2,     3,     4,     5,
       6,     7,     0,     8,     0,     9,     0,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    11,     0,     0,
       0,     0,     0,    12,    13,     0,     0,    14,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    16,    17,
       0,     0,    19,     0,    20,     0,    21,    22,    23,     0,
      24,    25,    26,     0,    28,    29,     1,     2,     3,     4,
       5,     6,     7,     0,    77,    86,     9,     0,    10,     1,
       2,     3,     4,     5,     6,     7,     0,    77,     0,     9,
       0,    10,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    12,    13,     0,     0,    14,    15,
       0,     0,     0,     0,     0,     0,     0,    12,    13,    16,
       0,    14,    15,     0,   131,     0,     0,     0,    22,     0,
       0,    24,    16,   132,     0,   133,    29,   134,     0,   135,
       0,    22,     0,     0,    24,   136,     0,   137,     0,    29,
       0,     0,   138,     0,     0,   139,   140,     0,     0,   141,
     142,     0,   143,     0,   144,     0,     0,   145,     0,     0,
       0,   146
  };

  const short int
  JS_Parser::yycheck_[] =
  {
       0,    10,    47,     0,    20,   101,    12,   102,     8,     9,
      10,     8,    12,     7,    14,    10,    25,     8,    10,    13,
      20,    15,    16,   206,     9,    25,    15,    17,    31,    19,
     186,    31,    22,    38,    31,    15,    73,    43,    15,    23,
      36,     9,    26,    48,    28,   243,   202,    43,    53,    15,
      58,    43,    14,    61,    26,    27,   101,    47,   103,    31,
       0,    13,    34,    15,     3,     4,     5,     6,     7,     8,
       9,   269,    11,    41,    13,    35,    15,    45,    73,    82,
      35,    43,    82,   266,    73,    82,    77,    39,    56,   105,
      35,   100,    14,    73,    35,    67,    28,    29,   114,    35,
     100,   196,    41,    42,    35,   105,    45,    46,    30,    16,
      17,   101,    42,    35,   114,    43,    46,    56,   171,   172,
      59,    43,    54,    55,    50,    23,    65,    25,    19,    68,
     130,    21,    71,    51,    73,    33,   136,   127,   168,   169,
     170,   186,    16,    17,    36,   130,    11,   147,   148,   149,
     246,   136,    72,   153,    15,    11,    43,   202,    30,   150,
      35,   206,   147,   148,   149,    14,   150,    43,   153,    63,
     163,   164,   165,   166,   167,    10,    12,    43,   178,   173,
     174,   175,   182,   159,   160,   161,   162,    14,    36,   180,
      36,    35,   192,   178,    36,   192,   186,   182,    10,    10,
     184,   246,    10,   203,    14,     0,    19,   100,   104,    24,
     246,   108,   202,   108,   103,    24,   149,    24,   203,   180,
     154,   266,   157,   182,    -1,    -1,   155,    -1,    -1,   156,
      -1,    -1,   248,   158,   243,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   243,    -1,    -1,    -1,    -1,   248,   265,
      -1,    -1,   261,    -1,    -1,   255,   246,   257,    -1,   275,
     269,   261,    -1,    -1,   280,   265,    -1,    -1,    -1,   269,
     255,    -1,   257,    -1,    -1,   275,    -1,    -1,     0,    -1,
     280,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    13,    -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
      -1,    -1,    11,    35,    13,    -1,    15,    -1,    -1,    41,
      42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    56,    57,    -1,    59,    60,    -1,
      62,    -1,    64,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    13,    -1,    15,    -1,    65,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,    -1,
      41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,    60,
      -1,    62,    -1,    64,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    41,    42,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,    59,
      60,    -1,    62,    -1,    64,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,     3,     4,     5,     6,     7,     8,
       9,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,    -1,
      -1,    -1,    41,    42,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    -1,
      59,    60,    -1,    62,    -1,    64,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,     3,     4,     5,     6,     7,
       8,     9,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    -1,    -1,
      -1,    -1,    -1,    41,    42,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,
      -1,    -1,    60,    -1,    62,    -1,    64,    65,    66,    -1,
      68,    69,    70,    -1,    72,    73,     3,     4,     5,     6,
       7,     8,     9,    -1,    11,    12,    13,    -1,    15,     3,
       4,     5,     6,     7,     8,     9,    -1,    11,    -1,    13,
      -1,    15,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    42,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    42,    56,
      -1,    45,    46,    -1,     9,    -1,    -1,    -1,    65,    -1,
      -1,    68,    56,    18,    -1,    20,    73,    22,    -1,    24,
      -1,    65,    -1,    -1,    68,    30,    -1,    32,    -1,    73,
      -1,    -1,    37,    -1,    -1,    40,    41,    -1,    -1,    44,
      45,    -1,    47,    -1,    49,    -1,    -1,    52,    -1,    -1,
      -1,    56
  };

  const unsigned char
  JS_Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,     7,     8,     9,    11,    13,
      15,    35,    41,    42,    45,    46,    56,    57,    59,    60,
      62,    64,    65,    66,    68,    69,    70,    71,    72,    73,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      91,    92,    93,    95,    96,    98,    99,   100,   105,   112,
     114,   116,   117,   119,   121,   122,   123,   124,   131,   132,
     133,   134,   135,   136,   137,   140,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,    11,   121,   135,
     153,    10,    76,   136,   138,   139,    12,   114,   141,   142,
     112,   121,   153,   121,   153,   153,    97,   117,    97,    78,
      15,    15,   106,   107,   117,   116,   123,   124,   125,   126,
     131,   112,   113,   116,   116,     0,    77,    35,    35,    35,
      35,    35,    35,   101,   102,   103,   117,   118,   120,   143,
      43,     9,    18,    20,    22,    24,    30,    32,    37,    40,
      41,    44,    45,    47,    49,    52,    56,   115,    13,    15,
      39,   127,   128,    16,    17,    50,    19,    21,    51,    28,
      29,    54,    55,    26,    27,    31,    34,    67,    23,    25,
      33,    42,    46,    38,    48,    53,   136,    10,    36,    10,
      43,    12,    43,    14,    72,    94,   100,   112,   103,   108,
     109,   110,    11,    82,   111,   118,   106,    78,   127,   128,
      11,    78,    43,    30,   104,   117,    16,   114,   114,   114,
     114,   129,   130,   129,   116,   136,   114,   144,   145,   146,
     147,   148,   149,   149,   149,   149,   150,   150,   150,   150,
     150,   151,   151,   151,   152,   152,   153,   153,   153,   114,
     139,   142,   116,    35,   102,    14,    43,    82,    63,    10,
      85,   102,   114,   120,    12,    43,    14,    36,   113,   110,
      78,    58,    61,    86,    87,    88,    36,   114,   114,    35,
     112,    36,    10,    78,    89,    90,   120,   113,    36,    78,
      14,    78
  };

  const unsigned char
  JS_Parser::yyr1_[] =
  {
       0,    74,    75,    76,    76,    77,    77,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    79,    79,
      80,    81,    82,    83,    83,    84,    84,    85,    85,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    92,    93,
      94,    94,    94,    95,    96,    97,    97,    98,    99,   100,
     100,   101,   101,   102,   103,   103,   104,   104,   105,   106,
     107,   108,   108,   109,   109,   110,   111,   111,   112,   112,
     113,   113,   114,   114,   114,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   116,   117,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   122,
     122,   122,   122,   123,   124,   125,   125,   125,   126,   126,
     127,   127,   127,   128,   129,   129,   130,   130,   131,   131,
     131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     133,   133,   134,   135,   136,   137,   137,   138,   138,   139,
     140,   140,   141,   141,   142,   143,   143,   144,   144,   145,
     145,   146,   146,   147,   147,   148,   148,   148,   148,   148,
     149,   149,   149,   149,   149,   149,   150,   150,   150,   150,
     151,   151,   151,   152,   152,   152,   152,   153,   153,   153,
     153,   153,   153,   153
  };

  const unsigned char
  JS_Parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     1,     2,     1,
       1,     1,     2,     1,     1,     2,     2,     2,     2,     1,
       1,     1,     3,     3,     5,     4,     6,     0,     2,     2,
       2,     3,     2,     1,     2,     1,     2,     4,     3,     9,
       0,     1,     2,     2,     2,     0,     1,     2,     2,     1,
       1,     1,     3,     2,     1,     2,     0,     2,     1,     2,
       3,     0,     1,     1,     3,     1,     0,     1,     1,     3,
       1,     0,     1,     3,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     1,     1,
       5,     1,     5,     1,     1,     1,     1,     2,     2,     2,
       2,     2,     2,     3,     2,     1,     2,     1,     1,     1,
       3,     2,     2,     3,     0,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     2,     3,     1,     3,     3,
       2,     3,     1,     3,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     3,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       2,     2,     2,     2
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const JS_Parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "NULL_V", "TRUE_V", "FALSE_V",
  "FLT_V", "INT_V", "STRING", "BIT_NOT_OP", "CLOSE_C", "OPEN_C", "CLOSE_B",
  "OPEN_B", "CLOSE_P", "OPEN_P", "TERNARY_OP", "LOGIC_OR_OP",
  "SHORT_BIT_OR_OP", "BIT_OR_OP", "SHORT_BIT_XOR_OP", "BIT_XOR_OP",
  "SHORT_BIT_SHIFT_Z_R_OP", "BIT_SHIFT_Z_R_OP", "SHORT_BIT_SHIFT_S_R_OP",
  "BIT_SHIFT_S_R_OP", "GE_OP", "G_OP", "EQ_VT_OP", "EQ_V_OP", "VA_OP",
  "LE_OP", "SHORT_BIT_SHIFT_L_OP", "BIT_SHIFT_L_OP", "L_OP", "STMT_TER_OP",
  "PA_OP", "SHORT_DIV_OP", "DIV_OP", "MEM_ACC_OP", "SHORT_SUB_OP",
  "UNIT_SUB_OP", "SUB_OP", "SEP_OP", "SHORT_ADD_OP", "UNIT_ADD_OP",
  "ADD_OP", "SHORT_MUL_OP", "MUL_OP", "SHORT_BIT_AND_OP", "LOGIC_AND_OP",
  "BIT_AND_OP", "SHORT_MOD_OP", "MOD_OP", "NEG_VT_OP", "NEG_V_OP",
  "LOGIC_NOT_OP", "BREAK", "CASE", "CONST", "CONTINUE", "DEFAULT", "DO",
  "ELSE", "FOR", "FUNCTION", "IF", "INSTANCEOF", "NEW", "RETURN", "SWITCH",
  "VAR", "WHILE", "ID", "$accept", "Program", "Statements", "Statement",
  "CodeStatement", "Definition", "EmptyStatement", "ExpressionStatement",
  "Block", "IfStatement", "SwitchStatement", "CaseGroups", "CaseGroup",
  "LastCaseGroup", "CaseGuards", "CaseStatements", "CaseStatementsPrefix",
  "DoStatement", "WhileStatement", "ForStatement", "ForInitializer",
  "ContinueStatement", "BreakStatement", "OptionalLabel",
  "ReturnStatement", "VariableDefinition", "VariableDefinitionKind",
  "VariableBindingList", "VariableBinding", "TypedIdentifier",
  "VariableInitializer", "FunctionDefinition", "FunctionSignature",
  "ParameterSignature", "Parameters", "RequiredParameters",
  "RequiredParameter", "ResultSignature", "Expression",
  "OptionalExpression", "AssignmentExpression", "CompoundAssignment",
  "ParenthesizedExpression", "Identifier", "TypeExpression",
  "ConditionalExpression", "NonAssignmentExpression", "PostfixExpression",
  "FullPostfixExpression", "FullNewExpression", "ShortNewExpression",
  "FullNewSubexpression", "ShortNewSubexpression", "MemberOperator",
  "Arguments", "ArgumentList", "ArgumentListPrefix", "PrimaryExpression",
  "SimpleExpression", "FunctionExpression", "AnonymousFunction",
  "NamedFunction", "QualifiedIdentifier", "ObjectLiteral", "FieldList",
  "LiteralField", "ArrayLiteral", "ElementList", "LiteralElement",
  "LogicalOrExpression", "LogicalAndExpression", "BitwiseOrExpression",
  "BitwiseXorExpression", "BitwiseAndExpression", "EqualityExpression",
  "RelationalExpression", "ShiftExpression", "AdditiveExpression",
  "MultiplicativeExpression", "UnaryExpression", YY_NULLPTR
  };


  const unsigned short int
  JS_Parser::yyrline_[] =
  {
       0,   195,   195,   199,   200,   204,   205,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,   219,   223,   224,
     228,   232,   236,   240,   241,   245,   246,   249,   251,   255,
     259,   263,   264,   268,   269,   273,   274,   278,   282,   286,
     289,   291,   292,   296,   300,   303,   305,   309,   313,   317,
     318,   322,   323,   327,   331,   332,   335,   337,   341,   345,
     349,   352,   354,   358,   359,   363,   366,   368,   372,   373,
     377,   378,   382,   383,   384,   388,   389,   390,   391,   392,
     393,   394,   395,   396,   397,   398,   402,   406,   410,   414,
     415,   419,   420,   424,   425,   429,   430,   431,   432,   433,
     434,   435,   436,   440,   444,   448,   449,   450,   454,   455,
     459,   460,   461,   465,   468,   470,   474,   475,   479,   480,
     481,   485,   486,   487,   488,   489,   490,   491,   492,   493,
     497,   498,   502,   506,   510,   514,   515,   519,   520,   524,
     528,   529,   533,   534,   538,   542,   543,   547,   548,   552,
     553,   557,   558,   562,   563,   567,   568,   569,   570,   571,
     575,   576,   577,   578,   579,   580,   584,   585,   586,   587,
     591,   592,   593,   597,   598,   599,   600,   604,   605,   606,
     607,   608,   609,   610
  };

  // Print the state stack on the debug stream.
  void
  JS_Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  JS_Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  JS_Parser::token_number_type
  JS_Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73
    };
    const unsigned int user_token_number_max_ = 328;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }

#line 5 "js_parser.yy" // lalr1.cc:1167
} // JS
#line 1254 "js_parser.tab.cc" // lalr1.cc:1167
#line 613 "js_parser.yy" // lalr1.cc:1168

void 
JS::JS_Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
