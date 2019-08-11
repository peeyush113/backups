#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif
#if HAVE_UNISTD_H
#include <unistd.h>
#endif

#include <freehdl/vaul.h>
#include "v2cc-chunk.h"
#include "mapping.h"
#include "v2cc-util.h"


void
cdfg_emit_subprogram_associations (string &str, RegionStack &rstack, pIIR_AssociationList assocs, 
				   pIIR_InterfaceList formals)
{
  string separator = "";

  // ****************************************************************************
  // Add normal subprogram parameter
  // ****************************************************************************
  for (pIIR_InterfaceList fl = formals; fl; fl = fl->rest) {
    pIIR_InterfaceDeclaration par = fl->first; // select formal parameter
    
    /* Select association element from an association list which
     * corresponds with given formal */
    list<pIIR_AssociationElement> a_list = find_matching_actuals(assocs, par); 
    assert (a_list.size() <= 1); // Only simple assoication is currently supported here!
    pIIR_AssociationElement a = a_list.size() == 0? NULL : a_list.front();
    
    str += separator;
    
    if (a != NULL && !a->actual->is(IR_OPEN_EXPRESSION)) {
      // An actual is associated with the formal
      if (a->formal_conversion)  {
	str += "/* converted by ";
	get_long_name(a->formal_conversion);
	str += " */";
      }

      // *******************************************************
      // Handle signal parameter
      // *******************************************************
      if (par->is(IR_SIGNAL_INTERFACE_DECLARATION)) {
	// First, append sig_info pointer
	cdfg_emit_expr (a->actual, str, rstack, SIGNAL);
	
      } else
	// *******************************************************
	// Handle normal parameter (non signal)
	// *******************************************************
	cdfg_emit_expr (a->actual, str, rstack, id_type(READER, DEREF));
      
    } else if (par->initial_value != NULL)
      // If the parameter was left open then insert the default
      // value if one is defined in the interface declaration
      cdfg_emit_expr (par->initial_value, str, rstack, DEFAULT);
    
    else 
      // If no default value is defined for the formal then create a
      // dummy instance of the appropriate type
      str += cdfg_create_default_instance(par->subtype, rstack);
    
    
    separator = " ";
  }
  
}



/*
 * Simulation Object Implementation
 */

void
m_cdfg_emit_impl (pIIR_ArrayType at, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_ArraySubtype ast, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_ScalarSubtype sst, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}
  

void
m_cdfg_emit_impl (pIIR_EnumerationType et, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_AccessType at, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_FileType ft, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_EntityDeclaration e, string &str, RegionStack &rstack, int l)
{
  rstack.push(e);

  list<pIIR_Declaration> subprograms = 
    filter_unique(extended_declarations(e),
		  tree_kind_list() << 
		  IR_PROCEDURE_DECLARATION <<
		  IR_FUNCTION_DECLARATION
		  );
  for (list<pIIR_Declaration>::iterator i = subprograms.begin(); i != subprograms.end(); i++)
    cdfg_emit_impl((*i), str, rstack, l);
  
  if (e->entity_statement_part != NULL)
    cdfg_emit_impl(e->entity_statement_part, str, rstack, l);

  rstack.pop();
}


void
m_cdfg_emit_impl (pIIR_ArchitectureDeclaration a, string &str, RegionStack &rstack, int l)
{
  rstack.push(a);

  list<pIIR_Declaration> subprograms = 
    filter_unique(extended_declarations(a),
		  tree_kind_list() << 
		  IR_PROCEDURE_DECLARATION <<
		  IR_FUNCTION_DECLARATION
		  );
  for (list<pIIR_Declaration>::iterator i = subprograms.begin(); i != subprograms.end(); i++)
    cdfg_emit_impl((*i), str, rstack, l);
  
  if (a->architecture_statement_part != NULL)
    cdfg_emit_impl(a->architecture_statement_part, str, rstack, l);

  rstack.pop();
}

void										
m_cdfg_emit_impl (pIIR_ConcurrentGenerateStatement gs, string &str, RegionStack &rstack, int l)
{ 
  rstack.push(gs);
  
  list<pIIR_Declaration> subprograms = 
    filter_unique(extended_declarations(gs),
		  tree_kind_list() << 
		  IR_PROCEDURE_DECLARATION <<
		  IR_FUNCTION_DECLARATION
		  );
  for (list<pIIR_Declaration>::iterator i = subprograms.begin(); i != subprograms.end(); i++)
    cdfg_emit_impl((*i), str, rstack, l);
  
  if (gs->concurrent_statement_part != NULL)
    cdfg_emit_impl(gs->concurrent_statement_part, str, rstack, 2);

  rstack.pop();
}


void
m_cdfg_emit_impl (pIIR_PackageBodyDeclaration pb, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_PackageDeclaration p, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}


void
m_cdfg_emit_impl (pIIR_ConcurrentStatementList s, string &str, RegionStack &rstack, int l)
{
  while (s)
    {
      cdfg_emit_impl (s->first, str, rstack, l);
      s = s->rest;
    }
}


void
m_cdfg_emit_impl (pIIR_ProcessStatement p, string &str, RegionStack &rstack, int l)
{
  rstack.push(p);
  ContextInfo &ctxt = *ActiveContext(rstack);

  str += "(define-process " + get_escaped_string(get_long_name(p), ":\"\\()") + " (current-scope process-name)\n";

  // Filter all signals, variables and constants that are accessed
  // (read, write or sensitive) within the process code
  list<AccessDescriptor> objects = 
    filter_unique(ctxt.accessed_objects, ACCESS,    
		  tree_kind_list() << 
		  IR_SIGNAL_DECLARATION << 
		  IR_SIGNAL_INTERFACE_DECLARATION <<
		  IR_CONSTANT_DECLARATION <<
		  IR_CONSTANT_INTERFACE_DECLARATION <<
		  IR_VARIABLE_DECLARATION <<
		  IR_SHARED_VARIABLE_DECLARATION
		  );
  // Mapp all objects which are used within the process
  if (objects.begin() != objects.end()) {
    str += spaces(4) + "(let* (\n";
    for (list<AccessDescriptor>::iterator i = objects.begin(); i != objects.end(); i++)
      str += spaces(7) + "(" + qid((*i).declaration, rstack, id_type(DEFAULT, NO_PREFIX)) + 
	" (map-object current-scope process-name " + 
	+ "\"" + get_escaped_string(get_long_name((*i).declaration)) + "\"))\n";
    str += spaces(7) + ")\n";
  }

  str += spaces(6) + "(create-process-statements current-scope process-name)\n";

  list<pIIR_Declaration> subprograms = 
    filter_unique(extended_declarations(p),
		  tree_kind_list() << 
		  IR_PROCEDURE_DECLARATION <<
		  IR_FUNCTION_DECLARATION
		  );
  for (list<pIIR_Declaration>::iterator i = subprograms.begin(); i != subprograms.end(); i++)
    cdfg_emit_impl((*i), str, rstack, 6);
  
  // emit sequential statements
  if (p->process_statement_part != NULL)
    cdfg_emit_impl(p->process_statement_part, str, rstack, 6);

  str += spaces(6) + "(create-end-process-statements)\n";

  str += spaces(4) + ")\n";

  str += ")\n";

  // Remove context from context stack
  rstack.pop();
}


// Print subprogram implementation
void
m_cdfg_emit_impl (pIIR_SubprogramDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  rstack.push(sbp);
  ContextInfo &ctxt = *ActiveContext(rstack);

  str += spaces(l) + "(define-procedure " + get_escaped_string(get_long_name(sbp), ":\"\\()") + " (current-scope procedure-name)\n";

  // Filter all signals, variables and constants that are accessed
  // (read, write or sensitive) within the process code
  list<AccessDescriptor> objects = 
    filter_unique(ctxt.accessed_objects, ACCESS,    
		  tree_kind_list() << 
		  IR_SIGNAL_DECLARATION << 
		  IR_SIGNAL_INTERFACE_DECLARATION <<
		  IR_CONSTANT_DECLARATION <<
		  IR_CONSTANT_INTERFACE_DECLARATION <<
		  IR_VARIABLE_DECLARATION <<
		  IR_SHARED_VARIABLE_DECLARATION);
  // Mapp all objects which are used within the process
  if (objects.begin() != objects.end()) {
    str += spaces(l+4) + "(let* (\n";
    for (list<AccessDescriptor>::iterator i = objects.begin(); i != objects.end(); i++)
      str += spaces(l+7) + "(" + qid((*i).declaration, rstack, id_type(DEFAULT, NO_PREFIX)) + 
	" (map-object current-scope procedure-name " + 
	+ "\"" + get_escaped_string(get_long_name((*i).declaration)) + "\"))\n";
    str += spaces(l+7) + ")\n";
  }

  str += spaces(l+6) + "(create-procedure-statements procedure-name)\n";

  list<pIIR_Declaration> subprograms = 
    filter_unique(extended_declarations(sbp),
		  tree_kind_list() << 
		  IR_PROCEDURE_DECLARATION <<
		  IR_FUNCTION_DECLARATION
		  );
  for (list<pIIR_Declaration>::iterator i = subprograms.begin(); i != subprograms.end(); i++)
    cdfg_emit_impl((*i), str, rstack, 6);

  // emit sequential statements
  if (sbp->subprogram_body != NULL)
    cdfg_emit_impl(sbp->subprogram_body, str, rstack, l+6);

  str += spaces(l+6) + "(create-end-procedure-statements)\n";

  str += spaces(l+4) + ")\n";

  str += spaces(l) + ")\n";

  // Remove context from context stack
  rstack.pop();
}


// Print subprogram implementation
void
m_cdfg_emit_impl (pIIR_PredefinedFunctionDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // Nothing to do.
}


// Print subprogram implementation
void
m_cdfg_emit_impl (pIIR_PredefinedProcedureDeclaration sbp, string &str, RegionStack &rstack, int l)
{
  // Nothing to do.
}


void                                                            // SeqStatList impl
m_cdfg_emit_impl (pIIR_SequentialStatementList sl, string &str, RegionStack &rstack, int l)	
{
  while (sl)
    {
      pIIR_SequentialStatement s = sl->first;
      
      cdfg_emit_impl (s, str, rstack, l);
      sl = sl->rest;
    }
}


void
m_cdfg_emit_impl (pIIR_NullStatement, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-null-statement)\n";
}


void
m_cdfg_emit_impl (pIIR_ReturnStatement r, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-return-statement ";
  if (r->return_expression)
    cdfg_emit_expr (r->return_expression, str, rstack, DEFAULT);
  str += ")\n";
}


void
m_cdfg_emit_impl (pIIR_VariableAssignmentStatement a, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-variable-assignment ";
  cdfg_emit_expr (a->target, str, rstack, DEFAULT);
  str += " ";
  cdfg_emit_expr (a->expression, str, rstack, DEFAULT);
  str += ")\n";
}

void
m_cdfg_emit_impl (pIIR_IfStatement is, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-if-statement ";
  cdfg_emit_expr (is->condition, str, rstack, DEFAULT);
  str += ")\n";

  str += spaces(l+2) + "(create-then-clause)\n";
  cdfg_emit_impl (is->then_sequence, str, rstack, l+4);
  if (is->else_sequence)
    {
      str += spaces(l+2) + "(create-else-clause)\n";
      cdfg_emit_impl (is->else_sequence, str, rstack, l+4);
    }
  str += spaces(l) + "(create-end-if)\n";
}


void
m_cdfg_emit_impl (pIIR_CaseStatement cs, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-case-statement ";
  cdfg_emit_expr (cs->expression, str, rstack, DEFAULT);
  str += " (list ";
  
  list<string> choice_str_list;
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest) {
    string choice_str;
    pIIR_CaseStatementAlternative a = al->first;
    // If more than a single selection expression is given (i.e., more
    // than a single value, range or others then these expressions are
    // "ored" together.
    const bool single_choice = a->choices->rest == NULL;
    if (!single_choice)
      choice_str += "(list or ";
    for (pIIR_ChoiceList cl = a->choices; cl; cl = cl->rest)
      if (cl->first->is(IR_CHOICE_BY_RANGE)) {
	//***************************************
	// Choice by range
	//***************************************
	choice_str += " (list range ";
	pIIR_ChoiceByRange cbr = pIIR_ChoiceByRange(cl->first);
	// Get range.
	vector<RangeDescriptor> range_desc = get_discrete_range(cbr->range, rstack, IR_LOCALLY_STATIC);
	StaticRangeDescriptor<lint, IR_Direction> range = 
	  range_desc[0].rangedes_to_lint(rstack);
	if (range.left <= range.right && range.dir == IR_DIRECTION_UP)
	  choice_str += to_string(range.left) + " to " + to_string(range.right);
	else if (range.left > range.right && range.dir != IR_DIRECTION_UP)
	  choice_str += to_string(range.right) + " downto " + to_string(range.left);
	choice_str += ") ";
	
      } else if (cl->first->is(IR_CHOICE_BY_EXPRESSION)) {
	//***************************************
	// Choice by expression
	//***************************************
	
	pIIR_ChoiceByExpression cbe = pIIR_ChoiceByExpression(cl->first);
	cdfg_emit_folded_value(folded_value(cbe->value), choice_str, rstack, cbe->value->subtype);
	choice_str += " ";
	
      } else if (cl->first->is(IR_CHOICE_BY_OTHERS)) {
	//***************************************
	// Choice by others
	//***************************************
	choice_str += "'others ";
      }
    
    if (!single_choice)
      choice_str += ")";
    // Add string to choice string list
    choice_str_list.push_back(choice_str);
  }

  str += concat_to_string(choice_str_list.begin(), choice_str_list.end(), " ") + "))\n";

  list<string>::iterator choice_iter = choice_str_list.begin();
  for (pIIR_CaseStatementAlternativeList al = cs->case_statement_alternatives; al; al = al->rest, choice_iter++) {
    pIIR_CaseStatementAlternative a = al->first;
    
    string case_str = spaces(l+2) + "(create-case-when-clause " + *choice_iter + ")\n";

    // Analyze sequential statements associated with alternative
    if (a->sequence_of_statements != NULL)
      cdfg_emit_impl(a->sequence_of_statements, case_str, rstack, l + 4);

    str += case_str;
  }
  
  str += spaces(l) + "(create-end-case)\n";
}



void
m_cdfg_emit_impl (pIIR_LoopStatement ls, string &str, RegionStack &rstack, int l)
{
  ContextInfo &ctxt = *ActiveContext(rstack);
  pIIR_DeclarativeRegion active_region = ActiveDeclarativeRegion(rstack);

  // Check whether a name has been associated with the loop statement
  if (ls->declarative_region->declarator == NULL) {
    // If the loop statement has no name then create a default name
    string loop_name = to_string(ls->declarative_region->seqno) + loop_default_postfix;
    ls->declarative_region->declarator = new IIR_TextLiteral(0, loop_name.c_str());
  }

  if (ls->is(IR_WHILE_LOOP_STATEMENT)) {
    str += spaces(l) + "(create-while-loop-statement \"";
    qid(ls->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX)); // Print loop name
    str += "\" ";
    cdfg_emit_expr (pIIR_WhileLoopStatement(ls)->condition, str, rstack, DEFAULT);
    str += ")\n";

  } else if (ls->is(IR_FOR_LOOP_STATEMENT)) {
    pIIR_ForLoopStatement fl = pIIR_ForLoopStatement (ls);
    str += spaces(l) + "(create-for-loop-statement \"" + 
      qid(ls->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX)) + "\" "; // Print loop name
    str += qid(fl->iterator, rstack, id_type(DEFAULT, NO_PREFIX)) + " ";
    
      // Get iteration range
    vector<RangeDescriptor> range_desc = 
      get_discrete_range (pIIR_ScalarSubtype(fl->iterator->subtype)->range, rstack, IR_NOT_STATIC);
    StaticRangeDescriptor<string, string> range = 
      range_desc[0].cdfg_rangedes_to_string(rstack, get_default_id_type(rstack));
    str += "(list range " + range.left + " " + range.dir + " " + range.right + "))\n";
      
  } else {
    str += spaces(l) + "(create-while-loop-statement \"";
    qid(ls->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX)); // Print loop name
    str += "\" 1)\n";
  }
  
  if (ls->sequence_of_statements != NULL)
    cdfg_emit_impl (ls->sequence_of_statements, str, rstack, l+4);

  str += spaces(l) + "(create-end-loop \"" + 
    qid(ls->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX))
    + "\")\n";
}


void
m_cdfg_emit_impl (pIIR_NextStatement ns, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-next-statement \"";
  qid(ns->loop->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX)); // Print loop name
  str += "\" ";
  if (ns->condition) {
    cdfg_emit_expr (ns->condition, str, rstack, DEFAULT);
  } 
  str += ")";
}


void
m_cdfg_emit_impl (pIIR_ExitStatement es, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-exit-statement \"";
  qid(es->loop->declarative_region, rstack, id_type(DEFAULT, NO_PREFIX)); // Print loop name
  str += "\" ";
  if (es->condition)
    cdfg_emit_expr (es->condition, str, rstack, id_type(READER, DEREF));
  str += ")";
}


void
m_cdfg_emit_impl (pIIR_ProcedureCallStatement pcs, string &str, RegionStack &rstack, int l)
{
  
}

void
m_cdfg_emit_impl (pIIR_WaitStatement ws, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-wait-statement ";

  if (ws->condition_clause == NULL &&
      ws->timeout_clause == NULL &&
      ws->sensitivity_list == NULL) {
    // If there is no condition clause and no timeout clause and no
    // sensitivity_list then this wait statements shall stop the
    // process for the rest of the simulation time.
    str += "'() '() '()";
    
  } else {
    
    str += "(list";
    if (ws->sensitivity_list != NULL) {
      // Wait statemen has an explicit sensitivity list
      for (pIIR_ExpressionList el = ws->sensitivity_list; el; el = el->rest)
	{
	  str += " ";
	  cdfg_emit_expr(el->first, str, rstack, DEFAULT);
	}
    
    } else if (ws->condition_clause) {

      ContextInfo tmp_ctxt;
      get_context(ws->condition_clause, tmp_ctxt, rstack, false, 0);
      list<AccessDescriptor> sense_sigs = 
	filter(tmp_ctxt.accessed_objects, READ, 
	       tree_kind_list(IR_SIGNAL_DECLARATION, IR_SIGNAL_INTERFACE_DECLARATION));

      for (access_list::iterator i = tmp_ctxt.accessed_objects.begin(); 
	   i != tmp_ctxt.accessed_objects.end(); i++) {
	str += " ";
	cdfg_get_static_expr((*i).access_expr, str, rstack, IR_GLOBALLY_STATIC, DEFAULT, true);
      }
    }
    str += ") ";

    if (ws->condition_clause) {
      cdfg_emit_expr(ws->condition_clause, str, rstack, DEFAULT);
      str += " ";
    } else
      str += "'() ";

    // Explore timeout expression
    if (ws->timeout_clause) {
      cdfg_emit_expr(ws->timeout_clause, str, rstack, DEFAULT);
      str += " ";
    } else
      str += "'() ";
  }

  str += ")\n";
}


void
m_cdfg_emit_impl (pIIR_AssertionStatement as, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-assertion-statement\n";
  str += spaces(l+2);
  cdfg_emit_expr (as->assertion_condition, str, rstack, DEFAULT);
  str += "\n";
  str += spaces(l + 2);
  emit_expr (as->report_expression, str, rstack, DEFAULT);
  str += "\n";
  if (as->severity_expression != NULL) {
    str += spaces(l+2);
    emit_expr (as->severity_expression, str, rstack, DEFAULT);
  } 
  str += ")\n";
}

void
m_cdfg_emit_impl (pIIR_ReportStatement rs, string &str, RegionStack &rstack, int l)
{
  str += spaces(l) + "(create-report-statement\n";
  str += spaces(l+2);
  emit_expr (rs->report_expression, str, rstack, DEFAULT);
  str += ")\n";
  if (rs->severity_expression != NULL) {
    str += spaces(l+2);
    emit_expr (rs->severity_expression, str, rstack, DEFAULT);
  } 
  str += ")\n";
}



void
m_cdfg_emit_impl (pIIR_SignalAssignmentStatement sa, string &str, RegionStack &rstack, int l)
{
  // determine the signals that are written!
  ContextInfo &ctxt = *ActiveContext(rstack);

  // Target signal(s)
  str += spaces(l) + "(create-signal-assignment\n";
  str += spaces(l+2);
  cdfg_emit_expr(sa->target, str, rstack, DEFAULT);
  str += "\n";

  // Delay mechanism
  str += spaces(l+2);
  if (sa->delay_mechanism==IR_INERTIAL_DELAY) {
    if (sa->reject_time_expression != NULL) {
      str += "'(reject ";
      cdfg_emit_expr(sa->reject_time_expression, str, rstack, DEFAULT);
      str += ")\n";
    } else
      str += "'(inertial)\n";

  } else
    str += "(transport)\n";

  str += spaces(l+2) + "(list\n";
  for (pIIR_WaveformList wl = sa->waveform; wl; wl = wl->rest)
    {
      pIIR_WaveformElement we = wl->first;
      str += spaces(l+4) + "(list ";
      cdfg_emit_expr (we->value, str, rstack, DEFAULT);
      str += " ";
      if (we->time != NULL)
	cdfg_emit_expr (we->time, str, rstack, DEFAULT);
      else
	str += "0";
      str += ")\n";
    }
  str += spaces(l+2) + ")\n";
  str += spaces(l) + ")\n";
}


void
m_cdfg_emit_impl (pIIR_SequentialStatement s, string &str, RegionStack &rstack, int l)
{
  str += string(";; emit statement ") + s->kind_name ();
}


void
m_cdfg_emit_impl (pIIR_ComponentInstantiationStatement ci, string &str, RegionStack &rstack, int l)
{
  /* Nothing to do */
}

void
m_cdfg_emit_impl (pIIR_BlockStatement bs, string &str, RegionStack &rstack, int l)
{
  rstack.push(bs);
  
  if (bs->block_statement_part != NULL)
    cdfg_emit_impl(bs->block_statement_part, str, rstack, l);

  rstack.pop();
}


void
m_cdfg_emit_impl (pIIR_ConcurrentStatement cs, string &str, RegionStack &rstack, int l)
{
  str += string(";; ") + string(cs->kind_name());
}

