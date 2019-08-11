declarator_head:
	declarator_id
	| '(' declarator ')'
	| ptr_operator declarator_head
	;

declarator_tail:
	'(' parameter_declaration_clause ')'
	| '(' parameter_declaration_clause ')' cv_qualifier_seq
	| '(' parameter_declaration_clause ')'                  exception_specification
	| '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| '[' ']'
	| '[' constant_expression ']'
	;

declarator_tail_seq:
	declarator_tail
	| declarator_tail_seq declarator_tail
	;

member_declarator_list_tail:
	',' member_declarator_list
	;

scoped_class_name:
	class_name
	| class_name SCOPE scoped_class_name
	| class_name SCOPE TEMPLATE scoped_class_name
	;

scoped_id:
	IDENTIFIER
	| class_name SCOPE scoped_id
	| class_name SCOPE TEMPLATE scoped_id
	;

scoped_unqualified_id:
	class_name SCOPE unqualified_id
	| class_name SCOPE TEMPLATE unqualified_id
	| class_name SCOPE scoped_unqualified_id
	| class_name SCOPE TEMPLATE scoped_unqualified_id
	;

STRING_LITERAL_seq:
	STRING_LITERAL
	| STRING_LITERAL_seq STRING_LITERAL
	;

any_word:
	IDENTIFIER
    | storage_class_specifier
    | cv_qualifier
    ;

asm_clobbers:
	STRING_LITERAL
	| asm_clobbers ',' STRING_LITERAL
	;

asm_operand:
	STRING_LITERAL '(' expression ')'
	| '[' IDENTIFIER ']' STRING_LITERAL '(' expression ')'
	;

asm_operands:
	asm_operand
	| asm_operands ',' asm_operand
	;

attrib:
	any_word
	| any_word '(' expression_list ')'
	;

attribute:
	ATTRIBUTE '(' '(' attribute_list ')' ')'
	;

attribute_list:
	attrib
	| attribute_list ',' attrib
	;

attributes:
	attribute
	| attributes attribute
	;

literal:
	CONSTANT
	| STRING_LITERAL_seq
	| boolean_literal
	;

boolean_literal:
	CTRUE
	| CFALSE
	;

translation_unit:
	declaration_seq
	| /* empty */
	;

primary_expression:
	literal
	| THIS
	| SCOPE id_expression
	| '(' expression ')'
	| id_expression
	;

id_expression:
	unqualified_id
	| qualified_id
	;

unqualified_id:
	class_name
	| operator_function_id
	| conversion_function_id
	| '~' class_name
	;

qualified_id:
	scoped_unqualified_id
	;

nested_name_specifier:
	class_name    SCOPE
	| class_name SCOPE nested_name_specifier
	| class_name  SCOPE TEMPLATE nested_name_specifier
	;

postfix_expression:
	primary_expression
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' expression_list ')'
	| simple_type_specifier '(' ')'
	| simple_type_specifier '(' expression_list ')'
	| TYPENAME       scoped_class_name '(' ')'
	| TYPENAME       scoped_class_name '(' expression_list ')'
	| TYPENAME SCOPE scoped_class_name '(' ')'
	| TYPENAME SCOPE scoped_class_name '(' expression_list ')'
	| postfix_expression '.'                   id_expression
	| postfix_expression '.'    TEMPLATE       id_expression
	| postfix_expression '.'             SCOPE id_expression
	| postfix_expression '.'    TEMPLATE SCOPE id_expression
	| postfix_expression PTR_OP                id_expression
	| postfix_expression PTR_OP TEMPLATE       id_expression
	| postfix_expression PTR_OP          SCOPE id_expression
	| postfix_expression PTR_OP TEMPLATE SCOPE id_expression
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	| DYNAMIC_CAST     '<' type_id '>' '(' expression ')'
	| STATIC_CAST      '<' type_id '>' '(' expression ')'
	| REINTERPRET_CAST '<' type_id '>' '(' expression ')'
	| CONST_CAST       '<' type_id '>' '(' expression ')'
	| TYPEID '(' expression ')'
	| TYPEID '(' type_id ')'
	| VA_ARG '(' expression ',' type_id ')'
	| ambiguity
	;

expression_list:
	assignment_expression
	| expression_list ',' assignment_expression
	| ambiguity
	;

unary_expression:
	postfix_expression
	| INC_OP cast_expression
	| DEC_OP cast_expression
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_id ')'
	| new_expression
	| delete_expression
	| ALIGNOF unary_expression
	| ALIGNOF '(' type_id ')'
	| REALPART cast_expression
	| IMAGPART cast_expression
	| EXTENSION cast_expression
	| ambiguity
	;

unary_operator:
	'*'
	| '&'
	| '+'
	| '-'
	| '!'
	| '~'
	;

new_expression:
    NEW               new_type_id
	|       NEW               new_type_id new_initializer
	|       NEW new_placement new_type_id
	|       NEW new_placement new_type_id new_initializer
	| SCOPE NEW               new_type_id
	| SCOPE NEW               new_type_id new_initializer
	| SCOPE NEW new_placement new_type_id
	| SCOPE NEW new_placement new_type_id new_initializer
	|       NEW               '(' type_id ')'
	|       NEW               '(' type_id ')' new_initializer
	|       NEW new_placement '(' type_id ')'
	|       NEW new_placement '(' type_id ')' new_initializer
	| SCOPE NEW               '(' type_id ')'
	| SCOPE NEW               '(' type_id ')' new_initializer
	| SCOPE NEW new_placement '(' type_id ')'
	| SCOPE NEW new_placement '(' type_id ')' new_initializer
	;

new_placement:
	'(' expression_list ')'
	;

new_type_id:
	type_specifier_seq
	| type_specifier_seq new_declarator
	;

new_declarator:
	ptr_operator
	| ptr_operator new_declarator
	| direct_new_declarator
	;

direct_new_declarator:
	'[' expression ']'
	| direct_new_declarator '[' constant_expression ']'
	;

new_initializer:
	'(' ')'
	| '(' expression_list ')'
	;

delete_expression:
	DELETE cast_expression
	| SCOPE DELETE cast_expression
	| DELETE '[' ']' cast_expression
	| SCOPE DELETE '[' ']' cast_expression
	;

cast_expression:
	unary_expression
	| '(' type_id ')' cast_expression
	| '(' compound_statement ')'
	| ambiguity
	;

pm_expression:
	cast_expression
	| pm_expression DOT_MEMBER cast_expression
	| pm_expression PTR_MEMBER cast_expression
	;

multiplicative_expression:
	pm_expression
	| multiplicative_expression '*' pm_expression
	| multiplicative_expression '/' pm_expression
	| multiplicative_expression '%' pm_expression
	| ambiguity
	;

additive_expression:
	multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	| ambiguity
	;

shift_expression:
	additive_expression
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression:
	shift_expression
	| relational_expression '<' shift_expression
	| relational_expression '>' shift_expression
	| relational_expression LE_OP shift_expression
	| relational_expression GE_OP shift_expression
	;

equality_expression:
	relational_expression
	| equality_expression EQ_OP relational_expression
	| equality_expression NE_OP relational_expression
	;

and_expression:
	equality_expression
	| and_expression '&' equality_expression
	| ambiguity
	;

exclusive_or_expression:
	and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression:
	exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression:
	inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression:
	logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression:
	logical_or_expression
	| logical_or_expression '?' expression ':' assignment_expression
	;

assignment_expression:
	conditional_expression
	| logical_or_expression assignment_operator assignment_expression
	| throw_expression
	;

assignment_operator:
	'='
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| RIGHT_ASSIGN
	| LEFT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression:
	assignment_expression
	| expression ',' assignment_expression
	| ambiguity
	;

constant_expression:
	conditional_expression
	;

statement:
	labeled_statement
	| expression_statement
	| compound_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	| block_declaration
	| try_block
	| ambiguity
	;

labeled_statement:
	IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

expression_statement:
	expression ';'
	;

compound_statement:
	'{' '}'
	| '{' statement_seq '}'
	;

statement_seq:
	statement
	| statement_seq statement
	;

selection_statement:
	IF '(' condition ')' statement
	| IF '(' condition ')' statement ELSE statement
	| SWITCH '(' condition ')' statement
	;

condition:
	expression
	| type_specifier_seq declarator '=' assignment_expression
	;

iteration_statement:
	WHILE '(' condition ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' for_init_statement           ';'            ')' statement
	| FOR '(' for_init_statement           ';' expression ')' statement
	| FOR '(' for_init_statement condition ';'            ')' statement
	| FOR '(' for_init_statement condition ';' expression ')' statement
	;

for_init_statement:
	expression_statement
	| simple_declaration
	| ambiguity
	;

jump_statement:
	BREAK ';'
	| CONTINUE ';'
	| RETURN ';'
	| RETURN expression ';'
	| GOTO IDENTIFIER ';'
	;

declaration_seq:
	declaration
	| declaration_seq declaration
	;

declaration:
	block_declaration
	| function_definition
	| template_declaration
	| explicit_instantiation
	| explicit_specialization
	| linkage_specification
	| namespace_definition
	;

block_declaration:
	simple_declaration
	| asm_definition
	| namespace_alias_definition
	| using_declaration
	| using_directive
	| EXTENSION simple_declaration
	;

simple_declaration:
	';'
	| decl_specifier_seq ';'
	| decl_specifier_seq attributes ';'
	| init_declarator_list ';'
	| decl_specifier_seq declarator_head ';'
	| decl_specifier_seq declarator_head attributes ';'
	| decl_specifier_seq declarator_head ',' init_declarator_list ';'
	| decl_specifier_seq declarator_head attributes ',' init_declarator_list ';'
	| decl_specifier_seq declarator_head declarator_tail_seq ';'
	| decl_specifier_seq declarator_head declarator_tail_seq attributes ';'
	| decl_specifier_seq declarator_head declarator_tail_seq ',' init_declarator_list ';'
	| decl_specifier_seq declarator_head declarator_tail_seq attributes ',' init_declarator_list ';'
	| decl_specifier_seq declarator_head initializer ';'
	| decl_specifier_seq declarator_head initializer ',' init_declarator_list ';'
	| decl_specifier_seq declarator_head declarator_tail_seq initializer ';'
	| decl_specifier_seq declarator_head declarator_tail_seq initializer ',' init_declarator_list ';'
	| ambiguity
	;

decl_specifier:
	storage_class_specifier
	| type_specifier
	| function_specifier
	| FRIEND
	| TYPEDEF
	;

decl_specifier_seq:
	decl_specifier
	| decl_specifier_seq decl_specifier
	;

storage_class_specifier:
	AUTO
	| REGISTER
	| STATIC
	| EXTERN
	| MUTABLE
	;

function_specifier:
	INLINE
	| VIRTUAL
	| EXPLICIT
	;

type_specifier:
	simple_type_specifier
	| CLASS                               '{'                      '}'
	| CLASS                               '{' member_specification '}'
	| CLASS                   base_clause '{'                      '}'
	| CLASS                   base_clause '{' member_specification '}'
	| CLASS scoped_class_name             '{'                      '}'
	| CLASS scoped_class_name             '{' member_specification '}'
	| CLASS scoped_class_name base_clause '{'                      '}'
	| CLASS scoped_class_name base_clause '{' member_specification '}'
	| STRUCT                               '{'                      '}'
	| STRUCT                               '{' member_specification '}'
	| STRUCT                   base_clause '{'                      '}'
	| STRUCT                   base_clause '{' member_specification '}'
	| STRUCT scoped_class_name             '{'                      '}'
	| STRUCT scoped_class_name             '{' member_specification '}'
	| STRUCT scoped_class_name base_clause '{'                      '}'
	| STRUCT scoped_class_name base_clause '{' member_specification '}'
	| UNION                               '{'                      '}'
	| UNION                               '{' member_specification '}'
	| UNION                   base_clause '{'                      '}'
	| UNION                   base_clause '{' member_specification '}'
	| UNION scoped_class_name             '{'                      '}'
	| UNION scoped_class_name             '{' member_specification '}'
	| UNION scoped_class_name base_clause '{'                      '}'
	| UNION scoped_class_name base_clause '{' member_specification '}'
	| ENUM            '{'                 '}'
	| ENUM            '{' enumerator_list '}'
	| ENUM IDENTIFIER '{'                 '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| CLASS        scoped_class_name
	| CLASS  SCOPE scoped_class_name
	| STRUCT       scoped_class_name
	| STRUCT SCOPE scoped_class_name
	| UNION        scoped_class_name
	| UNION  SCOPE scoped_class_name
	| ENUM IDENTIFIER
	| ENUM IDENTIFIER SCOPE scoped_id
	| ENUM IDENTIFIER BEGIN_TEMPLATE '>' SCOPE scoped_id
	| ENUM IDENTIFIER BEGIN_TEMPLATE '>' SCOPE TEMPLATE scoped_id
	| ENUM IDENTIFIER BEGIN_TEMPLATE template_argument_list '>' SCOPE scoped_id
	| ENUM IDENTIFIER BEGIN_TEMPLATE template_argument_list '>' SCOPE TEMPLATE scoped_id
	| ENUM SCOPE scoped_id
	| TYPENAME scoped_class_name
	| TYPENAME SCOPE scoped_class_name
	| cv_qualifier
	;

simple_type_specifier:
	scoped_class_name
	| SCOPE scoped_class_name
	| CHAR
	| WCHAR_T
	| CBOOL
	| SHORT
	| INT
	| LONG
	| SIGNED
	| UNSIGNED
	| FLOAT
	| DOUBLE
	| VOID
	| COMPLEX
	| TYPEOF '(' expression ')'
	| TYPEOF '(' type_id ')'
	| ambiguity
	;

enumerator_list:
	enumerator_definition
	| enumerator_list ',' enumerator_definition
	;

enumerator_definition:
	IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

namespace_definition:
	NAMESPACE              '{'                 '}'
	| NAMESPACE            '{' declaration_seq '}'
	| NAMESPACE IDENTIFIER '{'                 '}'
	| NAMESPACE IDENTIFIER '{' declaration_seq '}'
	;

namespace_alias_definition:
	NAMESPACE IDENTIFIER '=' qualified_namespace_specifier ';'
	;

qualified_namespace_specifier:
	scoped_id
	| SCOPE scoped_id
	;

using_declaration:
	USING                  scoped_unqualified_id ';'
	| USING TYPENAME       scoped_unqualified_id ';'
	| USING          SCOPE scoped_unqualified_id ';'
	| USING TYPENAME SCOPE scoped_unqualified_id ';'
	| USING          SCOPE unqualified_id ';'
	;

using_directive:
	USING   NAMESPACE       scoped_id ';'
	| USING NAMESPACE SCOPE scoped_id ';'
	;

asm_definition:
	ASM                '(' STRING_LITERAL_seq ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                    ':'                  ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands     ':'                  ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                    ':' asm_operands     ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands     ':' asm_operands     ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                    ':'                  ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands     ':'                  ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                    ':' asm_operands     ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands     ':' asm_operands     ')' ';'
	| ASM              '(' STRING_LITERAL_seq SCOPE              ')' ';'
	| ASM              '(' STRING_LITERAL_seq SCOPE asm_operands ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq SCOPE              ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq SCOPE asm_operands ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                    ':'                  ':' asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands     ':'                  ':' asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                    ':' asm_operands     ':' asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands     ':' asm_operands     ':' asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                    ':'                  ':' asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands     ':'                  ':' asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                    ':' asm_operands     ':' asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands     ':' asm_operands     ':' asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq SCOPE              ':'   asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq SCOPE asm_operands ':'   asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq SCOPE              ':'   asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq SCOPE asm_operands ':'   asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'                SCOPE asm_clobbers ')' ';'
	| ASM              '(' STRING_LITERAL_seq ':'   asm_operands SCOPE asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'                SCOPE asm_clobbers ')' ';'
	| ASM cv_qualifier '(' STRING_LITERAL_seq ':'   asm_operands SCOPE asm_clobbers ')' ';'
	;

linkage_specification:
	EXTERN STRING_LITERAL '{' '}'
	| EXTERN STRING_LITERAL '{' declaration_seq '}'
	| EXTERN STRING_LITERAL declaration
	;

init_declarator_list:
	init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator:
	declarator
	| declarator initializer
	| ambiguity
	;

declarator:
	direct_declarator
	| ptr_operator declarator
	;

direct_declarator:
	declarator_id
	| direct_declarator '(' parameter_declaration_clause ')'
	| direct_declarator '(' parameter_declaration_clause ')' cv_qualifier_seq
	| direct_declarator '(' parameter_declaration_clause ')'                  exception_specification
	| direct_declarator '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_declarator '[' ']'
	| direct_declarator '[' constant_expression ']'
	| '(' declarator ')'
	;

ptr_operator:
	'*'
	| '*' cv_qualifier_seq
	| '&'
	| nested_name_specifier '*'
	| nested_name_specifier '*' cv_qualifier_seq
	| SCOPE nested_name_specifier '*'
	| SCOPE nested_name_specifier '*' cv_qualifier_seq
	;

cv_qualifier_seq:
	cv_qualifier
	| cv_qualifier_seq cv_qualifier
	;

cv_qualifier:
	CONST
	| VOLATILE
	| RESTRICT
	;

declarator_id:
	id_expression
	| SCOPE id_expression
	;

type_id:
	type_specifier_seq
	| type_specifier_seq abstract_declarator
	;

type_specifier_seq:
	type_specifier
	| type_specifier_seq type_specifier
	;

abstract_declarator:
	ptr_operator
	| ptr_operator abstract_declarator
	| direct_abstract_declarator
	;

direct_abstract_declarator:
	'(' parameter_declaration_clause ')'
	| '(' parameter_declaration_clause ')' cv_qualifier_seq
	| '(' parameter_declaration_clause ')'                  exception_specification
	| '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| direct_abstract_declarator '(' parameter_declaration_clause ')'
	| direct_abstract_declarator '(' parameter_declaration_clause ')' cv_qualifier_seq
	| direct_abstract_declarator '(' parameter_declaration_clause ')'                  exception_specification
	| direct_abstract_declarator '(' parameter_declaration_clause ')' cv_qualifier_seq exception_specification
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' abstract_declarator ')'
	;

parameter_declaration_clause:
	/*empty*/
	| parameter_declaration_list
	|                            ELLIPSIS
	| parameter_declaration_list ELLIPSIS
	| parameter_declaration_list ',' ELLIPSIS
	;

parameter_declaration_list:
	parameter_declaration
	| parameter_declaration_list ',' parameter_declaration
	| ambiguity
	;

parameter_declaration:
	decl_specifier_seq declarator_head
	| decl_specifier_seq declarator_head declarator_tail_seq
	| decl_specifier_seq declarator_head '=' assignment_expression
	| decl_specifier_seq declarator_head declarator_tail_seq '=' assignment_expression
	| decl_specifier_seq
	| decl_specifier_seq abstract_declarator
	| decl_specifier_seq                     '=' assignment_expression
	| decl_specifier_seq abstract_declarator '=' assignment_expression
	| ambiguity
	;

function_prefix:
	declarator
	| decl_specifier_seq            declarator_head
	| decl_specifier_seq attributes declarator_head
	| decl_specifier_seq            declarator_head declarator_tail_seq
	| decl_specifier_seq attributes declarator_head declarator_tail_seq
	| ambiguity
	;

function_definition:
	function_prefix compound_statement
	| function_prefix ctor_initializer compound_statement
	| function_prefix function_try_block
	;

initializer:
	'=' initializer_clause
	| '(' expression_list ')'
	;

initializer_clause:
	assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	| '{' '}'
	;

initializer_list:
	initializer_clause
	| initializer_list ',' initializer_clause
	;

class_name:
	IDENTIFIER
	| IDENTIFIER BEGIN_TEMPLATE '>'
	| IDENTIFIER BEGIN_TEMPLATE template_argument_list '>'
	;

member_specification:
	';'
	| member_declaration ';'
	| member_declaration_alt
	| EXTENSION member_declaration ';'
	| EXTENSION member_declaration_alt
	| member_specification ';'
	| member_specification member_declaration ';'
	| member_specification member_declaration_alt
	| member_specification EXTENSION member_declaration ';'
	| member_specification EXTENSION member_declaration_alt
	;

member_declaration:
	decl_specifier_seq
	| decl_specifier_seq attributes
	| member_declarator_list
	| decl_specifier_seq declarator_head
	| decl_specifier_seq declarator_head member_declarator_list_tail
	| decl_specifier_seq declarator_head constant_initializer
	| decl_specifier_seq declarator_head constant_initializer member_declarator_list_tail
	| decl_specifier_seq declarator_head declarator_tail_seq
	| decl_specifier_seq declarator_head declarator_tail_seq member_declarator_list_tail
	| decl_specifier_seq declarator_head declarator_tail_seq constant_initializer
	| decl_specifier_seq declarator_head declarator_tail_seq constant_initializer member_declarator_list_tail
	| decl_specifier_seq ':' constant_expression
	| decl_specifier_seq ':' constant_expression member_declarator_list_tail
	| decl_specifier_seq IDENTIFIER ':' constant_expression
	| decl_specifier_seq IDENTIFIER ':' constant_expression member_declarator_list_tail
	| scoped_unqualified_id
	| SCOPE scoped_unqualified_id
	| ambiguity
	;

member_declaration_alt:
	function_definition
	| using_declaration
	| template_declaration
	| access_specifier ':'
	;

member_declarator_list:
	member_declarator
	| member_declarator_list ',' member_declarator
	;

member_declarator:
	declarator
	| declarator constant_initializer
	| ':' constant_expression
	| IDENTIFIER ':' constant_expression
	;

constant_initializer:
	'=' constant_expression
	;

base_clause:
	':' base_specifier_list
	;

base_specifier_list:
	base_specifier
	| base_specifier_list ',' base_specifier
	;

base_specifier:
	scoped_class_name
	| SCOPE scoped_class_name
	| VIRTUAL                        scoped_class_name
	| VIRTUAL access_specifier       scoped_class_name
	| VIRTUAL                  SCOPE scoped_class_name
	| VIRTUAL access_specifier SCOPE scoped_class_name
	| access_specifier               scoped_class_name
	| access_specifier VIRTUAL       scoped_class_name
	| access_specifier         SCOPE scoped_class_name
	| access_specifier VIRTUAL SCOPE scoped_class_name
	;

access_specifier:
	PRIVATE
	| PROTECTED
	| PUBLIC
	;

conversion_function_id:
	OPERATOR conversion_type_id
	;

conversion_type_id:
	type_specifier_seq
	| type_specifier_seq conversion_declarator
	;

conversion_declarator:
	ptr_operator
	| ptr_operator conversion_declarator
	;

ctor_initializer:
	':' mem_initializer_list
	;

mem_initializer_list:
	mem_initializer
	| mem_initializer_list ',' mem_initializer
	;

mem_initializer:
	mem_initializer_id '(' ')'
	| mem_initializer_id '(' expression_list ')'
	;

mem_initializer_id:
	scoped_class_name
	| SCOPE scoped_class_name
	;

operator_function_id:
	OPERATOR operator_
	;

operator_:
	NEW
	| DELETE
	| NEW '[' ']'
	| DELETE '[' ']'
	| '+'
	| '-'
	| '*'
	| '/'
	| '%'
	| '^'
	| '&'
	| '|'
	| '~'
	| '!'
	| '='
	| '<'
	| '>'
	| ADD_ASSIGN
	| SUB_ASSIGN
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| XOR_ASSIGN
	| AND_ASSIGN
	| OR_ASSIGN
	| LEFT_OP
	| RIGHT_OP
	| RIGHT_ASSIGN
	| LEFT_ASSIGN
	| EQ_OP
	| NE_OP
	| LE_OP
	| GE_OP
	| AND_OP
	| OR_OP
	| INC_OP
	| DEC_OP
	| ','
	| PTR_MEMBER
	| PTR_OP
	| '(' ')'
	| '[' ']'
	;

template_declaration:
	TEMPLATE '<' template_parameter_list '>' declaration
	| EXPORT TEMPLATE '<' template_parameter_list '>' declaration
	;

template_parameter_list:
	template_parameter
	| template_parameter_list ',' template_parameter
	;

template_parameter:
	type_parameter
	| parameter_declaration
	| ambiguity
	;

type_parameter:
	CLASS
	| CLASS IDENTIFIER
	| CLASS            '=' type_id
	| CLASS IDENTIFIER '=' type_id
	| TYPENAME
	| TYPENAME IDENTIFIER
	| TYPENAME            '=' type_id
	| TYPENAME IDENTIFIER '=' type_id
	| TEMPLATE '<' template_parameter_list '>' CLASS
	| TEMPLATE '<' template_parameter_list '>' CLASS IDENTIFIER
	| TEMPLATE '<' template_parameter_list '>' CLASS            '=' id_expression
	| TEMPLATE '<' template_parameter_list '>' CLASS IDENTIFIER '=' id_expression
	;

template_argument_list:
	template_argument
	| template_argument_list ',' template_argument
	;

template_argument:
	assignment_expression
	| type_id
	| ambiguity
	;

explicit_instantiation:
	TEMPLATE declaration
	| EXTERN TEMPLATE declaration
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration
	;

try_block:
	TRY compound_statement handler_seq
	;

function_try_block:
	TRY compound_statement  handler_seq
	| TRY ctor_initializer compound_statement handler_seq
	;

handler_seq:
	handler
	| handler_seq handler
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement
	;

exception_declaration:
	type_specifier_seq declarator
	| type_specifier_seq abstract_declarator
	| type_specifier_seq
	| ELLIPSIS
	| ambiguity
	;

throw_expression:
	THROW
	| THROW assignment_expression
	;

exception_specification:
	THROW '(' ')'
	| THROW '(' type_id_list ')'
	;

type_id_list:
	type_id
	| type_id_list ',' type_id
	;
