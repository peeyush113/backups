
#include <freehdl/kernel-persistent-dump.hh>


//used to termine whether info is written in files
typemap type_info_map;
strmap str_map;

//*************************************************************************
//This function writes left and right boudries for defined type
//*************************************************************************
template<class T>
int fwrite_bounds(T &left, T &right, FILE* info_file)
{
  int result = 0;
  result += fwrite(&left, sizeof(T), 1, info_file);
  result += fwrite(&right, sizeof(T), 1, info_file);
  return result;
}

//***************************************************************************
// This routine verifies when a type_info_interface is written
//***************************************************************************
bool
verify_type_info(type_info_interface* type_info)
{
  if (type_info_map.begin() == type_info_map.end())
    return true;
  else {
    typemap::iterator it = type_info_map.find(type_info);
    if (it == type_info_map.end())
      return true;
    else
      return false;
  }

}


//--------------------------------------------------------------------------
//***************************************************************************
// This routine verifies when a string is written
//***************************************************************************
bool
verify_string(const char* ch)
{
  if (str_map.begin() == str_map.end())
    return true;
  else {
    strmap::iterator it = str_map.find(ch);
    if (it == str_map.end())
      return true;
    else
      return false;
  }

}


//-----------------------------------------------------------------------------
//This routine writes a string value in data file
//----------------------------------------------------------------------------

void
 write_value_string(FILE* info_file, const char* str_variable)
{
  const int length = strlen (str_variable);
  string str = str_variable;
  fwrite(&length, sizeof(int), 1, info_file);
  fwrite(str.c_str (), (length + 1), 1, info_file);
}

//***************************************************************************
//This routine writes scope_long_nam, name, instance_short_name and long_name, 
// and their pointers in a separate file.
//***************************************************************************

void write_string(FILE* string_file, const char* str_variable)
{
  if (!verify_string(str_variable))
    return;
  str_map[str_variable] = true;
  const int length = strlen(str_variable);
  string str = str_variable;
  fwrite(&str_variable, sizeof(char*), 1, string_file);
  fwrite(&length, sizeof(int), 1, string_file);
  fwrite(str.c_str (), (length+1), 1, string_file);
}

//*****************************************************************************
// This function writes need information  in an index file
//*****************************************************************************

void 
write_index_file(Xinfo_data_descriptor* ss, FILE* index_file, FILE* info_file, FILE* string_file)
{
  
  //first, write the major_id and minor_id of the elements
  packed_Xinfo_kind id = pack(ss->object_kind_id);
  fwrite(&id, sizeof(packed_Xinfo_kind), 1, index_file);
  //then writes the object_reference pointer
  fwrite(&ss->object_reference, sizeof(void*), 1,index_file);
  //next, write the scope_long_name, which represents the
  //instance_name.  Actually, only the string pointer is written into
  //the index file. The actual string is stored in the string file.
  fwrite(&ss->scope_long_name, sizeof(char*), 1,index_file);
  write_string(string_file,ss->scope_long_name);
  fwrite(&ss->name, sizeof(char*), 1,index_file);
  write_string(string_file,ss->name);
  // the next information to be written is scope_reference 
  fwrite(&ss->scope_reference, sizeof(void*), 1,index_file);
  // after, it tests the different presented cases based upon the defined functions.
  // The first case if the  object is a Xinfo_scope:
  if (ss->is_Xinfo_scope_descriptor())
    {
      Xinfo_scope_descriptor* s = (Xinfo_scope_descriptor*)ss;
      // then it writes its instance_short_name.
      fwrite(&s->instance_short_name, sizeof(char*), 1,index_file);
      write_string(string_file,s->instance_short_name);
      // The second case is when the object is Xinfo_signal:
    } else if(ss->is_Xinfo_signal_descriptor()) 
      {
	// until now nothing is to be written.
	Xinfo_signal_descriptor* s = (Xinfo_signal_descriptor*)ss;
	// The third case is when the object is Xinfo_plain_object either a signal
      } else if(ss->is_Xinfo_plain_object_descriptor())
	{
	  // until now nothing is to be written.
	  Xinfo_plain_object_descriptor* s = (Xinfo_plain_object_descriptor*)ss;
	  
	  // The last case is when this object is Xinfo_type_info
	}else if(ss->is_Xinfo_type_info_descriptor())
	  {
	    // until now nothing is to be written.
	    Xinfo_type_info_interface_descriptor* s = (Xinfo_type_info_interface_descriptor*)ss;
	    fwrite(&s->long_name, sizeof(char*), 1,index_file);
	    write_string(string_file, s->long_name);
	  }
  else {}
  //At the end we write the data file offset: address where the information
  //in the data file will be written
  long file_offset = ftell(info_file);
  fwrite(&file_offset, sizeof(long), 1,index_file);
}


//*********************************************************************************************************
//*********************************************************************************************************
//                This function writes anonimus_types  in the index file
//*********************************************************************************************************
//*********************************************************************************************************

void 
write_anonymous_types(Xinfo_data_descriptor* desc, FILE* index_file, FILE* info_file, type_info_interface* ainfo)
{
  
  Xinfo_kind::major_id_types major_id;
  major_id = desc->object_kind_id.get_major_id();
  if (major_id != Xinfo_kind::ID_OBJECT)
    return;
  // first, write the major_id and minor_id of the elements
  Xinfo_type_info_interface_descriptor* p = new 
    Xinfo_type_info_interface_descriptor(ainfo); 
  packed_Xinfo_kind id = pack(p->object_kind_id);
  fwrite(&id, sizeof(packed_Xinfo_kind), 1, index_file);
  // then write the object_reference pointer
  fwrite(&p->object_reference, sizeof(void*), 1,index_file);
  // after that write the offset of the info_file 
  long file_offset = ftell(info_file);
  fwrite(&file_offset, sizeof(long), 1,index_file);
  delete(p);
}


//***************************************************************************************************
//***************************************************************************************************
//                    Routine, which writes information in data file
//***************************************************************************************************
//***************************************************************************************************

template<class T>
int  write_ainfo_information(Xinfo_data_descriptor* sdesc, T& ainfo, FILE* info_file, FILE* index_file)
{
  int result = 0;
  // first, write the anonymous type of the current type_info_interface
  // elment and the its data file address( where will be written in the 
  // data file)
  type_info_interface* info = (type_info_interface*)ainfo;
  write_anonymous_types(sdesc,index_file, info_file, info);
  //after we write the information belonged to this 
  //type_info_interface element(id, & size):
  result += fwrite(&ainfo->id, sizeof(type_id), 1, info_file);
  //then, we write the type_info_interface of such element
  result += fwrite(&ainfo,sizeof(type_info_interface*),1, info_file);
  //we continue writing the left and right boundries of this 
  //element in the data file
  result += fwrite_bounds(ainfo->left_bound, ainfo->right_bound, info_file);
  return result;
}


//***********************************************************************************
// This function writes information of type_info_interface element
//***********************************************************************************

void 
write_type_info_interface(FILE* info_file,type_info_interface* info_type, 
			  Xinfo_data_descriptor* sdesc_type, FILE* index_file)
{
 
  if (!verify_type_info(info_type))
    return;
  type_info_map[info_type] = true;

  switch(info_type->id)
    {
      // first case is the array_info
    case ARRAY:
      {
	array_info *ainfo = (array_info*)info_type;
	write_type_info_interface(info_file, ainfo->element_type, sdesc_type, index_file);
	write_type_info_interface(info_file, ainfo->index_type, sdesc_type, index_file);
	write_ainfo_information(sdesc_type, ainfo, info_file, index_file);
	fwrite(&ainfo->length, sizeof(int), 1, info_file);
	fwrite(&ainfo->element_type, sizeof(type_info_interface*), 1, info_file);
	fwrite(&ainfo->index_type, sizeof(type_info_interface*), 1, info_file);
	break;
      }
      // second case is the enum_info type
    case ENUM:
      {

	enum_info_base *ainfo = (enum_info_base*)info_type;
	write_ainfo_information(sdesc_type, ainfo, info_file, index_file);
	const char* ch_enum = *ainfo->values;
	write_value_string(info_file, ch_enum);
	break;
      }
      // third case is the integer_info type
    case INTEGER:
      {
	integer_info_base *ainfo = (integer_info_base*)info_type; 
	write_ainfo_information(sdesc_type, ainfo, info_file, index_file);
	break;
      }
      // the fourth case is the float_info type
    case FLOAT:
      {
	float_info_base *ainfo = (float_info_base*)info_type;
	write_ainfo_information(sdesc_type, ainfo, info_file, index_file);
	break;
      }
      //the last case is the physical_info type
    case PHYSICAL:
      {
	physical_info_base *ainfo = (physical_info_base*)info_type;
	write_ainfo_information(sdesc_type, ainfo, info_file, index_file);
	const char* ch_physical = *ainfo->units;
	write_value_string(info_file, ch_physical);
	fwrite(ainfo->scale, sizeof(physical), 1, info_file);
	fwrite(&ainfo->unit_count, sizeof(int), 1, info_file);
	break;
      }
    default: 
      error(-1, "Unknown type_info_interface");
      break;         
    }
  
  return;
}


//************************************************************************************
// This function writes the data correspoding to type_info element in the info_file
//************************************************************************************

void 
Xinfo_write_type_info(Xinfo_type_info_interface_descriptor* sdesc, FILE* info_file, 
		      Xinfo_kind::minor_id_types& minor_id)
{
  switch(minor_id)
    {
      // first case is the array_info
    case Xinfo_kind::ID_ARRAY_INFO:
	 break;
      // second case is the enum_info type
    case Xinfo_kind::ID_ENUM_INFO:
	break;
      // third case is the integer_info type
    case Xinfo_kind::ID_INTEGER_INFO:
	break;
      // the fourth case is the float_info type
    case Xinfo_kind::ID_FLOAT_INFO:
	break;
      //the last case is the physical_info type
    case  Xinfo_kind::ID_PHYSICAL_INFO:
	break;
    case Xinfo_kind::ID_DEFAULT: // belong to process, ..
      break;
    case Xinfo_kind::ID_RECORD_INFO:// not defined yet
      break;
    case Xinfo_kind::ID_FILE_INFO:// not defined yet
      break;
    case Xinfo_kind::ID_ACCESS_INFO:// not defined yet
      break;
    default: 
      error(-1, "Unknown Xinfo_Type_Info");
      break;   
    }
}


//**************************************************************************************************
//**************************************************************************************************
// This function writes a data corresponding to a Xinfo_plain_object type in 
// the data file.
//**************************************************************************************************
//**************************************************************************************************

void 
Write_Xinfo_plain(Xinfo_plain_object_descriptor* sdesc, FILE* info_file, FILE* index_file, 
	    Xinfo_kind::minor_id_types& minor_id, FILE* string_file)
{

  sig_info_base* sig_info = (sig_info_base*)(sdesc->object_reference);
  buffer_stream str;
  str.clean();

  switch(minor_id)
    {
    case Xinfo_kind::ID_CONSTANT:
      {
	write_type_info_interface(info_file,sdesc->type, sdesc, index_file);
	write_index_file(sdesc,index_file, info_file, string_file);
	int num_of_byte= sdesc->type->binary_print(str,sdesc->initial_value);
	fwrite(&sdesc->type, sizeof(type_info_interface*), 1, info_file);
	fwrite(&num_of_byte, sizeof(int), 1, info_file);
	fwrite(&str, (num_of_byte+1), 1, info_file);
	break;
      }
    case Xinfo_kind::ID_SIGNAL:
      {
	write_type_info_interface(info_file,sig_info->type, sdesc, index_file);
	write_index_file(sdesc,index_file, info_file, string_file);
	int num_of_byte = sig_info->type->binary_print(str,sig_info->reader_pointer);
	fwrite(&sig_info->type, sizeof(type_info_interface*), 1, info_file);
	fwrite(&num_of_byte, sizeof(int), 1, info_file);
	fwrite(&str, (num_of_byte+1), 1, info_file);
	break;
      }	
    case Xinfo_kind::ID_VARIABLE:
      {
	write_type_info_interface(info_file,sdesc->type, sdesc, index_file);
	write_index_file(sdesc,index_file, info_file, string_file);
	fwrite(&sdesc->type, sizeof(type_info_interface*), 1, info_file);
	int num_of_byte = sdesc->type->binary_print(str,sdesc->initial_value);
	fwrite(&num_of_byte, sizeof(int), 1, info_file);
	fwrite(&str, (num_of_byte+1), 1, info_file);
	break;
      }
    case Xinfo_kind::ID_GENERIC:
     {
       write_type_info_interface(info_file,sdesc->type, sdesc, index_file);
       //fwrite(&file_offset, sizeof(long), 1,index_file);
       write_index_file(sdesc,index_file, info_file, string_file);
       int num_of_byte = sig_info->type->binary_print(str,sig_info->reader_pointer);
       fwrite(&sdesc->type, sizeof(type_info_interface*), 1, info_file);
       fwrite(&num_of_byte, sizeof(int), 1, info_file);
       fwrite(&str, (num_of_byte+1), 1, info_file);
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
}

//*****************************************************************************************
// This function write in the info_file the information correspoding to a major_id type
//*****************************************************************************************
void 
Write_Xinfo_data(Xinfo_data_descriptor* sdesc, FILE* info_file, FILE* index_file,
		Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id, FILE* string_file)
{
  
  switch(major_id) 
    {
    
    case Xinfo_kind::ID_ENTITY_ARCHITECTURE:
      break;
    case Xinfo_kind::ID_PROCESS:
      break;
    case Xinfo_kind::ID_PACKAGE:	
      break;	
    case Xinfo_kind::ID_PACKAGE_BODY:	
      break;
      
    case Xinfo_kind::ID_OBJECT:
      {
	Xinfo_plain_object_descriptor* ptr = (Xinfo_plain_object_descriptor*)sdesc;
	Write_Xinfo_plain(ptr,info_file, index_file, minor_id, string_file);	
	break;	
      }
    case Xinfo_kind::ID_TYPE_INFO:
      {
	Xinfo_type_info_interface_descriptor* ptr = (Xinfo_type_info_interface_descriptor*)sdesc;
	type_info_interface* type_info = (type_info_interface*)ptr->object_reference;
	write_type_info_interface(info_file, type_info, ptr, index_file);
	break;
      }
    default:
       error(-1, "Unknown Xinfo_Type");
      break;
    }
}



//*********************************************************************************************
// This function writes in the data file the need information. It tests 4 cases, then
// call the corresponding function to write the data in the info_file.
//**********************************************************************************************
void 
write_info_file(list<Xinfo_data_descriptor*> &xinfo_desc, FILE* info_file, FILE* index_file, FILE* string_file)
{
  for (list<Xinfo_data_descriptor*>::iterator it = xinfo_desc.begin(); it != xinfo_desc.end(); it++){
    
    Xinfo_data_descriptor* s = (*it);

    Xinfo_kind::major_id_types major_id;
    Xinfo_kind::minor_id_types minor_id;
    
    // case one: Xinfo_scope. 
    if (s->is_Xinfo_scope_descriptor()){
      Xinfo_scope_descriptor* sdesc = (Xinfo_scope_descriptor*)s;
      major_id = sdesc->object_kind_id.get_major_id();
      minor_id = sdesc->object_kind_id.get_minor_id();
      write_index_file(sdesc,index_file, info_file, string_file);
      //Write_Xinfo_data(sdesc, info_file, index_file, minor_id, major_id, string_file);
    }
    // case two: Xinfo_signal. This case is not yet good defined
    else if (s->is_Xinfo_signal_descriptor()){
      
      //Xinfo_signal_descriptor* sdesc = (Xinfo_signal_descriptor*)s;
      Xinfo_plain_object_descriptor* sdesc = (Xinfo_plain_object_descriptor*)s;
      major_id = sdesc->object_kind_id.get_major_id();
      minor_id = sdesc->object_kind_id.get_minor_id();
      Write_Xinfo_plain(sdesc, info_file, index_file, minor_id, string_file);
    }
    // case three:Xinfo_plain_object
    else if( s->is_Xinfo_plain_object_descriptor()) 
      {
	Xinfo_plain_object_descriptor* sdesc = (Xinfo_plain_object_descriptor*)s;
	major_id = sdesc->object_kind_id.get_major_id();
	minor_id = sdesc->object_kind_id.get_minor_id();
	Write_Xinfo_plain(sdesc, info_file, index_file, minor_id, string_file);

      }
    // case four: Xinfo_type_info
     else if( s->is_Xinfo_type_info_descriptor()) 
      {
	Xinfo_type_info_interface_descriptor* sdesc = (Xinfo_type_info_interface_descriptor*)s;
	major_id = sdesc->object_kind_id.get_major_id();
	minor_id = sdesc->object_kind_id.get_minor_id();
	//First, write the corresponding information in the index file
	write_index_file(sdesc,index_file, info_file, string_file);
	Write_Xinfo_data(sdesc, info_file, index_file, minor_id, major_id, string_file);
      }
    else {}
    
  }
  fflush(index_file);
  
}



