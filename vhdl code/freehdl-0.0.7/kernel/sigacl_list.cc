#include <freehdl/kernel-sigacl-list.hh>


sigacl_list::sigacl_list(int size) {
  count = 0;
  list = new _items[size];
}


sigacl_list::~sigacl_list() {
  if (list == NULL) return;
  for (int i = 0; i < count; i++)
    if (list[i].aclp != NULL)
      delete list[i].aclp;
  delete[] list;
}


void
sigacl_list::add(sig_info_base *s, acl *a) {
  list[count].signal = s;
  list[count].aclp = a->clone();
  count++;
}


