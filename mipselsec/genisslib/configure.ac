AC_INIT([UNISIM GENISSLIB], [3.0.2], [Gilles Mouchard <gilles.mouchard@cea.fr>, Yves  Lhuillier <yves.lhuillier@cea.fr>], [genisslib])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([subdir-objects tar-pax])
AC_PATH_PROGS(SH, sh)
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_LANG([C++])
AC_CHECK_HEADERS([cassert cctype cerrno cstdarg cstdio cstdlib cstring fstream inttypes.h iosfwd iostream limits map memory ostream unistd.h vector ],, AC_MSG_ERROR([Some external headers are missing.]))
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
