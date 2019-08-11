#ifndef FREEHDL_KERNEL_MAP_LIST_H
#define FREEHDL_KERNEL_MAP_LIST_H

#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-list.hh>
#include <freehdl/kernel-classes.hh>
#include <freehdl/kernel-acl.hh>
#include <freehdl/kernel-sig-info.hh>

using namespace std;
//using namespace __gnu_cxx;

// A signal_link instance describes the connection
// between a formal and actual SIGNAL
struct signal_link {
  // The following two members determine the part of 
  // the formal signal which is addressed by this 
  // link element
  acl *formal_aclp;
  string formal_name;
  // Mode of formal parameter (in, out, inout, buffer or linkage)
  char formal_mode; 
  // To represent f1(formal_sig) => actual_sig
  // If a conversion function is used in an association list, then
  // this conversion function must be executed on control of the kernel.
  // However, the kernel does not know this function at kernel compile time
  // Moreover, it does not even know it parameter and return value types
  void (*wrapper_fn_formal)(void *dest, void *data);

  // The next four members determine the part of the
  // actual signal which is addressed by the map
  // operation. Note, if the formal is of mode IN then
  // the actual can be a constant expression. In this
  // case value points to this expression and type
  // describes its type.
  acl *actual_aclp;
  sig_info_base *actual_signal;	// equal to NULL is that 
  // actual is an expression!
  void *value;	// Only used if actual is an expression
  // Otherwies value is set to NULL.
  type_info_interface *type;	// Only used if actual is 
  // an expression. Otherwise equal to NULL.
  // To represent formal_sig => f2(actual_sig)
  void (*wrapper_fn_actual)(void *dest, void *data);

  type_info_interface *get_actual_type();
  void *get_actual_value();
  acl *get_formal_aclp() { return formal_aclp; }
  acl *get_actual_aclp() { return actual_aclp; }
  
  // Constructor. Initializes formal_aclp, actual_aclp,
  // actual_signal, value, and type.
  signal_link(); 
  // Destructor. Removes formal_aclp, actual_aclp, and
  // value. 
    ~signal_link();
};


// A generic_link instance describes the connection
// between a formal generic parameter and actual
struct generic_link {
  // The following two members determine the part of 
  // the formal generic parameter which is addressed by 
  // this generic_link instance
  acl *formal_aclp;
  string formal_name;
  // value points to value the generic parameter is 
  // associated with and type points to the type info
  // instance.
  void *value;	// Points to a local copy of the generic value
  type_info_interface *type;	// So is the type...

  type_info_interface *get_actual_type();
  void *get_actual_value();
  acl *get_formal_aclp() { return formal_aclp; }
  acl *get_actual_aclp() { return NULL; }
  
  // Constructor. Initializes formal_aclp, actual_aclp,
  // value, and type.
  generic_link(); 
  // Destructor. Removes formal_aclp, actual_aclp, and
  // value. 
  ~generic_link();
};


class map_list {
 public:

  //////////////////////////////////////////////////////
  // Members of map_list
  //////////////////////////////////////////////////////

  simple_list<signal_link*> signal_maplist;
  simple_list<generic_link*> generic_maplist;

  //////////////////////////////////////////////////////
  // Methods of map_list
  // Note, all signal_map resp. generic_map methods 
  // create a copy of the acls!!! 
  //////////////////////////////////////////////////////

  // Adds a generic link to the generic_map list
  // It has only one connection with expression.
  void generic_map(const char *formal, acl *formal_acl,
		   const void *value, type_info_interface *type);

  // Adds a signal link to the signal_map list
  void signal_map(const char *formal, acl *formal_acl, 
		  const char formal_mode, sig_info_base *actual, 
		  acl *actual_acl);

  // the mapping with an expression
  void signal_map(const char *formal, acl *formal_acl,
		  const char formal_mode,  const void *value, 
		  type_info_interface *type);

  // the mapping with open
  void signal_map(const char *formal, acl *formal_acl, 
		  const char formal_mode);

  // the mapping with formal convert function
  void signal_map(const char *formal, acl *formal_acl,
		  const char formal_mode, 
		  void (*wrapper_fn_formal)(void *,void *),
		  sig_info_base *actual, acl *actual_acl);

  // the mapping with actual convert function
  void signal_map(const char *formal, acl *formal_acl,
		  const char formal_mode, sig_info_base *actual, 
		  acl *actual_acl,
		  void (*wrapper_fn_actual)(void *,void *));

  // the mapping with formal/actual convert function
  void signal_map(const char *formal, acl *formal_acl,
		  const char formal_mode,
		  void (*wrapper_fn_formal)(void *,void *),
		  sig_info_base *actual, acl *actual_acl,
		  void (*wrapper_fn_actual)(void *,void *));

  // Constructor
  map_list();

  // Destructor
  ~map_list();

  // Reset map_list instance so that it may be re-used
  void reset();
};


// global temproary map list object 
extern map_list tmpml;

#ifdef KERNEL
// ************************************************************************
// The following functions are used by the kernel only. Hence, they are
// made invisible to code emitted from hte compiler in order to reduce
// compile time
// ************************************************************************

#include <list>

#if !defined __GNUC__ || __GNUC__ != 2
#include <ext/hash_map>
#else
#include <hash_map>
#endif

#include <freehdl/kernel-util.hh>

// ***************************************************************************
// The query methods are used by the kernel or the generated code 
// to search for a specific generic parameter respectively 
// signal formal. Note, severals signal_link respectively
// generic_link instances may exist for formals of 
// composite type. Hence, the query functions store
// in "result" a LIST of appropriate pointers.
// ***************************************************************************

// Returns in result a list of pointers to the generic_link
// instances with formal_name = name. Returns true
// if at least one entry was found.
bool query_generic(map_list *mlist, list<generic_link*> &result, const string &name);
  
// Returns in result a list of pointers to the signal_link
// instances with formal_name = name. Returns true
// if at least actual was found.
bool query_signal(map_list *mlist, list<signal_link*> &result, const string &name);


// Calculates the index range for an unconstrained formal array port
// or generic parameter. The bounds are determined from the index type
// of the array respectively the index values which were used in the
// association list. Returns -1 if an error occured, 0 otherwise.
// Returns the bound in "left" and "right". Note thet left, right and
// dir are vectors as a port or gemeric may be of an muti-dimensionale
// type. The first vector element will correspond with index 1, the
// nexxt with index 2, .... "name" is the name of the formal, "ainfo"
// the info instance of the formal and "mlist" a list of elements
// associated with the formal.
int 
get_unconstrained_port_array_bounds(list<signal_link*> *mlist, const string &name, 
				    array_info *ainfo, vector<int> &left, vector<range_direction> &dir, 
				    vector<int> &right);

int 
get_unconstrained_generic_array_bounds(list<generic_link*> *mlist, const string &name, 
				       array_info *ainfo, vector<int> &left, vector<range_direction> &dir, 
				       vector<int> &right);


// Creates an new array_info instance for an unconstrained array. The
// array bounds are extracted from the left, dir and right vectors
// which are usually determined by function
// get_unconstrained_*_array_bounds. unc_array_info points to the
// corressponding array_info of the unconstrained array.
array_info *
create_array_info_for_unconstrained_link_array(array_info *unc_array_info,
					       vector<int> &left, vector<range_direction> &dir, 
					       vector<int> &right, const int rc=-1);


// ***************************************************************************
// Data structure to store mapping links between port signals and normal
// and/or port signals.
// ***************************************************************************


// To support multiple fathers of a signal (a composite signal)
// which represents the partial/direct/indirect signal interconnection
// direct mapping : formal => actual
// partial mapping : formal(1 downto 0) => actual(0 downto 1) or actual.field
// indirect mapping : f1(formal) => f2(actual)
struct fl_link {
  // Determines which part of the formal signal is addressed
  acl *formal_aclp;
  // Determines which part of the actual signal is addressed
  acl *actual_aclp;
  // wrapper function to support conversion function of formal/actual signal
  void (*wrapper_fn_formal)(void *dest, void *data);
  void (*wrapper_fn_actual)(void *dest, void *data);
  // Points to the actual signal
  sig_info_base *actual;
  fl_link() { 
    formal_aclp = actual_aclp = NULL; 
    wrapper_fn_formal = wrapper_fn_actual = NULL;
    actual = NULL;
  }
  fl_link(const fl_link &m) {
    formal_aclp = m.formal_aclp->clone();
    actual_aclp = m.actual_aclp->clone();
    wrapper_fn_formal = m.wrapper_fn_formal;
    wrapper_fn_actual = m.wrapper_fn_actual;
    actual = m.actual;
  }
  ~fl_link() {
    if (formal_aclp != NULL) delete formal_aclp;
    if (actual_aclp != NULL) delete actual_aclp;
  }
};


typedef hash_map<sig_info_base *, list<fl_link>, pointer_hash<sig_info_base *> > port_signal_link_map_t;

// Stores the father signal(s) of port signals
extern port_signal_link_map_t port_signal_link_map;

#endif

#endif
