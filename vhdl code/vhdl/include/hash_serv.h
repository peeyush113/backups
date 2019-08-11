
#ifndef HASH_SERV_H
#define HASH_SERV_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/**
  This class provides low level support functions (e.g., hash value
  calculation) for the hash table element classes.  The hash table
  is defined by a template and the element classes are the classes
  that are used in instantiating the hash table.  These classes
  must all provide certain class functions, which in turn make
  use of functions provided by this class.

 */
class hash_services {
public:
    hash_services() {};
    ~hash_services() {};
    unsigned int str_to_uint( const char *s );
    unsigned int hash_value( const char *name );
}; 

#endif
