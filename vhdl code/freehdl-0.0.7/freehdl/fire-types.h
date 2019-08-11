// -*- C++ -*-

#ifndef FREEHDL_FIRE_TYPES_H
#define FREEHDL_FIRE_TYPES_H

#include <iostream>

#include <freehdl/tree-supp.h>

typedef unsigned char IR_Character;

typedef tree_kind IR_Kind;

const IR_Kind IR_INVALID = NULL;

enum IR_SignalKind {
  IR_NO_SIGNAL_KIND,
  IR_REGISTER_KIND,
  IR_BUS_KIND
};

enum IR_Mode {
  IR_UNKNOWN_MODE,
  IR_IN_MODE,
  IR_OUT_MODE,
  IR_INOUT_MODE,
  IR_BUFFER_MODE,
  IR_LINKAGE_MODE
};

enum IR_Pure {
  IR_UNKNOWN_PURE,
  IR_PURE_FUNCTION,
  IR_IMPURE_FUNCTION,
  IR_PURE_PROCEDURAL,
  IR_IMPURE_PROCEDURAL
};

enum IR_Direction {
  IR_UNKNOWN_DIRECTION,
  IR_DIRECTION_UP,
  IR_DIRECTION_DOWN
};

enum IR_DelayMechanism {
  IR_UNKNOWN_DELAY,
  IR_INERTIAL_DELAY,
  IR_TRANSPORT_DELAY
};

enum IR_StaticLevel {
  IR_NOT_STATIC,
  IR_GLOBALLY_STATIC,
  IR_LOCALLY_STATIC
};

struct IIR_Root;
typedef IIR_Root IIR;
typedef IIR *pIIR;

// XXX - better use some ready made string class from STL here.  Eric?

struct IR_String {
  IR_String (const IR_Character *chars, int len);
  IR_String (const char *chars);
  IR_String (const IR_String &str);
  ~IR_String ();

  IR_String &operator= (const IR_String &str);

  int len ()
  {
    return rep->len;
  }

  IR_Character operator[] (int i)
  {
    return rep->chars[i];
  }

  char *to_chars ();
  char *to_chars_no_check ()
  {
    return (char *)rep->chars;
  }

private:
  struct strrep {
    int len;
    unsigned int ref_count;
    IR_Character chars[1];
  };
  strrep *rep;
};

std::ostream& operator<< (std::ostream &o, IR_String &str);

// printers for tree_print

void fire_print_int (void *mem);
void fire_print_bool (void *mem);
void fire_print_string (void *mem);
void fire_print_IR_String (void *mem);

#endif
