
#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "v2cc-util.h"



// ******************************************************************************************
// Name: m_qid , generic function
//
// Description: Returns get a fully qualified identifier name plus an
// appropriate prefix. I.e., if a identifier is used at a location in
// the code where it is not directly visible then some prefix code is
// needed in order to access it. E.g., if a generic parameter is used
// within process then it is accessed using a architecture pointer as
// the parameter is not directly visible within the process. parameter
// rstack determines the code region where the identifier is to be
// used. Parameter obj_access defines how the identifier is accessed.
// 
// Return value: returns fully qualified string
//
// ******************************************************************************************

// Prepends \ before special characters \ : ( ) ". 
string
get_fully_escaped_string(const string &str)
{
  string result;

  for (unsigned int i = 0; i < str.length(); i++) {
    if (str[i] == '\\' ||
	str[i] == ':' ||
	str[i] == '"' ||
	str[i] == '(' ||
	str[i] == ')')
      result += '\\';
    result += str[i];
  }
  return result;
}

 
string
get_access_prefix(pIIR_Declaration d, RegionStack &rstack, id_type obj_access)
{
  if (obj_access.access() & NO_PREFIX)
    return "";

  string prefix;

  // If the object has been declared within a package or package body
  // then no prefix is needed as the corresponding C++ objects are
  // declared globally.
  if (d->declarative_region->is(IR_PACKAGE_DECLARATION) ||
      d->declarative_region->is(IR_PACKAGE_BODY_DECLARATION))
    return "";

  // If the identifier is globally declared then no prefix is required
  if (static_declarative_region(d) == RootDeclarativeRegion(rstack))
    return "";

  // Determine the "home" region where the object has been
  // declared. Note that this is not necessarily the original
  // declarative region but may have been modified during
  // optimization. E.g., if a constant is declared within a process
  // then the declarative region of the constant is the process
  // itself. Usually, the corresponding C++ constant will be declared
  // within the C++ process code.  However, if the constant is locally
  // static then it is declared globally in the C++ source.
  pIIR_DeclarativeRegion ident_home_region = 
    static_declarative_region(d) != NULL? static_declarative_region(d) : d->declarative_region;
  while (true) {
    // Search for the next concurrent statement, package, package
    // body, subprogram, architecture or entity.
    if (ident_home_region->is(IR_CONCURRENT_STATEMENT) ||
	ident_home_region->is(IR_PACKAGE_DECLARATION) ||
	ident_home_region->is(IR_PACKAGE_BODY_DECLARATION) ||
	ident_home_region->is(IR_SUBPROGRAM_DECLARATION) ||
	ident_home_region->is(IR_ARCHITECTURE_DECLARATION) ||
	ident_home_region->is(IR_ENTITY_DECLARATION))
      break;
    ident_home_region = ident_home_region->declarative_region;
  }
  // If the home region is equal to the current region then the
  // object is directly visible. Hence, no prefix is needed. Further,
  // all objects within an architecture or entity region are directly
  // visible as well.
  RegionStack::iterator r_iter = --rstack.end();
  if  (ident_home_region == (*r_iter) ||
       (*r_iter)->is(IR_ENTITY_DECLARATION) ||
       (*r_iter)->is(IR_ARCHITECTURE_DECLARATION))
    return prefix;
  // Analyze each region beginning with the current region an
  // proceeding to the very first region.
  while (true) {
    // If the identifier is used within a subprogram then we do not
    // need any additional prefix. Note that any identifier not
    // global to a subprogram is passed into the corresponding C++
    // function (generated from the VHDL subprogram code) as a
    // parameter.
    if ((*r_iter)->is(IR_SUBPROGRAM_DECLARATION))
      return prefix;
    // If the current region pointer points to an entity then the
    // object is accessed via the entity/architecture pointer.
    // Further, if the object is declared within an generate
    // statement, then it is accessed vi a special pointer.
    if ((*r_iter)->is(IR_ENTITY_DECLARATION) ||
	(*r_iter)->is(IR_ARCHITECTURE_DECLARATION) ||
	((*r_iter)->is(IR_CONCURRENT_GENERATE_STATEMENT) &&
	 ident_home_region == (*r_iter)))
      return qid(*r_iter, rstack, id_type()) + "_AP->" + prefix;
    // If the current region pointer is equal to the "home" region of
    // the object then we are done and the prefix is returned.
    if  (ident_home_region == (*r_iter))
      return prefix;
    if (r_iter == rstack.begin())
      {
	// This should never happen
	cout << "Internal problem: Could not determine access prefix for " << d->declarator->text.to_chars() << endl;
	cout << "Tested regions: ";
	r_iter = --rstack.end();
	while (r_iter != rstack.begin ())
	  {
	    if ((*r_iter)->declarator != NULL)
	      cout << " " << (*r_iter)->declarator->text.to_chars();
	    else
	      cout << " ???";
	    r_iter--;
	  }
	cout << endl;
	cout << "static_declarative_region: " << (long)static_declarative_region(d);
	if (static_declarative_region(d) != NULL &&
	    static_declarative_region(d)->declarator != NULL)
	  cout << " = " << static_declarative_region(d)->declarator->text.to_chars();
	cout << endl;
	cout << "RootDeclarativeRegion: " << (long)RootDeclarativeRegion(rstack) << endl;
	assert (false);
      }
    r_iter--;
  };
  
  return prefix;
}


string
m_qid(pIIR_LibraryUnit d, RegionStack &rstack, id_type obj_access)
{
  string id;

  if (d->is (IR_ARCHITECTURE_DECLARATION))			// Ent_Arch
    id = qid(pIIR_ArchitectureDeclaration(d)->entity, rstack, obj_access);
  else if (!(obj_access.object() == BARE))
    id = nid(pIIR_LibraryUnit(d),LIBRARY);
  else
    id = pIIR_LibraryUnit(d)->library_name->text.to_chars();		

  id += "_" + nid(d, obj_access);

  return id;
}


string
m_qid(pIIR_SubprogramDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id;
  if (d->prototype != NULL)
    // If a subprogram shall be printed and if this subprogram has a
    // prototype then print the name of the prototype delcaration!
    id = qid(d->prototype, rstack, obj_access);
  else
    id = qid(d->declarative_region, rstack, obj_access) + "_" + nid(d, obj_access);

  return id;
}


string
m_qid(pIIR_Declaration d, RegionStack &rstack, id_type obj_access)
{
  return qid(d->declarative_region, rstack, obj_access) + "_" + nid(d, obj_access);
}


string
m_qid(pIIR_InterfaceDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id = get_access_prefix(d, rstack, obj_access) + 
    qid(d->declarative_region, rstack, obj_access) + "_" + nid(d, obj_access);

  if (d->alias_base != NULL && 
      !is_array_type(d->subtype) && 
      (obj_access.access() & DEREF))
      // If an object alias (other than an array alias) shall be
      // printed and the DEREF flag is set then the entire string is
      // prepended with "*"
      id = "(*" + id + ")";

  return id;
}


string
m_qid(pIIR_SignalInterfaceDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id = qid(d->declarative_region, rstack, obj_access) + "_";

  // if the reader is requested and ARCHREF is set then the reader is
  // accessed via the sig_info instance.
  if ((obj_access.object() == READER) &&
      (obj_access.access() & ARCHREF)) {
    id += nid(d, id_type(DEFAULT, obj_access.access()));
    id = get_access_prefix(d, rstack, obj_access) + id;
    if (!(obj_access.access() & DEREF))
      id = "&" + id;
    else
      id += "->reader()";

  } else {
    // Reader and driver are delclared locally. Hence, no access prefix
    // is required.
    id += nid(d, obj_access);
  
    if ((obj_access.object() != READER) && 
	(obj_access.object() != DRIVER) &&
	(obj_access.access() & ARCHREF))
      id = get_access_prefix(d, rstack, obj_access) + id;
    
    if (obj_access.access() & DEREF)
      // If a signal shall be printed and the DEREF flag is set then the
      // entire string is prepended with "*"
      id = "(*" + id + ")";
  }

  return id;
}


string
m_qid(pIIR_SignalDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id = qid(d->declarative_region, rstack, obj_access) + "_";

  // if the reader is requested and ARCHREF is set then the reader is
  // accessed via the sig_info instance.
  if ((obj_access.object() == READER) &&
      (obj_access.access() & ARCHREF)) {
    id += nid(d, id_type(DEFAULT, obj_access.access()));
    id = get_access_prefix(d, rstack, obj_access) + id;
    if (!(obj_access.access() & DEREF))
      id = "&" + id;
    else
      id += "->reader()";

  } else {
    // Reader and driver are delclared locally. Hence, no access prefix
    // is required.
    id += nid(d, obj_access);
    
    if ((obj_access.object() != READER) && 
	(obj_access.object() != DRIVER) &&
	(obj_access.access() & ARCHREF))
      id = get_access_prefix(d, rstack, obj_access) + id;
    
    if (obj_access.access() & DEREF)
      // If a signal shall be printed and the DEREF flag is set then the
      // entire string is prepended with "*"
      id = "(*" + id + ")";
  }

  return id;
}


string
m_qid(pIIR_ObjectDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id = get_access_prefix(d, rstack, obj_access) + 
    qid(d->declarative_region, rstack, obj_access) + "_" + nid(d, obj_access);

  if (d->alias_base != NULL &&
      !is_array_type(d->subtype) && 
      (obj_access.access() & DEREF))
    // If an object alias (other than an array alias) shall be printed
    // and the DEREF flag is set then the entire string is prepended
    // with "*"
    id = "(*" + id + ")";
  
  return id;
}


string
m_qid(pV2CC_ImplicitSignalDeclaration_WaitFor d, RegionStack &rstack, id_type obj_access)
{
  string id = nid(d, obj_access);

  if (obj_access.access() & DEREF)
    // If a signal shall be printed and the DEREF flag is set then the
    // entire string is prepended with "*"
    id = "(*" + id + ")";

  return id;
}


string
m_qid(pIIR_TypeDeclaration d, RegionStack &rstack, id_type obj_access)
{
  string id;

  if ((obj_access.object() == TYPE) && is_scalar_type(d->type)) {
    pIIR_Type base_type = get_base_type(d->type);
    
    if (base_type->is(IR_INTEGER_TYPE))
      return "integer";
    else if (base_type->is(IR_ENUMERATION_TYPE))
      return "enumeration";
    else if (base_type->is(IR_PHYSICAL_TYPE))
      return "physical";
    else if (base_type->is(IR_FLOATING_TYPE))
      return "floatingpoint";
    else
      assert(false);

  } else if ((obj_access.object() == TYPE) && d->type->is(IR_ACCESS_TYPE)) {
    return "vhdlaccess";

  } else if ((obj_access.object() == TYPE) && d->type->is(IR_FILE_TYPE)) {
    return "vhdlfile";
  
  } else
    id = qid(d->declarative_region, rstack, obj_access) + "_" + nid(d, obj_access);

  if (obj_access.object() == INFO)
    id = get_access_prefix (d, rstack, obj_access) + id;

  if ((obj_access.object() == (ALIAS | TYPE)) &&
      (d->type->is(IR_ARRAY_SUBTYPE) || (d->type->is(IR_ARRAY_TYPE))))
    // Create an array alias type name
    id = "array_alias<" + id + " >";

  return id;
}


string
m_qid(pIIR_Type t, RegionStack &rstack, id_type obj_access)
{
  return qid(get_declaration(t), rstack, obj_access);
}


string
m_qid(pIIR_Subtype t, RegionStack &rstack, id_type obj_access)
{
  if (implicit_subtype_declaration(t) != NULL)
    return qid(implicit_subtype_declaration(t), rstack, obj_access);
  else
    return qid(get_declaration(t), rstack, obj_access);
}
