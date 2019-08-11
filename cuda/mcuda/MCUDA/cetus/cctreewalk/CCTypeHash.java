
package cetus.cctreewalk;

/*
This hashtable gives a mapping from name (String) to its type code.
*/

import java.lang.*;
import java.util.*;

public class CCTypeHash implements CCTypeEnum
{
    Hashtable   name2enum;

    public int getEnumValue(String _name)
    {
        Integer value = (Integer)name2enum.get(_name);
        if (value == null)
        {
            if (isStringLiteral(_name) == true)
            {
                return __STRING_LITERAL__;
            }
            else if (isConstant(_name) == true)
            {
                return __CONSTANT__;
            }
            else if (isIdentifier(_name) == true)
            {
                return __IDENTIFIER__;
            }
            else
            {
                return -1;
            }
        }
        return value.intValue();
    }

    public CCTypeHash()
    {
        name2enum = new Hashtable();

        name2enum.put(new String("ambiguity"), new Integer(__ambiguity__));

        name2enum.put(new String("STRING_LITERAL_seq"), new Integer(__STRING_LITERAL_seq__));
        name2enum.put(new String("abstract_declarator"), new Integer(__abstract_declarator__));
        name2enum.put(new String("access_specifier"), new Integer(__access_specifier__));
        name2enum.put(new String("additive_expression"), new Integer(__additive_expression__));
        name2enum.put(new String("and_expression"), new Integer(__and_expression__));
        name2enum.put(new String("any_word"), new Integer(__any_word__));
        name2enum.put(new String("asm_clobbers"), new Integer(__asm_clobbers__));
        name2enum.put(new String("asm_definition"), new Integer(__asm_definition__));
        name2enum.put(new String("asm_operand"), new Integer(__asm_operand__));
        name2enum.put(new String("asm_operands"), new Integer(__asm_operands__));
        name2enum.put(new String("assignment_expression"), new Integer(__assignment_expression__));
        name2enum.put(new String("assignment_operator"), new Integer(__assignment_operator__));
        name2enum.put(new String("attrib"), new Integer(__attrib__));
        name2enum.put(new String("attribute"), new Integer(__attribute__));
        name2enum.put(new String("attribute_list"), new Integer(__attribute_list__));
        name2enum.put(new String("attributes"), new Integer(__attributes__));
        name2enum.put(new String("base_clause"), new Integer(__base_clause__));
        name2enum.put(new String("base_specifier"), new Integer(__base_specifier__));
        name2enum.put(new String("base_specifier_list"), new Integer(__base_specifier_list__));
        name2enum.put(new String("block_declaration"), new Integer(__block_declaration__));
        name2enum.put(new String("boolean_literal"), new Integer(__boolean_literal__));
        name2enum.put(new String("cast_expression"), new Integer(__cast_expression__));
        name2enum.put(new String("class_name"), new Integer(__class_name__));
        name2enum.put(new String("compound_statement"), new Integer(__compound_statement__));
        name2enum.put(new String("condition"), new Integer(__condition__));
        name2enum.put(new String("conditional_expression"), new Integer(__conditional_expression__));
        name2enum.put(new String("constant_expression"), new Integer(__constant_expression__));
        name2enum.put(new String("constant_initializer"), new Integer(__constant_initializer__));
        name2enum.put(new String("conversion_declarator"), new Integer(__conversion_declarator__));
        name2enum.put(new String("conversion_function_id"), new Integer(__conversion_function_id__));
        name2enum.put(new String("conversion_type_id"), new Integer(__conversion_type_id__));
        name2enum.put(new String("ctor_initializer"), new Integer(__ctor_initializer__));
        name2enum.put(new String("cv_qualifier"), new Integer(__cv_qualifier__));
        name2enum.put(new String("cv_qualifier_seq"), new Integer(__cv_qualifier_seq__));
        name2enum.put(new String("decl_specifier"), new Integer(__decl_specifier__));
        name2enum.put(new String("decl_specifier_seq"), new Integer(__decl_specifier_seq__));
        name2enum.put(new String("declaration"), new Integer(__declaration__));
        name2enum.put(new String("declaration_seq"), new Integer(__declaration_seq__));
        name2enum.put(new String("declarator"), new Integer(__declarator__));
        name2enum.put(new String("declarator_head"), new Integer(__declarator_head__));
        name2enum.put(new String("declarator_id"), new Integer(__declarator_id__));
        name2enum.put(new String("declarator_tail"), new Integer(__declarator_tail__));
        name2enum.put(new String("declarator_tail_seq"), new Integer(__declarator_tail_seq__));
        name2enum.put(new String("delete_expression"), new Integer(__delete_expression__));
        name2enum.put(new String("direct_abstract_declarator"), new Integer(__direct_abstract_declarator__));
        name2enum.put(new String("direct_declarator"), new Integer(__direct_declarator__));
        name2enum.put(new String("direct_new_declarator"), new Integer(__direct_new_declarator__));
        name2enum.put(new String("enumerator_definition"), new Integer(__enumerator_definition__));
        name2enum.put(new String("enumerator_list"), new Integer(__enumerator_list__));
        name2enum.put(new String("equality_expression"), new Integer(__equality_expression__));
        name2enum.put(new String("exception_declaration"), new Integer(__exception_declaration__));
        name2enum.put(new String("exception_specification"), new Integer(__exception_specification__));
        name2enum.put(new String("exclusive_or_expression"), new Integer(__exclusive_or_expression__));
        name2enum.put(new String("explicit_instantiation"), new Integer(__explicit_instantiation__));
        name2enum.put(new String("explicit_specialization"), new Integer(__explicit_specialization__));
        name2enum.put(new String("expression"), new Integer(__expression__));
        name2enum.put(new String("expression_list"), new Integer(__expression_list__));
        name2enum.put(new String("expression_statement"), new Integer(__expression_statement__));
        name2enum.put(new String("for_init_statement"), new Integer(__for_init_statement__));
        name2enum.put(new String("function_definition"), new Integer(__function_definition__));
        name2enum.put(new String("function_prefix"), new Integer(__function_prefix__));
        name2enum.put(new String("function_specifier"), new Integer(__function_specifier__));
        name2enum.put(new String("function_try_block"), new Integer(__function_try_block__));
        name2enum.put(new String("handler"), new Integer(__handler__));
        name2enum.put(new String("handler_seq"), new Integer(__handler_seq__));
        name2enum.put(new String("id_expression"), new Integer(__id_expression__));
        name2enum.put(new String("inclusive_or_expression"), new Integer(__inclusive_or_expression__));
        name2enum.put(new String("init_declarator"), new Integer(__init_declarator__));
        name2enum.put(new String("init_declarator_list"), new Integer(__init_declarator_list__));
        name2enum.put(new String("initializer"), new Integer(__initializer__));
        name2enum.put(new String("initializer_clause"), new Integer(__initializer_clause__));
        name2enum.put(new String("initializer_list"), new Integer(__initializer_list__));
        name2enum.put(new String("iteration_statement"), new Integer(__iteration_statement__));
        name2enum.put(new String("jump_statement"), new Integer(__jump_statement__));
        name2enum.put(new String("labeled_statement"), new Integer(__labeled_statement__));
        name2enum.put(new String("linkage_specification"), new Integer(__linkage_specification__));
        name2enum.put(new String("literal"), new Integer(__literal__));
        name2enum.put(new String("logical_and_expression"), new Integer(__logical_and_expression__));
        name2enum.put(new String("logical_or_expression"), new Integer(__logical_or_expression__));
        name2enum.put(new String("mem_initializer"), new Integer(__mem_initializer__));
        name2enum.put(new String("mem_initializer_id"), new Integer(__mem_initializer_id__));
        name2enum.put(new String("mem_initializer_list"), new Integer(__mem_initializer_list__));
        name2enum.put(new String("member_declaration"), new Integer(__member_declaration__));
        name2enum.put(new String("member_declaration_alt"), new Integer(__member_declaration_alt__));
        name2enum.put(new String("member_declarator"), new Integer(__member_declarator__));
        name2enum.put(new String("member_declarator_list"), new Integer(__member_declarator_list__));
        name2enum.put(new String("member_declarator_list_tail"), new Integer(__member_declarator_list_tail__));
        name2enum.put(new String("member_specification"), new Integer(__member_specification__));
        name2enum.put(new String("multiplicative_expression"), new Integer(__multiplicative_expression__));
        name2enum.put(new String("namespace_alias_definition"), new Integer(__namespace_alias_definition__));
        name2enum.put(new String("namespace_definition"), new Integer(__namespace_definition__));
        name2enum.put(new String("nested_name_specifier"), new Integer(__nested_name_specifier__));
        name2enum.put(new String("new_declarator"), new Integer(__new_declarator__));
        name2enum.put(new String("new_expression"), new Integer(__new_expression__));
        name2enum.put(new String("new_initializer"), new Integer(__new_initializer__));
        name2enum.put(new String("new_placement"), new Integer(__new_placement__));
        name2enum.put(new String("new_type_id"), new Integer(__new_type_id__));
        name2enum.put(new String("operator_"), new Integer(__operator___));
        name2enum.put(new String("operator_function_id"), new Integer(__operator_function_id__));
        name2enum.put(new String("parameter_declaration"), new Integer(__parameter_declaration__));
        name2enum.put(new String("parameter_declaration_clause"), new Integer(__parameter_declaration_clause__));
        name2enum.put(new String("parameter_declaration_list"), new Integer(__parameter_declaration_list__));
        name2enum.put(new String("pm_expression"), new Integer(__pm_expression__));
        name2enum.put(new String("postfix_expression"), new Integer(__postfix_expression__));
        name2enum.put(new String("primary_expression"), new Integer(__primary_expression__));
        name2enum.put(new String("ptr_operator"), new Integer(__ptr_operator__));
        name2enum.put(new String("qualified_id"), new Integer(__qualified_id__));
        name2enum.put(new String("qualified_namespace_specifier"), new Integer(__qualified_namespace_specifier__));
        name2enum.put(new String("relational_expression"), new Integer(__relational_expression__));
        name2enum.put(new String("scoped_class_name"), new Integer(__scoped_class_name__));
        name2enum.put(new String("scoped_id"), new Integer(__scoped_id__));
        name2enum.put(new String("scoped_unqualified_id"), new Integer(__scoped_unqualified_id__));
        name2enum.put(new String("selection_statement"), new Integer(__selection_statement__));
        name2enum.put(new String("shift_expression"), new Integer(__shift_expression__));
        name2enum.put(new String("simple_declaration"), new Integer(__simple_declaration__));
        name2enum.put(new String("simple_type_specifier"), new Integer(__simple_type_specifier__));
        name2enum.put(new String("statement"), new Integer(__statement__));
        name2enum.put(new String("statement_seq"), new Integer(__statement_seq__));
        name2enum.put(new String("storage_class_specifier"), new Integer(__storage_class_specifier__));
        name2enum.put(new String("template_argument"), new Integer(__template_argument__));
        name2enum.put(new String("template_argument_list"), new Integer(__template_argument_list__));
        name2enum.put(new String("template_declaration"), new Integer(__template_declaration__));
        name2enum.put(new String("template_parameter"), new Integer(__template_parameter__));
        name2enum.put(new String("template_parameter_list"), new Integer(__template_parameter_list__));
        name2enum.put(new String("throw_expression"), new Integer(__throw_expression__));
        name2enum.put(new String("translation_unit"), new Integer(__translation_unit__));
        name2enum.put(new String("try_block"), new Integer(__try_block__));
        name2enum.put(new String("type_id"), new Integer(__type_id__));
        name2enum.put(new String("type_id_list"), new Integer(__type_id_list__));
        name2enum.put(new String("type_parameter"), new Integer(__type_parameter__));
        name2enum.put(new String("type_specifier"), new Integer(__type_specifier__));
        name2enum.put(new String("type_specifier_seq"), new Integer(__type_specifier_seq__));
        name2enum.put(new String("unary_expression"), new Integer(__unary_expression__));
        name2enum.put(new String("unary_operator"), new Integer(__unary_operator__));
        name2enum.put(new String("unqualified_id"), new Integer(__unqualified_id__));
        name2enum.put(new String("using_declaration"), new Integer(__using_declaration__));
        name2enum.put(new String("using_directive"), new Integer(__using_directive__));

        name2enum.put(new String("sizeof"), new Integer(__SIZEOF__));
        name2enum.put(new String("->"), new Integer(__PTR_OP__));
        name2enum.put(new String("++"), new Integer(__INC_OP__));
        name2enum.put(new String("--"), new Integer(__DEC_OP__));
        name2enum.put(new String("<<"), new Integer(__LEFT_OP__));
        name2enum.put(new String(">>"), new Integer(__RIGHT_OP__));
        name2enum.put(new String("<="), new Integer(__LE_OP__));
        name2enum.put(new String(">="), new Integer(__GE_OP__));
        name2enum.put(new String("=="), new Integer(__EQ_OP__));
        name2enum.put(new String("!="), new Integer(__NE_OP__));
        name2enum.put(new String("not_eq"), new Integer(__NE_OP__));
        name2enum.put(new String("&&"), new Integer(__AND_OP__));
        name2enum.put(new String("and"), new Integer(__AND_OP__));
        name2enum.put(new String("||"), new Integer(__OR_OP__));
        name2enum.put(new String("or"), new Integer(__OR_OP__));
        name2enum.put(new String("*="), new Integer(__MUL_ASSIGN__));
        name2enum.put(new String("/="), new Integer(__DIV_ASSIGN__));
        name2enum.put(new String("%="), new Integer(__MOD_ASSIGN__));
        name2enum.put(new String("+="), new Integer(__ADD_ASSIGN__));
        name2enum.put(new String("-="), new Integer(__SUB_ASSIGN__));
        name2enum.put(new String("<<="), new Integer(__LEFT_ASSIGN__));
        name2enum.put(new String(">>="), new Integer(__RIGHT_ASSIGN__));
        name2enum.put(new String("&="), new Integer(__AND_ASSIGN__));
        name2enum.put(new String("and_eq"), new Integer(__AND_ASSIGN__));
        name2enum.put(new String("^="), new Integer(__XOR_ASSIGN__));
        name2enum.put(new String("xor_eq"), new Integer(__XOR_ASSIGN__));
        name2enum.put(new String("|="), new Integer(__OR_ASSIGN__));
        name2enum.put(new String("or_eq"), new Integer(__OR_ASSIGN__));
        name2enum.put(new String("typedef"), new Integer(__TYPEDEF__));
        name2enum.put(new String("extern"), new Integer(__EXTERN__));
        name2enum.put(new String("static"), new Integer(__STATIC__));
        name2enum.put(new String("auto"), new Integer(__AUTO__));
        name2enum.put(new String("register"), new Integer(__REGISTER__));
        name2enum.put(new String("char"), new Integer(__CHAR__));
        name2enum.put(new String("short"), new Integer(__SHORT__));
        name2enum.put(new String("int"), new Integer(__INT__));
        name2enum.put(new String("long"), new Integer(__LONG__));
        name2enum.put(new String("signed"), new Integer(__SIGNED__));
        name2enum.put(new String("__signed"), new Integer(__SIGNED__));
        name2enum.put(new String("__signed__"), new Integer(__SIGNED__));
        name2enum.put(new String("unsigned"), new Integer(__UNSIGNED__));
        name2enum.put(new String("float"), new Integer(__FLOAT__));
        name2enum.put(new String("double"), new Integer(__DOUBLE__));
        name2enum.put(new String("const"), new Integer(__CONST__));
        name2enum.put(new String("__const__"), new Integer(__CONST__));
        name2enum.put(new String("__const"), new Integer(__CONST__));
        name2enum.put(new String("volatile"), new Integer(__VOLATILE__));
        name2enum.put(new String("__volatile"), new Integer(__VOLATILE__));
        name2enum.put(new String("__volatile__"), new Integer(__VOLATILE__));
        name2enum.put(new String("void"), new Integer(__VOID__));
        name2enum.put(new String("struct"), new Integer(__STRUCT__));
        name2enum.put(new String("union"), new Integer(__UNION__));
        name2enum.put(new String("enum"), new Integer(__ENUM__));
        name2enum.put(new String("..."), new Integer(__ELLIPSIS__));
        name2enum.put(new String("case"), new Integer(__CASE__));
        name2enum.put(new String("default"), new Integer(__DEFAULT__));
        name2enum.put(new String("if"), new Integer(__IF__));
        name2enum.put(new String("else"), new Integer(__ELSE__));
        name2enum.put(new String("switch"), new Integer(__SWITCH__));
        name2enum.put(new String("while"), new Integer(__WHILE__));
        name2enum.put(new String("do"), new Integer(__DO__));
        name2enum.put(new String("for"), new Integer(__FOR__));
        name2enum.put(new String("goto"), new Integer(__GOTO__));
        name2enum.put(new String("continue"), new Integer(__CONTINUE__));
        name2enum.put(new String("break"), new Integer(__BREAK__));
        name2enum.put(new String("return"), new Integer(__RETURN__));
        name2enum.put(new String("__asm"), new Integer(__ASM__));
        name2enum.put(new String("__asm__"), new Integer(__ASM__));
        name2enum.put(new String("bool"), new Integer(__CBOOL__));
        name2enum.put(new String("catch"), new Integer(__CATCH__));
        name2enum.put(new String("class"), new Integer(__CLASS__));
        name2enum.put(new String("const_cast"), new Integer(__CONST_CAST__));
        name2enum.put(new String("delete"), new Integer(__DELETE__));
        name2enum.put(new String("dynamic_cast"), new Integer(__DYNAMIC_CAST__));
        name2enum.put(new String("explicit"), new Integer(__EXPLICIT__));
        name2enum.put(new String("export"), new Integer(__EXPORT__));
        name2enum.put(new String("false"), new Integer(__CFALSE__));
        name2enum.put(new String("friend"), new Integer(__FRIEND__));
        name2enum.put(new String("inline"), new Integer(__INLINE__));
        name2enum.put(new String("__inline"), new Integer(__INLINE__));
        name2enum.put(new String("__inline__"), new Integer(__INLINE__));
        name2enum.put(new String("mutable"), new Integer(__MUTABLE__));
        name2enum.put(new String("namespace"), new Integer(__NAMESPACE__));
        name2enum.put(new String("new"), new Integer(__NEW__));
        name2enum.put(new String("operator"), new Integer(__OPERATOR__));
        name2enum.put(new String("private"), new Integer(__PRIVATE__));
        name2enum.put(new String("protected"), new Integer(__PROTECTED__));
        name2enum.put(new String("public"), new Integer(__PUBLIC__));
        name2enum.put(new String("reinterpret_cast"), new Integer(__REINTERPRET_CAST__));
        name2enum.put(new String("static_cast"), new Integer(__STATIC_CAST__));
        name2enum.put(new String("template"), new Integer(__TEMPLATE__));
        name2enum.put(new String("this"), new Integer(__THIS__));
        name2enum.put(new String("throw"), new Integer(__THROW__));
        name2enum.put(new String("TRUE"), new Integer(__CTRUE__));
        name2enum.put(new String("try"), new Integer(__TRY__));
        name2enum.put(new String("typeid"), new Integer(__TYPEID__));
        name2enum.put(new String("typename"), new Integer(__TYPENAME__));
        name2enum.put(new String("using"), new Integer(__USING__));
        name2enum.put(new String("virtual"), new Integer(__VIRTUAL__));
        name2enum.put(new String("wchar_t"), new Integer(__WCHAR_T__));
        name2enum.put(new String("::"), new Integer(__SCOPE__));
        name2enum.put(new String("__alignof"), new Integer(__ALIGNOF__));
        name2enum.put(new String("__alignof__"), new Integer(__ALIGNOF__));
        name2enum.put(new String("__attribute"), new Integer(__ATTRIBUTE__));
        name2enum.put(new String("__attribute__"), new Integer(__ATTRIBUTE__));
        name2enum.put(new String("__complex"), new Integer(__COMPLEX__));
        name2enum.put(new String("__complex__"), new Integer(__COMPLEX__));
        name2enum.put(new String("__extension__"), new Integer(__EXTENSION__));
        name2enum.put(new String("__imag"), new Integer(__IMAGPART__));
        name2enum.put(new String("__imag__"), new Integer(__IMAGPART__));
        name2enum.put(new String("__real"), new Integer(__REALPART__));
        name2enum.put(new String("__real__"), new Integer(__REALPART__));
        name2enum.put(new String("__restrict"), new Integer(__RESTRICT__));
        name2enum.put(new String("__restrict__"), new Integer(__RESTRICT__));
        name2enum.put(new String("typeof"), new Integer(__TYPEOF__));
        name2enum.put(new String("__typeof"), new Integer(__TYPEOF__));
        name2enum.put(new String("__typeof__"), new Integer(__TYPEOF__));
        name2enum.put(new String("__builtin_va_arg"), new Integer(__VA_ARG__));
        name2enum.put(new String("BEGIN_TEMPLATE"), new Integer(__BEGIN_TEMPLATE__));

        name2enum.put(new String("~"), new Integer(__TILDE__));
        name2enum.put(new String("!"), new Integer(__BANG__));
        name2enum.put(new String("%"), new Integer(__PERCENT_SIGN__));
        name2enum.put(new String("^"), new Integer(__CARET__));
        name2enum.put(new String("&"), new Integer(__AMPERSAND__));
        name2enum.put(new String("#"), new Integer(__SHARP__));
        name2enum.put(new String("$"), new Integer(__DOLLAR_SIGN__));
        name2enum.put(new String("`"), new Integer(__BACKTICK__));
        name2enum.put(new String("@"), new Integer(__AT_SIGN__));
        name2enum.put(new String("("), new Integer(__LEFT_PARENTHESIS__));
        name2enum.put(new String(")"), new Integer(__RIGHT_PARENTHESIS__));
        name2enum.put(new String("["), new Integer(__LEFT_BRACKET__));
        name2enum.put(new String("]"), new Integer(__RIGHT_BRACKET__));
        name2enum.put(new String("<"), new Integer(__LEFT_ANGLE_BRACKET__));
        name2enum.put(new String(">"), new Integer(__RIGHT_ANGLE_BRACKET__));
        name2enum.put(new String("{"), new Integer(__LEFT_BRACE__));
        name2enum.put(new String("}"), new Integer(__RIGHT_BRACE__));
        name2enum.put(new String("+"), new Integer(__PLUS_SIGN__));
        name2enum.put(new String("-"), new Integer(__MINUS_SIGN__));
        name2enum.put(new String("*"), new Integer(__ASTERISK__));
        name2enum.put(new String("/"), new Integer(__SLASH__));
        name2enum.put(new String("="), new Integer(__EQUAL_SIGN__));
        name2enum.put(new String("."), new Integer(__DOT__));
        name2enum.put(new String(","), new Integer(__COMMA__));
        name2enum.put(new String("|"), new Integer(__VERTICAL_BAR__));
        name2enum.put(new String(":"), new Integer(__COLON__));
        name2enum.put(new String(";"), new Integer(__SEMICOLON__));
        name2enum.put(new String("?"), new Integer(__QUESTION_MARK__));
    }

    protected boolean isStringLiteral(String _str)
    {
        String str_exp = "L?\"(\\.|[^\"])*\"";

        if (_str.matches(str_exp) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected boolean isConstant(String _str)
    {
        String	D = "[0-9]";
        String	L = "[a-zA-Z_]";
        String  H = "[a-fA-F0-9]";
        String  E = "[Ee][+-]?(" + D + ")+";
        String  FS	= "(f|F|l|L)";
        String  IS	= "(u|U|l|L)*";

        String const1 = "0[xX](" + H + ")+(" + IS + ")?";
        String const2 = "0(" + D + ")+(" + IS + ")?";
        String const3 = "(" + D + ")+(" + IS+ ")?";
        String const4 = L + "?'(\\.|[^\\'])+'";	//weird
        String const5 = "(" + D + ")+(" + E + ")(" + FS + ")?";
        String const6 = "(" + D + ")*.(" + D + ")+(" + E + ")?" + FS + "?";
        String const7 = "(" + D + ")+.(" + D + ")*(" + E + ")?" + FS + "?";

        String num_exp = const1 + "|" + const2 + "|" + const3 + "|" + const4 + "|" + const5 + "|" + const6 + "|" + const7;

        if (_str.matches(num_exp) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    protected boolean isIdentifier(String _str)
    {
        String	D = "[0-9]";
        String	L = "[a-zA-Z_]";
        String id_exp = "(" + L + ")((" + L + ")|(" + D + "))*";

        if (_str.matches(id_exp) == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}

