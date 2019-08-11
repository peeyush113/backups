
#ifndef LIST_H
#define LIST_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/


/**
   This is a generic list type.  It should be instantiated
   with a scalar type, like an integer or a pointer to
   a larger type (e.g., a string or a structure).  For example
   
      LIST<char *> list;
      LIsT<my_struct *> list;

   This class does not have anything but the default destructor.  In
   order to allow a function to allocate a list and then return the
   list as its result, the list is not deallocated by the destructor.
   The list can be deallocated by calling the "dealloc" class
   function.  

*/
template <class T>
class LIST
{
public:
    typedef struct LIST_TYPE {
        T data;
        struct LIST_TYPE *next;
    } list_type;  // struct list_type

private:
  list_type *list;

public:
  typedef list_type *handle;

public:
  LIST(void) 
  { 
    list = 0;
  }


  /** deallocate the list */
  void dealloc(void)
  {
    while ( remove() != 0 )
      /* nada */;
  } // dealloc


  void add( T data )
  {
    list_type *t;
    
    t = new list_type;
    t->data = data;
    t->next = 0;
    if (list == 0) {
      list = t;
    }
    else {
      t->next = list;
      list = t;
    }
  }  // add


  // reverse the list
  void reverse(void)
  {
    list_type *elem, *prev, *next;

    prev = 0;
    next = 0;

    for (elem = list; elem != 0; prev = elem, elem = next) {
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

      for (elem = list; elem != 0; elem = elem->next)
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

    if (list != 0) {
      t = list;
      list = t->next;
      delete t;
    }
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
    list_type *next = 0;

    if (h != 0) {
	next = h->next;
    }

    return next;
  } // next
  
};  // template class LIST


#endif

