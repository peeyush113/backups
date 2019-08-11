/* blocks, components and bindings

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

pIIR_BindingIndication
psr::build_BindingIndic (pVAUL_IncrementalBindingIndic ibi)
{
  return build_BindingIndic (ibi->pos, 
			     ibi->unit, ibi->generic_assoc, ibi->port_assoc);
}

pIIR_BindingIndication
psr::build_BindingIndic (pIIR_PosInfo pos,
			 pIIR_Component unit,
			 pVAUL_NamedAssocElem gm,
			 pVAUL_NamedAssocElem pm)
{
  if (unit == NULL)
    return NULL;

  pIIR_AssociationList g = associate (gm, vaul_get_generics (unit), false);
  pIIR_AssociationList p = associate_ports (pm, vaul_get_ports (unit));
  return mIIR_BindingIndication (pos, unit, g, p);
}

void
psr::add_spec (pIIR_DeclarativeRegion dr, pVAUL_ConfigSpec cs)
{
  pIIR_ComponentDeclaration comp = cs->comps->comp;

  pIIR_ConfigurationSpecificationList specs =
    vaul_get_configuration_specifications (dr);

  if (cs->comps->ids->is(VAUL_INST_LIST_IDS))
    {
      // Check each one for duplicates and add it to the end of the
      // specification list.  Check for others and all specifications
      // as well.

      for (pIIR_IdentifierList il = pVAUL_InstList_Ids(cs->comps->ids)->ids;
	   il; il = il->rest)
	{
	  pIIR_Identifier l = il->first;

	  pIIR_ConfigurationSpecificationList *sp;
	  for (sp = &specs; *sp; sp = &(*sp)->rest)
	    {
	      pIIR_ConfigurationSpecification s = (*sp)->first;

	      if (s->label && vaul_name_eq (s->label, l))
		{
		  error ("%:duplicate configuration specification", cs);
		  info ("%:this is the conflicting specification", s);
		  break;
		}
	      else if (s->label == NULL && s->component == comp)
		{
		  error ("%:component %n is already covered by "
			 "an ALL or OTHERS binding", cs, comp);
		  return;
		}
	    }

	  if (*sp == NULL)
	    {
	      // We have reached the end of the list without
	      // conflicts.  Add a new labelled specification
	      
	      pIIR_ConfigurationSpecification ns =
		mIIR_ConfigurationSpecification (cs->pos,
						 l,
						 comp,
						 cs->binding);
	      *sp = mIIR_ConfigurationSpecificationList (cs->pos,
							 ns,
							 NULL);
	    }
	}
    }
  else if (cs->comps->ids->is(VAUL_INST_LIST_OTHERS))
    {
      // Check if we already have a `others' or `all' specification.

      pIIR_ConfigurationSpecificationList *sp;
      for (sp = &specs; *sp; sp = &(*sp)->rest)
	{
	  pIIR_ConfigurationSpecification s = (*sp)->first;
	  
	  if (s->label == NULL && s->component == comp)
	    {
	      error ("%:can only have one ALL or OTHERS specification"
		    " for a component", cs);
	      info ("%:here is another one", s);
	      return;
	    }
	}

      pIIR_ConfigurationSpecification ns =
	mIIR_ConfigurationSpecification (cs->pos,
					 NULL,
					 comp,
					 cs->binding);
      *sp = mIIR_ConfigurationSpecificationList (cs->pos,
						 ns,
						 NULL);
    }
  else if (cs->comps->ids->is(VAUL_INST_LIST_ALL))
    {
      // Check if we already have specifications for comp.

      pIIR_ConfigurationSpecificationList *sp;
      for (sp = &specs; *sp; sp = &(*sp)->rest)
	{
	  pIIR_ConfigurationSpecification s = (*sp)->first;
	  
	  if (s->component == comp)
	    {
	      error ("%:An ALL specification must be the only one"
		    " for a component", cs);
	      info ("%:here is another one", s);
	      return;
	    }
	}

      pIIR_ConfigurationSpecification ns =
	mIIR_ConfigurationSpecification (cs->pos,
					 NULL,
					 comp,
					 cs->binding);
      *sp = mIIR_ConfigurationSpecificationList (cs->pos,
						 ns,
						 NULL);
    }

  vaul_set_configuration_specifications (dr, specs);
}

static bool
filter_none_entities (pIIR_Declaration d, void *data)
{
  return d->is(IR_ENTITY_DECLARATION);
}

pIIR_BindingIndication
psr::find_component_configuration (pIIR_Identifier label,
				   pIIR_BindingIndication inst_binding)
{
  pIIR_DeclarativeRegion unit = inst_binding->unit;
  pIIR_BindingIndication conf_binding = NULL;

  pIIR_ConfigurationSpecificationList confs =
    vaul_get_configuration_specifications (cur_scope);

  for (pIIR_ConfigurationSpecificationList cl = confs; 
       cl && conf_binding == NULL; cl = cl->rest)
    {
      pIIR_ConfigurationSpecification s = cl->first;

      if (s->label && vaul_name_eq (s->label, label))
	{
	  if (s->component != unit)
	    {
	      error ("%:component %n conflicts with specification",
		     label, unit);
	      info ("%:here", s);
	    }
	  conf_binding = s->binding;
	}
      else if (s->label == NULL && s->component == unit)
	conf_binding = s->binding;
    }

  if (!unit->is(IR_COMPONENT_DECLARATION))
    {
      if (conf_binding)
	error ("%:only component instantiations can be configured",
	       label);
      return NULL;
    }

  if (!conf_binding)
    {
      pIIR_PosInfo pos = inst_binding->pos;

      vaul_decl_set *set = new vaul_decl_set(this);
      set->set_filter (filter_none_entities, NULL);
      find_decls (*set, unit->declarator, cur_scope, false);

      pIIR_Declaration d = set->single_decl (false);
      delete set;
      
      // Maybe look for an invisible entity in WORK

      if (d == NULL
	  && options.allow_invisible_default_bindings_from_work)
	{
	  vaul_decl_set *set = new vaul_decl_set(this);
	  set->set_filter (filter_none_entities, NULL);
	  pVAUL_Name work_entity =
	    mVAUL_SelName (pos,
			   mVAUL_SimpleName (pos, make_id ("work")),
			   unit->declarator);

	  find_decls (*set, work_entity);
	  d = set->single_decl (false);
	  if (d)
	    info ("note: using invisible %n as default binding", work_entity);
	  delete set;
	}

      if (d == NULL)
	return NULL;

      assert (d->is(IR_ENTITY_DECLARATION));
      pIIR_EntityDeclaration conf_unit = pIIR_EntityDeclaration(d);

      pVAUL_NamedAssocElem conf_gmap = NULL;

      for (pIIR_InterfaceList il = conf_unit->generic_clause;
	   il; il = il->rest)
	{
	  pIIR_InterfaceDeclaration formal = il->first;
	  
	  // Find corresponding local associations in component
	  // instantiation.  We might find more than one when partial
	  // association has been used.  When we find none, a
	  // association with "open" is constructed.
	  // 
	  // For every association that is found, we create a new
	  // 'named association' by copying the name that has been
	  // used to refer to the formal, and by constructing an expression

	  // XXX - do what is explained above

	  pIIR_InterfaceDeclaration local_generic = NULL;
	  for (pIIR_AssociationList al = inst_binding->generic_map_list;
	       al; al = al->rest)
	    {
	      pIIR_ObjectDeclaration obj =
		vaul_get_object_declaration (al->first->formal);
	      if (vaul_name_eq (obj->declarator, formal->declarator))
		{
		  assert (obj->is(IR_INTERFACE_DECLARATION));
		  local_generic = pIIR_InterfaceDeclaration (obj);
		  break;
		}
	    }
	  if (local_generic)
	    conf_gmap = mVAUL_NamedAssocElem 
	                 (pos,
			  conf_gmap,
			  mVAUL_SimpleName (pos, formal->declarator),
			  mIIR_SimpleReference (pos,
						local_generic->subtype,
						local_generic));
	  else
	    conf_gmap = mVAUL_NamedAssocElem 
	                 (pos,
			  conf_gmap,
			  mVAUL_SimpleName (pos, formal->declarator),
			  mIIR_OpenExpression (pos, formal->subtype));
	}

      pVAUL_NamedAssocElem conf_pmap = NULL;

      for (pIIR_InterfaceList il = conf_unit->port_clause;
	   il; il = il->rest)
	{
	  pIIR_InterfaceDeclaration formal = il->first;
	  
	  // find corresponding local port in component instantiation
	  pIIR_InterfaceDeclaration local_port = NULL;
	  for (pIIR_AssociationList al = inst_binding->port_map_list;
	       al; al = al->rest)
	    {
	      pIIR_ObjectDeclaration obj =
		vaul_get_object_declaration (al->first->formal);
	      if (vaul_name_eq (obj->declarator, formal->declarator))
		{
		  assert (obj->is(IR_INTERFACE_DECLARATION));
		  local_port = pIIR_InterfaceDeclaration (obj);
		  break;
		}
	    }
	  if (local_port)
	    conf_pmap = mVAUL_NamedAssocElem 
	                 (pos,
			  conf_pmap,
			  mVAUL_SimpleName (pos, formal->declarator),
			  mIIR_SimpleReference (pos,
						local_port->subtype,
						local_port));
	  else
	    conf_pmap = mVAUL_NamedAssocElem 
	                 (pos,
			  conf_pmap,
			  mVAUL_SimpleName (pos, formal->declarator),
			  mIIR_OpenExpression (pos, formal->subtype));
	}

      conf_binding = build_BindingIndic (pos, conf_unit, conf_gmap, conf_pmap);
    }

  return conf_binding;
}

pIIR_ComponentInstantiationStatement
psr::build_CompInst (int lineno,
		     pIIR_Identifier label,
		     pIIR_BindingIndication bi)
{
  return build_CompInst (make_posinfo (lineno), label, bi);
}

pIIR_ComponentInstantiationStatement
psr::build_CompInst (pIIR_PosInfo pos,
		     pIIR_Identifier label, 
		     pIIR_BindingIndication bi)
{
  if (bi == NULL)
    return NULL;

  return mIIR_ComponentInstantiationStatement 
         (pos,
	  NULL,
	  bi,
	  find_component_configuration (label, bi));
}

#if 0
void
psr::bind_specs (pIIR_BlockStatement b)
{
  for (pVAUL_ConfigSpec cs = config_specs(b); cs; cs = cs->next)
    {
      if (cs->comps == NULL)
	continue;

      pIIR_ConfigurationSpecification cf =
	mIIR_ConfigurationSpecification(cs->pos, NULL,
					cs->binding->unit,
					cs->binding->generic_assoc,
					cs->binding->port_assoc);
      bound_by_name(cf) = cs->comps->ids->is(VAUL_INST_LIST_IDS);

      add_decl_plain (b, cf);

      for (pIIR_ComponentInstantiationList cil =
	     list_comps (cs->comps, b); cil; cil = cil->rest)
	{
	  if (cil->first && cil->first->configuration_specification)
	    {
	      error ("%:%n is already configured by..", cs, cil->first);
	      info ("%:..this configuration specification",
		    cil->first->configuration_specification);
	    }
	  else if (cil->first)
	    cil->first->configuration_specification = cf;
	}
    }

  // Create default binding indications for the rest.

  
}
#endif

static void
add (pIIR_BlockConfiguration b, pIIR_ConfigurationItemList c)
{
  pIIR_ConfigurationItemList cp;
  for (cp = b->configuration_item_list; cp->rest; cp = cp->rest)
    ;
  cp->rest = c;
}

pIIR_ArchitectureDeclaration
psr::get_architecture (pIIR_EntityDeclaration entity,
		       pIIR_TextLiteral arch)
{
  pIIR_ArchitectureDeclaration arch_decl = NULL;

  vaul_design_unit *du = 
    pool->get_architecture (entity->library_name->text.to_chars (),
			    entity->declarator->text.to_chars (),
			    arch->text.to_chars ());
  if (du == NULL)
    error ("unknown architecture %n(%n)", entity, arch);
  else if (du->is_error())
    error ("%n(%n): %s", entity, arch, du->get_error_desc());
  else if (du->get_tree() == NULL
	   || !du->get_tree()->is(IR_ARCHITECTURE_DECLARATION))
    // "??)" is a trigraph, so we split the string to avoid a warning.
    // Whoever thought of trigraphs should go back to gardening.
    error ("%n(%n) is not an architecture (??""?)", entity, arch);
  else
    {
      use_unit (du);
      arch_decl = pIIR_ArchitectureDeclaration(du->get_tree());
    }
  release_ref(du);
  return arch_decl;
}


pIIR_ArchitectureRef
psr::get_architecture_ref (int lineno, pVAUL_Name en, pIIR_Identifier arch)
{
  assert(en != NULL);

  pIIR_EntityDeclaration entity =
    pIIR_EntityDeclaration(find_single_decl (en, IR_ENTITY_DECLARATION,
					     "entity"));
  if (entity == NULL)
    return NULL;

  return get_architecture_ref (entity, mVAUL_SimpleName(lineno, arch));
}

pIIR_ArchitectureRef
psr::get_architecture_ref (pIIR_EntityDeclaration entity, pVAUL_SimpleName arch)
{
  return mIIR_ArchitectureRef(arch->pos, NULL, entity, arch->id);
}

pIIR_BlockConfiguration
psr::start_BlockConfig (pVAUL_Name n)
{
  assert (cur_scope);

  pIIR_Component block = NULL;
  
  if (!n->is(VAUL_SIMPLE_NAME))
    error ("%:block specification must be a simple name", n);
  else if (cur_scope->is(IR_CONFIGURATION_DECLARATION))
    block = get_architecture (pIIR_ConfigurationDeclaration(cur_scope)->entity,
			      pVAUL_SimpleName(n)->id);
  else if (cur_scope->is(IR_BLOCK_CONFIGURATION))
    block = pIIR_BlockStatement (find_single_decl (n, IR_BLOCK_STATEMENT,
						   "block statement"));
  else if (cur_scope->is(IR_COMPONENT_CONFIGURATION))
    info ("XXX - no block config inside component config, yet");
  
  pIIR_BlockConfiguration bc = mIIR_BlockConfiguration (n->pos, NULL,
							block,
							NULL, NULL);
  bc->continued = block;
  
  if (cur_scope->is(IR_BLOCK_CONFIGURATION))
    add (pIIR_BlockConfiguration(cur_scope),
	 mIIR_ConfigurationItemList (bc->pos, bc, NULL));
  
  add_decl (bc);
  push_scope (bc);
  return bc;
}

static pIIR_ComponentConfiguration
get_CompConfig (pIIR_BlockConfiguration bc,
		pIIR_ComponentInstantiationStatement ci)
{
  for (pIIR_ConfigurationItemList cl = bc->configuration_item_list;
       cl; cl = cl->rest)
    {
      pIIR_ConfigurationItem c = cl->first;
      if (!c->is(IR_COMPONENT_CONFIGURATION))
	continue;
      pIIR_ComponentConfiguration cc = pIIR_ComponentConfiguration(c);
      for (pIIR_ComponentInstantiationList cil = cc->instantiation_list;
	   cil; cil = cil->rest)
	if (cil->first == ci)
	  return cc;
    }

  return NULL;
}

#if 0
static bool
bound_by_name (pIIR_ComponentInstantiationStatement ci,
	       pIIR_BlockConfiguration bc)
{
  pVAUL_ComponentSpec s = NULL;
  if (bc)
    {
      pIIR_ComponentConfiguration cc = get_CompConfig(bc, ci);
      return cc && bound_by_name (cc);
    }
  else
    return (ci->configuration_specification &&
	    bound_by_name (ci->configuration_specification));
}

pIIR_ComponentInstantiationList
psr::list_comps (pVAUL_ComponentSpec c, pIIR_DeclarativeRegion s)
{
  if (c == NULL || c->ids == NULL || s == NULL)
    return NULL;

  pIIR_ComponentInstantiationList l = NULL;

  if (c->ids->is(VAUL_INST_LIST_IDS))
    {
      for (pVAUL_IdList idl = pVAUL_InstList_Ids(c->ids)->ids;
	   idl; idl = idl->link)
	{
	  pVAUL_SimpleName sn = mVAUL_SimpleName (idl->pos, idl->id);
	  pIIR_ComponentInstantiationStatement ci = 
	    pIIR_ComponentInstantiationStatement
	    (find_single_decl(sn, IR_COMPONENT_INSTANTIATION_STATEMENT,
			      "component instantiation"));

	  if (ci && ci->instantiated_unit && c->comp &&
	      ci->instantiated_unit != c->comp)
	    {
	      error ("%:configured unit %n does not match"
		     " instantiated unit %n", idl, c->comp,
		     ci->instantiated_unit);
	    }
	  else
	    l = mIIR_ComponentInstantiationList (ci->pos, ci, l);
	}
    }
  else if (c->ids->is(VAUL_INST_LIST_ALL) || c->ids->is(VAUL_INST_LIST_OTHERS))
    {
      pIIR_Component b;
      pIIR_BlockConfiguration bc;
      if (s->is(IR_BLOCK_CONFIGURATION))
	{
	  bc = pIIR_BlockConfiguration(s);
	  b = bc->block_specification;
	  if (b == NULL)
	    return NULL;
	}
      else if (s->is(IR_BLOCK_STATEMENT))
	{
	  bc = NULL;
	  b = pIIR_BlockStatement(s);
	} 
      else
	return NULL;
      
      for (pIIR_ConcurrentStatementList csl = vaul_get_stats (b);
	   csl; csl = csl->rest) 
	{
	  pIIR_ConcurrentStatement cs = csl->first;
	  if (!cs->is(IR_COMPONENT_INSTANTIATION_STATEMENT))
	    continue;
	  pIIR_ComponentInstantiationStatement ci =
	    pIIR_ComponentInstantiationStatement(cs);
	  if (ci->instantiated_unit == c->comp
	      && !(c->ids->is(VAUL_INST_LIST_OTHERS) && bound_by_name(ci, bc)))
	    l = mIIR_ComponentInstantiationList (ci->pos, ci, l);
	}
    }
  
  return l;
}

static inline pIIR_Component
get_bound_unit (pIIR_ComponentInstantiationStatement ci)
{
  if (ci && ci->configuration_specification)
    return ci->configuration_specification->unit;
  return NULL;
}

pIIR_ComponentConfiguration
psr::start_CompConfig (int lno,
		       pVAUL_ComponentSpec c,
		       pVAUL_IncrementalBindingIndic ib)
{
  // XXX - do lots of checking

  if (c == NULL)
    return NULL;

  pIIR_ComponentConfiguration cc =
    mIIR_ComponentConfiguration (lno, NULL, NULL, 
				 list_comps (c, cur_scope), NULL, NULL, NULL);
  bound_by_name(cc) = c->ids->is(VAUL_INST_LIST_IDS);

  if (ib && ib->unit == NULL)
    {
      for (pIIR_ComponentInstantiationList cil = cc->instantiation_list;
	   cil; cil = cil->rest)
	{
	  pIIR_Component u = get_bound_unit(cil->first);
	  if (u)
	    {
	      if (ib->unit && ib->unit != u)
		info ("XXX - incrementally bound component instantiations"
		      " must all be bound to the same unit");
	      else
		ib->unit = u;
	    }
	}
    }

  if (ib)
    {
      pVAUL_BindingIndic b = build_BindingIndic (ib);
      assert (b->unit->is(IR_LIBRARY_UNIT));
      cc->entity_aspect = pIIR_LibraryUnit(b->unit);
      cc->generic_map_aspect = b->generic_assoc;
      cc->port_map_aspect = b->port_assoc;
    }

  if (cur_scope->is(IR_BLOCK_CONFIGURATION))
    add (pIIR_BlockConfiguration(cur_scope),
	 mIIR_ConfigurationItemList (cc->pos, cc, NULL));

  add_decl (cc);
  push_scope (cc);
  return cc;
}

#endif

pIIR_ComponentConfiguration
psr::start_CompConfig (int lno,
		       pVAUL_ComponentSpec c,
		       pVAUL_IncrementalBindingIndic ib)
{
  pIIR_ComponentConfiguration cc =
    mIIR_ComponentConfiguration (lno, NULL, NULL, 
				 NULL,
				 NULL, NULL, NULL);

  info ("XXX - no component configuration yet");

  if (cur_scope->is(IR_BLOCK_CONFIGURATION))
    add (pIIR_BlockConfiguration(cur_scope),
	 mIIR_ConfigurationItemList (cc->pos, cc, NULL));

  add_decl (cc);
  push_scope (cc);
  return cc;
}

void
psr::check_BlockConfig (pIIR_BlockConfiguration bc)
{
  // see if any component instantiation is bound more than once
  //
  for (pIIR_ConfigurationItemList c = bc->configuration_item_list;
       c; c = c->rest)
    {
      if (!c->is(IR_COMPONENT_CONFIGURATION))
	continue;
      pIIR_ComponentConfiguration cc = pIIR_ComponentConfiguration(c);
      for (pIIR_ComponentInstantiationList cil = cc->instantiation_list;
	   cil; cil = cil->rest)
	{
	  pIIR_ComponentConfiguration cc2 = get_CompConfig(bc, cil->first);
	  if (cc2 != cc)
	    {
	      error("%:%n is already configured by..", cc, cil->first);
	      info("%:..this component configuration", cc2);
	    }
	}
    }
}

void
psr::add_disconnect_spec (pIIR_ExpressionList sl, pVAUL_Name mark,
			  pIIR_Expression after)
{
  pIIR_Type t = get_type (mark);
  overload_resolution (after, std->predef_TIME);

  if (t == NULL || after == NULL)
    return;

  pIIR_Type bt = vaul_get_base (t);

  while (sl)
    {
      if (sl->first)
	{
	  if (vaul_get_base (vaul_get_type (sl->first)) != bt)
	    error ("%:%n does not match type %n", sl->first, sl->first, bt);
	  else
	    {
	      pIIR_ObjectReference s = pIIR_ObjectReference(sl->first);
	      assert (s->is(IR_OBJECT_REFERENCE));
	      pIIR_DisconnectSpecification ds =
		mIIR_DisconnectSpecification (sl->pos, NULL, t, after, s);
	      add_decl_plain (cur_scope, ds);
	    }
	}
      sl = sl->rest;
    }
}

pIIR_InterfaceList
m_vaul_get_generics (pIIR_ComponentDeclaration d)
{
  return d->local_generic_clause;
}

pIIR_InterfaceList
m_vaul_get_generics (pIIR_EntityDeclaration d)
{
  return d->generic_clause;
}

pIIR_InterfaceList
m_vaul_get_generics (pIIR_ArchitectureDeclaration d)
{
  return d->entity? d->entity->generic_clause : NULL;
}

pIIR_InterfaceList
m_vaul_get_generics (pIIR_ArchitectureRef d)
{
  return d->entity? d->entity->generic_clause : NULL;
}

pIIR_InterfaceList
m_vaul_get_generics (pIIR_BlockStatement bs)
{
  return bs->generic_clause;
}

pIIR_InterfaceList
m_vaul_get_ports (pIIR_ComponentDeclaration d)
{
  return d->local_port_clause;
}

pIIR_InterfaceList
m_vaul_get_ports (pIIR_EntityDeclaration d)
{
  return d->port_clause;
}

pIIR_InterfaceList
m_vaul_get_ports (pIIR_ArchitectureDeclaration d)
{
  return d->entity? d->entity->port_clause : NULL;
}

pIIR_InterfaceList
m_vaul_get_ports (pIIR_ArchitectureRef d)
{
  return d->entity? d->entity->port_clause : NULL;
}

pIIR_InterfaceList
m_vaul_get_ports (pIIR_BlockStatement bs)
{
  return bs->port_clause;
}

void
m_vaul_set_generics (pIIR_ComponentDeclaration d, pIIR_InterfaceList generics)
{
  d->local_generic_clause = generics;
}

void
m_vaul_set_generics (pIIR_EntityDeclaration d, pIIR_InterfaceList generics)
{
  d->generic_clause = generics;
}

void
m_vaul_set_generics (pIIR_BlockStatement bs, pIIR_InterfaceList generics)
{
  bs->generic_clause = generics;
}

void
m_vaul_set_ports (pIIR_ComponentDeclaration d, pIIR_InterfaceList ports)
{
  d->local_port_clause = ports;
}

void
m_vaul_set_ports (pIIR_EntityDeclaration d, pIIR_InterfaceList ports)
{
  d->port_clause = ports;
}

void
m_vaul_set_ports (pIIR_BlockStatement bs, pIIR_InterfaceList ports)
{
  bs->port_clause = ports;
}

pIIR_ConcurrentStatementList
m_vaul_get_stats (pIIR_ComponentDeclaration d)
{
  return NULL;
}

pIIR_ConcurrentStatementList
m_vaul_get_stats (pIIR_EntityDeclaration d)
{
  return d->entity_statement_part;
}

pIIR_ConcurrentStatementList
m_vaul_get_stats (pIIR_ArchitectureDeclaration d)
{
  return d->architecture_statement_part;
}

pIIR_ConcurrentStatementList
m_vaul_get_stats (pIIR_BlockStatement bs)
{
  return bs->block_statement_part;
}

pIIR_ConcurrentStatementList
m_vaul_get_stats (pIIR_ConfigurationDeclaration d)
{
  return NULL;
}

pIIR_ConfigurationSpecificationList
m_vaul_get_configuration_specifications (pIIR_ArchitectureDeclaration a)
{
  return a->configuration_specifications;
}

pIIR_ConfigurationSpecificationList
m_vaul_get_configuration_specifications (pIIR_BlockStatement bs)
{
  return bs->configuration_specifications;
}

pIIR_ConfigurationSpecificationList
m_vaul_get_configuration_specifications (pIIR_ConcurrentGenerateStatement gs)
{
  return gs->configuration_specifications;
}

void
m_vaul_set_configuration_specifications (pIIR_ArchitectureDeclaration a,
					 pIIR_ConfigurationSpecificationList l)
{
  a->configuration_specifications = l;
}

void
m_vaul_set_configuration_specifications (pIIR_BlockStatement bs,
					 pIIR_ConfigurationSpecificationList l)
{
  bs->configuration_specifications = l;
}

void
m_vaul_set_configuration_specifications (pIIR_ConcurrentGenerateStatement gs,
					 pIIR_ConfigurationSpecificationList l)
{
  gs->configuration_specifications = l;
}
