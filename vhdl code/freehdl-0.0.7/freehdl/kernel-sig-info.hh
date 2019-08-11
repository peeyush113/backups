#ifndef FREEHDL_KERNEL_SIG_INFO_H
#define FREEHDL_KERNEL_SIG_INFO_H

#include <string>
#include <freehdl/kernel-classes.hh>
#include <freehdl/kernel-list.hh>
#include <freehdl/kernel-name-stack.hh>
#include <freehdl/std-standard.hh>


/*
 * Information flow of signals
 */
#define vIN  1
#define vOUT 2
#define vINOUT 3
#define vBUFFER 4
#define vLINKAGE 5

/* 
 * Some internal kernal flags
 */
#define IS_DUMPED 1

/*
 * Signal type of a signal
 */
#define vREGISTER 1
#define vBUS 2

/*
 * Signal kind types
 */
#define vPLAIN 0
#define vDELAYED 1
#define vTRANSACTION 2
#define vSTABLE 3
#define vQUIET 4
#define vALIAS 5

/*
 * Delay type
 */
#define vTRANSPORT 1
#define vINERTIAL 2


/******************************************************
 * Some definitions which are used by the kernel only 
 ******************************************************/
#ifdef KERNEL

#include <string>
#include <map>
#include <list>
#include <freehdl/kernel-source-descriptor.hh>
#include <freehdl/kernel-db.hh>

// Define some data types for the kernel data base. Note that some
// information about signals are not directly stored to the
// corresponding sig_info class bus put into the kernel data base in
// order to make sig_info more slim.
struct sig_info_extensions {
  // Scalar items the signal reader consists of
  int scalar_count;
  // List of drivers for the signal. Note that there is an entry in
  // the list for each scalar element which is driven by a process
  //simple_list<driver_info*> driver_list;

  char mode;
  char sig_type;
  char kind;

  // Instance name and name of the signal
  string instance_name, name;

  // A set of flags defined by the kernel to store kernel related
  // informations about this signal. This flag is intialized with 0.
  int kernel_flags;

  // Points to the next sig_info_base in the list. Used to get a list
  // of sig_info_base pointer according to their creation time.
  sig_info_base *next_sig_info;
};


define_db_key_type (sig_info_base*, sig_info_base_p);
define_db_entry_type (sig_info_extensions, sig_info_extension);


// signal_name_table is a hash tables (map) to associate signal names with
// the corresponding sign_info_base pointers.
typedef map<string, sig_info_base*, less<string> > signal_map_t;
extern signal_map_t signal_name_table;

// A stack which is used to keep track which signals has been created
// within which component during elaboration. Note that this stack
// does only include any valid data during elaboration. It is cleared
// before simulation starts.
typedef list<list<sig_info_base *> > signal_component_stack_t;
extern signal_component_stack_t signal_component_stack;

/******************************************************
 * End of internal kernel definitions    
 ******************************************************/
#endif


class reader_info;
class map_list;

/* sig info core class. This class holds all informations which are
 * needed by some functions that require only a subset of the entire
 * sig_info information set. */
struct sig_info_core {
  // Type of the signal
  type_info_interface *type;
  // array of reader_info pointers. There is a separate pointer
  // for each scalar element of the signal
  reader_info **readers;
};

/*
 * Base sig info class
 */
struct sig_info_base : public sig_info_core {
  // Points to the reader object of the signal
  void *reader_pointer; 

  /* Constructors */
  sig_info_base(name_stack &iname, const char *n, const char *sln,
		map_list *mlist, type_info_interface *ty, char dir, void *sr);
  sig_info_base(name_stack &iname, const char *n, const char *sln,
		type_info_interface *ty, char sty, void *sr);
  sig_info_base(name_stack &iname, const char *n, const char *sln,
		type_info_interface *ty, char attr, sig_info_base *base_sig,
		acl *aclp, vtime delay, void *sr);
  sig_info_base(name_stack &iname, const char *n, const char *sln,
		type_info_interface *ty, sig_info_base *aliased_sig,
		acl *aclp, void *sr);

  // Cleans up sig_info
  void cleanup ();
  // Inits the reader of a signal
  void init_reader(const void *src);
};



template<class T>class sig_info : public sig_info_base {
 public:
  /* Casts the reader pointer to the corresponding type */
  T &reader() { return *(T*)reader_pointer; }
  /* Constructor to instantiate a port signal */
  sig_info(name_stack &iname, const char *n, const char *sln, map_list *mlist,
	   type_info_interface *type, char direction, void *sr) : 
    sig_info_base(iname, n, sln, mlist, type, direction, sr) {};
  /* Constructor to instantiate "normal" signal */
  sig_info(name_stack &iname, const char *n, const char *sln,
	   type_info_interface *type, char sigtype, void *sr) :
    sig_info_base(iname, n, sln, type, sigtype, sr) {};
  /* Constructor to instantiate a signal kind attribute */
  sig_info(name_stack &iname, const char *n, const char *sln,
	   type_info_interface *type, char attr, sig_info_base *base_sig,
	   acl *aclp, vtime delay, void *sr) :
    sig_info_base(iname, n, sln, type, attr, base_sig, aclp, delay, sr) {};
  /* Constructor to instantiate a guard signal */
  sig_info(name_stack &iname, const char *n, const char *sln,
	   void *reader, void *sr) : 
    sig_info_base(iname, n, sln, reader, sr) {};
  /* Constructor to instantiate an alias signal */
  sig_info(name_stack &iname, const char *n, const char *sln,
	   type_info_interface *ty, sig_info_base *aliased_sig,
	   acl *aclp, void *sr) :
    sig_info_base (iname, n, sln, ty, aliased_sig, aclp, sr) {};
  /* Init the reader of the signal */
  void init(const T &value) { init_reader(&value); }
};


#endif
