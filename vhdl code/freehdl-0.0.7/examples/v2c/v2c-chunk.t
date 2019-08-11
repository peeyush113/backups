; -*- scheme -*-

(include "freehdl/vaul-chunk.t")

(chunk v2c)

(header-add "#include <freehdl/vaul-chunk.h>")
(impl-add "#include \"v2c-chunk.h\"")

;;(defctype int)

(defgeneric emit_def
  (methods
   IIR_Subtype IIR_IntegerType IIR_PhysicalType
   IIR_FloatingType IIR_EnumerationType
   IIR_ArrayType IIR_RecordType IIR_FileType IIR_Type))

(defgeneric emit_decl
  (args (int l))
  (methods
   IIR_Declaration IIR_SubprogramDeclaration IIR_VariableDeclaration
   IIR_ConstantDeclaration IIR_FileDeclaration IIR_SignalDeclaration
   IIR_TypeDeclaration IIR_PackageDeclaration IIR_PackageBodyDeclaration
   IIR_EntityDeclaration IIR_ArchitectureDeclaration
   IIR_ConfigurationDeclaration IIR_ComponentDeclaration))

(defgeneric emit_stat
  (args (int l))
  (methods
   IIR_NullStatement IIR_ReturnStatement IIR_VariableAssignmentStatement
   IIR_IfStatement IIR_CaseStatement IIR_LoopStatement IIR_LoopControlStatement
   IIR_ProcedureCallStatement IIR_WaitStatement IIR_AssertionStatement
   IIR_ReportStatement IIR_SignalAssignmentStatement
   IIR_SequentialStatement))

(defgeneric emit_expr
  (methods
   IIR_FunctionCall IIR_SimpleReference IIR_AbstractLiteralExpression
   IIR_TypeConversion IIR_QualifiedExpression IIR_EnumLiteralReference
   IIR_ArrayReference IIR_ArrayLiteralExpression IIR_RecordReference
   IIR_RecordAggregate IIR_ArrayAggregate IIR_SliceReference
   IIR_AccessReference IIR_SignalAttr IIR_AttrSigFunc IIR_AttrArrayFunc
   IIR_Expression))

(defgeneric emit_conc_stat
  (args (int l))
  (methods
   IIR_ProcessStatement
   IIR_ComponentInstantiationStatement
   IIR_BlockStatement
   IIR_ConcurrentGenerateStatement
   IIR_ConcurrentStatement))

(defgeneric emit_start_of_context
  (args (int l))
  (methods
   IIR_ArchitectureDeclaration
   IIR_BlockStatement))

(defgeneric emit_end_of_context
  (args (int l))
  (methods
   IIR_ArchitectureDeclaration
   IIR_BlockStatement))
