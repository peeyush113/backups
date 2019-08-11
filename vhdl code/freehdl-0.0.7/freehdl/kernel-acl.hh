#ifndef FREEHDL_KERNEL_ACL_H
#define FREEHDL_KERNEL_ACL_H

#include <stdlib.h>
#include <string.h>

#include <freehdl/kernel-error.hh>


#define MAX_ACL_DEPTH 100 // Max depth of acl objects
#define ACL_MARKER ((int)0x80000000) // This const is used to store an range 
// value within an acl list and to mark the end of a list
#define ACL_RANGE ACL_MARKER


/* *************************************************************
 *  Range directions
 * ************************************************************* */
enum range_direction {to, downto};



// The following macro is used to store a range value into a alc list.
// Note, are stord as 4 int values into the list. ACL_RANGE_MARKER 
// marks the start of a range value. Thereafter the left, the direction
// and the right value are stored into the list. Note further, this
// macro is based on the "<<" operator of the acl class.
#define acl_range(left, direction ,right) ACL_RANGE << left << direction << right 


class acl;
typedef acl *pacl;
extern acl *free_acl[MAX_ACL_DEPTH + 1]; // List of acl objects that are currently not in use


// acl are used to identify elements or set of elements of
// a composite object. It is simply a list of int values. The
// first element stores the maximum length and the number of items
// currently on the list. Note, an acl instance can be created 
// with "new(x)" only, where "x" is the maximum length (number of
// items) of the list.
class acl {
  struct _head { short index; short size; };
  union _data { _head head; int value; acl *next; };
  _data data;
  _head &get_header() { return (&this->data)[-1].head; }
  int get_index() const { return (&this->data)[-1].head.index; }
public:
  // Returns the number of items of an acl instance
  int get_size() const { return (&this->data)[-1].head.size; }

  // Allocate a new acl instance from the list of free acl
  // objects. 
  void *operator new(size_t, int s) {
#ifdef DEBUG
    string deb;
#endif
    // Test parameter s
    v_assert(s >= MAX_ACL_DEPTH, "MAX_ACL_DEPTH too small");
#ifdef DEBUG
    deb=s;
    v_assert(s < 1, "Illegal acl size (" + deb + ")");
#endif
    acl *new_acl;
    if (free_acl[s] != NULL) {
      // There is an unused object in free_acl with the
      // correct length
      new_acl = free_acl[s];
      free_acl[s] = new_acl->data.next;
    } else
      // Otherwise create a new acl list. Two elementes are
      // used to mark the end of the list and one element
      // stores the length of the list. Note, the length
      // is stored in the -1'st element!
      new_acl = ((acl*)malloc((s + 3) * sizeof(_data)) + 1);

    // Mark the current as well as the absolute end of the list.
    // Note, contrary to the current end the absolute end will
    // be never overwritten!
    (&new_acl->data)[0].value = ACL_MARKER;
    (&new_acl->data)[1].value = ACL_MARKER;
    (&new_acl->data)[s].value = ACL_MARKER;
    (&new_acl->data)[s+1].value = ACL_MARKER;
    // Store the current size of the list
    new_acl->get_header().index = 0;
    new_acl->get_header().size = s;
    return new_acl;
  }

  // Removes a acl item. The unused item is inserted into
  // the free_acl array.
  void operator delete(void *a) {
    // The size of the current acl list is stored in the -1'nd
    // element
    register int s = ((acl*)a)->get_header().size;
    ((acl*)a)->data.next = free_acl[s];
    free_acl[s] = (acl*)a;
  }

  acl() { };

  // Clear the current acl list, i.e. remove all entries.
  acl &clear() {
    // Mark the current end of the list. Note that the it is not
    // necessary to reset the absolute end of the list as it is not
    // overwritten!
    (&data)[0].value = ACL_MARKER;
    (&data)[1].value = ACL_MARKER;
    // Set the size of the current size to 0
    get_header().index = 0;

    return *this;
  }

  // Adds a single int value to the current acl list. The result 
  // is stored into the current acl list. Note, no range checking 
  // is done!
  acl &operator<<(const int i) {
    ((int*)&data.value)[get_header().index++] = i;
    // Mark end of list
    ((int*)&data.value)[get_header().index + 1] = ACL_MARKER;
    return *this;
  }

  // Returns true if there are no more values
  bool end() const { 
    return (this == NULL)? true : (&data.value)[0] == ACL_MARKER && (&data.value)[1] == ACL_MARKER; 
  }

  // Compare operator
  bool operator==(const acl &a);

  // Assigment operator
  acl &operator=(const acl &a) {
    memcpy(&data.value, &a.data.value, sizeof(int) * (a.get_index() + 2));
    get_header().index = a.get_index();
    return *this;
  }

  // Creates a copy of the acl
  acl *clone() {
    if (this == NULL) return (acl*)NULL;
    acl *new_acl = new(get_size()) acl;
    *new_acl = *this;
    return new_acl;
  }

  // Returns item number i of an acl instance
  int get(int i) const { return ((int*)&data.value)[i]; }

  // Returns the current value the acl instance points to
  int get() const { return ((int*)&data.value)[0]; }

  // Set index i to value j
  acl *set(int i, int j) { 
    ((int*)&data.value)[i] = j;
    return (acl*)&data.value;
  }

  // Returns the next acl instance
  acl *next() { return (acl*)&((int*)&data.value)[1]; }

  // Return last entry in acl list. Note that an range entry is
  // considered as a single entry!
  acl *back() {
    if (end()) return this;
    
    acl *current_acl = this;
    acl *next_acl = current_acl->next();
    // search for the last entry in the list
    while (!next_acl->end()) {
      current_acl = next_acl;
      next_acl = next_acl->next();
      // If the next acl is a range entry then skip over all elements
      // of the range
      if (!next_acl->end() &&
	  next_acl->get() == ACL_RANGE)
	for (int i = 0; i < 4; i++)
	  next_acl = next_acl->next();
    }

    return current_acl;
  }
  
};


#ifdef KERNEL
// *****************************************************************
// Some function  which are used only within kernel code.
// *****************************************************************

// Count levels an acl consists of. Note that a range is counted as a
// single level.
int
count_levels(const pacl a);

// Get acl pointer associated with level "level". Note that a range is
// counted as a single level.
pacl
get_level(const pacl a, const int level);

// Creates a new acl containing levels begin to end (not included)
// from original acl a
pacl
clone_levels(const pacl a, const int begin, const int end);

// Returns current acl entry in left, dir and right. A single number
// is converted into a range "number" to "number". If no range or
// index is specified then a null range 1 to 0 is returned. Function
// returns a pointer to the next acl entry.
pacl
get_entry_data(pacl a, int &left, range_direction &dir, int &right);

#endif

extern pacl tmpacl;
extern pacl tmpacl1;
extern pacl tmpacl2;

#endif
