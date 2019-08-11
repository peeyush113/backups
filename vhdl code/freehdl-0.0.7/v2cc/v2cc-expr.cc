#if HAVE_ALLOCA_H
#include <alloca.h>
#endif
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#include <limits.h>

#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "mapping.h"
#include "v2cc-util.h"


// used to generate error messages
extern vaul_error_printer codegen_error;

string sprint_acl(list<string> &acl_list, const string acl_object);


// ******************************************************************************************
// Singleton Class VHDLOperators
// ******************************************************************************************

VHDLOperators* VHDLOperators::single_instance = NULL;

void
VHDLOperators::init_operator_macros()
{
  // Add uniary operator macros
  unary_operator_macro["\"not\""] = "op_not(%s)";
  unary_operator_macro["\"+\""] = "(+%s)";
  unary_operator_macro["\"-\""] = "(-%s)";
  unary_operator_macro["\"abs\""] = "op_abs(%s)";

  // Add binary operator macros
  binary_operator_macro["\"and\""] = "(%s&&%s)";
  binary_operator_macro["\"or\""] = "(%s||%s)";
  binary_operator_macro["\"xor\""] = "op_xor(%s,%s)";
  binary_operator_macro["\"xnor\""] = "op_xnor(%s,%s)";
  binary_operator_macro["\"nand\""] = "op_nand(%s,%s)";
  binary_operator_macro["\"nor\""] = "op_nor(%s,%s)";
  binary_operator_macro["\"=\""] = "(%s==%s)";
  binary_operator_macro["\">\""] = "(%s>%s)";
  binary_operator_macro["\">=\""] = "(%s>=%s)";
  binary_operator_macro["\"<\""] = "(%s<%s)";
  binary_operator_macro["\"<=\""] = "(%s<=%s)";
  binary_operator_macro["\"/=\""] = "(%s!=%s)";
  binary_operator_macro["\"+\""] = "(%s+%s)";
  binary_operator_macro["\"-\""] = "(%s-%s)";
  binary_operator_macro["\"/\""] = "(%s/%s)";
  binary_operator_macro["\"*\""] = "(%s*%s)";
  binary_operator_macro["\"mod\""] = "op_mod(%s,%s)";
  binary_operator_macro["\"rem\""] = "(%s%%%s)";
  binary_operator_macro["\"**\""] = "op_power(%s,%s)";
  binary_operator_macro["\"&\""] = "concat";
}


void
VHDLOperators::init_array_operator_macros()
{
  // Add uniary operator macros
  unary_array_operator_macro["\"not\""] = "op_array_not(%s)";

  // Add binary operator macros
  binary_array_operator_macro["\"and\""] = "op_array_and(%s,%s)";
  binary_array_operator_macro["\"or\""] = "op_array_or(%s,%s)";
  binary_array_operator_macro["\"xor\""] = "op_array_xor(%s,%s)";
  binary_array_operator_macro["\"xnor\""] = "op_array_xnor(%s,%s)";
  binary_array_operator_macro["\"nand\""] = "op_array_nand(%s,%s)";
  binary_array_operator_macro["\"nor\""] = "op_array_nor(%s,%s)";
  binary_array_operator_macro["\"=\""] = "(%s==%s)";
  binary_array_operator_macro["\">\""] = "(!op_array_lt(%s,%s))";
  binary_array_operator_macro["\">=\""] = "(!op_array_le(%s,%s))";
  binary_array_operator_macro["\"<\""] = "op_array_lt(%s,%s)";
  binary_array_operator_macro["\"<=\""] = "op_array_le(%s,%s)";
  binary_array_operator_macro["\"/=\""] = "(!(%s==%s))";
  binary_array_operator_macro["\"&\""] = "concat";

  binary_array_operator_macro["\"sll\""] = "op_array_sll(%s,%s)";
  binary_array_operator_macro["\"srl\""] = "op_array_srl(%s,%s)";
  binary_array_operator_macro["\"sla\""] = "op_array_sla(%s,%s)";
  binary_array_operator_macro["\"sra\""] = "op_array_sra(%s,%s)";
  binary_array_operator_macro["\"rol\""] = "op_array_rol(%s,%s)";
  binary_array_operator_macro["\"ror\""] = "op_array_ror(%s,%s)";
}


void
VHDLOperators::init_user_operator_names()
{
  // Add uniary operator macros
  unary_user_operator_name["\"not\""] = "op_not";
  unary_user_operator_name["\"+\""] = "op_plus";
  unary_user_operator_name["\"-\""] = "op_minus";
  unary_user_operator_name["\"abs\""] = "op_abs";

  // Add binary operator names
  binary_user_operator_name["\"and\""] = "op_and";
  binary_user_operator_name["\"or\""] = "op_or";
  binary_user_operator_name["\"xor\""] = "op_xor";
  binary_user_operator_name["\"xnor\""] = "op_xnor";
  binary_user_operator_name["\"nand\""] = "op_nand";
  binary_user_operator_name["\"nor\""] = "op_nor";
  binary_user_operator_name["\"=\""] = "op_eq";
  binary_user_operator_name["\">\""] = "op_gt";
  binary_user_operator_name["\">=\""] = "op_ge";
  binary_user_operator_name["\"<\""] = "op_lt";
  binary_user_operator_name["\"<=\""] = "op_le";
  binary_user_operator_name["\"/=\""] = "op_ne";
  binary_user_operator_name["\"+\""] = "op_plus";
  binary_user_operator_name["\"-\""] = "op_minus";
  binary_user_operator_name["\"/\""] = "op_div";
  binary_user_operator_name["\"*\""] = "op_mult";
  binary_user_operator_name["\"mod\""] = "op_mod";
  binary_user_operator_name["\"rem\""] = "op_rem";
  binary_user_operator_name["\"**\""] = "op_power";
  binary_user_operator_name["\"&\""] = "op_concat";

  binary_user_operator_name["\"sll\""] = "op_sll";
  binary_user_operator_name["\"srl\""] = "op_srl";
  binary_user_operator_name["\"sla\""] = "op_sla";
  binary_user_operator_name["\"sra\""] = "op_sra";
  binary_user_operator_name["\"rol\""] = "op_rol";
  binary_user_operator_name["\"ror\""] = "op_ror";
}

/* Get unary operator name string */
string VHDLOperators::get_unary_user_operator_name (const string &str)
{
  return unary_user_operator_name [str];
}

/* Get unary operator name string */
string VHDLOperators::get_binary_user_operator_name (const string &str)
{
  return binary_user_operator_name [str];
}

/* Generate string for a call to a binary operator */
string
VHDLOperators::get_operator_call_string(pIIR_FunctionDeclaration fd, const string arg1, const string arg2)
{
  string macro;
  if (is_array_type(fd->interface_declarations->first->subtype))
    macro = binary_array_operator_macro[fd->declarator->text.to_chars()];
  else
    macro = binary_operator_macro[fd->declarator->text.to_chars()];

  int size = macro.length() + arg1.length() + arg2.length() + 1; // Actually "size" is an upper bound
#ifdef HAVE_ALLOCA
  char *str = (char*)alloca (sizeof(char)*size);
#else
  char *str = (char*)malloc (sizeof(char)*size);
#endif
  sprintf(str, macro.c_str(), arg1.c_str(), arg2.c_str());

  string result = str;
  
#ifndef HAVE_ALLOCA
  free (str);
#endif

  return result;
}


/* Generate string for a call to a unary operator */
string
VHDLOperators::get_operator_call_string(pIIR_FunctionDeclaration fd, const string arg1)
{
  string macro;
  if (is_array_type(fd->interface_declarations->first->subtype))
    macro = unary_array_operator_macro[fd->declarator->text.to_chars()];
  else
    macro = unary_operator_macro[fd->declarator->text.to_chars()];

  int size = macro.length() + arg1.length() + 1; // Actually "size" is an upper bound
#ifdef HAVE_ALLOCA
  char *str = (char*)alloca (sizeof(char)*size);
#else
  char *str = (char*)malloc (sizeof(char)*size);
#endif
  sprintf(str, macro.c_str(), arg1.c_str());

  string result = str;

#ifndef HAVE_ALLOCA
  free (str);
#endif  

  return result;
}


// Generated code to concat two arrays
string
VHDLOperators::get_concat_operator_call_string(pIIR_FunctionCall fc, string &arg1, string &arg2, RegionStack &rstack)
{
 pIIR_Expression arg_exp1 = fc->parameter_association_list->first->actual;
 pIIR_Expression arg_exp2 = fc->parameter_association_list->rest->first->actual;

 pIIR_ArrayType dest_type = (pIIR_ArrayType)get_base_type(fc->subtype);
 pIIR_Type arg_type1 = get_base_type(arg_exp1->subtype);
 pIIR_Type arg_type2 = get_base_type(arg_exp2->subtype);
 
 // Determine range of the destination array
 vector<RangeDescriptor> range_desc = 
   get_discrete_range (((pIIR_ScalarSubtype)(dest_type->index_types->first))->range, rstack, IR_NOT_STATIC);
 // Convert to integer strings
 StaticRangeDescriptor<string, string> range = 
   range_desc[0].rangedes_to_string(rstack, get_default_id_type(rstack));

 // First, convert the arguments into appropriate array objects if
 // required
 if (dest_type != arg_type1) {
   // First argument is an element of the resulting array.  Create
   // index range for an array consisting of one single element
   string range_str = range.left + "," + range.dir + "," + range.left;
   // Create call to array consructor. The second constructor argument
   // is a the element value. The first argument is an array_info
   // instance.
   arg1 = qid(dest_type->declaration, rstack, TYPE) + "(new array_info(" + 
     qid(dest_type->declaration, rstack, INFO) + "_INFO.element_type," +
     qid(dest_type->declaration, rstack, INFO) + "_INFO.index_type," + 
     range_str + ",0)," + arg1 + ")";
 }
 if (dest_type != arg_type2) {
   // Second argument is an element of the resulting array.  Create
   // index range for an array consisting of one single element
   string range_str = range.left + "," + range.dir + "," + range.left;
   // Create call to array consructor. The second constructor argument
   // is a the element value. The first argument is an array_info
   // instance.
   arg2= qid(dest_type->declaration, rstack, TYPE) + "(new array_info(" + 
     qid(dest_type->declaration, rstack, INFO) + "_INFO.element_type," +
     qid(dest_type->declaration, rstack, INFO) + "_INFO.index_type," +
     range_str + ",0)," + arg2 + ")";
 }
 
 string str = "concat<" + qid(dest_type->declaration, rstack, TYPE) + "," + 
   qid(dest_type->element_type->declaration, rstack, TYPE)+ ">(" + arg1 + "," + arg2 + ")";

 return str;
}

/* Test whether operator name denotes contat operator */
bool VHDLOperators::is_concat_operator (const string &str)
{
  return binary_operator_macro[str] == "concat";
}


VHDLOperators::VHDLOperators ()
{
  init_operator_macros();
  init_array_operator_macros();
  init_user_operator_names();
}

VHDLOperators* VHDLOperators::get_instance ()
{
  if (single_instance == NULL)
    {
      single_instance = new VHDLOperators;
    }
  return single_instance;
}



// ******************************************************************************************


bool
m_emit_expr (pIIR_AttrSigFunc af, string &str, RegionStack &rstack, id_type t)
{
  string scalar_function_name, composite_function_name;

  // First, determine attribute kind
  if (af->is(IR_ATTR_EVENT)) {
    // Attribute: EVENT
    scalar_function_name = "attr_scalar_EVENT";
    composite_function_name = "attr_composite_EVENT";

  } else if (af->is(IR_ATTR_ACTIVE)) {
    // Attribute: ACTIVE
    scalar_function_name = "attr_scalar_ACTIVE";
    composite_function_name = "attr_composite_ACTIVE";
    
  } else if (af->is(IR_ATTR_LAST_VALUE)) {
    // Attribute: LAST_VALUE
    scalar_function_name = "attr_scalar_LAST_VALUE<" + 
      qid(get_declaration(af->subtype), rstack, TYPE) + ">";
    composite_function_name = "attr_composite_LAST_VALUE<" + 
      qid(get_declaration(af->subtype), rstack, TYPE) + ">";;

  } else if (af->is(IR_ATTR_LAST_EVENT)) {
    // Attribute: LAST_EVENT
    scalar_function_name = "attr_scalar_LAST_EVENT";
    composite_function_name = "attr_composite_LAST_EVENT";

  } else
    // else bail out!
    codegen_error.error("%:error: sorry, this attribute is currently not supported", af);


  string result;
  // Next, create attribute code
  if (af->signal->is(IR_SIMPLE_REFERENCE)) {
    // Prefix is a scalar signal
    result += scalar_function_name + "(";
    emit_expr(af->signal, result, rstack, id_type(SIGNAL, DEFAULT));
    result += ")";

  } else {
    // Prefix is a composite signal
    result += composite_function_name + "(";
    // Get object declaration of the prefix signal
    pIIR_ObjectDeclaration object_decl = get_object_declaration(af->signal);
    result += qid(object_decl, rstack, SIGNAL);

    // Append acl
    list<pair<pIIR_Expression, pIIR_Root> > acl_list;
    get_acl(af->signal, acl_list, rstack, IR_NOT_STATIC, true);
    // Create internal acl
    string internal_acl_name = create_internal_acl(get_acl_size(acl_list), rstack, true);
    // Add acl sequence
    if (af->is(IR_ATTR_LAST_VALUE) && 
	!is_scalar_type(af->subtype)) {
      // If the attribute is LAST_VALUE and the result is not scalar
      // then add a copy of the signal part as an additional parameter
      result += ",&(" + sprint_acl(acl_list, internal_acl_name + "->clear()", rstack, id_type(SIGNAL, ARCHREF)) + "),";
      emit_expr(af->signal, result, rstack, id_type(READER, DEREF));
      result += ")";
    } else
      result += ",&(" + sprint_acl(acl_list, internal_acl_name + "->clear()", rstack, id_type(SIGNAL, ARCHREF)) + "))";
  }

  str += result;

  return false;
}


bool
m_emit_expr (pIIR_AttrArrayFunc at, string &str, RegionStack &rstack, id_type t)
{
  // If the result type is an enumeration type then a cast
  // operation "enumeration(...)" must be done
  pIIR_Type type = get_base_type(at->subtype);
  string cast_start = "", cast_end = "";
  if (type->is(IR_ENUMERATION_TYPE)) {
    cast_start = "enumeration(";
    cast_end = ")";
  }  

  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(at)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    str += cast_start + to_string(folded_value(at).long_value()) + cast_end;
    
    return true;

  } else {

    string info_instance_str;
    if (at->array != NULL) {
      // The range attribute has been applied on an array
      // instance. First, emit code to extract the info instance from
      // the array.
      emit_expr (at->array, info_instance_str, rstack, id_type(READER, DEREF));
      info_instance_str += ".info";
      
    } else
      // The range attribute has been applied on an array type. Emit
      // code to reference the range corresponding info instance.
      info_instance_str += get_type_info_obj(at->array_type, rstack, false);
    
    // Get index number
    int index_number = at->index;
    // Build code to access the array info instance which
    // corresponds with the index_number
    for (int i = 1; i < index_number; i++)
      info_instance_str = "((array_info*)" + info_instance_str + "->element_type)";

    // Finally, emit code to determine the attribute code at runtime
    if (at->is(IR_ATTR_ARRAY_LENGTH))
      str += info_instance_str + "->length";
      
    else if (at->is(IR_ATTR_ARRAY_ASCENDING))
      str += "enumeration(" + info_instance_str + "->index_direction==to?1:0)";
      
    else if (at->is(IR_ATTR_ARRAY_LOW))
      str += cast_start + "min(" + info_instance_str + "->left_bound," + info_instance_str + 
	"->right_bound)" + cast_end;

    else if (at->is(IR_ATTR_ARRAY_HIGH))
      str += cast_start + "max(" + info_instance_str + "->left_bound," + info_instance_str + 
	"->right_bound)" + cast_end;

    else if (at->is(IR_ATTR_ARRAY_RIGHT))
      str += cast_start + info_instance_str + "->right_bound" + cast_end;
      
    else if (at->is(IR_ATTR_ARRAY_LEFT))
      str += cast_start + info_instance_str + "->left_bound" + cast_end;

    else 
      assert(false);

    return false;
  }
}


bool
m_emit_expr (pIIR_FunctionCall fc, string &str, RegionStack &rstack, id_type t)
{
  // If the function call has been folded then return the optimized
  // result instead of actually emitting the function call
  if (valid_folded_value(fc)) {
    emit_folded_value(folded_value(fc), str, rstack, fc->subtype);
    return true; // Ok, were are done!
  }

  VHDLOperators &operators = *VHDLOperators::get_instance ();

  // count the arguments
  int n_args = 0;
  for (pIIR_AssociationList al = fc->parameter_association_list; al; al = al->rest)
    n_args++;

  string arg1, arg2;
  bool int_literal;
  
  switch (get_operator_type(fc->function)) { // Analyze function call type
  case STD_OP: // The function call is a standard operator call
    // emit first operand
    int_literal = emit_expr (fc->parameter_association_list->first->actual, arg1, 
			     rstack, id_type(READER, DEREF)); // First argument
    //if (int_literal) 
    //arg1 = cast(fc->parameter_association_list->first->actual, arg1);

    // emit second operand
    if (n_args == 2) { // Binary operator call
      int_literal = emit_expr (fc->parameter_association_list->rest->first->actual, arg2, 
			       rstack, id_type(READER, DEREF)); // Second argument
      //if (int_literal) 
      //arg2 = cast(fc->parameter_association_list->rest->first->actual, arg2);

      string call_str;
      if (operators.is_concat_operator (fc->function->declarator->text.to_chars()))
	// Add concat operator call. The concat operator is handled
	// differently from the other operators
	call_str = operators.get_concat_operator_call_string(fc, arg1, arg2, rstack);
      else
	// Add operator call to code
	call_str = operators.get_operator_call_string(fc->function, arg1, arg2); 

      // Next, check whether this is a operator call with mixed
      // parameter types (e.g., of the form time * integer or time /
      // real). In this case cast the result to the target type.
      if (string(fc->function->declarator->text.to_chars()) == "\"*\"" ||
	  string(fc->function->declarator->text.to_chars()) == "\"/\"")
	{
	  pIIR_Type arg1_type = get_base_type (fc->function->interface_declarations->first->subtype);
	  pIIR_Type arg2_type = get_base_type (fc->function->interface_declarations->rest->first->subtype);
	  if (arg1_type != arg2_type)
	    {
	      pIIR_Type return_type = get_base_type (fc->function->return_type);
	      if (return_type->is (IR_INTEGER_TYPE))
		call_str = "integer(" + call_str + ")";
	      else if (return_type->is (IR_ENUMERATION_TYPE))
		call_str = "enumeration(" + call_str + ")";
	      else if (return_type->is (IR_PHYSICAL_TYPE))
		call_str = "physical(" + call_str + ")";
	      else if (return_type->is (IR_ENUMERATION_TYPE))
		call_str = "floatingpoint(" + call_str + ")";
	    }
	}
      
      str += call_str;

    } else // Unary operator call
      str += operators.get_operator_call_string(fc->function, arg1); // Add operator call

    break;

  case USER_OP: // The function is an user defined operator call
  case BASIC_OP: // The function is a operator defined in an IEEE
    // library. Currently this is handled like a user defined operator
    // call
  case NO_OP: // A ordinary function call (no operator)
    void emit_subprogram_associations (string&, RegionStack&, pIIR_AssociationList, 
				       pIIR_InterfaceList, list<AccessDescriptor>&);
    str += qid(fc->function, rstack, DEFAULT);
    str += " (";
    emit_subprogram_associations (str, rstack, fc->parameter_association_list,
				  fc->function->interface_declarations,
				  context(fc->function).extra_interface_objects);
    //emit_associations (str, rstack, fc->parameter_association_list,
    //		       fc->function->interface_declarations);
    str += ")";
  }

  return false;
}

bool
m_emit_expr (pIIR_SimpleReference sor, string &str, RegionStack &rstack, id_type t)
{
  // If the reference has been folded then return the optimized result
  // instead of accessing the reference
  if (valid_folded_value(sor)) {
    emit_folded_value(folded_value(sor), str, rstack, sor->subtype);
    return true; // Ok, were are done!
  }

  //emit_noqual_id (sor->object, str, t);
  str += qid (sor->object, rstack, t);

  return false;
}


bool
m_emit_expr (pIIR_NullExpression ne, string &str, RegionStack &rstack, id_type t)
{
  str += "((vhdlaccess)NULL)";
  return true;
}


bool
m_emit_expr (pIIR_Allocator a, string &str, RegionStack &rstack, id_type t)
{
  str += "(" + get_type_info_obj(pIIR_AccessType(a->type_mark)->designated_type, rstack, false) + ")";
  if (a->value != NULL) {
    str += "->clone(const_pointer(";
    emit_expr(a->value, str, rstack, t);
    str += "))";
  } else
    str += "->create()";
    
  return false;
}


void
emit_lit (pIIR_Literal l, string &str)
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
emit_unit (pIIR_PhysicalUnit u, string &str, RegionStack &rstack, int l)
{
  str += qid(u -> type -> declaration, rstack, INFO);
  str += "::scale[" + to_string ( u -> unit_pos)  + "]";
}


bool
m_emit_expr (pIIR_AbstractLiteralExpression ale, string &str, RegionStack &rstack, id_type t)
{
  if (ale->is(IR_PHYSICAL_LITERAL)) {
    if (valid_folded_value(ale)) {
      str += to_string(folded_value(ale).long_value()) + "LL";
    } else {
      assert (false);
      /* str += "(";
	 emit_lit (ale->value, str);
	 str += "*";
	 emit_unit (pIIR_PhysicalLiteral(ale)->unit, str, rstack, 0);
	 str += ")"; */
    }

  } else if (valid_folded_value (ale)) {
    if (ale->value->is(IR_INTEGER_LITERAL))
      str += to_string (folded_value(ale).long_value ());
    else if (ale->value->is(IR_FLOATING_POINT_LITERAL))
      str += (folded_value(ale).original_string () != "") ?
	folded_value(ale).original_string () :
	to_string (folded_value(ale).double_value ());
    else
      abort ();
  } else
    assert (false);
    // emit_lit (ale->value, str);

  return true;
}


bool
m_emit_expr (pIIR_TypeConversion tc, string &str, RegionStack &rstack, id_type t)
{
  if (valid_folded_value(tc)) {
    // Print folded value if available
    emit_folded_value(folded_value(tc), str, rstack, tc->type_mark);
    return true;
  }

  pIIR_Type target_base_type = get_base_type(tc->type_mark);
  pIIR_Declaration target_type_decl = get_declaration(tc->type_mark);
  string cast_start;

  string result_str;
  string expr_str;
  emit_expr(tc->expression, expr_str, rstack, t);
  
  if (target_base_type->is(IR_INTEGER_TYPE))
    if (get_base_type(tc->expression->subtype)->is(IR_FLOATING_TYPE))
      // If the the expression to be converted is a floating point
      // type then we must round the number to the nearest integer
      // value!
      result_str += "integer(rint(" + expr_str + "))";
    else
      result_str += "integer(" + expr_str + ")";

  else if (target_base_type->is(IR_ENUMERATION_TYPE))
    result_str += "enumeration(" + expr_str + ")";

  else if (target_base_type->is(IR_PHYSICAL_TYPE))
    result_str += "physical(" + expr_str + ")";

  else if (target_base_type->is(IR_FLOATING_TYPE))
    result_str += "floatingpoint(" + expr_str + ")";

  else if (is_array_type(target_base_type)) {
    pIIR_ArrayType source_array_base_type = 
      pIIR_ArrayType(get_base_type(tc->expression->subtype));
    pIIR_ArrayType target_array_base_type = pIIR_ArrayType(target_base_type);
  
    // First, considere one-dimensional arrays
    if (target_array_base_type->index_types->rest == NULL) {
      // Next, test whether the target array type is constrained
      if (!is_constrained_array_type(tc->type_mark))
	// If the target array is unconstrained then the source
	// array is passed over by reference so that the array_alias
	// constructor can retrieve the range information from the
	// source array. Note that the actual data is not copied but
	// reused by the array_alias constructor.
	result_str += "array_alias<" + qid(target_type_decl, rstack, TYPE) + " >(" + 
	  get_type_info_obj(tc->type_mark, rstack, false) + "," + expr_str + ")";
      
      else
	// If the target array is constrained then the bounds are
	// determined from the target type. Note that the data part
	// is not copied from the source array. Instead the data
	// pointer of the source is copied.
	result_str += "array_alias<" + qid(target_type_decl, rstack, TYPE) + " >(" + 
	  get_type_info_obj(tc->type_mark, rstack, false) + "," + expr_str + ".data)";
      
    } else
      // Handle multi-dimensional arrays
      result_str += qid(target_type_decl, rstack, TYPE) + "().init(" +
	get_type_info_obj(tc->type_mark, rstack, false) + "," + expr_str + ")";

  } else
    assert(false);

  str += result_str;

  return false;
}

bool
m_emit_expr (pIIR_QualifiedExpression qe, string &str, RegionStack &rstack, id_type t)
{
  emit_expr (qe->expression, str, rstack, t);

  return false;
}

bool
m_emit_expr (pIIR_EnumLiteralReference elr, string &str, RegionStack &rstack, id_type t)
{
  emit_id (elr->value, str, rstack);

  return true;
}

bool
m_emit_expr (pIIR_ArrayReference aor, string &str, RegionStack &rstack, id_type t)
{
  emit_expr (aor->array, str, rstack, t);
  for (pIIR_ExpressionList il = aor->indices; il; il = il->rest)
    {
      str += "[";
      string index;
      bool simple = emit_expr (il->first, index, rstack, t);
      str += index + "]";
    }

  return false;
}


bool
m_emit_expr (pIIR_ArrayLiteralExpression ale, string &str, RegionStack &rstack, id_type t)
{
  // Array literals are always folded. Hence, valid_folded_value
  // should return true!
  assert(valid_folded_value(ale));

  emit_folded_value(folded_value(ale), str, rstack, ale->subtype);

  return false;
}


bool
m_emit_expr (pIIR_RecordReference ror, string &str, RegionStack &rstack, id_type t)
{
  emit_expr (ror->record, str, rstack, t);
  str += ".value()." + nid (ror->element, DEFAULT);

  return false;
}


bool
m_emit_expr (pIIR_RecordAggregate ra, string &str, RegionStack &rstack, id_type t)
{
  pIIR_RecordType rt = pIIR_RecordType (get_base_type (ra->subtype->base));

  str += qid (rt, rstack, TYPE) + "().init(" + get_type_info_obj(rt, rstack, false) + ")";
  
  for (pIIR_ElementAssociationList al = ra->element_association_list;
       al; al = al->rest)
    {
      // check out whether the SAME value has been used for another
      // record element in the aggregate (e.g., this might happen in
      // case of an "others" choice).
      pIIR_ElementAssociationList test_al = ra->element_association_list;
      for (; test_al != al; test_al = test_al->rest)
	if (test_al->first->value ==  al->first->value)
	  break;
      if (test_al != al)
	// If the same value expression has been used then copy the
	// corresponding value to its destination instead of emitting
	// the same value expression again.
	str += ".aggregate_copy(" + to_string(al->first->element->declaration_pos) + "," +
	  to_string(test_al->first->element->declaration_pos) + ")";
      else {
	// Othewise, just call aggregate_set where the fist parameter
	// is the record element position number (first record element
	// is associated with number 0, ...). The second paramter
	// points to the appropriate value expression.
	str += ".aggregate_set(" + to_string(al->first->element->declaration_pos) + ",";
	str += "const_pointer(";
	emit_expr (al->first->value, str, rstack, t);
	str += "))";
      }
    }

  return false;
}


bool
m_emit_expr (pIIR_ArrayAggregate aa, string &str, RegionStack &rstack, id_type t)
{
  // Subtype of aggregate expression. At least the range direction will
  // be used...
  string dest_type_str, dest_type_info_str;
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
    dest_type_str = qid(get_declaration(dest_type), rstack, TYPE);
    dest_type_info_str = get_type_info_obj(dest_type, rstack, false);
    for (int i = 1; i <= dim_counter - current_dim_counter; i++) {
      dest_type_str += "::E_type";
      dest_type_info_str = "parray_info(" + dest_type_info_str + "->element_type)";
    }

  } else if (dest_type->is(IR_ARRAY_TYPE)) {
    dest_type = aa->subtype->declaration->type;
    dest_type_str = qid(get_declaration(dest_type), rstack, TYPE);
    dest_type_info_str = get_type_info_obj(get_basic_type(dest_type), rstack, false);

  } else {
    dest_type_str = qid(get_declaration(dest_type), rstack, TYPE);
    dest_type_info_str = get_type_info_obj(get_basic_type(dest_type), rstack, false);
  }
  // Get range type of aggregate and determine left bound, right
  // bound, direction and length of aggregat. Note that if the
  // aggregate subtype cannot be determined from the context then
  // dest_range will point to the corresponding index range of the
  // unconstrained array associated with the aggregate.
  vector<RangeDescriptor> range_desc = get_discrete_range(dest_type, rstack, IR_NOT_STATIC);
  // Extract bounds from aggregate range type. Perhaps these
  // bounds will be used to determine the range bounds of the aggregat.
  string range_str;
  StaticRangeDescriptor<string, string> range = 
    range_desc[dim_number - 1].rangedes_to_string(rstack, t);
  string dest_direction_str = 
    (dest_direction(aa) == IR_DIRECTION_UP? "to" : "downto"); // Direction of aggregate

  int association_count = 0; // Number of associations
  int max_len = 0; // Max index range length of a single choice
  pIIR_IndexedAssociation max_len_choice = NULL; // choice with longest range

  // First, take a look at all choices to determine the choice which
  // covers the largest range. However, an others choice will always
  // be selected as max_len_choice. Further, the number of
  // associations are counted.
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) { 
    if (al->first->is(IR_OTHERS_INDEXED_ASSOCIATION)) { // others choice
      max_len = INT_MAX; // set length value so that this entry is not overwritten
      max_len_choice = al->first;
    } else {
      if (max_len < length(al->first)) {
	max_len = length(al->first);
	max_len_choice = al->first;
      }
    }

    association_count++; // Count number of association 
  }
  // If no max length choice could be found (e.g., because the choice
  // length could not be determined at compile time) then just take
  // the very first association element as max_len_choice.
  if (max_len_choice == NULL)
    max_len_choice = aa->indexed_association_list->first;

  // *****************************************************************************
  // Now, generate the code. First. check some special cases.
  // *****************************************************************************
  string value_str;
  if (has_others(aa)) { // Does the aggregate include an others choice?
    // If the answer is yes, then the subtype of the aggregate must be
    // determinable from the context. Get value expression of others choice.
    emit_expr(pIIR_OthersIndexedAssociation(max_len_choice)->value, value_str, rstack, t);
    // Determine range of the array aggregate.
    range_str = range.left + "," + range.dir + "," + range.right;

  } else {
    // Ok, aggregate does not have an others choice. Hence, the array
    // bounds are directly determined from the choices. Generate code
    // for the first array instance. The initial array instance is
    // created from those choice which covers the longest range.
    if (association_count == 1) { 
      // Ok, there is a single choice
      if (max_len_choice->is(IR_SINGLE_INDEXED_ASSOCIATION)) {
	// Array contains only a single element
	pIIR_SingleIndexedAssociation saa = pIIR_SingleIndexedAssociation(max_len_choice);
	string index_str;
	if (named_association(aa)) {
	  // In case of named association use index value of choice
	  emit_expr(saa->index, index_str, rstack, DEFAULT);
	} else
	  // In case of positional association use left bound of
	  // aggregate type
	  index_str = range.left;
	
	range_str = index_str + "," + dest_direction_str + "," + index_str;

      } else if (max_len_choice->is(IR_RANGE_INDEXED_ASSOCIATION)) {
	// Array contains a single range choice. Note that the range
	// does not have to be locally static in this case.
	pIIR_RangeIndexedAssociation raa = pIIR_RangeIndexedAssociation(max_len_choice);
	vector<RangeDescriptor> range_desc = 
	  get_discrete_range(raa->index_range, rstack, IR_NOT_STATIC);
	StaticRangeDescriptor<string, string> range = 
	  range_desc[0].rangedes_to_string(rstack, t);

	if (!is_constrained_array_type(dest_type))
	  range_str = range.left + "," + range.dir + "," + range.right;
	else if (dest_direction_str == range.dir)
	  range_str = range.left + "," + dest_direction_str + "," + range.right;
	else
	  range_str = range.right + "," + dest_direction_str + "," + range.left;

      } else 
	// This should never happen!
	assert(false);

    } else
      // Ok, there are more than one choices. Hence, we use min_index
      // and max_index to setup the array range
      if (named_association(aa)) {
	// If the aggregate uses named association then the index
	// bounds are derived from the index number given in the
	// aggregate
	if (dest_direction_str == "to")
	  range_str = to_string(min_index(aa)) + "," + dest_direction_str + "," + to_string(max_index(aa));
	else
	  range_str = to_string(max_index(aa)) + "," + dest_direction_str + "," + to_string(min_index(aa));

      } else {
	// If the aggregate uses positional association then the
	// bounds are derived from the left bound of the target
	if (dest_direction_str == "to")
	  range_str = range.left + "," + dest_direction_str + "," + range.left + "+" + to_string(max_index(aa));
	else
	  range_str = range.left + "," + dest_direction_str + "," + range.left + "-" + to_string(max_index(aa));
      }

    // Generate value of choice 
    if (max_len_choice->is(IR_SINGLE_INDEXED_ASSOCIATION)) 
      emit_expr(pIIR_SingleIndexedAssociation(max_len_choice)->value, value_str, rstack, t);
    else if (max_len_choice->is(IR_RANGE_INDEXED_ASSOCIATION))
      emit_expr(pIIR_RangeIndexedAssociation(max_len_choice)->value, value_str, rstack, t);
    else
      assert(false);
  }

  // Create call to array constructor. The second constructor argument
  // is the element value. The first argument is an array_info
  // instance.
  str += dest_type_str + "(new array_info(" + dest_type_info_str + "->element_type," +
    dest_type_info_str + "->index_type," + range_str + ",0)," + value_str + ")";
  // If only a single choice is given then were done.
  if (association_count == 1) return false;

  // Next, handle the remaining choices
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest) {
    pIIR_IndexedAssociation ia = al->first;
    if (ia == max_len_choice) continue; // Skip choice if it has been already handled
    // Emit choice value 
    value_str = "";
    emit_expr(ia->value, value_str, rstack, t);
    if (ia->is(IR_SINGLE_INDEXED_ASSOCIATION) && !named_association(aa)) {
      // If choice is a single indexed *positional* association then
      // index number of the element is determined by adding the
      // choice number (stored in min_index) to the left bound of the
      // aggregate (stored in left_str).
      string index_str = range.left + (dest_direction_str == "to"? "+" : "-") + 
	to_string(min_index(ia));
      str += ".aggregate_set(" + index_str + ",to," + index_str + "," + value_str + ")";      
    } else
      // Add code to set the corresponding array elements 
      str += ".aggregate_set(" + to_string(min_index(ia)) + ",to," + 
	to_string(max_index(ia)) + "," + value_str + ")";
  }
  
  return false;
}



bool
m_emit_expr (pIIR_SliceReference sr, string &str, RegionStack &rstack, id_type t)
{
  // Get slice range
  vector<RangeDescriptor> range_desc = get_discrete_range(sr->range, rstack, IR_NOT_STATIC);
  StaticRangeDescriptor<string, string> range = 
    range_desc[0].rangedes_to_string(rstack, t);

  pIIR_TypeDeclaration type_declaration = get_declaration(sr->array->subtype);
  str += qid(type_declaration, rstack, id_type(TYPE | ALIAS, DEFAULT));

  str += "(new array_info(";
  str += get_type_info_obj(get_base_type(sr->array->subtype), rstack, false) + "->element_type," + 
    get_type_info_obj(get_base_type(sr->array->subtype), rstack, false) + "->index_type," + 
    range.left + "," + range.dir + "," + range.right + ",0),&";

  emit_expr (sr->array, str, rstack, t);
  str += "[" + range.left + "]";

  str += ")";

  return false;
}

bool
m_emit_expr (pIIR_AccessReference aor, string &str, RegionStack &rstack, id_type t)
{
  str += "deref<" + qid(aor->subtype, rstack, TYPE) + " >(";
  emit_expr (aor->access, str, rstack, t);
  str += ")";

  return false;
}


void
emit_builtin_id (IR_Kind k, string &str)
{
  str += tree_kind_name(k);
}


bool
m_emit_expr (pIIR_SignalAttr asr, string &str, RegionStack &rstack, id_type t)
{
  emit_builtin_id (asr->kind(), str);
  str += "(";
  emit_expr (asr->signal, str, rstack, t);
  str += ")";

  return false;
}

bool
m_emit_expr (pIIR_AttrTypeFunc atf, string &str, RegionStack &rstack, id_type t)
{
  // If the result type is an enumeration type then a cast
  // operation "enumeration(...)" must be done
  pIIR_Type return_type = get_base_type(atf->subtype);

  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(atf)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    emit_folded_value(folded_value(atf), str, rstack, return_type);
    return true;

  } else {
    // ******************************************************************
    // The attribute result could not be determined at compile
    // time. Hence, generate code to determine the corresponding value
    // at runtime.
    // ******************************************************************
    string info_instance_str = get_type_info_obj(atf->prefix, rstack, false);
    pIIR_Type prefix_base_type = get_base_type(atf->prefix);
    string argument_str;
    if (atf->argument != NULL)
      emit_expr(atf->argument, argument_str, rstack, id_type(READER, DEREF));

    // Determine range of prefix type
    vector<RangeDescriptor> type_range_des = get_discrete_range(atf->prefix, rstack, IR_NOT_STATIC); 
    // type_range_des should contain exactly one single
    // RangeDescriptor instance
    assert(type_range_des.size() == 1);
    // Try to fold range descriptor
    type_range_des[0].constant_fold_rangedes(rstack);
    // Determine left, right and direction of range. is_static stores
    // whether the corresponding value is static.
    StaticRangeDescriptor<lint, IR_Direction> lint_range;
    StaticRangeDescriptor<double, IR_Direction> double_range;
    
    if (get_base_type (atf->prefix)->is (IR_FLOATING_TYPE))
      double_range = type_range_des[0].rangedes_to_double (rstack);
    else
      lint_range = type_range_des[0].rangedes_to_lint (rstack);

    // Finally, handle the various attributes
    // ***** RIGHTOF *******************************************
    // Note that this attribute is not defined for floatingpoint types
    if (atf->is(IR_ATTR_RIGHTOF)) {
      // The resulting string looks like:
      // integer_INFO->check(value+(integer_INFO->left_bound <
      // integer_INFO->right_bound?+1:-1))
      if (lint_range.valid[1])
	// If the range direction could be determined then emit
	// optimized code
	str += info_instance_str + "->check(" + argument_str + (lint_range.dir == IR_DIRECTION_UP? "+1": "-1") + ")";
      else
	str += info_instance_str + "->check(" + argument_str + "+(" + info_instance_str + "->left_bound < " + 
	  info_instance_str + "->right_bound?+1:-1))";
      
      // ***** LEFTOF *******************************************
      // Note that this attribute is not defined for floatingpoint types
    } else if (atf->is(IR_ATTR_LEFTOF)) {
      // The resulting string looks like:
      // integer_INFO->check(value+(integer_INFO->left_bound < integer_INFO->right_bound?+1:-1))
      if (lint_range.valid[1])
	// If the range direction could be determined then emit
	// optimized code
	str += info_instance_str + "->check(" + argument_str + (lint_range.dir == IR_DIRECTION_UP? "-1": "+1") + ")";
      else
	str += info_instance_str + "->check(" + argument_str + "-(" + info_instance_str + "->left_bound < " + 
	  info_instance_str + "->right_bound?+1:-1))";
      
      // ***** PRED *******************************************
      // Note that this attribute is not defined for floatingpoint types
    } else if (atf->is(IR_ATTR_PRED)) {
      str += info_instance_str + "->check(" + argument_str + "-1)";
      
      // ***** SUCC *******************************************
      // Note that this attribute is not defined for floatingpoint types
    } else if (atf->is(IR_ATTR_SUCC)) {
      str += info_instance_str + "->check(" + argument_str + "+1)";
      
      // ***** VAL *******************************************
      // Note that this attribute is not defined for floatingpoint types
    } else if (atf->is(IR_ATTR_VAL)) {
      str += info_instance_str + "->check(" + argument_str + ")";
      
      // ***** POS *******************************************
      // Note that this attribute is not defined for floatingpoint types
    } else if (atf->is(IR_ATTR_POS)) {
      str += info_instance_str + "->check(" + argument_str + ")";
      
      // ***** VALUE *******************************************
    } else if (atf->is(IR_ATTR_VALUE)) {
      str += "((" + qid(prefix_base_type->declaration, rstack, TYPE) +
	+ ")attribute_value(" + info_instance_str + "," + argument_str + "))";
      
      // ***** IMAGE *******************************************
    } else if (atf->is(IR_ATTR_IMAGE)) {
      str += "attribute_image(" + info_instance_str + ",const_pointer(" + argument_str + "))";
      
    } else 
      assert(false);
    
    return false;
  }
}


bool
m_emit_expr (pIIR_AttrTypeValue atf, string &str, RegionStack &rstack, id_type t)
{
  // If the result type is an enumeration type then a cast
  // operation "enumeration(...)" must be done
  pIIR_Type return_type = get_base_type(atf->subtype);

  // First, check whether the attribute was folded successfully.
  if (valid_folded_value(atf)) {
    // Emit the folded value instead of accessing determining the
    // attribute at runtime
    emit_folded_value(folded_value(atf), str, rstack, return_type);
    return true;

  } else {
    // ******************************************************************
    // The attribute result could not be determined at compile
    // time. Hence, generate code to determine the corresponding value
    // at runtime.
    // ******************************************************************
    string info_instance_str = get_type_info_obj(atf->prefix, rstack, false);
    pIIR_Type prefix_base_type = get_base_type(atf->prefix);
    string argument_str;
    if (atf->argument != NULL)
      emit_expr(atf->argument, argument_str, rstack, DEREF);

    // Determine range of prefix type
    vector<RangeDescriptor> type_range_des = 
      get_discrete_range(atf->prefix, rstack, IR_NOT_STATIC); 
    // type_range_des should contain exactly one single
    // RangeDescriptor instance
    assert(type_range_des.size() == 1);
    // Try to fold range descriptor
    type_range_des[0].constant_fold_rangedes(rstack);
    // Determine left, right and direction of range. is_static stores
    // whether the corresponding value is static.
    StaticRangeDescriptor<lint, IR_Direction> lint_range;
    StaticRangeDescriptor<double, IR_Direction> double_range;
    
    bool is_floatingpoint_type = false;
    if (get_base_type (atf->prefix)->is (IR_FLOATING_TYPE))
      {
	double_range = type_range_des[0].rangedes_to_double (rstack);
	is_floatingpoint_type = true;
      }
    else
      {
	lint_range = type_range_des[0].rangedes_to_lint (rstack);
	is_floatingpoint_type = false;
      }

    // Finally, handle the various attributes
    // ***** LENGTH *******************************************
    if (atf->is(IR_ATTR_LENGTH)) {
      // Actually, this attribute is defined for arrays only!
      assert(false);
      
      // ***** ASCENDING *******************************************
    } else if (atf->is(IR_ATTR_ASCENDING)) {
      str += "enumeration(" + info_instance_str + "->left_bound < " + 
	info_instance_str + "->right_bound?1:0)";
      
      // ***** HIGH *******************************************
    } else if (atf->is(IR_ATTR_HIGH)) {
      if (prefix_base_type->is(IR_ENUMERATION_TYPE))
	str += "max(" + info_instance_str + "->left_bound, " + 
	  info_instance_str + "->right_bound?)";
      else
	str += info_instance_str + "->high_bound";
      
      // ***** LOW *******************************************
    } else if (atf->is(IR_ATTR_LOW)) { 
      if (prefix_base_type->is(IR_ENUMERATION_TYPE))
	str += "min(" + info_instance_str + "->left_bound, " + 
	  info_instance_str + "->right_bound?)";
      else
	str += info_instance_str + "->low_bound";
      
      // ***** RIGHT *******************************************
    } else if (atf->is(IR_ATTR_RIGHT)) {
      str += info_instance_str + "->left_bound";

      
      // ***** LEFT *******************************************
    } else if (atf->is(IR_ATTR_LEFT)) {
      str += info_instance_str + "->right_bound";
      
    } else 
      assert(false);
    
    return false;
  }
}


bool
m_emit_expr (pIIR_Expression e, string &str, RegionStack &rstack, id_type t)
{
  str += "/* IIR_Expression " + string(e->kind_name()) + " */";

  return false;
} 


// Actually, IIR_EnumerationLiteral is not an expression but we need
// this method for internal use
bool
m_emit_expr (pIIR_EnumerationLiteral e, string &str, RegionStack &rstack, id_type t)
{
  str += qid(e->subtype->declaration, rstack, TYPE) + "(" + to_string(e->enum_pos) + ")";

  return true;
}

