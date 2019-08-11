
#
# Makefile for Linux/UNIX
#
# This Makefile is targeted for UNIX make, not GNU make.
# On many Linux systems GNU make is the default, rather
# than BSD made.  To run this Makefile use "pmake" on
# Linux.
#
# Before running the Makefile for the first time, enter
#
#    pmake depend
#
# to build the "dependencies" include file.
#
# To build the VHDL compiler objects simply type pmake.
#

CC        = g++
DEBUG     = -g
EXCEPT	  = 
INCLUDE = -Iinclude
MISL      = -fcheck-new
CFLAGS    = $(INCLUDE) $(DEBUG) $(EXCEPT) $(MISL)
OBJ       = o
CEE       = C
EXE       = 
DOXYPATH = 
DOXY_CONFIG = doxygenTemplate


MAIN_SRC  = main/globals.$(CEE) main/main.$(CEE)
MEM_SRC   = mem/bigblock.$(CEE) mem/blockpool.$(CEE)
SKEL_SRC  = skel/hash_serv.$(CEE) skel/output.$(CEE)
SYM_SRC   = sym/strtable.$(CEE) sym/sym.$(CEE) sym/type.$(CEE) sym/typetable.$(CEE) sym/symtable.$(CEE)

VHDL_SRC = $(MAIN_SRC) $(MEM_SRC) $(SKEL_SRC) $(SYM_SRC)

FILTER_SRC = globals.$(CEE) Logger.$(CEE) SpamUtil.$(CEE) SpamParameters.$(CEE) MailFilter.$(CEE) MailHeader.$(CEE) MailBody.$(CEE) HeaderInfo.$(CEE) main.$(CEE)

MAIN_OBJ  = globals.$(OBJ) main.$(OBJ)
MEM_OBJ   = bigblock.$(OBJ) blockpool.$(OBJ)
SKEL_OBJ  = hash_serv.$(OBJ) output.$(OBJ)
SYM_OBJ   = strtable.$(OBJ) sym.$(OBJ) type.$(OBJ) typetable.$(OBJ) symtable.$(OBJ)

VHDL_OBJ = $(MAIN_OBJ) $(MEM_OBJ) $(SKEL_OBJ) $(SYM_OBJ)

all: vhdl_test

clean:
	rm -f *.o *~

doxygen:
	$(DOXYPATH)/doxygen $(DOXY_CONFIG)

depend:
	rm -f dependencies
	mkdep -f dependencies $(INCLUDE) $(VHDL_SRC)

vhdl_test: $(VHDL_OBJ)
	$(CC) $(VHDL_OBJ) $(DEBUG) $(EXCEPT) -o $@

.sinclude "dependencies"
