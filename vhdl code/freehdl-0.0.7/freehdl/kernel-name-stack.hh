#ifndef FREEHDL_KERNEL_NAME_STACK_H
#define FREEHDL_KERNEL_NAME_STACK_H

#include <string>

using namespace std;

#define NAME_STACK_INCREMENT 10


// Class used to store and maintain VHDL instance names
class name_stack {
  string **stack;
  int stack_pointer;
  int size;
  string buffer;
  void set_stack_element(int i, const string str);
public:
  name_stack();
  ~name_stack();
  // Pushes a string at the top of the name stack
  name_stack &push(const string str="");
  // Pushes a string representation of i (enclosed in
  // "()") on top of the name stack
  name_stack &push(const int i);
  // Removes top entry of the name stack
  name_stack &pop();
  // Replaces current top entry with str
  name_stack &set(const string str);
  // Replaces cuurent top entry with a string representation
  // of i (enclosed in "()")
  name_stack &set(const int i);
  // Returns a string which is constructed by appending all
  // stack entries
  string &get_name();
  // Returns the top stack elemement as a string
  string &get_top();
};


// The name stack instance used to construct VHDL instance names
extern name_stack instance_name;

#endif
