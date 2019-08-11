
#ifndef FIFO_LIST_H
#define FIFO_LIST_H

#ifndef NULL
#define NULL 0
#endif

/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/** 
   This is a generic list type for a list that has both a head and a
   tail pointer (note the the LIST template only has a head pointer).
   In this list, items are added to the tail.  When read from the
   front of the list, items will be read in a first-in, first-out
   order.  In contrast, the LIST template class adds items to the head
   and reads from the head (last in, first out).  It should be
   instantiated with a scalar type, like an integer or a pointer to a
   larger type (e.g., a string or a structure).  For example
<pre>
      FIFO_LIST<char *> list;
      FIFO_LIST<my_struct *> list;
</pre>

   This class does not have anything but the default destructor.  In
   order to allow a function to allocate a list and then return the
   list as its result, the list is not deallocated by the destructor.
   The list can be deallocated by calling the "dealloc" class
   function.  

*/
template <class T>
class FIFO_LIST
{
public:
    typedef struct LIST_TYPE {
        T data;
        struct LIST_TYPE *next;
    } list_type;  // struct list_type

private:
  list_type *list;
  list_type *tail;

public:
  typedef list_type *handle;

public:
  FIFO_LIST(void) 
  { 
    list = NULL;
    tail = NULL;
  }

  /** deallocate the list */
  void dealloc(void)
  {
    while ( remove() != NULL )
      /* nada */;
  } // dealloc


  void add( T data )
  {
    list_type *t;
    
    t = new list_type;
    t->data = data;
    t->next = NULL;
    if (list == NULL) {
      list = t;
      tail = t;
    }
    else {
      tail->next = t;
      tail = t;
    }
  }  // add


  /** reverse the list */
  void reverse(void)
  {
    list_type *elem, *prev, *next;

    prev = NULL;
    next = NULL;

    tail = list;
    for (elem = list; elem != NULL; prev = elem, elem = next) {
      next = elem->next;
      elem->next = prev;
    } // for 
    list = prev;
  }  // reverse


  /** return the lenght of the list */
  unsigned int length(void)
  {
      list_type *elem;
      unsigned int cnt = 0;

      for (elem = list; elem != NULL; elem = elem->next)
	  cnt++;
      return cnt;
  }  // lenght

  /**
     remove an element from the start of the list
     and return the first element of the remaining
     list
  */
  handle remove(void)
  {
    list_type *t;

    if (list != NULL) {
      t = list;
      list = t->next;
      delete t;
    }

    if (list == NULL)
	tail = NULL;

    return list;
  } // remove


  /** given a handle, return the associated data item */
  T get_item( handle h)
  {

    return h->data;
  } // get_item


  /** get the first element from the list */
  handle first(void)
  {
    return list;
  } // first


  /** iterator to get the next element */
  handle next(handle h)  
  {
    list_type *next = NULL;

    if (h != NULL) {
	next = h->next;
    }

    return next;
  } // next
  
};  // template class LIST


#endif

