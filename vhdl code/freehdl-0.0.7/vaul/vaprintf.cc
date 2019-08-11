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

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <freehdl/vaul-util.h>

char *
vaul_vaprintf (const char *fmt, va_list ap)
{
#ifdef HAVE_VASPRINTF
  char *str;
  vasprintf (&str, fmt, ap);
  if (str == NULL)
    vaul_fatal ("virtual memory exhausted\n");
  return str;
#elif defined (_WIN32)
  int n, len = 1024;
  char *buf, *str;
  do {
    str = (char *)malloc (len);
    if (str == NULL)
      vaul_fatal ("virtual memory exhausted\n");
    n = vsnprintf (str, len, fmt, ap);
    if (n < 0 || n >= len) {
      len *= 2;
      free (str);
      continue;
    }
  }
  while (n < 0 || n >= len);
  free (str);
  buf = (char *)vaul_xmalloc (n + 1);
  vsprintf (buf, fmt, ap);
  return buf;
#else
  int n;
  char *buf;
  FILE *f = fopen ("/dev/null", "w");
  if (f == NULL)
    vaul_fatal ("/dev/null: %s\n", strerror (errno));
  n = vfprintf (f, fmt, ap);
  fclose (f);
  if (n < 0)
    vaul_fatal ("/dev/null: %s\n", strerror (errno));
  buf = (char *)vaul_xmalloc (n + 1);
  vsprintf (buf, fmt, ap);
  return buf;
#endif
}
