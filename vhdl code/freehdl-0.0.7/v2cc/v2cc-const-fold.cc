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
#include <math.h>
#include <limits.h>

#include "mapping.h"
#include "v2cc-util.h"



// Used to generate error messages
extern vaul_error_printer codegen_error;



// ******************************************************************************************
// Name: m_constant_fold, generic function
//
// Description: performs constant folding optimizations on nodes
//
// Return value: returns number of errors found during folding
//
// ******************************************************************************************


int
m_constant_fold (pIIR_Type st, RegionStack &rstack)
{
  if (done(st) & CONST_FOLD) return 0; else  done(st) |= CONST_FOLD;

  int error_count = 0;
  if (st->declaration != NULL)
    error_count += constant_fold(st->declaration->type, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_PhysicalType st, RegionStack &rstack)
{
  if (done(st) & CONST_FOLD) return 0; else  done(st) |= CONST_FOLD;
  
  int error_count = 0;
  if (st->base != NULL)
    error_count += constant_fold(st->base, rstack);
  
  for (pIIR_UnitList ul = st->units; ul; ul = ul->rest)
    if (ul->first->multiplier)
      error_count += constant_fold(ul->first->multiplier, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_ScalarSubtype st, RegionStack &rstack)
{
  if (done(st) & CONST_FOLD) return 0; else  done(st) |= CONST_FOLD;
  
  int error_count = 0;
  error_count += constant_fold(st->immediate_base, rstack);

  if (st->range != NULL)
    error_count += constant_fold(st->range, rstack);
  
  return error_count;
}


int
m_constant_fold (pIIR_ArrayType st, RegionStack &rstack)
{
  if (done(st) & CONST_FOLD) return 0; else  done(st) |= CONST_FOLD;
  
  int error_count = 0;
  for (pIIR_TypeList tl = st->index_types; tl; tl = tl->rest)
    error_count += constant_fold(tl->first, rstack);
  
  error_count += constant_fold(st->element_type, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_ArraySubtype st, RegionStack &rstack)
{
  if (done(st) & CONST_FOLD) return 0; else  done(st) |= CONST_FOLD;
  
  int error_count = 0;
  error_count += constant_fold(st->immediate_base, rstack);
  for (pIIR_TypeList tl = st->constraint; tl; tl = tl->rest)
    error_count += constant_fold(tl->first, rstack);
  
  return error_count;
}


int
m_constant_fold (pIIR_QualifiedExpression e, RegionStack &rstack)
{
  if (done(e) & CONST_FOLD) return 0; else  done(e) |= CONST_FOLD;
  
  int error_count = 0;
  error_count += constant_fold(e->type_mark, rstack);
  error_count += constant_fold(e->expression, rstack);
  
  return error_count;
}


int
m_constant_fold(pIIR_AttrSigFunc ase, RegionStack &rstack)
{
  if (done(ase) & CONST_FOLD) return 0; else  done(ase) |= CONST_FOLD;

  int error_count = constant_fold(ase->signal, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_ArrayLiteralExpression le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  int error_count = 0;
  // Get the valid enumeration items
  pIIR_EnumerationLiteralList enum_item_list = 
    pIIR_EnumerationType(get_base_type(pIIR_ArrayType(get_base_type(le->subtype))->element_type))->enumeration_literals;

  char *str = le->value->text.to_chars() + 1; // Skip leading "
  int length = strlen(str) - 1; // Get length of array
  vector<int> literal_value(length);

  // Get enumeration pos for each item
  int i = 0;
  string item = "'"; 
  while (true) {
    if (*str == '"' && *(str + 1) == '\0') break; // Skip trailing "
    item = string("'") + *str + string("'");
    literal_value[i] = literal_to_pos(enum_item_list, item);
    i++;
    str++;
  }

  // Store folded value
  folded_value(le).array_literal_value() = literal_value;
  valid_folded_value(le) = true;

  // Currently array literals are not folded!
  return error_count;
}


int
m_constant_fold(pIIR_EnumLiteralReference le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  int error_count = constant_fold(le->value, rstack);
  folded_value(le).long_value() = le->value->enum_pos;
  valid_folded_value(le) = true;

  return error_count;
}


int
m_constant_fold(pIIR_CharacterLiteral le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  int error_count = 0;
  folded_value(le).long_value() = (long long int)(le->text.to_chars())[1];
  valid_folded_value(le) = true;

  return error_count;
}


int
m_constant_fold(pIIR_StringLiteral le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  int error_count = 0;
  // String literals are currently not folded
  return error_count;
}



int
m_constant_fold(pIIR_EnumerationLiteral el, RegionStack &rstack)
{
  if (done(el) & CONST_FOLD) return 0; else  done(el) |= CONST_FOLD;

  folded_value(el).long_value() = lint(el->enum_pos);
  valid_folded_value(el) = true;

  return 0;
}


int
m_constant_fold(pIIR_IntegerLiteral le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  pair<bool, StaticLint> result = string_to_lint (le->text.to_chars());
  folded_value(le) = result.second;
  valid_folded_value(le) = result.first;

  // Retrun an error of the constant could not be folded!
  return  result.first? 0 : 1;
}


int
m_constant_fold(pIIR_FloatingPointLiteral le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  pair<bool, StaticDouble> result = string_to_double (le->text.to_chars());
  folded_value(le) = result.second;
  valid_folded_value(le) = result.first;

  // Retrun an error of the constant could not be folded!
  return  result.first? 0 : 1;
}


int
m_constant_fold(pIIR_AbstractLiteralExpression ale, RegionStack &rstack)
{
  if (done(ale) & CONST_FOLD) return 0; else  done(ale) |= CONST_FOLD;

  int error_count = constant_fold(ale->value, rstack);
  if (valid_folded_value(ale->value))
    {
      folded_value(ale) =  folded_value(ale->value);
      valid_folded_value(ale) = valid_folded_value(ale->value);
    }

  return error_count;
}

// function is used to fold a scalar value
template<class T, class A>
T perform_operation(pIIR_FunctionCall fc, A a)
{
  string op_str = fc->function->declarator->text.to_chars();

  if (op_str == "\"not\"")
    return T(int(a)? 0 : 1);
  else if (op_str == "\"+\"")
    return T(a);
  else if (op_str == "\"-\"")
    return T(A(-1) * a);
  else if (op_str == "\"abs\"")
    return T((a < 0)? -a : a);
  else
    assert(false);
}

// Returns 0 if parameter is equal to 0, -1 if the parameter is less
// than 0, 1 otherwise
template<class X>
int sign(const X a)
{
  if (a == X(0))
    return 0;
  else if (a < X(0))
    return -1;
  else 
    return 1;
}


// Overloaded functions returning the min/max values of the
// corresponding type. Note that the parameter dummy is actually only
// used to select the corresponding function.
double max_huge_value(double dummy) { return HUGE_VAL; }
double min_huge_value(double dummy) { return -HUGE_VAL; }
lint max_huge_value(lint dummy) { return PHYSICAL_MAX; }
lint min_huge_value(lint dummy) { return PHYSICAL_MIN; }

//*******************************************************
// Add operations
//*******************************************************
template<class X, class Y>
X calculate_plus(const X a, const Y b)
{
  X result = a + b;

  // Check whether the sign of the result is ok
  if (abs(sign(a) + sign(b)) == 2 &&
      sign(a) != sign(result))
    // If the result is wrong then return either the max or the min
    // lint value
    return sign(a)==1? max_huge_value(a) : min_huge_value(a);
  else
    // Return result of the operation
    return result;
}

double
calculate_plus(const double a, const double b)
{
  return a + b; // If doubles are added we don't have to check the
  // result as this is done by the floating point operator
}

//*******************************************************
// Subtract operations
//*******************************************************
template<class X, class Y>
X calculate_minus(const X a, const Y b)
{
  X result = a - b;

  // Check whether the sign of the result is ok
  if (abs(sign(a) - sign(b)) == 2 &&
      sign(a) != sign(result))
    // If the result is wrong then return either the max or the min
    // lint value
    return sign(a)==1? max_huge_value(a) : min_huge_value(a);
  else
    // Return result of the operation
    return result;
}

double
calculate_minus(const double a, const double b)
{
  return a - b; // If doubles are subtracted we don't have to check
  // the result as this is done by the floating point operator
}

//*******************************************************
// Multiply operations
//*******************************************************
template<class X, class Y>
X calculate_mult(const X a, const Y b)
{
  X result = a * b;

  // Check whether at least one parameter is equal to 0 or the result
  // is reasonable. Note that we will compare result / a == b as well
  // as result / b == a as X and Y may be different types (e.g.,
  // double and long long int).
  if (a == X(0) || b == Y(0) ||
      (Y(result / a) == b) || 
      (X(result / b) == a))
    return result;
  else
    return sign(a) * sign(b) == -1? min_huge_value(a) : max_huge_value(a);
}

double
calculate_mult(const double a, const double b)
{
  return a * b; // If doubles are multiplied we don't have to check
  // the result as this is done by the floating point operator
}

//*******************************************************
// Divide operations
//*******************************************************
template<class X, class Y>
X calculate_div(const X a, const Y b)
{
  // Check second parameter
  if (b == Y(0))
    // If the second parameter is 0 then return either the maximum
    // lint or the min lint value depending on the sign of the first
    // parameter
    return sign(a) == -1? min_huge_value(a) : max_huge_value(a);
  else
    return X(a / b);
}

double
calculate_div(const double a, const double b)
{
  return a / b; // If doubles are divided we don't have to check
  // the result as this is done by the floating point operator
}


// function is used to fold two scalar values
template<class T, class A, class B>
T perform_operation(pIIR_FunctionCall fc, A a, B b)
{
  string op_str = fc->function->declarator->text.to_chars();

  if (op_str == "\"and\"")
    return T(int(a) & int(b)? 1 : 0);
  else if (op_str == "\"or\"")
    return T(int(a) | int(b)? 1 : 0);
  else if (op_str == "\"xor\"")
    return T(int(a) ^ int(b) ? 1 : 0);
  else if (op_str == "\"xnor\"")
    return T(1 ^ (int(a) ^ int(b)) ? 1 : 0);
  else if (op_str == "\"nand\"")
    return T(1 ^ (int(a) & int(b)) ? 1 : 0);
  else if (op_str == "\"nor\"")
    return T(1 ^ (int(a) | int(b)) ? 1 : 0);
  else if (op_str == "\"=\"")
    return T((a == b)? 1 : 0);
  else if (op_str == "\">\"")
    return T((a > b)? 1 : 0);
  else if (op_str == "\">=\"")
    return T((a > b)? 1 : 0);
  else if (op_str == "\"<=\"")
    return T((a <= b)? 1 : 0);
  else if (op_str == "\"<\"")
    return T((a < b)? 1 : 0);
  else if (op_str == "\"/=\"")
    return T((a != b)? 1 : 0);
  else if (op_str == "\"=\"")
    return T((a == b)? 1 : 0);
  else if (op_str == "\"+\"")
    return T(calculate_plus(a, b));
  else if (op_str == "\"-\"")
    return T(calculate_minus(a, b));
  else if (op_str == "\"*\"")
    return T(calculate_mult(a, b));
  else if (op_str == "\"/\"")
    return T(calculate_div(a, b));
  else if (op_str == "\"mod\"")
    assert(false);
  else if (op_str == "\"rem\"")
    assert(false);
  else if (op_str == "\"**\"") {
    return T(calculate_pow(a, b));
  } else
    assert(false);
}


int
m_constant_fold(pIIR_FunctionCall fc, RegionStack &rstack)
{
  if (done(fc) & CONST_FOLD) return 0; else  done(fc) |= CONST_FOLD;

  int error_count = 0;
  int n_args = 0;
  int try_function_folding = true;

  // Try to fold function parameters
  for (pIIR_AssociationList al = fc->parameter_association_list; al; al = al->rest) {
    error_count += constant_fold(al->first->actual, rstack);
    if (!valid_folded_value(al->first->actual))
      try_function_folding = false;
    n_args++;
  }

  // Return if not all prameters are locally static!
  if (!try_function_folding)
    return error_count;

  // Now, try to fold function call
  switch (get_operator_type(fc->function)) { // Analyze function call type

  case STD_OP: // The function call is a standard operator call

    if (n_args == 1) {
      //**********************************************************************
      // Function has one parameter
      //**********************************************************************
      pIIR_Type base_type = get_base_type(fc->parameter_association_list->first->actual->subtype);
      if (base_type->is(IR_INTEGER_TYPE) ||
	  base_type->is(IR_ENUMERATION_TYPE) ||
	  base_type->is(IR_PHYSICAL_TYPE)) {
	lint arg = folded_value(fc->parameter_association_list->first->actual).long_value();
	folded_value(fc).long_value() = perform_operation<lint, lint>(fc, arg);

      } else if (base_type->is(IR_FLOATING_TYPE)) {
	double arg = folded_value(fc->parameter_association_list->first->actual).double_value();
	folded_value(fc).double_value() = perform_operation<double, double>(fc, arg);

      } else
	assert(false);

    } else if (n_args == 2) {
      //**********************************************************************
      // Function has two parameters
      //**********************************************************************
      pIIR_Type base_type1 = get_base_type(fc->parameter_association_list->first->actual->subtype);
      pIIR_Type base_type2 = get_base_type(fc->parameter_association_list->rest->first->actual->subtype);
      pIIR_Type result_type = get_base_type(fc->subtype);
      
      if (is_array_type(result_type)) {
	//**********************************************************************
	// Two arrays (or an array and an array element, or two array elements) are 
	// concatenated
	string op_str = fc->function->declarator->text.to_chars();
	// Only the concatenation operator is predefined for arrays
	assert(op_str == "\"&\"");
	
	// First, determine length of arguments
	int length1 = is_array_type(base_type1)? 
	  folded_value(fc->parameter_association_list->first->actual).array_literal_value().size() : 1;
	int length2 = is_array_type(base_type2)? 
	  folded_value(fc->parameter_association_list->rest->first->actual).array_literal_value().size() : 1;

	// Next, concatenate both arguments
	vector<int> result(length1 + length2);
	if (is_array_type(base_type1)) 
	  // The argument is an array
	  copy(folded_value(fc->parameter_association_list->first->actual).array_literal_value().begin(),
	       folded_value(fc->parameter_association_list->first->actual).array_literal_value().end(),
	       result.begin());
	else
	  // The argument is an array element
	  result[0] = folded_value(fc->parameter_association_list->first->actual).long_value();

	if (is_array_type(base_type2))
	  // The argument is an array
	  copy(folded_value(fc->parameter_association_list->rest->first->actual).array_literal_value().begin(),
	       folded_value(fc->parameter_association_list->rest->first->actual).array_literal_value().end(),
	       &result[length1]);
	else
	  // The argument is an array element
	  result[length1] = folded_value(fc->parameter_association_list->rest->first->actual).long_value();

	// Check whether length of target array matches length of
	// concatenation result.
	if (is_constrained_array_type(fc->subtype)) {
	  // First, try to determine array bounds
	  vector<RangeDescriptor> range_desc = get_discrete_range(fc->subtype, rstack, IR_NOT_STATIC);
	  range_desc[0].constant_fold_rangedes(rstack);
	  StaticRangeDescriptor<lint, IR_Direction> range = 
	    range_desc[0].rangedes_to_lint(rstack);
	  // If array bounds are locally static then determine length
	  // of array
	  if (and_reduce(range.valid)) {
	    lint length = range_to_length(range.left, range.dir, range.right);
	    if (length != (length1 + length2)) {
	      codegen_error.error("%:error: length (=%i) of concatenation result does not match length (=%i) of target array.", 
				  fc, length1 + length2, length);
	      error_count++;
	    }
	  }
	}
	
	folded_value(fc).array_literal_value() = result;

      } else if (base_type1->is(IR_PHYSICAL_TYPE) && base_type2->is(IR_PHYSICAL_TYPE) ||
		 base_type1->is(IR_PHYSICAL_TYPE) && base_type2->is(IR_INTEGER_TYPE) ||
		 base_type1->is(IR_INTEGER_TYPE) && base_type2->is(IR_PHYSICAL_TYPE)) {
	//**********************************************************************
	lint arg1 = folded_value(fc->parameter_association_list->first->actual).long_value();
	lint arg2 = folded_value(fc->parameter_association_list->rest->first->actual).long_value();
	lint result = perform_operation<lint, lint, lint>(fc, arg1, arg2);
	// Check whether result is ok
	if (result > PHYSICAL_MAX || result < PHYSICAL_MIN) {
	  result = result > 0? PHYSICAL_MAX : PHYSICAL_MIN;
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).long_value() = result;

      } else if (base_type1->is(IR_PHYSICAL_TYPE) && base_type2->is(IR_FLOATING_TYPE)) {
	//**********************************************************************
	lint arg1 = folded_value(fc->parameter_association_list->first->actual).long_value();
	double arg2 = folded_value(fc->parameter_association_list->rest->first->actual).double_value();
	lint result = perform_operation<lint, double, double>(fc, double(arg1), arg2);
	// Check whether result is ok
	if (result > PHYSICAL_MAX || result < PHYSICAL_MIN) {
	  result = result > 0? PHYSICAL_MAX : PHYSICAL_MIN;
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).long_value() = result;
	
      } else if (base_type1->is(IR_FLOATING_TYPE) && base_type2->is(IR_PHYSICAL_TYPE)) {
	//**********************************************************************
	double arg1 = folded_value(fc->parameter_association_list->first->actual).double_value();
	lint arg2 = folded_value(fc->parameter_association_list->rest->first->actual).long_value();
	lint result = perform_operation<lint, double, double>(fc, arg1, double(arg2));
	// Check whether result is ok
	if (result > PHYSICAL_MAX || result < PHYSICAL_MIN) {
	  result = result > 0? PHYSICAL_MAX : PHYSICAL_MIN;
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).long_value() = result;
	
      } else if ((base_type1->is(IR_ENUMERATION_TYPE) || base_type1->is(IR_INTEGER_TYPE)) &&
		 (base_type2->is(IR_ENUMERATION_TYPE) || base_type2->is(IR_INTEGER_TYPE))) {
	//**********************************************************************
	lint arg1 = folded_value(fc->parameter_association_list->first->actual).long_value();
	lint arg2 = folded_value(fc->parameter_association_list->rest->first->actual).long_value();
	lint result = perform_operation<lint, lint, lint>(fc, arg1, arg2);
	// Check whether result is ok
	if (result > INTEGER_MAX || result < INTEGER_MIN) {
	  result = result > 0? INTEGER_MAX : INTEGER_MIN;
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).long_value() = result;
	
      } else if (base_type1->is(IR_FLOATING_TYPE) && base_type2->is(IR_FLOATING_TYPE) && 
		 result_type->is(IR_ENUMERATION_TYPE)) {
	//**********************************************************************
	// Compare operation
	double arg1 = folded_value(fc->parameter_association_list->first->actual).double_value();
	double arg2 = folded_value(fc->parameter_association_list->rest->first->actual).double_value();
	lint result = perform_operation<lint, double, double>(fc, arg1, arg2);
	// Check whether result is ok
	if (result > INTEGER_MAX || result < INTEGER_MIN) {
	  result = result > 0? INTEGER_MAX : INTEGER_MIN;
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).long_value() = result;
	
      } else if (base_type1->is(IR_FLOATING_TYPE) && base_type2->is(IR_INTEGER_TYPE)) {
	//**********************************************************************
	// Power
	double arg1 = folded_value(fc->parameter_association_list->first->actual).double_value();
	lint arg2 = folded_value(fc->parameter_association_list->rest->first->actual).long_value();
	double result = perform_operation<double, double, lint>(fc, arg1, arg2);
	// Check whether result is ok
	if (result == HUGE_VAL || result == -HUGE_VAL) {
	    codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	    error_count++;
	  }
	// Store result
	folded_value(fc).double_value() = result;

      } else if (base_type1->is(IR_FLOATING_TYPE) && base_type2->is(IR_FLOATING_TYPE) &&
		 result_type->is(IR_FLOATING_TYPE)) {
	//**********************************************************************
	// Misc operations
	double arg1 = folded_value(fc->parameter_association_list->first->actual).double_value();
	double arg2 = folded_value(fc->parameter_association_list->rest->first->actual).double_value();
	double result = perform_operation<double, double, double>(fc, arg1, arg2);
	// Check whether result is ok
	if (result == HUGE_VAL || result == -HUGE_VAL) {
	  codegen_error.error("%:error: overflow/underflow in %n.", fc, fc);
	  error_count++;
	}
	// Store result
	folded_value(fc).double_value() = result;
	
      } else
	assert(false);

    }

    if (error_count == 0)
      valid_folded_value(fc) = true; // The node has been optimized
      
    break;

  case BASIC_OP: // The function is a operator defined in an IEEE
    // library. Currently no constant folding is performed for this class
    // of operators
  case USER_OP: // The function is an user defined operator call
  case NO_OP: // A ordinary function call (no operator)
    break;
  }

  return error_count;
}


int
m_constant_fold(pIIR_PhysicalLiteral le, RegionStack &rstack)
{
  if (done(le) & CONST_FOLD) return 0; else  done(le) |= CONST_FOLD;

  // First, try to fold the unit. I.e., evaluate the number of basic
  // unit the current unit consists of
  int error_count = constant_fold(le->unit, rstack);
  
  // Next, fold the value expression
  if (le->value != NULL)
    // If value pointer is not NULL then fold value
    error_count += constant_fold(le->value, rstack);

  if (!valid_folded_value(le->unit) || 
      !(le->value == NULL || valid_folded_value(le->value)))
    return error_count;

  // Calculate the resulting physical value. The physical value is
  // actually converted to a long long int number which represents the
  // number of basic units the physical value consists of.
  valid_folded_value(le) = true;
  if (le->value == NULL) 
    // If the value expression is NULL then only a time unit was
    // given. Hence, implicitly set value to 1.
    folded_value(le).long_value() = folded_value(le->unit).long_value();
  else if (le->value->is(IR_INTEGER_LITERAL))
    folded_value(le).long_value() = 
      calculate_mult(folded_value(le->value).long_value(), folded_value(le->unit).long_value());
  else if (le->value->is(IR_FLOATING_POINT_LITERAL))
    {
      // XXX - Allow inaccuracies here.  `calculate_mult (double,
      // long)' does extensive checking to ensure that only
      // multiplications are performed where the result can be
      // represented exactly.  This does not make much sense for
      // floating point and for example fails for 1.0e-3 * 1000000.

      double res = (folded_value(le->value).double_value()
		    * folded_value(le->unit).long_value());
      if (res > PHYSICAL_MAX)
	folded_value(le).long_value() = PHYSICAL_MAX;
      else if (res < PHYSICAL_MIN)
	folded_value(le).long_value() = PHYSICAL_MIN;
      else
	folded_value(le).long_value() = lint(res);
    }
  else
    assert(false);
  
  // Check whether no overflow occurred during constant folding
  if (folded_value(le).long_value() > PHYSICAL_MAX ||
      folded_value(le).long_value() < PHYSICAL_MIN) {
    codegen_error.error("%:error: overflow occured during constant folding.", le);
    error_count++;
  }    

  return error_count;
}


int
m_constant_fold(pIIR_PhysicalUnit pu, RegionStack &rstack)
{
  if (done(pu) & CONST_FOLD) return 0; else  done(pu) |= CONST_FOLD;

  int error_count = 0;

  // Fold multiplier value
  if (pu->multiplier != NULL)
    error_count = constant_fold(pu->multiplier, rstack);
  // Fold unit name, i.e. determine number of basic units this unit
  // includes
  if (pu->unit_name != NULL)
    error_count += constant_fold(pu->unit_name, rstack);

  // Flag an error if no valid data could be folded
  if (pu->multiplier != NULL &&
      !valid_folded_value(pu->multiplier)) {
    codegen_error.error("%:error: cannot evaluate expression.", pu, pu->multiplier);
    error_count++;
  }
  // Flag an error if no valid data could be folded
  if (pu->unit_name != NULL &&
      !valid_folded_value(pu->unit_name)) {
    codegen_error.error("%:error: cannot evaluate expression.", pu, pu->unit_name);
    error_count++;
  }

  // Determine multiplier value an unit value (unit value = value
  // related to the basic unit)
  lint mult_value = pu->multiplier == NULL? lint(1) : folded_value(pu->multiplier).long_value();
  lint unit_value = pu->unit_name == NULL? lint(1) : folded_value(pu->unit_name).long_value();

  // Multiply the multiplier value with the number of basic units and
  // store result into node
  folded_value(pu).long_value() = calculate_mult(mult_value, unit_value);
  valid_folded_value(pu) = true;

  // Check whether no overflow occured during constant folding
  if (folded_value(pu).long_value() > PHYSICAL_MAX ||
      folded_value(pu).long_value() < PHYSICAL_MIN) {
    codegen_error.error("%:error: overflow occured during constant folding.", pu);
    error_count++;
  }    
  
  return error_count;
}



int
m_constant_fold(pIIR_SimpleReference sr, RegionStack &rstack)
{
  if (done(sr) & CONST_FOLD) return 0; else  done(sr) |= CONST_FOLD;
  // Return if the expression is not locally static or does not
  // reference a constant
  if (!sr->object->is(IR_CONSTANT_DECLARATION))
    return 0;

  pIIR_ConstantDeclaration cdecl = pIIR_ConstantDeclaration(sr->object);
  int error_count = 0;
  // Return if constant does not have an initial value
  if (cdecl->initial_value != NULL)
    error_count = constant_fold(cdecl->initial_value, rstack);
  else 
    return 0;
  // Return if no folded constant value could be determined.
  if (error_count != 0 ||
      !valid_folded_value(cdecl->initial_value))
    return error_count;

  pIIR_Type base_type = get_base_type(sr->subtype); // Get base type
  
  if (base_type->is(IR_INTEGER_TYPE) ||
      base_type->is(IR_ENUMERATION_TYPE) ||
      base_type->is(IR_PHYSICAL_TYPE)) {
    folded_value(sr).long_value() =
      folded_value(cdecl->initial_value).long_value();
    valid_folded_value(sr) = true;
  } if (base_type->is(IR_FLOATING_TYPE)) {
    folded_value(sr).double_value() =
      folded_value(cdecl->initial_value).double_value();
    valid_folded_value(sr) = true;
  } else if (folded_value(cdecl->initial_value).is_array_literal_value ()) {
    folded_value(sr).array_literal_value() =
      folded_value(cdecl->initial_value).array_literal_value ();
    valid_folded_value(sr) = true;
  }

  return 0;
}



int
m_constant_fold(pIIR_ArrayReference ar, RegionStack &rstack)
{
  if (done(ar) & CONST_FOLD) return 0; else  done(ar) |= CONST_FOLD;

  int error_count = constant_fold(ar->array, rstack);
  for (pIIR_ExpressionList el = ar->indices; el; el = el->rest)
    error_count += constant_fold(el, rstack);

  return error_count;
}



int
m_constant_fold(pIIR_ArrayRange ar, RegionStack &rstack)
{
  if (done(ar) & CONST_FOLD) return 0; else  done(ar) |= CONST_FOLD;

  int error_count = 0;

  if (ar->array != NULL)
    error_count += constant_fold(ar->array, rstack);

  if (ar->index != NULL)
    error_count += constant_fold(ar->index, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_ExplicitRange er, RegionStack &rstack)
{
  if (done(er) & CONST_FOLD) return 0; else  done(er) |= CONST_FOLD;

  int error_count = constant_fold(er->left, rstack);
  error_count += constant_fold(er->right, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_OthersIndexedAssociation ia, RegionStack &rstack)
{
  int error_count = constant_fold(ia->value, rstack);
  return error_count;
}


int
m_constant_fold(pIIR_RangeIndexedAssociation ia, RegionStack &rstack)
{
  if (done(ia) & CONST_FOLD) return 0; else  done(ia) |= CONST_FOLD;

  int error_count = constant_fold(ia->value, rstack);
  error_count += constant_fold(ia->index_range, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_SingleIndexedAssociation ia, RegionStack &rstack)
{
  if (done(ia) & CONST_FOLD) return 0; else  done(ia) |= CONST_FOLD;

  int error_count = 0;
  if (ia->index != NULL)
    error_count += constant_fold(ia->index, rstack);

  error_count += constant_fold(ia->value, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_SliceIndexedAssociation sia, RegionStack &rstack)
{
  if (done(sia) & CONST_FOLD) return 0; else  done(sia) |= CONST_FOLD;

  int error_count = constant_fold(sia->value, rstack);
  error_count += constant_fold(sia->index_range, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_SliceReference sr, RegionStack &rstack)
{
  if (done(sr) & CONST_FOLD) return 0; else  done(sr) |= CONST_FOLD;

  int error_count = 0;
  error_count += constant_fold(sr->array, rstack);
  error_count += constant_fold(sr->range, rstack);

  return error_count;
}



int
m_constant_fold(pIIR_RecordReference rr, RegionStack &rstack)
{
  if (done(rr) & CONST_FOLD) return 0; else  done(rr) |= CONST_FOLD;

  int error_count = 0;
  error_count += constant_fold(rr->record, rstack);

  return error_count;
}



int
m_constant_fold(pIIR_Expression e, RegionStack &rstack)
{
  return 0;
}


int
m_constant_fold(pIIR_Allocator a, RegionStack &rstack)
{
  if (done(a) & CONST_FOLD) return 0; else  done(a) |= CONST_FOLD;

  int error_count = constant_fold(a->type_mark, rstack);
  if (a->value != NULL)
    error_count += constant_fold(a->value, rstack);

  return error_count;
}


int
m_constant_fold(pIIR_ExpressionList el, RegionStack &rstack)
{
  if (done(el) & CONST_FOLD) return 0; else  done(el) |= CONST_FOLD;

  int error_count = 0;
  for ( ; el; el = el->rest)
    error_count += constant_fold(el->first, rstack);

  return error_count;
}



int
m_constant_fold (pIIR_ArrayAggregate aa, RegionStack &rstack)
{
  if (done(aa) & CONST_FOLD) return 0; else  done(aa) |= CONST_FOLD;

  int error_count = 0;
  // First, determine context of asscociations
  for (pIIR_IndexedAssociationList al = aa->indexed_association_list; al; al = al->rest)
    error_count += constant_fold(al->first, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_RecordAggregate ra, RegionStack &rstack)
{
  if (done(ra) & CONST_FOLD) return 0; else  done(ra) |= CONST_FOLD;

  int error_count = 0;
  // First, determine context of asscociations
  for (pIIR_ElementAssociationList al = ra->element_association_list; al; al = al->rest)
    error_count += constant_fold(al->first->value, rstack);

  return error_count;
}


int
m_constant_fold (pIIR_AttrArrayFunc aa, RegionStack &rstack)
{
  if (done(aa) & CONST_FOLD) return 0; else  done(aa) |= CONST_FOLD;

  int error_count = 0;
  vector<RangeDescriptor> range_des_vec;

  if (aa->array != NULL) {
    if (!is_constrained_array_type(aa->array->subtype)) return error_count;
    // Get range descriptors from array object
    range_des_vec = get_discrete_range(aa->array->subtype, rstack, IR_NOT_STATIC);

  } else if (aa->array_type != NULL) {
    if (!is_constrained_array_type(aa->array_type)) return error_count;
    // Get range descriptors from array type
    range_des_vec = get_discrete_range(aa->array_type, rstack, IR_NOT_STATIC);

  } else
    assert(false);
  
  // Constant fold corresponding range descriptor
  RangeDescriptor &range_des = range_des_vec[aa->index - 1];
  range_des.constant_fold_rangedes(rstack);
  StaticRangeDescriptor<lint, IR_Direction> range = 
    range_des.rangedes_to_lint(rstack);
  
  // Initialize flag
  valid_folded_value(aa) = false;

  // Check attribute
  if (aa->is(IR_ATTR_ARRAY_LENGTH)) {
    if (and_reduce(range.valid)) {
      folded_value(aa).long_value() = 
	(range.left <= range.right && range.dir == IR_DIRECTION_UP) || 
	(range.left >= range.right && range.dir == IR_DIRECTION_DOWN) ?
	lint_abs(range.right - range.left) + 1 : 0;
      valid_folded_value(aa) = true;
    }

  } else if (aa->is(IR_ATTR_ARRAY_ASCENDING)) {
    if (range.valid[1]) {
      folded_value(aa).long_value() = range.dir == IR_DIRECTION_UP? 1 : 0;
      valid_folded_value(aa) = true;
    }

  } else if (aa->is(IR_ATTR_ARRAY_LOW)) {
    if (and_reduce(range.valid)) {
      folded_value(aa).long_value() = min (range.left, range.right);
      valid_folded_value(aa) = true;
    }

  } else if (aa->is(IR_ATTR_ARRAY_HIGH)) {
    if (and_reduce(range.valid)) {
      folded_value(aa).long_value() = max (range.left, range.right);
      valid_folded_value(aa) = true;
    }

  } else if (aa->is(IR_ATTR_ARRAY_RIGHT)) {
    if (range.valid[2]) {
      folded_value(aa).long_value() = range.right;
      valid_folded_value(aa) = true;
    }

  } else if (aa->is(IR_ATTR_ARRAY_LEFT)) {
    if (range.valid[0]) {
      folded_value(aa).long_value() = range.left;
      valid_folded_value(aa) = true;
    }

  } else 
    assert(false);

  return error_count;
}



int
m_constant_fold (pIIR_AttrTypeFunc a, RegionStack &rstack)
{
  int error_count = 0;
  vector<RangeDescriptor> type_range_des;
  StaticRangeDescriptor<lint, IR_Direction> static_lint_range;
  StaticRangeDescriptor<double, IR_Direction> static_double_range;
  
  pIIR_Root left_bound_node, right_bound_node;

  if (a->prefix != NULL) {
    // Determine range of prefix type
    type_range_des = get_discrete_range(a->prefix, rstack, IR_NOT_STATIC); 
    // type_range_des should contain exactly one single
    // RangeDescriptor instance
    assert(type_range_des.size() == 1);
    left_bound_node = type_range_des[0].left;
    right_bound_node = type_range_des[0].right;
    // Try to fold range descriptor
    type_range_des[0].constant_fold_rangedes(rstack);
    if (get_base_type (a->prefix)-> is (IR_FLOATING_TYPE))
      {
	// Determine left, right and direction of range. is_static stores
	// whether the corresponding value is static.
	static_double_range = type_range_des[0].rangedes_to_double (rstack);
	// if neither left or right bound nor the direction are static
	// then do not perform any constant folding because no range
	// checking can be done at compile time.
	if (!or_reduce(static_double_range.valid))
	  return error_count;
      }
    else
      {
	// Determine left, right and direction of range. is_static stores
	// whether the corresponding value is static.
	static_lint_range = type_range_des[0].rangedes_to_lint (rstack);
	// if neither left or right bound nor the direction are static
	// then do not perform any constant folding because no range
	// checking can be done at compile time.
	if (!or_reduce(static_lint_range.valid))
	  return error_count;
      }
  }

  // Fold argument
  if (a->argument != NULL)
    constant_fold(a->argument, rstack);
  // Return if the argument is not locally static
  if (a->argument != NULL && !valid_folded_value(a->argument))
    return error_count;

  // Determine argument value and store whether the argument is an
  // integer/enumeration/physical or floating point type
  lint lint_argument;
  double double_argument;
  bool has_long_argument;
  bool has_no_argument = true;
  if (a->argument != NULL) {
    pIIR_Type type = get_base_type(a->argument->subtype);
    has_no_argument = false;
    if (type->is(IR_INTEGER_TYPE) ||
	type->is(IR_ENUMERATION_TYPE) ||
	type->is(IR_PHYSICAL_TYPE)) {
      lint_argument = folded_value(a->argument).long_value();
      has_long_argument = true;

    } else if (type->is(IR_FLOATING_TYPE)) {
      double_argument = folded_value(a->argument).double_value();
      has_long_argument = false;
      
    } else {
      cerr << "unsupported argtype: " << type->base->kind_name () << "\n";
      assert(false);
    }
  }


  // Bail out if the attribute is used on an illegal type
  if (!has_long_argument && 
      (a->is(IR_ATTR_RIGHTOF) ||
       a->is(IR_ATTR_LEFTOF) ||
       a->is(IR_ATTR_VAL) ||
       a->is(IR_ATTR_POS) ||
       a->is(IR_ATTR_SUCC) ||
       a->is(IR_ATTR_PRED) ||
       a->is(IR_ATTR_LEFTOF) ||
       a->is(IR_ATTR_RIGHTOF)
       )) {
    codegen_error.error("%:error: attribute %n is not defined for floating point types.", a, a);
    return ++error_count;
  }
      
  
  // Finally, handle the various attributes
  // ***** RIGHTOF *******************************************
  // Note that this attribute is not defined for floatingpoint types
  if (a->is(IR_ATTR_RIGHTOF)) {
    folded_value(a).long_value() = 
      lint_argument + (static_lint_range.dir == IR_DIRECTION_UP? +1 : -1);
    // Check result
    if (static_lint_range.dir == IR_DIRECTION_DOWN)
      if (!static_lint_range.valid[0])
	// Return if we cannot range check the result
	return error_count;
      else if (folded_value(a).long_value() < static_lint_range.left) {
	codegen_error.error("%:error: result of attribute %n is out of bounds. Left bound of type %n is %n.", 
			    a, a, a->prefix, left_bound_node);
	return ++error_count;
      }

    if (static_lint_range.dir == IR_DIRECTION_UP)
      if (!static_lint_range.valid[2])
	// Return if we cannot range check the result
	return error_count;
      else if (folded_value(a).long_value() > static_lint_range.right) {
	codegen_error.error("%:error: result of attribute %n is out of bounds. Right bound of type %n is %n.", 
			    a, a, a->prefix, right_bound_node);
	return ++error_count;
      }

    valid_folded_value(a) = true;

  // ***** LEFTOF *******************************************
  // Note that this attribute is not defined for floatingpoint types
  } else if (a->is(IR_ATTR_LEFTOF)) {
    folded_value(a).long_value() = lint_argument - (static_lint_range.dir == IR_DIRECTION_UP? +1 : -1);
    // Check result
    if (static_lint_range.dir == IR_DIRECTION_UP)
      if (!static_lint_range.valid[2])
	// Return if we cannot range check the result
	return error_count;
      else if (folded_value(a).long_value() < static_lint_range.left) {
	codegen_error.error("%:error: result of attribute %n is out of bounds. Left bound of type %n is %n.", 
			    a, a, a->prefix, left_bound_node);
	return ++error_count;
      }

    if (static_lint_range.dir == IR_DIRECTION_DOWN)
      if (!static_lint_range.valid[0])
	// Return if we cannot range check the result
	return error_count;
      else if (folded_value(a).long_value() > static_lint_range.right) {
	  codegen_error.error("%:error: result of attribute %n is out of bounds. Right bound of type %n is %n.", 
			      a, a, a->prefix, right_bound_node);
	  return ++error_count;
      }

    valid_folded_value(a) = true;

  // ***** PRED *******************************************
  // Note that this attribute is not defined for floatingpoint types
  } else if (a->is(IR_ATTR_PRED)) {
    folded_value(a).long_value() = lint_argument - 1;
    // Check result
    if (!static_lint_range.valid[0])
      // Return if we cannot range check the result
      return error_count;
    
    if (folded_value(a).long_value() < static_lint_range.left) {
      codegen_error.error("%:error: result of attribute %n is out of bound. Left bound of type %n is %n.", 
			  a, a, a->prefix, right_bound_node);
      return ++error_count;
    }

    valid_folded_value(a) = true;

  // ***** SUCC *******************************************
  // Note that this attribute is not defined for floatingpoint types
  } else if (a->is(IR_ATTR_SUCC)) {
    folded_value(a).long_value() = lint_argument + 1;
    // Check result
    if (!static_lint_range.valid[2])
      // Return if we cannot range check the result
      return error_count;

    if (folded_value(a).long_value() > static_lint_range.right) {
      codegen_error.error("%:error: result of attribute %n is out of bound. Right bound of type %n is %n.", 
			  a, a, a->prefix, right_bound_node);
      return ++error_count;
    }

    valid_folded_value(a) = true;

  // ***** VAL *******************************************
  // Note that this attribute is not defined for floatingpoint types
  } else if (a->is(IR_ATTR_VAL)) {
    folded_value(a).long_value() = lint_argument;
    // Check result
    if (!static_lint_range.valid[2] ||
	!static_lint_range.valid[0])
      // Return if we cannot range check the result
      return error_count;
    else if (folded_value(a).long_value() < static_lint_range.left) {
      codegen_error.error("%:error: result of attribute %n is out of bounds. Left bound of type %n is %n.", 
			  a, a, a->prefix, left_bound_node);
      return ++error_count;
    } else if (folded_value(a).long_value() > static_lint_range.right) {
      codegen_error.error("%:error: result of attribute %n is out of bounds. Right bound of type %n is %n.", 
			  a, a, a->prefix, right_bound_node);
      return ++error_count;
    }
    valid_folded_value(a) = true;

  // ***** POS *******************************************
  // Note that this attribute is not defined for floatingpoint types
  } else if (a->is(IR_ATTR_POS)) {
    folded_value(a).long_value() = lint_argument;
    valid_folded_value(a) = true;

  // ***** VALUE *******************************************
  } else if (a->is(IR_ATTR_VALUE)) {
    // The VALUE attribute is not folded
    return error_count;

  // ***** IMAGE *******************************************
  } else if (a->is(IR_ATTR_IMAGE)) {
    // The IMAGE attribute is not folded
    return error_count;

  } else 
    assert(false);

  return error_count;
}



int
m_constant_fold (pIIR_AttrTypeValue a, RegionStack &rstack)
{
  int error_count = 0;
  vector<RangeDescriptor> type_range_des;
  StaticRangeDescriptor<lint, IR_Direction> static_lint_range;
  StaticRangeDescriptor<double, IR_Direction> static_double_range;
  bool is_floatingpoint_type = false;

  if (a->prefix != NULL) {
    // Determine range of prefix type
    type_range_des = get_discrete_range(a->prefix, rstack, IR_NOT_STATIC); 
    // type_range_des should contain exactly one single
    // RangeDescriptor instance
    assert(type_range_des.size() == 1);
    // Try to fold range descriptor
    type_range_des[0].constant_fold_rangedes(rstack);
    // Determine left, right and direction of range. is_static stores
    // whether the corresponding value is static.
    if (get_base_type (a->prefix)->is (IR_FLOATING_TYPE))
      {
	static_double_range = type_range_des[0].rangedes_to_double (rstack);
	// if neither left or right bound nor the direction are static
	// then do not perform any constant folding because no range
	// checking can be done at compile time.
	is_floatingpoint_type = true;
	if (!or_reduce(static_double_range.valid))
	  return error_count;
      }
    else 
      {
	static_lint_range = type_range_des[0].rangedes_to_lint (rstack);
	// if neither left or right bound nor the direction are static
	// then do not perform any constant folding because no range
	// checking can be done at compile time.
	is_floatingpoint_type = false;
	if (!or_reduce(static_lint_range.valid))
	  return error_count;
      }
  }

  // Fold argument
  if (a->argument != NULL)
    constant_fold(a->argument, rstack);
  // Return if the argument is not locally static
  if (a->argument != NULL && !valid_folded_value(a->argument))
    return error_count;

  // Determine argument value and store whether the argument is an
  // integer/enumeration/physical or floating point type
  lint lint_argument;
  double double_argument;
  bool has_long_argument;
  bool has_no_argument = true;
  if (a->argument != NULL) {
    pIIR_Type type = get_base_type(a->argument->subtype);
    has_no_argument = false;
    if (type->is(IR_INTEGER_TYPE) ||
	type->is(IR_ENUMERATION_TYPE) ||
	type->is(IR_PHYSICAL_TYPE)) {
      lint_argument = folded_value(a->argument).long_value();
      has_long_argument = true;
      
    } else if (type->is(IR_FLOATING_TYPE)) {
      double_argument = folded_value(a->argument).double_value();
      has_long_argument = false;
      
    } else
      assert(false);
  }

  // Create shortcut to access valid array.
  vector<bool> &valid = is_floatingpoint_type?
    static_double_range.valid : static_lint_range.valid;

  // Finally, handle the various attributes
  // ***** LENGTH *******************************************
  if (a->is(IR_ATTR_LENGTH)) {
    // Actually, this attribute is defined for arrays only!
    assert(false);

  // ***** ASCENDING *******************************************
  } else if (a->is(IR_ATTR_ASCENDING)) {
    if (!valid[1])
      // Return if direction is not static
      return error_count;

    if (is_floatingpoint_type)
      folded_value(a).double_value() = static_double_range.dir == IR_DIRECTION_UP? 1 : 0;
    else
      folded_value(a).long_value() = static_lint_range.dir == IR_DIRECTION_UP? 1 : 0;
    valid_folded_value(a) = true;

  // ***** HIGH *******************************************
  } else if (a->is(IR_ATTR_HIGH)) {
    if (!valid[2] ||
	!valid[0])
      // Return if bound is not static
      return error_count;

    if (is_floatingpoint_type)
      folded_value(a).double_value() = max(static_double_range.right, static_double_range.left);
    else
      folded_value(a).long_value() = max(static_lint_range.right, static_lint_range.left);
    valid_folded_value(a) = true;

  // ***** LOW *******************************************
  } else if (a->is(IR_ATTR_LOW)) { 
    if (!valid[2] ||
	!valid[0])
      // Return if bound is not static
      return error_count;

    if (is_floatingpoint_type)
      folded_value(a).double_value() = min(static_double_range.right, static_double_range.left);
    else
      folded_value(a).long_value() = min(static_lint_range.right, static_lint_range.left);
    valid_folded_value(a) = true;

  // ***** RIGHT *******************************************
  } else if (a->is(IR_ATTR_RIGHT)) {
    if (!valid[2])
      // Return if bound is not static
      return error_count;

    if (is_floatingpoint_type)
      folded_value(a).double_value() = static_double_range.right;
    else
      folded_value(a).long_value() = static_lint_range.right;
    valid_folded_value(a) = true;

  // ***** LEFT *******************************************
  } else if (a->is(IR_ATTR_LEFT)) {
    if (!valid[0])
      // Return if bound is not static
      return error_count;

    if (is_floatingpoint_type)
      folded_value(a).double_value() = static_double_range.left;
    else
      folded_value(a).long_value() = static_lint_range.left;
    valid_folded_value(a) = true;

  } else 
    assert(false);

  return error_count;
}


int
m_constant_fold (pIIR_TypeConversion tc, RegionStack &rstack)
{
  int error_count = 0;
  
  error_count += constant_fold(tc->expression, rstack);
  // Return if an error occured during constant folding of the operand
  // or no valid folded value could be determined for the operand or
  // the operand is not scalar.
  if (error_count != 0 ||
      !valid_folded_value(tc->expression) ||
      !is_scalar_type(tc->expression->subtype)) 
    return error_count;
  // Determine converted value
  pIIR_Type target_base_type = get_base_type(tc->type_mark);
  pIIR_Type source_base_type = get_base_type(tc->expression->subtype);

  if (target_base_type->is(IR_FLOATING_TYPE) &&
      source_base_type->is(IR_INTEGER_TYPE)) {
    folded_value(tc).double_value() = (double)folded_value(tc->expression).long_value();
    // Check whether 
    error_count += check_scalar_against_bounds(tc, folded_value(tc).double_value(), tc->type_mark, 
					       rstack, runtime_checks(tc), true, " illegal type conversion:" );

  } else if (source_base_type->is(IR_FLOATING_TYPE) &&
	     target_base_type->is(IR_INTEGER_TYPE)) {
    folded_value(tc).long_value() = (lint)rint(folded_value(tc->expression).double_value());
    error_count += check_scalar_against_bounds(tc, folded_value(tc).long_value(), tc->type_mark,
					       rstack, runtime_checks(tc), true, " illegal type conversion:" );

  } else if (target_base_type->is(IR_FLOATING_TYPE) &&
	     source_base_type->is(IR_FLOATING_TYPE)) {
    folded_value(tc).double_value() = folded_value(tc->expression).double_value();
    error_count += check_scalar_against_bounds(tc, folded_value(tc).double_value(), tc->type_mark, 
					       rstack, runtime_checks(tc), true, " illegal type conversion:" );

  } else {
    folded_value(tc).long_value() = folded_value(tc->expression).long_value();
    error_count += check_scalar_against_bounds(tc, folded_value(tc).long_value(), tc->type_mark, 
					       rstack, runtime_checks(tc), true, " illegal type conversion:" );

  }
  
  valid_folded_value(tc) = (error_count == 0);

  return error_count;
}
