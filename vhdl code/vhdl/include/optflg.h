
#ifndef OPTFLG_H
#define OPTFLG_H


/*===============================<o>=====================================

Copyright 1996, 1997, 2004 Ian Kaplan, Bear Products International,
www.bearcave.com.

All Rights Reserved

You may use this software in software components for which you do
not collect money (e.g., non-commercial software).  All commercial
use is reserved.

===============================<o>=====================================*/



typedef enum { bad_option =   0x0,
	       unused1 =      0x00000001,
	       unused2 =      0x00000002,
	       unused3 =      0x00000004,
	       unused4 =      0x00000008,
               unused5 =      0x00000010,
               unused6 =      0x00000020,
               unused7 =      0x00000040,
               unused8 =      0x00000080,
               unused9 =      0x00000100,
               unused10 =     0x00000200,
               unused11 =     0x00000400,
               unused12 =     0x00000800,
               unused13 =     0x00001000,
               unused14 =     0x00002000,
               unused15 =     0x00004000,
               unused16 =     0x00008000,
               unused17 =     0x00010000,
               unused18 =     0x00020000,
               unused19 =     0x00040000,
               unused20 =     0x00080000,
               unused21 =     0x00100000,
               unused22 =     0x00200000,
               unused23 =     0x00400000,
               unused24 =     0x00800000,
               unused25 =     0x01000000,
               unused26 =     0x02000000,
               unused27 =     0x04000000,
               unused28 =     0x08000000,
               unused29 =     0x10000000,
               unused30 =     0x20000000,
               unused31 =     0x40000000,
	       last_option } VHDL_OPTIONS;

/**
  The option_flags class maintains a bit-vector of
  option flags.  These options are set during 
  command line processing and can be globally
  referenced throughout the program.

  The flags that can be represented by this class
  are boolean in nature (e.g., something is either
  on or off).  
 */
class option_flags {
private:
    VHDL_OPTIONS comm_line_opt;

public:
    option_flags(void) { comm_line_opt = bad_option; }
    void set_opt( VHDL_OPTIONS opt ) 
    { 
	comm_line_opt = (VHDL_OPTIONS)((unsigned int)comm_line_opt | (unsigned int)opt); 
    }
    Boolean is_set( VHDL_OPTIONS opt )     { return (comm_line_opt & opt) != 0; }
};

extern option_flags optflgs;


#endif
