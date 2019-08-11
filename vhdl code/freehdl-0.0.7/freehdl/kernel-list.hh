#ifndef FREEHDL_KERNEL_LIST_H
#define FREEHDL_KERNEL_LIST_H

#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

//**********************************************************************
// A simple list template class.
//**********************************************************************

template<class T> class simple_list {
  struct _item {
    _item *next, *prev;
    T value;
    _item() { };
  };

  _item *first_item, *last_item;

  // A list of currently unused items
  _item *free_items;

  // Allocates a new item from the free_items list or creates
  // a new one
  _item *internal_new() {
    if (free_items) {
      _item *nitem = free_items;
      free_items = free_items->next;
      return nitem;
    }
    return new _item;
  }

  // Removes a item from the list. Actually, the memory is not
  // "freed" but the item is inserted into the free_items list
  void internal_delete(void *p) {
    _item *pos = (_item*)p;
    pos->next = free_items;
    free_items = pos;
  }
 public:
  void clean_up() {
    while (free_items) {
      _item *nitem = free_items->next;
      delete free_items;
      free_items = nitem;
    }
    free_items = NULL;
  }

  simple_list() { first_item = last_item = free_items = NULL; }

  // Returns the # of items on the list
  int size();

  // Returns true if the list is empty
  int is_empty() { return first_item == NULL; }

  // Returns handler to first item on the list
  void *begin() const { return (void*)first_item; }

  // Returns handler to last item on the list
  void *end() const { return (void*)last_item; }

  // Returns next item
  void *next(void *p) { return ((_item*)p)->next; }

  // Returns prevouis item
  void *prev(void *p) { return ((_item*)p)->prev; }

  // Returns a reference to the content of a list item
  T &content(void *p) { return ((_item*)p)->value; }

  // Inserts a new item into the list. The item is inserted 
  // before the item referenced by "pos". If pos is NULL then
  // it is appended.
  void *insert(void *p, const T &t) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;
    new_item->value = t;
    if (!pos) {
      new_item->prev = last_item;
      new_item->next = NULL;
      if (last_item) last_item->next = new_item;
      else first_item = new_item;
      last_item = new_item;
      return (void*)new_item;
    } else if (pos == first_item) {
      new_item->prev = NULL;
      first_item->prev = new_item;
      new_item->next = first_item;
      first_item = new_item;
      return (void*)new_item;
    }
    pos->prev->next = new_item;
    new_item->prev = pos->prev;
    pos->prev = new_item;
    new_item->next = pos;
    return (void*)new_item;
  }

  // Append a new item
  void *push_back(const T &t) { return insert(NULL, t); } 

  // Removes a item. Returns a handler to the previous item
  // or to the first item on the list if the removed one was
  // the first item.
  void *remove(void *p) {
    _item *pos = (_item*)p;
    if (pos->prev) pos->prev->next = pos->next; else first_item = pos->next;
    if (pos->next) pos->next->prev = pos->prev; else last_item = pos->prev;
    _item *ret = (pos->prev)? pos->prev : first_item;
    internal_delete(pos);
    return (void*) ret;
  }

  // Reset list
  void reset() {
    _item *pos = first_item;
    while (pos) { pos = (_item*)remove(pos); }
    clean_up(); 
  }

  // Destructor
  ~simple_list() { reset(); }
};


template<class T>
int simple_list<T>::size()
{
  int result = 0;
  _item *pos = first_item;
  while (pos) {
    result++;
    pos = pos->next;
  }
  return result;
}





//**********************************************************************
// A sorted list template class. The list items are sorted
// in increasing order given by "key".
//**********************************************************************

template<class T, class K> class simple_queue {
  struct _item {
    K key;
    _item *next, *prev;
    T value;
    _item() { };
  };
  _item *first_item, *last_item;
  _item *free_items;
  
  // Allocates a new item from the free_items list or creates
  // a new one
  _item *internal_new() {
    if (free_items) {
      _item *nitem = free_items;
      free_items = free_items->next;
      return nitem;
    }
    return new _item;
  }

  // Removes a item from the list. Actually, the memory is not
  // "freed" but the item is inserted into the free_items list
  void internal_delete(void *p) {
    _item *pos = (_item*)p;
    pos->next = free_items;
    free_items = pos;
  }
 public:
  void clean_up() {
    while (free_items) {
      _item *nitem = free_items->next;
      delete free_items;
      free_items = nitem;
    }
    free_items = NULL;
  }

  simple_queue() { first_item = last_item = free_items = NULL; }

  // Returns the # of items on the list
  int size();

  // Returns handler to first item on the list
  void *begin() const { return (void*)first_item; }

  // Returns handler to last item on the list
  void *end() const { return (void*)last_item; }

   // Returns next item
  void *next(void *p) { return ((_item*)p)->next; }
  
  // Returns prevouis item
  void *prev(void *p) { return ((_item*)p)->prev; }

  // Returns a reference to the content of a list item
  T &content(void *p) { return ((_item*)p)->value; }

  // Returns the key value of the item
  K &key(void *p) { return ((_item*)p)->key; }

  // Inserts a new item into the list. The item is inserted 
  // before the item referenced by "pos". If pos is NULL then
  // it is appended.
  void *insert(void *p, const T &t, const K &key) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;
    new_item->value = t;
    new_item->key = key;
    if (!pos) {
      new_item->prev = last_item;
      new_item->next = NULL;
      if (last_item) last_item->next = new_item;
      else first_item = new_item;
      last_item = new_item;
      return (void*)new_item;
    } else if (pos == first_item) {
      new_item->prev = NULL;
      first_item->prev = new_item;
      new_item->next = first_item;
      first_item = new_item;
      return (void*)new_item;
    }
    pos->prev->next = new_item;
    new_item->prev = pos->prev;
    pos->prev = new_item;
    new_item->next = pos;
    return (void*)new_item;
  }

  // Creates a new item. The item is inserted 
  // before the item referenced by "pos". If pos is NULL then
  // it is appended. Note, the value of the new item
  // is not set.
  void *insert(void *p, const K &key) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;
    new_item->key = key;
    if (!pos) {
      new_item->prev = last_item;
      new_item->next = NULL;
      if (last_item) last_item->next = new_item;
      else first_item = new_item;
      last_item = new_item;
      return (void*)new_item;
    } else if (pos == first_item) {
      new_item->prev = NULL;
      first_item->prev = new_item;
      new_item->next = first_item;
      first_item = new_item;
      return (void*)new_item;
    }
    pos->prev->next = new_item;
    new_item->prev = pos->prev;
    pos->prev = new_item;
    new_item->next = pos;
    return (void*)new_item;
  }

  // Append a new item
  void *push_back(const T &t, const K &key) { return insert(NULL, t, key); } 

  // Append a new item
  void *push_back(const K &key) { return insert(NULL, key); } 

  // Removes a item. Returns a handler to the previous item
  // or to the first item on the list if the removed one was
  // the first item.
  void *remove(void *p) {
    _item *pos = (_item*)p;
    if (pos->prev) pos->prev->next = pos->next; else first_item = pos->next;
    if (pos->next) pos->next->prev = pos->prev; else last_item = pos->prev;
    _item *ret = (pos->prev)? pos->prev : first_item;
    internal_delete(pos);
    return (void*) ret;
  }

  // Inserts a new item into the list sorted in increasing order
  // by k
  void *inqueue(const T &t, const K &k) {
    _item *pos = first_item;
    while (pos && pos->key < k) { pos = pos->next; }
    return insert(pos, t, k);
  }

  // Same as inqueue, but the place to insert the new item is 
  // searched starting from the end of the queue
  void *inqueue_r(const T &t, const K &k) {
    _item *pos = last_item, *old_pos = NULL;
    while (pos && pos->key > k) { old_pos = pos; pos = pos->prev; }
    return insert(old_pos, t, k);
  }

  // Destructor
  ~simple_queue() { 
    _item *pos = first_item;
    while (pos) { pos = (_item*)remove(pos); }
    clean_up(); 
  }
};


template<class T, class K>
int simple_queue<T,K>::size()
{
  int result = 0;
  _item *pos = first_item;
  while (pos) {
    result++;
    pos = pos->next;
  }
  return result;
}



//**********************************************************************
//A sorted list template class. The list items are sorted in
//increasing order given by "key". This class is similar to the queue
//class. The main difference is that all free items are stored in a
//global linked list which is specified during template instantiation.
//**********************************************************************

template<class T, class K> class fqueue {
  struct _item {
    _item *next, *prev;
    K key;
    T value;
    _item() { };
  };
  _item *first_item;
  static void *free_items; // Note, this pointer is static! Actually,
  // it would be better to pass it in as a template
  // parameter. Unfortunately, gcc currently crashes when a void*
  // pointer is added to the template parameter list.
  
  // Allocates a new item from the free_items list or creates
  // a new one
  static _item *internal_new() {
    if (free_items) {
      _item *nitem = (_item*)free_items;
      free_items = ((_item*)free_items)->next;
      return nitem;
    } else
      return new _item;
  }

  // Removes an item and all following items from the list. Actually,
  // the memory is not "freed" but the item is inserted into the
  // free_items list
  static void internal_delete_chain(void *p) {
    _item *pos = (_item*)p;
    _item *npos = pos;
    while (npos->next)
      npos = npos->next;
    npos->next = (_item*)free_items;
    free_items = pos;
  }

 public:
  // Move item to free_items list
  static void free_item(void *p) {
    _item *pos = (_item*)p;
    pos->next = (_item*)free_items;
    free_items = pos;
  }

  static void *get_new_item() { return (void*)internal_new(); }

  static void clean_up() {
    while (free_items) {
      _item *nitem = ((_item*)free_items)->next;
      delete (_item*)free_items;
      free_items = nitem;
    }
    free_items = NULL;
  }

  fqueue() { first_item = NULL; }

  // Return length of the queue
  int size();

  // Returns handler to first item on the list
  void *start() const { return (void*)&first_item; }

  // Returns handler to first item on the list
  void *begin() const { return (void*)first_item; }

   // Returns next item
  static void *next(void *p) { return ((_item*)p)->next; }
  
  // Returns prevouis item
  static void *prev(void *p) { return ((_item*)p)->prev; }

  // Get empty item
  void *new_item() { return internal_new(); }

  // Returns a reference to the content of a list item
  static T &content(void *p) { return ((_item*)p)->value; }

  // Returns the key value of the item
  static K &key(void *p) { return ((_item*)p)->key; }

  // Inserts a new item into the list. The item is inserted 
  // after the item referenced by "pos".
  static void *insert(void *p, const T &t, const K &key) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;
    new_item->value = t;
    new_item->key = key;
    if (pos->next) {
      new_item->next = pos->next;
      pos->next->prev = new_item;
    }
    pos->next = new_item;
    new_item->prev = pos;

    return (void*)new_item;
  }


  // Creates a new item. The item is inserted 
  // after the item referenced by "p"
  static void *insert(void *p, const K &key) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;
    _item *npos = pos->next;

    new_item->key = key;
    new_item->prev = pos;
    new_item->next = npos;
    if (npos)
      npos->prev = new_item;
    pos->next = new_item;

    return (void*)new_item;
  }

  // Creates a new item. The item is inserted after the item
  // referenced by "p". "p" must point to the end of
  // the queue.
  static void *push_back(void *p, const K &key) { 
    _item *new_item = internal_new();
    _item *pos = (_item*)p;

    new_item->key = key;
    new_item->prev = pos;
    new_item->next = NULL;
    pos->next = new_item;

    return (void*)new_item;
  }

  // Inserts new item "n" after "p" into the queue. "p" must point to
  // the end of the queue.
  static void push_back(void *p, void *n) { 
    _item *new_item = (_item*)n;
    _item *pos = (_item*)p;

    new_item->prev = pos;
    new_item->next = NULL;
    pos->next = new_item;
  }

  // Removes a item. Returns a handler to the next item
  // or NULL if p is the last item.
  static void *remove(void *p) {
    _item *pos = (_item*)p;
    _item *ret = pos->next;
    if (pos->next)
      pos->next->prev = pos->prev;
    pos->prev->next = pos->next;

    free_item(pos);

    return (void*) ret;
  }

  // Removes item p and all following items.
  static void cut_remove(void *p) {
    _item *pos = (_item*)p;
    pos->prev->next = NULL;
    internal_delete_chain(pos);
  }

  // Unlink item from list but do NOT remove it. Returns handler to
  // the next item or NULL if p is the kast item
  static void *unlink(void *p) {
    _item *pos = (_item*)p;
    _item *ret = pos->next;
    if (pos->next)
      pos->next->prev = pos->prev;
    pos->prev->next = pos->next;

    return (void*) ret;
  }

  // Destructor
  ~fqueue() {
    if (first_item)
      cut_remove(first_item);
    clean_up(); 
  }
};


template<class T, class K>
int fqueue<T,K>::size()
{
  int result = 0;
  _item *pos = first_item;
  while (pos) {
    result++;
    pos = pos->next;
  }
  return result;
}




//**********************************************************************
// A simple array template class. The array cannot shrink but several
// arrays may share the same internal data structure in order to save
// space!
// //**********************************************************************

template<class T> class shared_array {
  int length;
  char *array_pointer;

  T* array_data() const { return (T*)(array_pointer + sizeof(int)); }
  int &reference_counter_ref() const { return *(int*)array_pointer; }
  
 public:
  void clean_up() {
    if (array_pointer != NULL) {
      // The first int of array_pointer always point to a reference
      // counter
      if (--reference_counter_ref() == 0)
	free(array_pointer);
    }
    length = 0;
    array_pointer = NULL;
  }

  shared_array() { array_pointer = NULL; length = 0; }

  // Returns # of items on the list
  int size() const { return length; }

  // Returns true if the list is empty
  int is_empty() const { return length == 0; }

  // Returns a reference to the content of a list item
  T &content(const int i) const { return array_data()[i]; }

  // Inserts a new item at the end of the array.
  void push_back(const T &t) {
    // The first int of array_pointer always point to a reference
    // counter
    if (array_pointer != NULL &&
	reference_counter_ref() > 1) {
      reference_counter_ref()--;
      char *new_array_pointer = (char*)malloc(sizeof(T) * (length + 1) + sizeof(int));
      memcpy(new_array_pointer, array_pointer, sizeof(T) * (length++) + sizeof(int));
      array_pointer = new_array_pointer;
    } else
      array_pointer = (char*)realloc(array_pointer, sizeof(T) * ++length + sizeof(int));
    reference_counter_ref() = 1;
    array_data()[length - 1] = t;
  }

  // Makes a copy of array "a". Note that the current instance will
  // use the same array_pointer as "a".
  void link(shared_array &a) {
    clean_up();
    length = a.length;
    array_pointer = a.array_pointer;
    // The first int of array_pointer always point to a reference
    // counter
    reference_counter_ref()++;
  }

  // Returns true if "a" and current instance reference the same
  // array.
  bool is_linked(const shared_array &a) const { return array_pointer == a.array_pointer; }

  void reset() {
    clean_up(); 
  }

  // Destructor
  ~shared_array() { reset(); }
};



/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

// Compare equal operator for array<T> 
template<class T>
inline bool 
is_equal(const shared_array<T> &a, const shared_array<T> &b) 
{
  if (a.size() != b.size()) return false;
  if (a.is_linked(b)) return true;
  for (int i = 0; i < a.size(); i++)
    if (!is_equal(a.content(i), b.content(i)))
      return false;
  return true;
}

  
// Generate hash number from array<T> 
template<class T>
inline unsigned int
get_hash(const shared_array<T> &a) {
  unsigned int num = 0;
  const int UINT_BIT = sizeof(unsigned int) * CHAR_BIT;
  for (int i = 0; i < a.size(); i++)
    num = ((num << 2) || ((UINT_BIT - 2) >> 30)) + get_hash(a.content(i));
  return num;
}

#endif

#endif
