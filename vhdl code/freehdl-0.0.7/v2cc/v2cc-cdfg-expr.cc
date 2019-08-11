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


// used to generate error messages
extern vaul_error_printer codegen_error;

string sprint_acl(list<string> &acl_list, const string acl_object);



/* Generate string identifier string for to a function or
 * subprogram. This string does contain the subrogram name and lists
 * its parameter type as well as return type (if any). E.g.,
 * ":std:standard:\"+\"(:std:standard:integer,:std:standard:integer):std:standard:integer"
 * is associated with the add operator for type integer. */
string
cdfg_get_subprogram_identifier_string(pIIR_SubprogramDeclaration sd)
{
  const char *separator = "";
  string result = "\"" + get_escaped_string(get_long_name(sd))+ "(";
  for (pIIR_InterfaceList al = sd->interface_declarations; al; al = al->rest) {
    result += separator + get_escaped_string(get_long_name(get_declaration(al->first->subtype)));
    separator = ",";
  }
  result += ")";
  if (sd->is(IR_FUNCTION_DECLARATION))
    result += get_escaped_string(get_long_name(get_declaration(pIIR_FunctionDeclaration(sd)->return_type)));

  result += "\"";

  return result;
}


/* Generate string for a call to a operator */
string
cdfg_operator_call_string(pIIR_FunctionDeclaration fd, const string arg1, const string arg2)
{
  return "(list operator-call " + cdfg_get_subprogram_identifier_string(fd) + " " + arg1 + " " + arg2 + ")";
}


bool
m_cdfg_emit_expr (pIIR_AttrSigFunc af, string &str, RegionStack &rstack, id_type t)
{
  string attribute_name;

  // First, determine attribute kind
  if (af->is(IR_ATTR_EVENT)) {
    // Attribute: EVENT
    attribute_name = "event";

  } else if (af->is(IR_ATTR_ACTIVE)) {
    // Attribute: ACTIVE
    attribute_name = "active";
    
  } else if (af->is(IR_ATTR_LAST_VALUE)) {
    // Attribute: LAST_VALUE
    attribute_name = "last_value";

  } else
    // else bail out!
    codegen_error.error("%:error: sorry, this attribute is currently not supported", af);


  str += "(signal-attribute-call " + attribute_name + " ";
  cdfg_emit_expr(af->signal, str, rstack, t);
  str += ")";

  return false;
}


bool
m_cdfg_emit_expr (pIIR_AttrArrayFunc at, string &str, RegionStack &rstack, id_type t)
{
  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(at)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    str += to_string(folded_value(at).long_value());
    
    return true;

  } else {

    str += "(list array-attribute-call-";
    // Finally, emit code to determine the attribute code at runtime
    if (at->is(IR_ATTR_ARRAY_LENGTH))
      str += "length";
      
    else if (at->is(IR_ATTR_ARRAY_ASCENDING))
      str += "ascending";
      
    else if (at->is(IR_ATTR_ARRAY_LOW))
      str += "low";

    else if (at->is(IR_ATTR_ARRAY_HIGH))
      str += "high";

    else if (at->is(IR_ATTR_ARRAY_RIGHT))
      str += "right";
      
    else if (at->is(IR_ATTR_ARRAY_LEFT))
      str += "left";

    else 
      assert(false);

    // Get index number
    str += " " + to_string(at->index);

    if (at->array != NULL) {
      // The range attribute has been applied on an array
      // instance. First, emit code to extract the info instance from
      // the array.
      cdfg_emit_expr (at->array, str, rstack, DEFAULT);
      
    } else
      // The range attribute has been applied on an array type. Emit
      // code to reference the range corresponding info instance.
      str += get_type_info_obj(at->array_type, rstack, false);

    str += ")";
    
    return false;
  }
}


bool
m_cdfg_emit_expr (pIIR_FunctionCall fc, string &str, RegionStack &rstack, id_type t)
{
  // If the function call has been folded then return the optimized
  // result instead of actually emitting the function call
  if (valid_folded_value(fc)) {
    cdfg_emit_folded_value(folded_value(fc), str, rstack, fc->subtype);
    return true; // Ok, were are done!
  }

  // count the arguments
  int n_args = 0;
  for (pIIR_AssociationList al = fc->parameter_association_list; al; al = al->rest)
    n_args++;

  string arg1, arg2;
  
  switch (get_operator_type(fc->function)) { // Analyze function call type
  case USER_OP: // The function is an user defined operator call
  case BASIC_OP: // The function is a operator defined in an IEEE
    // library.
  case STD_OP: // The function call is a standard operator call
    // emit first operand
    cdfg_emit_expr (fc->parameter_association_list->first->actual, arg1, 
		    rstack, DEFAULT); // First argument

    // emit second operand
    if (n_args == 2) { // Binary operator call
      cdfg_emit_expr (fc->parameter_association_list->rest->first->actual, arg2, 
		      rstack, DEFAULT); // Second argument
    } 
    // Add operator call to code
    str += cdfg_operator_call_string(fc->function, arg1, arg2); 

    break;

  case NO_OP: // A ordinary function call (no operator)
    void cdfg_emit_subprogram_associations (string&, RegionStack&, pIIR_AssociationList, 
					    pIIR_InterfaceList);
    str += "(list function-call " + cdfg_get_subprogram_identifier_string(fc->function) + " ";
    cdfg_emit_subprogram_associations (str, rstack, fc->parameter_association_list,
				       fc->function->interface_declarations);
    str += ")";
  }

  return false;
}


bool
m_cdfg_emit_expr (pIIR_SimpleReference sor, string &str, RegionStack &rstack, id_type t)
{
  // If the reference has been folded then return the optimized result
  // instead of accessing the reference
  if (valid_folded_value(sor)) {
    cdfg_emit_folded_value(folded_value(sor), str, rstack, sor->subtype);
    return true; // Ok, were are done!
  }

  str += qid(sor->object, rstack, id_type(DEFAULT, NO_PREFIX));

  return false;
}


bool
m_cdfg_emit_expr (pIIR_NullExpression ne, string &str, RegionStack &rstack, id_type t)
{
  str += "NULL";
  return true;
}


bool
m_cdfg_emit_expr (pIIR_Allocator a, string &str, RegionStack &rstack, id_type t)
{
  str += "(list allocator-call-" + string(a->value != NULL? "clone " : "create ");
  str += "\"" + get_escaped_string(get_long_name(get_declaration(pIIR_AccessType(a->type_mark)->designated_type))) + "\"";
  if (a->value != NULL) {
    str += " ";
    cdfg_emit_expr(a->value, str, rstack, t);
  }
  str += ")";
    
  return false;
}


void
cdfg_emit_lit (pIIR_Literal l, string &str)
{
  if (l == NULL)
    str += "1";
  else if (l->is(IR_TEXT_LITERAL))
    str += pIIR_TextLiteral(l)->text.to_chars();
  else if (l->is(IR_INTEGER_LITERAL))
    str += pIIR_IntegerLiteral(l)->text.to_chars();
  else if (l->is(IR_FLOATING_POINT_LITERAL))
    str += pIIR_FloatingPointLiteral(l)->text.to_chars();
  else
    str += "<" + string(l->kind_name()) + ">";
}


/* Emit a physical unit. This done by expressing it in terms of
   its base unit.
*/
void
cdfg_emit_unit (pIIR_PhysicalUnit u, string &str, RegionStack &rstack, int l)
{
  str += to_string(u->unit_pos);
}


bool
m_cdfg_emit_expr (pIIR_AbstractLiteralExpression ale, string &str, RegionStack &rstack, id_type t)
{
  if (ale->is(IR_PHYSICAL_LITERAL)) {
    if (valid_folded_value(ale)) {
      str += to_string(folded_value(ale).long_value());
    } else {
      assert(false);
    }

  } else if (ale->value->is(IR_INTEGER_LITERAL) ||
	     ale->value->is(IR_FLOATING_POINT_LITERAL)) {
    cdfg_emit_lit (ale->value, str);

  } else
    cdfg_emit_lit (ale->value, str);

  return true;
}


bool
m_cdfg_emit_expr (pIIR_TypeConversion tc, string &str, RegionStack &rstack, id_type t)
{
  if (valid_folded_value(tc)) {
    // Print folded value if available
    cdfg_emit_folded_value(folded_value(tc), str, rstack, tc->type_mark);
    return true;
  }

  pIIR_Type target_base_type = get_base_type(tc->type_mark);
  pIIR_Declaration target_type_decl = get_declaration(tc->type_mark);
  string cast_start;

  string result_str;
  string expr_str;
  cdfg_emit_expr(tc->expression, expr_str, rstack, t);
  
  if (target_base_type->is(IR_INTEGER_TYPE))
    result_str += expr_str;

  else if (target_base_type->is(IR_ENUMERATION_TYPE))
    result_str += expr_str;

  else if (target_base_type->is(IR_PHYSICAL_TYPE))
    result_str += expr_str;

  else if (target_base_type->is(IR_FLOATING_TYPE))
    result_str += expr_str;

  else if (is_array_type(target_base_type)) {
    pIIR_ArrayType target_array_base_type = pIIR_ArrayType(target_base_type);  
    result_str += "(list array-type-conversion \"" + 
      get_escaped_string(get_long_name(get_declaration(target_array_base_type))) + "\" " + 
      expr_str + ")";
    
  } else
    assert(false);

  str += result_str;

  return false;
}

bool
m_cdfg_emit_expr (pIIR_QualifiedExpression qe, string &str, RegionStack &rstack, id_type t)
{
  cdfg_emit_expr (qe->expression, str, rstack, t);

  return false;
}

bool
m_cdfg_emit_expr (pIIR_EnumLiteralReference elr, string &str, RegionStack &rstack, id_type t)
{
  str += to_string(elr->value->enum_pos);

  return true;
}

bool
m_cdfg_emit_expr (pIIR_ArrayReference aor, string &str, RegionStack &rstack, id_type t)
{
  str += "(list array-element-reference ";
  cdfg_emit_expr (aor->array, str, rstack, t);
  for (pIIR_ExpressionList il = aor->indices; il; il = il->rest)
    {
      str += " ";
      bool simple = cdfg_emit_expr (il->first, str, rstack, t);
    }
  str +=")";

  return false;
}


bool
m_cdfg_emit_expr (pIIR_ArrayLiteralExpression ale, string &str, RegionStack &rstack, id_type t)
{
  // Array literals are always folded. Hence, valid_folded_value
  // should return true!
  assert(valid_folded_value(ale));

  cdfg_emit_folded_value(folded_value(ale), str, rstack, ale->subtype);

  return false;
}


bool
m_cdfg_emit_expr (pIIR_RecordReference ror, string &str, RegionStack &rstack, id_type t)
{
  str += "(list record-element-reference ";
  cdfg_emit_expr (ror->record, str, rstack, t);
  str += " " + to_string(ror->element->declaration_pos) + ")";

  return false;
}

bool
m_cdfg_emit_expr (pIIR_RecordAggregate ra, string &str, RegionStack &rstack, id_type t)
{
  str += "{ ";
  for (pIIR_ElementAssociationList al = ra->element_association_list;
       al; al = al->rest)
    {
      emit_id (al->first->element->declarator, str, rstack);
      str += ": ";
      cdfg_emit_expr (al->first->value, str, rstack, t);
      if (al->rest)
	str += ", ";
    }
  str += " }";

  return false;
}


bool
m_cdfg_emit_expr (pIIR_ArrayAggregate aa, string &str, RegionStack &rstack, id_type t)
{
  // Subtype of aggregate expression. At least the range direction will
  // be used...
  string dest_type_str, value_str;
  pIIR_Type dest_type = aa->subtype;
  int dim_number = 1;
  if(dest_type->is(VAUL_SUBARRAY_TYPE)) {
    // If the aggreate is an multi-dimensional then a node
    // VAUL_SubarrayType is used to describe the (sub)type of the
    // sub-aggregate
    dest_type = pVAUL_SubarrayType(aa->subtype)->complete_type->declaration->type;
    pIIR_ArrayType at = pVAUL_SubarrayType(aa->subtype)->complete_type;
    // Determine dimension of main array to which the aggregate
    // belongs
    int dim_counter = 0;
    for (pIIR_TypeList tl = at->index_types; tl; tl = tl->rest)
      dim_counter++;
    // Next, determine the index associated with the array
    // aggregate. Note that we can only count how many dimensions are
    // left from where the aggregate starts.
    int current_dim_counter = 0;
    for (pIIR_TypeList tl = pVAUL_SubarrayType(aa->subtype)->index_types; tl; tl = tl->rest)
      current_dim_counter++;
    // Now, determine the index number the aggregate belongs to
    dim_number = dim_counter - current_dim_counter + 1;
    // Setup dest_type_str and dest_type_info_str
    dest_type_str = "\"" + get_escaped_string(get_long_name(get_declaration(dest_type))) + "\" " + to_string(dim_number);

  } else if (dest_type->is(IR_ARRAY_TYPE)) {
    dest_type = aa->subtype->declaration->type;
    dest_type_str = "\"" + get_escaped_string(get_long_name(get_declaration(dest_type))) + "\"";

  } else {
    dest_type_str = "\"" + get_escaped_string(get_long_name(get_declaration(dest_type))) + "\"";
  }

  // handle choices
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) {
    pIIR_IndexedAssociation ia = al->first;
    // Emit choice value 
    value_str += " (list choice ";
    if (ia->is(IR_SINGLE_INDEXED_ASSOCIATION)) {
      cdfg_emit_expr(pIIR_SingleIndexedAssociation(ia)->index, value_str, rstack, t) + " ";

    } else if (ia->is(IR_RANGE_INDEXED_ASSOCIATION)) {
      cdfg_emit_expr(pIIR_RangeIndexedAssociation(ia)->index_range, value_str, rstack, t) + " ";

    } else if (ia->is(IR_OTHERS_INDEXED_ASSOCIATION)) {
      value_str += "others ";
      
    }

    cdfg_emit_expr(ia->value, value_str, rstack, t);
    value_str += ")";
  }

  str += "(create-array-aggregate " + dest_type_str + " (list" + value_str + "))";
  
  return false;
}



bool
m_cdfg_emit_expr (pIIR_SliceReference sr, string &str, RegionStack &rstack, id_type t)
{
  // Get slice range
  vector<RangeDescriptor> range_desc = get_discrete_range(sr->range, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<string, string> range = 
    range_desc[0].cdfg_rangedes_to_string(rstack, t);

  string result = "(list array-slice ";
  cdfg_emit_expr (sr->array, result, rstack, t);
  result += " (list range " + range.left + " " + range.dir + " " + range.right + "))";

  str += result;

  return false;
}


bool
m_cdfg_emit_expr (pIIR_AccessReference aor, string &str, RegionStack &rstack, id_type t)
{
  string result = "(list access-ref ";
  cdfg_emit_expr (aor->access, result, rstack, t);
  result += ")";

  str += result;

  return false;
}



bool
m_cdfg_emit_expr (pIIR_SignalAttr asr, string &str, RegionStack &rstack, id_type t)
{
  assert(false);

  return false;
}


bool
m_cdfg_emit_expr (pIIR_AttrTypeFunc atf, string &str, RegionStack &rstack, id_type t)
{
  pIIR_Type return_type = get_base_type(atf->subtype);

  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(atf)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    cdfg_emit_folded_value(folded_value(atf), str, rstack, return_type);
    return true;

  } else {
    // ******************************************************************
    // The attribute result could not be determined at compile
    // time.
    // ******************************************************************
    string result = "(list attribute-type-func-call-";

    // Finally, handle the various attributes
    // ***** RIGHTOF *******************************************
    if (atf->is(IR_ATTR_RIGHTOF)) {
      result += "rightof";
      
      // ***** LEFTOF *******************************************
    } else if (atf->is(IR_ATTR_LEFTOF)) {
      result += "leftof";
      
      // ***** PRED *******************************************
    } else if (atf->is(IR_ATTR_PRED)) {
      result += "pred";
      
      // ***** SUCC *******************************************
    } else if (atf->is(IR_ATTR_SUCC)) {
      result += "succ";
      
      // ***** VAL *******************************************
    } else if (atf->is(IR_ATTR_VAL)) {
      result += "val";
      
      // ***** POS *******************************************
    } else if (atf->is(IR_ATTR_POS)) {
      result += "pos";
      
      // ***** VALUE *******************************************
    } else if (atf->is(IR_ATTR_VALUE)) {
      codegen_error.error("%:error: sorry, attribute VALUE is not supported yet", atf);
      
      // ***** IMAGE *******************************************
    } else if (atf->is(IR_ATTR_IMAGE)) {
      codegen_error.error("%:error: sorry, attribute IMAGE is not supported yet", atf);
      
    } else 
      assert(false);
    
    result += " \"" + get_escaped_string(get_long_name(get_declaration(atf->prefix))) + "\"";
    if (atf->argument != NULL) {
      result += " ";
      cdfg_emit_expr(atf->argument, result, rstack, DEREF);
    }
    result += ")";

    str += result;

    return false;
  }
}


bool
m_cdfg_emit_expr (pIIR_AttrTypeValue atf, string &str, RegionStack &rstack, id_type t)
{
  pIIR_Type return_type = get_base_type(atf->subtype);

  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(atf)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    cdfg_emit_folded_value(folded_value(atf), str, rstack, return_type);
    return true;

  } else {
    // ******************************************************************
    // The attribute result could not be determined at compile
    // time.
    // ******************************************************************
    string result = "(list attribute-type-value-call-";

    // Finally, handle the various attributes
    // ***** LENGTH *******************************************
    if (atf->is(IR_ATTR_LENGTH)) {
      // Actually, this attribute is defined for arrays only!
      assert(false);
      
      // ***** ASCENDING *******************************************
    } else if (atf->is(IR_ATTR_ASCENDING)) {
      result += "ascending";
      
      // ***** HIGH *******************************************
    } else if (atf->is(IR_ATTR_HIGH)) {
      result += "high";
      
      // ***** LOW *******************************************
    } else if (atf->is(IR_ATTR_LOW)) { 
      result += "low";
      
      // ***** RIGHT *******************************************
    } else if (atf->is(IR_ATTR_RIGHT)) {
      result += "right";
      
      // ***** LEFT *******************************************
    } else if (atf->is(IR_ATTR_LEFT)) {
      result += "left";
      
    } else 
      assert(false);
    
    result += " \"" + get_escaped_string(get_long_name(get_declaration(atf->prefix))) + "\"";
    if (atf->argument != NULL) {
      result += " ";
      cdfg_emit_expr(atf->argument, result, rstack, DEREF);
    }
    result += ")";

    str += result;

    return false;
  }
}


bool
m_cdfg_emit_expr (pIIR_Expression e, string &str, RegionStack &rstack, id_type t)
{
  str += "/* IIR_Expression " + string(e->kind_name()) + " */";

  return false;
} 


// Actually, IIR_EnumerationLiteral is not an expression but we need
// this method for internal use
bool
m_cdfg_emit_expr (pIIR_EnumerationLiteral e, string &str, RegionStack &rstack, id_type t)
{
  str += to_string(e->enum_pos);

  return true;
}

