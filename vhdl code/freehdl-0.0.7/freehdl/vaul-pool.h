/* a pool of design units

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

#ifndef FREEHDL_VAUL_POOL_H
#define FREEHDL_VAUL_POOL_H

#include <freehdl/vaul-errors.h>
#include <freehdl/vaul-dunit.h>

struct vaul_pool {

  vaul_pool ();
  virtual ~vaul_pool ();

  virtual vaul_design_unit *get (char *library, char *name);

  vaul_design_unit *get_package_body (char *library, char *package_name);
  vaul_design_unit *get_architecture (char *library,
				      char *entity_name, char *arch_name);

  virtual char *package_body_name (char *package_name);
  virtual char *architecture_name (char *entity_name, char *arch_name);

  virtual void insert (vaul_design_unit *du);
  virtual void clear ();
  virtual void flush ();

  void begin_session (char *work_library);
  char *get_work_library ();
  void end_session ();

private:
  struct entry {
    entry *link;
    vaul_design_unit *du;
  };
  entry *contents;
  struct session {
    session *prev;
    char *work_library;
  };
  session *cur_ses;
};

#endif
