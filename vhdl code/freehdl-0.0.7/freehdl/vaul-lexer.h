/* the lexical scanner

   Copyright (C) 1994-1997, 2003 University of Dortmund
   Department of Electrical Engineering, AG SIV

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

*/

#ifndef FREEHDL_VAUL_LEXER_H
#define FREEHDL_VAUL_LEXER_H

#include <freehdl/vaul-errors.h>
#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-mempool.h>
#include <freehdl/vaul-printer.h>

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

using namespace std;

#undef yyFlexLexer
#define yyFlexLexer vaul_FlexLexer
#include <freehdl/FlexLexer.h>

// sind zwei VHDL-Namen gleich?
//
bool vaul_name_eq(const char *n1, const char *n2);
bool vaul_name_eq(pIIR_TextLiteral i1, pIIR_TextLiteral i2);
bool vaul_name_eq(pIIR_TextLiteral i1, const char *n2);
bool vaul_name_eq(const char *n1, pIIR_TextLiteral i2);

bool vaul_pos_eq (pIIR_PosInfo p1, pIIR_PosInfo p2);

// vaul_yystype hält den semantischen Wert von Token
//
union vaul_yystype {
  VAUL_Tree tree;
  IR_Direction dir;
  VAUL_ObjectClass obj_class;
  IR_Mode mode;
  IR_SignalKind signal_kind;
  bool boolean;
  IR_Kind kind;
};

// vaul_yyltype hält Informationen über die Position eines Tokens
//
struct vaul_yyltype {
  int first_line,
    last_line,
    first_column,
    last_column;
  char *text;

  operator int () { return first_line; }
};

// vaul_lexer enthält den von 'flex++' generierten lexikalischen
// Analysator.
//
struct vaul_lexer : public vaul_FlexLexer, vaul_error_source {

  vaul_lexer(const char *filename, FILE *f = NULL);
  // Öffnet die Datei 'filename' zum Lesen, wenn 'f == NULL'.
  // Sonst wird aus 'f' gelesen und 'filename' wird nur für
  // Fehlermeldungen verwendet.

  ~vaul_lexer();

  int lex(vaul_yystype *val, vaul_yyltype *loc);
  // Sucht das nächste Token und füllt '*val' und '*loc' mit
  // passenden Werten.

  int lineno;
  char *filename;

  void set_printer(vaul_printer *p, FILE *f) { prt = p; log = f; }
  void set_creator(vaul_node_creator *c)     { creator = c; }

  const char *context()
  {
    return yytext[0]? yytext : "end of input"; 
  }
  
  void stop();
  void skip_bodies (bool);

private:
  FILE *file;
  bool close_file;
  
  vaul_printer *prt;
  vaul_node_creator *creator;
  FILE *log;
  
  bool stopped;
  bool skipping;

  IR_String expand_bitstring(const char *, int len);
  
  int LexerInput(char *buf, int max_size);
  void LexerError(char *msg);
  void message(char *fmt, va_list ap);
  void message(vaul_yyltype &loc, char *fmt, va_list ap);

  void maybe_complain_about_improper_underscores (const char *id);
};

#endif
