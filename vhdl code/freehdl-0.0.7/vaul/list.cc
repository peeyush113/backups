/* some list hacks

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

#include <stddef.h>

#include <freehdl/vaul-list.h>

#define memberat(type, ptr, off) (*((type *)(((char *)(ptr))+(off))))

void *generic_reverse(void *l, size_t noff)
{
    void *rl = NULL, *n;
    while(l) {
	n = memberat(void *, l, noff);
	memberat(void *, l, noff) = rl;
	rl = l;
	l = n;
    }
    return rl;
}

void *generic_concat(void *l1, void *l2, size_t noff)
{
    if(l2 == NULL)
	return l1;

    void **l;
    for(l = &l1; *l; l = &memberat(void *, *l, noff))
	;
    *l = l2;
    return l1;
}
