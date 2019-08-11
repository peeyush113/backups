/* expressions

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
#include "vaulgens-chunk.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define psr vaul_parser

static int aggregate_conversion_cost(pVAUL_AmbgAggregate, pIIR_Type t, IR_Kind k);

pIIR_PhysicalLiteral
psr::build_PhysicalLiteral (pIIR_AbstractLiteral lit, 
			    pIIR_Identifier unit)
{
  pVAUL_Name u = mVAUL_SimpleName(lit->pos, unit);
  pIIR_Declaration d = find_single_decl (u, IR_PHYSICAL_UNIT, "physical unit");
  if (d == NULL)
    return NULL;
  pIIR_PhysicalUnit pu = pIIR_PhysicalUnit(d);
  return mIIR_PhysicalLiteral(lit->pos, pu->type, lit, pu);
}

pIIR_AbstractLiteralExpression
psr::build_LiteralExpression (pIIR_PosInfo pos, pIIR_AbstractLiteral lit)
{
  if (lit->is(IR_INTEGER_LITERAL))
    return mIIR_AbstractLiteralExpression(pos, std->universal_integer, lit);
  else if (lit->is(IR_FLOATING_POINT_LITERAL))
    return mIIR_AbstractLiteralExpression(pos, std->universal_real, lit);
  else
    abort ();
}

pIIR_AbstractLiteralExpression
psr::build_LiteralExpression (int lineno, pIIR_AbstractLiteral lit)
{
  return build_LiteralExpression (make_posinfo (lineno), lit);
}

pIIR_Expression
psr::build_QualifiedExpr(pVAUL_Name m, pIIR_Expression e)
{
  pIIR_Type t = get_type(m);
  if (t == NULL)
    return NULL;
  overload_resolution (e, t);
  return mIIR_QualifiedExpression(m->pos, t, t, e);
}

pIIR_Expression
psr::build_TypeConversion (pIIR_PosInfo pos,
			   pIIR_Type t,
			   pIIR_Expression e)
{
  overload_resolution(e, IR_TYPE);
  // XXX - check for closely related types and stuff
  // info("xxx - unchecked conversion from %n to %n", expr_type(e), t);
  return mIIR_TypeConversion(pos, t, t, e);
}

pIIR_Expression psr::build_bcall(pIIR_Expression l, const char *op, pIIR_Expression r)
{
  // XXX - reincarnate lno parm.

  pIIR_PosInfo pos = l? l->pos : make_posinfo(0);
  pVAUL_Name n =
    mVAUL_IftsName(pos,
		   mVAUL_SimpleName(pos, make_opid(op)),
		   mVAUL_NamedAssocElem(pos,
					r? mVAUL_NamedAssocElem(pos,
								NULL,
								NULL,
								r) : NULL,
					NULL, l));
  return build_Expr(n);
}

static void
iterate_for_kind (pIIR_Declaration d, void *cl)
{
  IR_Kind &basic_k = *(IR_Kind *)cl;
  IR_Kind this_k = d->kind();
  
  if (basic_k == IR_INVALID)
    basic_k = this_k;
  else if (basic_k != this_k && !tree_is (this_k, basic_k))
    {
      while (!tree_is(basic_k, this_k))
	this_k = tree_base (this_k);
      basic_k = this_k;
    }
}

static int
filter_for_kind_ignore_funcs (pIIR_Declaration d, void *cl)
{
  if (!d->is(IR_SUBPROGRAM_DECLARATION))
    {
      iterate_for_kind (d, cl);
      return 0;
    } 
  else
    return -1;
}

static int
filter_for_kind_ignore_enums (pIIR_Declaration d, void *cl)
{
  if (!d->is(IR_ENUMERATION_LITERAL))
    {
      iterate_for_kind (d, cl);
      return 0;
    }
  else
    return -1;
}

pIIR
psr::build_Expr_or_Attr (pVAUL_Name n)
{
  // A SimpleName with a StringLiteral as its id is really a string literal.
  
  if (n->is(VAUL_SIMPLE_NAME)
      && pVAUL_SimpleName(n)->id->is(IR_STRING_LITERAL))
    return mVAUL_AmbgArrayLitRef (n->pos, NULL, 
				  pIIR_StringLiteral(pVAUL_SimpleName(n)->id));

  // see what declarations a prefix of the name matches
  
  vaul_decl_set *set = new vaul_decl_set(this);
  find_decls(*set, n);

  if (!set->multi_decls (false))
    {
      delete set;
      return mVAUL_UnresolvedName (n->pos, NULL, n);
    }

  // recursivly resolve the rest of the name.
  
  return build_Expr_or_Attr (n, set, IR_INVALID);
}

static pVAUL_SimpleName
get_simple_name (pVAUL_Name n)
{
  if (n->is(VAUL_SIMPLE_NAME))
    return pVAUL_SimpleName(n);
  else if (n->is(VAUL_SEL_NAME))
    return get_simple_name(pVAUL_SelName(n)->prefix);
  else if (n->is(VAUL_IFTS_NAME))
    return get_simple_name(pVAUL_IftsName(n)->prefix);
  else
    return NULL;
}

pIIR_Expression
psr::build_formal_Expr (pIIR_InterfaceDeclaration formal, pVAUL_Name n)
{
  // construct a decl_set that has found the given formal

  vaul_decl_set *set = new vaul_decl_set(this);
  set->add (formal);
  set->name = get_simple_name (n);

  // recursivly resolve the rest of the name.
  
  pIIR ea = build_Expr_or_Attr (n, set, IR_INVALID);
  return validate_Expr (ea);
}

pIIR_Expression
psr::validate_Expr (pIIR ea)
{
  if (ea == NULL)
    return NULL;
  if (ea->is(IR_EXPRESSION))
    return pIIR_Expression(ea);
  if (ea->is(IR_ARRAY_RANGE))
    error ("%:%n can not be used in an expression", ea, ea);
  else
    error ("%:%n can only be used as the prefix of another attribute",
	   ea, ea);
  return NULL;
}

pIIR_Expression
psr::build_Expr (pVAUL_Name n)
{
  pIIR ea = build_Expr_or_Attr (n);
  return validate_Expr (ea);
}

pIIR_Expression psr::make_appropriate(pIIR_Expression e)
{
  if (e && try_overload_resolution(e, NULL, IR_ACCESS_TYPE)) 
    {
      overload_resolution (e, IR_ACCESS_TYPE);
      pIIR_Type at = expr_type (e);
      if (at == NULL)
	return NULL;
      at = vaul_get_base (at);
      assert (at->is(IR_ACCESS_TYPE));
      e = mIIR_AccessReference (e->pos, pIIR_AccessType(at)->designated_type,
				e);
    }
  return e;
}

pIIR
psr::build_Expr_or_Attr (pVAUL_Name n, vaul_decl_set *set, IR_Kind basic_k)
{
  if (basic_k == IR_INVALID) 
    set->iterate (iterate_for_kind, &basic_k);

  if (n->is(VAUL_IFTS_NAME)
      || (set->name == n && tree_is(basic_k, IR_SUBPROGRAM_DECLARATION))) 
    {
      
      // An array subscription, a function call (maybe without
      // arguments), a type conversion, or an array slicing.

      pVAUL_Name pfx = n;
      pVAUL_GenAssocElem a = NULL;

      if (n->is(VAUL_IFTS_NAME)) 
	{
	  pfx = pVAUL_IftsName(n)->prefix;
	  a = pVAUL_IftsName(n)->assoc;
	}

      // Now PFX is the function to be called, the array to be
      // subscripted or sliced, or the target type of the conversion.
      // A is the list of arguments, or NULL if there are none.

      if (a && (a->is(VAUL_RANGE_ASSOC_ELEM)
		|| a->is(VAUL_SUBTYPE_ASSOC_ELEM))) 
	{
	  // An array slice.
	  
	  pIIR_Expression prefix =
	    make_appropriate (build_Expr (pfx, set, basic_k));
	  overload_resolution (prefix, NULL, IR_ARRAY_TYPE, false, false);
	  return build_SliceReference (prefix, a);
	}
      else if (set->name == pfx 
	       && tree_is (basic_k, IR_SUBPROGRAM_DECLARATION)) 
	{
	  // A function call.

	  if (prepare_named_assocs(a)) 
	    {
	      pVAUL_AmbgCall e = mVAUL_AmbgCall (pfx->pos, NULL,
						 pVAUL_NamedAssocElem(a));
	      e->set = set;
	      
	      int c = pre_constrain (e);
	      if (c < 0)
		{
		  report_mismatched_subprog (pfx, set,
					     pVAUL_NamedAssocElem(a));
		  delete set;
		  return NULL;
		}
	      
	      e->set->invalidate_pot_invalids();
	      
	      // When we have more than one member, they must be enum
	      // literals or be distinguishable by their return type.
	      
	      // XXX -- check this.
	      
	      return e;
	    }
	}
      else
	{
	  if (set->name == pfx && tree_is (basic_k, IR_TYPE_DECLARATION)) 
	    {
	      // A type conversion.
	      
	      if (a == NULL || a->next != NULL)
		error ("%:type conversions must have exactly one argument",
		       pfx);
	      else if (!a->is(VAUL_NAMED_ASSOC_ELEM) 
		       || pVAUL_NamedAssocElem(a)->formal)
		error ("%:argument of type conversion must be a simple "
		       "expression", pfx);
	      else 
		{
		  pIIR_Declaration d = set->single_decl ();
		  delete set;
		  assert (d 
			  && d->is(IR_TYPE_DECLARATION) 
			  && a->is(VAUL_NAMED_ASSOC_ELEM));
		  pIIR_Expression e = pVAUL_NamedAssocElem(a)->actual;
		  return build_TypeConversion (pfx->pos,
					       pIIR_TypeDeclaration(d)->type,
					       e);
		}
	    }
	  else 
	    {
	      assert(n->is(VAUL_IFTS_NAME));
	      // An array subscription.
	      
	      pIIR_Expression prefix =
		make_appropriate (build_Expr (pfx, set, basic_k));
	      overload_resolution (prefix, NULL, IR_ARRAY_TYPE, false, false);
	      return build_ArrayReference (prefix, a);
	    }
	}
      
    }
  else if (n == set->name)
    {
      if (tree_is (basic_k, IR_ENUMERATION_LITERAL)
	  || basic_k == IR_DECLARATION)
	{
	  /* We have basic_k == IR_DECLARATION when set contains both
	     enumeration literals and subprograms.  Overload
	     resolution will handle this special case.
	  */
	  pVAUL_AmbgEnumLitRef e = mVAUL_AmbgEnumLitRef(n->pos, NULL);
	  e->set = set;
	  return e;
	}
#if 0
      else if (tree_is (basic_k, IR_ALIAS_DECLARATION))
	{
	  pIIR_Declaration d = set->single_decl();
	  delete set;
	  if (d == NULL)
	    return NULL;
	  assert (d->is(IR_ALIAS_DECLARATION));
	  return pIIR_AliasDeclaration(d)->initial_value;
	}
#endif
      else if (!tree_is (basic_k, IR_OBJECT_DECLARATION)
	       && !tree_is(basic_k, IR_PHYSICAL_UNIT))
	{
	  delete set;
	  return mVAUL_UnresolvedName(n->pos, NULL, n);
	}
      
      pIIR_Declaration d = set->single_decl();
      delete set;
      if(d == NULL)
	return NULL;
      
      if (d->is(IR_OBJECT_DECLARATION))
	{
	  pIIR_ObjectDeclaration od = pIIR_ObjectDeclaration(d);
	  pIIR_SimpleReference sr =
	    mIIR_SimpleReference(n->pos, od->subtype, od);
	  simple_reference_name(sr) = n;
	  return sr;
	}
      else if (d->is(IR_PHYSICAL_UNIT))
	{
	  pIIR_PhysicalUnit u = pIIR_PhysicalUnit(d);
	  return mIIR_PhysicalLiteral(n->pos, u->type, NULL, u);
	}
      else
	assert (false);
    }
  else if (n->is(VAUL_ATTRIBUTE_NAME))
    {
      return build_AttrNode(pVAUL_AttributeName(n), set, basic_k);
    }
  else if (n->is(VAUL_SEL_NAME))
    {
      pIIR_TextLiteral suffix = pVAUL_SelName(n)->suffix;
      pVAUL_Name pfx = pVAUL_SelName(n)->prefix;
      pIIR_Expression orig_prefix = build_Expr (pfx, set, basic_k);
      pIIR_Expression prefix = make_appropriate (orig_prefix);
      
      if (prefix != orig_prefix && vaul_name_eq (suffix, "all"))
	return prefix;
      overload_resolution (prefix, NULL, IR_RECORD_TYPE, false, false);
      if (prefix == NULL)
	return NULL;
      pIIR_Type t = expr_type (prefix);
      if (t == NULL || !t->base->is(IR_RECORD_TYPE))
	{
	  info ("XXX - not a record type %n", t);
	  return NULL;
	}
      pIIR_RecordType rt = pIIR_RecordType(t->base);
      for (pIIR_ElementDeclarationList elts = rt->element_declarations;
	   elts; elts = elts->rest)
	{
	  pIIR_ElementDeclaration re = elts->first;
	  if (vaul_name_eq (re->declarator, suffix))
	    return mIIR_RecordReference(n->pos, re->subtype, prefix, re);
	}
      error("%:%n has no element named %n, it has", n, rt, suffix);
      for (pIIR_ElementDeclarationList elts = rt->element_declarations;
	   elts; elts = elts->rest)
	{
	  pIIR_ElementDeclaration re = elts->first;
	  info("%: %n: %n", re, re->declarator, re->subtype);
	}
      return NULL;
      
    }
  else
    {
      info ("%:XXX - unimplemented partial expr name %n (%n)",
	    n, n, set->name);
    }
  
  delete set;
  return NULL;
}

pIIR_Expression
psr::build_Expr (pVAUL_Name n, vaul_decl_set *set, IR_Kind basic_k)
{
  pIIR ea = build_Expr_or_Attr (n, set, basic_k);
  return validate_Expr (ea);
}

void
psr::report_mismatched_subprog (pVAUL_Name pfx, vaul_decl_set *set,
				pVAUL_NamedAssocElem assocs)
{
  bool obvious = true;
  my_dynparray<pIIR_Type_vector> assoc_types;
  
  for (pVAUL_NamedAssocElem na = assocs; na;
       na = pVAUL_NamedAssocElem(na->next))
    {
      assert (na->is(VAUL_NAMED_ASSOC_ELEM));
      pIIR_Type_vector *tv = ambg_expr_types (na->actual);
      assert (tv);
      assoc_types.add (tv);
      if (tv->size() > 5)
	obvious = false;
    }
  if (obvious || options.fullnames)
    {
      error ("%:no declaration matches use as %n(%~", pfx, pfx);
      int i = 0;
      for (pVAUL_NamedAssocElem na = assocs; na;
	   na = pVAUL_NamedAssocElem(na->next))
	{
	  assert (na->is(VAUL_NAMED_ASSOC_ELEM));
	  if (na->formal)
	    info ("%~%n => %~", na->formal);
	  pIIR_Type_vector *tv = assoc_types[i++];
	  if (tv->size() == 0)
	    info ("%~?%~");
	  if (tv->size() > 1)
	    info ("%~{ %~");
	  for (int j = 0; j < tv->size(); j++) 
	    {
	      info ("%~%n%~", (*tv)[j]);
	      if (j < tv->size()-1)
		info("%~ | %~");
	    }
	  if (tv->size() > 1)
	    info ("%~ }%~");
	  if (na->next)
	    info ("%~, %~");
	}
      info ("%~), candidates are");
    }
  else
    error ("%:no declaration of %n matches this unobvious use, candidates are",
	   pfx, pfx);
  for (int i = 0; i < assoc_types.size(); i++)
    delete assoc_types[i];
  set->show ();
}

pIIR_ArrayReference
psr::build_ArrayReference (pIIR_Expression prefix, pVAUL_GenAssocElem a)
{
  if (prefix == NULL || a == NULL)
    return NULL;
  
  pIIR_Type t = expr_type (prefix);
  if (t == NULL)
    return NULL;

  if (!t->base->is(IR_ARRAY_TYPE))
    {
      error ("%:can't subscribe %n (not an array)", a, prefix);
      return NULL;
    }
    
  pIIR_ArrayType at = pIIR_ArrayType(t->base);
  if (at->index_types == NULL)
    return NULL;
  
  pIIR_ArrayReference aor = mIIR_ArrayReference (a->pos, at->element_type, 
						 prefix, NULL);
  pIIR_ExpressionList *ind_tail = &aor->indices;
  for (pIIR_TypeList it = at->index_types; it; it = it->rest)
    {
      if (a == NULL)
	{
	  error ("%:too few subscripts for array %n", prefix, prefix);
	  return NULL;
	}
      if (!a->is(VAUL_NAMED_ASSOC_ELEM) || pVAUL_NamedAssocElem(a)->formal)
	{
	  error("%:array subscripts must be simple expressions", a);
	  return NULL;
	}
      
      pVAUL_NamedAssocElem na = pVAUL_NamedAssocElem(a);
      overload_resolution (na->actual, it->first);
      *ind_tail = mIIR_ExpressionList (a->pos, na->actual, NULL);
      ind_tail = &(*ind_tail)->rest;
      a = a->next;
    }

  if (a)
    {
      error ("%:too many subscripts for array %n", a, prefix);
      return NULL;
    }
  
  return aor;
}

pIIR_SliceReference
psr::build_SliceReference (pIIR_Expression prefix, pVAUL_GenAssocElem slice)
{
  if (prefix == NULL || slice == NULL)
    return NULL;

  pIIR_Range r = range_from_assoc (slice);
  pIIR_Type rt = ensure_range_type (r, NULL);

  if (rt == NULL)
    return NULL;

  assert (slice->next == NULL);

  pIIR_Type t = expr_type (prefix);
  if (t == NULL)
    return NULL;

  if (!t->base->is(IR_ARRAY_TYPE))
    {
      error("%:can't take slice of %n (not an array)", slice, prefix);
      return NULL;
    }

  pIIR_ArrayType at = pIIR_ArrayType(t->base);
  if (at->index_types && at->index_types->rest)
    error ("%:sliced arrays must be one-dimensional", slice);

  if (rt && at->index_types && at->index_types->first 
      && rt->base != at->index_types->first->base)
    {
      error ("%:type of slice bounds does not match array index type", slice);
      r = NULL;
    }

  pIIR_ScalarSubtype it = mIIR_ScalarSubtype (slice->pos,
					      rt->base,
					      rt,
					      NULL,
					      r);
  pIIR_ArraySubtype st = mIIR_ArraySubtype (slice->pos,
					    at,
					    t,
					    NULL,
					    mIIR_TypeList (slice->pos,
							   it,
							   NULL));

  return mIIR_SliceReference (slice->pos, st, prefix, r);
}

int
psr::try_one_association (pVAUL_NamedAssocElem a,
			  pIIR_InterfaceDeclaration f)
{
  // XXX - what about formal and actual conversions?
  return constrain (a->actual, f->subtype, IR_INVALID);
}

static pIIR_InterfaceDeclaration
find_interface_by_id (pIIR_InterfaceList list, pIIR_TextLiteral id)
{
  if (!id->is(IR_IDENTIFIER))
    return NULL;

  while (list)
    {
      if (vaul_name_eq (list->first->declarator, id))
	return list->first;
      list = list->rest;
    }
  return NULL;
}

pIIR_Declaration
psr::grab_formal_conversion (pVAUL_NamedAssocElem assoc,
			     pIIR_InterfaceList formals,
			     int *formal_cost,
			     pIIR_InterfaceDeclaration *converted_formal)
{
    if (assoc->ifts_decls == NULL)
	return NULL;

    // We have either function(ifc) or type(ifc) with ifc being
    // the only argument.
    
    assert(assoc->formal->is(VAUL_IFTS_NAME));
    pVAUL_IftsName ifts = pVAUL_IftsName(assoc->formal);
    assert(ifts->assoc && ifts->assoc->is(VAUL_NAMED_ASSOC_ELEM));
    pVAUL_NamedAssocElem arg = pVAUL_NamedAssocElem(ifts->assoc);
    assert(arg->next == NULL);
    IR_Kind kind = assoc->ifts_kind;
    pVAUL_SimpleName sn = assoc->ifts_arg_name;
    assert(sn);

    if (pIIR_InterfaceDeclaration f = find_interface_by_id (formals, sn->id))
      {
	pIIR_Declaration conversion = NULL;
	int fcost;
	if (tree_is(kind, IR_FUNCTION_DECLARATION))
	  {
	    // See if we can resolve the function.

	    pIIR_SimpleReference mor = mIIR_SimpleReference (assoc->pos,
							    f->subtype,
							    f);
	    simple_reference_name(mor) = sn;
	    pVAUL_NamedAssocElem na = mVAUL_NamedAssocElem (assoc->pos,
						  NULL,
						  arg->formal,
						  mor);
	    pVAUL_AmbgCall ac = mVAUL_AmbgCall (assoc->pos, NULL, na);
	    ac->set = assoc->ifts_decls;
	    // XXX - should this be based on the actual type?
	    fcost = constrain(ac, NULL, IR_TYPE);
	    if(fcost >= 0) {
		conversion = assoc->ifts_decls->single_decl(false);
		assert(conversion && conversion->is(IR_FUNCTION_DECLARATION));
	    }
	} else if(tree_is(kind, IR_TYPE_DECLARATION)) {
	  conversion = assoc->ifts_decls->single_decl(false);
	  assert(conversion && conversion->is(IR_TYPE_DECLARATION));
	  fcost = 0;
	} else
	    assert(false);

	info("+++ - %n converted by %n (cost %d)", f, conversion, fcost);

	if(formal_cost)
	    *formal_cost = fcost;
	if(converted_formal)
	    *converted_formal = f;
	return conversion;
    }

    return NULL;
}

static pIIR_Type
get_partial_formal_type (pVAUL_Name name, pIIR_InterfaceDeclaration formal,
			 pVAUL_SubarrayType subarray_storage = NULL)
{
  if (name->is(VAUL_SIMPLE_NAME))
    return formal->subtype;
  else if (name->is(VAUL_SEL_NAME)) 
    {
      pIIR_Type ptype =
	get_partial_formal_type (pVAUL_SelName(name)->prefix, formal);
      if (!ptype || !ptype->is(IR_RECORD_TYPE))
	return NULL;

      for (pIIR_ElementDeclarationList elts =
	     pIIR_RecordType(ptype)->element_declarations;
	   elts; elts = elts->rest)
	{
	  pIIR_ElementDeclaration re = elts->first;
	  if (vaul_name_eq (re->declarator, pVAUL_SelName(name)->suffix))
	    return re->subtype;
	}
      return NULL;
    }
  else if (name->is(VAUL_IFTS_NAME)) 
    {
      pIIR_Type ptype =
	get_partial_formal_type (pVAUL_IftsName(name)->prefix, formal);
      if (!ptype)
	return NULL;

      ptype = ptype->base;
      if (!ptype->is(IR_ARRAY_TYPE))
	return NULL;

      pVAUL_GenAssocElem arg = pVAUL_IftsName(name)->assoc;
      if (arg == NULL)
	return NULL;
      if (arg->is(VAUL_NAMED_ASSOC_ELEM)) 
	{
	  pIIR_ArrayType at = pIIR_ArrayType(ptype);
	  pIIR_TypeList it = at->index_types;
	  while (it && arg) 
	    {
	      assert (arg->is(VAUL_NAMED_ASSOC_ELEM));
	      arg = arg->next;
	      it = it->rest;
	    }
	  if (arg)
	    return NULL;
	  if (it)
	    {
	      if (subarray_storage)
		{
		  subarray_storage->pos = at->pos;
		  subarray_storage->static_level = at->static_level;
		  subarray_storage->declaration = NULL;
		  subarray_storage->index_types = it;
		  subarray_storage->element_type = at->element_type;
		  subarray_storage->complete_type = at;
		  return subarray_storage;
		}
	      else
		return NULL;
	    }
	  else
	    ptype = pIIR_ArrayType(ptype)->element_type;
	}
      else
	{
	  // slices must be one-dimensional, this has already been checked
	  assert (arg->next == NULL);
	}
      return ptype;
    }
  else
    assert (false);
}

int
psr::try_association (pVAUL_NamedAssocElem actuals, pIIR_InterfaceList formals)
{
  int cost = 0;
  pIIR_InterfaceList formal;
  pVAUL_NamedAssocElem a;
  my_dynarray<pIIR_InterfaceDeclaration> associated_formals;

  // quick check to avoid unecessary recursion for the most common cases

  int n_formals = 0, n_opt_formals = 0;
  for (pIIR_InterfaceList f = formals; f; f = f->rest) 
    {
      n_formals++;
      if (f->first->initial_value)
	n_opt_formals++;
    }

  int n_actuals = 0;
  bool valid = true;
  for (pVAUL_NamedAssocElem ae = actuals; ae; ae = pVAUL_NamedAssocElem(ae->next)) 
    {
      assert (ae->is(VAUL_NAMED_ASSOC_ELEM));
      if (ae->formal && !ae->formal->is(VAUL_SIMPLE_NAME))
	{
	  valid = false;
	  break;
	}
      n_actuals++;
      if (n_actuals > n_formals)
	break;
    }

  if (valid && (n_actuals > n_formals
		|| n_actuals < n_formals - n_opt_formals))
    {
      // info("+++ - shortcut");
      return -1;
    }

  // first, the unnamed ones

  formal = formals;
  a = actuals;
  while (formal && a && a->formal == NULL) 
    {
      assert(a->is(VAUL_NAMED_ASSOC_ELEM));

      int c = try_one_association (a, formal->first);
      if (c < 0)
	return c;
      cost += c;
      associated_formals.add (formal->first);
      a = pVAUL_NamedAssocElem(a->next);
      formal = formal->rest;
    }

  if (formal == NULL && a != NULL)
    return -1;

  // and now the named ones

  while (a)
    {
      assert (a->is(VAUL_NAMED_ASSOC_ELEM));
      if (a->formal == NULL)
	break;

      info ("+++ - on %n", a->formal);

      // There are several cases here for the formal:
      //
      // interface_name
      // function(interface_name)
      // type(interface_name)
      //
      // interface_name.record_item
      // interface_name(array_index, ...)
      //   and combinations
      //
      // we try all cases and if more than one is valid, it's an error

      int formal_cost = -1;
      pIIR_InterfaceDeclaration converted_formal = NULL;

      pIIR_Declaration conv = grab_formal_conversion (a, formals,
						      &formal_cost,
						      &converted_formal);
      if (conv) 
	{
	  pIIR_Type actual_type;
	  if (conv->is(IR_FUNCTION_DECLARATION))
	    actual_type = pIIR_FunctionDeclaration(conv)->return_type;
	  else if (conv->is(IR_TYPE_DECLARATION))
	    actual_type = pIIR_TypeDeclaration(conv)->type;
	  else
	    assert (false);
	  formal_cost += constrain (a->actual, actual_type, IR_INVALID);
	  associated_formals.add (converted_formal);
	}

      pVAUL_SimpleName sn = get_simple_name (a->formal);
      assert (sn);
      if (pIIR_InterfaceDeclaration f =
	  find_interface_by_id (formals, sn->id))
	{
	  if (converted_formal)
	    {
#if 0
	      error("%:%n is ambigous as a formal name",
		    a->formal, a->formal);
	      info("%: it could apply to both %n and %n",
		   a->formal, converted_formal, f);
#endif
	      return -1;
	    }
	  
	  assert (formal_cost < 0);

	  pVAUL_SubarrayType sat = mVAUL_SubarrayType ((IIR_PosInfo *)NULL,
						       NULL,
						       NULL,
						       NULL);
	  pIIR_Type atype = get_partial_formal_type (a->formal, f, sat);
	  if (atype)
	    {
	      info("+++ - type of %n is %n", a->formal, atype);
	      formal_cost = constrain (a->actual, atype, IR_INVALID);
	      associated_formals.add (f);
	    }
	  else
	    return -1;
	}

      if (formal_cost < 0)
	return formal_cost;
      cost += formal_cost;
      a = pVAUL_NamedAssocElem (a->next);
    }

  for (pIIR_InterfaceList f = formals; f; f = f->rest) 
    {
      if (!f->first->initial_value && !associated_formals.contains(f->first))
	return -1;
    }

  return cost;
}

int 
psr::try_array_subscription (pIIR_ArrayType at, pVAUL_GenAssocElem a)
{
  int cost = 0;
  for (pIIR_TypeList it = at->index_types; it; it = it->rest)
    {
      if (a == NULL || !a->is(VAUL_NAMED_ASSOC_ELEM) ||
	  pVAUL_NamedAssocElem(a)->formal)
	return -1;
      int c = constrain (pVAUL_NamedAssocElem(a)->actual, it->first,
			 IR_INVALID);
      if (c < 0)
	return -1;
      cost += c;
      a = a->next;
    }
  if (a)
    return -1;
  return cost;
}

static const char *
mode_name (IR_Mode m)
{
  switch (m)
    {
    case IR_UNKNOWN_MODE:
      return "<unknown>";
    case IR_IN_MODE:
      return "in";
    case IR_OUT_MODE:
      return "out";
    case IR_INOUT_MODE:
      return "inout";
    case IR_BUFFER_MODE:
      return "buffer";
    case IR_LINKAGE_MODE:
      return "linkage";
    }
  return NULL;
}

// Check whether the expression E can be read.

void
psr::check_for_read (pIIR_Expression e)
{

  // All objects except those of mode out can be read.  References to
  // objects with unknown declarations (such as the return value of a
  // function call) are OK, too.
  //
  if (e->is(IR_OBJECT_REFERENCE))
    {
      pIIR_ObjectDeclaration obj = vaul_get_object_declaration (e);
      IR_Mode m = vaul_get_mode (e);
      if (obj && m == IR_OUT_MODE)
	error ("%:%n (of mode out) can not be read", e, obj);
    }

  // The attributes 'STABLE, 'QUIET, 'DELAYED and 'TRANSACTION of a
  // signal that is a interface object of mode inout, or out can not
  // be read.  For mode in, they can not be read when the interface
  // object is a subprogram parameter.  Else they can be read.
  //
  else if (e->is(IR_ATTR_STABLE)
	   || e->is(IR_ATTR_QUIET)
	   || e->is(IR_ATTR_DELAYED)
	   || e->is(IR_ATTR_TRANSACTION))
    {
      pIIR_ObjectDeclaration obj =
	vaul_get_object_declaration (pIIR_SignalAttr(e)->signal);
      IR_Mode m = vaul_get_mode (obj);

      if (obj == NULL || !obj->is(IR_INTERFACE_DECLARATION))
	return;

      if (m == IR_IN_MODE)
	{
	  if (obj->declarative_region->is(IR_SUBPROGRAM_DECLARATION))
	    error ("%:%n can not be accessed since %n is a subprogram"
		   " parameter of mode `in'", e, e, obj);
	}
      else if (m == IR_INOUT_MODE || m == IR_OUT_MODE)
	{
	  error ("%:%n can not be accessed since %n has mode `%s'",
		 e, e, obj, mode_name (m));
	}
    }

  // The attributes 'EVENT, 'ACTIVE, 'LAST_EVENT, 'LAST_ACTIVE, and
  // 'LAST_VALUE of a interface object of mode out can not be read.

  else if (e->is(IR_ATTR_EVENT)
	   || e->is(IR_ATTR_ACTIVE)
	   || e->is(IR_ATTR_LAST_EVENT)
	   || e->is(IR_ATTR_LAST_ACTIVE)
	   || e->is(IR_ATTR_LAST_VALUE))
    {
      pIIR_ObjectDeclaration obj =
	vaul_get_object_declaration (pIIR_SignalAttr(e)->signal);
      IR_Mode m = vaul_get_mode (obj);

      if (obj == NULL || !obj->is(IR_INTERFACE_DECLARATION))
	return;

      if (m == IR_OUT_MODE)
	{
	  error ("%:%n can not be accessed since %n has mode `out'",
		 e, e, obj);
	}
	
    }

  // For aggregates, check all elements.

  else if (e->is(IR_RECORD_AGGREGATE))
    {
      for (pIIR_ElementAssociationList eal =
	     pIIR_RecordAggregate(e)->element_association_list;
	   eal; eal = eal->rest)
	check_for_read (eal->first->value);
    }
  else if (e->is(IR_ARRAY_AGGREGATE))
    {
      for (pIIR_IndexedAssociationList ial =
	     pIIR_ArrayAggregate(e)->indexed_association_list;
	   ial; ial = ial->rest)
	check_for_read (ial->first->value);
    }

  // Everything else can be read.
}

// Check whether the expression E can be updated.

void
psr::check_for_update (pIIR_Expression e)
{
  if (e->is(IR_OBJECT_REFERENCE))
    {
      pIIR_ObjectDeclaration obj = vaul_get_object_declaration (e);
      IR_Mode m = vaul_get_mode (e);
      if (obj && m == IR_IN_MODE)
	error ("%:%n (of mode in) can not be updated", e, obj);
    }

  // For aggregates, check all elements.

  else if (e->is(IR_RECORD_AGGREGATE))
    {
      for (pIIR_ElementAssociationList eal =
	     pIIR_RecordAggregate(e)->element_association_list;
	   eal; eal = eal->rest)
	check_for_update (eal->first->value);
    }
  else if (e->is(IR_ARRAY_AGGREGATE))
    {
      for (pIIR_IndexedAssociationList ial =
	     pIIR_ArrayAggregate(e)->indexed_association_list;
	   ial; ial = ial->rest)
	check_for_update (ial->first->value);
    }

  // "open" associations can be updated
  //
  else if (e->is(IR_OPEN_EXPRESSION))
    {
      return;
    }

  else
    error ("%:%n can not be updated", e, e);
}

bool
psr::associate_one (pIIR_AssociationList &tail,
		    pIIR_ObjectReference f,
		    pIIR_Declaration fconv,
		    pIIR_Expression a,
		    pIIR_Declaration aconv,
		    bool need_overload_resolution)
{
  if (f == NULL || a == NULL)
    return false;
  
  if (a->is(VAUL_UNRESOLVED_NAME))
    {
      pVAUL_UnresolvedName un = pVAUL_UnresolvedName(a);
      pIIR_Declaration d = find_single_decl(un->name, IR_DECLARATION, "");
      if(d)
	error("%:%n can not be used in an expression", un->name, d);
      return false;
    }

#if 0
  for (pIIR_AssociationList asl = tail; asl; asl = asl->rest)
    if (asl->first && asl->first->formal == f)
      {
	error ("%:multiple actuals for formal %n", a, f);
	return false;
      }
#endif

  pIIR_Type actual_type;
  if (fconv)
    {
      if (fconv->is(IR_FUNCTION_DECLARATION))
	actual_type = pIIR_FunctionDeclaration(fconv)->return_type;
      else if (fconv->is(IR_TYPE_DECLARATION))
	actual_type = pIIR_TypeDeclaration(fconv)->type;
      else
	assert (false);
    }
  else
    actual_type = f->subtype;

  if (need_overload_resolution)
    overload_resolution_not_for_read (a, actual_type);
  else
    {
      /* disambiguation is good enough because this expression tree
	 has already been subject to overload resolution. */
      a = disambiguate_expr (a, actual_type, false);
    }

  if (a == NULL)
    return false;

  if (aconv)
    info ("%: +++ - actual of %n converted by %n", a, f, aconv);

  pIIR_InterfaceDeclaration fi =
    pIIR_InterfaceDeclaration (vaul_get_object_declaration (f));
  if (fi && (fi->mode == IR_IN_MODE || fi->mode == IR_INOUT_MODE
	     || fi->mode == IR_LINKAGE_MODE))
    check_for_read (a);
  if (fi && (fi->mode == IR_OUT_MODE || fi->mode == IR_INOUT_MODE
	     || fi->mode == IR_BUFFER_MODE || fi->mode == IR_LINKAGE_MODE))
    check_for_update (a);

  pIIR_AssociationElement assoc;
  if (a->is(IR_OPEN_EXPRESSION))
    assoc = mIIR_AssociationElementOpen (a->pos, f, fi, fconv, a, aconv);
  else
    assoc = mIIR_AssociationElementByExpression (a->pos, f, fi, fconv, a, aconv);

  tail = mIIR_AssociationList (assoc->pos, assoc, tail);
  return true;
}

pIIR_Expression
psr::add_partial_choice (pIIR_Expression &pactual,
			 pVAUL_Name formal,
			 pIIR_Expression actual)
{
  pIIR_PosInfo pos = formal->pos;
  pIIR_Expression *ep = NULL;

  if (formal->is(VAUL_SIMPLE_NAME))
    ep = &pactual;

  else if(formal->is(VAUL_SEL_NAME)) 
    {
      pIIR_Expression px = add_partial_choice (pactual, 
					       pVAUL_SelName(formal)->prefix,
					       NULL);
      if (px == NULL)
	return NULL;
      assert (px->is(VAUL_ARTIFICIAL_AMBG_AGGREGATE));
      pVAUL_AmbgAggregate aggr = pVAUL_AmbgAggregate(px);
      pIIR_TextLiteral sfx = pVAUL_SelName(formal)->suffix;
      pVAUL_ElemAssoc ea;
      for (ea = aggr->first_assoc; ea; ea = ea->next) 
	{
	  if (ea->choices && ea->choices->rest == NULL 
	      && ea->choices && ea->choices->first->is(VAUL_CHOICE_BY_NAME)) 
	    {
	      pVAUL_ChoiceByName nc = pVAUL_ChoiceByName (ea->choices->first);
	      if (nc->name && nc->name->is(VAUL_SIMPLE_NAME)
		  && vaul_name_eq(pVAUL_SimpleName(nc->name)->id, sfx))
		break;
	    }
	}
      if (ea == NULL) 
	{
	  pIIR_Choice c = mVAUL_ChoiceByName (pos, mVAUL_SimpleName(pos, sfx));
	  ea = mVAUL_ElemAssoc (pos, aggr->first_assoc,
			   mIIR_ChoiceList (pos, c, NULL), NULL);
	  aggr->first_assoc = ea;
	}
      ep = &ea->actual;
	
    }

  else if (formal->is(VAUL_IFTS_NAME)) 
    {
      pVAUL_GenAssocElem arg = pVAUL_IftsName(formal)->assoc;
      if (arg == NULL)
	return NULL;

      pIIR_Expression px = add_partial_choice (pactual,
					       pVAUL_IftsName(formal)->prefix,
					       NULL);
      if (px == NULL)
	return NULL;
      assert (px->is(VAUL_ARTIFICIAL_AMBG_AGGREGATE));
      pVAUL_AmbgAggregate aggr = pVAUL_AmbgAggregate(px);

      while (arg) 
	{
	  pIIR_Choice c;
	  if (arg->is(VAUL_NAMED_ASSOC_ELEM))
	    c = mIIR_ChoiceByExpression (pos, pVAUL_NamedAssocElem(arg)->actual);
	  else
	    {
	      c = mIIR_ChoiceByRange (pos, range_from_assoc (arg));
	      actual_is_slice(pIIR_ChoiceByRange(c)) = true;
	    }
	  pVAUL_ElemAssoc ea = mVAUL_ElemAssoc (pos, aggr->first_assoc,
				      mIIR_ChoiceList (pos, c, NULL),
				      NULL);
	  aggr->first_assoc = ea;
	  ep = &ea->actual;

	  arg = arg->next;
	  if(arg) 
	    {
	      aggr = mVAUL_ArtificialAmbgAggregate(pos, NULL, NULL);
	      *ep = aggr;
	    }
	}

    } 
  else
    assert(false);

  if (*ep)
    {
      if (actual || !(*ep)->is(VAUL_ARTIFICIAL_AMBG_AGGREGATE)) 
	{
	  error ("%:multiple actuals for %n", formal, formal);
	  return NULL;
	}
    }
  else
    *ep = actual? actual : mVAUL_ArtificialAmbgAggregate (pos, NULL, NULL);

  return *ep;
}

pIIR_AssociationList
psr::associate (pVAUL_NamedAssocElem actuals,
		pIIR_InterfaceList formals,
		bool complete,
		bool need_overload_resolution)
{
  pIIR_AssociationList tail = NULL;
  pVAUL_NamedAssocElem a;
  pIIR_InterfaceList formal;

  formal = formals;
  a = actuals;
  while (formal && a && a->formal == NULL) 
    {
      assert (a->is(VAUL_NAMED_ASSOC_ELEM));
      
      pIIR_InterfaceDeclaration f = formal->first;
      pIIR_Expression f_exp = mIIR_SimpleReference (a->pos,
						    f->subtype,
						    f);
      overload_resolution_not_for_read (f_exp, pIIR_Type(NULL));

      if (a->actual 
	  && !associate_one (tail,
			     pIIR_ObjectReference (f_exp), NULL,
			     a->actual, NULL,
			     need_overload_resolution))
	return NULL;
      a = pVAUL_NamedAssocElem (a->next);
      formal = formal->rest;
    }
  
  if (formal == NULL && a != NULL) 
    {
      error("%:too many actuals", a);
      return NULL;
    }
  
  while (a)
    {
      assert (a->is(VAUL_NAMED_ASSOC_ELEM) && a->formal);

      if (a->actual == NULL)
	{
	  a = pVAUL_NamedAssocElem(a->next);
	  continue;
	}

      pIIR_InterfaceDeclaration f;
      pIIR_Declaration fconv = grab_formal_conversion (a, formals, NULL, &f);
      pIIR_Expression f_exp;
      if (fconv)
	f_exp = mIIR_SimpleReference (a->pos, f->subtype, f);
      else
	{
	  pVAUL_SimpleName sn = get_simple_name (a->formal);
	  f = find_interface_by_id (formals, sn->id);
	  if (f == NULL)
	    {
	      error ("%:no formal with name %n", sn, sn);
	      f_exp = NULL;
	    }
	  else
	    f_exp = build_formal_Expr (f, a->formal);
	}
      overload_resolution_not_for_read (f_exp, pIIR_Type(NULL));

      if (f_exp == NULL
	  || !associate_one(tail,
			    pIIR_ObjectReference (f_exp), fconv,
			    a->actual, NULL,
			    need_overload_resolution))
	return NULL;
      
      a = pVAUL_NamedAssocElem(a->next);
    }
  
#if 0
  if (complete) 
    {
      bool success = true;
      for (pIIR_InterfaceList f = formals; f; f = f->rest) 
	{
	  if (f->first->initial_value)
	    continue;
	  pIIR_AssociationList asl;
	  for (asl = tail; asl; asl = asl->rest)
	    if(asl->first && asl->first->formal == f->first)
	      break;
	  if (asl == NULL) 
	    {
	      error ("%:formal %n has not been associated",
		     actuals, f->first);
	      success = false;
	    }
	}
      if (!success)
	return NULL;
    }
#endif

  return reverse (tail);
}

pIIR_AssociationList
psr::associate_ports (pVAUL_NamedAssocElem actuals,
		      pIIR_InterfaceList formals)
{
  pIIR_AssociationList map = associate (actuals, formals, false);
  
  for (pIIR_AssociationList al = map; al; al = al->rest)
    {
      pIIR_AssociationElement a = al->first;
      pIIR_SignalInterfaceDeclaration p =
	pIIR_SignalInterfaceDeclaration (a->formal_declaration);  // fixed: ... (a->formal)

      if (a->actual->is (IR_OBJECT_REFERENCE))
	{
	  pIIR_ObjectDeclaration obj = vaul_get_object_declaration (a->actual);
	  if (obj)
	    {
	      IR_Mode peer_mode = vaul_get_mode (obj);
	      const char *allowed = NULL;
	      switch (p->mode)
		{
		case IR_IN_MODE:
		  if (peer_mode != IR_IN_MODE
		      && peer_mode != IR_INOUT_MODE
		      && peer_mode != IR_BUFFER_MODE)
		    allowed = "in, inout or buffer";
		  break;
		case IR_OUT_MODE:
		  if (peer_mode != IR_OUT_MODE
		      && peer_mode != IR_INOUT_MODE
		      && peer_mode != IR_BUFFER_MODE)
		    allowed = "out, inout or buffer";
		  break;
		case IR_INOUT_MODE:
		  if (peer_mode != IR_INOUT_MODE
		      && peer_mode != IR_BUFFER_MODE)
		    allowed = "inout or buffer";
		  break;
		case IR_BUFFER_MODE:
		  if (peer_mode != IR_OUT_MODE
		      && peer_mode != IR_INOUT_MODE
		      && peer_mode != IR_BUFFER_MODE)
		    allowed = "out, inout or buffer";
		  break;
		}
	      if (allowed)
		error ("%:port %n of mode %s can only be connected "
		       "to ports of mode %s.",
		       a, p, mode_name (p->mode), allowed);
	    }
	}
    }

  return map;
}

struct psr::filter_return_closure {
  vaul_parser *self;
  pIIR_Type t;
  IR_Kind k;
  pVAUL_NamedAssocElem a;
};

int
psr::filter_return_stub (pIIR_Declaration d, void *cl)
{
  filter_return_closure *rc = (filter_return_closure *)cl;
  return rc->self->filter_return (d, rc);
}

pIIR_Type
psr::expr_type (pIIR_Expression e)
{
  if (e == NULL)
    return NULL;
  
  if (e->subtype == NULL && !e->is(IR_OPEN_EXPRESSION) && options.debug)
    info("%:XXX - %n (%s) has no type", e, e, e->kind_name());

  return e->subtype;
}


static void
get_ambg_types (pIIR_Declaration d, void *cl)
{
  pIIR_Type_vector *vc = (pIIR_Type_vector *)cl;
  if (d->is(IR_FUNCTION_DECLARATION)
      && pIIR_FunctionDeclaration(d)->return_type)
    vc->add_uniq (pIIR_FunctionDeclaration(d)->return_type);
  else if (d->is(IR_ENUMERATION_LITERAL)
	   && pIIR_EnumerationLiteral(d)->subtype)
    vc->add_uniq (pIIR_EnumerationLiteral(d)->subtype);
#if 0
  else
    fprintf (stderr,  "XXX - %n (%s) has no ambg_type\n", d, d->type_id());
#endif
}

struct psr::cat_closure {
    vaul_parser *self;
    pIIR_Type_vector *types;
    pIIR_Expression expr;
};

static bool
is_interesting_array_type (pIIR_Type t)
{
  return 
    t->is(IR_ARRAY_TYPE) && pIIR_ArrayType(t)->declaration != NULL
    || (t->is(IR_ARRAY_SUBTYPE)
	&& (pIIR_ArraySubtype(t)->immediate_base->declaration ==
	    t->declaration));
}

void
psr::collect_ambg_types_stub (pIIR_Declaration d, void *_cl)
{
  cat_closure *cl = (cat_closure *)_cl;
  cl->self->collect_ambg_types (d, cl);
}

void
psr::collect_ambg_types (pIIR_Declaration d, cat_closure *cl)
{
  if (!d->is(IR_TYPE_DECLARATION))
    return;

  pIIR_Type t = pIIR_TypeDeclaration(d)->type;

  if (cl->expr->is(VAUL_AMBG_ARRAY_LIT_REF))
    {
      pVAUL_AmbgArrayLitRef alit = pVAUL_AmbgArrayLitRef(cl->expr);

      if (is_interesting_array_type (t)
	  && array_literal_conversion_cost (alit, t, IR_INVALID) >= 0)
	cl->types->add_uniq (t);
    }
  else if (cl->expr->is(VAUL_AMBG_AGGREGATE)) 
    {
      pVAUL_AmbgAggregate aggr = pVAUL_AmbgAggregate(cl->expr);

      if ((is_interesting_array_type (t) || t->is(IR_RECORD_TYPE))
	  && aggregate_conversion_cost (aggr, t, IR_INVALID) >= 0)
	cl->types->add_uniq (t);
    }
  else if(cl->expr->is(VAUL_AMBG_NULL_EXPR)) 
    {
      if (t->is(IR_ACCESS_TYPE))
	cl->types->add_uniq (t);
    }
  else
    assert (false);
}

pIIR_Type_vector *psr::ambg_expr_types(pIIR_Expression e)
{
    pIIR_Type_vector *types = new pIIR_Type_vector;

    if (e == NULL)
      return types;

    if(e->is(VAUL_AMBG_CALL) || e->is(VAUL_AMBG_ENUM_LIT_REF)) {
	vaul_decl_set *d = e->is(VAUL_AMBG_CALL)? pVAUL_AmbgCall(e)->set :
	                                      pVAUL_AmbgEnumLitRef(e)->set;
	d->refresh();
	d->iterate(get_ambg_types, types);
    } else if(e->is(VAUL_AMBG_ARRAY_LIT_REF) || e->is(VAUL_AMBG_AGGREGATE)
	      || e->is(VAUL_AMBG_NULL_EXPR)) {
	// brute force, what else?
	cat_closure cl = { this, types, e };
	visit_decls (collect_ambg_types_stub, &cl);
	// info("+++ - collected %d types", types->size());
    } else if(e->is(VAUL_UNRESOLVED_NAME)) {
      // just for the error message
      overload_resolution(e, IR_TYPE);
    } else if(pIIR_Type t = expr_type(e))
	types->add(t);
    
    if (types->size() == 0 && e)
      error ("%:%n not valid here", e, e);

    return types;
}

int
psr::conversion_cost (pIIR target, pIIR_Type should_t, IR_Kind should_k)
{
  if (target == NULL)
    return 0;

  if (should_t) 
    {
      should_t = vaul_get_base (should_t);
      should_k = should_t->kind();
    }

  bool impl_conv = false;
  pIIR_Type is_t = NULL;
  
  IR_Kind target_k = target->kind ();  // Optimization
#define TARGET_IS(k) (tree_is ((target_k), (k)))

  if (TARGET_IS(IR_FUNCTION_DECLARATION))
    {
      pIIR_FunctionDeclaration f = pIIR_FunctionDeclaration(target);
      is_t = f->return_type;
      pIIR_InterfaceList parm1 = f->interface_declarations;
      pIIR_InterfaceList parm2 = parm1? parm1->rest : NULL;
      if (f->is(IR_PREDEFINED_FUNCTION_DECLARATION)
	  && vaul_name_eq("\"/\"", f->declarator)
	  && parm1 && parm1->first && parm2->first
	  && parm1->first->subtype->base->is(IR_PHYSICAL_TYPE)
	  && parm2->first->subtype->base->is(IR_PHYSICAL_TYPE))
	impl_conv = true;
    }
  else if (TARGET_IS(IR_ABSTRACT_LITERAL_EXPRESSION))
    {
      is_t = expr_type (pIIR_AbstractLiteralExpression(target));
      if (is_t == std->universal_integer || is_t == std->universal_real)
	impl_conv = true;
    }
  else if (TARGET_IS(VAUL_AMBG_ARRAY_LIT_REF)) 
    {
      return array_literal_conversion_cost (pVAUL_AmbgArrayLitRef(target),
					    should_t, should_k,
					    false);
    }
  else if (TARGET_IS(IR_ATTR_ARRAY_LENGTH)) 
    {
      is_t = pIIR_Attr_ArrayLENGTH(target)->subtype;
      impl_conv = true;
    }
#if 0
  else if (TARGET_IS(IR_ATTR_LENGTH)) 
    {
      is_t = pIIR_Attr_LENGTH(target)->subtype;
      impl_conv = true;
    }
#endif 
  else if (TARGET_IS(IR_ATTR_POS)) 
    {
      is_t = pIIR_Attr_POS(target)->subtype;
      impl_conv = true;
    } 
  else if (TARGET_IS(VAUL_AMBG_NULL_EXPR))
    {
      return tree_is(IR_ACCESS_TYPE, should_k)? 0 : -1;
    }
  else if (TARGET_IS(IR_ALLOCATOR)
	   && should_t && should_t->is(IR_ACCESS_TYPE)) 
    {
      pIIR_Type new_type = pIIR_Allocator(target)->type_mark;
      assert (new_type->is(IR_ACCESS_TYPE));
      return conversion_cost (pIIR_AccessType(new_type)->designated_type,
			      pIIR_AccessType(should_t)->designated_type,
			      IR_INVALID);
    }
  else if (TARGET_IS(IR_EXPRESSION))
    {
      is_t = expr_type(pIIR_Expression(target));
    }
  else 
    {
      assert(TARGET_IS(IR_TYPE));
      is_t = pIIR_Type(target);
    }
	
  if (is_t == NULL)
    return 0;

  is_t = vaul_get_base (is_t);

  // exact match
  if (should_t? is_t == should_t : is_t->is(should_k))
    return 0;

  // implicit conversion from universal types
  if (impl_conv)
    {
      if (should_t)
	should_k = should_t->kind();
      if ((is_t == std->universal_integer
	   && tree_is(should_k, IR_INTEGER_TYPE))
	  || (is_t == std->universal_real
	      && tree_is(should_k, IR_FLOATING_TYPE)))
	return 1;
    }

  // no match
  return -1;
}

int
psr::array_literal_conversion_cost (pVAUL_AmbgArrayLitRef l,
				    pIIR_Type t,
				    IR_Kind k,
				    bool look_inside)
{
  if (t == 0)
    return (tree_is(IR_ARRAY_TYPE, k) || tree_is(k, IR_ARRAY_TYPE)) ? 0 : -1;
  
  t = t->base;

  if (!t->is(IR_ARRAY_TYPE))
    return -1;

  pIIR_ArrayType at = pIIR_ArrayType(t);
  if (at->index_types && at->index_types->rest)
    return -1;
  pIIR_Type et = at->element_type;
  if (et == NULL)
    return -1;
  et = et->base;
  if (!et->is(IR_ENUMERATION_TYPE))
    return -1;
  if (et == std->predef_CHARACTER)
    return 0;

  if (!look_inside)
    {
      pIIR_EnumerationLiteralList el;
      for (el = pIIR_EnumerationType(et)->enumeration_literals;
	   el; el = el->rest)
	{
	  if (el->first->declarator
	      && el->first->declarator->is(IR_CHARACTER_LITERAL))
	    return 0;
	}
      return -1;
    }

    {
      IR_String &val = l->value->text;
      for (int i = 1; i < val.len()-1; i++)
	{
	  pIIR_EnumerationLiteralList el;
	  for (el = pIIR_EnumerationType(et)->enumeration_literals;
	       el; el = el->rest)
	    {
	      if (el->first->declarator
		  && el->first->declarator->is(IR_CHARACTER_LITERAL)
		  && el->first->declarator->text[1] == val[i])
		break;
	    }
	  if (el == NULL)
	    return -1;
	}
      return 0;
    }
}

static pVAUL_SimpleName
choice_simple_name (pIIR_Choice c)
{
  pVAUL_Name n = NULL;
  if (c->is(VAUL_CHOICE_BY_NAME))
    n = pVAUL_ChoiceByName(c)->name;
  else if (c->is(IR_CHOICE_BY_EXPRESSION))
    {
      if(pIIR_Expression e = pIIR_ChoiceByExpression(c)->value)
	{
	  if (e->is(VAUL_UNRESOLVED_NAME))
	    n = pVAUL_UnresolvedName(e)->name;
	  else if (e->is(IR_SIMPLE_REFERENCE))
	    n = simple_reference_name(pIIR_SimpleReference(e));
	  else
	    return NULL;
	}
    }
  if (n == NULL || !n->is(VAUL_SIMPLE_NAME))
    return NULL;
  return pVAUL_SimpleName(n);
}

static pIIR_ElementDeclaration
choice_elem (pIIR_RecordType t, pIIR_Choice c)
{
  pVAUL_SimpleName n = choice_simple_name (c);
  if (n == NULL)
    return NULL;
  for (pIIR_ElementDeclarationList elts = t->element_declarations;
       elts; elts = elts->rest)
    {
      pIIR_ElementDeclaration re = elts->first;
      if (vaul_name_eq (re->declarator, n->id))
	return re;
    }
  return NULL;
}

int
psr::choice_conversion_cost (pIIR_Choice c, pIIR_Expression actual,
			     pIIR_Type t, IR_Kind k)
{
  if (tree_is (k, IR_ARRAY_TYPE))
    {
      int c1 = 0, c2 = 0;
      pIIR_ArrayType at = NULL;
      if (t)
	{
	  assert (t->is(IR_ARRAY_TYPE));
	  pIIR_ArrayType at = pIIR_ArrayType(t);
	  c1 = constrain (actual, at->element_type, IR_INVALID);
	  if (c1 < 0)
	    return c1;
	}
      if (c != NULL) 
	{
	  if (!c->is(IR_CHOICE_BY_EXPRESSION))
	    return -1;
	  pIIR_Expression e = pIIR_ChoiceByExpression(c)->value;
	  if (e == NULL)
	    return c1;
	  if (at)
	    {
	      if (at->index_types == NULL)
		return -1;
	      c2 = constrain (e, at->index_types->first, IR_INVALID);
	      if (c2 < 0)
		return c2;
	      return c1 + c2;
	    }
	  else
	    return e->is(VAUL_UNRESOLVED_NAME)? -1 : c1;
	}
    }
  else if (tree_is(k, IR_RECORD_TYPE)) 
    {
      pVAUL_SimpleName n = choice_simple_name(c);
      if (n == NULL)
	return -1;
      if (t)
	{
	  assert (t->is(IR_RECORD_TYPE));
	  pIIR_RecordType rt = pIIR_RecordType(t);
	  for (pIIR_ElementDeclarationList elts = rt->element_declarations;
	       elts; elts = elts->rest)
	    {
	      pIIR_ElementDeclaration re = elts->first;
	      if (vaul_name_eq(re->declarator, n->id))
		return constrain(actual, re->subtype, IR_INVALID);
	    }
	  return -1;
	}
      else
	return 0;
    }

  return -1;
}

static int
aggregate_conversion_cost (pVAUL_AmbgAggregate a, pIIR_Type t, IR_Kind k)
{
    if(t) {
	t = vaul_get_base (t);
	k = t->kind();
    }

#if 1
    return tree_is(k, IR_COMPOSITE_TYPE)? 0 : -1;
#else // no need to be this clever.
    int cost = 0;

    for(pVAUL_ElemAssoc ea = a->first_assoc; ea; ea = ea->next)
	for(nChoice c = ea->first_choice; c; c = c->next) {
	    int cc = choice_conversion_cost(c, ea->actual, t, k);
	    if(cc < 0)
		return cc;
	    cost += cc;
	}
    return cost;
#endif
}

pIIR_Aggregate
psr::build_Aggregate (pVAUL_AmbgAggregate aggr, pIIR_Type t)
{
  if (aggr == NULL || t == NULL)
    return NULL;

  pIIR_Type bt = vaul_get_base (t);

  if (bt->is(IR_RECORD_TYPE))
    {
      pIIR_RecordType rt = pIIR_RecordType(bt);
      pIIR_RecordAggregate ra;
      if (aggr->is (VAUL_ARTIFICIAL_AMBG_AGGREGATE))
	ra = mIIR_ArtificialRecordAggregate (aggr->pos, rt, NULL);
      else
	ra = mIIR_RecordAggregate (aggr->pos, rt, NULL);
      pIIR_ElementAssociationList *al_tail = &ra->element_association_list;
	
      // associations without choice
      //
      pVAUL_ElemAssoc ea = aggr->first_assoc;
      pIIR_ElementDeclarationList elts = rt->element_declarations;
      while (ea && ea->choices == NULL && elts)
	{
	  pIIR_ElementDeclaration re = elts->first;
	  pIIR_ElementAssociation ela =
	    mIIR_ElementAssociation (ea->pos, re, ea->actual);
	  *al_tail = mIIR_ElementAssociationList (ea->pos, ela, NULL);
	  overload_resolution (ela->value, re->subtype);
	  al_tail = &(*al_tail)->rest;
	  elts = elts->rest;
	  ea = ea->next;
	}

      if (elts == NULL && ea != NULL) 
	{
	  error("%:too many elements in record aggregate of type %n",
		ea, rt);
	  return ra;
	}

      // associations with choices
      //
      while (ea && ea->choices)
	{
	  // find all choosen elements
	  pIIR_DeclarationList elts = NULL;
	  for (pIIR_ChoiceList cl = ea->choices; cl; cl = cl->rest) 
	    {
	      pIIR_Choice c = cl->first;
	      if (c->is(IR_CHOICE_BY_OTHERS))
		{
		  for (pIIR_ElementDeclarationList elts2 =
			 rt->element_declarations;
		       elts2; elts2 = elts2->rest)
		    {
		      pIIR_ElementDeclaration re = elts2->first;
		      bool found = false;
		      for (pIIR_ElementAssociationList al =
			     ra->element_association_list;
			   al; al = al->rest)
			if (al->first->element == re)
			  {
			    found = true;
			    break;
			  }
		      if (!found)
			elts = mIIR_DeclarationList (c->pos, re, elts);
		    }
		}
	      else
		{
		  pIIR_ElementDeclaration re = choice_elem (rt, c);
		  if (re)
		    elts = mIIR_DeclarationList (c->pos, re, elts);
		  else
		    {
		      error ("%:%n has no element named %n, it has:",
			     c, rt, c);
		      for (pIIR_ElementDeclarationList elts2 =
			     rt->element_declarations;
			   elts2; elts2 = elts2->rest)
			{
			  pIIR_ElementDeclaration re = elts2->first;
			  info ("%: %n: %n",
				re, re->declarator, re->subtype);
			}
		    }
		}
	    }
	  
	  // find the type of all choosen elements
	  pIIR_Type elem_type = NULL;
	  for (pIIR_DeclarationList elt = elts; elt; elt = elt->rest) 
	    {
	      pIIR_ElementDeclaration re = pIIR_ElementDeclaration(elt->first);
	      for (pIIR_ElementAssociationList al =
		     ra->element_association_list;
		   al; al = al->rest)
		{
		  pIIR_ElementAssociation a = al->first;
		  if (a->element == re)
		    {
		      error ("%:%n::%n has already been associated",
			     elt, rt, re->declarator);
		      if (!vaul_pos_eq (a->pos, elt->pos))
			info ("%: here", a);
		      continue;
		    }
		}

	      if (elem_type && elem_type != re->subtype)
		error ("%:all elements selected by a choice must be of"
		       " the same type", elt);
	      elem_type = re->subtype;
	    }
	  
	  if (elem_type) 
	    {
	      overload_resolution (ea->actual, elem_type);
	      for (pIIR_DeclarationList elt = elts; elt; elt = elt->rest) 
		{
		  pIIR_ElementDeclaration re =
		    pIIR_ElementDeclaration(elt->first);
		  pIIR_ElementAssociation ela =
		    mIIR_ElementAssociation (elt->pos, re, ea->actual);
		  *al_tail = mIIR_ElementAssociationList (elt->pos, ela, NULL);
		  al_tail = &(*al_tail)->rest;
		}
	    }

	  ea = ea->next;
	}

      if (ea)
	error ("%:associations without choices must precede all the others",
	       ea);

      // check that all elements have been choosen
      //
      for (pIIR_ElementDeclarationList elts2 = rt->element_declarations;
	   elts2; elts2 = elts2->rest)
	{
	  pIIR_ElementDeclaration re = elts2->first;
	  bool found = false;
	  for (pIIR_ElementAssociationList al = ra->element_association_list;
	       al; al = al->rest)
	    if (al->first->element == re)
	      {
		found = true;
		break;
	      }
	  if (!found)
	    error ("%:%n::%n has not been associated", aggr, rt,
		   re->declarator);
	}
	    
      return ra;

    }
  else if (bt->is(IR_ARRAY_TYPE)) 
    {
      pIIR_ArrayType at = pIIR_ArrayType(bt);

      if (at->index_types == NULL)
	return NULL;

      pIIR_ArrayAggregate aa;
      if (aggr->is(VAUL_ARTIFICIAL_AMBG_AGGREGATE))
	aa = mIIR_ArtificialArrayAggregate(aggr->pos, t, NULL);
      else
	aa = mIIR_ArrayAggregate(aggr->pos, t, NULL);
      pIIR_IndexedAssociationList *al_tail = &aa->indexed_association_list;

      pIIR_Type actual_type;
      if (at->index_types->rest == NULL)
	actual_type = at->element_type;
      else 
	{
	  pIIR_ArrayType base = (at->is(VAUL_SUBARRAY_TYPE)?
				 pVAUL_SubarrayType(at)->complete_type : at);
	  actual_type = mVAUL_SubarrayType (at->pos,
					    at->index_types->rest,
					    at->element_type,
					    base);
	}

      pVAUL_ElemAssoc ea = aggr->first_assoc;
      while (ea && ea->choices == NULL)
	{
	  overload_resolution (ea->actual, actual_type);
	  pIIR_SingleIndexedAssociation ia =
	    mIIR_SingleIndexedAssociation(ea->pos, ea->actual, NULL);
	  *al_tail = mIIR_IndexedAssociationList(ea->pos, ia, NULL);
	  al_tail = &(*al_tail)->rest;
	  ea = ea->next;
	}

      while (ea && ea->choices) 
	{
	  pIIR_ChoiceList cl = ea->choices;
	  pIIR_Choice c = cl->first;
	  pIIR_Type atype;
	  if (c->is(IR_CHOICE_BY_RANGE) &&
	      actual_is_slice(pIIR_ChoiceByRange(c)))
	    atype = at;
	  else
	    atype = actual_type;
	  
	  overload_resolution_not_for_read (ea->actual, atype);
	  for (; cl; cl = cl->rest)
	    {
	      pIIR_Choice c = cl->first;
	      pIIR_IndexedAssociation ia = NULL;

	      if (c->is(IR_CHOICE_BY_EXPRESSION))
		{
		  assert (atype == actual_type);
		  pIIR_Expression e = pIIR_ChoiceByExpression(c)->value;
		  overload_resolution (e, at->index_types->first);
		  ia = mIIR_SingleIndexedAssociation(ea->pos, ea->actual, e);
		}
	      else if (c->is(IR_CHOICE_BY_RANGE))
		{
		  assert (atype == (actual_is_slice(pIIR_ChoiceByRange(c))?
				    at : actual_type));
		  pIIR_Range range = pIIR_ChoiceByRange(c)->range;
		  ensure_range_type (range, NULL);
		  if (actual_is_slice(pIIR_ChoiceByRange(c)))
		    ia = mIIR_SliceIndexedAssociation (ea->pos, ea->actual,
						       range);
		  else
		    ia = mIIR_RangeIndexedAssociation (ea->pos, ea->actual,
						       range);
		}
	      else if (c->is(IR_CHOICE_BY_OTHERS))
		ia = mIIR_OthersIndexedAssociation (ea->pos, ea->actual);
	      else
		error ("%:%n invalid as array aggregate choice", c, c);

	      *al_tail = mIIR_IndexedAssociationList(ea->pos, ia, NULL);
	      al_tail = &(*al_tail)->rest;
	    }
	  ea = ea->next;
	}

      if (ea)
	error("%:associations without choices must precede all the others",
	      ea);

      return aa;
      
    }
  else
    error ("%n is not a composite type", t);
  return NULL;
}

static bool
is_array_func (pIIR_FunctionDeclaration f, pVAUL_NamedAssocElem a)
{
    return f->return_type && f->return_type->is(IR_ARRAY_TYPE)
	&& f->interface_declarations == NULL && a != NULL;
}

int
psr::filter_return (pIIR_Declaration d, filter_return_closure *rc)
{
  if (d->is(IR_FUNCTION_DECLARATION)) 
    {
      pIIR_FunctionDeclaration f = pIIR_FunctionDeclaration(d);
      int c1, c2;
      if (is_array_func(f, rc->a)) 
	{
	  c1 = conversion_cost (pIIR_ArrayType(f->return_type)->element_type,
				rc->t, rc->k);
	  if(c1 >= 0)
	    c2 = try_array_subscription (pIIR_ArrayType(f->return_type),
					 rc->a);
	}
      else 
	{
	  c1 = conversion_cost (f, rc->t, rc->k);
	  if (c1 >= 0)
	    c2 = try_association (rc->a, f->interface_declarations);
	}
      if (c1 < 0 || c2 < 0)
	return -1;
      return c1+c2;
    }
  else if (d->is(IR_PROCEDURE_DECLARATION))
    {
      pIIR_ProcedureDeclaration pd = pIIR_ProcedureDeclaration(d);
      if (!tree_is (VAUL_VOID_TYPE, rc->k))
	return -1;
      return try_association (rc->a, pd->interface_declarations);
    }
  else if (d->is(IR_ENUMERATION_LITERAL))
    {
      pIIR_EnumerationLiteral el = pIIR_EnumerationLiteral(d);
      return conversion_cost (el->subtype, rc->t, rc->k);
    }
  else
    return -1;
}

static pVAUL_Name
expr_name (pIIR_Expression e)
{
  if (e->is(VAUL_UNRESOLVED_NAME))
    return pVAUL_UnresolvedName(e)->name;
  else if (e->is(IR_SIMPLE_REFERENCE))
    return simple_reference_name (pIIR_SimpleReference(e));
  else if(e->is(VAUL_AMBG_CALL))
    {
      vaul_decl_set *set = pVAUL_AmbgCall(e)->set;
      return set? set->name : NULL;
    }
  else
    return NULL;
}

bool psr::prepare_named_assocs(pVAUL_GenAssocElem gen)
{
    bool named = false;
    bool success = true;

    for(pVAUL_GenAssocElem a = gen; a; a = a->next) {
	if(a->is(VAUL_NAMED_ASSOC_ELEM)) {
	    pVAUL_NamedAssocElem na = pVAUL_NamedAssocElem(a);

	    if(na->formal)
		named = true;
	    else if(named) {
		error("%:unnamed associations must preced the named ones", na);
		return false;
	    }

	    if(na->formal) {
		pVAUL_Name f = na->formal;

		na->ifts_decls = NULL;
		if(f->is(VAUL_IFTS_NAME)) {
		    pVAUL_IftsName in = pVAUL_IftsName(f);
		    //info("%:+++ - function/type/array element", f);
		    na->ifts_arg_name = NULL;
		    if(in->assoc && in->assoc->next == NULL
		       && in->assoc->is(VAUL_NAMED_ASSOC_ELEM)) {
			pIIR_Expression a = pVAUL_NamedAssocElem(in->assoc)->actual;
			if(a) {
			    pVAUL_Name an = expr_name(a);
			    if(an && an->is(VAUL_SIMPLE_NAME))
				na->ifts_arg_name = pVAUL_SimpleName(an);
			}
		    }

		    if(na->ifts_arg_name) {
			na->ifts_decls = new vaul_decl_set(this);
			find_decls(*(na->ifts_decls), f);

			if(!na->ifts_decls->multi_decls(false)) {
			    //info("      but no matches (which is fine)", f);
			    delete na->ifts_decls;
			    na->ifts_decls = NULL;
			} else {
			    na->ifts_kind = IR_INVALID;
			    na->ifts_decls->iterate(iterate_for_kind,
						    &na->ifts_kind);
			    if (!tree_is (na->ifts_kind,
					  IR_FUNCTION_DECLARATION)
				&& !tree_is (na->ifts_kind, 
					     IR_TYPE_DECLARATION))
			      {
				// info("%:      but not a function/type (%s)",
				//     f, tree_kind_name(na->ifts_kind));
				delete na->ifts_decls;
				na->ifts_decls = NULL;
			      }
			}
		    } else
		      // info("%:      but not exactly one simple argument", f)
		      ;
		}

		if(get_simple_name(f) == NULL) {
		    error("%:%n does not contain an interface name",
			  na->formal, na->formal);
		    success = false;
		}
	    }

	} else {
	    error("%:%n can not be used in an association", a, a);
	    success = false;
	}
    }

    return success;
}

void psr::validate_gen_assocs(pVAUL_GenAssocElem assocs)
{
    for(pVAUL_GenAssocElem a = assocs; a; a = a->next) {
	if(!a->is(VAUL_NAMED_ASSOC_ELEM)) {
	    if(a != assocs || a->next != NULL) {
		error("%:slices must be one-dimensional", a);
		a->next = NULL;
	    }
	}
    }
}

int
psr::pre_constrain (pIIR_Expression e)
{
  max_constrain_depth = 2;
  constrain_depth = 0;
  int res = constrain (e, NULL, IR_TYPE);
  max_constrain_depth = -1;
  return res;
}

int
psr::constrain (pIIR_Expression e, pIIR_Type t, IR_Kind k)
{
  if (max_constrain_depth >= 0) {
    if (constrain_depth >= max_constrain_depth)
      return 0;
    constrain_depth += 1;
  }

  int res = constrain1 (e, t, k);

  if (max_constrain_depth >= 0)
    constrain_depth -= 1;
  return res;
}

int
psr::constrain1 (pIIR_Expression e, pIIR_Type t, IR_Kind k)
{
    if(e == NULL || (t == NULL && k == IR_INVALID))
        return 0;

    if(e->is(VAUL_AMBG_CALL)) {
	vaul_decl_set *s = pVAUL_AmbgCall(e)->set;
	s->refresh();
	filter_return_closure rc = { this, t, k, pVAUL_AmbgCall(e)->first_actual };
	s->filter(filter_return_stub, &rc);
	if(max_constrain_depth >= 0 && constrain_depth == 1) {
	    s->invalidate_pot_invalids();
	    return s->multi_decls(false)? 0 : -1;
	} else
	    return s->retain_lowcost();
    } else if(e->is(VAUL_AMBG_ENUM_LIT_REF)) {
	vaul_decl_set *s = pVAUL_AmbgEnumLitRef(e)->set;
	s->refresh();
	filter_return_closure rc = { this, t, k, NULL };
	s->filter (filter_return_stub, &rc);
	return s->retain_lowcost();
    } else if(e->is(VAUL_AMBG_AGGREGATE))
	return aggregate_conversion_cost(pVAUL_AmbgAggregate(e), t, k);
    else if(e->is(VAUL_UNRESOLVED_NAME))
	return 0;
    else 
	return conversion_cost(e, t, k);
}

bool psr::try_overload_resolution(pIIR_Expression e, pIIR_Type t, IR_Kind k)
{
    return constrain(e, t, k) >= 0;
}

static const char *type_string(IR_Kind k)
{
  if (k == IR_INTEGER_TYPE)
    return "an integer";
  if (k == IR_FLOATING_TYPE)
    return "a floating point";
  if (k == IR_PHYSICAL_TYPE)
    return "a physical";
  if (k == IR_ARRAY_TYPE)
    return "an array";
  if (k == IR_RECORD_TYPE)
    return "a record";
  if (k == IR_COMPOSITE_TYPE)
    return "a composite";
  if (k == IR_ACCESS_TYPE)
    return "an access";
  if (k == IR_TYPE)
    return "a";
  return "an unspeakable";
}

pIIR_Expression
psr::disambiguate_expr (pIIR_Expression e, pIIR_Type t, bool procs)
{
  e = disambiguate_expr1 (e, t, procs);
  if (e)
    e->static_level = vaul_compute_static_level (e);
  return e;
}

pIIR_Expression
psr::disambiguate_expr1 (pIIR_Expression e, pIIR_Type t, bool procs)
{
  if (e->is(VAUL_AMBG_CALL))
    {
      for (pVAUL_NamedAssocElem ne = pVAUL_AmbgCall(e)->first_actual; ne;
	   ne = pVAUL_NamedAssocElem(ne->next)) 
	{
	  assert(ne->is(VAUL_NAMED_ASSOC_ELEM));
	  if (ne->actual == NULL) 
	    {
	      info("%:+++ - found NULL actual in %n", e, e);
	      return NULL;
	    }
	}
	
      pVAUL_AmbgCall(e)->set->invalidate_pot_invalids ();
      pIIR_Declaration d = pVAUL_AmbgCall(e)->set->single_decl ();
      if (d == NULL)
	{
#if 0
	  // give more info about `e'
	  info ("+++ - assocs:");
	  for (pVAUL_GenAssocElem ge = pVAUL_AmbgCall(e)->first_actual; ge;
	       ge = ge->next) 
	    {
	      info ("+++ -  %n", ge);
	      if (ge->is(VAUL_NAMED_ASSOC_ELEM)) 
		{
		  pIIR_Expression e = pVAUL_NamedAssocElem(ge)->actual;
		  pIIR_Type_vector *types = ambg_expr_types(e);
		  for (int i = 0; i < types->size(); i++)
		    if (try_overload_resolution(e, (*types)[i], IR_INVALID))
		      info ("+++ --  %n", (*types)[i]);
		}
	    }
#endif
	}

      if (d && d->is(IR_FUNCTION_DECLARATION)) 
	{
	  pVAUL_AmbgCall ac = pVAUL_AmbgCall (e);
	  if (is_array_func(pIIR_FunctionDeclaration(d), ac->first_actual)) 
	    {
	      pIIR_FunctionDeclaration fd = pIIR_FunctionDeclaration(d);
	      e = mIIR_FunctionCall (ac->pos, fd->return_type, fd, NULL);
	      return build_ArrayReference (e, ac->first_actual);
	    }
	  else
	    {
	      pIIR_FunctionDeclaration fd = pIIR_FunctionDeclaration(d);
	      pIIR_AssociationList al = 
		associate (pVAUL_AmbgCall(e)->first_actual,
			   fd->interface_declarations, true, false);
	      return mIIR_FunctionCall (e->pos, fd->return_type, fd, al);
	    }
	}
      else if (d && d->is(IR_PROCEDURE_DECLARATION)) 
	{
	  if (!procs) 
	    {
	      error ("%:%n is a procedure, not a function", e, d);
	      return NULL;
	    }
	  else
	    {
	      pIIR_ProcedureDeclaration pd = pIIR_ProcedureDeclaration(d);
	      pIIR_AssociationList al = 
		associate (pVAUL_AmbgCall(e)->first_actual,
			   pd->interface_declarations, true, false);
	      return mVAUL_ProcedureCall (e->pos, NULL, pd, al);
	    }
	}

    }
  else if(e->is(VAUL_AMBG_ENUM_LIT_REF)) 
    {
      /* In addition to enum literals, we might also happen upon
	 subprograms without parameters here.
      */

      pVAUL_AmbgEnumLitRef(e)->set->invalidate_pot_invalids();
      pIIR_Declaration d = pVAUL_AmbgEnumLitRef(e)->set->single_decl();
      if(d == 0)
	return NULL;
      if (d->is(IR_ENUMERATION_LITERAL))
	{
	  pIIR_EnumerationLiteral el = pIIR_EnumerationLiteral(d); 
	  return mIIR_EnumLiteralReference(e->pos, el->subtype, el);
	}
      else if (d->is(IR_FUNCTION_DECLARATION))
	{
	  pIIR_FunctionDeclaration fd = pIIR_FunctionDeclaration(d);
	  return mIIR_FunctionCall (e->pos, fd->return_type, fd, NULL);
	}
      else if (d->is(IR_PROCEDURE_DECLARATION))
	{
	  if (!procs) 
	    {
	      error ("%:%n is a procedure, not a function", e, d);
	      return NULL;
	    }
	  return mVAUL_ProcedureCall (e->pos, NULL,
				      pIIR_ProcedureDeclaration(d),
				      NULL);
	}
      else
	abort ();
    }
  else if (e->is(VAUL_AMBG_ARRAY_LIT_REF)) 
    {
      pVAUL_AmbgArrayLitRef l = pVAUL_AmbgArrayLitRef(e);
      if (t == NULL)
	error ("%:can't determine string literal type", l);
      else if (array_literal_conversion_cost (l, t, IR_INVALID) >= 0) 
	return mIIR_ArrayLiteralExpression (l->pos, t, l->value);
      else
	report_type_mismatch (e, t, IR_INVALID);
    }
  else if (e->is(VAUL_AMBG_AGGREGATE)) 
    {
      if (t == NULL)
	error("%:can't determine aggregate type", e);
      else
	return build_Aggregate(pVAUL_AmbgAggregate(e), t);
    }
  else if (e->is(VAUL_AMBG_NULL_EXPR)) 
    {
      if (t == NULL)
	error("%:can't determine null constant type", e);
      else
	return mIIR_NullExpression(e->pos, t);
    }
#if 0 // This is wrong to do in general.
  else if (e->is(IR_ALLOCATOR))
    {
      if (t == NULL)
	error ("%:can't determine type of new object", e);
      else 
	{
	  pIIR_Allocator(e)->type_mark = t;
	  return e;
	}
    }
#endif
  else
    return e;

  return NULL;
}

bool psr::check_for_unresolved_names (pIIR_Expression e)
{
  if (e == NULL)
    return true;

  if(e->is (VAUL_UNRESOLVED_NAME)) 
    {
      pVAUL_UnresolvedName un = pVAUL_UnresolvedName(e);
      pIIR_Declaration d = find_single_decl(un->name, IR_DECLARATION, "");
      if(d)
	error("%:%n can not be used in an expression", un->name, d);
      return false;
    }

  bool ret = true;

  if (e->is (VAUL_AMBG_CALL))
    {
      for(pVAUL_NamedAssocElem ne = pVAUL_AmbgCall(e)->first_actual; ne;
	  ne = pVAUL_NamedAssocElem(ne->next)) 
	{
	  assert(ne->is(VAUL_NAMED_ASSOC_ELEM));
	  if(!check_for_unresolved_names (ne->actual))
	    ret = false;
	}
    }
  else if (e->is (VAUL_AMBG_AGGREGATE))
    {
      // build_Aggregate does it for us.  It still uses
      // overload_resolution.
    }

  return ret;
}

void
psr::report_type_mismatch (pIIR_Expression e, pIIR_Type t, IR_Kind k)
{
  pIIR_Type_vector *types = ambg_expr_types(e);
  if (t)
    error ("%:%n does not match required type %n, its type could be:",
	   e, e, t);
  else
    error ("%:type of %n is not %s type, its type could be:", e, e,
	   type_string(k));
  for (int i = 0; i < types->size(); i++) 
    {
      pIIR_Type t = (*types)[i];
      if (try_overload_resolution(e, t, IR_INVALID))
	info("%:   %n", (*types)[i], (*types)[i]);
    }
  delete types;
}

static bool
is_time_type (pIIR_Type t)
{
  pIIR_Declaration d = t->declaration;
  return t->is(IR_PHYSICAL_TYPE) &&
    d && d->declarative_region
    && d->declarative_region->is(VAUL_STANDARD_PACKAGE)
    && vaul_name_eq ("time", d->declarator);
}

IR_StaticLevel
vaul_merge_levels (IR_StaticLevel l1, IR_StaticLevel l2)
{
  return (l1 < l2)? l1 : l2;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_AbstractLiteralExpression e)
{
  return is_time_type (e->subtype)? IR_GLOBALLY_STATIC : IR_LOCALLY_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_EnumLiteralReference e)
{
  return IR_LOCALLY_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ArrayLiteralExpression e)
{
  return IR_LOCALLY_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_SimpleReference e)
{
  return vaul_compute_static_level (e->object);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_RecordReference e)
{
  return e->record->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_Declaration d)
{
  return IR_NOT_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ConstantDeclaration d)
{
  // Constants in a loop are not static, but everywhere else they are
  // at least globally static, including in generate statements.  When
  // the constant is initialized with a locally static expression, it
  // is also locally static.

  if (d->declarative_region->is (IR_LOOP_DECLARATIVE_REGION))
    return IR_NOT_STATIC;

  return ((d->initial_value &&
	   d->initial_value->static_level == IR_LOCALLY_STATIC)?
	  IR_LOCALLY_STATIC : IR_GLOBALLY_STATIC);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ConstantInterfaceDeclaration d)
{
  // XXX - every constant interface thing expect in a subprogram is a
  // generic?

  if (!d->declarative_region->is (IR_SUBPROGRAM_DECLARATION))
    return IR_GLOBALLY_STATIC;
  return IR_NOT_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_FunctionCall e)
{
  IR_StaticLevel lev;
  
  // initialize LEV to the maximal level possible

  if (e->function->is (IR_PREDEFINED_FUNCTION_DECLARATION))
    lev = IR_LOCALLY_STATIC;
  else if (e->function->pure)
    lev = IR_GLOBALLY_STATIC;
  else
    return IR_NOT_STATIC;

  // adjust for actuals

  for (pIIR_AssociationList al = e->parameter_association_list;
       al; al = al->rest)
    lev = vaul_merge_levels (lev, al->first->actual->static_level);

  return lev;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ExplicitRange e)
{
  IR_StaticLevel lev_left = (e->left
			     ? e->left->static_level
			     : IR_GLOBALLY_STATIC);
  IR_StaticLevel lev_right = (e->right
			      ? e->right->static_level
			      : IR_GLOBALLY_STATIC);

  return vaul_merge_levels (lev_left, lev_right);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ArrayRange a)
{
  return a->array_type->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_ArrayAggregate e)
{
  // Array aggregates are eithe globally static or non-static.  They
  // are never locally static.

  for (pIIR_IndexedAssociationList ial = e->indexed_association_list;
       ial; ial = ial->rest)
    {
      pIIR_IndexedAssociation ia = ial->first;
      if (ia->value && ia->value->static_level < IR_GLOBALLY_STATIC)
	return IR_NOT_STATIC;
      if (ia->is(IR_RANGE_INDEXED_ASSOCIATION)
	  && (vaul_compute_static_level (pIIR_RangeIndexedAssociation(ia)->index_range) 
	      < IR_GLOBALLY_STATIC))
	return IR_NOT_STATIC;
      if (ia->is(IR_SINGLE_INDEXED_ASSOCIATION)
	  && pIIR_SingleIndexedAssociation(ia)->index
	  && (pIIR_SingleIndexedAssociation(ia)->index->static_level 
	      < IR_GLOBALLY_STATIC))
	return IR_NOT_STATIC;
    }
  return IR_GLOBALLY_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_RecordAggregate e)
{
  // Record aggregates are eithe globally static or non-static.  They
  // are never locally static.

  for (pIIR_ElementAssociationList eal = e->element_association_list;
       eal; eal = eal->rest)
    {
      if (eal->first->value &&
	  eal->first->value->static_level < IR_GLOBALLY_STATIC)
	return IR_NOT_STATIC;
    }
  return IR_GLOBALLY_STATIC;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_AttrTypeValue e)
{
  return vaul_compute_static_level (e->prefix);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_AttrTypeFunc e)
{
  IR_StaticLevel lev1 = vaul_compute_static_level (e->prefix);
  IR_StaticLevel lev2 = e->argument->static_level;

  return vaul_merge_levels (lev1, lev2);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_AttrArrayFunc e)
{
  return e->array_type->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_AttrSigFunc a)
{
  return a->signal->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_QualifiedExpression e)
{
  return e->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_TypeConversion e)
{
  return e->static_level;
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_Allocator a)
{
  IR_StaticLevel lev;
  if (a->value)
    lev = a->value->static_level;
  else
    lev = a->type_mark->static_level;
  // A allocator is at most globally static
  return vaul_merge_levels (lev, IR_GLOBALLY_STATIC);
}

IR_StaticLevel
m_vaul_compute_static_level (pIIR_Expression e)
{
  return IR_NOT_STATIC;
}

void
psr::overload_resolution (pIIR_Expression &e, pIIR_Type t, IR_Kind k,
			  bool procs, bool for_read)
{
  if (e == NULL)
    return;

  if (!check_for_unresolved_names (e))
    {
      e = NULL;
      return;
    }

  bool valid = try_overload_resolution (e, t, k);
  
  if (!valid)
    {
      report_type_mismatch (e, t, k);
      e = NULL;
    }
  else
    e = disambiguate_expr (e, t, procs);

  if (e && for_read)
    check_for_read (e);
}

void
psr::check_static_level (pIIR_Expression e, IR_StaticLevel l)
{
  static const char *level_name[] = { "not(?)", "globally", "locally" };

  // XXX - turn this into an error when the determination of the
  // static level of expressions is complete.

  if (e && e->static_level < l && options.debug)
    info ("%:warning: %n is not known to be %s static", e, e, level_name[l]);
}

pIIR_Range
psr::range_from_assoc (pVAUL_GenAssocElem assoc)
{
  if (assoc->is(VAUL_RANGE_ASSOC_ELEM))
    return pVAUL_RangeAssocElem(assoc)->range;
  else if (assoc->is(VAUL_SUBTYPE_ASSOC_ELEM))
    {
      pIIR_Type type = pVAUL_SubtypeAssocElem(assoc)->type;
      if (type == NULL)
	return NULL;
      else if (!type->is(IR_SCALAR_SUBTYPE))
	{
	  error ("%:%n cannot be used as range", assoc, type);
	  return NULL;
	}
      else
	return pIIR_ScalarSubtype(type)->range;
    }
  else
    info ("XXX - no `%s' ranges", assoc->kind_name());
  return NULL;
}

pIIR_Type
psr::ensure_range_type (pIIR_Range range, pIIR_Type type)
{
  if (range->is(IR_EXPLICIT_RANGE))
    {
      pIIR_ExplicitRange er = pIIR_ExplicitRange(range);
      if (type == NULL)
	type = find_index_range_type (er);
      if (type == NULL)
	return NULL;
      overload_resolution(er->left, type);
      overload_resolution(er->right, type);
    }
  else if (range->is(IR_ARRAY_RANGE))
    {
      if (type)
	{
	  pIIR_Type t = pIIR_ArrayRange(range)->type;
	  if (vaul_get_base (t) != type)
	    error ("%:%n is not a base type of %n", t, t, type);
	}
    }
  else
    assert(false);

  return type;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_Expression e)
{
  return VAUL_ObjClass_None;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_RecordReference ror)
{
  if (ror->record)
    return vaul_get_class (ror->record);
  else
    return VAUL_ObjClass_None;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_GenericArrayReference aor)
{
  if (aor->array)
    return vaul_get_class (aor->array);
  else
    return VAUL_ObjClass_None;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_SignalAttr asr)
{
  return VAUL_ObjClass_None;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_SimpleReference so)
{
  return so->object? vaul_get_class (so->object) : VAUL_ObjClass_None;
}
  
VAUL_ObjectClass
m_vaul_get_class (pIIR_AccessReference)
{
  return VAUL_ObjClass_Variable;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_ConstantInterfaceDeclaration i)
{
  return VAUL_ObjClass_Constant;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_VariableInterfaceDeclaration i)
{
  return VAUL_ObjClass_Variable;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_SignalInterfaceDeclaration i)
{
  return VAUL_ObjClass_Signal;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_FileInterfaceDeclaration i)
{
  return VAUL_ObjClass_File;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_ConstantDeclaration)
{
  return VAUL_ObjClass_Constant;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_VariableDeclaration)
{
  return VAUL_ObjClass_Variable;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_SignalDeclaration)
{
  return VAUL_ObjClass_Signal;
}

VAUL_ObjectClass
m_vaul_get_class (pIIR_FileDeclaration)
{
  return VAUL_ObjClass_File;
}

IR_Mode
m_vaul_get_mode (pIIR_Expression e)
{
  return IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_RecordReference ror)
{
  return ror->record? vaul_get_mode (ror->record) : IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_GenericArrayReference aor)
{
  return aor->array? vaul_get_mode (aor->array) : IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_SignalAttr)
{
  return IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_SimpleReference so)
{
  return so->object? vaul_get_mode (so->object) : IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_AccessReference)
{
  return IR_INOUT_MODE; // XXX - guessed
}

IR_Mode
m_vaul_get_mode (pIIR_InterfaceDeclaration i)
{
  return i->mode;
}

IR_Mode
m_vaul_get_mode (pIIR_ConstantDeclaration)
{
  return IR_IN_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_VariableDeclaration)
{
  return IR_INOUT_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_SignalDeclaration)
{
  return IR_INOUT_MODE;
}

IR_Mode
m_vaul_get_mode (pIIR_FileDeclaration)
{
  return IR_UNKNOWN_MODE;
}

pIIR_Type
m_vaul_get_type (pIIR_RecordReference ror)
{
  return ror->subtype;
}

pIIR_Type
m_vaul_get_type (pIIR_ArrayReference aor)
{
  return aor->subtype;
}

pIIR_Type
m_vaul_get_type (pIIR_SliceReference sor)
{
  return sor->subtype;
}

pIIR_Type
m_vaul_get_type (pIIR_SignalAttr asr)
{
  return asr->subtype;
}

pIIR_Type
m_vaul_get_type (pIIR_SimpleReference so)
{
  return so->subtype;
}

pIIR_Type
m_vaul_get_type (pIIR_AccessReference aor)
{
  return aor->subtype;
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_Expression exp)
{
  return NULL;
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_RecordReference ror)
{
  return vaul_get_object_declaration (ror->record);
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_GenericArrayReference aor)
{
  return vaul_get_object_declaration (aor->array);
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_SignalAttr asr)
{
  return vaul_get_object_declaration (asr->signal);
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_SimpleReference so)
{
  return so->object;
}

pIIR_ObjectDeclaration
m_vaul_get_object_declaration (pIIR_AccessReference aor)
{
  return vaul_get_object_declaration (aor->access);
}
