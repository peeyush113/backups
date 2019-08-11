/* implementation of vaul_design_unit

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

#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-util.h>

#include <errno.h>
#include <string.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif

#include "debug.h"

vaul_design_unit::vaul_design_unit (char *l, char *n, char *s)
{
  library = vaul_xstrdup (l);
  name = vaul_xstrdup (n);
  source = vaul_xstrdup (s);
  tree = NULL;
  used_dus = NULL;
}

vaul_design_unit::~vaul_design_unit ()
{
  debug("deleting unit %p (%s)\n", this, name);
  
  if (tree)
    {
      tree_unprotect (tree);
      // fprintf (stderr, "after freeing %s: ", name); 
      tree_collect_garbage ();
    }

  free (library);
  free (name);
  free (source);

  du_entry *de, *de2;
  for (de = used_dus; de; de = de2)
    {
      de2 = de->link;
      de->du->release ();
      delete de;
    }
}

void
vaul_design_unit::set_library (char *l)
{
  free (library);
  library = vaul_xstrdup (l);
}

void
vaul_design_unit::set_name (char *n)
{
  free (name);
  name = vaul_xstrdup (n);
}

void
vaul_design_unit::set_source (char *s)
{
  free (source);
  source = vaul_xstrdup (s);
}

void
vaul_design_unit::set_tree (IIR_LibraryUnit *t)
{
  tree_protect (t);
  tree_unprotect (tree);
  tree = t;
}

char *
vaul_design_unit::get_library ()
{
  return library;
}

char *
vaul_design_unit::get_name ()
{
  return name;
}

char *
vaul_design_unit::get_source ()
{
  return source;
}

IIR_LibraryUnit *
vaul_design_unit::get_tree ()
{
  return tree;
}

void
vaul_design_unit::uses (vaul_design_unit *du)
{
  if(du == this)
    return;

  du_entry *de;
  for (de = used_dus; de; de = de->link)
    if (de->du == du)
      return;
  de = new du_entry;
  retain_ref (du);
  de->du = du;
  de->link = used_dus;
  used_dus = de;
}

vaul_design_unit *
vaul_design_unit::query_used_dus (vaul_design_unit *du)
{
  if(du == NULL)
    return used_dus? used_dus->du : NULL;
  else 
    {
      for (du_entry *de = used_dus; de; de = de->link)
	if (de->du == du)
	  return de->link? de->link->du : NULL;
      return NULL;
    }
}

