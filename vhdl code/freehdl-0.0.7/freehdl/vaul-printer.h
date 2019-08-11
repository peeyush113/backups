/* beefed up printf

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

#ifndef FREEHDL_VAUL_PRINTER_H
#define FREEHDL_VAUL_PRINTER_H

#include <stdio.h>
#include <stdarg.h>
#include <iostream>

struct tree_base_node;
std::ostream &operator<< (std::ostream &o, tree_base_node *n);

struct vaul_printer {
  virtual ~vaul_printer() {};

  void printf(const char *fmt, ...);
  void fprintf(FILE *, const char *fmt, ...);
  void vfprintf(FILE *, const char *fmt, va_list ap);

protected:
  virtual void print_node (FILE *, tree_base_node *);
};


#endif
