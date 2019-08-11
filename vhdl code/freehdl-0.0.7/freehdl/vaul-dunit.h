/* a design unit represented as an abstract graph

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

#ifndef FREEHDL_VAUL_DUNIT_H
#define FREEHDL_VAUL_DUNIT_H

#include <freehdl/vaul-ref.h>
#include <freehdl/vaul-errors.h>

struct IIR_LibraryUnit;

struct vaul_design_unit : vaul_error_source, vaul_ref {

  vaul_design_unit (char *library = NULL, char *name = NULL,
		    char *source = NULL);
  ~vaul_design_unit ();
  
  void set_library (char *library);
  void set_name (char *name);
  void set_source (char *source);
  void set_tree (IIR_LibraryUnit *);

  char *get_library ();
  char *get_name ();
  char *get_source ();
  IIR_LibraryUnit *get_tree ();

  void uses (vaul_design_unit *du);
  vaul_design_unit *query_used_dus (vaul_design_unit *);

private:
  char *library;
  char *name;
  char *source;
  IIR_LibraryUnit *tree;
  struct du_entry {
    du_entry *link;
    vaul_design_unit *du;
  } *used_dus;
};

#endif
