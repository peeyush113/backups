/* types and subtypes

   Copyright (C) 1994-1997 University of Dortmund
   Department of Electrical Engineering, AG SIV

   VAUL is free software; you can redistribute it and/or modify it
   under the terms of the GNU Library General Public License as
   published by the Free Software Foundation; either version 2 of the
   License, or (at your option) any later version.

   VAUL is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General
   Public License for more details.

   You should have received a copy of the GNU Library General Public
   License along with VAUL; see the file COPYING.LIB.  If not, write
   to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
   Boston, MA 02111-1307 USA.


*/

#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-util.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define psr vaul_parser

struct resolution_filter_closure {
  pIIR_Type base;
};

static int
resolution_filter (pIIR_Declaration d, void *closure)
{
  resolution_filter_closure *rfc = (resolution_filter_closure *)closure;

  if (!d->is(IR_FUNCTION_DECLARATION))
    return -1;

  pIIR_FunctionDeclaration f = pIIR_FunctionDeclaration(d);
  if (!f->pure)
    return -1;
  if (vaul_get_base (f->return_type) != rfc->base)
    return -1;
  if (f->interface_declarations == NULL
      || f->interface_declarations->rest != NULL)
    return -1;

  pIIR_InterfaceDeclaration p = f->interface_declarations->first;
  if (!p->is(IR_CONSTANT_INTERFACE_DECLARATION) || p->mode != IR_IN_MODE)
    return -1;
  if (!p->subtype->is(IR_ARRAY_TYPE))
    return -1;

  pIIR_ArrayType pt = pIIR_ArrayType (p->subtype);
  if (pt->index_types == NULL || pt->index_types->rest != NULL)
    return -1;
  if (vaul_get_base (pt->element_type) != rfc->base)
    return -1;
  
  return 0;
}

pIIR_FunctionDeclaration
psr::find_resolution_function (pVAUL_Name res_name, pIIR_Type type)
{
  pIIR_FunctionDeclaration res_func = NULL;

  if (res_name)
    {	
      vaul_decl_set ds(this);
      find_decls (ds, res_name);
      resolution_filter_closure rfc = { type->base };
      ds.filter (resolution_filter, &rfc);
      ds.invalidate_pot_invalids ();
      res_func = pIIR_FunctionDeclaration (ds.single_decl (false));
      if (res_func == NULL)
	{
	  error ("%:no match for resolution function %n, candidates are",
		 res_name, res_name);
	  ds.show(false);
	}
      assert (!res_func || res_func->is(IR_FUNCTION_DECLARATION));
    }

  return res_func;
}

pIIR_Type
psr::build_ArraySubtype (pVAUL_Name res_name,
			 pVAUL_Name type_mark,
			 pIIR_TypeList constraint)
{
  pIIR_Type base = get_type (type_mark);
  if (base == NULL)
    return NULL;
  
  pIIR_FunctionDeclaration res_func =
    find_resolution_function (res_name, base);
  
  if(constraint) 
    constraint = build_IndexConstraint (constraint, base);

  // XXX - do some checks here, like constraints on
  // access/record/file types
  
  if (constraint == NULL && res_func == NULL)
    return base;

  pIIR_ArraySubtype subtype =
    mIIR_ArraySubtype (type_mark->pos, base->base, base, res_func,
		       constraint);

  return subtype;
}

pIIR_Type
psr::build_ScalarSubtype (pVAUL_Name res_name,
			  pVAUL_Name type_mark,
			  pIIR_Range range)
{
  pIIR_Type base = get_type (type_mark);
  if (base == NULL)
    return NULL;

  pIIR_FunctionDeclaration res_func =
    find_resolution_function (res_name, base);

  if (range) 
    {
      if (range->is(IR_EXPLICIT_RANGE))
	{
	  pIIR_ExplicitRange r = pIIR_ExplicitRange(range);
	  overload_resolution(r->left, base);
	  overload_resolution(r->right, base);
	}
      else if (range->is(IR_ARRAY_RANGE))
	{
	  pIIR_Type t = pIIR_ArrayRange(range)->type;
	  if (t->base != base)
	    error ("%:%n is not a base type of %n", range, t, base);
	}
      else
	assert (false);
    }

  // XXX - do some checks here, like constraints on
  // access/record/file types

  if (range == NULL && res_func == NULL)
    return base;
  return mIIR_ScalarSubtype (type_mark->pos, base->base, base,
			     res_func, range);
}

pIIR_Type
psr::build_Subtype (pVAUL_Name res_name,
		    pVAUL_Name type_mark,
		    pIIR_TypeList opt_constraint)
{
  // When we have a constraint, build a ArraySubtype
  //
  if (opt_constraint)
    return build_ArraySubtype (res_name, type_mark, opt_constraint);

  // Build a ScalarSubtype when the type_mark denotes a scalar type; a
  // ArraySubtype when it is an array type; else build a unqualified
  // subtype.

  pIIR_Type base = get_type (type_mark);
  if (base == NULL)
    return NULL;
  
  if (base->is(IR_SCALAR_TYPE) || base->is(IR_SCALAR_SUBTYPE))
    return build_ScalarSubtype (res_name, type_mark, NULL);
  if (base->is(IR_ARRAY_TYPE) || base->is(IR_ARRAY_SUBTYPE))
    return build_ArraySubtype (res_name, type_mark, NULL);

  pIIR_FunctionDeclaration res_func =
    find_resolution_function (res_name, base);

  if (res_func)
    {
      if (base->is(IR_RECORD_TYPE) || base->is(IR_RECORD_SUBTYPE))
	return mIIR_RecordSubtype (type_mark->pos,
				   base->base,
				   base, 
				   res_func);
      else
	{
	  info ("xxx - plain subtype of %s", base->kind_name());
	  return mIIR_Subtype (type_mark->pos,
			       base->base,
			       base, 
			       res_func);
	}
    }

  return base;
}

pIIR_Range
psr::get_scalar_type_range (pIIR_Type type)
{
  if (type->is(IR_SCALAR_SUBTYPE))
    return pIIR_ScalarSubtype (type)->range;
  else if (type->is(IR_ENUMERATION_TYPE))
    {
      pIIR_EnumerationType et = pIIR_EnumerationType (type);
      pIIR_EnumerationLiteral left = et->enumeration_literals->first;
      pIIR_EnumerationLiteral right;
      for (pIIR_EnumerationLiteralList lits = et->enumeration_literals;
	   lits; lits = lits->rest)
	right = lits->first;
      return mIIR_ExplicitRange (type->pos,
				 mIIR_EnumLiteralReference (type->pos,
							    type, left),
				 mIIR_EnumLiteralReference (type->pos,
							    type, right),
				 IR_DIRECTION_UP);
    }
  else
    {
      info ("XXX - no range for %n", type);
      return NULL;
    }
}

pIIR_Type
psr::build_EnumerationType (int pos, pIIR_EnumerationLiteralList lits)
{
  pIIR_EnumerationType t = mIIR_EnumerationType (pos, lits);
  int enum_pos_counter = 0;

  for (pIIR_EnumerationLiteralList el = lits; el; el = el->rest)
    {
      el->first->subtype = t;
      el->first->enum_pos = enum_pos_counter++;
    }

  return t;
}

pIIR_TypeList
psr::build_IndexConstraint (pIIR_TypeList pre,
			    pIIR_Type immediate_base)
{
  pIIR_Type base = immediate_base->base;

  if (!base->is(IR_ARRAY_TYPE))
    {
      error ("%:only array types can have index constraints", pre);
      return NULL;
    }

  pIIR_TypeList itypes = pIIR_ArrayType(base)->index_types;
  pIIR_TypeList pcons = pre;
  pIIR_TypeList cons = NULL, *ctail = &cons;

  while (pcons && itypes)
    {
      assert (pcons->first->is(VAUL_PRE_INDEX_CONSTRAINT));
      pVAUL_PreIndexConstraint pic = pVAUL_PreIndexConstraint(pcons->first);
      if (itypes->first == NULL)
	return NULL;

      pIIR_Type type = NULL;

      if (pic->is(VAUL_PRE_INDEX_RANGE_CONSTRAINT))
	{
	  if (pIIR_Range r = pVAUL_PreIndexRangeConstraint(pic)->range) 
	    {
	      if (r->is(IR_EXPLICIT_RANGE))
		{
		  pIIR_ExplicitRange er = pIIR_ExplicitRange(r);
		  if (pIIR_Type itype = find_index_range_type (er)) 
		    {
		      overload_resolution(er->left, itype);
		      overload_resolution(er->right, itype);
		    }
		}
	      type = mIIR_ScalarSubtype (pic->pos, 
					 itypes->first->base,
					 itypes->first,
					 NULL,
					 r);
	    }
	}
      else if (pic->is(VAUL_PRE_INDEX_SUBTYPE_CONSTRAINT))
	type = pVAUL_PreIndexSubtypeConstraint(pic)->type;
      else
	vaul_fatal ("build_IndexConstraint confused.\n");

      if (type && itypes->first && type->base != itypes->first->base)
	error ("%:constraint type (%n) does not match index type (%n)",
	       pre, type->base, itypes->first->base);

      *ctail = mIIR_TypeList (pcons->pos, type, *ctail);
      ctail = &(*ctail)->rest;
      itypes = itypes->rest;
      pcons = pcons->rest;
    }

  if (pcons)
    error ("%:too many index constraints for %n", pre, immediate_base);
  else if (itypes)
    error ("%:too few index constraints for %n", pre, immediate_base);
  return cons;
}

pIIR_Type
psr::find_index_range_type (pIIR_ExplicitRange r)
{
  pIIR_Type_vector &left_types = *ambg_expr_types(r->left);
  pIIR_Type_vector &right_types = *ambg_expr_types(r->right);

  if (left_types.size() == 0 || right_types.size() == 0)
    return NULL;

  pIIR_Type_vector types;
  
  for (int i = 0; i < left_types.size(); i++) 
    {
      assert(left_types[i]);
      pIIR_Type t = left_types[i];
      if (!is_discrete_type(t->base))
	{
	  // info ("%:%n is not discrete", t->base, t->base);
	  continue;
	}
      for (int j = 0; j < right_types.size(); j++) 
	{
	  assert (right_types[j]);
	  pIIR_Type tt = right_types[j];
	  if(!is_discrete_type(vaul_get_base(tt)))
	    {
	      info ("%:%n is not discrete", t->base, t->base);
	      continue;
	    }
	  if(t == std->universal_integer)
	    t = tt;
	  else if(tt == std->universal_integer)
	    tt = t;
	  if(vaul_get_base(t) == vaul_get_base(tt)) {
	    if(t == std->universal_integer)
	      {
		// Don't look any further when universal integer is
		// possible.  Universal integers are coerced into
		// std.standard.integer.  LRM 3.2.1.1.

		delete &left_types;
		delete &right_types;
		return std->predef_INTEGER;
	      }

	    if(try_overload_resolution(r->left, t, IR_INVALID)
	       && try_overload_resolution(r->right, t, IR_INVALID)) {
	      bool already_inserted = false;
	      for(int k = 0; k < types.size(); k++)
		if(vaul_get_base(types[k]) == vaul_get_base(t)) {
		  // info("+++ - found %n twice", t);
		  already_inserted = true;
		  break;
		}
	      if(!already_inserted)
		types.add(t);
	    }
#if 0
	    else
	      info ("%:can't coerce %n,%n to %n", t, r->left, r->right, t);
#endif
	  }
	}
    }

  if(types.size() == 0) {
    error("%:index bounds must be discrete and of the same type", r);
    if(left_types.size() > 0) {
      info("left bound could be:"); 
      for(int i = 0; i < left_types.size(); i++)
	info("%:   %n", left_types[i], left_types[i]);
    } else
      info("no left types");
    if(right_types.size() > 0) {
      info("right bound could be:"); 
      for(int i = 0; i < right_types.size(); i++)
	info("%:   %n", right_types[i], right_types[i]);
    } else
      info("no right types");
  } else if(types.size() != 1) {
    error("%:type of index bounds is ambigous, it could be:", r);
    for(int i = 0; i < types.size(); i++)
      info("%:   %n (%s)", types[i], types[i], types[i]->kind_name());
  }
  
  delete &left_types;
  delete &right_types;

  return types.size() == 1? types[0] : NULL;
}


pIIR_ScalarSubtype
psr::build_SubType_def (int pos, pIIR_Range r, pIIR_Type base)
{
  if (r == NULL)
    return NULL;

  if (base == NULL) 
    {
      if (r->is(IR_EXPLICIT_RANGE)) 
	{
	  pIIR_ExplicitRange er = pIIR_ExplicitRange(r);
	  if (try_overload_resolution (er->left, NULL,
				       IR_INTEGER_TYPE)
	      && try_overload_resolution (er->right, NULL,
					  IR_INTEGER_TYPE))
	    {
	      base = mIIR_IntegerType (pos);
	    }
	  else if (try_overload_resolution (er->left, NULL,
					    IR_FLOATING_TYPE)
		   && try_overload_resolution (er->right, NULL,
					       IR_FLOATING_TYPE))
	    {
	      base = mIIR_FloatingType (pos);
	    }
	  else 
	    {
	      error ("%!range bounds must be both either integer"
		     " or real values", lex, pos);
#if 0
	      info("%!they can be:", lex, pos);
	      pIIR_Type_vector &types = *ambg_expr_types(er->first);
	      for (int i = 0; i < types.size(); i++)
		info ("%:  %n", types[i], types[i]);
	      pIIR_Type_vector &types2 = *ambg_expr_types(er->last);
	      info ("and");
	      for (int i = 0; i < types2.size(); i++)
		info ("%:  %n", types2[i], types2[i]);
#endif
	      return NULL;
	    }
	} 
      else if (r->is(IR_ARRAY_RANGE))
	{
	  info ("XXX - no array ranges in type definition");
	  return NULL;
	}
      else
	assert (false);
    }

  IR_Kind base_k = base->kind();
  if (base_k == IR_PHYSICAL_TYPE)
    base_k = IR_INTEGER_TYPE;
  assert (r->is(IR_EXPLICIT_RANGE)); // for now...
  overload_resolution (pIIR_ExplicitRange(r)->left, base_k);
  overload_resolution (pIIR_ExplicitRange(r)->right, base_k);

  return mIIR_ScalarSubtype (pos, base->base, base, NULL, r);
}

pIIR_Type
psr::get_type (pVAUL_Name mark)
{
  pIIR_TypeDeclaration d = 
    pIIR_TypeDeclaration(find_single_decl (mark, IR_TYPE_DECLARATION, "type"));
  if (d && d->type)
    {
      if (d->type->is(VAUL_INCOMPLETE_TYPE))
	error ("%:type %n is incomplete", mark, mark);
      else
	return d->type;
    }
  return NULL;
}

void 
psr::add_PredefOp (pIIR_PosInfo pos, pIIR_Type ret, 
		   pIIR_TextLiteral sym, pIIR_Type left,
		   pIIR_Type right)
{
  pIIR_InterfaceList interf = 
    mIIR_InterfaceList (pos,
			mIIR_ConstantInterfaceDeclaration (pos, NULL,
							   left, NULL,
							   IR_IN_MODE,
							   false),
			NULL);
  if (right)
    interf->rest =
      mIIR_InterfaceList (pos,
			  mIIR_ConstantInterfaceDeclaration (pos, NULL,
							     right, NULL,
							     IR_IN_MODE,
							     false),
			  NULL);
    
  add_decl (mIIR_PredefinedFunctionDeclaration (pos, sym, interf, true, ret));
}

pIIR_Type
psr::is_one_dim_array (pIIR_Type t)
{
  if (!t->is(IR_ARRAY_TYPE))
    return NULL;
  pIIR_ArrayType at = pIIR_ArrayType(t);
  if (!at->index_types || at->index_types->rest)
    return NULL;
  return at->element_type;
}

bool
psr::is_one_dim_logical_array (pIIR_Type t)
{
  pIIR_Type et = is_one_dim_array (t);
  return et && et == std->predef_BIT || et == std->predef_BOOLEAN;
}

bool
psr::is_one_dim_discrete_array (pIIR_Type t)
{
    pIIR_Type et = is_one_dim_array (t);
    return is_discrete_type (et);
}

bool
psr::is_discrete_type (pIIR_Type t)
{
  if (t == NULL)
    return false;
  t = t->base;
  return t && (t->is(IR_INTEGER_TYPE)
	       || t->is(IR_ENUMERATION_TYPE));
}

void
psr::add_predefined_ops (pIIR_Type t)
{
  if (t == NULL)
    return;

  pIIR_Type bt = t;

  if (t->is(IR_SUBTYPE)
      && t->declaration == pIIR_Subtype(t)->immediate_base->declaration)
    bt = pIIR_Subtype(t)->immediate_base;
  if (bt->is(VAUL_INCOMPLETE_TYPE) || bt->is(IR_SUBTYPE))
    return;


# define add(r, op, t1, t2)  add_PredefOp(t->pos, r, make_strlit(#op), \
                                            t1, t2)

  // logical operators
  //
  if ((t == std->predef_BIT || t == std->predef_BOOLEAN)
      || is_one_dim_logical_array(bt)) 
    {
      add (t, "and", t, t);
      add (t, "or", t, t);
      add (t, "nand", t, t);
      add (t, "nor", t, t);
      add (t, "xor", t, t);
      add (t, "xnor", t, t);
      add (t, "not", t, NULL);
      if (bt == std->predef_BOOLEAN)
	{
	  pIIR_IntegerType ui = mIIR_IntegerType (t->pos);
	  std->universal_integer = ui;
	  add_predefined_ops(ui);
	  
	  pIIR_FloatingType ur = mIIR_FloatingType (t->pos);
	  std->universal_real = ur;
	  add_predefined_ops(ur);
	}
    }

  // relational operators
  //
  pIIR_Type b = std->predef_BOOLEAN;
  if (b == NULL) 
    {
      info ("%:can't predefine relational operators for %n", t, t);
      info ("%:since type BOOLEAN is undefined", t);
    } 
  else
    {
      add (b, "=", t, t);
      add (b, "/=", t, t);
      if (bt->is(IR_SCALAR_TYPE) || is_one_dim_discrete_array(bt))
	{
	  add (b, "<", t, t);
	  add (b, ">", t, t);
	  add (b, "<=", t, t);
	  add (b, ">=", t, t);
	}
    }

  // shift operators
  //
  if (is_one_dim_logical_array(bt)) 
    {
      if (pIIR_Type r = std->predef_INTEGER) 
	{
	  add (t, "sll", t, r);
	  add (t, "srl", t, r);
	  add (t, "sla", t, r);
	  add (t, "sra", t, r);
	  add (t, "rol", t, r);
	  add (t, "ror", t, r);
	} 
      else
	{
	  info ("%:can't predefine shift operators for %n", t, t);
	  info ("%:since type INTEGER is undefined", t);
	}
    }

  // Adding, Sign and Miscellanous operators
  //
  if (bt->is(IR_INTEGER_TYPE)
      || bt->is(IR_FLOATING_TYPE)
      || bt->is(IR_PHYSICAL_TYPE))
    {
      add (t, "+", t, t);
      add (t, "-", t, t);
      add (t, "abs", t, NULL);
      add (t, "+", t, NULL);
      add (t, "-", t, NULL);
    }

  // concatenation operator
  //
  if(pIIR_Type et = is_one_dim_array(bt)) 
    {
      add (t, "&", t, t);
      add (t, "&", t, et);
      add (t, "&", et, t);
      add (t, "&", et, et);
    }

  // Multiplying operators
  //
  if (bt->is(IR_INTEGER_TYPE)
      || bt->is(IR_FLOATING_TYPE))
    {
      add (t, "*", t, t);
      add (t, "/", t, t);
      if (bt->is(IR_INTEGER_TYPE))
	{
	  add (t, "mod", t, t);
	  add (t, "rem", t, t);
	}
      if (std->predef_INTEGER)
	add (t, "**", t, std->predef_INTEGER);
      else if (bt != std->universal_integer && bt != std->universal_real) 
	{
	  info ("%:can't predefine \"**\" operator for %n", t, t);
	  info ("%:since type INTEGER is undefined", t);
	}
    }
  
  if (bt->is(IR_PHYSICAL_TYPE))
    {
      if (std->predef_INTEGER && std->predef_REAL) 
	{
	  add (t, "*", t, std->predef_INTEGER);
	  add (t, "*", std->predef_INTEGER, t);
	  add (t, "/", t, std->predef_INTEGER);
	  add (t, "*", t, std->predef_REAL);
	  add (t, "*", std->predef_REAL, t);
	  add (t, "/", t, std->predef_REAL);
	}
      else 
	{
	  info ("%:can't predefine multiplying operators for %n", t, t);
	  info ("%:since types INTEGER and REAL are undefined", t);
	}
      if (std->universal_integer)
	add (std->universal_integer, "/", t, t);
    }

  if (t == std->predef_INTEGER) 
    {
      add (std->universal_integer, "**", std->universal_integer, t);
      add (std->universal_real, "**", std->universal_real, t);
    }

  if (t->is(IR_ACCESS_TYPE)) 
    {
      pIIR_InterfaceList parm =
	mIIR_InterfaceList (t->pos, 
			    mIIR_VariableInterfaceDeclaration (t->pos, NULL,
							       t, NULL,
							       IR_INOUT_MODE,
							       false),
			    NULL);
      pIIR_PredefinedProcedureDeclaration dealloc =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("deallocate"),
					     parm);
      add_decl(dealloc);
    }
    
  if (t->is(IR_FILE_TYPE))
    {
      pIIR_FileType ft = pIIR_FileType(t);

      // FILE_OPEN 
      
      pIIR_Expression read_mode = NULL; // XXX

      {
	// long hand for finding READ_MODE
	
	for (pIIR_DeclarationList dl = std->declarations;
	     dl; dl = dl->rest)
	  if (dl->first
	      && vaul_name_eq (dl->first->declarator, "READ_MODE"))
	    {
	      assert (dl->first->is(IR_ENUMERATION_LITERAL));
	      pIIR_EnumerationLiteral lit =
		pIIR_EnumerationLiteral (dl->first);
	      read_mode = mIIR_EnumLiteralReference (ft->pos,
						     lit->subtype,
						     lit);
	      break;
	    }

	if (read_mode == NULL)
	  error ("can't find READ_MODE in std.standard");
      }
						     
      pIIR_InterfaceList parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_ConstantInterfaceDeclaration 
			    (t->pos, make_id ("Open_Kind"),
			     std->predef_FILE_OPEN_KIND,
			     read_mode,
			     IR_IN_MODE,
			     false),
			    NULL);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_ConstantInterfaceDeclaration 
			    (t->pos, make_id ("External_Name"),
			     std->predef_STRING, NULL,
			     IR_IN_MODE,
			     false),
			    parm);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration 
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    parm);

      pIIR_PredefinedProcedureDeclaration file_open1 =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("FILE_OPEN"),
					     parm);
      add_decl(file_open1);

      // FILE_OPEN

      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_ConstantInterfaceDeclaration 
			    (t->pos, make_id ("Open_Kind"),
			     std->predef_FILE_OPEN_KIND,
			     read_mode,
			     IR_IN_MODE,
			     false),
			    NULL);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_ConstantInterfaceDeclaration 
			    (t->pos, make_id ("External_Name"),
			     std->predef_STRING, NULL,
			     IR_IN_MODE,
			     false),
			    parm);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration 
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    parm);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_VariableInterfaceDeclaration 
			    (t->pos, make_id ("Status"),
			     std->predef_FILE_OPEN_STATUS, NULL,
			     IR_OUT_MODE,
			     false),
			    parm);

      pIIR_PredefinedProcedureDeclaration file_open2 =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("FILE_OPEN"),
					     parm);
      add_decl(file_open2);

      // FILE_CLOSE

      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration 
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    NULL);

      pIIR_PredefinedProcedureDeclaration file_close =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("FILE_CLOSE"),
					     parm);
      add_decl(file_close);
      
      // READ

      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_VariableInterfaceDeclaration 
			    (t->pos, make_id ("VALUE"),
			     ft->type_mark,
			     NULL,
			     IR_OUT_MODE,
			     false),
			    NULL);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    parm);
      
      pIIR_PredefinedProcedureDeclaration read =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("READ"),
					     parm);
      add_decl(read);

      // WRITE

      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_VariableInterfaceDeclaration 
			    (t->pos, make_id ("VALUE"),
			     ft->type_mark,
			     NULL,
			     IR_IN_MODE,
			     false),
			    NULL);
      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    parm);
      pIIR_PredefinedProcedureDeclaration write =
	mIIR_PredefinedProcedureDeclaration (t->pos,
					     make_id ("WRITE"),
					     parm);
      add_decl(write);

      // ENDFILE

      parm =
	mIIR_InterfaceList (t->pos,
			    mIIR_FileInterfaceDeclaration 
			    (t->pos, make_id ("F"),
			     ft, NULL,
			     IR_UNKNOWN_MODE,
			     false),
			    NULL);
      pIIR_PredefinedFunctionDeclaration endfile =
	mIIR_PredefinedFunctionDeclaration (t->pos,
					    make_id ("ENDFILE"),
					    parm,
					    false,
					    std->predef_BOOLEAN);
      add_decl(endfile);
    }
  
#   undef add
}

void
vaul_add_incomplete_type_use (pVAUL_IncompleteType it, pIIR_Type &ref)
{
  assert (ref == it);
  vaul_incomplete_type_use *u = new vaul_incomplete_type_use;
  u->next = it->uses;
  it->uses = u;
  u->ref = &ref;
}

void
vaul_complete_incomplete_type (pVAUL_IncompleteType it, pIIR_Type t)
{
  for (vaul_incomplete_type_use *u = it->uses; u; u = u->next) 
    {
      assert(*u->ref == it);
      *u->ref = t;
    }
}

pIIR_TypeList
psr::build_PreIndexConstraint (pVAUL_GenAssocElem a)
{
    pIIR_TypeList ic = NULL, *ict = &ic;

    while (a)
      {
	pIIR_Type type = NULL;

	if (a->is(VAUL_NAMED_ASSOC_ELEM))
	  {
	    pVAUL_NamedAssocElem nae = pVAUL_NamedAssocElem(a);
	    if (nae->formal)
	      error ("%:index constraints can't use named association", nae);
	    if (nae->actual && nae->actual->is(VAUL_UNRESOLVED_NAME))
	      {
		pVAUL_Name n = pVAUL_UnresolvedName(nae->actual)->name;
		pIIR_Type st = get_type (n);
		if (is_discrete_type(st))
		  type = mVAUL_PreIndexSubtypeConstraint(a->pos, st);
		else if (st)
		  error ("%: %n is not a discrete type", n, st);
	      }
	  }
	else if (a->is(VAUL_RANGE_ASSOC_ELEM))
	  {
	    type = mVAUL_PreIndexRangeConstraint(a->pos,
					    pVAUL_RangeAssocElem(a)->range);
	  }
	else if (a->is(VAUL_SUBTYPE_ASSOC_ELEM)) 
	  {
	    type = mVAUL_PreIndexSubtypeConstraint(a->pos,
					      pVAUL_SubtypeAssocElem(a)->type);
	  }

	if (type)
	  {
	    *ict = mIIR_TypeList (a->pos, type, *ict);
	    ict = &(*ict)->rest;
	  }

	a = a->next;
      }

    return ic;
}

pIIR_ScalarSubtype
psr::make_scalar_subtype (pIIR_PosInfo pos, pIIR_Type t,
			  int left, int right)
{
  info ("+++ - making subtype %n %d to %d", t, left, right);

  assert (t->is (IR_SCALAR_SUBTYPE));
  pIIR_Type base = t->base;

  // The expressions that we generate are
  //
  //   t'VAL(t'POS(t'LEFT) + left) and
  //   t'VAL(t'POS(t'LEFT) + right).

  char buf[128];

  sprintf (buf, "%d", left);
  pIIR_IntegerLiteral left_lit =
    mIIR_IntegerLiteral (pos, (IR_Character *)buf, strlen(buf));
  pIIR_Expression t_left_pos =
    mIIR_Attr_POS (pos, std->universal_integer,
		   t, mIIR_Attr_LEFT (pos, t,
				      t, NULL));
  pIIR_Expression t_left_new_pos =
    build_bcall (t_left_pos, "+",
		 build_LiteralExpression (pos,
					  left_lit));
  overload_resolution (t_left_new_pos, t);
  pIIR_Expression t_left_val =
    mIIR_Attr_VAL (pos, t, t, t_left_new_pos);

  sprintf (buf, "%d", right);
  pIIR_IntegerLiteral right_lit =
    mIIR_IntegerLiteral (pos, (IR_Character *)buf, strlen(buf));
  pIIR_Expression t_right_pos =
    mIIR_Attr_POS (pos,  std->universal_integer,
		   t, mIIR_Attr_LEFT (pos, t,
				      t, NULL));
  pIIR_Expression t_right_new_pos =
    build_bcall (t_right_pos, "+",
		 build_LiteralExpression (pos,
					  right_lit));
  overload_resolution (t_right_new_pos, t);
  pIIR_Expression t_right_val =
    mIIR_Attr_VAL (pos, t, t, t_right_new_pos);

  return mIIR_ScalarSubtype (pos,
			     t->base, t,
			     NULL,
			     mIIR_ExplicitRange (pos,
						 t_left_val,
						 t_right_val,
						 IR_DIRECTION_UP));
}

static int
stringlitlen (pIIR_StringLiteral str)
{
  IR_String &s = str->text;
  int q = 0;
  for (int i = 1; i < s.len()-1; i++)
    if (s[i] == '"')
      q++;
  return s.len()-2-q/2;
}

pIIR_Type
psr::adapt_object_type (VAUL_ObjectClass c,
			pIIR_Type t,
			pIIR_Expression init)
{
  if (t == NULL)
    return NULL;
  
  if (c == VAUL_ObjClass_Variable || c == VAUL_ObjClass_Signal) 
    {
      if (t->is(IR_ARRAY_TYPE))
	error("array objects must have a constrained type");
      return t;
    }

  if (c == VAUL_ObjClass_Constant) 
    {
      if (init == NULL || !t->is(IR_ARRAY_TYPE))
	return t;

      pIIR_ArrayType at = pIIR_ArrayType(t);

      if (init->subtype && init->subtype->is (IR_ARRAY_SUBTYPE))
	return init->subtype;

      if (init->is (IR_ARRAY_LITERAL_EXPRESSION)
	  || init->is (VAUL_AMBG_ARRAY_LIT_REF))
	{
	  assert (at->index_types && at->index_types->rest == NULL);

	  pIIR_StringLiteral value;
	  if (init->is (IR_ARRAY_LITERAL_EXPRESSION))
	    value = pIIR_ArrayLiteralExpression(init)->value;
	  else
	    value = pVAUL_AmbgArrayLitRef(init)->value;

	  // This is actually not correct as left bound and range
	  // direction of the array index are determined from the
	  // unconstrained array type. I.e., left index bound and
	  // direction = left index bound and direction of
	  // unconstrained array (and not necessarily 0)!
	  pIIR_ScalarSubtype st = make_scalar_subtype (init->pos,
						       at->index_types->first,
						       0,
						       stringlitlen (value) - 1);
	  if (st == NULL)
	    return t;

	  pIIR_ArraySubtype as =
	    mIIR_ArraySubtype (init->pos,
			       t->base,
			       t, NULL, mIIR_TypeList (init->pos,
						       st, NULL));
	  return as;
	}
      else if (init->is (VAUL_AMBG_AGGREGATE))
	{
	  if (at->index_types->rest)
	    {
	      //error ("can't determine array subtype from
	      //multi-dimensional aggregates, yet."); 
	      
	      //Note: this is currently done by the code generator! 
	      //Hence, do not produce an error message.
	      return t;
	    }
		
	  int n = 0;
	  for (pVAUL_ElemAssoc ea = pVAUL_AmbgAggregate (init)->first_assoc;
	       ea; ea = ea->next)
	    {
	      if (ea->choices)
		{
		  //error ("can't determine array subtype from
		  //aggregates with index associations, yet.");

		  //Note: this is currently done by the code
		  //generator! Hence, do not produce an error message.
		  return t;
		}
	      n += 1;
	    }
	  
	  pIIR_ScalarSubtype st = make_scalar_subtype (init->pos,
						       at->index_types->first,
						       0, n-1);
	  if (st == NULL)
	    return t;

	  pIIR_ArraySubtype as =
	    mIIR_ArraySubtype (init->pos,
			       t->base,
			       t, NULL, mIIR_TypeList (init->pos,
						       st, NULL));
	  return as;
	}
      else
	{
	  // error ("can't determine array subtype from %s yet.",
	  //        init->kind_name ());

	  //Note: this is currently done by the code
	  //generator! Hence, do not produce an error message.
	  return t;
	}
    }
  else
    info ("xxx - unchecked object type");

  return t;
}

pIIR_ArraySubtype
psr::build_constrained_array_type (pIIR_TypeList pre,
				   pIIR_Type elt)
{
  pIIR_TypeList itypes = NULL, *itail = &itypes;
  
  for (pIIR_TypeList p = pre; p; p = p->rest)
    {
      pIIR_Type it, pt = p->first;
      
      if (pt->is(VAUL_PRE_INDEX_SUBTYPE_CONSTRAINT))
	it = pVAUL_PreIndexSubtypeConstraint(pt)->type;
      else if (pt->is(VAUL_PRE_INDEX_RANGE_CONSTRAINT)) 
	{
	  pIIR_Range r = pVAUL_PreIndexRangeConstraint(pt)->range;
	  if (r == NULL)
	    return NULL;
	  if (r->is(IR_EXPLICIT_RANGE))
	    it = find_index_range_type (pIIR_ExplicitRange(r));
	  else if (r->is(IR_ARRAY_RANGE))
	    it = pIIR_ArrayRange(r)->type;
	  else
	    assert (false);
	}
      else
	assert(false);

      *itail = mIIR_TypeList(p->pos, it, NULL);
      itail = &(*itail)->rest;
    }

  pIIR_ArrayType base = mIIR_ArrayType(pre? pre->pos:NULL, itypes, elt);
  return mIIR_ArraySubtype (base->pos, base,
			    base, NULL, build_IndexConstraint (pre, base));
}

bool
psr::legal_file_type (pIIR_Type t)
{
  if (t == NULL)
    return true;

  pIIR_Type b = t->base;

  if (b->is(IR_FILE_TYPE)
      || b->is(IR_ACCESS_TYPE)
      /* || b->is(IR_PROTECTED_TYPE) */ )
    {
      error ("%n can not be used as the contents of a file", b);
      return false;
    }

  if (b->is(IR_ARRAY_TYPE))
    {
      pIIR_ArrayType at = pIIR_ArrayType(b);
      if (at->index_types && at->index_types->rest != NULL)
	{
	  error ("only one dimensional arrays can be used with files");
	  return false;
	}
      return legal_file_type (at->element_type);
    }

  if (b->is(IR_RECORD_TYPE))
    {
      pIIR_RecordType rt = pIIR_RecordType (b);
      bool result = true;
      for (pIIR_ElementDeclarationList elts = rt->element_declarations;
	   elts; elts = elts->rest)
	{
	  if (elts->first && !legal_file_type (elts->first->subtype))
	    result = false;
	}
      return result;
    }

  return true;
}

pIIR_FileType
psr::build_FileType (pVAUL_Name type_mark)
{
  pIIR_Type ct = get_type (type_mark);
  if (!legal_file_type (ct))
    return NULL;
  return mIIR_FileType (type_mark->pos, ct);
}

pIIR_FileDeclaration
psr::add_File (pIIR_Identifier id,
	       pIIR_Type file_type,
	       pIIR_Expression mode,
	       pVAUL_FilenameAndMode name_and_mode)
{
  if (!file_type->is(IR_FILE_TYPE))
    {
      error ("%:%n is not a file type", id, file_type);
      return NULL;
    }
  if (name_and_mode && name_and_mode->mode != IR_UNKNOWN_MODE)
    {
      const char *mode_id;

      if (mode != NULL)
	{
	  error ("%:mixed '93 and '87 syntax in file declaration", id);
	  return NULL;
	}
      if (name_and_mode->mode == IR_IN_MODE)
	mode_id = "READ_MODE";
      else if (name_and_mode->mode == IR_OUT_MODE)
	mode_id = "WRITE_MODE";
      else
	abort ();

      pIIR_PosInfo pos = name_and_mode->name->pos;
      pVAUL_Name mode_name =
	mVAUL_SelName (pos,
		       mVAUL_SelName (pos,
				      mVAUL_SimpleName (pos, make_id ("std")),
				      make_id ("standard")),
		       make_id (mode_id));
      mode = build_Expr (mode_name);
      overload_resolution (mode, std->predef_FILE_OPEN_KIND);
    }

  return pIIR_FileDeclaration (
     add_decl(mIIR_FileDeclaration (id->pos, id, file_type,
				    NULL, mode,
				    (name_and_mode?
				     name_and_mode->name : NULL))));
}

pIIR_Type
m_vaul_get_base (pIIR_Type t)
{
  return t->base;
}

void
vaul_fix_static_level (pIIR_Type t)
{
  t->static_level = vaul_compute_static_level (t);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_RecordType t)
{
  IR_StaticLevel lev = IR_LOCALLY_STATIC;
  for (pIIR_ElementDeclarationList el = t->element_declarations;
       el; el = el->rest)
    lev = vaul_merge_levels (lev, el->first->subtype->static_level);
  return lev;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_RecordSubtype t)
{
  return t->base->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ArrayType t)
{
  return IR_NOT_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ArraySubtype t)
{
  // Note: the static level of the base type does not enter the
  // definition.

  IR_StaticLevel lev = IR_LOCALLY_STATIC;
  for (pIIR_TypeList cl = t->constraint; cl; cl = cl->rest)
    lev = vaul_merge_levels (lev, cl->first->static_level);
  return lev;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ScalarSubtype t)
{
  IR_StaticLevel lev = t->base->static_level;
  if (t->range)
    lev = vaul_merge_levels (lev, vaul_compute_static_level (t->range));
  return lev;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_Type t)
{
  // All types except the ones handled above are unconditionally
  // locally static.  This includes file types with non-static element
  // types, for example.

  return IR_LOCALLY_STATIC;
}
