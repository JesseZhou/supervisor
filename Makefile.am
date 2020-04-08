ACLOCAL_AMFLAGS = -I m4

BASE_NO_WARNING_CPPFLAGS = \
    -I$(top_srcdir)/include -I$(builddir)/include \
    $(BOOST_CPPFLAGS)
BASE_CPPFLAGS = \
    -Wall -Werror -Wextra -Wno-missing-field-initializers \
    $(BASE_NO_WARNING_CPPFLAGS)

bin_PROGRAMS = supervisorctrl
supervisorctrl_SOURCES = \
    src/supervisorctrl/main.cpp \
    src/utils/abort.cpp 
supervisorctrl_CPPFLAGS = \
    $(BASE_CPPFLAGS)   
supervisorctrl_LDADD = \
    $(BASE_LIBS) \
    $(BOOST_SYSTEM_LIB) \
    $(BOOST_ASIO_LIB) \
    $(BOOST_IOSTREAMS_LIB) \
    $(BOOST_FILESYSTEM_LIB)