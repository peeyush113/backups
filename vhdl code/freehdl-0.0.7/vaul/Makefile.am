## -*- makefile -*-
## Process this file with automake to produce Makefile.in

INCLUDES = -I$(top_srcdir) -I..
YPROTO = '^.*yyparse (.*);$$'
GENNODES = $(top_srcdir)/freehdl/freehdl-gennodes
GENNODES_FLAGS = -I $(top_srcdir)

lib_LTLIBRARIES = libfreehdl-vaul.la

libfreehdl_vaul_la_SOURCES = attr.cc		\
			     blocks.cc		\
			     decls.cc		\
			     dfile.cc		\
			     dunit.cc		\
			     error.cc		\
			     expr.cc		\
                             fold.cc            \
			     lexer.cc		\
			     list.cc		\
			     mempool.cc		\
			     message.cc		\
			     bison-parser.yy	\
			     printer.cc		\
			     ref.cc		\
	 		     stats.cc		\
			     subprogs.cc	\
			     tree.cc		\
			     types.cc		\
			     version.cc		\
			     pool.cc		\
			     vaul-chunk.cc	\
                             vaulgens-chunk.h   \
	                     vaulgens-chunk.cc	\
		             aprintf.cc		\
			     vaprintf.cc	\
			     xmalloc.cc		\
	                     xrealloc.cc	\
	                     xstrdup.cc		\
	                     fatal.cc		\
	                     vfatal.cc		\
			     FlexLexer.h	\
	                     bison-parser.h	\
	                     debug.h

libfreehdl_vaul_la_LDFLAGS = -version-info 0:0

if MAINTAINER_MODE
lexer.cc: lexer.ll
	$(LEX) -o$@ $<

bison-parser.cc: bison-parser.yy
	$(YACC) -v -o $@ --defines=$*.h $< && \
	mv $@ tmp.cc && grep -v $(YPROTO) < tmp.cc > $@ && rm -f tmp.cc

bison-parser.h: bison-parser.cc
endif

if MAINTAINER_MODE
CHUNK_H = vaulgens-chunk.h
CHUNK_CC = vaul-chunk.cc vaulgens-chunk.cc

BUILT_SOURCES = bison-parser.cc bison-parser.h lexer.cc	\
                $(CHUNK_CC) $(CHUNK_H)

# rules for tree generation

FIRE_T = $(top_srcdir)/freehdl/fire-chunk.t
VAUL_T = $(top_srcdir)/freehdl/vaul-chunk.t
VAULGENS_T = vaulgens-chunk.t

vaul-chunk.cc: $(VAUL_T) $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl vaul $< $@

vaulgens-chunk.h: $(VAULGENS_T) $(VAUL_T) $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) header vaulgens $< $@

vaulgens-chunk.cc: $(VAULGENS_T) $(VAUL_T) $(FIRE_T) $(GENNODES)
	$(GENNODES) $(GENNODES_FLAGS) impl vaulgens $< $@
endif

EXTRA_DIST = vaulgens-chunk.t bison-parser.h lexer.ll

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in $(BUILT_SOURCES)
