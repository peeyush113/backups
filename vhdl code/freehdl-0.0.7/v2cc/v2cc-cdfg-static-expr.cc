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
// Name: m_cdfg_get_static_expr , generic function
//
// Description: Returns static expression (with respect to slevel) in CDFG style
//
// Parameter: slevel = static level of the expression which shall be considered.
//   str = result string
//   t = Controls conversion of VHDL objects
//   start = false if the ENTIRE expression shall be converted into an ACL
// 
// Return value: returns true if e matches the static level slevel
//
// ******************************************************************************************


bool
m_cdfg_get_static_expr(pIIR_Expression e, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		  id_type t = id_type(), bool start = false)
{
  bool match = level_match(e->static_level, slevel);
  if (start) return match;

  // first check whether slevel matches the static level of the
  // expression e
  if (! match) return false;

  cdfg_emit_expr(e, str, rstack, t);
  
  return true; // e matches the static level slevel
}


bool
m_cdfg_get_static_expr (pIIR_SimpleReference sor, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		   id_type t = id_type(), bool start = false)
{
  return start ? true : level_match(sor->static_level, slevel);
}


bool
m_cdfg_get_static_expr (pIIR_ArrayReference aor, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		   id_type t = id_type(), bool start = false)
{
  if (start) {
    string result = "(create-array-element-reference ";
    // if start is true then first calculate prefix
    bool match = cdfg_get_static_expr(aor->array, result, rstack, slevel, t, true);

    // Now test whether each index value matches the static level
    // slevel. Further, convert the index values.
    for (pIIR_ExpressionList il = aor->indices; match && il; il = il->rest)
      {
	// Stop creating ACL objects as soon as the first index is
	// found which does not match the static level slevel
	if (! level_match(il->first->static_level, slevel)) {
	  match = false;  
	  break; 
	}
	bool simple = cdfg_emit_expr (il->first, result, rstack, t);
      }
    result += ")";

    str += result;

    return match;
    
  } else {
    // if start is false then convert the entire expression if the
    // slevel matches the static level of the expression aor.
    if (! level_match(aor->static_level, slevel)) return false;
    cdfg_emit_expr (aor, str, rstack, t);
    return true;
  }
}


bool
m_cdfg_get_static_expr (pIIR_RecordReference ror, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		   id_type t = id_type(), bool start = false)
{
  if (start) {
    string result = "(create-record-element-reference ";
    // if start is true then calculate the prefix
    if (cdfg_get_static_expr(ror->record, result, rstack, slevel, t, start)) {
      // if the prefix is static then determine the declaration number
      // of the record element (the first element is associated with
      // number 0, the next element is associated with 1, ...)
      result += " " + to_string(ror->element->declaration_pos) + ")";
      str += result;
      
      return true;
      
    } else
      // if the prefix is not static then return false. Do not append
      // the declaration number!
      return false;

  } else {
    // if start is false then convert the entire expression if the
    // slevel matches the static level of the expression ror.
    if (! level_match(ror->static_level, slevel)) return false;
    cdfg_emit_expr(ror, str, rstack, t);
    return true;
  }
}



bool
m_cdfg_get_static_expr (pIIR_ExplicitRange er, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		   id_type t = id_type(), bool start = false)
{
  // bail out if start is true
  assert(!start);

  // check whether left and right border match the static level
  if (! level_match(er->left->static_level, slevel) ||
      ! level_match(er->right->static_level, slevel))
    return false;

  str += "(create-range ";

  // now add left border, direction and right border
  cdfg_emit_expr(er->left, str, rstack, t);
  str += " " + string(er->direction == IR_DIRECTION_UP ? "(int)to" : "(int)downto") + " ";
  cdfg_emit_expr(er->right, str, rstack, t);

  return true;
}



bool
m_cdfg_get_static_expr (pIIR_SliceReference sr, string &str, RegionStack &rstack, IR_StaticLevel slevel, 
		   id_type t = id_type(), bool start = false)
{
  if (start) {
    string result = "(create-array-slice ";
    // if start is true then calculate the ACL for the prefix as well
    // as the ACL for the range
    if (cdfg_get_static_expr(sr->array, result, rstack, slevel, t, true) &&
	cdfg_get_static_expr(sr->range, result, rstack, slevel, t, false)) {
      str += result + ")";
      return true;
    } else
      return false;
    
  } else {
    // if start is false then convert the entire expression into an
    // ACL object if the slevel matches the static level of the
    // expression ror
    if (! level_match(sr->static_level, slevel)) return false;
    cdfg_emit_expr(sr, str, rstack, t);
    return true;
  }
}

