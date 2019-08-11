## -*- makefile -*-
## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir) -I..
GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)

lib_LTLIBRARIES = libfreehdl-cdfggen.la

libfreehdl_cdfggen_la_SOURCES = cdfggen-chunk.cc

CHUNK_CC = cdfggen-chunk.cc

BUILT_SOURCES = cdfggen-chunk.cc

libfreehdl_cdfggen_la_LDFLAGS = -version-info 0:0

if MAINTAINER_MODE
# rules for tree generation

CDFGGEN_T = $(top_srcdir)/freehdl/cdfggen-chunk.t

cdfggen-chunk.cc: $(CDFGGEN_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl cdfggen $< $@
endif

EXTRA_DIST = 
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
