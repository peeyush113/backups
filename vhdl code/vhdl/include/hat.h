
#ifndef HAT_H
#define HAT_H

#include "sysinc.h"

/** These macros ensure the these calculations get
   inlined even for stupid compilers.
*/
#define GetTopIndex(i) ((i)>>power)
#define GetLeafIndex(i) ((i)&leafMask)

/** Minimum hat array will hold 32 *32 = 1024 elements.  Note
   that the 32 element leaves will be allocated on demand. */
typedef enum { min_hat_size = 32 };

#ifndef NULL
#define NULL 0
#endif

/**
   This class implements a dynamicly growable array.  Arrays of this
   type are particularly useful in code generators, where algorithms
   like register range analysis and peephole optimization work best on
   arrays of instructions.

   This class is implemented by a Hashed Array Tree (see <i>HATs: Hashed
   Array Trees - very fast variable length arrays</i> by Edward Sitarski,
   published in the "Algorithm Alley" section of Dr. Dobb's Journal,
   September 1996).  The code here is derived from the public domain
   code published along with this article (e.g., ftp from the Dr. Dobbs
   ftp site).

   This is a template class.  Some C++ compilers (e.g., Sun) will only
   compile template classes with in-line class functions.

   This code is fairly tricky.  Memory is only allocated when it is needed
   and the addLeaf and resize functions end up being recursive co-routines.
   I like to think that my code is more transparent than this, since trickiness
   makes code difficult to understand and maintain.  However, I've combed 
   through this code and run some tests on it and as far as I can tell,
   it works correctly.
<h4>
  Notes
</h4>
<ul>
<li>
<p>
    Hashed Array Trees (hat)
</p>
<p>
      A slightly altered quote from the <i>Hats: Hashed Array Trees</i> article
      is included below:
</p>
<p>
<i>
        Although used to implement one dimensional arrays, HATs are
        really two dimensional.  A HAT consists of a "Top" array and a
        number of "Leaves" which are pointed to by the Top array.  The
        number of pointers in the Top array and the number of elements
        in each Leaf is the same, and is always a power of 2.
</i>
</p>
<p>
<i>
        Because the Top and Leaf arrays are powers of 2, you can
	efficiently find an element in a HAT using bit operations.
	Usually appending elements is very fast since the last leaf
	may have empty space.  Less frequently, a new leaf must be
	added, which is also very fast and requires no copying.
</i>
</p>
<p>
<i>
        When the Top array is full, the size of new Top and Leaf
	arrays are calculated (e.g., a Top, that is twice as big,
	is allocated and enough leaf arrays are allocated to hold
	the current data set).  A new Top is allocated.  The existing
	data is "appended" to the new hat, allocating new leaves and
	deallocating old leaves as the copying is done.
</i>
</p>
<i>
        Recopying only occurs when the Top array is full and this
	happens when the number of elements exceeds the square of a
	power of two
</i>
</p>
</li>
<li>
<p>
    size_t
</p>
<p>
      You've got to love C++, it's huge and they constantly add to it.  There
      are endless corners of the language that few people know about which
      allow people like Al Stevens (a Dr. Dobb's columnist) to count coup on
      the rest of us.  One of these obscure features is size_t.  From
      section 5.3.2 of The Annotated C++ Reference Manual:
</p>
<p>
         ... size_t, an impementation-dependent unsigned integral type
         defined in the standard header <stddef.h>.
</p>
      On most systems this is the local version of "unsigned int".
</li>
<li>
<p>
    Code bloat
</p>
<p>
      The Sun compiler has a habbit of in-lining constructors.  As
      a result, a lot of code, especially in templates, ends up
      in line, exploding the size of the program.
</p>
</li>
</ul>

 */

template <class T>
class Hat
{
private:
    size_t leafSize() const { return 1<<power; /* return 2^power */ }
    size_t topSize() const { return 1<<power; /* return 2^power */ }
    size_t topIndex( const unsigned i ) const { return GetTopIndex(i); }
    size_t leafIndex( const unsigned i ) const { return GetLeafIndex(i); }

    /**
     Allocate a new HAT and copy the data from "this" HAT
     into the new HAT.
     */
    void resize( const size_t newExpectedSize )
    {
	size_t	i, leaf_ix;

	Hat<T>	hatNew( newExpectedSize );

	/* if the new HAT is the same size (e.g., power) as "this"
	   HAT, return */
	if( hatNew.power == power )
	    return;

	/* copy the data from "this" hat into the new array */
	for( i = 0, leaf_ix = 0; i < numElements; i++ )
	    {
		hatNew.add_to_end( (*this)[i], 0 );	// append, but do not resize again

		leaf_ix++;
		// delete the leaves as we go - this decreases memory overhead.
		if( leaf_ix == leafSize() )
		    {
			delete [] top[topIndex(i)];
			leaf_ix = 0;
		    }
	    }

	// delete any unused leaves.
	for( i = topIndex(numElements); i < topUsed; i++ )
	    delete [] top[i];

	// assign the new array to the old.
	delete top;
	top = hatNew.top;
	setPower( hatNew.power );
	topUsed = hatNew.topUsed;
	numAvail = hatNew.numAvail;

	// clean up so nothing gets corrupted.
	hatNew.numElements = 0;
	hatNew.topUsed = 0;
	hatNew.top = NULL;
    }  // resize


    /**
     Add a new Leaf to the HAT pointer array and insert the
     new data element (aValue) into it.

     */
    void addLeaf( const T &aValue, const int doResize )
    {
	/* If the top array is either empty (topUsed == 0) or is full
	   topUsed == topSize (no new leaves can be added), reallocate the
	   array.  */
	if( topUsed % topSize() == 0 )
	    {
		int	growTop = TRUE;

		if( doResize )
		    {
			resize( numElements );

			// Check if after the resize we have room.
			if( topIndex(numElements) < topUsed )
			    {
				(*this)[numElements++] = aValue;
				return;
			    }

			// Check if we have room for a new leaf.
			if( topUsed % topSize() != 0 )
			    growTop = FALSE;
		    }
		if( growTop )
		    {
			// Increase the top array by topSize.
			T	**topNew = new T * [ topUsed + topSize() ];
			for( size_t i = 0; i < topUsed; i++ )
			    topNew[i] = top[i];
			delete [] top;
			top = topNew;
		    }
	    }
	/* add a new leaf */
	top[topUsed] = new T [leafSize()];
	top[topUsed][0] = aValue;
	numAvail += leafSize();
	topUsed++;
	numElements++;
    } /* addLeaf */


    size_t recommendedPower( const size_t s ) const
    {

	const size_t powerMin = 1; // set a resonable minimum
	size_t p;
	for( p = powerMin; s > (1<<(p<<1)); p++ )
	    ;
	return p;
    } // recommendedPower

    void setPower( const size_t p )
    {
	power = p;
	leafMask = leafSize()-1;
    }


    void add_to_end( const T &aValue, const int doResize = 1 )
    {
	if (numElements == numAvail) {
	    addLeaf( aValue, doResize );
	}
	else {
	    (*this)[numElements] = aValue;
	    numElements++;
	}
    }


    /** top points to leaves */
    T	**top;
    /** amount of top actually used (number of leaves) */
    size_t	topUsed;     
    /** power of 2 used for leaves and top */
    size_t	power;	     
    /** used to compute the leaf index */
    size_t	leafMask;    
    /** Number of elements used in the array.  numElements
        always points to the next free element in the array */
    size_t	numElements; 
    /** number of elements currently allocated in the array */
    size_t      numAvail;    

public:
    void init( const size_t aExpectedSize = min_hat_size )
    {
	size_t p;

	/* get the smallest power of two greater than aExpectedSize */
	p = recommendedPower(aExpectedSize);
	setPower( p );
	numElements = 0;
	numAvail = 0;

	top = NULL;
	topUsed = 0;
    } // init

  /**
     * Hat default constructor (e.g., default since the class definition
     * assigns a default value of zero to aExpectedSize).
     */
    Hat( const size_t aExpectedSize = min_hat_size )
    {
	init( aExpectedSize );
    }


    Hat( const Hat<T> &hat )
    {
	init( 0 );
	(*this) = hat;
    }

    ~Hat()
    {
	if (top != NULL) {
	    for( size_t i = 0; i < topUsed; i++ ) {
		if (top[i] != NULL) {
		    delete [] top[i];
		    top[i] = NULL;
		}
	    }
	    delete [] top;
	    top = NULL;
	}
    }
    

  /**
       Insert an element "a" into the array at index
       "i".
      
       An empty array is an array with no data elements in it.
       This is not necessarily the same as the number of storage
       elements currently available in the array.
      
       A data element can be inserted into an empty array at 
       index 0 (e.g., appended to an empty array).  A data
       element can be inserted at the end of the array (that
       is array.insert( a, array.length())).  A data element
       cannot be inserted beyond array.length() and an attempt
       to do so will result in an assert error.
      
       Except for insertion at element 0 of an empty array and
       insertion at the end of the array, insert can be an 
       expensive operation.  All elements from i+1 to the
       end of the array are moved up one array location.
  */
    void insert( const T &a, const size_t i )
    {
	assert( i <= numElements );

	if (numElements == 0 || i == numElements) {
	    append( a );
	}
	else {
	    assert( length() > 0 );

	    size_t last_ix = length() - 1;

	    // Move all data elements from i+1 up by one index
	    append( (*this)[last_ix] );  // append the last element to the end of the array
	    assert( length() == last_ix + 2 );

	    int ix;

	    for (ix = last_ix; ix > i; ix--) {
		(*this)[ix] = (*this)[ix-1];
	    }
	    (*this)[i] = a;
	}
    } // insert


  /** 
       Remove (delete is a reserved word) the element at index "i".
       Like insert, this can be an expensive operation.  Unless the
       element is at the very end of the array, elements from i+1 to
       numElements are moved "down" one element.

       It is an error to attempt to remove an element beyond the end
       of the array.  It is also an error to remove an element from an
       empty array.  
     */
    void remove( const size_t i )
    {
	assert( length() > 0 );
	assert( i < length() );

	if (i < length() - 1) {
	    int ix;

	    for (ix = i; ix < length()-1; ix++) {
		(*this)[ix] = (*this)[ix+1];
	    }
	}

	numElements--;
    }  // remove


  /** remove_n: like remove, but this function removes
      more than one item. */
    void remove_n( const size_t i, const size_t n)
    {
	assert( length() > 0 );
	assert( i + n <= length() );

	if (i + n < length()) {
	    int ix;

	    for (ix = i; ix < length()-n; ix++) {
		(*this)[ix] = (*this)[ix+n];
	    }
	}

	numElements -= n;;	
    }


    T &operator[](const size_t i)
    {
	assert( i < numAvail );
	return top[GetTopIndex(i)][GetLeafIndex(i)];
    }

    T operator[](const size_t i) const
    {
	assert( i < numAvail );
	return top[GetTopIndex(i)][GetLeafIndex(i)];
    }

  /** the at function as an l-value */
    T &at(const size_t i) 
    { 
	return (*this)[i]; 
    }

  /** return the address of a data element */
    T at(const size_t i) const 
    { 
	return (*this)[i]; 
    }

  /** return the first data element in the array */
    T first() const { 
	return (*this)[0]; 
    }

  /** Return the last data element in the array */
    T last() const { 
	return (*this)[numElements-1]; 
    }

  /** Add an element to the end of the array */
    void append( const T& a ) { 
	add_to_end(a); 
    }

  /** return TRUE if there are no data elements
      in the array. */
    int isEmpty() const { 
	return numElements == 0; 
    }

  /** When the number of elements is set to zero,
       the array is empty of data, but contains storage.
       This is the difference between numElements (the
       number of data items) and numAvail, the number of
       storage elements available.
  */
    void set_to_empty() {
	numElements = 0;
    }

  /** Return the number of data elements in the array.
       As noted above, this is different from the number
       of storage elements.
  */
    size_t length() const { 
	return numElements; 
    }

    void decrement_length( const unsigned int val ) {
	if (val <= numElements)
	    numElements = numElements - val;
	else
	    numElements = 0;
    } // decrement_length
};

#undef GetTopIndex
#undef GetLeafIndex

#endif
