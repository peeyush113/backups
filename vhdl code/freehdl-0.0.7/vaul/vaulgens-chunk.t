;; -*- scheme -*-

(include "freehdl/vaul-chunk.t")

(chunk vaulgens)

(header-add "#include <freehdl/fire.h>"
	    "#include <freehdl/vaul-chunk.h>")

(impl-add "#include \"vaulgens-chunk.h\"")

(defctype VAUL_ObjectClass)

(defgeneric vaul_get_base
  (return IIR_Type)
  (methods IIR_Type))

(defgeneric vaul_get_class
  (return VAUL_ObjectClass)
  (methods
   IIR_Expression IIR_RecordReference IIR_GenericArrayReference
   IIR_SignalAttr IIR_SimpleReference IIR_AccessReference
   IIR_ConstantInterfaceDeclaration IIR_VariableInterfaceDeclaration
   IIR_SignalInterfaceDeclaration IIR_FileInterfaceDeclaration
   IIR_ConstantDeclaration IIR_VariableDeclaration
   IIR_SignalDeclaration IIR_FileDeclaration))

(defgeneric vaul_get_mode
  (return IR_Mode)
  (methods
   IIR_Expression IIR_RecordReference IIR_GenericArrayReference
   IIR_SignalAttr IIR_SimpleReference IIR_AccessReference
   IIR_InterfaceDeclaration IIR_VariableDeclaration
   IIR_ConstantDeclaration IIR_SignalDeclaration IIR_FileDeclaration))

(defgeneric vaul_get_type
  (return IIR_Type)
  (methods
   IIR_RecordReference IIR_ArrayReference IIR_SliceReference
   IIR_SimpleReference IIR_AccessReference))

(defgeneric vaul_get_object_declaration
  (return IIR_ObjectDeclaration)
  (methods
   IIR_Expression
   IIR_RecordReference IIR_GenericArrayReference
   IIR_SimpleReference IIR_AccessReference))

(defgeneric vaul_get_generics
  (return IIR_InterfaceList)
  (methods IIR_ComponentDeclaration IIR_EntityDeclaration
	   IIR_ArchitectureDeclaration IIR_ArchitectureRef
	   IIR_BlockStatement))

(defgeneric vaul_get_ports
  (return IIR_InterfaceList)
  (methods IIR_ComponentDeclaration IIR_EntityDeclaration
	   IIR_ArchitectureDeclaration IIR_ArchitectureRef
	   IIR_BlockStatement))

(defgeneric vaul_set_generics
  (args (IIR_InterfaceList generics))
  (methods IIR_ComponentDeclaration IIR_EntityDeclaration
	   IIR_BlockStatement))

(defgeneric vaul_set_ports
  (args (IIR_InterfaceList ports))
  (methods IIR_ComponentDeclaration IIR_EntityDeclaration
	   IIR_BlockStatement))

(defgeneric vaul_get_stats
  (return IIR_ConcurrentStatementList)
  (methods IIR_ComponentDeclaration IIR_EntityDeclaration
	   IIR_ArchitectureDeclaration IIR_ConfigurationDeclaration
	   IIR_BlockStatement))

(defgeneric vaul_compute_static_level
  (return IR_StaticLevel)
  (methods IIR_AbstractLiteralExpression
	   IIR_EnumLiteralReference IIR_ArrayLiteralExpression
	   IIR_SimpleReference IIR_RecordReference
	   IIR_Declaration IIR_ConstantDeclaration
	   IIR_ConstantInterfaceDeclaration IIR_FunctionCall
	   IIR_AttrTypeValue IIR_AttrTypeFunc IIR_AttrArrayFunc
	   IIR_AttrSigFunc
	   IIR_QualifiedExpression IIR_TypeConversion
	   IIR_ArrayAggregate IIR_RecordAggregate
	   IIR_Allocator
	   IIR_Expression
	   IIR_ExplicitRange IIR_ArrayRange
	   IIR_RecordType IIR_ArrayType
	   IIR_ArraySubtype IIR_RecordSubtype IIR_ScalarSubtype
	   IIR_Type))

(defgeneric vaul_get_configuration_specifications
  (return IIR_ConfigurationSpecificationList)
  (methods IIR_ArchitectureDeclaration IIR_BlockStatement
	   IIR_ConcurrentGenerateStatement))

(defgeneric vaul_set_configuration_specifications
  (args (IIR_ConfigurationSpecificationList specs))
  (methods IIR_ArchitectureDeclaration IIR_BlockStatement
	   IIR_ConcurrentGenerateStatement))

(defctype ostream_ref (cname "std::ostream&"))

(defgeneric vaul_print_to_ostream 
  (args (ostream_ref o))
  (methods
   IIR_PosInfo_TextFile IIR_PosInfo_Sheet IIR_Root IIR_TextLiteral
   IIR_IntegerLiteral IIR_FloatingPointLiteral IIR_Declaration
   VAUL_SimpleName VAUL_AttributeName VAUL_SelName VAUL_IftsName
   IIR_Type IIR_Subtype IIR_ArrayType IIR_AccessType IIR_PhysicalType
   IIR_EnumerationLiteral IIR_SubprogramDeclaration IIR_ExplicitRange
   IIR_ArrayRange IIR_TypeList IIR_SimpleReference IIR_SliceReference
   IIR_FunctionCall IIR_AbstractLiteralExpression 
   IIR_ArrayLiteralExpression
   IIR_PhysicalLiteral
   VAUL_AmbgArrayLitRef IIR_ArrayReference IIR_RecordReference
   IIR_ElementDeclaration IIR_ChoiceByExpression VAUL_ChoiceByName
   IIR_ChoiceByRange VAUL_UnresolvedName IIR_QualifiedExpression
   VAUL_AmbgAggregate IIR_ArrayAggregate IIR_SingleIndexedAssociation
   IIR_RangeIndexedAssociation IIR_OthersIndexedAssociation
   VAUL_RangeAssocElem
   VAUL_NamedAssocElem
   VAUL_AmbgEnumLitRef IIR_Allocator
   IIR_EnumLiteralReference
   IIR_AttrTypeValue
   IIR_AttrTypeFunc
   ))
