
#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "v2cc-util.h"



// ******************************************************************************************
// Name: m_get_type_info_obj , generic function
//
// Description: Returns type info object for a type or subtype. If the
// (sub)type is anonymous then code which generates a new type info
// objects is returned. static_object controls whether a new created
// info object shall be static (i.e., it is never removed) or not.
// 
// Return value: string
//
// ******************************************************************************************

string
m_get_type_info_obj(pIIR_AccessType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_EnumerationType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_FileType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_IntegerType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_PhysicalType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_FloatingType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_RecordSubtype t, RegionStack &rstack, bool static_info)
{
  if (t->declaration != NULL ||
      implicit_subtype_declaration(t) != NULL)
    return "(&" + qid(t, rstack, INFO) + "_INFO)";
  else
    return "(&" + qid(get_base_type(t), rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_Subtype t, RegionStack &rstack, bool static_info)
{
  if (t->declaration != NULL ||
      implicit_subtype_declaration(t) != NULL)
    return "(&" + qid(t, rstack, INFO) + "_INFO)";
  else
    return "(&" + qid(get_base_type(t), rstack, INFO) + "_INFO)";
}


string
m_get_type_info_obj(pIIR_ScalarSubtype t, RegionStack &rstack, bool static_info)
{
  string str;

  // If subtype has an explicit declaration then return the
  // corresponding info pointer.
  if (t->declaration != NULL ||
      implicit_subtype_declaration(t) != NULL) 
    return "(&" + qid(t, rstack, INFO) + "_INFO)";
  // If the subtype is not constrained then analyze its immediate base
  if (t->range == NULL)
    return get_type_info_obj(t->immediate_base, rstack, static_info);

  vector<RangeDescriptor> range_desc = get_discrete_range(t, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<string, string> range = 
    range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
  string left_checked_str = range.left, right_checked_str = range.right;
  string base_info_str = get_type_info_obj(t->base, rstack, false);

  // Ok, the subtype is constrained but has no explicit declaration
  if (t->base->is(IR_ENUMERATION_TYPE)) {
    // ****************************************************************************
    // Enumeration subtype
    // ****************************************************************************
    // Shall we perform runtime range checks?
    if ((do_runtime_checks & CG_CHECK_SCALAR_TYPE_RANGE)) {
      string base_info_str = get_type_info_obj(get_basic_type(t->immediate_base), rstack, false);
      // Could the left bound be checked at compile time or do we
      // have to do this at runtime?
      if (runtime_checks(t) & RT_CHECK_LEFT_BOUND)
	left_checked_str = base_info_str + "->check(" + range.left + ")";
      // Could the right bound be checked at compile time or do we
      // have to do this at runtime?
      if (runtime_checks(t) & RT_CHECK_RIGHT_BOUND)
	right_checked_str = base_info_str + "->check(" + range.right + ")";
    }
    str = "new enum_info_base(" + left_checked_str + "," + right_checked_str + "," + 
      base_info_str + "->values)";

  } else if (t->base->is(IR_INTEGER_TYPE) ||
	     t->base->is(IR_PHYSICAL_TYPE) ||
	     t->base->is(IR_FLOATING_TYPE)) {
    // ****************************************************************************
    // integer, physical or floating point subtype
    // ****************************************************************************
    // Shall we perform runtime range checks?
    if ((do_runtime_checks & CG_CHECK_SCALAR_TYPE_RANGE)) {
      string base_info_str = get_type_info_obj(get_basic_type(t->immediate_base), rstack, false);
      // Could the left bound be checked at compile time or do we
      // have to do this at runtime?
      if (runtime_checks(t) & RT_CHECK_LEFT_BOUND)
	left_checked_str = base_info_str + "->check(" + range.left + ")";
      // Could the right bound be checked at compile time or do we
      // have to do this at runtime?
      if (runtime_checks(t) & RT_CHECK_RIGHT_BOUND)
	right_checked_str = base_info_str + "->check(" + range.right + ")";
    }

    if (t->base->is(IR_INTEGER_TYPE)) 
      str = "new integer_info_base(" + left_checked_str + "," + right_checked_str + "," + 
	"min(" + range.left + "," + range.right + ")," + "max(" + range.left + "," + range.right + "))";
    else if (t->base->is(IR_FLOATING_TYPE)) 
      str = "new floating_info_base(" + left_checked_str + "," + right_checked_str + "," + 
	"min(" + range.left + "," + range.right + ")," + "max(" + range.left + "," + range.right + "))";
    else if (t->base->is(IR_PHYSICAL_TYPE)) 
      str = "new physical_info_base(" + left_checked_str + "," + right_checked_str + "," + 
	"min(" + range.left + "," + range.right + ")," + "max(" + range.left + "," + range.right + ")," + 
	base_info_str + "->units," + base_info_str + "->scale," + base_info_str + "->unit_count)";
    
  }
  return str;
}


/* Creates an array info object for an array subtype */
string
m_get_type_info_obj(pIIR_ArraySubtype as, RegionStack &rstack, bool static_info)
{
  // If the declaration is not anonymous then simply return the
  // corresponding array info pointer
  if (as->declaration != NULL ||
      implicit_subtype_declaration(as) != NULL)
    return "(&" + qid(as, rstack, INFO) + "_INFO)";

  // If no constraints are defined then get type info instance for
  // immediate base
  if (as->constraint == NULL)
    return get_type_info_obj(as->immediate_base, rstack, static_info);

  // Count number of dimensions
  pIIR_ArrayType array_type = pIIR_ArrayType(get_base_type(as));
  int counter = 0;
  for (pIIR_TypeList tl = array_type->index_types; tl; tl = tl->rest)
    counter++;

  // Determine whether the base type of the array is named (i.e.,
  // whether there is an explicit type declaration for the base
  // type)
  bool named_base_type = !is_implicit_subtype(array_type);
  // Determine type info instance for element type of the array
  string array_info_str;
  if (named_base_type) {
    // If the base type is named then the elment type is derived
    // from the base array type
    array_info_str = get_type_info_obj(array_type, rstack, static_info) + "->element_type";
    for (int i = counter; i > 1; i--)
      array_info_str = "parray_info(" + array_info_str + ")->element_type";
  } else
    // Otherwise, the element type is determined directly from the
    // corresponding element subtype 
    array_info_str = get_type_info_obj(array_type->element_type, rstack, static_info);

  // Step through each dimension of the array starting with the last
  // dimension.
  for (int i = counter; i >= 1; i--) {
    string base_info_str;
    pIIR_TypeList tl = as->constraint;
    for (int j = 1; j < i; j++) tl = tl->rest;
    // Get index range
    vector<RangeDescriptor> range_desc = get_discrete_range(tl->first, rstack, IR_NOT_STATIC);
    // Bail out if more than a single range descriptor is returned
    assert(range_desc.size() <= 1);
    // Next convert range descriptor to int strings
    StaticRangeDescriptor<string, string> range = 
      range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));
    // Get index info instance for the corresponding array index
    string index_info_str;
    if (named_base_type) {
      // If the base type of the current array subtype is named then
      // the corresponding index subtype is derived from this type
      index_info_str = get_type_info_obj(array_type, rstack, static_info);
      for (int k = i; k > 1; k--)
	index_info_str = "parray_info(" + array_info_str + "->element_type)";
      index_info_str = index_info_str + "->index_type";
    } else
      // Otherwise, the index info is directly derived from the
      // corresponding index subtype
      index_info_str = get_type_info_obj(get_base_type(tl->first), rstack, static_info);
    // setup init value for array info instance
    array_info_str = "(new array_info(" + array_info_str + "," + index_info_str + "," +
      range.left + "," + range.dir + "," + range.right + "," +  (static_info?"-1":"0") + "))";
  }
  
  return array_info_str;
}


string
m_get_type_info_obj(pIIR_ArrayType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}

string
m_get_type_info_obj(pIIR_RecordType t, RegionStack &rstack, bool static_info)
{
  assert (t->declaration != NULL);

  return "(&" + qid(t->declaration, rstack, INFO) + "_INFO)";
}
