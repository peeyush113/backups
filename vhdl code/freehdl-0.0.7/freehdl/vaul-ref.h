/* reference counting

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

#ifndef FREEHDL_VAUL_REF_H
#define FREEHDL_VAUL_REF_H

typedef void vaul_weak_notify (void *data);

struct vaul_ref {

  vaul_ref();
  virtual ~vaul_ref();

  void retain();
  void release();

  void retain_weak (vaul_weak_notify *notify, void *data);
  void release_weak (vaul_weak_notify *notify, void *data);

  unsigned long get_ref_count ()  { return ref_count; }

private:
  unsigned int ref_count;
  struct weak {
    weak *link;
    vaul_weak_notify *notify;
    void *data;
  };
  weak *weaks;
};

inline void retain_ref (vaul_ref *r)       { if (r) r->retain(); }
inline void release_ref (vaul_ref *r)      { if (r) r->release(); }

#endif
