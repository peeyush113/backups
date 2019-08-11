#define KERNEL
#include <freehdl/kernel-util.hh>
#include <freehdl/kernel-persistent-cdfg-dump.hh>
#include <freehdl/kernel-persistent-dump.hh>


buffer_stream register_cdfg_tmp_buffer;

/* Convert an integer value into a string */
template <class T>
inline string
cdfg_to_string(T i)
{
  return to_string (i);
}


inline string
cdfg_to_string(double i)
{
  string result = to_string (i);

  for (unsigned int i = 0; i < result.length(); i++)
    if (result [i] == 'e' ||
	result [i] == 'E')
      result [i] = 'l';

  return result;
}


//***********************************************************************************
// This function writes information about type_info_interface elements
//***********************************************************************************

template<class T>
string cdfg_get_range(T *type_info)
{
  return  string("(list range ") + cdfg_to_string(type_info->left_bound)
    + (type_info->left_bound < type_info->right_bound? " to " : " downto ")
    + cdfg_to_string(type_info->right_bound) + ")";
}


string cdfg_get_range(array_info *type_info)
{
  return string("(list range ") + cdfg_to_string(type_info->left_bound)
    + (type_info->index_direction == to? " to " : " downto ")
    + cdfg_to_string(type_info->right_bound) + ")";
}


string
get_cdfg_type_info_interface_definition(type_info_interface *type_info,
					list<Xinfo_data_descriptor*> &xinfo_desc)
{
  string get_cdfg_type_info_interface_descriptor(type_info_interface *,	
						 list<Xinfo_data_descriptor*> &);
  string result;

  switch(type_info->id)
    {
      //  array_info
    case ARRAY:
      {
	array_info *ainfo = (array_info*)type_info;
	result += string("'(array-type ") + get_cdfg_type_info_interface_descriptor(ainfo->index_type, xinfo_desc) +" " 
	  + cdfg_get_range(ainfo) + " " + cdfg_to_string(ainfo->length) + " " 
	  + get_cdfg_type_info_interface_descriptor(ainfo->element_type, xinfo_desc) + ")";
	break;
      }
      //  record_info
    case RECORD:
      {
	record_info *rinfo = (record_info*)type_info;
	result += string("'(record-type");
	for (int i = 0; i < rinfo->record_size; i++)
	  result += " (\"" + string(rinfo->element_names[i]) + "\" " 
	    + get_cdfg_type_info_interface_descriptor(rinfo->element_types[i], xinfo_desc) + ")";
	result += ")";
	break;
      }
      //  enum_info type
    case ENUM:
      {
	enum_info_base *ainfo = (enum_info_base*)type_info;
	result += string("'(enum-type ") + cdfg_get_range(ainfo) + " ";
	result += "(";
	for (int i = ainfo->left_bound; i <= ainfo->right_bound; i++) {
	  const char *str = ainfo->values[i];
	  result += "\"";
	  while (*str != '\0') {
	    switch (*str) {
	    case '"': result += "\\\""; break;
	    case '\\': result += "\\\\"; break;
	    default: result += *str;
	    }
	    str++;
	  }
	  result += "\" ";
	}
	result += "))";
	break;
      }
      //  integer_info type
    case INTEGER:
      {
	integer_info_base *ainfo = (integer_info_base*)type_info; 
	result += string("'(integer-type ") + cdfg_get_range(ainfo) + ")";
	break;
      }
      //  float_info type
    case FLOAT:
      {
	float_info_base *ainfo = (float_info_base*)type_info;
	result += string("'(float-type ") + cdfg_get_range(ainfo) + ")";
	break;
      }
      //  physical_info type
    case PHYSICAL:
      {
	physical_info_base *ainfo = (physical_info_base*)type_info;
	result += string("'(physical-type ") + cdfg_get_range(ainfo) + " ";
	result += "(list ";
	for (int i = 0; i < ainfo->unit_count; i++)
	  result += string("(pair ") + ainfo->units[i] + " " + cdfg_to_string(ainfo->scale[i]) + ") ";
	result += "))";
	break;
      }
      // access_info type
    case ACCESS:
      {
	access_info_base *acinfo = (access_info_base*)type_info;
	result += string ("'(access-type ") + " "  
	  + get_cdfg_type_info_interface_descriptor(acinfo->designated_type_info, xinfo_desc) + ")";
	break;
      }
      // vhdlfile_info type
    case VHDLFILE:
      {
	vhdlfile_info_base *finfo = (vhdlfile_info_base*)type_info;
	result += string ("'(vhdlfile-type ") + " "  
	  + get_cdfg_type_info_interface_descriptor(finfo->type_info, xinfo_desc) + ")";
	break;
      }
    default: 
      error(-1, "Unknown type_info_interface");
      break;         
    }

  return result;
}


string
get_cdfg_type_info_interface_descriptor(type_info_interface *type_info,
					list<Xinfo_data_descriptor*> &xinfo_desc)
{
  string result;

  Xinfo_type_info_interface_descriptor *entry = get_type_registry_entry(type_info, xinfo_desc);
  if (entry != NULL)
    return "\"" + string(entry->long_name) + "\"";

  return get_cdfg_type_info_interface_definition(type_info, xinfo_desc);
}


string
get_cdfg_Xinfo_type_info_interface_descriptor(Xinfo_type_info_interface_descriptor* sdesc,
					      list<Xinfo_data_descriptor*> &xinfo_desc)
{
  // First, determine instance long name and scope long name of object
  string instance_long_name = get_instance_long_name(sdesc, xinfo_desc);
  string scope_long_name = string(sdesc->scope_long_name) + sdesc->name;

  string result = string("(create-type ") + "\"" + instance_long_name + "\" " 
    + "\"" + scope_long_name + "\" " 
    + get_cdfg_type_info_interface_definition((type_info_interface*)sdesc->object_reference, xinfo_desc) + ")";

  return result;
}


//**************************************************************************************************
// Write information about plain objects (constant, variable, generic
// but NOT signals) into a string using cdfg style syntax
//**************************************************************************************************


string
get_cdfg_Xinfo_signal_descriptor(Xinfo_signal_descriptor* sdesc, 
				 list<Xinfo_data_descriptor*> &xinfo_desc)
{
  string result; 

  // First, determine instance long name and scope long name of object
  string instance_long_name = get_instance_long_name(sdesc, xinfo_desc);
  string long_name = string(sdesc->scope_long_name) + sdesc->name;

  result = string("(create-signal ") + "\"" + instance_long_name + "\" "
    + "\"" + long_name + "\" " + get_cdfg_type_info_interface_descriptor(((sig_info_base*)sdesc->object_reference)->type, xinfo_desc) + ")";

  return result;
}

//**************************************************************************************************
// Write information about plain objects (constant, variable, generic
// but NOT signals) into a string using cdfg style syntax
//**************************************************************************************************


string
get_cdfg_Xinfo_plain_object_descriptor(Xinfo_plain_object_descriptor* sdesc, 
				       list<Xinfo_data_descriptor*> &xinfo_desc)
{
  string result; 

  Xinfo_kind::major_id_types major_id = sdesc->object_kind_id.get_major_id();
  Xinfo_kind::minor_id_types minor_id = sdesc->object_kind_id.get_minor_id();

  // First, determine instance long name and scope long name of object
  string instance_long_name = get_instance_long_name(get_registry_entry(sdesc->object_reference, xinfo_desc), xinfo_desc);
  string scope_long_name = string(sdesc->scope_long_name) + sdesc->name;

  // Get initial value of object
  register_cdfg_tmp_buffer.clean();
  string initial_value = "'()";
  if (sdesc->initial_value != NULL) {
    sdesc->type->print(register_cdfg_tmp_buffer, sdesc->initial_value, CDFG_PRINT_MODE);
    initial_value = register_cdfg_tmp_buffer.str();
  }

  switch(minor_id)
    {
    case Xinfo_kind::ID_CONSTANT:
      {
	result += string("(create-constant ") + "\"" + instance_long_name + "\" " 
	  + "\"" + scope_long_name + "\" " + get_cdfg_type_info_interface_descriptor(sdesc->type, xinfo_desc) 
	  + " " + initial_value + ")";
	break;
      }
    case Xinfo_kind::ID_VARIABLE:
      {
	result += string("(create-variable ") + "\"" + instance_long_name + "\" " 
	  + "\"" + scope_long_name + "\" " + get_cdfg_type_info_interface_descriptor(sdesc->type, xinfo_desc) 
	  + " " + initial_value + ")";
	break;
      }
    case Xinfo_kind::ID_GENERIC:
     {
	result += string("(create-generic ") + "\"" + instance_long_name + "\" " 
	  + "\"" + scope_long_name + "\" " + get_cdfg_type_info_interface_descriptor(sdesc->type, xinfo_desc) 
	  + " " + initial_value + ")";
       break;
      }
    case Xinfo_kind::ID_DEFAULT: // belong to process, ..
      break;
    case Xinfo_kind::ID_RECORD_INFO:// not defined yet
      break;
    case Xinfo_kind::ID_FILE_INFO:// not defined yet
      break;
    case Xinfo_kind::ID_ACCESS_INFO:// not defined yet
      break;
    default: 
       error(-1, "Unknown Xinfo_Object");
      break;
    }

  return result;
}


//**********************************************************************************************
// Write scope information into a string using cdfg style syntax
//**********************************************************************************************
string
get_cdfg_Xinfo_scope_descriptor(Xinfo_scope_descriptor *sdesc, 
				list<Xinfo_data_descriptor*> &xinfo_desc)
{
  Xinfo_kind::major_id_types major_id = sdesc->object_kind_id.get_major_id();
  Xinfo_kind::minor_id_types minor_id = sdesc->object_kind_id.get_minor_id();

  string instance_long_name = get_instance_long_name(get_registry_entry(sdesc->object_reference, xinfo_desc), xinfo_desc);
  string scope_long_name = string(sdesc->scope_long_name != NULL? sdesc->scope_long_name : "") + sdesc->name;
  string result;

  switch (major_id) {
  case Xinfo_kind::ID_PROCESS:
    {
      result = "(create-process ";
      string escaped_scope_long_name;
      for (unsigned int i = 0; i < scope_long_name.length(); i++) {
	if (scope_long_name[i] == '\\' ||
	    scope_long_name[i] == ':' ||
	    scope_long_name[i] == '"' ||
	    scope_long_name[i] == '(' ||
	    scope_long_name[i] == ')')
	  escaped_scope_long_name += '\\';
	escaped_scope_long_name += scope_long_name[i];
      }
      return result + "\"" + instance_long_name + "\" \"" + scope_long_name + "\" " + escaped_scope_long_name + ")";
      break;
    }
  case Xinfo_kind::ID_ENTITY_ARCHITECTURE:
    {
      // Hack: currently no mapping description is generated...
      result = "(create-entity-architecture ";
      return result + "\"" + instance_long_name + "\" " + "\"" + scope_long_name + "\" (list))";
      break;
    }
  case Xinfo_kind::ID_PACKAGE:
    {
      result = "(create-package ";
      return result + "\"" + instance_long_name + "\" " + "\"" + scope_long_name + "\")";
      break;
    }
  case Xinfo_kind::ID_PACKAGE_BODY:
    {
      result = "(create-package-body ";
      return result + "\"" + instance_long_name + "\" " + "\"" + scope_long_name + "\")";
      break;
    }
  }
}


//**********************************************************************************************
// Write design information into file using a cdfg style syntax
//**********************************************************************************************
void 
write_cdfg_info_file(list<Xinfo_data_descriptor*> &xinfo_desc, ostream &os)
{
  // First, write out a list of lisp.cdfg files which directly or
  // indirectly referenced by the current design
  string included_cdfg_files = "(cdfg-files (list";
  for (list<Xinfo_data_descriptor*>::iterator it = xinfo_desc.begin(); it != xinfo_desc.end(); it++){
    if ((*it)->is_Xinfo_source_file_desriptor()) {
      string fn = (*it)->source_path_name;
      fn.erase(fn.rfind('.'));
      fn += ".cdfg.lsp";
      included_cdfg_files += " \"" + fn + "\"";
    }
  }
  included_cdfg_files += "))\n";
  os << included_cdfg_files;

  // Finally, write out remaining descriptor informations
  for (list<Xinfo_data_descriptor*>::iterator it = xinfo_desc.begin(); it != xinfo_desc.end(); it++){
    
    Xinfo_data_descriptor* s = (*it);
    
    // case one: Xinfo_scope. 
    if (s->is_Xinfo_scope_descriptor()){
      Xinfo_scope_descriptor* sdesc = (Xinfo_scope_descriptor*)s;
      os << get_cdfg_Xinfo_scope_descriptor(sdesc, xinfo_desc) << endl;
    }
    // case two: Xinfo_signal. This case is not yet good defined
    else if (s->is_Xinfo_signal_descriptor()){
      
      //Xinfo_signal_descriptor* sdesc = (Xinfo_signal_descriptor*)s;
      Xinfo_signal_descriptor* sdesc = (Xinfo_signal_descriptor*)s;
      os << get_cdfg_Xinfo_signal_descriptor(sdesc, xinfo_desc) << endl;
    }
    // case three:Xinfo_plain_object
    else if(s->is_Xinfo_plain_object_descriptor()) 
      {
	Xinfo_plain_object_descriptor* sdesc = (Xinfo_plain_object_descriptor*)s;
	os << get_cdfg_Xinfo_plain_object_descriptor(sdesc, xinfo_desc) << endl;
      }
    // case four: Xinfo_type_info
     else if(s->is_Xinfo_type_info_descriptor()) 
      {
	Xinfo_type_info_interface_descriptor* sdesc = (Xinfo_type_info_interface_descriptor*)s;
	os << get_cdfg_Xinfo_type_info_interface_descriptor(sdesc, xinfo_desc) << endl;
      }
    else {}
    
  }

  // Flush stream
  os.flush();
  
}



