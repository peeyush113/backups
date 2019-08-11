## -*- makefile -*-
## Process this file with automake to produce Makefile.in

info_TEXINFOS = fire.texi
fire_TEXINFOS = fireref.texi

dist_man_MANS = freehdl-v2cc.1 gvhdl.1 v2cc.libs.5 freehdl-config.1 \
	freehdl-gennodes.1

GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)
FIRE_T = $(top_srcdir)/freehdl/fire-chunk.t

if MAINTAINER_MODE
fireref.texi: fireref.texi.in $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) <$< doc fire $(FIRE_T) $@
endif

EXTRA_DIST = VHDL93.bnf gen-nodes.grammar fireref.texi.in

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in
