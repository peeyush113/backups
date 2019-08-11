#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:std_logic_unsigned */
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
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i15(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i21(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i30(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i36(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_mult_i41(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i44(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i47(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i50(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i53(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i56(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i59(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i62(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i65(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i68(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i71(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i77(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i83(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i89(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i92(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shl_i95(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shr_i98(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:conv_integer */
integer L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Initialization function for package :ieee:std_logic_unsigned */
int L3std_Q8standard_init ();
int L4ieee_Q15std_logic_arith_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_Q18std_logic_unsigned_init_done = false;
int L4ieee_Q18std_logic_unsigned_init(){
if (L4ieee_Q18std_logic_unsigned_init_done) return 1;
L4ieee_Q18std_logic_unsigned_init_done=true;
L3std_Q8standard_init ();
L4ieee_Q15std_logic_arith_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_unsigned.vhdl","std_logic_unsigned.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":std_logic_unsigned");
iname.pop();
handle_info *h = get_handle ("ieee","std_logic_unsigned",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:std_logic_unsigned */

/* package body :ieee:std_logic_unsigned */
/* External declarations */
extern array_info L4ieee_Q15std_logic_arith_I8unsigned_INFO;
#define L4ieee_Q15std_logic_arith_T8unsigned array_type<enumeration >
#define L4ieee_Q15std_logic_arith_I8unsigned array_info

/* Prototype for subprogram :IEEE:std_logic_arith:shr */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shr_i365(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:shl */
L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q15std_logic_arith_Y3shl_i359(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:conv_integer */
integer L4ieee_Q15std_logic_arith_Y12conv_integer_i372(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i350(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i347(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"/=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ne_i335(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i326(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i323(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_eq_i311(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i302(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i299(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:">=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_ge_i287(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i278(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i275(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:">" */
enumeration L4ieee_Q15std_logic_arith_Y5op_gt_i263(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i254(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i251(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"<=" */
enumeration L4ieee_Q15std_logic_arith_Y5op_le_i239(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i230(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i227(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"<" */
enumeration L4ieee_Q15std_logic_arith_Y5op_lt_i215(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_mult_i203(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i182(const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i166(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i163(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i154(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i151(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y8op_minus_i139(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i94(const enumeration ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i91(const L4ieee_Q15std_logic_arith_T8unsigned &,const enumeration );
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i82(const integer ,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i79(const L4ieee_Q15std_logic_arith_T8unsigned &,const integer );
/* Prototype for subprogram :IEEE:std_logic_arith:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q15std_logic_arith_Y7op_plus_i67(const L4ieee_Q15std_logic_arith_T8unsigned &,const L4ieee_Q15std_logic_arith_T8unsigned &);
/* End of external declarations */
/* Prototype for subprogram :ieee:std_logic_unsigned:maximum */
integer L4ieee_W18std_logic_unsigned_Y7maximum_i9(const integer ,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i15(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i21(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i30(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i36(const enumeration ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_mult_i41(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i44(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i47(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i50(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i53(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i56(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i59(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i62(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i65(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i68(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i71(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i77(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_W18std_logic_unsigned_Y5op_eq_i99(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i83(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i89(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const integer );
/* Prototype for subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i92(const integer ,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:conv_integer */
integer L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shl_i95(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_unsigned:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shr_i98(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Implementation of subprogram :ieee:std_logic_unsigned:maximum */
integer L4ieee_W18std_logic_unsigned_Y7maximum_i9(const integer L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1l,const integer L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1r)
{
    if((L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1l>L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1r)) {
      return L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1l;
    } else {
      return L4ieee_W18std_logic_unsigned_Y7maximum_i9_C1r;
    }
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i9(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1r)
{
    integer L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C6length=L4ieee_W18std_logic_unsigned_Y7maximum_i9 (L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1l.info->length,L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1r.info->length);
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C6length-1),downto,0,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i67 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i9_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i12(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1l,const integer L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1l.info->left_bound,L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1l.info->index_direction,L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i79 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1l),L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i12_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i15(const integer L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1r.info->left_bound,L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1r.info->index_direction,L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i82 (L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i15_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i18(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1l,const enumeration L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1l.info->left_bound,L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1l.info->index_direction,L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i91 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1l),L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i18_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i21(const enumeration L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1r.info->left_bound,L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1r.info->index_direction,L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i94 (L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i21_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i24(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1r)
{
    integer L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_V6result;
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C6length=L4ieee_W18std_logic_unsigned_Y7maximum_i9 (L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1l.info->length,L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1r.info->length);
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C6length-1),downto,0,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i139 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i24_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i27(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1l,const integer L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_V6result;
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1l.info->left_bound,L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1l.info->index_direction,L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i151 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1l),L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i27_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i30(const integer L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_V6result;
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1r.info->left_bound,L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1r.info->index_direction,L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i154 (L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i30_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i33(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1l,const enumeration L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_V6result;
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1l.info->left_bound,L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1l.info->index_direction,L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i163 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1l),L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_C1r);
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i33_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"-" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i36(const enumeration L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1r)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_V6result;
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1r.info->left_bound,L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1r.info->index_direction,L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1r.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_V6result=L4ieee_Q15std_logic_arith_Y8op_minus_i166 (L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y8op_minus_i36_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"+" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i38(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_C1l)
{
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_C1l.info->left_bound,L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_C1l.info->index_direction,L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_C1l.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_V6result=L4ieee_Q15std_logic_arith_Y7op_plus_i182 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_C1l));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_plus_i38_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"*" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_mult_i41(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1r)
{
    integer L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C6length;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_V6result;
    L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C6length=L4ieee_W18std_logic_unsigned_Y7maximum_i9 (L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1l.info->length,L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1r.info->length);
    L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,((L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1l.info->length+L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1r.info->length)-1),downto,0,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_V6result=L4ieee_Q15std_logic_arith_Y7op_mult_i203 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_C1r));
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q18std_logic_unsigned_Y7op_mult_i41_V6result));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i44(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1r)
{
    integer L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C6length;
    L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C6length=L4ieee_W18std_logic_unsigned_Y7maximum_i9 (L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1l.info->length,L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1r.info->length);
    return L4ieee_Q15std_logic_arith_Y5op_lt_i215 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_lt_i44_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i47(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_lt_i47_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_lt_i47_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_lt_i227 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_lt_i47_C1l),L4ieee_Q18std_logic_unsigned_Y5op_lt_i47_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_lt_i50(const integer L4ieee_Q18std_logic_unsigned_Y5op_lt_i50_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_lt_i50_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_lt_i230 (L4ieee_Q18std_logic_unsigned_Y5op_lt_i50_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_lt_i50_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i53(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_le_i53_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_le_i53_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i239 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_le_i53_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_le_i53_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i56(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_le_i56_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_le_i56_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i251 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_le_i56_C1l),L4ieee_Q18std_logic_unsigned_Y5op_le_i56_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"<=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_le_i59(const integer L4ieee_Q18std_logic_unsigned_Y5op_le_i59_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_le_i59_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_le_i254 (L4ieee_Q18std_logic_unsigned_Y5op_le_i59_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_le_i59_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i62(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_gt_i62_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_gt_i62_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i263 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_gt_i62_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_gt_i62_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i65(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_gt_i65_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_gt_i65_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i275 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_gt_i65_C1l),L4ieee_Q18std_logic_unsigned_Y5op_gt_i65_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_gt_i68(const integer L4ieee_Q18std_logic_unsigned_Y5op_gt_i68_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_gt_i68_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_gt_i278 (L4ieee_Q18std_logic_unsigned_Y5op_gt_i68_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_gt_i68_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i71(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ge_i71_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ge_i71_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i287 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ge_i71_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ge_i71_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ge_i74_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_ge_i74_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i299 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ge_i74_C1l),L4ieee_Q18std_logic_unsigned_Y5op_ge_i74_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:">=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ge_i77(const integer L4ieee_Q18std_logic_unsigned_Y5op_ge_i77_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ge_i77_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ge_i302 (L4ieee_Q18std_logic_unsigned_Y5op_ge_i77_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ge_i77_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_W18std_logic_unsigned_Y5op_eq_i99(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W18std_logic_unsigned_Y5op_eq_i99_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_W18std_logic_unsigned_Y5op_eq_i99_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i311 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W18std_logic_unsigned_Y5op_eq_i99_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_W18std_logic_unsigned_Y5op_eq_i99_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_eq_i80_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_eq_i80_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i323 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_eq_i80_C1l),L4ieee_Q18std_logic_unsigned_Y5op_eq_i80_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_eq_i83(const integer L4ieee_Q18std_logic_unsigned_Y5op_eq_i83_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_eq_i83_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_eq_i326 (L4ieee_Q18std_logic_unsigned_Y5op_eq_i83_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_eq_i83_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ne_i86_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ne_i86_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i335 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ne_i86_C1l),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ne_i86_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i89(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ne_i89_C1l,const integer L4ieee_Q18std_logic_unsigned_Y5op_ne_i89_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i347 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ne_i89_C1l),L4ieee_Q18std_logic_unsigned_Y5op_ne_i89_C1r);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:"/=" */
enumeration L4ieee_Q18std_logic_unsigned_Y5op_ne_i92(const integer L4ieee_Q18std_logic_unsigned_Y5op_ne_i92_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y5op_ne_i92_C1r)
{
    return L4ieee_Q15std_logic_arith_Y5op_ne_i350 (L4ieee_Q18std_logic_unsigned_Y5op_ne_i92_C1l,array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y5op_ne_i92_C1r));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:conv_integer */
integer L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_C3arg)
{
    L4ieee_Q15std_logic_arith_T8unsigned L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_V6result;
    L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_V6result.init((new array_info((&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->element_type,(&L4ieee_Q15std_logic_arith_I8unsigned_INFO)->index_type,L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_C3arg.info->left_bound,L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_C3arg.info->index_direction,L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_C3arg.info->right_bound,0)),enumeration(0));
    L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_V6result=array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_C3arg);
    return L4ieee_Q15std_logic_arith_Y12conv_integer_i372 (L4ieee_Q18std_logic_unsigned_Y12conv_integer_i100_V6result);
}
/* Implementation of subprogram :ieee:std_logic_unsigned:shl */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shl_i95(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y3shl_i95_C3arg,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y3shl_i95_C5count)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3shl_i359 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y3shl_i95_C3arg),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y3shl_i95_C5count))));
}
/* Implementation of subprogram :ieee:std_logic_unsigned:shr */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q18std_logic_unsigned_Y3shr_i98(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y3shr_i98_C3arg,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q18std_logic_unsigned_Y3shr_i98_C5count)
{
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q15std_logic_arith_Y3shr_i365 (array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y3shr_i98_C3arg),array_alias<L4ieee_Q15std_logic_arith_T8unsigned >((&L4ieee_Q15std_logic_arith_I8unsigned_INFO),L4ieee_Q18std_logic_unsigned_Y3shr_i98_C5count))));
}
/* Initialization function for package body :ieee:std_logic_unsigned */
int L4ieee_Q18std_logic_unsigned_init ();
int L3std_Q8standard_init ();
int L4ieee_Q15std_logic_arith_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_W18std_logic_unsigned_init_done = false;
int L4ieee_W18std_logic_unsigned_init(){
if (L4ieee_W18std_logic_unsigned_init_done) return 1;
L4ieee_W18std_logic_unsigned_init_done=true;
L4ieee_Q18std_logic_unsigned_init ();
L3std_Q8standard_init ();
L4ieee_Q15std_logic_arith_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_unsigned.vhdl","std_logic_unsigned.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":std_logic_unsigned");
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W18std_logic_unsigned_hinfo =
  add_handle("ieee","std_logic_unsigned",NULL,NULL,&L4ieee_W18std_logic_unsigned_init);

/* end of package body :ieee:std_logic_unsigned */
