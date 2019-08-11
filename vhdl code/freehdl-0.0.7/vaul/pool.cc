/* 
   Copyright (C) 1998 University of Dortmund
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

#include <freehdl/vaul-pool.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-util.h>

#if HAVE_MALLOC_H
#include <malloc.h>
#endif

vaul_pool::vaul_pool ()
{
  contents = NULL;
}

vaul_pool::~vaul_pool ()
{
  clear ();
  while (cur_ses)
    end_session ();
}

vaul_design_unit *
vaul_pool::get (char *library, char *name)
{
  for (entry *e = contents; e; e = e->link)
    if (vaul_name_eq (e->du->get_library (), library)
	&& vaul_name_eq (e->du->get_name (), name))
      {
	retain_ref (e->du);
	return e->du;
      }

  return NULL;
}

vaul_design_unit *
vaul_pool::get_package_body (char *library, char *package_name)
{
  char *name = package_body_name (package_name);
  vaul_design_unit *du = get (library, name);
  free (name);
  return du;
}

vaul_design_unit *
vaul_pool::get_architecture (char *library, char *entity_name,
			     char *arch_name)
{
  char *name = architecture_name (entity_name, arch_name);
  vaul_design_unit *du = get (library, name);
  free (name);
  return du;
}

char *
vaul_pool::package_body_name (char *package_name)
{
  return vaul_aprintf ("%s(body)", package_name);
}

char *
vaul_pool::architecture_name (char *entity_name, char *arch_name)
{
  return vaul_aprintf ("%s(%s)", entity_name, arch_name);
}

void
vaul_pool::insert (vaul_design_unit *du)
{
  entry *e = new entry;
  e->du = du;
  retain_ref (e->du);
  e->link = contents;
  contents = e;
}

void
vaul_pool::clear ()
{
  // We will be going thru a frenzy of garbage collections as we
  // release the design units.  By blocking the collector around the
  // loop, we reduce this to just one collection at the end.

  tree_block_garbage_collection ();
  entry *e, *e2;
  for (e = contents; e; e = e2)
    {
      e2 = e->link;
      release_ref (e->du);
      delete e;
    }
  tree_unblock_garbage_collection ();
}

void
vaul_pool::flush ()
{
  tree_block_garbage_collection ();
  for (entry **ep = &contents; *ep;)
    {
      entry *e = *ep;
      if (e->du->get_ref_count () == 1)
	{
	  *ep = e->link;
	  release_ref (e->du);
	  delete e;
	}
      else
	ep = &(*ep)->link;
    }
  tree_unblock_garbage_collection ();
}

void
vaul_pool::begin_session (char *wl)
{
  session *s = new session;
  s->work_library = vaul_xstrdup (wl);
  s->prev = cur_ses;
  cur_ses = s;
}

char *
vaul_pool::get_work_library ()
{
  return cur_ses? cur_ses->work_library : NULL;
}

void
vaul_pool::end_session ()
{
  session *s = cur_ses;
  if (s)
    {
      cur_ses = s->prev;
      free (s->work_library);
      delete s;
    }
}
