/* list hacks

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

#ifndef FREEHDL_VAUL_LIST_H
#define FREEHDL_VAUL_LIST_H

void *generic_reverse(void *l, size_t next_offset);
void *generic_concat(void *l1, void *l2, size_t next_offset);

template<class node>
inline node *reverse2(node *l)
{
    node *next_constrain = l? l->next : NULL;
    return (node *)generic_reverse(l, offsetof(node, next));
}

template<class node>
inline node *concat(node *l1, node *l2)
{
    node *rest_constrain = l1? l1->rest : NULL;
    return (node *)generic_concat(l1, l2, offsetof(node, rest));
}

#endif
