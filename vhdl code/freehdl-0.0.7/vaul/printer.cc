/* custom printf

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

#include <freehdl/vaul-printer.h>
#include <freehdl/fire-chunk.h>
#include <freehdl/vaul-lexer.h>
#include <string.h>
#include <sstream>

using namespace std;

void vaul_printer::printf (const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(stdout, fmt, ap);
    va_end(ap);
}

void vaul_printer::fprintf (FILE *f, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vfprintf(f, fmt, ap);
    va_end(ap);
}

void vaul_printer::vfprintf (FILE *out, const char *fmt, va_list ap)
{
    const char *mods = "-+ #*0123456789.hlL";

    while (*fmt)
      {
	const char *cp;
	for (cp = fmt; *fmt && *fmt != '%'; fmt++)
	  ;
	fwrite (cp, sizeof(char), fmt-cp, out);
	if (*fmt == '%')
	  {
	    const char *spec = fmt++;
	    while (*fmt && strchr(mods, *fmt))
	      fmt++;
	    if (*fmt)
	      {
		fmt++;
		int len = fmt - spec;

		switch (spec[len-1])
		  {
		  case 'i':
		  case 'd':
		    if (spec[len-2] == 'l')
		      ::fprintf (out, "%ld", va_arg (ap, long int));
		    else
		      ::fprintf (out, "%d", va_arg (ap, int));
		    break;
		  case 'x':
		    if (spec[len-2] == 'l')
		      ::fprintf (out, "%lx", va_arg (ap, long int));
		    else
		      ::fprintf (out, "%x", va_arg (ap, int));
		    break;
		  case 'c':
		    ::fprintf (out, "%c", va_arg (ap, int));
		  break;
		  case 's':
		    ::fprintf (out, "%s", va_arg (ap, const char *));
		  break;
		  case 'p':
		    ::fprintf (out, "%p", va_arg (ap, const char *));
		  break;

		  case 'n':
		    {
		      tree_base_node *n = va_arg (ap, tree_base_node *);
		      print_node (out, n);
		      break;
		    }

		  case ':': 
		    {
		      pIIR_Root n = va_arg (ap, pIIR_Root);
		      if (n)
			{
			  ostringstream str;
			  str << n->pos << '\0';
			  ::fprintf (out, "%s: ", str.str().c_str());
			}
		      else
			::fprintf (out, "?:?: ");
		      break;
		    }

		  case ';':
		    {
		      pIIR_Root n = va_arg (ap, pIIR_Root);
		      if (n)
			{
			  if (n->pos->is (IR_POS_INFO_TEXT_FILE))
			    ::fprintf (out, "%i", pIIR_PosInfo_TextFile (n->pos)->line_number);
			  else
			    ::fprintf (out, "?");
			}
		      break;
		    }
		    
		  case '?':
		    {
		      vaul_lexer *l = va_arg (ap, vaul_lexer *);
		      if (l) 
			::fprintf (out, "%s:%d: ", l->filename, l->lineno);
		      break;
		    }

		  case '!':
		    {
		      vaul_lexer *l = va_arg (ap, vaul_lexer *);
		      int pos = va_arg (ap, int);
		      if (l)
			::fprintf (out, "%s:", l->filename);
		      if (pos > 0)
			::fprintf (out, "%d:", pos);
		      if (l || pos > 0)
			::fprintf (out, " ");
		      break;
		    }
		    
		  case 'C':
		    {
		      vaul_lexer *l = va_arg (ap, vaul_lexer *);
		      ::fprintf (out, "at %s", l->context());
		      break;
		    }

		  case '~':
		    break;

		  default:
		    ::fprintf (out, "?%c?", spec[len-1]);
		  break;
		  
		  }
		
	      }
	  }
      }
}

void
vaul_printer::print_node (FILE *f, tree_base_node *n)
{
  ostringstream str;
  str << n << '\0';
  fputs (str.str().c_str(), f);
}

void vaul_print_to_ostream (tree_base_node *n, ostream &o);

ostream&
operator<< (ostream &o, tree_base_node *n)
{
  if (n)
    vaul_print_to_ostream (n, o);
  else
    o << "<null>";
  return o;
}
