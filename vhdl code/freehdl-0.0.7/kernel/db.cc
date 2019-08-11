#define KERNEL // Include internal kernel definitions

using namespace std;
#include <freehdl/kernel-db.hh>


// A data base of the kernel. Stores information about various items
// (processes, signals, ...). Only those information are put into the
// data base that are rarely used. As a result, the actual data
// structures associated with the processes, signals, ... are more
// slim. This improves processor cache performance.  Note that the
// actual kernel database is a singleton pattern.

kernel_db_singleton *kernel_db_singleton::single_instance = NULL;

