/* flex scanner. -*- c++ -*-

   Copyright (C) 1993, 2003 Universite Pierre et Marie Curie (PARIS VI)
   MASI/CAO-VLSI CAD Team

   Copyright (C) Thomas Dettmer

   Copyright (C) 1994-1997 University of Dortmund
   Department of Electrical Engineering, AG SIV

   Yes, this file has been hacked by many people, and it shows.

   VAUL is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   VAUL is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General
   Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with VAUL; see the file COPYING.LIB.  If not, write
   to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA.

   Please see the file "vhdl.lex" for additional details.
*/

%{

#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-util.h>

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

int yyFlexLexer::yywrap() { return 1; }

  //using namespace std;

inline static void str_to_name(char *n)
{
    while(*n) {
	*n = tolower(*n);
	n++;
    }
}

#include "bison-parser.h"

#define YY_DECL int vaul_lexer::lex(vaul_yystype *val, vaul_yyltype *loc)

#define set_loc()	{ loc->first_line = lineno; }
#define YY_USER_ACTION	set_loc();

#define MVL_LG_MC 15
#define MVL_NB_MC (sizeof(tab_mc)/sizeof(struct el_mc))  // 84

int MVL_LINNUM=1;

struct el_mc {
  char nom[MVL_LG_MC];
  int kval, skip_kval;
};

static el_mc tab_mc []=
  {
    {"abs"	    ,t_ABS, t_ABS},
    {"access"	    ,t_ACCESS, t_ACCESS},
    {"after"	    ,t_AFTER, t_AFTER},
    {"alias"	    ,t_ALIAS, t_ALIAS},
    {"all"	    ,t_ALL, t_ALL},
    {"and"	    ,t_AND, t_AND},
    {"architecture" ,t_ARCHITECTURE, skip_t_ARCHITECTURE},
    {"array"	    ,t_ARRAY, t_ARRAY},
    {"assert"	    ,t_ASSERT, t_ASSERT},
    {"attribute"    ,t_ATTRIBUTE, t_ATTRIBUTE},
    {"begin"	    ,t_BEGIN, t_BEGIN},
    {"block"	    ,t_BLOCK, t_BLOCK},
    {"body"	    ,t_BODY, skip_t_BODY},
    {"buffer"	    ,t_BUFFER, t_BUFFER},
    {"bus"	    ,t_BUS, t_BUS},
    {"case"	    ,t_CASE, t_CASE},
    {"component"    ,t_COMPONENT, t_COMPONENT},
    {"configuration",t_CONFIGURATION, skip_t_CONFIGURATION},
    {"constant"	    ,t_CONSTANT, t_CONSTANT},
    {"disconnect"   ,t_DISCONNECT, t_DISCONNECT},
    {"downto"	    ,t_DOWNTO, t_DOWNTO},
    {"else"	    ,t_ELSE, t_ELSE},
    {"elsif"	    ,t_ELSIF, t_ELSIF},
    {"end"	    ,t_END, t_END},
    {"entity"	    ,t_ENTITY, t_ENTITY},
    {"exit"	    ,t_EXIT, t_EXIT},
    {"file"	    ,t_FILE, t_FILE},
    {"for"	    ,t_FOR, t_FOR},
    {"function"	    ,t_FUNCTION, t_FUNCTION},
    {"generate"	    ,t_GENERATE, t_GENERATE},
    {"generic"	    ,t_GENERIC, t_GENERIC},
    {"guarded"	    ,t_GUARDED, t_GUARDED},
    {"if"	    ,t_IF, t_IF},
    {"impure"       ,t_IMPURE, t_IMPURE},
    {"in"	    ,t_IN, t_IN},
    {"inertial"     ,t_INERTIAL, t_INERTIAL},
    {"inout"	    ,t_INOUT, t_INOUT},
    {"is"	    ,t_IS, t_IS},
    {"label"	    ,t_LABEL, t_LABEL},
    {"library"	    ,t_LIBRARY, t_LIBRARY},
    {"linkage"	    ,t_LINKAGE, t_LINKAGE},
    {"loop"	    ,t_LOOP, t_LOOP},
    {"map"	    ,t_MAP, t_MAP},
    {"mod"	    ,t_MOD, t_MOD},
    {"nand"	    ,t_NAND, t_NAND},
    {"new"	    ,t_NEW, t_NEW},
    {"next"	    ,t_NEXT, t_NEXT},
    {"nor"	    ,t_NOR, t_NOR},
    {"not"	    ,t_NOT, t_NOT},
    {"null"	    ,t_NULL, t_NULL},
    {"of"	    ,t_OF, t_OF},
    {"on"	    ,t_ON, t_ON},
    {"open"	    ,t_OPEN, t_OPEN},
    {"or"	    ,t_OR, t_OR},
    {"others"	    ,t_OTHERS, t_OTHERS},
    {"out"	    ,t_OUT, t_OUT},
    {"package"	    ,t_PACKAGE, t_PACKAGE},
    {"port"	    ,t_PORT, t_PORT},
    {"postponed"    ,t_POSTPONED, t_POSTPONED},
    {"procedure"    ,t_PROCEDURE, t_PROCEDURE},
    {"process"	    ,t_PROCESS, t_PROCESS},
    {"pure"         ,t_PURE, t_PURE},
    {"range"	    ,t_RANGE, t_RANGE},
    {"record"	    ,t_RECORD, t_RECORD},
    {"register"	    ,t_REGISTER, t_REGISTER},
    {"reject"       ,t_REJECT, t_REJECT},
    {"rem"	    ,t_REM, t_REM},
    {"report"	    ,t_REPORT, t_REPORT},
    {"return"	    ,t_RETURN, t_RETURN},
    {"reverse_range",t_REVERSE_RANGE, t_REVERSE_RANGE},
    {"rol"          ,t_ROL, t_ROL},
    {"ror"          ,t_ROR, t_ROR},
    {"select"	    ,t_SELECT, t_SELECT},
    {"severity"	    ,t_SEVERITY, t_SEVERITY},
    {"signal"	    ,t_SIGNAL, t_SIGNAL},
    {"sla"          ,t_SLA, t_SLA},
    {"sll"          ,t_SLL, t_SLL},
    {"sra"          ,t_SRA, t_SRA},
    {"srl"          ,t_SRL, t_SRL},
    {"subtype"	    ,t_SUBTYPE, t_SUBTYPE},
    {"then"	    ,t_THEN, t_THEN},
    {"to"	    ,t_TO, t_TO},
    {"transport"    ,t_TRANSPORT, t_TRANSPORT},
    {"type"	    ,t_TYPE, t_TYPE},
    {"units"	    ,t_UNITS, t_UNITS},
    {"until"	    ,t_UNTIL, t_UNTIL},
    {"use"	    ,t_USE, t_USE},
    {"variable"	    ,t_VARIABLE, t_VARIABLE},
    {"wait"	    ,t_WAIT, t_WAIT},
    {"when"	    ,t_WHEN, t_WHEN},
    {"while"	    ,t_WHILE, t_WHILE},
    {"with"	    ,t_WITH, t_WITH},
    {"xnor"	    ,t_XNOR, t_XNOR},
    {"xor"	    ,t_XOR, t_XOR}
};

typedef int cmpfunc_t(const void *, const void *);

static int find_mc(char *s, int skip_p)
{
    char l[strlen(s)+1];
    strcpy(l, s);
    str_to_name(l);
    el_mc *pt = (el_mc *) bsearch(l, tab_mc, MVL_NB_MC, sizeof(el_mc),
			  (cmpfunc_t *)strcmp);
    if (pt==NULL)
	return(-1);
    else
	return(skip_p? pt->skip_kval : pt->kval);
}

%}

%option C++ noyywrap

upper_case_letter	[A-Z]
digit			[0-9]
special_char		[\#\&\'\(\)\*\+\,\-\.\/\:\;\<\=\>\_\|]
space_char		[ \t]
format_effector		[\t\v\r\f]
end_of_line		\n
lower_case_letter	[a-z]
other_special_char	[\!\$\@\?\[\\\]\^\`\{\}\~]

graphic_char {basic_graphic_char}|{lower_case_letter}|{other_special_char}
basic_graphic_char {upper_case_letter}|{digit}|{special_char}|{space_char}
letter		    {upper_case_letter}|{lower_case_letter}
letter_or_u         {letter}|\_
letter_or_digit	    {letter}|{digit}
letter_or_u_or_digit {letter_or_u}|{digit}
decimal_literal	    {integer}(\.{integer})?({exponent})?
integer		    {digit}(_?{digit})*
exponent	    [eE][-+]?{integer}
base		    {integer}
based_integer	    {extended_digit}(_?{extended_digit})*
extended_digit	    {digit}|[a-fA-F]
base_specifier	    (B|b|O|o|X|x)
%%

	    if(stopped) return 0;

{space_char}	    /* nothing */
{format_effector}   /* still nothing */

\&	    return t_Ampersand;
\'	    return t_Apostrophe;
\(	    return t_LeftParen;
\)	    return t_RightParen;
"**"	    return t_DoubleStar;
\*	    return t_Star;
\+	    return t_Plus;
\,	    return t_Comma;
\-	    return t_Minus;
":="	    return t_VarAsgn;
\:	    return t_Colon;
\;	    return t_Semicolon;
"<="	    return t_LESym;
">="	    return t_GESym;
\<	    return t_LTSym;
\>	    return t_GTSym;
\=	    return t_EQSym;
"/="	    return t_NESym;
"=>"	    return t_Arrow;
"<>"	    return t_Box;
\|	    return t_Bar;
!	    return t_Bar;
\.	    return t_Dot;
\/	    return t_Slash;

{letter_or_u}(_?{letter_or_u_or_digit})*  {

  /* Allow underscores everywhere, and complain later */

	    int itoken;

	    maybe_complain_about_improper_underscores (yytext);

	    itoken=find_mc(yytext, skipping);
	    if (itoken== -1) {
		val->tree.IIR_Identifier =
		   creator->mIIR_Identifier (lineno, 
                                             (IR_Character *) yytext,
                                             (int) yyleng);
		return t_Identifier;
	    } else
		return itoken;
	}


{decimal_literal}|({base}#{based_integer}(\.{based_integer})?#{exponent}?)|({base}:{based_integer}(\.{based_integer})?:{exponent}?)	{
  
    if (strchr (yytext, '.'))
      val->tree.IIR_Literal = 
        creator->mIIR_FloatingPointLiteral (lineno,
			 		    (IR_Character *) yytext,
					    (int) yyleng);
    else
      val->tree.IIR_Literal = 
	creator->mIIR_IntegerLiteral (lineno,
			 	      (IR_Character *) yytext,
				      (int) yyleng);
    return t_AbstractLit;
  }


'({graphic_char}|\"|\%)'    {

            val->tree.IIR_CharacterLiteral =
	      creator->mIIR_CharacterLiteral (lineno,
					      (IR_Character *) yytext,
	                                      (int) yyleng);
	    return t_CharacterLit;
	}

(\"({graphic_char}|(\"\")|\%)*\")|(\%({graphic_char}|(\%\%)|\")*\%) {

            val->tree.IIR_StringLiteral =
	      creator->mIIR_StringLiteral (lineno,
					   (IR_Character *) yytext,
					   (int) yyleng);
	    return t_StringLit;
	}

{base_specifier}(\"{extended_digit}(_?{extended_digit})*\"|\%{extended_digit}(_?{extended_digit})*\%)		{

            val->tree.IIR_StringLiteral =
	      creator->mIIR_StringLiteral (lineno,
					   expand_bitstring(yytext, yyleng));
	    return t_StringLit;
	}

\n	    lineno++;

\-\-.*$	    /* comment */

.	{   
	    if(prt)
		prt->fprintf(log, "%?illegal character '0x%02x'\n",
				     this, (unsigned char)yytext[0]);
	}


%%

int
yyFlexLexer::yylex ()
{
  vaul_fatal ("internal lexer fuck up\n");
  return 0;	
}

vaul_lexer::vaul_lexer (const char *fn, FILE *f)
{
  close_file = 0;
  file = NULL;
  filename = vaul_xstrdup (fn);
  lineno = 1;
  prt = NULL;

  if (f == NULL) 
    {
      if (!(f = fopen(fn, "r")))
	{
	  set_error ();
	  return;
	}
      close_file = 1;
    }
  file = f;
  stopped = false;
  skipping = false;
}

vaul_lexer::~vaul_lexer()
{
  if (close_file)
    fclose (file);
  free (filename);
}

void
vaul_lexer::stop ()
{
  stopped = true;
}

void
vaul_lexer::skip_bodies (bool flag)
{
  skipping = flag;
}

int
vaul_lexer::LexerInput (char *buf, int max_size)
{
  if (file == NULL)
    return 0;

  if (!fgets (buf, max_size, file))
    {
      set_error ();
      return 0;
    }

  return strlen (buf);
}

void
vaul_lexer::LexerError (char *m)
{
  if (prt)
    prt->fprintf (log, "%?%s %C\n", this, m, this);
  else
    fprintf (stderr, "%s:%d: %s at %s\n", filename, lineno, m, context());
}

IR_String
vaul_lexer::expand_bitstring (const char *tok, int len)
{
  char buf[len*4];
  char *bp = buf;

  char bid = tolower (tok[0]);
  int bits = (bid == 'b'? 1 : bid == 'o'? 3 : bid == 'x'? 4 : 0);
  if(bits == 0
     || (tok[1] != '"' && tok[1] != '%') 
     || (tok[strlen(tok)-1] != '"' && tok[strlen(tok)-1] != '%'))
    {
      prt->fprintf (log, "%?illegal bitstring literal\n", this);
      return IR_String ((IR_Character *)"\"\"", 2);
    }

  *bp++ = '"';
  for (const char *cp = tok+2; *cp != '"' && *cp != '%'; cp++)
    {
      if (*cp == '_')
	continue;
      int dig = tolower (*cp) - '0';
      if (dig > 10)
	dig -= 'a'-'9'-1;
      if (dig >= (1 << bits)) 
	{
	  prt->fprintf (log, "%?illegal digit '%c' in bitstring literal\n",
			this, *cp);
	  dig = 0;
	}
      
      for (int i = bits-1; i >= 0; i--)
	*bp++ = (dig & (1 << i))? '1' : '0';
    }
  *bp++ = '"';
  *bp = '\0';
  // prt->fprintf (log, "%?xxx - expanded '%s' to '%s'\n", this, tok, buf);
  return IR_String ((IR_Character *)buf, bp-buf);
}

void
vaul_lexer::maybe_complain_about_improper_underscores (const char *id)
{
  // Underscores are not allowed at the start, the end, and immediatly
  // following another underscore.

  bool underscore_allowed = false;
  for (const char *cp = id; *cp; cp++)
    {
      if (*cp == '_')
	{
	  if (!underscore_allowed || *(cp+1) == '\0')
	    prt->fprintf (log, "%?illegal underscore in `%s'\n", this, id);
	  underscore_allowed = false;
	}
      else
	underscore_allowed = true;
    }
}

bool
vaul_name_eq (const char *n1, const char *n2)
{
  if (n1 == NULL || n2 == NULL)
    return false;
  if (n1[0] == '\\' || n1[0] == '\'')
    return !strcmp (n1, n2);
  else
    return !strcasecmp (n1, n2);
}

bool
vaul_name_eq (pIIR_TextLiteral i1, pIIR_TextLiteral i2)
{
  if (i1 == NULL || i2 == NULL)
    return false;

  int len = i1->text.len();
  if (i2->text.len() != len)
    return false;

  // XXX - this is slow

  char *n1 = i1->text.to_chars(), *n2 = i2->text.to_chars();

  if (n1[0] == '\\' || n1[0] == '\'')
    return !strncmp (n1, n2, len);
  else
    return !strncasecmp (n1, n2, len);
}

bool
vaul_name_eq (pIIR_TextLiteral i1, const char *n2)
{
  if (i1 == NULL || n2 == NULL)
    return false;

  unsigned int len = i1->text.len();
  if (strlen (n2) != len)
    return false;

  char *n1 = i1->text.to_chars();

  if (n1[0] == '\\' || n1[0] == '\'')
    return !strncmp (n1, n2, len);
  else
    return !strncasecmp (n1, n2, len);
}

bool
vaul_name_eq (const char *n1, pIIR_TextLiteral i2)
{
  return vaul_name_eq (i2, n1);
}

bool
vaul_pos_eq (pIIR_PosInfo p1, pIIR_PosInfo p2)
{
  if (p1->is(IR_POS_INFO_TEXT_FILE)
      && p2->is(IR_POS_INFO_TEXT_FILE))
    {
      pIIR_PosInfo_TextFile pt1 = pIIR_PosInfo_TextFile (p1);
      pIIR_PosInfo_TextFile pt2 = pIIR_PosInfo_TextFile (p2);
      return pt1->file_name == pt2->file_name
	&& pt1->line_number == pt2->line_number;
    }
  
  return false;
}
