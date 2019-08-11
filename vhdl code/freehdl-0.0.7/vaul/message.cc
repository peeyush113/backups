/* printing errors and such

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

#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-printer.h>

void vaul_error_printer::info(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vinfo(fmt, ap);
    va_end(ap);
}

void vaul_error_printer::error(const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vinfo(fmt, ap);
    va_end(ap);
    n_errors++;
}

void vaul_error_printer::vinfo(const char *fmt, va_list ap)
{
    vfprintf(log, fmt, ap);
    int l = strlen(fmt);
    if(l < 2 || fmt[l-2] != '%' || fmt[l-1] != '~')
	fprintf(log, "\n");
}

void vaul_parser::BisonError(const char *msg)
{
    error("%s %C", msg, lex);
    lex->stop();
}

void vaul_parser::vinfo(const char *fmt, va_list ap)
{
  if (announced_scope != cur_scope && cur_scope != NULL) 
    {
      pIIR_DeclarativeRegion s = cur_scope;
      while (s->declarator == NULL && s->continued)
	s = s->continued;
      while (s->declarator == NULL && s->declarative_region)
	s = s->declarative_region;
      if (announced_scope != s) 
	{
	  announced_scope = s;
	  if (s->is(VAUL_TOP_SCOPE))
	    vaul_error_printer::info ("%!at top level:", lex, 0);
	  else if (s->is(IR_ARCHITECTURE_DECLARATION))
	    vaul_error_printer::info ("%!in %n(%n):", lex, 0,
				      s->continued, s->declarator);
	  else
	    vaul_error_printer::info ("%!in %n:", lex, 0, s);
	}
    }
  if (fmt[0] != '%' || !strchr(":?!~", fmt[1]))
    fprintf (log, "%?", lex);
  if (strstr (fmt, "XXX"))
    XXX_seen = true;
  vaul_error_printer::vinfo (fmt, ap);
}

void
vaul_parser::print_node (FILE *f, tree_base_node *n)
{
  if (options.fullnames)
    {
      if (n && n->is(IR_DECLARATION)
	  && pIIR_Declaration(n)->declarative_region
	  && pIIR_Declaration(n)->declarative_region != announced_scope
	  && !pIIR_Declaration(n)->declarative_region->is(VAUL_TOP_SCOPE))
	{
	  pIIR_DeclarativeRegion as = announced_scope;
	  announced_scope = NULL;
	  fprintf (f, "%n::", pIIR_Declaration(n)->declarative_region);
	  announced_scope = as;
	}
    }

  vaul_printer::print_node (f, n);
}
