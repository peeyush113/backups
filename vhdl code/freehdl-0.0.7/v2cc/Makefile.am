## -*- makefile -*-
## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir) -DDEFAULT_V2CC_LIBRARY_DIR=\"$(prefix)/share/freehdl/lib\"
GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)

bin_SCRIPTS = gvhdl
dist_noinst_SCRIPTS = gvhdl-local
bin_PROGRAMS = freehdl-v2cc
noinst_PROGRAMS = test-mapper

if MAINTAINER_MODE
CHUNK_H = v2cc-chunk.h
CHUNK_CC = v2cc-chunk.cc

BUILT_SOURCES = v2cc-chunk.h v2cc-chunk.cc

# rules for tree generation

$(CHUNK_H): %-chunk.h: %-chunk.t $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header $* $< $@

$(CHUNK_CC): %-chunk.cc: %-chunk.t $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl $* $< $@

v2cc-chunk.h v2cc-chunk.cc: $(top_srcdir)/freehdl/fire-chunk.t
v2cc-chunk.h v2cc-chunk.cc: $(top_srcdir)/freehdl/vaul-chunk.t
endif

freehdl_v2cc_SOURCES = v2cc.h v2cc.cc v2cc-chunk.h v2cc-chunk.cc mapping.h \
  mapping.cc v2cc-explore.cc v2cc-util.h v2cc-util.cc v2cc-const-fold.cc   \
  v2cc-decl.cc v2cc-expr.cc v2cc-cdfg-expr.cc v2cc-impl.cc v2cc-acl.cc     \
  v2cc-qid.cc v2cc-get-type-info.cc v2cc-cdfg-static-expr.cc               \
  v2cc-cdfg-impl.cc v2cc-optimize.cc

freehdl_v2cc_LDADD = ../vaul/libfreehdl-vaul.la ../fire/libfreehdl-fire.la $(GETOPTLIBS)

test_mapper_SOURCES = test-mapper.cc mapping.cc mapping.h

EXTRA_DIST = v2cc-chunk.t gvhdl.in HACKING.v2cc x.vhdl y.vhdl z.vhdl \
  adder.vhdl error.vhdl model.vhdl model4.vhdl model5.vhdl top.vhdl

CLEANFILES = *~
DISTCLEANFILES = gvhdl
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
