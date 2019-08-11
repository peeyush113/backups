#ifndef FREEHDL_KERNEL_XINFO_DATA_DESCRIPTOR_H
#define FREEHDL_KERNEL_XINFO_DATA_DESCRIPTOR_H

#ifdef KERNEL
/* ****************************************************************
 * Some definitions required by the kernel only but not by the
 * automatically generated code.
 * **************************************************************** */

/* Read in Xinfo_kind class. The kind of a Xinfo data set is
 * determined by Xinfo_kind. Each Xinfo_kind consists of a major_id
 * and an minor_id. The major id defines the object group
 * (e.g. process, entit/architecture, package, type) while the
 * minor_id determines a subelement of an object group. E.g. major_id
 * might be set to "type" and minor_id might be set to "array
 * type". */
#include <freehdl/kernel-db.hh>
#include <freehdl/kernel-Xinfo-kind.hh>


// This *base* class includes all the entries which are common to all
// descriptor items. From this base class three classes are derived:
// Xinfo_signal_descriptor, Xinfo_scope_descriptor and
// Xinfo_plain_object_descriptor. Note that the base class is actually
// virtual!
struct Xinfo_data_descriptor {
  // Determines the kind of the object the data set descriptor is
  // describing
  Xinfo_kind object_kind_id;
  // Points to the actual object 
  void *object_reference;
  // Long name of the scope this object has been declared
  // within. E.g., if the object has been defined in library "lib",
  // entity "ent" then this string will be set to ":lib:ent". In case
  // of registering a source file name source_path_name will reference
  // the file name.
  union { const char *scope_long_name; const char *source_path_name; };
  // Name of the object. E.g., is the current object describes a
  // constant named "const" then it is set to "const".
  const char *name; 
  // "scope_reference" will point to the object representing the 
  // declaration region (scope) the current object is declared within.
  void *scope_reference;
  // Constructor
  Xinfo_data_descriptor(void *mor, Xinfo_kind id, const char *sln, const char *n, 
			void *sr) :
    object_kind_id(id), object_reference(mor), scope_long_name(sln), name(n), 
    scope_reference(sr) {};
  // Check whether the current instance is actually of a specific
  // class
  bool is_Xinfo_scope_descriptor() const {
    return object_kind_id.get_major_id() != Xinfo_kind::ID_OBJECT && 
      object_kind_id.get_major_id() != Xinfo_kind::ID_SOURCE_FILE &&
      object_kind_id.get_major_id() != Xinfo_kind::ID_TYPE_INFO;
  }
  bool is_Xinfo_signal_descriptor() const {
    return object_kind_id.get_major_id() == Xinfo_kind::ID_OBJECT && 
      object_kind_id.get_minor_id() == Xinfo_kind::ID_SIGNAL;
  }
  bool is_Xinfo_plain_object_descriptor() const {
    return object_kind_id.get_major_id() == Xinfo_kind::ID_OBJECT && 
      object_kind_id.get_minor_id() != Xinfo_kind::ID_SIGNAL;
  }
  bool is_Xinfo_type_info_descriptor() const {
    return object_kind_id.get_major_id() == Xinfo_kind::ID_TYPE_INFO;
  }
  bool is_Xinfo_anonymous_type_info_descriptor() const {
    return object_kind_id.get_major_id() == Xinfo_kind::ID_ANONYMOUS_TYPE_INFO;
  }
  bool is_Xinfo_source_file_desriptor() const {
    return object_kind_id.get_major_id() == Xinfo_kind::ID_SOURCE_FILE;
  }
};

// The descriptor used to store information about "scopes"
// (entity/architectures, packages, package bodies, processes, ...)
struct Xinfo_scope_descriptor : public Xinfo_data_descriptor {
  // Instance name of the object (last part). Note that if the
  // current object is a constant or variable or ... then 
  // "instance_short_name" and "name" will point to the same string. 
  // However, if the obejct is e.g. an entity/architecture pair then 
  // "name" will be the name of the entity while "instance_short_name" 
  // will be the name given to the component given during instantiation!
  const char *instance_short_name;
  // Constructor
  Xinfo_scope_descriptor(void *mor, Xinfo_kind id, const char *sln, const char *n, 
			 const char *isn, void *sr) : 
    Xinfo_data_descriptor(mor, id, sln, n, sr), instance_short_name(isn) { };
};

// Descriptor used to store information about signals
struct Xinfo_signal_descriptor : public Xinfo_data_descriptor {
  // Constructor
  Xinfo_signal_descriptor(void *mor, const char *sln, const char *n, void *sr) :
    Xinfo_data_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_OBJECT, Xinfo_kind::ID_SIGNAL), 
			  sln, n, sr) { };
};

// Descriptor to store information all other none signal objects
// (variables, constants, generic parameters, ...)
struct Xinfo_plain_object_descriptor: public Xinfo_data_descriptor {
  // Type of the object. Note that from the plain pointer to a
  // variable or constant the type cannot be derived. Hence, it must
  // be stored here.
  type_info_interface *type;
  // Initial value member, which is used to store the initial value of
  // an object type.
  void *initial_value;
  // Constructor
  Xinfo_plain_object_descriptor(void *mor, Xinfo_kind::minor_id_types min_id, const char *sln, 
				const char *n, type_info_interface *t, void *sr) :
    Xinfo_data_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_OBJECT, min_id), sln, n, sr), 
    type(t), initial_value(t->clone(mor)) { };
};

// Descriptor used to store information about types
struct Xinfo_type_info_interface_descriptor : public Xinfo_data_descriptor {
  // Long name of type. E.g., if the type "mytype" has been defined in
  // library "lib", entity "ent" then this string will be set to
  // ":lib:ent:mytype".
  const char *long_name;
  void determine_and_set_minor_id(type_id id) {
    switch (id) {
    case INTEGER: object_kind_id.set_minor_id(Xinfo_kind::ID_INTEGER_INFO); break;
    case ENUM: object_kind_id.set_minor_id(Xinfo_kind::ID_ENUM_INFO); break;
    case FLOAT: object_kind_id.set_minor_id(Xinfo_kind::ID_FLOAT_INFO); break;
    case PHYSICAL: object_kind_id.set_minor_id(Xinfo_kind::ID_PHYSICAL_INFO); break;
    case RECORD: object_kind_id.set_minor_id(Xinfo_kind::ID_RECORD_INFO); break;
    case ARRAY: object_kind_id.set_minor_id(Xinfo_kind::ID_ARRAY_INFO); break;
    case ACCESS: object_kind_id.set_minor_id(Xinfo_kind::ID_ACCESS_INFO); break;
    case VHDLFILE: object_kind_id.set_minor_id(Xinfo_kind::ID_VHDLFILE_INFO); break;
    }
  }
  // Constructor
  Xinfo_type_info_interface_descriptor(void *mor) :
    Xinfo_data_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_ANONYMOUS_TYPE_INFO, Xinfo_kind::ID_DEFAULT), 
			  NULL, NULL, NULL),
    long_name(NULL) { 
    type_info_interface *info = (type_info_interface*)mor;
    determine_and_set_minor_id(info->id);
  };
  Xinfo_type_info_interface_descriptor(void *mor, const char *sln, const char *ln, const char *n, void *sr) :
    Xinfo_data_descriptor(mor, Xinfo_kind(Xinfo_kind::ID_TYPE_INFO, Xinfo_kind::ID_DEFAULT), sln, n, sr),
    long_name(ln) { 
    type_info_interface *info = (type_info_interface*)mor;
    determine_and_set_minor_id(info->id);
  };
};


// Define a new database entry type.
typedef Xinfo_data_descriptor* Xinfo_data_descriptor_p;
define_db_entry_type(Xinfo_data_descriptor_p, Xinfo_data_descriptor_p);

#endif
#endif
