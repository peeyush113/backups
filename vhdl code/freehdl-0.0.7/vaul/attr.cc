/* attributes

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

enum attr_id {

    // type prefix
    ai_BASE, ai_IMAGE, ai_VALUE, ai_POS, ai_VAL, ai_SUCC, ai_PRED,
    ai_LEFTOF, ai_RIGHTOF,

    // type or array prefix
    ai_LEFT, ai_RIGHT, ai_HIGH, ai_LOW, ai_ASCENDING,
    ai_RANGE, ai_REVERSE_RANGE, ai_LENGTH,

    // signal prefix
    ai_DELAYED, ai_STABLE, ai_QUIET, ai_TRANSACTION, ai_EVENT,
    ai_ACTIVE, ai_LAST_EVENT, ai_LAST_ACTIVE, ai_LAST_VALUE,
    ai_DRIVING, ai_DRIVING_VALUE,

    // named entity prefix
    ai_SIMPLE_NAME, ai_INSTANCE_NAME, ai_PATH_NAME,

    ai_MAX
};

#define AI_FIRST_TYPE   ai_BASE
#define AI_LAST_TYPE    ai_RIGHTOF
#define AI_FIRST_T_OR_A ai_LEFT
#define AI_LAST_T_OR_A  ai_LENGTH
#define AI_FIRST_TA     AI_FIRST_TYPE
#define AI_LAST_TA      AI_LAST_T_OR_A
#define AI_FIRST_SIGNAL ai_DELAYED
#define AI_LAST_SIGNAL  ai_DRIVING_VALUE
#define AI_FIRST_ENTITY ai_SIMPLE_NAME
#define AI_LAST_ENTITY  ai_PATH_NAME

static const char *attr_name[] = {
    "BASE", "IMAGE", "VALUE", "POS", "VAL", "SUCC", "PRED",
    "LEFTOF", "RIGHTOF",

    "LEFT", "RIGHT", "HIGH", "LOW", "ASCENDING",

    "RANGE", "REVERSE_RANGE", "LENGTH",

    "DELAYED", "STABLE", "QUIET", "TRANSACTION", "EVENT",
    "ACTIVE", "LAST_EVENT", "LAST_ACTIVE", "LAST_VALUE",
    "DRIVING", "DRIVING_VALUE",

    "SIMPLE_NAME", "INSTANCE_NAME", "PATH_NAME"
};


pIIR
psr::build_AttrNode (pVAUL_Name n, vaul_decl_set *set, IR_Kind basic_k)
{
  if (n->is(VAUL_ATTRIBUTE_NAME))
    return build_AttrNode (pVAUL_AttributeName(n), set, basic_k);

  if(n == set->name && tree_is (basic_k, IR_TYPE_DECLARATION)) 
    {
      pIIR_Declaration d = set->single_decl ();
      delete set;
      assert (d->is(IR_TYPE_DECLARATION));
      return pIIR_TypeDeclaration(d)->type;
    }

  return build_Expr (n, set, basic_k);
}

pIIR
psr::build_AttrNode (pVAUL_AttributeName n, vaul_decl_set *set, IR_Kind basic_k)
{
  pIIR_Expression p = NULL;
  bool too_many = false;
  if (n->first_actual) 
    {
      if (n->first_actual->next)	    
	too_many = true;
      if (n->first_actual->formal)
	error ("%:attribute arguments do not have names", n);
      p = n->first_actual->actual;
    }

  attr_id ai = ai_MAX;
  for (int i = 0; i < ai_MAX; i++)
    if(vaul_name_eq(n->attribute, attr_name[i])) 
      {
	ai = attr_id(i);
	break;
      }

  pIIR res = NULL;

  if (ai >= AI_FIRST_TA && ai <= AI_LAST_TA) 
    {
      pIIR pfx = build_AttrNode (n->prefix, set, basic_k);
      if (pfx == NULL)
	return NULL;

      // T is the type we are talking about.
      // BT is the base type of T
      // E is an expression denoting the original prefix, or NULL
      // when the prefix was T itself.

      pIIR_Type t = NULL, base_t = NULL;
      pIIR_Expression e = NULL;
      
      if (pfx->is(IR_EXPRESSION))
	{
	  e = pIIR_Expression(pfx);
	  overload_resolution (e, NULL, IR_TYPE, false, false);
	  e = make_appropriate (e);
	  if (e == NULL)
	    return NULL;
	  t = expr_type (e);
	  if (t == NULL)
	    return NULL;
	}
      else if (pfx->is(IR_TYPE))
	{
	  t = pIIR_Type(pfx);
	}
      else
	{
	  error ("%:prefix of '%s must be a type or object",
		 n->prefix, attr_name[ai]);
	  return NULL;
	}
	
      base_t = vaul_get_base (t);

      if(ai >= AI_FIRST_TYPE && ai <= AI_LAST_TYPE) {
	if(ai >= ai_IMAGE && ai <= ai_VALUE) {
	  if(!base_t->is(IR_SCALAR_TYPE)) {
	    error("%:prefix of '%s must be a scalar type", n->prefix,
		  attr_name[ai]);
	    return NULL;
	  }
	} else if(ai >= ai_POS && ai <= ai_RIGHTOF) {
	  if(!is_discrete_type(base_t)
	     && !base_t->is(IR_PHYSICAL_TYPE)) {
	    error("%:prefix of '%s must be a discrete or"
		  " physical type", n->prefix, attr_name[ai]);
	    return NULL;
	  }
	}

	switch(ai) {
	case ai_BASE: {
	  res = base_t;
	} break;

	case ai_IMAGE: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_IMAGE (n->pos, std->predef_STRING, t, p);
	  p = NULL;
	} break;

	case ai_VALUE: {
	  overload_resolution (p, std->predef_STRING);
	  res = mIIR_Attr_VALUE (n->pos, t, t, p);
	  p = NULL;
	} break;

	case ai_POS: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_POS (n->pos, std->universal_integer, t, p);
	  p = NULL;
	} break;

	case ai_VAL: {
	  overload_resolution (p, IR_INTEGER_TYPE);
	  res = mIIR_Attr_VAL (n->pos, t, t, p);
	  p = NULL;
	} break;

	case ai_SUCC: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_SUCC (n->pos, t, t, p);
	  p = NULL;
	} break;

	case ai_PRED: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_PRED (n->pos, t, t, p);
	  p = NULL;
	} break;

	case ai_LEFTOF: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_LEFTOF (n->pos, t, t, p);
	  p = NULL;
	} break;

	case ai_RIGHTOF: {
	  overload_resolution (p, t);
	  res = mIIR_Attr_RIGHTOF (n->pos, t, t, p);
	  p = NULL;
	} break;

	default: // should be complete.
	  info("%:XXX - unimplemented type attribute %n",
	       n, n->attribute);
	  return NULL;
	}

      } else if (ai >= AI_FIRST_T_OR_A && ai <= AI_LAST_T_OR_A) {
	int index;
	pIIR_Expression arg = p;
	p = NULL;
	if (base_t->is(IR_ARRAY_TYPE))
	  {
	    if (arg)
	      {
		overload_resolution (arg, IR_INTEGER_TYPE);
		if (arg == NULL)
		  return NULL;
	      }

	    pIIR_Type it = find_array_attr_index_type (pIIR_ArrayType(base_t),
						       arg, index);
	    if (it == NULL)
	      return NULL;

	    switch (ai) 
	      {
	      case ai_LEFT:
		res = mIIR_Attr_ArrayLEFT (n->pos, it, e, t, index);
		break;
	      case ai_RIGHT:
		res = mIIR_Attr_ArrayRIGHT (n->pos, it, e, t, index);
		break;
	      case ai_HIGH:
		res = mIIR_Attr_ArrayHIGH (n->pos, it, e, t, index);
		break;
	      case ai_LOW:
		res = mIIR_Attr_ArrayLOW (n->pos, it, e, t, index);
		break;
	      case ai_ASCENDING:
		res = mIIR_Attr_ArrayASCENDING (n->pos,
						std->predef_BOOLEAN,
						e, t, index);
		break;
	      case ai_RANGE:
		res = mIIR_Attr_ArrayRANGE (n->pos, it, e, t, arg);
		break;
	      case ai_REVERSE_RANGE:
		res = mIIR_Attr_ArrayREVERSE_RANGE (n->pos, it, e, t, arg);
		break;
	      case ai_LENGTH:
		res = mIIR_Attr_ArrayLENGTH (n->pos,
					     std->universal_integer, e, t,
					     index);
		break;
	      default:
		assert (false);
	      }
	  }
	else if (t)
	  {
	    switch (ai)
	      {
	      case ai_LEFT:
		res = mIIR_Attr_LEFT (n->pos, t, t, arg);
		break;
	      case ai_RIGHT:
		res = mIIR_Attr_RIGHT (n->pos, t, t, arg);
		break;
	      case ai_HIGH:
		res = mIIR_Attr_HIGH (n->pos, t, t, arg);
		break;
	      case ai_LOW:
		res = mIIR_Attr_LOW (n->pos, t, t, arg);
		break;
	      case ai_ASCENDING:
		res = mIIR_Attr_ASCENDING (n->pos, std->predef_BOOLEAN,
					   t, arg);
		break;
	      case ai_RANGE:
	      case ai_REVERSE_RANGE:
	      case ai_LENGTH:
		error ("prefix of '%s must be an array or array type",
		       attr_name[ai]);
		res = NULL;
		break;
	      default:
		assert (false);
	      }
	  }
	else
	  {
	    error ("%:prefix of '%s must be a type or array",
		   n->prefix, attr_name[ai]);
	    return NULL;
	  }
      }

    } else if(ai >= AI_FIRST_SIGNAL && ai <= AI_LAST_SIGNAL) {

      pIIR b = build_Expr (n->prefix, set, basic_k);
      if (b == NULL)
	return NULL;
      if (!b->is(IR_OBJECT_REFERENCE) || !is_signal (pIIR_ObjectReference(b)))
	{
	  error ("%:prefix of '%s must be a signal",
		 n->prefix, attr_name[ai]);
	  return NULL;
	}

      pIIR_ObjectReference r = pIIR_ObjectReference(b);

      switch(ai) 
	{
	case ai_DELAYED:
	  overload_resolution (p, std->predef_TIME);
	  res = mIIR_Attr_DELAYED (n->pos, vaul_get_type (r), r, p);
	  p = NULL;
	  break;

	case ai_STABLE:
	  overload_resolution (p, std->predef_TIME);
	  res = mIIR_Attr_STABLE (n->pos, std->predef_BOOLEAN, r, p);
	  p = NULL;
	  break;

	case ai_QUIET:
	  overload_resolution (p, std->predef_TIME);
	  res = mIIR_Attr_QUIET (n->pos, std->predef_BOOLEAN, r, p);
	  p = NULL;
	  break;

	case ai_TRANSACTION:
	  res = mIIR_Attr_TRANSACTION (n->pos, std->predef_BIT, r);
	  break;

	case ai_EVENT:
	  res = mIIR_Attr_EVENT (n->pos, std->predef_BOOLEAN, r);
	  break;

	case ai_ACTIVE:
	  res = mIIR_Attr_ACTIVE (n->pos, std->predef_BOOLEAN, r);
	  break;

	case ai_LAST_EVENT:
	  res = mIIR_Attr_LAST_EVENT (n->pos, std->predef_TIME, r);
	  break;
	    
	case ai_LAST_ACTIVE:
	  res = mIIR_Attr_LAST_ACTIVE (n->pos, std->predef_TIME, r);
	  break;
	    
	case ai_LAST_VALUE:
	  res = mIIR_Attr_LAST_VALUE (n->pos, vaul_get_type(r), r);
	  break;

	case ai_DRIVING:
	  res = mIIR_Attr_DRIVING (n->pos, std->predef_BOOLEAN, r);
	  break;
	    
	case ai_DRIVING_VALUE:
	  res = mIIR_Attr_DRIVING_VALUE (n->pos, vaul_get_type(r), r);
	  break;

	default:
	  // should be complete
	  info ("%:XXX - unimplemented signal attribute %n", n, n->attribute);
	  
	}

    } else if(ai >= AI_FIRST_ENTITY && ai <= AI_LAST_ENTITY) {
      info ("XXX - unimplemented entity attribute %n", n, n->attribute);
      delete set;
      res = NULL;
    } else {
      // user defined attributes
      info("%:XXX - no user defined attributes", n);
      delete set;
      res = NULL;
    }

  if(p || too_many)
    error ("%:too many arguments for attribute %s", n, attr_name[ai]);

  return res;
}

pIIR_Type
psr::find_array_attr_index_type (pIIR_ArrayType t, pIIR_Expression p, int &index)
{
  if (p == NULL)
    index = 1;
  else if (!evaluate_locally_static_universal_integer(p, index))
    return NULL;

  //info ("+++ - folded %n to %d", p, index);

  if (index <= 0)
    {
      error ("%:indices must be positive", p);
      return NULL;
    }
    
  pIIR_TypeList it = pIIR_ArrayType(t)->index_types;
  int dims = 0;
  while(it && index != ++dims)
    it = it->rest;
  if (it == NULL) 
    {
      error("%:%n has only %d dimensions, not %d", p, t,
	    dims, index);
      return NULL;
    }
  return it->first;
}

#if 0 // not used

static pIIR_Declaration
find_in_decl_part (nScope part, Id id)
{
  for (nDeclaration d = part->first_decl; d; d = d->next_decl) {
    if (d->id && vaul_name_eq (d->id, id))
      return d;
  }
  return NULL;
}

#endif

void
psr::bind_attrspec (pVAUL_AttributeSpec s)
{
  if (s == NULL || s->entities == NULL)
    return;

  pVAUL_SimpleName attr_name = mVAUL_SimpleName (s->pos, s->attr_desig);
  pIIR_AttributeDeclaration a =
    pIIR_AttributeDeclaration (find_single_decl (attr_name,
						 IR_ATTRIBUTE_DECLARATION,
						 "attribute"));
  if (a == NULL)
    return;

  overload_resolution (s->value, a->subtype);
  if (s->value == NULL)
    return;

  pVAUL_EntityNameList el = s->entities->names;
  if (el->is(VAUL_ENTITY_NAME_LIST_IDS)) 
    {
      IR_Kind eclass = s->entities->entity_class;
      const char *ename = tree_kind_name (eclass);
      
      for (pVAUL_DesigList il = pVAUL_EntityNameList_Ids(el)->ids;
	   il; il = il->link)
	{
	  pIIR_Declaration d =
	    find_single_decl (mVAUL_SimpleName(il->pos,
					       il->desig),
			      IR_DECLARATION, NULL);
	  if (d == NULL)
	    continue;
	  
	  if (d->declarative_region != cur_scope
	      && d != cur_du->get_tree())
	    {
	      error ("%:only declarations in the current design unit "
		     "can be attributed", il);
	    }
	  else
	    {
	      pIIR_AttributeValue av = mIIR_AttributeValue (il->pos,
							    s->value,
							    a);
	      d->attributes =
		mIIR_AttributeValueList (av->pos, av, d->attributes);
	    }
	}
    }
  else if(el->is(VAUL_ENTITY_NAME_LIST_ALL))
    {
      info("%:XXX - no ALL attributions yet", el);
    }
  else if(el->is(VAUL_ENTITY_NAME_LIST_OTHERS))
    {
      info("%:XXX - no OTHERS attributions yet", el);
    }
  else
    assert(false);
}
