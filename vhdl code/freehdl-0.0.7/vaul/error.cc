/* error handling

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

#include <freehdl/vaul-errors.h>
#include <freehdl/vaul-util.h>

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

vaul_error_source::vaul_error_source()
{
    error_code = 0;
    error_desc = NULL;
}

vaul_error_source::~vaul_error_source()
{
    set_error_desc(NULL);
}

void vaul_error_source::set_error()
{
    set_error("");
}

void vaul_error_source::set_error(const char *fmt, ...)
{
    if(errno) {
	error_code = errno;
	va_list ap;
	va_start(ap, fmt);
	set_error_desc (vaul_vaprintf (fmt, ap));
	more_error_desc(strerror(error_code));
	va_end(ap);
    } else
	clear_error();
}

void vaul_error_source::set_error(int code, const char *fmt, ...)
{
    if(code) {
	error_code = code;
	va_list ap;
	va_start(ap, fmt);
	set_error_desc (vaul_vaprintf (fmt, ap));
	va_end(ap);
    } else
	clear_error();
}

void vaul_error_source::set_error(vaul_error_source *es, const char *fmt, ...)
{
    if(es->error_code) {
	error_code = es->error_code;
	va_list ap;
	va_start(ap, fmt);
	set_error_desc (vaul_vaprintf (fmt, ap));
	more_error_desc(es->error_desc);
	va_end(ap);
    } else
	clear_error();
}

void vaul_error_source::set_error(vaul_error_source &es, const char *fmt, ...)
{
    if(es.error_code) {
	error_code = es.error_code;
	va_list ap;
	va_start(ap, fmt);
	set_error_desc (vaul_vaprintf (fmt, ap));
	more_error_desc(es.error_desc);
	va_end(ap);
    } else
	clear_error();
}

void vaul_error_source::clear_error()
{
    error_code = 0;
    set_error_desc(NULL);
}

void vaul_error_source::print_err(FILE *f, const char *msg)
{
    fprintf(f, "%s: ", vaul_application_name);
    if(msg)
	fprintf(f, "%s: ", msg);
    if(error_desc)
	fprintf(f, "%s\n", error_desc);
    else
	fprintf(f, "BOGUS ERROR REPORT\n");
}

void vaul_error_source::print_err(const char *msg)
{
    print_err(stderr, msg);
}

void vaul_error_source::set_error_desc(const char *s)
{
    free((char*)error_desc);
    error_desc = s;
}

void vaul_error_source::more_error_desc(const char *s)
{
    if(error_desc == NULL)
	set_error_desc(s);
    else
	set_error_desc (vaul_aprintf ("%s%s", error_desc, s));
}
