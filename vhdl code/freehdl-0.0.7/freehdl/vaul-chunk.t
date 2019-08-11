;; -*- scheme -*-

(include "freehdl/fire-chunk.t")

(define (format-vaul-kind name)
  (upcase (concat-strings (syllables name) "_")))

(chunk vaul
  (struct-fmt "~a")
  (pointer-fmt "p~a")
  (kind-fmt-func format-vaul-kind)
  (creator-fmt "m~a"))

(header-add "#include <freehdl/fire.h>"
	    "#include <freehdl/vaul-types.h>"
	    "#include <freehdl/vaul-creator-base.h>"
	    "struct vaul_decl_set;")

(impl-add "#include <freehdl/vaul-chunk.h>")

(defctype vaul_id_set)
(defctype vaul_decl_set_ptr (cname "vaul_decl_set*"))
(defctype vaul_incomplete_type_use_ptr (cname "vaul_incomplete_type_use*"))

;; Extensions of FIRE nodes.

(defextension IIR_DeclarativeRegion
  ((vaul_id_set decls_in_flight)
   (IIR_DeclarationList tail (= "NULL"))))

(defextension IIR_SimpleReference
  ((VAUL_Name simple_reference_name (= "NULL"))))

(defextension IIR_ChoiceByRange
  ((bool actual_is_slice (= "false"))))

(defextension IIR_BlockStatement
  ((VAUL_ConfigSpec config_specs (= "NULL"))))

;; Additional nodes that VAUL needs for analyzing the source files.
;; They will not appear in the generated graph but VAUL needs them
;; internally.

(defnode VAUL_DelayMechanism (IIR_Root)
  ())

(defnode VAUL_DelayInertial (VAUL_DelayMechanism)
  ((IIR_Expression rejection_time)))

(defnode VAUL_DelayTransport (VAUL_DelayMechanism)
  ())

(defnode VAUL_CondalWaveform (IIR_Root)
  ((IIR_WaveformList wave)
   (IIR_Expression condition)
   (VAUL_CondalWaveform else_wave))
  (reverse else_wave))

(defnode VAUL_CondalSignalAssign (IIR_Root)
  ((IIR_Expression target)
   (bool guarded)
   (VAUL_DelayMechanism delay)
   (VAUL_CondalWaveform wave)))

(defnode VAUL_SelWaveform (IIR_Root)
  ((IIR_WaveformList wave)
   (IIR_ChoiceList choice)
   (VAUL_SelWaveform next_wave))
  (reverse next_wave))

(defnode VAUL_SelSignalAssign (IIR_Root)
  ((IIR_Expression value)
   (IIR_Expression target)
   (bool guarded)
   (VAUL_DelayMechanism delay)
   (VAUL_SelWaveform wave)))

(defnode VAUL_DesigList (IIR_Root)
  ((IIR_TextLiteral desig)
   (VAUL_DesigList link))
  (reverse link))

;;; Names

(defnode VAUL_Name (IIR_Root)
  ())

(defnode VAUL_SimpleName (VAUL_Name)
  ((IIR_TextLiteral id)))

(defnode VAUL_SelName (VAUL_Name)
  ((VAUL_Name prefix)
   (IIR_TextLiteral suffix)))

(defnode VAUL_IftsName (VAUL_Name)
  ((VAUL_Name prefix)
   (VAUL_GenAssocElem assoc)))

(defnode VAUL_AttributeName (VAUL_Name)
  ((VAUL_Name prefix)
   (IIR_Identifier attribute)
   (VAUL_NamedAssocElem first_actual)))

(defnode VAUL_SelNameList (IIR_Root)
  ((VAUL_SelName name)
   (VAUL_SelNameList link))
  (reverse link))

(defnode VAUL_NameList (IIR_Root)
  ((VAUL_Name name)
   (VAUL_NameList link))
  (reverse link))

(defnode VAUL_TopScope (IIR_DeclarativeRegion)
  ())

(defnode VAUL_StandardPackage (IIR_PackageDeclaration)
  ((IIR_Type predef_BIT)
   (IIR_Type predef_BOOLEAN)
   (IIR_Type predef_INTEGER)
   (IIR_Type predef_REAL)
   (IIR_Type predef_TIME)
   (IIR_Type predef_CHARACTER)
   (IIR_Type predef_STRING)
   (IIR_Type predef_BIT_VECTOR)
   (IIR_Type predef_SEVERITY_LEVEL)
   (IIR_Type predef_FILE_OPEN_KIND)
   (IIR_Type predef_FILE_OPEN_STATUS)
   (IIR_Type universal_integer)
   (IIR_Type universal_real)))

(defnode VAUL_IncompleteType (IIR_Type)
  ((vaul_incomplete_type_use_ptr uses)))

;; this is used during overload resolution as the return type of
;; procedures
(defnode VAUL_VoidType (IIR_Type)
  ())

;; this is used for aggregates
(defnode VAUL_SubarrayType (IIR_ArrayType)
  ((IIR_ArrayType complete_type)))

(defnode VAUL_PreIndexConstraint (IIR_Type)
  ())

(defnode VAUL_PreIndexRangeConstraint (VAUL_PreIndexConstraint)
  ((IIR_Range range)))

(defnode VAUL_PreIndexSubtypeConstraint (VAUL_PreIndexConstraint)
  ((IIR_Type type)))

(defnode VAUL_GuardSignal (IIR_SignalDeclaration)
  ())

;;; Expressions

(defnode VAUL_UnresolvedName (IIR_Expression)
  ((VAUL_Name name)))

(defnode VAUL_ProcedureCall (IIR_Expression)
  ((IIR_ProcedureDeclaration proc)
   (IIR_AssociationList actuals)))

(defnode VAUL_AmbgCall (IIR_Expression)
  ((VAUL_NamedAssocElem first_actual)
   (vaul_decl_set_ptr set)))

(defnode VAUL_GenAssocElem (IIR_Root)
  ((VAUL_GenAssocElem next))
  (reverse next))

(defnode VAUL_NamedAssocElem (VAUL_GenAssocElem)
  ((VAUL_Name formal)
   (IIR_Expression actual)
   (vaul_decl_set_ptr ifts_decls)
   (IR_Kind ifts_kind)
   (VAUL_SimpleName ifts_arg_name)))

(defnode VAUL_SubtypeAssocElem (VAUL_GenAssocElem)
  ((IIR_Type type)))

(defnode VAUL_RangeAssocElem (VAUL_GenAssocElem)
  ((IIR_Range range)))

(defnode VAUL_AmbgArrayLitRef (IIR_Expression)
  ((IIR_StringLiteral value)))

(defnode VAUL_AmbgNullExpr (IIR_Expression)
  ())

(defnode VAUL_AmbgEnumLitRef (IIR_Expression)
  ((vaul_decl_set_ptr set)))

(defnode VAUL_AttributeSpec (IIR_Root)
  ((IIR_Identifier attr_desig)
   (VAUL_EntitySpec entities)
   (IIR_Expression value)))

(defnode VAUL_EntitySpec (IIR_Root)
  ((VAUL_EntityNameList names)
   (IR_Kind entity_class)))

(defnode VAUL_EntityNameList (IIR_Root)
  ())

(defnode VAUL_EntityNameList_Ids (VAUL_EntityNameList)
  ((VAUL_DesigList ids)))

(defnode VAUL_EntityNameList_ALL (VAUL_EntityNameList)
  ())

(defnode VAUL_EntityNameList_OTHERS (VAUL_EntityNameList)
  ())

(defnode VAUL_AmbgAggregate (IIR_Expression)
  ((VAUL_ElemAssoc first_assoc)))

(defnode VAUL_ArtificialAmbgAggregate (VAUL_AmbgAggregate)
  ())

(defnode VAUL_ElemAssoc (IIR_Root)
  ((VAUL_ElemAssoc next)
   (IIR_ChoiceList choices)
   (IIR_Expression actual))
  (reverse next))

(defnode VAUL_ChoiceByName (IIR_Choice)
  ((VAUL_Name name)))

(defnode VAUL_IterationScheme (IIR_Root)
  ())

(defnode VAUL_IfScheme (VAUL_IterationScheme)
  ((IIR_Expression condition)))

(defnode VAUL_WhileScheme (VAUL_IterationScheme)
  ((IIR_Expression condition)))

(defnode VAUL_ForScheme (VAUL_IterationScheme)
  ((IIR_Identifier var)
   (IIR_Type range)))

;; Concurrent Statements

(defnode VAUL_ConfigSpec (IIR_Root)
  ((VAUL_ComponentSpec comps)
   (IIR_BindingIndication binding)
   (VAUL_ConfigSpec next))
  (reverse next))

(defextension IIR_ConfigurationSpecification
  ((bool bound_by_name)))

(defextension IIR_ComponentConfiguration
  ((bool bound_by_name)))

(defnode VAUL_ComponentSpec (IIR_Root)
  ((VAUL_InstList ids)
   (IIR_ComponentDeclaration comp)))

(defnode VAUL_InstList (IIR_Root)
  ())

(defnode VAUL_InstList_Ids (VAUL_InstList)
  ((IIR_IdentifierList ids)))

(defnode VAUL_InstList_ALL (VAUL_InstList)
  ())

(defnode VAUL_InstList_OTHERS (VAUL_InstList)
  ())

(defnode VAUL_IncrementalBindingIndic (IIR_Root)
  ((IIR_DeclarativeRegion unit)
   (VAUL_NamedAssocElem generic_assoc)
   (VAUL_NamedAssocElem port_assoc)))

(defnode VAUL_DeclCache ()
  ((VAUL_DeclCache next)
   (vaul_decl_set_ptr set)
   (IIR_TextLiteral id)
   (IIR_Declaration scope)
   (bool by_sel)))

(defnode VAUL_FilenameAndMode ()
  ((IIR_Expression name)
   (IR_Mode mode)))

(defcreator vaul_node_creator
  (base vaul_node_creator_base)
  (chunks fire vaul)
  (placement "&hist")
  (inits
   (IIR_Root)
   (IIR_Root (pos (wrap ((int lineno)) "make_posinfo(lineno)")))

   (IIR_TextLiteral)
   (IIR_TextLiteral (text (wrap ((IR_Character *str) (int len))
				"IR_String(str, len)")))
   (IIR_IntegerLiteral)
   (IIR_IntegerLiteral
    (text (wrap ((IR_Character *str) (int len))
		"IR_String(str, len)")))
   (IIR_FloatingPointLiteral)
   (IIR_FloatingPointLiteral
    (text (wrap ((IR_Character *str) (int len))
		"IR_String(str, len)")))

   (IIR_Declaration (declarative_region NULL) (attributes NULL) (seqno "-1"))
   (IIR_DeclarativeRegion (continued NULL) (declarations NULL))
   (IIR_LibraryUnit (context_items NULL)
		    (external_decls NULL)
		    (library_name NULL)
		    (used_units NULL))
   (IIR_Type ((type_definition NULL)
	      (declaration NULL)
	      (base NULL)
	      (static_level IR_NOT_STATIC))
	     (construct-extra "vaul_fix_static_level"))
   (IIR_Subtype (base #f))
   (VAUL_StandardPackage (predef_BIT NULL) (predef_BOOLEAN NULL)
			 (predef_INTEGER NULL) (predef_REAL NULL)
			 (predef_TIME NULL) (predef_CHARACTER NULL)
			 (predef_STRING NULL) (predef_BIT_VECTOR NULL)
			 (predef_SEVERITY_LEVEL NULL)
			 (predef_FILE_OPEN_KIND NULL)
			 (predef_FILE_OPEN_STATUS NULL)
			 (universal_integer NULL) (universal_real NULL))
   (IIR_ObjectDeclaration (alias_base NULL))
   (IIR_SubprogramDeclaration (subprogram_body NULL) (prototype NULL))
   (IIR_EntityDeclaration (generic_clause NULL) (port_clause NULL)
			  (entity_statement_part NULL))
   (IIR_ArchitectureDeclaration (configuration_specifications NULL)
				(architecture_statement_part NULL))
   (IIR_ConfigurationDeclaration (block_configuration NULL))
   (IIR_ComponentDeclaration (local_generic_clause NULL)
			     (local_port_clause NULL))
   (IIR_SequentialStatement (label NULL))
   (IIR_ProcessStatement (guarded false))
   (VAUL_CondalWaveform (else_wave NULL))
   (IIR_BlockStatement (generic_clause NULL) (generic_map_aspect NULL)
		       (port_clause NULL) (port_map_aspect NULL)
		       (block_statement_part NULL))
   (IIR_ConcurrentGenerateStatement (configuration_specifications NULL))
   (VAUL_ConfigSpec (next NULL))
   (IIR_ConfigurationDeclaration (block_config NULL))
   (VAUL_AmbgCall (set NULL))
   (VAUL_AmbgEnumLitRef (set NULL))
   (VAUL_IncompleteType (uses NULL))
   (VAUL_NamedAssocElem (ifts_decls NULL) (ifts_kind NULL)
			(ifts_arg_name NULL))
   (VAUL_DeclCache (next NULL))
   (IIR_Expression (static_level IR_NOT_STATIC))))

(defunion VAUL_Tree
  (chunks fire vaul))
