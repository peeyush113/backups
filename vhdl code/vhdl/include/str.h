
#ifndef _QT_STR_H_
#define _QT_STR_H_


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/

#include <stdio.h> //     -- for FILE and fprintf
#include "stdtypes.h"


/**
   The STRING class packages a character string which has
   been allocated in a hash table.  All strings in this 
   table are unique.  As a result, string comparison can
   be done my comparing the string pointers.

   The usage of this class assumes that the string has been
   entered in the string table.  If the text field is initialized
   with a string, make sure that the string is entered in the
   string table (find_string can be called with a STRING 
   argument, in which case it will make a copy of the string
   pointed to by text).

   This class is used by the string table hash table in
   strtable.h
 */
class STRING {
private:
    char *text;

public:
    STRING(void)               { text = NULL; }
    STRING( const STRING &str ) // copy constructor
    {
	(*this) = str;
    } // copy constructor
    ~STRING() { /* do nothing */ }

    const char *GetText(void)  { return text; }

    void SetText( const char *t )    { text = (char *)t; }

    void pr( FILE *fp = stdout )
    {
	fprintf(fp, "%s", GetText() );
    }
}; // STRING


extern STRING NULLSTR;

#endif
