#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:std_logic_signed */
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
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i15(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i21(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i30(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i36(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i40(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y0_i42(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_mult_i45(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i48(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i51(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i54(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i57(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i60(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i63(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i66(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i69(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i72(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i75(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i78(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i81(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i84(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i87(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i90(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i93(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i96(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i99(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shl_i102(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shr_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:conv_integer */
integer L4ieee_Q16std_logic_signed_Y12conv_integer_i107(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Initialization function for package :ieee:std_logic_signed */
int L3std_Q8standard_init ();
int L4ieee_Q15std_logic_arith_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_Q16std_logic_signed_init_done = false;
int L4ieee_Q16std_logic_signed_init(){
if (L4ieee_Q16std_logic_signed_init_done) return 1;
L4ieee_Q16std_logic_signed_init_done=true;
L3std_Q8standard_init ();
L4ieee_Q15std_logic_arith_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_signed.vhdl","std_logic_signed.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":std_logic_signed");
iname.pop();
handle_info *h = get_handle ("ieee","std_logic_signed",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:std_logic_signed */

/* package body :ieee:std_logic_signed */
/* External declarations */
extern array_info L4ieee_Q15std_logic_arith_I6signed_INFO;
#define L4ieee_Q15std_logic_arith_T6signed array_type<enumeration >
#define L4ieee_Q15std_logic_arith_I6signed array_info

/* Prototype for subprogram :IEEE:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i374(const L4ieee_Q15std_logic_arith_T6signed &);
extern array_info L4ieee_Q15std_logic_arith_I8unsigned_INFO;
#define L4ieee_Q15std_logic_arith_T8unsigned array_type<enumeration >
#define L4ieee_Q15std_logic_arith_I8unsigned array_info

/* Prototype for subprogram :IEEE:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shr_i368(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T6signed L4ieee_Q15std_logic_arith_Y3shl_i362(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i356(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i353(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i338(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i332(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i329(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i314(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i308(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i305(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i290(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i284(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i281(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i266(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i260(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i257(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i242(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i236(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i233(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i218(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i206(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y0_i188(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i186(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i184(const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i172(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i169(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i160(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i157(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i142(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i100(const enumeration ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i97(const L4ieee_Q15std_logic_arith_T6signed &,const enumeration );
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i88(const integer ,const L4ieee_Q15std_logic_arith_T6signed &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i85(const L4ieee_Q15std_logic_arith_T6signed &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i70(const L4ieee_Q15std_logic_arith_T6signed &,const L4ieee_Q15std_logic_arith_T6signed &);
/* End of external declarations */
/* Prototype for subprogram :ieee:std_logic_signed:maximum */
integer L4ieee_W16std_logic_signed_Y7maximum_i9(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i15(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i21(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i30(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i36(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i40(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y0_i42(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_mult_i45(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i48(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i51(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i54(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i57(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i60(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i63(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i66(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i69(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i72(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i75(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i78(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i81(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i84(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i87(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i90(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i93(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i96(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i99(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shl_i102(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shr_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_signed:conv_integer */
integer L4ieee_Q16std_logic_signed_Y12conv_integer_i107(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Implementation of subprogram :ieee:std_logic_signed:maximum */
integer L4ieee_W16std_logic_signed_Y7maximum_i9(const integer L4ieee_W16std_logic_signed_Y7maximum_i9_C1l,const integer L4ieee_W16std_logic_signed_Y7maximum_i9_C1r)
{
    if((L4ieee_W16std_logic_signed_Y7maximum_i9_C1l>L4ieee_W16std_logic_signed_Y7maximum_i9_C1r)) {
      return L4ieee_W16std_logic_signed_Y7maximum_i9_C1l;
    } else {
      return L4ieee_W16std_logic_signed_Y7maximum_i9_C1r;
    }
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1r)
{
    integer L4ieee_Q16std_logic_signed_Y7op_plus_i9_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i9_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i9_C6length=L4ieee_W16std_logic_signed_Y7maximum_i9 (L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1l.info->length,L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1r.info->length);
    L4ieee_Q16std_logic_signed_Y7op_plus_i9_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q16std_logic_signed_Y7op_plus_i9_C6length-1),downto,0,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i9_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i70 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i9_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i9_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1l,const integer L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i12_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i12_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i12_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i85 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1l),L4ieee_Q16std_logic_signed_Y7op_plus_i12_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i12_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i15(const integer L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i15_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i15_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1r.info->left_bound,L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1r.info->index_direction,L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i15_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i88 (L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i15_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i15_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1l,const enumeration L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i18_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i18_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i18_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i97 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1l),L4ieee_Q16std_logic_signed_Y7op_plus_i18_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i18_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i21(const enumeration L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i21_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i21_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1r.info->left_bound,L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1r.info->index_direction,L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i21_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i100 (L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i21_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i21_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1r)
{
    integer L4ieee_Q16std_logic_signed_Y8op_minus_i24_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i24_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i24_C6length=L4ieee_W16std_logic_signed_Y7maximum_i9 (L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1l.info->length,L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1r.info->length);
    L4ieee_Q16std_logic_signed_Y8op_minus_i24_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q16std_logic_signed_Y8op_minus_i24_C6length-1),downto,0,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i24_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i142 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i24_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i24_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1l,const integer L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i27_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i27_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i27_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i157 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1l),L4ieee_Q16std_logic_signed_Y8op_minus_i27_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i27_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i30(const integer L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i30_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i30_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1r.info->left_bound,L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1r.info->index_direction,L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i30_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i160 (L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i30_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i30_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1l,const enumeration L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i33_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i33_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i33_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i169 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1l),L4ieee_Q16std_logic_signed_Y8op_minus_i33_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i33_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i36(const enumeration L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i36_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i36_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1r.info->left_bound,L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1r.info->index_direction,L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i36_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i172 (L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i36_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i36_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_plus_i38_C1l)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_plus_i38_V6result;
    L4ieee_Q16std_logic_signed_Y7op_plus_i38_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y7op_plus_i38_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y7op_plus_i38_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y7op_plus_i38_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_plus_i38_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i184 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i38_C1l));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_plus_i38_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i40(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y8op_minus_i40_C1l)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y8op_minus_i40_V6result;
    L4ieee_Q16std_logic_signed_Y8op_minus_i40_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y8op_minus_i40_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y8op_minus_i40_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y8op_minus_i40_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y8op_minus_i40_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i186 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i40_C1l));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y8op_minus_i40_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"abs" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y0_i42(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y0_i42_C1l)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y0_i42_V6result;
    L4ieee_Q16std_logic_signed_Y0_i42_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q16std_logic_signed_Y0_i42_C1l.info->left_bound,L4ieee_Q16std_logic_signed_Y0_i42_C1l.info->index_direction,L4ieee_Q16std_logic_signed_Y0_i42_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y0_i42_V6result=L4ieee_Q15std_logic_arith_Y0_i188 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y0_i42_C1l));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y0_i42_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_mult_i45(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1r)
{
    integer L4ieee_Q16std_logic_signed_Y7op_mult_i45_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y7op_mult_i45_V6result;
    L4ieee_Q16std_logic_signed_Y7op_mult_i45_C6length=L4ieee_W16std_logic_signed_Y7maximum_i9 (L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1l.info->length,L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1r.info->length);
    L4ieee_Q16std_logic_signed_Y7op_mult_i45_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,((L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1l.info->length+L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1r.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y7op_mult_i45_V6result=L4ieee_Q15std_logic_arith_Y7op_mult_i206 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y7op_mult_i45_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q16std_logic_signed_Y7op_mult_i45_V6result));
}
/* Implementation of subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i48(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1r)
{
    integer L4ieee_Q16std_logic_signed_Y5op_lt_i48_C6length;
    L4ieee_Q16std_logic_signed_Y5op_lt_i48_C6length=L4ieee_W16std_logic_signed_Y7maximum_i9 (L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1l.info->length,L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1r.info->length);
    return L4ieee_Q15std_logic_arith_Y5op_lt_i218 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_lt_i48_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i51(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_lt_i51_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_lt_i51_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_lt_i233 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_lt_i51_C1l),L4ieee_Q16std_logic_signed_Y5op_lt_i51_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:"<" */
enumeration L4ieee_Q16std_logic_signed_Y5op_lt_i54(const integer L4ieee_Q16std_logic_signed_Y5op_lt_i54_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_lt_i54_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_lt_i236 (L4ieee_Q16std_logic_signed_Y5op_lt_i54_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_lt_i54_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i57(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_le_i57_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_le_i57_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i242 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_le_i57_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_le_i57_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i60(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_le_i60_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_le_i60_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i257 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_le_i60_C1l),L4ieee_Q16std_logic_signed_Y5op_le_i60_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:"<=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_le_i63(const integer L4ieee_Q16std_logic_signed_Y5op_le_i63_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_le_i63_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i260 (L4ieee_Q16std_logic_signed_Y5op_le_i63_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_le_i63_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i66(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_gt_i66_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_gt_i66_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i266 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_gt_i66_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_gt_i66_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i69(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_gt_i69_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_gt_i69_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i281 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_gt_i69_C1l),L4ieee_Q16std_logic_signed_Y5op_gt_i69_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:">" */
enumeration L4ieee_Q16std_logic_signed_Y5op_gt_i72(const integer L4ieee_Q16std_logic_signed_Y5op_gt_i72_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_gt_i72_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i284 (L4ieee_Q16std_logic_signed_Y5op_gt_i72_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_gt_i72_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i75(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ge_i75_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ge_i75_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i290 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ge_i75_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ge_i75_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i78(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ge_i78_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_ge_i78_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i305 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ge_i78_C1l),L4ieee_Q16std_logic_signed_Y5op_ge_i78_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:">=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ge_i81(const integer L4ieee_Q16std_logic_signed_Y5op_ge_i81_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ge_i81_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i308 (L4ieee_Q16std_logic_signed_Y5op_ge_i81_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ge_i81_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i84(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_eq_i84_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_eq_i84_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i314 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_eq_i84_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_eq_i84_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i87(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_eq_i87_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_eq_i87_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i329 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_eq_i87_C1l),L4ieee_Q16std_logic_signed_Y5op_eq_i87_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:"=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_eq_i90(const integer L4ieee_Q16std_logic_signed_Y5op_eq_i90_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_eq_i90_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i332 (L4ieee_Q16std_logic_signed_Y5op_eq_i90_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_eq_i90_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i93(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ne_i93_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ne_i93_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i338 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ne_i93_C1l),array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ne_i93_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i96(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ne_i96_C1l,const integer L4ieee_Q16std_logic_signed_Y5op_ne_i96_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i353 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ne_i96_C1l),L4ieee_Q16std_logic_signed_Y5op_ne_i96_C1r);
}
/* Implementation of subprogram :ieee:std_logic_signed:"/=" */
enumeration L4ieee_Q16std_logic_signed_Y5op_ne_i99(const integer L4ieee_Q16std_logic_signed_Y5op_ne_i99_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y5op_ne_i99_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i356 (L4ieee_Q16std_logic_signed_Y5op_ne_i99_C1l,array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y5op_ne_i99_C1r));
}
/* Implementation of subprogram :ieee:std_logic_signed:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shl_i102(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y3shl_i102_C3arg,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y3shl_i102_C5count)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3shl_i362 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y3shl_i102_C3arg),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q16std_logic_signed_Y3shl_i102_C5count))));
}
/* Implementation of subprogram :ieee:std_logic_signed:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q16std_logic_signed_Y3shr_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y3shr_i105_C3arg,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y3shr_i105_C5count)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3shr_i368 (array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y3shr_i105_C3arg),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q16std_logic_signed_Y3shr_i105_C5count))));
}
/* Implementation of subprogram :ieee:std_logic_signed:conv_integer */
integer L4ieee_Q16std_logic_signed_Y12conv_integer_i107(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q16std_logic_signed_Y12conv_integer_i107_C3arg)
{
    L4ieee_Q15std_logic_arith_T6signed L4ieee_Q16std_logic_signed_Y12conv_integer_i107_V6result;
    L4ieee_Q16std_logic_signed_Y12conv_integer_i107_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I6signed_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I6signed_INFO)->index_type,L4ieee_Q16std_logic_signed_Y12conv_integer_i107_C3arg.info->left_bound,L4ieee_Q16std_logic_signed_Y12conv_integer_i107_C3arg.info->index_direction,L4ieee_Q16std_logic_signed_Y12conv_integer_i107_C3arg.info->right_bound,0)),enumeration(0));
    L4ieee_Q16std_logic_signed_Y12conv_integer_i107_V6result=array_alias<L4ieee_Q15std_logic_arith_T6signed >((&L4ieee_Q15std_logic_arith_I6signed_INFO),L4ieee_Q16std_logic_signed_Y12conv_integer_i107_C3arg);
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i374 (L4ieee_Q16std_logic_signed_Y12conv_integer_i107_V6result);
}
/* Initialization function for package body :ieee:std_logic_signed */
int L4ieee_Q16std_logic_signed_init ();
int L3std_Q8standard_init ();
int L4ieee_Q15std_logic_arith_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_W16std_logic_signed_init_done = false;
int L4ieee_W16std_logic_signed_init(){
if (L4ieee_W16std_logic_signed_init_done) return 1;
L4ieee_W16std_logic_signed_init_done=true;
L4ieee_Q16std_logic_signed_init ();
L3std_Q8standard_init ();
L4ieee_Q15std_logic_arith_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_signed.vhdl","std_logic_signed.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":std_logic_signed");
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W16std_logic_signed_hinfo =
  add_handle("ieee","std_logic_signed",NULL,NULL,&L4ieee_W16std_logic_signed_init);

/* end of package body :ieee:std_logic_signed */
