#ifndef FREEHDL_KERNEL_WINFO_ITEM_H
#define FREEHDL_KERNEL_WINFO_ITEM_H

#include <freehdl/kernel-classes.hh>


class winfo_item {
  union _data { int wait_id; winfo_item *wii; };
  _data data;
public:
  winfo_item() { data.wait_id = 0; data.wii = NULL; }
  operator int() { return data.wait_id; }
  operator winfo_item*() { return data.wii; }
  winfo_item &operator=(int id) { 
    data.wait_id = id; return *this;
  }
  winfo_item &operator=(winfo_item *a) { 
    data.wii = a; return *this;
  }
};

#endif
