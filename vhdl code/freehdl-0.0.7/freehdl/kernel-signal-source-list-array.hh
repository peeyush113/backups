#ifndef KERNEL_SIGNAL_SOURCE_LIST_ARRAY_H
#define KERNEL_SIGNAL_SOURCE_LIST_ARRAY_H

#ifdef KERNEL

#if !defined __GNUC__ || __GNUC__ != 2
#include <ext/hash_map>
#else
#include <hash_map>
#endif

#include <list>
#include <freehdl/kernel-util.hh>
#include <freehdl/kernel-source-descriptor.hh>

using namespace std;
//using namespace __gnu_cxx;

// signal_source stores information about a source of a signal. Note
// that a signal source may be scalar or consist of a set of scalar
// elements. If the signal is not resolved or elementwise resolved
// then the source is scalar. Otherwise, a source consists of all
// scalar signals which are covered by the corresponding resolution
// function. E.g., if a resolution function is defined for a entire
// record type (say, for type "type myrec is record a : bit_vector(0
// to 3); b : integer; end record;") then a source covers all scalars
// which are directly or indirectly included in the record (in this
// case, the record includes 5 scalars (four bits and one integer)).
struct signal_source {
  // driving_id identifies the driving entity (process or
  // component). Note that a source may be either created from a
  // process or an component which is connected to the driven signal
  // (or element thereof).
  void *driving_id;
  // Array of SCALAR drivers
  vector<driver_info*> drivers;
};


// list of sources for a signal or set of signal elements.
struct signal_source_list : public source_descriptor {
  // starting index number of corresponding source, number of scalar
  // signals and resolver_descriptor associated with source are stored
  // in the base class.

  // list of sources. Note that each source gets a separate entry in
  // the list. Further, note that if a resolver process is associated
  // with a signal group then another "virtual" source is added to the
  // end of the source list. This "virtual" source is needed to store
  // the drivers associated with the resolver process.
  list<signal_source> sources;

  signal_source_list() : source_descriptor() { };
  // adds a source to the list of sources for a sepcific set of
  // scalars. id is a unique number to indentify the driver.
  signal_source &add_source(void *id) {
    // create a new source and initialize it
    sources.push_back(signal_source());
    sources.back().driving_id = id;
    sources.back().drivers.resize(size);
    fill(sources.back().drivers.begin(), sources.back().drivers.end(), (driver_info*)NULL);

    return sources.back();
  }
};


// signal_source_list_array stores for each scalar of the signal a
// pointer to a corresponding signal_source_list. Note that several
// scalars may belong to the same signal_source_list. E.g., if a
// composite signal is resolved as a whole then all pointers stored in
// source_list_array point to the same signal_source_list; the
// signal_source_list in turn stores information about each source of
// the signal. However, if the signal is not resolved then each
// source_list_array item points to a different signal_source_list as
// all scalars are individually sourced.
struct signal_source_list_array {
  vector<signal_source_list*> source_list_array;

  signal_source_list_array() { };
  ~signal_source_list_array() {
    for (unsigned int i = 0; i < source_list_array.size(); i++)
      // Note that several elements of source_list array may point to
      // the SAME signal_source_list data instance. However, each
      // signal_source_list item has a index_start value which stores
      // the first scalar index number that is covered by the item. In
      // order to free each data structure only once we compare
      // index_start with the current index.
      if (source_list_array[i] != NULL &&
	  source_list_array[i]->index_start == i)
	delete source_list_array[i];
  }
  signal_source_list_array(const signal_source_list_array &a) {
    source_list_array = a.source_list_array;
  }
  // Initialize data structures. In detail source_list_array is
  // allocated and filled. I.e., the necessary signal_source_list
  // instances are allocated and linked into the array.
  void init(type_info_interface *type);
  signal_source_list *operator[](const int i) {
    return source_list_array[i];
  }
};

// a map stores the sources for each signal. Note that each signal is
// associated with a vector of signal_source_list pointers (included
// in signal_source_list_array).
typedef hash_map<sig_info_base *, signal_source_list_array, pointer_hash<sig_info_base *> > signal_source_map_t;
extern signal_source_map_t signal_source_map;

#endif
#endif
