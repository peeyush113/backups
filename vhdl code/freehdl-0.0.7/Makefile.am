## Process this file with automake to produce Makefile.in

EXTRA_DIST = README.gen-nodes README.vaul README.libraries README.AIRE README.v2cc v2cc.libs HACKING

SUBDIRS = freehdl fire vaul kernel std v2cc doc examples ieee FHDLgui cdfggen

snap:
	$(MAKE) distdir="$(PACKAGE)-`date +%Y%m%d`" dist

# TESTS = test-leon

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = freehdl.pc

CLEANFILES = *~
MAINTAINERCLEANFILES = Makefile.in
