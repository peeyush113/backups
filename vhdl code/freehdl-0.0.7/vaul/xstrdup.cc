/* Copyright (C) 1994-1997 University of Dortmund
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

#include <string.h>
#include <freehdl/vaul-util.h>

char *
vaul_xstrdup (const char *str)
{
  if (str == NULL)
    return NULL;
  else 
    {
      char *nstr = (char *) vaul_xmalloc (strlen(str) + 1);
      strcpy (nstr, str);
      return nstr;
    }
}
