// generated by gen-nodes from `v2c-chunk.t'.  Do not edit.

#ifndef V2C_H
#define V2C_H

#include <freehdl/vaul-chunk.h>

extern tree_chunk_info v2c_chunk_info;

typedef void (*v2c_generic_0_mtype) (tree_base_node*);
extern tree_generic<v2c_generic_0_mtype> v2c_generic_0;
void emit_def (tree_base_node *);

typedef void (*v2c_generic_1_mtype) (tree_base_node*, int l);
extern tree_generic<v2c_generic_1_mtype> v2c_generic_1;
void emit_decl (tree_base_node *, int l);

typedef void (*v2c_generic_2_mtype) (tree_base_node*, int l);
extern tree_generic<v2c_generic_2_mtype> v2c_generic_2;
void emit_stat (tree_base_node *, int l);

typedef void (*v2c_generic_3_mtype) (tree_base_node*);
extern tree_generic<v2c_generic_3_mtype> v2c_generic_3;
void emit_expr (tree_base_node *);

typedef void (*v2c_generic_4_mtype) (tree_base_node*, int l);
extern tree_generic<v2c_generic_4_mtype> v2c_generic_4;
void emit_conc_stat (tree_base_node *, int l);

typedef void (*v2c_generic_5_mtype) (tree_base_node*, int l);
extern tree_generic<v2c_generic_5_mtype> v2c_generic_5;
void emit_start_of_context (tree_base_node *, int l);

typedef void (*v2c_generic_6_mtype) (tree_base_node*, int l);
extern tree_generic<v2c_generic_6_mtype> v2c_generic_6;
void emit_end_of_context (tree_base_node *, int l);
void m_emit_def (pIIR_Type );
void m_emit_def (pIIR_FileType );
void m_emit_def (pIIR_RecordType );
void m_emit_def (pIIR_ArrayType );
void m_emit_def (pIIR_EnumerationType );
void m_emit_def (pIIR_FloatingType );
void m_emit_def (pIIR_PhysicalType );
void m_emit_def (pIIR_IntegerType );
void m_emit_def (pIIR_Subtype );
void m_emit_decl (pIIR_ComponentDeclaration , int l);
void m_emit_decl (pIIR_ConfigurationDeclaration , int l);
void m_emit_decl (pIIR_ArchitectureDeclaration , int l);
void m_emit_decl (pIIR_EntityDeclaration , int l);
void m_emit_decl (pIIR_PackageBodyDeclaration , int l);
void m_emit_decl (pIIR_PackageDeclaration , int l);
void m_emit_decl (pIIR_TypeDeclaration , int l);
void m_emit_decl (pIIR_SignalDeclaration , int l);
void m_emit_decl (pIIR_FileDeclaration , int l);
void m_emit_decl (pIIR_ConstantDeclaration , int l);
void m_emit_decl (pIIR_VariableDeclaration , int l);
void m_emit_decl (pIIR_SubprogramDeclaration , int l);
void m_emit_decl (pIIR_Declaration , int l);
void m_emit_stat (pIIR_SequentialStatement , int l);
void m_emit_stat (pIIR_SignalAssignmentStatement , int l);
void m_emit_stat (pIIR_ReportStatement , int l);
void m_emit_stat (pIIR_AssertionStatement , int l);
void m_emit_stat (pIIR_WaitStatement , int l);
void m_emit_stat (pIIR_ProcedureCallStatement , int l);
void m_emit_stat (pIIR_LoopControlStatement , int l);
void m_emit_stat (pIIR_LoopStatement , int l);
void m_emit_stat (pIIR_CaseStatement , int l);
void m_emit_stat (pIIR_IfStatement , int l);
void m_emit_stat (pIIR_VariableAssignmentStatement , int l);
void m_emit_stat (pIIR_ReturnStatement , int l);
void m_emit_stat (pIIR_NullStatement , int l);
void m_emit_expr (pIIR_Expression );
void m_emit_expr (pIIR_AttrArrayFunc );
void m_emit_expr (pIIR_AttrSigFunc );
void m_emit_expr (pIIR_SignalAttr );
void m_emit_expr (pIIR_AccessReference );
void m_emit_expr (pIIR_SliceReference );
void m_emit_expr (pIIR_ArrayAggregate );
void m_emit_expr (pIIR_RecordAggregate );
void m_emit_expr (pIIR_RecordReference );
void m_emit_expr (pIIR_ArrayLiteralExpression );
void m_emit_expr (pIIR_ArrayReference );
void m_emit_expr (pIIR_EnumLiteralReference );
void m_emit_expr (pIIR_QualifiedExpression );
void m_emit_expr (pIIR_TypeConversion );
void m_emit_expr (pIIR_AbstractLiteralExpression );
void m_emit_expr (pIIR_SimpleReference );
void m_emit_expr (pIIR_FunctionCall );
void m_emit_conc_stat (pIIR_ConcurrentStatement , int l);
void m_emit_conc_stat (pIIR_ConcurrentGenerateStatement , int l);
void m_emit_conc_stat (pIIR_BlockStatement , int l);
void m_emit_conc_stat (pIIR_ComponentInstantiationStatement , int l);
void m_emit_conc_stat (pIIR_ProcessStatement , int l);
void m_emit_start_of_context (pIIR_BlockStatement , int l);
void m_emit_start_of_context (pIIR_ArchitectureDeclaration , int l);
void m_emit_end_of_context (pIIR_BlockStatement , int l);
void m_emit_end_of_context (pIIR_ArchitectureDeclaration , int l);

void init_v2c_chunk ();

#endif
