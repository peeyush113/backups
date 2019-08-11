
#ifndef STDTYPES_H
#define STDTYPES_H

/* These rather convoluted ifndef's are required because both FALSE,
   TRUE and BOOLEAN are defined by various windows and windows/nt
   headers.  When these headers are included, a redefine error results
   without these ifndefs.  
*/

  typedef enum {
#ifndef FALSE
                 FALSE = 0, 
#endif
#ifndef TRUE
                 TRUE = 1,
#endif 
                 BOGUS} BoolVals;

typedef int Boolean;

typedef unsigned short int ushort;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef char * pChar;

#define LOCAL static

#endif
