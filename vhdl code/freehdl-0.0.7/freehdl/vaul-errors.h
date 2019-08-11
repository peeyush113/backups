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

#ifndef FREEHDL_VAUL_ERRORS_H
#define FREEHDL_VAUL_ERRORS_H

#include <stdio.h>
#include <errno.h>

//	Fehlermeldungen bestehen aus einem Code, der den Fehler grob einordnet,
//	und einem String als genauere Fehlerbeschreibung.
//	
enum {
	vhdlerr_first_error = -5000,

	// Allgemeine Fehler
	vhdlerr_not_implemented,
		// Übergangsweise gibt's die gewünschte Funktionalität leider
		// nicht; komm' später noch mal wieder.
	vhdlerr_usage,
		// Funktion im falschen Kontext aufgerufen, Dein Fehler

	// Datei Fehler
	vhdlerr_timeout,
		// Die Datei ist durch andere Programme blockiert
	vhdlerr_eof,
		// Dateiende erreicht, obwohl noch was kommen sollte

	// Parser Fehler
	vhdlerr_errors_detected,
		// Die gelesene VHDL Datei war nicht ganz fehlerfrei
	
	// Library Fehler
	vhdlerr_lib_corrupt,
		// Die Library ist nicht in Ordnung
	vhdlerr_out_of_date,
		// Ein Verweis zeigt auf etwas, das sich inzwischen geändert hat
	vhdlerr_frozen
		// Library ist gefroren

	// und alle 'errnos', also ENOENT, EPERM, ...
};

//	vaul_error_source dient zum Speichern von Fehlermeldungen
//	und wird als Basis für alle Klassen verwendet die
//	Fehler erzeugen.
//
struct vaul_error_source {

	vaul_error_source();
	virtual ~vaul_error_source();

	bool is_error()				{ return get_error() != 0; }
	int get_error()				{ return error_code; }
	const char *get_error_desc()		{ return error_desc; }

	void print_err(FILE *f = stderr, const char *msg = NULL);
	void print_err(const char *msg);
		// gibt die Fehlermeldung zusammen mit dem Programmnamen
		// auf f (oder stderr) aus.

	void clear_error();
		// error_code = 0; error_desc = "";

	// Funktionen, um Fehlermeldungen zu speichern.
	//	(fmt... bedeutet einen String, wie ihn printf(fmt, ...) ausgeben
	//	würde)
	//
	void set_error();
		// error_code = errno, error_desc = strerror(errno);
	void set_error(const char *fmt, ...);
		// error_code = errno, error_desc = fmt... strerror(errno);
	void set_error(int code, const char *fmt, ...);
		// error_code = code; error_desc = fmt...;
	void set_error(vaul_error_source *, const char *fmt = "", ...);
	void set_error(vaul_error_source &, const char *fmt = "", ...);
		// übernimmt komplette Fehlermeldung und setzt fmt... vor
		// die alte Fehlerbeschreibung.

private:
	int error_code;
	const char *error_desc;

	void set_error_desc(const char *);
	void more_error_desc(const char *);
};

#endif

