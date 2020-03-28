AC_INIT([UNISIM Mipselsec little endian Mips symbolic translator], [0.1.0], [Yves Lhuillier <yves.lhuillier@cea.fr>], [unisim-mipselsec-core])
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
AC_CHECK_HEADER([algorithm],, AC_MSG_ERROR([algorithm is missing]))
AC_CHECK_HEADER([cstring],, AC_MSG_ERROR([cstring is missing]))
AC_CHECK_HEADER([iomanip],, AC_MSG_ERROR([iomanip is missing]))
AC_CHECK_HEADER([iosfwd],, AC_MSG_ERROR([iosfwd is missing]))
AC_CHECK_HEADER([iostream],, AC_MSG_ERROR([iostream is missing]))
AC_CHECK_HEADER([sstream],, AC_MSG_ERROR([sstream is missing]))
AC_CHECK_HEADER([string],, AC_MSG_ERROR([string is missing]))
AC_CHECK_HEADER([fcntl.h],, AC_MSG_ERROR([fcntl.h is missing]))
AC_CHECK_HEADER([signal.h],, AC_MSG_ERROR([signal.h is missing]))
AC_CHECK_HEADER([stdint.h],, AC_MSG_ERROR([stdint.h is missing]))
AC_CHECK_HEADER([stdio.h],, AC_MSG_ERROR([stdio.h is missing]))
AC_CHECK_HEADER([stdlib.h],, AC_MSG_ERROR([stdlib.h is missing]))
AC_CHECK_HEADER([unistd.h],, AC_MSG_ERROR([unistd.h is missing])) 
dnl This is a hack: see http://cvs.pld-linux.org/cgi-bin/viewvc.cgi/cvs/packages/icu/ac264-hack.patch?view=markup
dnl
dnl this AC_LINK_IFELSE is early here so that ac 2.64 wouldn't define the `ac_fn_cxx_try_link' in if..else condition
AC_LANG_PUSH([C++])
AC_LINK_IFELSE([AC_LANG_PROGRAM()])
AC_LANG_POP([C++])
UNISIM_CHECK_GET_EXECUTABLE_PATH
UNISIM_CHECK_PTHREAD
AC_CHECK_HEADER([cassert],, AC_MSG_ERROR([cassert is missing]))
AC_CHECK_HEADER([fstream],, AC_MSG_ERROR([fstream is missing]))
AC_CHECK_HEADER([list],, AC_MSG_ERROR([list is missing]))
AC_CHECK_HEADER([map],, AC_MSG_ERROR([map is missing]))
AC_CHECK_HEADER([set],, AC_MSG_ERROR([set is missing]))
AC_CHECK_HEADER([vector],, AC_MSG_ERROR([vector is missing]))
AC_CHECK_HEADER([ostream],, AC_MSG_ERROR([ostream is missing]))
UNISIM_CHECK_CXXABI
AC_CHECK_HEADER([ctype.h],, AC_MSG_ERROR([ctype.h is missing])) 
AC_CHECK_HEADER([errno.h],, AC_MSG_ERROR([errno.h is missing]))
UNISIM_CHECK_BSD_SOCKETS
AC_CHECK_HEADER([cstdlib],, AC_MSG_ERROR([cstdlib is missing]))
AC_CHECK_HEADER([sys/types.h],, AC_MSG_ERROR([sys/types.h is missing]))
UNISIM_CHECK_REAL_PATH
AC_CHECK_HEADER([string.h],, AC_MSG_ERROR([string.h is missing]))
UNISIM_CHECK_ENDIAN
AC_CHECK_HEADER([assert.h],, AC_MSG_ERROR([assert.h is missing]))
AC_CHECK_HEADER([time.h],, AC_MSG_ERROR([time.h is missing]))
UNISIM_CHECK_TIMES
AC_CHECK_HEADER([cerrno],, AC_MSG_ERROR([cerrno is missing]))
AC_CHECK_HEADER([queue],, AC_MSG_ERROR([queue is missing]))
AC_CHECK_HEADER([stdexcept],, AC_MSG_ERROR([stdexcept is missing]))
AC_CHECK_HEADER([cctype],, AC_MSG_ERROR([cctype is missing]))
AC_CHECK_HEADER([fenv.h],, AC_MSG_ERROR([fenv.h is missing]))
AC_CHECK_HEADER([math.h],, AC_MSG_ERROR([math.h is missing]))
AC_CHECK_HEADER([cmath],, AC_MSG_ERROR([cmath is missing]))
AC_CHECK_HEADER([cstdio],, AC_MSG_ERROR([cstdio is missing]))
AC_CHECK_HEADER([deque],, AC_MSG_ERROR([deque is missing]))
AC_CHECK_HEADER([stack],, AC_MSG_ERROR([stack is missing]))
AC_CHECK_HEADER([stdarg.h],, AC_MSG_ERROR([stdarg.h is missing]))
AX_CXXFLAGS_WARN_ALL 
GENISSLIB_PATH=$(pwd)/../genisslib/genisslib
AC_SUBST(GENISSLIB_PATH)
AC_DEFINE([BIN_TO_SHARED_DATA_PATH], ["../share/unisim-mipselsec-0.1.0"], [path of shared data relative to bin directory])
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
