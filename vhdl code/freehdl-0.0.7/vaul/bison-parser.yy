/* bison grammar. -*- c++ -*-

   Copyright (C) University of Twente
   Department of Computer Science (INF/SPA)

   Copyright (C) Thomas Dettmer

   Copyright (C) 1994-1998, 2003 University of Dortmund
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

   Please see the file "vhdl.yacc" for additional details.
*/

/*
 This is only an approximation to the real VHDL grammar.  The right
 thing would probably be a handwritten parser.  It will get us
 superior error handling and maybe better performance.
*/

%{

#include <freehdl/vaul-chunk.h>
#include <freehdl/vaul-lexer.h>
#include <freehdl/vaul-parser.h>
#include <freehdl/vaul-dunit.h>
#include <freehdl/vaul-list.h>
#include <freehdl/vaul-util.h>
#include <vaul/vaulgens-chunk.h>

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>
#if HAVE_MALLOC_H
#include <malloc.h>
#endif

using namespace std;

#define YYINITDEPTH 10000
#define YYMAXDEPTH 100000

#define yylex(sem, loc) lex->lex(sem, loc)
#define yyparse		vaul_parser::bison_parse
#define yyerror		BisonError

#define YYSTYPE vaul_yystype
#define YYLTYPE vaul_yyltype

/* This is a hack to prevent the bison sceleton to declare a prototype
   for yyparse.  Since yyparse is a qualified name, it can't be used
   in a prototype. */

#define YYPARSE_PARAM dummy

#if 1
// Erweiterte Fehlermeldungen waeren ja ganz schön, aber die
// Namen fuer die Token sind nicht sehr elegant.
#define YYDEBUG 1
#define YYERROR_VERBOSE
#endif

// XXX - tidy up, used only for RANGE attribute resolution

static void
iterate_for_kind (pIIR_Declaration d, void *cl)
{
  IR_Kind &basic_k = *(IR_Kind *)cl;
  IR_Kind this_k = d->kind();
  
  if (basic_k == IR_INVALID)
    basic_k = this_k;
  else if (basic_k != this_k && !tree_is (this_k, basic_k)) 
    {
      while (!tree_is (basic_k, this_k))
	this_k = tree_base (this_k);
      basic_k = this_k;
    }
}

%}

%pure_parser
%expect 2

%token
t_ACCESS
t_AFTER
t_ALIAS
t_ALL
t_AND
t_ARCHITECTURE
skip_t_ARCHITECTURE
t_ARRAY
t_ASSERT
t_ATTRIBUTE
t_BEGIN
t_BLOCK
t_BODY
skip_t_BODY
t_BUFFER
t_BUS
t_CASE
t_COMPONENT
t_CONFIGURATION
skip_t_CONFIGURATION
t_CONSTANT
t_DISCONNECT
t_DOWNTO
t_ELSE
t_ELSIF
t_END
t_ENTITY
t_EXIT
t_FILE
t_FOR
t_FUNCTION
t_GENERATE
t_GENERIC
t_GUARDED
t_IF
t_IMPURE
t_IN
t_INERTIAL
t_INOUT
t_IS
t_LABEL
t_LIBRARY
t_LINKAGE
t_LOOP
t_MAP
t_NAND
t_NEW
t_NEXT
t_NOR
t_NULL
t_OF
t_ON
t_OPEN
t_OR
t_OTHERS
t_OUT
t_PACKAGE
t_PORT
t_POSTPONED
t_PROCEDURE
t_PROCESS
t_PURE
t_RANGE
t_REVERSE_RANGE
t_RECORD
t_REGISTER
t_REJECT
t_REPORT
t_RETURN
t_ROL
t_ROR
t_SELECT
t_SEVERITY
t_SIGNAL
t_SLA
t_SLL
t_SRA
t_SRL
t_SUBTYPE
t_THEN
t_TO
t_TRANSPORT
t_TYPE
t_UNITS
t_UNTIL
t_USE
t_VARIABLE
t_WAIT
t_WHEN
t_WHILE
t_WITH
t_XNOR
t_XOR

%nonassoc t_EQSym t_NESym t_LTSym t_LESym t_GTSym t_GESym
%nonassoc t_SLL t_SRL t_SLA t_SRA t_ROL t_ROR 
%left t_Plus t_Minus t_Ampersand
%left MED_PRECEDENCE
%left t_Star t_Slash t_MOD t_REM
%nonassoc t_DoubleStar t_ABS t_NOT MAX_PRECEDENCE

%token
t_Apostrophe
t_LeftParen
t_RightParen
t_Comma
t_VarAsgn
t_Colon
t_Semicolon

t_Arrow
t_Box
t_Bar
t_Dot

%token <tree.IIR_AbstractLiteral>
    t_AbstractLit

%token <tree.IIR_CharacterLiteral>
    t_CharacterLit

%token <tree.IIR_Identifier>
    t_Identifier

%token <tree.IIR_StringLiteral>
    t_StringLit

%type <tree.IIR_TextLiteral>
    designator opt_designator suffix enumeration_literal

%type <tree.IIR_Identifier>
    opt_entity_end opt_package_end
    opt_package_body_end opt_architecture_end
    opt_configuration_end opt_t_Identifier
    decl_Identifier opt_arch_id opt_record_end

%type <tree.IIR_AbstractLiteral>
    opt_t_AbstractLit

%type <tree.IIR_IdentifierList>
    idf_list lib_clause

%type <tree.VAUL_Name>
    name name2 mark ifts_name simple_sel_name attribute_prefix

%type <tree.VAUL_NameList>
    formal_part

%type <tree.VAUL_AttributeName>
    attribute_name range_attribute_name range_attribute_name_with_param

%type <tree.VAUL_SelName>
    sel_name

%type <tree.VAUL_SelNameList>
    sel_list use_clause

%type <tree.IIR_Type>
    opt_type_def type_definition enumeration_type_definition
    subtype_indic subtype_indic_opt_incomplete subtype_indic1
    physical_type_definition unconstrained_array_definition
    constrained_array_definition file_type_definition

%type <tree.IIR_PhysicalUnit>
    primary_unit_decl secondary_unit_decl 

%type <tree.IIR_UnitList>
    secondary_unit_decls

%type <tree.IIR_PhysicalLiteral>
    physical_literal_no_default physical_literal    

%type <tree.IIR_Range>
    range_constraint range_spec range_spec2

%type <tree.IIR_ExplicitRange>
    opt_direction_expr

%type <tree.IIR_TypeList>
    opt_index_constraint index_constraint opt_index_association_list

%type <tree.IIR_EnumerationLiteralList>
    enumeration_literal_decls opt_more_enumeration_literals

%type <dir>
    direction

%type <tree.IIR_Expression>
    expr opt_var_init and_expression or_expression xor_expression
    xnor_expression
    relation
    shift_expression
    simple_expression
    term
    factor
    primary
    opt_expr qualified_expr
    condition literal opt_when opt_wait_until opt_wait_for
    opt_wavefrm_after block_guard target opt_assertion_severity
    opt_assertion_report allocator opt_open_mode

%type <tree.VAUL_FilenameAndMode>
    opt_file_name

%type <tree.IIR_Root>
    expr_or_attr relation_or_attr shift_expression_or_attr
    simple_expression_or_attr signed_term_or_attr term_or_attr
    factor_or_attr primary_or_attr actual_part

%type <tree.IIR_SubprogramDeclaration>
    subprog_spec proc_or_func_spec

%type <tree.IIR_InterfaceList>
    opt_interf_list interf_list interf_list_1 opt_more_interf_elements
    port_interf_list generic_interf_list interf_element

%type <tree.IIR_SequentialStatementList>
    seq_stats rev_seq_stats if_stat_1 if_stat_2 

%type <tree.IIR_SequentialStatement>
    seq_stat return_stat variable_assign_stat if_stat
    loop_stat next_stat exit_stat null_stat wait_stat
    signal_assign_stat case_stat

%type <tree.IIR_AssertionStatement>
    assertion_stat

%type <tree.IIR_ReportStatement>
    report_stat

%type <tree.IIR_ProcedureCallStatement>
    procedure_call_stat
    procedure_call_stat_with_args
    procedure_call_stat_without_args

%type <tree.IIR_CaseStatementAlternativeList>
    case_stat_alternative more_case_stat_alternatives

%type <tree.IIR_Label>
    opt_label

%type <tree.VAUL_GenAssocElem>
    gen_association_list gen_association_list_1 gen_association_elements
    association_elements association_list association_list_1 discrete_range
    discrete_range1 opt_more_discrete_ranges

%type <tree.VAUL_NamedAssocElem>
    opt_port_map opt_port_map_semi opt_generic_map
    opt_generic_map_semi block_generic_stuff block_port_stuff port_map
    generic_map named_association_list opt_attribute_param

%type <tree.IIR_ExpressionList>
    sensitivity_list reverse_opt_more_sensitivities signal_name
    opt_wait_on opt_proc_sensitivity_list signal_list opt_more_signal_list

%type <tree.VAUL_IterationScheme>
    while_scheme for_scheme opt_iteration_scheme iteration_scheme
    generation_scheme if_scheme

%type <tree.IIR_WaveformList>
    wavefrm reverse_more_wavefrm wavefrm_element

%type <obj_class>
    object_class opt_object_class

%type <signal_kind>
    signal_kind opt_signal_kind

%type <mode>
    mode opt_mode opt_file_mode

%type <boolean>
    opt_t_BUS opt_guarded opt_postponed pure_or_impure

%type <tree.IIR_ConcurrentStatement> 
    concurrent_stat_with_label_1 concurrent_stat_without_label_1
    proc_stat block_stat comp_inst_stat concurrent_signal_assign_stat
    concurrent_assertion_stat concurrent_procedure_call generate_stat

%type <tree.VAUL_CondalSignalAssign>
    condal_signal_assign

%type <tree.VAUL_CondalWaveform>
    condal_wavefrms condal_wavefrms_1

%type <tree.VAUL_SelSignalAssign>
    sel_signal_assign

%type <tree.VAUL_SelWaveform>
    sel_wavefrms sel_wavefrms_1

%type <tree.IIR_ComponentDeclaration>
    comp_mark 

%type <tree.IIR_DeclarativeRegion>
    comp_mark_with_keyword

%type <tree.IIR_DeclarativeRegion>
    entity_aspect

%type <tree.VAUL_ComponentSpec>
    comp_spec

%type <tree.IIR_BindingIndication>
    binding_indic 

%type <tree.VAUL_IncrementalBindingIndic>
    opt_comp_binding_indic incremental_binding_indic
    pre_binding_indic

%type <tree.VAUL_InstList>
    inst_list

%type <tree.IIR_Type>
    index_subtype_definition

%type <tree.IIR_TypeList>
    index_subtype_defs opt_more_index_subtype_defs

%type <tree.IIR_RecordType>
    record_type_definition

%type <tree.IIR_ElementDeclarationList>
    element_decl opt_more_element_decls

%type <tree.VAUL_AmbgAggregate>
    aggregate

%type <tree.VAUL_ElemAssoc>
    rev_element_association_list2 element_association

%type <tree.IIR_Choice>
    choice

%type <tree.IIR_ChoiceList>
    choices opt_more_choices 

%type <tree.IIR_AccessType>
    access_type_definition

%type <tree.IIR_ConfigurationItem>
    config_item comp_config

%type <tree.IIR_BlockConfiguration>
    block_config opt_block_config

%type <tree.VAUL_EntitySpec>
    entity_spec

%type <tree.VAUL_DesigList>
    opt_more_entity_name_list

%type <tree.VAUL_EntityNameList>
    entity_name_list

%type <tree.VAUL_DelayMechanism>
    delay_mechanism

%type <kind>
    entity_class opt_function_or_procedure_t

%%

start:
	opt_design_unit { YYACCEPT; }	
    ;

opt_design_unit:    
	/* nothing */  { eof = true; }
    |	design_unit    { eof = false; }
    ;

designator:
	t_Identifier	{ $$ = $1; }
    |	t_StringLit	{ $$ = $1; }
    ;

literal:
	t_AbstractLit		    
        {
	  $$ = build_LiteralExpression (@1, $1);
	}
    |	t_CharacterLit		    { $$ = build_Expr(mVAUL_SimpleName(@1, $1)); }
    |	physical_literal_no_default { $$ = $1; }
    |	t_NULL			    { $$ = mVAUL_AmbgNullExpr(@1, NULL); }
    ;

enumeration_literal:
	t_CharacterLit	{ $$ = $1; }
    |	t_Identifier	{ $$ = $1; }
    ;

physical_literal:
	opt_t_AbstractLit t_Identifier
        {
	   if ($1 == NULL)
             $1 = mIIR_IntegerLiteral(@1, (IR_Character *)"1", 1);
	   $$ = build_PhysicalLiteral($1, $2);
        }
    ;

opt_t_AbstractLit:  
	/* nothing */	{ $$ = NULL; }
    |	t_AbstractLit
    ;

physical_literal_no_default:
	t_AbstractLit t_Identifier
	 { $$ = build_PhysicalLiteral($1, $2); }
    ;

idf_list:
	t_Identifier
          { $$ = mIIR_IdentifierList (@1, $1, NULL); }
    |	idf_list t_Comma t_Identifier
          { $$ = mIIR_IdentifierList (@3, $3, $1); }
    ;

/*------------------------------------------
--  Desing Unit
--------------------------------------------*/

design_unit:
	context_list lib_unit
    ;

context_list:
	/* nothing */  
    |	context_list context_item
    ;

lib_unit:
	entity_declaration
    |	configuration_declaration		
    |	package_declaration
    |	architecture_body 
    |	package_body
    |   skip_configuration_declaration
    |   skip_architecture_body
    |   skip_package_body
    ;

context_item:
	lib_clause	{ add_libs($1); }
    |	use_clause	{ use($1); }
    ;

lib_clause:
	t_LIBRARY idf_list t_Semicolon	{ $$ = reverse($2); }
    ;

use_clause:
	t_USE sel_list t_Semicolon	{ $$ = reverse($2); }
    ;

sel_list:
	sel_name			{ $$ = mVAUL_SelNameList(@1, $1, NULL); }
    |	sel_list t_Comma sel_name	{ $$ = mVAUL_SelNameList(@3, $3, $1); }
    ;

/*------------------------------------------
--  Library Units
--------------------------------------------*/

entity_declaration:
    t_ENTITY t_Identifier t_IS
    {
      pIIR_EntityDeclaration e = mIIR_EntityDeclaration(@2, $2);
      start (e);
      $<tree.IIR_EntityDeclaration>$ = e;
    }
	opt_generic_and_port_clauses
	entity_decl_part
        {
	  pIIR_EntityDeclaration e = $<tree.IIR_EntityDeclaration>4;
	  push_concurrent_stats_tail (&e->entity_statement_part);
	}
	opt_entity_stats
    t_END opt_entity_end t_Semicolon
    {
      pIIR_EntityDeclaration e = $<tree.IIR_EntityDeclaration>4;
      if ($10 && !vaul_name_eq($10, $2))
	error ("%n does not match entity name %n", $10, $2);
      pop_concurrent_stats_tail (&e->entity_statement_part);
      pop_scope (e);
    };

opt_generic_and_port_clauses:
	/* nothing */
    |	generic_clause
    |   port_clause
    |   generic_clause port_clause
    |	port_clause generic_clause
    ;

/*
opt_generic_clause:
	/ nothing /
    |	generic_clause
    ;
*/

generic_clause:
	t_GENERIC generic_interf_list t_Semicolon
	{
	  vaul_set_generics (cur_scope, $2);
	}
    ;


/*
opt_port_clause:
	/ nothing /
    |	port_clause
    ;
*/

port_clause:	    
	t_PORT port_interf_list t_Semicolon
	{
	  vaul_set_ports (cur_scope, $2);
	}
    ;

entity_decl_part:
	/* nothing */
    |	entity_decl_part entity_decltve_item
    ;

opt_entity_stats:
	/* nothing */ 
    |	t_BEGIN concurrent_stats
    ;

opt_entity_end:			
	t_ENTITY opt_t_Identifier   { $$ = $2; }
    |	opt_t_Identifier	    { $$ = $1; }
    ;

opt_t_Identifier:
	/* nothing */		    { $$ = NULL; }
    |	t_Identifier		    { $$ = $1; }
    ;

architecture_body:
    t_ARCHITECTURE t_Identifier t_OF t_Identifier t_IS
    {
      pIIR_EntityDeclaration entity = get_entity ($4);
      pIIR_ArchitectureDeclaration a = mIIR_ArchitectureDeclaration (@2, $2,
                                                                     entity);
      a->continued = entity;
      start (a);
      $<tree.IIR_ArchitectureDeclaration>$ = a;
    }
	architecture_decl_part
    t_BEGIN
        {
	  pIIR_ArchitectureDeclaration a =
	    $<tree.IIR_ArchitectureDeclaration>6;
	  push_concurrent_stats_tail (&a->architecture_statement_part);
	}
	opt_concurrent_stats
    t_END opt_architecture_end t_Semicolon
    {
      pIIR_ArchitectureDeclaration a = $<tree.IIR_ArchitectureDeclaration>6;
      if ($12 && !vaul_name_eq($12, $2))
	error ("%n does not match architecture name %n", $12, $2);
      pop_concurrent_stats_tail (&a->architecture_statement_part);
      pop_scope ($<tree.IIR_ArchitectureDeclaration>6);
    };

architecture_decl_part:
	/* nothing */
    |	architecture_decl_part block_decltve_item
    ;

opt_architecture_end:		    
	t_ARCHITECTURE opt_t_Identifier { $$ = $2; }
    |	opt_t_Identifier		{ $$ = $1; }
    ;


configuration_declaration:
    t_CONFIGURATION t_Identifier t_OF t_Identifier t_IS
    {
      pIIR_ConfigurationDeclaration c =
	mIIR_ConfigurationDeclaration (@2, $2, get_entity($4));
      start (c);
      $<tree.IIR_ConfigurationDeclaration>$ = c;
    }
	configuration_decl_part
	block_config
    t_END opt_configuration_end t_Semicolon
    {
      $<tree.IIR_ConfigurationDeclaration>6->block_configuration = $8;
      if ($10 && !vaul_name_eq($10, $2))
	error("%n does not match configuration name %n", $10, $2);
      pop_scope ($<tree.IIR_ConfigurationDeclaration>6);
    };

configuration_decl_part:
    | configuration_decl_part config_decltve_item
    ;

opt_configuration_end:
	t_CONFIGURATION opt_t_Identifier    { $$ = $2; }
    |	opt_t_Identifier		    { $$ = $1; }
    ;
    

package_declaration:
    t_PACKAGE t_Identifier t_IS
    {	if(vaul_name_eq($2, "standard"))
	    start(mVAUL_StandardPackage(@2, $2));
	else
	    start(mIIR_PackageDeclaration(@2, $2));
    }
	package_decl_part
    t_END opt_package_end t_Semicolon
    {
	if($7 && !vaul_name_eq($7, $2))
	    error("%n does not match package name %n", $7, $2);
	pop_scope(cur_du->get_tree());
    };

package_decl_part:
    |	package_decl_part package_decltve_item
    ;

opt_package_end:
	t_PACKAGE opt_t_Identifier	{ $$ = $2; }
    |	opt_t_Identifier		{ $$ = $1; }
    ;


package_body:
    t_PACKAGE t_BODY t_Identifier t_IS
    {
      pIIR_PackageDeclaration p = get_package ($3);
      pIIR_PackageBodyDeclaration pb = mIIR_PackageBodyDeclaration (@3, $3, p);
      pb->continued = p;
      start (pb);
    }
	package_body_decl_part
    t_END opt_package_body_end t_Semicolon
    {
      if ($8 && !vaul_name_eq($8, $3))
	error ("%n does not match package name %n", $8, $3);
      pop_scope (cur_du->get_tree());
    };

package_body_decl_part:
    |	package_body_decl_part package_body_decltve_item
    ;

opt_package_body_end:
	t_PACKAGE t_BODY opt_t_Identifier   { $$ = $3; }
    |	opt_t_Identifier		    { $$ = $1; }
    ;

/*------------------------------------------
--  Declarative Item
--------------------------------------------*/

common_decltve_item:
	type_decl
    |	subtype_decl  
    |	constant_decl
    |	file_decl
    |	alias_decl
    |	subprog_decl
    |	use_clause	{ use($1); }
    ;

entity_decltve_item:
	common_decltve_item
    |	subprog_body
    |	attribute_decl
    |	attribute_spec
    |	disconnection_spec
    |	signal_decl
    ;

block_decltve_item:
	common_decltve_item
    |	subprog_body
    |	comp_decl
    |	attribute_decl
    |	attribute_spec
    |	config_spec
    |	disconnection_spec
    |	signal_decl
    ;

package_decltve_item:
	common_decltve_item
    |	comp_decl
    |	attribute_decl
    |	attribute_spec
    |	disconnection_spec
    |	signal_decl
    ;

package_body_decltve_item:
	common_decltve_item
    |	subprog_body
    ;

subprog_decltve_item:
	common_decltve_item
    |	subprog_body
    |	attribute_decl
    |	attribute_spec
    |	variable_decl
    ;

proc_decltve_item:
	common_decltve_item
    |	subprog_body
    |	attribute_decl
    |	attribute_spec
    |	variable_decl
    ;

config_decltve_item:
	attribute_spec
    |	use_clause	{ use($1); }
    ;

/*------------------------------------------
--  Subprograms
--------------------------------------------*/

subprog_decl:
	subprog_spec t_Semicolon
	{
	  add_decl ($1);
	  if (consumer)
	    consumer->consume_pbody_decl ($1);
	  collect ();
	}
    ;

subprog_spec:
	proc_or_func_spec
	{
	  for (pIIR_InterfaceList il = $1->interface_declarations;
	       il; il = il->rest)
	    {
	      validate_interface ($1, il->first);
	      add_decl ($1, il->first);
	    }
	  $$ = $1;
	}
    ;

proc_or_func_spec:
	t_PROCEDURE t_Identifier opt_interf_list
	{
	  $$ = mIIR_ProcedureDeclaration (@2, $2, $3);
	}
    |	pure_or_impure t_FUNCTION designator opt_interf_list
          t_RETURN subtype_indic
	{
	  $$ = mIIR_FunctionDeclaration (@3, $3, $4, $1, $6);
	}
    ;

pure_or_impure:
	/* nothing */   { $$ = true; }
    |   t_PURE          { $$ = true; }
    |   t_IMPURE        { $$ = false; }
    ;

opt_interf_list:
	/* nothing */	{ $$ = NULL; }
    |	interf_list
    ;

subprog_body:
	subprog_spec t_IS
	{
	  pIIR_SubprogramDeclaration body = $1;
	  pIIR_SubprogramDeclaration proto =
	    pIIR_SubprogramDeclaration (add_decl (body));
	  assert (proto->is(IR_SUBPROGRAM_DECLARATION));

	  if (proto->subprogram_body != NULL)
	    {
	      error ("redefinition of %n", body);
	      info ("%: here is the previous definition", proto);
	    }

	  if (body != proto)
	    {
	      body->prototype = proto;
	      add_decl_plain (cur_scope, body);
	    }
 
	  push_scope (body);
	  $<tree.IIR_SubprogramDeclaration>$ = body;
	}
	    subprog_body_decl_part
	t_BEGIN
	    seq_stats
	t_END opt_function_or_procedure_t opt_designator t_Semicolon
        {
	  pIIR_SubprogramDeclaration body =
	    $<tree.IIR_SubprogramDeclaration>3;

	  /* Check whether procedure/function is closed with "end
	     procedure/function" and not with "end
	     function/procedure" */
	  if ($8 != NULL && !$1->is ($8))
	    if ($1->is (IR_PROCEDURE_DECLARATION))
	      error ("parse error, unexpected t_FUNCTION, expecting t_PROCEDURE");
	    else
	      error ("parse error, unexpected t_PROCEDURE, expecting t_FUNCTION");

	  if ($9 && !vaul_name_eq ($9, body->declarator))
	    error ("%n does not match subprogram designator %n",
		   $9, body->declarator);
	  if ($6)
	    body->subprogram_body = $6;
	  else
	    body->subprogram_body =
	      mIIR_SequentialStatementList (@6, mIIR_NullStatement (@6), NULL);

	  if (consumer)
	    consumer->consume_pbody_decl (body);
	  collect ();

	  pop_scope (body);
	}
    ;


opt_function_or_procedure_t:
	/* nothing */	{ $$ = NULL; }
|   t_PROCEDURE { $$ = IR_PROCEDURE_DECLARATION; }
|   t_FUNCTION  { $$ = IR_FUNCTION_DECLARATION; }
    ;     

opt_designator:
	/* nothing */	{ $$ = NULL; }
|	designator      { $$ = $1; }
    ;

subprog_body_decl_part:
	/* nothing */
    |	subprog_body_decl_part subprog_decltve_item
    ;


/*--------------------------------------------------
--  Interface Lists and Associaton Lists
----------------------------------------------------*/

port_interf_list:
        {
	  cur_default_obj_class = VAUL_ObjClass_Signal;
	}
	interf_list_1
	{
	  for(pIIR_InterfaceList il = $2; il; il = il->rest) 
	    {
	      validate_port (il->first);
	      add_decl (il->first);
	    }
	  $$ = $2;
	}
    ;

generic_interf_list:
        {
	  cur_default_obj_class = VAUL_ObjClass_Constant;
	}
	interf_list_1
	{
	  for(pIIR_InterfaceList il = $2; il; il = il->rest) 
	    {
	      validate_generic (il->first);
	      add_decl (il->first);
	    }
	  $$ = $2;
	}
    ;

interf_list:
        {
	  cur_default_obj_class = VAUL_ObjClass_None;
	}
        interf_list_1
        {
          $$ = $2;
	}
        ;

interf_list_1:
	t_LeftParen interf_element opt_more_interf_elements t_RightParen
	{
	  pIIR_InterfaceList i;
	  for (i = $2; i && i->rest; i = i->rest)
	    ;
	  if (i)
	    {
	      i->rest = $3;
	      $$ = $2;
	    }
	  else
	    $$ = $3;
	}
    ;

opt_more_interf_elements:
	/* nothing */	    { $$ = NULL; }
    |	opt_more_interf_elements t_Semicolon interf_element
	{
	  pIIR_InterfaceList i;
	  for (i = $1; i && i->rest; i = i->rest)
	    ;
	  if (i)
	    {
	      i->rest = $3;
	      $$ = $1;
	    }
	  else
	    $$ = $3;
	}
    ;

interf_element:
	opt_object_class idf_list t_Colon opt_mode subtype_indic
	    opt_t_BUS opt_var_init
        {
	  $$ = NULL;
	  overload_resolution ($7, $5);
	  for (pIIR_IdentifierList idl = $2; idl; idl = idl->rest)
	    $$ = mIIR_InterfaceList(@2, build_Interface (idl->first, $5, $7,
							 $1, $4, $6),
	                            $$);
	}
    ;

opt_t_BUS:
	/* nothing */	{ $$ = false; }
    |	t_BUS	        { $$ = true; }
    ;

opt_mode:
	/* nothing */	{ $$ = IR_UNKNOWN_MODE; }
    |	mode
    ;
  
opt_object_class:
	/* nothing */	{ $$ = VAUL_ObjClass_None; }
    |	object_class
    ;
  
mode:
	t_IN	    { $$ = IR_IN_MODE; }
    |	t_OUT	    { $$ = IR_OUT_MODE; }
    |	t_INOUT	    { $$ = IR_INOUT_MODE; }
    |	t_BUFFER    { $$ = IR_BUFFER_MODE; }
    |	t_LINKAGE   { $$ = IR_LINKAGE_MODE; }
    ;

association_list:
	t_LeftParen association_elements association_list_1 t_RightParen
	{
	    $$ = $2;
	    pVAUL_GenAssocElem ae = $2;
	    while (ae->next)
		ae = ae->next;
	    ae->next = reverse ($3);
        }
    ;

named_association_list:
	association_list
	{   
	    $$ = prepare_named_assocs($1)? pVAUL_NamedAssocElem($1) : NULL;
	}
    ;

association_list_1:
	/* nothing */	{ $$ = NULL; }
    |	association_list_1 t_Comma association_elements
	{
	    pVAUL_GenAssocElem ae = $3;
	    while (ae->next)
	        ae = ae->next;
	    ae->next = $1;
	    $$ = $3;
	}
    ;


gen_association_list:
	t_LeftParen gen_association_elements gen_association_list_1 t_RightParen
	{
	    $$ = reverse($3);
	    if($2) {
		pVAUL_GenAssocElem ae = $2;
		while (ae->next)
		    ae = ae->next;
		ae->next = $$;
		$$ = $2;
	    }
	}
    ;

gen_association_list_1:
	/* nothing */	{ $$ = NULL; }
    |	gen_association_list_1 t_Comma gen_association_elements
	{
	    $$ = $1;
	    if($3) {
		pVAUL_GenAssocElem ae = $3;
		while (ae->next)
		    ae = ae->next;
		ae->next = $$;
		$$ = $3;
	    }
	}
    ;

association_elements:
	formal_part t_Arrow actual_part
	{
	    pIIR_Expression a = validate_Expr ($3);
	    $$ = NULL;
	    for (pVAUL_NameList nl = $1; nl; nl = nl->link)
		$$ = mVAUL_NamedAssocElem(@2, $$, nl->name, a);
	}
    |	actual_part
	{
	    if($1 && $1->is(IR_RANGE))
		$$ = mVAUL_RangeAssocElem(@1, NULL, pIIR_Range($1));
	    else 
		$$ = mVAUL_NamedAssocElem(@1, NULL, NULL, validate_Expr($1));
	}
    ;

gen_association_elements:
    	association_elements
    |  	discrete_range1
    ;

formal_part:
	name                   { $$ = mVAUL_NameList (@1, $1, NULL); }
    |	formal_part t_Bar name { $$ = mVAUL_NameList (@1, $3, $1); } 
    ;

actual_part:
	expr_or_attr
    |	t_OPEN	{ $$ = mIIR_OpenExpression(@1, NULL); }
    ;

/*--------------------------------------------------
--  Names and Expressions
----------------------------------------------------*/

mark: 
	t_Identifier	{ $$ = mVAUL_SimpleName(@1, $1); }
    |	sel_name	{ $$ = $1; }
    ;

expr:
	expr_or_attr
	{
	    $$ = validate_Expr($1);
	}
    ;

expr_or_attr:
	and_expression	    { $$ = $1; }
    |	or_expression	    { $$ = $1; }
    |	xor_expression	    { $$ = $1; } 
    |   xnor_expression     { $$ = $1; }
    |	relation_or_attr    { $$ = $1; }
    |	relation t_NAND relation
	 { $$ = build_bcall($1, "nand", $3); }
    |	relation t_NOR relation
	 { $$ = build_bcall($1, "nor", $3); }
    ;

relation:
	relation_or_attr
	{
	    $$ = validate_Expr($1);
	}
    ;

and_expression:
	relation t_AND relation
	 { $$ = build_bcall($1, "and", $3); }
    |	and_expression t_AND relation
	 { $$ = build_bcall($1, "and", $3); }
    ;

or_expression:
	relation t_OR relation
	 { $$ = build_bcall($1, "or", $3); }
    |	or_expression t_OR relation
	 { $$ = build_bcall($1, "or", $3); }
    ;

xor_expression:
	relation t_XOR relation
	 { $$ = build_bcall($1, "xor", $3); }
    |	xor_expression t_XOR relation
	 { $$ = build_bcall($1, "xor", $3); }
    ;

xnor_expression:
	relation t_XNOR relation
	 { $$ = build_bcall($1, "xnor", $3); }
    |	xnor_expression t_XNOR relation
	 { $$ = build_bcall($1, "xnor", $3); }
    ;

relation_or_attr:
        shift_expression_or_attr
    |   shift_expression t_EQSym shift_expression
        {
          $$ = build_bcall ($1, "=", $3);
	}
    |   shift_expression t_NESym shift_expression
        {
          $$ = build_bcall ($1, "/=", $3);
	}
    |   shift_expression t_LTSym shift_expression
        {
          $$ = build_bcall ($1, "<", $3);
	}
    |   shift_expression t_LESym shift_expression
        {
          $$ = build_bcall ($1, "<=", $3);
	}
    |   shift_expression t_GTSym shift_expression
        {
          $$ = build_bcall ($1, ">", $3);
	}
    |   shift_expression t_GESym shift_expression
        {
          $$ = build_bcall ($1, ">=", $3);
	}
    ;

shift_expression:
        shift_expression_or_attr
        {
	  $$ = validate_Expr($1);
	}
    ;

shift_expression_or_attr:
	simple_expression_or_attr
    |   simple_expression t_SLL simple_expression
        {
          $$ = build_bcall ($1, "sll", $3);
	}
    |   simple_expression t_SRL simple_expression
        {
          $$ = build_bcall ($1, "srl", $3);
	}
    |   simple_expression t_SLA simple_expression
        {
          $$ = build_bcall ($1, "sla", $3);
	}
    |   simple_expression t_SRA simple_expression
        {
          $$ = build_bcall ($1, "sra", $3);
	}
    |   simple_expression t_ROL simple_expression
        {
          $$ = build_bcall ($1, "rol", $3);
	}
    |   simple_expression t_ROR simple_expression
        {
          $$ = build_bcall ($1, "ror", $3);
	}
    ;

simple_expression:
        simple_expression_or_attr
        {
	  $$ = validate_Expr($1);
	}
    ;

simple_expression_or_attr:
        signed_term_or_attr
    |   simple_expression t_Plus term
        {
          $$ = build_bcall ($1, "+", $3);
	}
    |   simple_expression t_Minus term
        {
          $$ = build_bcall ($1, "-", $3);
	}
    |   simple_expression t_Ampersand term
        {
          $$ = build_bcall ($1, "&", $3);
	}
    ;

signed_term_or_attr:
        term_or_attr
    |	t_Plus term
        {
	  $$ = build_bcall ($2, "+", NULL);
	}
    |	t_Minus term
        {
	  $$ = build_bcall ($2, "-", NULL);
	}
    ; 

term:
        term_or_attr
        {
	  $$ = validate_Expr($1);
	}
    ;

term_or_attr:
	factor_or_attr
    |   term t_Star factor
        {
          $$ = build_bcall ($1, "*", $3);
	}
    |   term t_Slash factor
        {
          $$ = build_bcall ($1, "/", $3);
	}
    |   term t_MOD factor
        {
          $$ = build_bcall ($1, "mod", $3);
	}
    |   term t_REM factor
        {
          $$ = build_bcall ($1, "rem", $3);
	}
    ;

factor:
        factor_or_attr
        {
	  $$ = validate_Expr($1);
	}
    ;

factor_or_attr:
	primary_or_attr
    |   primary t_DoubleStar primary
        {
          $$ = build_bcall ($1, "**", $3);
	}
    |   t_ABS primary
        {
          $$ = build_bcall ($2, "abs", NULL);
	}
    |   t_NOT primary
        {
          $$ = build_bcall ($2, "not", NULL);
	}
    ;
 
primary:
	primary_or_attr
	{
	    $$ = validate_Expr($1);
	}
    ;

primary_or_attr:
	name		{ $$ = build_Expr_or_Attr($1); }
    |	literal		{ $$ = $1; }
    |	aggregate	{ $$ = $1; }
    |	qualified_expr	{ $$ = $1; }
    |	allocator	{ $$ = $1; }
    |	t_LeftParen expr t_RightParen { $$ = $2; }
    ;


name:
	mark
    |	name2
    ;

name2:
	t_StringLit	    { $$ = mVAUL_SimpleName(@1, $1); }
    |	attribute_name	    { $$ = $1; }
    |	ifts_name
    ;  

sel_name:
	name t_Dot suffix   { $$ = mVAUL_SelName(@1, $1, $3); }
    ;

simple_sel_name:
	simple_sel_name t_Dot t_Identifier  { $$ = mVAUL_SelName(@1, $1, $3); }
    |	t_Identifier			    { $$ = mVAUL_SimpleName(@1, $1); }
    ;

suffix:
	designator	    { $$ = $1; }
    |	t_CharacterLit	    { $$ = $1; }
    |	t_ALL		    { $$ = make_id("all"); }
    ;

ifts_name:
	mark gen_association_list   
	{
	    pVAUL_Name n = $1; // gcc bug?
	    if(n->is(VAUL_ATTRIBUTE_NAME)) {
		pVAUL_AttributeName(n)->first_actual =
		    prepare_named_assocs($2)? pVAUL_NamedAssocElem($2) : NULL;
		$$ = n;
	    } else {
		validate_gen_assocs($2);
		$$ = mVAUL_IftsName(@1, n, $2);
	    }
	}
    |	name2 gen_association_list
	{
	    pVAUL_Name n = $1; // gcc bug?
	    if(n->is(VAUL_ATTRIBUTE_NAME)) {
		pVAUL_AttributeName(n)->first_actual =
		    prepare_named_assocs($2)? pVAUL_NamedAssocElem($2) : NULL;
		$$ = n;
	    } else {
		validate_gen_assocs($2);
		$$ = mVAUL_IftsName(@1, n, $2);
	    }
	}
    ;


attribute_prefix:
    mark t_Apostrophe { $$ = $1; }
    | name2 t_Apostrophe { $$ = $1; }
    ;


range_attribute_name:
    attribute_prefix t_RANGE
         { $$ = mVAUL_AttributeName(@1, $1, make_id("RANGE"), NULL); }
    | attribute_prefix t_REVERSE_RANGE
         { $$ = mVAUL_AttributeName(@1, $1, make_id("REVERSE_RANGE"), NULL); }
    ;


attribute_name:
    attribute_prefix t_Identifier
	 { $$ = mVAUL_AttributeName(@1, $1, $2, NULL); }
    | range_attribute_name { $$ = $1; }
    ;

/*
attribute_name:
	mark t_Apostrophe t_Identifier
	 { $$ = mVAUL_AttributeName(@1, $1, $3, NULL); }
    |	name2 t_Apostrophe t_Identifier
	 { $$ = mVAUL_AttributeName(@1, $1, $3, NULL); }
    |	mark t_Apostrophe t_RANGE
	 { $$ = mVAUL_AttributeName(@1, $1, make_id("RANGE"), NULL);
         }
    |	name2 t_Apostrophe t_RANGE
	 { $$ = mVAUL_AttributeName(@1, $1, make_id("RANGE"), NULL);
         }
    ;
*/

range_attribute_name_with_param:
	range_attribute_name opt_attribute_param
	{
	    pVAUL_AttributeName n = $$ = $1;
	    if(n)
		n->first_actual = $2;
	}
    ;


/*
attribute_name_with_param:
	attribute_name opt_attribute_param
	{
	    pVAUL_AttributeName n = $$ = $1;
	    if(n)
		n->first_actual = $2;
	}
    ;
*/

opt_attribute_param:
	/* empty */ { $$ = NULL; }
    |	t_LeftParen expr t_RightParen
	{ $$ = mVAUL_NamedAssocElem(@1, NULL, NULL, $2); }
    ;

aggregate:
	rev_element_association_list2 t_RightParen
	{
	    $$ = mVAUL_AmbgAggregate(@1, NULL, reverse($1));
	}
    |	t_LeftParen choices t_Arrow expr t_RightParen
	{
	    $$ = mVAUL_AmbgAggregate(@1, NULL, mVAUL_ElemAssoc(@3, NULL, $2, $4));
	}
    ;

rev_element_association_list2:
	t_LeftParen element_association t_Comma element_association
	{
	    if($4) {
		$4->next = $2;
		$$ = $4;
	    } else
		$$ = $2;
	}
    |	rev_element_association_list2 t_Comma element_association
	{
	    if($3) {
		$3->next = $1;
		$$ = $3;
	    } else
		$$ = $1;
	}
    ;

qualified_expr:
	mark t_Apostrophe t_LeftParen expr t_RightParen
	 { $$ = build_QualifiedExpr($1, $4); }
    |	mark t_Apostrophe aggregate
	 { $$ = build_QualifiedExpr($1, $3); }
    ;


allocator:
	t_NEW mark mark opt_index_association_list
	{
	    pIIR_Type t =
	      mIIR_AccessType(@1, build_ArraySubtype ($2, $3, $4));
	    $$ = mIIR_Allocator (@1, t, t, NULL);
	}
    |	t_NEW mark opt_index_association_list
	{
	    pIIR_Type t =
	      mIIR_AccessType(@1, build_ArraySubtype (NULL, $2, $3));
	    pIIR_Allocator a = mIIR_Allocator (@1, t, t, NULL);
	    $$ = a;
	}
    |	t_NEW qualified_expr
	{
	    pIIR_Expression e = $2;
	    overload_resolution(e, IR_TYPE);
	    if (e) 
	      {
		assert (e->is(IR_QUALIFIED_EXPRESSION));
		pIIR_QualifiedExpression qe = pIIR_QualifiedExpression(e);
		pIIR_Type t = mIIR_AccessType(@1, qe->subtype);
		$$ = mIIR_Allocator (@1, t, t, qe->expression);
	      }
	    else
	      $$ = NULL;
	}
    ;

opt_index_association_list:
	/* nothing */		{ $$ = NULL; }
    |	gen_association_list	{ $$ = build_PreIndexConstraint($1); }
    ;

/*--------------------------------------------------
--  Element Association and Choices
----------------------------------------------------*/

element_association:
	choices t_Arrow expr
	    { $$ = mVAUL_ElemAssoc(@2, NULL, $1, $3); }
    |	expr
	    { $$ = mVAUL_ElemAssoc(@1, NULL, NULL, $1); }
    ;

choices:
	choice opt_more_choices
	{
	  if ($1)
	    $$ = mIIR_ChoiceList (@1, $1, $2);
	  else
	    $$ = $2;
	}
    ;

opt_more_choices:
	/* nothing */	{ $$ = NULL; }
    |	opt_more_choices t_Bar choice
	{
	  pIIR_ChoiceList cl = mIIR_ChoiceList (@3, $3, NULL);
	  if ($1)
	    {
	      pIIR_ChoiceList c;
	      for(c = $1; c->rest; c = c->rest)
		;
	      c->rest = cl;
	      $$ = $1;
	    } 
	  else
	    $$ = cl;
	}	    
    ;

choice:
	expr_or_attr
	{
	  pIIR e = $1;
	  if (e->is(IR_ARRAY_RANGE))
	    $$ = mIIR_ChoiceByRange (@1, pIIR_ArrayRange(e));
	  else
	    $$ = mIIR_ChoiceByExpression (@1, validate_Expr(e));
	}
    |	discrete_range1
	{
	  $$ = mIIR_ChoiceByRange (@1, range_from_assoc ($1));
	}
    |	t_OTHERS
	{
	  $$ = mIIR_ChoiceByOthers (@1);
	}
    ;

/*--------------------------------------------------
--  Type Declarations
----------------------------------------------------*/

decl_Identifier:
	t_Identifier { start_decl($1); $$ = $1; }
    ;

type_decl:
	t_TYPE decl_Identifier opt_type_def t_Semicolon
	{ 
	    pIIR_TypeDeclaration td = add_type_decl(cur_scope, $3, $2);
	    add_predefined_ops(td->type);
	}
    ;

opt_type_def:
	/* nothing */		{ $$ = mVAUL_IncompleteType(int(0)); }
    |	t_IS type_definition	{ $$ = $2; }
    ;

type_definition:
	enumeration_type_definition     { $$ = $1; }
    |	range_constraint		{ $$ = build_SubType_def(@1, $1); }
    |	physical_type_definition        { $$ = $1; }
    |	unconstrained_array_definition  { $$ = $1; }
    |	constrained_array_definition    { $$ = $1; }
    |	record_type_definition          { $$ = $1; }
    |	access_type_definition          { $$ = $1; }	
    |	file_type_definition            { $$ = $1; }
    ;

enumeration_type_definition:
	t_LeftParen enumeration_literal_decls t_RightParen
	{
	  $$ = build_EnumerationType (@1, $2);
	}
    ;

enumeration_literal_decls:
	enumeration_literal opt_more_enumeration_literals
	{
	  pIIR_EnumerationLiteral el = pIIR_EnumerationLiteral (
		add_decl (mIIR_EnumerationLiteral(@1, $1, NULL, 0)));
	  $$ = mIIR_EnumerationLiteralList (@1, el, $2);
	}
    ;

opt_more_enumeration_literals:
	/* nothing */			    { $$ = NULL; }
    |	t_Comma enumeration_literal_decls   { $$ = $2; }
    ;

physical_type_definition:
	range_constraint t_UNITS
	    primary_unit_decl
	    secondary_unit_decls
	t_END t_UNITS
	{
	  pIIR_PhysicalType base = mIIR_PhysicalType (@2, $3, NULL);
	  if ($3) 
	    {
	      int unit_pos_counter = 0;
	      pIIR_UnitList ul = mIIR_UnitList (@3, $3, reverse ($4));
	      base->units = ul;
	      while (ul)
		{
		  pIIR_PhysicalUnit pu = ul->first;
		  if (pu->unit_name &&
		      pu->unit_name->type != base)
		      error("%:value of unit %n must be from its"
			    " physical type", pu, pu);
		  pu->type = base;
		  pu->unit_pos = unit_pos_counter++;
		  ul = ul->rest;
		}
	    }
	  $$ = build_SubType_def(@1, $1, base);
	}
    ;

secondary_unit_decls:
	/* nothing */	{ $$ = NULL; }
    |	secondary_unit_decls secondary_unit_decl
	{
	  $$ = mIIR_UnitList (@2, $2, $1);
	}
    ;

primary_unit_decl:
	t_Identifier t_Semicolon
	{
	  $$ = pIIR_PhysicalUnit(
		    add_decl(mIIR_PhysicalUnit (@1, $1, NULL, NULL, NULL, 0)));
	}
    ;

secondary_unit_decl:
	t_Identifier t_EQSym physical_literal t_Semicolon
	{
	  if ($3 && !$3->value->is (IR_INTEGER_LITERAL))
	    error ("secondary units must be integer multiples");
	  pIIR_AbstractLiteralExpression mult =
	    build_LiteralExpression (@3, $3->value);
	  mult->static_level = IR_LOCALLY_STATIC;
	  $$ = pIIR_PhysicalUnit(
		    add_decl(mIIR_PhysicalUnit(@1, $1, mult, $3->unit, NULL, 0)));
	}
    ;

unconstrained_array_definition:
	t_ARRAY t_LeftParen index_subtype_defs t_RightParen t_OF subtype_indic
	{
	    $$ = mIIR_ArrayType(@1, $3, $6);
	}
    ;

index_subtype_defs:
	index_subtype_definition opt_more_index_subtype_defs
	{
	  $$ = mIIR_TypeList (@1, $1, $2);
	}
    ;

opt_more_index_subtype_defs:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	t_Comma index_subtype_definition opt_more_index_subtype_defs
	{
	  $$ = mIIR_TypeList (@2, $2, $3);
	}
    ;

index_subtype_definition:
	mark t_RANGE t_Box
	{
	  $$ = get_type($1);
	}
    ;

constrained_array_definition:
	t_ARRAY index_constraint t_OF subtype_indic
	{
	    $$ = build_constrained_array_type($2, $4);
	}
    ;

opt_record_end:
	/* nothing */ 
        {
	  $$ = NULL;
	}
    |   t_Identifier
        { 
	  $$ = $1;
        }
    |   t_RECORD opt_t_Identifier
        {
	  $$ = $2;
	}
    ;   

record_type_definition:
	t_RECORD element_decl opt_more_element_decls t_END opt_record_end
	{
	  pIIR_ElementDeclarationList dl = concat ($2, $3);
	  int record_pos_counter = 0;
	  for (pIIR_ElementDeclarationList el = dl; el; el = el->rest)
	    el->first->declaration_pos = record_pos_counter++;

	  if ($5 != NULL
	      && !decls_in_flight(cur_scope).is_last ($5))
	    {
	      error ("%n does not match current record type name", $5);
	    }

	  $$ = mIIR_RecordType(@1, dl);
	}
    ;

opt_more_element_decls:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	opt_more_element_decls element_decl
	{
	    pIIR_ElementDeclarationList dl = concat($1, $2);
	    $$ = dl;
	    /* edwin, vorher: $$ = concat ($1, $2); */
	}
    ;

element_decl:
	idf_list t_Colon subtype_indic t_Semicolon
	{
	    $$ = NULL;
	    for(pIIR_IdentifierList idl = reverse($1); idl; idl = idl->rest)
	      {
		pIIR_ElementDeclaration re =
		  mIIR_ElementDeclaration (idl->pos, idl->first, $3, -1);
		$$ = mIIR_ElementDeclarationList (re->pos, re, $$);
	      }
	    $$ = reverse($$);
	}
    ;

access_type_definition:
	t_ACCESS subtype_indic_opt_incomplete
	{
	    if ($2 && $2->is(IR_FILE_TYPE)) 
	      {
		error("%:can't access files", $2);
		$2 = NULL;
	      }
	    $$ = mIIR_AccessType(@1, $2);
	    if ($2->is(VAUL_INCOMPLETE_TYPE))
	      vaul_add_incomplete_type_use (pVAUL_IncompleteType ($2),
					    $$->designated_type);
	}
    ;

file_type_definition:
	t_FILE t_OF mark
	{
	  $$ = build_FileType ($3);
	}
    ;

/*--------------------------------------------------
--  Subtypes and Constraints
----------------------------------------------------*/

subtype_decl:
	t_SUBTYPE decl_Identifier t_IS subtype_indic t_Semicolon
	{
	    if ($4 && $4->declaration)
	      {
		if ($4->is(IR_SCALAR_SUBTYPE) ||
		    $4->is(IR_SCALAR_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_ScalarSubtype (@2, $4->base,
				                       $4, NULL, NULL),
				   $2);
		  }
		else if ($4->is(IR_ARRAY_SUBTYPE) ||
	                 $4->is(IR_ARRAY_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_ArraySubtype(@2, $4->base,
				                     $4, NULL, NULL),
				   $2);
		  }
		else if ($4->is(IR_RECORD_SUBTYPE) ||
	                 $4->is(IR_RECORD_TYPE))
		  {
		    add_type_decl (cur_scope,
				   mIIR_RecordSubtype(@2, $4->base,
						      $4, NULL),
				   $2);
		  }
		else
		  {
		    info ("xxx - plain subtype of %s", $4->kind_name ());
		    add_type_decl (cur_scope,
				   mIIR_Subtype (@2, $4->base, $4, NULL),
				   $2);
		  }
	      }
	    else
	      add_type_decl (cur_scope, $4, $2);
	}
    ;

subtype_indic:
	subtype_indic_opt_incomplete
        {
	  if ($1->is(VAUL_INCOMPLETE_TYPE))
	    {
	      error ("type %n is incomplete", $1);
	      $$ = NULL;
	    }
	  else
	    $$ = $1;
	}
    ;
  
	
subtype_indic_opt_incomplete:
	mark opt_index_constraint   
        {
	  if ($2 == NULL)
	    {
	      // allow incomplete types here
	      pIIR_TypeDeclaration d = 
		pIIR_TypeDeclaration (find_single_decl ($1,
							IR_TYPE_DECLARATION,
							"type"));
	      $$ = (d? d->type : NULL);
	    }
	  else
	    $$ = build_ArraySubtype(NULL, $1, $2); 
	}
    |	subtype_indic1
    ;

subtype_indic1:
	mark mark range_constraint
        {
	  $$ = build_ScalarSubtype($1, $2, $3); 
	}
    |	mark range_constraint
        {
	  $$ = build_ScalarSubtype(NULL, $1, $2); 
	}
    |	mark mark opt_index_constraint
        {
	  $$ = build_Subtype ($1, $2, $3);
	}
    ;

opt_index_constraint:
	/* nothing */		{ $$ = NULL; }
    |	gen_association_list	{ $$ = build_PreIndexConstraint($1); }
    ;

range_constraint:
	t_RANGE range_spec2  { $$ = $2; }
    ;

index_constraint:
	t_LeftParen discrete_range opt_more_discrete_ranges t_RightParen
	{
	    if($2) {
		$2->next = reverse($3);
		$$ = build_PreIndexConstraint($2);
	    } else
		$$ = build_PreIndexConstraint($3);
	}
    ;
  
opt_more_discrete_ranges:
	/* nothing */ 
	{
	    $$ = NULL;
	}
    |	opt_more_discrete_ranges t_Comma discrete_range
	{
	    if($3) {
		$3->next = $1;
		$$ = $3;
	    } else
		$$ = $1;
	}
    ;

discrete_range:
	subtype_indic
	{
	    if(is_discrete_type($1))
		$$ = mVAUL_SubtypeAssocElem(@1, NULL, $1);
	    else {
		if($1)
		    error("%!%n is not a discrete type", lex, int(@1), $1);
		$$ = NULL;
	    }
	}
    |	range_spec
	{
	    $$ = mVAUL_RangeAssocElem(@1, NULL, $1);
	}
    ;

discrete_range1:
	subtype_indic1
	{
	  if (is_discrete_type($1))
	    $$ = mVAUL_SubtypeAssocElem (@1, NULL, $1);
	  else 
	    {
	      if ($1)
		error ("%!%n is not a discrete type", lex, int(@1), $1);
	      $$ = NULL;
	    }
	}
    |	expr_or_attr direction expr
	{
	    $$ = mVAUL_RangeAssocElem(@1, NULL,
                       mIIR_ExplicitRange(@2, validate_Expr($1), $3, $2));
	}
    ;


opt_direction_expr:
        /* nothing */
	{
	    $$ = NULL;
	}
    |	direction expr
	{
	  $$ = mIIR_ExplicitRange (@1, NULL, $2, $1);
	}
    ;


/* XXX - range_spec contains a shift/reduce conflict, because an
   attribute_name_with_param can be an expr.  range_spec2 solves this
   but can not be used as a discrete range because it conflicts with
   ordinary expressions.  I think.

   A possible solution would maybe be to elevate ranges to be
   expressions and disambiguate this purely on a semantic basis.  */

range_spec:
	range_attribute_name_with_param 
	{
	    pIIR n = build_Expr_or_Attr ($1);
	    if (n && n->is(IR_ARRAY_RANGE))
	      $$ = pIIR_ArrayRange (n);
	    else {
	      if (n)
 	        error ("%n not valid as range specification", n);
	      $$ = NULL;
	    }
	}
    |	expr direction expr 
	{
	  $$ = mIIR_ExplicitRange(@2, $1, $3, $2);
	}
    ;

range_spec2:
    	expr_or_attr opt_direction_expr
	{
	  if ($2)
	    {
	      $2->left = validate_Expr ($1);
	      $$ = $2;
	    }
	  else
	    {
	      if (!$1->is(IR_RANGE))
		{
		  error ("invalid range specification %n", $1);
		  $$ = NULL;
		}
	      else
		$$ = pIIR_Range($1);
	    }
	}
    ;

direction:
	t_TO	    { $$ = IR_DIRECTION_UP; }
    |	t_DOWNTO    { $$ = IR_DIRECTION_DOWN; }
    ;

/*--------------------------------------------------
--  Objects, Aliases, Files, Disconnections
----------------------------------------------------*/

constant_decl:
	t_CONSTANT idf_list t_Colon subtype_indic opt_var_init t_Semicolon
	{
	  if ($5 == NULL && !cur_scope->is(IR_PACKAGE_DECLARATION))
	    error ("constants must be initialized");
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Constant, $4, $5);
	  overload_resolution ($5, t);
	  for (pIIR_IdentifierList idl = $2; idl; idl = idl->rest)
	    add_decl (mIIR_ConstantDeclaration (@2, idl->first, t, $5));
	}
    ;
  

signal_decl:
	t_SIGNAL idf_list t_Colon subtype_indic
	    opt_signal_kind opt_var_init t_Semicolon
	{
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Signal, $4, $6);
	  overload_resolution ($6, t);
	  for (pIIR_IdentifierList idl = $2; idl; idl = idl->rest)
	    add_decl (mIIR_SignalDeclaration (@2, idl->first, t, $6, $5));
	}
    ;

opt_signal_kind:
	/* nothing */	{ $$ = IR_NO_SIGNAL_KIND; }
    |	signal_kind
    ;

variable_decl:
	t_VARIABLE idf_list t_Colon subtype_indic opt_var_init t_Semicolon
	{
	  pIIR_Type t = adapt_object_type (VAUL_ObjClass_Variable, $4, $5);
	  overload_resolution ($5, t);
	  for (pIIR_IdentifierList idl = $2; idl; idl = idl->rest)
	    add_decl (mIIR_VariableDeclaration (@2, idl->first, t, $5));
	}
    ;

opt_var_init:  
	/* nothing */	    { $$ = NULL; }
    |	t_VarAsgn expr	    { $$ = $2; }
    ;

object_class:
	t_CONSTANT  { $$ = VAUL_ObjClass_Constant; }
    |	t_SIGNAL    { $$ = VAUL_ObjClass_Signal; }
    |	t_VARIABLE  { $$ = VAUL_ObjClass_Variable; }
    |	t_FILE	    { $$ = VAUL_ObjClass_File; }
    ;

signal_kind:
	t_BUS	    { $$ = IR_BUS_KIND; }
    |	t_REGISTER  { $$ = IR_REGISTER_KIND; }
    ;

alias_decl:
	t_ALIAS t_Identifier t_Colon subtype_indic t_IS name t_Semicolon
	{
	    add_Alias ($2, $4, $6);
	}
    ;  

file_decl:
	t_FILE t_Identifier t_Colon subtype_indic opt_open_mode opt_file_name
	  t_Semicolon
	{
	    add_File ($2, $4, $5, $6);
	}
    ;

opt_open_mode:
	/* nothing */
	{
	    $$ = NULL; 
	}
    |	t_OPEN expr
	{
	    pIIR_Expression e = $2;
	    overload_resolution(e, std->predef_FILE_OPEN_KIND);
	    $$ = e;
	}
    ;

opt_file_name:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	t_IS opt_file_mode expr
	{
	    pIIR_Expression e = $3;
	    overload_resolution(e, std->predef_STRING);
	    $$ = mVAUL_FilenameAndMode (e, $2);
	}
    ;

opt_file_mode:
        /* nothing */
        {
	  $$ = IR_UNKNOWN_MODE;
	}
    |   t_IN
        {
	  $$ = IR_IN_MODE;
	}
    |   t_OUT
        {
	  $$ = IR_OUT_MODE;
	}
    ;

disconnection_spec:
	t_DISCONNECT signal_list t_Colon mark t_AFTER expr t_Semicolon
	{
	  add_disconnect_spec ($2, $4, $6);
	}
    ;

signal_list:
	signal_name opt_more_signal_list 
	{
	    $1->rest = $2;
	    $$ = $1;
	}
    |	t_OTHERS                  
	{ 
	    info ("XXX - no OTHERS signals");
	    $$ = NULL;
	}
    |	t_ALL
	{
	    info ("XXX - no ALL signals");
	    $$ = NULL;
	}
    ;

opt_more_signal_list:
	/* nothing */             { $$ = NULL; }
    |	opt_more_signal_list t_Comma signal_name
	{
	  if ($1)
	    {
	      pIIR_ExpressionList sl = $1;
	      while (sl->rest)
		sl = sl->rest;
	      sl->rest = $3;
	      $$ = $1;
	    }
	  else
	    $$ = $3;
	}
    ;

/*--------------------------------------------------
--  Attribute Declarations and Specifications
----------------------------------------------------*/

attribute_decl:
	t_ATTRIBUTE t_Identifier t_Colon mark t_Semicolon
	{
	    pIIR_Type t = get_type($4);
	    if(t) {
		pIIR_Type bt = vaul_get_base (t);
		if(bt && bt->is(IR_ACCESS_TYPE))
		    error("%!attributes can't have access types",
			     lex, int(@1));
		else if(bt && bt->is(IR_FILE_TYPE))
		    error("%!attributes can't have file types",
			     lex, int(@1));
		else
		    add_decl (mIIR_AttributeDeclaration(@1, $2, t));
	    }
	}
    ;

attribute_spec:
	t_ATTRIBUTE t_Identifier t_OF entity_spec t_IS expr t_Semicolon
	{
	    bind_attrspec (mVAUL_AttributeSpec(@1, $2, $4, $6));
	}
    ;

entity_spec:
	entity_name_list t_Colon entity_class
	{
	    $$ = mVAUL_EntitySpec(@1, $1, $3);
	}
    ;

entity_name_list:
	designator opt_more_entity_name_list
	{
	  $$ = mVAUL_EntityNameList_Ids (@1, mVAUL_DesigList (@1, $1,
	                                                      reverse($2)));
	}
    |	t_OTHERS
	{
	  $$ = mVAUL_EntityNameList_OTHERS (@1);
	}
    |	t_ALL
	{
	  $$ = mVAUL_EntityNameList_ALL (@1);
	}
    ;

opt_more_entity_name_list:
	/* nothing */	{ $$ = NULL; }
    |	opt_more_entity_name_list t_Comma designator
	{
	  $$ = mVAUL_DesigList (@3, $3, $1);
	}
    ;

entity_class:
	t_ENTITY	{ $$ = IR_ENTITY_DECLARATION; }
    |	t_ARCHITECTURE  { $$ = IR_ARCHITECTURE_DECLARATION; }
    |	t_PACKAGE       { $$ = IR_PACKAGE_DECLARATION; }
    |	t_CONFIGURATION { $$ = IR_CONFIGURATION_DECLARATION; }
    |	t_COMPONENT     { $$ = IR_COMPONENT_DECLARATION; }
    |	t_LABEL         { $$ = IR_LABEL; }
    |	t_TYPE          { $$ = IR_TYPE; }
    |	t_SUBTYPE       { $$ = IR_SUBTYPE; }
    |	t_PROCEDURE     { $$ = IR_PROCEDURE_DECLARATION; }
    |	t_FUNCTION      { $$ = IR_FUNCTION_DECLARATION; }
    |	t_SIGNAL        { $$ = IR_SIGNAL_DECLARATION; }
    |	t_VARIABLE      { $$ = IR_VARIABLE_DECLARATION; }
    |	t_CONSTANT      { $$ = IR_CONSTANT_DECLARATION; }
    ;

/*--------------------------------------------------
--  Schemes
----------------------------------------------------*/

generation_scheme:
	if_scheme    { $$ = $1; }
    |	for_scheme   { $$ = $1; }
    ;

iteration_scheme:
	for_scheme   { $$ = $1; }
    |	while_scheme { $$ = $1; }
    ;

if_scheme:
	t_IF condition { $$ = mVAUL_IfScheme (@1, $2); }
    ;

for_scheme:
	t_FOR t_Identifier t_IN discrete_range
	{
	  pIIR_TypeList r = build_PreIndexConstraint($4);
	  $$ = mVAUL_ForScheme(@1, $2, r? r->first:NULL);
	}
    ;

while_scheme:
	t_WHILE condition { $$ = mVAUL_WhileScheme(@1, $2); }
    ;

/*--------------------------------------------------
--  Concurrent Statements
----------------------------------------------------*/

concurrent_stats:
	opt_concurrent_stats concurrent_stat
    ;

opt_concurrent_stats:
	/* nothing */
    |	opt_concurrent_stats concurrent_stat
    ;

concurrent_stat:
        {
          closing_label = NULL;
          starting_label = NULL;
        }
        concurrent_stat_1
    ;

concurrent_stat_1:
        concurrent_stat_without_label
    |   concurrent_stat_with_label
    ;

concurrent_stat_without_label:
	concurrent_stat_without_label_1
	{
	  if ($1)
	    {
	      if (closing_label
		  && !vaul_name_eq (closing_label, $1->declarator))
		{
		  if ($1->declarator)
		    error ("%n does not match label %n",
			   closing_label, $1->declarator);
		  else if ($1->is (IR_PROCESS_STATEMENT))
		    error ("process has no label");
		  else
		    error ("concurrent statement has no label");
		}
	      add_to_concurrent_stats_tail ($1);
	    }
	  collect ();
	}
    ;

concurrent_stat_with_label:
        t_Identifier t_Colon 
        {
	  starting_label = $1;

	  // $1 needs to survive any garbage collection that might
	  // happen during nested concurrent statements.
	  tree_protect ($1);
	}
	concurrent_stat_with_label_1
	{
	  if ($4)
	    {
	      $4->declarator = $1;
	      invalidate_decl_cache ($1);
	      if (closing_label
		  && !vaul_name_eq (closing_label, $4->declarator))
		{
		  error ("%n does not match label %n",
			   closing_label, $4->declarator);
		}
	      add_to_concurrent_stats_tail ($4);
	    }
	  tree_unprotect ($1);
	  collect ();
	}
    ;

concurrent_stat_without_label_1:
    	concurrent_assertion_stat
    |	concurrent_procedure_call
    |	concurrent_signal_assign_stat
    |	proc_stat
    ;

concurrent_stat_with_label_1:
	block_stat
    |	comp_inst_stat
    |	concurrent_assertion_stat
    |	concurrent_procedure_call
    |	concurrent_signal_assign_stat
    |	generate_stat
    |	proc_stat
    ;

block_stat:
	t_BLOCK block_guard opt_t_IS
	{
	  pIIR_BlockStatement b = mIIR_BlockStatement (@1, NULL, $2, NULL);
	  add_decl (cur_scope, b, starting_label);
	  push_scope (b);
	  if ($2)
	    add_decl (mVAUL_GuardSignal(@2, make_id("GUARD"),
	                                std->predef_BOOLEAN, $2,
	                                IR_NO_SIGNAL_KIND));
	  $<tree.IIR_BlockStatement>$ = b;
	}
	    block_generic_stuff
            {
	      pIIR_BlockStatement b = $<tree.IIR_BlockStatement>4;
	      b->generic_map_aspect = associate ($5, b->generic_clause, false);
	    }
	    block_port_stuff
            {
	      pIIR_BlockStatement b = $<tree.IIR_BlockStatement>4;
	      b->port_map_aspect = associate_ports ($7, b->port_clause);
	    }
	    block_decl_part
	t_BEGIN
            {
	      pIIR_BlockStatement b = $<tree.IIR_BlockStatement>4;
	      push_concurrent_stats_tail (&b->block_statement_part);
	    }
	    opt_concurrent_stats
	t_END t_BLOCK opt_t_Identifier t_Semicolon
	{
	  pIIR_BlockStatement b = $<tree.IIR_BlockStatement>4;
	  closing_label = $15;
	  pop_concurrent_stats_tail (&b->block_statement_part);
	  pop_scope (b);
	  $$ = b;
	}
    ;

block_decl_part:
	/* nothing */
    |	block_decl_part block_decltve_item
    ;

block_port_stuff:
	/* nothing */			{ $$ = NULL; }
    |	port_clause opt_port_map_semi   { $$ = $2; }
    ;

block_generic_stuff:
	/* nothing */			    { $$ = NULL; }
    |	generic_clause opt_generic_map_semi { $$ = $2; }
    ;

block_guard:
	/* nothing */			    { $$ = NULL; }
    |	t_LeftParen condition t_RightParen  { $$ = $2; }
    ;

opt_port_map_semi:
	/* nothing */            { $$ = NULL; }
    |	port_map t_Semicolon     { $$ = $1; }
    ;

opt_generic_map_semi:
	/* nothing */            { $$ = NULL; }
    |	generic_map t_Semicolon  { $$ = $1; }
    ;

/*
comp_inst_stat:
	t_Identifier t_Colon comp_inst_unit
	    opt_generic_map
	    opt_port_map
	t_Semicolon
	{
	    $$ = mComponentInst(@3, $1, build_BindingIndic($3, $4, $5));
	    add_decl($$);
	}
    ;
*/

comp_inst_stat:
	comp_mark
	    t_GENERIC t_MAP named_association_list
	    opt_port_map
	t_Semicolon
	{
	  $$ = build_CompInst (@1, starting_label,
			       build_BindingIndic(make_posinfo (@1),
						  $1, $4, $5));
	  add_decl($$);
	}

    |	comp_mark
	    t_PORT t_MAP named_association_list
	    opt_generic_map
	t_Semicolon
	{
	  $$ = build_CompInst (@1, starting_label,
			       build_BindingIndic(make_posinfo (@1),
						  $1, $5, $4));
	  add_decl($$);
	}
    |   comp_mark_with_keyword
            opt_generic_map
            opt_port_map
        t_Semicolon
        {
	  $$ = build_CompInst (@1, starting_label,
			       build_BindingIndic (make_posinfo (@1),
						   $1, $2, $3));
	  add_decl ($$);
	}
    ;

comp_mark_with_keyword:
	t_COMPONENT comp_mark                 
        {
	  $$ = $2; 
	}
    |   t_ENTITY simple_sel_name opt_arch_id  
        {
	  $$ = get_architecture_ref (@1, $2, $3);
	}
    |   t_CONFIGURATION mark
        {
	  $$ = get_configuration ($2);
	}
    ;

/* NOTE: component instantiation statements without a keyword look
**	 like concurrent procedure calls
*/

opt_generic_map:
	/* nothing */	{ $$ = NULL; }
    |	generic_map
    ;

generic_map:
	t_GENERIC t_MAP named_association_list    { $$ = $3; }
    ;

opt_port_map:
	/* nothing */			{ $$ = NULL; }
    |	port_map
    ;

port_map:
    	t_PORT t_MAP named_association_list	{ $$ = $3; }
    ;

concurrent_assertion_stat:
    	assertion_stat
	{
	  $$ = build_conc_AssertStat (@1, NULL, false, $1);
	}

    |	t_POSTPONED assertion_stat
	{
	  $$ = build_conc_AssertStat(@1, NULL, true, $2);
	}
    ;

concurrent_procedure_call:
        mark t_Semicolon
	{
	  $$ = build_conc_ProcedureCall_or_ComponentInst (@1, NULL, $1);
	}

    |   procedure_call_stat_with_args
	{
	  $$ = build_conc_ProcedureCall (@1, NULL, false, $1);
	}

    |	t_POSTPONED procedure_call_stat
	{
	  $$ = build_conc_ProcedureCall (@1, NULL, true, $2);
	}
    ;

opt_postponed:
	/* nothing */ { $$ = false; }
    |	t_POSTPONED   { $$ = true; }
    ;

concurrent_signal_assign_stat:
    	condal_signal_assign
    	{
	  $$ = build_condal_Process (NULL, false, $1);
	}

    |	t_POSTPONED condal_signal_assign
    	{
	  $$ = build_condal_Process (NULL, true, $2);
	}

|	sel_signal_assign
    	{
	  $$ = build_sel_Process (NULL, false, $1);
	}

|	t_POSTPONED sel_signal_assign
        {
	  $$ = build_sel_Process (NULL, true, $2);
	}
    ;

condal_signal_assign:
    	target t_LESym opt_guarded delay_mechanism condal_wavefrms t_Semicolon
    	{
	  $$ = mVAUL_CondalSignalAssign (@2, $1, $3, $4, $5);
	}
    ;

condal_wavefrms:
    	condal_wavefrms_1 wavefrm
    	{
	  pVAUL_CondalWaveform w = mVAUL_CondalWaveform (@2, $2, NULL);
	  if (($$ = $1) != NULL)
	    {
	      while ($1->else_wave)
		$1 = $1->else_wave;
	      $1->else_wave = w;
    	    } 
	  else
	    $$ = w;
    	}
    ;

condal_wavefrms_1:
    	/* nothing */ { $$ = NULL; }
    |	condal_wavefrms_1 wavefrm t_WHEN condition t_ELSE
    	{
	  pVAUL_CondalWaveform w = mVAUL_CondalWaveform (@2, $2, $4);
	  if (($$ = $1) != NULL)
	    {
	      while ($1->else_wave)
		$1 = $1->else_wave;
	      $1->else_wave = w;
    	    } 
	  else
	    $$ = w;
    	}
    ;

wavefrm:
	wavefrm_element reverse_more_wavefrm
	{
	  $2 = reverse ($2);
	  if ($1) 
	    {
	      $1->rest = $2;
	      $$ = $1;
	    }
	  else
	    $$ = $2;
	}
    ;

reverse_more_wavefrm:
	/* nothing */	{ $$ = NULL; }
    |	reverse_more_wavefrm t_Comma wavefrm_element
	{
	  if ($3) 
	    {
	      $3->rest = $1;
	      $$ = $3;
	    }
	  else
	    $$ = $1;
	}
    ;

wavefrm_element:
	expr opt_wavefrm_after
	{
	  $$ = mIIR_WaveformList (@1, mIIR_WaveformElement (@1, $1, $2), NULL);
	}
    ;

opt_wavefrm_after:
	/* nothing */	{ $$ = NULL; }
    |	t_AFTER expr	{ $$ = $2; overload_resolution($$, std->predef_TIME); }
    ;

target:
	name	    { $$ = build_Expr($1); }
    |	aggregate   { $$ = $1; }
    ;

opt_guarded:
	/* nothing */   { $$ = false; }
    |	t_GUARDED	{ $$ = true; }
    ;

sel_signal_assign:
	t_WITH expr t_SELECT target t_LESym opt_guarded delay_mechanism
                                            sel_wavefrms t_Semicolon
        {
	  $$ = mVAUL_SelSignalAssign (@1, $2, $4, $6, $7, $8);
	}
    ;

sel_wavefrms:
	sel_wavefrms_1 wavefrm t_WHEN choices
        {
	  $$ = mVAUL_SelWaveform (@3, $2, $4, $1);
	}
    ;

sel_wavefrms_1:
	/* nothing */
        {
	  $$ = NULL;
	}
    |	sel_wavefrms_1 wavefrm t_WHEN choices t_Comma
        {
          $$ = mVAUL_SelWaveform (@3, $2, $4, $1);
	}
    ;

generate_stat:
	generation_scheme t_GENERATE
	{
	  pIIR_ConcurrentGenerateStatement g = push_GenerateStat (@2, $1);
	  push_concurrent_stats_tail (&g->concurrent_statement_part);
	  $<tree.IIR_ConcurrentGenerateStatement>$ = g;
	}
          generate_declarative_items_block
	  concurrent_stats
	t_END t_GENERATE opt_t_Identifier t_Semicolon
	{
	  pIIR_ConcurrentGenerateStatement g =
	    $<tree.IIR_ConcurrentGenerateStatement>3;
	  closing_label = $8;
	  pop_scope (g);
	  pop_concurrent_stats_tail (&g->concurrent_statement_part);
	  $$ = g;
	}
    ;

generate_declarative_items_block:
	  /* nothing */
    |     generate_declarative_items t_BEGIN
    ;

generate_declarative_items:
          /* nothing */
    |     generate_declarative_items generate_declarative_item
    ;

generate_declarative_item:
	  common_decltve_item
    |     subprog_body
    |	  comp_decl
    |	  attribute_decl
    |	  attribute_spec
    |	  config_spec
    |	  disconnection_spec
    |	  signal_decl
    ;

proc_stat:
	t_PROCESS opt_proc_sensitivity_list opt_t_IS
	{
	  pIIR_ProcessStatement p = build_Process (@1, $2, false);
	  add_decl (p);
	  push_scope (p);
	  $<tree.IIR_ProcessStatement>$ = p;
	}
	    proc_decl_part
	t_BEGIN
	    seq_stats
	t_END opt_postponed t_PROCESS opt_t_Identifier t_Semicolon
	{
	  $<tree.IIR_ProcessStatement>4->process_statement_part = $7;
	  if ($9)
	    error ("process is not postponed");
	  closing_label = $11;
	  $$ = $<tree.IIR_ProcessStatement>4;
	  pop_scope($$);
	}

    |	t_POSTPONED t_PROCESS opt_proc_sensitivity_list opt_t_IS
	{
	  pIIR_ProcessStatement p = build_Process (@2, $3, true);
	  add_decl (p);
	  push_scope (p);
	  $<tree.IIR_ProcessStatement>$ = p;
	}
	    proc_decl_part
	t_BEGIN
	    seq_stats
	t_END opt_postponed t_PROCESS opt_t_Identifier t_Semicolon
	{
	  $<tree.IIR_ProcessStatement>5->process_statement_part = $8;
	  closing_label = $12;
	  $$ = $<tree.IIR_ProcessStatement>5;
	  pop_scope ($$);
	}
    ;

opt_t_IS:
	/* nothing */
    |	t_IS
    ;

proc_decl_part:
	/* nothing */
    |	proc_decl_part proc_decltve_item
    ;

opt_proc_sensitivity_list:
	/* nothing */				    { $$ = no_sens_list; }
    |	t_LeftParen sensitivity_list t_RightParen   { $$ = $2; }
    ; 

sensitivity_list:
	signal_name reverse_opt_more_sensitivities
	{
	    $1->rest = reverse ($2);
	    $$ = $1;
	}
    ;

reverse_opt_more_sensitivities:	 
	/* nothing */	{ $$ = NULL; }
    |	reverse_opt_more_sensitivities t_Comma signal_name
	{
	    $3->rest = $1;
	    $$ = $3;
	}	
    ;

signal_name:
	name
	{
	  pIIR_Expression e = build_Expr ($1);
	  overload_resolution (e, IR_TYPE);
	  if (e && (!e->is(IR_OBJECT_REFERENCE)
		    || !is_signal (pIIR_ObjectReference(e))))
	    {
	      error ("%:%n is not a signal", $1, $1);
	      e = NULL;
	    }
	  $$ = mIIR_ExpressionList (@1, e, NULL);
	}
    ;

/*--------------------------------------------------
--  Sequential Statements
----------------------------------------------------*/

seq_stats:
	rev_seq_stats	{ $$ = reverse($1); }
    ;

rev_seq_stats:
	/* nothing */		{ $$ = NULL; }
    |	rev_seq_stats seq_stat	
	{
	  if ($2) 
	    $$ = mIIR_SequentialStatementList (@2, $2, $1);
	  else
	    $$ = $1;
	  /* XX - make it safe to put a call to collect here. */
	  // collect ();
	}
    ;

seq_stat:
	assertion_stat        { $$ = $1; }
    |   report_stat           { $$ = $1; }
    |	case_stat             { $$ = $1; }
    |	exit_stat             { $$ = $1; }
    |	if_stat               { $$ = $1; }
    |	loop_stat             { $$ = $1; }
    |	next_stat             { $$ = $1; }
    |	null_stat             { $$ = $1; }
    |	procedure_call_stat   { $$ = $1; }
    |	return_stat           { $$ = $1; }
    |	signal_assign_stat    { $$ = $1; }
    |	variable_assign_stat  { $$ = $1; }
    |	wait_stat             { $$ = $1; }
    ;

assertion_stat:
	t_ASSERT condition opt_assertion_report opt_assertion_severity
	 t_Semicolon
	{
	  $$ = mIIR_AssertionStatement (@1, $2, $3, $4);
	}
    ;

report_stat:
	t_REPORT expr opt_assertion_severity t_Semicolon
	{
	  overload_resolution ($2, std->predef_STRING);
	  $$ = mIIR_ReportStatement (@1, $2, $3);
	}
    ;

opt_assertion_severity:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	t_SEVERITY expr
	{
	    $$ = $2;
	    overload_resolution($$, std->predef_SEVERITY_LEVEL);
	}
    ;

opt_assertion_report:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	t_REPORT expr
	{
	    $$ = $2;
	    overload_resolution($$, std->predef_STRING);
	}
    ;

case_stat:
	t_CASE expr t_IS 
	    case_stat_alternative
	    more_case_stat_alternatives 
	t_END t_CASE t_Semicolon
	{
	  pIIR_CaseStatementAlternativeList ca = reverse ($5);
	  if ($4)
	    {
	      $4->rest = ca;
	      ca = $4;
	    }
	  $$ = build_CaseStat (make_posinfo(@1), $2, ca);
	}
    ;

case_stat_alternative:
	t_WHEN choices t_Arrow seq_stats
	{
	  $$ = mIIR_CaseStatementAlternativeList (@1,
	     mIIR_CaseStatementAlternative (@1, $4, $2), NULL);
	}
    ;

more_case_stat_alternatives:
	/* nothing */
	{
	    $$ = NULL;
	}
    |	more_case_stat_alternatives case_stat_alternative
	{
	    if($2) {
		$2->rest = $1;
		$$ = $2;
	    } else
		$$ = $1;
	}
    ;

if_stat:
	t_IF condition t_THEN seq_stats if_stat_1 if_stat_2 t_END t_IF
	t_Semicolon
	{
	  $$ = mIIR_IfStatement (@1, $2, $4, $5);
	  if ($6)
	    {
	      pIIR_SequentialStatementList *s;
	      for (s = &(pIIR_IfStatement($$)->else_sequence);
		   *s && (*s)->first->is(IR_IF_STATEMENT);
		   s = &(pIIR_IfStatement((*s)->first)->else_sequence))
		;
	      assert (*s == NULL);
	      *s = $6;
	    }
	}
    ;

if_stat_2:
	/* nothing */	    { $$ = NULL; }
    |	t_ELSE seq_stats    { $$ = $2; }
    ;

if_stat_1:
	/* nothing */	    { $$ = NULL; }
    |	if_stat_1  t_ELSIF condition t_THEN seq_stats
	{
	  $$ = mIIR_SequentialStatementList (@2,
	                                     mIIR_IfStatement (@2, $3, $5,
					                       NULL),
	                                     NULL);
	  if ($1)
	    {
	      assert ($1->is(IR_SEQUENTIAL_STATEMENT_LIST));
	      pIIR_SequentialStatementList sl =
		pIIR_SequentialStatementList($1);
	      assert (sl->first && sl->rest == NULL &&
		      sl->first->is(IR_IF_STATEMENT));
	      pIIR_SequentialStatementList *s;
	      for (s = &(pIIR_IfStatement(sl->first)->else_sequence);
		   *s && (*s)->first->is(IR_IF_STATEMENT);
		   s = &(pIIR_IfStatement((*s)->first)->else_sequence))
		;
	      assert (*s == NULL);
	      *s = $$;
	      $$ = $1;
	    }
	}
    ;

condition:
	expr 
        {
	  overload_resolution ($1, std->predef_BOOLEAN);
	  $$ = $1; 
	}
    ;

loop_stat:
	opt_label opt_iteration_scheme t_LOOP
	{ 
	    pIIR_LoopStatement l = push_loop(@3, $1, $2);
	}
	    seq_stats
	t_END t_LOOP opt_t_Identifier t_Semicolon
	{
	    $$ = pop_loop($5, $8);
	}
    ;

opt_iteration_scheme:
	/* nothing */	    { $$ = NULL; }
    |	iteration_scheme    { $$ = $1; }
    ;

opt_label:
	/* nothing */	     { $$ = NULL; }
    |	t_Identifier t_Colon 
        {
	  $$ = pIIR_Label (add_decl (mIIR_Label(@1, $1, NULL))); 
	}
    ;

next_stat:
	t_NEXT opt_t_Identifier opt_when t_Semicolon
	{   
	    $$ = build_LoopControlStat(@1, IR_NEXT_STATEMENT, $2, $3);
	}
    ;

exit_stat:
	t_EXIT opt_t_Identifier opt_when t_Semicolon
	{   
	    $$ = build_LoopControlStat(@1, IR_EXIT_STATEMENT, $2, $3);
	}
    ;

opt_when:
	/* nothing */	    { $$ = NULL; }
    |	t_WHEN condition    { $$ = $2; }
    ;

null_stat:
	t_NULL t_Semicolon  { $$ = mIIR_NullStatement(@1); }
    ;

procedure_call_stat:
        procedure_call_stat_without_args   { $$ = $1; }
    |   procedure_call_stat_with_args      { $$ = $1; }
    ;

procedure_call_stat_without_args:
	mark t_Semicolon
	{
	    $$ = build_ProcedureCallStat (@1, $1);
	}
    ;

procedure_call_stat_with_args:
	name2 t_Semicolon
	{
	    $$ = build_ProcedureCallStat (@1, $1);
	}
    ;

return_stat:
	t_RETURN opt_expr t_Semicolon
	{
	  if (cur_body == NULL || $2 == NULL)
	    $$ = NULL;
	  else if (cur_body->is(IR_FUNCTION_DECLARATION))
	    {
	      if ($2->is(IR_OPEN_EXPRESSION))
		{
		  error ("return without a value");
		  $$ = NULL;
		}
	      else 
		{
		  overload_resolution($2,
			   pIIR_FunctionDeclaration(cur_body)->return_type);
		  $$ = mIIR_ReturnStatement (@1, cur_body, $2);
		}
	    } 
	  else if (cur_body->is(IR_PROCEDURE_DECLARATION))
	    {
	      if (!$2->is(IR_OPEN_EXPRESSION))
		{
		  error ("return with a value");
		  $$ = NULL;
		}
	      else
		$$ = mIIR_ReturnStatement (@1, cur_body, NULL);
	    }
	  else
	    {
	      error ("can only return from subprograms");
	      $$ = NULL;
	    }
	}
    ;

opt_expr:
	/* nothing */	{ $$ = mIIR_OpenExpression(-1, NULL); }
    |	expr
    ;

signal_assign_stat:
	target t_LESym delay_mechanism wavefrm t_Semicolon
	{
	    $$ = build_SignalAssignment(make_posinfo(@2), $1, $3, $4);
	}
    ;

delay_mechanism:
	/* nothing */  { $$ = mVAUL_DelayInertial ((IIR_PosInfo *)NULL, NULL); }
    |   t_TRANSPORT    { $$ = mVAUL_DelayTransport (@1); }
    |   t_INERTIAL     { $$ = mVAUL_DelayInertial (@1, NULL); }
    |	t_REJECT expr t_INERTIAL 
        {
	    pIIR_Expression rtime = $2;
	    overload_resolution (rtime, std->predef_TIME);
	    $$ = mVAUL_DelayInertial (@1, rtime);
	}
    ;

variable_assign_stat:
	target t_VarAsgn expr t_Semicolon
	{
	    $$ = build_VarAssignment(@2, $1, $3);
	}
    ;

wait_stat:
	t_WAIT opt_wait_on opt_wait_until opt_wait_for t_Semicolon
	{
	    $$ = mIIR_WaitStatement (@1, $3, $4, $2);
	}
    ;

opt_wait_for:
	/* nothing */	{ $$ = NULL; }
    |	t_FOR expr	{ $$ = $2; overload_resolution($$, std->predef_TIME); }
    ;

opt_wait_until:
	/* nothing */	    { $$ = NULL; }
    |	t_UNTIL condition   { $$ = $2; }
    ;

opt_wait_on:
	/* nothing */		{ $$ = NULL; }
    |	t_ON sensitivity_list	{ $$ = $2; }
    ;

/*--------------------------------------------------
--  Components and Configurations
----------------------------------------------------*/

comp_decl:
	t_COMPONENT t_Identifier opt_t_IS
	{
	  pIIR_ComponentDeclaration c = mIIR_ComponentDeclaration (@1, $2);
	  add_decl (c);
	  push_scope (c);
	  $<tree.IIR_ComponentDeclaration>$ = c;
	}
	    opt_generic_and_port_clauses
	t_END t_COMPONENT opt_t_Identifier t_Semicolon
	{
	  if ($8 && !vaul_name_eq($8, $2))
	    error("%n does not match component name %n", $8, $2);
	  pop_scope ($<tree.IIR_ComponentDeclaration>4);
	}
    ;

block_config:
	t_FOR name { $<tree.IIR_BlockConfiguration>$ = start_BlockConfig($2); }
    	    use_clauses
    	    config_items
    	t_END t_FOR t_Semicolon
    	{
    	    $$ = $<tree.IIR_BlockConfiguration>3;
    	    if($$) {
    	    	check_BlockConfig($$);
    		pop_scope($$);
    	    }
    	}
    ;

config_items:
 	/* nothing */		    { }
    |	config_items config_item    { }
    ;

use_clauses:
	/* nothing */
    |	use_clauses use_clause { use($2); }
    ;

config_item:
	block_config  { $$ = $1; }
    |	comp_config   { $$ = $1; }
    ;

comp_config:
	t_FOR comp_spec opt_comp_binding_indic
    	{ $<tree.IIR_ComponentConfiguration>$ = start_CompConfig(@1, $2, $3); }
    	    opt_block_config
	t_END t_FOR t_Semicolon
    	{
    	    pIIR_ComponentConfiguration cc =
	      $<tree.IIR_ComponentConfiguration>4;
    	    if(cc) {
       	    	cc->block_config = $5;
    		pop_scope(cc);
    	    }
    	}
    ;

opt_block_config:
	/* nothing */	{ $$ = NULL; }
    |	block_config	{ $$ = $1; }
    ;

opt_comp_binding_indic:
    	/* nothing */	{ $$ = NULL; }
    |  	incremental_binding_indic t_Semicolon { $$ = $1; }
    |	pre_binding_indic t_Semicolon { $$ = $1; }
    ;

config_spec:
	t_FOR comp_spec binding_indic t_Semicolon
	{
	  pVAUL_ConfigSpec cs = mVAUL_ConfigSpec (@1, $2, $3);
	  add_spec (cur_scope, cs);
	}
    ;

comp_spec:
	inst_list t_Colon comp_mark
	{
	  $$ = mVAUL_ComponentSpec (@1, $1, $3);
	  select_scope ($3);
	}
    ;

comp_mark:
	mark
	{
	  $$ = pIIR_ComponentDeclaration(
		 find_single_decl ($1, IR_COMPONENT_DECLARATION,
				   "component"));
	}
    ;

inst_list:
	idf_list    { $$ = mVAUL_InstList_Ids(@1, $1); }
    |	t_ALL	    { $$ = mVAUL_InstList_ALL(@1); }
    |	t_OTHERS    { $$ = mVAUL_InstList_OTHERS(@1); }
    ;

/* binding_indic et al is to be invoked with the component decl
** as the selected scope
*/

binding_indic:
    	pre_binding_indic { $$ = build_BindingIndic($1); }
    ;

pre_binding_indic:
	{ $<tree.IIR_DeclarativeRegion>$ = selected_scope; unselect_scope(); }
	t_USE entity_aspect
	{ select_scope($<tree.IIR_DeclarativeRegion>1); }
	opt_generic_map opt_port_map
	{
	    $$ = mVAUL_IncrementalBindingIndic(@1, $3, $5, $6);
	    unselect_scope();
	}
    ;

incremental_binding_indic:
	generic_map opt_port_map
	{
	    $$ = mVAUL_IncrementalBindingIndic(@1, NULL, $1, $2);
	    unselect_scope();
	}
    |	port_map
    	{
    	    $$ = mVAUL_IncrementalBindingIndic(@1, NULL, NULL, $1);
    	    unselect_scope();
    	}
    ;

entity_aspect:
	t_ENTITY simple_sel_name opt_arch_id
	{
	  $$ = get_architecture_ref (@1, $2, $3); 
	}
    |	t_CONFIGURATION mark
	{
	  $$ = get_configuration($2); 
	}
    |	t_OPEN
	{
	  $$ = NULL; 
	}
    ;

opt_arch_id:
	/* nothing */				{ $$ = NULL; }
    |	t_LeftParen t_Identifier t_RightParen	{ $$ = $2; }
    ;

/* This is a second copy of the grammar that does nothing.  It is used
   to skip over unwanted parts. */

skip_designator:
t_Identifier {}
|	t_StringLit {}
    ;

skip_literal:
	t_AbstractLit		    
{}
|	t_CharacterLit {}
|	skip_physical_literal_no_default {}
|	t_NULL {}
    ;

skip_enumeration_literal:
t_CharacterLit {}
|	t_Identifier {}
    ;

skip_physical_literal:
	skip_opt_t_AbstractLit t_Identifier
{}
    ;

skip_opt_t_AbstractLit:  
	/* skip_nothing */ {}
|	t_AbstractLit {}
    ;

skip_physical_literal_no_default:
	t_AbstractLit t_Identifier
{}
    ;

skip_idf_list:
	t_Identifier {}
|	skip_idf_list t_Comma t_Identifier {}
    ;

/*------------------------------------------
--  skip_Desing skip_Unit
--------------------------------------------*/

/*
skip_lib_clause:
skip_t_LIBRARY skip_idf_list t_Semicolon {}
    ;
*/


skip_use_clause:
t_USE skip_sel_list t_Semicolon {}
    ;


skip_sel_list:
skip_sel_name {}
|	skip_sel_list t_Comma skip_sel_name {}
    ;

/*------------------------------------------
--  skip_Library skip_Units
--------------------------------------------*/

/*
skip_entity_declaration:
    t_ENTITY t_Identifier t_IS
{}
	skip_opt_generic_and_port_clauses
	skip_entity_decl_part
{}
	skip_opt_entity_stats
    t_END skip_opt_entity_end t_Semicolon
    {};
*/


skip_opt_generic_and_port_clauses:

    |	skip_generic_clause
    |   skip_port_clause
    |   skip_generic_clause skip_port_clause
    |	skip_port_clause skip_generic_clause
    ;



/*
skip_opt_generic_clause:
    / skip_nothing /
    |	skip_generic_clause
    ;
*/


skip_generic_clause:
	t_GENERIC skip_generic_interf_list t_Semicolon
{}
    ;


/*
skip_opt_port_clause:
	/ skip_nothing /
    |	skip_port_clause
    ;
*/


skip_port_clause:	    
	t_PORT skip_port_interf_list t_Semicolon
{}
    ;


/*
skip_entity_decl_part:
	/ skip_nothing /
    |	skip_entity_decl_part skip_entity_decltve_item
    ;
*/

/*
skip_opt_entity_stats:
	/ skip_nothing / 
    |	t_BEGIN skip_concurrent_stats
    ;
*/

/*
skip_opt_entity_end:			
    t_ENTITY skip_opt_t_Identifier {}
|	skip_opt_t_Identifier {}
    ;
*/

skip_opt_t_Identifier:
/* skip_nothing */ {}
|	t_Identifier {}
    ;

skip_architecture_body:
    skip_t_ARCHITECTURE t_Identifier t_OF t_Identifier t_IS
    {
      // info ("skipping %n", $4);
    }
	skip_architecture_decl_part
    t_BEGIN
{}
	skip_opt_concurrent_stats
    t_END skip_opt_architecture_end t_Semicolon
    {};

skip_architecture_decl_part:
    |	skip_architecture_decl_part skip_block_decltve_item
    ;

skip_opt_architecture_end:		    
    skip_t_ARCHITECTURE skip_opt_t_Identifier {}
|	skip_opt_t_Identifier {}
    ;


skip_configuration_declaration:
    skip_t_CONFIGURATION t_Identifier t_OF t_Identifier t_IS
    {
      // info ("skipping %n", $4);
    }
	skip_configuration_decl_part
	skip_block_config
    t_END skip_opt_configuration_end t_Semicolon
    {};

skip_configuration_decl_part:
    | skip_configuration_decl_part skip_config_decltve_item
    ;

skip_opt_configuration_end:
    skip_t_CONFIGURATION skip_opt_t_Identifier {}
|	skip_opt_t_Identifier {}
    ;
    

/*
skip_package_declaration:
    t_PACKAGE t_Identifier t_IS
{}
	skip_package_decl_part
    t_END skip_opt_package_end t_Semicolon
    {};
*/

/*
skip_package_decl_part:
    |	skip_package_decl_part skip_package_decltve_item
    ;

skip_opt_package_end:
    t_PACKAGE skip_opt_t_Identifier {}
|	skip_opt_t_Identifier {}
    ;
*/

skip_package_body:
    t_PACKAGE skip_t_BODY t_Identifier t_IS
    {
      // info ("skipping %n", $3);
    }
	skip_package_body_decl_part
    t_END skip_opt_package_body_end t_Semicolon
    {};

skip_package_body_decl_part:
    |	skip_package_body_decl_part skip_package_body_decltve_item
    ;

skip_opt_package_body_end:
    t_PACKAGE skip_t_BODY skip_opt_t_Identifier 
|	skip_opt_t_Identifier {}
    ;

/*------------------------------------------
--  skip_Declarative skip_Item
--------------------------------------------*/

skip_common_decltve_item:
	skip_type_decl
    |	skip_subtype_decl  
    |	skip_constant_decl
    |	skip_file_decl
    |	skip_alias_decl
    |	skip_subprog_decl
	|	skip_use_clause {}
    ;

/*
skip_entity_decltve_item:
	skip_common_decltve_item
    |	skip_subprog_body
    |	skip_attribute_decl
    |	skip_attribute_spec
    |	skip_disconnection_spec
    |	skip_signal_decl
    ;
*/

skip_block_decltve_item:
	skip_common_decltve_item
    |	skip_subprog_body
    |	skip_comp_decl
    |	skip_attribute_decl
    |	skip_attribute_spec
    |	skip_config_spec
    |	skip_disconnection_spec
    |	skip_signal_decl
    ;

/*
skip_package_decltve_item:
	skip_common_decltve_item
    |	skip_comp_decl
    |	skip_attribute_decl
    |	skip_attribute_spec
    |	skip_disconnection_spec
    |	skip_signal_decl
    ;
*/

skip_package_body_decltve_item:
	skip_common_decltve_item
    |	skip_subprog_body
    ;

skip_subprog_decltve_item:
	skip_common_decltve_item
    |	skip_subprog_body
    |	skip_attribute_decl
    |	skip_attribute_spec
    |	skip_variable_decl
    ;

skip_proc_decltve_item:
	skip_common_decltve_item
    |	skip_subprog_body
    |	skip_attribute_decl
    |	skip_attribute_spec
    |	skip_variable_decl
    ;

skip_config_decltve_item:
	skip_attribute_spec
	|	skip_use_clause {}
    ;

/*------------------------------------------
--  skip_Subprograms
--------------------------------------------*/

skip_subprog_decl:
	skip_subprog_spec t_Semicolon
{}
    ;

skip_subprog_spec:
	skip_proc_or_func_spec
{}
    ;

skip_proc_or_func_spec:
	t_PROCEDURE t_Identifier skip_opt_interf_list
{}
    |	skip_pure_or_impure t_FUNCTION skip_designator skip_opt_interf_list
          t_RETURN skip_subtype_indic
{}
    ;

skip_pure_or_impure:
    /* skip_nothing */ {}
|   t_PURE {}
|   t_IMPURE {}
    ;

skip_opt_interf_list:
/* skip_nothing */ {}
    |	skip_interf_list
    ;

skip_subprog_body:
	skip_subprog_spec t_IS
{}
	    skip_subprog_body_decl_part
	t_BEGIN
	    skip_seq_stats
	t_END skip_opt_designator t_Semicolon
{}
    ;

skip_opt_designator:
	    /* skip_nothing */ {}
|	skip_designator {}
    ;

skip_subprog_body_decl_part:
	/* skip_nothing */
    |	skip_subprog_body_decl_part skip_subprog_decltve_item
    ;


/*--------------------------------------------------
--  skip_Interface skip_Lists skip_and skip_Associaton skip_Lists
----------------------------------------------------*/

skip_port_interf_list:
{}
	skip_interf_list_1
{}
    ;

skip_generic_interf_list:
{}
	skip_interf_list_1
{}
    ;

skip_interf_list:
{}
        skip_interf_list_1
{}
    ;

skip_interf_list_1:
	t_LeftParen skip_interf_element skip_opt_more_interf_elements t_RightParen
{}
    ;

skip_opt_more_interf_elements:
	/* skip_nothing */ {}
    |	skip_opt_more_interf_elements t_Semicolon skip_interf_element
{}
    ;

skip_interf_element:
	skip_opt_object_class skip_idf_list t_Colon skip_opt_mode skip_subtype_indic
	    skip_opt_t_BUS skip_opt_var_init
{}
    ;

skip_opt_t_BUS:
	/* skip_nothing */ {}
|	t_BUS {}
    ;

skip_opt_mode:
/* skip_nothing */ {}
    |	skip_mode
    ;
  
skip_opt_object_class:
    /* skip_nothing */ {}
    |	skip_object_class
    ;
  
skip_mode:
    t_IN {}
|	t_OUT {}
|	t_INOUT {}
|	t_BUFFER {}
|	t_LINKAGE {}
    ;

skip_association_list:
	t_LeftParen skip_association_elements skip_association_list_1 t_RightParen
{}
    ;

skip_named_association_list:
	skip_association_list
{}
    ;

skip_association_list_1:
	/* skip_nothing */ {}
    |	skip_association_list_1 t_Comma skip_association_elements
{}
    ;


skip_gen_association_list:
	t_LeftParen skip_gen_association_elements skip_gen_association_list_1 t_RightParen
{}
    ;

skip_gen_association_list_1:
	/* skip_nothing */ {}
    |	skip_gen_association_list_1 t_Comma skip_gen_association_elements
{}
    ;

skip_association_elements:
	skip_formal_part t_Arrow skip_actual_part
{}
    |	skip_actual_part
{}
    ;

skip_gen_association_elements:
    	skip_association_elements
    |  	skip_discrete_range1
    ;

skip_formal_part:
	skip_name {}
|	skip_formal_part t_Bar skip_name {} 
    ;

skip_actual_part:
	skip_expr_or_attr
	|	t_OPEN {}
    ;

/*--------------------------------------------------
--  skip_Names skip_and skip_Expressions
----------------------------------------------------*/

skip_mark: 
	t_Identifier {}
|	skip_sel_name {}
    ;

skip_expr:
	skip_expr_or_attr
{}
    ;

skip_expr_or_attr:
	skip_and_expression {}
|	skip_or_expression {}
|	skip_xor_expression {} 
|   skip_xnor_expression {}
|	skip_relation_or_attr {}
    |	skip_relation t_NAND skip_relation
{}
    |	skip_relation t_NOR skip_relation
{}
    ;

skip_relation:
	skip_relation_or_attr
	{
	}
    ;

skip_and_expression:
	skip_relation t_AND skip_relation
	 { }
    |	skip_and_expression t_AND skip_relation
	 { }
    ;

skip_or_expression:
	skip_relation t_OR skip_relation
	 { }
    |	skip_or_expression t_OR skip_relation
	 { }
    ;

skip_xor_expression:
	skip_relation t_XOR skip_relation
	 { }
    |	skip_xor_expression t_XOR skip_relation
	 { }
    ;

skip_xnor_expression:
	skip_relation t_XNOR skip_relation
	 { }
    |	skip_xnor_expression t_XNOR skip_relation
	 { }
    ;

skip_relation_or_attr:
        skip_shift_expression_or_attr
    |   skip_shift_expression t_EQSym skip_shift_expression
        {
	}
    |   skip_shift_expression t_NESym skip_shift_expression
        {
	}
    |   skip_shift_expression t_LTSym skip_shift_expression
        {
	}
    |   skip_shift_expression t_LESym skip_shift_expression
        {
	}
    |   skip_shift_expression t_GTSym skip_shift_expression
        {
	}
    |   skip_shift_expression t_GESym skip_shift_expression
        {
	}
    ;

skip_shift_expression:
        skip_shift_expression_or_attr
        {
	}
    ;

skip_shift_expression_or_attr:
	skip_simple_expression_or_attr
    |   skip_simple_expression t_SLL skip_simple_expression
        {
	}
    |   skip_simple_expression t_SRL skip_simple_expression
        {
	}
    |   skip_simple_expression t_SLA skip_simple_expression
        {
	}
    |   skip_simple_expression t_SRA skip_simple_expression
        {
	}
    |   skip_simple_expression t_ROL skip_simple_expression
        {
	}
    |   skip_simple_expression t_ROR skip_simple_expression
        {
	}
    ;

skip_simple_expression:
        skip_simple_expression_or_attr
        {
	}
    ;

skip_simple_expression_or_attr:
        skip_signed_term_or_attr
    |   skip_simple_expression t_Plus skip_term
        {
	}
    |   skip_simple_expression t_Minus skip_term
        {
	}
    |   skip_simple_expression t_Ampersand skip_term
        {
	}
    ;

skip_signed_term_or_attr:
        skip_term_or_attr
    |	t_Plus skip_term
        {
	}
    |	t_Minus skip_term
        {
	}
    ; 

skip_term:
        skip_term_or_attr
        {
	}
    ;

skip_term_or_attr:
	skip_factor_or_attr
    |   skip_term t_Star skip_factor
        {
	}
    |   skip_term t_Slash skip_factor
        {
	}
    |   skip_term t_MOD skip_factor
        {
	}
    |   skip_term t_REM skip_factor
        {
	}
    ;

skip_factor:
        skip_factor_or_attr
        {
	}
    ;

skip_factor_or_attr:
	skip_primary_or_attr
    |   skip_primary t_DoubleStar skip_primary
        {
	}
    |   t_ABS skip_primary
        {
	}
    |   t_NOT skip_primary
        {
	}
    ;

skip_primary:
	skip_primary_or_attr
	{
	}
    ;

skip_primary_or_attr:
    skip_name {}
|	skip_literal {}
|	skip_aggregate {}
|	skip_qualified_expr {}
|	skip_allocator {}
|	t_LeftParen skip_expr t_RightParen {}
    ;

skip_name:
	skip_mark
    |	skip_name2
    ;

skip_name2:
	t_StringLit {}
|	skip_attribute_name {}
    |	skip_ifts_name
    ;  

skip_sel_name:
    skip_name t_Dot skip_suffix {}
    ;

skip_simple_sel_name:
    skip_simple_sel_name t_Dot t_Identifier {}
|	t_Identifier {}
    ;

skip_suffix:
skip_designator {}
|	t_CharacterLit {}
|	t_ALL {}
    ;

skip_ifts_name:
	skip_mark skip_gen_association_list   
{}
    |	skip_name2 skip_gen_association_list
{}
    ;


skip_attribute_prefix:
    skip_mark t_Apostrophe { }
    | skip_name2 t_Apostrophe { }
    ;


skip_range_attribute_name:
    skip_attribute_prefix t_RANGE { }
    | skip_attribute_prefix t_REVERSE_RANGE { }
    ;


skip_attribute_name:
    skip_attribute_prefix t_Identifier
    | skip_range_attribute_name { }
    ;



/*
skip_attribute_name:
	skip_mark t_Apostrophe t_Identifier
{}
    |	skip_name2 t_Apostrophe t_Identifier
{}
    |	skip_mark t_Apostrophe t_RANGE
{}
    |	skip_name2 t_Apostrophe t_RANGE
{}
    ;
*/

skip_range_attribute_name_with_param:
	skip_range_attribute_name skip_opt_attribute_param
{}
    ;

skip_opt_attribute_param:
	/* skip_empty */ {}
    |	t_LeftParen skip_expr t_RightParen
{}
    ;

skip_aggregate:
	skip_rev_element_association_list2 t_RightParen
{}
    |	t_LeftParen skip_choices t_Arrow skip_expr t_RightParen
{}
    ;

skip_rev_element_association_list2:
	t_LeftParen skip_element_association t_Comma skip_element_association
{}
    |	skip_rev_element_association_list2 t_Comma skip_element_association
{}
    ;

skip_qualified_expr:
	skip_mark t_Apostrophe t_LeftParen skip_expr t_RightParen
{}
    |	skip_mark t_Apostrophe skip_aggregate
{}
    ;


skip_allocator:
	t_NEW skip_mark skip_mark skip_opt_index_association_list
{}
    |	t_NEW skip_mark skip_opt_index_association_list
{}
    |	t_NEW skip_qualified_expr
{}
    ;

skip_opt_index_association_list:
    /* skip_nothing */ {}
|	skip_gen_association_list {}
    ;

/*--------------------------------------------------
--  skip_Element skip_Association skip_and skip_Choices
----------------------------------------------------*/

skip_element_association:
	skip_choices t_Arrow skip_expr
{}
    |	skip_expr
{}
    ;

skip_choices:
	skip_choice skip_opt_more_choices
{}
    ;

skip_opt_more_choices:
	/* skip_nothing */ {}
    |	skip_opt_more_choices t_Bar skip_choice
{}	    
    ;

skip_choice:
	skip_expr_or_attr
{}
    |	skip_discrete_range1
{}
    |	t_OTHERS
{}
    ;

/*--------------------------------------------------
--  skip_Type skip_Declarations
----------------------------------------------------*/

skip_decl_Identifier:
    t_Identifier {}
    ;

skip_type_decl:
	t_TYPE skip_decl_Identifier skip_opt_type_def t_Semicolon
{}
    ;

skip_opt_type_def:
	/* skip_nothing */ {}
|	t_IS skip_type_definition {}
    ;

skip_type_definition:
skip_enumeration_type_definition {}
|	skip_range_constraint {}
|	skip_physical_type_definition {}
|	skip_unconstrained_array_definition {}
|	skip_constrained_array_definition {}
|	skip_record_type_definition {}
|	skip_access_type_definition {}	
|	skip_file_type_definition {}
    ;

skip_enumeration_type_definition:
	t_LeftParen skip_enumeration_literal_decls t_RightParen
{}
    ;

skip_enumeration_literal_decls:
	skip_enumeration_literal skip_opt_more_enumeration_literals
{}
    ;

skip_opt_more_enumeration_literals:
	/* skip_nothing */ {}
|	t_Comma skip_enumeration_literal_decls {}
    ;

skip_physical_type_definition:
	skip_range_constraint t_UNITS
	    skip_primary_unit_decl
	    skip_secondary_unit_decls
	t_END t_UNITS
{}
    ;

skip_secondary_unit_decls:
	/* skip_nothing */ {}
    |	skip_secondary_unit_decls skip_secondary_unit_decl
{}
    ;

skip_primary_unit_decl:
	t_Identifier t_Semicolon
{}
    ;

skip_secondary_unit_decl:
	t_Identifier t_EQSym skip_physical_literal t_Semicolon
{}
    ;

skip_unconstrained_array_definition:
	t_ARRAY t_LeftParen skip_index_subtype_defs t_RightParen t_OF skip_subtype_indic
{}
    ;

skip_index_subtype_defs:
	skip_index_subtype_definition skip_opt_more_index_subtype_defs
{}
    ;

skip_opt_more_index_subtype_defs:
	/* skip_nothing */
{}
    |	t_Comma skip_index_subtype_definition skip_opt_more_index_subtype_defs
{}
    ;

skip_index_subtype_definition:
	skip_mark t_RANGE t_Box
{}
    ;

skip_constrained_array_definition:
	t_ARRAY skip_index_constraint t_OF skip_subtype_indic
{}
    ;

skip_record_type_definition:
	t_RECORD skip_element_decl skip_opt_more_element_decls t_END t_RECORD
{}
    ;

skip_opt_more_element_decls:
	/* skip_nothing */
{}
    |	skip_opt_more_element_decls skip_element_decl
{}
    ;

skip_element_decl:
	skip_idf_list t_Colon skip_subtype_indic t_Semicolon
{}
    ;

skip_access_type_definition:
	t_ACCESS skip_subtype_indic
{}
    ;

skip_file_type_definition:
	t_FILE t_OF skip_mark
{}
    ;

/*--------------------------------------------------
--  skip_Subtypes skip_and skip_Constraints
----------------------------------------------------*/

skip_subtype_decl:
	t_SUBTYPE skip_decl_Identifier t_IS skip_subtype_indic t_Semicolon
{}
    ;

skip_subtype_indic:
	skip_mark skip_opt_index_constraint {}
    |	skip_subtype_indic1
    ;

skip_subtype_indic1:
	skip_mark skip_mark skip_range_constraint
{}
    |	skip_mark skip_range_constraint
{}
    |	skip_mark skip_mark skip_opt_index_constraint
{}
    ;

skip_opt_index_constraint:
    /* skip_nothing */ {}
|	skip_gen_association_list {}
    ;

skip_range_constraint:
t_RANGE skip_range_spec2 {}
    ;

skip_index_constraint:
	t_LeftParen skip_discrete_range skip_opt_more_discrete_ranges t_RightParen
{}
    ;
  
skip_opt_more_discrete_ranges:
	/* skip_nothing */ 
{}
    |	skip_opt_more_discrete_ranges t_Comma skip_discrete_range
{}
    ;

skip_discrete_range:
	skip_subtype_indic
{}
    |	skip_range_spec
{}
    ;

skip_discrete_range1:
	skip_subtype_indic1
{}
    |	skip_expr_or_attr skip_direction skip_expr
{}
    ;


skip_opt_direction_expr:
        /* skip_nothing */
{}
    |	skip_direction skip_expr
{}
    ;


/* skip_XXX - skip_range_spec skip_contains skip_a skip_shift/skip_reduce skip_conflict, skip_because skip_an
   skip_attribute_name_with_param skip_can skip_be skip_an skip_expr.  skip_range_spec2 skip_solves skip_this
   skip_but skip_can skip_not skip_be skip_used skip_as skip_a skip_discrete skip_range skip_because skip_it skip_conflicts skip_with
   skip_ordinary skip_expressions.  skip_I skip_think.

   skip_A skip_possible skip_solution skip_would skip_maybe skip_be skip_to skip_elevate skip_ranges skip_to skip_be
   skip_expressions skip_and skip_disambiguate skip_this skip_purely skip_on skip_a skip_semantic skip_basis.  */

skip_range_spec:
	skip_range_attribute_name_with_param 
{}
    |	skip_expr skip_direction skip_expr 
{}
    ;

skip_range_spec2:
    	skip_expr_or_attr skip_opt_direction_expr
{}
    ;

skip_direction:
	t_TO {}
|	t_DOWNTO {}
    ;

/*--------------------------------------------------
--  skip_Objects, skip_Aliases, skip_Files, skip_Disconnections
----------------------------------------------------*/

skip_constant_decl:
	t_CONSTANT skip_idf_list t_Colon skip_subtype_indic skip_opt_var_init t_Semicolon
{}
    ;
  

skip_signal_decl:
	t_SIGNAL skip_idf_list t_Colon skip_subtype_indic
	    skip_opt_signal_kind skip_opt_var_init t_Semicolon
{}
    ;

skip_opt_signal_kind:
	/* skip_nothing */ {}
    |	skip_signal_kind
    ;

skip_variable_decl:
	t_VARIABLE skip_idf_list t_Colon skip_subtype_indic skip_opt_var_init t_Semicolon
{}
    ;

skip_opt_var_init:  
	/* skip_nothing */ {}
|	t_VarAsgn skip_expr {}
    ;

skip_object_class:
t_CONSTANT {}
|	t_SIGNAL {}
|	t_VARIABLE {}
|	t_FILE {}
    ;

skip_signal_kind:
t_BUS {}
|	t_REGISTER {}
    ;

skip_alias_decl:
	t_ALIAS t_Identifier t_Colon skip_subtype_indic t_IS skip_name t_Semicolon
{}
    ;  

skip_file_decl:
	t_FILE t_Identifier t_Colon skip_subtype_indic skip_opt_open_mode skip_opt_file_name
	  t_Semicolon
{}
    ;

skip_opt_open_mode:
	/* skip_nothing */
{}
    |	t_OPEN skip_expr
{}
    ;

skip_opt_file_name:
	/* skip_nothing */
{}
    |	t_IS skip_opt_file_mode skip_expr
{}
    ;

skip_opt_file_mode:
        /* nothing */
        {
	}
    |   t_IN
        {
	}
    |   t_OUT
        {
	}
    ;

skip_disconnection_spec:
	t_DISCONNECT skip_signal_list t_Colon skip_mark t_AFTER skip_expr t_Semicolon
{}
    ;

skip_signal_list:
	skip_signal_name skip_opt_more_signal_list 
{}
    |	t_OTHERS                  
{}
    |	t_ALL
{}
    ;

skip_opt_more_signal_list:
    /* skip_nothing */ {}
    |	skip_opt_more_signal_list t_Comma skip_signal_name
{}
    ;

/*--------------------------------------------------
--  skip_Attribute skip_Declarations skip_and skip_Specifications
----------------------------------------------------*/

skip_attribute_decl:
	t_ATTRIBUTE t_Identifier t_Colon skip_mark t_Semicolon
{}
    ;

skip_attribute_spec:
	t_ATTRIBUTE t_Identifier t_OF skip_entity_spec t_IS skip_expr t_Semicolon
{}
    ;

skip_entity_spec:
	skip_entity_name_list t_Colon skip_entity_class
{}
    ;

skip_entity_name_list:
	skip_designator skip_opt_more_entity_name_list
{}
    |	t_OTHERS
{}
    |	t_ALL
{}
    ;

skip_opt_more_entity_name_list:
    /* skip_nothing */ {}
    |	skip_opt_more_entity_name_list t_Comma skip_designator
{}
    ;

skip_entity_class:
    t_ENTITY {}
|	t_ARCHITECTURE {}
|	t_PACKAGE {}
|	t_CONFIGURATION {}
|	t_COMPONENT {}
|	t_LABEL {}
|	t_TYPE {}
|	t_SUBTYPE {}
|	t_PROCEDURE {}
|	t_FUNCTION {}
|	t_SIGNAL {}
|	t_VARIABLE {}
|	t_CONSTANT {}
    ;

/*--------------------------------------------------
--  skip_Schemes
----------------------------------------------------*/

skip_generation_scheme:
skip_if_scheme {}
|	skip_for_scheme {}
    ;

skip_iteration_scheme:
skip_for_scheme {}
|	skip_while_scheme {}
    ;

skip_if_scheme:
t_IF skip_condition {}
    ;

skip_for_scheme:
	t_FOR t_Identifier t_IN skip_discrete_range
{}
    ;

skip_while_scheme:
	t_WHILE skip_condition {}
    ;

/*--------------------------------------------------
--  skip_Concurrent skip_Statements
----------------------------------------------------*/

skip_concurrent_stats:
	skip_opt_concurrent_stats skip_concurrent_stat
    ;

skip_opt_concurrent_stats:
	/* nothing */
    |	skip_opt_concurrent_stats skip_concurrent_stat
    ;

skip_concurrent_stat:
        {
        }
        skip_concurrent_stat_1
    ;

skip_concurrent_stat_1:
        skip_concurrent_stat_without_label
    |   skip_concurrent_stat_with_label
    ;

skip_concurrent_stat_without_label:
	skip_concurrent_stat_without_label_1
	{
	}
    ;

skip_concurrent_stat_with_label:
        t_Identifier t_Colon 
        {
	}
	skip_concurrent_stat_with_label_1
	{
	}
    ;

skip_concurrent_stat_without_label_1:
    	skip_concurrent_assertion_stat
    |	skip_concurrent_procedure_call
    |	skip_concurrent_signal_assign_stat
    |	skip_proc_stat
    ;

skip_concurrent_stat_with_label_1:
	skip_block_stat
    |	skip_comp_inst_stat
    |	skip_concurrent_assertion_stat
    |	skip_concurrent_procedure_call
    |	skip_concurrent_signal_assign_stat
    |	skip_generate_stat
    |	skip_proc_stat
    ;

skip_block_stat:
	t_BLOCK skip_block_guard skip_opt_t_IS
{}
	    skip_block_generic_stuff
{}
	    skip_block_port_stuff
{}
	    skip_block_decl_part
	t_BEGIN
{}
	    skip_opt_concurrent_stats
	t_END t_BLOCK skip_opt_t_Identifier t_Semicolon
{}
    ;

skip_block_decl_part:
	/* skip_nothing */
    |	skip_block_decl_part skip_block_decltve_item
    ;

skip_block_port_stuff:
    /* skip_nothing */ {}
|	skip_port_clause skip_opt_port_map_semi {}
    ;

skip_block_generic_stuff:
/* skip_nothing */ {}
|	skip_generic_clause skip_opt_generic_map_semi {}
    ;

skip_block_guard:
/* skip_nothing */ {}
|	t_LeftParen skip_condition t_RightParen {}
    ;

skip_opt_port_map_semi:
/* skip_nothing */ {}
|	skip_port_map t_Semicolon {}
    ;

skip_opt_generic_map_semi:
/* skip_nothing */ {}
|	skip_generic_map t_Semicolon {}
    ;

/*
skip_comp_inst_stat:
	t_Identifier t_Colon skip_comp_inst_unit
	    skip_opt_generic_map
	    skip_opt_port_map
	t_Semicolon
	{}
    ;
*/

skip_comp_inst_stat:
	skip_comp_mark
	    t_GENERIC t_MAP skip_named_association_list
	    skip_opt_port_map
	t_Semicolon
{}

    |	skip_comp_mark
	    t_PORT t_MAP skip_named_association_list
	    skip_opt_generic_map
	t_Semicolon
{}
    |   skip_comp_mark_with_keyword
            skip_opt_generic_map
            skip_opt_port_map
        t_Semicolon
{}
    ;

skip_comp_mark_with_keyword:
	t_COMPONENT skip_comp_mark                 
{}
    |   t_ENTITY skip_simple_sel_name skip_opt_arch_id  
{}
    |   t_CONFIGURATION skip_mark
{}
    ;

/* skip_NOTE: skip_component skip_instantiation skip_statements skip_without skip_a skip_keyword skip_look
**	 skip_like skip_concurrent skip_procedure skip_calls
*/

skip_opt_generic_map:
    /* skip_nothing */ {}
    |	skip_generic_map
    ;

skip_generic_map:
    t_GENERIC t_MAP skip_named_association_list {}
    ;

skip_opt_port_map:
    /* skip_nothing */ {}
    |	skip_port_map
    ;

skip_port_map:
    t_PORT t_MAP skip_named_association_list {}
    ;

skip_concurrent_assertion_stat:
    	skip_assertion_stat
{}

    |	t_POSTPONED skip_assertion_stat
{}
    ;

skip_concurrent_procedure_call:
        skip_mark t_Semicolon
{}

    |   skip_procedure_call_stat_with_args
{}

    |	t_POSTPONED skip_procedure_call_stat
{}
    ;

skip_opt_postponed:
    /* skip_nothing */ {}
|	t_POSTPONED {}
    ;

skip_concurrent_signal_assign_stat:
    	skip_condal_signal_assign
{}

    |	t_POSTPONED skip_condal_signal_assign
{}

|	skip_sel_signal_assign
{}

|	t_POSTPONED skip_sel_signal_assign
{}
    ;

skip_condal_signal_assign:
    	skip_target t_LESym skip_opt_guarded skip_delay_mechanism skip_condal_wavefrms t_Semicolon
{}
    ;

skip_condal_wavefrms:
    	skip_condal_wavefrms_1 skip_wavefrm
{}
    ;

skip_condal_wavefrms_1:
    	/* skip_nothing */ {}
    |	skip_condal_wavefrms_1 skip_wavefrm t_WHEN skip_condition t_ELSE
{}
    ;

skip_wavefrm:
	skip_wavefrm_element skip_reverse_more_wavefrm
{}
    ;

skip_reverse_more_wavefrm:
	/* skip_nothing */ {}
    |	skip_reverse_more_wavefrm t_Comma skip_wavefrm_element
{}
    ;

skip_wavefrm_element:
	skip_expr skip_opt_wavefrm_after
{}
    ;

skip_opt_wavefrm_after:
	/* skip_nothing */ {}
|	t_AFTER skip_expr {}
    ;

skip_target:
skip_name {}
|	skip_aggregate {}
    ;

skip_opt_guarded:
/* skip_nothing */ {}
|	t_GUARDED {}
    ;

skip_sel_signal_assign:
	t_WITH skip_expr t_SELECT skip_target t_LESym skip_opt_guarded skip_delay_mechanism
                                            skip_sel_wavefrms t_Semicolon
{}
    ;

skip_sel_wavefrms:
	skip_sel_wavefrms_1 skip_wavefrm t_WHEN skip_choices
{}
    ;

skip_sel_wavefrms_1:
	/* skip_nothing */
{}
    |	skip_sel_wavefrms_1 skip_wavefrm t_WHEN skip_choices t_Comma
{}
    ;

skip_generate_stat:
	skip_generation_scheme t_GENERATE
	{
	}
          skip_generate_declarative_items_block
	  skip_concurrent_stats
	t_END t_GENERATE skip_opt_t_Identifier t_Semicolon
	{
	}
    ;

skip_generate_declarative_items_block:
	  /* nothing */
    |     skip_generate_declarative_items t_BEGIN
    ;

skip_generate_declarative_items:
          /* nothing */
    |     skip_generate_declarative_items skip_generate_declarative_item
    ;

skip_generate_declarative_item:
	  skip_common_decltve_item
    |     skip_subprog_body
    |	  skip_comp_decl
    |	  skip_attribute_decl
    |	  skip_attribute_spec
    |	  skip_config_spec
    |	  skip_disconnection_spec
    |	  skip_signal_decl
    ;

skip_proc_stat:
	t_PROCESS skip_opt_proc_sensitivity_list skip_opt_t_IS
{}
	    skip_proc_decl_part
	t_BEGIN
	    skip_seq_stats
	t_END skip_opt_postponed t_PROCESS skip_opt_t_Identifier t_Semicolon
{}

    |	t_POSTPONED t_PROCESS skip_opt_proc_sensitivity_list skip_opt_t_IS
{}
	    skip_proc_decl_part
	t_BEGIN
	    skip_seq_stats
	t_END skip_opt_postponed t_PROCESS skip_opt_t_Identifier t_Semicolon
{}
    ;

skip_opt_t_IS:
	/* skip_nothing */
    |	t_IS
    ;

skip_proc_decl_part:
	/* skip_nothing */
    |	skip_proc_decl_part skip_proc_decltve_item
    ;

skip_opt_proc_sensitivity_list:
    /* skip_nothing */ {}
|	t_LeftParen skip_sensitivity_list t_RightParen {}
    ; 

skip_sensitivity_list:
	skip_signal_name skip_reverse_opt_more_sensitivities
{}
    ;

skip_reverse_opt_more_sensitivities:	 
	/* skip_nothing */ {}
    |	skip_reverse_opt_more_sensitivities t_Comma skip_signal_name
{}	
    ;

skip_signal_name:
	skip_name
{}
    ;

/*--------------------------------------------------
--  skip_Sequential skip_Statements
----------------------------------------------------*/

skip_seq_stats:
	skip_rev_seq_stats {}
    ;

skip_rev_seq_stats:
	/* skip_nothing */ {}
    |	skip_rev_seq_stats skip_seq_stat	
{}
    ;

skip_seq_stat:
    skip_assertion_stat {}
|   skip_report_stat {}
|	skip_case_stat {}
|	skip_exit_stat {}
|	skip_if_stat {}
|	skip_loop_stat {}
|	skip_next_stat {}
|	skip_null_stat {}
|	skip_procedure_call_stat {}
|	skip_return_stat {}
|	skip_signal_assign_stat {}
|	skip_variable_assign_stat {}
|	skip_wait_stat {}
    ;

skip_assertion_stat:
	t_ASSERT skip_condition skip_opt_assertion_report skip_opt_assertion_severity
	 t_Semicolon
{}
    ;

skip_report_stat:
	t_REPORT skip_expr skip_opt_assertion_severity t_Semicolon
{}
    ;

skip_opt_assertion_severity:
	/* skip_nothing */
{}
    |	t_SEVERITY skip_expr
{}
    ;

skip_opt_assertion_report:
	/* skip_nothing */
{}
    |	t_REPORT skip_expr
{}
    ;

skip_case_stat:
	t_CASE skip_expr t_IS 
	    skip_case_stat_alternative
	    skip_more_case_stat_alternatives 
	t_END t_CASE t_Semicolon
{}
    ;

skip_case_stat_alternative:
	t_WHEN skip_choices t_Arrow skip_seq_stats
{}
    ;

skip_more_case_stat_alternatives:
	/* skip_nothing */
{}
    |	skip_more_case_stat_alternatives skip_case_stat_alternative
{}
    ;

skip_if_stat:
	t_IF skip_condition t_THEN skip_seq_stats skip_if_stat_1 skip_if_stat_2 t_END t_IF
	t_Semicolon
{}
    ;

skip_if_stat_2:
	/* skip_nothing */ {}
|	t_ELSE skip_seq_stats {}
    ;

skip_if_stat_1:
/* skip_nothing */ {}
    |	skip_if_stat_1  t_ELSIF skip_condition t_THEN skip_seq_stats
{}
    ;

skip_condition:
    skip_expr {}
    ;

skip_loop_stat:
	skip_opt_label skip_opt_iteration_scheme t_LOOP
{}
	    skip_seq_stats
	t_END t_LOOP skip_opt_t_Identifier t_Semicolon
{}
    ;

skip_opt_iteration_scheme:
	    /* skip_nothing */ {}
|	skip_iteration_scheme {}
    ;

skip_opt_label:
/* skip_nothing */ {}
    |	t_Identifier t_Colon 
{}
    ;

skip_next_stat:
	t_NEXT skip_opt_t_Identifier skip_opt_when t_Semicolon
{}
    ;

skip_exit_stat:
	t_EXIT skip_opt_t_Identifier skip_opt_when t_Semicolon
{}
    ;

skip_opt_when:
	/* skip_nothing */ {}
|	t_WHEN skip_condition {}
    ;

skip_null_stat:
t_NULL t_Semicolon {}
    ;

skip_procedure_call_stat:
skip_procedure_call_stat_without_args {}
|   skip_procedure_call_stat_with_args {}
    ;

skip_procedure_call_stat_without_args:
	skip_mark t_Semicolon
{}
    ;

skip_procedure_call_stat_with_args:
	skip_name2 t_Semicolon
{}
    ;

skip_return_stat:
	t_RETURN skip_opt_expr t_Semicolon
{}
    ;

skip_opt_expr:
	/* skip_nothing */ {}
    |	skip_expr
    ;

skip_signal_assign_stat:
	skip_target t_LESym skip_delay_mechanism skip_wavefrm t_Semicolon
{}
    ;

skip_delay_mechanism:
	/* skip_nothing */ {}
|   t_TRANSPORT {}
|   t_INERTIAL {}
    |	t_REJECT skip_expr t_INERTIAL 
{}
    ;

skip_variable_assign_stat:
	skip_target t_VarAsgn skip_expr t_Semicolon
{}
    ;

skip_wait_stat:
	t_WAIT skip_opt_wait_on skip_opt_wait_until skip_opt_wait_for t_Semicolon
{}
    ;

skip_opt_wait_for:
	/* skip_nothing */ {}
|	t_FOR skip_expr {}
    ;

skip_opt_wait_until:
/* skip_nothing */ {}
|	t_UNTIL skip_condition {}
    ;

skip_opt_wait_on:
/* skip_nothing */ {}
|	t_ON skip_sensitivity_list {}
    ;

/*--------------------------------------------------
--  skip_Components skip_and skip_Configurations
----------------------------------------------------*/

skip_comp_decl:
	t_COMPONENT t_Identifier skip_opt_t_IS
{}
	    skip_opt_generic_and_port_clauses
	t_END t_COMPONENT skip_opt_t_Identifier t_Semicolon
{}
    ;

skip_block_config:
	    t_FOR skip_name {}
    	    skip_use_clauses
    	    skip_config_items
    	t_END t_FOR t_Semicolon
{}
    ;

skip_config_items:
	    /* skip_nothing */ {}
|	skip_config_items skip_config_item {}
    ;

skip_use_clauses:
	/* skip_nothing */
|	skip_use_clauses skip_use_clause {}
    ;

skip_config_item:
skip_block_config {}
|	skip_comp_config {}
    ;

skip_comp_config:
	t_FOR skip_comp_spec skip_opt_comp_binding_indic
{}
    	    skip_opt_block_config
	t_END t_FOR t_Semicolon
{}
    ;

skip_opt_block_config:
	    /* skip_nothing */ {}
|	skip_block_config {}
    ;

skip_opt_comp_binding_indic:
/* skip_nothing */ {}
|  	skip_incremental_binding_indic t_Semicolon {}
|	skip_pre_binding_indic t_Semicolon {}
    ;

skip_config_spec:
	t_FOR skip_comp_spec skip_binding_indic t_Semicolon
{}
    ;

skip_comp_spec:
	skip_inst_list t_Colon skip_comp_mark
{}
    ;

skip_comp_mark:
	skip_mark
{}
    ;

skip_inst_list:
	skip_idf_list {}
|	t_ALL {}
|	t_OTHERS {}
    ;

/* skip_binding_indic skip_et skip_al skip_is skip_to skip_be skip_invoked skip_with skip_the skip_component skip_decl
** skip_as skip_the skip_selected skip_scope
*/

skip_binding_indic:
skip_pre_binding_indic {}
    ;

skip_pre_binding_indic:
{}
	t_USE skip_entity_aspect
{}
	skip_opt_generic_map skip_opt_port_map
{}
    ;

skip_incremental_binding_indic:
	skip_generic_map skip_opt_port_map
{}
    |	skip_port_map
{}
    ;

skip_entity_aspect:
	t_ENTITY skip_simple_sel_name skip_opt_arch_id
{}
    |	t_CONFIGURATION skip_mark
{}
    |	t_OPEN
{}
    ;

skip_opt_arch_id:
    /* skip_nothing */ {}
|	t_LeftParen t_Identifier t_RightParen {}
    ;


%%

vaul_error_printer::vaul_error_printer ()
{
  log = stderr;
  n_errors = 0;
}

pIIR_ExpressionList vaul_parser::no_sens_list = NULL;

vaul_parser::vaul_parser (vaul_lexer *l)
{
  init_fire_chunk ();
  init_vaul_chunk ();
  init_vaulgens_chunk ();

  lex = l;
  lex->set_printer (this, log);
  lex->set_creator (this);
  cur_du = NULL;
  eof = false;

  if (no_sens_list == NULL)
    {
      no_sens_list = mIIR_ExpressionList (pIIR_PosInfo(NULL), NULL, NULL);
      tree_protect (no_sens_list);
    }
  consumer = NULL;

  options = default_options;

  //yydebug = 1;
}

vaul_parser::~vaul_parser ()
{
}

vaul_design_unit *vaul_current_design_unit;

vaul_parser_options::vaul_parser_options ()
{
  debug = false;
  fullnames = false;
  allow_invisible_default_bindings_from_work = false;
  nocache = false;
  skip_bodies = false;
}

vaul_parser_options vaul_parser::default_options;

vaul_design_unit *
vaul_parser::parse (vaul_pool *p)
{
  vaul_design_unit *prev_cur_du;
  pool = p;

  lex->skip_bodies (options.skip_bodies);

  // We block the garbage collector while creating the graph because
  // we have unprotected nodes floating around.  When `finish' returns,
  // all nodes that we care about have been linked into the design
  // unit, so it is safe to collect the unneeded ones.

  // Additionally, the parser is now careful to have all live nodes
  // safely plugged into the design unit between concurrent
  // statements.  This allows us to collect the garbage after each
  // concurrent statement has been parsed.
  
  // XXX - extend this to declarations and sequential statements.

  tree_block_garbage_collection ();  
  prev_cur_du = vaul_current_design_unit;
  XXX_seen = false;
  init ();
  bison_parse ();
  if (XXX_seen)
    n_errors++;
  vaul_design_unit *du = finish ();
  vaul_current_design_unit = prev_cur_du;
//    if (flags & VAUL_PARSER_VERBOSE)
//      fprintf (stderr, "after parse of %s: ", du? du->get_name () : "EOF");
  tree_collect_garbage ();
  tree_unblock_garbage_collection ();

  if (du && n_errors > 0)
    du->set_error (vhdlerr_errors_detected, "%d errors", n_errors);

  // if (flags & VAUL_PARSER_VERBOSE)
  //   hist.print ();

  return du;
}

int vaul_parser_gc_thresh = 100000;

void
vaul_parser::collect ()
{
  tree_collect_garbage ();
  tree_unblock_garbage_collection ();
  tree_block_garbage_collection ();
}

void
vaul_parser::clear_errors ()
{
  n_errors = 0;
}
