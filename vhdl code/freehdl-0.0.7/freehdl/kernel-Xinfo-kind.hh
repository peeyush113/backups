#ifndef FREEHDL_KERNEL_XINFO_KIND_H
#define FREEHDL_KERNEL_XINFO_KIND_H


/* *****************************************************************
 * This file contains types and functions needed to store additional
 * information about objects created by the generated code. E.g., some
 * additional information about type_info instances are maintained
 * using this function. As this additional information is rarely used
 * it is *not* directly put into the corresponding type_info classes
 * but stored in an additional class referenced by the type info
 * class.
 * **************************************************************** */

/* The kind of a Xinfo data set is determined by Xinfo_kind. Each
 * Xinfo_kind consists of a major_id and an minor_id. The major id
 * defines the object group (e.g. process, entit/architecture,
 * package, type) while the minor_id determines a subelement of an
 * object group. E.g. major_id might be set to "type" and minor_id
 * might be set to "array type". */

class Xinfo_kind {
  // Note that the major and minor id's are actually NOT stored in
  // major_id_types or minor_id_types. Instead each id value is stored
  // into a char variable in order to save memory. Note that g++ will
  // use 4 bytes to hold each enumeration value which obviously is an
  // overkill in this case! We also provide a set of operators to
  // seamlessly convert between the enumeration ids and short
  // variables.
  char major_id_value;
  char minor_id_value;
public:
  // Note that enumeration types in C++ are numbered starting with #0
  enum major_id_types { 
    ID_PROCESS, ID_ENTITY_ARCHITECTURE, ID_PACKAGE, ID_PACKAGE_BODY, ID_OBJECT, ID_TYPE_INFO,
    ID_ANONYMOUS_TYPE_INFO, ID_SOURCE_FILE
  };
  enum minor_id_types { 
    ID_DEFAULT, ID_CONSTANT, ID_SIGNAL, ID_VARIABLE, ID_GENERIC, 
    ID_INTEGER_INFO, ID_ENUM_INFO, ID_FLOAT_INFO, ID_PHYSICAL_INFO, ID_RECORD_INFO, 
    ID_ARRAY_INFO, ID_FILE_INFO, ID_ACCESS_INFO, ID_VHDLFILE_INFO
  };
  Xinfo_kind(const major_id_types ma, const minor_id_types mi = ID_DEFAULT) {
    major_id_value = (char)ma;
    minor_id_value = (char)mi;
  }
  major_id_types get_major_id() const { return major_id_types(major_id_value); }
  minor_id_types get_minor_id() const { return minor_id_types(minor_id_value); }
  void set_major_id(const major_id_types val) { major_id_value = (char)val; }
  void set_minor_id(const minor_id_types val) { minor_id_value = (char)val; }
};

typedef short packed_Xinfo_kind;

// Pack a Xinfo_kind into a short variable
inline packed_Xinfo_kind pack(const Xinfo_kind &id) { 
  return ((((int)id.get_major_id()) << 8) | (int)id.get_minor_id()); 
}

// Create a Xinfo_kind from a short variable
inline Xinfo_kind unpack(const packed_Xinfo_kind s) { 
  return Xinfo_kind(Xinfo_kind::major_id_types((s >> 8) & 0xff), Xinfo_kind::minor_id_types(s & 0xff)); 
} 

#endif
