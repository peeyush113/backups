/* some utility functions

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

#ifndef FREEHDL_VAUL_UTIL_H
#define FREEHDL_VAUL_UTIL_H

#include <stddef.h>
#include <stdarg.h>

/* Same as sprintf, but stores result in freshly allocated storage;
   you must free this storage with free().  These functions never
   return NULL.  */

char  *vaul_aprintf(const char *fmt, ...);
char *vaul_vaprintf(const char *fmt, va_list ap);

/* Same as malloc(size), but never fails.  */

void *vaul_xmalloc(size_t size);

/* Same as realloc(old_mem, new_size), but never fails.  */

void *vaul_xrealloc(void *old_mem, size_t new_size);

/* Like strdup(str) but never fails and returns NULL for
   vaul_xstrdup(NULL).  */

char *vaul_xstrdup(const char *str);

/* The name of the main application, to be used in error messages from
   libvaul.  */

extern const char *vaul_application_name;

/* Printf a message to stderr with the application name prepended, and
   exit with code 1.  */

void  vaul_fatal (const char *fmt, ...);
void vaul_vfatal (const char *fmt, va_list ap);

#endif
