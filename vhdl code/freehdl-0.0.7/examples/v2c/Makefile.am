## -*- makefile -*-
## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir) -I../..

noinst_PROGRAMS = v2c
v2c_SOURCES = v2c.cc v2c-chunk.h v2c-chunk.cc
v2c_LDADD = ../../vaul/libfreehdl-vaul.la ../../fire/libfreehdl-fire.la

if MAINTAINER_MODE
CHUNK_H = v2c-chunk.h
CHUNK_CC = v2c-chunk.cc

BUILT_SOURCES = v2c-chunk.h v2c-chunk.cc

# rules for tree generation

GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)

$(CHUNK_H): %-chunk.h: %-chunk.t $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header $* $< $@

$(CHUNK_CC): %-chunk.cc: %-chunk.t $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl $* $< $@

v2c-chunk.h v2c-chunk.cc: $(top_srcdir)/freehdl/fire-chunk.t
v2c-chunk.h v2c-chunk.cc: $(top_srcdir)/freehdl/vaul-chunk.t
endif

EXTRA_DIST = v2c-chunk.t

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
