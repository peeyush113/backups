INCLUDES = -I$(top_srcdir) -I..

lib_LTLIBRARIES = libfreehdl-std.la

libfreehdl_std_la_SOURCES = memory.cc \
			    vhdl_types.cc \
			    internal_textio.cc \
                            standard.cc 

stddir = $(prefix)/share/freehdl/lib/std
std_DATA = standard.vhdl \
           textio.vhdl

EXTRA_DIST = $(std_DATA)

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in
