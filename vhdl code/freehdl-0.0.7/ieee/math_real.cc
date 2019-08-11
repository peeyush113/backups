#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:math_real */
/* External declarations */
/* End of external declarations */
/* Prototype for subprogram :ieee:math_real:sign */
floatingpoint L4ieee_Q9math_real_Y4sign_i20(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:ceil */
floatingpoint L4ieee_Q9math_real_Y4ceil_i22(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:floor */
floatingpoint L4ieee_Q9math_real_Y5floor_i24(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:round */
floatingpoint L4ieee_Q9math_real_Y5round_i26(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:fmax */
floatingpoint L4ieee_Q9math_real_Y4fmax_i29(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:fmin */
floatingpoint L4ieee_Q9math_real_Y4fmin_i32(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:uniform */
void L4ieee_Q9math_real_X7uniform_i36(integer &,integer &,floatingpoint &);
/* Prototype for subprogram :ieee:math_real:srand */
integer L4ieee_Q9math_real_Y5srand_i38(const integer );
/* Prototype for subprogram :ieee:math_real:rand */
integer L4ieee_Q9math_real_Y4rand_i39();
/* Prototype for subprogram :ieee:math_real:get_rand_max */
integer L4ieee_Q9math_real_Y12get_rand_max_i40();
/* Prototype for subprogram :ieee:math_real:sqrt */
floatingpoint L4ieee_Q9math_real_Y4sqrt_i42(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cbrt */
floatingpoint L4ieee_Q9math_real_Y4cbrt_i44(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i47(const integer ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i50(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:exp */
floatingpoint L4ieee_Q9math_real_Y3exp_i52(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i54(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i57(const integer ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:sin */
floatingpoint L4ieee_Q9math_real_Y3sin_i59(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cos */
floatingpoint L4ieee_Q9math_real_Y3cos_i61(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:tan */
floatingpoint L4ieee_Q9math_real_Y3tan_i63(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:asin */
floatingpoint L4ieee_Q9math_real_Y4asin_i65(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:acos */
floatingpoint L4ieee_Q9math_real_Y4acos_i67(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atan */
floatingpoint L4ieee_Q9math_real_Y4atan_i69(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atan2 */
floatingpoint L4ieee_Q9math_real_Y5atan2_i72(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:sinh */
floatingpoint L4ieee_Q9math_real_Y4sinh_i74(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cosh */
floatingpoint L4ieee_Q9math_real_Y4cosh_i76(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:tanh */
floatingpoint L4ieee_Q9math_real_Y4tanh_i78(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:asinh */
floatingpoint L4ieee_Q9math_real_Y5asinh_i80(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:acosh */
floatingpoint L4ieee_Q9math_real_Y5acosh_i82(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atanh */
floatingpoint L4ieee_Q9math_real_Y5atanh_i84(const floatingpoint );
floatingpoint L4ieee_Q9math_real_C6math_e,L4ieee_Q9math_real_C8math_1_e,L4ieee_Q9math_real_C7math_pi,L4ieee_Q9math_real_C9math_1_pi,L4ieee_Q9math_real_C13math_log_of_2,L4ieee_Q9math_real_C14math_log_of_10,L4ieee_Q9math_real_C14math_log2_of_e,L4ieee_Q9math_real_C15math_log10_of_e,L4ieee_Q9math_real_C10math_sqrt2,L4ieee_Q9math_real_C12math_sqrt1_2,L4ieee_Q9math_real_C12math_sqrt_pi,L4ieee_Q9math_real_C15math_deg_to_rad,L4ieee_Q9math_real_C15math_rad_to_deg;
/* Initialization function for package :ieee:math_real */
int L3std_Q8standard_init ();
bool L4ieee_Q9math_real_init_done = false;
int L4ieee_Q9math_real_init(){
if (L4ieee_Q9math_real_init_done) return 1;
L4ieee_Q9math_real_init_done=true;
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/math_real.vhdl","math_real.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":math_real");
L4ieee_Q9math_real_C6math_e=2.71828182845904523536;
L4ieee_Q9math_real_C8math_1_e=0.36787944117144232160;
L4ieee_Q9math_real_C7math_pi=3.14159265358979323846;
L4ieee_Q9math_real_C9math_1_pi=0.31830988618379067154;
L4ieee_Q9math_real_C13math_log_of_2=0.69314718055994530942;
L4ieee_Q9math_real_C14math_log_of_10=2.30258509299404568402;
L4ieee_Q9math_real_C14math_log2_of_e=1.4426950408889634074;
L4ieee_Q9math_real_C15math_log10_of_e=0.43429448190325182765;
L4ieee_Q9math_real_C10math_sqrt2=1.41421356237309504880;
L4ieee_Q9math_real_C12math_sqrt1_2=0.70710678118654752440;
L4ieee_Q9math_real_C12math_sqrt_pi=1.77245385090551602730;
L4ieee_Q9math_real_C15math_deg_to_rad=0.01745329251994329577;
L4ieee_Q9math_real_C15math_rad_to_deg=57.29577951308232087685;
iname.pop();
handle_info *h = get_handle ("ieee","math_real",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:math_real */

/* package :ieee:math_complex */
/* External declarations */
/* End of external declarations */
/* Definitions for record type :ieee:math_complex:complex */
#define L4ieee_Q12math_complex_I7complex record_info
void *L4ieee_Q12math_complex_T7complex_ELEM_ADDR(void*,int);
struct L4ieee_Q12math_complex_T7complex_DATA {
  floatingpoint M2re;
  floatingpoint M2im;
  L4ieee_Q12math_complex_T7complex_DATA(floatingpoint M2re, floatingpoint M2im) : 
    M2re(M2re),
    M2im(M2im)
    { }
  L4ieee_Q12math_complex_T7complex_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M2re=((float_info_base*)einfos[0])->left_bound;
    M2im=((float_info_base*)einfos[1])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12math_complex_T7complex_DATA &src_data = *(L4ieee_Q12math_complex_T7complex_DATA*)((const record_base *)p)->data;
    M2re=src_data.M2re;
    M2im=src_data.M2im;
  };
};
#define L4ieee_Q12math_complex_T7complex record_type<L4ieee_Q12math_complex_T7complex_DATA>
extern record_info L4ieee_Q12math_complex_I7complex_INFO;
extern array_info L4ieee_Q12math_complex_I14complex_vector_INFO;
#define L4ieee_Q12math_complex_T14complex_vector array_type<L4ieee_Q12math_complex_T7complex >
#define L4ieee_Q12math_complex_I14complex_vector array_info

/* Definitions for record type :ieee:math_complex:complex_polar */
#define L4ieee_Q12math_complex_I13complex_polar record_info
void *L4ieee_Q12math_complex_T13complex_polar_ELEM_ADDR(void*,int);
struct L4ieee_Q12math_complex_T13complex_polar_DATA {
  floatingpoint M3mag;
  floatingpoint M3arg;
  L4ieee_Q12math_complex_T13complex_polar_DATA(floatingpoint M3mag, floatingpoint M3arg) : 
    M3mag(M3mag),
    M3arg(M3arg)
    { }
  L4ieee_Q12math_complex_T13complex_polar_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M3mag=((float_info_base*)einfos[0])->left_bound;
    M3arg=((float_info_base*)einfos[1])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12math_complex_T13complex_polar_DATA &src_data = *(L4ieee_Q12math_complex_T13complex_polar_DATA*)((const record_base *)p)->data;
    M3mag=src_data.M3mag;
    M3arg=src_data.M3arg;
  };
};
#define L4ieee_Q12math_complex_T13complex_polar record_type<L4ieee_Q12math_complex_T13complex_polar_DATA>
extern record_info L4ieee_Q12math_complex_I13complex_polar_INFO;
/* Prototype for subprogram :ieee:math_complex:cabs */
floatingpoint L4ieee_Q12math_complex_Y4cabs_i22(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:carg */
floatingpoint L4ieee_Q12math_complex_Y4carg_i24(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:cmplx */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y5cmplx_i27(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i29(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y8op_minus_i31(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4conj_i33(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y4conj_i35(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:csqrt */
L4ieee_Q12math_complex_T14complex_vector L4ieee_Q12math_complex_Y5csqrt_i37(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:cexp */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4cexp_i39(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:complex_to_polar */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y16complex_to_polar_i41(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:polar_to_complex */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y16polar_to_complex_i43(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i46(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i49(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i52(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i55(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i58(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i61(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i64(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i67(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i70(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i73(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i76(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i79(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i82(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i85(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i88(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i91(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i94(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i97(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i100(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i103(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i106(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i109(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i112(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i115(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i118(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i121(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i124(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i127(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i130(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i133(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i136(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i139(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_C7cbase_1,L4ieee_Q12math_complex_C7cbase_j,L4ieee_Q12math_complex_C5czero;
const char *L4ieee_Q12math_complex_T7complex_NAMES[] = {
  "re",
  "im"
};
void *L4ieee_Q12math_complex_T7complex_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12math_complex_T7complex_DATA &obj=*(L4ieee_Q12math_complex_T7complex_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M2re;
  case 1: return (void*)&obj.M2im;
  };
};
L4ieee_Q12math_complex_I7complex L4ieee_Q12math_complex_I7complex_INFO;
L4ieee_Q12math_complex_I14complex_vector L4ieee_Q12math_complex_I14complex_vector_INFO;
const char *L4ieee_Q12math_complex_T13complex_polar_NAMES[] = {
  "mag",
  "arg"
};
void *L4ieee_Q12math_complex_T13complex_polar_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12math_complex_T13complex_polar_DATA &obj=*(L4ieee_Q12math_complex_T13complex_polar_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M3mag;
  case 1: return (void*)&obj.M3arg;
  };
};
L4ieee_Q12math_complex_I13complex_polar L4ieee_Q12math_complex_I13complex_polar_INFO;
/* Initialization function for package :ieee:math_complex */
int L3std_Q8standard_init ();
bool L4ieee_Q12math_complex_init_done = false;
int L4ieee_Q12math_complex_init(){
if (L4ieee_Q12math_complex_init_done) return 1;
L4ieee_Q12math_complex_init_done=true;
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/math_real.vhdl","math_real.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":math_complex");
L4ieee_Q12math_complex_I7complex_INFO.set(2,sizeof(L4ieee_Q12math_complex_T7complex_DATA),L4ieee_Q12math_complex_T7complex_NAMES,L4ieee_Q12math_complex_T7complex_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4real_INFO)).set(1,(&L3std_Q8standard_I4real_INFO)).register_type(":ieee:math_complex",":ieee:math_complex:complex",":COMPLEX",NULL);
L4ieee_Q12math_complex_I14complex_vector_INFO.set((&L4ieee_Q12math_complex_I7complex_INFO),(&L3std_Q8standard_I7integer_INFO),-1).register_type(":ieee:math_complex",":ieee:math_complex:complex_vector",":COMPLEX_VECTOR",NULL);
L4ieee_Q12math_complex_I13complex_polar_INFO.set(2,sizeof(L4ieee_Q12math_complex_T13complex_polar_DATA),L4ieee_Q12math_complex_T13complex_polar_NAMES,L4ieee_Q12math_complex_T13complex_polar_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4real_INFO)).set(1,(&L3std_Q8standard_I4real_INFO)).register_type(":ieee:math_complex",":ieee:math_complex:complex_polar",":COMPLEX_POLAR",NULL);
L4ieee_Q12math_complex_C7cbase_1.init((&L4ieee_Q12math_complex_I7complex_INFO));
L4ieee_Q12math_complex_C7cbase_1=L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(1.0)).aggregate_set(1,const_pointer(0.0));
L4ieee_Q12math_complex_C7cbase_j.init((&L4ieee_Q12math_complex_I7complex_INFO));
L4ieee_Q12math_complex_C7cbase_j=L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(0.0)).aggregate_set(1,const_pointer(1.0));
L4ieee_Q12math_complex_C5czero.init((&L4ieee_Q12math_complex_I7complex_INFO));
L4ieee_Q12math_complex_C5czero=L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(0.0)).aggregate_set(1,const_pointer(0.0));
iname.pop();
handle_info *h = get_handle ("ieee","math_complex",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:math_complex */

/* package body :ieee:math_real */
/* External declarations */
/* End of external declarations */
extern array_info L4ieee_W9math_real_I11real_vector_INFO;
#define L4ieee_W9math_real_T11real_vector array_type<floatingpoint >
#define L4ieee_W9math_real_I11real_vector array_info

extern array_info L4ieee_W9math_real_I14natural_vector_INFO;
#define L4ieee_W9math_real_T14natural_vector array_type<integer >
#define L4ieee_W9math_real_I14natural_vector array_info

extern array_info L4ieee_W9math_real_I13real_vector_n_INFO;
#define L4ieee_W9math_real_T13real_vector_n array_type<floatingpoint >
#define L4ieee_W9math_real_I13real_vector_n array_info

extern array_info L4ieee_W9math_real_I10real_arr_2_INFO;
#define L4ieee_W9math_real_T10real_arr_2 array_type<floatingpoint >
#define L4ieee_W9math_real_I10real_arr_2 array_info

extern array_info L4ieee_W9math_real_I10real_arr_3_INFO;
#define L4ieee_W9math_real_T10real_arr_3 array_type<floatingpoint >
#define L4ieee_W9math_real_I10real_arr_3 array_info

/** Integer info class :ieee:math_real:quadrant */
class L4ieee_W9math_real_I8quadrant:public integer_info_base{
public:
   L4ieee_W9math_real_I8quadrant():integer_info_base(0,3,0,3) {};
   static integer low() { return 0; }
   static integer high() { return 3; }
   static integer left() { return 0; }
   static integer right() { return 3; }
};
extern L4ieee_W9math_real_I8quadrant L4ieee_W9math_real_I8quadrant_INFO;
/* Definitions for enumeration type :ieee:math_real:cordic_mode_type */
class L4ieee_W9math_real_I16cordic_mode_type:public enum_info_base{
   static const char *values[];
public:
   L4ieee_W9math_real_I16cordic_mode_type():enum_info_base(0,1,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 1; }
   static int left() { return 0; }
   static int right() { return 1; }
};
extern L4ieee_W9math_real_I16cordic_mode_type L4ieee_W9math_real_I16cordic_mode_type_INFO;
/* Prototype for subprogram :ieee:math_real:power_of_2_series */
L4ieee_W9math_real_T11real_vector L4ieee_W9math_real_Y17power_of_2_series_i44(const L4ieee_W9math_real_T14natural_vector &,const floatingpoint ,const integer );
/* Prototype for subprogram :ieee:math_real:cordic */
L4ieee_W9math_real_T10real_arr_3 L4ieee_W9math_real_Y6cordic_i59(const floatingpoint ,const floatingpoint ,const floatingpoint ,const integer ,const enumeration );
/* Prototype for subprogram :ieee:math_real:sign */
floatingpoint L4ieee_Q9math_real_Y4sign_i20(const floatingpoint );
/** Integer info class :ieee:math_real:ceil:long */
class L4ieee_Q9math_real_Y4ceil_i22_I4long:public integer_info_base{
public:
   L4ieee_Q9math_real_Y4ceil_i22_I4long():integer_info_base(-1073741824,1073741824,-1073741824,1073741824) {};
   static integer low() { return -1073741824; }
   static integer high() { return 1073741824; }
   static integer left() { return -1073741824; }
   static integer right() { return 1073741824; }
};
extern L4ieee_Q9math_real_Y4ceil_i22_I4long L4ieee_Q9math_real_Y4ceil_i22_I4long_INFO;
/* Prototype for subprogram :ieee:math_real:ceil */
floatingpoint L4ieee_Q9math_real_Y4ceil_i22(const floatingpoint );
/** Integer info class :ieee:math_real:floor:long */
class L4ieee_Q9math_real_Y5floor_i24_I4long:public integer_info_base{
public:
   L4ieee_Q9math_real_Y5floor_i24_I4long():integer_info_base(-1073741824,1073741824,-1073741824,1073741824) {};
   static integer low() { return -1073741824; }
   static integer high() { return 1073741824; }
   static integer left() { return -1073741824; }
   static integer right() { return 1073741824; }
};
extern L4ieee_Q9math_real_Y5floor_i24_I4long L4ieee_Q9math_real_Y5floor_i24_I4long_INFO;
/* Prototype for subprogram :ieee:math_real:floor */
floatingpoint L4ieee_Q9math_real_Y5floor_i24(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:round */
floatingpoint L4ieee_Q9math_real_Y5round_i26(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:fmax */
floatingpoint L4ieee_Q9math_real_Y4fmax_i29(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:fmin */
floatingpoint L4ieee_Q9math_real_Y4fmin_i32(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:uniform */
void L4ieee_Q9math_real_X7uniform_i36(integer &,integer &,floatingpoint &);
/* Prototype for subprogram :ieee:math_real:srand */
integer L4ieee_Q9math_real_Y5srand_i38(const integer );
/* Prototype for subprogram :ieee:math_real:rand */
integer L4ieee_Q9math_real_Y4rand_i39();
/* Prototype for subprogram :ieee:math_real:get_rand_max */
integer L4ieee_Q9math_real_Y12get_rand_max_i40();
/* Prototype for subprogram :ieee:math_real:sqrt */
floatingpoint L4ieee_Q9math_real_Y4sqrt_i42(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cbrt */
floatingpoint L4ieee_Q9math_real_Y4cbrt_i44(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i47(const integer ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i50(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:exp */
floatingpoint L4ieee_Q9math_real_Y3exp_i52(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i54(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i57(const integer ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:sin */
floatingpoint L4ieee_Q9math_real_Y3sin_i59(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cos */
floatingpoint L4ieee_Q9math_real_Y3cos_i61(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:tan */
floatingpoint L4ieee_Q9math_real_Y3tan_i63(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:asin */
floatingpoint L4ieee_Q9math_real_Y4asin_i65(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:acos */
floatingpoint L4ieee_Q9math_real_Y4acos_i67(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atan */
floatingpoint L4ieee_Q9math_real_Y4atan_i69(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atan2 */
floatingpoint L4ieee_Q9math_real_Y5atan2_i72(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_real:sinh */
floatingpoint L4ieee_Q9math_real_Y4sinh_i74(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:cosh */
floatingpoint L4ieee_Q9math_real_Y4cosh_i76(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:tanh */
floatingpoint L4ieee_Q9math_real_Y4tanh_i78(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:asinh */
floatingpoint L4ieee_Q9math_real_Y5asinh_i80(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:acosh */
floatingpoint L4ieee_Q9math_real_Y5acosh_i82(const floatingpoint );
/* Prototype for subprogram :ieee:math_real:atanh */
floatingpoint L4ieee_Q9math_real_Y5atanh_i84(const floatingpoint );
floatingpoint L4ieee_W9math_real_C4q_pi,L4ieee_W9math_real_C7half_pi,L4ieee_W9math_real_C6two_pi;
integer L4ieee_W9math_real_C8max_iter;
floatingpoint L4ieee_W9math_real_C2kc;
L4ieee_W9math_real_T11real_vector L4ieee_W9math_real_C12two_at_minus;
L4ieee_W9math_real_T13real_vector_n L4ieee_W9math_real_C7epsilon;
L4ieee_W9math_real_I11real_vector L4ieee_W9math_real_I11real_vector_INFO;
L4ieee_W9math_real_I14natural_vector L4ieee_W9math_real_I14natural_vector_INFO;
L4ieee_W9math_real_I13real_vector_n L4ieee_W9math_real_I13real_vector_n_INFO;
L4ieee_W9math_real_I10real_arr_2 L4ieee_W9math_real_I10real_arr_2_INFO;
L4ieee_W9math_real_I10real_arr_3 L4ieee_W9math_real_I10real_arr_3_INFO;
L4ieee_W9math_real_I8quadrant L4ieee_W9math_real_I8quadrant_INFO;
/* Implementation of enumeration type :ieee:math_real:cordic_mode_type */
const char *L4ieee_W9math_real_I16cordic_mode_type::values[]={"ROTATION","VECTORING"};
L4ieee_W9math_real_I16cordic_mode_type L4ieee_W9math_real_I16cordic_mode_type_INFO;
/* Implementation of subprogram :ieee:math_real:power_of_2_series */
L4ieee_W9math_real_T11real_vector L4ieee_W9math_real_Y17power_of_2_series_i44(const L4ieee_W9math_real_T14natural_vector &L4ieee_W9math_real_Y17power_of_2_series_i44_C1d,const floatingpoint L4ieee_W9math_real_Y17power_of_2_series_i44_C13initial_value,const integer L4ieee_W9math_real_Y17power_of_2_series_i44_C16number_of_values)
{
    L4ieee_W9math_real_T11real_vector L4ieee_W9math_real_Y17power_of_2_series_i44_V1v;
    floatingpoint L4ieee_W9math_real_Y17power_of_2_series_i44_V4temp;
    enumeration L4ieee_W9math_real_Y17power_of_2_series_i44_V4flag;
    integer L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i_lc,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_lc,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_ls;
    L4ieee_W9math_real_Y17power_of_2_series_i44_V1v.init((new array_info((&L4ieee_W9math_real_I11real_vector_INFO)->element_type,(&L4ieee_W9math_real_I11real_vector_INFO)->index_type,0,to,L4ieee_W9math_real_Y17power_of_2_series_i44_C16number_of_values,0)),-9.9999999999999998603e+306);
    L4ieee_W9math_real_Y17power_of_2_series_i44_V4temp=L4ieee_W9math_real_Y17power_of_2_series_i44_C13initial_value;
    L4ieee_W9math_real_Y17power_of_2_series_i44_V4flag=enumeration(1);
    for (L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i=0,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i_lc=up_range_to_length<integer>(0,L4ieee_W9math_real_Y17power_of_2_series_i44_C16number_of_values); L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i_lc!=0; L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i++,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i_lc--) {
      L4ieee_W9math_real_Y17power_of_2_series_i44_V1v[L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i]=L4ieee_W9math_real_Y17power_of_2_series_i44_V4temp;
      for (L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p=L4ieee_W9math_real_Y17power_of_2_series_i44_C1d.info->left_bound,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_ls=L4ieee_W9math_real_Y17power_of_2_series_i44_C1d.info->index_direction==to?+1:-1,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_lc=range_to_length<integer>(L4ieee_W9math_real_Y17power_of_2_series_i44_C1d.info->left_bound,L4ieee_W9math_real_Y17power_of_2_series_i44_C1d.info->index_direction,L4ieee_W9math_real_Y17power_of_2_series_i44_C1d.info->right_bound);L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_lc!=0; L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p+=L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_ls,L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p_lc--) {
        if((L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_C1i==L4ieee_W9math_real_Y17power_of_2_series_i44_C1d[L4ieee_W9math_real_Y17power_of_2_series_i44_L448ln_L450ln_C1p])) {
          L4ieee_W9math_real_Y17power_of_2_series_i44_V4flag=enumeration(0);
        }
      }
      if(L4ieee_W9math_real_Y17power_of_2_series_i44_V4flag) {
        L4ieee_W9math_real_Y17power_of_2_series_i44_V4temp=(L4ieee_W9math_real_Y17power_of_2_series_i44_V4temp/2.0);
      }
      L4ieee_W9math_real_Y17power_of_2_series_i44_V4flag=enumeration(1);
    }
    return array_alias<L4ieee_W9math_real_T11real_vector >((&L4ieee_W9math_real_I11real_vector_INFO),L4ieee_W9math_real_Y17power_of_2_series_i44_V1v);
}
/* Implementation of subprogram :ieee:math_real:cordic */
L4ieee_W9math_real_T10real_arr_3 L4ieee_W9math_real_Y6cordic_i59(const floatingpoint L4ieee_W9math_real_Y6cordic_i59_C2x0,const floatingpoint L4ieee_W9math_real_Y6cordic_i59_C2y0,const floatingpoint L4ieee_W9math_real_Y6cordic_i59_C2z0,const integer L4ieee_W9math_real_Y6cordic_i59_C1n,const enumeration L4ieee_W9math_real_Y6cordic_i59_C11cordic_mode)
{
    floatingpoint L4ieee_W9math_real_Y6cordic_i59_V1x,L4ieee_W9math_real_Y6cordic_i59_V1y,L4ieee_W9math_real_Y6cordic_i59_V1z,L4ieee_W9math_real_Y6cordic_i59_V6x_temp;
    integer L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k,L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k_lc,L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k,L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k_lc;
    L4ieee_W9math_real_Y6cordic_i59_V1x=L4ieee_W9math_real_Y6cordic_i59_C2x0;
    L4ieee_W9math_real_Y6cordic_i59_V1y=L4ieee_W9math_real_Y6cordic_i59_C2y0;
    L4ieee_W9math_real_Y6cordic_i59_V1z=L4ieee_W9math_real_Y6cordic_i59_C2z0;
    L4ieee_W9math_real_Y6cordic_i59_V6x_temp=-9.9999999999999998603e+306;
    if((L4ieee_W9math_real_Y6cordic_i59_C11cordic_mode==enumeration(0))) {
      for (L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k=0,L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k_lc=up_range_to_length<integer>(0,L4ieee_W9math_real_Y6cordic_i59_C1n); L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k_lc!=0; L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k++,L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k_lc--) {
        L4ieee_W9math_real_Y6cordic_i59_V6x_temp=L4ieee_W9math_real_Y6cordic_i59_V1x;
        if((L4ieee_W9math_real_Y6cordic_i59_V1z>=0.0)) {
          L4ieee_W9math_real_Y6cordic_i59_V1x=(L4ieee_W9math_real_Y6cordic_i59_V1x-(L4ieee_W9math_real_Y6cordic_i59_V1y*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1y=(L4ieee_W9math_real_Y6cordic_i59_V1y+(L4ieee_W9math_real_Y6cordic_i59_V6x_temp*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1z=(L4ieee_W9math_real_Y6cordic_i59_V1z-L4ieee_W9math_real_C7epsilon[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]);
        } else {
          L4ieee_W9math_real_Y6cordic_i59_V1x=(L4ieee_W9math_real_Y6cordic_i59_V1x+(L4ieee_W9math_real_Y6cordic_i59_V1y*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1y=(L4ieee_W9math_real_Y6cordic_i59_V1y-(L4ieee_W9math_real_Y6cordic_i59_V6x_temp*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1z=(L4ieee_W9math_real_Y6cordic_i59_V1z+L4ieee_W9math_real_C7epsilon[L4ieee_W9math_real_Y6cordic_i59_L464ln_C1k]);
        }
      }
    } else {
      for (L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k=0,L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k_lc=up_range_to_length<integer>(0,L4ieee_W9math_real_Y6cordic_i59_C1n); L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k_lc!=0; L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k++,L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k_lc--) {
        L4ieee_W9math_real_Y6cordic_i59_V6x_temp=L4ieee_W9math_real_Y6cordic_i59_V1x;
        if((L4ieee_W9math_real_Y6cordic_i59_V1y<0.0)) {
          L4ieee_W9math_real_Y6cordic_i59_V1x=(L4ieee_W9math_real_Y6cordic_i59_V1x-(L4ieee_W9math_real_Y6cordic_i59_V1y*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1y=(L4ieee_W9math_real_Y6cordic_i59_V1y+(L4ieee_W9math_real_Y6cordic_i59_V6x_temp*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1z=(L4ieee_W9math_real_Y6cordic_i59_V1z-L4ieee_W9math_real_C7epsilon[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]);
        } else {
          L4ieee_W9math_real_Y6cordic_i59_V1x=(L4ieee_W9math_real_Y6cordic_i59_V1x+(L4ieee_W9math_real_Y6cordic_i59_V1y*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1y=(L4ieee_W9math_real_Y6cordic_i59_V1y-(L4ieee_W9math_real_Y6cordic_i59_V6x_temp*L4ieee_W9math_real_C12two_at_minus[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]));
          L4ieee_W9math_real_Y6cordic_i59_V1z=(L4ieee_W9math_real_Y6cordic_i59_V1z+L4ieee_W9math_real_C7epsilon[L4ieee_W9math_real_Y6cordic_i59_L466ln_C1k]);
        }
      }
    }
    return array_alias<L4ieee_W9math_real_T11real_vector >((&L4ieee_W9math_real_I10real_arr_3_INFO),(L4ieee_W9math_real_T10real_arr_3(new array_info((&L4ieee_W9math_real_I10real_arr_3_INFO)->element_type,(&L4ieee_W9math_real_I10real_arr_3_INFO)->index_type,0,to,0+2,0),L4ieee_W9math_real_Y6cordic_i59_V1x).aggregate_set(0+1,to,0+1,L4ieee_W9math_real_Y6cordic_i59_V1y).aggregate_set(0+2,to,0+2,L4ieee_W9math_real_Y6cordic_i59_V1z)).data);
}
/* Implementation of subprogram :ieee:math_real:sign */
floatingpoint L4ieee_Q9math_real_Y4sign_i20(const floatingpoint L4ieee_Q9math_real_Y4sign_i20_C1x)
{
    if((L4ieee_Q9math_real_Y4sign_i20_C1x>0.0)) {
      return 1.0;
    } else {
      if((L4ieee_Q9math_real_Y4sign_i20_C1x<0.0)) {
        return -1.0000000000000000000;
      } else {
        return 0.0;
      }
    }
}
L4ieee_Q9math_real_Y4ceil_i22_I4long L4ieee_Q9math_real_Y4ceil_i22_I4long_INFO;
/* Implementation of subprogram :ieee:math_real:ceil */
floatingpoint L4ieee_Q9math_real_Y4ceil_i22(const floatingpoint L4ieee_Q9math_real_Y4ceil_i22_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y4ceil_i22_V5large,L4ieee_Q9math_real_Y4ceil_i22_V2rd;
    L4ieee_Q9math_real_Y4ceil_i22_V5large=1073741824.0;
    L4ieee_Q9math_real_Y4ceil_i22_V2rd=-9.9999999999999998603e+306;
    if((op_abs(L4ieee_Q9math_real_Y4ceil_i22_C1x)>=L4ieee_Q9math_real_Y4ceil_i22_V5large)) {
      return L4ieee_Q9math_real_Y4ceil_i22_C1x;
    } else {
      L4ieee_Q9math_real_Y4ceil_i22_V2rd=floatingpoint(integer(rint(L4ieee_Q9math_real_Y4ceil_i22_C1x)));
      if((L4ieee_Q9math_real_Y4ceil_i22_C1x>0.0)) {
        if((L4ieee_Q9math_real_Y4ceil_i22_V2rd>=L4ieee_Q9math_real_Y4ceil_i22_C1x)) {
          return L4ieee_Q9math_real_Y4ceil_i22_V2rd;
        } else {
          return (L4ieee_Q9math_real_Y4ceil_i22_V2rd+1.0);
        }
      } else {
        if((L4ieee_Q9math_real_Y4ceil_i22_C1x==0.0)) {
          return 0.0;
        } else {
          if((L4ieee_Q9math_real_Y4ceil_i22_V2rd<=L4ieee_Q9math_real_Y4ceil_i22_C1x)) {
            return L4ieee_Q9math_real_Y4ceil_i22_V2rd;
          } else {
            return (L4ieee_Q9math_real_Y4ceil_i22_V2rd-1.0);
          }
        }
      }
    }
}
L4ieee_Q9math_real_Y5floor_i24_I4long L4ieee_Q9math_real_Y5floor_i24_I4long_INFO;
/* Implementation of subprogram :ieee:math_real:floor */
floatingpoint L4ieee_Q9math_real_Y5floor_i24(const floatingpoint L4ieee_Q9math_real_Y5floor_i24_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y5floor_i24_V5large,L4ieee_Q9math_real_Y5floor_i24_V2rd;
    L4ieee_Q9math_real_Y5floor_i24_V5large=1073741824.0;
    L4ieee_Q9math_real_Y5floor_i24_V2rd=-9.9999999999999998603e+306;
    if((op_abs(L4ieee_Q9math_real_Y5floor_i24_C1x)>=L4ieee_Q9math_real_Y5floor_i24_V5large)) {
      return L4ieee_Q9math_real_Y5floor_i24_C1x;
    } else {
      L4ieee_Q9math_real_Y5floor_i24_V2rd=floatingpoint(integer(rint(L4ieee_Q9math_real_Y5floor_i24_C1x)));
      if((L4ieee_Q9math_real_Y5floor_i24_C1x>0.0)) {
        if((L4ieee_Q9math_real_Y5floor_i24_V2rd<=L4ieee_Q9math_real_Y5floor_i24_C1x)) {
          return L4ieee_Q9math_real_Y5floor_i24_V2rd;
        } else {
          return (L4ieee_Q9math_real_Y5floor_i24_V2rd-1.0);
        }
      } else {
        if((L4ieee_Q9math_real_Y5floor_i24_C1x==0.0)) {
          return 0.0;
        } else {
          if((L4ieee_Q9math_real_Y5floor_i24_V2rd>=L4ieee_Q9math_real_Y5floor_i24_C1x)) {
            return L4ieee_Q9math_real_Y5floor_i24_V2rd;
          } else {
            return (L4ieee_Q9math_real_Y5floor_i24_V2rd+1.0);
          }
        }
      }
    }
}
/* Implementation of subprogram :ieee:math_real:round */
floatingpoint L4ieee_Q9math_real_Y5round_i26(const floatingpoint L4ieee_Q9math_real_Y5round_i26_C1x)
{
    if((L4ieee_Q9math_real_Y5round_i26_C1x>0.0)) {
      return L4ieee_Q9math_real_Y5floor_i24 ((L4ieee_Q9math_real_Y5round_i26_C1x+0.5));
    } else {
      if((L4ieee_Q9math_real_Y5round_i26_C1x<0.0)) {
        return L4ieee_Q9math_real_Y4ceil_i22 ((L4ieee_Q9math_real_Y5round_i26_C1x-0.5));
      } else {
        return 0.0;
      }
    }
}
/* Implementation of subprogram :ieee:math_real:fmax */
floatingpoint L4ieee_Q9math_real_Y4fmax_i29(const floatingpoint L4ieee_Q9math_real_Y4fmax_i29_C1x,const floatingpoint L4ieee_Q9math_real_Y4fmax_i29_C1y)
{
    if((L4ieee_Q9math_real_Y4fmax_i29_C1x>L4ieee_Q9math_real_Y4fmax_i29_C1y)) {
      return L4ieee_Q9math_real_Y4fmax_i29_C1x;
    } else {
      return L4ieee_Q9math_real_Y4fmax_i29_C1y;
    }
}
/* Implementation of subprogram :ieee:math_real:fmin */
floatingpoint L4ieee_Q9math_real_Y4fmin_i32(const floatingpoint L4ieee_Q9math_real_Y4fmin_i32_C1x,const floatingpoint L4ieee_Q9math_real_Y4fmin_i32_C1y)
{
    if((L4ieee_Q9math_real_Y4fmin_i32_C1x<L4ieee_Q9math_real_Y4fmin_i32_C1y)) {
      return L4ieee_Q9math_real_Y4fmin_i32_C1x;
    } else {
      return L4ieee_Q9math_real_Y4fmin_i32_C1y;
    }
}
/* Implementation of subprogram :ieee:math_real:uniform */
void L4ieee_Q9math_real_X7uniform_i36(integer &L4ieee_Q9math_real_X7uniform_i36_V5seed1_PAR,integer &L4ieee_Q9math_real_X7uniform_i36_V5seed2_PAR,floatingpoint &L4ieee_Q9math_real_X7uniform_i36_V1x_PAR)
{
    integer L4ieee_Q9math_real_X7uniform_i36_V5seed1=L4ieee_Q9math_real_X7uniform_i36_V5seed1_PAR;
    integer L4ieee_Q9math_real_X7uniform_i36_V5seed2=L4ieee_Q9math_real_X7uniform_i36_V5seed2_PAR;
    floatingpoint L4ieee_Q9math_real_X7uniform_i36_V1x;
    integer L4ieee_Q9math_real_X7uniform_i36_V1k,L4ieee_Q9math_real_X7uniform_i36_V1z;
    L4ieee_Q9math_real_X7uniform_i36_V1k=-2147483648LL;
    L4ieee_Q9math_real_X7uniform_i36_V1z=-2147483648LL;
    L4ieee_Q9math_real_X7uniform_i36_V1k=(L4ieee_Q9math_real_X7uniform_i36_V5seed1/53668);
    L4ieee_Q9math_real_X7uniform_i36_V5seed1=((40014*(L4ieee_Q9math_real_X7uniform_i36_V5seed1-(L4ieee_Q9math_real_X7uniform_i36_V1k*53668)))-(L4ieee_Q9math_real_X7uniform_i36_V1k*12211));
    if((L4ieee_Q9math_real_X7uniform_i36_V5seed1<0)) {
      L4ieee_Q9math_real_X7uniform_i36_V5seed1=(L4ieee_Q9math_real_X7uniform_i36_V5seed1+2147483563);
    }
    L4ieee_Q9math_real_X7uniform_i36_V1k=(L4ieee_Q9math_real_X7uniform_i36_V5seed2/52774);
    L4ieee_Q9math_real_X7uniform_i36_V5seed2=((40692*(L4ieee_Q9math_real_X7uniform_i36_V5seed2-(L4ieee_Q9math_real_X7uniform_i36_V1k*52774)))-(L4ieee_Q9math_real_X7uniform_i36_V1k*3791));
    if((L4ieee_Q9math_real_X7uniform_i36_V5seed2<0)) {
      L4ieee_Q9math_real_X7uniform_i36_V5seed2=(L4ieee_Q9math_real_X7uniform_i36_V5seed2+2147483399);
    }
    L4ieee_Q9math_real_X7uniform_i36_V1z=(L4ieee_Q9math_real_X7uniform_i36_V5seed1-L4ieee_Q9math_real_X7uniform_i36_V5seed2);
    if((L4ieee_Q9math_real_X7uniform_i36_V1z<1)) {
      L4ieee_Q9math_real_X7uniform_i36_V1z=(L4ieee_Q9math_real_X7uniform_i36_V1z+2147483562);
    }
    L4ieee_Q9math_real_X7uniform_i36_V1x=(floatingpoint(L4ieee_Q9math_real_X7uniform_i36_V1z)*4.656613e-10);
    rlabel:
    L4ieee_Q9math_real_X7uniform_i36_V5seed1_PAR=L4ieee_Q9math_real_X7uniform_i36_V5seed1;
    L4ieee_Q9math_real_X7uniform_i36_V5seed2_PAR=L4ieee_Q9math_real_X7uniform_i36_V5seed2;
    L4ieee_Q9math_real_X7uniform_i36_V1x_PAR=L4ieee_Q9math_real_X7uniform_i36_V1x;
    return;
}
/* Implementation of subprogram :ieee:math_real:srand */
integer L4ieee_Q9math_real_Y5srand_i38(const integer L4ieee_Q9math_real_Y5srand_i38_C4seed)
{
/* NullStat impl */;
}
/* Implementation of subprogram :ieee:math_real:rand */
integer L4ieee_Q9math_real_Y4rand_i39()
{
/* NullStat impl */;
}
/* Implementation of subprogram :ieee:math_real:get_rand_max */
integer L4ieee_Q9math_real_Y12get_rand_max_i40()
{
/* NullStat impl */;
}
enumeration L4ieee_W9math_real_itn8_lit[]={88,32,60,32,48,32,105,110,32,83,81,82,84,40,88,41};
/* Implementation of subprogram :ieee:math_real:sqrt */
floatingpoint L4ieee_Q9math_real_Y4sqrt_i42(const floatingpoint L4ieee_Q9math_real_Y4sqrt_i42_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y4sqrt_i42_C6inival,L4ieee_Q9math_real_Y4sqrt_i42_C3eps,L4ieee_Q9math_real_Y4sqrt_i42_C12relative_err,L4ieee_Q9math_real_Y4sqrt_i42_V6oldval,L4ieee_Q9math_real_Y4sqrt_i42_V6newval;
    L4ieee_Q9math_real_Y4sqrt_i42_C6inival=1.5;
    L4ieee_Q9math_real_Y4sqrt_i42_C3eps=0.000001;
    L4ieee_Q9math_real_Y4sqrt_i42_C12relative_err=(9.9999999999999995475e-07*L4ieee_Q9math_real_Y4sqrt_i42_C1x);
    L4ieee_Q9math_real_Y4sqrt_i42_V6oldval=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y4sqrt_i42_V6newval=-9.9999999999999998603e+306;
    if((L4ieee_Q9math_real_Y4sqrt_i42_C1x<0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+15,0),L4ieee_W9math_real_itn8_lit),enumeration(2));
      return 0.0;
    }
    if((L4ieee_Q9math_real_Y4sqrt_i42_C1x==0.0)) {
      return 0.0;
    } else {
      if((L4ieee_Q9math_real_Y4sqrt_i42_C1x==1.0)) {
        return 1.0;
      }
    }
    L4ieee_Q9math_real_Y4sqrt_i42_V6oldval=1.5000000000000000000;
    L4ieee_Q9math_real_Y4sqrt_i42_V6newval=(((L4ieee_Q9math_real_Y4sqrt_i42_C1x/L4ieee_Q9math_real_Y4sqrt_i42_V6oldval)+L4ieee_Q9math_real_Y4sqrt_i42_V6oldval)/2.0);
    while((op_abs((L4ieee_Q9math_real_Y4sqrt_i42_V6newval-L4ieee_Q9math_real_Y4sqrt_i42_V6oldval))>L4ieee_Q9math_real_Y4sqrt_i42_C12relative_err)) {
      L4ieee_Q9math_real_Y4sqrt_i42_V6oldval=L4ieee_Q9math_real_Y4sqrt_i42_V6newval;
      L4ieee_Q9math_real_Y4sqrt_i42_V6newval=(((L4ieee_Q9math_real_Y4sqrt_i42_C1x/L4ieee_Q9math_real_Y4sqrt_i42_V6oldval)+L4ieee_Q9math_real_Y4sqrt_i42_V6oldval)/2.0);
    }
    return L4ieee_Q9math_real_Y4sqrt_i42_V6newval;
}
/* Implementation of subprogram :ieee:math_real:cbrt */
floatingpoint L4ieee_Q9math_real_Y4cbrt_i44(const floatingpoint L4ieee_Q9math_real_Y4cbrt_i44_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y4cbrt_i44_C6inival,L4ieee_Q9math_real_Y4cbrt_i44_C3eps,L4ieee_Q9math_real_Y4cbrt_i44_C12relative_err,L4ieee_Q9math_real_Y4cbrt_i44_V6xlocal;
    enumeration L4ieee_Q9math_real_Y4cbrt_i44_V8negative;
    floatingpoint L4ieee_Q9math_real_Y4cbrt_i44_V6oldval,L4ieee_Q9math_real_Y4cbrt_i44_V6newval;
    L4ieee_Q9math_real_Y4cbrt_i44_C6inival=1.5;
    L4ieee_Q9math_real_Y4cbrt_i44_C3eps=0.000001;
    L4ieee_Q9math_real_Y4cbrt_i44_C12relative_err=(9.9999999999999995475e-07*op_abs(L4ieee_Q9math_real_Y4cbrt_i44_C1x));
    L4ieee_Q9math_real_Y4cbrt_i44_V6xlocal=L4ieee_Q9math_real_Y4cbrt_i44_C1x;
    L4ieee_Q9math_real_Y4cbrt_i44_V8negative=(L4ieee_Q9math_real_Y4cbrt_i44_C1x<0.0);
    L4ieee_Q9math_real_Y4cbrt_i44_V6oldval=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y4cbrt_i44_V6newval=-9.9999999999999998603e+306;
    if((L4ieee_Q9math_real_Y4cbrt_i44_C1x==0.0)) {
      return 0.0;
    } else {
      if((L4ieee_Q9math_real_Y4cbrt_i44_C1x==1.0)) {
        return 1.0;
      } else {
        if((L4ieee_Q9math_real_Y4cbrt_i44_C1x==-1.0000000000000000000)) {
          return -1.0000000000000000000;
        }
      }
    }
    if(L4ieee_Q9math_real_Y4cbrt_i44_V8negative) {
      L4ieee_Q9math_real_Y4cbrt_i44_V6xlocal=(-L4ieee_Q9math_real_Y4cbrt_i44_C1x);
    }
    L4ieee_Q9math_real_Y4cbrt_i44_V6oldval=1.5000000000000000000;
    L4ieee_Q9math_real_Y4cbrt_i44_V6newval=(((L4ieee_Q9math_real_Y4cbrt_i44_V6xlocal/(L4ieee_Q9math_real_Y4cbrt_i44_V6oldval*L4ieee_Q9math_real_Y4cbrt_i44_V6oldval))+(2.0*L4ieee_Q9math_real_Y4cbrt_i44_V6oldval))/3.0);
    while((op_abs((L4ieee_Q9math_real_Y4cbrt_i44_V6newval-L4ieee_Q9math_real_Y4cbrt_i44_V6oldval))>L4ieee_Q9math_real_Y4cbrt_i44_C12relative_err)) {
      L4ieee_Q9math_real_Y4cbrt_i44_V6oldval=L4ieee_Q9math_real_Y4cbrt_i44_V6newval;
      L4ieee_Q9math_real_Y4cbrt_i44_V6newval=(((L4ieee_Q9math_real_Y4cbrt_i44_V6xlocal/(L4ieee_Q9math_real_Y4cbrt_i44_V6oldval*L4ieee_Q9math_real_Y4cbrt_i44_V6oldval))+(2.0*L4ieee_Q9math_real_Y4cbrt_i44_V6oldval))/3.0);
    }
    if(L4ieee_Q9math_real_Y4cbrt_i44_V8negative) {
      L4ieee_Q9math_real_Y4cbrt_i44_V6newval=(-L4ieee_Q9math_real_Y4cbrt_i44_V6newval);
    }
    return L4ieee_Q9math_real_Y4cbrt_i44_V6newval;
}
enumeration L4ieee_W9math_real_itn9_lit[]={88,32,61,32,48,32,97,110,100,32,89,32,60,61,32,48,46,48,32,105,110,32,88,42,42,89};
enumeration L4ieee_W9math_real_itn10_lit[]={88,32,60,32,48,32,97,110,100,32,89,32,92,61,32,105,110,116,101,103,101,114,32,105,110,32,88,42,42,89};
/* Implementation of subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i47(const integer L4ieee_Q9math_real_Y8op_power_i47_C1x,const floatingpoint L4ieee_Q9math_real_Y8op_power_i47_C1y)
{
    if(((L4ieee_Q9math_real_Y8op_power_i47_C1x==0)&&(L4ieee_Q9math_real_Y8op_power_i47_C1y<=0.0))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+25,0),L4ieee_W9math_real_itn9_lit),enumeration(2));
      return 0.0;
    }
    if(((L4ieee_Q9math_real_Y8op_power_i47_C1x<0)&&(L4ieee_Q9math_real_Y8op_power_i47_C1y!=floatingpoint(integer(rint(L4ieee_Q9math_real_Y8op_power_i47_C1y)))))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W9math_real_itn10_lit),enumeration(2));
      return 0.0;
    }
    return L4ieee_Q9math_real_Y3exp_i52 ((L4ieee_Q9math_real_Y8op_power_i47_C1y*L4ieee_Q9math_real_Y3log_i54 (floatingpoint(L4ieee_Q9math_real_Y8op_power_i47_C1x))));
}
enumeration L4ieee_W9math_real_itn11_lit[]={88,32,61,32,48,46,48,32,97,110,100,32,89,32,60,61,32,48,46,48,32,105,110,32,88,42,42,89};
enumeration L4ieee_W9math_real_itn12_lit[]={88,32,60,32,48,46,48,32,97,110,100,32,89,32,92,61,32,105,110,116,101,103,101,114,32,105,110,32,88,42,42,89};
/* Implementation of subprogram :ieee:math_real:"**" */
floatingpoint L4ieee_Q9math_real_Y8op_power_i50(const floatingpoint L4ieee_Q9math_real_Y8op_power_i50_C1x,const floatingpoint L4ieee_Q9math_real_Y8op_power_i50_C1y)
{
    if(((L4ieee_Q9math_real_Y8op_power_i50_C1x==0.0)&&(L4ieee_Q9math_real_Y8op_power_i50_C1y<=0.0))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+27,0),L4ieee_W9math_real_itn11_lit),enumeration(2));
      return 0.0;
    }
    if(((L4ieee_Q9math_real_Y8op_power_i50_C1x<0.0)&&(L4ieee_Q9math_real_Y8op_power_i50_C1y!=floatingpoint(integer(rint(L4ieee_Q9math_real_Y8op_power_i50_C1y)))))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+31,0),L4ieee_W9math_real_itn12_lit),enumeration(2));
      return 0.0;
    }
    return L4ieee_Q9math_real_Y3exp_i52 ((L4ieee_Q9math_real_Y8op_power_i50_C1y*L4ieee_Q9math_real_Y3log_i54 (L4ieee_Q9math_real_Y8op_power_i50_C1x)));
}
/* Implementation of subprogram :ieee:math_real:exp */
floatingpoint L4ieee_Q9math_real_Y3exp_i52(const floatingpoint L4ieee_Q9math_real_Y3exp_i52_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y3exp_i52_C3eps;
    enumeration L4ieee_Q9math_real_Y3exp_i52_V10reciprocal;
    floatingpoint L4ieee_Q9math_real_Y3exp_i52_V6xlocal,L4ieee_Q9math_real_Y3exp_i52_V6oldval,L4ieee_Q9math_real_Y3exp_i52_V3num;
    integer L4ieee_Q9math_real_Y3exp_i52_V5count;
    floatingpoint L4ieee_Q9math_real_Y3exp_i52_V5denom,L4ieee_Q9math_real_Y3exp_i52_V6newval;
    L4ieee_Q9math_real_Y3exp_i52_C3eps=0.000001;
    L4ieee_Q9math_real_Y3exp_i52_V10reciprocal=(L4ieee_Q9math_real_Y3exp_i52_C1x<0.0);
    L4ieee_Q9math_real_Y3exp_i52_V6xlocal=op_abs(L4ieee_Q9math_real_Y3exp_i52_C1x);
    L4ieee_Q9math_real_Y3exp_i52_V6oldval=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3exp_i52_V3num=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3exp_i52_V5count=-2147483648LL;
    L4ieee_Q9math_real_Y3exp_i52_V5denom=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3exp_i52_V6newval=-9.9999999999999998603e+306;
    if((L4ieee_Q9math_real_Y3exp_i52_C1x==0.0)) {
      return 1.0;
    } else {
      if((L4ieee_Q9math_real_Y3exp_i52_C1x==1.0)) {
        return 2.7182818284590450908;
      }
    }
    L4ieee_Q9math_real_Y3exp_i52_V6oldval=1.0;
    L4ieee_Q9math_real_Y3exp_i52_V3num=L4ieee_Q9math_real_Y3exp_i52_V6xlocal;
    L4ieee_Q9math_real_Y3exp_i52_V5count=1;
    L4ieee_Q9math_real_Y3exp_i52_V5denom=1.0;
    L4ieee_Q9math_real_Y3exp_i52_V6newval=(L4ieee_Q9math_real_Y3exp_i52_V6oldval+(L4ieee_Q9math_real_Y3exp_i52_V3num/L4ieee_Q9math_real_Y3exp_i52_V5denom));
    while((op_abs((L4ieee_Q9math_real_Y3exp_i52_V6newval-L4ieee_Q9math_real_Y3exp_i52_V6oldval))>9.9999999999999995475e-07)) {
      L4ieee_Q9math_real_Y3exp_i52_V6oldval=L4ieee_Q9math_real_Y3exp_i52_V6newval;
      L4ieee_Q9math_real_Y3exp_i52_V3num=(L4ieee_Q9math_real_Y3exp_i52_V3num*L4ieee_Q9math_real_Y3exp_i52_V6xlocal);
      L4ieee_Q9math_real_Y3exp_i52_V5count=(L4ieee_Q9math_real_Y3exp_i52_V5count+1);
      L4ieee_Q9math_real_Y3exp_i52_V5denom=(L4ieee_Q9math_real_Y3exp_i52_V5denom*floatingpoint(L4ieee_Q9math_real_Y3exp_i52_V5count));
      L4ieee_Q9math_real_Y3exp_i52_V6newval=(L4ieee_Q9math_real_Y3exp_i52_V6oldval+(L4ieee_Q9math_real_Y3exp_i52_V3num/L4ieee_Q9math_real_Y3exp_i52_V5denom));
    }
    if(L4ieee_Q9math_real_Y3exp_i52_V10reciprocal) {
      L4ieee_Q9math_real_Y3exp_i52_V6newval=(1.0/L4ieee_Q9math_real_Y3exp_i52_V6newval);
    }
    return L4ieee_Q9math_real_Y3exp_i52_V6newval;
}
enumeration L4ieee_W9math_real_itn13_lit[]={88,32,60,61,32,48,32,105,110,32,76,79,71,40,88,41};
/* Implementation of subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i54(const floatingpoint L4ieee_Q9math_real_Y3log_i54_C1x)
{
    floatingpoint L4ieee_Q9math_real_Y3log_i54_C3eps,L4ieee_Q9math_real_Y3log_i54_V6xlocal,L4ieee_Q9math_real_Y3log_i54_V6oldval,L4ieee_Q9math_real_Y3log_i54_V9xlocalsqr,L4ieee_Q9math_real_Y3log_i54_V6factor;
    integer L4ieee_Q9math_real_Y3log_i54_V5count;
    floatingpoint L4ieee_Q9math_real_Y3log_i54_V6newval;
    L4ieee_Q9math_real_Y3log_i54_C3eps=0.000001;
    L4ieee_Q9math_real_Y3log_i54_V6xlocal=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3log_i54_V6oldval=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3log_i54_V9xlocalsqr=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3log_i54_V6factor=-9.9999999999999998603e+306;
    L4ieee_Q9math_real_Y3log_i54_V5count=-2147483648LL;
    L4ieee_Q9math_real_Y3log_i54_V6newval=-9.9999999999999998603e+306;
    if((L4ieee_Q9math_real_Y3log_i54_C1x<=0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+15,0),L4ieee_W9math_real_itn13_lit),enumeration(2));
      return -9.9999999999999998603e+306;
    }
    if((L4ieee_Q9math_real_Y3log_i54_C1x==1.0)) {
      return 0.0;
    } else {
      if((L4ieee_Q9math_real_Y3log_i54_C1x==2.7182818284590450908)) {
        return 1.0;
      }
    }
    L4ieee_Q9math_real_Y3log_i54_V6xlocal=((L4ieee_Q9math_real_Y3log_i54_C1x-1.0)/(L4ieee_Q9math_real_Y3log_i54_C1x+1.0));
    L4ieee_Q9math_real_Y3log_i54_V6oldval=L4ieee_Q9math_real_Y3log_i54_V6xlocal;
    L4ieee_Q9math_real_Y3log_i54_V9xlocalsqr=(L4ieee_Q9math_real_Y3log_i54_V6xlocal*L4ieee_Q9math_real_Y3log_i54_V6xlocal);
    L4ieee_Q9math_real_Y3log_i54_V6factor=(L4ieee_Q9math_real_Y3log_i54_V6xlocal*L4ieee_Q9math_real_Y3log_i54_V9xlocalsqr);
    L4ieee_Q9math_real_Y3log_i54_V5count=3;
    L4ieee_Q9math_real_Y3log_i54_V6newval=(L4ieee_Q9math_real_Y3log_i54_V6oldval+(L4ieee_Q9math_real_Y3log_i54_V6factor/floatingpoint(L4ieee_Q9math_real_Y3log_i54_V5count)));
    while((op_abs((L4ieee_Q9math_real_Y3log_i54_V6newval-L4ieee_Q9math_real_Y3log_i54_V6oldval))>9.9999999999999995475e-07)) {
      L4ieee_Q9math_real_Y3log_i54_V6oldval=L4ieee_Q9math_real_Y3log_i54_V6newval;
      L4ieee_Q9math_real_Y3log_i54_V5count=(L4ieee_Q9math_real_Y3log_i54_V5count+2);
      L4ieee_Q9math_real_Y3log_i54_V6factor=(L4ieee_Q9math_real_Y3log_i54_V6factor*L4ieee_Q9math_real_Y3log_i54_V9xlocalsqr);
      L4ieee_Q9math_real_Y3log_i54_V6newval=(L4ieee_Q9math_real_Y3log_i54_V6oldval+(L4ieee_Q9math_real_Y3log_i54_V6factor/floatingpoint(L4ieee_Q9math_real_Y3log_i54_V5count)));
    }
    L4ieee_Q9math_real_Y3log_i54_V6newval=(L4ieee_Q9math_real_Y3log_i54_V6newval*2.0);
    return L4ieee_Q9math_real_Y3log_i54_V6newval;
}
enumeration L4ieee_W9math_real_itn14_lit[]={66,65,83,69,32,60,61,32,48,32,111,114,32,88,32,60,61,32,48,46,48,32,105,110,32,76,79,71,40,66,65,83,69,44,32,88,41};
/* Implementation of subprogram :ieee:math_real:log */
floatingpoint L4ieee_Q9math_real_Y3log_i57(const integer L4ieee_Q9math_real_Y3log_i57_C4base,const floatingpoint L4ieee_Q9math_real_Y3log_i57_C1x)
{
    if(((L4ieee_Q9math_real_Y3log_i57_C4base<=0)||(L4ieee_Q9math_real_Y3log_i57_C1x<=0.0))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W9math_real_itn14_lit),enumeration(2));
      return -9.9999999999999998603e+306;
    }
    return (L4ieee_Q9math_real_Y3log_i54 (L4ieee_Q9math_real_Y3log_i57_C1x)/L4ieee_Q9math_real_Y3log_i54 (floatingpoint(L4ieee_Q9math_real_Y3log_i57_C4base)));
}
/* Implementation of subprogram :ieee:math_real:sin */
floatingpoint L4ieee_Q9math_real_Y3sin_i59(const floatingpoint L4ieee_Q9math_real_Y3sin_i59_C1x)
{
    integer L4ieee_Q9math_real_Y3sin_i59_V1n;
    L4ieee_Q9math_real_Y3sin_i59_V1n=-2147483648LL;
    if(((L4ieee_Q9math_real_Y3sin_i59_C1x<1.6)&&(L4ieee_Q9math_real_Y3sin_i59_C1x>-1.6000000000000000888))) {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,L4ieee_Q9math_real_Y3sin_i59_C1x,27,enumeration(0))[1];
    }
    L4ieee_Q9math_real_Y3sin_i59_V1n=integer(rint((L4ieee_Q9math_real_Y3sin_i59_C1x/1.5707963267948965580)));
    switch(integer(op_mod(L4ieee_Q9math_real_Y3sin_i59_V1n,4))) {
    case 0: {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3sin_i59_C1x-(floatingpoint(L4ieee_Q9math_real_Y3sin_i59_V1n)*1.5707963267948965580)),27,enumeration(0))[1];
     } break;
    case 1: {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3sin_i59_C1x-(floatingpoint(L4ieee_Q9math_real_Y3sin_i59_V1n)*1.5707963267948965580)),27,enumeration(0))[0];
     } break;
    case 2: {
      return (-L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3sin_i59_C1x-(floatingpoint(L4ieee_Q9math_real_Y3sin_i59_V1n)*1.5707963267948965580)),27,enumeration(0))[1]);
     } break;
    case 3: {
      return (-L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3sin_i59_C1x-(floatingpoint(L4ieee_Q9math_real_Y3sin_i59_V1n)*1.5707963267948965580)),27,enumeration(0))[0]);
     } break;
    }
}
/* Implementation of subprogram :ieee:math_real:cos */
floatingpoint L4ieee_Q9math_real_Y3cos_i61(const floatingpoint L4ieee_Q9math_real_Y3cos_i61_C1x)
{
    integer L4ieee_Q9math_real_Y3cos_i61_V1n;
    L4ieee_Q9math_real_Y3cos_i61_V1n=-2147483648LL;
    if(((L4ieee_Q9math_real_Y3cos_i61_C1x<1.6)&&(L4ieee_Q9math_real_Y3cos_i61_C1x>-1.6000000000000000888))) {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,L4ieee_Q9math_real_Y3cos_i61_C1x,27,enumeration(0))[0];
    }
    L4ieee_Q9math_real_Y3cos_i61_V1n=integer(rint((L4ieee_Q9math_real_Y3cos_i61_C1x/1.5707963267948965580)));
    switch(integer(op_mod(L4ieee_Q9math_real_Y3cos_i61_V1n,4))) {
    case 0: {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3cos_i61_C1x-(floatingpoint(L4ieee_Q9math_real_Y3cos_i61_V1n)*1.5707963267948965580)),27,enumeration(0))[0];
     } break;
    case 1: {
      return (-L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3cos_i61_C1x-(floatingpoint(L4ieee_Q9math_real_Y3cos_i61_V1n)*1.5707963267948965580)),27,enumeration(0))[1]);
     } break;
    case 2: {
      return (-L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3cos_i61_C1x-(floatingpoint(L4ieee_Q9math_real_Y3cos_i61_V1n)*1.5707963267948965580)),27,enumeration(0))[0]);
     } break;
    case 3: {
      return L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3cos_i61_C1x-(floatingpoint(L4ieee_Q9math_real_Y3cos_i61_V1n)*1.5707963267948965580)),27,enumeration(0))[1];
     } break;
    }
}
/* Implementation of subprogram :ieee:math_real:tan */
floatingpoint L4ieee_Q9math_real_Y3tan_i63(const floatingpoint L4ieee_Q9math_real_Y3tan_i63_C1x)
{
    integer L4ieee_Q9math_real_Y3tan_i63_V1n;
    L4ieee_W9math_real_T10real_arr_3 L4ieee_Q9math_real_Y3tan_i63_V1v;
    L4ieee_Q9math_real_Y3tan_i63_V1n=integer(rint((L4ieee_Q9math_real_Y3tan_i63_C1x/1.5707963267948965580)));
    L4ieee_Q9math_real_Y3tan_i63_V1v.init((&L4ieee_W9math_real_I10real_arr_3_INFO),-9.9999999999999998603e+306);
    L4ieee_Q9math_real_Y3tan_i63_V1v=L4ieee_W9math_real_Y6cordic_i59 (0.60725293500888144482,0.0,(L4ieee_Q9math_real_Y3tan_i63_C1x-(floatingpoint(L4ieee_Q9math_real_Y3tan_i63_V1n)*1.5707963267948965580)),27,enumeration(0));
    if((op_mod(L4ieee_Q9math_real_Y3tan_i63_V1n,2)==0)) {
      return (L4ieee_Q9math_real_Y3tan_i63_V1v[1]/L4ieee_Q9math_real_Y3tan_i63_V1v[0]);
    } else {
      return (-(L4ieee_Q9math_real_Y3tan_i63_V1v[0]/L4ieee_Q9math_real_Y3tan_i63_V1v[1]));
    }
}
enumeration L4ieee_W9math_real_itn15_lit[]={79,117,116,32,111,102,32,114,97,110,103,101,32,112,97,114,97,109,101,116,101,114,32,112,97,115,115,101,100,32,116,111,32,65,83,73,78};
/* Implementation of subprogram :ieee:math_real:asin */
floatingpoint L4ieee_Q9math_real_Y4asin_i65(const floatingpoint L4ieee_Q9math_real_Y4asin_i65_C1x)
{
    if((op_abs(L4ieee_Q9math_real_Y4asin_i65_C1x)>1.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W9math_real_itn15_lit),enumeration(2));
      return L4ieee_Q9math_real_Y4asin_i65_C1x;
    } else {
      if((op_abs(L4ieee_Q9math_real_Y4asin_i65_C1x)<0.9)) {
        return L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4asin_i65_C1x/L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4asin_i65_C1x*L4ieee_Q9math_real_Y4asin_i65_C1x)))));
      } else {
        if((L4ieee_Q9math_real_Y4asin_i65_C1x>0.0)) {
          return (1.5707963267948965580-L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4asin_i65_C1x*L4ieee_Q9math_real_Y4asin_i65_C1x)))/L4ieee_Q9math_real_Y4asin_i65_C1x)));
        } else {
          return (-1.5707963267948965580+L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4asin_i65_C1x*L4ieee_Q9math_real_Y4asin_i65_C1x)))/L4ieee_Q9math_real_Y4asin_i65_C1x)));
        }
      }
    }
}
enumeration L4ieee_W9math_real_itn16_lit[]={79,117,116,32,111,102,32,114,97,110,103,101,32,112,97,114,97,109,101,116,101,114,32,112,97,115,115,101,100,32,116,111,32,65,67,79,83};
/* Implementation of subprogram :ieee:math_real:acos */
floatingpoint L4ieee_Q9math_real_Y4acos_i67(const floatingpoint L4ieee_Q9math_real_Y4acos_i67_C1x)
{
    if((op_abs(L4ieee_Q9math_real_Y4acos_i67_C1x)>1.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+36,0),L4ieee_W9math_real_itn16_lit),enumeration(2));
      return L4ieee_Q9math_real_Y4acos_i67_C1x;
    } else {
      if((op_abs(L4ieee_Q9math_real_Y4acos_i67_C1x)>0.9)) {
        if((L4ieee_Q9math_real_Y4acos_i67_C1x>0.0)) {
          return L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4acos_i67_C1x*L4ieee_Q9math_real_Y4acos_i67_C1x)))/L4ieee_Q9math_real_Y4acos_i67_C1x));
        } else {
          return (3.1415926535897931160-L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4acos_i67_C1x*L4ieee_Q9math_real_Y4acos_i67_C1x)))/L4ieee_Q9math_real_Y4acos_i67_C1x)));
        }
      } else {
        return (1.5707963267948965580-L4ieee_Q9math_real_Y4atan_i69 ((L4ieee_Q9math_real_Y4acos_i67_C1x/L4ieee_Q9math_real_Y4sqrt_i42 ((1.0-(L4ieee_Q9math_real_Y4acos_i67_C1x*L4ieee_Q9math_real_Y4acos_i67_C1x))))));
      }
    }
}
/* Implementation of subprogram :ieee:math_real:atan */
floatingpoint L4ieee_Q9math_real_Y4atan_i69(const floatingpoint L4ieee_Q9math_real_Y4atan_i69_C1x)
{
    return L4ieee_W9math_real_Y6cordic_i59 (1.0,L4ieee_Q9math_real_Y4atan_i69_C1x,0.0,27,enumeration(1))[2];
}
enumeration L4ieee_W9math_real_itn17_lit[]={97,116,97,110,50,40,48,46,48,44,32,48,46,48,41,32,105,115,32,117,110,100,101,116,101,114,109,105,110,101,100,44,32,114,101,116,117,114,110,101,100,32,48,44,48};
/* Implementation of subprogram :ieee:math_real:atan2 */
floatingpoint L4ieee_Q9math_real_Y5atan2_i72(const floatingpoint L4ieee_Q9math_real_Y5atan2_i72_C1x,const floatingpoint L4ieee_Q9math_real_Y5atan2_i72_C1y)
{
    if((L4ieee_Q9math_real_Y5atan2_i72_C1y==0.0)) {
      if((L4ieee_Q9math_real_Y5atan2_i72_C1x==0.0)) {
        if(!enumeration(0))
          report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+44,0),L4ieee_W9math_real_itn17_lit),enumeration(0));
        return 0.0;
      } else {
        if((L4ieee_Q9math_real_Y5atan2_i72_C1x>0.0)) {
          return 0.0;
        } else {
          return 3.1415926535897931160;
        }
      }
    } else {
      if((L4ieee_Q9math_real_Y5atan2_i72_C1x>0.0)) {
        return L4ieee_W9math_real_Y6cordic_i59 (L4ieee_Q9math_real_Y5atan2_i72_C1x,L4ieee_Q9math_real_Y5atan2_i72_C1y,0.0,27,enumeration(1))[2];
      } else {
        return (3.1415926535897931160+L4ieee_W9math_real_Y6cordic_i59 (L4ieee_Q9math_real_Y5atan2_i72_C1x,L4ieee_Q9math_real_Y5atan2_i72_C1y,0.0,27,enumeration(1))[2]);
      }
    }
}
/* Implementation of subprogram :ieee:math_real:sinh */
floatingpoint L4ieee_Q9math_real_Y4sinh_i74(const floatingpoint L4ieee_Q9math_real_Y4sinh_i74_C1x)
{
    return ((L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q9math_real_Y4sinh_i74_C1x)-L4ieee_Q9math_real_Y3exp_i52 ((-L4ieee_Q9math_real_Y4sinh_i74_C1x)))/2.0);
}
/* Implementation of subprogram :ieee:math_real:cosh */
floatingpoint L4ieee_Q9math_real_Y4cosh_i76(const floatingpoint L4ieee_Q9math_real_Y4cosh_i76_C1x)
{
    return ((L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q9math_real_Y4cosh_i76_C1x)+L4ieee_Q9math_real_Y3exp_i52 ((-L4ieee_Q9math_real_Y4cosh_i76_C1x)))/2.0);
}
/* Implementation of subprogram :ieee:math_real:tanh */
floatingpoint L4ieee_Q9math_real_Y4tanh_i78(const floatingpoint L4ieee_Q9math_real_Y4tanh_i78_C1x)
{
    return ((L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q9math_real_Y4tanh_i78_C1x)-L4ieee_Q9math_real_Y3exp_i52 ((-L4ieee_Q9math_real_Y4tanh_i78_C1x)))/(L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q9math_real_Y4tanh_i78_C1x)+L4ieee_Q9math_real_Y3exp_i52 ((-L4ieee_Q9math_real_Y4tanh_i78_C1x))));
}
/* Implementation of subprogram :ieee:math_real:asinh */
floatingpoint L4ieee_Q9math_real_Y5asinh_i80(const floatingpoint L4ieee_Q9math_real_Y5asinh_i80_C1x)
{
    return L4ieee_Q9math_real_Y3log_i54 ((L4ieee_Q9math_real_Y5asinh_i80_C1x+L4ieee_Q9math_real_Y4sqrt_i42 ((op_power(L4ieee_Q9math_real_Y5asinh_i80_C1x,2)+1.0))));
}
enumeration L4ieee_W9math_real_itn18_lit[]={79,117,116,32,111,102,32,114,97,110,103,101,32,112,97,114,97,109,101,116,101,114,32,112,97,115,115,101,100,32,116,111,32,65,67,79,83,72};
/* Implementation of subprogram :ieee:math_real:acosh */
floatingpoint L4ieee_Q9math_real_Y5acosh_i82(const floatingpoint L4ieee_Q9math_real_Y5acosh_i82_C1x)
{
    if((op_abs(L4ieee_Q9math_real_Y5acosh_i82_C1x)>=1.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W9math_real_itn18_lit),enumeration(2));
      return L4ieee_Q9math_real_Y5acosh_i82_C1x;
    }
    return L4ieee_Q9math_real_Y3log_i54 ((L4ieee_Q9math_real_Y5acosh_i82_C1x+L4ieee_Q9math_real_Y4sqrt_i42 ((op_power(L4ieee_Q9math_real_Y5acosh_i82_C1x,2)-1.0))));
}
enumeration L4ieee_W9math_real_itn19_lit[]={79,117,116,32,111,102,32,114,97,110,103,101,32,112,97,114,97,109,101,116,101,114,32,112,97,115,115,101,100,32,116,111,32,65,84,65,78,72};
/* Implementation of subprogram :ieee:math_real:atanh */
floatingpoint L4ieee_Q9math_real_Y5atanh_i84(const floatingpoint L4ieee_Q9math_real_Y5atanh_i84_C1x)
{
    if((op_abs(L4ieee_Q9math_real_Y5atanh_i84_C1x)<1.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+37,0),L4ieee_W9math_real_itn19_lit),enumeration(2));
      return L4ieee_Q9math_real_Y5atanh_i84_C1x;
    }
    return (L4ieee_Q9math_real_Y3log_i54 (((1.0+L4ieee_Q9math_real_Y5atanh_i84_C1x)/(1.0-L4ieee_Q9math_real_Y5atanh_i84_C1x)))/2.0);
}
/* Initialization function for package body :ieee:math_real */
int L4ieee_Q9math_real_init ();
int L3std_Q8standard_init ();
bool L4ieee_W9math_real_init_done = false;
int L4ieee_W9math_real_init(){
if (L4ieee_W9math_real_init_done) return 1;
L4ieee_W9math_real_init_done=true;
L4ieee_Q9math_real_init ();
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/math_real.vhdl","math_real.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":math_real");
L4ieee_W9math_real_I11real_vector_INFO.set((&L3std_Q8standard_I4real_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:math_real",":ieee:math_real:real_vector",":REAL_VECTOR",NULL);
L4ieee_W9math_real_I14natural_vector_INFO.set((&L3std_Q8standard_I7natural_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:math_real",":ieee:math_real:natural_vector",":NATURAL_VECTOR",NULL);
L4ieee_W9math_real_I13real_vector_n_INFO.set((&L3std_Q8standard_I4real_INFO),(&L3std_Q8standard_I7integer_INFO),0,to,27,-1).register_type(":ieee:math_real",":ieee:math_real:real_vector_n",":REAL_VECTOR_N",NULL);
L4ieee_W9math_real_I10real_arr_2_INFO.set((&L3std_Q8standard_I4real_INFO),(&L3std_Q8standard_I7integer_INFO),0,to,1,-1).register_type(":ieee:math_real",":ieee:math_real:real_arr_2",":REAL_ARR_2",NULL);
L4ieee_W9math_real_I10real_arr_3_INFO.set((&L3std_Q8standard_I4real_INFO),(&L3std_Q8standard_I7integer_INFO),0,to,2,-1).register_type(":ieee:math_real",":ieee:math_real:real_arr_3",":REAL_ARR_3",NULL);
L4ieee_W9math_real_I8quadrant_INFO.register_type(":ieee:math_real",":ieee:math_real:quadrant",":QUADRANT",NULL);
L4ieee_W9math_real_I16cordic_mode_type_INFO.register_type(":ieee:math_real",":ieee:math_real:cordic_mode_type",":CORDIC_MODE_TYPE",NULL);
L4ieee_Q9math_real_Y4ceil_i22_I4long_INFO.register_type(":ieee:math_real:ceil",":ieee:math_real:ceil:long",":long",NULL);
L4ieee_Q9math_real_Y5floor_i24_I4long_INFO.register_type(":ieee:math_real:floor",":ieee:math_real:floor:long",":long",NULL);
L4ieee_W9math_real_C4q_pi=0.78539816339744827900;
L4ieee_W9math_real_C7half_pi=1.5707963267948965580;
L4ieee_W9math_real_C6two_pi=6.2831853071795862320;
L4ieee_W9math_real_C8max_iter=27;
L4ieee_W9math_real_C2kc=6.0725293500888142e-01;
L4ieee_W9math_real_C12two_at_minus.init(const_pointer(L4ieee_W9math_real_Y17power_of_2_series_i44 (L4ieee_W9math_real_T14natural_vector(new array_info((&L4ieee_W9math_real_I14natural_vector_INFO)->element_type,(&L4ieee_W9math_real_I14natural_vector_INFO)->index_type,0,to,0+1,0),100).aggregate_set(0+1,to,0+1,90),1.0,27)));
L4ieee_W9math_real_C7epsilon.init((&L4ieee_W9math_real_I13real_vector_n_INFO),-9.9999999999999998603e+306);
L4ieee_W9math_real_C7epsilon=L4ieee_W9math_real_T13real_vector_n(new array_info((&L4ieee_W9math_real_I13real_vector_n_INFO)->element_type,(&L4ieee_W9math_real_I13real_vector_n_INFO)->index_type,0,to,0+27,0),7.8539816339744827e-01).aggregate_set(0+1,to,0+1,4.6364760900080606e-01).aggregate_set(0+2,to,0+2,2.4497866312686413e-01).aggregate_set(0+3,to,0+3,1.2435499454676144e-01).aggregate_set(0+4,to,0+4,6.2418809995957351e-02).aggregate_set(0+5,to,0+5,3.1239833430268277e-02).aggregate_set(0+6,to,0+6,1.5623728620476830e-02).aggregate_set(0+7,to,0+7,7.8123410601011116e-03).aggregate_set(0+8,to,0+8,3.9062301319669717e-03).aggregate_set(0+9,to,0+9,1.9531225164788189e-03).aggregate_set(0+10,to,0+10,9.7656218955931937e-04).aggregate_set(0+11,to,0+11,4.8828121119489829e-04).aggregate_set(0+12,to,0+12,2.4414062014936175e-04).aggregate_set(0+13,to,0+13,1.2207031189367021e-04).aggregate_set(0+14,to,0+14,6.1035156174208768e-05).aggregate_set(0+15,to,0+15,3.0517578115526093e-05).aggregate_set(0+16,to,0+16,1.5258789061315760e-05).aggregate_set(0+17,to,0+17,7.6293945311019699e-06).aggregate_set(0+18,to,0+18,3.8146972656064960e-06).aggregate_set(0+19,to,0+19,1.9073486328101870e-06).aggregate_set(0+20,to,0+20,9.5367431640596080e-07).aggregate_set(0+21,to,0+21,4.7683715820308876e-07).aggregate_set(0+22,to,0+22,2.3841857910155801e-07).aggregate_set(0+23,to,0+23,1.1920928955078067e-07).aggregate_set(0+24,to,0+24,5.9604644775390553e-08).aggregate_set(0+25,to,0+25,2.9802322387695303e-08).aggregate_set(0+26,to,0+26,1.4901161193847654e-08).aggregate_set(0+27,to,0+27,7.4505805969238281e-09);
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W9math_real_hinfo =
  add_handle("ieee","math_real",NULL,NULL,&L4ieee_W9math_real_init);

/* end of package body :ieee:math_real */

/* package body :ieee:math_complex */
/* External declarations */
/* End of external declarations */
/* Prototype for subprogram :ieee:math_complex:cabs */
floatingpoint L4ieee_Q12math_complex_Y4cabs_i22(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:carg */
floatingpoint L4ieee_Q12math_complex_Y4carg_i24(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:cmplx */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y5cmplx_i27(const floatingpoint ,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i29(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y8op_minus_i31(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4conj_i33(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y4conj_i35(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:csqrt */
L4ieee_Q12math_complex_T14complex_vector L4ieee_Q12math_complex_Y5csqrt_i37(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:cexp */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4cexp_i39(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:complex_to_polar */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y16complex_to_polar_i41(const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:polar_to_complex */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y16polar_to_complex_i43(const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i46(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i49(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i52(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i55(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i58(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i61(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i64(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i67(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i70(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i73(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i76(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i79(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i82(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i85(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i88(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i91(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i94(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i97(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i100(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i103(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i106(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i109(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i112(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i115(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i118(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i121(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i124(const L4ieee_Q12math_complex_T13complex_polar &,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i127(const L4ieee_Q12math_complex_T7complex &,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i130(const floatingpoint ,const L4ieee_Q12math_complex_T7complex &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i133(const L4ieee_Q12math_complex_T7complex &,const floatingpoint );
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i136(const floatingpoint ,const L4ieee_Q12math_complex_T13complex_polar &);
/* Prototype for subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i139(const L4ieee_Q12math_complex_T13complex_polar &,const floatingpoint );
/* Implementation of subprogram :ieee:math_complex:cabs */
floatingpoint L4ieee_Q12math_complex_Y4cabs_i22(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y4cabs_i22_C1z)
{
    L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y4cabs_i22_V5ztemp;
    L4ieee_Q12math_complex_Y4cabs_i22_V5ztemp.init((&L4ieee_Q12math_complex_I13complex_polar_INFO));
    L4ieee_Q12math_complex_Y4cabs_i22_V5ztemp=L4ieee_Q12math_complex_Y16complex_to_polar_i41 (L4ieee_Q12math_complex_Y4cabs_i22_C1z);
    return L4ieee_Q12math_complex_Y4cabs_i22_V5ztemp.value().M3mag;
}
/* Implementation of subprogram :ieee:math_complex:carg */
floatingpoint L4ieee_Q12math_complex_Y4carg_i24(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y4carg_i24_C1z)
{
    L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y4carg_i24_V5ztemp;
    L4ieee_Q12math_complex_Y4carg_i24_V5ztemp.init((&L4ieee_Q12math_complex_I13complex_polar_INFO));
    L4ieee_Q12math_complex_Y4carg_i24_V5ztemp=L4ieee_Q12math_complex_Y16complex_to_polar_i41 (L4ieee_Q12math_complex_Y4carg_i24_C1z);
    return L4ieee_Q12math_complex_Y4carg_i24_V5ztemp.value().M3arg;
}
/* Implementation of subprogram :ieee:math_complex:cmplx */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y5cmplx_i27(const floatingpoint L4ieee_Q12math_complex_Y5cmplx_i27_C1x,const floatingpoint L4ieee_Q12math_complex_Y5cmplx_i27_C1y)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(L4ieee_Q12math_complex_Y5cmplx_i27_C1x)).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y5cmplx_i27_C1y));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i29(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i29_C1z)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((-L4ieee_Q12math_complex_Y8op_minus_i29_C1z.value().M2re))).aggregate_set(1,const_pointer((-L4ieee_Q12math_complex_Y8op_minus_i29_C1z.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y8op_minus_i31(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i31_C1z)
{
    return L4ieee_Q12math_complex_T13complex_polar().init((&L4ieee_Q12math_complex_I13complex_polar_INFO)).aggregate_set(0,const_pointer(L4ieee_Q12math_complex_Y8op_minus_i31_C1z.value().M3mag)).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i31_C1z.value().M3arg+3.1415926535897931160)));
}
/* Implementation of subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4conj_i33(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y4conj_i33_C1z)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(L4ieee_Q12math_complex_Y4conj_i33_C1z.value().M2re)).aggregate_set(1,const_pointer((-L4ieee_Q12math_complex_Y4conj_i33_C1z.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:conj */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y4conj_i35(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y4conj_i35_C1z)
{
    return L4ieee_Q12math_complex_T13complex_polar().init((&L4ieee_Q12math_complex_I13complex_polar_INFO)).aggregate_set(0,const_pointer(L4ieee_Q12math_complex_Y4conj_i35_C1z.value().M3mag)).aggregate_set(1,const_pointer((-L4ieee_Q12math_complex_Y4conj_i35_C1z.value().M3arg)));
}
/* Implementation of subprogram :ieee:math_complex:csqrt */
L4ieee_Q12math_complex_T14complex_vector L4ieee_Q12math_complex_Y5csqrt_i37(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y5csqrt_i37_C1z)
{
    L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp;
    L4ieee_Q12math_complex_T14complex_vector L4ieee_Q12math_complex_Y5csqrt_i37_V4zout;
    floatingpoint L4ieee_Q12math_complex_Y5csqrt_i37_V4temp;
    L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.init((&L4ieee_Q12math_complex_I13complex_polar_INFO));
    L4ieee_Q12math_complex_Y5csqrt_i37_V4zout.init((new array_info((&L4ieee_Q12math_complex_I14complex_vector_INFO)->element_type,(&L4ieee_Q12math_complex_I14complex_vector_INFO)->index_type,0,to,1,0)));
    L4ieee_Q12math_complex_Y5csqrt_i37_V4temp=-9.9999999999999998603e+306;
    L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp=L4ieee_Q12math_complex_Y16complex_to_polar_i41 (L4ieee_Q12math_complex_Y5csqrt_i37_C1z);
    L4ieee_Q12math_complex_Y5csqrt_i37_V4temp=L4ieee_Q9math_real_Y4sqrt_i42 (L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.value().M3mag);
    L4ieee_Q12math_complex_Y5csqrt_i37_V4zout[0].value().M2re=(L4ieee_Q12math_complex_Y5csqrt_i37_V4temp*L4ieee_Q9math_real_Y3cos_i61 ((L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.value().M3arg/2.0)));
    L4ieee_Q12math_complex_Y5csqrt_i37_V4zout[0].value().M2im=(L4ieee_Q12math_complex_Y5csqrt_i37_V4temp*L4ieee_Q9math_real_Y3sin_i59 ((L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.value().M3arg/2.0)));
    L4ieee_Q12math_complex_Y5csqrt_i37_V4zout[1].value().M2re=(L4ieee_Q12math_complex_Y5csqrt_i37_V4temp*L4ieee_Q9math_real_Y3cos_i61 (((L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.value().M3arg/2.0)+3.1415926535897931160)));
    L4ieee_Q12math_complex_Y5csqrt_i37_V4zout[1].value().M2im=(L4ieee_Q12math_complex_Y5csqrt_i37_V4temp*L4ieee_Q9math_real_Y3sin_i59 (((L4ieee_Q12math_complex_Y5csqrt_i37_V5ztemp.value().M3arg/2.0)+3.1415926535897931160)));
    return array_alias<L4ieee_Q12math_complex_T14complex_vector >((&L4ieee_Q12math_complex_I14complex_vector_INFO),L4ieee_Q12math_complex_Y5csqrt_i37_V4zout);
}
/* Implementation of subprogram :ieee:math_complex:cexp */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y4cexp_i39(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y4cexp_i39_C1z)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q12math_complex_Y4cexp_i39_C1z.value().M2re)*L4ieee_Q9math_real_Y3cos_i61 (L4ieee_Q12math_complex_Y4cexp_i39_C1z.value().M2im)))).aggregate_set(1,const_pointer((L4ieee_Q9math_real_Y3exp_i52 (L4ieee_Q12math_complex_Y4cexp_i39_C1z.value().M2re)*L4ieee_Q9math_real_Y3sin_i59 (L4ieee_Q12math_complex_Y4cexp_i39_C1z.value().M2im))));
}
/* Implementation of subprogram :ieee:math_complex:complex_to_polar */
L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y16complex_to_polar_i41(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y16complex_to_polar_i41_C1z)
{
    return L4ieee_Q12math_complex_T13complex_polar().init((&L4ieee_Q12math_complex_I13complex_polar_INFO)).aggregate_set(0,const_pointer(L4ieee_Q9math_real_Y4sqrt_i42 ((op_power(L4ieee_Q12math_complex_Y16complex_to_polar_i41_C1z.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y16complex_to_polar_i41_C1z.value().M2im,2))))).aggregate_set(1,const_pointer(L4ieee_Q9math_real_Y5atan2_i72 (L4ieee_Q12math_complex_Y16complex_to_polar_i41_C1z.value().M2re,L4ieee_Q12math_complex_Y16complex_to_polar_i41_C1z.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:polar_to_complex */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y16polar_to_complex_i43(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y16polar_to_complex_i43_C1z)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y16polar_to_complex_i43_C1z.value().M3mag*L4ieee_Q9math_real_Y3cos_i61 (L4ieee_Q12math_complex_Y16polar_to_complex_i43_C1z.value().M3arg)))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y16polar_to_complex_i43_C1z.value().M3mag*L4ieee_Q9math_real_Y3sin_i59 (L4ieee_Q12math_complex_Y16polar_to_complex_i43_C1z.value().M3arg))));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i46(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i46_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i46_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i46_C1l.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i46_C1r.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i46_C1l.value().M2im+L4ieee_Q12math_complex_Y7op_plus_i46_C1r.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i49(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i49_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i49_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i49_V2zr,L4ieee_Q12math_complex_Y7op_plus_i49_V2zl;
    L4ieee_Q12math_complex_Y7op_plus_i49_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i49_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i49_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i49_C1l);
    L4ieee_Q12math_complex_Y7op_plus_i49_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i49_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i49_V2zl.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i49_V2zr.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i49_V2zl.value().M2im+L4ieee_Q12math_complex_Y7op_plus_i49_V2zr.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i52(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i52_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i52_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i52_V2zl;
    L4ieee_Q12math_complex_Y7op_plus_i52_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i52_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i52_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i52_V2zl.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i52_C1r.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i52_V2zl.value().M2im+L4ieee_Q12math_complex_Y7op_plus_i52_C1r.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i55(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i55_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i55_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i55_V2zr;
    L4ieee_Q12math_complex_Y7op_plus_i55_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i55_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i55_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i55_C1l.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i55_V2zr.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i55_C1l.value().M2im+L4ieee_Q12math_complex_Y7op_plus_i55_V2zr.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i58(const floatingpoint L4ieee_Q12math_complex_Y7op_plus_i58_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i58_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i58_C1l+L4ieee_Q12math_complex_Y7op_plus_i58_C1r.value().M2re))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y7op_plus_i58_C1r.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i61(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_plus_i61_C1l,const floatingpoint L4ieee_Q12math_complex_Y7op_plus_i61_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i61_C1l.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i61_C1r))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y7op_plus_i61_C1l.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i64(const floatingpoint L4ieee_Q12math_complex_Y7op_plus_i64_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i64_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i64_V2zr;
    L4ieee_Q12math_complex_Y7op_plus_i64_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i64_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i64_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i64_C1l+L4ieee_Q12math_complex_Y7op_plus_i64_V2zr.value().M2re))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y7op_plus_i64_V2zr.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"+" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i67(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_plus_i67_C1l,const floatingpoint L4ieee_Q12math_complex_Y7op_plus_i67_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_plus_i67_V2zl;
    L4ieee_Q12math_complex_Y7op_plus_i67_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_plus_i67_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_plus_i67_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_plus_i67_V2zl.value().M2re+L4ieee_Q12math_complex_Y7op_plus_i67_C1r))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y7op_plus_i67_V2zl.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i70(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i70_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i70_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i70_C1l.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i70_C1r.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i70_C1l.value().M2im-L4ieee_Q12math_complex_Y8op_minus_i70_C1r.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i73(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i73_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i73_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i73_V2zr,L4ieee_Q12math_complex_Y8op_minus_i73_V2zl;
    L4ieee_Q12math_complex_Y8op_minus_i73_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i73_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i73_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i73_C1l);
    L4ieee_Q12math_complex_Y8op_minus_i73_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i73_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i73_V2zl.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i73_V2zr.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i73_V2zl.value().M2im-L4ieee_Q12math_complex_Y8op_minus_i73_V2zr.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i76(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i76_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i76_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i76_V2zl;
    L4ieee_Q12math_complex_Y8op_minus_i76_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i76_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i76_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i76_V2zl.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i76_C1r.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i76_V2zl.value().M2im-L4ieee_Q12math_complex_Y8op_minus_i76_C1r.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i79(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i79_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i79_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i79_V2zr;
    L4ieee_Q12math_complex_Y8op_minus_i79_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i79_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i79_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i79_C1l.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i79_V2zr.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i79_C1l.value().M2im-L4ieee_Q12math_complex_Y8op_minus_i79_V2zr.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i82(const floatingpoint L4ieee_Q12math_complex_Y8op_minus_i82_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i82_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i82_C1l-L4ieee_Q12math_complex_Y8op_minus_i82_C1r.value().M2re))).aggregate_set(1,const_pointer((-(1.0*L4ieee_Q12math_complex_Y8op_minus_i82_C1r.value().M2im))));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i85(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y8op_minus_i85_C1l,const floatingpoint L4ieee_Q12math_complex_Y8op_minus_i85_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i85_C1l.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i85_C1r))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y8op_minus_i85_C1l.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i88(const floatingpoint L4ieee_Q12math_complex_Y8op_minus_i88_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i88_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i88_V2zr;
    L4ieee_Q12math_complex_Y8op_minus_i88_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i88_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i88_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i88_C1l-L4ieee_Q12math_complex_Y8op_minus_i88_V2zr.value().M2re))).aggregate_set(1,const_pointer((-(1.0*L4ieee_Q12math_complex_Y8op_minus_i88_V2zr.value().M2im))));
}
/* Implementation of subprogram :ieee:math_complex:"-" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i91(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y8op_minus_i91_C1l,const floatingpoint L4ieee_Q12math_complex_Y8op_minus_i91_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y8op_minus_i91_V2zl;
    L4ieee_Q12math_complex_Y8op_minus_i91_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y8op_minus_i91_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y8op_minus_i91_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y8op_minus_i91_V2zl.value().M2re-L4ieee_Q12math_complex_Y8op_minus_i91_C1r))).aggregate_set(1,const_pointer(L4ieee_Q12math_complex_Y8op_minus_i91_V2zl.value().M2im));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i94(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i94_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i94_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i94_C1l.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i94_C1r.value().M2re)-(L4ieee_Q12math_complex_Y7op_mult_i94_C1l.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i94_C1r.value().M2im)))).aggregate_set(1,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i94_C1l.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i94_C1r.value().M2im)+(L4ieee_Q12math_complex_Y7op_mult_i94_C1l.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i94_C1r.value().M2re))));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i97(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i97_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i97_C1r)
{
    L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y7op_mult_i97_V4zout;
    L4ieee_Q12math_complex_Y7op_mult_i97_V4zout.init((&L4ieee_Q12math_complex_I13complex_polar_INFO));
    L4ieee_Q12math_complex_Y7op_mult_i97_V4zout.value().M3mag=(L4ieee_Q12math_complex_Y7op_mult_i97_C1l.value().M3mag*L4ieee_Q12math_complex_Y7op_mult_i97_C1r.value().M3mag);
    L4ieee_Q12math_complex_Y7op_mult_i97_V4zout.value().M3arg=(L4ieee_Q12math_complex_Y7op_mult_i97_C1l.value().M3arg+L4ieee_Q12math_complex_Y7op_mult_i97_C1r.value().M3arg);
    return L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_mult_i97_V4zout);
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i100(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i100_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i100_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i100_V2zl;
    L4ieee_Q12math_complex_Y7op_mult_i100_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_mult_i100_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_mult_i100_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i100_V2zl.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i100_C1r.value().M2re)-(L4ieee_Q12math_complex_Y7op_mult_i100_V2zl.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i100_C1r.value().M2im)))).aggregate_set(1,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i100_V2zl.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i100_C1r.value().M2im)+(L4ieee_Q12math_complex_Y7op_mult_i100_V2zl.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i100_C1r.value().M2re))));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i103(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i103_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i103_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i103_V2zr;
    L4ieee_Q12math_complex_Y7op_mult_i103_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_mult_i103_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_mult_i103_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i103_C1l.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i103_V2zr.value().M2re)-(L4ieee_Q12math_complex_Y7op_mult_i103_C1l.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i103_V2zr.value().M2im)))).aggregate_set(1,const_pointer(((L4ieee_Q12math_complex_Y7op_mult_i103_C1l.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i103_V2zr.value().M2im)+(L4ieee_Q12math_complex_Y7op_mult_i103_C1l.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i103_V2zr.value().M2re))));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i106(const floatingpoint L4ieee_Q12math_complex_Y7op_mult_i106_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i106_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i106_C1l*L4ieee_Q12math_complex_Y7op_mult_i106_C1r.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i106_C1l*L4ieee_Q12math_complex_Y7op_mult_i106_C1r.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i109(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y7op_mult_i109_C1l,const floatingpoint L4ieee_Q12math_complex_Y7op_mult_i109_C1r)
{
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i109_C1l.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i109_C1r))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i109_C1l.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i109_C1r)));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i112(const floatingpoint L4ieee_Q12math_complex_Y7op_mult_i112_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i112_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i112_V2zr;
    L4ieee_Q12math_complex_Y7op_mult_i112_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_mult_i112_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_mult_i112_C1r);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i112_C1l*L4ieee_Q12math_complex_Y7op_mult_i112_V2zr.value().M2re))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i112_C1l*L4ieee_Q12math_complex_Y7op_mult_i112_V2zr.value().M2im)));
}
/* Implementation of subprogram :ieee:math_complex:"*" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i115(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y7op_mult_i115_C1l,const floatingpoint L4ieee_Q12math_complex_Y7op_mult_i115_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y7op_mult_i115_V2zl;
    L4ieee_Q12math_complex_Y7op_mult_i115_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y7op_mult_i115_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y7op_mult_i115_C1l);
    return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i115_V2zl.value().M2re*L4ieee_Q12math_complex_Y7op_mult_i115_C1r))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y7op_mult_i115_V2zl.value().M2im*L4ieee_Q12math_complex_Y7op_mult_i115_C1r)));
}
enumeration L4ieee_W12math_complex_itn20_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,44,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i118(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i118_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i118_C1r)
{
    floatingpoint L4ieee_Q12math_complex_Y6op_div_i118_V6magrsq;
    L4ieee_Q12math_complex_Y6op_div_i118_V6magrsq=(op_power(L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2im,2));
    if((L4ieee_Q12math_complex_Y6op_div_i118_V6magrsq==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+25,0),L4ieee_W12math_complex_itn20_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i118_C1l.value().M2re*L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2re)+(L4ieee_Q12math_complex_Y6op_div_i118_C1l.value().M2im*L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i118_V6magrsq))).aggregate_set(1,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i118_C1l.value().M2im*L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2re)-(L4ieee_Q12math_complex_Y6op_div_i118_C1l.value().M2re*L4ieee_Q12math_complex_Y6op_div_i118_C1r.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i118_V6magrsq)));
    }
}
enumeration L4ieee_W12math_complex_itn21_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,44,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i121(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i121_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i121_C1r)
{
    L4ieee_Q12math_complex_T13complex_polar L4ieee_Q12math_complex_Y6op_div_i121_V4zout;
    L4ieee_Q12math_complex_Y6op_div_i121_V4zout.init((&L4ieee_Q12math_complex_I13complex_polar_INFO));
    if((L4ieee_Q12math_complex_Y6op_div_i121_C1r.value().M3mag==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+25,0),L4ieee_W12math_complex_itn21_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      L4ieee_Q12math_complex_Y6op_div_i121_V4zout.value().M3mag=(L4ieee_Q12math_complex_Y6op_div_i121_C1l.value().M3mag/L4ieee_Q12math_complex_Y6op_div_i121_C1r.value().M3mag);
      L4ieee_Q12math_complex_Y6op_div_i121_V4zout.value().M3arg=(L4ieee_Q12math_complex_Y6op_div_i121_C1l.value().M3arg-L4ieee_Q12math_complex_Y6op_div_i121_C1r.value().M3arg);
      return L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y6op_div_i121_V4zout);
    }
}
enumeration L4ieee_W12math_complex_itn22_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i124(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i124_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i124_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i124_V2zl;
    floatingpoint L4ieee_Q12math_complex_Y6op_div_i124_V4temp;
    L4ieee_Q12math_complex_Y6op_div_i124_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y6op_div_i124_V4temp=(op_power(L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2im,2));
    if((L4ieee_Q12math_complex_Y6op_div_i124_V4temp==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn22_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      L4ieee_Q12math_complex_Y6op_div_i124_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y6op_div_i124_C1l);
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i124_V2zl.value().M2re*L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2re)+(L4ieee_Q12math_complex_Y6op_div_i124_V2zl.value().M2im*L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i124_V4temp))).aggregate_set(1,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i124_V2zl.value().M2im*L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2re)-(L4ieee_Q12math_complex_Y6op_div_i124_V2zl.value().M2re*L4ieee_Q12math_complex_Y6op_div_i124_C1r.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i124_V4temp)));
    }
}
enumeration L4ieee_W12math_complex_itn23_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i127(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i127_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i127_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i127_V2zr;
    floatingpoint L4ieee_Q12math_complex_Y6op_div_i127_V4temp;
    L4ieee_Q12math_complex_Y6op_div_i127_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y6op_div_i127_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y6op_div_i127_C1r);
    L4ieee_Q12math_complex_Y6op_div_i127_V4temp=(op_power(L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2im,2));
    if(((L4ieee_Q12math_complex_Y6op_div_i127_C1r.value().M3mag==0.0)||(L4ieee_Q12math_complex_Y6op_div_i127_V4temp==0.0))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn23_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i127_C1l.value().M2re*L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2re)+(L4ieee_Q12math_complex_Y6op_div_i127_C1l.value().M2im*L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i127_V4temp))).aggregate_set(1,const_pointer((((L4ieee_Q12math_complex_Y6op_div_i127_C1l.value().M2im*L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2re)-(L4ieee_Q12math_complex_Y6op_div_i127_C1l.value().M2re*L4ieee_Q12math_complex_Y6op_div_i127_V2zr.value().M2im))/L4ieee_Q12math_complex_Y6op_div_i127_V4temp)));
    }
}
enumeration L4ieee_W12math_complex_itn24_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i130(const floatingpoint L4ieee_Q12math_complex_Y6op_div_i130_C1l,const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i130_C1r)
{
    floatingpoint L4ieee_Q12math_complex_Y6op_div_i130_V4temp;
    L4ieee_Q12math_complex_Y6op_div_i130_V4temp=(op_power(L4ieee_Q12math_complex_Y6op_div_i130_C1r.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y6op_div_i130_C1r.value().M2im,2));
    if((L4ieee_Q12math_complex_Y6op_div_i130_V4temp==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn24_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      L4ieee_Q12math_complex_Y6op_div_i130_V4temp=(L4ieee_Q12math_complex_Y6op_div_i130_C1l/L4ieee_Q12math_complex_Y6op_div_i130_V4temp);
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y6op_div_i130_V4temp*L4ieee_Q12math_complex_Y6op_div_i130_C1r.value().M2re))).aggregate_set(1,const_pointer((-(L4ieee_Q12math_complex_Y6op_div_i130_V4temp*L4ieee_Q12math_complex_Y6op_div_i130_C1r.value().M2im))));
    }
}
enumeration L4ieee_W12math_complex_itn25_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i133(const L4ieee_Q12math_complex_T7complex &L4ieee_Q12math_complex_Y6op_div_i133_C1l,const floatingpoint L4ieee_Q12math_complex_Y6op_div_i133_C1r)
{
    if((L4ieee_Q12math_complex_Y6op_div_i133_C1r==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn25_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y6op_div_i133_C1l.value().M2re/L4ieee_Q12math_complex_Y6op_div_i133_C1r))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y6op_div_i133_C1l.value().M2im/L4ieee_Q12math_complex_Y6op_div_i133_C1r)));
    }
}
enumeration L4ieee_W12math_complex_itn26_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i136(const floatingpoint L4ieee_Q12math_complex_Y6op_div_i136_C1l,const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i136_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i136_V2zr;
    floatingpoint L4ieee_Q12math_complex_Y6op_div_i136_V4temp;
    L4ieee_Q12math_complex_Y6op_div_i136_V2zr.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y6op_div_i136_V2zr=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y6op_div_i136_C1r);
    L4ieee_Q12math_complex_Y6op_div_i136_V4temp=(op_power(L4ieee_Q12math_complex_Y6op_div_i136_V2zr.value().M2re,2)+op_power(L4ieee_Q12math_complex_Y6op_div_i136_V2zr.value().M2im,2));
    if(((L4ieee_Q12math_complex_Y6op_div_i136_C1r.value().M3mag==0.0)||(L4ieee_Q12math_complex_Y6op_div_i136_V4temp==0.0))) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn26_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      L4ieee_Q12math_complex_Y6op_div_i136_V4temp=(L4ieee_Q12math_complex_Y6op_div_i136_C1l/L4ieee_Q12math_complex_Y6op_div_i136_V4temp);
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y6op_div_i136_V4temp*L4ieee_Q12math_complex_Y6op_div_i136_V2zr.value().M2re))).aggregate_set(1,const_pointer((-(L4ieee_Q12math_complex_Y6op_div_i136_V4temp*L4ieee_Q12math_complex_Y6op_div_i136_V2zr.value().M2im))));
    }
}
enumeration L4ieee_W12math_complex_itn27_lit[]={65,116,116,101,109,112,116,32,116,111,32,100,105,118,105,100,101,32,98,121,32,40,48,46,48,44,48,46,48,41};
/* Implementation of subprogram :ieee:math_complex:"/" */
L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i139(const L4ieee_Q12math_complex_T13complex_polar &L4ieee_Q12math_complex_Y6op_div_i139_C1l,const floatingpoint L4ieee_Q12math_complex_Y6op_div_i139_C1r)
{
    L4ieee_Q12math_complex_T7complex L4ieee_Q12math_complex_Y6op_div_i139_V2zl;
    L4ieee_Q12math_complex_Y6op_div_i139_V2zl.init((&L4ieee_Q12math_complex_I7complex_INFO));
    L4ieee_Q12math_complex_Y6op_div_i139_V2zl=L4ieee_Q12math_complex_Y16polar_to_complex_i43 (L4ieee_Q12math_complex_Y6op_div_i139_C1l);
    if((L4ieee_Q12math_complex_Y6op_div_i139_C1r==0.0)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+29,0),L4ieee_W12math_complex_itn27_lit),enumeration(2));
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer(9.9999999999999998603e+306)).aggregate_set(1,const_pointer(9.9999999999999998603e+306));
    } else {
      return L4ieee_Q12math_complex_T7complex().init((&L4ieee_Q12math_complex_I7complex_INFO)).aggregate_set(0,const_pointer((L4ieee_Q12math_complex_Y6op_div_i139_V2zl.value().M2re/L4ieee_Q12math_complex_Y6op_div_i139_C1r))).aggregate_set(1,const_pointer((L4ieee_Q12math_complex_Y6op_div_i139_V2zl.value().M2im/L4ieee_Q12math_complex_Y6op_div_i139_C1r)));
    }
}
/* Initialization function for package body :ieee:math_complex */
int L4ieee_Q12math_complex_init ();
int L3std_Q8standard_init ();
int L4ieee_Q9math_real_init ();
bool L4ieee_W12math_complex_init_done = false;
int L4ieee_W12math_complex_init(){
if (L4ieee_W12math_complex_init_done) return 1;
L4ieee_W12math_complex_init_done=true;
L4ieee_Q12math_complex_init ();
L3std_Q8standard_init ();
L4ieee_Q9math_real_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/math_real.vhdl","math_real.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":math_complex");
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W12math_complex_hinfo =
  add_handle("ieee","math_complex",NULL,NULL,&L4ieee_W12math_complex_init);

/* end of package body :ieee:math_complex */
