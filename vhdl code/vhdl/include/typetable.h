
#ifndef TYPETABLE_H
#define TYPETABLE_H

/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/**
   Named types are represented by the sym_type class.  A sym_type
   object has a pointer to a type, which is an unnamed object
   described by the classes in type.h.  The type table class provides
   a way to encapsulate these allocated types.

   Two allocation scopes are used for types: the global allocation
   scope, where types defined in packages will be entered and the
   component allocation scope.  Types in the global scope will be
   allocated from the global pool.  Types in the component scope will
   be allocated from the component pool.

   The types in the type table are ordered as lists of a given type
   class (e.g., type_range, type_real, type_array, type_record,
   type_file).  Types in the type table are not currently unique.
   There are two reasons for this: its a pain to make show that
   two types are the same in all cases and I can't think of a 
   reason to do this extra work.

 */
class typetable {
private:
    static LIST<type_time *>   time_list;
    LIST<type_range *>  range_list;
    LIST<type_real *>   real_list;
    LIST<type_array *>  array_list;
    LIST<type_record *> rec_list;
    LIST<type_file *>   file_list;

    pool *alloc_pool;   // pointer to the memory allocation pool

private:
    // no copy constructor allowed
    typetable( const typetable &ty ) { assert( FALSE ); }

    type *find_time( const uint time_scale );

public:
    typetable(pool *p = NULL)
    {
	alloc_pool = p;
    }

    void set_pool( pool *p )
    {
	alloc_pool = p;
    }

    type *new_type( uint kind, uint time_scale = time_bad_time );

    // debug print
    void pr();
};

extern typetable glob_typtab;
extern type_real REAL;

#endif
