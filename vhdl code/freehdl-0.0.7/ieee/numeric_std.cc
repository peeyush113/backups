#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:numeric_std */
/* External declarations */
/* Definitions for enumeration type :ieee:std_logic_1164:std_ulogic */
class L4ieee_Q14std_logic_1164_I10std_ulogic:public enum_info_base{
   static const char *values[];
public:
   L4ieee_Q14std_logic_1164_I10std_ulogic():enum_info_base(0,8,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 8; }
   static int left() { return 0; }
   static int right() { return 8; }
};
extern L4ieee_Q14std_logic_1164_I10std_ulogic L4ieee_Q14std_logic_1164_I10std_ulogic_INFO;
/** Enumeration info class :ieee:std_logic_1164:std_logic */
class L4ieee_Q14std_logic_1164_I9std_logic:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q14std_logic_1164_I9std_logic():enum_info_base(0,8,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 8; }
   static int left() { return 0; }
   static int right() { return 8; }
};
extern L4ieee_Q14std_logic_1164_I9std_logic L4ieee_Q14std_logic_1164_I9std_logic_INFO;
extern array_info L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO;
#define L4ieee_Q14std_logic_1164_T16std_logic_vector array_type<enumeration >
#define L4ieee_Q14std_logic_1164_I16std_logic_vector array_info

/* End of external declarations */
extern array_info L4ieee_Q11numeric_std_I8unsigned_INFO;
#define L4ieee_Q11numeric_std_T8unsigned array_type<enumeration >
#define L4ieee_Q11numeric_std_I8unsigned array_info

extern array_info L4ieee_Q11numeric_std_I6signed_INFO;
#define L4ieee_Q11numeric_std_T6signed array_type<enumeration >
#define L4ieee_Q11numeric_std_I6signed array_info

/* Prototype for subprogram :ieee:numeric_std:"abs" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_abs_i29(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i31(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i34(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i37(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i40(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i43(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i46(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i49(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i52(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i55(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i58(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i61(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i64(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i67(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i70(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i73(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i76(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i79(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i82(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i85(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i88(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i91(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i94(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i97(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i100(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i103(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i106(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i109(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i112(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i115(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i118(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i121(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i124(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i127(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i130(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i133(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i136(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i139(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i142(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i145(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i148(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i151(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i154(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i157(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i160(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i163(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i166(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i169(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i172(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i175(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i178(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i181(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i184(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i187(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i190(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i193(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i196(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i199(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i202(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i205(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i208(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i211(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i214(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i217(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i220(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i223(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i226(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i229(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i232(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i235(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i238(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i241(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i244(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i247(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y10shift_left_i250(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11shift_right_i253(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y10shift_left_i256(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11shift_right_i259(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11rotate_left_i262(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y12rotate_right_i265(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11rotate_left_i268(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y12rotate_right_i271(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6resize_i274(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6resize_i277(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i279(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i281(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i284(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i287(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i289(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i291(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i293(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i295(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_not_i297(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_and_i300(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_or_i303(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_nand_i306(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_nor_i309(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_xor_i312(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_not_i314(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_and_i317(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_or_i320(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_nand_i323(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_nor_i326(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_xor_i329(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i332(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i335(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
L4ieee_Q11numeric_std_I8unsigned L4ieee_Q11numeric_std_I8unsigned_INFO;
L4ieee_Q11numeric_std_I6signed L4ieee_Q11numeric_std_I6signed_INFO;
/* Initialization function for package :ieee:numeric_std */
int L3std_Q8standard_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_Q11numeric_std_init_done = false;
int L4ieee_Q11numeric_std_init(){
if (L4ieee_Q11numeric_std_init_done) return 1;
L4ieee_Q11numeric_std_init_done=true;
L3std_Q8standard_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/numeric_std.vhdl","numeric_std.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":numeric_std");
L4ieee_Q11numeric_std_I8unsigned_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:numeric_std",":ieee:numeric_std:unsigned",":UNSIGNED",NULL);
L4ieee_Q11numeric_std_I6signed_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:numeric_std",":ieee:numeric_std:signed",":SIGNED",NULL);
iname.pop();
handle_info *h = get_handle ("ieee","numeric_std",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:numeric_std */

/* package body :ieee:numeric_std */
/* External declarations */
/* No header for IIR_EnumerationLiteral */
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i92(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y5op_or_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_and_i68(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_not_i97(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* Prototype for predefined function :ieee:std_logic_1164:"<=" */
/** Enumeration info class :ieee:std_logic_1164:ux01 */
class L4ieee_Q14std_logic_1164_I4ux01:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q14std_logic_1164_I4ux01():enum_info_base(0,3,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 3; }
   static int left() { return 0; }
   static int right() { return 3; }
};
extern L4ieee_Q14std_logic_1164_I4ux01 L4ieee_Q14std_logic_1164_I4ux01_INFO;
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
enumeration L4ieee_Q14std_logic_1164_Y6op_not_i65(const enumeration );
/* Prototype for predefined function :ieee:std_logic_1164:"<" */
/* Prototype for predefined function :ieee:std_logic_1164:"=" */
/* No header for IIR_EnumerationLiteral */
/* Prototype for predefined function :ieee:std_logic_1164:"=" */
/* Prototype for predefined function :ieee:std_logic_1164:"/=" */
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63(const enumeration ,const enumeration );
/* No header for IIR_EnumerationLiteral */
/* End of external declarations */
extern array_info L4ieee_W11numeric_std_I3_t0_INFO;
#define L4ieee_W11numeric_std_T3_t0 array_type<enumeration >
#define L4ieee_W11numeric_std_I3_t0 array_info

extern array_info L4ieee_W11numeric_std_I3_t1_INFO;
#define L4ieee_W11numeric_std_T3_t1 array_type<enumeration >
#define L4ieee_W11numeric_std_I3_t1 array_info

/* Prototype for subprogram :ieee:numeric_std:max */
integer L4ieee_W11numeric_std_Y3max_i9(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:min */
integer L4ieee_W11numeric_std_Y3min_i12(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:signed_num_bits */
integer L4ieee_W11numeric_std_Y15signed_num_bits_i14(const integer );
/* Prototype for subprogram :ieee:numeric_std:unsigned_num_bits */
integer L4ieee_W11numeric_std_Y17unsigned_num_bits_i19(const integer );
/* Prototype for subprogram :ieee:numeric_std:add_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y12add_unsigned_i26(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:add_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y10add_signed_i37(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:divmod */
void L4ieee_W11numeric_std_X6divmod_i49(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &,L4ieee_Q11numeric_std_T8unsigned &,L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:xsll */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsll_i65(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:numeric_std:xsrl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsrl_i71(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:numeric_std:xsra */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsra_i77(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:numeric_std:xrol */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xrol_i84(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:numeric_std:xror */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xror_i91(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:numeric_std:unsigned_equal */
enumeration L4ieee_W11numeric_std_Y14unsigned_equal_i98(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:signed_equal */
enumeration L4ieee_W11numeric_std_Y12signed_equal_i101(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:unsigned_less */
enumeration L4ieee_W11numeric_std_Y13unsigned_less_i104(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:signed_less */
enumeration L4ieee_W11numeric_std_Y11signed_less_i107(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:unsigned_less_or_equal */
enumeration L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:signed_less_or_equal */
enumeration L4ieee_W11numeric_std_Y20signed_less_or_equal_i115(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:to_01 */
L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y5to_01_i120(const L4ieee_Q11numeric_std_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:to_01 */
L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y5to_01_i130(const L4ieee_Q11numeric_std_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:"abs" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_abs_i29(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i31(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i34(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i37(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i40(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i43(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i49(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i46(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i52(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i55(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i58(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i61(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i64(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i67(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i70(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i73(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i76(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i79(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i82(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i85(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i88(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i91(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i94(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i97(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i100(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i103(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i106(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i109(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i112(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i115(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i118(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i121(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i124(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i127(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i130(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i133(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i136(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i139(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i142(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i145(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i148(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i151(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i154(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i157(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i160(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i163(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i166(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i169(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i172(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i175(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i178(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i181(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i184(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i187(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i190(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i193(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i196(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i199(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i202(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i205(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i208(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i211(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i214(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i217(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i220(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i223(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i226(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i229(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i232(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i235(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i238(const integer ,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i241(const integer ,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i244(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i247(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y10shift_left_i250(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11shift_right_i253(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y10shift_left_i256(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11shift_right_i259(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11rotate_left_i262(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y12rotate_right_i265(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11rotate_left_i268(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y12rotate_right_i271(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i279(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i281(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i284(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i287(const integer ,const integer );
/* Prototype for subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i289(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i291(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i293(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i295(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6resize_i274(const L4ieee_Q11numeric_std_T6signed &,const integer );
/* Prototype for subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6resize_i277(const L4ieee_Q11numeric_std_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_not_i297(const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_and_i300(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_or_i303(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_nand_i306(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_nor_i309(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_xor_i312(const L4ieee_Q11numeric_std_T8unsigned &,const L4ieee_Q11numeric_std_T8unsigned &);
/* Prototype for subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_not_i314(const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_and_i317(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_or_i320(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_nand_i323(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_nor_i326(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
/* Prototype for subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_xor_i329(const L4ieee_Q11numeric_std_T6signed &,const L4ieee_Q11numeric_std_T6signed &);
extern array_info L4ieee_W11numeric_std_I15stdulogic_table_INFO;
#define L4ieee_W11numeric_std_T15stdulogic_table array_type<array_type<enumeration > >
#define L4ieee_W11numeric_std_I15stdulogic_table array_info

/* Prototype for subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i332(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i335(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
L4ieee_W11numeric_std_T3_t0 L4ieee_W11numeric_std_C3nau;
L4ieee_W11numeric_std_T3_t1 L4ieee_W11numeric_std_C3nas;
enumeration L4ieee_W11numeric_std_C10no_warning;
L4ieee_W11numeric_std_T15stdulogic_table L4ieee_W11numeric_std_C9and_table,L4ieee_W11numeric_std_C11match_table;
L4ieee_W11numeric_std_I3_t0 L4ieee_W11numeric_std_I3_t0_INFO;
L4ieee_W11numeric_std_I3_t1 L4ieee_W11numeric_std_I3_t1_INFO;
/* Implementation of subprogram :ieee:numeric_std:max */
integer L4ieee_W11numeric_std_Y3max_i9(const integer L4ieee_W11numeric_std_Y3max_i9_C4left,const integer L4ieee_W11numeric_std_Y3max_i9_C5right)
{
    if((L4ieee_W11numeric_std_Y3max_i9_C4left>L4ieee_W11numeric_std_Y3max_i9_C5right)) {
      return L4ieee_W11numeric_std_Y3max_i9_C4left;
    } else {
      return L4ieee_W11numeric_std_Y3max_i9_C5right;
    }
}
/* Implementation of subprogram :ieee:numeric_std:min */
integer L4ieee_W11numeric_std_Y3min_i12(const integer L4ieee_W11numeric_std_Y3min_i12_C4left,const integer L4ieee_W11numeric_std_Y3min_i12_C5right)
{
    if((L4ieee_W11numeric_std_Y3min_i12_C4left<L4ieee_W11numeric_std_Y3min_i12_C5right)) {
      return L4ieee_W11numeric_std_Y3min_i12_C4left;
    } else {
      return L4ieee_W11numeric_std_Y3min_i12_C5right;
    }
}
/* Implementation of subprogram :ieee:numeric_std:signed_num_bits */
integer L4ieee_W11numeric_std_Y15signed_num_bits_i14(const integer L4ieee_W11numeric_std_Y15signed_num_bits_i14_C3arg)
{
    integer L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits,L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n;
    L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits=0;
    L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n=0;
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14_C3arg>=0)) {
      L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n=L4ieee_W11numeric_std_Y15signed_num_bits_i14_C3arg;
    } else {
      L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n=(-(L4ieee_W11numeric_std_Y15signed_num_bits_i14_C3arg+1));
    }
    L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits=1;
    while((L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n>0)) {
      L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits=(L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits+1);
      L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n=(L4ieee_W11numeric_std_Y15signed_num_bits_i14_V1n/2);
    }
    return L4ieee_W11numeric_std_Y15signed_num_bits_i14_V5nbits;
}
/* Implementation of subprogram :ieee:numeric_std:unsigned_num_bits */
integer L4ieee_W11numeric_std_Y17unsigned_num_bits_i19(const integer L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_C3arg)
{
    integer L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits,L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n;
    L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits=0;
    L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n=0;
    L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n=L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_C3arg;
    L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits=1;
    while((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n>1)) {
      L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits=(L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits+1);
      L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n=(L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V1n/2);
    }
    return L4ieee_W11numeric_std_Y17unsigned_num_bits_i19_V5nbits;
}
/* Implementation of subprogram :ieee:numeric_std:add_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y12add_unsigned_i26(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y12add_unsigned_i26_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y12add_unsigned_i26_C1r,const enumeration L4ieee_W11numeric_std_Y12add_unsigned_i26_C1c)
{
    integer L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xl,L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y12add_unsigned_i26_V6result;
    enumeration L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit;
    integer L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i,L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i_lc;
    L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left=(L4ieee_W11numeric_std_Y12add_unsigned_i26_C1l.info->length-1);
    L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left,downto,0,0)), L4ieee_W11numeric_std_Y12add_unsigned_i26_C1l.data);
    L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left,downto,0,0)), L4ieee_W11numeric_std_Y12add_unsigned_i26_C1r.data);
    L4ieee_W11numeric_std_Y12add_unsigned_i26_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit=L4ieee_W11numeric_std_Y12add_unsigned_i26_C1c;
    for (L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i=0,L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W11numeric_std_Y12add_unsigned_i26_C6l_left); L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i_lc!=0; L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i++,L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i_lc--) {
      L4ieee_W11numeric_std_Y12add_unsigned_i26_V6result[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit,L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xl[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i]),L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xr[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i]);
      L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit,L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xl[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y12add_unsigned_i26_V4cbit,L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xr[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i])),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xl[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i],L4ieee_W11numeric_std_Y12add_unsigned_i26_H2xr[L4ieee_W11numeric_std_Y12add_unsigned_i26_L432ln_C1i]));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y12add_unsigned_i26_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:add_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y10add_signed_i37(const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y10add_signed_i37_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y10add_signed_i37_C1r,const enumeration L4ieee_W11numeric_std_Y10add_signed_i37_C1c)
{
    integer L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_W11numeric_std_Y10add_signed_i37_H2xl,L4ieee_W11numeric_std_Y10add_signed_i37_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y10add_signed_i37_V6result;
    enumeration L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit;
    integer L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i,L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i_lc;
    L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left=(L4ieee_W11numeric_std_Y10add_signed_i37_C1l.info->length-1);
    L4ieee_W11numeric_std_Y10add_signed_i37_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left,downto,0,0)), L4ieee_W11numeric_std_Y10add_signed_i37_C1l.data);
    L4ieee_W11numeric_std_Y10add_signed_i37_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left,downto,0,0)), L4ieee_W11numeric_std_Y10add_signed_i37_C1r.data);
    L4ieee_W11numeric_std_Y10add_signed_i37_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit=L4ieee_W11numeric_std_Y10add_signed_i37_C1c;
    for (L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i=0,L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W11numeric_std_Y10add_signed_i37_C6l_left); L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i_lc!=0; L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i++,L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i_lc--) {
      L4ieee_W11numeric_std_Y10add_signed_i37_V6result[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit,L4ieee_W11numeric_std_Y10add_signed_i37_H2xl[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i]),L4ieee_W11numeric_std_Y10add_signed_i37_H2xr[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i]);
      L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit,L4ieee_W11numeric_std_Y10add_signed_i37_H2xl[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y10add_signed_i37_V4cbit,L4ieee_W11numeric_std_Y10add_signed_i37_H2xr[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i])),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W11numeric_std_Y10add_signed_i37_H2xl[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i],L4ieee_W11numeric_std_Y10add_signed_i37_H2xr[L4ieee_W11numeric_std_Y10add_signed_i37_L443ln_C1i]));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y10add_signed_i37_V6result);
}
enumeration L4ieee_W11numeric_std_itn20_lit[]={68,73,86,44,77,79,68,44,111,114,32,82,69,77,32,98,121,32,122,101,114,111};
enumeration L4ieee_W11numeric_std_itn21_lit[]={2};
enumeration L4ieee_W11numeric_std_itn22_lit[]={2};
enumeration L4ieee_W11numeric_std_itn23_lit[]={105,110,116,101,114,110,97,108,32,101,114,114,111,114,32,105,110,32,116,104,101,32,100,105,118,105,115,105,111,110,32,97,108,103,111,114,105,116,104,109};
enumeration L4ieee_W11numeric_std_itn24_lit[]={105,110,116,101,114,110,97,108,32,101,114,114,111,114,32,105,110,32,116,104,101,32,100,105,118,105,115,105,111,110,32,97,108,103,111,114,105,116,104,109};
/* Implementation of subprogram :ieee:numeric_std:divmod */
void L4ieee_W11numeric_std_X6divmod_i49(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_X6divmod_i49_C3num,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_X6divmod_i49_C6xdenom,L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_X6divmod_i49_V5xquot,L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_X6divmod_i49_V7xremain)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_X6divmod_i49_V4temp,L4ieee_W11numeric_std_X6divmod_i49_V4quot,L4ieee_W11numeric_std_X6divmod_i49_V4diff;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_W11numeric_std_X6divmod_i49_H5denom;
    enumeration L4ieee_W11numeric_std_X6divmod_i49_V5carry;
    integer L4ieee_W11numeric_std_X6divmod_i49_V6topbit;
    enumeration L4ieee_W11numeric_std_X6divmod_i49_V6iszero;
    integer L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j,L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_lc,L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_ls,L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j,L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j_lc,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j_lc;
    L4ieee_W11numeric_std_X6divmod_i49_V4temp.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_X6divmod_i49_V4quot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_X6divmod_i49_V4diff.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_X6divmod_i49_H5denom.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length-1),downto,0,0)), L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.data);
    L4ieee_W11numeric_std_X6divmod_i49_V5carry=enumeration(0);
    L4ieee_W11numeric_std_X6divmod_i49_V6topbit=0;
    L4ieee_W11numeric_std_X6divmod_i49_V6iszero=enumeration(0);
    L4ieee_W11numeric_std_X6divmod_i49_V6iszero=enumeration(1);
    for (L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j=L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->left_bound,L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_ls=L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->index_direction==to?+1:-1,L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_lc=range_to_length<integer>(L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->left_bound,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->index_direction,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->right_bound);L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_lc!=0; L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j+=L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_ls,L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j_lc--) {
      L4ieee_W11numeric_std_X6divmod_i49_V5carry=L4ieee_W11numeric_std_X6divmod_i49_H5denom[L4ieee_W11numeric_std_X6divmod_i49_L457ln_C1j];
      if((L4ieee_W11numeric_std_X6divmod_i49_V5carry!=enumeration(2))) {
        L4ieee_W11numeric_std_X6divmod_i49_V6iszero=enumeration(0);
      }
    }
    if(!op_not(L4ieee_W11numeric_std_X6divmod_i49_V6iszero))
      report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+21,0),L4ieee_W11numeric_std_itn20_lit),enumeration(2));
    L4ieee_W11numeric_std_X6divmod_i49_V4temp=L4ieee_W11numeric_std_X6divmod_i49_C3num;
    L4ieee_W11numeric_std_X6divmod_i49_V4quot=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length)-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length)-1),downto,0,0))->index_type,(L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length,L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length)-1),downto,0,0),enumeration(2));
    L4ieee_W11numeric_std_X6divmod_i49_V6topbit=0;
    for (L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j=(L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length-1),L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_X6divmod_i49_C6xdenom.info->length-1),0); L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j_lc!=0; L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j--,L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j_lc--) {
      if((L4ieee_W11numeric_std_X6divmod_i49_H5denom[L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j]==enumeration(3))) {
        L4ieee_W11numeric_std_X6divmod_i49_V6topbit=L4ieee_W11numeric_std_X6divmod_i49_L459ln_C1j;
        goto exit_7;
      }
    } exit_7:; 
    L4ieee_W11numeric_std_X6divmod_i49_V5carry=enumeration(2);
    for (L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j=(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+1)),L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+1)),0); L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j_lc!=0; L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j--,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j_lc--) {
      if(L4ieee_Q11numeric_std_Y5op_ge_i196 (concat<L4ieee_Q11numeric_std_T8unsigned,enumeration>(L4ieee_Q11numeric_std_T8unsigned(new array_info(L4ieee_Q11numeric_std_I8unsigned_INFO.element_type,L4ieee_Q11numeric_std_I8unsigned_INFO.index_type,0,to,0,0),L4ieee_W11numeric_std_X6divmod_i49_V5carry),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j),downto,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j,0),&L4ieee_W11numeric_std_X6divmod_i49_V4temp[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)])),concat<L4ieee_Q11numeric_std_T8unsigned,enumeration>(array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,0,to,0+0,0),L4ieee_W11numeric_std_itn21_lit),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_X6divmod_i49_V6topbit,downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_H5denom[L4ieee_W11numeric_std_X6divmod_i49_V6topbit])))) {
        array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+1),downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_V4diff[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+1)])=L4ieee_Q11numeric_std_Y8op_minus_i52 (concat<L4ieee_Q11numeric_std_T8unsigned,enumeration>(L4ieee_Q11numeric_std_T8unsigned(new array_info(L4ieee_Q11numeric_std_I8unsigned_INFO.element_type,L4ieee_Q11numeric_std_I8unsigned_INFO.index_type,0,to,0,0),L4ieee_W11numeric_std_X6divmod_i49_V5carry),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j),downto,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j,0),&L4ieee_W11numeric_std_X6divmod_i49_V4temp[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)])),concat<L4ieee_Q11numeric_std_T8unsigned,enumeration>(array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,0,to,0+0,0),L4ieee_W11numeric_std_itn22_lit),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_X6divmod_i49_V6topbit,downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_H5denom[L4ieee_W11numeric_std_X6divmod_i49_V6topbit])));
        if(!(L4ieee_W11numeric_std_X6divmod_i49_V4diff[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+1)]==enumeration(2)))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn23_lit),enumeration(2));
        L4ieee_W11numeric_std_X6divmod_i49_V5carry=L4ieee_W11numeric_std_X6divmod_i49_V4diff[L4ieee_W11numeric_std_X6divmod_i49_V6topbit];
        if((((L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)+1)<=L4ieee_W11numeric_std_X6divmod_i49_V4temp.info->left_bound)) {
          L4ieee_W11numeric_std_X6divmod_i49_V4temp[((L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)+1)]=enumeration(2);
        }
        array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j),downto,L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j,0),&L4ieee_W11numeric_std_X6divmod_i49_V4temp[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)])=array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_W11numeric_std_X6divmod_i49_V6topbit,downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_V4diff[L4ieee_W11numeric_std_X6divmod_i49_V6topbit]);
        L4ieee_W11numeric_std_X6divmod_i49_V4quot[L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j]=enumeration(3);
      } else {
        if(!(L4ieee_W11numeric_std_X6divmod_i49_V5carry==enumeration(2)))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn24_lit),enumeration(2));
        L4ieee_W11numeric_std_X6divmod_i49_V5carry=L4ieee_W11numeric_std_X6divmod_i49_V4temp[(L4ieee_W11numeric_std_X6divmod_i49_V6topbit+L4ieee_W11numeric_std_X6divmod_i49_L461ln_C1j)];
      }
    }
    L4ieee_W11numeric_std_X6divmod_i49_V5xquot=array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-1),downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_V4quot[(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-1)]);
    L4ieee_W11numeric_std_X6divmod_i49_V7xremain=array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-1),downto,0,0),&L4ieee_W11numeric_std_X6divmod_i49_V4temp[(L4ieee_W11numeric_std_X6divmod_i49_C3num.info->length-1)]);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:numeric_std:xsll */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsll_i65(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W11numeric_std_Y4xsll_i65_C3arg,const integer L4ieee_W11numeric_std_Y4xsll_i65_C5count)
{
    integer L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l;
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_W11numeric_std_Y4xsll_i65_H4xarg;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsll_i65_V6result;
    L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l=(L4ieee_W11numeric_std_Y4xsll_i65_C3arg.info->length-1);
    L4ieee_W11numeric_std_Y4xsll_i65_H4xarg.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,0,0)), L4ieee_W11numeric_std_Y4xsll_i65_C3arg.data);
    L4ieee_W11numeric_std_Y4xsll_i65_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y4xsll_i65_V6result=L4ieee_Q14std_logic_1164_T16std_logic_vector(new array_info((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,0,0))->element_type,(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,0,0))->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,0,0),enumeration(2));
    if((L4ieee_W11numeric_std_Y4xsll_i65_C5count<=L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l)) {
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l,downto,L4ieee_W11numeric_std_Y4xsll_i65_C5count,0),&L4ieee_W11numeric_std_Y4xsll_i65_V6result[L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l-L4ieee_W11numeric_std_Y4xsll_i65_C5count),downto,0,0),&L4ieee_W11numeric_std_Y4xsll_i65_H4xarg[(L4ieee_W11numeric_std_Y4xsll_i65_C5arg_l-L4ieee_W11numeric_std_Y4xsll_i65_C5count)]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xsll_i65_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:xsrl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsrl_i71(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W11numeric_std_Y4xsrl_i71_C3arg,const integer L4ieee_W11numeric_std_Y4xsrl_i71_C5count)
{
    integer L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l;
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_W11numeric_std_Y4xsrl_i71_H4xarg;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsrl_i71_V6result;
    L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l=(L4ieee_W11numeric_std_Y4xsrl_i71_C3arg.info->length-1);
    L4ieee_W11numeric_std_Y4xsrl_i71_H4xarg.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,0,0)), L4ieee_W11numeric_std_Y4xsrl_i71_C3arg.data);
    L4ieee_W11numeric_std_Y4xsrl_i71_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y4xsrl_i71_V6result=L4ieee_Q14std_logic_1164_T16std_logic_vector(new array_info((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,0,0))->element_type,(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,0,0))->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,0,0),enumeration(2));
    if((L4ieee_W11numeric_std_Y4xsrl_i71_C5count<=L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l)) {
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l-L4ieee_W11numeric_std_Y4xsrl_i71_C5count),downto,0,0),&L4ieee_W11numeric_std_Y4xsrl_i71_V6result[(L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l-L4ieee_W11numeric_std_Y4xsrl_i71_C5count)])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l,downto,L4ieee_W11numeric_std_Y4xsrl_i71_C5count,0),&L4ieee_W11numeric_std_Y4xsrl_i71_H4xarg[L4ieee_W11numeric_std_Y4xsrl_i71_C5arg_l]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xsrl_i71_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:xsra */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsra_i77(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W11numeric_std_Y4xsra_i77_C3arg,const integer L4ieee_W11numeric_std_Y4xsra_i77_C5count)
{
    integer L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l;
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_W11numeric_std_Y4xsra_i77_H4xarg;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xsra_i77_V6result;
    integer L4ieee_W11numeric_std_Y4xsra_i77_V6xcount;
    L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l=(L4ieee_W11numeric_std_Y4xsra_i77_C3arg.info->length-1);
    L4ieee_W11numeric_std_Y4xsra_i77_H4xarg.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,0,0)), L4ieee_W11numeric_std_Y4xsra_i77_C3arg.data);
    L4ieee_W11numeric_std_Y4xsra_i77_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y4xsra_i77_V6xcount=L4ieee_W11numeric_std_Y4xsra_i77_C5count;
    if(((L4ieee_W11numeric_std_Y4xsra_i77_C3arg.info->length<=1)||(L4ieee_W11numeric_std_Y4xsra_i77_V6xcount==0))) {
      return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xsra_i77_C3arg);
    } else {
      if((L4ieee_W11numeric_std_Y4xsra_i77_V6xcount>L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l)) {
        L4ieee_W11numeric_std_Y4xsra_i77_V6xcount=L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l;
      }
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount),downto,0,0),&L4ieee_W11numeric_std_Y4xsra_i77_V6result[(L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount)])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,L4ieee_W11numeric_std_Y4xsra_i77_V6xcount,0),&L4ieee_W11numeric_std_Y4xsra_i77_H4xarg[L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l]);
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount)+1),0),&L4ieee_W11numeric_std_Y4xsra_i77_V6result[L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l])=L4ieee_Q14std_logic_1164_T16std_logic_vector(new array_info((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount)+1),0))->element_type,(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount)+1),0))->index_type,L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l-L4ieee_W11numeric_std_Y4xsra_i77_V6xcount)+1),0),L4ieee_W11numeric_std_Y4xsra_i77_H4xarg[L4ieee_W11numeric_std_Y4xsra_i77_C5arg_l]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xsra_i77_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:xrol */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xrol_i84(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W11numeric_std_Y4xrol_i84_C3arg,const integer L4ieee_W11numeric_std_Y4xrol_i84_C5count)
{
    integer L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l;
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_W11numeric_std_Y4xrol_i84_H4xarg;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xrol_i84_V6result;
    integer L4ieee_W11numeric_std_Y4xrol_i84_V6countm;
    L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l=(L4ieee_W11numeric_std_Y4xrol_i84_C3arg.info->length-1);
    L4ieee_W11numeric_std_Y4xrol_i84_H4xarg.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l,downto,0,0)), L4ieee_W11numeric_std_Y4xrol_i84_C3arg.data);
    L4ieee_W11numeric_std_Y4xrol_i84_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y4xrol_i84_V6result=L4ieee_W11numeric_std_Y4xrol_i84_H4xarg;
    L4ieee_W11numeric_std_Y4xrol_i84_V6countm=-2147483648LL;
    L4ieee_W11numeric_std_Y4xrol_i84_V6countm=op_mod(L4ieee_W11numeric_std_Y4xrol_i84_C5count,(L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l+1));
    if((L4ieee_W11numeric_std_Y4xrol_i84_V6countm!=0)) {
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l,downto,L4ieee_W11numeric_std_Y4xrol_i84_V6countm,0),&L4ieee_W11numeric_std_Y4xrol_i84_V6result[L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l-L4ieee_W11numeric_std_Y4xrol_i84_V6countm),downto,0,0),&L4ieee_W11numeric_std_Y4xrol_i84_H4xarg[(L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l-L4ieee_W11numeric_std_Y4xrol_i84_V6countm)]);
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xrol_i84_V6countm-1),downto,0,0),&L4ieee_W11numeric_std_Y4xrol_i84_V6result[(L4ieee_W11numeric_std_Y4xrol_i84_V6countm-1)])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l-L4ieee_W11numeric_std_Y4xrol_i84_V6countm)+1),0),&L4ieee_W11numeric_std_Y4xrol_i84_H4xarg[L4ieee_W11numeric_std_Y4xrol_i84_C5arg_l]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xrol_i84_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:xror */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xror_i91(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W11numeric_std_Y4xror_i91_C3arg,const integer L4ieee_W11numeric_std_Y4xror_i91_C5count)
{
    integer L4ieee_W11numeric_std_Y4xror_i91_C5arg_l;
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_W11numeric_std_Y4xror_i91_H4xarg;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W11numeric_std_Y4xror_i91_V6result;
    integer L4ieee_W11numeric_std_Y4xror_i91_V6countm;
    L4ieee_W11numeric_std_Y4xror_i91_C5arg_l=(L4ieee_W11numeric_std_Y4xror_i91_C3arg.info->length-1);
    L4ieee_W11numeric_std_Y4xror_i91_H4xarg.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xror_i91_C5arg_l,downto,0,0)), L4ieee_W11numeric_std_Y4xror_i91_C3arg.data);
    L4ieee_W11numeric_std_Y4xror_i91_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xror_i91_C5arg_l,downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y4xror_i91_V6result=L4ieee_W11numeric_std_Y4xror_i91_H4xarg;
    L4ieee_W11numeric_std_Y4xror_i91_V6countm=-2147483648LL;
    L4ieee_W11numeric_std_Y4xror_i91_V6countm=op_mod(L4ieee_W11numeric_std_Y4xror_i91_C5count,(L4ieee_W11numeric_std_Y4xror_i91_C5arg_l+1));
    if((L4ieee_W11numeric_std_Y4xror_i91_V6countm!=0)) {
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xror_i91_C5arg_l-L4ieee_W11numeric_std_Y4xror_i91_V6countm),downto,0,0),&L4ieee_W11numeric_std_Y4xror_i91_V6result[(L4ieee_W11numeric_std_Y4xror_i91_C5arg_l-L4ieee_W11numeric_std_Y4xror_i91_V6countm)])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xror_i91_C5arg_l,downto,L4ieee_W11numeric_std_Y4xror_i91_V6countm,0),&L4ieee_W11numeric_std_Y4xror_i91_H4xarg[L4ieee_W11numeric_std_Y4xror_i91_C5arg_l]);
      array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W11numeric_std_Y4xror_i91_C5arg_l,downto,((L4ieee_W11numeric_std_Y4xror_i91_C5arg_l-L4ieee_W11numeric_std_Y4xror_i91_V6countm)+1),0),&L4ieee_W11numeric_std_Y4xror_i91_V6result[L4ieee_W11numeric_std_Y4xror_i91_C5arg_l])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_W11numeric_std_Y4xror_i91_V6countm-1),downto,0,0),&L4ieee_W11numeric_std_Y4xror_i91_H4xarg[(L4ieee_W11numeric_std_Y4xror_i91_V6countm-1)]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y4xror_i91_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:unsigned_equal */
enumeration L4ieee_W11numeric_std_Y14unsigned_equal_i98(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y14unsigned_equal_i98_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y14unsigned_equal_i98_C1r)
{
    return (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y14unsigned_equal_i98_C1l)==array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y14unsigned_equal_i98_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:signed_equal */
enumeration L4ieee_W11numeric_std_Y12signed_equal_i101(const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y12signed_equal_i101_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y12signed_equal_i101_C1r)
{
    return (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y12signed_equal_i101_C1l)==array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y12signed_equal_i101_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:unsigned_less */
enumeration L4ieee_W11numeric_std_Y13unsigned_less_i104(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y13unsigned_less_i104_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y13unsigned_less_i104_C1r)
{
    return op_array_lt(array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y13unsigned_less_i104_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y13unsigned_less_i104_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:signed_less */
enumeration L4ieee_W11numeric_std_Y11signed_less_i107(const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y11signed_less_i107_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y11signed_less_i107_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l,L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r;
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,0,to,(L4ieee_W11numeric_std_Y11signed_less_i107_C1l.info->length-1),0)),enumeration(0));
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,0,to,(L4ieee_W11numeric_std_Y11signed_less_i107_C1r.info->length-1),0)),enumeration(0));
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l=L4ieee_W11numeric_std_Y11signed_less_i107_C1l;
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r=L4ieee_W11numeric_std_Y11signed_less_i107_C1r;
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l[0]=L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l[0]);
    L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r[0]=L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r[0]);
    return op_array_lt(array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y11signed_less_i107_V8intern_r));
}
/* Implementation of subprogram :ieee:numeric_std:unsigned_less_or_equal */
enumeration L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112_C1r)
{
    return op_array_le(array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:signed_less_or_equal */
enumeration L4ieee_W11numeric_std_Y20signed_less_or_equal_i115(const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l,L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r;
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,0,to,(L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1l.info->length-1),0)),enumeration(0));
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,0,to,(L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1r.info->length-1),0)),enumeration(0));
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l=L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1l;
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r=L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_C1r;
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l[0]=L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l[0]);
    L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r[0]=L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r[0]);
    return op_array_le(array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W11numeric_std_Y20signed_less_or_equal_i115_V8intern_r));
}
enumeration L4ieee_W11numeric_std_itn25_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,48,49,58,32,65,114,114,97,121,32,69,108,101,109,101,110,116,32,110,111,116,32,105,110,32,123,48,44,49,44,72,44,76,125};
/* Implementation of subprogram :ieee:numeric_std:to_01 */
L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y5to_01_i120(const L4ieee_Q11numeric_std_T6signed &L4ieee_W11numeric_std_Y5to_01_i120_C1s,const enumeration L4ieee_W11numeric_std_Y5to_01_i120_C4xmap)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_W11numeric_std_Y5to_01_i120_V6result;
    enumeration L4ieee_W11numeric_std_Y5to_01_i120_V11bad_element;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_W11numeric_std_Y5to_01_i120_H2xs;
    integer L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i,L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i_lc,L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i,L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i_lc;
    L4ieee_W11numeric_std_Y5to_01_i120_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y5to_01_i120_V11bad_element=enumeration(0);
    L4ieee_W11numeric_std_Y5to_01_i120_H2xs.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),downto,0,0)), L4ieee_W11numeric_std_Y5to_01_i120_C1s.data);
    for (L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i=(L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),0); L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i_lc!=0; L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i--,L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i_lc--) {
      switch(L4ieee_W11numeric_std_Y5to_01_i120_H2xs[L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i]) {
      case 2: case 6: {
        L4ieee_W11numeric_std_Y5to_01_i120_V6result[L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i]=enumeration(2);
       } break;
      case 3: case 7: {
        L4ieee_W11numeric_std_Y5to_01_i120_V6result[L4ieee_W11numeric_std_Y5to_01_i120_L5124ln_C1i]=enumeration(3);
       } break;
      default: {
        L4ieee_W11numeric_std_Y5to_01_i120_V11bad_element=enumeration(1);
       } break;
      }
    }
    if(L4ieee_W11numeric_std_Y5to_01_i120_V11bad_element) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+48,0),L4ieee_W11numeric_std_itn25_lit),enumeration(1));
      for (L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i=(L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_Y5to_01_i120_C1s.info->length-1),0); L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i_lc!=0; L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i--,L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i_lc--) {
        L4ieee_W11numeric_std_Y5to_01_i120_V6result[L4ieee_W11numeric_std_Y5to_01_i120_L5126ln_C1i]=L4ieee_W11numeric_std_Y5to_01_i120_C4xmap;
      }
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y5to_01_i120_V6result);
}
enumeration L4ieee_W11numeric_std_itn26_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,48,49,58,32,65,114,114,97,121,32,69,108,101,109,101,110,116,32,110,111,116,32,105,110,32,123,48,44,49,44,72,44,76,125};
/* Implementation of subprogram :ieee:numeric_std:to_01 */
L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y5to_01_i130(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_W11numeric_std_Y5to_01_i130_C1s,const enumeration L4ieee_W11numeric_std_Y5to_01_i130_C4xmap)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_W11numeric_std_Y5to_01_i130_V6result;
    enumeration L4ieee_W11numeric_std_Y5to_01_i130_V11bad_element;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_W11numeric_std_Y5to_01_i130_H2xs;
    integer L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i,L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i_lc,L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i,L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i_lc;
    L4ieee_W11numeric_std_Y5to_01_i130_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_W11numeric_std_Y5to_01_i130_V11bad_element=enumeration(0);
    L4ieee_W11numeric_std_Y5to_01_i130_H2xs.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),downto,0,0)), L4ieee_W11numeric_std_Y5to_01_i130_C1s.data);
    for (L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i=(L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),0); L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i_lc!=0; L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i--,L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i_lc--) {
      switch(L4ieee_W11numeric_std_Y5to_01_i130_H2xs[L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i]) {
      case 2: case 6: {
        L4ieee_W11numeric_std_Y5to_01_i130_V6result[L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i]=enumeration(2);
       } break;
      case 3: case 7: {
        L4ieee_W11numeric_std_Y5to_01_i130_V6result[L4ieee_W11numeric_std_Y5to_01_i130_L5134ln_C1i]=enumeration(3);
       } break;
      default: {
        L4ieee_W11numeric_std_Y5to_01_i130_V11bad_element=enumeration(1);
       } break;
      }
    }
    if(L4ieee_W11numeric_std_Y5to_01_i130_V11bad_element) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+48,0),L4ieee_W11numeric_std_itn26_lit),enumeration(1));
      for (L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i=(L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i_lc=down_range_to_length<integer>((L4ieee_W11numeric_std_Y5to_01_i130_C1s.info->length-1),0); L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i_lc!=0; L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i--,L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i_lc--) {
        L4ieee_W11numeric_std_Y5to_01_i130_V6result[L4ieee_W11numeric_std_Y5to_01_i130_L5136ln_C1i]=L4ieee_W11numeric_std_Y5to_01_i130_C4xmap;
      }
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y5to_01_i130_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"abs" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_abs_i29(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_abs_i29_C1x)
{
    integer L4ieee_Q11numeric_std_Y6op_abs_i29_C8arg_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y6op_abs_i29_H2xx;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_abs_i29_V6result;
    L4ieee_Q11numeric_std_Y6op_abs_i29_C8arg_left=(L4ieee_Q11numeric_std_Y6op_abs_i29_C1x.info->length-1);
    L4ieee_Q11numeric_std_Y6op_abs_i29_H2xx.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_abs_i29_C8arg_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_abs_i29_C1x.data);
    L4ieee_Q11numeric_std_Y6op_abs_i29_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_abs_i29_C8arg_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y6op_abs_i29_C1x.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y6op_abs_i29_V6result=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_abs_i29_H2xx,enumeration(1));
    if((L4ieee_Q11numeric_std_Y6op_abs_i29_V6result[L4ieee_Q11numeric_std_Y6op_abs_i29_V6result.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_abs_i29_V6result);
    }
    if((L4ieee_Q11numeric_std_Y6op_abs_i29_V6result[L4ieee_Q11numeric_std_Y6op_abs_i29_V6result.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_abs_i29_V6result=L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y6op_abs_i29_V6result);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_abs_i29_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i31(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y8op_minus_i31_C3arg)
{
    integer L4ieee_Q11numeric_std_Y8op_minus_i31_C8arg_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y8op_minus_i31_H4xarg;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01,L4ieee_Q11numeric_std_Y8op_minus_i31_V6result;
    enumeration L4ieee_Q11numeric_std_Y8op_minus_i31_V4cbit;
    integer L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i,L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i_lc;
    L4ieee_Q11numeric_std_Y8op_minus_i31_C8arg_left=(L4ieee_Q11numeric_std_Y8op_minus_i31_C3arg.info->length-1);
    L4ieee_Q11numeric_std_Y8op_minus_i31_H4xarg.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y8op_minus_i31_C8arg_left,downto,0,0)), L4ieee_Q11numeric_std_Y8op_minus_i31_C3arg.data);
    L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y8op_minus_i31_C8arg_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y8op_minus_i31_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y8op_minus_i31_C8arg_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y8op_minus_i31_V4cbit=enumeration(3);
    if((L4ieee_Q11numeric_std_Y8op_minus_i31_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y8op_minus_i31_C3arg,enumeration(1));
    if((L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01[L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01);
    }
    for (L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i=0,L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y8op_minus_i31_V6result.info->left_bound); L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i++,L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i_lc--) {
      L4ieee_Q11numeric_std_Y8op_minus_i31_V6result[L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01[L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i]),L4ieee_Q11numeric_std_Y8op_minus_i31_V4cbit);
      L4ieee_Q11numeric_std_Y8op_minus_i31_V4cbit=L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_Q11numeric_std_Y8op_minus_i31_V4cbit,L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_Q11numeric_std_Y8op_minus_i31_V6xarg01[L4ieee_Q11numeric_std_Y8op_minus_i31_L5150ln_C1i]));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i34(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_plus_i34_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_plus_i34_C1r)
{
    integer L4ieee_Q11numeric_std_Y7op_plus_i34_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01,L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01;
    L4ieee_Q11numeric_std_Y7op_plus_i34_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y7op_plus_i34_C1l.info->length,L4ieee_Q11numeric_std_Y7op_plus_i34_C1r.info->length);
    L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y7op_plus_i34_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y7op_plus_i34_C4size-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y7op_plus_i34_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y7op_plus_i34_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y7op_plus_i34_C1l,L4ieee_Q11numeric_std_Y7op_plus_i34_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01[L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01);
    }
    L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y7op_plus_i34_C1r,L4ieee_Q11numeric_std_Y7op_plus_i34_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01[L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y12add_unsigned_i26 (L4ieee_Q11numeric_std_Y7op_plus_i34_V3l01,L4ieee_Q11numeric_std_Y7op_plus_i34_V3r01,enumeration(2)));
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i37(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_plus_i37_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_plus_i37_C1r)
{
    integer L4ieee_Q11numeric_std_Y7op_plus_i37_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01,L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01;
    L4ieee_Q11numeric_std_Y7op_plus_i37_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y7op_plus_i37_C1l.info->length,L4ieee_Q11numeric_std_Y7op_plus_i37_C1r.info->length);
    L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y7op_plus_i37_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y7op_plus_i37_C4size-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y7op_plus_i37_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y7op_plus_i37_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y7op_plus_i37_C1l,L4ieee_Q11numeric_std_Y7op_plus_i37_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01[L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01);
    }
    L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y7op_plus_i37_C1r,L4ieee_Q11numeric_std_Y7op_plus_i37_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01[L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y10add_signed_i37 (L4ieee_Q11numeric_std_Y7op_plus_i37_V3l01,L4ieee_Q11numeric_std_Y7op_plus_i37_V3r01,enumeration(2)));
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i40(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_plus_i40_C1l,const integer L4ieee_Q11numeric_std_Y7op_plus_i40_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_plus_i34 (L4ieee_Q11numeric_std_Y7op_plus_i40_C1l,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y7op_plus_i40_C1r,L4ieee_Q11numeric_std_Y7op_plus_i40_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_plus_i43(const integer L4ieee_Q11numeric_std_Y7op_plus_i43_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_plus_i43_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_plus_i34 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y7op_plus_i43_C1l,L4ieee_Q11numeric_std_Y7op_plus_i43_C1r.info->length),L4ieee_Q11numeric_std_Y7op_plus_i43_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i49(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_plus_i49_C1l,const integer L4ieee_Q11numeric_std_Y7op_plus_i49_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_plus_i37 (L4ieee_Q11numeric_std_Y7op_plus_i49_C1l,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y7op_plus_i49_C1r,L4ieee_Q11numeric_std_Y7op_plus_i49_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"+" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_plus_i46(const integer L4ieee_Q11numeric_std_Y7op_plus_i46_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_plus_i46_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_plus_i37 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y7op_plus_i46_C1l,L4ieee_Q11numeric_std_Y7op_plus_i46_C1r.info->length),L4ieee_Q11numeric_std_Y7op_plus_i46_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i52(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y8op_minus_i52_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y8op_minus_i52_C1r)
{
    integer L4ieee_Q11numeric_std_Y8op_minus_i52_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01,L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01;
    L4ieee_Q11numeric_std_Y8op_minus_i52_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y8op_minus_i52_C1l.info->length,L4ieee_Q11numeric_std_Y8op_minus_i52_C1r.info->length);
    L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y8op_minus_i52_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y8op_minus_i52_C4size-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y8op_minus_i52_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y8op_minus_i52_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y8op_minus_i52_C1l,L4ieee_Q11numeric_std_Y8op_minus_i52_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01[L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01);
    }
    L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y8op_minus_i52_C1r,L4ieee_Q11numeric_std_Y8op_minus_i52_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01[L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y12add_unsigned_i26 (L4ieee_Q11numeric_std_Y8op_minus_i52_V3l01,L4ieee_Q11numeric_std_Y6op_not_i297 (L4ieee_Q11numeric_std_Y8op_minus_i52_V3r01),enumeration(3)));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i55(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y8op_minus_i55_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y8op_minus_i55_C1r)
{
    integer L4ieee_Q11numeric_std_Y8op_minus_i55_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01,L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01;
    L4ieee_Q11numeric_std_Y8op_minus_i55_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y8op_minus_i55_C1l.info->length,L4ieee_Q11numeric_std_Y8op_minus_i55_C1r.info->length);
    L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y8op_minus_i55_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y8op_minus_i55_C4size-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y8op_minus_i55_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y8op_minus_i55_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y8op_minus_i55_C1l,L4ieee_Q11numeric_std_Y8op_minus_i55_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01[L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01);
    }
    L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y8op_minus_i55_C1r,L4ieee_Q11numeric_std_Y8op_minus_i55_C4size),enumeration(1));
    if((L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01[L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01.info->left_bound]==enumeration(1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y10add_signed_i37 (L4ieee_Q11numeric_std_Y8op_minus_i55_V3l01,L4ieee_Q11numeric_std_Y6op_not_i314 (L4ieee_Q11numeric_std_Y8op_minus_i55_V3r01),enumeration(3)));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i58(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y8op_minus_i58_C1l,const integer L4ieee_Q11numeric_std_Y8op_minus_i58_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i52 (L4ieee_Q11numeric_std_Y8op_minus_i58_C1l,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y8op_minus_i58_C1r,L4ieee_Q11numeric_std_Y8op_minus_i58_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y8op_minus_i61(const integer L4ieee_Q11numeric_std_Y8op_minus_i61_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y8op_minus_i61_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i52 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y8op_minus_i61_C1l,L4ieee_Q11numeric_std_Y8op_minus_i61_C1r.info->length),L4ieee_Q11numeric_std_Y8op_minus_i61_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i64(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y8op_minus_i64_C1l,const integer L4ieee_Q11numeric_std_Y8op_minus_i64_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i55 (L4ieee_Q11numeric_std_Y8op_minus_i64_C1l,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y8op_minus_i64_C1r,L4ieee_Q11numeric_std_Y8op_minus_i64_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"-" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y8op_minus_i67(const integer L4ieee_Q11numeric_std_Y8op_minus_i67_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y8op_minus_i67_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y8op_minus_i55 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y8op_minus_i67_C1l,L4ieee_Q11numeric_std_Y8op_minus_i67_C1r.info->length),L4ieee_Q11numeric_std_Y8op_minus_i67_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i70(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_mult_i70_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_mult_i70_C1r)
{
    integer L4ieee_Q11numeric_std_Y7op_mult_i70_C6l_left,L4ieee_Q11numeric_std_Y7op_mult_i70_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxl,L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl,L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr,L4ieee_Q11numeric_std_Y7op_mult_i70_V6result,L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval;
    integer L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i,L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i_lc;
    L4ieee_Q11numeric_std_Y7op_mult_i70_C6l_left=(L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y7op_mult_i70_C6r_left=(L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i70_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.data);
    L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i70_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.data);
    L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i70_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i70_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i70_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i70_V6result=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0))->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0),enumeration(2));
    L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y7op_mult_i70_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl[L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr[L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y7op_mult_i70_V6result=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0))->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i70_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i70_C1r.info->length)-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_mult_i70_V6result);
    }
    L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval=L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y7op_mult_i70_V2xr,L4ieee_Q11numeric_std_Y7op_mult_i70_V6result.info->length);
    for (L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i=0,L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y7op_mult_i70_C6l_left); L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i++,L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i_lc--) {
      if((L4ieee_Q11numeric_std_Y7op_mult_i70_V2xl[L4ieee_Q11numeric_std_Y7op_mult_i70_L5211ln_C1i]==enumeration(3))) {
        L4ieee_Q11numeric_std_Y7op_mult_i70_V6result=L4ieee_Q11numeric_std_Y7op_plus_i34 (L4ieee_Q11numeric_std_Y7op_mult_i70_V6result,L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval);
      }
      L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval=L4ieee_Q11numeric_std_Y10shift_left_i250 (L4ieee_Q11numeric_std_Y7op_mult_i70_V5adval,1);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_mult_i70_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i73(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_mult_i73_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_mult_i73_C1r)
{
    integer L4ieee_Q11numeric_std_Y7op_mult_i73_C6l_left,L4ieee_Q11numeric_std_Y7op_mult_i73_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxl,L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl,L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr,L4ieee_Q11numeric_std_Y7op_mult_i73_V6result,L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval;
    enumeration L4ieee_Q11numeric_std_Y7op_mult_i73_V4invt;
    integer L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i,L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i_lc;
    L4ieee_Q11numeric_std_Y7op_mult_i73_C6l_left=(L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y7op_mult_i73_C6r_left=(L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i73_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.data);
    L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i73_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.data);
    L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i73_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_mult_i73_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V6result=L4ieee_Q11numeric_std_T6signed(new array_info((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0))->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0),enumeration(2));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V4invt=enumeration(2);
    if(((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y7op_mult_i73_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl[L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr[L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y7op_mult_i73_V6result=L4ieee_Q11numeric_std_T6signed(new array_info((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0))->index_type,((L4ieee_Q11numeric_std_Y7op_mult_i73_C1l.info->length+L4ieee_Q11numeric_std_Y7op_mult_i73_C1r.info->length)-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_mult_i73_V6result);
    }
    L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval=L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y7op_mult_i73_V2xr,L4ieee_Q11numeric_std_Y7op_mult_i73_V6result.info->length);
    if((L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl[L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval=L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval);
      L4ieee_Q11numeric_std_Y7op_mult_i73_V4invt=enumeration(3);
    }
    for (L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i=0,L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y7op_mult_i73_C6l_left); L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i++,L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i_lc--) {
      if((L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q11numeric_std_Y7op_mult_i73_V4invt,L4ieee_Q11numeric_std_Y7op_mult_i73_V2xl[L4ieee_Q11numeric_std_Y7op_mult_i73_L5225ln_C1i])==enumeration(3))) {
        L4ieee_Q11numeric_std_Y7op_mult_i73_V6result=L4ieee_Q11numeric_std_Y7op_plus_i37 (L4ieee_Q11numeric_std_Y7op_mult_i73_V6result,L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval);
      }
      L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval=L4ieee_Q11numeric_std_Y10shift_left_i256 (L4ieee_Q11numeric_std_Y7op_mult_i73_V5adval,1);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_mult_i73_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i76(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_mult_i76_C1l,const integer L4ieee_Q11numeric_std_Y7op_mult_i76_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_mult_i70 (L4ieee_Q11numeric_std_Y7op_mult_i76_C1l,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y7op_mult_i76_C1r,L4ieee_Q11numeric_std_Y7op_mult_i76_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_mult_i79(const integer L4ieee_Q11numeric_std_Y7op_mult_i79_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_mult_i79_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_mult_i70 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y7op_mult_i79_C1l,L4ieee_Q11numeric_std_Y7op_mult_i79_C1r.info->length),L4ieee_Q11numeric_std_Y7op_mult_i79_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i82(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_mult_i82_C1l,const integer L4ieee_Q11numeric_std_Y7op_mult_i82_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_mult_i73 (L4ieee_Q11numeric_std_Y7op_mult_i82_C1l,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y7op_mult_i82_C1r,L4ieee_Q11numeric_std_Y7op_mult_i82_C1l.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"*" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_mult_i85(const integer L4ieee_Q11numeric_std_Y7op_mult_i85_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_mult_i85_C1r)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_mult_i73 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y7op_mult_i85_C1l,L4ieee_Q11numeric_std_Y7op_mult_i85_C1r.info->length),L4ieee_Q11numeric_std_Y7op_mult_i85_C1r));
}
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i88(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_div_i88_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_div_i88_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i88_C6l_left,L4ieee_Q11numeric_std_Y6op_div_i88_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y6op_div_i88_H3xxl,L4ieee_Q11numeric_std_Y6op_div_i88_H3xxr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i88_V2xl,L4ieee_Q11numeric_std_Y6op_div_i88_V2xr,L4ieee_Q11numeric_std_Y6op_div_i88_V7fremain,L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot;
    L4ieee_Q11numeric_std_Y6op_div_i88_C6l_left=(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_div_i88_C6r_left=(L4ieee_Q11numeric_std_Y6op_div_i88_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_div_i88_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i88_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_div_i88_C1l.data);
    L4ieee_Q11numeric_std_Y6op_div_i88_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i88_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_div_i88_C1r.data);
    L4ieee_Q11numeric_std_Y6op_div_i88_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i88_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i88_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i88_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i88_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_div_i88_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y6op_div_i88_V2xl=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_div_i88_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y6op_div_i88_V2xr=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_div_i88_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y6op_div_i88_V2xl[L4ieee_Q11numeric_std_Y6op_div_i88_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_div_i88_V2xr[L4ieee_Q11numeric_std_Y6op_div_i88_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_div_i88_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_div_i88_V2xl,L4ieee_Q11numeric_std_Y6op_div_i88_V2xr,L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot,L4ieee_Q11numeric_std_Y6op_div_i88_V7fremain);
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_div_i88_V5fquot);
}
enumeration L4ieee_W11numeric_std_itn27_lit[]={2};
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i91(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_div_i91_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_div_i91_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i91_C6l_left,L4ieee_Q11numeric_std_Y6op_div_i91_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y6op_div_i91_H3xxl,L4ieee_Q11numeric_std_Y6op_div_i91_H3xxr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i91_V2xl,L4ieee_Q11numeric_std_Y6op_div_i91_V2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i91_V7fremain,L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot,L4ieee_Q11numeric_std_Y6op_div_i91_V4xnum,L4ieee_Q11numeric_std_Y6op_div_i91_V6xdenom;
    enumeration L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg;
    L4ieee_Q11numeric_std_Y6op_div_i91_C6l_left=(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_div_i91_C6r_left=(L4ieee_Q11numeric_std_Y6op_div_i91_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_div_i91_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i91_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_div_i91_C1l.data);
    L4ieee_Q11numeric_std_Y6op_div_i91_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i91_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_div_i91_C1r.data);
    L4ieee_Q11numeric_std_Y6op_div_i91_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i91_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_div_i91_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V4xnum.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V6xdenom.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1r.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg=enumeration(0);
    if(((L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_div_i91_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y6op_div_i91_V2xl=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_div_i91_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y6op_div_i91_V2xr=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_div_i91_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y6op_div_i91_V2xl[L4ieee_Q11numeric_std_Y6op_div_i91_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_div_i91_V2xr[L4ieee_Q11numeric_std_Y6op_div_i91_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_div_i91_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot));
    }
    if((L4ieee_Q11numeric_std_Y6op_div_i91_V2xl[L4ieee_Q11numeric_std_Y6op_div_i91_V2xl.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_div_i91_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y6op_div_i91_V2xl));
      L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg=enumeration(1);
    } else {
      L4ieee_Q11numeric_std_Y6op_div_i91_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_div_i91_V2xl);
    }
    if((L4ieee_Q11numeric_std_Y6op_div_i91_V2xr[L4ieee_Q11numeric_std_Y6op_div_i91_V2xr.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_div_i91_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y6op_div_i91_V2xr));
      L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg=op_not(L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg);
    } else {
      L4ieee_Q11numeric_std_Y6op_div_i91_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_div_i91_V2xr);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_div_i91_V4xnum,L4ieee_Q11numeric_std_Y6op_div_i91_V6xdenom,L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot,L4ieee_Q11numeric_std_Y6op_div_i91_V7fremain);
    if(L4ieee_Q11numeric_std_Y6op_div_i91_V4qneg) {
      L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot=L4ieee_Q11numeric_std_Y8op_minus_i52 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,0,to,0+0,0),L4ieee_W11numeric_std_itn27_lit),L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_div_i91_V5fquot));
}
enumeration L4ieee_W11numeric_std_itn28_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,47,34,34,58,32,81,117,111,116,105,101,110,116,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i94(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_div_i94_C1l,const integer L4ieee_Q11numeric_std_Y6op_div_i94_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i94_V4quot,L4ieee_Q11numeric_std_Y6op_div_i94_V2xr;
    L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length,L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_div_i94_C1r));
    L4ieee_Q11numeric_std_Y6op_div_i94_V4quot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i94_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i94_V2xr=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_div_i94_C1r,L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length);
    L4ieee_Q11numeric_std_Y6op_div_i94_V4quot=L4ieee_Q11numeric_std_Y6op_div_i88 (L4ieee_Q11numeric_std_Y6op_div_i94_C1l,L4ieee_Q11numeric_std_Y6op_div_i94_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length>L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_div_i94_V4quot[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_div_i94_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i94_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W11numeric_std_itn28_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_div_i94_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i94_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn29_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,47,34,34,58,32,81,117,111,116,105,101,110,116,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i97(const integer L4ieee_Q11numeric_std_Y6op_div_i97_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_div_i97_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_div_i97_V4quot,L4ieee_Q11numeric_std_Y6op_div_i97_V2xl;
    L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_div_i97_C1l),L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_div_i97_V4quot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i97_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i97_V2xl=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_div_i97_C1l,L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length);
    L4ieee_Q11numeric_std_Y6op_div_i97_V4quot=L4ieee_Q11numeric_std_Y6op_div_i88 (L4ieee_Q11numeric_std_Y6op_div_i97_V2xl,L4ieee_Q11numeric_std_Y6op_div_i97_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length>L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_div_i97_V4quot[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_div_i97_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i97_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W11numeric_std_itn29_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_div_i97_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i97_C1r.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn30_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,47,34,34,58,32,81,117,111,116,105,101,110,116,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i100(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_div_i100_C1l,const integer L4ieee_Q11numeric_std_Y6op_div_i100_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i100_V4quot,L4ieee_Q11numeric_std_Y6op_div_i100_V2xr;
    L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length,L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_div_i100_C1r));
    L4ieee_Q11numeric_std_Y6op_div_i100_V4quot.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i100_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i100_V2xr=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_div_i100_C1r,L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length);
    L4ieee_Q11numeric_std_Y6op_div_i100_V4quot=L4ieee_Q11numeric_std_Y6op_div_i91 (L4ieee_Q11numeric_std_Y6op_div_i100_C1l,L4ieee_Q11numeric_std_Y6op_div_i100_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length>L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_div_i100_V4quot[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_div_i100_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i100_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length,0),L4ieee_Q11numeric_std_Y6op_div_i100_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W11numeric_std_itn30_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_div_i100_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i100_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn31_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,47,34,34,58,32,81,117,111,116,105,101,110,116,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"/" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i103(const integer L4ieee_Q11numeric_std_Y6op_div_i103_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_div_i103_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_div_i103_V4quot,L4ieee_Q11numeric_std_Y6op_div_i103_V2xl;
    L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_div_i103_C1l),L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_div_i103_V4quot.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i103_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_div_i103_V2xl=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_div_i103_C1l,L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length);
    L4ieee_Q11numeric_std_Y6op_div_i103_V4quot=L4ieee_Q11numeric_std_Y6op_div_i91 (L4ieee_Q11numeric_std_Y6op_div_i103_V2xl,L4ieee_Q11numeric_std_Y6op_div_i103_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length>L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_div_i103_V4quot[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_div_i103_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i103_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length,0),L4ieee_Q11numeric_std_Y6op_div_i103_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W11numeric_std_itn31_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_div_i103_V4quot[(L4ieee_Q11numeric_std_Y6op_div_i103_C1r.info->length-1)]));
}
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i106(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_rem_i106_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_rem_i106_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i106_C6l_left,L4ieee_Q11numeric_std_Y6op_rem_i106_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxl,L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl,L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr,L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain,L4ieee_Q11numeric_std_Y6op_rem_i106_V5fquot;
    L4ieee_Q11numeric_std_Y6op_rem_i106_C6l_left=(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_rem_i106_C6r_left=(L4ieee_Q11numeric_std_Y6op_rem_i106_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i106_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.data);
    L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i106_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_rem_i106_C1r.data);
    L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i106_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i106_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i106_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_rem_i106_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_rem_i106_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl[L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr[L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i106_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_rem_i106_V2xl,L4ieee_Q11numeric_std_Y6op_rem_i106_V2xr,L4ieee_Q11numeric_std_Y6op_rem_i106_V5fquot,L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain);
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_rem_i106_V7fremain);
}
enumeration L4ieee_W11numeric_std_itn32_lit[]={2};
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i109(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_rem_i109_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_rem_i109_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i109_C6l_left,L4ieee_Q11numeric_std_Y6op_rem_i109_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxl,L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain,L4ieee_Q11numeric_std_Y6op_rem_i109_V5fquot,L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum,L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom;
    enumeration L4ieee_Q11numeric_std_Y6op_rem_i109_V4rneg;
    L4ieee_Q11numeric_std_Y6op_rem_i109_C6l_left=(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_rem_i109_C6r_left=(L4ieee_Q11numeric_std_Y6op_rem_i109_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i109_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.data);
    L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_rem_i109_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_rem_i109_C1r.data);
    L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i109_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1r.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i109_V4rneg=enumeration(0);
    if(((L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_rem_i109_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxl,enumeration(1)));
    L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_rem_i109_H3xxr,enumeration(1)));
    if(((L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum[L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom[L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i109_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain));
    }
    if((L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum[L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum)));
      L4ieee_Q11numeric_std_Y6op_rem_i109_V4rneg=enumeration(1);
    } else {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum);
    }
    if((L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom[L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom)));
    } else {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_rem_i109_V4xnum,L4ieee_Q11numeric_std_Y6op_rem_i109_V6xdenom,L4ieee_Q11numeric_std_Y6op_rem_i109_V5fquot,L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain);
    if(L4ieee_Q11numeric_std_Y6op_rem_i109_V4rneg) {
      L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain=L4ieee_Q11numeric_std_Y8op_minus_i52 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,0,to,0+0,0),L4ieee_W11numeric_std_itn32_lit),L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_rem_i109_V7fremain));
}
enumeration L4ieee_W11numeric_std_itn33_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,114,101,109,34,34,58,32,82,101,109,97,105,110,100,101,114,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i112(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_rem_i112_C1l,const integer L4ieee_Q11numeric_std_Y6op_rem_i112_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem,L4ieee_Q11numeric_std_Y6op_rem_i112_V2xr;
    L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length,L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_rem_i112_C1r));
    L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i112_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i112_V2xr=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_rem_i112_C1r,L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length);
    L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem=L4ieee_Q11numeric_std_Y6op_rem_i106 (L4ieee_Q11numeric_std_Y6op_rem_i112_C1l,L4ieee_Q11numeric_std_Y6op_rem_i112_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length>L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i112_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn33_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_rem_i112_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i112_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn34_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,114,101,109,34,34,58,32,82,101,109,97,105,110,100,101,114,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i115(const integer L4ieee_Q11numeric_std_Y6op_rem_i115_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_rem_i115_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem,L4ieee_Q11numeric_std_Y6op_rem_i115_V2xl;
    L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_rem_i115_C1l),L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i115_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i115_V2xl=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_rem_i115_C1l,L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length);
    L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem=L4ieee_Q11numeric_std_Y6op_rem_i106 (L4ieee_Q11numeric_std_Y6op_rem_i115_V2xl,L4ieee_Q11numeric_std_Y6op_rem_i115_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length>L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i115_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn34_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_rem_i115_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i115_C1r.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn35_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,114,101,109,34,34,58,32,82,101,109,97,105,110,100,101,114,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i118(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_rem_i118_C1l,const integer L4ieee_Q11numeric_std_Y6op_rem_i118_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem,L4ieee_Q11numeric_std_Y6op_rem_i118_V2xr;
    L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length,L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_rem_i118_C1r));
    L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i118_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i118_V2xr=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_rem_i118_C1r,L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length);
    L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem=L4ieee_Q11numeric_std_Y6op_rem_i109 (L4ieee_Q11numeric_std_Y6op_rem_i118_C1l,L4ieee_Q11numeric_std_Y6op_rem_i118_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length>L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i118_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length,0),L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn35_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_rem_i118_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i118_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn36_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,114,101,109,34,34,58,32,82,101,109,97,105,110,100,101,114,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"rem" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i121(const integer L4ieee_Q11numeric_std_Y6op_rem_i121_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_rem_i121_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem,L4ieee_Q11numeric_std_Y6op_rem_i121_V2xl;
    L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_rem_i121_C1l),L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i121_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_rem_i121_V2xl=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_rem_i121_C1l,L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length);
    L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem=L4ieee_Q11numeric_std_Y6op_rem_i109 (L4ieee_Q11numeric_std_Y6op_rem_i121_V2xl,L4ieee_Q11numeric_std_Y6op_rem_i121_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length>L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i121_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length,0),L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn36_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_rem_i121_V4xrem[(L4ieee_Q11numeric_std_Y6op_rem_i121_C1r.info->length-1)]));
}
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i124(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_mod_i124_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_mod_i124_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i124_C6l_left,L4ieee_Q11numeric_std_Y6op_mod_i124_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxl,L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl,L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr,L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain,L4ieee_Q11numeric_std_Y6op_mod_i124_V5fquot;
    L4ieee_Q11numeric_std_Y6op_mod_i124_C6l_left=(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_mod_i124_C6r_left=(L4ieee_Q11numeric_std_Y6op_mod_i124_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i124_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.data);
    L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i124_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_mod_i124_C1r.data);
    L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i124_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i124_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i124_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_mod_i124_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y6op_mod_i124_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl[L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr[L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i124_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_mod_i124_V2xl,L4ieee_Q11numeric_std_Y6op_mod_i124_V2xr,L4ieee_Q11numeric_std_Y6op_mod_i124_V5fquot,L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain);
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_mod_i124_V7fremain);
}
enumeration L4ieee_W11numeric_std_itn37_lit[]={2};
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i127(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_mod_i127_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_mod_i127_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i127_C6l_left,L4ieee_Q11numeric_std_Y6op_mod_i127_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxl,L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl,L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain,L4ieee_Q11numeric_std_Y6op_mod_i127_V5fquot,L4ieee_Q11numeric_std_Y6op_mod_i127_V4xnum,L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom;
    enumeration L4ieee_Q11numeric_std_Y6op_mod_i127_V4rneg;
    L4ieee_Q11numeric_std_Y6op_mod_i127_C6l_left=(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y6op_mod_i127_C6r_left=(L4ieee_Q11numeric_std_Y6op_mod_i127_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i127_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.data);
    L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i127_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y6op_mod_i127_C1r.data);
    L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i127_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_mod_i127_C6r_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V5fquot.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V4xnum.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1r.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V4rneg=enumeration(0);
    if(((L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y6op_mod_i127_C1r.info->length<1))) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxl,enumeration(1));
    L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y6op_mod_i127_H3xxr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl[L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr[L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr.info->left_bound]==enumeration(1)))) {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->length-1),downto,0,0),enumeration(1));
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain));
    }
    if((L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl[L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl));
    } else {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V4xnum=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_mod_i127_V2xl);
    }
    if((L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr[L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr.info->left_bound]==enumeration(3))) {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr));
      L4ieee_Q11numeric_std_Y6op_mod_i127_V4rneg=enumeration(1);
    } else {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_mod_i127_V2xr);
    }
    L4ieee_W11numeric_std_X6divmod_i49 (L4ieee_Q11numeric_std_Y6op_mod_i127_V4xnum,L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom,L4ieee_Q11numeric_std_Y6op_mod_i127_V5fquot,L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain);
    if((L4ieee_Q11numeric_std_Y6op_mod_i127_V4rneg&&(L4ieee_Q11numeric_std_Y6op_mod_i127_C1l[L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->left_bound]==enumeration(3)))) {
      L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain=L4ieee_Q11numeric_std_Y8op_minus_i52 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,0,to,0+0,0),L4ieee_W11numeric_std_itn37_lit),L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain);
    } else {
      if(L4ieee_Q11numeric_std_Y6op_mod_i127_V4rneg) {
        L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain=L4ieee_Q11numeric_std_Y8op_minus_i52 (L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain,L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom);
      } else {
        if((L4ieee_Q11numeric_std_Y6op_mod_i127_C1l[L4ieee_Q11numeric_std_Y6op_mod_i127_C1l.info->left_bound]==enumeration(3))) {
          L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain=L4ieee_Q11numeric_std_Y8op_minus_i52 (L4ieee_Q11numeric_std_Y6op_mod_i127_V6xdenom,L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain);
        }
      }
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_mod_i127_V7fremain));
}
enumeration L4ieee_W11numeric_std_itn38_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,109,111,100,34,34,58,32,77,111,100,117,108,117,115,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i130(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_mod_i130_C1l,const integer L4ieee_Q11numeric_std_Y6op_mod_i130_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem,L4ieee_Q11numeric_std_Y6op_mod_i130_V2xr;
    L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length,L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_mod_i130_C1r));
    L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i130_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i130_V2xr=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_mod_i130_C1r,L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length);
    L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem=L4ieee_Q11numeric_std_Y6op_mod_i124 (L4ieee_Q11numeric_std_Y6op_mod_i130_C1l,L4ieee_Q11numeric_std_Y6op_mod_i130_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length>L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i130_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W11numeric_std_itn38_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_mod_i130_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i130_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn39_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,109,111,100,34,34,58,32,77,111,100,117,108,117,115,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i133(const integer L4ieee_Q11numeric_std_Y6op_mod_i133_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_mod_i133_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem,L4ieee_Q11numeric_std_Y6op_mod_i133_V2xl;
    L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y6op_mod_i133_C1l),L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i133_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i133_V2xl=L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y6op_mod_i133_C1l,L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length);
    L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem=L4ieee_Q11numeric_std_Y6op_mod_i124 (L4ieee_Q11numeric_std_Y6op_mod_i133_V2xl,L4ieee_Q11numeric_std_Y6op_mod_i133_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length>L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i232 (array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length-1)]),L4ieee_Q11numeric_std_T8unsigned(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i133_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length,0),enumeration(2))))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W11numeric_std_itn39_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_mod_i133_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i133_C1r.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn40_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,109,111,100,34,34,58,32,77,111,100,117,108,117,115,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i136(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_mod_i136_C1l,const integer L4ieee_Q11numeric_std_Y6op_mod_i136_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem,L4ieee_Q11numeric_std_Y6op_mod_i136_V2xr;
    L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length,L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_mod_i136_C1r));
    L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i136_V2xr.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i136_V2xr=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_mod_i136_C1r,L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length);
    L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem=L4ieee_Q11numeric_std_Y6op_mod_i127 (L4ieee_Q11numeric_std_Y6op_mod_i136_C1l,L4ieee_Q11numeric_std_Y6op_mod_i136_V2xr);
    if((((L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length>L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length)&&(L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length,0),&L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i136_C8r_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length,0),L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W11numeric_std_itn40_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_mod_i136_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i136_C1l.info->length-1)]));
}
enumeration L4ieee_W11numeric_std_itn41_lit[]={78,117,109,101,114,105,99,95,115,116,100,46,34,34,109,111,100,34,34,58,32,77,111,100,117,108,117,115,32,84,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:"mod" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i139(const integer L4ieee_Q11numeric_std_Y6op_mod_i139_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_mod_i139_C1r)
{
    integer L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem,L4ieee_Q11numeric_std_Y6op_mod_i139_V2xl;
    L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y6op_mod_i139_C1l),L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length);
    L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i139_V2xl.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_mod_i139_V2xl=L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y6op_mod_i139_C1l,L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length);
    L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem=L4ieee_Q11numeric_std_Y6op_mod_i127 (L4ieee_Q11numeric_std_Y6op_mod_i139_V2xl,L4ieee_Q11numeric_std_Y6op_mod_i139_C1r);
    if((((L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length>L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length)&&(L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem[0]!=enumeration(1)))&&L4ieee_Q11numeric_std_Y5op_ne_i235 (array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length,0),&L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length-1)]),L4ieee_Q11numeric_std_T6signed(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i139_C8l_length-1),downto,L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length,0),L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length-1)])))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W11numeric_std_itn41_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length-1),downto,0,0),&L4ieee_Q11numeric_std_Y6op_mod_i139_V4xrem[(L4ieee_Q11numeric_std_Y6op_mod_i139_C1r.info->length-1)]));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i142(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_gt_i142_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_gt_i142_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i142_C6l_left,L4ieee_Q11numeric_std_Y5op_gt_i142_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_gt_i142_H2xl,L4ieee_Q11numeric_std_Y5op_gt_i142_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_gt_i142_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01,L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01;
    L4ieee_Q11numeric_std_Y5op_gt_i142_C6l_left=(L4ieee_Q11numeric_std_Y5op_gt_i142_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i142_C6r_left=(L4ieee_Q11numeric_std_Y5op_gt_i142_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i142_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i142_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i142_C1l.data);
    L4ieee_Q11numeric_std_Y5op_gt_i142_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i142_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i142_C1r.data);
    L4ieee_Q11numeric_std_Y5op_gt_i142_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_gt_i142_C1l.info->length,L4ieee_Q11numeric_std_Y5op_gt_i142_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i142_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i142_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_gt_i142_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_gt_i142_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_gt_i142_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_gt_i142_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01[L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01[L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return op_not(L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_gt_i142_V3l01,L4ieee_Q11numeric_std_Y5op_gt_i142_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_gt_i142_V3r01,L4ieee_Q11numeric_std_Y5op_gt_i142_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i145(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_gt_i145_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_gt_i145_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i145_C6l_left,L4ieee_Q11numeric_std_Y5op_gt_i145_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_gt_i145_H2xl,L4ieee_Q11numeric_std_Y5op_gt_i145_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_gt_i145_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01,L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01;
    L4ieee_Q11numeric_std_Y5op_gt_i145_C6l_left=(L4ieee_Q11numeric_std_Y5op_gt_i145_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i145_C6r_left=(L4ieee_Q11numeric_std_Y5op_gt_i145_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i145_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i145_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i145_C1l.data);
    L4ieee_Q11numeric_std_Y5op_gt_i145_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i145_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i145_C1r.data);
    L4ieee_Q11numeric_std_Y5op_gt_i145_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_gt_i145_C1l.info->length,L4ieee_Q11numeric_std_Y5op_gt_i145_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i145_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i145_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_gt_i145_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_gt_i145_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_gt_i145_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_gt_i145_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01[L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01[L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return op_not(L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_gt_i145_V3l01,L4ieee_Q11numeric_std_Y5op_gt_i145_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_gt_i145_V3r01,L4ieee_Q11numeric_std_Y5op_gt_i145_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i148(const integer L4ieee_Q11numeric_std_Y5op_gt_i148_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_gt_i148_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i148_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_gt_i148_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01;
    L4ieee_Q11numeric_std_Y5op_gt_i148_C6r_left=(L4ieee_Q11numeric_std_Y5op_gt_i148_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i148_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i148_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i148_C1r.data);
    L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i148_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_gt_i148_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_gt_i148_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01[L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_gt_i148_C1l)>L4ieee_Q11numeric_std_Y5op_gt_i148_C1r.info->length)) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_gt_i148_C1l,L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_gt_i148_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i151(const integer L4ieee_Q11numeric_std_Y5op_gt_i151_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_gt_i151_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i151_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_gt_i151_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01;
    L4ieee_Q11numeric_std_Y5op_gt_i151_C6r_left=(L4ieee_Q11numeric_std_Y5op_gt_i151_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i151_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i151_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i151_C1r.data);
    L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i151_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_gt_i151_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_gt_i151_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01[L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_gt_i151_C1l)>L4ieee_Q11numeric_std_Y5op_gt_i151_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_gt_i151_C1l>0);
    }
    return op_not(L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_gt_i151_C1l,L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_gt_i151_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i154(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_gt_i154_C1l,const integer L4ieee_Q11numeric_std_Y5op_gt_i154_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i154_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_gt_i154_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01;
    L4ieee_Q11numeric_std_Y5op_gt_i154_C6l_left=(L4ieee_Q11numeric_std_Y5op_gt_i154_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i154_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i154_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i154_C1l.data);
    L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i154_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_gt_i154_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_gt_i154_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01[L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_gt_i154_C1r)>L4ieee_Q11numeric_std_Y5op_gt_i154_C1l.info->length)) {
      return enumeration(0);
    }
    return op_not(L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_gt_i154_C1r,L4ieee_Q11numeric_std_Y5op_gt_i154_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:">" */
enumeration L4ieee_Q11numeric_std_Y5op_gt_i157(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_gt_i157_C1l,const integer L4ieee_Q11numeric_std_Y5op_gt_i157_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_gt_i157_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_gt_i157_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01;
    L4ieee_Q11numeric_std_Y5op_gt_i157_C6l_left=(L4ieee_Q11numeric_std_Y5op_gt_i157_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_gt_i157_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i157_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_gt_i157_C1l.data);
    L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_gt_i157_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_gt_i157_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_gt_i157_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01[L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_gt_i157_C1r)>L4ieee_Q11numeric_std_Y5op_gt_i157_C1l.info->length)) {
      return (0>L4ieee_Q11numeric_std_Y5op_gt_i157_C1r);
    }
    return op_not(L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_gt_i157_C1r,L4ieee_Q11numeric_std_Y5op_gt_i157_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i160(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_lt_i160_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_lt_i160_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i160_C6l_left,L4ieee_Q11numeric_std_Y5op_lt_i160_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_lt_i160_H2xl,L4ieee_Q11numeric_std_Y5op_lt_i160_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_lt_i160_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01,L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01;
    L4ieee_Q11numeric_std_Y5op_lt_i160_C6l_left=(L4ieee_Q11numeric_std_Y5op_lt_i160_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i160_C6r_left=(L4ieee_Q11numeric_std_Y5op_lt_i160_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i160_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i160_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i160_C1l.data);
    L4ieee_Q11numeric_std_Y5op_lt_i160_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i160_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i160_C1r.data);
    L4ieee_Q11numeric_std_Y5op_lt_i160_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_lt_i160_C1l.info->length,L4ieee_Q11numeric_std_Y5op_lt_i160_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i160_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i160_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_lt_i160_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_lt_i160_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_lt_i160_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_lt_i160_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01[L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01[L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_lt_i160_V3l01,L4ieee_Q11numeric_std_Y5op_lt_i160_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_lt_i160_V3r01,L4ieee_Q11numeric_std_Y5op_lt_i160_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i163(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_lt_i163_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_lt_i163_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i163_C6l_left,L4ieee_Q11numeric_std_Y5op_lt_i163_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_lt_i163_H2xl,L4ieee_Q11numeric_std_Y5op_lt_i163_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_lt_i163_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01,L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01;
    L4ieee_Q11numeric_std_Y5op_lt_i163_C6l_left=(L4ieee_Q11numeric_std_Y5op_lt_i163_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i163_C6r_left=(L4ieee_Q11numeric_std_Y5op_lt_i163_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i163_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i163_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i163_C1l.data);
    L4ieee_Q11numeric_std_Y5op_lt_i163_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i163_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i163_C1r.data);
    L4ieee_Q11numeric_std_Y5op_lt_i163_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_lt_i163_C1l.info->length,L4ieee_Q11numeric_std_Y5op_lt_i163_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i163_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i163_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_lt_i163_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_lt_i163_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_lt_i163_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_lt_i163_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01[L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01[L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_lt_i163_V3l01,L4ieee_Q11numeric_std_Y5op_lt_i163_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_lt_i163_V3r01,L4ieee_Q11numeric_std_Y5op_lt_i163_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i166(const integer L4ieee_Q11numeric_std_Y5op_lt_i166_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_lt_i166_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i166_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_lt_i166_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01;
    L4ieee_Q11numeric_std_Y5op_lt_i166_C6r_left=(L4ieee_Q11numeric_std_Y5op_lt_i166_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i166_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i166_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i166_C1r.data);
    L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i166_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_lt_i166_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_lt_i166_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01[L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_lt_i166_C1l)>L4ieee_Q11numeric_std_Y5op_lt_i166_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_lt_i166_C1l<0);
    }
    return L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_lt_i166_C1l,L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_lt_i166_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i169(const integer L4ieee_Q11numeric_std_Y5op_lt_i169_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_lt_i169_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i169_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_lt_i169_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01;
    L4ieee_Q11numeric_std_Y5op_lt_i169_C6r_left=(L4ieee_Q11numeric_std_Y5op_lt_i169_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i169_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i169_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i169_C1r.data);
    L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i169_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_lt_i169_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_lt_i169_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01[L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_lt_i169_C1l)>L4ieee_Q11numeric_std_Y5op_lt_i169_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_lt_i169_C1l<0);
    }
    return L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_lt_i169_C1l,L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_lt_i169_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i172(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_lt_i172_C1l,const integer L4ieee_Q11numeric_std_Y5op_lt_i172_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i172_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_lt_i172_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01;
    L4ieee_Q11numeric_std_Y5op_lt_i172_C6l_left=(L4ieee_Q11numeric_std_Y5op_lt_i172_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i172_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i172_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i172_C1l.data);
    L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i172_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_lt_i172_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_lt_i172_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01[L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_lt_i172_C1r)>L4ieee_Q11numeric_std_Y5op_lt_i172_C1l.info->length)) {
      return (0<L4ieee_Q11numeric_std_Y5op_lt_i172_C1r);
    }
    return L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_lt_i172_C1r,L4ieee_Q11numeric_std_Y5op_lt_i172_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:"<" */
enumeration L4ieee_Q11numeric_std_Y5op_lt_i175(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_lt_i175_C1l,const integer L4ieee_Q11numeric_std_Y5op_lt_i175_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_lt_i175_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_lt_i175_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01;
    L4ieee_Q11numeric_std_Y5op_lt_i175_C6l_left=(L4ieee_Q11numeric_std_Y5op_lt_i175_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_lt_i175_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i175_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_lt_i175_C1l.data);
    L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_lt_i175_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_lt_i175_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_lt_i175_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01[L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_lt_i175_C1r)>L4ieee_Q11numeric_std_Y5op_lt_i175_C1l.info->length)) {
      return (0<L4ieee_Q11numeric_std_Y5op_lt_i175_C1r);
    }
    return L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_lt_i175_C1r,L4ieee_Q11numeric_std_Y5op_lt_i175_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i178(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_le_i178_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_le_i178_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i178_C6l_left,L4ieee_Q11numeric_std_Y5op_le_i178_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_le_i178_H2xl,L4ieee_Q11numeric_std_Y5op_le_i178_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_le_i178_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_le_i178_V3l01,L4ieee_Q11numeric_std_Y5op_le_i178_V3r01;
    L4ieee_Q11numeric_std_Y5op_le_i178_C6l_left=(L4ieee_Q11numeric_std_Y5op_le_i178_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i178_C6r_left=(L4ieee_Q11numeric_std_Y5op_le_i178_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i178_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i178_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i178_C1l.data);
    L4ieee_Q11numeric_std_Y5op_le_i178_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i178_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i178_C1r.data);
    L4ieee_Q11numeric_std_Y5op_le_i178_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_le_i178_C1l.info->length,L4ieee_Q11numeric_std_Y5op_le_i178_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_le_i178_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i178_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_le_i178_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i178_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_le_i178_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_le_i178_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i178_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_le_i178_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_le_i178_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_le_i178_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_le_i178_V3l01[L4ieee_Q11numeric_std_Y5op_le_i178_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_le_i178_V3r01[L4ieee_Q11numeric_std_Y5op_le_i178_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_le_i178_V3l01,L4ieee_Q11numeric_std_Y5op_le_i178_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_le_i178_V3r01,L4ieee_Q11numeric_std_Y5op_le_i178_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i181(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_le_i181_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_le_i181_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i181_C6l_left,L4ieee_Q11numeric_std_Y5op_le_i181_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_le_i181_H2xl,L4ieee_Q11numeric_std_Y5op_le_i181_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_le_i181_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_le_i181_V3l01,L4ieee_Q11numeric_std_Y5op_le_i181_V3r01;
    L4ieee_Q11numeric_std_Y5op_le_i181_C6l_left=(L4ieee_Q11numeric_std_Y5op_le_i181_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i181_C6r_left=(L4ieee_Q11numeric_std_Y5op_le_i181_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i181_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i181_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i181_C1l.data);
    L4ieee_Q11numeric_std_Y5op_le_i181_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i181_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i181_C1r.data);
    L4ieee_Q11numeric_std_Y5op_le_i181_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_le_i181_C1l.info->length,L4ieee_Q11numeric_std_Y5op_le_i181_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_le_i181_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i181_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_le_i181_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i181_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_le_i181_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_le_i181_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i181_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_le_i181_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_le_i181_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_le_i181_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_le_i181_V3l01[L4ieee_Q11numeric_std_Y5op_le_i181_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_le_i181_V3r01[L4ieee_Q11numeric_std_Y5op_le_i181_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_le_i181_V3l01,L4ieee_Q11numeric_std_Y5op_le_i181_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_le_i181_V3r01,L4ieee_Q11numeric_std_Y5op_le_i181_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i184(const integer L4ieee_Q11numeric_std_Y5op_le_i184_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_le_i184_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i184_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_le_i184_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_le_i184_V3r01;
    L4ieee_Q11numeric_std_Y5op_le_i184_C6r_left=(L4ieee_Q11numeric_std_Y5op_le_i184_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i184_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i184_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i184_C1r.data);
    L4ieee_Q11numeric_std_Y5op_le_i184_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i184_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_le_i184_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i184_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_le_i184_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_le_i184_V3r01[L4ieee_Q11numeric_std_Y5op_le_i184_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_le_i184_C1l)>L4ieee_Q11numeric_std_Y5op_le_i184_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_le_i184_C1l<0);
    }
    return L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_le_i184_C1l,L4ieee_Q11numeric_std_Y5op_le_i184_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_le_i184_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i187(const integer L4ieee_Q11numeric_std_Y5op_le_i187_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_le_i187_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i187_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_le_i187_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_le_i187_V3r01;
    L4ieee_Q11numeric_std_Y5op_le_i187_C6r_left=(L4ieee_Q11numeric_std_Y5op_le_i187_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i187_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i187_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i187_C1r.data);
    L4ieee_Q11numeric_std_Y5op_le_i187_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i187_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_le_i187_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i187_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_le_i187_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_le_i187_V3r01[L4ieee_Q11numeric_std_Y5op_le_i187_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_le_i187_C1l)>L4ieee_Q11numeric_std_Y5op_le_i187_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_le_i187_C1l<0);
    }
    return L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_le_i187_C1l,L4ieee_Q11numeric_std_Y5op_le_i187_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_le_i187_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i190(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_le_i190_C1l,const integer L4ieee_Q11numeric_std_Y5op_le_i190_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i190_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_le_i190_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_le_i190_V3l01;
    L4ieee_Q11numeric_std_Y5op_le_i190_C6l_left=(L4ieee_Q11numeric_std_Y5op_le_i190_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i190_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i190_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i190_C1l.data);
    L4ieee_Q11numeric_std_Y5op_le_i190_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i190_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_le_i190_C6l_left<0)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i190_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_le_i190_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_le_i190_V3l01[L4ieee_Q11numeric_std_Y5op_le_i190_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_le_i190_C1r)>L4ieee_Q11numeric_std_Y5op_le_i190_C1l.info->length)) {
      return (0<L4ieee_Q11numeric_std_Y5op_le_i190_C1r);
    }
    return L4ieee_W11numeric_std_Y22unsigned_less_or_equal_i112 (L4ieee_Q11numeric_std_Y5op_le_i190_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_le_i190_C1r,L4ieee_Q11numeric_std_Y5op_le_i190_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:"<=" */
enumeration L4ieee_Q11numeric_std_Y5op_le_i193(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_le_i193_C1l,const integer L4ieee_Q11numeric_std_Y5op_le_i193_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_le_i193_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_le_i193_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_le_i193_V3l01;
    L4ieee_Q11numeric_std_Y5op_le_i193_C6l_left=(L4ieee_Q11numeric_std_Y5op_le_i193_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_le_i193_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i193_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_le_i193_C1l.data);
    L4ieee_Q11numeric_std_Y5op_le_i193_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_le_i193_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_le_i193_C6l_left<0)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_le_i193_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_le_i193_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_le_i193_V3l01[L4ieee_Q11numeric_std_Y5op_le_i193_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_le_i193_C1r)>L4ieee_Q11numeric_std_Y5op_le_i193_C1l.info->length)) {
      return (0<L4ieee_Q11numeric_std_Y5op_le_i193_C1r);
    }
    return L4ieee_W11numeric_std_Y20signed_less_or_equal_i115 (L4ieee_Q11numeric_std_Y5op_le_i193_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_le_i193_C1r,L4ieee_Q11numeric_std_Y5op_le_i193_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i196(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ge_i196_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ge_i196_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i196_C6l_left,L4ieee_Q11numeric_std_Y5op_ge_i196_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ge_i196_H2xl,L4ieee_Q11numeric_std_Y5op_ge_i196_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_ge_i196_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01,L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01;
    L4ieee_Q11numeric_std_Y5op_ge_i196_C6l_left=(L4ieee_Q11numeric_std_Y5op_ge_i196_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i196_C6r_left=(L4ieee_Q11numeric_std_Y5op_ge_i196_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i196_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i196_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i196_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ge_i196_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i196_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i196_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ge_i196_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_ge_i196_C1l.info->length,L4ieee_Q11numeric_std_Y5op_ge_i196_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i196_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i196_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_ge_i196_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_ge_i196_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ge_i196_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ge_i196_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01[L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01[L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return op_not(L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_ge_i196_V3l01,L4ieee_Q11numeric_std_Y5op_ge_i196_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_ge_i196_V3r01,L4ieee_Q11numeric_std_Y5op_ge_i196_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i199(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ge_i199_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ge_i199_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i199_C6l_left,L4ieee_Q11numeric_std_Y5op_ge_i199_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ge_i199_H2xl,L4ieee_Q11numeric_std_Y5op_ge_i199_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_ge_i199_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01,L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01;
    L4ieee_Q11numeric_std_Y5op_ge_i199_C6l_left=(L4ieee_Q11numeric_std_Y5op_ge_i199_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i199_C6r_left=(L4ieee_Q11numeric_std_Y5op_ge_i199_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i199_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i199_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i199_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ge_i199_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i199_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i199_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ge_i199_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_ge_i199_C1l.info->length,L4ieee_Q11numeric_std_Y5op_ge_i199_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i199_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i199_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_ge_i199_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_ge_i199_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ge_i199_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ge_i199_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01[L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01[L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return op_not(L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_ge_i199_V3l01,L4ieee_Q11numeric_std_Y5op_ge_i199_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_ge_i199_V3r01,L4ieee_Q11numeric_std_Y5op_ge_i199_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i202(const integer L4ieee_Q11numeric_std_Y5op_ge_i202_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ge_i202_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i202_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ge_i202_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01;
    L4ieee_Q11numeric_std_Y5op_ge_i202_C6r_left=(L4ieee_Q11numeric_std_Y5op_ge_i202_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i202_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i202_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i202_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i202_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ge_i202_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ge_i202_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01[L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_ge_i202_C1l)>L4ieee_Q11numeric_std_Y5op_ge_i202_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_ge_i202_C1l>0);
    }
    return op_not(L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_ge_i202_C1l,L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_ge_i202_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i205(const integer L4ieee_Q11numeric_std_Y5op_ge_i205_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ge_i205_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i205_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ge_i205_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01;
    L4ieee_Q11numeric_std_Y5op_ge_i205_C6r_left=(L4ieee_Q11numeric_std_Y5op_ge_i205_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i205_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i205_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i205_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i205_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ge_i205_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ge_i205_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01[L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_ge_i205_C1l)>L4ieee_Q11numeric_std_Y5op_ge_i205_C1r.info->length)) {
      return (L4ieee_Q11numeric_std_Y5op_ge_i205_C1l>0);
    }
    return op_not(L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_ge_i205_C1l,L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_ge_i205_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i208(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ge_i208_C1l,const integer L4ieee_Q11numeric_std_Y5op_ge_i208_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i208_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ge_i208_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01;
    L4ieee_Q11numeric_std_Y5op_ge_i208_C6l_left=(L4ieee_Q11numeric_std_Y5op_ge_i208_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i208_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i208_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i208_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i208_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ge_i208_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ge_i208_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01[L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_ge_i208_C1r)>L4ieee_Q11numeric_std_Y5op_ge_i208_C1l.info->length)) {
      return (0>L4ieee_Q11numeric_std_Y5op_ge_i208_C1r);
    }
    return op_not(L4ieee_W11numeric_std_Y13unsigned_less_i104 (L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_ge_i208_C1r,L4ieee_Q11numeric_std_Y5op_ge_i208_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:">=" */
enumeration L4ieee_Q11numeric_std_Y5op_ge_i211(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ge_i211_C1l,const integer L4ieee_Q11numeric_std_Y5op_ge_i211_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ge_i211_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ge_i211_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01;
    L4ieee_Q11numeric_std_Y5op_ge_i211_C6l_left=(L4ieee_Q11numeric_std_Y5op_ge_i211_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ge_i211_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i211_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ge_i211_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ge_i211_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ge_i211_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ge_i211_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01[L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_ge_i211_C1r)>L4ieee_Q11numeric_std_Y5op_ge_i211_C1l.info->length)) {
      return (0>L4ieee_Q11numeric_std_Y5op_ge_i211_C1r);
    }
    return op_not(L4ieee_W11numeric_std_Y11signed_less_i107 (L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_ge_i211_C1r,L4ieee_Q11numeric_std_Y5op_ge_i211_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i214(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_eq_i214_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_eq_i214_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i214_C6l_left,L4ieee_Q11numeric_std_Y5op_eq_i214_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_eq_i214_H2xl,L4ieee_Q11numeric_std_Y5op_eq_i214_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_eq_i214_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01,L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01;
    L4ieee_Q11numeric_std_Y5op_eq_i214_C6l_left=(L4ieee_Q11numeric_std_Y5op_eq_i214_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i214_C6r_left=(L4ieee_Q11numeric_std_Y5op_eq_i214_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i214_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i214_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i214_C1l.data);
    L4ieee_Q11numeric_std_Y5op_eq_i214_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i214_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i214_C1r.data);
    L4ieee_Q11numeric_std_Y5op_eq_i214_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_eq_i214_C1l.info->length,L4ieee_Q11numeric_std_Y5op_eq_i214_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i214_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i214_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_eq_i214_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_eq_i214_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_eq_i214_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_eq_i214_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01[L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01[L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_eq_i214_V3l01,L4ieee_Q11numeric_std_Y5op_eq_i214_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_eq_i214_V3r01,L4ieee_Q11numeric_std_Y5op_eq_i214_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i217(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_eq_i217_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_eq_i217_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i217_C6l_left,L4ieee_Q11numeric_std_Y5op_eq_i217_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_eq_i217_H2xl,L4ieee_Q11numeric_std_Y5op_eq_i217_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_eq_i217_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01,L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01;
    L4ieee_Q11numeric_std_Y5op_eq_i217_C6l_left=(L4ieee_Q11numeric_std_Y5op_eq_i217_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i217_C6r_left=(L4ieee_Q11numeric_std_Y5op_eq_i217_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i217_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i217_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i217_C1l.data);
    L4ieee_Q11numeric_std_Y5op_eq_i217_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i217_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i217_C1r.data);
    L4ieee_Q11numeric_std_Y5op_eq_i217_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_eq_i217_C1l.info->length,L4ieee_Q11numeric_std_Y5op_eq_i217_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i217_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i217_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_eq_i217_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_eq_i217_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_eq_i217_H2xl,enumeration(1));
    L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_eq_i217_H2xr,enumeration(1));
    if(((L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01[L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01[L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_eq_i217_V3l01,L4ieee_Q11numeric_std_Y5op_eq_i217_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_eq_i217_V3r01,L4ieee_Q11numeric_std_Y5op_eq_i217_C4size));
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i220(const integer L4ieee_Q11numeric_std_Y5op_eq_i220_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_eq_i220_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i220_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_eq_i220_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01;
    L4ieee_Q11numeric_std_Y5op_eq_i220_C6r_left=(L4ieee_Q11numeric_std_Y5op_eq_i220_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i220_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i220_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i220_C1r.data);
    L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i220_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_eq_i220_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_eq_i220_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01[L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_eq_i220_C1l)>L4ieee_Q11numeric_std_Y5op_eq_i220_C1r.info->length)) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_eq_i220_C1l,L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_eq_i220_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i223(const integer L4ieee_Q11numeric_std_Y5op_eq_i223_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_eq_i223_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i223_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_eq_i223_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01;
    L4ieee_Q11numeric_std_Y5op_eq_i223_C6r_left=(L4ieee_Q11numeric_std_Y5op_eq_i223_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i223_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i223_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i223_C1r.data);
    L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i223_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_eq_i223_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_eq_i223_H2xr,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01[L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_eq_i223_C1l)>L4ieee_Q11numeric_std_Y5op_eq_i223_C1r.info->length)) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_eq_i223_C1l,L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_eq_i223_V3r01);
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i226(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_eq_i226_C1l,const integer L4ieee_Q11numeric_std_Y5op_eq_i226_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i226_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_eq_i226_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01;
    L4ieee_Q11numeric_std_Y5op_eq_i226_C6l_left=(L4ieee_Q11numeric_std_Y5op_eq_i226_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i226_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i226_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i226_C1l.data);
    L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i226_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_eq_i226_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_eq_i226_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01[L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_eq_i226_C1r)>L4ieee_Q11numeric_std_Y5op_eq_i226_C1l.info->length)) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_eq_i226_C1r,L4ieee_Q11numeric_std_Y5op_eq_i226_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:"=" */
enumeration L4ieee_Q11numeric_std_Y5op_eq_i229(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_eq_i229_C1l,const integer L4ieee_Q11numeric_std_Y5op_eq_i229_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_eq_i229_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_eq_i229_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01;
    L4ieee_Q11numeric_std_Y5op_eq_i229_C6l_left=(L4ieee_Q11numeric_std_Y5op_eq_i229_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_eq_i229_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i229_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_eq_i229_C1l.data);
    L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_eq_i229_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_eq_i229_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_eq_i229_H2xl,enumeration(1));
    if((L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01[L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(0);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_eq_i229_C1r)>L4ieee_Q11numeric_std_Y5op_eq_i229_C1l.info->length)) {
      return enumeration(0);
    }
    return L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_eq_i229_C1r,L4ieee_Q11numeric_std_Y5op_eq_i229_V3l01.info->length));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i232(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ne_i232_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ne_i232_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i232_C6l_left,L4ieee_Q11numeric_std_Y5op_ne_i232_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ne_i232_H2xl,L4ieee_Q11numeric_std_Y5op_ne_i232_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_ne_i232_C4size;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01,L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01;
    L4ieee_Q11numeric_std_Y5op_ne_i232_C6l_left=(L4ieee_Q11numeric_std_Y5op_ne_i232_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i232_C6r_left=(L4ieee_Q11numeric_std_Y5op_ne_i232_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i232_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i232_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i232_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ne_i232_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i232_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i232_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ne_i232_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_ne_i232_C1l.info->length,L4ieee_Q11numeric_std_Y5op_ne_i232_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i232_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i232_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_ne_i232_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_ne_i232_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ne_i232_H2xl,enumeration(2));
    L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ne_i232_H2xr,enumeration(2));
    if(((L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01[L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01[L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_ne_i232_V3l01,L4ieee_Q11numeric_std_Y5op_ne_i232_C4size),L4ieee_Q11numeric_std_Y6resize_i277 (L4ieee_Q11numeric_std_Y5op_ne_i232_V3r01,L4ieee_Q11numeric_std_Y5op_ne_i232_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i235(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ne_i235_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ne_i235_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i235_C6l_left,L4ieee_Q11numeric_std_Y5op_ne_i235_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ne_i235_H2xl,L4ieee_Q11numeric_std_Y5op_ne_i235_H2xr;
    integer L4ieee_Q11numeric_std_Y5op_ne_i235_C4size;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01,L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01;
    L4ieee_Q11numeric_std_Y5op_ne_i235_C6l_left=(L4ieee_Q11numeric_std_Y5op_ne_i235_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i235_C6r_left=(L4ieee_Q11numeric_std_Y5op_ne_i235_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i235_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i235_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i235_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ne_i235_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i235_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i235_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ne_i235_C4size=L4ieee_W11numeric_std_Y3max_i9 (L4ieee_Q11numeric_std_Y5op_ne_i235_C1l.info->length,L4ieee_Q11numeric_std_Y5op_ne_i235_C1r.info->length);
    L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i235_C6l_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i235_C6r_left,downto,0,0)),enumeration(0));
    if(((L4ieee_Q11numeric_std_Y5op_ne_i235_C1l.info->length<1)||(L4ieee_Q11numeric_std_Y5op_ne_i235_C1r.info->length<1))) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ne_i235_H2xl,enumeration(2));
    L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ne_i235_H2xr,enumeration(2));
    if(((L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01[L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01.info->left_bound]==enumeration(1))||(L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01[L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01.info->left_bound]==enumeration(1)))) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_ne_i235_V3l01,L4ieee_Q11numeric_std_Y5op_ne_i235_C4size),L4ieee_Q11numeric_std_Y6resize_i274 (L4ieee_Q11numeric_std_Y5op_ne_i235_V3r01,L4ieee_Q11numeric_std_Y5op_ne_i235_C4size)));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i238(const integer L4ieee_Q11numeric_std_Y5op_ne_i238_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ne_i238_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i238_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ne_i238_H2xr;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01;
    L4ieee_Q11numeric_std_Y5op_ne_i238_C6r_left=(L4ieee_Q11numeric_std_Y5op_ne_i238_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i238_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i238_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i238_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i238_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ne_i238_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ne_i238_H2xr,enumeration(2));
    if((L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01[L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(1);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_ne_i238_C1l)>L4ieee_Q11numeric_std_Y5op_ne_i238_C1r.info->length)) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_ne_i238_C1l,L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_ne_i238_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i241(const integer L4ieee_Q11numeric_std_Y5op_ne_i241_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ne_i241_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i241_C6r_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ne_i241_H2xr;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01;
    L4ieee_Q11numeric_std_Y5op_ne_i241_C6r_left=(L4ieee_Q11numeric_std_Y5op_ne_i241_C1r.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i241_H2xr.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i241_C6r_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i241_C1r.data);
    L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i241_C6r_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ne_i241_C1r.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ne_i241_H2xr,enumeration(2));
    if((L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01[L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01.info->left_bound]==enumeration(1))) {
      return enumeration(1);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_ne_i241_C1l)>L4ieee_Q11numeric_std_Y5op_ne_i241_C1r.info->length)) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_ne_i241_C1l,L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01.info->length),L4ieee_Q11numeric_std_Y5op_ne_i241_V3r01));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i244(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_ne_i244_C1l,const integer L4ieee_Q11numeric_std_Y5op_ne_i244_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i244_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y5op_ne_i244_H2xl;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01;
    L4ieee_Q11numeric_std_Y5op_ne_i244_C6l_left=(L4ieee_Q11numeric_std_Y5op_ne_i244_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i244_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i244_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i244_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i244_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ne_i244_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y5op_ne_i244_H2xl,enumeration(2));
    if((L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01[L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(1);
    }
    if((L4ieee_W11numeric_std_Y17unsigned_num_bits_i19 (L4ieee_Q11numeric_std_Y5op_ne_i244_C1r)>L4ieee_Q11numeric_std_Y5op_ne_i244_C1l.info->length)) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y14unsigned_equal_i98 (L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01,L4ieee_Q11numeric_std_Y11to_unsigned_i284 (L4ieee_Q11numeric_std_Y5op_ne_i244_C1r,L4ieee_Q11numeric_std_Y5op_ne_i244_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:"/=" */
enumeration L4ieee_Q11numeric_std_Y5op_ne_i247(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_ne_i247_C1l,const integer L4ieee_Q11numeric_std_Y5op_ne_i247_C1r)
{
    integer L4ieee_Q11numeric_std_Y5op_ne_i247_C6l_left;
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y5op_ne_i247_H2xl;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01;
    L4ieee_Q11numeric_std_Y5op_ne_i247_C6l_left=(L4ieee_Q11numeric_std_Y5op_ne_i247_C1l.info->length-1);
    L4ieee_Q11numeric_std_Y5op_ne_i247_H2xl.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i247_C6l_left,downto,0,0)), L4ieee_Q11numeric_std_Y5op_ne_i247_C1l.data);
    L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_ne_i247_C6l_left,downto,0,0)),enumeration(0));
    if((L4ieee_Q11numeric_std_Y5op_ne_i247_C1l.info->length<1)) {
      return enumeration(0);
    }
    L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01=L4ieee_W11numeric_std_Y5to_01_i120 (L4ieee_Q11numeric_std_Y5op_ne_i247_H2xl,enumeration(2));
    if((L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01[L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01.info->left_bound]==enumeration(1))) {
      return enumeration(1);
    }
    if((L4ieee_W11numeric_std_Y15signed_num_bits_i14 (L4ieee_Q11numeric_std_Y5op_ne_i247_C1r)>L4ieee_Q11numeric_std_Y5op_ne_i247_C1l.info->length)) {
      return enumeration(1);
    }
    return op_not(L4ieee_W11numeric_std_Y12signed_equal_i101 (L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01,L4ieee_Q11numeric_std_Y9to_signed_i287 (L4ieee_Q11numeric_std_Y5op_ne_i247_C1r,L4ieee_Q11numeric_std_Y5op_ne_i247_V3l01.info->length)));
}
/* Implementation of subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y10shift_left_i250(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y10shift_left_i250_C3arg,const integer L4ieee_Q11numeric_std_Y10shift_left_i250_C5count)
{
    if((L4ieee_Q11numeric_std_Y10shift_left_i250_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y4xsll_i65 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y10shift_left_i250_C3arg),L4ieee_Q11numeric_std_Y10shift_left_i250_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11shift_right_i253(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y11shift_right_i253_C3arg,const integer L4ieee_Q11numeric_std_Y11shift_right_i253_C5count)
{
    if((L4ieee_Q11numeric_std_Y11shift_right_i253_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y4xsrl_i71 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y11shift_right_i253_C3arg),L4ieee_Q11numeric_std_Y11shift_right_i253_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:shift_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y10shift_left_i256(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y10shift_left_i256_C3arg,const integer L4ieee_Q11numeric_std_Y10shift_left_i256_C5count)
{
    if((L4ieee_Q11numeric_std_Y10shift_left_i256_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y4xsll_i65 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y10shift_left_i256_C3arg),L4ieee_Q11numeric_std_Y10shift_left_i256_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:shift_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11shift_right_i259(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y11shift_right_i259_C3arg,const integer L4ieee_Q11numeric_std_Y11shift_right_i259_C5count)
{
    if((L4ieee_Q11numeric_std_Y11shift_right_i259_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y4xsra_i77 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y11shift_right_i259_C3arg),L4ieee_Q11numeric_std_Y11shift_right_i259_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11rotate_left_i262(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y11rotate_left_i262_C3arg,const integer L4ieee_Q11numeric_std_Y11rotate_left_i262_C5count)
{
    if((L4ieee_Q11numeric_std_Y11rotate_left_i262_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y4xrol_i84 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y11rotate_left_i262_C3arg),L4ieee_Q11numeric_std_Y11rotate_left_i262_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y12rotate_right_i265(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y12rotate_right_i265_C3arg,const integer L4ieee_Q11numeric_std_Y12rotate_right_i265_C5count)
{
    if((L4ieee_Q11numeric_std_Y12rotate_right_i265_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_Y4xror_i91 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y12rotate_right_i265_C3arg),L4ieee_Q11numeric_std_Y12rotate_right_i265_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:rotate_left */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y11rotate_left_i268(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y11rotate_left_i268_C3arg,const integer L4ieee_Q11numeric_std_Y11rotate_left_i268_C5count)
{
    if((L4ieee_Q11numeric_std_Y11rotate_left_i268_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y4xrol_i84 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y11rotate_left_i268_C3arg),L4ieee_Q11numeric_std_Y11rotate_left_i268_C5count)));
}
/* Implementation of subprogram :ieee:numeric_std:rotate_right */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y12rotate_right_i271(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y12rotate_right_i271_C3arg,const integer L4ieee_Q11numeric_std_Y12rotate_right_i271_C5count)
{
    if((L4ieee_Q11numeric_std_Y12rotate_right_i271_C3arg.info->length<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_Y4xror_i91 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y12rotate_right_i271_C3arg),L4ieee_Q11numeric_std_Y12rotate_right_i271_C5count)));
}
enumeration L4ieee_W11numeric_std_itn42_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,73,78,84,69,71,69,82,58,32,110,117,108,108,32,97,114,103};
enumeration L4ieee_W11numeric_std_itn43_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,73,78,84,69,71,69,82,58,32,109,101,116,97,118,97,108,117,101,32,97,114,103,32,115,101,116,32,116,111,32,48};
/* Implementation of subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i279(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y10to_integer_i279_C3arg)
{
    integer L4ieee_Q11numeric_std_Y10to_integer_i279_C8arg_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y10to_integer_i279_H5xxarg;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg;
    integer L4ieee_Q11numeric_std_Y10to_integer_i279_V6result,L4ieee_Q11numeric_std_Y10to_integer_i279_V1w,L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i,L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i_lc;
    L4ieee_Q11numeric_std_Y10to_integer_i279_C8arg_left=(L4ieee_Q11numeric_std_Y10to_integer_i279_C3arg.info->length-1);
    L4ieee_Q11numeric_std_Y10to_integer_i279_H5xxarg.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y10to_integer_i279_C8arg_left,downto,0,0)), L4ieee_Q11numeric_std_Y10to_integer_i279_C3arg.data);
    L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y10to_integer_i279_C8arg_left,downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y10to_integer_i279_V6result=0;
    L4ieee_Q11numeric_std_Y10to_integer_i279_V1w=1;
    if((L4ieee_Q11numeric_std_Y10to_integer_i279_C3arg.info->length<1)) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+31,0),L4ieee_W11numeric_std_itn42_lit),enumeration(1));
      return 0;
    }
    L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg=L4ieee_W11numeric_std_Y5to_01_i130 (L4ieee_Q11numeric_std_Y10to_integer_i279_H5xxarg,enumeration(2));
    if((L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg[L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg.info->left_bound]==enumeration(1))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+45,0),L4ieee_W11numeric_std_itn43_lit),enumeration(1));
      return 0;
    }
    for (L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i=0,L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y10to_integer_i279_C8arg_left); L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i++,L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i_lc--) {
      if((L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg[L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i]==enumeration(3))) {
        L4ieee_Q11numeric_std_Y10to_integer_i279_V6result=(L4ieee_Q11numeric_std_Y10to_integer_i279_V6result+L4ieee_Q11numeric_std_Y10to_integer_i279_V1w);
      }
      if((L4ieee_Q11numeric_std_Y10to_integer_i279_L5679ln_C1i!=L4ieee_Q11numeric_std_Y10to_integer_i279_V4xarg.info->left_bound)) {
        L4ieee_Q11numeric_std_Y10to_integer_i279_V1w=(L4ieee_Q11numeric_std_Y10to_integer_i279_V1w+L4ieee_Q11numeric_std_Y10to_integer_i279_V1w);
      }
    }
    return L4ieee_Q11numeric_std_Y10to_integer_i279_V6result;
}
/* Implementation of subprogram :ieee:numeric_std:to_integer */
integer L4ieee_Q11numeric_std_Y10to_integer_i281(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y10to_integer_i281_C3arg)
{
    if((L4ieee_Q11numeric_std_Y10to_integer_i281_C3arg[L4ieee_Q11numeric_std_Y10to_integer_i281_C3arg.info->left_bound]==enumeration(2))) {
      return L4ieee_Q11numeric_std_Y10to_integer_i279 (array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y10to_integer_i281_C3arg));
    } else {
      return ((-L4ieee_Q11numeric_std_Y10to_integer_i279 (array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y8op_minus_i31 (L4ieee_Q11numeric_std_Y7op_plus_i49 (L4ieee_Q11numeric_std_Y10to_integer_i281_C3arg,1)))))-1);
    }
}
enumeration L4ieee_W11numeric_std_itn44_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,85,78,83,73,71,78,69,68,32,58,32,118,101,99,116,111,114,32,116,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i284(const integer L4ieee_Q11numeric_std_Y11to_unsigned_i284_C3arg,const integer L4ieee_Q11numeric_std_Y11to_unsigned_i284_C4size)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result;
    integer L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val,L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i,L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i_lc;
    L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y11to_unsigned_i284_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val=L4ieee_Q11numeric_std_Y11to_unsigned_i284_C3arg;
    if((L4ieee_Q11numeric_std_Y11to_unsigned_i284_C4size<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    for (L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i=0,L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result.info->left_bound); L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i++,L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i_lc--) {
      if((op_mod(L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val,2)==0)) {
        L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result[L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i]=enumeration(2);
      } else {
        L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result[L4ieee_Q11numeric_std_Y11to_unsigned_i284_L5688ln_C1i]=enumeration(3);
      }
      L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val=(L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val/2);
    }
    if(op_not((L4ieee_Q11numeric_std_Y11to_unsigned_i284_V5i_val==0))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+41,0),L4ieee_W11numeric_std_itn44_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y11to_unsigned_i284_V6result);
}
enumeration L4ieee_W11numeric_std_itn45_lit[]={110,117,109,101,114,105,99,95,115,116,100,46,84,79,95,83,73,71,78,69,68,32,58,32,118,101,99,116,111,114,32,116,114,117,110,99,97,116,101,100};
/* Implementation of subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i287(const integer L4ieee_Q11numeric_std_Y9to_signed_i287_C3arg,const integer L4ieee_Q11numeric_std_Y9to_signed_i287_C4size)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i287_V6result;
    enumeration L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val;
    integer L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val,L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i,L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i_lc;
    L4ieee_Q11numeric_std_Y9to_signed_i287_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y9to_signed_i287_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val=enumeration(2);
    L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val=L4ieee_Q11numeric_std_Y9to_signed_i287_C3arg;
    if((L4ieee_Q11numeric_std_Y9to_signed_i287_C4size<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    if((L4ieee_Q11numeric_std_Y9to_signed_i287_C3arg<0)) {
      L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val=enumeration(3);
      L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val=(-(L4ieee_Q11numeric_std_Y9to_signed_i287_C3arg+1));
    }
    for (L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i=0,L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q11numeric_std_Y9to_signed_i287_V6result.info->left_bound); L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i++,L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i_lc--) {
      if((op_mod(L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val,2)==0)) {
        L4ieee_Q11numeric_std_Y9to_signed_i287_V6result[L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i]=L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val;
      } else {
        L4ieee_Q11numeric_std_Y9to_signed_i287_V6result[L4ieee_Q11numeric_std_Y9to_signed_i287_L5696ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_not_i65 (L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val);
      }
      L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val=(L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val/2);
    }
    if(((L4ieee_Q11numeric_std_Y9to_signed_i287_V5i_val!=0)||(L4ieee_Q11numeric_std_Y9to_signed_i287_V5b_val!=L4ieee_Q11numeric_std_Y9to_signed_i287_V6result[L4ieee_Q11numeric_std_Y9to_signed_i287_V6result.info->left_bound]))) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+39,0),L4ieee_W11numeric_std_itn45_lit),enumeration(1));
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y9to_signed_i287_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:to_unsigned */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y11to_unsigned_i289(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q11numeric_std_Y11to_unsigned_i289_C3arg)
{
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y11to_unsigned_i289_C3arg));
}
/* Implementation of subprogram :ieee:numeric_std:to_signed */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y9to_signed_i291(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q11numeric_std_Y9to_signed_i291_C3arg)
{
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y9to_signed_i291_C3arg));
}
/* Implementation of subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i293(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y17to_stdlogicvector_i293_C3arg)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y17to_stdlogicvector_i293_C3arg));
}
/* Implementation of subprogram :ieee:numeric_std:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q11numeric_std_Y17to_stdlogicvector_i295(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y17to_stdlogicvector_i295_C3arg)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y17to_stdlogicvector_i295_C3arg));
}
/* Implementation of subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6resize_i274(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6resize_i274_C3arg,const integer L4ieee_Q11numeric_std_Y6resize_i274_C8new_size)
{
    array_alias<L4ieee_Q11numeric_std_T6signed > L4ieee_Q11numeric_std_Y6resize_i274_H5invec;
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6resize_i274_V6result;
    integer L4ieee_Q11numeric_std_Y6resize_i274_C5bound;
    L4ieee_Q11numeric_std_Y6resize_i274_H5invec.set((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i274_C3arg.info->length-1),downto,0,0)), L4ieee_Q11numeric_std_Y6resize_i274_C3arg.data);
    L4ieee_Q11numeric_std_Y6resize_i274_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i274_C8new_size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6resize_i274_C5bound=(L4ieee_W11numeric_std_Y3min_i12 (L4ieee_Q11numeric_std_Y6resize_i274_C3arg.info->length,L4ieee_Q11numeric_std_Y6resize_i274_V6result.info->length)-2);
    if((L4ieee_Q11numeric_std_Y6resize_i274_C8new_size<1)) {
      return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_W11numeric_std_C3nas);
    }
    L4ieee_Q11numeric_std_Y6resize_i274_V6result=L4ieee_Q11numeric_std_T6signed(new array_info((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i274_C8new_size-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i274_C8new_size-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6resize_i274_C8new_size-1),downto,0,0),L4ieee_Q11numeric_std_Y6resize_i274_C3arg[L4ieee_Q11numeric_std_Y6resize_i274_C3arg.info->left_bound]);
    if((L4ieee_Q11numeric_std_Y6resize_i274_C5bound>=0)) {
      array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i274_C5bound,downto,0,0),&L4ieee_Q11numeric_std_Y6resize_i274_V6result[L4ieee_Q11numeric_std_Y6resize_i274_C5bound])=array_alias<L4ieee_Q11numeric_std_T6signed >(new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i274_C5bound,downto,0,0),&L4ieee_Q11numeric_std_Y6resize_i274_H5invec[L4ieee_Q11numeric_std_Y6resize_i274_C5bound]);
    }
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6resize_i274_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:resize */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6resize_i277(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6resize_i277_C3arg,const integer L4ieee_Q11numeric_std_Y6resize_i277_C8new_size)
{
    integer L4ieee_Q11numeric_std_Y6resize_i277_C8arg_left;
    array_alias<L4ieee_Q11numeric_std_T8unsigned > L4ieee_Q11numeric_std_Y6resize_i277_H4xarg;
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6resize_i277_V6result;
    L4ieee_Q11numeric_std_Y6resize_i277_C8arg_left=(L4ieee_Q11numeric_std_Y6resize_i277_C3arg.info->length-1);
    L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.set((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_C8arg_left,downto,0,0)), L4ieee_Q11numeric_std_Y6resize_i277_C3arg.data);
    L4ieee_Q11numeric_std_Y6resize_i277_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i277_C8new_size-1),downto,0,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6resize_i277_V6result=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i277_C8new_size-1),downto,0,0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,(L4ieee_Q11numeric_std_Y6resize_i277_C8new_size-1),downto,0,0))->index_type,(L4ieee_Q11numeric_std_Y6resize_i277_C8new_size-1),downto,0,0),enumeration(2));
    if((L4ieee_Q11numeric_std_Y6resize_i277_C8new_size<1)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_W11numeric_std_C3nau);
    }
    if((L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->length==0)) {
      return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6resize_i277_V6result);
    }
    if((L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->length<L4ieee_Q11numeric_std_Y6resize_i277_C3arg.info->length)) {
      array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,0,0),&L4ieee_Q11numeric_std_Y6resize_i277_V6result[L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound])=array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,0,0),&L4ieee_Q11numeric_std_Y6resize_i277_H4xarg[L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound]);
    } else {
      array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,(L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound+1),0),&L4ieee_Q11numeric_std_Y6resize_i277_V6result[L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound])=L4ieee_Q11numeric_std_T8unsigned(new array_info((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,(L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound+1),0))->element_type,(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,(L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound+1),0))->index_type,L4ieee_Q11numeric_std_Y6resize_i277_V6result.info->left_bound,downto,(L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound+1),0),enumeration(2));
      array_alias<L4ieee_Q11numeric_std_T8unsigned >(new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound,downto,0,0),&L4ieee_Q11numeric_std_Y6resize_i277_V6result[L4ieee_Q11numeric_std_Y6resize_i277_H4xarg.info->left_bound])=L4ieee_Q11numeric_std_Y6resize_i277_H4xarg;
    }
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6resize_i277_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_not_i297(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_not_i297_C1l)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_not_i297_V6result;
    L4ieee_Q11numeric_std_Y6op_not_i297_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_not_i297_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_not_i297_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_not_i297_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_not_i297_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y6op_not_i97 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_not_i297_C1l)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_not_i297_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_and_i300(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_and_i300_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_and_i300_C1r)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_and_i300_V6result;
    L4ieee_Q11numeric_std_Y6op_and_i300_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_and_i300_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_and_i300_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_and_i300_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_and_i300_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y6op_and_i68 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_and_i300_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_and_i300_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_and_i300_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_or_i303(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_or_i303_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y5op_or_i303_C1r)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y5op_or_i303_V6result;
    L4ieee_Q11numeric_std_Y5op_or_i303_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_or_i303_C1l.info->left_bound,L4ieee_Q11numeric_std_Y5op_or_i303_C1l.info->index_direction,L4ieee_Q11numeric_std_Y5op_or_i303_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_or_i303_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y5op_or_i80 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y5op_or_i303_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y5op_or_i303_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y5op_or_i303_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_nand_i306(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_nand_i306_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y7op_nand_i306_C1r)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y7op_nand_i306_V6result;
    L4ieee_Q11numeric_std_Y7op_nand_i306_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_nand_i306_C1l.info->left_bound,L4ieee_Q11numeric_std_Y7op_nand_i306_C1l.info->index_direction,L4ieee_Q11numeric_std_Y7op_nand_i306_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_nand_i306_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y7op_nand_i74 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y7op_nand_i306_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y7op_nand_i306_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y7op_nand_i306_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_nor_i309(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_nor_i309_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_nor_i309_C1r)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_nor_i309_V6result;
    L4ieee_Q11numeric_std_Y6op_nor_i309_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_nor_i309_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_nor_i309_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_nor_i309_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_nor_i309_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y6op_nor_i86 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_nor_i309_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_nor_i309_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_nor_i309_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_xor_i312(const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_xor_i312_C1l,const L4ieee_Q11numeric_std_T8unsigned &L4ieee_Q11numeric_std_Y6op_xor_i312_C1r)
{
    L4ieee_Q11numeric_std_T8unsigned L4ieee_Q11numeric_std_Y6op_xor_i312_V6result;
    L4ieee_Q11numeric_std_Y6op_xor_i312_V6result.init((new array_info((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,(&L4ieee_Q11numeric_std_I8unsigned_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_xor_i312_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_xor_i312_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_xor_i312_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_xor_i312_V6result=array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q14std_logic_1164_Y6op_xor_i92 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_xor_i312_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_xor_i312_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T8unsigned >((&L4ieee_Q11numeric_std_I8unsigned_INFO),L4ieee_Q11numeric_std_Y6op_xor_i312_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"not" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_not_i314(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_not_i314_C1l)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_not_i314_V6result;
    L4ieee_Q11numeric_std_Y6op_not_i314_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_not_i314_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_not_i314_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_not_i314_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_not_i314_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y6op_not_i97 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_not_i314_C1l)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_not_i314_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"and" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_and_i317(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_and_i317_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_and_i317_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_and_i317_V6result;
    L4ieee_Q11numeric_std_Y6op_and_i317_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_and_i317_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_and_i317_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_and_i317_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_and_i317_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y6op_and_i68 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_and_i317_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_and_i317_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_and_i317_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"or" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_or_i320(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_or_i320_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y5op_or_i320_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y5op_or_i320_V6result;
    L4ieee_Q11numeric_std_Y5op_or_i320_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y5op_or_i320_C1l.info->left_bound,L4ieee_Q11numeric_std_Y5op_or_i320_C1l.info->index_direction,L4ieee_Q11numeric_std_Y5op_or_i320_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y5op_or_i320_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y5op_or_i80 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y5op_or_i320_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y5op_or_i320_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y5op_or_i320_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"nand" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_nand_i323(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_nand_i323_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y7op_nand_i323_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y7op_nand_i323_V6result;
    L4ieee_Q11numeric_std_Y7op_nand_i323_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y7op_nand_i323_C1l.info->left_bound,L4ieee_Q11numeric_std_Y7op_nand_i323_C1l.info->index_direction,L4ieee_Q11numeric_std_Y7op_nand_i323_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y7op_nand_i323_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y7op_nand_i74 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y7op_nand_i323_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y7op_nand_i323_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y7op_nand_i323_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"nor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_nor_i326(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_nor_i326_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_nor_i326_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_nor_i326_V6result;
    L4ieee_Q11numeric_std_Y6op_nor_i326_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_nor_i326_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_nor_i326_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_nor_i326_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_nor_i326_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y6op_nor_i86 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_nor_i326_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_nor_i326_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_nor_i326_V6result);
}
/* Implementation of subprogram :ieee:numeric_std:"xor" */
L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_xor_i329(const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_xor_i329_C1l,const L4ieee_Q11numeric_std_T6signed &L4ieee_Q11numeric_std_Y6op_xor_i329_C1r)
{
    L4ieee_Q11numeric_std_T6signed L4ieee_Q11numeric_std_Y6op_xor_i329_V6result;
    L4ieee_Q11numeric_std_Y6op_xor_i329_V6result.init((new array_info((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,(&L4ieee_Q11numeric_std_I6signed_INFO)->index_type,L4ieee_Q11numeric_std_Y6op_xor_i329_C1l.info->left_bound,L4ieee_Q11numeric_std_Y6op_xor_i329_C1l.info->index_direction,L4ieee_Q11numeric_std_Y6op_xor_i329_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q11numeric_std_Y6op_xor_i329_V6result=array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q14std_logic_1164_Y6op_xor_i92 (array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_xor_i329_C1l),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q11numeric_std_Y6op_xor_i329_C1r)));
    return array_alias<L4ieee_Q11numeric_std_T6signed >((&L4ieee_Q11numeric_std_I6signed_INFO),L4ieee_Q11numeric_std_Y6op_xor_i329_V6result);
}
L4ieee_W11numeric_std_I15stdulogic_table L4ieee_W11numeric_std_I15stdulogic_table_INFO;
/* Implementation of subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i332(const enumeration L4ieee_Q11numeric_std_Y9std_match_i332_C1l,const enumeration L4ieee_Q11numeric_std_Y9std_match_i332_C1r)
{
    enumeration L4ieee_Q11numeric_std_Y9std_match_i332_V5value;
    L4ieee_Q11numeric_std_Y9std_match_i332_V5value=enumeration(0);
    L4ieee_Q11numeric_std_Y9std_match_i332_V5value=L4ieee_W11numeric_std_C11match_table[L4ieee_Q11numeric_std_Y9std_match_i332_C1l][L4ieee_Q11numeric_std_Y9std_match_i332_C1r];
    return (L4ieee_Q11numeric_std_Y9std_match_i332_V5value==enumeration(3));
}
enumeration L4ieee_W11numeric_std_itn46_lit[]={83,84,68,95,77,65,84,67,72,32,105,110,112,117,116,32,97,114,103,117,109,101,110,116,115,32,97,114,101,32,110,111,116,32,111,102,32,101,113,117,97,108,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:numeric_std:std_match */
enumeration L4ieee_Q11numeric_std_Y9std_match_i335(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q11numeric_std_Y9std_match_i335_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q11numeric_std_Y9std_match_i335_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q11numeric_std_Y9std_match_i335_H2lv,L4ieee_Q11numeric_std_Y9std_match_i335_H2rv;
    enumeration L4ieee_Q11numeric_std_Y9std_match_i335_V5value;
    integer L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i,L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i_lc;
    L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q11numeric_std_Y9std_match_i335_C1l.info->length,0)), L4ieee_Q11numeric_std_Y9std_match_i335_C1l.data);
    L4ieee_Q11numeric_std_Y9std_match_i335_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q11numeric_std_Y9std_match_i335_C1r.info->length,0)), L4ieee_Q11numeric_std_Y9std_match_i335_C1r.data);
    L4ieee_Q11numeric_std_Y9std_match_i335_V5value=enumeration(3);
    if((L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->length!=L4ieee_Q11numeric_std_Y9std_match_i335_H2rv.info->length)) {
      if(!enumeration(1))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+48,0),L4ieee_W11numeric_std_itn46_lit),enumeration(1));
      return enumeration(0);
    } else {
      for (L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i=min(L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->left_bound,L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->right_bound),L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i_lc=up_range_to_length<integer>(min(L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->left_bound,L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->right_bound),max(L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->left_bound,L4ieee_Q11numeric_std_Y9std_match_i335_H2lv.info->right_bound)); L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i_lc!=0; L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i++,L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i_lc--) {
        L4ieee_Q11numeric_std_Y9std_match_i335_V5value=L4ieee_W11numeric_std_C9and_table[L4ieee_W11numeric_std_C11match_table[L4ieee_Q11numeric_std_Y9std_match_i335_H2lv[L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i]][L4ieee_Q11numeric_std_Y9std_match_i335_H2rv[L4ieee_Q11numeric_std_Y9std_match_i335_L5779ln_C1i]]][L4ieee_Q11numeric_std_Y9std_match_i335_V5value];
      }
      return (L4ieee_Q11numeric_std_Y9std_match_i335_V5value==enumeration(3));
    }
}
/* Initialization function for package body :ieee:numeric_std */
int L4ieee_Q11numeric_std_init ();
int L3std_Q8standard_init ();
bool L4ieee_W11numeric_std_init_done = false;
int L4ieee_W11numeric_std_init(){
if (L4ieee_W11numeric_std_init_done) return 1;
L4ieee_W11numeric_std_init_done=true;
L4ieee_Q11numeric_std_init ();
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/numeric_std.vhdl","numeric_std.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":numeric_std");
L4ieee_W11numeric_std_I3_t0_INFO.set((&L4ieee_Q11numeric_std_I8unsigned_INFO)->element_type,parray_info((&L4ieee_Q11numeric_std_I8unsigned_INFO))->index_type,0,downto,1,-1).register_type(":ieee:numeric_std",":ieee:numeric_std:_t0",":_t0",NULL);
L4ieee_W11numeric_std_I3_t1_INFO.set((&L4ieee_Q11numeric_std_I6signed_INFO)->element_type,parray_info((&L4ieee_Q11numeric_std_I6signed_INFO))->index_type,0,downto,1,-1).register_type(":ieee:numeric_std",":ieee:numeric_std:_t1",":_t1",NULL);
L4ieee_W11numeric_std_I15stdulogic_table_INFO.set((new array_info((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1)),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:numeric_std",":ieee:numeric_std:stdulogic_table",":STDULOGIC_TABLE",NULL);
L4ieee_W11numeric_std_C3nau.init((&L4ieee_W11numeric_std_I3_t0_INFO),enumeration(0));
L4ieee_W11numeric_std_C3nau=L4ieee_W11numeric_std_T3_t0(new array_info((&L4ieee_W11numeric_std_I3_t0_INFO)->element_type,(&L4ieee_W11numeric_std_I3_t0_INFO)->index_type,0,downto,1,0),enumeration(2));
L4ieee_W11numeric_std_C3nas.init((&L4ieee_W11numeric_std_I3_t1_INFO),enumeration(0));
L4ieee_W11numeric_std_C3nas=L4ieee_W11numeric_std_T3_t1(new array_info((&L4ieee_W11numeric_std_I3_t1_INFO)->element_type,(&L4ieee_W11numeric_std_I3_t1_INFO)->index_type,0,downto,1,0),enumeration(2));
L4ieee_W11numeric_std_C10no_warning=enumeration(1);
L4ieee_W11numeric_std_C9and_table.init((&L4ieee_W11numeric_std_I15stdulogic_table_INFO));
L4ieee_W11numeric_std_C9and_table=L4ieee_W11numeric_std_T15stdulogic_table(new array_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type,(&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(0))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(2)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(2)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(2)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(2)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(2))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(2)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(2)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(2)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(2)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(2))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1)));
L4ieee_W11numeric_std_C11match_table.init((&L4ieee_W11numeric_std_I15stdulogic_table_INFO));
L4ieee_W11numeric_std_C11match_table=L4ieee_W11numeric_std_T15stdulogic_table(new array_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type,(&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(0)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(0)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W11numeric_std_T15stdulogic_table::E_type(new array_info(parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W11numeric_std_I15stdulogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(3)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(3)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(3)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(3)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3)));
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W11numeric_std_hinfo =
  add_handle("ieee","numeric_std",NULL,NULL,&L4ieee_W11numeric_std_init);

/* end of package body :ieee:numeric_std */
