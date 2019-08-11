
#ifndef SPARSE_H
#define SPARSE_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/

#include <string.h> // for memset

#define GetTopIndex(i) ((i)>>power)
#define GetLeafIndex(i) ((i)&leafMask)

/**
   Template class for a sparse array of fixed size (e.g., it does not
   grow).
  
   This class is used as follows:
<pre>
      sparse_array<my_type> a( 1024 );
</pre>
   This will create a sparse array object that can hold up to 1M items
   (1024 * 1024).  This object is modeled after the hashed array tree
   object (see hat.h).  Unlike the HAT, once it is allocated, the sparse
   array object size is fixed.
*/
template <class T>
class sparse_array {
private:

    unsigned int power;
    unsigned int dimension_size;
    unsigned int leafMask;
    unsigned int bytes_alloced;
    T **top;

public:
    void init( const unsigned int size )
    {
	if (size > 0) {
	    // round size up to the nearest power of two
	    power = get_power_of_two( size );
	    dimension_size = two_to_n( power );
	    leafMask = dimension_size - 1;  // (2^n) - 1

	    top = new T* [ dimension_size ];
	    bytes_alloced = sizeof( T *) * dimension_size;
	    memset( (char *)top, 0, bytes_alloced );  // make sure that top is NULL
	}
	else {
	    power = 0;
	    dimension_size = 0;
	    leafMask = 0;
	    bytes_alloced = 0;
	    top = NULL;
	}
    }  // init
    // constructor
    sparse_array( const unsigned int size )
    {
	init( size );
    } // sparse_array constructor

    // copy constructor
    sparse_array( const sparse_array<T> &a )
    {
	init(0);
	(*this) = a;
    }  // sparse_array

  /**
      An explicit destructor cannot be used, since the constructor is used
      to allocate memory.  For example, in the sparse_array template is
      used as the base of the hash table.  The hash_array object is
      dynamically allocated and then initialized with a size:
<pre>
         *hash = sparse_array<sym_list>( hash_size );
</pre>
      This call invokes the constructor and the destructor, after the
      assignment is complete.  If the destructor de-allocates the
      sparse array, future references to the hash table will fail
      since they reference deallocated memory.
     */
    void dealloc(void)
    {
	unsigned int i;

	for (i = 0; i < dimension_size; i++) {
	    if (top[i] != NULL) {
		delete [] top[ i ];  // delete the array pointed to by top[ i ]
		top[ i ] = NULL;
	    }
	}
	if (top != NULL) {
	    delete [] top;
	    init(0);
	}
    } // dealloc


    unsigned int two_to_n( unsigned int n ) { return 1 << (n & 0x1f); }

  /**
      get_power_of_two
     
      Return the smallest power of two that is greater than or 
      equal to val.
  */
    unsigned int get_power_of_two( const unsigned int val )
    {
	const uint powerMin = 1; // set a resonable minimum
	uint p;

	for( p = powerMin; val > (uint)(1 << p); p++ )
	    /* nada */
	    ;
	return p;
    } // get_power_of_two


    void add_leaf( const unsigned int top_ix )
    {
	assert( top[ top_ix ] == NULL );

	top[ top_ix ] = new T [ dimension_size ];
	memset( top[top_ix], 0, sizeof( T ) * dimension_size );
	bytes_alloced += sizeof( T ) * dimension_size;
    } // add_leaf

    void insert( const T &val, const unsigned int ix) 
    {
	unsigned int top_ix = GetTopIndex(ix);
	unsigned int leaf_ix = GetLeafIndex(ix);
    
	assert( top_ix < dimension_size );
	if (top[top_ix] == NULL) {
	    add_leaf( top_ix );
	}

	top[top_ix][ leaf_ix ] = val;
    } // insert


  /** 
      both l-value and r-value forms of this operator
      operate by reference to avoid a copy constructor
      invokation.
  */
    T &operator[]( const unsigned int i )
    {
	unsigned int top_ix = GetTopIndex(i);
	unsigned int leaf_ix = GetLeafIndex(i);

	assert( top_ix < dimension_size );
	assert( top[ top_ix ] != NULL );
	return top[ top_ix ][ leaf_ix ];
    }


  /** 
      probe is used by aliens on Nebraska farmers... No,
      actually probe returns TRUE if an element has been
      allocated in the table slot with index ix.
  */
    int probe( const unsigned int ix )
    {
	int rslt = TRUE;
	unsigned int top_ix = GetTopIndex(ix);
	
	assert( top_ix < dimension_size );
 	if (top[top_ix] == NULL) {
	    rslt = FALSE;
	}
	return rslt;
    }

  /** This is the maximum number of elements that could be inserted into
       the array.  This will always be a power of two.
  */
    unsigned int get_total_size() { return dimension_size * dimension_size; }

    // ----- debug functions -----
    unsigned int get_bytes_alloced(void) { return bytes_alloced; };
    unsigned int get_percent_alloced(void);
};  // class sparse_array




// ----------------- debug functions

template <class T>
unsigned int sparse_array<T>::get_percent_alloced(void)
{
    uint i;
    int top_used, trunc;
    float percent, tsize, used;

    trunc = 0;
    if (top != NULL) {
	top_used = 0;
	for (i = 0; i < dimension_size; i++) {
	    if (top[ i ] != NULL)
		top_used++;
	}
	tsize = (float)dimension_size;
	used = (float)top_used;
	percent = (used / tsize) * (float)100;
	trunc = (int)percent;
    }

    return trunc;
}


#undef GetTopIndex
#undef GetLeafIndex

#endif
