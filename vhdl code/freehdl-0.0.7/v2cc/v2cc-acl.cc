#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#include "mapping.h"
#include "v2cc-util.h"


// ******************************************************************************************
// Name: m_get_acl , generic function
//
// Description: Extracts ACL list from an expression. Depending on the
// parameter slevel only the locally static, globally static or all
// parts of the expression are converted and added to the list. The
// resulting list elements are made of pair<pIIR_Expression,
// pIIR_Root> where the second element of the pair denotes the
// appropriate expression. In most cases the first element is
// NULL. However, if an element of an array or record shall be
// addressed, then the first element points to the corresponding array
// or record expression. start is true if the entire expression e
// shall be converted into an ACL object.
//
// Parameter: acl_expr_list = output list
//   rstack = region stack
//   slevel = only expressions that match static level slevel 
//            are appended to the output list
//   start = false if the ENTIRE expression shall be converted into an ACL
// 
// Return value: returns true if e matches the static level slevel
//
// ******************************************************************************************


string 
sprint_object_reference(pIIR_ObjectDeclaration obj, 
			vector<StaticRangeDescriptor<lint, IR_Direction> > &static_range_vec,
			RegionStack &rstack)
{
  // First, print object name to string
  string str = obj->declarator->text.to_chars ();
  pIIR_Type type = get_basic_type (obj->subtype);

  vector<StaticRangeDescriptor<lint, IR_Direction> >::iterator iter = 
    static_range_vec.begin ();
  while (iter != static_range_vec.end ())
    {
      if (type->is (IR_ARRAY_TYPE) ||
	  type->is (IR_ARRAY_SUBTYPE))
	{
	  // Element is an array
	  pIIR_TypeList type_list = type->is (IR_ARRAY_TYPE)? 
	    pIIR_ArrayType (type)->index_types : 
	    pIIR_ArraySubtype (type)->constraint;

	  str += "(";
	  string separator;
	  // Iterate over dims or until end of static_range_vec is
	  // reached
	  for (; type_list != NULL && iter != static_range_vec.end (); 
	       type_list = type_list->rest, iter++)
	    {
	      if (! and_reduce (iter->valid))
		// Range is not static or element could not be
		// statically determined. Hence, print ??? instead,
		str += separator + "???";
	      else if (range_to_length (iter->left, iter->dir, iter->right) == 0)
		{
		  // Range is 0 (i.e., null range specified)
		  str += separator + "*null range*";
		}
	      else if (range_to_length (iter->left, iter->dir, iter->right) == 1)
		// Only a single element of the dimension is addressed
		str += separator + 
		  to_string (pIIR_ScalarType (get_base_type (type_list->first)), 
			     StaticDataType (iter->left));
	      else
		{
		  // A range is specified. First, determine range
		  // direction from the index type.
		  vector<RangeDescriptor> range_desc = 
		    get_discrete_range(type_list->first, rstack, IR_NOT_STATIC);
		  StaticRangeDescriptor<lint, IR_Direction> range = 
		    range_desc[0].rangedes_to_lint (rstack);
		  // If the range direction is not static then get
		  // range direction from base type...
		  if (!range.valid [1])
		    {
		      range_desc = get_discrete_range 
			(get_base_type (type_list->first), rstack, IR_NOT_STATIC);
		      range = range_desc[0].rangedes_to_lint (rstack);
		    }
		  // Finally, print range
		  str += to_string (iter->left) + 
		    (range.dir == IR_DIRECTION_UP || !range.valid [1] ? " to " : " downto ") +
		    to_string (iter->right);
		}

	      separator = ", ";
	    }

	  str += type_list == NULL ? ")" : ",...)";

	  type = pIIR_ArrayType (get_base_type (type))->element_type;

	}

      else if (type->is (IR_RECORD_TYPE) ||
	       type->is (IR_RECORD_SUBTYPE))
	{
	  assert (iter->left == iter->right);
	  pIIR_RecordType record_type = pIIR_RecordType (get_basic_type (type));
	  pIIR_ElementDeclaration elem_decl = 
	    get_nth_element (record_type->element_declarations, iter->left)->first;
	  str += elem_decl->declarator->text.to_chars ();

	  type = elem_decl->subtype;
	}
      else
	assert (false);
    }
  
  return str;
}


string
sprint_acl(list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list, 
	   const string acl_object, 
	   RegionStack &rstack, id_type t)
{
  if (acl_expr_list.size() == 0)
    return string("");

  string result = acl_object;

  for (list<pair<pIIR_Expression, pIIR_Root> >::iterator it = acl_expr_list.begin(); it != acl_expr_list.end(); it++)
    {
      const bool emit_directly = (*it).first == NULL;
      pIIR_Root ex = (*it).second;

      result += "<<";
      if (!emit_directly && ex->is(IR_RECORD_REFERENCE))
	{
	  // if the prefix is static then determine the declaration number
	  // of the record element (the first element is associated with
	  // number 0, the next element is associated with 1, ...)
	  result += to_string(pIIR_RecordReference(ex)->element->declaration_pos);
	}
      else if (!emit_directly && ex->is(IR_EXPLICIT_RANGE))
	{

	  // Determine range 
	  vector<RangeDescriptor> range_desc = 
	    get_discrete_range (pIIR_ExplicitRange(ex), rstack, IR_NOT_STATIC);
	  // Convert to integer strings
	  StaticRangeDescriptor<string, string> range = 
	    range_desc[0].rangedes_to_string(rstack, t);
	  result += "ACL_RANGE<<" + range.left + "<<" + range.dir + "<<" + range.right;
	}
      else
	{
	  emit_expr(ex, result, rstack, t);
	}
    }

  return result;
}


// Returns types that are associated with the corresponding
// expressions on the acl list. In detail, the function returns a list
// of type pairs, where each pair is associated with a entry on the
// list.  The first element of a pair denotes the main type (which is
// either a record or array (sub)type) and the second element is the
// actual index type (in case of an array type) or record element type
// (in case of an record type). Note that in case of an
// multi-dimensional array more than one index type may be listed.
vector<pair<pIIR_Type, pIIR_Type> >
get_types(list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list, const pIIR_Type type)
{
  vector<pair<pIIR_Type, pIIR_Type> > result;
  pIIR_Type basic_type = type;
  
  // Loop through all acl elements. Note that for each element an
  // appropriate entry is generated on the result list.
  list<pair<pIIR_Expression, pIIR_Root> >::iterator it = acl_expr_list.begin();
  while (it != acl_expr_list.end ())
    {
      // Remove an subtypes that only add resolution functions.
      basic_type = get_basic_type (basic_type);
      
      if (basic_type->is (IR_ARRAY_TYPE) ||
	  basic_type->is (IR_ARRAY_SUBTYPE))
	{
	  // Ok, the current acl element is an array index (or perhaps
	  // a array range)
	  pIIR_TypeList type_list = basic_type->is (IR_ARRAY_TYPE)?
	    pIIR_ArrayType (basic_type)->index_types : 
	    pIIR_ArraySubtype (basic_type)->constraint;
	  // Add as many pairs to the list as index values are stored
	  // in acl_expr_list. However, stop if all dimensions of the
	  // current array are processed.
	  for (pIIR_TypeList tl = type_list; 
	       tl && (it != acl_expr_list.end ()); 
	       tl = tl->rest, it ++)
	    result.push_back (pair<pIIR_Type, pIIR_Type> (basic_type, tl->first));
	}
      else if (basic_type->is (IR_RECORD_TYPE) ||
	       basic_type->is (IR_RECORD_SUBTYPE))
	{
	  // Ok, the current acl element is an record type. First, get
	  // base type (i.e., remove any resolution function subtypes)
	  // of type.
	  basic_type = get_base_type (basic_type);
	  result.push_back (pair<pIIR_Type, pIIR_Type> (basic_type, basic_type));
	}
      else
	// Should never happen!
	assert (false);
    }

  return result;
}


// Determine length of acl from an acl expression list
int
get_acl_size(list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list)
{
  int count = 0;

  for (list<pair<pIIR_Expression, pIIR_Root> >::iterator it = acl_expr_list.begin(); it != acl_expr_list.end(); it++)
    {
      const bool emit_directly = (*it).first == NULL;
      pIIR_Root ex = (*it).second;

     if (!emit_directly && ex->is(IR_RECORD_REFERENCE))
	count++;
      else if (!emit_directly && ex->is(IR_EXPLICIT_RANGE))
	count += 4;
      else
	count++;
    }

  return count;
}




bool
m_get_acl(pIIR_Expression e, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	  RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  bool match = level_match(e->static_level, slevel);
  if (start) return match;

  // first check whether slevel matches the static level of the
  // expression e
  if (! match) return false;

  acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(NULL, e));
  
  return true; // e matches the static level slevel
}


bool
m_get_acl (pIIR_SimpleReference sor, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	   RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  return start ? true : level_match(sor->static_level, slevel);
}


bool
m_get_acl (pIIR_ArrayReference aor, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	   RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  if (start) 
    {
      // if start is true then first calculate the ACL for the prefix
      bool match = get_acl(aor->array, acl_expr_list, rstack, slevel, true);
      
      // Now test whether each index value matches the static level
      // slevel. Further, convert the index values into ACL objects.
      for (pIIR_ExpressionList il = aor->indices; match && il; il = il->rest)
	{
	  // Stop creating ACL objects as soon as the first index is
	  // found which does not match the static level slevel
	  if (! level_match(il->first->static_level, slevel)) 
	    {
	      match = false;  
	      break; 
	    }
	  
	  acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(aor, il->first));
	}
      
      return match;
      
    } 
  else 
    {
      // if start is false then convert the entire expression into an
      // ACL object if the slevel matches the static level of the
      // expression aor.
      if (! level_match(aor->static_level, slevel)) return false;
      acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(NULL, aor));
      
      return true;
  }
}


bool
m_get_acl (pIIR_RecordReference ror, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	   RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  if (start) 
    {
      // if start is true then calculate the ACL for the prefix
      if (get_acl(ror->record, acl_expr_list, rstack, slevel, start)) 
	{
	  acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(ror, ror));
	  return true;
	  
	} else
	  // if the prefix is not static then return false. Do not append
	  // the declaration number!
	  return false;
    } 
  else 
    {
      // if start is false then convert the entire expression into an
      // ACL object if the slevel matches the static level of the
      // expression ror
      if (! level_match(ror->static_level, slevel)) return false;
      acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(NULL, ror));
      
      return true;
    }
}



bool
m_get_acl (pIIR_ExplicitRange er, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	   RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  // bail out if start is true
  assert(!start);

  // check whether left and right border match the static level
  if (! level_match(er->left->static_level, slevel) ||
      ! level_match(er->right->static_level, slevel))
    return false;

  acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(NULL, er));

  return true;
}



bool
m_get_acl (pIIR_SliceReference sr, list<pair<pIIR_Expression, pIIR_Root> > &acl_expr_list,
	   RegionStack &rstack, IR_StaticLevel slevel, bool start = false)
{
  if (start) {
    // if start is true then calculate the ACL for the prefix as well
    // as the ACL for the range
    if (get_acl(sr->array, acl_expr_list, rstack, slevel, true))
      {
	bool match = get_acl(sr->range, acl_expr_list, rstack, slevel, false);
	if (match)
	  {
	    acl_expr_list.back().first = sr;
	    return true;
	  }
      }
    
    return false;
    
  } else {
    // if start is false then convert the entire expression into an
    // ACL object if the slevel matches the static level of the
    // expression sr
    if (! level_match(sr->static_level, slevel)) return false;
    acl_expr_list.push_back(pair<pIIR_Expression, pIIR_Root>(NULL, sr));
  
    return true;
  }
}



