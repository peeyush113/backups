#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:std_logic_1164 */
/* External declarations */
/* End of external declarations */
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
extern array_info L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO;
#define L4ieee_Q14std_logic_1164_T17std_ulogic_vector array_type<enumeration >
#define L4ieee_Q14std_logic_1164_I17std_ulogic_vector array_info

/* Prototype for subprogram :ieee:std_logic_1164:resolved */
enumeration L4ieee_Q14std_logic_1164_Y8resolved_i32(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
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

/** Enumeration info class :ieee:std_logic_1164:x01 */
class L4ieee_Q14std_logic_1164_I3x01:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q14std_logic_1164_I3x01():enum_info_base(1,3,values) {};
   static const char **get_values() { return values; }
   static int low() { return 1; }
   static int high() { return 3; }
   static int left() { return 1; }
   static int right() { return 3; }
};
extern L4ieee_Q14std_logic_1164_I3x01 L4ieee_Q14std_logic_1164_I3x01_INFO;
/** Enumeration info class :ieee:std_logic_1164:x01z */
class L4ieee_Q14std_logic_1164_I4x01z:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q14std_logic_1164_I4x01z():enum_info_base(1,4,values) {};
   static const char **get_values() { return values; }
   static int low() { return 1; }
   static int high() { return 4; }
   static int left() { return 1; }
   static int right() { return 4; }
};
extern L4ieee_Q14std_logic_1164_I4x01z L4ieee_Q14std_logic_1164_I4x01z_INFO;
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
/** Enumeration info class :ieee:std_logic_1164:ux01z */
class L4ieee_Q14std_logic_1164_I5ux01z:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q14std_logic_1164_I5ux01z():enum_info_base(0,4,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 4; }
   static int left() { return 0; }
   static int right() { return 4; }
};
extern L4ieee_Q14std_logic_1164_I5ux01z L4ieee_Q14std_logic_1164_I5ux01z_INFO;
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
enumeration L4ieee_Q14std_logic_1164_Y7op_nand_i54(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_nor_i60(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
enumeration L4ieee_Q14std_logic_1164_Y6op_not_i65(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_and_i68(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_and_i71(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i77(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y5op_or_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y5op_or_i83(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i89(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i92(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i95(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_not_i97(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_not_i99(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_bit */
enumeration L4ieee_Q14std_logic_1164_Y6to_bit_i102(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i108(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogic */
enumeration L4ieee_Q14std_logic_1164_Y12to_stdulogic_i110(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i120(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i122(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i124(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i126(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i128(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i130(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i132(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i134(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i136(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i138(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i140(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i142(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i144(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i146(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i148(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i150(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i152(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i154(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:rising_edge */
enumeration L4ieee_Q14std_logic_1164_Y11rising_edge_i156(sig_info<enumeration> *,enumeration *);
/* Prototype for subprogram :ieee:std_logic_1164:falling_edge */
enumeration L4ieee_Q14std_logic_1164_Y12falling_edge_i158(sig_info<enumeration> *,enumeration *);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i160(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i162(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i164(const enumeration );
/* Implementation of enumeration type :ieee:std_logic_1164:std_ulogic */
const char *L4ieee_Q14std_logic_1164_I10std_ulogic::values[]={"'U'","'X'","'0'","'1'","'Z'","'W'","'L'","'H'","'-'"};
L4ieee_Q14std_logic_1164_I10std_ulogic L4ieee_Q14std_logic_1164_I10std_ulogic_INFO;
L4ieee_Q14std_logic_1164_I17std_ulogic_vector L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO;
/* Implementation of enumeration type :ieee:std_logic_1164:std_logic */
const char **L4ieee_Q14std_logic_1164_I9std_logic::values=((enum_info_base&)L4ieee_Q14std_logic_1164_I9std_logic_INFO).values=&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.get_values()[enumeration(0)];
L4ieee_Q14std_logic_1164_I9std_logic L4ieee_Q14std_logic_1164_I9std_logic_INFO;
L4ieee_Q14std_logic_1164_I16std_logic_vector L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO;
/* Implementation of enumeration type :ieee:std_logic_1164:x01 */
const char **L4ieee_Q14std_logic_1164_I3x01::values=((enum_info_base&)L4ieee_Q14std_logic_1164_I3x01_INFO).values=&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.get_values()[enumeration(1)];
L4ieee_Q14std_logic_1164_I3x01 L4ieee_Q14std_logic_1164_I3x01_INFO;
/* Implementation of enumeration type :ieee:std_logic_1164:x01z */
const char **L4ieee_Q14std_logic_1164_I4x01z::values=((enum_info_base&)L4ieee_Q14std_logic_1164_I4x01z_INFO).values=&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.get_values()[enumeration(1)];
L4ieee_Q14std_logic_1164_I4x01z L4ieee_Q14std_logic_1164_I4x01z_INFO;
/* Implementation of enumeration type :ieee:std_logic_1164:ux01 */
const char **L4ieee_Q14std_logic_1164_I4ux01::values=((enum_info_base&)L4ieee_Q14std_logic_1164_I4ux01_INFO).values=&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.get_values()[enumeration(0)];
L4ieee_Q14std_logic_1164_I4ux01 L4ieee_Q14std_logic_1164_I4ux01_INFO;
/* Implementation of enumeration type :ieee:std_logic_1164:ux01z */
const char **L4ieee_Q14std_logic_1164_I5ux01z::values=((enum_info_base&)L4ieee_Q14std_logic_1164_I5ux01z_INFO).values=&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.get_values()[enumeration(0)];
L4ieee_Q14std_logic_1164_I5ux01z L4ieee_Q14std_logic_1164_I5ux01z_INFO;
/* Initialization function for package :ieee:std_logic_1164 */
int L3std_Q8standard_init ();
bool L4ieee_Q14std_logic_1164_init_done = false;
int L4ieee_Q14std_logic_1164_init(){
if (L4ieee_Q14std_logic_1164_init_done) return 1;
L4ieee_Q14std_logic_1164_init_done=true;
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_1164.vhdl","std_logic_1164.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":std_logic_1164");
L4ieee_Q14std_logic_1164_I10std_ulogic_INFO.register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:std_ulogic",":std_ulogic",NULL);
L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:std_ulogic_vector",":std_ulogic_vector",NULL);
L4ieee_Q14std_logic_1164_I9std_logic_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO)).add_resolver(resolver_handler<enumeration,L4ieee_Q14std_logic_1164_Y8resolved_i32>,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),true).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:std_logic",":std_logic",NULL);
L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:std_logic_vector",":std_logic_vector",NULL);
L4ieee_Q14std_logic_1164_I3x01_INFO.register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:x01",":X01",NULL);
L4ieee_Q14std_logic_1164_I4x01z_INFO.register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:x01z",":X01Z",NULL);
L4ieee_Q14std_logic_1164_I4ux01_INFO.register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:ux01",":UX01",NULL);
L4ieee_Q14std_logic_1164_I5ux01z_INFO.register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:ux01z",":UX01Z",NULL);
iname.pop();
handle_info *h = get_handle ("ieee","std_logic_1164",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:std_logic_1164 */

/* package body :ieee:std_logic_1164 */
/* External declarations */
/* End of external declarations */
extern array_info L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO;
#define L4ieee_W14std_logic_1164_T11stdlogic_1d array_type<enumeration >
#define L4ieee_W14std_logic_1164_I11stdlogic_1d array_info

extern array_info L4ieee_W14std_logic_1164_I14stdlogic_table_INFO;
#define L4ieee_W14std_logic_1164_T14stdlogic_table array_type<array_type<enumeration > >
#define L4ieee_W14std_logic_1164_I14stdlogic_table array_info

/* Prototype for subprogram :ieee:std_logic_1164:resolved */
enumeration L4ieee_Q14std_logic_1164_Y8resolved_i32(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
enumeration L4ieee_Q14std_logic_1164_Y7op_nand_i54(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_nor_i60(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
enumeration L4ieee_Q14std_logic_1164_Y6op_not_i65(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_and_i68(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_and_i71(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i77(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y5op_or_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y5op_or_i83(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i89(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i92(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i95(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_not_i97(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_not_i99(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
extern array_info L4ieee_W14std_logic_1164_I15logic_x01_table_INFO;
#define L4ieee_W14std_logic_1164_T15logic_x01_table array_type<enumeration >
#define L4ieee_W14std_logic_1164_I15logic_x01_table array_info

extern array_info L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO;
#define L4ieee_W14std_logic_1164_T16logic_x01z_table array_type<enumeration >
#define L4ieee_W14std_logic_1164_I16logic_x01z_table array_info

extern array_info L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO;
#define L4ieee_W14std_logic_1164_T16logic_ux01_table array_type<enumeration >
#define L4ieee_W14std_logic_1164_I16logic_ux01_table array_info

/* Prototype for subprogram :ieee:std_logic_1164:to_bit */
enumeration L4ieee_Q14std_logic_1164_Y6to_bit_i102(const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i108(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &,const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogic */
enumeration L4ieee_Q14std_logic_1164_Y12to_stdulogic_i110(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i120(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i122(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i124(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i126(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i128(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i130(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i132(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i134(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i136(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i138(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i140(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i142(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i144(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i146(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i148(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i150(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i152(const L3std_Q8standard_T10bit_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i154(const enumeration );
/* Prototype for subprogram :ieee:std_logic_1164:rising_edge */
enumeration L4ieee_Q14std_logic_1164_Y11rising_edge_i156(sig_info<enumeration> *,enumeration *);
/* Prototype for subprogram :ieee:std_logic_1164:falling_edge */
enumeration L4ieee_Q14std_logic_1164_Y12falling_edge_i158(sig_info<enumeration> *,enumeration *);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i160(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i162(const L4ieee_Q14std_logic_1164_T16std_logic_vector &);
/* Prototype for subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i164(const enumeration );
L4ieee_W14std_logic_1164_T14stdlogic_table L4ieee_W14std_logic_1164_C16resolution_table,L4ieee_W14std_logic_1164_C9and_table,L4ieee_W14std_logic_1164_C8or_table,L4ieee_W14std_logic_1164_C9xor_table;
L4ieee_W14std_logic_1164_T11stdlogic_1d L4ieee_W14std_logic_1164_C9not_table;
L4ieee_W14std_logic_1164_T15logic_x01_table L4ieee_W14std_logic_1164_C10cvt_to_x01;
L4ieee_W14std_logic_1164_T16logic_x01z_table L4ieee_W14std_logic_1164_C11cvt_to_x01z;
L4ieee_W14std_logic_1164_T16logic_ux01_table L4ieee_W14std_logic_1164_C11cvt_to_ux01;
L4ieee_W14std_logic_1164_I11stdlogic_1d L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO;
L4ieee_W14std_logic_1164_I14stdlogic_table L4ieee_W14std_logic_1164_I14stdlogic_table_INFO;
/* Implementation of subprogram :ieee:std_logic_1164:resolved */
enumeration L4ieee_Q14std_logic_1164_Y8resolved_i32(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s)
{
    enumeration L4ieee_Q14std_logic_1164_Y8resolved_i32_V6result;
    integer L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i,L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_lc,L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_ls;
    L4ieee_Q14std_logic_1164_Y8resolved_i32_V6result=enumeration(4);
    if((L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->length==1)) {
      return L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s[min(L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->right_bound)];
    } else {
      for (L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i=L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_ls=L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->index_direction==to?+1:-1,L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_lc=range_to_length<integer>(L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->index_direction,L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s.info->right_bound);L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i+=L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_ls,L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y8resolved_i32_V6result=L4ieee_W14std_logic_1164_C16resolution_table[L4ieee_Q14std_logic_1164_Y8resolved_i32_V6result][L4ieee_Q14std_logic_1164_Y8resolved_i32_C1s[L4ieee_Q14std_logic_1164_Y8resolved_i32_L422ln_C1i]];
      }
    }
    return L4ieee_Q14std_logic_1164_Y8resolved_i32_V6result;
}
/* Implementation of subprogram :ieee:std_logic_1164:"and" */
enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51(const enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51_C1l,const enumeration L4ieee_Q14std_logic_1164_Y6op_and_i51_C1r)
{
    return L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y6op_and_i51_C1l][L4ieee_Q14std_logic_1164_Y6op_and_i51_C1r];
}
/* Implementation of subprogram :ieee:std_logic_1164:"nand" */
enumeration L4ieee_Q14std_logic_1164_Y7op_nand_i54(const enumeration L4ieee_Q14std_logic_1164_Y7op_nand_i54_C1l,const enumeration L4ieee_Q14std_logic_1164_Y7op_nand_i54_C1r)
{
    return L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y7op_nand_i54_C1l][L4ieee_Q14std_logic_1164_Y7op_nand_i54_C1r]];
}
/* Implementation of subprogram :ieee:std_logic_1164:"or" */
enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57(const enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57_C1l,const enumeration L4ieee_Q14std_logic_1164_Y5op_or_i57_C1r)
{
    return L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y5op_or_i57_C1l][L4ieee_Q14std_logic_1164_Y5op_or_i57_C1r];
}
/* Implementation of subprogram :ieee:std_logic_1164:"nor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_nor_i60(const enumeration L4ieee_Q14std_logic_1164_Y6op_nor_i60_C1l,const enumeration L4ieee_Q14std_logic_1164_Y6op_nor_i60_C1r)
{
    return L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y6op_nor_i60_C1l][L4ieee_Q14std_logic_1164_Y6op_nor_i60_C1r]];
}
/* Implementation of subprogram :ieee:std_logic_1164:"xor" */
enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63(const enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63_C1l,const enumeration L4ieee_Q14std_logic_1164_Y6op_xor_i63_C1r)
{
    return L4ieee_W14std_logic_1164_C9xor_table[L4ieee_Q14std_logic_1164_Y6op_xor_i63_C1l][L4ieee_Q14std_logic_1164_Y6op_xor_i63_C1r];
}
/* Implementation of subprogram :ieee:std_logic_1164:"not" */
enumeration L4ieee_Q14std_logic_1164_Y6op_not_i65(const enumeration L4ieee_Q14std_logic_1164_Y6op_not_i65_C1l)
{
    return L4ieee_W14std_logic_1164_C9not_table[L4ieee_Q14std_logic_1164_Y6op_not_i65_C1l];
}
enumeration L4ieee_W14std_logic_1164_itn33_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,97,110,100,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_and_i68(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_and_i68_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y6op_and_i68_H2lv,L4ieee_Q14std_logic_1164_Y6op_and_i68_H2rv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_and_i68_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i,L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_and_i68_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_and_i68_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i68_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_and_i68_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_and_i68_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_and_i68_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn33_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_and_i68_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_and_i68_V6result[L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i]=L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y6op_and_i68_H2lv[L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_and_i68_H2rv[L4ieee_Q14std_logic_1164_Y6op_and_i68_L451ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_and_i68_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn34_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,97,110,100,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"and" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_and_i71(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_and_i71_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y6op_and_i71_H2lv,L4ieee_Q14std_logic_1164_Y6op_and_i71_H2rv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_and_i71_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i,L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_and_i71_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_and_i71_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i71_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_and_i71_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_and_i71_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_and_i71_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn34_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_and_i71_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_and_i71_V6result[L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i]=L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y6op_and_i71_H2lv[L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_and_i71_H2rv[L4ieee_Q14std_logic_1164_Y6op_and_i71_L459ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_and_i71_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn35_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,110,97,110,100,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i74(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2lv,L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2rv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i74_V6result;
    integer L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i,L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l.data);
    L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1r.data);
    L4ieee_Q14std_logic_1164_Y7op_nand_i74_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l.info->length!=L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+65,0),L4ieee_W14std_logic_1164_itn35_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i=1,L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7op_nand_i74_C1l.info->length); L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i++,L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y7op_nand_i74_V6result[L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2lv[L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i]][L4ieee_Q14std_logic_1164_Y7op_nand_i74_H2rv[L4ieee_Q14std_logic_1164_Y7op_nand_i74_L467ln_C1i]]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y7op_nand_i74_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn36_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,110,97,110,100,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"nand" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i77(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2lv,L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2rv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7op_nand_i77_V6result;
    integer L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i,L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l.data);
    L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1r.data);
    L4ieee_Q14std_logic_1164_Y7op_nand_i77_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l.info->length!=L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+65,0),L4ieee_W14std_logic_1164_itn36_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i=1,L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7op_nand_i77_C1l.info->length); L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i++,L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y7op_nand_i77_V6result[L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C9and_table[L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2lv[L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i]][L4ieee_Q14std_logic_1164_Y7op_nand_i77_H2rv[L4ieee_Q14std_logic_1164_Y7op_nand_i77_L475ln_C1i]]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y7op_nand_i77_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn37_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y5op_or_i80(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y5op_or_i80_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y5op_or_i80_H2lv,L4ieee_Q14std_logic_1164_Y5op_or_i80_H2rv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y5op_or_i80_V6result;
    integer L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i,L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y5op_or_i80_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l.data);
    L4ieee_Q14std_logic_1164_Y5op_or_i80_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i80_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y5op_or_i80_C1r.data);
    L4ieee_Q14std_logic_1164_Y5op_or_i80_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l.info->length!=L4ieee_Q14std_logic_1164_Y5op_or_i80_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+63,0),L4ieee_W14std_logic_1164_itn37_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i=1,L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y5op_or_i80_C1l.info->length); L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i++,L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y5op_or_i80_V6result[L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i]=L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y5op_or_i80_H2lv[L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i]][L4ieee_Q14std_logic_1164_Y5op_or_i80_H2rv[L4ieee_Q14std_logic_1164_Y5op_or_i80_L483ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y5op_or_i80_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn38_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"or" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y5op_or_i83(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y5op_or_i83_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y5op_or_i83_H2lv,L4ieee_Q14std_logic_1164_Y5op_or_i83_H2rv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y5op_or_i83_V6result;
    integer L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i,L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y5op_or_i83_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l.data);
    L4ieee_Q14std_logic_1164_Y5op_or_i83_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i83_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y5op_or_i83_C1r.data);
    L4ieee_Q14std_logic_1164_Y5op_or_i83_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l.info->length!=L4ieee_Q14std_logic_1164_Y5op_or_i83_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+63,0),L4ieee_W14std_logic_1164_itn38_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i=1,L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y5op_or_i83_C1l.info->length); L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i++,L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y5op_or_i83_V6result[L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i]=L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y5op_or_i83_H2lv[L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i]][L4ieee_Q14std_logic_1164_Y5op_or_i83_H2rv[L4ieee_Q14std_logic_1164_Y5op_or_i83_L491ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y5op_or_i83_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn39_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,110,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i86(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2lv,L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2rv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i86_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i,L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_nor_i86_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn39_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_nor_i86_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_nor_i86_V6result[L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2lv[L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_nor_i86_H2rv[L4ieee_Q14std_logic_1164_Y6op_nor_i86_L499ln_C1i]]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_nor_i86_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn40_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,110,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"nor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i89(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2lv,L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2rv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_nor_i89_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i,L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_nor_i89_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn40_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_nor_i89_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_nor_i89_V6result[L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_W14std_logic_1164_C8or_table[L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2lv[L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_nor_i89_H2rv[L4ieee_Q14std_logic_1164_Y6op_nor_i89_L5107ln_C1i]]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_nor_i89_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn41_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,120,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i92(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l,const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2lv,L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2rv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i92_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i,L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_xor_i92_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn41_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_xor_i92_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_xor_i92_V6result[L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i]=L4ieee_W14std_logic_1164_C9xor_table[L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2lv[L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_xor_i92_H2rv[L4ieee_Q14std_logic_1164_Y6op_xor_i92_L5115ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_xor_i92_V6result);
}
enumeration L4ieee_W14std_logic_1164_itn42_lit[]={97,114,103,117,109,101,110,116,115,32,111,102,32,111,118,101,114,108,111,97,100,101,100,32,39,120,111,114,39,32,111,112,101,114,97,116,111,114,32,97,114,101,32,110,111,116,32,111,102,32,116,104,101,32,115,97,109,101,32,108,101,110,103,116,104};
/* Implementation of subprogram :ieee:std_logic_1164:"xor" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i95(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l,const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1r)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2lv,L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2rv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_xor_i95_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i,L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2rv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1r.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1r.data);
    L4ieee_Q14std_logic_1164_Y6op_xor_i95_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l.info->length,0)),enumeration(0));
    if((L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l.info->length!=L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1r.info->length)) {
      if(!enumeration(0))
        report(array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+64,0),L4ieee_W14std_logic_1164_itn42_lit),enumeration(3));
    } else {
      for (L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_xor_i95_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i_lc--) {
        L4ieee_Q14std_logic_1164_Y6op_xor_i95_V6result[L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i]=L4ieee_W14std_logic_1164_C9xor_table[L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2lv[L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i]][L4ieee_Q14std_logic_1164_Y6op_xor_i95_H2rv[L4ieee_Q14std_logic_1164_Y6op_xor_i95_L5123ln_C1i]];
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_xor_i95_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_not_i97(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y6op_not_i97_H2lv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6op_not_i97_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i,L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_not_i97_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_not_i97_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length,0)),enumeration(0));
    L4ieee_Q14std_logic_1164_Y6op_not_i97_V6result=L4ieee_Q14std_logic_1164_T16std_logic_vector(new array_info((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length,0))->element_type,(new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length,0))->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length,0),enumeration(1));
    for (L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_not_i97_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y6op_not_i97_V6result[L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_Q14std_logic_1164_Y6op_not_i97_H2lv[L4ieee_Q14std_logic_1164_Y6op_not_i97_L5129ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_not_i97_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:"not" */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_not_i99(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y6op_not_i99_H2lv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6op_not_i99_V6result;
    integer L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i,L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6op_not_i99_H2lv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length,0)), L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.data);
    L4ieee_Q14std_logic_1164_Y6op_not_i99_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length,0)),enumeration(0));
    L4ieee_Q14std_logic_1164_Y6op_not_i99_V6result=L4ieee_Q14std_logic_1164_T17std_ulogic_vector(new array_info((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length,0))->element_type,(new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length,0))->index_type,1,to,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length,0),enumeration(1));
    for (L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i=1,L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6op_not_i99_C1l.info->length); L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i++,L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y6op_not_i99_V6result[L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i]=L4ieee_W14std_logic_1164_C9not_table[L4ieee_Q14std_logic_1164_Y6op_not_i99_H2lv[L4ieee_Q14std_logic_1164_Y6op_not_i99_L5135ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6op_not_i99_V6result);
}
L4ieee_W14std_logic_1164_I15logic_x01_table L4ieee_W14std_logic_1164_I15logic_x01_table_INFO;
L4ieee_W14std_logic_1164_I16logic_x01z_table L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO;
L4ieee_W14std_logic_1164_I16logic_ux01_table L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO;
/* Implementation of subprogram :ieee:std_logic_1164:to_bit */
enumeration L4ieee_Q14std_logic_1164_Y6to_bit_i102(const enumeration L4ieee_Q14std_logic_1164_Y6to_bit_i102_C1s,const enumeration L4ieee_Q14std_logic_1164_Y6to_bit_i102_C4xmap)
{
    switch(L4ieee_Q14std_logic_1164_Y6to_bit_i102_C1s) {
    case 2: case 6: {
      return enumeration(0);
     } break;
    case 3: case 7: {
      return enumeration(1);
     } break;
    default: {
      return L4ieee_Q14std_logic_1164_Y6to_bit_i102_C4xmap;
     } break;
    }
}
/* Implementation of subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i105(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s,const enumeration L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C4xmap)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_H2sv;
    L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result;
    integer L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i,L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s.data);
    L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result.init((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i=(L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s.info->length-1),L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C1s.info->length-1),0); L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i--,L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_H2sv[L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i]) {
      case 2: case 6: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i]=enumeration(0);
       } break;
      case 3: case 7: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i]=enumeration(1);
       } break;
      default: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_L5181ln_C1i]=L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_C4xmap;
       } break;
      }
    }
    return array_alias<L3std_Q8standard_T10bit_vector >((&L3std_Q8standard_I10bit_vector_INFO),L4ieee_Q14std_logic_1164_Y12to_bitvector_i105_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_bitvector */
L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i108(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s,const enumeration L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C4xmap)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_H2sv;
    L3std_Q8standard_T10bit_vector L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result;
    integer L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i,L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s.data);
    L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result.init((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i=(L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s.info->length-1),L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C1s.info->length-1),0); L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i--,L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_H2sv[L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i]) {
      case 2: case 6: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i]=enumeration(0);
       } break;
      case 3: case 7: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i]=enumeration(1);
       } break;
      default: {
        L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result[L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_L5188ln_C1i]=L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_C4xmap;
       } break;
      }
    }
    return array_alias<L3std_Q8standard_T10bit_vector >((&L3std_Q8standard_I10bit_vector_INFO),L4ieee_Q14std_logic_1164_Y12to_bitvector_i108_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_stdulogic */
enumeration L4ieee_Q14std_logic_1164_Y12to_stdulogic_i110(const enumeration L4ieee_Q14std_logic_1164_Y12to_stdulogic_i110_C1b)
{
    switch(L4ieee_Q14std_logic_1164_Y12to_stdulogic_i110_C1b) {
    case 0: {
      return enumeration(2);
     } break;
    case 1: {
      return enumeration(3);
     } break;
    }
}
/* Implementation of subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_H2bv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_V6result;
    integer L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i,L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b.data);
    L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i=(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b.info->length-1),L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_C1b.info->length-1),0); L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i--,L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_H2bv[L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_V6result[L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_V6result[L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_L5196ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i112_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_stdlogicvector */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_H2sv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_V6result;
    integer L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i,L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s.data);
    L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i=(L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s.info->length-1),L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_C1s.info->length-1),0); L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i--,L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_V6result[L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i]=L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_H2sv[L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_L5202ln_C1i];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y17to_stdlogicvector_i114_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_H2bv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_V6result;
    integer L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i,L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b.data);
    L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i=(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b.info->length-1),L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_C1b.info->length-1),0); L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i--,L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_H2bv[L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_V6result[L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_V6result[L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_L5208ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i116_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_stdulogicvector */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_H2sv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_V6result;
    integer L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i,L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s.info->length-1),downto,0,0)), L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s.data);
    L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s.info->length-1),downto,0,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i=(L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s.info->length-1),L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i_lc=down_range_to_length<integer>((L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_C1s.info->length-1),0); L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i--,L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_V6result[L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i]=L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_H2sv[L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_L5214ln_C1i];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y18to_stdulogicvector_i118_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i120(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y6to_x01_i120_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y6to_x01_i120_H2sv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i120_V6result;
    integer L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i,L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6to_x01_i120_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i120_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y6to_x01_i120_C1s.data);
    L4ieee_Q14std_logic_1164_Y6to_x01_i120_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i120_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i=1,L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6to_x01_i120_C1s.info->length); L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i++,L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y6to_x01_i120_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i]=L4ieee_W14std_logic_1164_C10cvt_to_x01[L4ieee_Q14std_logic_1164_Y6to_x01_i120_H2sv[L4ieee_Q14std_logic_1164_Y6to_x01_i120_L5220ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6to_x01_i120_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i122(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y6to_x01_i122_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y6to_x01_i122_H2sv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i122_V6result;
    integer L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i,L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6to_x01_i122_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i122_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y6to_x01_i122_C1s.data);
    L4ieee_Q14std_logic_1164_Y6to_x01_i122_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i122_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i=1,L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6to_x01_i122_C1s.info->length); L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i++,L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y6to_x01_i122_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i]=L4ieee_W14std_logic_1164_C10cvt_to_x01[L4ieee_Q14std_logic_1164_Y6to_x01_i122_H2sv[L4ieee_Q14std_logic_1164_Y6to_x01_i122_L5226ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6to_x01_i122_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i124(const enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i124_C1s)
{
    return L4ieee_W14std_logic_1164_C10cvt_to_x01[L4ieee_Q14std_logic_1164_Y6to_x01_i124_C1s];
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i126(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y6to_x01_i126_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y6to_x01_i126_H2bv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i126_V6result;
    integer L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i,L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6to_x01_i126_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i126_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y6to_x01_i126_C1b.data);
    L4ieee_Q14std_logic_1164_Y6to_x01_i126_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i126_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i=1,L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6to_x01_i126_C1b.info->length); L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i++,L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y6to_x01_i126_H2bv[L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y6to_x01_i126_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y6to_x01_i126_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i126_L5234ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y6to_x01_i126_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i128(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y6to_x01_i128_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y6to_x01_i128_H2bv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y6to_x01_i128_V6result;
    integer L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i,L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y6to_x01_i128_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i128_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y6to_x01_i128_C1b.data);
    L4ieee_Q14std_logic_1164_Y6to_x01_i128_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y6to_x01_i128_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i=1,L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y6to_x01_i128_C1b.info->length); L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i++,L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y6to_x01_i128_H2bv[L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y6to_x01_i128_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y6to_x01_i128_V6result[L4ieee_Q14std_logic_1164_Y6to_x01_i128_L5240ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y6to_x01_i128_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i130(const enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i130_C1b)
{
    switch(L4ieee_Q14std_logic_1164_Y6to_x01_i130_C1b) {
    case 0: {
      return enumeration(2);
     } break;
    case 1: {
      return enumeration(3);
     } break;
    }
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i132(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y7to_x01z_i132_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y7to_x01z_i132_H2sv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i132_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_x01z_i132_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_x01z_i132_C1s.data);
    L4ieee_Q14std_logic_1164_Y7to_x01z_i132_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_C1s.info->length); L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y7to_x01z_i132_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i]=L4ieee_W14std_logic_1164_C11cvt_to_x01z[L4ieee_Q14std_logic_1164_Y7to_x01z_i132_H2sv[L4ieee_Q14std_logic_1164_Y7to_x01z_i132_L5248ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_x01z_i132_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i134(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y7to_x01z_i134_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y7to_x01z_i134_H2sv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i134_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_x01z_i134_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_x01z_i134_C1s.data);
    L4ieee_Q14std_logic_1164_Y7to_x01z_i134_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_C1s.info->length); L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y7to_x01z_i134_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i]=L4ieee_W14std_logic_1164_C11cvt_to_x01z[L4ieee_Q14std_logic_1164_Y7to_x01z_i134_H2sv[L4ieee_Q14std_logic_1164_Y7to_x01z_i134_L5254ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_x01z_i134_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i136(const enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i136_C1s)
{
    return L4ieee_W14std_logic_1164_C11cvt_to_x01z[L4ieee_Q14std_logic_1164_Y7to_x01z_i136_C1s];
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i138(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y7to_x01z_i138_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y7to_x01z_i138_H2bv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i138_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_x01z_i138_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_x01z_i138_C1b.data);
    L4ieee_Q14std_logic_1164_Y7to_x01z_i138_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_C1b.info->length); L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y7to_x01z_i138_H2bv[L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y7to_x01z_i138_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y7to_x01z_i138_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i138_L5262ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_x01z_i138_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i140(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y7to_x01z_i140_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y7to_x01z_i140_H2bv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_x01z_i140_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_x01z_i140_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_x01z_i140_C1b.data);
    L4ieee_Q14std_logic_1164_Y7to_x01z_i140_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_C1b.info->length); L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y7to_x01z_i140_H2bv[L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y7to_x01z_i140_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y7to_x01z_i140_V6result[L4ieee_Q14std_logic_1164_Y7to_x01z_i140_L5268ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_x01z_i140_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i142(const enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i142_C1b)
{
    switch(L4ieee_Q14std_logic_1164_Y7to_x01z_i142_C1b) {
    case 0: {
      return enumeration(2);
     } break;
    case 1: {
      return enumeration(3);
     } break;
    }
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i144(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y7to_ux01_i144_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector > L4ieee_Q14std_logic_1164_Y7to_ux01_i144_H2sv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i144_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_ux01_i144_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_ux01_i144_C1s.data);
    L4ieee_Q14std_logic_1164_Y7to_ux01_i144_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_C1s.info->length); L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y7to_ux01_i144_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i]=L4ieee_W14std_logic_1164_C11cvt_to_ux01[L4ieee_Q14std_logic_1164_Y7to_ux01_i144_H2sv[L4ieee_Q14std_logic_1164_Y7to_ux01_i144_L5276ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_ux01_i144_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i146(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y7to_ux01_i146_C1s)
{
    array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector > L4ieee_Q14std_logic_1164_Y7to_ux01_i146_H2sv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i146_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_ux01_i146_H2sv.set((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_C1s.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_ux01_i146_C1s.data);
    L4ieee_Q14std_logic_1164_Y7to_ux01_i146_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_C1s.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_C1s.info->length); L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i_lc--) {
      L4ieee_Q14std_logic_1164_Y7to_ux01_i146_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i]=L4ieee_W14std_logic_1164_C11cvt_to_ux01[L4ieee_Q14std_logic_1164_Y7to_ux01_i146_H2sv[L4ieee_Q14std_logic_1164_Y7to_ux01_i146_L5282ln_C1i]];
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_ux01_i146_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i148(const enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i148_C1s)
{
    return L4ieee_W14std_logic_1164_C11cvt_to_ux01[L4ieee_Q14std_logic_1164_Y7to_ux01_i148_C1s];
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i150(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y7to_ux01_i150_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y7to_ux01_i150_H2bv;
    L4ieee_Q14std_logic_1164_T16std_logic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i150_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_ux01_i150_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_ux01_i150_C1b.data);
    L4ieee_Q14std_logic_1164_Y7to_ux01_i150_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_C1b.info->length); L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y7to_ux01_i150_H2bv[L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y7to_ux01_i150_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y7to_ux01_i150_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i150_L5290ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T16std_logic_vector >((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_ux01_i150_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i152(const L3std_Q8standard_T10bit_vector &L4ieee_Q14std_logic_1164_Y7to_ux01_i152_C1b)
{
    array_alias<L3std_Q8standard_T10bit_vector > L4ieee_Q14std_logic_1164_Y7to_ux01_i152_H2bv;
    L4ieee_Q14std_logic_1164_T17std_ulogic_vector L4ieee_Q14std_logic_1164_Y7to_ux01_i152_V6result;
    integer L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i_lc;
    L4ieee_Q14std_logic_1164_Y7to_ux01_i152_H2bv.set((new array_info((&L3std_Q8standard_I10bit_vector_INFO)->element_type,(&L3std_Q8standard_I10bit_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_C1b.info->length,0)), L4ieee_Q14std_logic_1164_Y7to_ux01_i152_C1b.data);
    L4ieee_Q14std_logic_1164_Y7to_ux01_i152_V6result.init((new array_info((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO)->index_type,1,to,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_C1b.info->length,0)),enumeration(0));
    for (L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i=1,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i_lc=up_range_to_length<integer>(1,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_C1b.info->length); L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i++,L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y7to_ux01_i152_H2bv[L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i]) {
      case 0: {
        L4ieee_Q14std_logic_1164_Y7to_ux01_i152_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i]=enumeration(2);
       } break;
      case 1: {
        L4ieee_Q14std_logic_1164_Y7to_ux01_i152_V6result[L4ieee_Q14std_logic_1164_Y7to_ux01_i152_L5296ln_C1i]=enumeration(3);
       } break;
      }
    }
    return array_alias<L4ieee_Q14std_logic_1164_T17std_ulogic_vector >((&L4ieee_Q14std_logic_1164_I17std_ulogic_vector_INFO),L4ieee_Q14std_logic_1164_Y7to_ux01_i152_V6result);
}
/* Implementation of subprogram :ieee:std_logic_1164:to_ux01 */
enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i154(const enumeration L4ieee_Q14std_logic_1164_Y7to_ux01_i154_C1b)
{
    switch(L4ieee_Q14std_logic_1164_Y7to_ux01_i154_C1b) {
    case 0: {
      return enumeration(2);
     } break;
    case 1: {
      return enumeration(3);
     } break;
    }
}
/* Implementation of subprogram :ieee:std_logic_1164:rising_edge */
enumeration L4ieee_Q14std_logic_1164_Y11rising_edge_i156(sig_info<enumeration> *L4ieee_Q14std_logic_1164_Y11rising_edge_i156_S1s,enumeration *L4ieee_Q14std_logic_1164_Y11rising_edge_i156_R1s)
{
    return ((attr_scalar_EVENT(L4ieee_Q14std_logic_1164_Y11rising_edge_i156_S1s)&&(L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q14std_logic_1164_Y11rising_edge_i156_R1s))==enumeration(3)))&&(L4ieee_Q14std_logic_1164_Y6to_x01_i124 (attr_scalar_LAST_VALUE<enumeration>(L4ieee_Q14std_logic_1164_Y11rising_edge_i156_S1s))==enumeration(2)));
}
/* Implementation of subprogram :ieee:std_logic_1164:falling_edge */
enumeration L4ieee_Q14std_logic_1164_Y12falling_edge_i158(sig_info<enumeration> *L4ieee_Q14std_logic_1164_Y12falling_edge_i158_S1s,enumeration *L4ieee_Q14std_logic_1164_Y12falling_edge_i158_R1s)
{
    return ((attr_scalar_EVENT(L4ieee_Q14std_logic_1164_Y12falling_edge_i158_S1s)&&(L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q14std_logic_1164_Y12falling_edge_i158_R1s))==enumeration(2)))&&(L4ieee_Q14std_logic_1164_Y6to_x01_i124 (attr_scalar_LAST_VALUE<enumeration>(L4ieee_Q14std_logic_1164_Y12falling_edge_i158_S1s))==enumeration(3)));
}
/* Implementation of subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i160(const L4ieee_Q14std_logic_1164_T17std_ulogic_vector &L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s)
{
    integer L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i,L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_lc,L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_ls;
    for (L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i=L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_ls=L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s.info->index_direction==to?+1:-1,L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_lc=range_to_length<integer>(L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s.info->index_direction,L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s.info->right_bound);L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i+=L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_ls,L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y4is_x_i160_C1s[L4ieee_Q14std_logic_1164_Y4is_x_i160_L5306ln_C1i]) {
      case 0: case 1: case 4: case 5: case 8: {
        return enumeration(1);
       } break;
      default: {
/* NullStat impl */;
       } break;
      }
    }
    return enumeration(0);
}
/* Implementation of subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i162(const L4ieee_Q14std_logic_1164_T16std_logic_vector &L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s)
{
    integer L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i,L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_lc,L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_ls;
    for (L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i=L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_ls=L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s.info->index_direction==to?+1:-1,L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_lc=range_to_length<integer>(L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s.info->left_bound,L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s.info->index_direction,L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s.info->right_bound);L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_lc!=0; L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i+=L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_ls,L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i_lc--) {
      switch(L4ieee_Q14std_logic_1164_Y4is_x_i162_C1s[L4ieee_Q14std_logic_1164_Y4is_x_i162_L5310ln_C1i]) {
      case 0: case 1: case 4: case 5: case 8: {
        return enumeration(1);
       } break;
      default: {
/* NullStat impl */;
       } break;
      }
    }
    return enumeration(0);
}
/* Implementation of subprogram :ieee:std_logic_1164:is_x */
enumeration L4ieee_Q14std_logic_1164_Y4is_x_i164(const enumeration L4ieee_Q14std_logic_1164_Y4is_x_i164_C1s)
{
    switch(L4ieee_Q14std_logic_1164_Y4is_x_i164_C1s) {
    case 0: case 1: case 4: case 5: case 8: {
      return enumeration(1);
     } break;
    default: {
/* NullStat impl */;
     } break;
    }
    return enumeration(0);
}
/* Initialization function for package body :ieee:std_logic_1164 */
int L4ieee_Q14std_logic_1164_init ();
int L3std_Q8standard_init ();
bool L4ieee_W14std_logic_1164_init_done = false;
int L4ieee_W14std_logic_1164_init(){
if (L4ieee_W14std_logic_1164_init_done) return 1;
L4ieee_W14std_logic_1164_init_done=true;
L4ieee_Q14std_logic_1164_init ();
L3std_Q8standard_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/std_logic_1164.vhdl","std_logic_1164.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":std_logic_1164");
L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:stdlogic_1d",":stdlogic_1d",NULL);
L4ieee_W14std_logic_1164_I14stdlogic_table_INFO.set((new array_info((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1)),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:stdlogic_table",":stdlogic_table",NULL);
L4ieee_W14std_logic_1164_I15logic_x01_table_INFO.set((&L4ieee_Q14std_logic_1164_I3x01_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:logic_x01_table",":logic_x01_table",NULL);
L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO.set((&L4ieee_Q14std_logic_1164_I4x01z_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:logic_x01z_table",":logic_x01z_table",NULL);
L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO.set((&L4ieee_Q14std_logic_1164_I4ux01_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:std_logic_1164",":ieee:std_logic_1164:logic_ux01_table",":logic_ux01_table",NULL);
L4ieee_W14std_logic_1164_C16resolution_table.init((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO));
L4ieee_W14std_logic_1164_C16resolution_table=L4ieee_W14std_logic_1164_T14stdlogic_table(new array_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(0)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(0)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(0))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(2)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(2)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(3)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(3)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(4)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(5)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(6)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(7)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(5)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(5)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(5)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(5)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(6)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(5)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(6)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(5)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(7)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(5)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(5)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(7)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1)));
L4ieee_W14std_logic_1164_C9and_table.init((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO));
L4ieee_W14std_logic_1164_C9and_table=L4ieee_W14std_logic_1164_T14stdlogic_table(new array_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(0))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(2)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(2)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(2)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(2)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(2))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(2)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(2)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(2)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(2)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(2))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1)));
L4ieee_W14std_logic_1164_C8or_table.init((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO));
L4ieee_W14std_logic_1164_C8or_table=L4ieee_W14std_logic_1164_T14stdlogic_table(new array_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(0)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(0)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(0))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(3)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(3)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(3)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(3)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(3)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(3)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(3)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(3)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(3))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1)));
L4ieee_W14std_logic_1164_C9xor_table.init((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO));
L4ieee_W14std_logic_1164_C9xor_table=L4ieee_W14std_logic_1164_T14stdlogic_table(new array_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(0)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(0)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(0)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(0)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(0)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(0)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(0)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(0))).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1))).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,L4ieee_W14std_logic_1164_T14stdlogic_table::E_type(new array_info(parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->element_type,parray_info((&L4ieee_W14std_logic_1164_I14stdlogic_table_INFO)->element_type)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(1)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(1)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(1)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(1)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1)));
L4ieee_W14std_logic_1164_C9not_table.init((&L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO),enumeration(0));
L4ieee_W14std_logic_1164_C9not_table=L4ieee_W14std_logic_1164_T11stdlogic_1d(new array_info((&L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO)->element_type,(&L4ieee_W14std_logic_1164_I11stdlogic_1d_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(3)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(2)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(3)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(2)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
L4ieee_W14std_logic_1164_C10cvt_to_x01.init((&L4ieee_W14std_logic_1164_I15logic_x01_table_INFO),enumeration(1));
L4ieee_W14std_logic_1164_C10cvt_to_x01=L4ieee_W14std_logic_1164_T15logic_x01_table(new array_info((&L4ieee_W14std_logic_1164_I15logic_x01_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I15logic_x01_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(1)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
L4ieee_W14std_logic_1164_C11cvt_to_x01z.init((&L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO),enumeration(1));
L4ieee_W14std_logic_1164_C11cvt_to_x01z=L4ieee_W14std_logic_1164_T16logic_x01z_table(new array_info((&L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I16logic_x01z_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(1)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(4)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
L4ieee_W14std_logic_1164_C11cvt_to_ux01.init((&L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO),enumeration(0));
L4ieee_W14std_logic_1164_C11cvt_to_ux01=L4ieee_W14std_logic_1164_T16logic_ux01_table(new array_info((&L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO)->element_type,(&L4ieee_W14std_logic_1164_I16logic_ux01_table_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(1)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(1)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(2)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(3)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(1));
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W14std_logic_1164_hinfo =
  add_handle("ieee","std_logic_1164",NULL,NULL,&L4ieee_W14std_logic_1164_init);

/* end of package body :ieee:std_logic_1164 */
