/* syntactical analysis of VHDL

   Copyright (C) 1994-1999 University of Dortmund
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

#ifndef FREEHDL_PARSER_H
#define FREEHDL_PARSER_H

#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-errors.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-printer.h>
#include <freehdl/vaul-dynarray.h>
#include <freehdl/vaul-pool.h>

VAUL_ObjectClass vaul_get_class (tree_base_node *);
pIIR_Type vaul_get_type (tree_base_node *);
pIIR_Type vaul_get_base (tree_base_node *);
IR_Mode vaul_get_mode (tree_base_node *);

struct vaul_design_unit;

struct vaul_error_printer : vaul_printer {

    vaul_error_printer ();
    virtual ~vaul_error_printer () {};

    void info (const char *fmt, ...);
    void error(const char *fmt, ...);
	// %n:	nNode
	// %C:	vaul_lexer *, lexer Kontext
	// %::	nPosNode, Node Position
	// %*:	vaul_lexer *, lexer Position
	//	rest wie printf

    virtual void vinfo (const char *fmt, va_list ap);
    int n_errors;
    FILE *log;
};

struct vaul_parser;

struct vaul_decl_set {

  vaul_decl_set (vaul_parser *);
  ~vaul_decl_set ();

  void reset();
  void copy_from (vaul_decl_set *);

  pIIR_Declaration single_decl (bool print = true);
  bool multi_decls (bool print = true);
  bool found_none ();

  void show (bool only_valids=false);

  pVAUL_Name name;

  void add (pIIR_Declaration);
  void begin_indirects ();
  void end_indirects ();
  bool finish_scope (pIIR_DeclarativeRegion);

  void refresh ();
  void invalidate_pot_invalids ();

  void iterate (void (*f) (pIIR_Declaration, void *cl), void *cl);
  void filter (int (*f) (pIIR_Declaration, void *cl), void *cl);
  int retain_lowcost ();

  void set_filter (bool (*func)(pIIR_Declaration, void*), void *data);
  bool has_filter ();
  
  bool use_cache ();

private:
  vaul_parser *pr;
  enum state_code { invalid, pot_invalid, pot_valid, valid };
  struct item {
    pIIR_Declaration d;
    state_code state;
    int cost;
  } *decls;
  int n_decls;
  bool doing_indirects;
  bool not_overloadable;
  bool (*filter_func)(pIIR_Declaration, void*);
  void *filter_data;
};

// Interleaving code generation with parsing.

struct vaul_parser;

struct vaul_consumer {
  vaul_consumer ();
  virtual ~vaul_consumer ();

  // the parser that feeds this consumer

  vaul_parser *parser;

  // For concurrent statements.  Returning FALSE from
  // CONSUME_CONC_STAT means that you don't care that statement any
  // longer and that VAUL can throw it away.

  virtual void push_conc_context (pIIR_DeclarativeRegion context);
  virtual bool consume_conc_stat (pIIR_ConcurrentStatement stat);
  virtual void pop_conc_context (pIIR_DeclarativeRegion context);

  // For declarations in a package body.  Returning FALSE means that
  // VAUL can throw as much of the declaration away as it wants to.

  virtual bool consume_pbody_decl (pIIR_Declaration);
};

typedef my_dynarray<pIIR_Type> pIIR_Type_vector;

inline bool
is_constant (pIIR_ObjectReference r)
{
  return vaul_get_class (r) == VAUL_ObjClass_Constant; 
}

inline bool
is_variable (pIIR_ObjectReference r)
{
  return vaul_get_class (r) == VAUL_ObjClass_Variable; 
}

inline bool
is_signal (pIIR_ObjectReference r)
{
  return vaul_get_class (r) == VAUL_ObjClass_Signal; 
}

inline bool
is_file (pIIR_ObjectReference r)
{
  return vaul_get_class (r) == VAUL_ObjClass_File; 
}

pIIR_DeclarationList next (pIIR_DeclarationList);
pIIR_DeclarationList first (pIIR_DeclarativeRegion);

void vaul_add_incomplete_type_use (pVAUL_IncompleteType it, pIIR_Type &ref);
void vaul_complete_incomplete_type (pVAUL_IncompleteType, pIIR_Type t);

typedef IIR_DeclarativeRegion IIR_Component;
typedef pIIR_DeclarativeRegion pIIR_Component;

// Option flags

struct vaul_parser_options {

  vaul_parser_options ();

  bool fullnames;         // Print fully qualified names in messages.
  bool debug;             // Print debugging messages.

  bool allow_invisible_default_bindings_from_work;
                          // When looking for default bindings,
                          // consider also units from the WORK library
                          // that are not visible.

  bool nocache;           // Do not use the cache.
  bool skip_bodies;       // Do only analyze entities and package headers.


  void set_fullnames (bool val)
  {
    fullnames = val;
  }

  void set_debug (bool val)
  {
    debug = val;
  }

  void set_allow_invisible_default_bindings_from_work (bool val)
  {
    allow_invisible_default_bindings_from_work = val;
  }

  void set_nocache (bool val)
  {
    nocache = val;
  }

  void set_skip_bodies (bool val)
  {
    skip_bodies = val;
  }
};

//  vaul_parser enthält den von Bison erzeugten Parser
//
struct vaul_parser : vaul_error_source, vaul_error_printer, vaul_node_creator {

  vaul_parser(vaul_lexer *l);
  ~vaul_parser();

  vaul_design_unit *parse(vaul_pool *p);

  void clear_errors();
  bool was_eof()	    { return eof; }

  vaul_parser_options options;

  static vaul_parser_options default_options;

  vaul_consumer *consumer;

private:

  vaul_lexer *lex;
  int bison_parse (void *dummy = NULL);
  //int bison_parse (void *dummy);
  //int bison_parse () { bison_parse(NULL); }

  void BisonError (const char *msg);

  void vinfo (const char *fmt, va_list ap);
  void print_node (FILE *, tree_base_node *);

  bool XXX_seen;
  pIIR_DeclarativeRegion announced_scope;
    
  bool eof;

  vaul_pool *pool;
  pIIR_SubprogramDeclaration cur_body;

  void init();
  void start (pIIR_LibraryUnit u);
  vaul_design_unit *finish();

  // decls.cc

  int next_decl_seqno;

  pIIR_Identifier make_id (const char *id);
  pIIR_StringLiteral make_strlit (const char *str);
  pIIR_StringLiteral make_opid (const char *op);
  char *id_to_chars (pIIR_TextLiteral id);

  void add_libs (pIIR_IdentifierList);
  void use (pVAUL_SelNameList);

  void visit_decls (void f (pIIR_Declaration, void *), void *);
  
  pIIR_EntityDeclaration get_entity (pIIR_Identifier id);
  pIIR_PackageDeclaration get_package (pIIR_Identifier id);
  pIIR_ConfigurationDeclaration get_configuration (pVAUL_Name);

  pIIR_DeclarativeRegion cur_scope, selected_scope;
  void push_scope (pIIR_DeclarativeRegion);
  void pop_scope (pIIR_DeclarativeRegion);

  pIIR_Declaration add_decl (pIIR_DeclarativeRegion,
			     pIIR_Declaration,
			     pIIR_TextLiteral = NULL);
  void rem_decl (pIIR_DeclarativeRegion, pIIR_Declaration);

  pIIR_Declaration add_decl (pIIR_Declaration d)
  {
    return add_decl (cur_scope, d, NULL); 
  }

  pIIR_TypeDeclaration add_type_decl (pIIR_DeclarativeRegion,
				      pIIR_Type,
				      pIIR_TextLiteral);

  void add_decl_plain (pIIR_DeclarativeRegion, pIIR_Declaration);

  void find_decls (vaul_decl_set &, pVAUL_Name);
  pIIR_Declaration find_single_decl (pVAUL_Name,
				     IR_Kind exp_k,
				     const char *kind_name = NULL);
  pIIR_Declaration find_single_decl (pIIR_TextLiteral,
				     IR_Kind exp_k,
				     const char *kind_name = NULL);

  void find_decls (vaul_decl_set &, pIIR_TextLiteral, pIIR_Declaration,
		   bool by_selection);
  void find_decls (vaul_decl_set &, pVAUL_Name, pIIR_Declaration,
		   bool by_selection);

  void start_decl (pIIR_TextLiteral id);

  void select_scope (pIIR_DeclarativeRegion);
  void unselect_scope ();
    
  pIIR_Declaration add_Alias (pIIR_Identifier id,
			      pIIR_Type alias_type,
			      pVAUL_Name aliased_thing);
  pIIR_FileDeclaration add_File (pIIR_Identifier id,
				 pIIR_Type file_type,
				 pIIR_Expression mode,
				 pVAUL_FilenameAndMode name_and_mode);

  pVAUL_StandardPackage std;

  void use_unit (vaul_design_unit *du);

  // types.cc

  pIIR_FunctionDeclaration find_resolution_function (pVAUL_Name res_name,
						     pIIR_Type type);

  pIIR_Type build_ArraySubtype (pVAUL_Name resol,
				pVAUL_Name mark,
				pIIR_TypeList);

  pIIR_Type build_ScalarSubtype (pVAUL_Name resol,
				 pVAUL_Name mark,
				 pIIR_Range);

  pIIR_Type build_Subtype (pVAUL_Name resol,
			   pVAUL_Name mark,
			   pIIR_TypeList);

  pIIR_Type build_EnumerationType (int pos, pIIR_EnumerationLiteralList lits);

  pIIR_FileType build_FileType (pVAUL_Name type_mark);

  pIIR_ScalarSubtype
  build_SubType_def (int lno,
		     pIIR_Range,
		     pIIR_Type base = NULL);

  pIIR_Range get_scalar_type_range (pIIR_Type t);

  pIIR_Type get_type(pVAUL_Name);
  void add_PredefOp(pIIR_PosInfo pos, pIIR_Type ret, pIIR_TextLiteral,
		    pIIR_Type l, pIIR_Type r = NULL);
  void add_predefined_ops(pIIR_Type);

  pIIR_TypeList build_PreIndexConstraint (pVAUL_GenAssocElem);
  pIIR_TypeList build_IndexConstraint (pIIR_TypeList,
				       pIIR_Type base);
  pIIR_Type find_index_range_type (pIIR_ExplicitRange);

  pIIR_ScalarSubtype make_scalar_subtype (pIIR_PosInfo pos,
					  pIIR_Type base,
					  int left, int right);
  pIIR_Type adapt_object_type(VAUL_ObjectClass, pIIR_Type,
			      pIIR_Expression initial_value);
  pIIR_ArraySubtype build_constrained_array_type(pIIR_TypeList,
						 pIIR_Type elt);

  // expr.cc

  bool try_overload_resolution(pIIR_Expression, pIIR_Type, IR_Kind = IR_INVALID);
  void overload_resolution(pIIR_Expression &, pIIR_Type, IR_Kind,
			   bool procs_allowed, bool for_read);
  void overload_resolution(pIIR_Expression &e, pIIR_Type t)
  { overload_resolution(e, t, IR_INVALID, false, true); }
  void overload_resolution(pIIR_Expression &e, IR_Kind k)
  { overload_resolution(e, NULL, k, false, true); }
  void overload_resolution_not_for_read(pIIR_Expression &e, pIIR_Type t)
  { overload_resolution(e, t, IR_INVALID, false, false); }

  void report_type_mismatch (pIIR_Expression e, pIIR_Type r, IR_Kind);

  void check_static_level (pIIR_Expression e, IR_StaticLevel l);

  bool prepare_named_assocs(pVAUL_GenAssocElem);
  void validate_gen_assocs(pVAUL_GenAssocElem);

  pIIR_AssociationList associate (pVAUL_NamedAssocElem, pIIR_InterfaceList,
				  bool complete = true,
				  bool need_overload_resolution = true);

  pIIR_AssociationList associate_ports (pVAUL_NamedAssocElem,
					pIIR_InterfaceList);

  void check_for_read (pIIR_Expression e);
  void check_for_update (pIIR_Expression e);

  pIIR_Expression build_Expr (pVAUL_Name);
  pIIR_Expression build_Expr (pVAUL_Name, vaul_decl_set *set, IR_Kind basic_k);
  pIIR_Expression build_formal_Expr (pIIR_InterfaceDeclaration formal,
				     pVAUL_Name name);

  pIIR build_Expr_or_Attr (pVAUL_Name);
  pIIR build_Expr_or_Attr (pVAUL_Name, vaul_decl_set *set, IR_Kind basic_k);
  pIIR_Expression validate_Expr (pIIR expr_or_attr);

  pIIR_ArrayReference build_ArrayReference (pIIR_Expression prefix,
					    pVAUL_GenAssocElem indices);
  pIIR_SliceReference build_SliceReference (pIIR_Expression prefix,
					    pVAUL_GenAssocElem slice);
  pIIR_PhysicalLiteral build_PhysicalLiteral (pIIR_AbstractLiteral lit,
					      pIIR_Identifier unit);
  pIIR_AbstractLiteralExpression
  build_LiteralExpression (int lineno,
			   pIIR_AbstractLiteral lit);
  pIIR_AbstractLiteralExpression
  build_LiteralExpression (pIIR_PosInfo pos,
			   pIIR_AbstractLiteral lit);

  pIIR_Aggregate build_Aggregate(pVAUL_AmbgAggregate, pIIR_Type);

  pIIR_Expression build_bcall(pIIR_Expression l, const char *op, pIIR_Expression r);
  pIIR_Expression build_QualifiedExpr(pVAUL_Name mark, pIIR_Expression);
  pIIR_Expression build_TypeConversion(pIIR_PosInfo pos, pIIR_Type,
				       pIIR_Expression);

  pIIR_Type expr_type(pIIR_Expression);

  pIIR_Type_vector *ambg_expr_types (pIIR_Expression);

  // attr.cc

  pIIR_Expression build_AttrExpr(pVAUL_AttributeName, vaul_decl_set *set,
				 IR_Kind basic_k);
    
  pIIR build_AttrNode (pVAUL_Name, vaul_decl_set *set, IR_Kind basic_k);
  pIIR build_AttrNode (pVAUL_AttributeName, vaul_decl_set *set, IR_Kind basic_k);

  void bind_attrspec (pVAUL_AttributeSpec);

  // subprogs.cc

  VAUL_ObjectClass cur_default_obj_class;

  pIIR_InterfaceDeclaration build_Interface (pIIR_TextLiteral declarator,
					     pIIR_Type subtype,
					     pIIR_Expression value,
					     VAUL_ObjectClass obj_class,
					     IR_Mode mode,
					     bool bus);

  void validate_interface (pIIR_SubprogramDeclaration,
			   pIIR_InterfaceDeclaration);
  void validate_port (pIIR_InterfaceDeclaration);
  void validate_generic (pIIR_InterfaceDeclaration);

  // stats.cc

  pIIR_ProcedureCallStatement build_ProcedureCallStat (int lineno, pVAUL_Name name);

  pIIR_LoopStatement
   push_loop (int lineno, pIIR_Label, pVAUL_IterationScheme scheme);
  pIIR_LoopStatement
   pop_loop (pIIR_SequentialStatementList loop_stats, pIIR_Identifier loop_id);

  pIIR_ProcessStatement build_condal_Process (pIIR_Identifier label,
					      bool pp,
					      pVAUL_CondalSignalAssign);
  pIIR_ProcessStatement build_sel_Process (pIIR_Identifier label,
					   bool pp,
					   pVAUL_SelSignalAssign);
  pIIR_ConcurrentGenerateStatement push_GenerateStat (int lineno,
						      pVAUL_IterationScheme);
  pIIR_LoopControlStatement build_LoopControlStat(int lineno, IR_Kind stat,
						  pIIR_Identifier loop_label,
						  pIIR_Expression when);
  pIIR_VariableAssignmentStatement
  build_VarAssignment(int lineno, pIIR_Expression target,
		      pIIR_Expression value);

  pIIR_SignalAssignmentStatement
  build_SignalAssignment(pIIR_PosInfo pos,
			 pIIR_Expression target,
			 pVAUL_DelayMechanism delay,
			 pIIR_WaveformList wave);
  pIIR_CaseStatement
  build_CaseStat (pIIR_PosInfo pos,
		  pIIR_Expression switch_expr,
		  pIIR_CaseStatementAlternativeList alternatives);
  pIIR_ProcessStatement build_conc_AssertStat (int lineno,
					       pIIR_Identifier label,
					       bool pp,
					       pIIR_AssertionStatement);
  pIIR_ConcurrentStatement
  build_conc_ProcedureCall_or_ComponentInst (int lno,
					     pIIR_Identifier label,
					     pVAUL_Name mark);
  pIIR_ProcessStatement build_conc_ProcedureCall (int lineno,
						  pIIR_Identifier label,
						  bool pp,
						  pIIR_ProcedureCallStatement);

  static pIIR_ExpressionList no_sens_list;
  pIIR_ProcessStatement build_Process (int lineno,
				       pIIR_ExpressionList sensitivities,
				       bool pp);

  void get_implicit_signals (pIIR_ExpressionList &sigs, pIIR_Expression e);
  void add_to_signal_list (pIIR_ExpressionList &sigs,
			   pIIR_ObjectReference sig);

  // blocks.cc

  pIIR_BindingIndication build_BindingIndic(pVAUL_IncrementalBindingIndic);
  pIIR_BindingIndication build_BindingIndic(pIIR_PosInfo pos,
					    pIIR_Component unit,
					    pVAUL_NamedAssocElem gmap,
					    pVAUL_NamedAssocElem pmap);

  pIIR_ComponentInstantiationStatement build_CompInst (int l,
						       pIIR_Identifier,
						       pIIR_BindingIndication);
  pIIR_ComponentInstantiationStatement build_CompInst (pIIR_PosInfo p,
						       pIIR_Identifier,
						       pIIR_BindingIndication);

  pIIR_BindingIndication
  find_component_configuration (pIIR_Identifier label,
				pIIR_BindingIndication inst_binding);

  void add_spec (pIIR_DeclarativeRegion b, pVAUL_ConfigSpec cs);

#if 0
  void bind_specs (pIIR_BlockStatement);
#endif

  pIIR_ArchitectureDeclaration get_architecture (pIIR_EntityDeclaration entity,
						 pIIR_TextLiteral arch);

  pIIR_ArchitectureRef get_architecture_ref (int lineno, pVAUL_Name entity,
					     pIIR_Identifier arch);
  pIIR_ArchitectureRef get_architecture_ref (pIIR_EntityDeclaration entity,
					     pVAUL_SimpleName arch);

  pIIR_BlockConfiguration start_BlockConfig (pVAUL_Name);
  pIIR_ComponentConfiguration start_CompConfig (int lineno, 
						pVAUL_ComponentSpec,
						pVAUL_IncrementalBindingIndic);
  void check_BlockConfig (pIIR_BlockConfiguration);

  pIIR_ComponentInstantiationList list_comps (pVAUL_ComponentSpec,
					      pIIR_DeclarativeRegion);

  // super private:
  bool associate_one (pIIR_AssociationList &tail,
		      pIIR_ObjectReference, pIIR_Declaration,
		      pIIR_Expression, pIIR_Declaration,
		      bool need_overload_resolution);
  int max_constrain_depth, constrain_depth;
  int constrain(pIIR_Expression, pIIR_Type, IR_Kind);
  int constrain1(pIIR_Expression, pIIR_Type, IR_Kind);
  int pre_constrain(pIIR_Expression);
  int try_one_association(pVAUL_NamedAssocElem, pIIR_InterfaceDeclaration);
  int try_association(pVAUL_NamedAssocElem, pIIR_InterfaceList);
  static int filter_return_stub (pIIR_Declaration, void *);
  struct filter_return_closure;
  int filter_return (pIIR_Declaration, filter_return_closure *);
  int conversion_cost (pIIR, pIIR_Type, IR_Kind);
  int try_array_subscription(pIIR_ArrayType, pVAUL_GenAssocElem);
  pIIR_Type is_one_dim_array(pIIR_Type);
  bool is_one_dim_logical_array(pIIR_Type);
  bool is_one_dim_discrete_array(pIIR_Type);
  bool is_discrete_type (pIIR_Type);
  int choice_conversion_cost (pIIR_Choice, pIIR_Expression actual,
			      pIIR_Type, IR_Kind);
  int array_literal_conversion_cost (pVAUL_AmbgArrayLitRef l, pIIR_Type t, IR_Kind k,
				     bool look_inside = true);
  struct cat_closure;
  static void collect_ambg_types_stub (pIIR_Declaration, void *);
  void collect_ambg_types (pIIR_Declaration d, cat_closure *);
  bool check_target(pIIR_Expression target, VAUL_ObjectClass oc,
		    const char *oc_label);
  pIIR_Declaration
  grab_formal_conversion (pVAUL_NamedAssocElem assoc,
			  pIIR_InterfaceList formals,
			  int *formal_cost = NULL,
			  pIIR_InterfaceDeclaration *converted_formal = NULL);
  pIIR_Expression add_partial_choice(pIIR_Expression &pactual, pVAUL_Name formal, pIIR_Expression actual);
  pIIR_Expression disambiguate_expr(pIIR_Expression, pIIR_Type, bool procs);
  pIIR_Expression disambiguate_expr1(pIIR_Expression, pIIR_Type, bool procs);
  bool evaluate_locally_static_universal_integer(pIIR_Expression, int &);
  pIIR_Type find_array_attr_index_type(pIIR_ArrayType, pIIR_Expression, int &);
  pIIR_Expression make_appropriate(pIIR_Expression);
  void report_mismatched_subprog(pVAUL_Name, vaul_decl_set *, pVAUL_NamedAssocElem);
  pIIR_Identifier closing_label;
  pIIR_Identifier starting_label;
  void add_disconnect_spec (pIIR_ExpressionList, pVAUL_Name mark,
			    pIIR_Expression after);
  pIIR_ConstantDeclaration fix_for_scheme (pVAUL_ForScheme);
  bool check_for_unresolved_names (pIIR_Expression e);

  pIIR_Range range_from_assoc (pVAUL_GenAssocElem assoc);
  pIIR_Type ensure_range_type (pIIR_Range, pIIR_Type);

  pVAUL_DeclCache decl_cache;
  void invalidate_decl_cache (pIIR_TextLiteral id);
  bool find_in_decl_cache (vaul_decl_set &dset, pIIR_TextLiteral id,
			   pIIR_Declaration scope, bool by_sel);
  void add_to_decl_cache (vaul_decl_set &dset, pIIR_TextLiteral id,
			  pIIR_Declaration scope, bool by_sel);

  struct cstat_item {
    cstat_item *prev;
    pIIR_ConcurrentStatementList *tail;
    pIIR_ConcurrentStatementList *start_tail;
    pIIR_DeclarativeRegion context;
  };
  cstat_item *cstat_tail;

  void push_concurrent_stats_tail (pIIR_ConcurrentStatementList *);
  void pop_concurrent_stats_tail (pIIR_ConcurrentStatementList *);
  void add_to_concurrent_stats_tail (pIIR_ConcurrentStatement);  

  void collect ();

  bool legal_file_type (pIIR_Type);
};

void vaul_add_spec (pIIR_BlockStatement, pVAUL_ConfigSpec);
IR_StaticLevel vaul_merge_levels (IR_StaticLevel l1, IR_StaticLevel l2);

#endif
