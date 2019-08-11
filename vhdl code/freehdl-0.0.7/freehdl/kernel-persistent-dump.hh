#define KERNEL 
#include <freehdl/std-vhdl-types.hh>
#include <freehdl/kernel-register.hh>
#include <freehdl/kernel-error.hh>
#include <stdio.h>
#include <map>
#include <list>



//

typedef map<type_info_interface*, bool, less<type_info_interface*> > typemap;

typedef map<const char*, bool, less<const char*> > strmap;

//

void 
write_info_file(list<Xinfo_data_descriptor*> &xinfo_desc, FILE* info_file, FILE* index_file, FILE* string_file);

//
void 
write_index_file(list<Xinfo_data_descriptor*> &xinfo_desc, FILE* index_file, FILE* info_file,FILE* string_file );

//
void 
Write_Xinfo_data(Xinfo_data_descriptor* sdesc, FILE* info_file, 
	   Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id, FILE* string_file);

//
void 
Xinfo_write_data(Xinfo_data_descriptor* sdesc, FILE* info_file, 
		 Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id);

//
void 
Write_Xinfo_plain(Xinfo_plain_object_descriptor* sdesc, FILE* info_file, 
	    Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id);

//
void 
Xinfo_write_type_info(Xinfo_plain_object_descriptor* sdesc, FILE* info_file, 
		      Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id);

//
void 
Xinfo_write_plain(Xinfo_plain_object_descriptor* sdesc, FILE* info_file, 
		  Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id);

//
// // This function writes the data correspoding to type_info element in the info_file
// void 
// Xinfo_write_type_info(Xinfo_plain_object_descriptor* sdesc, FILE* info_file, 
// 	    Xinfo_kind::minor_id_types& minor_id, Xinfo_kind::major_id_types& major_id)
// {
//   bool sig_exist = false;
//   switch(minor_id)
//     {
//     case Xinfo_kind::ID_ARRAY_INFO:
//       {
// 	array_info *ainfo = (array_info*)sdesc->type;
// 	if (ainfo->element_type->id != ARRAY){
	  
// 	  if (type_map.begin() == type_map.end())
// 	    sig_exist = true;
// 	  else {
// 	    mymap::iterator it = type_map.find(sdesc);
// 	    if (it == type_map.end())
// 	      sig_exist = true;
// 	  }
// 	  if( sig_exist){

// 	    type_map[sdesc] = true;

// 	    size_t size = sizeof(int);
// 	    size_t nelement = 1;
// 	    fwrite(&major_id, size, nelement, info_file);
// 	    int idd = (int)(sdesc->type->id);
// 	    fwrite(&idd, size, nelement, info_file);
// 	    int lb = ainfo->left_bound;
// 	    int rb = ainfo->right_bound;
// 	    size = sizeof(int);
// 	    fwrite(&lb, size, nelement, info_file);
// 	    fwrite(&rb, size, nelement, info_file);
// 	    size = sizeof(array_info*);
// 	    fwrite(&ainfo, size, nelement, info_file);
// 	  } else
// 	    type_map[sdesc] = false;
// 	} else
// 	  Xinfo_write_type_info(sdesc, info_file,minor_id, major_id);
// 	return;
// 	break;
//       }
//     case Xinfo_kind::ID_ENUM_INFO:
//       {
// 	enum_info_base *ainfo = (enum_info_base*)sdesc->type;
// 	if (type_map.begin() == type_map.end())
// 	  sig_exist = true;
// 	else {
// 	  mymap::iterator it = type_map.find(sdesc);
// 	  if (it == type_map.end())
// 	    sig_exist = true;
// 	}
// 	if( sig_exist){
    
// 	  type_map[sdesc] = true;
	    
// 	  size_t size = sizeof(int);
// 	  size_t nelement = 1;
// 	  fwrite(&major_id, size, nelement, info_file);
// 	  int idd = (int)(sdesc->type->id);
// 	  fwrite(&idd, size, nelement, info_file);
// 	  int lb = ainfo->left_bound;
// 	  int rb = ainfo->right_bound;
// 	  size = sizeof(int);
// 	  fwrite(&lb, size, nelement, info_file);
// 	  fwrite(&rb, size, nelement, info_file);
// 	  size = sizeof(enum_info_base*);
// 	  fwrite(&ainfo, size, nelement, info_file);
// 	} else
// 	  type_map[sdesc] = false;
// 	break;
//       }
//     case Xinfo_kind::ID_INTEGER_INFO:
//       {
// 	integer_info_base *ainfo = (integer_info_base*)sdesc->type;
// 	if (type_map.begin() == type_map.end())
// 	  sig_exist = true;
// 	else {
// 	  mymap::iterator it = type_map.find(sdesc);
// 	  if (it == type_map.end())
// 	    sig_exist = true;
// 	}
// 	if( sig_exist){
    
// 	  type_map[sdesc] = true;
// 	  size_t size = sizeof(int);
// 	  size_t nelement = 1;
// 	  fwrite(&major_id, size, nelement, info_file);
// 	  int idd = (int)(sdesc->type->id);
// 	  fwrite(&idd, size, nelement, info_file);
// 	  int lb = ainfo->left_bound;
// 	  int rb = ainfo->right_bound;
// 	  size = sizeof(int);
// 	  fwrite(&lb, size, nelement, info_file);
// 	  fwrite(&rb, size, nelement, info_file);
// 	  size = sizeof( integer_info_base*);
// 	  fwrite(&ainfo, size, nelement, info_file);
// 	} else
// 	  type_map[sdesc] = false;	
// 	break;
//       }
//     case Xinfo_kind::ID_FLOAT_INFO:
//       {
// 	float_info_base *ainfo = (float_info_base*)sdesc->type;
// 	if (type_map.begin() == type_map.end())
// 	  sig_exist = true;
// 	else {
// 	  mymap::iterator it = type_map.find(sdesc);
// 	  if (it == type_map.end())
// 	    sig_exist = true;
// 	}
// 	if( sig_exist){
    
// 	  type_map[sdesc] = true;

// 	  size_t size = sizeof(int);
// 	  size_t nelement = 1;
// 	  fwrite(&major_id, size, nelement, info_file);
// 	  int idd = (int)(sdesc->type->id);
// 	  fwrite(&idd, size, nelement, info_file);
// 	  floatingpoint lb = ainfo->left_bound;
// 	  floatingpoint rb = ainfo->right_bound;
// 	  size = sizeof(float);
// 	  fwrite(&lb, size, nelement, info_file);
// 	  fwrite(&rb, size, nelement, info_file);
// 	  size = sizeof(float_info_base*);
// 	  fwrite(&ainfo, size, nelement, info_file);
// 	} else
// 	  type_map[sdesc] = false;	

// 	break;
//       }
//     case  Xinfo_kind::ID_PHYSICAL_INFO:
//       {
// 	physical_info_base *ainfo = (physical_info_base*)sdesc->type;
// 	if (type_map.begin() == type_map.end())
// 	  sig_exist = true;
// 	else {
// 	  mymap::iterator it = type_map.find(sdesc);
// 	  if (it == type_map.end())
// 	    sig_exist = true;
// 	}
// 	if( sig_exist){

// 	  type_map[sdesc] = true;
		
// 	  size_t size = sizeof(int);
// 	  size_t nelement = 1;
// 	  fwrite(&major_id, size, nelement, info_file);
// 	  int idd = (int)(sdesc->type->id);
// 	  fwrite(&idd, size, nelement, info_file);
// 	  physical lb = ainfo->left_bound;
// 	  physical rb = ainfo->right_bound;
// 	  size = sizeof(physical);
// 	  fwrite(&lb, size, nelement, info_file);
// 	  fwrite(&rb, size, nelement, info_file);
// 	  size = sizeof(physical_info_base*);
// 	  nelement = 1;
// 	  fwrite(&ainfo, size, nelement, info_file);
// 	} else
// 	  type_map[sdesc] = false;
// 	break;
//       }
//     default: 
//       break;   
//     }
// }


// ///-------------
