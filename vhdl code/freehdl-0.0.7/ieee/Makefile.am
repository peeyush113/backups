## -*- makefile -*-
## Process this file with automake to produce Makefile.in
SUFFIXES = .vhdl

INCLUDES = -I $(top_srcdir) -I ..

ieeedir = $(prefix)/share/freehdl/lib/ieee
freehdllibdir = $(libdir)/freehdl

freehdllib_LTLIBRARIES = libieee.la
libieee_la_SOURCES = std_logic_1164.cc numeric_std.cc numeric_bit.cc std_logic_signed.cc std_logic_unsigned.cc std_logic_arith.cc math_real.cc vital_timing.cc

ieee_DATA = std_logic_1164.vhdl numeric_std.vhdl numeric_bit.vhdl std_logic_signed.vhdl std_logic_unsigned.vhdl std_logic_arith.vhdl math_real.vhdl vital_timing.vhdl

BUILT_SOURCES = $(libieee_la_SOURCES)

.vhdl.cc:
	../v2cc/freehdl-v2cc -lieee -L $(top_srcdir) $< >$@.tmp && mv $@.tmp $@

if MAINTAINER_MODE
$(BUILT_SOURCES): ../v2cc/freehdl-v2cc
endif

EXTRA_DIST = $(ieee_DATA)

MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
