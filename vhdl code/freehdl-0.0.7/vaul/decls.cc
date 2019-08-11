/* declarations

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
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-pool.h>
#include <freehdl/vaul-util.h>

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

#include "vaulgens-chunk.h"

#define psr vaul_parser

pIIR_Identifier
psr::make_id (const char *id)
{
  return mIIR_Identifier (int(0), (IR_Character *)id, strlen (id));
}

pIIR_StringLiteral
psr::make_strlit (const char *str)
{
  return mIIR_StringLiteral (int(0), (IR_Character *)str, strlen (str));
}

pIIR_StringLiteral
psr::make_opid (const char *op)
{
  char *opidstr = vaul_aprintf ("\"%s\"", op);
  pIIR_StringLiteral l = make_strlit (opidstr);
  free (opidstr);
  return l;
}

char *
psr::id_to_chars (pIIR_TextLiteral id)
{
  return id->text.to_chars ();
}

void
psr::init ()
{
  decl_cache = NULL;
  cstat_tail = NULL;
  cur_scope = NULL;
  cur_body = NULL;
  cur_du = new vaul_design_unit (pool->get_work_library(), 
				 NULL, lex->filename);

  tree_protect_loc ((tree_base_node **)&decl_cache);

  next_decl_seqno = 0;

  int l = lex->lineno;
  push_scope (mVAUL_TopScope(l, NULL));
  add_decl (mIIR_LibraryClause (l, make_id("work")));
  add_decl (mIIR_LibraryClause (l, make_id("std")));
  
  std = NULL;

  announced_scope = NULL;
  n_errors = 0;

  max_constrain_depth = -1;
}

void
psr::start (pIIR_LibraryUnit u)
{
  if(u->is(VAUL_STANDARD_PACKAGE))
    std = pVAUL_StandardPackage(u);
  else 
    {
      int l = lex->lineno;
      pVAUL_SelName sn = mVAUL_SelName (l, mVAUL_SimpleName(l, make_id("std")),
			      make_id("standard"));
      pIIR_Declaration d = find_single_decl (sn, VAUL_STANDARD_PACKAGE,
					     "(the) standard package");
      if (d == NULL)
	std = mVAUL_StandardPackage (l, make_id("pseudo-standard"));
      else 
	{
	  std = pVAUL_StandardPackage(d);
	  add_decl (mIIR_UseClause (l, NULL, std));
	}
    }

  u->context_items = cur_scope->declarations;
  u->library_name = make_id (cur_du->get_library ());

  cur_du->set_tree (u);
  add_decl (u);
  push_scope (u);

  char *name;
  if (u->is(IR_ARCHITECTURE_DECLARATION) && u->continued)
    name = pool->architecture_name (id_to_chars (u->continued->declarator),
				    id_to_chars (u->declarator));
  else if (u->is(IR_PACKAGE_BODY_DECLARATION))
    name = pool->package_body_name (id_to_chars (u->declarator));
  else
    name = id_to_chars (u->declarator);
  cur_du->set_name (name);
}

vaul_design_unit *
psr::finish ()
{
  if (cur_scope && cur_scope->is(VAUL_TOP_SCOPE))
    pop_scope (cur_scope);

  if (eof)
    {
      release_ref (cur_du);
      cur_du = NULL;
    }

  if (cur_du && cur_du->get_tree ())
    {
      /* Copy list of used units into LibraryUnit node for easy
	 access.
      */
      vaul_design_unit *u = cur_du->query_used_dus (NULL);
      pIIR_LibraryUnitList n = NULL, *nt = &n;
      while (u)
	{
	  *nt = mIIR_LibraryUnitList (-1, u->get_tree (), NULL);
	  nt = &(*nt)->rest;
	  u = cur_du->query_used_dus (u);
	}
      cur_du->get_tree()->used_units = n;
    }

  closing_label = NULL;
  cur_scope = NULL;

  decl_cache = NULL;
  tree_unprotect_loc ((tree_base_node **)&decl_cache);

  return cur_du;
}

void
psr::add_libs (pIIR_IdentifierList ids)
{
  while (ids)
    {
      add_decl (mIIR_LibraryClause (ids->pos, ids->first));
      ids = ids->rest;
    }
}

void psr::use (pVAUL_SelNameList snl)
{
  for (; snl; snl = snl->link) 
    {
      pVAUL_SelName sn = snl->name;
      pIIR_Declaration d = find_single_decl (sn->prefix, IR_DECLARATION, "");
      if (d == NULL)
	continue;
      if (!d->is(IR_LIBRARY_CLAUSE) && !d->is(IR_PACKAGE_DECLARATION)) {
	error ("%:%n should be a library or a package", sn, sn);
	continue;
      }

      pIIR_TextLiteral id = vaul_name_eq(sn->suffix, "all")? NULL : sn->suffix;
      add_decl (mIIR_UseClause (sn->pos, id, d));
      if (id && d->is (IR_DECLARATIVE_REGION))
	{
	  vaul_decl_set dset(this);
	  find_decls (dset, id, pIIR_DeclarativeRegion(d), true);
	  if (dset.found_none())
	    info ("%:warning: %n is not declared in %n", sn, id, d);
	}
    }
}

void
psr::use_unit (vaul_design_unit *du)
{
  cur_du->uses (du);
}

static void
visit_scope (pIIR_DeclarativeRegion s,
	     void f(pIIR_Declaration, void *),
	     void *cl)
{
  for (pIIR_DeclarationList dl = first(s); dl; dl = next(dl)) 
    {
      pIIR_Declaration d = dl->first;
      if (d->is(IR_USE_CLAUSE))
	{
	  pIIR_Declaration uu = pIIR_UseClause(d)->used_unit;
	  if (uu->is(IR_DECLARATIVE_REGION))
	    visit_scope (pIIR_DeclarativeRegion(uu), f, cl);
	  else
	    f (d, cl);
	}
      else if (d->is(IR_DECLARATIVE_REGION))
	visit_scope (pIIR_DeclarativeRegion(d), f, cl);
      else
	f (d, cl);
    }
}

void
psr::visit_decls (void f (pIIR_Declaration, void *), void *cl)
{
  pIIR_DeclarativeRegion s = cur_scope;
  while (s && !s->is(VAUL_TOP_SCOPE))
    s = s->declarative_region;
  assert(s);

  visit_scope (s, f, cl);
}

void
psr::push_scope (pIIR_DeclarativeRegion s)
{
  s->declarative_region = cur_scope;
  cur_scope = s;

  decls_in_flight(s).init();

  if (s->is(IR_SUBPROGRAM_DECLARATION))
    cur_body = pIIR_SubprogramDeclaration(s);
}

void
psr::pop_scope (pIIR_DeclarativeRegion s)
{
  assert (cur_scope && cur_scope == s);

  decls_in_flight(s).init();

  // check incomplete types
  for (pIIR_DeclarationList dl = s->declarations; dl; dl = dl->rest)
    {
      pIIR_Declaration d = dl->first;
      if (d->is(VAUL_INCOMPLETE_TYPE))
	{
	  error ("%n is still incomplete", d);
	  info ("%:here is the incomplete declaration", d);
	}
    }

  // check unitialized constants
  if (s->is(IR_PACKAGE_BODY_DECLARATION)
      && s->continued && s->continued->is(IR_PACKAGE_DECLARATION))
    {
      pIIR_PackageDeclaration p = pIIR_PackageDeclaration (s->continued);
      for (pIIR_DeclarationList dl = p->declarations; dl; dl = dl->rest)
	{
	  pIIR_Declaration d = dl->first;
	  if (!d->is(IR_CONSTANT_DECLARATION)
	      || pIIR_ConstantDeclaration(d)->initial_value != NULL)
	    continue;

	  pIIR_Declaration d2 = NULL;
	  for (pIIR_DeclarationList dl2 = s->declarations; dl2;
	       dl2 = dl2->rest)
	    {
	      d2 = dl2->first;
	      if (d2->declarator == d->declarator
		  && d2->is(IR_CONSTANT_DECLARATION))
		break;
	    }
	  if(d2 == NULL) 
	    {
	      error ("%n is still not initialized", d);
	      info ("%:here is the declaration", d);
	    }
	}
    }

#if 0
  if (s->is(IR_BLOCK_STATEMENT))
    bind_specs (pIIR_BlockStatement(s));
#endif

  cur_scope = s->declarative_region;
  if (s->is (IR_SUBPROGRAM_DECLARATION))
    {
      pIIR_DeclarativeRegion b;
      for (b = cur_scope; b && !b->is(IR_SUBPROGRAM_DECLARATION);
	   b = b->declarative_region)
	;
      cur_body = pIIR_SubprogramDeclaration(b);
    }
}

static bool
top_can_contain (pIIR_Declaration d)
{
  return d->is(IR_LIBRARY_CLAUSE)
    || d->is(IR_USE_CLAUSE)
    || d->is(IR_DECLARATIVE_REGION);
}

pIIR_DeclarationList
next (pIIR_DeclarationList dl)
{
    if (dl->rest)
      return dl->rest;
    else
      {
	pIIR_Declaration d = dl->first;
	if (d->declarative_region->continued)
	  return first (d->declarative_region->continued);
	else
	  return NULL;
      }
}

pIIR_DeclarationList
first (pIIR_DeclarativeRegion s)
{
  for (; s; s = s->continued)
    if (s->declarations)
      return s->declarations;
  return NULL;
}

static inline bool
overloadable (pIIR_Declaration d)
{
  return d->is(IR_ENUMERATION_LITERAL) || d->is(IR_SUBPROGRAM_DECLARATION);
}

static bool
homograph (pIIR_Declaration d1, pIIR_Declaration d2)
{
  if (!vaul_name_eq (d1->declarator, d2->declarator))
    return false;

  pIIR_InterfaceList p1l =
    (d1->is(IR_SUBPROGRAM_DECLARATION)?
     pIIR_SubprogramDeclaration(d1)->interface_declarations : NULL);
  pIIR_InterfaceList p2l =
    (d2->is(IR_SUBPROGRAM_DECLARATION)?
     pIIR_SubprogramDeclaration(d2)->interface_declarations : NULL);

  while (p1l && p2l)
    {
      pIIR_InterfaceDeclaration p1 = p1l->first;
      pIIR_InterfaceDeclaration p2 = p2l->first;
      if (p1->subtype == NULL || p2->subtype == NULL
	  || vaul_get_base (p1->subtype) != vaul_get_base (p2->subtype))
	return false;
      p1l = p1l->rest;
      p2l = p2l->rest;
    }
  if (p1l || p2l)
    return false;
  
  pIIR_Type t1 = (d1->is(IR_FUNCTION_DECLARATION)?
		  pIIR_FunctionDeclaration(d1)->return_type :
		  (d1->is(IR_ENUMERATION_LITERAL) ?
		   pIIR_EnumerationLiteral(d1)->subtype : NULL));
  pIIR_Type t2 = (d2->is(IR_FUNCTION_DECLARATION) ?
		  pIIR_FunctionDeclaration(d2)->return_type :
		  (d2->is(IR_ENUMERATION_LITERAL) ?
		   pIIR_EnumerationLiteral(d2)->subtype : NULL));

  if (t1 && t2)
    return vaul_get_base (t1) == vaul_get_base (t2);
  return t1 == t2;
}

/* XXX all this same_* stuff should be done by ctree
*/

static bool
same_literal (pIIR_Literal l1, pIIR_Literal l2)
{
  return true;
}

static bool
same_expr (pIIR_Expression e1, pIIR_Expression e2)
{
  if (e1 == e2)
    return true;
  if (!e1 || !e2)
    return false;
  if (e1->kind () != e2->kind ())
    return false;

  if (e1->is(IR_ABSTRACT_LITERAL_EXPRESSION))
    return same_literal (pIIR_AbstractLiteralExpression(e1)->value, 
			 pIIR_AbstractLiteralExpression(e2)->value);
  else if (e1->is(IR_SIMPLE_REFERENCE))
    return (pIIR_SimpleReference(e1)->object ==
	    pIIR_SimpleReference(e2)->object);
  else
    {
      fprintf (stderr, "xxx - can't compare expressions for sameness.\n");
      return true;
    }
}

static bool same_type(pIIR_Type t1, pIIR_Type t2);

static bool
same_range (pIIR_Range r1, pIIR_Range r2)
{
  if (r1 == r2)
    return true;
  if (!r1 || !r2)
    return false;
  if (r1->kind() != r2->kind())
    return false;
  if (r1->is(IR_EXPLICIT_RANGE))
    {
      pIIR_ExplicitRange er1 = pIIR_ExplicitRange(r1);
      pIIR_ExplicitRange er2 = pIIR_ExplicitRange(r2);
      return er1->direction == er2->direction
	&& same_expr (er1->left, er2->left)
	&& same_expr (er1->right, er2->right);
    }
  else if (r1->is(IR_ARRAY_RANGE))
    {
      pIIR_ArrayRange ar1 = pIIR_ArrayRange(r1);
      pIIR_ArrayRange ar2 = pIIR_ArrayRange(r2);
      return ar1->array == ar2->array
	&& same_expr (ar1->index, ar2->index);
    }
  else
    return true;
}

static bool
same_index_constraint (pIIR_TypeList c1,
		       pIIR_TypeList c2)
{
  if (c1 == c2)
    return true;
  if (!c1 || !c2)
    return false;

  while (c1 && c2)
    {
      if (!same_type (c1->first, c2->first))
	return false;
      c1 = c1->rest;
      c2 = c2->rest;
    }
  
  return c1 == NULL && c2 == NULL;
}

static bool
same_type (pIIR_Type t1, pIIR_Type t2)
{
  if (t1 == t2)
    return true;
  if (!t1 || !t2)
    return false;
  if (vaul_get_base (t1) != vaul_get_base (t2))
    return false;

  if (t1->is(IR_SCALAR_SUBTYPE)
      && t2->is(IR_SCALAR_SUBTYPE))
    {
      return same_range (pIIR_ScalarSubtype(t1)->range,
			 pIIR_ScalarSubtype(t2)->range);
    }
  else if (t1->is(IR_ARRAY_SUBTYPE) && t2->is(IR_ARRAY_SUBTYPE))
    {
      return same_index_constraint (pIIR_ArraySubtype(t1)->constraint,
				    pIIR_ArraySubtype(t2)->constraint);
    }
  return false;
}

static bool
conforming (pIIR_Declaration d1, pIIR_Declaration d2)
{
  if (d1->is(IR_SUBPROGRAM_DECLARATION))
    {
      if ((d1->is(IR_FUNCTION_DECLARATION)
	   && !d2->is(IR_FUNCTION_DECLARATION))
	  || (d1->is(IR_PROCEDURE_DECLARATION)
	      && !d2->is(IR_PROCEDURE_DECLARATION)))
	return false;

      pIIR_InterfaceList p1l =
	pIIR_SubprogramDeclaration(d1)->interface_declarations;
      pIIR_InterfaceList p2l =
	pIIR_SubprogramDeclaration(d2)->interface_declarations;

      while (p1l && p2l) 
	{
	  pIIR_InterfaceDeclaration p1 = p1l->first;
	  pIIR_InterfaceDeclaration p2 = p2l->first;

	  if (p1->mode != p2->mode
	      || vaul_get_class (p1) != vaul_get_class (p2)
	      || p1->bus != p2->bus
	      || !same_type(p1->subtype, p2->subtype))
	    return false;
	  p1l = p1l->rest;
	  p2l = p2l->rest;
	}
      
      if (d1->is(IR_FUNCTION_DECLARATION))
	return same_type(pIIR_FunctionDeclaration(d1)->return_type,
			 pIIR_FunctionDeclaration(d2)->return_type);
      return true;
    }
  return false;
}

static bool
immediate_scope (pIIR_Declaration d, pIIR_DeclarativeRegion s)
{
  while (s) 
    {
      if (d->declarative_region == s)
	return true;
      s = s->continued;
    }
  return false;
}

pIIR_Declaration
psr::add_decl (pIIR_DeclarativeRegion region, pIIR_Declaration decl,
	       pIIR_TextLiteral id)
{
  unselect_scope ();

  if (decl == NULL)
    return NULL;

  assert (!region->is(VAUL_TOP_SCOPE) || top_can_contain(decl));

  if (id)
    {
      decl->pos = id->pos;
      decl->declarator = id;
    }

  decl->seqno = next_decl_seqno++;

  if (decl->declarator)
    invalidate_decl_cache (decl->declarator);

  if (decl->declarator && !decl->is(IR_USE_CLAUSE))
    {
      decls_in_flight(region).remove(decl->declarator);

      /* deal with redeclarations
       */
      pIIR_Declaration prev = NULL;
      pIIR_DeclarationList dl;
      for (dl = first(region); dl; dl = next(dl))
	{
	  if (homograph (dl->first, decl))
	    {
	      prev = dl->first;
	      break;
	    }
	}

      while (prev)          // "while" so that we can break out of it
	{
	  if (decl->is(IR_TYPE_DECLARATION)
	      && prev->is(IR_TYPE_DECLARATION))
	    {
	      pIIR_Type pt = pIIR_TypeDeclaration(prev)->type;
	      pIIR_Type dt = pIIR_TypeDeclaration(decl)->type;
	      if (pt->is(VAUL_INCOMPLETE_TYPE) && !dt->is(VAUL_INCOMPLETE_TYPE)) 
		{
		  vaul_complete_incomplete_type (pVAUL_IncompleteType(pt), dt);
		  rem_decl (region, prev);
		  break;
		}
	      else if (dt->is(VAUL_INCOMPLETE_TYPE))
		return prev;
	    }
	  else if (decl->is(IR_CONSTANT_DECLARATION)
		   && prev->is(IR_CONSTANT_DECLARATION))
	    {
	      if (pIIR_ConstantDeclaration(prev)->initial_value == NULL)
		{
		  add_decl_plain (region,
				  mIIR_ConstantDeclaration (decl->pos,
							    prev->declarator,
							    pIIR_ConstantDeclaration(prev)->subtype,
							    pIIR_ConstantDeclaration(decl)->initial_value));
		  return prev;
		}
	    }
	  else if (decl->is(IR_LIBRARY_CLAUSE)
		   && prev->is(IR_LIBRARY_CLAUSE))
	    return prev;
	  else if (conforming(prev, decl)) 
	    {
	      if (prev->is(IR_PREDEFINED_FUNCTION_DECLARATION)
		  || prev->is(IR_PREDEFINED_PROCEDURE_DECLARATION))
		{
		  if (prev->declarative_region == region)
		    {
		      rem_decl (region, prev);
		      break;
		    }
		  else 
		    {
		      error ("%:sorry, you must declare builtin operators"
			     " along with their types", decl);
		      decl->declarative_region = region;
		      return decl;
		    }
		}
	      return prev;
	    }

	  error ("%:redeclaration of %n", decl, prev);
	  info ("%: previously declared here", prev);

	  // point redecl to its 'wannabe' scope, but don't link it
	  // into scope's list, so that it can't be found.
	  //
	  decl->declarative_region = region;
	  return decl;
	}
    }

  add_decl_plain (region, decl);

  if (region->is(VAUL_STANDARD_PACKAGE) && decl->is(IR_TYPE_DECLARATION))
    {
      pVAUL_StandardPackage std = pVAUL_StandardPackage(region);
      pIIR_Type t = pIIR_TypeDeclaration(decl)->type;
      if (vaul_name_eq (decl->declarator, "bit"))
	std->predef_BIT = t;
      else if (vaul_name_eq (decl->declarator, "boolean"))
	std->predef_BOOLEAN = t;
      else if (vaul_name_eq (decl->declarator, "integer"))
	std->predef_INTEGER = t;
      else if (vaul_name_eq (decl->declarator, "real"))
	std->predef_REAL = t;
      else if (vaul_name_eq (decl->declarator, "time"))
	std->predef_TIME = t;
      else if (vaul_name_eq (decl->declarator, "character"))
	std->predef_CHARACTER = t;
      else if (vaul_name_eq (decl->declarator, "string"))
	std->predef_STRING = t;
      else if (vaul_name_eq (decl->declarator, "bit_vector"))
	std->predef_BIT_VECTOR = t;
      else if (vaul_name_eq (decl->declarator, "severity_level"))
	std->predef_SEVERITY_LEVEL = t;
      else if (vaul_name_eq (decl->declarator, "file_open_kind"))
	std->predef_FILE_OPEN_KIND = t;
      else if (vaul_name_eq (decl->declarator, "file_open_status"))
	std->predef_FILE_OPEN_STATUS = t;
    }

  if (decl->is(IR_DECLARATIVE_REGION)
      && pIIR_DeclarativeRegion(decl)->continued
      && region->is(VAUL_TOP_SCOPE))
    {
      region->continued =
	pIIR_DeclarativeRegion(decl)->continued->declarative_region;
    }

  /* Call out to the code generator when we are in a package body.
     Subprograms are handled specially.  Enumeration literals and
     physical units are not handed to the consumer at all. */

  if (!decl->is(IR_SUBPROGRAM_DECLARATION)
      && !decl->is(IR_ENUMERATION_LITERAL)
      && !decl->is(IR_PHYSICAL_UNIT)
      && region->is(IR_PACKAGE_BODY_DECLARATION))
    {
      if (consumer)
	consumer->consume_pbody_decl (decl);
      collect ();
    }

  return decl;
}

void
psr::add_decl_plain (pIIR_DeclarativeRegion region, pIIR_Declaration decl)
{
  decl->declarative_region = region;
  pIIR_DeclarationList dl = mIIR_DeclarationList(decl->pos, decl, NULL);
  if (pIIR_DeclarationList t = tail(region))
    t->rest = dl;
  else
    region->declarations = dl;
  tail(region) = dl;
}

void
psr::rem_decl (pIIR_DeclarativeRegion region, pIIR_Declaration decl)
{
  pIIR_DeclarationList prev = NULL;
  for (pIIR_DeclarationList dl = region->declarations; dl;
       prev = dl, dl = dl->rest)
    {
      if (dl->first == decl)
	{
	  if (prev)
	    prev->rest = dl->rest;
	  else
	    region->declarations = dl->rest;
	  if (dl == tail(region))
	    tail(region) = prev;
	  return;
	}
    }
  assert(false);
}

pIIR_TypeDeclaration
psr::add_type_decl (pIIR_DeclarativeRegion region,
		    pIIR_Type type,
		    pIIR_TextLiteral name)
{
  if (type == NULL)
    return NULL;

  pIIR_TypeDeclaration decl = mIIR_TypeDeclaration(name->pos, name, type);
  decl = pIIR_TypeDeclaration (add_decl (region, decl));
  while (type && type->declaration == NULL)
    {
      type->declaration = decl;
      if (type->is (IR_SUBTYPE))
	type = pIIR_Subtype(type)->immediate_base;
      else
	type = NULL;
    }
  return decl;
}

void
psr::start_decl (pIIR_TextLiteral id)
{
  assert (cur_scope != NULL);
  decls_in_flight(cur_scope).add (id);
}

vaul_decl_set::vaul_decl_set (vaul_parser *p)
{
  pr = p;
  decls = NULL;
  filter_func = NULL;
  filter_data = NULL;

  reset ();
}

vaul_decl_set::~vaul_decl_set ()
{
  reset ();
}

void
vaul_decl_set::reset ()
{
  free (decls);

  decls = NULL;
  n_decls = 0;
  doing_indirects = false;
  not_overloadable = false;
  name = NULL;
}

void
vaul_decl_set::copy_from (vaul_decl_set *set)
{
  reset ();
  n_decls = set->n_decls;
  decls = (item*) vaul_xmalloc (n_decls*sizeof(item));
  for (int i = 0; i < n_decls; i++)
    decls[i] = set->decls[i];
}

void
vaul_decl_set::set_filter (bool (*func)(pIIR_Declaration, void*), void *data)
{
  filter_func = func;
  filter_data = data;
}

bool
vaul_decl_set::has_filter ()
{
  return filter_func != NULL;
}

bool
vaul_decl_set::use_cache ()
{
  return !has_filter ();
}

void
vaul_decl_set::add (pIIR_Declaration d)
{
  // if we have a filter and it rejects D, don't add it.
  
  if (filter_func && !filter_func (d, filter_data))
    return;
    
  // filter out hidden decls

  if (!doing_indirects)
    {
      if (not_overloadable)
	return;
      if (!overloadable(d))
	not_overloadable = true;
      for (int i = 0; i < n_decls; i++)
	if (decls[i].state == valid && homograph (decls[i].d, d)) 
	  {
	    if(name && pr)
	      pr->info("%:%n hides %n", name, decls[i].d, d); // XXX
	    return;
	  }
    }
  else
    {
      // Only add indirect declarations D when the set is either empty
      // or D is overloadable.

      if (n_decls > 0  && !overloadable (d))
	return;
    }
	

  for (int i = 0; i < n_decls; i++)
    if (decls[i].d == d)
      return;

  decls = (item *)vaul_xrealloc(decls, (n_decls+1) * sizeof(item));
  decls[n_decls].d = d;
  decls[n_decls].state = doing_indirects? pot_valid : valid;
  decls[n_decls].cost = 0;
  n_decls++;
}

bool
vaul_decl_set::finish_scope (pIIR_DeclarativeRegion s)
{
  if (doing_indirects)
    return true;

  int i;

  // if there is more than one !overloadable pot_valid, remove all
  // !overloadable pot_valids.
  
  int n_simple_pot_valids = 0;
  for (i = 0; i < n_decls; i++)
    if (decls[i].state == pot_valid && !overloadable(decls[i].d))
      n_simple_pot_valids++;

  if (n_simple_pot_valids > 1)
    for (i = 0; i < n_decls; i++)
      if (decls[i].state == pot_valid && !overloadable(decls[i].d))
	decls[i].state = invalid;

  // filter out pot_valids that have a homograph in immediate scope S

  for (i = 0; i < n_decls; i++)
    if (decls[i].state == valid && immediate_scope(decls[i].d, s))
      for (int j = 0; j < n_decls; j++)
	if (decls[j].state == pot_valid
	    && homograph (decls[i].d, decls[j].d))
	  decls[j].state = invalid;

  // all pot_valids that remain become valids

  for (i = 0; i < n_decls; i++)
    if (decls[i].state == pot_valid) 
      {
	decls[i].state = valid;
	if(!overloadable(decls[i].d))
	  not_overloadable = true;
      }

  // if there are physical units and something else, remove the
  // physical units.

  int n_others = 0;
  for (i = 0; i < n_decls; i++)
    if (decls[i].state == valid && !decls[i].d->is(IR_PHYSICAL_UNIT))
      n_others++;

  if (n_others > 0)
    {
      for (i = 0; i < n_decls; i++)
	if (decls[i].d->is(IR_PHYSICAL_UNIT))
	  decls[i].state = invalid;
    }

  // figure out if no more decls can possibly be accepted
  return not_overloadable;
}

void
vaul_decl_set::begin_indirects ()
{
  doing_indirects = true;
}

void
vaul_decl_set::end_indirects ()
{
  doing_indirects = false;
}

void
vaul_decl_set::refresh ()
{
  for (int i = 0; i < n_decls; i++) 
    {
      if (decls[i].state == pot_invalid)
	decls[i].state = valid;
      decls[i].cost = 0;
    }
}

void
vaul_decl_set::invalidate_pot_invalids ()
{
  for (int i = 0; i < n_decls; i++)
    if (decls[i].state == pot_invalid)
      decls[i].state = invalid;
}

void
vaul_decl_set::filter (int (*f) (pIIR_Declaration, void *), void *cl)
{
  for (int i = 0; i < n_decls; i++)
    if (decls[i].state == valid) 
      {
	int c = f (decls[i].d, cl);
	if (c < 0)
	  decls[i].state = pot_invalid;
	else
	  decls[i].cost = c;
      }
}

void
vaul_decl_set::iterate (void (*f) (pIIR_Declaration, void *), void *cl)
{
  for (int i = 0; i < n_decls; i++)
    if (decls[i].state == valid)
      f (decls[i].d, cl);
}

int
vaul_decl_set::retain_lowcost ()
{
  int i, lc = INT_MAX;

  for (i = 0; i < n_decls; i++)
    if (decls[i].state == valid && decls[i].cost < lc)
      lc = decls[i].cost;
  for (i = 0; i < n_decls; i++)
    if (decls[i].state == valid && decls[i].cost > lc)
      decls[i].state = pot_invalid;
  return lc == INT_MAX ? -1 : lc;
}

static const char *item_state[] = {
  "invalid",
  "pot. invalid",
  "pot. valid",
  "valid"
};

pIIR_Declaration
vaul_decl_set::single_decl (bool print)
{
  // see if a single valid decl remains

  pIIR_Declaration d = NULL;
  int lc;
  int i;
  for (i = 0; i < n_decls; i++)
    if (decls[i].state == valid) 
      {
	if (d)
	  break;
	d = decls[i].d;
	lc = decls[i].cost;
      }

  if (i == n_decls && d) 
    {
      // if (print && name && pr && n_decls > 1)
      //   pr->info ("%:%n resolved to %n (%d)", name, name, d, lc);

      // Add D to list of external decls if it comes from another
      // library unit and is not already on the list.

      pIIR_LibraryUnit cur_lu = pr->cur_du->get_tree ();
      for (pIIR_DeclarativeRegion dr = d->declarative_region;
	   dr;
	   dr = dr->declarative_region)
	{
       
	  if (dr->is (IR_LIBRARY_UNIT) && dr != cur_lu)
	    {
	      for (pIIR_DeclarationList dl = cur_lu->external_decls;
		   dl;
		   dl = dl->rest)
		if (dl->first == d)
		  return d;
	      // pr->info ("+++ - external %n", d);
	      cur_lu->external_decls =
		pr->mIIR_DeclarationList (d->pos,
					  d,
					  cur_lu->external_decls);
	      break;
	    }
	}

      return d;
    }

  if (print && name && pr) 
    {
      // report why not
      if (n_decls == 0)
	pr->error ("%:%n is undeclared", name, name);
      else 
	{
	  // XXX - introduce different kinds of 'invalid'
	  //       to disambiguate between different causes
	  pr->error ("%:use of %n is ambigous, candidates are", name, name);
	  show (!(pr && pr->options.debug));
	}
    }
  return NULL;
}

bool
vaul_decl_set::multi_decls (bool print)
{
  // see if at least one valid decl remains

  pIIR_Declaration d = NULL;
  for (int i = 0; i < n_decls; i++)
    if (decls[i].state == valid)
      return true;

  if (print && name && pr)
    {
      // report why not
      if (n_decls == 0)
	pr->error ("%:%n is undeclared", name, name);
      else 
	{
	  // XXX - introduce different kinds of 'invalid'.
	  pr->error ("%:use of %n is ambigous, candidates are", name, name);
	  show (!(pr && pr->options.debug));
	}
    }
  return false;
}

void
vaul_decl_set::show (bool only_valids)
{
  if (pr == NULL)
    return;

  for (int j = 0; j < n_decls; j++) {
    if (!only_valids || decls[j].state == valid) 
      {
	if (only_valids)
	  pr->info ("%: %n", decls[j].d, decls[j].d);
	else
	  pr->info ("%: %n (%s %d)", decls[j].d,
		    decls[j].d, item_state[decls[j].state],
		    decls[j].cost);
      }
  }
}

bool
vaul_decl_set::found_none()
{
  return n_decls == 0;
}

/* XXX - needs to get a lot cleverer, for example, avoid copy of
   decl_set. */

void
psr::invalidate_decl_cache (pIIR_TextLiteral id)
{
  pVAUL_DeclCache *cp;
  for (cp = &decl_cache; *cp;)
    if (vaul_name_eq (id, (*cp)->id))
      *cp = (*cp)->next;
    else
      cp = &(*cp)->next;
}


bool
psr::find_in_decl_cache (vaul_decl_set &dset, pIIR_TextLiteral id,
			 pIIR_Declaration scope, bool by_sel)
{
  if (options.nocache)
    return false;
  pVAUL_DeclCache c, p;
  for (c = decl_cache, p = NULL; c; p = c, c = c->next)
    {
      if (vaul_name_eq (id, c->id)
	  && scope == c->scope
	  && by_sel == c->by_sel)
	{
	  // bring cache entry to front of list?
#if 0
	  if (p)
	    {
	      p->next = c->next;
	      c->next = decl_cache;
	      decl_cache = c;
	    }
#endif
	  dset.copy_from (c->set);
	  // info ("found %n in cache", id);
	  return true;
	}
    }

  return false;
}

void
psr::add_to_decl_cache (vaul_decl_set &dset,  pIIR_TextLiteral id,
			pIIR_Declaration scope, bool by_sel)
{
  if (options.nocache)
    return;
  // info ("adding %n to cache", id);
  vaul_decl_set *set = new vaul_decl_set(this);
  set->copy_from (&dset);
  pVAUL_DeclCache c = mVAUL_DeclCache (set, id, scope, by_sel);
  c->next = decl_cache;
  decl_cache = c;
}

void
psr::find_decls (vaul_decl_set &ds, pIIR_TextLiteral id,
		 pIIR_Declaration scope_or_lib, bool by_sel)
{
  if (scope_or_lib->is(IR_LIBRARY_CLAUSE))
    {
      char *library = id_to_chars (scope_or_lib->declarator);
      if (vaul_name_eq (library, "work"))
	library = pool->get_work_library ();

      vaul_design_unit *du = pool->get (library, id_to_chars (id));
      if (du)
	{
	  if (du->is_error ())
	    error("%n: %s", id, du->get_error_desc());
	  else
	    {
	      use_unit (du);
	      ds.add (du->get_tree ());
	    }
	}
      release_ref(du);
      return;
    }

  assert (scope_or_lib->is(IR_DECLARATIVE_REGION));
  pIIR_DeclarativeRegion scope = pIIR_DeclarativeRegion (scope_or_lib);

  if (decls_in_flight(scope).contains (id))
    return;
	
  for (pIIR_DeclarationList dl = first(scope); dl; dl = next(dl))
    {
      pIIR_Declaration d = dl->first;
      if (d->is(IR_USE_CLAUSE))
	{
	  if (by_sel)
	    continue;
	  if (d->declarator != NULL && !vaul_name_eq (d->declarator, id))
	    continue;

	  /* declarations reached thru use-clauses must be visible by
	     selection inside their own scope. */

	  ds.begin_indirects ();
	  find_decls (ds, id, pIIR_UseClause(d)->used_unit, true);
	  ds.end_indirects ();
	}
      else if (vaul_name_eq (d->declarator, id))
	ds.add (d);
    }

  if (!ds.finish_scope (scope) && !by_sel && scope->declarative_region)
    find_decls (ds, id, scope->declarative_region, by_sel);
}

void
psr::find_decls (vaul_decl_set &dset, pVAUL_Name n,
		 pIIR_Declaration scope, bool by_sel)
{
  if (n->is(VAUL_SIMPLE_NAME))
    {
      pIIR_TextLiteral id = pVAUL_SimpleName(n)->id;
      if (!dset.use_cache ())
	find_decls (dset, id, scope, by_sel);
      else if(!find_in_decl_cache (dset, id, scope, by_sel))
	{
	  find_decls (dset, pVAUL_SimpleName(n)->id, scope, by_sel);
	  add_to_decl_cache (dset, id, scope, by_sel);
	}
      dset.name = n;
    }
  else if (n->is(VAUL_SEL_NAME))
    {
      // If we have a filter, look up the prefix with a fresh decl_set
      // and throw an error when the prefix could not be resolved.
      // Otherwise, use dset for looking up the prefix and allow
      // partial lookups, ie. for selected names that refer to record
      // components.

      pIIR_Declaration d;

      if (dset.has_filter ())
	{
	  vaul_decl_set prefix_dset (this);
	  find_decls (prefix_dset, pVAUL_SelName(n)->prefix, scope, by_sel);
	  d = prefix_dset.single_decl ();
	}
      else
	{
	  find_decls (dset, pVAUL_SelName(n)->prefix, scope, by_sel);
	  d = dset.single_decl (false);
	}

      if (d == NULL)
	return;

      if (!d->is(IR_DECLARATIVE_REGION) && !d->is(IR_LIBRARY_CLAUSE))
	{
	  // its probably a record reference. build_Expr will
	  // handle all errors.
	  return; 
	}

      if (!d->is(IR_PACKAGE_DECLARATION) && !d->is(IR_LIBRARY_CLAUSE))
	{
	  error ("%:declarations in %n are not visible here", n,
		 pVAUL_SelName(n)->prefix);
	  return;
	}

      dset.reset ();

      find_decls (dset, pVAUL_SelName(n)->suffix, d, true);
      dset.name = n;
    }
  else if (n->is(VAUL_IFTS_NAME))
    {
      find_decls (dset, pVAUL_IftsName(n)->prefix, scope, by_sel);
    }
  else if (n->is(VAUL_ATTRIBUTE_NAME))
    {
      find_decls (dset, pVAUL_AttributeName(n)->prefix, scope, by_sel);
    }
  else
    {
      info("XXX - can't look up a %s", n->kind_name());
      dset.name = n;
    }
}

void
psr::find_decls (vaul_decl_set &ds, pVAUL_Name n)
{
  if (selected_scope)
    find_decls(ds, n, selected_scope, true);
  find_decls (ds, n, cur_scope, false);
}

void
psr::select_scope (pIIR_DeclarativeRegion s)
{
  selected_scope = s;
}

void
psr::unselect_scope()
{
  selected_scope = NULL;
}

pIIR_Declaration
psr::find_single_decl (pVAUL_Name name, IR_Kind exp_k, const char *kind_name)
{
  vaul_decl_set ds(this);
  find_decls (ds, name);
  pIIR_Declaration d = ds.single_decl (kind_name != NULL);
  if (d && (!d->is(exp_k) || ds.name != name)) 
    {
      if (kind_name)
	error ("%:%n is not a %s", name, name, kind_name);
      d = NULL;
    }
  return d;
}

pIIR_EntityDeclaration
psr::get_entity (pIIR_Identifier n)
{
  pIIR_EntityDeclaration entity = NULL;

  vaul_design_unit *du = pool->get (pool->get_work_library(), 
				    id_to_chars (n));
  if (du == NULL)
    error ("unknown entity %n", n);
  else if (du->is_error())
    error ("%n: %s", n, du->get_error_desc());
  else if (du->get_tree() == NULL
	   || !du->get_tree()->is(IR_ENTITY_DECLARATION))
    error ("%n is not an entity", n);
  else 
    {
      use_unit (du);
      entity = pIIR_EntityDeclaration(du->get_tree());
    }
  release_ref(du);
  return entity;
}

pIIR_PackageDeclaration
psr::get_package (pIIR_Identifier n)
{
  pIIR_PackageDeclaration package = NULL;

  vaul_design_unit *du = pool->get (pool->get_work_library(),
				    id_to_chars (n));
  if (du == NULL)
    error ("unknown package %n", n);
  else if (du->is_error())
    error ("%n: %s", n, du->get_error_desc());
  else if (du->get_tree() == NULL
	   || !du->get_tree()->is(IR_PACKAGE_DECLARATION))
    error ("%n is not a package", n);
  else 
    {
      use_unit (du);
      package = pIIR_PackageDeclaration (du->get_tree());
    }
  release_ref(du);
  return package;
}

pIIR_ConfigurationDeclaration
psr::get_configuration (pVAUL_Name c)
{
  return pIIR_ConfigurationDeclaration(
	  find_single_decl(c, IR_CONFIGURATION_DECLARATION, "configuration"));
}

pIIR_Declaration
psr::add_Alias (pIIR_Identifier id, pIIR_Type type, pVAUL_Name thing)
{
  if (id == NULL || type == NULL || thing == NULL)
    return NULL;

  pIIR_Expression base = build_Expr (thing);
  overload_resolution_not_for_read (base, type);
  if (base == NULL)
    return NULL;

  // Clone `base', which is an ObjectReference.

  pIIR_ObjectDeclaration object = vaul_get_object_declaration (base);
  pIIR_ObjectDeclaration alias;

  if (object == NULL)
    return NULL;

  if (object->is(IR_SIGNAL_DECLARATION))
    {
      pIIR_SignalDeclaration d = pIIR_SignalDeclaration (object);
      alias = mIIR_SignalDeclaration (id->pos,
				      id, type,
				      d->initial_value,
				      d->signal_kind);
    }
  else if (object->is(IR_VARIABLE_DECLARATION))
    {
      pIIR_VariableDeclaration d = pIIR_VariableDeclaration (object);
      alias = mIIR_VariableDeclaration (id->pos,
					id, type,
					d->initial_value);
    }
  else if (object->is(IR_CONSTANT_DECLARATION))
    {
      pIIR_ConstantDeclaration d = pIIR_ConstantDeclaration (object);
      alias = mIIR_ConstantDeclaration (id->pos,
					id, type,
					d->initial_value);
    }
  else if (object->is(IR_FILE_DECLARATION))
    {
      pIIR_FileDeclaration d = pIIR_FileDeclaration (object);
      alias = mIIR_FileDeclaration (id->pos,
				    id, type,
				    NULL,
				    d->file_open_expression,
				    d->file_logical_name);
    }
  else if (object->is(IR_SIGNAL_INTERFACE_DECLARATION))
    {
      pIIR_SignalInterfaceDeclaration d =
	pIIR_SignalInterfaceDeclaration (object);
      alias = mIIR_SignalInterfaceDeclaration (id->pos,
					       id, type,
					       d->initial_value,
					       d->mode,
					       d->bus,
					       d->signal_kind);
    }
  else if (object->is(IR_VARIABLE_INTERFACE_DECLARATION))
    {
      pIIR_VariableInterfaceDeclaration d =
	pIIR_VariableInterfaceDeclaration (object);
      alias = mIIR_VariableInterfaceDeclaration (id->pos,
						 id, type,
						 d->initial_value,
						 d->mode,
						 d->bus);
    }
  else if (object->is(IR_CONSTANT_INTERFACE_DECLARATION))
    {
      pIIR_ConstantInterfaceDeclaration d =
	pIIR_ConstantInterfaceDeclaration (object);
      alias = mIIR_ConstantInterfaceDeclaration (id->pos,
						 id, type,
						 d->initial_value,
						 d->mode,
						 d->bus);
    }
  else if (object->is(IR_FILE_INTERFACE_DECLARATION))
    {
      pIIR_FileInterfaceDeclaration d =
	pIIR_FileInterfaceDeclaration (object);
      alias = mIIR_FileInterfaceDeclaration (id->pos,
					     id, type,
					     d->initial_value,
					     d->mode,
					     d->bus);
    }
  else
    {
      error ("XXX - don't know how to alias %n", object);
      return NULL;
    }

  alias->alias_base = pIIR_ObjectReference (base);

  return add_decl (alias);
}
