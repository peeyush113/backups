;; -*- scheme -*-

;;;  Copyright (C) 1998, 1999, 2000, 2001, 2003  Marius Vollmer
;;;
;;;  VAUL is free software; you can redistribute it and/or modify it
;;;  under the terms of the GNU Library General Public License as
;;;  published by the Free Software Foundation; either version 2 of the
;;;  License, or (at your option) any later version.
;;;
;;;  VAUL is distributed in the hope that it will be useful, but WITHOUT
;;;  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
;;;  or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General
;;;  Public License for more details.
;;;
;;;  You should have received a copy of the GNU Library General Public
;;;  License along with VAUL; see the file COPYING.LIB.  If not, write
;;;  to the Free Software Foundation, Inc., 59 Temple Place, Suite 330,
;;;  Boston, MA 02111-1307 USA.

(define (format-fire-kind name)
  (upcase (concat-strings (cons "ir" (cdr (syllables name))) "_")))

(chunk fire
  (struct-fmt "~a")
  (pointer-fmt "p~a")
  (kind-fmt-func format-fire-kind)
  (creator-fmt "m~a"))

(header-add "#include <freehdl/tree-supp.h>"
	    "#include <freehdl/fire-types.h>"
	    "#include <iostream>")

(impl-add "#include <freehdl/fire-chunk.h>")

;; A string who's memory is owned by someone else.  This should go
;; away sometime.
(defctype fire_string
  (cname "const char*")
  (printer "fire_print_string"))

(defctype bool
  (printer "fire_print_bool"))

(defctype int
  (printer "fire_print_int"))

(defctype IR_Kind)

(defctype IR_Character)

(defctype IR_String
  (printer "fire_print_IR_String"))

(defctype IR_SignalKind
  (printer "fire_print_int"))

(defctype IR_Mode
  (printer "fire_print_int"))

(defctype IR_Pure
  (printer "fire_print_int"))

(defctype IR_Direction
  (printer "fire_print_int"))

(defctype IR_DelayMechanism
  (printer "fire_print_int"))

(defctype IR_StaticLevel
  (printer "fire_print_int"))

;;; Chapter 5 -- IIR Base Class

;; Position information

(defnode IIR_PosInfo ()
  ())

(defnode IIR_PosInfo_TextFile (IIR_PosInfo)
  ((fire_string file_name)        ; XXX - IR_String
   (int         line_number)))

(defnode IIR_PosInfo_Sheet (IIR_PosInfo)
  ((fire_string sheet_name)       ; XXX - IR_String
   (int         x_coordinate)     ; what units?
   (int         y_coordinate)))

;; The base class.  This is what AIRE calls "IIR", but we give it a
;; real name.  "fire-types.h" contains suitable typedefs to make "IIR"
;; an alias for "IIR_Root".

(defnode IIR_Root ()
  ((IIR_PosInfo pos)))

;;; Dummy definitions.  Until FIRE is fully fleshed out we need some
;;; dummy types.

(defnode IIR_Dummy (IIR_Root)
  ())

(defmacro dummy (name)
  `(defnode ,name (IIR_Dummy)
     ()))

(dummy IIR_Signature)

;;; Chapter 7 -- Literals

(defnode IIR_Literal (IIR_Root)
  ())

(defnode IIR_TextLiteral (IIR_Literal)
  ((IR_String text)))

(defnode IIR_Identifier (IIR_TextLiteral)
  ())

(defnode IIR_CharacterLiteral (IIR_TextLiteral)
  ())

(defnode IIR_StringLiteral (IIR_TextLiteral)
  ())

(defnode IIR_AbstractLiteral (IIR_Literal)
  ())

(defnode IIR_IntegerLiteral (IIR_AbstractLiteral)
  ((IR_String text)))

(defnode IIR_FloatingPointLiteral (IIR_AbstractLiteral)
  ((IR_String text)))

;;; Chapter 8 -- Tupels

(defnode IIR_Tuple (IIR_Root)
  ())

(defnode IIR_AssociationElement (IIR_Tuple)
  ((IIR_ObjectReference formal)
   (IIR_InterfaceDeclaration formal_declaration)
   (IIR_Declaration formal_conversion)
   (IIR_Expression actual)
   (IIR_Declaration actual_conversion)))

(defnode IIR_AssociationElementByExpression (IIR_AssociationElement)
  ())

(defnode IIR_AssociationElementOpen (IIR_AssociationElement)
  ())

(defnode IIR_CaseStatementAlternative (IIR_Tuple)
  ((IIR_SequentialStatementList sequence_of_statements)
   (IIR_ChoiceList choices)))

(defnode IIR_Choice (IIR_Tuple)
  ())

(defnode IIR_ChoiceByExpression (IIR_Choice)
  ((IIR_Expression value)))

(defnode IIR_ChoiceByRange (IIR_Choice)
  ((IIR_Range range)))

(defnode IIR_ChoiceByOthers (IIR_Choice)
  ())

(defnode IIR_EntityClassEntry (IIR_Tuple)
  ((IR_Kind entity_kind)
   (bool is_boxed)))

(defnode IIR_WaveformElement (IIR_Tuple)
  ((IIR_Expression value)
   (IIR_Expression time)))

(defnode IIR_ElementAssociation (IIR_Tuple)
  ((IIR_ElementDeclaration element)
   (IIR_Expression value)))

(defnode IIR_IndexedAssociation (IIR_Tuple)
  ((IIR_Expression value)))

(defnode IIR_SingleIndexedAssociation (IIR_IndexedAssociation)
  ((IIR_Expression index)))

(defnode IIR_RangeIndexedAssociation (IIR_IndexedAssociation)
  ((IIR_Range index_range)))

(defnode IIR_SliceIndexedAssociation (IIR_RangeIndexedAssociation)
  ())

(defnode IIR_OthersIndexedAssociation (IIR_IndexedAssociation)
  ())

(defnode IIR_AttributeValue (IIR_Tuple)
  ((IIR_Expression value)
   (IIR_AttributeDeclaration attribute)))

;;; Chapter 9 -- Lists

(defnode IIR_List (IIR_Root)
  ())

(defmacro deflist (name type)
  `(defnode ,name (IIR_List)
     ((,type first)
      (,name rest))
     (reverse rest)))

(deflist IIR_AssociationList IIR_AssociationElement)
(deflist IIR_AttributeValueList IIR_AttributeValue)
(deflist IIR_CaseStatementAlternativeList IIR_CaseStatementAlternative)
(deflist IIR_ChoiceList IIR_Choice)
(deflist IIR_ConcurrentStatementList IIR_ConcurrentStatement)
(deflist IIR_ConfigurationItemList IIR_ConfigurationItem)
(deflist IIR_DeclarationList IIR_Declaration)
(deflist IIR_ElementDeclarationList IIR_ElementDeclaration)
(deflist IIR_EntityClassEntryList IIR_EntityClassEntry)
(deflist IIR_EnumerationLiteralList IIR_EnumerationLiteral)
(deflist IIR_InterfaceList IIR_InterfaceDeclaration)
(deflist IIR_LibraryUnitList IIR_LibraryUnit)
(deflist IIR_SequentialStatementList IIR_SequentialStatement)
(deflist IIR_UnitList IIR_PhysicalUnit)
(deflist IIR_WaveformList IIR_WaveformElement)
(deflist IIR_TypeList IIR_Type)
(deflist IIR_ExpressionList IIR_Expression)
(deflist IIR_IndexedAssociationList IIR_IndexedAssociation)
(deflist IIR_ElementAssociationList IIR_ElementAssociation)
(deflist IIR_ComponentInstantiationList IIR_ComponentInstantiationStatement)
(deflist IIR_ConfigurationSpecificationList IIR_ConfigurationSpecification)
(deflist IIR_IdentifierList IIR_Identifier)

;; XXX - can't do this unless IIR_GenericList/IIR_PortList is
;;       derived from IIR_InterfaceList
;;(deflist IIR_GenericList IIR_ConstantInterfaceDeclaration)
;;(deflist IIR_PortList IIR_SignalInterfaceDeclaration)

;;; Chapter 10 - Type Definitions

;; This is far from AIRE compliant, but according to me and SAVANT,
;; AIRE is pretty broken in this area anyway.  Right now I'm
;; particularily displeased with the long names, AIRE's arrangement of
;; the subtypes, the missing ability to express ranges that are
;; attributes and the way multidimensional arrays are handled.

(defnode IIR_Range (IIR_Root)
  ())

(defnode IIR_ExplicitRange (IIR_Range)
  ((IIR_Expression left)
   (IIR_Expression right)
   (IR_Direction direction)))

(defnode IIR_ArrayRange (IIR_Range)
  ((IIR_Type type)
   (IIR_Expression array)
   (IIR_Type array_type)
   (IIR_Expression index)))

(defnode IIR_Attr_ArrayRANGE (IIR_ArrayRange)
  ())

(defnode IIR_Attr_ArrayREVERSE_RANGE (IIR_ArrayRange)
  ())

(defnode IIR_Type (IIR_Root)
  ((IIR_TypeDeclaration declaration)
   (IIR_Type base (init-filter "(base == NULL)? this:base"))
   (IR_StaticLevel static_level)))

(defnode IIR_Subtype (IIR_Type)
  ((IIR_Type immediate_base)
   (IIR_FunctionDeclaration resolution_function)))

(defnode IIR_ScalarType (IIR_Type)
  ())

(defnode IIR_ScalarSubtype (IIR_Subtype)
  ((IIR_Range range)))

(defnode IIR_EnumerationType (IIR_ScalarType)
  ((IIR_EnumerationLiteralList enumeration_literals)))

(defnode IIR_IntegerType (IIR_ScalarType)
  ())

(defnode IIR_FloatingType (IIR_ScalarType)
  ())

(defnode IIR_PhysicalType (IIR_ScalarType)
  ((IIR_PhysicalUnit primary_unit)
   (IIR_UnitList units)))

(defnode IIR_CompositeType (IIR_Type)
  ())

(defnode IIR_RecordType (IIR_CompositeType)
  ((IIR_ElementDeclarationList element_declarations)))

(defnode IIR_RecordSubtype (IIR_Subtype)
  ())

(defnode IIR_AccessType (IIR_Type)
  ((IIR_Type designated_type)))

(defnode IIR_FileType (IIR_Type)
  ((IIR_Type type_mark)))

(defnode IIR_ArrayType (IIR_CompositeType)
  ((IIR_TypeList index_types)
   (IIR_Type element_type)))

(defnode IIR_ArraySubtype (IIR_Subtype)
  ((IIR_TypeList constraint)))

;;; Chapter 11 - Declarations

(defnode IIR_Declaration (IIR_Root)
  ((IIR_TextLiteral declarator)
   (IIR_DeclarativeRegion declarative_region)
   (IIR_AttributeValueList attributes)
   (int seqno)))

(defnode IIR_DeclarativeRegion (IIR_Declaration)
  ((IIR_DeclarativeRegion continued)
   (IIR_DeclarationList declarations)))

(defnode IIR_LoopDeclarativeRegion (IIR_DeclarativeRegion)
  ((IIR_LoopStatement loop_statement)))

(defnode IIR_SubprogramDeclaration (IIR_DeclarativeRegion)
  ((IIR_InterfaceList interface_declarations)
   (IIR_SequentialStatementList subprogram_body)
   (IIR_SubprogramDeclaration prototype)))

(defnode IIR_ProcedureDeclaration (IIR_SubprogramDeclaration)
  ())

(defnode IIR_PredefinedProcedureDeclaration (IIR_ProcedureDeclaration)
  ())

(defnode IIR_FunctionDeclaration (IIR_SubprogramDeclaration)
  ((bool pure)
   (IIR_Type return_type)))

(defnode IIR_PredefinedFunctionDeclaration (IIR_FunctionDeclaration)
  ())

(defnode IIR_EnumerationLiteral (IIR_Declaration)
  ((IIR_EnumerationType subtype)
   (int enum_pos)))

(defnode IIR_ElementDeclaration (IIR_Declaration)
  ((IIR_Type subtype)
   (int declaration_pos)))

(defnode IIR_TypeDeclaration (IIR_Declaration)
  ((IIR_Type type)))

(defnode IIR_SubtypeDeclaration (IIR_TypeDeclaration)
  ())

(defnode IIR_ObjectDeclaration (IIR_Declaration)
  ((IIR_Type subtype)
   (IIR_Expression initial_value)
   (IIR_ObjectReference alias_base)))

(defnode IIR_ConstantDeclaration (IIR_ObjectDeclaration)
  ())

(defnode IIR_VariableDeclaration (IIR_ObjectDeclaration)
  ())

(defnode IIR_SharedVariableDeclaration (IIR_VariableDeclaration)
  ())

(defnode IIR_SignalDeclaration (IIR_ObjectDeclaration)
  ((IR_SignalKind signal_kind)))

(defnode IIR_FileDeclaration (IIR_ObjectDeclaration)
  ((IIR_Expression file_open_expression)
   (IIR_Expression file_logical_name)))

(defnode IIR_InterfaceDeclaration (IIR_ObjectDeclaration)
  ((IR_Mode mode)
   (bool bus)))

(defnode IIR_ConstantInterfaceDeclaration (IIR_InterfaceDeclaration)
  ())

(defnode IIR_VariableInterfaceDeclaration (IIR_InterfaceDeclaration)
  ())

(defnode IIR_SignalInterfaceDeclaration (IIR_InterfaceDeclaration)
  ((IR_SignalKind signal_kind)))

(defnode IIR_FileInterfaceDeclaration (IIR_InterfaceDeclaration)
  ())

;(defnode IIR_AliasDeclaration (IIR_ObjectDeclaration)
;  ())

(defnode IIR_AttributeDeclaration (IIR_Declaration)
  ((IIR_Type subtype)))

(defnode IIR_ComponentDeclaration (IIR_DeclarativeRegion) ;; XXX
  ((IIR_InterfaceList local_generic_clause)
   (IIR_InterfaceList local_port_clause)))

(defnode IIR_LibraryDeclaration (IIR_Declaration)
  ((IIR_LibraryUnitList primary_units)))

(defnode IIR_LibraryUnit (IIR_DeclarativeRegion)
  ((IIR_DeclarationList context_items)
   (IIR_DeclarationList external_decls)
   (IIR_TextLiteral library_name)
   (IIR_LibraryUnitList used_units)))

(defnode IIR_EntityDeclaration (IIR_LibraryUnit)
  ((IIR_InterfaceList generic_clause)
   (IIR_InterfaceList port_clause)
   (IIR_ConcurrentStatementList entity_statement_part)))

(defnode IIR_ArchitectureDeclaration (IIR_LibraryUnit)
  ((IIR_EntityDeclaration entity)
   (IIR_ConfigurationSpecificationList configuration_specifications)
   (IIR_ConcurrentStatementList architecture_statement_part)))

;; A delayed reference to an architecture.  The backend has to find
;; out for itself which architecture is requested.  This is the right
;; thing to do when the IR can be saved to disk.

(defnode IIR_ArchitectureRef (IIR_DeclarativeRegion)
  ((IIR_EntityDeclaration entity)
   (IIR_TextLiteral architecture_name)))

(defnode IIR_PackageDeclaration (IIR_LibraryUnit)
  ())

(defnode IIR_PackageBodyDeclaration (IIR_LibraryUnit)
  ((IIR_PackageDeclaration package)))

(defnode IIR_ConfigurationDeclaration (IIR_LibraryUnit)
  ((IIR_BlockConfiguration block_configuration)
   (IIR_EntityDeclaration entity)))

(defnode IIR_ConfigurationItem (IIR_DeclarativeRegion) ;; XXX
  ())

(defnode IIR_BlockConfiguration (IIR_ConfigurationItem)
  ((IIR_DeclarativeRegion block_specification)
   (IIR_DeclarationList use_clause_list)
   (IIR_ConfigurationItemList configuration_item_list)))

(defnode IIR_ComponentConfiguration (IIR_ConfigurationItem)
  ((IIR_LibraryUnit entity_aspect)
   (IIR_ComponentInstantiationList instantiation_list)
   (IIR_AssociationList generic_map_aspect)
   (IIR_AssociationList port_map_aspect)
   (IIR_BlockConfiguration block_config)))

(defnode IIR_PhysicalUnit (IIR_Declaration)
  ((IIR_Expression multiplier)
   (IIR_PhysicalUnit unit_name)
   (IIR_PhysicalType type)
   (int unit_pos)))

(defnode IIR_BindingIndication (IIR_Tuple)
  ((IIR_DeclarativeRegion unit)
   (IIR_AssociationList generic_map_list)
   (IIR_AssociationList port_map_list)))

;;(defnode IIR_LabelledBindingIndication (IIR_Tuple)
;;  ((IIR_IdentifierList labels)
;;   (IIR_BindingIndication binding)))

;;(deflist IIR_LabelledBindingIndicationList IIR_LabelledBindingIndication)

(defnode IIR_ConfigurationSpecification (IIR_Tuple)
  ((IIR_Identifier label)                         ; label == NULL: others
   (IIR_ComponentDeclaration component)
   (IIR_BindingIndication binding)))

(defnode IIR_DisconnectSpecification (IIR_Declaration)
  ((IIR_Type type_mark)
   (IIR_Expression time_expression)
   (IIR_ObjectReference guarded_signal)))

(defnode IIR_Label (IIR_Declaration)
  ((IIR_SequentialStatement statement)))

(defnode IIR_LibraryClause (IIR_Declaration)
  ())

(defnode IIR_UseClause (IIR_Declaration)
  ((IIR_Declaration used_unit)))

;;; Chapter 13 -- Expressions

(defnode IIR_Expression (IIR_Root)
  ((IIR_Type subtype)
   (IR_StaticLevel static_level)))

(defnode IIR_AbstractLiteralExpression (IIR_Expression)
  ((IIR_AbstractLiteral value)))

(defnode IIR_PhysicalLiteral (IIR_AbstractLiteralExpression)
  ((IIR_PhysicalUnit unit)))

(defnode IIR_ArrayLiteralExpression (IIR_Expression)
  ((IIR_StringLiteral value)))

(defnode IIR_EnumLiteralReference (IIR_Expression)
  ((IIR_EnumerationLiteral value)))

(defnode IIR_NullExpression (IIR_Expression)
  ())

(defnode IIR_Aggregate (IIR_Expression)
  ())

(defnode IIR_RecordAggregate (IIR_Aggregate)
  ((IIR_ElementAssociationList element_association_list)))

(defnode IIR_ArtificialRecordAggregate (IIR_RecordAggregate)
  ())

(defnode IIR_ArrayAggregate (IIR_Aggregate)
  ((IIR_IndexedAssociationList indexed_association_list)))

(defnode IIR_ArtificialArrayAggregate (IIR_ArrayAggregate)
  ())

(defnode IIR_FunctionCall (IIR_Expression)
  ((IIR_FunctionDeclaration function)
   (IIR_AssociationList parameter_association_list)))

(defnode IIR_QualifiedExpression (IIR_Expression)
  ((IIR_Type type_mark)
   (IIR_Expression expression)))

(defnode IIR_TypeConversion (IIR_Expression)
  ((IIR_Type type_mark)
   (IIR_Expression expression)))

(defnode IIR_Allocator (IIR_Expression)
  ((IIR_Type type_mark)
   (IIR_Expression value)))

(defnode IIR_OpenExpression (IIR_Expression)
  ())

(defnode IIR_ObjectReference (IIR_Expression)
  ())

(defnode IIR_SimpleReference (IIR_ObjectReference)
  ((IIR_ObjectDeclaration object)))

(defnode IIR_AccessReference (IIR_ObjectReference)
  ((IIR_Expression access)))

(defnode IIR_RecordReference (IIR_ObjectReference)
  ((IIR_Expression record)
   (IIR_ElementDeclaration element)))

(defnode IIR_GenericArrayReference (IIR_ObjectReference)
  ((IIR_Expression array)))

(defnode IIR_ArrayReference (IIR_GenericArrayReference)
  ((IIR_ExpressionList indices)))

(defnode IIR_SliceReference (IIR_GenericArrayReference)
  ((IIR_Range range)))

;;; Chapter 13A -- Attributes

;; Some of the kinds of predefined attribute have an associated node
;; kind, some have not:
;;
;; value:        IIR_ValueAttr     (IIR_Expression)
;; type:         resolved to IIR_Type node
;; range:        IIR_ArrayRange
;; function:     IIR_FunctionAttr  (IIR_Expression)
;; signal:       IIR_SignalAttr    (IIR_ObjectReference)

(defnode IIR_SignalAttr (IIR_ObjectReference)
  ((IIR_ObjectReference signal)))

(defnode IIR_Attr_DELAYED (IIR_SignalAttr)
  ((IIR_Expression delay)))

(defnode IIR_Attr_STABLE (IIR_SignalAttr)
  ((IIR_Expression duration)))

(defnode IIR_Attr_QUIET (IIR_SignalAttr)
  ((IIR_Expression duration)))

(defnode IIR_Attr_TRANSACTION (IIR_SignalAttr)
  ())

(defnode IIR_FunctionAttr (IIR_Expression)
  ())

(defnode IIR_AttrSigFunc (IIR_FunctionAttr)
  ((IIR_ObjectReference signal)))

(defnode IIR_Attr_EVENT (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_ACTIVE (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_LAST_EVENT (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_LAST_ACTIVE (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_LAST_VALUE (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_DRIVING (IIR_AttrSigFunc)
  ())

(defnode IIR_Attr_DRIVING_VALUE (IIR_AttrSigFunc)
  ())

(defnode IIR_ValueAttr (IIR_Expression)
  ())

(defnode IIR_AttrTypeValue (IIR_ValueAttr)
  ((IIR_Type prefix)
   (IIR_Expression argument)))

(defnode IIR_Attr_LEFT (IIR_AttrTypeValue)
  ())

(defnode IIR_Attr_RIGHT (IIR_AttrTypeValue)
  ())

(defnode IIR_Attr_LOW (IIR_AttrTypeValue)
  ())

(defnode IIR_Attr_HIGH (IIR_AttrTypeValue)
  ())

(defnode IIR_Attr_ASCENDING (IIR_AttrTypeValue)
  ())

;; XXX - remove this?
(defnode IIR_Attr_LENGTH (IIR_AttrTypeValue)
  ())

(defnode IIR_AttrTypeFunc (IIR_FunctionAttr)
  ((IIR_Type prefix)
   (IIR_Expression argument)))

(defnode IIR_Attr_IMAGE (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_VALUE (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_POS (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_VAL (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_SUCC (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_PRED (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_LEFTOF (IIR_AttrTypeFunc)
  ())

(defnode IIR_Attr_RIGHTOF (IIR_AttrTypeFunc)
  ())

(defnode IIR_AttrArrayFunc (IIR_FunctionAttr)
  ((IIR_Expression array)
   (IIR_Type array_type)
   (int index)))

(defnode IIR_Attr_ArrayLEFT (IIR_AttrArrayFunc)
  ())

(defnode IIR_Attr_ArrayRIGHT (IIR_AttrArrayFunc)
  ())

(defnode IIR_Attr_ArrayHIGH (IIR_AttrArrayFunc)
  ())

(defnode IIR_Attr_ArrayLOW (IIR_AttrArrayFunc)
  ())

(defnode IIR_Attr_ArrayASCENDING (IIR_AttrArrayFunc)
  ())

(defnode IIR_Attr_ArrayLENGTH (IIR_AttrArrayFunc)
  ())

;;; Chapter 14 -- Sequential Statements

(defnode IIR_SequentialStatement (IIR_Root)
  ((IIR_Label label)))

(defnode IIR_WaitStatement (IIR_SequentialStatement)
  ((IIR_Expression condition_clause)
   (IIR_Expression timeout_clause)
   (IIR_ExpressionList sensitivity_list)))

(defnode IIR_AssertionStatement (IIR_SequentialStatement)
  ((IIR_Expression assertion_condition)
   (IIR_Expression report_expression)
   (IIR_Expression severity_expression)))

(defnode IIR_ReportStatement (IIR_SequentialStatement)
  ((IIR_Expression report_expression)
   (IIR_Expression severity_expression)))

(defnode IIR_SignalAssignmentStatement (IIR_SequentialStatement)
  ((IIR_Expression target)
   (IR_DelayMechanism delay_mechanism)
   (IIR_Expression reject_time_expression)
   (IIR_WaveformList waveform)))

(defnode IIR_VariableAssignmentStatement (IIR_SequentialStatement)
  ((IIR_Expression target)
   (IIR_Expression expression)))

(defnode IIR_ProcedureCallStatement (IIR_SequentialStatement)
  ((IIR_ProcedureDeclaration procedure)
   (IIR_AssociationList actual_parameter_part)))

(defnode IIR_IfStatement (IIR_SequentialStatement)
  ((IIR_Expression condition)
   (IIR_SequentialStatementList then_sequence)
   (IIR_SequentialStatementList else_sequence)))

(defnode IIR_CaseStatement (IIR_SequentialStatement)
  ((IIR_Expression expression)
   (IIR_CaseStatementAlternativeList case_statement_alternatives)))

(defnode IIR_LoopStatement (IIR_SequentialStatement)
  ((IIR_SequentialStatementList sequence_of_statements)
   (IIR_LoopDeclarativeRegion declarative_region)))

(defnode IIR_ForLoopStatement (IIR_LoopStatement)
  ((IIR_ConstantDeclaration iterator)))

(defnode IIR_WhileLoopStatement (IIR_LoopStatement)
  ((IIR_Expression condition)))

(defnode IIR_LoopControlStatement (IIR_SequentialStatement)
  ((IIR_LoopStatement loop)
   (IIR_Expression condition)))

(defnode IIR_NextStatement (IIR_LoopControlStatement)
  ())

(defnode IIR_ExitStatement (IIR_LoopControlStatement)
  ())

(defnode IIR_ReturnStatement (IIR_SequentialStatement)
  ((IIR_SubprogramDeclaration enclosing_subprogram)
   (IIR_Expression return_expression)))

(defnode IIR_NullStatement (IIR_SequentialStatement)
  ())
   
;;; Chapter 15 -- Concurrent Statements

(defnode IIR_ConcurrentStatement (IIR_DeclarativeRegion)
  ())

(defnode IIR_BlockStatement (IIR_ConcurrentStatement)
  ((IIR_Expression guard_expression)
   (IIR_InterfaceList generic_clause)
   (IIR_AssociationList generic_map_aspect)
   (IIR_InterfaceList port_clause)
   (IIR_AssociationList port_map_aspect)
   (IIR_ConfigurationSpecificationList configuration_specifications)
   (IIR_ConcurrentStatementList block_statement_part)))

(defnode IIR_ProcessStatement (IIR_ConcurrentStatement)
  ((bool postponed)
   (bool guarded)
   (IIR_SequentialStatementList process_statement_part)))

(defnode IIR_ImplicitProcessStatement (IIR_ProcessStatement)
  ())

(defnode IIR_SensitizedProcessStatement (IIR_ProcessStatement)
  ((IIR_ExpressionList sensitivity_list)))

(defnode IIR_ComponentInstantiationStatement (IIR_ConcurrentStatement)
  ((IIR_BindingIndication binding)
   (IIR_BindingIndication configuration)))

(defnode IIR_ConcurrentGenerateStatement (IIR_ConcurrentStatement)
  ((IIR_ConfigurationSpecificationList configuration_specifications)
   (IIR_ConcurrentStatementList concurrent_statement_part)))

(defnode IIR_ConcurrentGenerateForStatement (IIR_ConcurrentGenerateStatement)
  ((IIR_ConstantDeclaration generate_parameter_specification)))

(defnode IIR_ConcurrentGenerateIfStatement (IIR_ConcurrentGenerateStatement)
  ((IIR_Expression condition)))

