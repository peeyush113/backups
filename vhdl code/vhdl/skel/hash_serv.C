
/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/

#define NDEBUG 1

#include "sysinc.h"
#include "hash_serv.h"


#define SIZE_INT 4

/**
   This function is passed a string.  It returns a hash key
   formed from the string.  An attempt is made to make this
   key as unique as possible.
*/
unsigned int hash_services::str_to_uint( const char *s )
{
    int i, byte_ix, word_cnt;
    char c;
    union {
	unsigned char c[ SIZE_INT ];
	unsigned int  u;
    } val;

    val.u = 0;
    word_cnt = 0;
    for (i = 0, byte_ix = 0; i < strlen( s ); i++, byte_ix = (byte_ix + 1) % SIZE_INT) {
	if (i > 0 && (i % SIZE_INT) == 0) {
	    word_cnt++;
 	}
	c = s[ i ];
	// Every odd word, shift the character up by one bit
        // It turns out that this makes a big difference in the
        // uniqueness of the key generated from a string
	if (word_cnt & 0x1) {
	    c = c << 1;
	}
	val.c[ byte_ix ] ^= c;
    }

  return val.u;
} // str_to_uint

#undef SIZE_INT


/**
   Use a shift algorithm to distribute the key (e.g., make it more
   pseudo-random).  I actually tried several different algorithms to
   do this and this one worked the best.  It was suggested by
   Brent Gregory at Synopsys, although any mistakes in translating his 
   suggestion to code are mine.  The code below is a loop, which has
   been in-lined for speed.
*/
unsigned int hash_services::hash_value( const char *name )
{
  unsigned int val, new_val;
  
  val = str_to_uint( name );

  new_val = val ^ (val << 1);
  new_val = new_val ^ (val << 2);
  new_val = new_val ^ (val << 3);
  new_val = new_val ^ (val << 4);
  new_val = new_val ^ (val << 5);
  new_val = new_val ^ (val << 6);
  new_val = new_val ^ (val << 7);
  new_val = new_val ^ (val << 8);
  new_val = new_val ^ (val << 9);
  new_val = new_val ^ (val << 10);
  new_val = new_val ^ (val << 11);
  new_val = new_val ^ (val << 12);
  new_val = new_val ^ (val << 13);
  new_val = new_val ^ (val << 14);
  new_val = new_val ^ (val << 15);
  new_val = new_val ^ (val << 16);

  return new_val;  // adjust for hash table size
} // hash_value

