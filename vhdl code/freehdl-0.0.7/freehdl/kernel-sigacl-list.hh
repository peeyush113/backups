#ifndef FREEHDL_KERNEL_SIGACL_LIST_H
#define FREEHDL_KERNEL_SIGACL_LIST_H

#include <freehdl/kernel-classes.hh>
#include <freehdl/kernel-sig-info.hh>
#include <freehdl/kernel-acl.hh>


// sigacl_list is used to construct a list of
// signal_info_base pointer - acl pointer pairs.
// Currently not used
class sigacl_list {
 public:
  struct _items {
    sig_info_base *signal;
    acl *aclp;
  };
  int count;
  _items *list;
  sigacl_list(int size);
  ~sigacl_list();
  void add(sig_info_base *s, acl *a = NULL);
};


#endif
