## -*- makefile -*-
## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir) -I..
GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)

EXTRA_DIST = timeval.h

lib_LTLIBRARIES = libfreehdl-fire.la
noinst_PROGRAMS = test-fire

libfreehdl_fire_la_SOURCES = fire-chunk.cc	\
	                     fire-types.cc	\
                             tree-supp.cc

libfreehdl_fire_la_LDFLAGS = -version-info 0:0

test_fire_SOURCES = test-fire.cc
test_fire_LDADD = libfreehdl-fire.la

if MAINTAINER_MODE
# rules for tree generation

fire-chunk.cc: $(top_srcdir)/freehdl/fire-chunk.t $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl fire $< $@

BUILT_SOURCES = fire-chunk.cc
endif

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
