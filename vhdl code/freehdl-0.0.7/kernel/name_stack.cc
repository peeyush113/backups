#include <stdlib.h>
#include <stdio.h>
#include <freehdl/kernel-error.hh>
#include <freehdl/kernel-name-stack.hh>


name_stack instance_name;


name_stack::name_stack() {
  size = NAME_STACK_INCREMENT;
  stack = (string**)malloc(sizeof(string*)*NAME_STACK_INCREMENT);
  for (int i = 0; i < size; i++) stack[i] = NULL;
  stack_pointer = 0;
}


name_stack::~name_stack() {
  for (int i = 0; i < size; i++)
    if (stack[i] != NULL)
      delete stack[i];
  free(stack);
  stack_pointer = size = 0;
}


void name_stack::set_stack_element(int i, const string str) {
  if (i >= size) {
    size += NAME_STACK_INCREMENT;
    stack = (string**)realloc(stack, size * sizeof(string*));
    for (int i = size - NAME_STACK_INCREMENT; i < size; i++) stack[i] = NULL;
  }
  if (stack[i] != NULL) 
    *stack[i] = str;
  else
    stack[i] = new string(str);
}


name_stack &name_stack::push(const string str) {
  set_stack_element(stack_pointer++, str);
  return *this;
}


name_stack &name_stack::push(const int i) {
  char buffer[20];
  sprintf(buffer, "%i", i);
  set_stack_element(stack_pointer++, "(" + string(buffer) + ")");
  return *this;
}


name_stack &name_stack::pop() {
  stack_pointer--;
  if (stack_pointer < 0)
    error("Name stack underflow!");
  return *this;
}


name_stack &name_stack::set(const string str) {
  set_stack_element(stack_pointer - 1, str);
  return *this;
}


name_stack &name_stack::set(const int i) {
  char buffer[20];
  sprintf(buffer, "%i", i);
  set_stack_element(stack_pointer - 1, "(" + string(buffer) + ")");
  return *this;
}


string &name_stack::get_name() {
  buffer = "";
  for (int i = 0; i < stack_pointer; i++) buffer = buffer + *stack[i];
  return buffer;
}


string &name_stack::get_top() {
  return *stack[stack_pointer - 1];
}

