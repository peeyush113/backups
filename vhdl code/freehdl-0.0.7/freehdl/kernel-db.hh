#ifndef FREEHDL_KERNEL_DB_H
#define FREEHDL_KERNEL_DB_H

#include <assert.h>


/* This header file includes the definitions that are required to
 * setup a kernel database. This database will be used by the kernel
 * to store information. Each chunk of information is associated with
 * a key. The key as well as the type and name of information are not
 * necessarily kown to the database at compile time. E.g., new key
 * types as well as new data types can be added without recompiling or
 * rebuilding the database. Here is an short example on how to add and
 * use the database:

// These are macro calls so DO NOT INSERT ANY SPACE BETWEEN ".._type"
// AND "("!!!

// First, we define a key that is used to store an item in the data
// base. Here, the macro creates an item db_key_type::sig_key that
// references the corresponding key type. Note that db_key_type is a
// namespace.

define_db_key_type(sig_info_base*, sig_key); 

// Next, define two data types that shall be actually stored. Here the
// macro creates a new item db_entry_type::sig_name and associates it
// with the data type string. Further, a new struct is defined and
// also prepared for storing to the database. Note that db_entry_type is
// a namespace.

define_db_entry_type(string, sig_name);

// A structure shall be stored in the database
struct driver_data {
   int driver_count;
   bool is_resolved;
};

define_db_entry_type(driver_data, driver_data_entry)


// Now, create an database explorer instance. The database explorer is
// used to search and manipulate the database. The explorer is
// associated with the corresponding database (here: kernel_db) at
// construction. Note that we must define the data kind we are
// interested in as a template parameter to db_explorer.

db_explorer<db_key_type::sig_key, db_entry_type::sig_name> sig_info_ext (kernel_db);

// Now we can create and reference an entry. The following code will
// associate a_siginfo_pointer with an database entry
// db_entry_type::sig_name which stores the value "test". Note that
// get will automatically create an corresponding entry if the current
// a_siginfo_pointer value is not associated with this entry kind.

sig_info_ext.get (a_siginfo_pointer) = "test";

// Another explorer is created that can be used to access
// driver_data_entry. Note that an separate explorer instance must be
// used for each data entry type!

db_explorer<db_key_type::sig_key, db_entry_type::driver_data_entry> 
   sig_info_driver_ext (kernel_db);

sig_info_driver_ext.get (a_siginfo_pointer).is_resolved = true;
sig_info_driver_ext.get (a_siginfo_pointer).driver_count = 0;

// For other ways to access/query the databse see the db_explorer
// class.

*/

/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <vector>
#include <freehdl/kernel-util.hh>

#if !defined __GNUC__ || __GNUC__ != 2
#include <ext/hash_map>
#else
#include <hash_map>
#endif

// Macro used to define a key type. K is the actual type of the key
// while N is his name that will be used within the kernel
// database. Note that N is created in namespace db_key_type. Hence,
// to reference it use db_key_type::N.
#define define_db_key_type(K,N)			\
  namespace db_key_type				\
  {						\
    struct __kernel_db_key_type__ ## N { typedef K key_type;	\
      static string get_name () { return # N; } };		\
    typedef db_key_kind<__kernel_db_key_type__ ## N> N;		\
  }
  
// Macro used to define a database entry type. K is the type (as
// defined by define_db_key_type, while T is the type of the data
// entry and N is his name that will be used to identify the data
// entry type. Note that N is created in namespace
// db_entry_type. Hence, to reference it use db_entry_type::N.
#define define_db_entry_type(T,N)					\
  namespace db_entry_type						\
  {									\
    struct __kernel_db_entry_type__ ## N { typedef T data_type;		\
      static string get_name () { return # N; } };			\
    typedef db_entry_kind<T, __kernel_db_entry_type__ ## N> N;		\
  }									\
  

// Base class to derive all key kind classes from
class db_key_kind_base
{
public:
  virtual ~db_key_kind_base() {};
  virtual string get_name () = 0;
};

// The actual key kind class. This class represents the correponding
// key type. Key is the key type. This class is a singleton.
template<class Key>
class db_key_kind : public db_key_kind_base
{
private:
  static db_key_kind *single_instance;
  
public:
  static db_key_kind *get_instance ()
  {
    if (single_instance == NULL)
      single_instance = new db_key_kind;
    
    return single_instance;
  }
      
protected:
  db_key_kind () { };
  
public:
  // Get name of key.
  string get_name () { return Key::get_name (); }
  typedef db_key_kind_base kind_base_type;
  typedef typename Key::key_type key_type;
};

template<class Key>
db_key_kind<Key> *db_key_kind<Key>::single_instance = NULL;


// From the following class all entry kind classes are derived.
class db_entry_kind_base
{
public:
  virtual ~db_entry_kind_base() {};
  virtual string get_name () = 0;
};


// The actual entry kind class. This class represents the correponding
// database entry kind. This class is a singleton. T is the type of
// the data entry. N is the name of this data kind.
template<class T, class N>
class db_entry_kind : public db_entry_kind_base
{
private:
  static db_entry_kind *single_instance;

public:
  static db_entry_kind *get_instance ()
  {
    if (single_instance == NULL)
      single_instance = new db_entry_kind;
    
    return single_instance;
  }
      
protected:
  db_entry_kind () { };
  
public:
  // Get name of database entry.
  string get_name () { return N::get_name (); }
  typedef T data_type;
  typedef db_entry_kind_base kind_base_type;
};


template<class T,class N>
db_entry_kind<T,N> *db_entry_kind<T,N>::single_instance = NULL;


// Base class for all db_entry classes. THe class stores a pointer to
// the corresponding db_entry_kind.
class db_entry_base 
{
public:
  virtual ~db_entry_base() {};
  const db_entry_kind_base *kind;
  virtual string get_name () = 0;
  db_entry_base (db_entry_kind_base *k) : kind (k) { };
};

// This is the class that is used to store the database data. kind is
// the db_entry_kind associated with this entry.
template<class entry_kind>
class db_entry : public db_entry_base
{
public:
  typename entry_kind::data_type data;
  string get_name () { return entry_kind::get_instance () -> get_name (); }
  db_entry () : db_entry_base (entry_kind::get_instance ()) { };
};


class db_basic_key
{
public:
  void *value;
  bool operator == (const db_basic_key &k) const { return value == k.value; }
  db_basic_key (void *v) { value = v; }
};

// The database base class. Defines a set of common interfaces that
// must be implemented by all databases.
class db_base
{
public:
  virtual ~db_base() {};
  typedef pair<db_key_kind_base*, vector<db_entry_base*> > db_key_entry_pair;

  // Checks whether there is a entry in the database assoicated with
  // key.
  virtual bool is_in_database (db_basic_key key) = 0;
  // Looks up en entry in the database. Note that this method must not
  // be used if there is no entry associated with key.
  virtual db_key_entry_pair &find (db_basic_key key) = 0;
  // Same as find however, a new entry is created if key is not
  // present in database.
  virtual db_key_entry_pair &find_create (db_basic_key key, db_key_kind_base *key_kind) = 0;
  // Creates a new entry with key key and associates entry data dbe
  // with it.
  virtual db_entry_base *add_entry (db_basic_key key, db_key_kind_base *key_kind, db_entry_base *dbe) = 0;
  // Erase entry vom the database. The entry is defined by key and the
  // data entry index i. Note that there may be several entries
  // associated with key.
  virtual bool erase (db_basic_key key, int i) = 0;
  // Return number of keys stored in database.
  virtual int key_count () const = 0;
};


// A hash function template used tp generate a hash number from
// d
class db_basic_key_hash : public hash<unsigned long> {
public:
  size_t operator()(const db_basic_key& x) const {
    return (*(hash<unsigned long> *)this)(((unsigned long)x.value)>>2);
  }
};


// The acutal database definiton
class db : public db_base 
{
  // This mappes is the actual database.
  typedef hash_map<void*, db_key_entry_pair, db_basic_key_hash> db_data_map_type;
  db_data_map_type data_map;

  // The transaction id is incremented each time a new key is added or
  // a key is removed. 
  long long int transaction_id;

public:
  
  db () : transaction_id (0) {};

  // Some methods used to walk through the keys stored in the database.
  class key_iterator 
  {
    db_data_map_type::iterator iter;
  public:
    key_iterator () { }
    key_iterator (const db_data_map_type::iterator i) { iter = i; }
    key_iterator &operator ++ () { iter++; return *this; }
    key_iterator operator ++ (int) 
    { 
      key_iterator tmp = *this;
      iter++; 
      return tmp; 
    }
    bool operator == (const key_iterator i) const { return iter == i.iter; }
    bool operator != (const key_iterator i) const { return iter != i.iter; }
    db_basic_key operator * () const { return db_basic_key (iter->first); } 
  };
  key_iterator begin () { return key_iterator (data_map.begin ()); }
  key_iterator end () { return key_iterator (data_map.end ()); }

  // Return number of keys stored in database.
  int key_count () const { return data_map.size (); }

  // Checks whether there is a entry in the database assoicated with
  // key.
  bool is_in_database (db_basic_key key) 
  {
    return data_map.find (key.value) != data_map.end ();
  }

  
  // Looks up en entry in the database. Note that this method must not
  // be used if there is no entry associated with key.
  db_key_entry_pair &find (db_basic_key key) 
  {
    db_data_map_type::iterator iter = data_map.find (key.value);
    assert (iter != data_map.end ());

    return iter->second;
  }

  // Same as find however, a new entry is created if key is not
  // present in database.
  db_key_entry_pair &find_create (db_basic_key key, db_key_kind_base *key_kind) 
  {
    if (! is_in_database (key))
      {
	data_map [key.value] =  db_key_entry_pair (key_kind, vector<db_entry_base*> ());
	// Increment transaction id to mark that a key has been
	// added or removed.
	transaction_id ++;
      }
    db_data_map_type::iterator iter = data_map.find (key.value);

    return iter->second;
  }

  // Creates a new entry key and associates entry data dbe with it.
  db_entry_base *add_entry (db_basic_key key, db_key_kind_base *key_kind, db_entry_base *dbe)
  {
    vector<db_entry_base*> &vec = find_create (key, key_kind).second;
    vec.push_back (dbe);

    return vec.back ();
  }

  // Erase entry vom the database. The entry is defined by key and the
  // data entry index i. Note that there may be several entries
  // associated with key. If there is no entry left, then the
  // corresponding key is also removed from the database.
  bool erase (db_basic_key key, int i)
  {
    db_data_map_type::iterator iter = data_map.find (key.value);
    if (iter == data_map.end ()) return false;
    vector<db_entry_base*> &vec = iter->second.second;
    if (vec [i] != NULL)
      delete vec [i];
    vec.erase (vec.begin () + i);

    if (vec.size () == 0)
      {
	data_map.erase (iter);
	// Increment transaction id to mark that a key has been
	// added or removed.
	transaction_id ++;
      }

    return true;
  }
};


// Operator class used to control the search operation of the database.
template<class K>
class exact_match {
public:
  bool operator () (const typename K::kind_base_type *a, const typename K::kind_base_type *b)
  {
    return a == b;
  }
};


// Operator class used to control the search operation of the database.
template<class K>
class match_all {
public:
  bool operator () (const typename K::kind_base_type *a, const typename K::kind_base_type *b)
  {
    return true;
  }
};


// Template used to cast a key to void*. Note that the actual core
// database uses void* as keys.
template<class K>
class default_key_mapper
{
public:
  db_basic_key convert_to_basic_key (const typename K::key_type key) const { return db_basic_key ((void*)key); }
  typename K::key_type convert_to_key (db_basic_key p) const { return (typename K::key_type)p.value; }
};


// The database explorer is used to search and manipulate the
// database. The explorer is associated with the corresponding
// database (here: kernel_db) at construction. Note that we must
// define the data kind we are interested in as a template parameter
// to the explorer.
template<class key_kind,
	 class kind, 
	 class key_mapper = default_key_mapper<key_kind>,
	 class KM = exact_match<key_kind>, 
	 class DM = exact_match<kind> >
class db_explorer 
{
  db &database;
  // last_index is used to cache the last referenced entry accessed
  // with this database explorer.
  int last_index;

  // Looks up an entry specified by key in the database. Returns NULL
  // if no such entry is present (either key in not in the database or
  // there is no such entry kind associated with key.
  db_entry<kind> *find_entry (const typename key_kind::key_type key)
  {
    key_mapper keym;
    if (! database.is_in_database (keym.convert_to_basic_key (key))) return NULL;

    db_base::db_key_entry_pair &hit = database.find (keym.convert_to_basic_key (key));
    assert (hit.second.size () > 0);

    // Test whether key is assoicates with the correct key type
    KM km;
    if (!km (key_kind::get_instance (), hit.first)) return NULL;
    
    // Try to check out the last match that was found by the
    // explorer. This implements a simple type of cache mechanism to
    // speedup lookup operations.
    DM m;
    if ((unsigned)last_index < hit.second.size () &&
	m (kind::get_instance (), hit.second [last_index]->kind ))
      {
	db_entry<kind> *entry = dynamic_cast<db_entry<kind>*> (hit.second [last_index]);
	assert (entry != NULL);
	return entry;
      }

    for (unsigned int i = 0; i < hit.second.size (); i++)
      if (m (kind::get_instance (), hit.second [i]->kind ))
	{
	  db_entry<kind> *entry = dynamic_cast<db_entry<kind>*> (hit.second [i]);
	  assert (entry != NULL);
	  last_index = i;
	  return entry;
	}

    return NULL;
  }

public:
  db_explorer (db &d) : database (d), last_index (0) { };

  // Looks up an entry specified by key in the database. Returns
  // pointer to the actual database value. Returns NULL if no such
  // entry is present (either key in not in the database or there is
  // no such entry kind associated with key.
  typename kind::data_type *find (const typename key_kind::key_type key) 
  {
    db_entry<kind> *entry = find_entry (key); 
    return entry != NULL? &entry->data : NULL;
  } 

  // Looks up an entry specified by key in the database. Returns
  // pointer to the actual database value. Returns NULL if no such
  // entry is present (either key in not in the database or there is
  // no such entry kind associated with key.
  typename kind::data_type *find (const db_basic_key key) 
  {
    key_mapper keym;
    db_entry<kind> *entry = find_entry (keym.convert_to_key (key)); 
    return entry != NULL? &entry->data : NULL;
  } 

  // Checks whether a key is valid, i.e., actually is a key with the 
  // correct type.
  bool is_valid (const db_basic_key key)
  {
    key_mapper keym;
    db_entry<kind> *entry = find_entry (keym.convert_to_key (key)); 
    return entry != NULL;
  }

  // Converts basic key to the appropriate key type. Note that no
  // error checking is done. I.e., the caller must esure that key
  // actually refers to the correct pointer type.
  typename key_kind::key_type get_key (db_basic_key key) const 
  { 
    key_mapper keym;
    return keym.convert_to_key (key); 
  }

  // Same as find but creates an new entry if there is no such entry
  // present.
  typename kind::data_type *find_create (const typename key_kind::key_type key)
  {
    db_entry<kind> *entry = find_entry (key);

    if (entry == NULL)
      {
	key_mapper keym;
	database.find_create (keym.convert_to_basic_key (key), key_kind::get_instance ());
	entry = dynamic_cast<db_entry<kind>*> (database.add_entry (keym.convert_to_basic_key (key), 
								   key_kind::get_instance (),
								   new db_entry<kind> ()));
      }

    return &entry->data;
  } 

  typename kind::data_type *find_create (db_basic_key key) { return find_create (get_key (key)); }


  // Returns pointer to the corresponding data value.
  typename kind::data_type &get (const typename key_kind::key_type key)
  {
    return *find_create (key);
  }

  typename kind::data_type &get (db_basic_key key) { return get (get_key (key)); }

  // Removes all entries of of kind "kind" that are associated with
  // key.
  bool erase (const typename key_kind::key_type key)
  {
    key_mapper keym;
    if (! database.is_in_database (keym.convert_to_basic_key (key))) return false;

    DM m;
    db_base::db_key_entry_pair &hit = database.find (keym.convert_to_basic_key (key));
    for (int i = 0; i < hit.second.size (); i++)
      if (m (kind::get_instance (), hit.second [i]->kind))
	return database.erase (keym.convert_to_basic_key (key), i);
 
    return false;
  }

  bool erase (db_basic_key key) { return erase (get_key (key)); }
};



// Define a common database key
define_db_key_type(void*, generic_key); 


// db_generic_explorer is a special database explorer which does not
// take the key type into account during its operations. I.e., it does
// notcheck whether the key type of a specific entry is consistent
// with the kind parameter of the template. Hence, this explorer is
// NOT ALLOWED to insert any new keys into the database.
template<class kind, 
	 class key_mapper = default_key_mapper<db_key_type::generic_key>,
	 class DM = exact_match<kind> >
class db_generic_explorer
{
  db_explorer <db_key_type::generic_key, kind, key_mapper, match_all<db_key_type::generic_key>, DM > internal_explorer;
public:
  db_generic_explorer (db &d) : internal_explorer (d) { };

  // Looks up an entry specified by key in the database. Returns
  // pointer to the actual database value. Returns NULL if no such
  // entry is present (either key in not in the database or there is
  // no such entry kind associated with key.
  typename kind::data_type *find (const typename db_key_type::generic_key::key_type key) 
  {
    return internal_explorer.find (key);
  } 

  // Looks up an entry specified by key in the database. Returns
  // pointer to the actual database value. Returns NULL if no such
  // entry is present (either key in not in the database or there is
  // no such entry kind associated with key.
  typename kind::data_type *find (const db_basic_key key) 
  {
    return internal_explorer.find (key);
  } 

  // Returns pointer to the corresponding data value.
  typename kind::data_type &get (const typename db_key_type::generic_key::key_type key)
  {
    typename kind::data_type *d = internal_explorer.find (key);
    assert (d != NULL);
    return *d;
  }

  typename kind::data_type &get (db_basic_key key) { return get (this->get_key (key)); }
};


// The actual kernel database is a singleton pattern.
class kernel_db_singleton : public db
{
private:
  static kernel_db_singleton *single_instance;

public:
  static kernel_db_singleton *get_instance ()
  {
    if (single_instance == NULL)
      single_instance = new kernel_db_singleton;
    
    return single_instance;
  }
      
protected:
  kernel_db_singleton () { };

public:
};


// kernel_db is used to access the kernel database instance.
#define kernel_db (*kernel_db_singleton::get_instance ())



#endif /* ifdef KERNEL */
#endif
