#include <freehdl/kernel.h>
#include <freehdl/std.h>



/* package :ieee:vital_timing */
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
/** Enumeration info class :IEEE:std_logic_1164:x01 */
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
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/** Enumeration info class :IEEE:std_logic_1164:ux01z */
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
extern array_info L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO;
#define L4ieee_Q14std_logic_1164_T16std_logic_vector array_type<enumeration >
#define L4ieee_Q14std_logic_1164_I16std_logic_vector array_info

/* End of external declarations */
/* Definitions for enumeration type :ieee:vital_timing:vitaltransitiontype */
class L4ieee_Q12vital_timing_I19vitaltransitiontype:public enum_info_base{
   static const char *values[];
public:
   L4ieee_Q12vital_timing_I19vitaltransitiontype():enum_info_base(0,11,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 11; }
   static int left() { return 0; }
   static int right() { return 11; }
};
extern L4ieee_Q12vital_timing_I19vitaltransitiontype L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO;
#define L4ieee_Q12vital_timing_I14vitaldelaytype L3std_Q8standard_I4time
extern L4ieee_Q12vital_timing_I14vitaldelaytype L4ieee_Q12vital_timing_I14vitaldelaytype_INFO;
extern array_info L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO;
#define L4ieee_Q12vital_timing_T16vitaldelaytype01 array_type<physical >
#define L4ieee_Q12vital_timing_I16vitaldelaytype01 array_info

extern array_info L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO;
#define L4ieee_Q12vital_timing_T17vitaldelaytype01z array_type<physical >
#define L4ieee_Q12vital_timing_I17vitaldelaytype01z array_info

extern array_info L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO;
#define L4ieee_Q12vital_timing_T18vitaldelaytype01zx array_type<physical >
#define L4ieee_Q12vital_timing_I18vitaldelaytype01zx array_info

extern array_info L4ieee_Q12vital_timing_I19vitaldelayarraytype_INFO;
#define L4ieee_Q12vital_timing_T19vitaldelayarraytype array_type<physical >
#define L4ieee_Q12vital_timing_I19vitaldelayarraytype array_info

extern array_info L4ieee_Q12vital_timing_I21vitaldelayarraytype01_INFO;
#define L4ieee_Q12vital_timing_T21vitaldelayarraytype01 array_type<L4ieee_Q12vital_timing_T16vitaldelaytype01 >
#define L4ieee_Q12vital_timing_I21vitaldelayarraytype01 array_info

extern array_info L4ieee_Q12vital_timing_I22vitaldelayarraytype01z_INFO;
#define L4ieee_Q12vital_timing_T22vitaldelayarraytype01z array_type<L4ieee_Q12vital_timing_T17vitaldelaytype01z >
#define L4ieee_Q12vital_timing_I22vitaldelayarraytype01z array_info

extern array_info L4ieee_Q12vital_timing_I23vitaldelayarraytype01zx_INFO;
#define L4ieee_Q12vital_timing_T23vitaldelayarraytype01zx array_type<L4ieee_Q12vital_timing_T18vitaldelaytype01zx >
#define L4ieee_Q12vital_timing_I23vitaldelayarraytype01zx array_info

extern array_info L4ieee_Q12vital_timing_I17std_logic_vector2_INFO;
#define L4ieee_Q12vital_timing_T17std_logic_vector2 array_type<enumeration >
#define L4ieee_Q12vital_timing_I17std_logic_vector2 array_info

extern array_info L4ieee_Q12vital_timing_I17std_logic_vector3_INFO;
#define L4ieee_Q12vital_timing_T17std_logic_vector3 array_type<enumeration >
#define L4ieee_Q12vital_timing_I17std_logic_vector3 array_info

extern array_info L4ieee_Q12vital_timing_I17std_logic_vector4_INFO;
#define L4ieee_Q12vital_timing_T17std_logic_vector4 array_type<enumeration >
#define L4ieee_Q12vital_timing_I17std_logic_vector4 array_info

extern array_info L4ieee_Q12vital_timing_I17std_logic_vector8_INFO;
#define L4ieee_Q12vital_timing_T17std_logic_vector8 array_type<enumeration >
#define L4ieee_Q12vital_timing_I17std_logic_vector8 array_info

extern array_info L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO;
#define L4ieee_Q12vital_timing_T18vitaloutputmaptype array_type<enumeration >
#define L4ieee_Q12vital_timing_I18vitaloutputmaptype array_info

extern array_info L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO;
#define L4ieee_Q12vital_timing_T18vitalresultmaptype array_type<enumeration >
#define L4ieee_Q12vital_timing_I18vitalresultmaptype array_info

extern array_info L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO;
#define L4ieee_Q12vital_timing_T19vitalresultzmaptype array_type<enumeration >
#define L4ieee_Q12vital_timing_I19vitalresultzmaptype array_info

extern array_info L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO;
#define L4ieee_Q12vital_timing_T15vitaltimearrayt array_type<physical >
#define L4ieee_Q12vital_timing_I15vitaltimearrayt array_info

/* Definitions for access type :ieee:vital_timing:vitaltimearraypt */
#define L4ieee_Q12vital_timing_I16vitaltimearraypt access_info_base
extern access_info_base L4ieee_Q12vital_timing_I16vitaltimearraypt_INFO;
/* Prototype for predefined subprogram :ieee:vital_timing:deallocate */
#define L4ieee_Q12vital_timing_X10deallocate_i131(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)
extern array_info L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO;
#define L4ieee_Q12vital_timing_T15vitalboolarrayt array_type<enumeration >
#define L4ieee_Q12vital_timing_I15vitalboolarrayt array_info

/* Definitions for access type :ieee:vital_timing:vitalboolarraypt */
#define L4ieee_Q12vital_timing_I16vitalboolarraypt access_info_base
extern access_info_base L4ieee_Q12vital_timing_I16vitalboolarraypt_INFO;
/* Prototype for predefined subprogram :ieee:vital_timing:deallocate */
#define L4ieee_Q12vital_timing_X10deallocate_i159(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)
/* Definitions for access type :ieee:vital_timing:vitallogicarraypt */
#define L4ieee_Q12vital_timing_I17vitallogicarraypt access_info_base
extern access_info_base L4ieee_Q12vital_timing_I17vitallogicarraypt_INFO;
/* Prototype for predefined subprogram :ieee:vital_timing:deallocate */
#define L4ieee_Q12vital_timing_X10deallocate_i163(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)
/* Definitions for record type :ieee:vital_timing:vitaltimingdatatype */
#define L4ieee_Q12vital_timing_I19vitaltimingdatatype record_info
void *L4ieee_Q12vital_timing_T19vitaltimingdatatype_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA {
  enumeration M12notfirstflag;
  enumeration M7reflast;
  physical M7reftime;
  enumeration M6holden;
  enumeration M8testlast;
  physical M8testtime;
  enumeration M7setupen;
  vhdlaccess M9testlasta;
  vhdlaccess M9testtimea;
  vhdlaccess M7holdena;
  vhdlaccess M8setupena;
  L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA(enumeration M12notfirstflag, enumeration M7reflast, physical M7reftime, enumeration M6holden, enumeration M8testlast, physical M8testtime, enumeration M7setupen, vhdlaccess M9testlasta, vhdlaccess M9testtimea, vhdlaccess M7holdena, vhdlaccess M8setupena) : 
    M12notfirstflag(M12notfirstflag),
    M7reflast(M7reflast),
    M7reftime(M7reftime),
    M6holden(M6holden),
    M8testlast(M8testlast),
    M8testtime(M8testtime),
    M7setupen(M7setupen),
    M9testlasta(M9testlasta),
    M9testtimea(M9testtimea),
    M7holdena(M7holdena),
    M8setupena(M8setupena)
    { }
  L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M12notfirstflag=((enum_info_base*)einfos[0])->left_bound;
    M7reflast=((enum_info_base*)einfos[1])->left_bound;
    M7reftime=((physical_info_base*)einfos[2])->left_bound;
    M6holden=((enum_info_base*)einfos[3])->left_bound;
    M8testlast=((enum_info_base*)einfos[4])->left_bound;
    M8testtime=((physical_info_base*)einfos[5])->left_bound;
    M7setupen=((enum_info_base*)einfos[6])->left_bound;
    M9testlasta=NULL;
    M9testtimea=NULL;
    M7holdena=NULL;
    M8setupena=NULL;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA &src_data = *(L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA*)((const record_base *)p)->data;
    M12notfirstflag=src_data.M12notfirstflag;
    M7reflast=src_data.M7reflast;
    M7reftime=src_data.M7reftime;
    M6holden=src_data.M6holden;
    M8testlast=src_data.M8testlast;
    M8testtime=src_data.M8testtime;
    M7setupen=src_data.M7setupen;
    M9testlasta=src_data.M9testlasta;
    M9testtimea=src_data.M9testtimea;
    M7holdena=src_data.M7holdena;
    M8setupena=src_data.M8setupena;
  };
};
#define L4ieee_Q12vital_timing_T19vitaltimingdatatype record_type<L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA>
extern record_info L4ieee_Q12vital_timing_I19vitaltimingdatatype_INFO;
/* Prototype for subprogram :ieee:vital_timing:vitaltimingdatainit */
L4ieee_Q12vital_timing_T19vitaltimingdatatype L4ieee_Q12vital_timing_Y19vitaltimingdatainit_i167();
/* Definitions for record type :ieee:vital_timing:vitalperioddatatype */
#define L4ieee_Q12vital_timing_I19vitalperioddatatype record_info
void *L4ieee_Q12vital_timing_T19vitalperioddatatype_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA {
  enumeration M4last;
  physical M4rise;
  physical M4fall;
  enumeration M12notfirstflag;
  L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA(enumeration M4last, physical M4rise, physical M4fall, enumeration M12notfirstflag) : 
    M4last(M4last),
    M4rise(M4rise),
    M4fall(M4fall),
    M12notfirstflag(M12notfirstflag)
    { }
  L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M4last=((enum_info_base*)einfos[0])->left_bound;
    M4rise=((physical_info_base*)einfos[1])->left_bound;
    M4fall=((physical_info_base*)einfos[2])->left_bound;
    M12notfirstflag=((enum_info_base*)einfos[3])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA &src_data = *(L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA*)((const record_base *)p)->data;
    M4last=src_data.M4last;
    M4rise=src_data.M4rise;
    M4fall=src_data.M4fall;
    M12notfirstflag=src_data.M12notfirstflag;
  };
};
#define L4ieee_Q12vital_timing_T19vitalperioddatatype record_type<L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA>
extern record_info L4ieee_Q12vital_timing_I19vitalperioddatatype_INFO;
/* Definitions for enumeration type :ieee:vital_timing:vitalglitchkindtype */
class L4ieee_Q12vital_timing_I19vitalglitchkindtype:public enum_info_base{
   static const char *values[];
public:
   L4ieee_Q12vital_timing_I19vitalglitchkindtype():enum_info_base(0,3,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 3; }
   static int left() { return 0; }
   static int right() { return 3; }
};
extern L4ieee_Q12vital_timing_I19vitalglitchkindtype L4ieee_Q12vital_timing_I19vitalglitchkindtype_INFO;
/* Definitions for record type :ieee:vital_timing:vitalglitchdatatype */
#define L4ieee_Q12vital_timing_I19vitalglitchdatatype record_info
void *L4ieee_Q12vital_timing_T19vitalglitchdatatype_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA {
  physical M9schedtime;
  physical M10glitchtime;
  enumeration M10schedvalue;
  enumeration M9lastvalue;
  L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA(physical M9schedtime, physical M10glitchtime, enumeration M10schedvalue, enumeration M9lastvalue) : 
    M9schedtime(M9schedtime),
    M10glitchtime(M10glitchtime),
    M10schedvalue(M10schedvalue),
    M9lastvalue(M9lastvalue)
    { }
  L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M9schedtime=((physical_info_base*)einfos[0])->left_bound;
    M10glitchtime=((physical_info_base*)einfos[1])->left_bound;
    M10schedvalue=((enum_info_base*)einfos[2])->left_bound;
    M9lastvalue=((enum_info_base*)einfos[3])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA &src_data = *(L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA*)((const record_base *)p)->data;
    M9schedtime=src_data.M9schedtime;
    M10glitchtime=src_data.M10glitchtime;
    M10schedvalue=src_data.M10schedvalue;
    M9lastvalue=src_data.M9lastvalue;
  };
};
#define L4ieee_Q12vital_timing_T19vitalglitchdatatype record_type<L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA>
extern record_info L4ieee_Q12vital_timing_I19vitalglitchdatatype_INFO;
extern array_info L4ieee_Q12vital_timing_I24vitalglitchdataarraytype_INFO;
#define L4ieee_Q12vital_timing_T24vitalglitchdataarraytype array_type<L4ieee_Q12vital_timing_T19vitalglitchdatatype >
#define L4ieee_Q12vital_timing_I24vitalglitchdataarraytype array_info

/* Definitions for record type :ieee:vital_timing:vitalpathtype */
#define L4ieee_Q12vital_timing_I13vitalpathtype record_info
void *L4ieee_Q12vital_timing_T13vitalpathtype_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T13vitalpathtype_DATA {
  physical M15inputchangetime;
  physical M9pathdelay;
  enumeration M13pathcondition;
  L4ieee_Q12vital_timing_T13vitalpathtype_DATA(physical M15inputchangetime, physical M9pathdelay, enumeration M13pathcondition) : 
    M15inputchangetime(M15inputchangetime),
    M9pathdelay(M9pathdelay),
    M13pathcondition(M13pathcondition)
    { }
  L4ieee_Q12vital_timing_T13vitalpathtype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M15inputchangetime=((physical_info_base*)einfos[0])->left_bound;
    M9pathdelay=((physical_info_base*)einfos[1])->left_bound;
    M13pathcondition=((enum_info_base*)einfos[2])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T13vitalpathtype_DATA &src_data = *(L4ieee_Q12vital_timing_T13vitalpathtype_DATA*)((const record_base *)p)->data;
    M15inputchangetime=src_data.M15inputchangetime;
    M9pathdelay=src_data.M9pathdelay;
    M13pathcondition=src_data.M13pathcondition;
  };
};
#define L4ieee_Q12vital_timing_T13vitalpathtype record_type<L4ieee_Q12vital_timing_T13vitalpathtype_DATA>
extern record_info L4ieee_Q12vital_timing_I13vitalpathtype_INFO;
/* Definitions for record type :ieee:vital_timing:vitalpath01type */
#define L4ieee_Q12vital_timing_I15vitalpath01type record_info
void *L4ieee_Q12vital_timing_T15vitalpath01type_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T15vitalpath01type_DATA {
  physical M15inputchangetime;
  L4ieee_Q12vital_timing_T16vitaldelaytype01 M9pathdelay;
  enumeration M13pathcondition;
  L4ieee_Q12vital_timing_T15vitalpath01type_DATA(physical M15inputchangetime, L4ieee_Q12vital_timing_T16vitaldelaytype01 M9pathdelay, enumeration M13pathcondition) : 
    M15inputchangetime(M15inputchangetime),
    M9pathdelay(M9pathdelay),
    M13pathcondition(M13pathcondition)
    { }
  L4ieee_Q12vital_timing_T15vitalpath01type_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M15inputchangetime=((physical_info_base*)einfos[0])->left_bound;
    M9pathdelay.init(einfos[1]);
    M13pathcondition=((enum_info_base*)einfos[2])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T15vitalpath01type_DATA &src_data = *(L4ieee_Q12vital_timing_T15vitalpath01type_DATA*)((const record_base *)p)->data;
    M15inputchangetime=src_data.M15inputchangetime;
    M9pathdelay.init(einfos[1],(const void*)&src_data.M9pathdelay);
    M13pathcondition=src_data.M13pathcondition;
  };
};
#define L4ieee_Q12vital_timing_T15vitalpath01type record_type<L4ieee_Q12vital_timing_T15vitalpath01type_DATA>
extern record_info L4ieee_Q12vital_timing_I15vitalpath01type_INFO;
/* Definitions for record type :ieee:vital_timing:vitalpath01ztype */
#define L4ieee_Q12vital_timing_I16vitalpath01ztype record_info
void *L4ieee_Q12vital_timing_T16vitalpath01ztype_ELEM_ADDR(void*,int);
struct L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA {
  physical M15inputchangetime;
  L4ieee_Q12vital_timing_T17vitaldelaytype01z M9pathdelay;
  enumeration M13pathcondition;
  L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA(physical M15inputchangetime, L4ieee_Q12vital_timing_T17vitaldelaytype01z M9pathdelay, enumeration M13pathcondition) : 
    M15inputchangetime(M15inputchangetime),
    M9pathdelay(M9pathdelay),
    M13pathcondition(M13pathcondition)
    { }
  L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M15inputchangetime=((physical_info_base*)einfos[0])->left_bound;
    M9pathdelay.init(einfos[1]);
    M13pathcondition=((enum_info_base*)einfos[2])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA &src_data = *(L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA*)((const record_base *)p)->data;
    M15inputchangetime=src_data.M15inputchangetime;
    M9pathdelay.init(einfos[1],(const void*)&src_data.M9pathdelay);
    M13pathcondition=src_data.M13pathcondition;
  };
};
#define L4ieee_Q12vital_timing_T16vitalpath01ztype record_type<L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA>
extern record_info L4ieee_Q12vital_timing_I16vitalpath01ztype_INFO;
extern array_info L4ieee_Q12vital_timing_I18vitalpatharraytype_INFO;
#define L4ieee_Q12vital_timing_T18vitalpatharraytype array_type<L4ieee_Q12vital_timing_T13vitalpathtype >
#define L4ieee_Q12vital_timing_I18vitalpatharraytype array_info

extern array_info L4ieee_Q12vital_timing_I20vitalpatharray01type_INFO;
#define L4ieee_Q12vital_timing_T20vitalpatharray01type array_type<L4ieee_Q12vital_timing_T15vitalpath01type >
#define L4ieee_Q12vital_timing_I20vitalpatharray01type array_info

extern array_info L4ieee_Q12vital_timing_I21vitalpatharray01ztype_INFO;
#define L4ieee_Q12vital_timing_T21vitalpatharray01ztype array_type<L4ieee_Q12vital_timing_T16vitalpath01ztype >
#define L4ieee_Q12vital_timing_I21vitalpatharray01ztype array_info

/* Definitions for enumeration type :ieee:vital_timing:vitaltablesymboltype */
class L4ieee_Q12vital_timing_I20vitaltablesymboltype:public enum_info_base{
   static const char *values[];
public:
   L4ieee_Q12vital_timing_I20vitaltablesymboltype():enum_info_base(0,22,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 22; }
   static int left() { return 0; }
   static int right() { return 22; }
};
extern L4ieee_Q12vital_timing_I20vitaltablesymboltype L4ieee_Q12vital_timing_I20vitaltablesymboltype_INFO;
/** Enumeration info class :ieee:vital_timing:vitaledgesymboltype */
class L4ieee_Q12vital_timing_I19vitaledgesymboltype:public enum_info_base{
   static const char **values;
public:
   L4ieee_Q12vital_timing_I19vitaledgesymboltype():enum_info_base(0,15,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 15; }
   static int left() { return 0; }
   static int right() { return 15; }
};
extern L4ieee_Q12vital_timing_I19vitaledgesymboltype L4ieee_Q12vital_timing_I19vitaledgesymboltype_INFO;
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i255(const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257(const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259(const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263(const enumeration ,const enumeration ,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267(const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271(const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay */
void L4ieee_Q12vital_timing_X14vitalpathdelay_i282(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T18vitalpatharraytype &,const physical ,const enumeration ,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay01 */
void L4ieee_Q12vital_timing_X16vitalpathdelay01_i293(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T20vitalpatharray01type &,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &,const enumeration ,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay01z */
void L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T21vitalpatharray01ztype &,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &,const enumeration ,const enumeration ,const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T18vitaloutputmaptype &);
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i309(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i313(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i317(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalsignaldelay */
void L4ieee_Q12vital_timing_X16vitalsignaldelay_i321(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<L4ieee_Q14std_logic_1164_T16std_logic_vector> *,L4ieee_Q14std_logic_1164_T16std_logic_vector *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalrecoveryremovalcheck */
void L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalperiodpulsecheck */
void L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391(enumeration &,L4ieee_Q12vital_timing_T19vitalperioddatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
physical L4ieee_Q12vital_timing_C14vitalzerodelay;
L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_Q12vital_timing_C16vitalzerodelay01;
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_C17vitalzerodelay01z;
L4ieee_Q12vital_timing_T18vitaldelaytype01zx L4ieee_Q12vital_timing_C18vitalzerodelay01zx;
L4ieee_Q12vital_timing_T18vitaloutputmaptype L4ieee_Q12vital_timing_C21vitaldefaultoutputmap;
L4ieee_Q12vital_timing_T18vitalresultmaptype L4ieee_Q12vital_timing_C21vitaldefaultresultmap;
L4ieee_Q12vital_timing_T19vitalresultzmaptype L4ieee_Q12vital_timing_C22vitaldefaultresultzmap;
L4ieee_Q12vital_timing_T19vitalperioddatatype L4ieee_Q12vital_timing_C19vitalperioddatainit;
/* Implementation of enumeration type :ieee:vital_timing:vitaltransitiontype */
const char *L4ieee_Q12vital_timing_I19vitaltransitiontype::values[]={"tr01","tr10","tr0z","trz1","tr1z","trz0","tr0X","trx1","tr1x","trx0","trxz","trzx"};
L4ieee_Q12vital_timing_I19vitaltransitiontype L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO;
L4ieee_Q12vital_timing_I14vitaldelaytype L4ieee_Q12vital_timing_I14vitaldelaytype_INFO;
L4ieee_Q12vital_timing_I16vitaldelaytype01 L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO;
L4ieee_Q12vital_timing_I17vitaldelaytype01z L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO;
L4ieee_Q12vital_timing_I18vitaldelaytype01zx L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO;
L4ieee_Q12vital_timing_I19vitaldelayarraytype L4ieee_Q12vital_timing_I19vitaldelayarraytype_INFO;
L4ieee_Q12vital_timing_I21vitaldelayarraytype01 L4ieee_Q12vital_timing_I21vitaldelayarraytype01_INFO;
L4ieee_Q12vital_timing_I22vitaldelayarraytype01z L4ieee_Q12vital_timing_I22vitaldelayarraytype01z_INFO;
L4ieee_Q12vital_timing_I23vitaldelayarraytype01zx L4ieee_Q12vital_timing_I23vitaldelayarraytype01zx_INFO;
L4ieee_Q12vital_timing_I17std_logic_vector2 L4ieee_Q12vital_timing_I17std_logic_vector2_INFO;
L4ieee_Q12vital_timing_I17std_logic_vector3 L4ieee_Q12vital_timing_I17std_logic_vector3_INFO;
L4ieee_Q12vital_timing_I17std_logic_vector4 L4ieee_Q12vital_timing_I17std_logic_vector4_INFO;
L4ieee_Q12vital_timing_I17std_logic_vector8 L4ieee_Q12vital_timing_I17std_logic_vector8_INFO;
L4ieee_Q12vital_timing_I18vitaloutputmaptype L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO;
L4ieee_Q12vital_timing_I18vitalresultmaptype L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO;
L4ieee_Q12vital_timing_I19vitalresultzmaptype L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO;
enumeration L4ieee_Q12vital_timing_itn0_lit[]={0,1,2,3,4,5,6,7,8};
L4ieee_Q12vital_timing_I15vitaltimearrayt L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO;
L4ieee_Q12vital_timing_I16vitaltimearraypt L4ieee_Q12vital_timing_I16vitaltimearraypt_INFO;
L4ieee_Q12vital_timing_I15vitalboolarrayt L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO;
L4ieee_Q12vital_timing_I16vitalboolarraypt L4ieee_Q12vital_timing_I16vitalboolarraypt_INFO;
L4ieee_Q12vital_timing_I17vitallogicarraypt L4ieee_Q12vital_timing_I17vitallogicarraypt_INFO;
const char *L4ieee_Q12vital_timing_T19vitaltimingdatatype_NAMES[] = {
  "notfirstflag",
  "reflast",
  "reftime",
  "holden",
  "testlast",
  "testtime",
  "setupen",
  "testlasta",
  "testtimea",
  "holdena",
  "setupena"
};
void *L4ieee_Q12vital_timing_T19vitaltimingdatatype_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA &obj=*(L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M12notfirstflag;
  case 1: return (void*)&obj.M7reflast;
  case 2: return (void*)&obj.M7reftime;
  case 3: return (void*)&obj.M6holden;
  case 4: return (void*)&obj.M8testlast;
  case 5: return (void*)&obj.M8testtime;
  case 6: return (void*)&obj.M7setupen;
  case 7: return (void*)&obj.M9testlasta;
  case 8: return (void*)&obj.M9testtimea;
  case 9: return (void*)&obj.M7holdena;
  case 10: return (void*)&obj.M8setupena;
  };
};
L4ieee_Q12vital_timing_I19vitaltimingdatatype L4ieee_Q12vital_timing_I19vitaltimingdatatype_INFO;
const char *L4ieee_Q12vital_timing_T19vitalperioddatatype_NAMES[] = {
  "last",
  "rise",
  "fall",
  "notfirstflag"
};
void *L4ieee_Q12vital_timing_T19vitalperioddatatype_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA &obj=*(L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M4last;
  case 1: return (void*)&obj.M4rise;
  case 2: return (void*)&obj.M4fall;
  case 3: return (void*)&obj.M12notfirstflag;
  };
};
L4ieee_Q12vital_timing_I19vitalperioddatatype L4ieee_Q12vital_timing_I19vitalperioddatatype_INFO;
/* Implementation of enumeration type :ieee:vital_timing:vitalglitchkindtype */
const char *L4ieee_Q12vital_timing_I19vitalglitchkindtype::values[]={"OnEvent","OnDetect","VitalInertial","VitalTransport"};
L4ieee_Q12vital_timing_I19vitalglitchkindtype L4ieee_Q12vital_timing_I19vitalglitchkindtype_INFO;
const char *L4ieee_Q12vital_timing_T19vitalglitchdatatype_NAMES[] = {
  "schedtime",
  "glitchtime",
  "schedvalue",
  "lastvalue"
};
void *L4ieee_Q12vital_timing_T19vitalglitchdatatype_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA &obj=*(L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M9schedtime;
  case 1: return (void*)&obj.M10glitchtime;
  case 2: return (void*)&obj.M10schedvalue;
  case 3: return (void*)&obj.M9lastvalue;
  };
};
L4ieee_Q12vital_timing_I19vitalglitchdatatype L4ieee_Q12vital_timing_I19vitalglitchdatatype_INFO;
L4ieee_Q12vital_timing_I24vitalglitchdataarraytype L4ieee_Q12vital_timing_I24vitalglitchdataarraytype_INFO;
const char *L4ieee_Q12vital_timing_T13vitalpathtype_NAMES[] = {
  "inputchangetime",
  "pathdelay",
  "pathcondition"
};
void *L4ieee_Q12vital_timing_T13vitalpathtype_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T13vitalpathtype_DATA &obj=*(L4ieee_Q12vital_timing_T13vitalpathtype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M15inputchangetime;
  case 1: return (void*)&obj.M9pathdelay;
  case 2: return (void*)&obj.M13pathcondition;
  };
};
L4ieee_Q12vital_timing_I13vitalpathtype L4ieee_Q12vital_timing_I13vitalpathtype_INFO;
const char *L4ieee_Q12vital_timing_T15vitalpath01type_NAMES[] = {
  "inputchangetime",
  "pathdelay",
  "pathcondition"
};
void *L4ieee_Q12vital_timing_T15vitalpath01type_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T15vitalpath01type_DATA &obj=*(L4ieee_Q12vital_timing_T15vitalpath01type_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M15inputchangetime;
  case 1: return (void*)&obj.M9pathdelay;
  case 2: return (void*)&obj.M13pathcondition;
  };
};
L4ieee_Q12vital_timing_I15vitalpath01type L4ieee_Q12vital_timing_I15vitalpath01type_INFO;
const char *L4ieee_Q12vital_timing_T16vitalpath01ztype_NAMES[] = {
  "inputchangetime",
  "pathdelay",
  "pathcondition"
};
void *L4ieee_Q12vital_timing_T16vitalpath01ztype_ELEM_ADDR(void *p, int i)
{
  L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA &obj=*(L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M15inputchangetime;
  case 1: return (void*)&obj.M9pathdelay;
  case 2: return (void*)&obj.M13pathcondition;
  };
};
L4ieee_Q12vital_timing_I16vitalpath01ztype L4ieee_Q12vital_timing_I16vitalpath01ztype_INFO;
L4ieee_Q12vital_timing_I18vitalpatharraytype L4ieee_Q12vital_timing_I18vitalpatharraytype_INFO;
L4ieee_Q12vital_timing_I20vitalpatharray01type L4ieee_Q12vital_timing_I20vitalpatharray01type_INFO;
L4ieee_Q12vital_timing_I21vitalpatharray01ztype L4ieee_Q12vital_timing_I21vitalpatharray01ztype_INFO;
/* Implementation of enumeration type :ieee:vital_timing:vitaltablesymboltype */
const char *L4ieee_Q12vital_timing_I20vitaltablesymboltype::values[]={"'/'","'\'","'P'","'N'","'r'","'f'","'p'","'n'","'R'","'F'","'^'","'v'","'E'","'A'","'D'","'*'","'X'","'0'","'1'","'-'","'B'","'Z'","'S'"};
L4ieee_Q12vital_timing_I20vitaltablesymboltype L4ieee_Q12vital_timing_I20vitaltablesymboltype_INFO;
/* Implementation of enumeration type :ieee:vital_timing:vitaledgesymboltype */
const char **L4ieee_Q12vital_timing_I19vitaledgesymboltype::values=((enum_info_base&)L4ieee_Q12vital_timing_I19vitaledgesymboltype_INFO).values=&L4ieee_Q12vital_timing_I20vitaltablesymboltype_INFO.get_values()[enumeration(0)];
L4ieee_Q12vital_timing_I19vitaledgesymboltype L4ieee_Q12vital_timing_I19vitaledgesymboltype_INFO;
/* Initialization function for package :ieee:vital_timing */
int L3std_Q8standard_init ();
int L4ieee_Q14std_logic_1164_init ();
bool L4ieee_Q12vital_timing_init_done = false;
int L4ieee_Q12vital_timing_init(){
if (L4ieee_Q12vital_timing_init_done) return 1;
L4ieee_Q12vital_timing_init_done=true;
L3std_Q8standard_init ();
L4ieee_Q14std_logic_1164_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/vital_timing.vhdl","vital_timing.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package(":ieee",":vital_timing");
L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:vitaltransitiontype",":VitalTransitionType",NULL);
L4ieee_Q12vital_timing_I14vitaldelaytype_INFO.set((&L3std_Q8standard_I4time_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelaytype",":VitalDelayType",NULL);
L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO.set((&L3std_Q8standard_I4time_INFO),(&L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO),enumeration(0),to,enumeration(1),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelaytype01",":VitalDelayType01",NULL);
L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO.set((&L3std_Q8standard_I4time_INFO),(&L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO),enumeration(0),to,enumeration(5),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelaytype01z",":VitalDelayType01Z",NULL);
L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO.set((&L3std_Q8standard_I4time_INFO),(&L4ieee_Q12vital_timing_I19vitaltransitiontype_INFO),enumeration(0),to,enumeration(11),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelaytype01zx",":VitalDelayType01ZX",NULL);
L4ieee_Q12vital_timing_I19vitaldelayarraytype_INFO.set((&L4ieee_Q12vital_timing_I14vitaldelaytype_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelayarraytype",":VitalDelayArrayType",NULL);
L4ieee_Q12vital_timing_I21vitaldelayarraytype01_INFO.set((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelayarraytype01",":VitalDelayArrayType01",NULL);
L4ieee_Q12vital_timing_I22vitaldelayarraytype01z_INFO.set((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelayarraytype01z",":VitalDelayArrayType01Z",NULL);
L4ieee_Q12vital_timing_I23vitaldelayarraytype01zx_INFO.set((&L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaldelayarraytype01zx",":VitalDelayArrayType01ZX",NULL);
L4ieee_Q12vital_timing_I17std_logic_vector2_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),1,downto,0,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:std_logic_vector2",":std_logic_vector2",NULL);
L4ieee_Q12vital_timing_I17std_logic_vector3_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),2,downto,0,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:std_logic_vector3",":std_logic_vector3",NULL);
L4ieee_Q12vital_timing_I17std_logic_vector4_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),3,downto,0,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:std_logic_vector4",":std_logic_vector4",NULL);
L4ieee_Q12vital_timing_I17std_logic_vector8_INFO.set((&L4ieee_Q14std_logic_1164_I9std_logic_INFO),(&L3std_Q8standard_I7integer_INFO),7,downto,0,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:std_logic_vector8",":std_logic_vector8",NULL);
L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaloutputmaptype",":VitalOutputMapType",NULL);
L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(3),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalresultmaptype",":VitalResultMapType",NULL);
L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO.set((&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(4),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalresultzmaptype",":VitalResultZMapType",NULL);
L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO.set((&L3std_Q8standard_I4time_INFO),(&L3std_Q8standard_I7integer_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaltimearrayt",":VitalTimeArrayT",NULL);
L4ieee_Q12vital_timing_I16vitaltimearraypt_INFO.set((&L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaltimearraypt",":VitalTimeArrayPT",NULL);
L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO.set((&L3std_Q8standard_I7boolean_INFO),(&L3std_Q8standard_I7integer_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalboolarrayt",":VitalBoolArrayT",NULL);
L4ieee_Q12vital_timing_I16vitalboolarraypt_INFO.set((&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalboolarraypt",":VitalBoolArrayPT",NULL);
L4ieee_Q12vital_timing_I17vitallogicarraypt_INFO.set((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitallogicarraypt",":VitalLogicArrayPT",NULL);
L4ieee_Q12vital_timing_I19vitaltimingdatatype_INFO.set(11,sizeof(L4ieee_Q12vital_timing_T19vitaltimingdatatype_DATA),L4ieee_Q12vital_timing_T19vitaltimingdatatype_NAMES,L4ieee_Q12vital_timing_T19vitaltimingdatatype_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I7boolean_INFO)).set(1,(&L4ieee_Q14std_logic_1164_I3x01_INFO)).set(2,(&L3std_Q8standard_I4time_INFO)).set(3,(&L3std_Q8standard_I7boolean_INFO)).set(4,(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO)).set(5,(&L3std_Q8standard_I4time_INFO)).set(6,(&L3std_Q8standard_I7boolean_INFO)).set(7,(&L4ieee_Q12vital_timing_I17vitallogicarraypt_INFO)).set(8,(&L4ieee_Q12vital_timing_I16vitaltimearraypt_INFO)).set(9,(&L4ieee_Q12vital_timing_I16vitalboolarraypt_INFO)).set(10,(&L4ieee_Q12vital_timing_I16vitalboolarraypt_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitaltimingdatatype",":VitalTimingDataType",NULL);
L4ieee_Q12vital_timing_I19vitalperioddatatype_INFO.set(4,sizeof(L4ieee_Q12vital_timing_T19vitalperioddatatype_DATA),L4ieee_Q12vital_timing_T19vitalperioddatatype_NAMES,L4ieee_Q12vital_timing_T19vitalperioddatatype_ELEM_ADDR,-1).set(0,(&L4ieee_Q14std_logic_1164_I3x01_INFO)).set(1,(&L3std_Q8standard_I4time_INFO)).set(2,(&L3std_Q8standard_I4time_INFO)).set(3,(&L3std_Q8standard_I7boolean_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalperioddatatype",":VitalPeriodDataType",NULL);
L4ieee_Q12vital_timing_I19vitalglitchkindtype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:vitalglitchkindtype",":VitalGlitchKindType",NULL);
L4ieee_Q12vital_timing_I19vitalglitchdatatype_INFO.set(4,sizeof(L4ieee_Q12vital_timing_T19vitalglitchdatatype_DATA),L4ieee_Q12vital_timing_T19vitalglitchdatatype_NAMES,L4ieee_Q12vital_timing_T19vitalglitchdatatype_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4time_INFO)).set(1,(&L3std_Q8standard_I4time_INFO)).set(2,(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO)).set(3,(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalglitchdatatype",":VitalGlitchDataType",NULL);
L4ieee_Q12vital_timing_I24vitalglitchdataarraytype_INFO.set((&L4ieee_Q12vital_timing_I19vitalglitchdatatype_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalglitchdataarraytype",":VitalGlitchDataArrayType",NULL);
L4ieee_Q12vital_timing_I13vitalpathtype_INFO.set(3,sizeof(L4ieee_Q12vital_timing_T13vitalpathtype_DATA),L4ieee_Q12vital_timing_T13vitalpathtype_NAMES,L4ieee_Q12vital_timing_T13vitalpathtype_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4time_INFO)).set(1,(&L4ieee_Q12vital_timing_I14vitaldelaytype_INFO)).set(2,(&L3std_Q8standard_I7boolean_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpathtype",":VitalPathType",NULL);
L4ieee_Q12vital_timing_I15vitalpath01type_INFO.set(3,sizeof(L4ieee_Q12vital_timing_T15vitalpath01type_DATA),L4ieee_Q12vital_timing_T15vitalpath01type_NAMES,L4ieee_Q12vital_timing_T15vitalpath01type_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4time_INFO)).set(1,(&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO)).set(2,(&L3std_Q8standard_I7boolean_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpath01type",":VitalPath01Type",NULL);
L4ieee_Q12vital_timing_I16vitalpath01ztype_INFO.set(3,sizeof(L4ieee_Q12vital_timing_T16vitalpath01ztype_DATA),L4ieee_Q12vital_timing_T16vitalpath01ztype_NAMES,L4ieee_Q12vital_timing_T16vitalpath01ztype_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I4time_INFO)).set(1,(&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO)).set(2,(&L3std_Q8standard_I7boolean_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpath01ztype",":VitalPath01ZType",NULL);
L4ieee_Q12vital_timing_I18vitalpatharraytype_INFO.set((&L4ieee_Q12vital_timing_I13vitalpathtype_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpatharraytype",":VitalPathArrayType",NULL);
L4ieee_Q12vital_timing_I20vitalpatharray01type_INFO.set((&L4ieee_Q12vital_timing_I15vitalpath01type_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpatharray01type",":VitalPathArray01Type",NULL);
L4ieee_Q12vital_timing_I21vitalpatharray01ztype_INFO.set((&L4ieee_Q12vital_timing_I16vitalpath01ztype_INFO),(&L3std_Q8standard_I7natural_INFO),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalpatharray01ztype",":VitalPathArray01ZType",NULL);
L4ieee_Q12vital_timing_I20vitaltablesymboltype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:vitaltablesymboltype",":VitalTableSymbolType",NULL);
L4ieee_Q12vital_timing_I19vitaledgesymboltype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:vitaledgesymboltype",":VitalEdgeSymbolType",NULL);
L4ieee_Q12vital_timing_C14vitalzerodelay=0LL;
L4ieee_Q12vital_timing_C16vitalzerodelay01.init((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),-9223372036854775807LL);
L4ieee_Q12vital_timing_C16vitalzerodelay01=L4ieee_Q12vital_timing_T16vitaldelaytype01(new array_info((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO)->element_type,(&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO)->index_type,enumeration(0),to,enumeration(0)+1,0),0LL).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,0LL);
L4ieee_Q12vital_timing_C17vitalzerodelay01z.init((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),-9223372036854775807LL);
L4ieee_Q12vital_timing_C17vitalzerodelay01z=L4ieee_Q12vital_timing_T17vitaldelaytype01z(new array_info((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO)->element_type,(&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO)->index_type,enumeration(0),to,enumeration(5),0),0LL);
L4ieee_Q12vital_timing_C18vitalzerodelay01zx.init((&L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO),-9223372036854775807LL);
L4ieee_Q12vital_timing_C18vitalzerodelay01zx=L4ieee_Q12vital_timing_T18vitaldelaytype01zx(new array_info((&L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO)->element_type,(&L4ieee_Q12vital_timing_I18vitaldelaytype01zx_INFO)->index_type,enumeration(0),to,enumeration(11),0),0LL);
L4ieee_Q12vital_timing_C21vitaldefaultoutputmap.init((&L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO),enumeration(0));
L4ieee_Q12vital_timing_C21vitaldefaultoutputmap=array_alias<L4ieee_Q12vital_timing_T18vitaloutputmaptype >(new array_info((&L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO)->element_type,(&L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO)->index_type,enumeration(0),to,enumeration(8),0),L4ieee_Q12vital_timing_itn0_lit);
L4ieee_Q12vital_timing_C21vitaldefaultresultmap.init((&L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO),enumeration(0));
L4ieee_Q12vital_timing_C21vitaldefaultresultmap=L4ieee_Q12vital_timing_T18vitalresultmaptype(new array_info((&L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO)->element_type,(&L4ieee_Q12vital_timing_I18vitalresultmaptype_INFO)->index_type,enumeration(0),to,enumeration(0)+3,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3));
L4ieee_Q12vital_timing_C22vitaldefaultresultzmap.init((&L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO),enumeration(0));
L4ieee_Q12vital_timing_C22vitaldefaultresultzmap=L4ieee_Q12vital_timing_T19vitalresultzmaptype(new array_info((&L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO)->element_type,(&L4ieee_Q12vital_timing_I19vitalresultzmaptype_INFO)->index_type,enumeration(0),to,enumeration(0)+4,0),enumeration(0)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(1)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(2)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(3)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(4));
L4ieee_Q12vital_timing_C19vitalperioddatainit.init((&L4ieee_Q12vital_timing_I19vitalperioddatatype_INFO));
L4ieee_Q12vital_timing_C19vitalperioddatainit=L4ieee_Q12vital_timing_T19vitalperioddatatype().init((&L4ieee_Q12vital_timing_I19vitalperioddatatype_INFO)).aggregate_set(0,const_pointer(enumeration(1))).aggregate_set(1,const_pointer(0LL)).aggregate_set(2,const_pointer(0LL)).aggregate_set(3,const_pointer(enumeration(0)));
iname.pop();
handle_info *h = get_handle ("ieee","vital_timing",NULL);
if (h != NULL) (*h->init_function) ();
return 1;
}

/* end of package :ieee:vital_timing */

/* package body :ieee:vital_timing */
/* External declarations */
/** Enumeration info class :IEEE:std_logic_1164:x01z */
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
/* Prototype for subprogram :IEEE:std_logic_1164:to_x01z */
enumeration L4ieee_Q14std_logic_1164_Y7to_x01z_i136(const enumeration );
/* Prototype for subprogram :IEEE:std_logic_1164:to_x01 */
enumeration L4ieee_Q14std_logic_1164_Y6to_x01_i124(const enumeration );
/* Prototype for predefined function :IEEE:std_logic_1164:"=" */
/* Prototype for predefined function :IEEE:std_logic_1164:"/=" */
/* Definitions for access type :std:textio:line */
#define L3std_Q6textio_I4line access_info_base
extern access_info_base L3std_Q6textio_I4line_INFO;
/* Prototype for predefined subprogram :std:textio:deallocate */
#define L3std_Q6textio_X10deallocate_i7(p,a) p=(p!=NULL?(a.designated_type_info->remove(p),(void*)NULL):(void*)NULL)
/* Definitions for enumeration type :std:textio:side */
class L3std_Q6textio_I4side:public enum_info_base{
   static const char *values[];
public:
   L3std_Q6textio_I4side():enum_info_base(0,1,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 1; }
   static int left() { return 0; }
   static int right() { return 1; }
};
extern L3std_Q6textio_I4side L3std_Q6textio_I4side_INFO;
/* Prototype for subprogram :std:textio:write */
void L3std_Q6textio_X5write_i115(vhdlaccess &,const integer ,const enumeration ,const integer );
/* Prototype for subprogram :std:textio:write */
void L3std_Q6textio_X5write_i126(vhdlaccess &,const L3std_Q8standard_T6string &,const enumeration ,const integer );
/* Prototype for subprogram :std:textio:write */
void L3std_Q6textio_X5write_i110(vhdlaccess &,const enumeration ,const enumeration ,const integer );
/* Prototype for subprogram :std:textio:write */
void L3std_Q6textio_X5write_i132(vhdlaccess &,const physical ,const enumeration ,const integer ,const physical );
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* No header for IIR_EnumerationLiteral */
/* End of external declarations */
/* Definitions for enumeration type :ieee:vital_timing:checktype */
class L4ieee_W12vital_timing_I9checktype:public enum_info_base{
   static const char *values[];
public:
   L4ieee_W12vital_timing_I9checktype():enum_info_base(0,5,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 5; }
   static int left() { return 0; }
   static int right() { return 5; }
};
extern L4ieee_W12vital_timing_I9checktype L4ieee_W12vital_timing_I9checktype_INFO;
/* Definitions for record type :ieee:vital_timing:checkinfotype */
#define L4ieee_W12vital_timing_I13checkinfotype record_info
void *L4ieee_W12vital_timing_T13checkinfotype_ELEM_ADDR(void*,int);
struct L4ieee_W12vital_timing_T13checkinfotype_DATA {
  enumeration M9violation;
  enumeration M9checkkind;
  physical M7obstime;
  physical M7exptime;
  physical M7dettime;
  enumeration M5state;
  L4ieee_W12vital_timing_T13checkinfotype_DATA(enumeration M9violation, enumeration M9checkkind, physical M7obstime, physical M7exptime, physical M7dettime, enumeration M5state) : 
    M9violation(M9violation),
    M9checkkind(M9checkkind),
    M7obstime(M7obstime),
    M7exptime(M7exptime),
    M7dettime(M7dettime),
    M5state(M5state)
    { }
  L4ieee_W12vital_timing_T13checkinfotype_DATA() { }
  void init(type_info_interface *rinfo) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    M9violation=((enum_info_base*)einfos[0])->left_bound;
    M9checkkind=((enum_info_base*)einfos[1])->left_bound;
    M7obstime=((physical_info_base*)einfos[2])->left_bound;
    M7exptime=((physical_info_base*)einfos[3])->left_bound;
    M7dettime=((physical_info_base*)einfos[4])->left_bound;
    M5state=((enum_info_base*)einfos[5])->left_bound;
  };
  void init(type_info_interface *rinfo, const void *p) {
    type_info_interface **einfos = ((record_info*)rinfo)->element_types;
    const L4ieee_W12vital_timing_T13checkinfotype_DATA &src_data = *(L4ieee_W12vital_timing_T13checkinfotype_DATA*)((const record_base *)p)->data;
    M9violation=src_data.M9violation;
    M9checkkind=src_data.M9checkkind;
    M7obstime=src_data.M7obstime;
    M7exptime=src_data.M7exptime;
    M7dettime=src_data.M7dettime;
    M5state=src_data.M5state;
  };
};
#define L4ieee_W12vital_timing_T13checkinfotype record_type<L4ieee_W12vital_timing_T13checkinfotype_DATA>
extern record_info L4ieee_W12vital_timing_I13checkinfotype_INFO;
extern array_info L4ieee_W12vital_timing_I17logiccvttabletype_INFO;
#define L4ieee_W12vital_timing_T17logiccvttabletype array_type<enumeration >
#define L4ieee_W12vital_timing_I17logiccvttabletype array_info

extern array_info L4ieee_W12vital_timing_I11hilostrtype_INFO;
#define L4ieee_W12vital_timing_T11hilostrtype array_type<L3std_Q8standard_T6string >
#define L4ieee_W12vital_timing_I11hilostrtype array_info

extern array_info L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO;
#define L4ieee_W12vital_timing_T19edgesymbolmatchtype array_type<array_type<array_type<enumeration > > >
#define L4ieee_W12vital_timing_I19edgesymbolmatchtype array_info

/* Prototype for subprogram :ieee:vital_timing:minimum */
physical L4ieee_W12vital_timing_Y7minimum_i48(const physical ,const physical );
/* Prototype for subprogram :ieee:vital_timing:maximum */
physical L4ieee_W12vital_timing_Y7maximum_i51(const physical ,const physical );
/* Definitions for enumeration type :ieee:vital_timing:vitalerrortype */
class L4ieee_W12vital_timing_I14vitalerrortype:public enum_info_base{
   static const char *values[];
public:
   L4ieee_W12vital_timing_I14vitalerrortype():enum_info_base(0,3,values) {};
   static const char **get_values() { return values; }
   static int low() { return 0; }
   static int high() { return 3; }
   static int left() { return 0; }
   static int right() { return 3; }
};
extern L4ieee_W12vital_timing_I14vitalerrortype L4ieee_W12vital_timing_I14vitalerrortype_INFO;
extern array_info L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO;
#define L4ieee_W12vital_timing_T22vitalerrorseveritytype array_type<enumeration >
#define L4ieee_W12vital_timing_I22vitalerrorseveritytype array_info

extern array_info L4ieee_W12vital_timing_I3_t1_INFO;
#define L4ieee_W12vital_timing_T3_t1 array_type<enumeration >
#define L4ieee_W12vital_timing_I3_t1 array_info

extern array_info L4ieee_W12vital_timing_I3_t2_INFO;
#define L4ieee_W12vital_timing_T3_t2 array_type<enumeration >
#define L4ieee_W12vital_timing_I3_t2 array_info

extern array_info L4ieee_W12vital_timing_I3_t3_INFO;
#define L4ieee_W12vital_timing_T3_t3 array_type<enumeration >
#define L4ieee_W12vital_timing_I3_t3 array_info

extern array_info L4ieee_W12vital_timing_I3_t4_INFO;
#define L4ieee_W12vital_timing_T3_t4 array_type<enumeration >
#define L4ieee_W12vital_timing_I3_t4 array_info

extern array_info L4ieee_W12vital_timing_I3_t5_INFO;
#define L4ieee_W12vital_timing_T3_t5 array_type<enumeration >
#define L4ieee_W12vital_timing_I3_t5 array_info

/* Prototype for subprogram :ieee:vital_timing:vitalmessage */
L3std_Q8standard_T6string L4ieee_W12vital_timing_Y12vitalmessage_i81(const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i84(const L3std_Q8standard_T6string &,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i88(const L3std_Q8standard_T6string &,const enumeration ,const L3std_Q8standard_T6string &);
/* Prototype for subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i92(const L3std_Q8standard_T6string &,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i255(const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257(const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259(const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263(const enumeration ,const enumeration ,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267(const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271(const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119(const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const L4ieee_Q12vital_timing_T18vitalpatharraytype &,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130(const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const L4ieee_Q12vital_timing_T20vitalpatharray01type &,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141(const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const L4ieee_Q12vital_timing_T21vitalpatharray01ztype &,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:reportglitch */
void L4ieee_W12vital_timing_X12reportglitch_i156(const L3std_Q8standard_T6string &,const L3std_Q8standard_T6string &,const physical ,const enumeration ,const physical ,const enumeration ,const integer ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalglitch */
void L4ieee_W12vital_timing_X11vitalglitch_i171(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const physical ,const enumeration ,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay */
void L4ieee_Q12vital_timing_X14vitalpathdelay_i282(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T18vitalpatharraytype &,const physical ,const enumeration ,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay01 */
void L4ieee_Q12vital_timing_X16vitalpathdelay01_i293(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T20vitalpatharray01type &,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &,const enumeration ,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalpathdelay01z */
void L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305(sig_info<enumeration> *,driver_info *,L4ieee_Q12vital_timing_T19vitalglitchdatatype &,const L3std_Q8standard_T6string &,const enumeration ,const L4ieee_Q12vital_timing_T21vitalpatharray01ztype &,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &,const enumeration ,const enumeration ,const enumeration ,const enumeration ,const L4ieee_Q12vital_timing_T18vitaloutputmaptype &);
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i309(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const physical );
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i313(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &);
/* Prototype for subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i317(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &);
/* Prototype for subprogram :ieee:vital_timing:vitalsignaldelay */
void L4ieee_Q12vital_timing_X16vitalsignaldelay_i321(sig_info<enumeration> *,driver_info *,sig_info<enumeration> *,enumeration *,const physical );
/* Prototype for subprogram :ieee:vital_timing:reportviolation */
void L4ieee_W12vital_timing_X15reportviolation_i234(const L3std_Q8standard_T6string &,const L3std_Q8standard_T6string &,const L3std_Q8standard_T6string &,const L4ieee_W12vital_timing_T13checkinfotype &,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:internaltimingcheck */
void L4ieee_W12vital_timing_X19internaltimingcheck_i252(const enumeration ,const enumeration ,const physical ,const physical ,const physical ,const physical ,const physical ,const physical ,physical ,enumeration ,physical ,enumeration ,enumeration &,enumeration &,L4ieee_W12vital_timing_T13checkinfotype &,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitaltimingdatainit */
L4ieee_Q12vital_timing_T19vitaltimingdatatype L4ieee_Q12vital_timing_Y19vitaltimingdatainit_i167();
/* Prototype for subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<L4ieee_Q14std_logic_1164_T16std_logic_vector> *,L4ieee_Q14std_logic_1164_T16std_logic_vector *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalrecoveryremovalcheck */
void L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377(enumeration &,L4ieee_Q12vital_timing_T19vitaltimingdatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const enumeration ,const enumeration ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
/* Prototype for subprogram :ieee:vital_timing:vitalperiodpulsecheck */
void L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391(enumeration &,L4ieee_Q12vital_timing_T19vitalperioddatatype &,sig_info<enumeration> *,enumeration *,const L3std_Q8standard_T6string &,const physical ,const physical ,const physical ,const physical ,const enumeration ,const L3std_Q8standard_T6string &,const enumeration ,const enumeration ,const enumeration );
L4ieee_W12vital_timing_T17logiccvttabletype L4ieee_W12vital_timing_C13logiccvttable;
L4ieee_W12vital_timing_T11hilostrtype L4ieee_W12vital_timing_C7hilostr;
L4ieee_W12vital_timing_T19edgesymbolmatchtype L4ieee_W12vital_timing_C15edgesymbolmatch;
L4ieee_W12vital_timing_T22vitalerrorseveritytype L4ieee_W12vital_timing_C18vitalerrorseverity;
L4ieee_W12vital_timing_T3_t1 L4ieee_W12vital_timing_C9msgnopath;
L4ieee_W12vital_timing_T3_t2 L4ieee_W12vital_timing_C10msgnegpath;
L4ieee_W12vital_timing_T3_t3 L4ieee_W12vital_timing_C9msgnegdel;
L4ieee_W12vital_timing_T3_t4 L4ieee_W12vital_timing_C9msgvctlng;
L4ieee_W12vital_timing_T3_t5 L4ieee_W12vital_timing_C10msgunknown;
/* Implementation of enumeration type :ieee:vital_timing:checktype */
const char *L4ieee_W12vital_timing_I9checktype::values[]={"SetupCheck","HoldCheck","RecoveryCheck","RemovalCheck","PulseWidCheck","PeriodCheck"};
L4ieee_W12vital_timing_I9checktype L4ieee_W12vital_timing_I9checktype_INFO;
const char *L4ieee_W12vital_timing_T13checkinfotype_NAMES[] = {
  "violation",
  "checkkind",
  "obstime",
  "exptime",
  "dettime",
  "state"
};
void *L4ieee_W12vital_timing_T13checkinfotype_ELEM_ADDR(void *p, int i)
{
  L4ieee_W12vital_timing_T13checkinfotype_DATA &obj=*(L4ieee_W12vital_timing_T13checkinfotype_DATA*)p;
  switch (i) {
  case 0: return (void*)&obj.M9violation;
  case 1: return (void*)&obj.M9checkkind;
  case 2: return (void*)&obj.M7obstime;
  case 3: return (void*)&obj.M7exptime;
  case 4: return (void*)&obj.M7dettime;
  case 5: return (void*)&obj.M5state;
  };
};
L4ieee_W12vital_timing_I13checkinfotype L4ieee_W12vital_timing_I13checkinfotype_INFO;
L4ieee_W12vital_timing_I17logiccvttabletype L4ieee_W12vital_timing_I17logiccvttabletype_INFO;
L4ieee_W12vital_timing_I11hilostrtype L4ieee_W12vital_timing_I11hilostrtype_INFO;
enumeration L4ieee_W12vital_timing_itn13_lit[]={32,32,88,32};
enumeration L4ieee_W12vital_timing_itn14_lit[]={32,76,111,119};
enumeration L4ieee_W12vital_timing_itn15_lit[]={72,105,103,104};
L4ieee_W12vital_timing_I19edgesymbolmatchtype L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO;
/* Implementation of subprogram :ieee:vital_timing:minimum */
physical L4ieee_W12vital_timing_Y7minimum_i48(const physical L4ieee_W12vital_timing_Y7minimum_i48_C2t1,const physical L4ieee_W12vital_timing_Y7minimum_i48_C2t2)
{
    if((L4ieee_W12vital_timing_Y7minimum_i48_C2t1<L4ieee_W12vital_timing_Y7minimum_i48_C2t2)) {
      return L4ieee_W12vital_timing_Y7minimum_i48_C2t1;
    } else {
      return L4ieee_W12vital_timing_Y7minimum_i48_C2t2;
    }
}
/* Implementation of subprogram :ieee:vital_timing:maximum */
physical L4ieee_W12vital_timing_Y7maximum_i51(const physical L4ieee_W12vital_timing_Y7maximum_i51_C2t1,const physical L4ieee_W12vital_timing_Y7maximum_i51_C2t2)
{
    if((L4ieee_W12vital_timing_Y7maximum_i51_C2t1>L4ieee_W12vital_timing_Y7maximum_i51_C2t2)) {
      return L4ieee_W12vital_timing_Y7maximum_i51_C2t1;
    } else {
      return L4ieee_W12vital_timing_Y7maximum_i51_C2t2;
    }
}
/* Implementation of enumeration type :ieee:vital_timing:vitalerrortype */
const char *L4ieee_W12vital_timing_I14vitalerrortype::values[]={"ErrVctLng","ErrNoPath","ErrNegPath","ErrNegDel"};
L4ieee_W12vital_timing_I14vitalerrortype L4ieee_W12vital_timing_I14vitalerrortype_INFO;
L4ieee_W12vital_timing_I22vitalerrorseveritytype L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO;
L4ieee_W12vital_timing_I3_t1 L4ieee_W12vital_timing_I3_t1_INFO;
enumeration L4ieee_W12vital_timing_itn16_lit[]={78,111,32,68,101,108,97,121,32,80,97,116,104,32,67,111,110,100,105,116,105,111,110,32,84,82,85,69,46,32,32,48,45,100,101,108,97,121,32,117,115,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
L4ieee_W12vital_timing_I3_t2 L4ieee_W12vital_timing_I3_t2_INFO;
enumeration L4ieee_W12vital_timing_itn17_lit[]={80,97,116,104,32,68,101,108,97,121,32,108,101,115,115,32,116,104,97,110,32,116,105,109,101,32,115,105,110,99,101,32,105,110,112,117,116,46,32,48,32,100,101,108,97,121,32,117,115,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
L4ieee_W12vital_timing_I3_t3 L4ieee_W12vital_timing_I3_t3_INFO;
enumeration L4ieee_W12vital_timing_itn18_lit[]={78,101,103,97,116,105,118,101,32,100,101,108,97,121,46,32,78,101,119,32,111,117,116,112,117,116,32,118,97,108,117,101,32,110,111,116,32,115,99,104,101,100,117,108,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
L4ieee_W12vital_timing_I3_t4 L4ieee_W12vital_timing_I3_t4_INFO;
enumeration L4ieee_W12vital_timing_itn19_lit[]={86,101,99,116,111,114,32,40,97,114,114,97,121,41,32,108,101,110,103,116,104,115,32,110,111,116,32,101,113,117,97,108,46,32};
L4ieee_W12vital_timing_I3_t5 L4ieee_W12vital_timing_I3_t5_INFO;
enumeration L4ieee_W12vital_timing_itn20_lit[]={85,110,107,110,111,119,110,32,101,114,114,111,114,32,109,101,115,115,97,103,101,46};
enumeration L4ieee_W12vital_timing_itn21_lit[]={86,101,99,116,111,114,32,40,97,114,114,97,121,41,32,108,101,110,103,116,104,115,32,110,111,116,32,101,113,117,97,108,46,32};
enumeration L4ieee_W12vital_timing_itn22_lit[]={78,111,32,68,101,108,97,121,32,80,97,116,104,32,67,111,110,100,105,116,105,111,110,32,84,82,85,69,46,32,32,48,45,100,101,108,97,121,32,117,115,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
enumeration L4ieee_W12vital_timing_itn23_lit[]={80,97,116,104,32,68,101,108,97,121,32,108,101,115,115,32,116,104,97,110,32,116,105,109,101,32,115,105,110,99,101,32,105,110,112,117,116,46,32,48,32,100,101,108,97,121,32,117,115,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
enumeration L4ieee_W12vital_timing_itn24_lit[]={78,101,103,97,116,105,118,101,32,100,101,108,97,121,46,32,78,101,119,32,111,117,116,112,117,116,32,118,97,108,117,101,32,110,111,116,32,115,99,104,101,100,117,108,101,100,46,32,79,117,116,112,117,116,32,115,105,103,110,97,108,32,105,115,58,32};
enumeration L4ieee_W12vital_timing_itn25_lit[]={85,110,107,110,111,119,110,32,101,114,114,111,114,32,109,101,115,115,97,103,101,46};
/* Implementation of subprogram :ieee:vital_timing:vitalmessage */
L3std_Q8standard_T6string L4ieee_W12vital_timing_Y12vitalmessage_i81(const enumeration L4ieee_W12vital_timing_Y12vitalmessage_i81_C7errorid)
{
    switch(L4ieee_W12vital_timing_Y12vitalmessage_i81_C7errorid) {
    case 0: {
      return array_alias<L3std_Q8standard_T6string >((&L3std_Q8standard_I6string_INFO),array_alias<L4ieee_W12vital_timing_T3_t4 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,34,0),L4ieee_W12vital_timing_itn21_lit));
     } break;
    case 1: {
      return array_alias<L3std_Q8standard_T6string >((&L3std_Q8standard_I6string_INFO),array_alias<L4ieee_W12vital_timing_T3_t1 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,63,0),L4ieee_W12vital_timing_itn22_lit));
     } break;
    case 2: {
      return array_alias<L3std_Q8standard_T6string >((&L3std_Q8standard_I6string_INFO),array_alias<L4ieee_W12vital_timing_T3_t2 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,71,0),L4ieee_W12vital_timing_itn23_lit));
     } break;
    case 3: {
      return array_alias<L3std_Q8standard_T6string >((&L3std_Q8standard_I6string_INFO),array_alias<L4ieee_W12vital_timing_T3_t3 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,66,0),L4ieee_W12vital_timing_itn24_lit));
     } break;
    default: {
      return array_alias<L3std_Q8standard_T6string >((&L3std_Q8standard_I6string_INFO),array_alias<L4ieee_W12vital_timing_T3_t5 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,22,0),L4ieee_W12vital_timing_itn25_lit));
     } break;
    }
}
enumeration L4ieee_W12vital_timing_itn26_lit[]={58,32};
/* Implementation of subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i84(const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X10vitalerror_i84_C7routine,const enumeration L4ieee_W12vital_timing_X10vitalerror_i84_C7errorid)
{
    if(!enumeration(0))
      report(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(L4ieee_W12vital_timing_X10vitalerror_i84_C7routine,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+1,0),L4ieee_W12vital_timing_itn26_lit)),L4ieee_W12vital_timing_Y12vitalmessage_i81 (L4ieee_W12vital_timing_X10vitalerror_i84_C7errorid)),L4ieee_W12vital_timing_C18vitalerrorseverity[L4ieee_W12vital_timing_X10vitalerror_i84_C7errorid]);
    rlabel:
    return;
}
enumeration L4ieee_W12vital_timing_itn27_lit[]={58,32};
/* Implementation of subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i88(const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X10vitalerror_i88_C7routine,const enumeration L4ieee_W12vital_timing_X10vitalerror_i88_C7errorid,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X10vitalerror_i88_C4info)
{
    if(!enumeration(0))
      report(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(L4ieee_W12vital_timing_X10vitalerror_i88_C7routine,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+1,0),L4ieee_W12vital_timing_itn27_lit)),L4ieee_W12vital_timing_Y12vitalmessage_i81 (L4ieee_W12vital_timing_X10vitalerror_i88_C7errorid)),L4ieee_W12vital_timing_X10vitalerror_i88_C4info),L4ieee_W12vital_timing_C18vitalerrorseverity[L4ieee_W12vital_timing_X10vitalerror_i88_C7errorid]);
    rlabel:
    return;
}
enumeration L4ieee_W12vital_timing_itn28_lit[]={58,32};
/* Implementation of subprogram :ieee:vital_timing:vitalerror */
void L4ieee_W12vital_timing_X10vitalerror_i92(const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X10vitalerror_i92_C7routine,const enumeration L4ieee_W12vital_timing_X10vitalerror_i92_C7errorid,const enumeration L4ieee_W12vital_timing_X10vitalerror_i92_C4info)
{
    if(!enumeration(0))
      report(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(L4ieee_W12vital_timing_X10vitalerror_i92_C7routine,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+1,0),L4ieee_W12vital_timing_itn28_lit)),L4ieee_W12vital_timing_Y12vitalmessage_i81 (L4ieee_W12vital_timing_X10vitalerror_i92_C7errorid)),L3std_Q8standard_T6string(new array_info(L3std_Q8standard_I6string_INFO.element_type,L3std_Q8standard_I6string_INFO.index_type,1,to,1,0),L4ieee_W12vital_timing_X10vitalerror_i92_C4info)),L4ieee_W12vital_timing_C18vitalerrorseverity[L4ieee_W12vital_timing_X10vitalerror_i92_C7errorid]);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i255(const physical L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i255_C5delay)
{
    return array_alias<L4ieee_Q12vital_timing_T17vitaldelaytype01z >((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z(new array_info((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO)->element_type,(&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO)->index_type,enumeration(0),to,enumeration(5),0),L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i255_C5delay)).data);
}
/* Implementation of subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257(const L4ieee_Q12vital_timing_T16vitaldelaytype01 &L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay_PAR)
{
    L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(L4ieee_Q12vital_timing_T16vitaldelaytype01::E_type*)L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay_PAR.data);
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z;
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z.init((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),-9223372036854775807LL);
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(0)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(0)];
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(2)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(0)];
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(3)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(0)];
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(1)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(1)];
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(4)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(1)];
    L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z[enumeration(5)]=L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_C5delay[enumeration(1)];
    return array_alias<L4ieee_Q12vital_timing_T17vitaldelaytype01z >((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i257_V8delay01z).data);
}
/* Implementation of subprogram :ieee:vital_timing:vitalextendtofilldelay */
L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259(const L4ieee_Q12vital_timing_T17vitaldelaytype01z &L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259_C5delay_PAR)
{
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259_C5delay((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z::E_type*)L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259_C5delay_PAR.data);
    return array_alias<L4ieee_Q12vital_timing_T17vitaldelaytype01z >((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_Y22vitalextendtofilldelay_i259_C5delay).data);
}
/* Implementation of subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263(const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263_C6newval,const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263_C6oldval,const physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263_C5delay)
{
    return L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263_C5delay;
}
/* Implementation of subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267(const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C6newval,const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C6oldval,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay_PAR)
{
    L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(L4ieee_Q12vital_timing_T16vitaldelaytype01::E_type*)L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay_PAR.data);
    physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result;
    L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=-9223372036854775807LL;
    switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C6newval) {
    case 2: case 6: {
      L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)];
     } break;
    case 3: case 7: {
      L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)];
     } break;
    case 4: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C6oldval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)];
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)];
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)]);
       } break;
      }
     } break;
    default: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C6oldval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)];
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)];
       } break;
      case 4: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_W12vital_timing_Y7minimum_i48 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)]);
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_C5delay[enumeration(0)]);
       } break;
      }
     } break;
    }
    return L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267_V6result;
}
/* Implementation of subprogram :ieee:vital_timing:vitalcalcdelay */
physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271(const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6newval,const enumeration L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6oldval,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay_PAR)
{
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z::E_type*)L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay_PAR.data);
    physical L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result;
    L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=-9223372036854775807LL;
    switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6oldval) {
    case 2: case 6: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6newval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(1)];
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(0)];
       } break;
      case 4: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(2)];
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7minimum_i48 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(0)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(2)]);
       } break;
      }
     } break;
    case 3: case 7: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6newval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(1)];
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(0)];
       } break;
      case 4: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(4)];
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7minimum_i48 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(4)]);
       } break;
      }
     } break;
    case 4: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6newval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(5)];
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(3)];
       } break;
      case 4: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(2)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(4)]);
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7minimum_i48 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(3)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(5)]);
       } break;
      }
     } break;
    case 0: case 1: case 5: case 8: {
      switch(L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C6newval) {
      case 2: case 6: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(5)]);
       } break;
      case 3: case 7: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(0)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(3)]);
       } break;
      case 4: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(4)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(2)]);
       } break;
      default: {
        L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(1)],L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_C5delay[enumeration(0)]);
       } break;
      }
     } break;
    }
    return L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271_V6result;
}
/* Implementation of subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119(const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8newvalue,const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8oldvalue,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C13outsignalname,const L4ieee_Q12vital_timing_T18vitalpatharraytype &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths,const physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C12defaultdelay)
{
    physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay;
    integer L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_lc,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_ls;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay=-9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage=9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=9223372036854775807LL;
    for (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_ls=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths.info->index_direction==to?+1:-1,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_lc=range_to_length<integer>(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths.info->index_direction,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths.info->right_bound);L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_lc!=0; L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i+=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_ls,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i_lc--) {
      if (op_not(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i].value().M13pathcondition)) goto next_6;
      if ((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i].value().M15inputchangetime>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage)) goto next_6;
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i].value().M9pathdelay);
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i].value().M15inputchangetime<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay;
      } else {
        if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay)) {
          L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8tmpdelay;
        }
      }
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_L5123ln_C1i].value().M15inputchangetime;
    next_6:; }
    if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay==9223372036854775807LL)) {
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C12defaultdelay);
    } else {
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i263 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_C12defaultdelay);
      } else {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay=(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay-L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V8inputage);
      }
    }
    return L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119_V9propdelay;
}
/* Implementation of subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130(const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8newvalue,const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8oldvalue,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C13outsignalname,const L4ieee_Q12vital_timing_T20vitalpatharray01type &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C12defaultdelay_PAR)
{
    L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C12defaultdelay((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(L4ieee_Q12vital_timing_T16vitaldelaytype01::E_type*)L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C12defaultdelay_PAR.data);
    physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay;
    integer L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_lc,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_ls;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay=-9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage=9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=9223372036854775807LL;
    for (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_ls=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths.info->index_direction==to?+1:-1,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_lc=range_to_length<integer>(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths.info->index_direction,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths.info->right_bound);L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_lc!=0; L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i+=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_ls,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i_lc--) {
      if (op_not(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i].value().M13pathcondition)) goto next_7;
      if ((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i].value().M15inputchangetime>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage)) goto next_7;
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i].value().M9pathdelay);
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i].value().M15inputchangetime<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay;
      } else {
        if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay)) {
          L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8tmpdelay;
        }
      }
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_L5134ln_C1i].value().M15inputchangetime;
    next_7:; }
    if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay==9223372036854775807LL)) {
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C12defaultdelay);
    } else {
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_C12defaultdelay);
      } else {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay=(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay-L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V8inputage);
      }
    }
    return L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130_V9propdelay;
}
/* Implementation of subprogram :ieee:vital_timing:vitalselectpathdelay */
physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141(const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8newvalue,const enumeration L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8oldvalue,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C13outsignalname,const L4ieee_Q12vital_timing_T21vitalpatharray01ztype &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C12defaultdelay_PAR)
{
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C12defaultdelay((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z::E_type*)L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C12defaultdelay_PAR.data);
    physical L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay;
    integer L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_lc,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_ls;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay=-9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage=9223372036854775807LL;
    L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=9223372036854775807LL;
    for (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_ls=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths.info->index_direction==to?+1:-1,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_lc=range_to_length<integer>(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths.info->left_bound,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths.info->index_direction,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths.info->right_bound);L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_lc!=0; L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i+=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_ls,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i_lc--) {
      if (op_not(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i].value().M13pathcondition)) goto next_8;
      if ((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i].value().M15inputchangetime>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage)) goto next_8;
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i].value().M9pathdelay);
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i].value().M15inputchangetime<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay;
      } else {
        if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay<L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay)) {
          L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8tmpdelay;
        }
      }
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C5paths[L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_L5145ln_C1i].value().M15inputchangetime;
    next_8:; }
    if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay==9223372036854775807LL)) {
      L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C12defaultdelay);
    } else {
      if((L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage>L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay)) {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271 (L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8newvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C8oldvalue,L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_C12defaultdelay);
      } else {
        L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay=(L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay-L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V8inputage);
      }
    }
    return L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141_V9propdelay;
}
enumeration L4ieee_W12vital_timing_itn29_lit[]={40};
enumeration L4ieee_W12vital_timing_itn30_lit[]={41};
enumeration L4ieee_W12vital_timing_itn31_lit[]={32};
enumeration L4ieee_W12vital_timing_itn32_lit[]={58,32,71,76,73,84,67,72,32,68,101,116,101,99,116,101,100,32,111,110,32,112,111,114,116,32};
enumeration L4ieee_W12vital_timing_itn33_lit[]={59,32,80,114,101,101,109,112,116,101,100,32,70,117,116,117,114,101,32,86,97,108,117,101,32,58,61,32};
enumeration L4ieee_W12vital_timing_itn34_lit[]={32,64,32};
enumeration L4ieee_W12vital_timing_itn35_lit[]={59,32,78,101,119,108,121,32,83,99,104,101,100,117,108,101,100,32,86,97,108,117,101,32,58,61,32};
enumeration L4ieee_W12vital_timing_itn36_lit[]={32,64,32};
enumeration L4ieee_W12vital_timing_itn37_lit[]={59};
/* Implementation of subprogram :ieee:vital_timing:reportglitch */
void L4ieee_W12vital_timing_X12reportglitch_i156(const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X12reportglitch_i156_C13glitchroutine,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X12reportglitch_i156_C13outsignalname,const physical L4ieee_W12vital_timing_X12reportglitch_i156_C13preemptedtime,const enumeration L4ieee_W12vital_timing_X12reportglitch_i156_C14preemptedvalue,const physical L4ieee_W12vital_timing_X12reportglitch_i156_C7newtime,const enumeration L4ieee_W12vital_timing_X12reportglitch_i156_C8newvalue,const integer L4ieee_W12vital_timing_X12reportglitch_i156_C5index,const enumeration L4ieee_W12vital_timing_X12reportglitch_i156_C13isarraysignal,const enumeration L4ieee_W12vital_timing_X12reportglitch_i156_C11msgseverity)
{
    vhdlaccess L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr4,L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr3,L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr2,L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr1;
    L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5=NULL;
    L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr4=NULL;
    L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr3=NULL;
    L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr2=NULL;
    L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr1=NULL;
    L3std_Q6textio_X5write_i132 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr1,L4ieee_W12vital_timing_X12reportglitch_i156_C13preemptedtime,enumeration(0),0,1000000LL);
    L3std_Q6textio_X5write_i132 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr2,L4ieee_W12vital_timing_X12reportglitch_i156_C7newtime,enumeration(0),0,1000000LL);
    L3std_Q6textio_X5write_i110 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr3,L4ieee_W12vital_timing_C13logiccvttable[L4ieee_W12vital_timing_X12reportglitch_i156_C14preemptedvalue],enumeration(0),0);
    L3std_Q6textio_X5write_i110 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr4,L4ieee_W12vital_timing_C13logiccvttable[L4ieee_W12vital_timing_X12reportglitch_i156_C8newvalue],enumeration(0),0);
    if(L4ieee_W12vital_timing_X12reportglitch_i156_C13isarraysignal) {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn29_lit),enumeration(0),0);
      L3std_Q6textio_X5write_i115 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,L4ieee_W12vital_timing_X12reportglitch_i156_C5index,enumeration(0),0);
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn30_lit),enumeration(0),0);
    } else {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn31_lit),enumeration(0),0);
    }
    if(!(L4ieee_W12vital_timing_X12reportglitch_i156_C13preemptedtime>L4ieee_W12vital_timing_X12reportglitch_i156_C7newtime))
      report(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(L4ieee_W12vital_timing_X12reportglitch_i156_C13glitchroutine,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+25,0),L4ieee_W12vital_timing_itn32_lit)),L4ieee_W12vital_timing_X12reportglitch_i156_C13outsignalname),deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+27,0),L4ieee_W12vital_timing_itn33_lit)),deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr3)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+2,0),L4ieee_W12vital_timing_itn34_lit)),deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr1)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+26,0),L4ieee_W12vital_timing_itn35_lit)),deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr4)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+2,0),L4ieee_W12vital_timing_itn36_lit)),deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr2)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn37_lit)),L4ieee_W12vital_timing_X12reportglitch_i156_C11msgseverity);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr1,L3std_Q6textio_I4line_INFO);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr2,L3std_Q6textio_I4line_INFO);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr3,L3std_Q6textio_I4line_INFO);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr4,L3std_Q6textio_I4line_INFO);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X12reportglitch_i156_V7strptr5,L3std_Q6textio_I4line_INFO);
    goto rlabel;
    rlabel:
    return;
}
enumeration L4ieee_W12vital_timing_itn38_lit[]={86,105,116,97,108,71,108,105,116,99,104};
enumeration L4ieee_W12vital_timing_itn39_lit[]={86,105,116,97,108,71,108,105,116,99,104};
/* Implementation of subprogram :ieee:vital_timing:vitalglitch */
void L4ieee_W12vital_timing_X11vitalglitch_i171(sig_info<enumeration> *L4ieee_W12vital_timing_X11vitalglitch_i171_S9outsignal,driver_info *L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal,L4ieee_Q12vital_timing_T19vitalglitchdatatype &L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X11vitalglitch_i171_C13outsignalname,const enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,const physical L4ieee_W12vital_timing_X11vitalglitch_i171_C8newdelay,const enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_C4mode,const enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_C3xon,const enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_C5msgon,const enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_C11msgseverity)
{
    enumeration L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch;
    physical L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly;
    L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(1);
    L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly=L4ieee_W12vital_timing_X11vitalglitch_i171_C8newdelay;
    if((L4ieee_W12vital_timing_X11vitalglitch_i171_C8newdelay<0LL)) {
      if((L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue!=L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue)) {
        L4ieee_W12vital_timing_X10vitalerror_i88 (array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+10,0),L4ieee_W12vital_timing_itn38_lit),enumeration(3),L4ieee_W12vital_timing_X11vitalglitch_i171_C13outsignalname);
      }
      goto rlabel;
    }
    if((L4ieee_W12vital_timing_X11vitalglitch_i171_C4mode==enumeration(2))) {
      L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->inertial_assign(L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,vtime(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly));
    } else {
      if((L4ieee_W12vital_timing_X11vitalglitch_i171_C4mode==enumeration(3))) {
        L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->transport_assign(L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,vtime(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly));
      } else {
        if((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime<=L3std_Q8standard_Y3now_i303 ())) {
          if((L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue==L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue)) {
            goto rlabel;
          }
          L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(0);
          L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime=(L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly);
        } else {
          if((((L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly)<=L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime)&&((L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly)<=L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime))) {
            L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(0);
            L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime=(L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly);
          } else {
            if((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime<=L3std_Q8standard_Y3now_i303 ())) {
              if((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue==L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue)) {
                L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly=L4ieee_W12vital_timing_Y7minimum_i48 ((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime-L3std_Q8standard_Y3now_i303 ()),L4ieee_W12vital_timing_X11vitalglitch_i171_C8newdelay);
              }
              L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(0);
            } else {
              if(((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue==L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue)&&(L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime==L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime))) {
                L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly=L4ieee_W12vital_timing_Y7minimum_i48 ((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime-L3std_Q8standard_Y3now_i303 ()),L4ieee_W12vital_timing_X11vitalglitch_i171_C8newdelay);
                L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(0);
                L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime=(L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly);
              } else {
                L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch=enumeration(1);
              }
            }
          }
        }
        if(L4ieee_W12vital_timing_X11vitalglitch_i171_V9newglitch) {
          if(L4ieee_W12vital_timing_X11vitalglitch_i171_C5msgon) {
            L4ieee_W12vital_timing_X12reportglitch_i156 (array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+10,0),L4ieee_W12vital_timing_itn39_lit),L4ieee_W12vital_timing_X11vitalglitch_i171_C13outsignalname,L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime,L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue,(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly+L3std_Q8standard_Y3now_i303 ()),L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,0,enumeration(0),L4ieee_W12vital_timing_X11vitalglitch_i171_C11msgseverity);
          }
          if((L4ieee_W12vital_timing_X11vitalglitch_i171_C4mode==enumeration(1))) {
            L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime=L3std_Q8standard_Y3now_i303 ();
          }
          if(L4ieee_W12vital_timing_X11vitalglitch_i171_C3xon) {
            L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->inertial_assign(enumeration(1),vtime((L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10glitchtime-L3std_Q8standard_Y3now_i303 ())));
            L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->transport_assign(L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,vtime(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly));
          } else {
            L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->inertial_assign(L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,vtime(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly));
          }
        } else {
          L4ieee_W12vital_timing_X11vitalglitch_i171_D9outsignal->inertial_assign(L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue,vtime(L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly));
        }
      }
    }
    L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M10schedvalue=L4ieee_W12vital_timing_X11vitalglitch_i171_C8newvalue;
    L4ieee_W12vital_timing_X11vitalglitch_i171_V10glitchdata.value().M9schedtime=(L3std_Q8standard_Y3now_i303 ()+L4ieee_W12vital_timing_X11vitalglitch_i171_V3dly);
    goto rlabel;
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalpathdelay */
void L4ieee_Q12vital_timing_X14vitalpathdelay_i282(sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalpathdelay_i282_S9outsignal,driver_info *L4ieee_Q12vital_timing_X14vitalpathdelay_i282_D9outsignal,L4ieee_Q12vital_timing_T19vitalglitchdatatype &L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C13outsignalname,const enumeration L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C7outtemp,const L4ieee_Q12vital_timing_T18vitalpatharraytype &L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C5paths,const physical L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C12defaultdelay,const enumeration L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C4mode,const enumeration L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C3xon,const enumeration L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C5msgon,const enumeration L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C11msgseverity)
{
    physical L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V9propdelay;
    L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V9propdelay=-9223372036854775807LL;
    if(((L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata.value().M9schedtime<=L3std_Q8standard_Y3now_i303 ())&&(L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata.value().M10schedvalue==L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C7outtemp))) {
      goto rlabel;
    }
    L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i119 (L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C7outtemp,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata.value().M9lastvalue,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C13outsignalname,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C5paths,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C12defaultdelay);
    L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata.value().M9lastvalue=L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C7outtemp;
    L4ieee_W12vital_timing_X11vitalglitch_i171 (L4ieee_Q12vital_timing_X14vitalpathdelay_i282_S9outsignal,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_D9outsignal,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V10glitchdata,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C13outsignalname,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C7outtemp,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_V9propdelay,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C4mode,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C3xon,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C5msgon,L4ieee_Q12vital_timing_X14vitalpathdelay_i282_C11msgseverity);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalpathdelay01 */
void L4ieee_Q12vital_timing_X16vitalpathdelay01_i293(sig_info<enumeration> *L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_S9outsignal,driver_info *L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_D9outsignal,L4ieee_Q12vital_timing_T19vitalglitchdatatype &L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C13outsignalname,const enumeration L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C7outtemp,const L4ieee_Q12vital_timing_T20vitalpatharray01type &L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C5paths,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C12defaultdelay_PAR,const enumeration L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C4mode,const enumeration L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C3xon,const enumeration L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C5msgon,const enumeration L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C11msgseverity)
{
    L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C12defaultdelay((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(L4ieee_Q12vital_timing_T16vitaldelaytype01::E_type*)L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C12defaultdelay_PAR.data);
    physical L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V9propdelay;
    L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V9propdelay=-9223372036854775807LL;
    if(((L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata.value().M9schedtime<=L3std_Q8standard_Y3now_i303 ())&&(L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata.value().M10schedvalue==L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C7outtemp))) {
      goto rlabel;
    }
    L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i130 (L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C7outtemp,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata.value().M9lastvalue,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C13outsignalname,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C5paths,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C12defaultdelay);
    L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata.value().M9lastvalue=L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C7outtemp;
    L4ieee_W12vital_timing_X11vitalglitch_i171 (L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_S9outsignal,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_D9outsignal,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V10glitchdata,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C13outsignalname,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C7outtemp,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_V9propdelay,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C4mode,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C3xon,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C5msgon,L4ieee_Q12vital_timing_X16vitalpathdelay01_i293_C11msgseverity);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalpathdelay01z */
void L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305(sig_info<enumeration> *L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_S9outsignal,driver_info *L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_D9outsignal,L4ieee_Q12vital_timing_T19vitalglitchdatatype &L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C13outsignalname,const enumeration L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C7outtemp,const L4ieee_Q12vital_timing_T21vitalpatharray01ztype &L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C5paths,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C12defaultdelay_PAR,const enumeration L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C4mode,const enumeration L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C3xon,const enumeration L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C5msgon,const enumeration L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C11msgseverity,const L4ieee_Q12vital_timing_T18vitaloutputmaptype &L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C9outputmap_PAR)
{
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C12defaultdelay((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z::E_type*)L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C12defaultdelay_PAR.data);
    L4ieee_Q12vital_timing_T18vitaloutputmaptype L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C9outputmap((&L4ieee_Q12vital_timing_I18vitaloutputmaptype_INFO),(L4ieee_Q12vital_timing_T18vitaloutputmaptype::E_type*)L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C9outputmap_PAR.data);
    physical L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V9propdelay;
    L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V9propdelay=-9223372036854775807LL;
    if(((L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata.value().M9schedtime<=L3std_Q8standard_Y3now_i303 ())&&(L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata.value().M10schedvalue==L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C9outputmap[L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C7outtemp]))) {
      goto rlabel;
    }
    L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V9propdelay=L4ieee_W12vital_timing_Y20vitalselectpathdelay_i141 (L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C7outtemp,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata.value().M9lastvalue,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C13outsignalname,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C5paths,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C12defaultdelay);
    L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata.value().M9lastvalue=L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C7outtemp;
    L4ieee_W12vital_timing_X11vitalglitch_i171 (L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_S9outsignal,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_D9outsignal,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V10glitchdata,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C13outsignalname,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C9outputmap[L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C7outtemp],L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_V9propdelay,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C4mode,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C3xon,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C5msgon,L4ieee_Q12vital_timing_X17vitalpathdelay01z_i305_C11msgseverity);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i309(sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i309_S6outsig,driver_info *L4ieee_Q12vital_timing_X14vitalwiredelay_i309_D6outsig,sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i309_S5insig,enumeration *L4ieee_Q12vital_timing_X14vitalwiredelay_i309_R5insig,const physical L4ieee_Q12vital_timing_X14vitalwiredelay_i309_C5twire)
{
    L4ieee_Q12vital_timing_X14vitalwiredelay_i309_D6outsig->transport_assign((*L4ieee_Q12vital_timing_X14vitalwiredelay_i309_R5insig),vtime(L4ieee_Q12vital_timing_X14vitalwiredelay_i309_C5twire));
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i313(sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i313_S6outsig,driver_info *L4ieee_Q12vital_timing_X14vitalwiredelay_i313_D6outsig,sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i313_S5insig,enumeration *L4ieee_Q12vital_timing_X14vitalwiredelay_i313_R5insig,const L4ieee_Q12vital_timing_T16vitaldelaytype01 &L4ieee_Q12vital_timing_X14vitalwiredelay_i313_C5twire_PAR)
{
    L4ieee_Q12vital_timing_T16vitaldelaytype01 L4ieee_Q12vital_timing_X14vitalwiredelay_i313_C5twire((&L4ieee_Q12vital_timing_I16vitaldelaytype01_INFO),(L4ieee_Q12vital_timing_T16vitaldelaytype01::E_type*)L4ieee_Q12vital_timing_X14vitalwiredelay_i313_C5twire_PAR.data);
    physical L4ieee_Q12vital_timing_X14vitalwiredelay_i313_V5delay;
    L4ieee_Q12vital_timing_X14vitalwiredelay_i313_V5delay=-9223372036854775807LL;
    L4ieee_Q12vital_timing_X14vitalwiredelay_i313_V5delay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i267 ((*L4ieee_Q12vital_timing_X14vitalwiredelay_i313_R5insig),attr_scalar_LAST_VALUE<enumeration>(L4ieee_Q12vital_timing_X14vitalwiredelay_i313_S5insig),L4ieee_Q12vital_timing_X14vitalwiredelay_i313_C5twire);
    L4ieee_Q12vital_timing_X14vitalwiredelay_i313_D6outsig->transport_assign((*L4ieee_Q12vital_timing_X14vitalwiredelay_i313_R5insig),vtime(L4ieee_Q12vital_timing_X14vitalwiredelay_i313_V5delay));
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalwiredelay */
void L4ieee_Q12vital_timing_X14vitalwiredelay_i317(sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i317_S6outsig,driver_info *L4ieee_Q12vital_timing_X14vitalwiredelay_i317_D6outsig,sig_info<enumeration> *L4ieee_Q12vital_timing_X14vitalwiredelay_i317_S5insig,enumeration *L4ieee_Q12vital_timing_X14vitalwiredelay_i317_R5insig,const L4ieee_Q12vital_timing_T17vitaldelaytype01z &L4ieee_Q12vital_timing_X14vitalwiredelay_i317_C5twire_PAR)
{
    L4ieee_Q12vital_timing_T17vitaldelaytype01z L4ieee_Q12vital_timing_X14vitalwiredelay_i317_C5twire((&L4ieee_Q12vital_timing_I17vitaldelaytype01z_INFO),(L4ieee_Q12vital_timing_T17vitaldelaytype01z::E_type*)L4ieee_Q12vital_timing_X14vitalwiredelay_i317_C5twire_PAR.data);
    physical L4ieee_Q12vital_timing_X14vitalwiredelay_i317_V5delay;
    L4ieee_Q12vital_timing_X14vitalwiredelay_i317_V5delay=-9223372036854775807LL;
    L4ieee_Q12vital_timing_X14vitalwiredelay_i317_V5delay=L4ieee_Q12vital_timing_Y14vitalcalcdelay_i271 ((*L4ieee_Q12vital_timing_X14vitalwiredelay_i317_R5insig),attr_scalar_LAST_VALUE<enumeration>(L4ieee_Q12vital_timing_X14vitalwiredelay_i317_S5insig),L4ieee_Q12vital_timing_X14vitalwiredelay_i317_C5twire);
    L4ieee_Q12vital_timing_X14vitalwiredelay_i317_D6outsig->transport_assign((*L4ieee_Q12vital_timing_X14vitalwiredelay_i317_R5insig),vtime(L4ieee_Q12vital_timing_X14vitalwiredelay_i317_V5delay));
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalsignaldelay */
void L4ieee_Q12vital_timing_X16vitalsignaldelay_i321(sig_info<enumeration> *L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_S6outsig,driver_info *L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_D6outsig,sig_info<enumeration> *L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_S5insig,enumeration *L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_R5insig,const physical L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_C3dly)
{
    L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_D6outsig->transport_assign((*L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_R5insig),vtime(L4ieee_Q12vital_timing_X16vitalsignaldelay_i321_C3dly));
    rlabel:
    return;
}
enumeration L4ieee_W12vital_timing_itn40_lit[]={32,83,69,84,85,80,32};
enumeration L4ieee_W12vital_timing_itn41_lit[]={32,72,79,76,68,32};
enumeration L4ieee_W12vital_timing_itn42_lit[]={32,82,69,67,79,86,69,82,89,32};
enumeration L4ieee_W12vital_timing_itn43_lit[]={32,82,69,77,79,86,65,76,32};
enumeration L4ieee_W12vital_timing_itn44_lit[]={32,80,85,76,83,69,32,87,73,68,84,72,32};
enumeration L4ieee_W12vital_timing_itn45_lit[]={32,80,69,82,73,79,68,32};
enumeration L4ieee_W12vital_timing_itn46_lit[]={32,86,73,79,76,65,84,73,79,78,32,79,78,32};
enumeration L4ieee_W12vital_timing_itn47_lit[]={32,87,73,84,72,32,82,69,83,80,69,67,84,32,84,79,32};
enumeration L4ieee_W12vital_timing_itn48_lit[]={59,10};
enumeration L4ieee_W12vital_timing_itn49_lit[]={32,32,69,120,112,101,99,116,101,100,32,58,61,32};
enumeration L4ieee_W12vital_timing_itn50_lit[]={59,32,79,98,115,101,114,118,101,100,32,58,61,32};
enumeration L4ieee_W12vital_timing_itn51_lit[]={59,32,65,116,32,58,32};
/* Implementation of subprogram :ieee:vital_timing:reportviolation */
void L4ieee_W12vital_timing_X15reportviolation_i234(const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X15reportviolation_i234_C14testsignalname,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X15reportviolation_i234_C13refsignalname,const L3std_Q8standard_T6string &L4ieee_W12vital_timing_X15reportviolation_i234_C9headermsg,const L4ieee_W12vital_timing_T13checkinfotype &L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo,const enumeration L4ieee_W12vital_timing_X15reportviolation_i234_C11msgseverity)
{
    vhdlaccess L4ieee_W12vital_timing_X15reportviolation_i234_V7message;
    L4ieee_W12vital_timing_X15reportviolation_i234_V7message=NULL;
    if(op_not(L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M9violation)) {
      goto rlabel;
    }
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C9headermsg,enumeration(0),0);
    switch(L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M9checkkind) {
    case 0: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+6,0),L4ieee_W12vital_timing_itn40_lit),enumeration(0),0);
     } break;
    case 1: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+5,0),L4ieee_W12vital_timing_itn41_lit),enumeration(0),0);
     } break;
    case 2: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+9,0),L4ieee_W12vital_timing_itn42_lit),enumeration(0),0);
     } break;
    case 3: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+8,0),L4ieee_W12vital_timing_itn43_lit),enumeration(0),0);
     } break;
    case 4: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+12,0),L4ieee_W12vital_timing_itn44_lit),enumeration(0),0);
     } break;
    case 5: {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+7,0),L4ieee_W12vital_timing_itn45_lit),enumeration(0),0);
     } break;
    }
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_C7hilostr[L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M5state],enumeration(0),0);
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+13,0),L4ieee_W12vital_timing_itn46_lit),enumeration(0),0);
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C14testsignalname,enumeration(0),0);
    if((L4ieee_W12vital_timing_X15reportviolation_i234_C13refsignalname.info->length>0)) {
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+16,0),L4ieee_W12vital_timing_itn47_lit),enumeration(0),0);
      L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C13refsignalname,enumeration(0),0);
    }
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+1,0),L4ieee_W12vital_timing_itn48_lit),enumeration(0),0);
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+13,0),L4ieee_W12vital_timing_itn49_lit),enumeration(0),0);
    L3std_Q6textio_X5write_i132 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M7exptime,enumeration(0),0,1000000LL);
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+13,0),L4ieee_W12vital_timing_itn50_lit),enumeration(0),0);
    L3std_Q6textio_X5write_i132 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M7obstime,enumeration(0),0,1000000LL);
    L3std_Q6textio_X5write_i126 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+6,0),L4ieee_W12vital_timing_itn51_lit),enumeration(0),0);
    L3std_Q6textio_X5write_i132 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L4ieee_W12vital_timing_X15reportviolation_i234_C9checkinfo.value().M7dettime,enumeration(0),0,1000000LL);
    if(!enumeration(0))
      report(deref<L3std_Q8standard_T6string >(L4ieee_W12vital_timing_X15reportviolation_i234_V7message),L4ieee_W12vital_timing_X15reportviolation_i234_C11msgseverity);
    L3std_Q6textio_X10deallocate_i7 (L4ieee_W12vital_timing_X15reportviolation_i234_V7message,L3std_Q6textio_I4line_INFO);
    rlabel:
    return;
}
/* Implementation of subprogram :ieee:vital_timing:internaltimingcheck */
void L4ieee_W12vital_timing_X19internaltimingcheck_i252(const enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_C10testsignal,const enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9refsignal,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9testdelay,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8refdelay,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9setuphigh,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8setuplow,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8holdhigh,const physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_C7holdlow,physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7reftime,enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7refedge,physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_V8testtime,enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9testevent,enumeration &L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen_PAR,enumeration &L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden_PAR,L4ieee_W12vital_timing_T13checkinfotype &L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo,const enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_C5msgon)
{
    enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen_PAR;
    enumeration L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden_PAR;
    physical L4ieee_W12vital_timing_X19internaltimingcheck_i252_V2b2,L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias;
    L4ieee_W12vital_timing_X19internaltimingcheck_i252_V2b2=-9223372036854775807LL;
    L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias=-9223372036854775807LL;
    if(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7refedge) {
      if(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen) {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7reftime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V8testtime);
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M5state=L4ieee_Q14std_logic_1164_Y6to_x01_i124 (L4ieee_W12vital_timing_X19internaltimingcheck_i252_C10testsignal);
        switch(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M5state) {
        case 2: {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8setuplow;
         } break;
        case 3: {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9setuphigh;
         } break;
        case 1: {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9setuphigh,L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8setuplow);
         } break;
        }
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime<L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime);
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen=enumeration(0);
      } else {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation=enumeration(0);
      }
    } else {
      if(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9testevent) {
        if(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden) {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V8testtime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7reftime);
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M5state=L4ieee_Q14std_logic_1164_Y6to_x01_i124 (L4ieee_W12vital_timing_X19internaltimingcheck_i252_C10testsignal);
          switch(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M5state) {
          case 2: {
            L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8holdhigh;
           } break;
          case 3: {
            L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_X19internaltimingcheck_i252_C7holdlow;
           } break;
          case 1: {
            L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8holdhigh,L4ieee_W12vital_timing_X19internaltimingcheck_i252_C7holdlow);
           } break;
          }
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime<L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime);
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden=op_not(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation);
        } else {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation=enumeration(0);
        }
      } else {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation=enumeration(0);
      }
    }
    if((L4ieee_W12vital_timing_X19internaltimingcheck_i252_C5msgon&&L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9violation)) {
      L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9testdelay-L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8refdelay);
      if(((L4ieee_W12vital_timing_X19internaltimingcheck_i252_V8testtime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7reftime)<=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias)) {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9checkkind=enumeration(0);
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V2b2=(9223372036854775807LL-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias);
        if((L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime<=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V2b2)) {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime+L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias);
        } else {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime=9223372036854775807LL;
        }
        if((L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime<=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V2b2)) {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime+L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias);
        } else {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=9223372036854775807LL;
        }
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7dettime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7reftime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_C8refdelay);
      } else {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M9checkkind=enumeration(1);
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7obstime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias);
        if((L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime>=0LL)) {
          L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7exptime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_V4bias);
        }
        L4ieee_W12vital_timing_X19internaltimingcheck_i252_V9checkinfo.value().M7dettime=(L4ieee_W12vital_timing_X19internaltimingcheck_i252_V8testtime-L4ieee_W12vital_timing_X19internaltimingcheck_i252_C9testdelay);
      }
    }
    rlabel:
    L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen_PAR=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V7setupen;
    L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden_PAR=L4ieee_W12vital_timing_X19internaltimingcheck_i252_V6holden;
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitaltimingdatainit */
L4ieee_Q12vital_timing_T19vitaltimingdatatype L4ieee_Q12vital_timing_Y19vitaltimingdatainit_i167()
{
    return L4ieee_Q12vital_timing_T19vitaltimingdatatype().init((&L4ieee_Q12vital_timing_I19vitaltimingdatatype_INFO)).aggregate_set(0,const_pointer(enumeration(0))).aggregate_set(1,const_pointer(enumeration(1))).aggregate_set(2,const_pointer(0LL)).aggregate_set(3,const_pointer(enumeration(0))).aggregate_set(4,const_pointer(enumeration(1))).aggregate_set(5,const_pointer(0LL)).aggregate_set(6,const_pointer(enumeration(0))).aggregate_set(7,const_pointer(((vhdlaccess)NULL))).aggregate_set(8,const_pointer(((vhdlaccess)NULL))).aggregate_set(9,const_pointer(((vhdlaccess)NULL))).aggregate_set(10,const_pointer(((vhdlaccess)NULL)));
}
/* Implementation of subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340(enumeration &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation_PAR,L4ieee_Q12vital_timing_T19vitaltimingdatatype &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata,sig_info<enumeration> *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_S10testsignal,enumeration *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R10testsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C14testsignalname,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9testdelay,sig_info<enumeration> *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_S9refsignal,enumeration *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R9refsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C13refsignalname,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8refdelay,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9setuphigh,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8setuplow,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8holdhigh,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C7holdlow,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C12checkenabled,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C13reftransition,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9headermsg,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C3xon,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C5msgon,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C11msgseverity)
{
    enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation;
    L4ieee_W12vital_timing_T13checkinfotype L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9checkinfo;
    enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9testevent,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7refedge;
    physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7testdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V6refdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V4bias;
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9checkinfo.init((&L4ieee_W12vital_timing_I13checkinfotype_INFO));
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9testevent=enumeration(0);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7refedge=enumeration(0);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7testdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9testdelay);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V6refdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8refdelay);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V4bias=-9223372036854775807LL;
    if((L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M12notfirstflag==enumeration(0))) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M8testlast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R10testsignal));
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R9refsignal));
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M12notfirstflag=enumeration(1);
    }
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7refedge=L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7reflast][L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R9refsignal))][L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C13reftransition];
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R9refsignal));
    if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7refedge) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7reftime=L3std_Q8standard_Y3now_i303 ();
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M6holden=enumeration(1);
    }
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9testevent=(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M8testlast!=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R10testsignal)));
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M8testlast=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R10testsignal));
    if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9testevent) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M8testtime=L3std_Q8standard_Y3now_i303 ();
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7setupen=enumeration(1);
    }
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation=enumeration(2);
    if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C12checkenabled) {
      L4ieee_W12vital_timing_X19internaltimingcheck_i252 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R10testsignal),(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_R9refsignal),L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7testdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V6refdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9setuphigh,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8setuplow,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C8holdhigh,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C7holdlow,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7reftime,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V7refedge,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M8testtime,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9testevent,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M7setupen,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V10timingdata.value().M6holden,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9checkinfo,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C5msgon);
      if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9checkinfo.value().M9violation) {
        if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C5msgon) {
          L4ieee_W12vital_timing_X15reportviolation_i234 (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C14testsignalname,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C13refsignalname,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C9headermsg,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9checkinfo,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C11msgseverity);
        }
        if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_C3xon) {
          L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation=enumeration(1);
        }
      }
    }
    rlabel:
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation_PAR=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i340_V9violation;
    return;
}
enumeration L4ieee_W12vital_timing_itn52_lit[]={40,46,46,46,41};
enumeration L4ieee_W12vital_timing_itn53_lit[]={40};
enumeration L4ieee_W12vital_timing_itn54_lit[]={41};
/* Implementation of subprogram :ieee:vital_timing:vitalsetupholdcheck */
void L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359(enumeration &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation_PAR,L4ieee_Q12vital_timing_T19vitaltimingdatatype &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata,sig_info<L4ieee_Q14std_logic_1164_T16std_logic_vector> *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_S10testsignal,L4ieee_Q14std_logic_1164_T16std_logic_vector *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C14testsignalname,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9testdelay,sig_info<enumeration> *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_S9refsignal,enumeration *L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R9refsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C13refsignalname,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8refdelay,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9setuphigh,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8setuplow,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8holdhigh,const physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C7holdlow,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C12checkenabled,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C13reftransition,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9headermsg,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C3xon,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C5msgon,const enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C11msgseverity)
{
    enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation;
    L4ieee_W12vital_timing_T13checkinfotype L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo;
    enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7refedge;
    L4ieee_Q12vital_timing_T15vitalboolarrayt L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9testevent;
    physical L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7testdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V6refdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V4bias;
    enumeration L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V16changedallatonce;
    vhdlaccess L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1;
    integer L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_lc,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_lc,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_lc,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_lc,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_ls;
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo.init((&L4ieee_W12vital_timing_I13checkinfotype_INFO));
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7refedge=enumeration(0);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9testevent.init((new array_info((&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->element_type,(&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0)),enumeration(0));
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7testdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9testdelay);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V6refdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8refdelay);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V4bias=-9223372036854775807LL;
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V16changedallatonce=enumeration(1);
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1=NULL;
    if((L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M12notfirstflag==enumeration(0))) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testlasta=((new array_info((&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->element_type,(&L4ieee_Q14std_logic_1164_I16std_logic_vector_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0)))->create();
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testtimea=((new array_info((&L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO)->element_type,(&L4ieee_Q12vital_timing_I15vitaltimearrayt_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0)))->create();
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7holdena=((new array_info((&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->element_type,(&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0)))->create();
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M8setupena=((new array_info((&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->element_type,(&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0)))->create();
      for (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_ls=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction==to?+1:-1,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_lc=range_to_length<integer>((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound);L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_lc!=0; L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i+=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i_lc--) {
        deref<L4ieee_Q14std_logic_1164_T16std_logic_vector >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testlasta)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i]=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5308ln_C1i]);
      }
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R9refsignal));
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M12notfirstflag=enumeration(1);
    }
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7refedge=L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7reflast][L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R9refsignal))][L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C13reftransition];
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R9refsignal));
    if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7refedge) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7reftime=L3std_Q8standard_Y3now_i303 ();
      deref<L4ieee_Q12vital_timing_T15vitalboolarrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7holdena)=L4ieee_Q12vital_timing_T15vitalboolarrayt(new array_info((&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->element_type,(&L4ieee_Q12vital_timing_I15vitalboolarrayt_INFO)->index_type,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound,0),enumeration(1));
    }
    for (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_ls=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction==to?+1:-1,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_lc=range_to_length<integer>((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound);L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_lc!=0; L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i+=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i_lc--) {
      L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9testevent[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]=(deref<L4ieee_Q14std_logic_1164_T16std_logic_vector >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testlasta)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]!=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]));
      deref<L4ieee_Q14std_logic_1164_T16std_logic_vector >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testlasta)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]);
      if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9testevent[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]) {
        deref<L4ieee_Q12vital_timing_T15vitaltimearrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testtimea)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]=L3std_Q8standard_Y3now_i303 ();
        deref<L4ieee_Q12vital_timing_T15vitalboolarrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M8setupena)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5310ln_C1i]=enumeration(1);
        L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M8testtime=L3std_Q8standard_Y3now_i303 ();
      }
    }
    for (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_ls=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction==to?+1:-1,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_lc=range_to_length<integer>((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound);L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_lc!=0; L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i+=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i_lc--) {
      if((deref<L4ieee_Q12vital_timing_T15vitaltimearrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testtimea)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5312ln_C1i]!=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M8testtime)) {
        L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V16changedallatonce=enumeration(0);
        goto exit_11;
      }
    } exit_11:; 
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation=enumeration(2);
    if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C12checkenabled) {
      for (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_ls=(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction==to?+1:-1,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_lc=range_to_length<integer>((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->index_direction,(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->right_bound);L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_lc!=0; L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i+=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_ls,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i_lc--) {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252 ((*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i],(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R9refsignal),L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7testdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V6refdly,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9setuphigh,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8setuplow,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C8holdhigh,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C7holdlow,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7reftime,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7refedge,deref<L4ieee_Q12vital_timing_T15vitaltimearrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M9testtimea)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i],L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9testevent[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i],deref<L4ieee_Q12vital_timing_T15vitalboolarrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M8setupena)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i],deref<L4ieee_Q12vital_timing_T15vitalboolarrayt >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V10timingdata.value().M7holdena)[L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i],L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C5msgon);
        if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo.value().M9violation) {
          if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C5msgon) {
            if((L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V16changedallatonce&&(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i==(*L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_R10testsignal).info->left_bound))) {
              L4ieee_W12vital_timing_X15reportviolation_i234 (concat<L3std_Q8standard_T6string,enumeration>(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C14testsignalname,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+4,0),L4ieee_W12vital_timing_itn52_lit)),L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C13refsignalname,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9headermsg,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C11msgseverity);
            } else {
              if(op_not(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V16changedallatonce)) {
                L3std_Q6textio_X5write_i115 (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_L5314ln_C1i,enumeration(0),0);
                L4ieee_W12vital_timing_X15reportviolation_i234 (concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(concat<L3std_Q8standard_T6string,enumeration>(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C14testsignalname,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn53_lit)),deref<L3std_Q8standard_T6string >(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1)),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+0,0),L4ieee_W12vital_timing_itn54_lit)),L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C13refsignalname,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C9headermsg,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9checkinfo,L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C11msgseverity);
                L3std_Q6textio_X10deallocate_i7 (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1,L3std_Q6textio_I4line_INFO);
              }
            }
          }
          if(L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_C3xon) {
            L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation=enumeration(1);
          }
        }
      }
    }
    L3std_Q6textio_X10deallocate_i7 (L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V7strptr1,L3std_Q6textio_I4line_INFO);
    rlabel:
    L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation_PAR=L4ieee_Q12vital_timing_X19vitalsetupholdcheck_i359_V9violation;
    return;
}
/* Implementation of subprogram :ieee:vital_timing:vitalrecoveryremovalcheck */
void L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377(enumeration &L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation_PAR,L4ieee_Q12vital_timing_T19vitaltimingdatatype &L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata,sig_info<enumeration> *L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_S10testsignal,enumeration *L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C14testsignalname,const physical L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9testdelay,sig_info<enumeration> *L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_S9refsignal,enumeration *L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C13refsignalname,const physical L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C8refdelay,const physical L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C8recovery,const physical L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C7removal,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9activelow,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C12checkenabled,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C13reftransition,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9headermsg,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C3xon,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C5msgon,const enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C11msgseverity)
{
    enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation;
    L4ieee_W12vital_timing_T13checkinfotype L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo;
    enumeration L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge;
    physical L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7testdly,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V6refdly,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V4bias;
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo.init((&L4ieee_W12vital_timing_I13checkinfotype_INFO));
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent=enumeration(0);
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge=enumeration(0);
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7testdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9testdelay);
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V6refdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C8refdelay);
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V4bias=-9223372036854775807LL;
    if((L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M12notfirstflag==enumeration(0))) {
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testlast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal));
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal));
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M12notfirstflag=enumeration(1);
    }
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge=L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reflast][L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal))][L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C13reftransition];
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reflast=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal));
    if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge) {
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reftime=L3std_Q8standard_Y3now_i303 ();
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M6holden=enumeration(1);
    }
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent=(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testlast!=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal)));
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testlast=L4ieee_Q14std_logic_1164_Y7to_x01z_i136 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal));
    if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent) {
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testtime=L3std_Q8standard_Y3now_i303 ();
      L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7setupen=enumeration(1);
    }
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation=enumeration(2);
    if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C12checkenabled) {
      if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9activelow) {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal),(*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal),L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7testdly,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V6refdly,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C8recovery,0LL,0LL,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C7removal,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reftime,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testtime,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7setupen,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M6holden,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C5msgon);
      } else {
        L4ieee_W12vital_timing_X19internaltimingcheck_i252 ((*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R10testsignal),(*L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_R9refsignal),L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7testdly,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V6refdly,0LL,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C8recovery,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C7removal,0LL,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7reftime,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V7refedge,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M8testtime,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9testevent,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M7setupen,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V10timingdata.value().M6holden,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C5msgon);
      }
      if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo.value().M9violation) {
        if((L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo.value().M9checkkind==enumeration(0))) {
          L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo.value().M9checkkind=enumeration(2);
        } else {
          L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo.value().M9checkkind=enumeration(3);
        }
        if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C5msgon) {
          L4ieee_W12vital_timing_X15reportviolation_i234 (L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C14testsignalname,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C13refsignalname,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C9headermsg,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9checkinfo,L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C11msgseverity);
        }
        if(L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_C3xon) {
          L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation=enumeration(1);
        }
      }
    }
    rlabel:
    L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation_PAR=L4ieee_Q12vital_timing_X25vitalrecoveryremovalcheck_i377_V9violation;
    return;
}
enumeration L4ieee_W12vital_timing_itn55_lit[]={};
enumeration L4ieee_W12vital_timing_itn56_lit[]={};
/* Implementation of subprogram :ieee:vital_timing:vitalperiodpulsecheck */
void L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391(enumeration &L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation_PAR,L4ieee_Q12vital_timing_T19vitalperioddatatype &L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata,sig_info<enumeration> *L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_S10testsignal,enumeration *L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_R10testsignal,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14testsignalname,const physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C9testdelay,const physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C6period,const physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14pulsewidthhigh,const physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C13pulsewidthlow,const enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C12checkenabled,const L3std_Q8standard_T6string &L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C9headermsg,const enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C3xon,const enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C5msgon,const enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C11msgseverity)
{
    enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation;
    physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V7testdly;
    L4ieee_W12vital_timing_T13checkinfotype L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo;
    physical L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9periodobs;
    enumeration L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue;
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V7testdly=L4ieee_W12vital_timing_Y7maximum_i51 (0LL,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C9testdelay);
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.init((&L4ieee_W12vital_timing_I13checkinfotype_INFO));
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9periodobs=-9223372036854775807LL;
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest=enumeration(0);
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest=enumeration(0);
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_R10testsignal));
    if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M12notfirstflag==enumeration(0))) {
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4rise=(-L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C6period,L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14pulsewidthhigh,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C13pulsewidthlow)));
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4fall=(-L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C6period,L4ieee_W12vital_timing_Y7maximum_i51 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14pulsewidthhigh,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C13pulsewidthlow)));
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last=L4ieee_Q14std_logic_1164_Y6to_x01_i124 ((*L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_R10testsignal));
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M12notfirstflag=enumeration(1);
    }
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation=enumeration(2);
    if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last==L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue)) {
      goto rlabel;
    }
    if(L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last][L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue][enumeration(2)]) {
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9periodobs=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4rise);
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4rise=L3std_Q8standard_Y3now_i303 ();
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest=enumeration(1);
    } else {
      if(L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last][L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue][enumeration(3)]) {
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9periodobs=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4fall);
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4fall=L3std_Q8standard_Y3now_i303 ();
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest=enumeration(1);
      } else {
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest=enumeration(0);
      }
    }
    if(L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last][L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue][enumeration(6)]) {
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7obstime=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4fall);
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7exptime=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C13pulsewidthlow;
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest=enumeration(1);
    } else {
      if(L4ieee_W12vital_timing_C15edgesymbolmatch[L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last][L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue][enumeration(7)]) {
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7obstime=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4rise);
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7exptime=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14pulsewidthhigh;
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest=enumeration(1);
      } else {
        L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest=enumeration(0);
      }
    }
    if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9pulsetest&&L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C12checkenabled)) {
      if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7obstime<L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7exptime)) {
        if(L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C3xon) {
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation=enumeration(1);
        }
        if(L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C5msgon) {
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M9violation=enumeration(1);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M9checkkind=enumeration(4);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7dettime=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V7testdly);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M5state=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last;
          L4ieee_W12vital_timing_X15reportviolation_i234 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14testsignalname,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+-1,0),L4ieee_W12vital_timing_itn55_lit),L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C9headermsg,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C11msgseverity);
        }
      }
    }
    if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10periodtest&&L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C12checkenabled)) {
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7obstime=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9periodobs;
      L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7exptime=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C6period;
      if((L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7obstime<L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7exptime)) {
        if(L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C3xon) {
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation=enumeration(1);
        }
        if(L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C5msgon) {
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M9violation=enumeration(1);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M9checkkind=enumeration(5);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M7dettime=(L3std_Q8standard_Y3now_i303 ()-L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V7testdly);
          L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo.value().M5state=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue;
          L4ieee_W12vital_timing_X15reportviolation_i234 (L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C14testsignalname,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,1+-1,0),L4ieee_W12vital_timing_itn56_lit),L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C9headermsg,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9checkinfo,L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_C11msgseverity);
        }
      }
    }
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V10perioddata.value().M4last=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9testvalue;
    rlabel:
    L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation_PAR=L4ieee_Q12vital_timing_X21vitalperiodpulsecheck_i391_V9violation;
    return;
}
/* Initialization function for package body :ieee:vital_timing */
int L4ieee_Q12vital_timing_init ();
int L3std_Q8standard_init ();
int L3std_Q6textio_init ();
bool L4ieee_W12vital_timing_init_done = false;
int L4ieee_W12vital_timing_init(){
if (L4ieee_W12vital_timing_init_done) return 1;
L4ieee_W12vital_timing_init_done=true;
L4ieee_Q12vital_timing_init ();
L3std_Q8standard_init ();
L3std_Q6textio_init ();
register_source_file("/home/stefan/cvs-local/freehdl-teaser/ieee/vital_timing.vhdl","vital_timing.vhdl");
name_stack iname;
iname.push("");
void *sref=register_package_body(":ieee",":vital_timing");
L4ieee_W12vital_timing_I9checktype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:checktype",":CheckType",NULL);
L4ieee_W12vital_timing_I13checkinfotype_INFO.set(6,sizeof(L4ieee_W12vital_timing_T13checkinfotype_DATA),L4ieee_W12vital_timing_T13checkinfotype_NAMES,L4ieee_W12vital_timing_T13checkinfotype_ELEM_ADDR,-1).set(0,(&L3std_Q8standard_I7boolean_INFO)).set(1,(&L4ieee_W12vital_timing_I9checktype_INFO)).set(2,(&L3std_Q8standard_I4time_INFO)).set(3,(&L3std_Q8standard_I4time_INFO)).set(4,(&L3std_Q8standard_I4time_INFO)).set(5,(&L4ieee_Q14std_logic_1164_I3x01_INFO)).register_type(":ieee:vital_timing",":ieee:vital_timing:checkinfotype",":CheckInfoType",NULL);
L4ieee_W12vital_timing_I17logiccvttabletype_INFO.set((&L3std_Q8standard_I9character_INFO),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(0),to,enumeration(8),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:logiccvttabletype",":LogicCvtTableType",NULL);
L4ieee_W12vital_timing_I11hilostrtype_INFO.set((new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,4,-1)),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(1),to,enumeration(3),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:hilostrtype",":HiLoStrType",NULL);
L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO.set((new array_info((new array_info((&L3std_Q8standard_I7boolean_INFO),(&L4ieee_Q12vital_timing_I20vitaltablesymboltype_INFO),enumeration(0),to,enumeration(15),-1)),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(1),to,enumeration(3),-1)),(&L4ieee_Q14std_logic_1164_I10std_ulogic_INFO),enumeration(1),to,enumeration(3),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:edgesymbolmatchtype",":EdgeSymbolMatchType",NULL);
L4ieee_W12vital_timing_I14vitalerrortype_INFO.register_type(":ieee:vital_timing",":ieee:vital_timing:vitalerrortype",":VitalErrorType",NULL);
L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO.set((&L3std_Q8standard_I14severity_level_INFO),(&L4ieee_W12vital_timing_I14vitalerrortype_INFO),enumeration(0),to,enumeration(3),-1).register_type(":ieee:vital_timing",":ieee:vital_timing:vitalerrorseveritytype",":VitalErrorSeverityType",NULL);
L4ieee_W12vital_timing_I3_t1_INFO.set((&L3std_Q8standard_I6string_INFO)->element_type,parray_info((&L3std_Q8standard_I6string_INFO))->index_type,1,to,63,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:_t1",":_t1",NULL);
L4ieee_W12vital_timing_I3_t2_INFO.set((&L3std_Q8standard_I6string_INFO)->element_type,parray_info((&L3std_Q8standard_I6string_INFO))->index_type,1,to,71,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:_t2",":_t2",NULL);
L4ieee_W12vital_timing_I3_t3_INFO.set((&L3std_Q8standard_I6string_INFO)->element_type,parray_info((&L3std_Q8standard_I6string_INFO))->index_type,1,to,66,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:_t3",":_t3",NULL);
L4ieee_W12vital_timing_I3_t4_INFO.set((&L3std_Q8standard_I6string_INFO)->element_type,parray_info((&L3std_Q8standard_I6string_INFO))->index_type,1,to,34,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:_t4",":_t4",NULL);
L4ieee_W12vital_timing_I3_t5_INFO.set((&L3std_Q8standard_I6string_INFO)->element_type,parray_info((&L3std_Q8standard_I6string_INFO))->index_type,1,to,22,-1).register_type(":ieee:vital_timing",":ieee:vital_timing:_t5",":_t5",NULL);
L4ieee_W12vital_timing_C13logiccvttable.init((&L4ieee_W12vital_timing_I17logiccvttabletype_INFO),enumeration(0));
L4ieee_W12vital_timing_C13logiccvttable=L4ieee_W12vital_timing_T17logiccvttabletype(new array_info((&L4ieee_W12vital_timing_I17logiccvttabletype_INFO)->element_type,(&L4ieee_W12vital_timing_I17logiccvttabletype_INFO)->index_type,enumeration(0),to,enumeration(0)+8,0),enumeration(85)).aggregate_set(enumeration(0)+1,to,enumeration(0)+1,enumeration(88)).aggregate_set(enumeration(0)+2,to,enumeration(0)+2,enumeration(48)).aggregate_set(enumeration(0)+3,to,enumeration(0)+3,enumeration(49)).aggregate_set(enumeration(0)+4,to,enumeration(0)+4,enumeration(90)).aggregate_set(enumeration(0)+5,to,enumeration(0)+5,enumeration(87)).aggregate_set(enumeration(0)+6,to,enumeration(0)+6,enumeration(76)).aggregate_set(enumeration(0)+7,to,enumeration(0)+7,enumeration(72)).aggregate_set(enumeration(0)+8,to,enumeration(0)+8,enumeration(45));
L4ieee_W12vital_timing_C7hilostr.init((&L4ieee_W12vital_timing_I11hilostrtype_INFO));
L4ieee_W12vital_timing_C7hilostr=L4ieee_W12vital_timing_T11hilostrtype(new array_info((&L4ieee_W12vital_timing_I11hilostrtype_INFO)->element_type,(&L4ieee_W12vital_timing_I11hilostrtype_INFO)->index_type,enumeration(1),to,enumeration(1)+2,0),array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,4,0),L4ieee_W12vital_timing_itn13_lit)).aggregate_set(enumeration(1)+1,to,enumeration(1)+1,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,4,0),L4ieee_W12vital_timing_itn14_lit)).aggregate_set(enumeration(1)+2,to,enumeration(1)+2,array_alias<L3std_Q8standard_T6string >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,4,0),L4ieee_W12vital_timing_itn15_lit));
L4ieee_W12vital_timing_C15edgesymbolmatch.init((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO));
L4ieee_W12vital_timing_C15edgesymbolmatch=L4ieee_W12vital_timing_T19edgesymbolmatchtype(new array_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type,(&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->index_type,1,to,3,0),L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type(new array_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type,parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->index_type,1,to,3,0),L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0))).aggregate_set(2,to,2,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(3,to,3,enumeration(1)).aggregate_set(9,to,9,enumeration(1)).aggregate_set(11,to,11,enumeration(1)).aggregate_set(12,to,12,enumeration(1)).aggregate_set(14,to,14,enumeration(1)).aggregate_set(15,to,15,enumeration(1))).aggregate_set(3,to,3,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(2,to,2,enumeration(1)).aggregate_set(8,to,8,enumeration(1)).aggregate_set(10,to,10,enumeration(1)).aggregate_set(12,to,12,enumeration(1)).aggregate_set(13,to,13,enumeration(1)).aggregate_set(15,to,15,enumeration(1)))).aggregate_set(2,to,2,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type(new array_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type,parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->index_type,1,to,3,0),L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(4,to,4,enumeration(1)).aggregate_set(6,to,6,enumeration(1)).aggregate_set(8,to,8,enumeration(1)).aggregate_set(13,to,13,enumeration(1)).aggregate_set(15,to,15,enumeration(1))).aggregate_set(2,to,2,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0))).aggregate_set(3,to,3,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(0,to,0,enumeration(1)).aggregate_set(2,to,2,enumeration(1)).aggregate_set(6,to,6,enumeration(1)).aggregate_set(8,to,8,enumeration(1)).aggregate_set(15,to,15,enumeration(1)))).aggregate_set(3,to,3,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type(new array_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type,parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->index_type,1,to,3,0),L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(5,to,5,enumeration(1)).aggregate_set(7,to,7,enumeration(1)).aggregate_set(9,to,9,enumeration(1)).aggregate_set(14,to,14,enumeration(1)).aggregate_set(15,to,15,enumeration(1))).aggregate_set(2,to,2,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0)).aggregate_set(1,to,1,enumeration(1)).aggregate_set(3,to,3,enumeration(1)).aggregate_set(7,to,7,enumeration(1)).aggregate_set(9,to,9,enumeration(1)).aggregate_set(15,to,15,enumeration(1))).aggregate_set(3,to,3,L4ieee_W12vital_timing_T19edgesymbolmatchtype::E_type::E_type(new array_info(parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->element_type,parray_info(parray_info((&L4ieee_W12vital_timing_I19edgesymbolmatchtype_INFO)->element_type)->element_type)->index_type,enumeration(0),to,enumeration(15),0),enumeration(0))));
L4ieee_W12vital_timing_C18vitalerrorseverity.init((&L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO),enumeration(0));
L4ieee_W12vital_timing_C18vitalerrorseverity=L4ieee_W12vital_timing_T22vitalerrorseveritytype(new array_info((&L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO)->element_type,(&L4ieee_W12vital_timing_I22vitalerrorseveritytype_INFO)->index_type,0,to,3,0),enumeration(2)).aggregate_set(1,to,1,enumeration(1)).aggregate_set(2,to,2,enumeration(1)).aggregate_set(3,to,3,enumeration(1));
L4ieee_W12vital_timing_C9msgnopath.init((&L4ieee_W12vital_timing_I3_t1_INFO),enumeration(0));
L4ieee_W12vital_timing_C9msgnopath=array_alias<L4ieee_W12vital_timing_T3_t1 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,63,0),L4ieee_W12vital_timing_itn16_lit);
L4ieee_W12vital_timing_C10msgnegpath.init((&L4ieee_W12vital_timing_I3_t2_INFO),enumeration(0));
L4ieee_W12vital_timing_C10msgnegpath=array_alias<L4ieee_W12vital_timing_T3_t2 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,71,0),L4ieee_W12vital_timing_itn17_lit);
L4ieee_W12vital_timing_C9msgnegdel.init((&L4ieee_W12vital_timing_I3_t3_INFO),enumeration(0));
L4ieee_W12vital_timing_C9msgnegdel=array_alias<L4ieee_W12vital_timing_T3_t3 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,66,0),L4ieee_W12vital_timing_itn18_lit);
L4ieee_W12vital_timing_C9msgvctlng.init((&L4ieee_W12vital_timing_I3_t4_INFO),enumeration(0));
L4ieee_W12vital_timing_C9msgvctlng=array_alias<L4ieee_W12vital_timing_T3_t4 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,34,0),L4ieee_W12vital_timing_itn19_lit);
L4ieee_W12vital_timing_C10msgunknown.init((&L4ieee_W12vital_timing_I3_t5_INFO),enumeration(0));
L4ieee_W12vital_timing_C10msgunknown=array_alias<L4ieee_W12vital_timing_T3_t5 >(new array_info((&L3std_Q8standard_I6string_INFO)->element_type,(&L3std_Q8standard_I6string_INFO)->index_type,1,to,22,0),L4ieee_W12vital_timing_itn20_lit);
iname.pop();
return 1;
}
/* handle for simulator to find package body initialization function */
handle_info *L4ieee_W12vital_timing_hinfo =
  add_handle("ieee","vital_timing",NULL,NULL,&L4ieee_W12vital_timing_init);

/* end of package body :ieee:vital_timing */
