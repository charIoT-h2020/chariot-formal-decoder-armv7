AC_INIT([UNISIM ArmSec ARMv7 to BINSEC-DBA translator], [1.0.9], [Yves Lhuillier <yves.lhuillier@cea.fr>], [unisim-armsec-core])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_HEADERS([config.h])
AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE([subdir-objects tar-pax])
AC_PATH_PROGS(SH, sh)
AC_PROG_CXX
AC_PROG_INSTALL
LT_INIT
AC_SUBST(LIBTOOL_DEPS)
AC_PROG_LN_S
AC_LANG([C++])
AM_PROG_CC_C_O
case "${host}" in
	*mingw*)
		CPPFLAGS="-U__STRICT_ANSI__ ${CPPFLAGS}"
		CXXFLAGS="-Wa,-mbig-obj ${CXXFLAGS}"
		;;
	*)
		;;
esac
AC_CHECK_HEADER([inttypes.h],, AC_MSG_ERROR([inttypes.h is missing]))
AC_CHECK_HEADER([iostream],, AC_MSG_ERROR([iostream is missing]))
AC_CHECK_HEADER([iomanip],, AC_MSG_ERROR([iomanip is missing]))
AC_CHECK_HEADER([iosfwd],, AC_MSG_ERROR([iosfwd is missing]))
AC_CHECK_HEADER([map],, AC_MSG_ERROR([map is missing]))
AC_CHECK_HEADER([stdint.h],, AC_MSG_ERROR([stdint.h is missing]))
AC_CHECK_HEADER([string.h],, AC_MSG_ERROR([string.h is missing]))
AC_CHECK_HEADER([sys/types.h],, AC_MSG_ERROR([sys/types.h is missing]))
UNISIM_CHECK_ENDIAN
AC_CHECK_HEADER([ostream],, AC_MSG_ERROR([ostream is missing]))
AC_CHECK_HEADER([set],, AC_MSG_ERROR([set is missing]))
AC_CHECK_HEADER([sstream],, AC_MSG_ERROR([sstream is missing]))
AC_CHECK_HEADER([vector],, AC_MSG_ERROR([vector is missing]))
AC_CHECK_HEADER([algorithm],, AC_MSG_ERROR([algorithm is missing]))
AC_CHECK_HEADER([cstring],, AC_MSG_ERROR([cstring is missing]))
AC_CHECK_HEADER([stdexcept],, AC_MSG_ERROR([stdexcept is missing]))
AC_CHECK_HEADER([cstdio],, AC_MSG_ERROR([cstdio is missing]))
AC_CHECK_HEADER([cstdlib],, AC_MSG_ERROR([cstdlib is missing]))
AC_CHECK_HEADER([string],, AC_MSG_ERROR([string is missing]))
AX_CXXFLAGS_WARN_ALL 
GENISSLIB_PATH=$(pwd)/../genisslib/genisslib
AC_SUBST(GENISSLIB_PATH)
AC_DEFINE([BIN_TO_SHARED_DATA_PATH], ["../share/unisim-armsec-1.0.9"], [path of shared data relative to bin directory])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
