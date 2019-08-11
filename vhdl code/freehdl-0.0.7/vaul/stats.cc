/* statements

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

pIIR_ProcedureCallStatement
psr::build_ProcedureCallStat (int lineno, pVAUL_Name name)
{
  pIIR_Expression e = build_Expr (name);
  overload_resolution (e, NULL, VAUL_VOID_TYPE, true, true);
  if (e && e->is(VAUL_PROCEDURE_CALL))
    return mIIR_ProcedureCallStatement (lineno, pVAUL_ProcedureCall(e)->proc,
					pVAUL_ProcedureCall(e)->actuals);
  else
    {
      if (e)
	error("%:%n is not a procedure call", name, name);
      return NULL;
    }
}

pIIR_ConstantDeclaration
psr::fix_for_scheme (pVAUL_ForScheme pfs)
{
  // XXX - merge this with build_IndexConstraint

  pIIR_Range range = NULL;
  pIIR_Type type = NULL;
  pIIR_Subtype subtype = NULL;

  if (pfs->range == NULL)
    ;
  else if (pfs->range->is(VAUL_PRE_INDEX_RANGE_CONSTRAINT)) 
    {
      if ((range = pVAUL_PreIndexRangeConstraint(pfs->range)->range) != NULL)
	{
	  if (range->is(IR_EXPLICIT_RANGE)) 
	    {
	      pIIR_ExplicitRange er = pIIR_ExplicitRange(range);
	      if ((type = find_index_range_type(er)) != NULL)
		{
		  overload_resolution (er->left, type);
		  overload_resolution (er->right, type);
		  subtype = mIIR_ScalarSubtype (pfs->pos, type->base, type,
						NULL, range);
		}
	    }
	  else if (range->is(IR_ARRAY_RANGE))
	    {
	      type = pIIR_ArrayRange(range)->type;
	      subtype = mIIR_ScalarSubtype (pfs->pos, type->base, type,
					    NULL, range);
	    }
	  else
	    assert (false);
	}
    }
  else if (pfs->range->is(VAUL_PRE_INDEX_SUBTYPE_CONSTRAINT)) 
    {
      type = pVAUL_PreIndexSubtypeConstraint(pfs->range)->type;
      if (!is_discrete_type(type))
	error ("%n is not a discrete type", type);
      else if (type)
	{
	  if (type->is(IR_SCALAR_SUBTYPE)
	      && pIIR_ScalarSubtype(type)->range->is(IR_RANGE))
	    subtype = pIIR_ScalarSubtype (type);
	  else 
	    {
	      range = get_scalar_type_range (type);
	      subtype = mIIR_ScalarSubtype (pfs->pos, type->base, type,
					    NULL, range);
	    }
	}
    }
  else
    vaul_fatal ("fix_for_scheme confused.\n");

  return mIIR_ConstantDeclaration (pfs->pos, pfs->var, subtype, NULL);
}

pIIR_LoopStatement
psr::push_loop (int lineno, pIIR_Label label, pVAUL_IterationScheme scheme)
{
  pIIR_LoopDeclarativeRegion region = pIIR_LoopDeclarativeRegion (
    add_decl(cur_scope, mIIR_LoopDeclarativeRegion (lineno, NULL, NULL)));
  push_scope(region);
  
  pIIR_LoopStatement st = NULL;

  if (scheme == NULL)
    st = mIIR_LoopStatement (lineno, NULL, region);
  else if (scheme->is(VAUL_WHILE_SCHEME))
    st = mIIR_WhileLoopStatement (lineno, NULL, region,
				  pVAUL_WhileScheme(scheme)->condition);
  else if (scheme->is(VAUL_FOR_SCHEME))
    {
      pIIR_ConstantDeclaration c = fix_for_scheme (pVAUL_ForScheme (scheme));
      add_decl (cur_scope, c);
      st = mIIR_ForLoopStatement (lineno, NULL, region, c);
    }

  region->loop_statement = st;
  st->declarative_region = region;
  st->label = label;
  if (label)
    label->statement = st;
  return st;
}

pIIR_LoopStatement
psr::pop_loop (pIIR_SequentialStatementList stats, pIIR_Identifier id)
{
  if (cur_scope && !cur_scope->is(IR_LOOP_DECLARATIVE_REGION))
    {
      info ("confusion, expect failure");
      while (cur_scope && !cur_scope->is(IR_LOOP_DECLARATIVE_REGION))
	pop_scope (cur_scope);
    }

  if (cur_scope == NULL)
    return NULL;
  
  assert (cur_scope && cur_scope->is(IR_LOOP_DECLARATIVE_REGION));
    
  pIIR_LoopDeclarativeRegion region = pIIR_LoopDeclarativeRegion(cur_scope);
  pop_scope (region);
  
  if (region->loop_statement == NULL)
    return NULL;
  
  if (id)
    {
      pIIR_Label l = region->loop_statement->label;
      if (l && !vaul_name_eq (l->declarator, id))
	error("%n does not match loop label %n", id, l->declarator);
      else if (l == NULL)
	error ("loop has no label");
    }
  region->loop_statement->sequence_of_statements = stats;

  return region->loop_statement;
}

pIIR_ConcurrentGenerateStatement
psr::push_GenerateStat (int lineno, pVAUL_IterationScheme scheme)
{
  pIIR_ConcurrentGenerateStatement g = NULL;

  if (scheme->is(VAUL_FOR_SCHEME))
    {
      pIIR_ConstantDeclaration loop_var =
	fix_for_scheme (pVAUL_ForScheme(scheme));
      g = mIIR_ConcurrentGenerateForStatement (lineno, NULL, NULL, loop_var);
      add_decl (g, loop_var);
    }
  else if (scheme->is(VAUL_IF_SCHEME))
    {
      pIIR_Expression cond = pVAUL_IfScheme(scheme)->condition;
      g = mIIR_ConcurrentGenerateIfStatement (lineno, NULL, NULL, cond);
    }
    
  add_decl (cur_scope, g);
  push_scope (g);

  return g;
}

void
psr::add_to_signal_list (pIIR_ExpressionList &sigs, pIIR_ObjectReference sig)
{
  pIIR_ExpressionList *slp;
  for (slp = &sigs; *slp; slp = &(*slp)->rest)
    if ((*slp)->first == sig)  // XXX - does this really work?
      return;
  *slp = mIIR_ExpressionList ((IIR_PosInfo *)NULL, sig, *slp);
}

void
psr::get_implicit_signals (pIIR_ExpressionList &sigs, pIIR_Expression e)
{
  if (e == NULL)
    return;
  
  if (e->is(IR_FUNCTION_CALL)) 
    {
      for (pIIR_AssociationList al =
	     pIIR_FunctionCall(e)->parameter_association_list;
	   al; al = al->rest)
	if (al->first)
	  get_implicit_signals (sigs, al->first->actual);
    }
  else if (e->is(IR_TYPE_CONVERSION))
    get_implicit_signals (sigs, pIIR_TypeConversion(e)->expression);
  else if (e->is(IR_QUALIFIED_EXPRESSION))
    get_implicit_signals (sigs, pIIR_QualifiedExpression(e)->expression);
  else if (e->is(IR_OBJECT_REFERENCE))
    {
      pIIR_ObjectReference mor = pIIR_ObjectReference(e);
      if (is_signal (mor))
	add_to_signal_list (sigs, mor);
    }
  else if (e->is(IR_ATTR_SIG_FUNC))
    add_to_signal_list (sigs, pIIR_AttrSigFunc(e)->signal);
  else if (e->is(IR_ENUM_LITERAL_REFERENCE)
	   || e->is(IR_ABSTRACT_LITERAL_EXPRESSION)
	   || e->is(IR_ARRAY_LITERAL_EXPRESSION))
    {
      // ignore
    }
  else if (e->is(IR_ATTR_ARRAY_FUNC)) 
    {
      if (pIIR_AttrArrayFunc(e)->array)
	get_implicit_signals (sigs, pIIR_AttrArrayFunc(e)->array);
    }
  else if (e->is(IR_ARRAY_AGGREGATE))
    {
      for (pIIR_IndexedAssociationList l =
	     pIIR_ArrayAggregate (e)->indexed_association_list;
	   l; l = l->rest)
	get_implicit_signals (sigs, l->first->value);
    }
  else
    info ("xxx - %s not scanned for implicit signals", e->kind_name());
}

pIIR_ProcessStatement
psr::build_Process (int lineno, pIIR_ExpressionList sensitivities, bool pp)
{
  if (sensitivities == no_sens_list)
    return mIIR_ProcessStatement (lineno, NULL, pp, NULL);
  else
    return mIIR_SensitizedProcessStatement (lineno, NULL, pp, NULL,
					    sensitivities);
}

pIIR_ProcessStatement
psr::build_condal_Process (pIIR_Identifier l,
			   bool pp, pVAUL_CondalSignalAssign csa)
{
  if (csa == NULL || csa->target == NULL || csa->wave == NULL)
    return NULL;

  pIIR_ExpressionList sens = NULL;

  pIIR_SequentialStatementList stats = NULL, *statp = &stats;
  for (pVAUL_CondalWaveform cw = csa->wave; cw; cw = cw->else_wave) 
    {
      pIIR_SignalAssignmentStatement ass = build_SignalAssignment (cw->pos,
								   csa->target,
								   csa->delay,
								   cw->wave);
      if (ass)
	{
	  for (pIIR_WaveformList wfl = ass->waveform; wfl; wfl = wfl->rest)
	    if (wfl->first)
	      get_implicit_signals (sens, wfl->first->value);
	}
      if (cw->condition) 
	{
	  get_implicit_signals (sens, cw->condition);
	  pIIR_IfStatement s =
	    mIIR_IfStatement (cw->pos, cw->condition,
			      mIIR_SequentialStatementList (ass->pos,
							    ass,
							    NULL),
			      NULL);
	  *statp = mIIR_SequentialStatementList (cw->pos, s, NULL);
	  statp = &s->else_sequence;
	}
      else
	{
	  *statp = mIIR_SequentialStatementList (cw->pos, ass, NULL);
	  break;
	}
    }

  if (stats)
    stats->rest = mIIR_SequentialStatementList (csa->pos,
						mIIR_WaitStatement (csa->pos,
								    NULL, 
								    NULL,
								    sens),
						NULL);

  pIIR_ImplicitProcessStatement p = mIIR_ImplicitProcessStatement (csa->pos, l, pp, stats);
  if (csa->guarded)
    p->guarded = true;
  // p->orig_statement = csa;
  add_decl (p);
  return p;
}

pIIR_ProcessStatement
psr::build_sel_Process (pIIR_Identifier l,
			bool pp, pVAUL_SelSignalAssign ssa)
{
  if (ssa == NULL || ssa->target == NULL || ssa->wave == NULL)
    return NULL;
  
  pIIR_ExpressionList sens = NULL;

  pIIR_CaseStatementAlternativeList ca = NULL;
  for (pVAUL_SelWaveform sw = ssa->wave; sw; sw = sw->next_wave)
    {
      pIIR_SignalAssignmentStatement ass = build_SignalAssignment (sw->pos,
								   ssa->target,
								   ssa->delay,
								   sw->wave);
      if (ass)
	for(pIIR_WaveformList wfl = ass->waveform; wfl; wfl = wfl->rest)
	  if (wfl->first)
	    get_implicit_signals (sens, wfl->first->value);
      pIIR_CaseStatementAlternative a =
	mIIR_CaseStatementAlternative (sw->pos, 
				       mIIR_SequentialStatementList (ass->pos,
								     ass,
								     NULL),
				       sw->choice);
      ca = mIIR_CaseStatementAlternativeList (sw->pos, a, ca);
    }

  pIIR_CaseStatement stat = build_CaseStat (ssa->pos, ssa->value, ca);
  if (stat)
    get_implicit_signals (sens, stat->expression);
  else
    return NULL;

  pIIR_SequentialStatementList stats =
    mIIR_SequentialStatementList (stat->pos, stat, NULL);
  stats->rest =
    mIIR_SequentialStatementList (ssa->pos,
				  mIIR_WaitStatement (ssa->pos,
						      NULL,
						      NULL,
						      sens),
				  NULL);

  pIIR_ImplicitProcessStatement p = mIIR_ImplicitProcessStatement (ssa->pos, l, pp, stats);
  if (ssa->guarded)
    p->guarded = true;
  // p->orig_statement = ssa;
  add_decl (p);
  return p;
}

pIIR_ProcessStatement
psr::build_conc_AssertStat (int lno, pIIR_Identifier label,
			    bool pp, pIIR_AssertionStatement as)
{
  if (as == NULL)
    return NULL;

  pIIR_ExpressionList sens = NULL;
  get_implicit_signals (sens, as->assertion_condition);

  pIIR_SequentialStatementList stats =
    mIIR_SequentialStatementList (as->pos, as, NULL);
  stats->rest =
    mIIR_SequentialStatementList (lno,
				  mIIR_WaitStatement (lno,
						      NULL,
						      NULL,
						      sens),
				  NULL);

  pIIR_ImplicitProcessStatement p = mIIR_ImplicitProcessStatement (lno, label, pp, stats);
  // p->orig_statement = as;
  add_decl (p);
  return p;
}

pIIR_ProcessStatement
psr::build_conc_ProcedureCall (int lno, pIIR_Identifier label,
			       bool pp, pIIR_ProcedureCallStatement pcs)
{
  if (pcs == NULL)
    return NULL;

  pIIR_ExpressionList sens = NULL;
  for (pIIR_AssociationList al = pcs->actual_parameter_part; al; al = al->rest)
    if (al->first)
      get_implicit_signals (sens, al->first->actual);
  
  pIIR_SequentialStatementList stats =
    mIIR_SequentialStatementList (pcs->pos, pcs, NULL);
  stats->rest =
    mIIR_SequentialStatementList (lno,
				  mIIR_WaitStatement (lno,
						      NULL,
						      NULL,
						      sens),
				  NULL);

  pIIR_ImplicitProcessStatement p = mIIR_ImplicitProcessStatement (lno, label, pp,
								   stats);
  // p->orig_statement = pcs;
  add_decl (p);
  return p;
}

pIIR_ConcurrentStatement
psr::build_conc_ProcedureCall_or_ComponentInst (int pos,
						pIIR_Identifier label,
						pVAUL_Name mark)
{
  pIIR_Declaration decl = find_single_decl (mark, IR_DECLARATION, NULL);
  if (decl == NULL)
    return NULL;

  // XXX - what if there is both a procedure and component in scope?
  
  if (decl->is(IR_SUBPROGRAM_DECLARATION))
    {
      // This is really a procedure call without arguments
      pIIR_ProcedureCallStatement pcs = build_ProcedureCallStat (pos, mark);
      return build_conc_ProcedureCall (pos, label, false, pcs);
    }

  pIIR_ComponentDeclaration c =
    pIIR_ComponentDeclaration (find_single_decl (mark,
						 IR_COMPONENT_DECLARATION,
						 "component"));

  pIIR_BindingIndication bi = build_BindingIndic (make_posinfo (pos),
						  c, NULL, NULL);
  pIIR_ConcurrentStatement cs = build_CompInst (pos, label, bi);
  add_decl (cs);
  return cs;
}

pIIR_LoopControlStatement
psr::build_LoopControlStat (int pos, IR_Kind k,
			    pIIR_Identifier loop, pIIR_Expression when)
{
  pIIR_LoopControlStatement lcs = NULL;
  
  pIIR_LoopDeclarativeRegion sc = NULL;
  if (loop)
    {
      pIIR_Label l = pIIR_Label(find_single_decl (mVAUL_SimpleName (pos, loop), 
						  IR_LABEL, "label"));
      if (l && l->statement)
	{
	  if (l->statement->is(IR_LOOP_STATEMENT))
	    sc = pIIR_LoopStatement(l->statement)->declarative_region;
	  else
	    error ("%n is not a loop statement", loop);
	}
    }
  
  pIIR_DeclarativeRegion s = cur_scope;
  while (s && (!s->is(IR_LOOP_DECLARATIVE_REGION) || (sc && s != sc)))
    s = s->declarative_region;

  if (s == NULL)
    {
      error(loop? "%s statement is not in loop labeled `%n'"
	        : "%s statement outside of loop", 
	    (k == IR_NEXT_STATEMENT)? "next" : "exit", loop);
    }
  else
    {
      assert (s->is(IR_LOOP_DECLARATIVE_REGION));
      pIIR_LoopStatement l = pIIR_LoopDeclarativeRegion(s)->loop_statement;
      /*
      lcs = ((k == IR_NEXT_STATEMENT)?
	     mIIR_NextStatement (pos, l, when) :
	     mIIR_ExitStatement (pos, l, when));
	     */
      if(k == IR_NEXT_STATEMENT)
	lcs = mIIR_NextStatement (pos, l, when);
      else
	lcs = mIIR_ExitStatement (pos, l, when);
    }

  return lcs;
}

bool
psr::check_target (pIIR_Expression t, VAUL_ObjectClass oc,
		   const char *oc_label)
{
  if (t == NULL)
    return true;

  if (t->is(IR_RECORD_AGGREGATE))
    {
      pIIR_RecordAggregate ra = pIIR_RecordAggregate(t);
      for (pIIR_ElementAssociationList al = ra->element_association_list;
	   al; al = al->rest)
	{
	  if (al->first && !check_target (al->first->value, oc, oc_label))
	    return false;
	}
      return true;
    }
  else if (t->is(IR_ARRAY_AGGREGATE))
    {
      pIIR_ArrayAggregate aa = pIIR_ArrayAggregate(t);
      for (pIIR_IndexedAssociationList al = aa->indexed_association_list;
	   al; al = al->rest)
	{
	  if (al->first && !check_target(al->first->value, oc, oc_label))
	    return false;
	}
      return true;
    }
  
  if (!t->is(IR_OBJECT_REFERENCE)
      || vaul_get_class (pIIR_ObjectReference(t)) != oc)
    {
      error ("%:%n is not a %s", t, t, oc_label);
      return false;
    }

  check_for_update (t);

  return true;
}
	

pIIR_VariableAssignmentStatement
psr::build_VarAssignment (int pos, pIIR_Expression t, pIIR_Expression v)
{
  if (t == NULL || v == NULL)
    return NULL;

  if (t->is(VAUL_AMBG_AGGREGATE)) 
    {
      overload_resolution (v, IR_COMPOSITE_TYPE);
      if (v == NULL)
	return NULL;
      pIIR_Type vt = expr_type (v);
      overload_resolution_not_for_read (t, vt);
    }
  else if (t->is(IR_OBJECT_REFERENCE))
    overload_resolution (v, vaul_get_type (pIIR_ObjectReference(t)));
  else
    return NULL;

  if (check_target(t, VAUL_ObjClass_Variable, "variable"))
    return mIIR_VariableAssignmentStatement (pos, t, v);
  else
    return NULL;
}

pIIR_SignalAssignmentStatement
psr::build_SignalAssignment (pIIR_PosInfo pos,
			    pIIR_Expression t,
			    pVAUL_DelayMechanism delay,
			    pIIR_WaveformList wf)
{
  if (t == NULL || wf == NULL)
    return NULL;

  if (t->is(VAUL_AMBG_AGGREGATE))
    {
      bool all_composite = true;
      for (pIIR_WaveformList wl = wf; wl; wl = wl->rest) 
	{
	  pIIR_WaveformElement we = wl->first;
	  if (we)
	    {
	      overload_resolution (we->value, IR_COMPOSITE_TYPE);
	      if (we->value == NULL)
		all_composite = false;
	    }
	}
      if (!all_composite)
	return NULL;

      pIIR_Type comp_type = NULL;
      bool ct_valid = true;
      for (pIIR_WaveformList _wl = wf; _wl; _wl = _wl->rest)
	{
	  pIIR_Type t = expr_type(_wl->first->value);
	  if(t && comp_type != t && comp_type != NULL)
	    ct_valid = false;
	  else
	    comp_type = t;
	}
      if (!ct_valid) 
	{
	  error ("the types of all waveform elements must be the same");
	  info ("they are, in order:");
	  for (pIIR_WaveformList wl = wf; wl; wl = wl->rest)
	    {
	      pIIR_Type t = expr_type (wl->first->value);
	      info ("%: %n", t, t);
	    }
	  return NULL;
	}

      overload_resolution_not_for_read (t, comp_type);

    }
  else if (t->is(IR_OBJECT_REFERENCE))
    {
      pIIR_Type type = vaul_get_type (pIIR_ObjectReference(t));
      for (pIIR_WaveformList wl = wf; wl; wl = wl->rest)
	if (wl->first)
	  overload_resolution (wl->first->value, type);
    }
  else 
    {
      error ("%:%n can not be a target", t, t);
      return NULL;
    }

  if (check_target(t, VAUL_ObjClass_Signal, "signal"))
    {
      pIIR_SignalAssignmentStatement s;
      if (delay && delay->is(VAUL_DELAY_INERTIAL))
	s = mIIR_SignalAssignmentStatement (pos, t,
					    IR_INERTIAL_DELAY,
					    (pVAUL_DelayInertial(delay)
					     ->rejection_time),
					    wf);
      else
	s = mIIR_SignalAssignmentStatement (pos, t, IR_TRANSPORT_DELAY, NULL,
					    wf);
      return s;
    }
  else
    return NULL;
}

static bool
is_character_type (pIIR_Type t)
{
  if (t == NULL || (t = vaul_get_base (t)) == NULL)
    return false;
  
  if (!t->is(IR_ENUMERATION_TYPE))
    return false;

  pIIR_EnumerationType et = pIIR_EnumerationType(t);
  for (pIIR_EnumerationLiteralList el = 
	 pIIR_EnumerationType(t)->enumeration_literals;
       el; el = el->rest)
    if (el->first && el->first->declarator &&
	el->first->declarator->is(IR_CHARACTER_LITERAL))
      return true;
  return false;
}

static bool possible_switch_expr_type(pIIR_Type t)
{
    if(t == NULL)
	return false;
    pIIR_Type bt = vaul_get_base (t);

    if(bt->is(IR_SCALAR_TYPE) ||
       bt->is(IR_ENUMERATION_TYPE))
	return true;
    if(!bt->is(IR_ARRAY_TYPE))
	return false;

    pIIR_ArrayType at = pIIR_ArrayType(bt);
    if(!at->index_types || at->index_types->rest)
	return false;
    return is_character_type(at->element_type);
}

pIIR_CaseStatement
psr::build_CaseStat (pIIR_PosInfo pos, pIIR_Expression swex,
		     pIIR_CaseStatementAlternativeList alts)
{
  if (swex == NULL)
    return NULL;
  
  pIIR_Type_vector *swex_types = ambg_expr_types (swex);
  assert (swex_types);
  
  if (swex_types->size() == 0)
    return NULL;

  bool valid_type = true;
  pIIR_Type swex_type = NULL;
  for (int i = 0; i < swex_types->size(); i++)
    if (possible_switch_expr_type((*swex_types)[i])) 
      {
	if (swex_type)
	  valid_type = false;
	swex_type = (*swex_types)[i];
      }

  if (!valid_type) 
    {
      error ("%:type of case expression is ambigous, it could be:", swex);
      for (int i = 0; i < swex_types->size(); i++)
	if (possible_switch_expr_type((*swex_types)[i]))
	  info ("%:    %n", (*swex_types)[i], (*swex_types)[i]);
      return NULL;
    }

  if (swex_type == NULL) 
    {
      error ("%:type of case expression is invalid, it could be:", swex);
      for (int i = 0; i < swex_types->size(); i++)
	info ("%:    %n", (*swex_types)[i], (*swex_types)[i]);
      return NULL;
    }

  if (swex->subtype->declaration == NULL)
    {
      swex_type = get_type(mVAUL_SimpleName(pos, make_id("integer")));
      //pVAUL_SelName sn = mVAUL_SelName(pos, mVAUL_SimpleName(pos, make_id("std")),
      //			       make_id("standard"));
      //pIIR_Declaration spack = find_single_decl (sn, VAUL_STANDARD_PACKAGE, "(the) standard package");
      //vaul_decl_set ds(this);
      //find_decls (ds, mVAUL_SimpleName(pos, make_id("integer")), spack, true);
      swex->subtype = swex_type;
    }

  delete swex_types;

  overload_resolution (swex, swex_type);
  for (pIIR_CaseStatementAlternativeList al = alts; al; al = al->rest)
    {
      pIIR_CaseStatementAlternative a = al->first;
      for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest)
	{
	  pIIR_Choice c = cl->first;
	  if (c->is(IR_CHOICE_BY_EXPRESSION))
	    overload_resolution (pIIR_ChoiceByExpression(c)->value, swex_type);
	  else if (c->is(IR_CHOICE_BY_RANGE))
	    {
#if 1
	      pIIR_Range range = pIIR_ChoiceByRange(c)->range;
	      ensure_range_type (range, swex_type);
#else
#endif
	    }
	  else if (c->is(IR_CHOICE_BY_OTHERS))
	      ;
	  else
	    info ("XXX - no `%s' choices", c->kind_name());
	}
    }

  return mIIR_CaseStatement(pos, swex, alts);
}

void
psr::push_concurrent_stats_tail (pIIR_ConcurrentStatementList *pl)
{
  cstat_item *i = new cstat_item;
  i->tail = i->start_tail = pl;
  i->prev = cstat_tail;
  i->context = cur_scope;
  cstat_tail = i;

  if (consumer)
    consumer->push_conc_context (i->context);
}

void
psr::pop_concurrent_stats_tail (pIIR_ConcurrentStatementList *pl)
{
  assert (cstat_tail && cstat_tail->start_tail == pl);

  cstat_item *i = cstat_tail;
  cstat_tail = i->prev;
  delete i;

  if (consumer)
    consumer->pop_conc_context (cstat_tail? cstat_tail->context : NULL);
}

void
psr::add_to_concurrent_stats_tail (pIIR_ConcurrentStatement s)
{
  assert (cstat_tail && cstat_tail->tail);
  
  if (s == NULL)
    return;

  if (consumer)
    {
      if (!consumer->consume_conc_stat (s))
	{
	  rem_decl (s->declarative_region, s);
	  return;
	}
    }
      
  pIIR_ConcurrentStatementList l =
    mIIR_ConcurrentStatementList (s->pos, s, NULL);
  *cstat_tail->tail = l;
  cstat_tail->tail = &l->rest;
}

vaul_consumer::vaul_consumer ()
{
}

vaul_consumer::~vaul_consumer ()
{
}

void
vaul_consumer::push_conc_context (pIIR_DeclarativeRegion context)
{
}

bool
vaul_consumer::consume_conc_stat (pIIR_ConcurrentStatement stat)
{
  return true;
}

void
vaul_consumer::pop_conc_context (pIIR_DeclarativeRegion context)
{
}

bool
vaul_consumer::consume_pbody_decl (pIIR_Declaration decl)
{
  return true;
}
