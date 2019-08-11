#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:std_logic_arith */
/* External declarations */
/* Definitions for enumeration type :IEEE:std_logic_1164:std_ulogic */
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
/** Enumeration info class :IEEE:std_logic_1164:std_logic */
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
extern array_info L4ieee_Q15std_logic_arith_I8unsigned_INFO;
#define L4ieee_Q15std_logic_arith_T8unsigned array_type<enumeration >
#define L4ieee_Q15std_logic_arith_I8unsigned array_info

extern array_info L4ieee_Q15std_logic_arith_I6signed_INFO;
#define L4ieee_Q15std_logic_arith_T6signed array_type<enumeration >
#define L4ieee_Q15std_logic_arith_I6signed array_info

/** Integer info class :ieee:std_logic_arith:small_int */
class L4ieee_Q15std_logic_arith_I9small_int:public integer_info_base{
public:
   L4ieee_Q15std_logic_arith_I9small_int():integer_info_base(0,1,0,1) {};
   static integer low() { return 0; }
   static integer high() { return 1; }
   static integer left() { return 0; }
   static integer right() { return 1; }
};
extern L4ieee_Q15std_logic_arith_I9small_int L4ieee_Q15std_logic_arith_I9small_int_INFO;
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i31(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i34(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i37(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i40(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i43(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i46(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i49(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i52(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i55(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i58(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i61(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i64(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i67(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i70(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i73(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i76(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i79(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i82(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i85(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i88(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i91(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i94(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i97(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i100(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i103(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i106(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i109(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i112(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i115(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i118(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i121(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i124(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i127(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i130(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i133(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i136(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i139(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i142(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i145(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i148(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i151(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i154(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i157(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i160(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i163(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i166(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i169(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i172(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i174(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i176(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i178(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y0_i180(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i182(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i184(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i186(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y0_i188(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_mult_i191(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i194(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i197(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i200(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i203(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i206(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i209(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i212(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i215(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i218(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i221(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i224(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i227(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i230(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i233(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i236(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i239(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i242(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i245(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i248(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i251(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i254(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i257(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i260(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i263(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i266(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i269(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i272(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i275(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i278(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i281(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i284(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i287(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i290(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i293(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i296(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i299(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i302(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i305(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i308(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i311(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i314(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i317(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i320(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i323(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i326(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i329(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i332(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i335(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i338(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i341(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i344(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i347(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i350(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i353(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i356(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i359(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shl_i362(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i365(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shr_i368(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i370(const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i376(const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388(const enumeration ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i391(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i394(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i397(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i400(const enumeration ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412(const enumeration ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:ext */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3ext_i415(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:sxt */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3sxt_i418(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
L4ieee_Q15std_logic_arith_I8unsigned L4ieee_Q15std_logic_arith_I8unsigned_INFO;
L4ieee_Q15std_logic_arith_I6signed L4ieee_Q15std_logic_arith_I6signed_INFO;
L4ieee_Q15std_logic_arith_I9small_int L4ieee_Q15std_logic_arith_I9small_int_INFO;
/* Initialization function for package :ieee:std_logic_arith */
int L3std_Q8standard_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_Q15std_logic_arith_init_done = false;
int L4ieee_Q15std_logic_arith_init(){
if (L4ieee_Q15std_logic_arith_init_done) return 1;
L4ieee_Q15std_logic_arith_init_done=true;
L3std_Q8standard_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_arith.vhdl","std_logic_arith.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":std_logic_arith");
L4ieee_Q15std_logic_arith_I8unsigned_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:std_logic_arith",":ieee:std_logic_arith:unsigned",":UNSIGNED",NULL);
L4ieee_Q15std_logic_arith_I6signed_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:std_logic_arith",":ieee:std_logic_arith:signed",":SIGNED",NULL);
L4ieee_Q15std_logic_arith_I9small_int_INFO.register_type(":ieee:std_logic_arith",":ieee:std_logic_arith:small_int",":SMALL_INT",NULL);
iname.pop();
handle_info *h = get_handle ("ieee","std_logic_arith",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:std_logic_arith */

/* package body :ieee:std_logic_arith */
/* External declarations */
/* Prototype for predefined function :IEEE:std_logic_1164:"/=" */
/* No header for IIR_EnumerationLiteral */
/** Enumeration info class :IEEE:std_logic_1164:ux01 */
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
/* Prototype for subprogram :IEEE:std_logic_1164:"and" */
enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51(const enumeration ,const enumeration );
/* Prototype for subprogram :IEEE:std_logic_1164:"or" */
enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57(const enumeration ,const enumeration );
extern array_info L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO;
#define L4ieee_Q14std_logic_1164_T17std_ulogic_vector array_type<enumeration >
#define L4ieee_Q14std_logic_1164_I17std_ulogic_vector array_info

/* Prototype for subprogram :IEEE:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_not_i99(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :IEEE:std_logic_1164:"xor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63(const enumeration ,const enumeration );
/* Prototype for predefined function :IEEE:std_logic_1164:"=" */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* End of external declarations */
/* Prototype for subprogram :ieee:std_logic_arith:max */
integer L4ieee_W15std_logic_arith_Y3max_i8(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:min */
integer L4ieee_W15std_logic_arith_Y3min_i12(const integer ,const integer );
extern array_info L4ieee_W15std_logic_arith_I8tbl_type_INFO;
#define L4ieee_W15std_logic_arith_T8tbl_type array_type<enumeration >
#define L4ieee_W15std_logic_arith_I8tbl_type array_info

extern array_info L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO;
#define L4ieee_W15std_logic_arith_T16tbl_mvl9_boolean array_type<enumeration >
#define L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean array_info

/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
enumeration L4ieee_W15std_logic_arith_Y11make_binary_i52(const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i55(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i63(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i71(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i79(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i87(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i95(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i103(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:left_signed_arg */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15left_signed_arg_i112(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:left_unsigned_arg */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:mult_signed_arg */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:mult_unsigned_arg */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:mult */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4mult_i128(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:mult */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y4mult_i142(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:minus */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y5minus_i154(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:plus */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4plus_i164(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:unsigned_minus */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y14unsigned_minus_i174(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:unsigned_plus */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y13unsigned_plus_i184(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i194(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_mult_i191(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i200(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i197(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i206(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i203(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i212(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i209(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i31(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i34(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i37(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i40(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i43(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i46(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i49(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i52(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i55(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i58(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i61(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i64(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i67(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i70(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i73(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i76(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i79(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i82(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i85(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i88(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i91(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i94(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i97(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i100(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i103(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i106(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i109(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i112(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i115(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i118(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i121(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i124(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i127(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i130(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i133(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i136(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i139(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i142(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i145(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i148(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i151(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i154(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i157(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i160(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i163(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i166(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i169(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i172(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i174(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i176(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i178(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y0_i180(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i182(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i184(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i186(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y0_i188(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:unsigned_return_boolean */
enumeration L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:signed_return_boolean */
enumeration L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:is_less */
enumeration L4ieee_W15std_logic_arith_Y7is_less_i437(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:is_less_or_equal */
enumeration L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:unsigned_is_less */
enumeration L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:unsigned_is_less_or_equal */
enumeration L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i215(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i218(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i221(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i224(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i227(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i230(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i233(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i236(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i239(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i242(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i245(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i248(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i251(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i254(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i257(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i260(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i263(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i266(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i269(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i272(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i275(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i278(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i281(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i284(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i287(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i290(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i293(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i296(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i299(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i302(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i305(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i308(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:bitwise_eql */
enumeration L4ieee_W15std_logic_arith_Y11bitwise_eql_i601(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_arith:bitwise_neq */
enumeration L4ieee_W15std_logic_arith_Y11bitwise_neq_i607(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i311(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i314(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i317(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i320(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i323(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i326(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i329(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i332(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i335(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i338(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i341(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i344(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i347(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i350(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i353(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i356(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
#define L4ieee_Q15std_logic_arith_Y3shl_i359_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i359(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
#define L4ieee_Q15std_logic_arith_Y3shl_i362_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shl_i362(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
#define L4ieee_Q15std_logic_arith_Y3shr_i365_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i365(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
#define L4ieee_Q15std_logic_arith_Y3shr_i368_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shr_i368(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i370(const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i376(const enumeration );
/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379(const integer ,const integer );
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388(const enumeration ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i391(const integer ,const integer );
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i394_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i394_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i394(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i397_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i397_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i397(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i400_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y11conv_signed_i400_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i400(const enumeration ,const integer );
/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403(const integer ,const integer );
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412(const enumeration ,const integer );
#define L4ieee_Q15std_logic_arith_Y3ext_i415_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3ext_i415_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:ext */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3ext_i415(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
#define L4ieee_Q15std_logic_arith_Y3sxt_i418_T5rtype array_type<enumeration >
#define L4ieee_Q15std_logic_arith_Y3sxt_i418_I5rtype array_info

/* Prototype for subprogram :ieee:std_logic_arith:sxt */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3sxt_i418(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
L4ieee_W15std_logic_arith_T8tbl_type L4ieee_W15std_logic_arith_C10tbl_binary;
L4ieee_W15std_logic_arith_T16tbl_mvl9_boolean L4ieee_W15std_logic_arith_C4is_x;
/* Implementation of subprogram :ieee:std_logic_arith:max */
integer L4ieee_W15std_logic_arith_Y3max_i8(const integer L4ieee_W15std_logic_arith_Y3max_i8_C1l,const integer L4ieee_W15std_logic_arith_Y3max_i8_C1r)
{
    integer L4ieee_W15std_logic_arith_Y3max_i8_V6result;
    L4ieee_W15std_logic_arith_Y3max_i8_V6result=-2147483648LL;
    if((L4ieee_W15std_logic_arith_Y3max_i8_C1l>L4ieee_W15std_logic_arith_Y3max_i8_C1r)) {
      L4ieee_W15std_logic_arith_Y3max_i8_V6result=L4ieee_W15std_logic_arith_Y3max_i8_C1l;
    } else {
      L4ieee_W15std_logic_arith_Y3max_i8_V6result=L4ieee_W15std_logic_arith_Y3max_i8_C1r;
    }
    return L4ieee_W15std_logic_arith_Y3max_i8_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:min */
integer L4ieee_W15std_logic_arith_Y3min_i12(const integer L4ieee_W15std_logic_arith_Y3min_i12_C1l,const integer L4ieee_W15std_logic_arith_Y3min_i12_C1r)
{
    integer L4ieee_W15std_logic_arith_Y3min_i12_V6result;
    L4ieee_W15std_logic_arith_Y3min_i12_V6result=-2147483648LL;
    if((L4ieee_W15std_logic_arith_Y3min_i12_C1l<L4ieee_W15std_logic_arith_Y3min_i12_C1r)) {
      L4ieee_W15std_logic_arith_Y3min_i12_V6result=L4ieee_W15std_logic_arith_Y3min_i12_C1l;
    } else {
      L4ieee_W15std_logic_arith_Y3min_i12_V6result=L4ieee_W15std_logic_arith_Y3min_i12_C1r;
    }
    return L4ieee_W15std_logic_arith_Y3min_i12_V6result;
}
L4ieee_W15std_logic_arith_I8tbl_type L4ieee_W15std_logic_arith_I8tbl_type_INFO;
L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO;
enumeration L4ieee_W15std_logic_arith_itn73_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
enumeration L4ieee_W15std_logic_arith_Y11make_binary_i52(const enumeration L4ieee_W15std_logic_arith_Y11make_binary_i52_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i52_V6result;
    L4ieee_W15std_logic_arith_Y11make_binary_i52_V6result=enumeration(0);
    if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i52_C1a]) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn73_lit),enumeration(1));
      L4ieee_W15std_logic_arith_Y11make_binary_i52_V6result=enumeration(1);
    } else {
      L4ieee_W15std_logic_arith_Y11make_binary_i52_V6result=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i52_C1a];
    }
    return L4ieee_W15std_logic_arith_Y11make_binary_i52_V6result;
}
enumeration L4ieee_W15std_logic_arith_itn74_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i55(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i55_V7one_bit;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i55_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i55_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i55_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn74_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i55_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_L460ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i55_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i55_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i55_L458ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i55_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn75_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i63(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i63_V7one_bit;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i63_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i63_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i63_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn75_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i63_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_L468ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i63_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i63_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i63_L466ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i63_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn76_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i71(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i71_V7one_bit;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y11make_binary_i71_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i71_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i71_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn76_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i71_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_L476ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i71_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i71_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i71_L474ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i71_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn77_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i79(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i79_V7one_bit;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y11make_binary_i79_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i79_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i79_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn77_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i79_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_L484ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i79_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i79_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i79_L482ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i79_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn78_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i87(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i87_V7one_bit;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i87_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i87_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i87_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn78_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i87_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_L492ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i87_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i87_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i87_L490ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i87_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn79_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i95(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i95_V7one_bit;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i95_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i95_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i95_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn79_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i95_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_L5100ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i95_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i95_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i95_L498ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i95_V6result);
}
enumeration L4ieee_W15std_logic_arith_itn80_lit[]={84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,116,104,101,32,114,101,115,117,108,116,32,119,105,108,108,32,98,101,32,39,88,39,40,101,115,41,46};
/* Implementation of subprogram :ieee:std_logic_arith:make_binary */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i103(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a)
{
    enumeration L4ieee_W15std_logic_arith_Y11make_binary_i103_V7one_bit;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_W15std_logic_arith_Y11make_binary_i103_V6result;
    integer L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_lc,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_lc,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_ls;
    L4ieee_W15std_logic_arith_Y11make_binary_i103_V7one_bit=enumeration(0);
    L4ieee_W15std_logic_arith_Y11make_binary_i103_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->right_bound,0)),enumeration(0));
    for (L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i=L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_ls=L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i+=L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_ls,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i_lc--) {
      if(L4ieee_W15std_logic_arith_C4is_x[L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i]]) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+84,0),L4ieee_W15std_logic_arith_itn80_lit),enumeration(1));
        for (L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j=L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_ls=L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j+=L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_ls,L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j_lc--) {
          L4ieee_W15std_logic_arith_Y11make_binary_i103_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_L5108ln_C1j]=enumeration(1);
        }
      } else {
        L4ieee_W15std_logic_arith_Y11make_binary_i103_V6result[L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i]=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_W15std_logic_arith_Y11make_binary_i103_C1a[L4ieee_W15std_logic_arith_Y11make_binary_i103_L5106ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y11make_binary_i103_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:left_signed_arg */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15left_signed_arg_i112(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_C1b)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_V1z;
    L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_V1z.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_C1a.info->left_bound,downto,0,0)),enumeration(0));
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y15left_signed_arg_i112_V1z);
}
/* Implementation of subprogram :ieee:std_logic_arith:left_unsigned_arg */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_C1b)
{
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_V1z;
    L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_V1z.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_C1a.info->left_bound,downto,0,0)),enumeration(0));
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y17left_unsigned_arg_i116_V1z);
}
/* Implementation of subprogram :ieee:std_logic_arith:mult_signed_arg */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_C1b)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_V1z;
    L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_V1z.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,((L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_C1a.info->length+L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_C1b.info->length)-1),downto,0,0)),enumeration(0));
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y15mult_signed_arg_i120_V1z);
}
/* Implementation of subprogram :ieee:std_logic_arith:mult_unsigned_arg */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_C1b)
{
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_V1z;
    L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_V1z.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,((L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_C1a.info->length+L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_C1b.info->length)-1),downto,0,0)),enumeration(0));
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y17mult_unsigned_arg_i124_V1z);
}
enumeration L4ieee_W15std_logic_arith_itn81_lit[]={2,3};
enumeration L4ieee_W15std_logic_arith_itn82_lit[]={2,3};
/* Implementation of subprogram :ieee:std_logic_arith:mult */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4mult_i128(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y4mult_i128_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y4mult_i128_C1b)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4mult_i128_V2ba,L4ieee_W15std_logic_arith_Y4mult_i128_V2pa,L4ieee_W15std_logic_arith_Y4mult_i128_V2aa;
    enumeration L4ieee_W15std_logic_arith_Y4mult_i128_V3neg;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y4mult_i128_C3one;
    integer L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j,L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_lc,L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_lc,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i,L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y4mult_i128_V2ba.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,((L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i128_C1b.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i128_V2pa.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,((L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i128_C1b.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i128_V2aa.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->length,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i128_V3neg=enumeration(0);
    L4ieee_W15std_logic_arith_Y4mult_i128_C3one.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i128_C3one=array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0),L4ieee_W15std_logic_arith_itn82_lit);
    if(((L4ieee_W15std_logic_arith_Y4mult_i128_C1a[L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y4mult_i128_C1b[L4ieee_W15std_logic_arith_Y4mult_i128_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j=L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_ls=L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j+=L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y4mult_i128_V2pa[L4ieee_W15std_logic_arith_Y4mult_i128_L5134ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j=L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_ls=L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j+=L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y4mult_i128_V2pa[L4ieee_W15std_logic_arith_Y4mult_i128_L5136ln_C1j]=enumeration(2);
      }
      L4ieee_W15std_logic_arith_Y4mult_i128_V3neg=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W15std_logic_arith_Y4mult_i128_C1b[L4ieee_W15std_logic_arith_Y4mult_i128_C1b.info->left_bound],L4ieee_W15std_logic_arith_Y4mult_i128_C1a[L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->left_bound]);
      L4ieee_W15std_logic_arith_Y4mult_i128_V2ba=L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (concat<L4ieee_Q15std_logic_arith_T6signed,enumeration>(L4ieee_Q15std_logic_arith_T6signed(new array_info(L4ieee_Q15std_logic_arith_I6signed_INFO.element_type,L4ieee_Q15std_logic_arith_I6signed_INFO.index_type,0,to,0,0),enumeration(2)),L4ieee_Q15std_logic_arith_Y0_i180 (L4ieee_W15std_logic_arith_Y4mult_i128_C1b)),(L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i128_C1b.info->length));
      L4ieee_W15std_logic_arith_Y4mult_i128_V2aa=concat<L4ieee_Q15std_logic_arith_T6signed,enumeration>(L4ieee_Q15std_logic_arith_T6signed(new array_info(L4ieee_Q15std_logic_arith_I6signed_INFO.element_type,L4ieee_Q15std_logic_arith_I6signed_INFO.index_type,0,to,0,0),enumeration(2)),L4ieee_Q15std_logic_arith_Y0_i180 (L4ieee_W15std_logic_arith_Y4mult_i128_C1a));
      for (L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i=0,L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_W15std_logic_arith_Y4mult_i128_C1a.info->length-1)); L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i++,L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i_lc--) {
        if((L4ieee_W15std_logic_arith_Y4mult_i128_V2aa[L4ieee_W15std_logic_arith_Y4mult_i128_L5138ln_C1i]==enumeration(3))) {
          L4ieee_W15std_logic_arith_Y4mult_i128_V2pa=L4ieee_Q15std_logic_arith_Y7op_plus_i34 (L4ieee_W15std_logic_arith_Y4mult_i128_V2pa,L4ieee_W15std_logic_arith_Y4mult_i128_V2ba);
        }
        L4ieee_W15std_logic_arith_Y4mult_i128_V2ba=L4ieee_Q15std_logic_arith_Y3shl_i362 (L4ieee_W15std_logic_arith_Y4mult_i128_V2ba,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0),L4ieee_W15std_logic_arith_itn81_lit));
      }
      if((L4ieee_W15std_logic_arith_Y4mult_i128_V3neg==enumeration(3))) {
        L4ieee_W15std_logic_arith_Y4mult_i128_V2pa=L4ieee_Q15std_logic_arith_Y8op_minus_i124 (0,L4ieee_W15std_logic_arith_Y4mult_i128_V2pa);
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4mult_i128_V2pa);
}
enumeration L4ieee_W15std_logic_arith_itn83_lit[]={2,3};
enumeration L4ieee_W15std_logic_arith_itn84_lit[]={2,3};
/* Implementation of subprogram :ieee:std_logic_arith:mult */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y4mult_i142(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y4mult_i142_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y4mult_i142_C1b)
{
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y4mult_i142_V2ba,L4ieee_W15std_logic_arith_Y4mult_i142_V2pa,L4ieee_W15std_logic_arith_Y4mult_i142_C3one;
    integer L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j,L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_lc,L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_lc,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i,L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y4mult_i142_V2ba.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,((L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i142_C1b.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i142_V2pa.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,((L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i142_C1b.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i142_C3one.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4mult_i142_C3one=array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0),L4ieee_W15std_logic_arith_itn84_lit);
    if(((L4ieee_W15std_logic_arith_Y4mult_i142_C1a[L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y4mult_i142_C1b[L4ieee_W15std_logic_arith_Y4mult_i142_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j=L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_ls=L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j+=L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y4mult_i142_V2pa[L4ieee_W15std_logic_arith_Y4mult_i142_L5146ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j=L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_ls=L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->index_direction,L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->right_bound);L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j+=L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_ls,L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y4mult_i142_V2pa[L4ieee_W15std_logic_arith_Y4mult_i142_L5148ln_C1j]=enumeration(2);
      }
      L4ieee_W15std_logic_arith_Y4mult_i142_V2ba=L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_W15std_logic_arith_Y4mult_i142_C1b,(L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->length+L4ieee_W15std_logic_arith_Y4mult_i142_C1b.info->length));
      for (L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i=0,L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_W15std_logic_arith_Y4mult_i142_C1a.info->length-1)); L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i++,L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i_lc--) {
        if((L4ieee_W15std_logic_arith_Y4mult_i142_C1a[L4ieee_W15std_logic_arith_Y4mult_i142_L5150ln_C1i]==enumeration(3))) {
          L4ieee_W15std_logic_arith_Y4mult_i142_V2pa=L4ieee_Q15std_logic_arith_Y7op_plus_i31 (L4ieee_W15std_logic_arith_Y4mult_i142_V2pa,L4ieee_W15std_logic_arith_Y4mult_i142_V2ba);
        }
        L4ieee_W15std_logic_arith_Y4mult_i142_V2ba=L4ieee_Q15std_logic_arith_Y3shl_i359 (L4ieee_W15std_logic_arith_Y4mult_i142_V2ba,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,1,downto,0,0),L4ieee_W15std_logic_arith_itn83_lit));
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y4mult_i142_V2pa);
}
/* Implementation of subprogram :ieee:std_logic_arith:minus */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y5minus_i154(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y5minus_i154_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y5minus_i154_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y5minus_i154_V5carry;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_W15std_logic_arith_Y5minus_i154_V2bv;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y5minus_i154_V3sum;
    integer L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j,L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j_lc,L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i,L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y5minus_i154_V5carry=enumeration(0);
    L4ieee_W15std_logic_arith_Y5minus_i154_V2bv.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y5minus_i154_V3sum.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound,downto,0,0)),enumeration(0));
    if(((L4ieee_W15std_logic_arith_Y5minus_i154_C1a[L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y5minus_i154_C1b[L4ieee_W15std_logic_arith_Y5minus_i154_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j=L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j_lc=down_range_to_length<integer>(L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound,0); L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j--,L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y5minus_i154_V3sum[L4ieee_W15std_logic_arith_Y5minus_i154_L5158ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_W15std_logic_arith_Y5minus_i154_V5carry=enumeration(3);
      L4ieee_W15std_logic_arith_Y5minus_i154_V2bv=L4ieee_Q14std_logic_1164_Y6op_not_i99 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154_C1b));
      for (L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i=0,L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y5minus_i154_C1a.info->left_bound); L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i++,L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y5minus_i154_V3sum[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W15std_logic_arith_Y5minus_i154_C1a[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i],L4ieee_W15std_logic_arith_Y5minus_i154_V2bv[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i]),L4ieee_W15std_logic_arith_Y5minus_i154_V5carry);
        L4ieee_W15std_logic_arith_Y5minus_i154_V5carry=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y5minus_i154_C1a[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i],L4ieee_W15std_logic_arith_Y5minus_i154_V2bv[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y5minus_i154_C1a[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i],L4ieee_W15std_logic_arith_Y5minus_i154_V5carry)),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y5minus_i154_V5carry,L4ieee_W15std_logic_arith_Y5minus_i154_V2bv[L4ieee_W15std_logic_arith_Y5minus_i154_L5160ln_C1i]));
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154_V3sum);
}
/* Implementation of subprogram :ieee:std_logic_arith:plus */
L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4plus_i164(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y4plus_i164_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y4plus_i164_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y4plus_i164_V5carry;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_W15std_logic_arith_Y4plus_i164_V3sum,L4ieee_W15std_logic_arith_Y4plus_i164_V2bv;
    integer L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j,L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j_lc,L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i,L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y4plus_i164_V5carry=enumeration(0);
    L4ieee_W15std_logic_arith_Y4plus_i164_V3sum.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y4plus_i164_V2bv.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound,downto,0,0)),enumeration(0));
    if(((L4ieee_W15std_logic_arith_Y4plus_i164_C1a[L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y4plus_i164_C1b[L4ieee_W15std_logic_arith_Y4plus_i164_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j=L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j_lc=down_range_to_length<integer>(L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound,0); L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j--,L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y4plus_i164_V3sum[L4ieee_W15std_logic_arith_Y4plus_i164_L5168ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_W15std_logic_arith_Y4plus_i164_V5carry=enumeration(2);
      L4ieee_W15std_logic_arith_Y4plus_i164_V2bv=L4ieee_W15std_logic_arith_Y4plus_i164_C1b;
      for (L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i=0,L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y4plus_i164_C1a.info->left_bound); L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i++,L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y4plus_i164_V3sum[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W15std_logic_arith_Y4plus_i164_C1a[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i],L4ieee_W15std_logic_arith_Y4plus_i164_V2bv[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i]),L4ieee_W15std_logic_arith_Y4plus_i164_V5carry);
        L4ieee_W15std_logic_arith_Y4plus_i164_V5carry=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y4plus_i164_C1a[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i],L4ieee_W15std_logic_arith_Y4plus_i164_V2bv[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y4plus_i164_C1a[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i],L4ieee_W15std_logic_arith_Y4plus_i164_V5carry)),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y4plus_i164_V5carry,L4ieee_W15std_logic_arith_Y4plus_i164_V2bv[L4ieee_W15std_logic_arith_Y4plus_i164_L5170ln_C1i]));
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164_V3sum);
}
/* Implementation of subprogram :ieee:std_logic_arith:unsigned_minus */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y14unsigned_minus_i174(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V3sum;
    integer L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j_lc,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry=enumeration(0);
    L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V3sum.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound,downto,0,0)),enumeration(0));
    if(((L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1b[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j=L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j_lc=down_range_to_length<integer>(L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound,0); L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j--,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V3sum[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5178ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry=enumeration(3);
      L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv=L4ieee_Q14std_logic_1164_Y6op_not_i99 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1b));
      for (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i=0,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a.info->left_bound); L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i++,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V3sum[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i],L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i]),L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry);
        L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i],L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_C1a[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i],L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry)),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V5carry,L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V2bv[L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_L5180ln_C1i]));
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y14unsigned_minus_i174_V3sum);
}
/* Implementation of subprogram :ieee:std_logic_arith:unsigned_plus */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y13unsigned_plus_i184(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V3sum,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv;
    integer L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j_lc,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry=enumeration(0);
    L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V3sum.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound,downto,0,0)),enumeration(0));
    L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound,downto,0,0)),enumeration(0));
    if(((L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound]==enumeration(1))||(L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1b[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1b.info->left_bound]==enumeration(1)))) {
      for (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j=L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j_lc=down_range_to_length<integer>(L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound,0); L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j_lc!=0; L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j--,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j_lc--) {
        L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V3sum[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5188ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry=enumeration(2);
      L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv=L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1b;
      for (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i=0,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a.info->left_bound); L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i++,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V3sum[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i]=L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_Q14std_logic_1164_Y6op_xor_i63 (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i],L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i]),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry);
        L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry=L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y5op_or_i57 (L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i],L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i]),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_C1a[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i],L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry)),L4ieee_Q14std_logic_1164_Y6op_and_i51 (L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V5carry,L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V2bv[L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_L5190ln_C1i]));
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184_V3sum);
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i194(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1r)
{
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1l.info->length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i194_C1r.info->length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_mult_i191(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1r)
{
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y4mult_i142 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1l.info->length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i191_C1r.info->length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i200(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1r)
{
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1l,(L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1l.info->length+1)),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i200_C1r.info->length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_mult_i197(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1r)
{
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1l.info->length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1r,(L4ieee_Q15std_logic_arith_Y7op_mult_i197_C1r.info->length+1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i206(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1r)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1l.info->length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i206_C1r.info->length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i203(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1r)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4mult_i142 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1l.info->length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i203_C1r.info->length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i212(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1r)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1l,(L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1l.info->length+1)),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1r,L4ieee_Q15std_logic_arith_Y7op_mult_i212_C1r.info->length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i209(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1r)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4mult_i128 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1l,L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1l.info->length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1r,(L4ieee_Q15std_logic_arith_Y7op_mult_i209_C1r.info->length+1)))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i31(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i31_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i31_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1l.info->length,L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i31_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i31_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i31_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i34(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i34_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i34_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1l.info->length,L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i34_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i34_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i34_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i37(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i37_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i37_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i37_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i37_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i37_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i40(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i40_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i40_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1l.info->length,(L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1r.info->length+1));
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i40_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i40_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i40_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i43(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i43_C1l,const integer L4ieee_Q15std_logic_arith_Y7op_plus_i43_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i43_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i43_C6length=(L4ieee_Q15std_logic_arith_Y7op_plus_i43_C1l.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i43_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i43_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i43_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i43_C6length)),(L4ieee_Q15std_logic_arith_Y7op_plus_i43_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i46(const integer L4ieee_Q15std_logic_arith_Y7op_plus_i46_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i46_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i46_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i46_C6length=(L4ieee_Q15std_logic_arith_Y7op_plus_i46_C1r.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i46_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i46_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i46_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i46_C6length)),(L4ieee_Q15std_logic_arith_Y7op_plus_i46_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i49(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i49_C1l,const integer L4ieee_Q15std_logic_arith_Y7op_plus_i49_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i49_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i49_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i49_C1l.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i49_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i49_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i49_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i49_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i52(const integer L4ieee_Q15std_logic_arith_Y7op_plus_i52_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i52_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i52_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i52_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i52_C1r.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i52_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i52_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i52_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i52_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i55(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i55_C1l,const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i55_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i55_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i55_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i55_C1l.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i55_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i55_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388 (L4ieee_Q15std_logic_arith_Y7op_plus_i55_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i55_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i58(const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i58_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i58_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i58_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i58_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i58_C1r.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388 (L4ieee_Q15std_logic_arith_Y7op_plus_i58_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i58_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i58_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i58_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i61(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i61_C1l,const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i61_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i61_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i61_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i61_C1l.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i61_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i61_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y7op_plus_i61_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i61_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i64(const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i64_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i64_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i64_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i64_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i64_C1r.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y7op_plus_i64_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i64_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i64_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i64_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i67(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i67_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i67_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1l.info->length,L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i67_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i67_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i67_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i70(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i70_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i70_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1l.info->length,L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i70_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i70_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i70_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i73(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i73_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i73_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i73_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i73_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i73_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i76(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i76_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i76_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1l.info->length,(L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1r.info->length+1));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i76_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i76_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i76_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i79(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i79_C1l,const integer L4ieee_Q15std_logic_arith_Y7op_plus_i79_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i79_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i79_C6length=(L4ieee_Q15std_logic_arith_Y7op_plus_i79_C1l.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i79_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i79_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i79_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i79_C6length)),(L4ieee_Q15std_logic_arith_Y7op_plus_i79_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i82(const integer L4ieee_Q15std_logic_arith_Y7op_plus_i82_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i82_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i82_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i82_C6length=(L4ieee_Q15std_logic_arith_Y7op_plus_i82_C1r.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i82_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i82_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y7op_plus_i82_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i82_C6length)),(L4ieee_Q15std_logic_arith_Y7op_plus_i82_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i85(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i85_C1l,const integer L4ieee_Q15std_logic_arith_Y7op_plus_i85_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i85_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i85_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i85_C1l.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i85_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i85_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i85_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i85_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i88(const integer L4ieee_Q15std_logic_arith_Y7op_plus_i88_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i88_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i88_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i88_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i88_C1r.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y7op_plus_i88_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i88_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i88_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i88_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i91(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i91_C1l,const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i91_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i91_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i91_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i91_C1l.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i91_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i91_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388 (L4ieee_Q15std_logic_arith_Y7op_plus_i91_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i91_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i94(const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i94_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i94_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i94_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i94_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i94_C1r.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y13unsigned_plus_i184 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388 (L4ieee_Q15std_logic_arith_Y7op_plus_i94_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i94_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y7op_plus_i94_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i94_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i97(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i97_C1l,const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i97_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i97_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i97_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i97_C1l.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i97_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i97_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y7op_plus_i97_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i97_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i100(const enumeration L4ieee_Q15std_logic_arith_Y7op_plus_i100_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i100_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y7op_plus_i100_C6length;
    L4ieee_Q15std_logic_arith_Y7op_plus_i100_C6length=L4ieee_Q15std_logic_arith_Y7op_plus_i100_C1r.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y4plus_i164 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y7op_plus_i100_C1l,L4ieee_Q15std_logic_arith_Y7op_plus_i100_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y7op_plus_i100_C1r,L4ieee_Q15std_logic_arith_Y7op_plus_i100_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i103(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i103_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i103_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1l.info->length,L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W15std_logic_arith_Y14unsigned_minus_i174 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i103_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y8op_minus_i103_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i103_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i106(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i106_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i106_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1l.info->length,L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i106_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i106_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i106_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i109(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i109_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i109_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1r.info->length);
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i109_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i109_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i109_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i112(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i112_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i112_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1l.info->length,(L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1r.info->length+1));
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i112_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i112_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i112_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i115(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i115_C1l,const integer L4ieee_Q15std_logic_arith_Y8op_minus_i115_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i115_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i115_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i115_C1l.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i115_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i115_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i115_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i115_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i115_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i118(const integer L4ieee_Q15std_logic_arith_Y8op_minus_i118_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i118_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i118_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i118_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i118_C1r.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i118_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i118_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i118_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i118_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i118_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i121(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i121_C1l,const integer L4ieee_Q15std_logic_arith_Y8op_minus_i121_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i121_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i121_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i121_C1l.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i121_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i121_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i121_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i121_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i124(const integer L4ieee_Q15std_logic_arith_Y8op_minus_i124_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i124_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i124_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i124_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i124_C1r.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i124_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i124_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i124_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i124_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i127(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i127_C1l,const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i127_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i127_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i127_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i127_C1l.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i127_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i127_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i127_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i127_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i127_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y8op_minus_i130(const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i130_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i130_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i130_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i130_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i130_C1r.info->length+1);
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i130_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i130_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i130_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i130_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i130_C6length-1)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i133(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i133_C1l,const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i133_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i133_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i133_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i133_C1l.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i133_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i133_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i133_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i133_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i136(const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i136_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i136_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i136_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i136_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i136_C1r.info->length;
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i136_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i136_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i136_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i136_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i139(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i139_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i139_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1l.info->length,L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y14unsigned_minus_i174 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i139_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y8op_minus_i139_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i139_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i142(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i142_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i142_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1l.info->length,L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i142_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i142_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i142_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i145(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i145_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i145_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1r.info->length);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i145_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i145_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i145_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i148(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i148_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i148_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1l.info->length,(L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1r.info->length+1));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i148_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i148_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i148_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i151(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i151_C1l,const integer L4ieee_Q15std_logic_arith_Y8op_minus_i151_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i151_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i151_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i151_C1l.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i151_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i151_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i151_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i151_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i151_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i154(const integer L4ieee_Q15std_logic_arith_Y8op_minus_i154_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i154_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i154_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i154_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i154_C1r.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i154_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i154_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i154_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i154_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i154_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i157(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i157_C1l,const integer L4ieee_Q15std_logic_arith_Y8op_minus_i157_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i157_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i157_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i157_C1l.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i157_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i157_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i157_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i157_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i160(const integer L4ieee_Q15std_logic_arith_Y8op_minus_i160_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i160_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i160_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i160_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i160_C1r.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y8op_minus_i160_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i160_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i160_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i160_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i163(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i163_C1l,const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i163_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i163_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i163_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i163_C1l.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i163_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i163_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i163_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i163_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i163_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i166(const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i166_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y8op_minus_i166_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i166_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i166_C6length=(L4ieee_Q15std_logic_arith_Y8op_minus_i166_C1r.info->length+1);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385 (L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i166_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i166_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y8op_minus_i166_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i166_C6length)),(L4ieee_Q15std_logic_arith_Y8op_minus_i166_C6length-1))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i169(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i169_C1l,const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i169_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i169_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i169_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i169_C1l.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i169_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i169_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i169_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i169_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i172(const enumeration L4ieee_Q15std_logic_arith_Y8op_minus_i172_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i172_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y8op_minus_i172_C6length;
    L4ieee_Q15std_logic_arith_Y8op_minus_i172_C6length=L4ieee_Q15std_logic_arith_Y8op_minus_i172_C1r.info->length;
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_W15std_logic_arith_Y5minus_i154 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400 (L4ieee_Q15std_logic_arith_Y8op_minus_i172_C1l,L4ieee_Q15std_logic_arith_Y8op_minus_i172_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y8op_minus_i172_C1r,L4ieee_Q15std_logic_arith_Y8op_minus_i172_C6length))));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y7op_plus_i174(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i174_C1l)
{
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y7op_plus_i174_C1l);
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y7op_plus_i176(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i176_C1l)
{
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y7op_plus_i176_C1l);
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i178(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i178_C1l)
{
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y8op_minus_i124 (0,L4ieee_Q15std_logic_arith_Y8op_minus_i178_C1l));
}
/* Implementation of subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y0_i180(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y0_i180_C1l)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y0_i180_V6result;
    L4ieee_Q15std_logic_arith_Y0_i180_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y0_i180_C1l.info->length-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q15std_logic_arith_Y0_i180_C1l[L4ieee_Q15std_logic_arith_Y0_i180_C1l.info->left_bound]==enumeration(2))||(L4ieee_Q15std_logic_arith_Y0_i180_C1l[L4ieee_Q15std_logic_arith_Y0_i180_C1l.info->left_bound]==enumeration(6)))) {
      L4ieee_Q15std_logic_arith_Y0_i180_V6result=L4ieee_Q15std_logic_arith_Y0_i180_C1l;
    } else {
      L4ieee_Q15std_logic_arith_Y0_i180_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i124 (0,L4ieee_Q15std_logic_arith_Y0_i180_C1l);
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y0_i180_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i182(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y7op_plus_i182_C1l)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y7op_plus_i182_C1l));
}
/* Implementation of subprogram :ieee:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i184(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y7op_plus_i184_C1l)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y7op_plus_i184_C1l));
}
/* Implementation of subprogram :ieee:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i186(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y8op_minus_i186_C1l)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y8op_minus_i186_V3tmp;
    L4ieee_Q15std_logic_arith_Y8op_minus_i186_V3tmp.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y8op_minus_i186_C1l.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y8op_minus_i186_V3tmp=L4ieee_Q15std_logic_arith_Y8op_minus_i124 (0,L4ieee_Q15std_logic_arith_Y8op_minus_i186_C1l);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y8op_minus_i186_V3tmp));
}
/* Implementation of subprogram :ieee:std_logic_arith:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y0_i188(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y0_i188_C1l)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y0_i188_V3tmp;
    L4ieee_Q15std_logic_arith_Y0_i188_V3tmp.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y0_i188_C1l.info->length-1),downto,0,0)),enumeration(0));
    if(((L4ieee_Q15std_logic_arith_Y0_i188_C1l[L4ieee_Q15std_logic_arith_Y0_i188_C1l.info->left_bound]==enumeration(2))||(L4ieee_Q15std_logic_arith_Y0_i188_C1l[L4ieee_Q15std_logic_arith_Y0_i188_C1l.info->left_bound]==enumeration(6)))) {
      L4ieee_Q15std_logic_arith_Y0_i188_V3tmp=L4ieee_Q15std_logic_arith_Y0_i188_C1l;
    } else {
      L4ieee_Q15std_logic_arith_Y0_i188_V3tmp=L4ieee_Q15std_logic_arith_Y8op_minus_i124 (0,L4ieee_Q15std_logic_arith_Y0_i188_C1l);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y0_i188_V3tmp));
}
/* Implementation of subprogram :ieee:std_logic_arith:unsigned_return_boolean */
enumeration L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429_V1z;
    L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429_V1z=enumeration(0);
    return L4ieee_W15std_logic_arith_Y23unsigned_return_boolean_i429_V1z;
}
/* Implementation of subprogram :ieee:std_logic_arith:signed_return_boolean */
enumeration L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433_C1b)
{
    enumeration L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433_V1z;
    L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433_V1z=enumeration(0);
    return L4ieee_W15std_logic_arith_Y21signed_return_boolean_i433_V1z;
}
/* Implementation of subprogram :ieee:std_logic_arith:is_less */
enumeration L4ieee_W15std_logic_arith_Y7is_less_i437(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y7is_less_i437_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y7is_less_i437_C1b)
{
    integer L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign;
    enumeration L4ieee_W15std_logic_arith_Y7is_less_i437_V6result,L4ieee_W15std_logic_arith_Y7is_less_i437_V6b_is_1,L4ieee_W15std_logic_arith_Y7is_less_i437_V6a_is_0;
    integer L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i,L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign=L4ieee_W15std_logic_arith_Y7is_less_i437_C1a.info->left_bound;
    L4ieee_W15std_logic_arith_Y7is_less_i437_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y7is_less_i437_V6b_is_1=enumeration(0);
    L4ieee_W15std_logic_arith_Y7is_less_i437_V6a_is_0=enumeration(0);
    if((L4ieee_W15std_logic_arith_Y7is_less_i437_C1a[L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign]!=L4ieee_W15std_logic_arith_Y7is_less_i437_C1b[L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign])) {
      L4ieee_W15std_logic_arith_Y7is_less_i437_V6result=(L4ieee_W15std_logic_arith_Y7is_less_i437_C1a[L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign]==enumeration(3));
    } else {
      L4ieee_W15std_logic_arith_Y7is_less_i437_V6result=enumeration(0);
      for (L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i=0,L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_W15std_logic_arith_Y7is_less_i437_C4sign-1)); L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i++,L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y7is_less_i437_V6a_is_0=(L4ieee_W15std_logic_arith_Y7is_less_i437_C1a[L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i]==enumeration(2));
        L4ieee_W15std_logic_arith_Y7is_less_i437_V6b_is_1=(L4ieee_W15std_logic_arith_Y7is_less_i437_C1b[L4ieee_W15std_logic_arith_Y7is_less_i437_L5442ln_C1i]==enumeration(3));
        L4ieee_W15std_logic_arith_Y7is_less_i437_V6result=(((L4ieee_W15std_logic_arith_Y7is_less_i437_V6a_is_0&&L4ieee_W15std_logic_arith_Y7is_less_i437_V6b_is_1)||(L4ieee_W15std_logic_arith_Y7is_less_i437_V6a_is_0&&L4ieee_W15std_logic_arith_Y7is_less_i437_V6result))||(L4ieee_W15std_logic_arith_Y7is_less_i437_V6b_is_1&&L4ieee_W15std_logic_arith_Y7is_less_i437_V6result));
      }
    }
    return L4ieee_W15std_logic_arith_Y7is_less_i437_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:is_less_or_equal */
enumeration L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1a,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1b)
{
    integer L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign;
    enumeration L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result,L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6b_is_1,L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6a_is_0;
    integer L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i,L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign=L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1a.info->left_bound;
    L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6b_is_1=enumeration(0);
    L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6a_is_0=enumeration(0);
    if((L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1a[L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign]!=L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1b[L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign])) {
      L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result=(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1a[L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign]==enumeration(3));
    } else {
      L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result=enumeration(1);
      for (L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i=0,L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C4sign-1)); L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i++,L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i_lc--) {
        L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6a_is_0=(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1a[L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i]==enumeration(2));
        L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6b_is_1=(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_C1b[L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_L5451ln_C1i]==enumeration(3));
        L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result=(((L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6a_is_0&&L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6b_is_1)||(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6a_is_0&&L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result))||(L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6b_is_1&&L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result));
      }
    }
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:unsigned_is_less */
enumeration L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C1b)
{
    integer L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C4sign;
    enumeration L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6b_is_1,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6a_is_0;
    integer L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C4sign=L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C1a.info->left_bound;
    L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6b_is_1=enumeration(0);
    L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6a_is_0=enumeration(0);
    L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result=enumeration(0);
    for (L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i=0,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C4sign); L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i++,L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i_lc--) {
      L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6a_is_0=(L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C1a[L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i]==enumeration(2));
      L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6b_is_1=(L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_C1b[L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_L5460ln_C1i]==enumeration(3));
      L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result=(((L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6a_is_0&&L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6b_is_1)||(L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6a_is_0&&L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result))||(L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6b_is_1&&L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result));
    }
    return L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:unsigned_is_less_or_equal */
enumeration L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C1a,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C1b)
{
    integer L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C4sign;
    enumeration L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6b_is_1,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6a_is_0;
    integer L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i_lc;
    L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C4sign=L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C1a.info->left_bound;
    L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6b_is_1=enumeration(0);
    L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6a_is_0=enumeration(0);
    L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result=enumeration(1);
    for (L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i=0,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C4sign); L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i++,L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i_lc--) {
      L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6a_is_0=(L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C1a[L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i]==enumeration(2));
      L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6b_is_1=(L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_C1b[L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_L5469ln_C1i]==enumeration(3));
      L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result=(((L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6a_is_0&&L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6b_is_1)||(L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6a_is_0&&L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result))||(L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6b_is_1&&L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result));
    }
    return L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i215(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i215_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i215_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i215_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_lt_i215_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i215_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i218(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i218_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i218_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i218_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i218_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i218_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i221(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i221_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i221_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i221_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i221_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i221_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i224(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i224_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i224_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i224_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_lt_i224_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i224_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i227(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i227_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_lt_i227_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i227_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i227_C6length=(L4ieee_Q15std_logic_arith_Y5op_lt_i227_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_lt_i227_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i227_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_lt_i227_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i227_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i230(const integer L4ieee_Q15std_logic_arith_Y5op_lt_i230_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_lt_i230_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i230_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i230_C6length=(L4ieee_Q15std_logic_arith_Y5op_lt_i230_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_lt_i230_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i230_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_lt_i230_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i230_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i233(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i233_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_lt_i233_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i233_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i233_C6length=L4ieee_Q15std_logic_arith_Y5op_lt_i233_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i233_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i233_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_lt_i233_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i233_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i236(const integer L4ieee_Q15std_logic_arith_Y5op_lt_i236_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_lt_i236_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_lt_i236_C6length;
    L4ieee_Q15std_logic_arith_Y5op_lt_i236_C6length=L4ieee_Q15std_logic_arith_Y5op_lt_i236_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_lt_i236_C1l,L4ieee_Q15std_logic_arith_Y5op_lt_i236_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_lt_i236_C1r,L4ieee_Q15std_logic_arith_Y5op_lt_i236_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i239(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i239_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i239_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i239_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i239_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_le_i239_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_le_i239_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_le_i239_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i239_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_le_i239_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i239_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i242(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i242_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i242_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i242_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i242_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_le_i242_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_le_i242_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i242_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i242_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i242_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i242_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i245(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i245_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i245_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i245_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i245_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_le_i245_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_le_i245_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_le_i245_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i245_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i245_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i245_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i248(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i248_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i248_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i248_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i248_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_le_i248_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_le_i248_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i248_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i248_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_le_i248_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i248_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i251(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i251_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_le_i251_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i251_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i251_C6length=(L4ieee_Q15std_logic_arith_Y5op_le_i251_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_le_i251_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i251_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_le_i251_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i251_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i254(const integer L4ieee_Q15std_logic_arith_Y5op_le_i254_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_le_i254_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i254_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i254_C6length=(L4ieee_Q15std_logic_arith_Y5op_le_i254_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_le_i254_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i254_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_le_i254_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i254_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i257(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i257_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_le_i257_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i257_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i257_C6length=L4ieee_Q15std_logic_arith_Y5op_le_i257_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i257_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i257_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_le_i257_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i257_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i260(const integer L4ieee_Q15std_logic_arith_Y5op_le_i260_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_le_i260_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_le_i260_C6length;
    L4ieee_Q15std_logic_arith_Y5op_le_i260_C6length=L4ieee_Q15std_logic_arith_Y5op_le_i260_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_le_i260_C1l,L4ieee_Q15std_logic_arith_Y5op_le_i260_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_le_i260_C1r,L4ieee_Q15std_logic_arith_Y5op_le_i260_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i263(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i263_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i263_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16unsigned_is_less_i455 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i263_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_gt_i263_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i263_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i266(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i266_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i266_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i266_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i266_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i266_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i269(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i269_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i269_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i269_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_gt_i269_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i269_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i272(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i272_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i272_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i272_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i272_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i272_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i275(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i275_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_gt_i275_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i275_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i275_C6length=(L4ieee_Q15std_logic_arith_Y5op_gt_i275_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_gt_i275_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i275_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_gt_i275_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i275_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i278(const integer L4ieee_Q15std_logic_arith_Y5op_gt_i278_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_gt_i278_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i278_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i278_C6length=(L4ieee_Q15std_logic_arith_Y5op_gt_i278_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_gt_i278_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i278_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_gt_i278_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i278_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i281(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i281_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_gt_i281_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i281_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i281_C6length=L4ieee_Q15std_logic_arith_Y5op_gt_i281_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_gt_i281_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i281_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i281_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i281_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i284(const integer L4ieee_Q15std_logic_arith_Y5op_gt_i284_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_gt_i284_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_gt_i284_C6length;
    L4ieee_Q15std_logic_arith_Y5op_gt_i284_C6length=L4ieee_Q15std_logic_arith_Y5op_gt_i284_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y7is_less_i437 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_gt_i284_C1r,L4ieee_Q15std_logic_arith_Y5op_gt_i284_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_gt_i284_C1l,L4ieee_Q15std_logic_arith_Y5op_gt_i284_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i287(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i287_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i287_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y25unsigned_is_less_or_equal_i464 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i287_C6length),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_ge_i287_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i287_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i290(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i290_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i290_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i290_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i290_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i290_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i293(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i293_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i293_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i293_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ge_i293_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i293_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i296(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i296_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i296_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i296_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i296_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i296_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i299(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i299_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_ge_i299_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i299_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i299_C6length=(L4ieee_Q15std_logic_arith_Y5op_ge_i299_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ge_i299_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i299_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ge_i299_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i299_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i302(const integer L4ieee_Q15std_logic_arith_Y5op_ge_i302_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ge_i302_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i302_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i302_C6length=(L4ieee_Q15std_logic_arith_Y5op_ge_i302_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ge_i302_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i302_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ge_i302_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i302_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i305(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i305_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_ge_i305_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i305_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i305_C6length=L4ieee_Q15std_logic_arith_Y5op_ge_i305_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ge_i305_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i305_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i305_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i305_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i308(const integer L4ieee_Q15std_logic_arith_Y5op_ge_i308_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ge_i308_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ge_i308_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ge_i308_C6length=L4ieee_Q15std_logic_arith_Y5op_ge_i308_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y16is_less_or_equal_i446 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ge_i308_C1r,L4ieee_Q15std_logic_arith_Y5op_ge_i308_C6length),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ge_i308_C1l,L4ieee_Q15std_logic_arith_Y5op_ge_i308_C6length));
}
/* Implementation of subprogram :ieee:std_logic_arith:bitwise_eql */
enumeration L4ieee_W15std_logic_arith_Y11bitwise_eql_i601(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1r)
{
    enumeration L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_V6result;
    integer L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_lc,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_ls;
    L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_V6result=enumeration(1);
    for (L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i=L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l.info->left_bound,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_ls=L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l.info->left_bound,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l.info->index_direction,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l.info->right_bound);L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i+=L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_ls,L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i_lc--) {
      if((L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1l[L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i]!=L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_C1r[L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_L5603ln_C1i])) {
        L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_V6result=enumeration(0);
      }
    }
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:bitwise_neq */
enumeration L4ieee_W15std_logic_arith_Y11bitwise_neq_i607(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1r)
{
    enumeration L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_V6result;
    integer L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_lc,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_ls;
    L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_V6result=enumeration(0);
    L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_V6result=enumeration(0);
    for (L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i=L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l.info->left_bound,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_ls=L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l.info->index_direction==to?+1:-1,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_lc=range_to_length<integer>(L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l.info->left_bound,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l.info->index_direction,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l.info->right_bound);L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_lc!=0; L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i+=L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_ls,L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i_lc--) {
      if((L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1l[L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i]!=L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_C1r[L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_L5609ln_C1i])) {
        L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_V6result=enumeration(1);
      }
    }
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i311(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i311_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i311_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i311_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_eq_i311_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i311_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i314(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i314_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i314_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i314_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i314_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i314_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i317(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i317_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i317_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i317_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i317_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i317_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i320(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i320_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i320_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i320_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_eq_i320_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i320_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i323(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i323_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_eq_i323_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i323_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i323_C6length=(L4ieee_Q15std_logic_arith_Y5op_eq_i323_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_eq_i323_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i323_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_eq_i323_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i323_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i326(const integer L4ieee_Q15std_logic_arith_Y5op_eq_i326_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_eq_i326_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i326_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i326_C6length=(L4ieee_Q15std_logic_arith_Y5op_eq_i326_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_eq_i326_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i326_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_eq_i326_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i326_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i329(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i329_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_eq_i329_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i329_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i329_C6length=L4ieee_Q15std_logic_arith_Y5op_eq_i329_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i329_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i329_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_eq_i329_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i329_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i332(const integer L4ieee_Q15std_logic_arith_Y5op_eq_i332_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_eq_i332_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_eq_i332_C6length;
    L4ieee_Q15std_logic_arith_Y5op_eq_i332_C6length=L4ieee_Q15std_logic_arith_Y5op_eq_i332_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y11bitwise_eql_i601 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_eq_i332_C1l,L4ieee_Q15std_logic_arith_Y5op_eq_i332_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_eq_i332_C1r,L4ieee_Q15std_logic_arith_Y5op_eq_i332_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i335(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i335_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i335_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i335_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382 (L4ieee_Q15std_logic_arith_Y5op_ne_i335_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i335_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i338(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i338_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i338_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1l.info->length,L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i338_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i338_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i338_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i341(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i341_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i341_C6length=L4ieee_W15std_logic_arith_Y3max_i8 ((L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1l.info->length+1),L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1r.info->length);
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i341_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i341_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i341_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i344(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i344_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i344_C6length=L4ieee_W15std_logic_arith_Y3max_i8 (L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1l.info->length,(L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1r.info->length+1));
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i344_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ne_i344_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i344_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i347(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i347_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_ne_i347_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i347_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i347_C6length=(L4ieee_Q15std_logic_arith_Y5op_ne_i347_C1l.info->length+1);
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ne_i347_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i347_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ne_i347_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i347_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i350(const integer L4ieee_Q15std_logic_arith_Y5op_ne_i350_C1l,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y5op_ne_i350_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i350_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i350_C6length=(L4ieee_Q15std_logic_arith_Y5op_ne_i350_C1r.info->length+1);
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ne_i350_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i350_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394 (L4ieee_Q15std_logic_arith_Y5op_ne_i350_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i350_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i353(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i353_C1l,const integer L4ieee_Q15std_logic_arith_Y5op_ne_i353_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i353_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i353_C6length=L4ieee_Q15std_logic_arith_Y5op_ne_i353_C1l.info->length;
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i353_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i353_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ne_i353_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i353_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i356(const integer L4ieee_Q15std_logic_arith_Y5op_ne_i356_C1l,const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y5op_ne_i356_C1r)
{
    integer L4ieee_Q15std_logic_arith_Y5op_ne_i356_C6length;
    L4ieee_Q15std_logic_arith_Y5op_ne_i356_C6length=L4ieee_Q15std_logic_arith_Y5op_ne_i356_C1r.info->length;
    return L4ieee_W15std_logic_arith_Y11bitwise_neq_i607 (array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391 (L4ieee_Q15std_logic_arith_Y5op_ne_i356_C1l,L4ieee_Q15std_logic_arith_Y5op_ne_i356_C6length)),array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397 (L4ieee_Q15std_logic_arith_Y5op_ne_i356_C1r,L4ieee_Q15std_logic_arith_Y5op_ne_i356_C6length)));
}
/* Implementation of subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i359(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shl_i359_C3arg,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shl_i359_C5count)
{
    integer L4ieee_Q15std_logic_arith_Y3shl_i359_C11control_msb;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i359_V7control;
    integer L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb;
    L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y3shl_i359_T5rtype L4ieee_Q15std_logic_arith_Y3shl_i359_V4temp,L4ieee_Q15std_logic_arith_Y3shl_i359_V6result;
    integer L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j,L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i_lc,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3shl_i359_C11control_msb=(L4ieee_Q15std_logic_arith_Y3shl_i359_C5count.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shl_i359_V7control.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shl_i359_C11control_msb,downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb=(L4ieee_Q15std_logic_arith_Y3shl_i359_C3arg.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3shl_i359_V4temp.init((&L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i359_V6result.init((&L4ieee_Q15std_logic_arith_Y3shl_i359_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i359_V7control=L4ieee_W15std_logic_arith_Y11make_binary_i55 (L4ieee_Q15std_logic_arith_Y3shl_i359_C5count);
    if((L4ieee_Q15std_logic_arith_Y3shl_i359_V7control[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j=L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j--,L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3shl_i359_V6result[L4ieee_Q15std_logic_arith_Y3shl_i359_L5684ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_Q15std_logic_arith_Y3shl_i359_V6result=L4ieee_Q15std_logic_arith_Y3shl_i359_C3arg;
      for (L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i=0,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q15std_logic_arith_Y3shl_i359_C11control_msb); L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i++,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i_lc--) {
        if((L4ieee_Q15std_logic_arith_Y3shl_i359_V7control[L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i]==enumeration(3))) {
          for (L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j=L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j--,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j_lc--) {
            L4ieee_Q15std_logic_arith_Y3shl_i359_V4temp[L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_L5688ln_C1j]=enumeration(2);
          }
          if((op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i)<=L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb)) {
            array_alias<L4ieee_Q15std_logic_arith_Y3shl_i359_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb,downto,op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i),0),&L4ieee_Q15std_logic_arith_Y3shl_i359_V4temp[L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb])=array_alias<L4ieee_Q15std_logic_arith_Y3shl_i359_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i)),downto,0,0),&L4ieee_Q15std_logic_arith_Y3shl_i359_V6result[(L4ieee_Q15std_logic_arith_Y3shl_i359_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i359_L5686ln_C1i))]);
          }
          L4ieee_Q15std_logic_arith_Y3shl_i359_V6result=L4ieee_Q15std_logic_arith_Y3shl_i359_V4temp;
        }
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y3shl_i359_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shl_i362(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y3shl_i362_C3arg,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shl_i362_C5count)
{
    integer L4ieee_Q15std_logic_arith_Y3shl_i362_C11control_msb;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i362_V7control;
    integer L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb;
    L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y3shl_i362_T5rtype L4ieee_Q15std_logic_arith_Y3shl_i362_V4temp,L4ieee_Q15std_logic_arith_Y3shl_i362_V6result;
    integer L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j,L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i_lc,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3shl_i362_C11control_msb=(L4ieee_Q15std_logic_arith_Y3shl_i362_C5count.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shl_i362_V7control.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shl_i362_C11control_msb,downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb=(L4ieee_Q15std_logic_arith_Y3shl_i362_C3arg.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3shl_i362_V4temp.init((&L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i362_V6result.init((&L4ieee_Q15std_logic_arith_Y3shl_i362_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shl_i362_V7control=L4ieee_W15std_logic_arith_Y11make_binary_i55 (L4ieee_Q15std_logic_arith_Y3shl_i362_C5count);
    if((L4ieee_Q15std_logic_arith_Y3shl_i362_V7control[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j=L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j--,L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3shl_i362_V6result[L4ieee_Q15std_logic_arith_Y3shl_i362_L5699ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_Q15std_logic_arith_Y3shl_i362_V6result=L4ieee_Q15std_logic_arith_Y3shl_i362_C3arg;
      for (L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i=0,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q15std_logic_arith_Y3shl_i362_C11control_msb); L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i++,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i_lc--) {
        if((L4ieee_Q15std_logic_arith_Y3shl_i362_V7control[L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i]==enumeration(3))) {
          for (L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j=L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j--,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j_lc--) {
            L4ieee_Q15std_logic_arith_Y3shl_i362_V4temp[L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_L5703ln_C1j]=enumeration(2);
          }
          if((op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i)<=L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb)) {
            array_alias<L4ieee_Q15std_logic_arith_Y3shl_i362_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb,downto,op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i),0),&L4ieee_Q15std_logic_arith_Y3shl_i362_V4temp[L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb])=array_alias<L4ieee_Q15std_logic_arith_Y3shl_i362_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i)),downto,0,0),&L4ieee_Q15std_logic_arith_Y3shl_i362_V6result[(L4ieee_Q15std_logic_arith_Y3shl_i362_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shl_i362_L5701ln_C1i))]);
          }
          L4ieee_Q15std_logic_arith_Y3shl_i362_V6result=L4ieee_Q15std_logic_arith_Y3shl_i362_V4temp;
        }
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y3shl_i362_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i365(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shr_i365_C3arg,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shr_i365_C5count)
{
    integer L4ieee_Q15std_logic_arith_Y3shr_i365_C11control_msb;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i365_V7control;
    integer L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb;
    L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y3shr_i365_T5rtype L4ieee_Q15std_logic_arith_Y3shr_i365_V4temp,L4ieee_Q15std_logic_arith_Y3shr_i365_V6result;
    integer L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j,L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i_lc,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3shr_i365_C11control_msb=(L4ieee_Q15std_logic_arith_Y3shr_i365_C5count.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shr_i365_V7control.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shr_i365_C11control_msb,downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb=(L4ieee_Q15std_logic_arith_Y3shr_i365_C3arg.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3shr_i365_V4temp.init((&L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i365_V6result.init((&L4ieee_Q15std_logic_arith_Y3shr_i365_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i365_V7control=L4ieee_W15std_logic_arith_Y11make_binary_i55 (L4ieee_Q15std_logic_arith_Y3shr_i365_C5count);
    if((L4ieee_Q15std_logic_arith_Y3shr_i365_V7control[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j=L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j--,L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3shr_i365_V6result[L4ieee_Q15std_logic_arith_Y3shr_i365_L5714ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_Q15std_logic_arith_Y3shr_i365_V6result=L4ieee_Q15std_logic_arith_Y3shr_i365_C3arg;
      for (L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i=0,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q15std_logic_arith_Y3shr_i365_C11control_msb); L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i++,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i_lc--) {
        if((L4ieee_Q15std_logic_arith_Y3shr_i365_V7control[L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i]==enumeration(3))) {
          for (L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j=L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j--,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j_lc--) {
            L4ieee_Q15std_logic_arith_Y3shr_i365_V4temp[L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_L5718ln_C1j]=enumeration(2);
          }
          if((op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i)<=L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb)) {
            array_alias<L4ieee_Q15std_logic_arith_Y3shr_i365_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i)),downto,0,0),&L4ieee_Q15std_logic_arith_Y3shr_i365_V4temp[(L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i))])=array_alias<L4ieee_Q15std_logic_arith_Y3shr_i365_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb,downto,op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i365_L5716ln_C1i),0),&L4ieee_Q15std_logic_arith_Y3shr_i365_V6result[L4ieee_Q15std_logic_arith_Y3shr_i365_C10result_msb]);
          }
          L4ieee_Q15std_logic_arith_Y3shr_i365_V6result=L4ieee_Q15std_logic_arith_Y3shr_i365_V4temp;
        }
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y3shr_i365_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shr_i368(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y3shr_i368_C3arg,const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y3shr_i368_C5count)
{
    integer L4ieee_Q15std_logic_arith_Y3shr_i368_C11control_msb;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i368_V7control;
    integer L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb;
    L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y3shr_i368_T5rtype L4ieee_Q15std_logic_arith_Y3shr_i368_V4temp,L4ieee_Q15std_logic_arith_Y3shr_i368_V6result;
    enumeration L4ieee_Q15std_logic_arith_Y3shr_i368_V8sign_bit;
    integer L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j,L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i_lc,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3shr_i368_C11control_msb=(L4ieee_Q15std_logic_arith_Y3shr_i368_C5count.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shr_i368_V7control.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shr_i368_C11control_msb,downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb=(L4ieee_Q15std_logic_arith_Y3shr_i368_C3arg.info->length-1);
    L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3shr_i368_V4temp.init((&L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i368_V6result.init((&L4ieee_Q15std_logic_arith_Y3shr_i368_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3shr_i368_V8sign_bit=enumeration(0);
    L4ieee_Q15std_logic_arith_Y3shr_i368_V7control=L4ieee_W15std_logic_arith_Y11make_binary_i55 (L4ieee_Q15std_logic_arith_Y3shr_i368_C5count);
    if((L4ieee_Q15std_logic_arith_Y3shr_i368_V7control[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j=L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j--,L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3shr_i368_V6result[L4ieee_Q15std_logic_arith_Y3shr_i368_L5730ln_C1j]=enumeration(1);
      }
    } else {
      L4ieee_Q15std_logic_arith_Y3shr_i368_V6result=L4ieee_Q15std_logic_arith_Y3shr_i368_C3arg;
      L4ieee_Q15std_logic_arith_Y3shr_i368_V8sign_bit=L4ieee_Q15std_logic_arith_Y3shr_i368_C3arg[L4ieee_Q15std_logic_arith_Y3shr_i368_C3arg.info->left_bound];
      for (L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i=0,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_Q15std_logic_arith_Y3shr_i368_C11control_msb); L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i++,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i_lc--) {
        if((L4ieee_Q15std_logic_arith_Y3shr_i368_V7control[L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i]==enumeration(3))) {
          for (L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j=L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j_lc=down_range_to_length<integer>(L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,0); L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j--,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j_lc--) {
            L4ieee_Q15std_logic_arith_Y3shr_i368_V4temp[L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_L5734ln_C1j]=L4ieee_Q15std_logic_arith_Y3shr_i368_V8sign_bit;
          }
          if((op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i)<=L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb)) {
            array_alias<L4ieee_Q15std_logic_arith_Y3shr_i368_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i)),downto,0,0),&L4ieee_Q15std_logic_arith_Y3shr_i368_V4temp[(L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb-op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i))])=array_alias<L4ieee_Q15std_logic_arith_Y3shr_i368_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb,downto,op_power(2,L4ieee_Q15std_logic_arith_Y3shr_i368_L5732ln_C1i),0),&L4ieee_Q15std_logic_arith_Y3shr_i368_V6result[L4ieee_Q15std_logic_arith_Y3shr_i368_C10result_msb]);
          }
          L4ieee_Q15std_logic_arith_Y3shr_i368_V6result=L4ieee_Q15std_logic_arith_Y3shr_i368_V4temp;
        }
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y3shr_i368_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i370(const integer L4ieee_Q15std_logic_arith_Y12conv_integer_i370_C3arg)
{
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i370_C3arg;
}
enumeration L4ieee_W15std_logic_arith_itn85_lit[]={65,82,71,32,105,115,32,116,111,111,32,108,97,114,103,101,32,105,110,32,67,79,78,86,95,73,78,84,69,71,69,82};
enumeration L4ieee_W15std_logic_arith_itn86_lit[]={67,79,78,86,95,73,78,84,69,71,69,82,58,32,84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,97,110,100,32,105,116,32,104,97,115,32,98,101,101,110,32,99,111,110,118,101,114,116,101,100,32,116,111,32,48,46};
/* Implementation of subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg)
{
    integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result;
    enumeration L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V3tmp;
    integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_lc,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_ls;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V3tmp=enumeration(0);
    if(!(L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->length<=31))
      report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+31,0),L4ieee_W15std_logic_arith_itn85_lit),enumeration(3));
    L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result=0;
    for (L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i=L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->left_bound,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_ls=L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->index_direction==to?+1:-1,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_lc=range_to_length<integer>(L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->left_bound,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->index_direction,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg.info->right_bound);L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i+=L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_ls,L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i_lc--) {
      L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result=(L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result*2);
      L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V3tmp=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_Q15std_logic_arith_Y12conv_integer_i372_C3arg[L4ieee_Q15std_logic_arith_Y12conv_integer_i372_L5742ln_C1i]];
      if((L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V3tmp==enumeration(3))) {
        L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result=(L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result+1);
      } else {
        if((L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V3tmp==enumeration(1))) {
          if(!enumeration(0))
            report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+102,0),L4ieee_W15std_logic_arith_itn86_lit),enumeration(1));
        }
      }
    }
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i372_V6result;
}
enumeration L4ieee_W15std_logic_arith_itn87_lit[]={65,82,71,32,105,115,32,116,111,111,32,108,97,114,103,101,32,105,110,32,67,79,78,86,95,73,78,84,69,71,69,82};
enumeration L4ieee_W15std_logic_arith_itn88_lit[]={67,79,78,86,95,73,78,84,69,71,69,82,58,32,84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,97,110,100,32,105,116,32,104,97,115,32,98,101,101,110,32,99,111,110,118,101,114,116,101,100,32,116,111,32,48,46};
/* Implementation of subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg)
{
    integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result;
    enumeration L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp;
    integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_lc,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_ls;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp=enumeration(0);
    if(!(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->length<=32))
      report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+31,0),L4ieee_W15std_logic_arith_itn87_lit),enumeration(3));
    L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=0;
    for (L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i=L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->left_bound,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_ls=L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->index_direction==to?+1:-1,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_lc=range_to_length<integer>(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->left_bound,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->index_direction,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->right_bound);L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i+=L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_ls,L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i_lc--) {
      if((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i!=L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->left_bound)) {
        L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result*2);
        L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg[L4ieee_Q15std_logic_arith_Y12conv_integer_i374_L5748ln_C1i]];
        if((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp==enumeration(3))) {
          L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result+1);
        } else {
          if((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp==enumeration(1))) {
            if(!enumeration(0))
              report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+102,0),L4ieee_W15std_logic_arith_itn88_lit),enumeration(1));
          }
        }
      }
    }
    L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp=L4ieee_W15std_logic_arith_Y11make_binary_i52 (L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg[L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->left_bound]);
    if((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V3tmp==enumeration(3))) {
      if((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->length==32)) {
        L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=((L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result-1073741824)-1073741824);
      } else {
        L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result=(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result-op_power(2,(L4ieee_Q15std_logic_arith_Y12conv_integer_i374_C3arg.info->length-1)));
      }
    }
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i374_V6result;
}
enumeration L4ieee_W15std_logic_arith_itn89_lit[]={67,79,78,86,95,73,78,84,69,71,69,82,58,32,84,104,101,114,101,32,105,115,32,97,110,32,39,85,39,124,39,88,39,124,39,87,39,124,39,90,39,124,39,45,39,32,105,110,32,97,110,32,97,114,105,116,104,109,101,116,105,99,32,111,112,101,114,97,110,100,44,32,97,110,100,32,105,116,32,104,97,115,32,98,101,101,110,32,99,111,110,118,101,114,116,101,100,32,116,111,32,48,46};
/* Implementation of subprogram :ieee:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i376(const enumeration L4ieee_Q15std_logic_arith_Y12conv_integer_i376_C3arg)
{
    enumeration L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V3tmp;
    integer L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V3tmp=enumeration(0);
    L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V3tmp=L4ieee_W15std_logic_arith_C10tbl_binary[L4ieee_Q15std_logic_arith_Y12conv_integer_i376_C3arg];
    if((L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V3tmp==enumeration(3))) {
      L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result=1;
    } else {
      if((L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V3tmp==enumeration(1))) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+102,0),L4ieee_W15std_logic_arith_itn89_lit),enumeration(1));
        L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result=0;
      } else {
        L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result=0;
      }
    }
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i376_V6result;
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379(const integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_C3arg,const integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_C4size)
{
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V6result;
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i_lc;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp=L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_C3arg;
    for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i=0,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_C4size-1)); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i++,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i_lc--) {
      if((op_mod(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp,2)==1)) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i]=enumeration(3);
      } else {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_L5759ln_C1i]=enumeration(2);
      }
      if((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp>0)) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp/2);
      } else {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp=((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V4temp-1)/2);
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i379_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3arg,const integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_I5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_T5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result;
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j_lc,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3arg.info->length,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size)-1);
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V10new_bounds.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result.init((&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i55 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3arg);
    if((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5768ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_L5770ln_C1j]=enumeration(2);
      }
      array_alias<L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb])=array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V10new_bounds[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_C3msb]);
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i382_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3arg,const integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_I5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_T5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result;
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j_lc,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3arg.info->length,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size)-1);
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result.init((&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i71 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3arg);
    if((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5779ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_L5781ln_C1j]=L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds.info->left_bound];
      }
      array_alias<L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb])=array_alias<L4ieee_Q15std_logic_arith_T8unsigned >(new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V10new_bounds[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_C3msb]);
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i385_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_unsigned */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388(const enumeration L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C3arg,const integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size)
{
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_I5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_T5rtype L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result;
    integer L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j_lc,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result.init((&L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_I5rtype_INFO),enumeration(0));
    for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j_lc--) {
      L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5788ln_C1j]=enumeration(2);
    }
    L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result[0]=L4ieee_W15std_logic_arith_Y11make_binary_i52 (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C3arg);
    if((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j=(L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size-1),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_C4size-1),0); L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j--,L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result[L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_L5790ln_C1j]=enumeration(1);
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q15std_logic_arith_Y13conv_unsigned_i388_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i391(const integer L4ieee_Q15std_logic_arith_Y11conv_signed_i391_C3arg,const integer L4ieee_Q15std_logic_arith_Y11conv_signed_i391_C4size)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V6result;
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp,L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i,L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i_lc;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y11conv_signed_i391_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp=L4ieee_Q15std_logic_arith_Y11conv_signed_i391_C3arg;
    for (L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i=0,L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_Q15std_logic_arith_Y11conv_signed_i391_C4size-1)); L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i++,L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i_lc--) {
      if((op_mod(L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp,2)==1)) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i]=enumeration(3);
      } else {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i391_L5797ln_C1i]=enumeration(2);
      }
      if((L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp>0)) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp=(L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp/2);
      } else {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp=((L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V4temp-1)/2);
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i391_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i394(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3arg,const integer L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_I5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i394_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_T5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result;
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j_lc,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3arg.info->length,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size)-1);
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V10new_bounds.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result.init((&L4ieee_Q15std_logic_arith_Y11conv_signed_i394_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i63 (L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3arg);
    if((L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5806ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i394_L5808ln_C1j]=enumeration(2);
      }
      array_alias<L4ieee_Q15std_logic_arith_Y11conv_signed_i394_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb])=array_alias<L4ieee_Q15std_logic_arith_T6signed >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V10new_bounds[L4ieee_Q15std_logic_arith_Y11conv_signed_i394_C3msb]);
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i394_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i397(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3arg,const integer L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_I5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i397_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_T5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result;
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j_lc,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3arg.info->length,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size)-1);
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result.init((&L4ieee_Q15std_logic_arith_Y11conv_signed_i397_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i79 (L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3arg);
    if((L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5817ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i397_L5819ln_C1j]=L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds[L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds.info->left_bound];
      }
      array_alias<L4ieee_Q15std_logic_arith_Y11conv_signed_i397_T5rtype >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb])=array_alias<L4ieee_Q15std_logic_arith_T6signed >(new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V10new_bounds[L4ieee_Q15std_logic_arith_Y11conv_signed_i397_C3msb]);
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i397_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_signed */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y11conv_signed_i400(const enumeration L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C3arg,const integer L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size)
{
    L4ieee_Q15std_logic_arith_Y11conv_signed_i400_I5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i400_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i400_T5rtype L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result;
    integer L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j_lc,L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j,L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y11conv_signed_i400_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result.init((&L4ieee_Q15std_logic_arith_Y11conv_signed_i400_I5rtype_INFO),enumeration(0));
    for (L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j_lc--) {
      L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5826ln_C1j]=enumeration(2);
    }
    L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result[0]=L4ieee_W15std_logic_arith_Y11make_binary_i52 (L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C3arg);
    if((L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j=(L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size-1),L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y11conv_signed_i400_C4size-1),0); L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j--,L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result[L4ieee_Q15std_logic_arith_Y11conv_signed_i400_L5828ln_C1j]=enumeration(1);
      }
    }
    return array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q15std_logic_arith_Y11conv_signed_i400_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403(const integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_C3arg,const integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_C4size)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V6result;
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i_lc;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_C4size-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp=-2147483648LL;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp=L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_C3arg;
    for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i=0,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i_lc=up_range_to_length<integer>(0,(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_C4size-1)); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i++,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i_lc--) {
      if((op_mod(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp,2)==1)) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i]=enumeration(3);
      } else {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_L5835ln_C1i]=enumeration(2);
      }
      if((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp>0)) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp/2);
      } else {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp=((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V4temp-1)/2);
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i403_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406(const L4ieee_Q15std_logic_arith_T8unsigned &L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3arg,const integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_I5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_I5rtype_INFO;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_T5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result;
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j_lc,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3arg.info->length,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size)-1);
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V10new_bounds.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result.init((&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i95 (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3arg);
    if((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5844ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_L5846ln_C1j]=enumeration(2);
      }
      array_alias<L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_T5rtype >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V10new_bounds[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_C3msb]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i406_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409(const L4ieee_Q15std_logic_arith_T6signed &L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3arg,const integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_I5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_I5rtype_INFO;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_T5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result;
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j_lc,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3arg.info->length,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size)-1);
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result.init((&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i103 (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3arg);
    if((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5855ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_L5857ln_C1j]=L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds.info->left_bound];
      }
      array_alias<L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_T5rtype >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V10new_bounds[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_C3msb]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i409_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:conv_std_logic_vector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412(const enumeration L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C3arg,const integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size)
{
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_I5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_I5rtype_INFO;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_T5rtype L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result;
    integer L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j_lc,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result.init((&L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_I5rtype_INFO),enumeration(0));
    for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j_lc--) {
      L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5864ln_C1j]=enumeration(2);
    }
    L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result[0]=L4ieee_W15std_logic_arith_Y11make_binary_i52 (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C3arg);
    if((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j=(L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size-1),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_C4size-1),0); L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j--,L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result[L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_L5866ln_C1j]=enumeration(1);
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y21conv_std_logic_vector_i412_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:ext */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3ext_i415(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q15std_logic_arith_Y3ext_i415_C3arg,const integer L4ieee_Q15std_logic_arith_Y3ext_i415_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb;
    L4ieee_Q15std_logic_arith_Y3ext_i415_I5rtype L4ieee_Q15std_logic_arith_Y3ext_i415_I5rtype_INFO;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3ext_i415_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y3ext_i415_T5rtype L4ieee_Q15std_logic_arith_Y3ext_i415_V6result;
    integer L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j,L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j,L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y3ext_i415_C3arg.info->length,L4ieee_Q15std_logic_arith_Y3ext_i415_C4size)-1);
    L4ieee_Q15std_logic_arith_Y3ext_i415_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y3ext_i415_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3ext_i415_V10new_bounds.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3ext_i415_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3ext_i415_V6result.init((&L4ieee_Q15std_logic_arith_Y3ext_i415_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3ext_i415_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i87 (L4ieee_Q15std_logic_arith_Y3ext_i415_C3arg);
    if((L4ieee_Q15std_logic_arith_Y3ext_i415_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j=(L4ieee_Q15std_logic_arith_Y3ext_i415_C4size-1),L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y3ext_i415_C4size-1),0); L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j--,L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3ext_i415_V6result[L4ieee_Q15std_logic_arith_Y3ext_i415_L5875ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j=(L4ieee_Q15std_logic_arith_Y3ext_i415_C4size-1),L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y3ext_i415_C4size-1),0); L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j--,L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3ext_i415_V6result[L4ieee_Q15std_logic_arith_Y3ext_i415_L5877ln_C1j]=enumeration(2);
      }
      array_alias<L4ieee_Q15std_logic_arith_Y3ext_i415_T5rtype >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y3ext_i415_V6result[L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y3ext_i415_V10new_bounds[L4ieee_Q15std_logic_arith_Y3ext_i415_C3msb]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3ext_i415_V6result);
}
/* Implementation of subprogram :ieee:std_logic_arith:sxt */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3sxt_i418(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q15std_logic_arith_Y3sxt_i418_C3arg,const integer L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size)
{
    integer L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb;
    L4ieee_Q15std_logic_arith_Y3sxt_i418_I5rtype L4ieee_Q15std_logic_arith_Y3sxt_i418_I5rtype_INFO;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds;
    L4ieee_Q15std_logic_arith_Y3sxt_i418_T5rtype L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result;
    integer L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j,L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j_lc,L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j,L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j_lc;
    L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb=(L4ieee_W15std_logic_arith_Y3min_i12 (L4ieee_Q15std_logic_arith_Y3sxt_i418_C3arg.info->length,L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size)-1);
    L4ieee_Q15std_logic_arith_Y3sxt_i418_I5rtype_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),(L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size-1),downto,0,-1);
    L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q15std_logic_arith_Y3sxt_i418_C3arg.info->length-1),downto,0,0)),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result.init((&L4ieee_Q15std_logic_arith_Y3sxt_i418_I5rtype_INFO),enumeration(0));
    L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds=L4ieee_W15std_logic_arith_Y11make_binary_i87 (L4ieee_Q15std_logic_arith_Y3sxt_i418_C3arg);
    if((L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds[0]==enumeration(1))) {
      for (L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j=(L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size-1),L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size-1),0); L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j--,L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result[L4ieee_Q15std_logic_arith_Y3sxt_i418_L5886ln_C1j]=enumeration(1);
      }
    } else {
      for (L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j=(L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size-1),L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j_lc=down_range_to_length<integer>((L4ieee_Q15std_logic_arith_Y3sxt_i418_C4size-1),0); L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j_lc!=0; L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j--,L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j_lc--) {
        L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result[L4ieee_Q15std_logic_arith_Y3sxt_i418_L5888ln_C1j]=L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds[L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds.info->left_bound];
      }
      array_alias<L4ieee_Q15std_logic_arith_Y3sxt_i418_T5rtype >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result[L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb])=array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb,downto,0,0),&L4ieee_Q15std_logic_arith_Y3sxt_i418_V10new_bounds[L4ieee_Q15std_logic_arith_Y3sxt_i418_C3msb]);
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3sxt_i418_V6result);
}
/* Initialization function for package body :ieee:std_logic_arith */
int L4ieee_Q15std_logic_arith_init ();
int L3std_Q8standard_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_W15std_logic_arith_init_done = false;
int L4ieee_W15std_logic_arith_init(){
if (L4ieee_W15std_logic_arith_init_done) return 1;
L4ieee_W15std_logic_arith_init_done=true;
L4ieee_Q15std_logic_arith_init ();
L3std_Q8standard_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_arith.vhdl","std_logic_arith.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":std_logic_arith");
L4ieee_W15std_logic_arith_I8tbl_type_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_arith",":ieee:std_logic_arith:tbl_type",":tbl_type",NULL);
L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO.set((&L3std_Q8standard_I7boolean_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_arith",":ieee:std_logic_arith:tbl_mvl9_boolean",":tbl_mvl9_boolean",NULL);
L4ieee_W15std_logic_arith_C10tbl_binary.init((&L4ieee_W15std_logic_arith_I8tbl_type_INFO),enumeration(0));
L4ieee_W15std_logic_arith_C10tbl_binary=L4ieee_W15std_logic_arith_T8tbl_type(new array_info((&L4ieee_W15std_logic_arith_I8tbl_type_INFO)->element_type,(&L4ieee_W15std_logic_arith_I8tbl_type_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(1)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
L4ieee_W15std_logic_arith_C4is_x.init((&L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO),enumeration(0));
L4ieee_W15std_logic_arith_C4is_x=L4ieee_W15std_logic_arith_T16tbl_mvl9_boolean(new array_info((&L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO)->element_type,(&L4ieee_W15std_logic_arith_I16tbl_mvl9_boolean_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(1)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(0)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(0)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W15std_logic_arith_hinfo =
  add_handle("ieee","std_logic_arith",NULL,NULL,&L4ieee_W15std_logic_arith_init);

/* end of package body :ieee:std_logic_arith */
