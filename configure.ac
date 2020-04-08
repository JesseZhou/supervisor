AC_INIT([supersivor], [3], [], [], [https://gerrite1.ext.net.nokia.com/scm_rcp/ccsmcu-testapp])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_FILES([Makefile])
#AC_CONFIG_FILES([Doxyfile])
#AC_CONFIG_FILES([include/ministarter/version.h])
#AC_CONFIG_FILES([run-tests.sh], [chmod +x run-tests.sh])
AM_INIT_AUTOMAKE([subdir-objects foreign 1.13 tar-pax -Wall -Werror])
AM_SILENT_RULES([yes])
AM_PROG_AR
AC_PROG_CXX
AC_LANG([C++])
#AM_PROG_LIBTOOL
AC_PROG_MKDIR_P
LT_INIT
AC_CONFIG_MACRO_DIR([m4])
AX_CXX_COMPILE_STDCXX(17, [noext], [mandatory])
AX_BOOST_BASE([1.66], [], [AC_MSG_ERROR(Unable to detect suitable boost library)])
AX_BOOST_ASIO
AX_BOOST_IOSTREAMS
AX_BOOST_FILESYSTEM
AX_BOOST_SYSTEM
AX_PTHREAD
AC_OUTPUT