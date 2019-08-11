; -*- scheme -*-

(include "freehdl/vaul-chunk.t")

(define (format-v2cc-kind name)
  (upcase (concat-strings (cons "v2cc" (cdr (syllables name))) "_")))

(chunk v2cc
       (struct-fmt "~a")
       (pointer-fmt "p~a")
       (kind-fmt-func format-v2cc-kind)
       )

(header-add "#include <freehdl/vaul-chunk.h>")
(header-add "#include <string>")
(header-add "#include <set>")
(header-add "#include <list>")
(header-add "#include <vector>")
(header-add "#include <map>")
(header-add "#include <deque>")
(header-add "#include <vector>")
(header-add "#include <algorithm>")
(header-add "#include \"v2cc.h\"")
;; Returns kind of a VHDL operator:
;;  NO_OP if the function does not denote an operator
;;  STD_OP if the funcion denotes an predefined VHDL operator
;;  BASIC_OP if the function denotes an operator defined in an 
;;           IEEE library (e.g. numeric_std)
;;  USER_OP an user defined operator
(header-add "enum op_type { NO_OP, STD_OP, BASIC_OP, USER_OP };")
;;  
(impl-add "#include \"v2cc-chunk.h\"")

;;(defctype int)
(defctype set_string (cname "set<string>"))
(defctype list_string (cname "list<string>"))
(defctype list_expr_pair_ref (cname "list<pair<pIIR_Expression, pIIR_Root> >&"))
(defctype vector_string (cname "vector<string>"))
(defctype vector_string_ref (cname "vector<string>&"))
(defctype vector_bool (cname "vector<bool>"))
(defctype vector_lint_ref (cname "vector<long long int>&"))
(defctype RegionStack (cname "RegionStack"))
(defctype RegionStack_ref (cname "RegionStack &"))
(defctype ContextInfo (cname "ContextInfo"))
(defctype ContextInfo_ref (cname "ContextInfo &"))
(defctype pContextInfo (cname "ContextInfo*"))
(defctype pAccessDescriptor (cname "pAccessDescriptor"))
(defctype lint (cname "long long int"))
(defctype StaticDataType (cname "StaticDataType"))
(defctype string (cname "string"))
(defctype string_ref (cname "string&"))
(defctype set_IIR_SimpleReference (name "set<IIR_SimpleReference>"))
(defctype pIIR_ObjectDeclaration (cname "pIIR_ObjectDeclaration"))
;(defctype IR_StaticLevel (cname "IR_StaticLevel"))
(defctype RangeDescriptor_vec (cname "vector<RangeDescriptor>"))
(defctype RuntimeCheckFlags (cname "RuntimeCheckFlags"))
(defctype id_type)
;;(defctype static_level_type)
(defctype op_type)

;;(defgeneric emit_def 
;;  (args (string_ref str) (RegionStack_ref ctxt))
;;  (methods
;;   IIR_Subtype IIR_IntegerType IIR_PhysicalType
;;   IIR_FloatingType IIR_EnumerationType
;;   IIR_ArrayType IIR_RecordType IIR_FileType IIR_Type))

(defgeneric emit_decl
  (args (string_ref str) (RegionStack_ref ctxt) (int l))
  (methods
   IIR_Declaration 
   IIR_SubprogramDeclaration 
   IIR_VariableDeclaration
   IIR_ConstantDeclaration 
   IIR_FileDeclaration 
   IIR_SignalDeclaration
   IIR_TypeDeclaration 
   IIR_PackageDeclaration 
   IIR_PackageBodyDeclaration
   IIR_EntityDeclaration 
   IIR_ArchitectureDeclaration
   IIR_ConfigurationDeclaration 
   IIR_ComponentDeclaration))

(defgeneric emit_main
  (args (string_ref str) (RegionStack_ref ctxt) (int l))
  (methods
   IIR_Declaration 
   IIR_ArchitectureDeclaration
   IIR_ConfigurationDeclaration))

(defgeneric emit_expr
  (args (string_ref str) (RegionStack_ref ctxt) (id_type t))
  (return bool)
  (methods
   IIR_FunctionCall 
   IIR_SimpleReference 
   IIR_AbstractLiteralExpression
   IIR_TypeConversion 
   IIR_QualifiedExpression 
   IIR_EnumLiteralReference
   IIR_ArrayReference 
   IIR_ArrayLiteralExpression 
   IIR_RecordReference
   IIR_RecordAggregate 
   IIR_ArrayAggregate 
   IIR_SliceReference
   IIR_AccessReference 
   IIR_SignalAttr 
   IIR_AttrSigFunc 
   IIR_AttrArrayFunc 
   IIR_AttrTypeFunc 
   IIR_AttrTypeValue
   IIR_Expression 
   IIR_EnumerationLiteral
   IIR_NullExpression
   IIR_Allocator
   ))

(defgeneric cdfg_emit_expr
  (args (string_ref str) (RegionStack_ref ctxt) (id_type t))
  (return bool)
  (methods
   IIR_FunctionCall 
   IIR_SimpleReference 
   IIR_AbstractLiteralExpression
   IIR_TypeConversion 
   IIR_QualifiedExpression 
   IIR_EnumLiteralReference
   IIR_ArrayReference 
   IIR_ArrayLiteralExpression 
   IIR_RecordReference
   IIR_RecordAggregate 
   IIR_ArrayAggregate 
   IIR_SliceReference
   IIR_AccessReference 
   IIR_SignalAttr 
   IIR_AttrSigFunc 
   IIR_AttrArrayFunc 
   IIR_AttrTypeFunc 
   IIR_AttrTypeValue
   IIR_Expression 
   IIR_EnumerationLiteral
   IIR_NullExpression
   IIR_Allocator
   ))

;;
;;  emit class headers (AKA declarations)
;;

(defgeneric emit_hdr
  (args (string_ref str) (RegionStack_ref ctxt) (int l))
  (methods
   IIR_EntityDeclaration 
   IIR_ArchitectureDeclaration
   IIR_PackageDeclaration
   IIR_PackageBodyDeclaration
   IIR_ProcessStatement
   IIR_ComponentInstantiationStatement
   IIR_BlockStatement
   IIR_ConcurrentGenerateStatement
   IIR_ConcurrentStatement
   IIR_ConcurrentStatementList
   IIR_SubprogramDeclaration
   IIR_PredefinedFunctionDeclaration
   IIR_PredefinedProcedureDeclaration
   IIR_EnumerationType
   IIR_AccessType
   IIR_FileType
   IIR_ScalarSubtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_TypeDeclaration
   IIR_RecordType
   IIR_RecordSubtype
   IIR_Root
   ))

;;
;;  emit class implementation (AKA definition)
;;

(defgeneric emit_impl
  (args (string_ref str) (RegionStack_ref ctxt) (int l))
  (methods
   IIR_NullStatement 
   IIR_ReturnStatement 
   IIR_VariableAssignmentStatement
   IIR_IfStatement 
   IIR_CaseStatement 
   IIR_LoopStatement 
   IIR_NextStatement
   IIR_ExitStatement
   ;;IIR_LoopControlStatement
   IIR_ProcedureCallStatement 
   IIR_WaitStatement 
   IIR_AssertionStatement
   IIR_ReportStatement 
   IIR_SignalAssignmentStatement
   IIR_SequentialStatement 
   IIR_EntityDeclaration 
   IIR_ArchitectureDeclaration
   IIR_ProcessStatement
   IIR_ComponentInstantiationStatement
   IIR_PackageDeclaration
   IIR_PackageBodyDeclaration
   IIR_BlockStatement
   IIR_ConcurrentGenerateStatement
   IIR_SequentialStatementList
   IIR_SequentialStatement
   IIR_ConcurrentStatement
   IIR_ConcurrentStatementList
   IIR_SubprogramDeclaration
   IIR_PredefinedFunctionDeclaration
   IIR_PredefinedProcedureDeclaration
   IIR_EnumerationType
   IIR_ScalarSubtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_AccessType
   IIR_FileType
   IIR_RecordType
   IIR_RecordSubtype
   ))


(defgeneric cdfg_emit_impl
  (args (string_ref str) (RegionStack_ref ctxt) (int l))
  (methods
   IIR_NullStatement 
   IIR_ReturnStatement 
   IIR_VariableAssignmentStatement
   IIR_IfStatement 
   IIR_CaseStatement 
   IIR_LoopStatement 
   IIR_NextStatement
   IIR_ExitStatement
   ;;IIR_LoopControlStatement
   IIR_ProcedureCallStatement 
   IIR_WaitStatement 
   IIR_AssertionStatement
   IIR_ReportStatement 
   IIR_SignalAssignmentStatement
   IIR_SequentialStatement 
   IIR_EntityDeclaration 
   IIR_ArchitectureDeclaration
   IIR_ProcessStatement
   IIR_ComponentInstantiationStatement
   IIR_PackageDeclaration
   IIR_PackageBodyDeclaration
   IIR_BlockStatement
   IIR_ConcurrentGenerateStatement
   IIR_SequentialStatementList
   IIR_SequentialStatement
   IIR_ConcurrentStatement
   IIR_ConcurrentStatementList
   IIR_SubprogramDeclaration
   IIR_PredefinedFunctionDeclaration
   IIR_PredefinedProcedureDeclaration
   IIR_EnumerationType
   IIR_ScalarSubtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_AccessType
   IIR_FileType
   ))


;; ******************************************************************************************
;; Name: m_emit_info_init , generic function
;;
;; Description: emits initialization code of type info instances
;; 
;; Return value: Static level of the array info instance
;;
;; ******************************************************************************************
(defgeneric emit_info_init
  (args (string_ref str) (RegionStack_ref ctxt) (bool static_info) (int l))
  (return IR_StaticLevel)
  (methods
   IIR_EnumerationType
   IIR_ScalarSubtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_AccessType
   IIR_FileType
   IIR_RecordType
   IIR_RecordSubtype
   ))


;;(defgeneric emit 
;;  (args (string_ref str) (RegionStack_ref ctxt) (int l))
;;  (methods
;;   IIR_Declaration 
;;   IIR_Type 
;;   IIR_InterfaceDeclaration 
;;   IIR_TypeList
;;   ))


(defgeneric get_acl 
  (args (list_expr_pair_ref alist) (RegionStack_ref ctxt) (IR_StaticLevel slevel) (bool start))
  (return bool)
  (methods
   IIR_Expression 
   IIR_SimpleReference 
   IIR_ArrayReference
   IIR_RecordReference
   IIR_ExplicitRange 
   IIR_SliceReference
   ))


(defgeneric cdfg_get_static_expr
  (args (string_ref str) (RegionStack_ref ctxt) (IR_StaticLevel slevel) (id_type t) (bool start))
  (return bool)
  (methods
   IIR_Expression 
   IIR_SimpleReference 
   IIR_ArrayReference
   IIR_ExplicitRange 
   IIR_SliceReference
   ))

;; ******************************************************************************************
;; Name: m_explore_and_check, generic function
;;
;; Description: explore (collect informations about node) and check
;; node for correctness
;;
;; Return value: returns number of errors found
;;
;; ******************************************************************************************
(defgeneric explore_and_check
  (args (RegionStack_ref rstack) (bool collect_access_info))
  (return int)
  (methods
   IIR_EntityDeclaration
   IIR_DeclarationList
   IIR_InterfaceDeclaration
   IIR_ArchitectureDeclaration
   IIR_ConcurrentStatementList
   IIR_ProcessStatement
   IIR_PackageDeclaration
   IIR_PackageBodyDeclaration
   IIR_SubprogramDeclaration
   IIR_ConfigurationDeclaration
   IIR_ComponentDeclaration
   IIR_SequentialStatementList
   IIR_IfStatement
   IIR_ForLoopStatement
   IIR_WhileLoopStatement
   IIR_LoopStatement
   IIR_NextStatement
   IIR_ExitStatement
   IIR_CaseStatement
   IIR_WaitStatement
   IIR_AssociationElement
   IIR_SignalAssignmentStatement
   IIR_VariableAssignmentStatement
   IIR_ComponentInstantiationStatement
   IIR_AssertionStatement
   IIR_ReportStatement
   IIR_ProcedureCallStatement
   IIR_EnumerationType
   IIR_Type
   IIR_RecordType
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_FileType
   IIR_ScalarSubtype
   IIR_Subtype
   IIR_NullStatement
   IIR_ReturnStatement
   IIR_ConcurrentGenerateIfStatement
   IIR_ConcurrentGenerateForStatement
   IIR_PredefinedFunctionDeclaration
   ))


;; ******************************************************************************************
;; Name: m_get_context, generic function
;;
;; Description: Analyzes statements and collects all abjects which are
;; accessed. The information about the accessed objects are stored in
;; a ContextInfo instance. A ContextInfo instance stores three
;; different kinds of informations: 
;;
;; 1. accessed_objects = all objects
;; which are accessed (read, written, sensitive).
;;
;; 2. wait_statements = pointer to the wait statements included in the
;; current context
;;
;; 3. signal_assignment_statements = list of pointers to all signal
;; assignment statements included in the current context
;;
;; 4. internal_vars = internal objects required by the generated code
;;
;; Parameter: ctxt = context info instance
;;   target = is true if the expression is target of an assignment
;;   level = level the object is located at. The entire statement
;; is assigned level 0. The level is increased each time an object is
;; included in an argument to a subroutine or an index value of an
;; array reference.
;; 
;; Return value: returns a pointer to the corresponding access
;; descriptor if an expression is analyzed. Otherwise, NULL is
;; returned.
;;
;; ******************************************************************************************
(defgeneric get_context
  (args (ContextInfo_ref ctxt) (RegionStack_ref rstack) (bool target) (int level))
  (return pAccessDescriptor)
  (methods
   IIR_FunctionCall
   IIR_SimpleReference
   IIR_ArrayReference
   IIR_AccessReference
   IIR_ArrayRange
   IIR_ExplicitRange
   IIR_OthersIndexedAssociation
   IIR_RangeIndexedAssociation
   IIR_SingleIndexedAssociation
   IIR_ElementAssociation
   IIR_SliceReference
   IIR_RecordReference
   IIR_Expression
   IIR_ExpressionList
   IIR_ArrayAggregate
   IIR_RecordAggregate
   IIR_WaitStatement
   IIR_AttrSigFunc
   IIR_TypeConversion
   IIR_Type
   IIR_QualifiedExpression
   IIR_Allocator
   IIR_AttrTypeFunc
   IIR_AttrTypeValue
   IIR_AttrArrayFunc
   ))


;; ******************************************************************************************
;; Name: m_check_expression , generic function
;;
;; Description: checks whether expression is valid and contains no
;; errors. Any errors found are reportet. Parameter rstack is a
;; reference to the current regions stack
;; 
;; Return value: returns number of errors which were found in the expression
;;
;; ******************************************************************************************
(defgeneric check_expression
  (args (RegionStack_ref rstack))
  (return int)
  (methods
   IIR_FunctionCall
   IIR_SimpleReference
   IIR_AccessReference
   IIR_ArrayReference
   IIR_ArrayRange
   IIR_ExplicitRange
   IIR_OthersIndexedAssociation
   IIR_RangeIndexedAssociation
   IIR_SingleIndexedAssociation
   IIR_SliceReference
   IIR_RecordReference
   IIR_Expression
   IIR_ExpressionList
   IIR_ArrayAggregate
   IIR_RecordAggregate
   IIR_AttrSigFunc
   IIR_ArrayLiteralExpression
   IIR_TypeConversion
   IIR_QualifiedExpression
   ))


;; Returns kind of operator:
;;  NO_OP if the function does not denote an operator
;;  PREDEF_OP if the funcion denotes an predefined VHDL operator
;;  BASIC_OP if the function denotes an operator defined in an 
;;           IEEE library (e.g. numeric_std)
;;  OP else
(defgeneric get_operator_type
  (return op_type)
  (methods 
   IIR_FunctionDeclaration
   IIR_ProcedureDeclaration
   ))


(defextension IIR_Declaration
  (
   ;; Stores information about what must be checked at runtime
   (RuntimeCheckFlags runtime_checks)
   ))


;; Some additional informations for all kind of nodes
(defextension IIR_Root
   (
    ;; stores which kinds of optimization has been applied on node
    (int done (= "0"))
    ;; stores the uppermost declarative region to which the
    ;; object/declaration/expression is static. E.g., if a constant is
    ;; delcared within a process and initilized with a generic
    ;; parameter then static_declarative_region is set to the entity
    ;; declarative region (because the constant value is static with
    ;; respect to the entity). Note that the value is set to NULL if
    ;; the object/declaration/expression is not static at all!
    (IIR_DeclarativeRegion static_declarative_region (= "NULL"))
   ))

;; Some additional information for library units (e.g., entity,
;; architecture, configuration, package, package body)
(defextension IIR_LibraryUnit
  (
   ;; stores whether code shall be omitted for this library unit. In
   ;; some case (e.g., if an entity if overwritten by another entity)
   ;; no code is generated for a specific library unit.
   (bool generate_code (= "true"))
   ))


;; Some additional information about expressions and some literals nodes
(defextension IIR_Expression
  (
   (StaticDataType folded_value) ;; Stores long long int/double value of a plain contant
   (bool valid_folded_value (= "false")) ;; folded_value contains an valid value
   ;; Stores information about what must be checked at runtime
   (RuntimeCheckFlags runtime_checks) 
   ))

(defextension IIR_Literal
  (
   (StaticDataType folded_value) ;; Stores long long int/double value of a plain contant
   (bool valid_folded_value (= "false")) ;; folded_value contains an valid value
   ))

(defextension IIR_EnumerationLiteral
  (
   (StaticDataType folded_value) ;; Stores long long int/double value of a plain contant
   (bool valid_folded_value (= "false")) ;; folded_value contains an valid value
   ))

(defextension IIR_PhysicalUnit
  (
   (StaticDataType folded_value) ;; Stores long long int/double value of a plain contant
   (bool valid_folded_value (= "false")) ;; folded_value contains an valid value
   ))

(defextension IIR_Type
  (
   ;; Stores information about what must be checked at runtime
   (RuntimeCheckFlags runtime_checks) 
   ))

(defextension IIR_Subtype
  (
   ;; Anonymous types may be converted into a declared type via an
   ;; implicit type declaration. Then, this slots points to the
   ;; corresponding declaration.
   (V2CC_ImplicitSubtypeDeclaration implicit_subtype_declaration (="NULL"))
   ))

;; stores the index number of the corresponding wait_info object which 
;; connected with the wait statement
(defextension IIR_WaitStatement
  ((int wait_info_index)))


;; stores the index number of the corresponding wait_info object which 
;; connected with a procedure call statement that contains a wait.
(defextension IIR_ProcedureCallStatement
  ((int wait_info_index)))


(defextension IIR_DeclarativeRegion
  (
   ;; Stores context information about the declaration region
   (ContextInfo context)
   ;; Includes all "normal" declarations of the current declaration
   ;; list and additional implicit type declarations.
   (IIR_DeclarationList extended_declarations (="NULL"))
   ))


(defextension IIR_EntityDeclaration
  (
   ;; Includes all "normal" declarations of the current declaration
   ;; list and additional implicit type declarations.
   (IIR_DeclarationList extended_generic_clause (="NULL"))
   (IIR_DeclarationList extended_port_clause (="NULL"))
   ))

(defextension IIR_SubprogramDeclaration
  (
   ;; Includes all "normal" declarations of the current declaration
   ;; list and additional implicit type declarations.
   (IIR_DeclarationList extended_interface_declarations (="NULL"))
   ))

(defextension IIR_ConcurrentStatement
  (
   ;; Store all additional parameters required by the constructors of
   ;; the corresponding C++ classes.
   (IIR_DeclarationList extended_interface_declarations (="NULL"))
   ))

(defextension IIR_BlockStatement
  (
   ;; Includes all "normal" declarations of the current declaration
   ;; list and additional implicit type declarations.
   ;; Includes all "normal" declarations of the current declaration
   ;; list and additional implicit type declarations.
   (IIR_DeclarationList extended_generic_clause (="NULL"))
   (IIR_DeclarationList extended_port_clause (="NULL"))
   ))

;; Store some additional information about the array aggregat
(defextension IIR_ArrayAggregate
  ((int dest_length) ;; length of the aggregate as determined form the aggregate subtype
   (int dest_left) ;; left bound of aggregate as determined from the agregate subtype
   (int dest_right) ;; right bound of aggregate as determined from the agregate subtype
   (IR_Direction dest_direction) ;; direction of aggregate as determined from the agregate subtype
   (bool named_association) ;; is true when the aggregate uses named association
   (bool known_subtype) ;; is true if subtype of aggregate is known from the context
   (bool has_others) ;; aggregat includes an others choice
   (bool locally_static_ranges) ;; true if all index ranges of the choices are locally static
   (int total_length) ;; total number of array elements (can be determined only if locally_static_ranges=true)
   (int min_index) ;; minimal index number among all choices (if determinable, i.e. locally_static_ranges=true)
   (int max_index))) ;; maximal index number among all choices (if determinable, i.e. locally_static_ranges=true)


;; Some additional information about a specific indexed association
(defextension IIR_IndexedAssociation
  ((bool locally_static_range) ;; true if all choices are locally range
   (int length) ;; number of elements (can be determined only if locally_static_range=true)
   (int min_index) ;; minimal index number among all choices (if determinable, i.e. locally_static_range=true)
   (int max_index))) ;; maximal index number among all choices (if determinable, i.e. locally_static_range=true)

(defextension IIR_EnumerationType
  ((int enum_item_number))) ;; number of enumeration items


(defextension IIR_ObjectDeclaration
  ((bool alias_check_bounds) ;; bounds must be checked at runtime
   ))

(defextension IIR_LoopStatement
  ((bool next_statement_used (= "false")) ;; stores whether a next statement was used for this loop
   (bool exit_statement_used (= "false")) ;; stores whether a exit statement was used for this loop
   (int loop_id (= "-1")) ;; number used to create unique labels for loops
   ))

(defextension IIR_ProcessStatement
  (
   ;; is true when the process includes (directly or indirectly) a
   ;; wait statement
   (bool has_wait (= "false"))
   ;; is true when the process includes (directly or indirectly) a
   ;; wait statement with an "for" clause
   (bool has_wait_for (= "false"))
   ))


(defextension IIR_ProcedureDeclaration
  (
   ;; is true when the process includes (directly or indirectly) a
   ;; wait statement
   (bool has_wait (= "false"))
   ;; is true when the procedure includes (directly or indirectly) a
   ;; wait statement with an "for" clause
   (bool has_wait_for (= "false")) 
   ))


;; ******************************************************************************************
;; Name: m_get_object_declaration , generic function
;;
;; Description: Returns the object declaration a reference expression
;; is based on. E.g. an expression "sig(3 downto 1)" will retrun the
;; object delcration pointer associated with "sig". Note that if the
;; prefix is a signal kind attribute then this signal attribute object
;; is returned!
;; 
;; Return value: returns object declaration
;;
;; ******************************************************************************************

(defgeneric get_object_declaration
  (return pIIR_ObjectDeclaration)
  (methods
   IIR_ObjectReference
   IIR_SimpleReference
   IIR_SliceReference
   IIR_SignalAttr
   IIR_ArrayReference
   IIR_RecordReference
   ))



;; ******************************************************************************************
;; Name: V2CC_InternalObjectDeclaration, node
;;
;; Description: A new declaration node type for internal objects which
;; are created by the code generator. Nothe that internal objects are
;; introduced by the code generation phase. They are needed by the
;; generated code in order to successfully map VHDL code to C++.
;;
;; 
;;
;; ******************************************************************************************

(defnode V2CC_InternalObjectDeclaration (IIR_ObjectDeclaration)
  (
   ;; C++ type of the object plotted into a string. Note that if this
   ;; string is empty then the type of the object is defined by the
   ;; subtype slot of the inherited IIR_ObjectDeclaration class.
   (string cpp_type_string) 
   ;; Initial value of the object. If the string is empty then the
   ;; initial value may be specified by the corresponding expression
   ;; pointer of the base class.
   (string cpp_initial_string)
   ;; Some additional information may be stored here
   (int flags)
  ))


;; ******************************************************************************************
;; Name: V2CC_ImplicitSignalDeclaration, node
;;
;; Description: A new declaration node type implicitly generated 
;; signals. Servers as a base type for several derived implicit
;; signal types
;;
;; ******************************************************************************************

(defnode V2CC_ImplicitSignalDeclaration (IIR_SignalDeclaration)
  ())


;; ******************************************************************************************
;; Name: V2CC_ImplicitSignalDeclaration_WaitFor, node
;;
;; Description: An implicit signal which is used to implement wait 
;; for clauses of wait statements
;;
;; ******************************************************************************************

(defnode V2CC_ImplicitSignalDeclaration_WaitFor (V2CC_ImplicitSignalDeclaration)
  ())


;; ******************************************************************************************
;; Name: V2CC_ImplicitSignalDeclaration_Transaction, node
;;
;; Description: An implicit signal which is used to implement the 
;; 'transaction functionality of VHDL
;;
;; ******************************************************************************************

(defnode V2CC_ImplicitSignalDeclaration_Transaction (V2CC_ImplicitSignalDeclaration)
  ())


;; ******************************************************************************************
;; Name: V2CC_InternalCode, node
;;
;; Description: Stores generated C++ code sequences which shall be
;; printed to the output file. Usually, it is used to store code
;; generated from VHDL subprograms declarations.
;; 
;;
;; ******************************************************************************************

(defnode V2CC_InternalCode (IIR_ObjectDeclaration)
  (
   ;; Header code
   (string cpp_header_string) 
   ;; Implementation code
   (string cpp_impl_string)
   ;; Some additional information may be stored here
   (int flags))
  )


;; ******************************************************************************************
;; Name: V2CC_ImplicitSubtypeDeclaration
;;
;; Description: A subtype declaration which is created by the code
;; generator from a implicit type declaration. E.g., for a declaration
;; "variable v : bit_vector(0 to 7);" an anonymous type "subtype
;; anonymous_type is bit_vector(0 to 7)" is generated and used in the
;; subsequent variable declaration.
;;
;; ******************************************************************************************

(defnode V2CC_ImplicitSubtypeDeclaration (IIR_SubtypeDeclaration)())


;; ******************************************************************************************
;; Name: V2CC_ImplicitInterfaceSubtypeDeclaration
;;
;; Description: A subtype declaration which is created by the code
;; generator from a implicit type declaration. E.g., for a declaration
;; "variable v : bit_vector(0 to 7);" an anonymous type "subtype
;; anonymous_type is bit_vector(0 to 7)" is generated and used in the
;; subsequent variable declaration.
;;
;; ******************************************************************************************

;;(defnode V2CC_ImplicitInterfaceSubtypeDeclaration (IIR_InterfaceDeclaration)())


;; ******************************************************************************************
;; Name: m_qid , generic function
;;
;; Description: Returns get a fully qualified identifier name plus an
;; appropriate prefix. I.e., if a identifier is used at a location in
;; the code where it is not directly visible then some prefix code is
;; needed in order to access it. E.g., if a generic parameter is used
;; within process then it is accessed using a architecture pointer as
;; the parameter is not directly visible within the process. parameter
;; rstack determines the code region where the identifier is to be
;; used. Parameter obj_access defines how the identifier is accessed.
;; 
;; Return value: returns fully qualified string
;;
;; ******************************************************************************************

(defgeneric qid
  (args (RegionStack_ref rstack) (id_type obj_access))
  (return string)
  (methods
   IIR_LibraryUnit
   IIR_Declaration
   IIR_SignalDeclaration
   IIR_InterfaceDeclaration
   IIR_SignalInterfaceDeclaration
   V2CC_ImplicitSignalDeclaration_WaitFor
   IIR_ObjectDeclaration
   IIR_SignalDeclaration
   IIR_SubprogramDeclaration
   IIR_TypeDeclaration
   IIR_Subtype
   IIR_Type
   ))


;; ******************************************************************************************
;; Name: m_get_type_info_obj , generic function
;;
;; Description: Returns type info object for a type or subtype. If the
;; (sub)type is anonymous then code which generates a new type info
;; objects is returned. static_object controls whether a new created
;; info object shall be static (i.e., it is never removed) or not.
;; 
;; Return value: string
;;
;; ******************************************************************************************
(defgeneric get_type_info_obj
  (args (RegionStack_ref rstack) (bool static_object))
  (return string)
  (methods
   IIR_EnumerationType
   IIR_IntegerType
   IIR_PhysicalType
   IIR_FloatingType
   IIR_ScalarSubtype
   IIR_RecordSubtype
   IIR_Subtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_AccessType
   IIR_FileType
   IIR_RecordType
   ))

;; ******************************************************************************************
;; Name: m_get_discrete_range , generic function
;;
;; Description: Returns an array of RangeDescriptors derived from the
;; first parameter. Note that usually this function is called to
;; determine the bounds on an scalar type or the index bounds on an
;; array. In most cases it will return an array containing only a
;; single element. However, when called to extract the index ranges
;; from an array several RangeDescriptors may be returned where each
;; one covers one index range.
;; 
;; Return value: RangeDescriptor (see v2cc.h)
;;
;; ******************************************************************************************
(defgeneric get_discrete_range
  (args (RegionStack_ref rstack) (IR_StaticLevel slevel))
  (return RangeDescriptor_vec)
  (methods
   IIR_EnumerationType
   IIR_IntegerType
   IIR_PhysicalType
   IIR_FloatingType
   IIR_ScalarSubtype
   IIR_ExplicitRange
   IIR_SliceReference
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_Attr_ArrayRANGE
   IIR_Attr_ArrayREVERSE_RANGE
   ))


;; ******************************************************************************************
;; Name: m_get_static_level , generic function
;;
;; Description: Determines static level of an type or expression
;; 
;; Return value: returns static level
;;
;; ******************************************************************************************

(defgeneric get_static_level
  (args (RegionStack_ref rstack))
  (return IR_StaticLevel)
  (methods
   IIR_Type
   IIR_Expression))


;; ******************************************************************************************
;; Name: m_constant_fold , generic function
;;
;; Description: performs constant folding optimizations on nodes
;; 
;; Return value: returns number of errors found during folding
;;
;; ******************************************************************************************

(defgeneric constant_fold
  (args (RegionStack_ref rstack))
  (return int)
  (methods
   IIR_Type
   IIR_PhysicalType
   IIR_ScalarSubtype
   IIR_ArrayType
   IIR_ArraySubtype
   IIR_AttrSigFunc
   IIR_ArrayLiteralExpression
   IIR_EnumLiteralReference
   IIR_FunctionCall
   IIR_SimpleReference
   IIR_ArrayReference
   IIR_ArrayRange
   IIR_AttrArrayFunc
   IIR_AttrTypeFunc
   IIR_AttrTypeValue
   IIR_ExplicitRange
   IIR_OthersIndexedAssociation
   IIR_SingleIndexedAssociation
   IIR_RangeIndexedAssociation
   IIR_SliceIndexedAssociation
   IIR_SliceReference
   IIR_RecordReference
   IIR_Expression
   IIR_TypeConversion
   IIR_ExpressionList
   IIR_ArrayAggregate
   IIR_RecordAggregate
   IIR_FloatingPointLiteral
   IIR_IntegerLiteral
   IIR_AbstractLiteralExpression
   IIR_PhysicalLiteral
   IIR_EnumerationLiteral
   IIR_PhysicalUnit
   IIR_QualifiedExpression
   IIR_Allocator
   ))


;; ******************************************************************************************
;; Name: m_optmize , generic function
;;
;; Description: performs some optimizations
;; 
;; Return value: void
;;
;; ******************************************************************************************


(defgeneric optimize
  (args (RegionStack_ref rstack))
  (methods
   IIR_PredefinedFunctionDeclaration
   IIR_SubprogramDeclaration
   IIR_EntityDeclaration
   IIR_Type
   IIR_ArchitectureDeclaration
   IIR_ConcurrentStatementList
   IIR_ProcessStatement
   IIR_PackageDeclaration
   IIR_PackageBodyDeclaration
   IIR_ConfigurationDeclaration
   IIR_ComponentDeclaration
   IIR_ComponentInstantiationStatement
   IIR_ConcurrentGenerateIfStatement
   IIR_ConcurrentGenerateForStatement
   ))




