dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.57)
AC_INIT(freehdl,0.0.7,edwin@ds.e-technik.uni-dortmund.de)
AC_CONFIG_SRCDIR([freehdl/fire-chunk.t])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([no-define])
AM_MAINTAINER_MODE
AC_PREFIX_DEFAULT([/usr/local])
test "x$prefix" = xNONE && prefix="/usr/local"

dnl Checks for programs.
AC_LIBTOOL_WIN32_DLL
AC_PROG_LIBTOOL
AC_PROG_CC
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_YACC
AM_PROG_LEX

AC_PATH_PROG(PERL, perl, :)
if test "$PERL" = ":"; then
  AC_MSG_ERROR([The $PACKAGE package needs a Perl.])
fi

AC_PATH_PROG(PKGCONFIG, pkg-config, :)
if test "$PKGCONFIG" = ":"; then
  AC_MSG_ERROR([The $PACKAGE package requires PKG-Config.])
fi

AC_CHECK_TOOLS([SYSTEM_LIBTOOL], [glibtool libtool], :)
if test "$SYSTEM_LIBTOOL" = ":"; then
  AC_MSG_ERROR([The $PACKAGE package requires an installed Libtool.])
fi
AC_SUBST(SYSTEM_LIBTOOL)

if test $USE_MAINTAINER_MODE = yes; then
  AC_PATH_PROG(GUILE, guile, :)
  if test "$GUILE" = ":"; then
    AC_MSG_ERROR([The $PACKAGE package requires a Guile.])
  fi
fi

dnl check for header files
AC_LANG_PUSH(C++)
AC_CHECK_HEADERS(FlexLexer.h)
AC_LANG_POP
AC_CHECK_HEADERS(execinfo.h malloc.h getopt.h)

dnl Check for machine architecture features
AC_C_BIGENDIAN
AC_CHECK_SIZEOF(int)

dnl Checks for functions
AC_CHECK_FUNCS(vasprintf)
AC_FUNC_ALLOCA
AC_CHECK_FUNCS(socket gettimeofday)

AC_CHECK_FUNC(regcomp, ,
  AC_CHECK_LIB(regex, regcomp, REGEXLIBS="-lregex"))
AC_SUBST(REGEXLIBS)
case $host_os in
mingw*)
  REGEXDEFS="-D__REGEX_IMPORT__"
  ;;
esac
AC_SUBST(REGEXDEFS)

dnl Solaris special.
case $host_os in
solaris*)
  GETOPTLIBS="`gcc --print-file-name=libiberty.a 2>/dev/null`"
  ;;
esac
AC_SUBST(GETOPTLIBS)

AC_OUTPUT(Makefile
          freehdl/Makefile
	  fire/Makefile
          vaul/Makefile
	  kernel/Makefile
          std/Makefile
          v2cc/Makefile
          doc/Makefile
          ieee/Makefile
	  FHDLgui/Makefile
	  FHDLgui/pictures/Makefile
	  examples/Makefile
	  examples/v2c/Makefile
	  cdfggen/Makefile
	  v2cc/gvhdl
	  freehdl.pc)

dnl Print results.
AC_MSG_RESULT([])
AC_MSG_RESULT([ $PACKAGE version $VERSION configured successfully.])
AC_MSG_RESULT([])
