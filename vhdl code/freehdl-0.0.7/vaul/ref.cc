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

#include <freehdl/vaul-ref.h>
#include <freehdl/vaul-util.h>

vaul_ref::vaul_ref ()
{
  ref_count = 1;
  weaks = NULL;
}

vaul_ref::~vaul_ref ()
{
  if (ref_count > 0)
    vaul_fatal ("referenced object destroyed.\n");

  weak *w, *w2;
  for (w = weaks; w; w = w2)
    {
      w2 = w->link;
      w->notify (w->data);
      delete w;
    }
}

void
vaul_ref::retain ()
{
  ref_count++;
}

void
vaul_ref::release ()
{
  if (--ref_count == 0)
    delete this;
}

void
vaul_ref::retain_weak (vaul_weak_notify *notify, void *data)
{
  weak *w = new weak;
  w->notify = notify;
  w->data = data;
  w->link = weaks;
  weaks = w;
}

void
vaul_ref::release_weak (vaul_weak_notify *notify, void *data)
{
  for (weak **wp = &weaks; *wp; wp = &(*wp)->link)
    {
      weak *w = *wp;
      if (w->notify == notify && w->data == data)
	{
	  *wp = w->link;
	  delete w;
	  break;
	}
    }
}
