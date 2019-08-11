## Process this file with automake to produce Makefile.in

bin_SCRIPTS = freehdl-config freehdl-gennodes

freehdldir = $(includedir)/freehdl
freehdl_HEADERS  = fire-types.h			\
                   fire-chunk.t			\
                   fire-chunk.h			\
                   tree-supp.h			\
                   fire.h			\
                   vaul-creator-base.h		\
                   vaul-dfile.h			\
                   vaul-dunit.h			\
                   vaul-dynarray.h		\
                   vaul-errors.h		\
                   vaul-lexer.h			\
                   vaul-list.h			\
		   vaul-mempool.h		\
		   vaul-parser.h		\
                   vaul-pool.h			\
                   vaul-printer.h		\
                   vaul-ref.h			\
                   vaul-types.h			\
                   vaul-util.h			\
                   vaul-chunk.t			\
                   vaul-chunk.h			\
                   vaul.h			\
		   FlexLexer.h			\
		   cdfggen-chunk.t		\
		   cdfggen-chunk.h		\
		   kernel-acl.hh		\
		   kernel-classes.hh		\
		   kernel-driver-info.hh	\
		   kernel-error.hh		\
		   kernel-flags.hh		\
		   kernel-global-event-queue.hh	\
		   kernel-handle-info.hh	\
		   kernel-handle.hh		\
		   kernel-kernel-class.hh	\
		   kernel-list.hh		\
		   kernel-map-list.hh		\
		   kernel-name-stack.hh		\
		   kernel-pcounter.hh		\
		   kernel-process-base.hh	\
		   kernel-delayed-procedure-base.hh	\
		   kernel-reader-info.hh	\
		   kernel-sig-info.hh		\
		   kernel-sigacl-list.hh	\
		   kernel-wait-info.hh		\
		   kernel-winfo-item.hh		\
		   kernel-attributes.hh		\
		   kernel-dump.hh		\
		   kernel-util.hh		\
		   kernel-fhdl-stream.hh	\
		   kernel-register.hh		\
		   kernel-resolver-process.hh	\
		   kernel-resolver-descriptor.hh	\
		   kernel-source-descriptor.hh	\
		   kernel-signal-source-list-array.hh	\
		   kernel-persistent-dump.hh		\
		   kernel-persistent-cdfg-dump.hh	\
		   kernel-Xinfo-kind.hh		\
		   kernel-Xinfo-data-descriptor.hh	\
		   kernel-stack-trace.hh		\
		   kernel-db.hh			\
                   kernel.h			\
		   std-memory.hh		\
                   std-standard.hh		\
                   std-vhdl-types.hh		\
                   std.h

GENNODES = $(srcdir)/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)
FIRE_T = fire-chunk.t
VAUL_T = vaul-chunk.t
CDFGGEN_T = cdfggen-chunk.t

if MAINTAINER_MODE
fire-chunk.h: $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header fire $< $@

vaul-chunk.h: $(VAUL_T) $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header vaul $< $@

cdfggen-chunk.h: $(CDFGGEN_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header cdfggen $< $@

BUILT_SOURCES = fire-chunk.h vaul-chunk.h cdfggen-chunk.h FlexLexer.h
endif

FlexLexer.h: $(top_srcdir)/vaul/FlexLexer.h
	cp $< $@

freehdl-gennodes: freehdl-gennodes.in
	sed -e 's,@DEFAULT_INCLUDE_PATH@,$(includedir),g' <$< >$@
	chmod a+x $@

EXTRA_DIST = freehdl-gennodes.in freehdl-config

CLEANFILES = *~
DISTCLEANFILES = freehdl-gennodes FlexLexer.h
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
