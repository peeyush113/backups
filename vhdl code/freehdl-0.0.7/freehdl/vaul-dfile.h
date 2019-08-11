/* parsing of VHDL text files

   Copyright (C) 1994-1997 University of Dortmund
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

#ifndef FREEHDL_VAUL_DFILE
#define FREEHDL_VAUL_DFILE

#include <freehdl/vaul-errors.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-pool.h>

struct vaul_design_unit;

struct vaul_design_file : vaul_error_source {

  vaul_design_file (const char *filename, FILE *f = NULL,
		    vaul_parser_options &options =
		    vaul_parser::default_options);
  // Öffnet die Datei <filename> zum Lesen, wenn 'f == NULL'.
  // Sonst wird aus <f> gelesen und <filename> wird nur für
  // Fehlermeldungen verwendet.

  ~vaul_design_file();

  vaul_design_unit *read_design_unit (vaul_pool *pool, vaul_consumer* = NULL);
  // Liest eine Design Unit. Meldungen über fehlerhaften
  // VHDL-Text werden nach 'stderr' ausgegeben und mitgezählt.
  // Siehe 'sync_vaul_errors()'.
  // "WORK" im VHDL-Text bezieht sich auf 'pool->worklib' und
  // andere benötigte VHDL-Libraries werden durch 'pool' gefunden.
  // Im Fehlerfall oder am Ende der Datei wird 'NULL' zurückgegeben.

  bool was_eof () { return parser.was_eof (); }

private:
  vaul_lexer lexer;
  vaul_parser parser;
};

#endif
