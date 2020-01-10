ACLOCAL_AMFLAGS=-I m4
AM_CPPFLAGS=-I$(top_srcdir) -I$(top_builddir)
LIBTOOL_DEPS = @LIBTOOL_DEPS@
libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status libtool

# Program
bin_PROGRAMS = unisim-armsec-1.0.9
unisim_armsec_1_0_9_SOURCES = main.cc 
unisim_armsec_1_0_9_LDFLAGS = -static-libtool-libs
unisim_armsec_1_0_9_LDADD = libunisim-armsec-1.0.9.la

# Static Library
noinst_LTLIBRARIES = libunisim-armsec-1.0.9.la
libunisim_armsec_1_0_9_la_SOURCES =  unisim/component/cxx/processor/arm/disasm.cc unisim/util/symbolic/symbolic.cc unisim/util/symbolic/binsec/binsec.cc
libunisim_armsec_1_0_9_la_LDFLAGS = -static

noinst_HEADERS =  unisim/component/cxx/processor/arm/isa/thumb/branch.isa unisim/component/cxx/processor/arm/isa/thumb/data_processing.isa unisim/component/cxx/processor/arm/isa/thumb/exception.isa unisim/component/cxx/processor/arm/isa/thumb/load_store.isa unisim/component/cxx/processor/arm/isa/thumb/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/thumb/multiply.isa unisim/component/cxx/processor/arm/isa/thumb/ordering.isa unisim/component/cxx/processor/arm/isa/thumb2/branch.isa unisim/component/cxx/processor/arm/isa/thumb2/coprocessor.isa unisim/component/cxx/processor/arm/isa/thumb2/data_processing.isa unisim/component/cxx/processor/arm/isa/thumb2/exception.isa unisim/component/cxx/processor/arm/isa/thumb2/hints.isa unisim/component/cxx/processor/arm/isa/thumb2/load_store.isa unisim/component/cxx/processor/arm/isa/thumb2/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/thumb2/multiply.isa unisim/component/cxx/processor/arm/isa/thumb2/neon.isa unisim/component/cxx/processor/arm/isa/thumb2/ordering.isa unisim/component/cxx/processor/arm/isa/thumb2/status_register_access.isa unisim/component/cxx/processor/arm/isa/thumb2/thumb.isa unisim/component/cxx/processor/arm/isa/thumb2/vfp.isa unisim/component/cxx/processor/arm/isa/thumb2/xscale.isa  unisim/component/cxx/processor/arm/isa/arm32/branch.isa unisim/component/cxx/processor/arm/isa/arm32/coprocessor.isa unisim/component/cxx/processor/arm/isa/arm32/data_processing.isa unisim/component/cxx/processor/arm/isa/arm32/exception.isa unisim/component/cxx/processor/arm/isa/arm32/hints.isa unisim/component/cxx/processor/arm/isa/arm32/load_store.isa unisim/component/cxx/processor/arm/isa/arm32/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/arm32/multiply.isa unisim/component/cxx/processor/arm/isa/arm32/neon.isa unisim/component/cxx/processor/arm/isa/arm32/ordering.isa unisim/component/cxx/processor/arm/isa/arm32/specialization.isa unisim/component/cxx/processor/arm/isa/arm32/status_register_access.isa unisim/component/cxx/processor/arm/isa/arm32/vfp.isa  unisim/util/inlining/inlining.hh unisim/util/truth_table/truth_table.hh unisim/util/arithmetic/arithmetic.hh unisim/util/endian/endian.hh unisim/util/likely/likely.hh unisim/component/cxx/processor/arm/disasm.hh unisim/component/cxx/processor/arm/execute.hh unisim/component/cxx/processor/arm/psr.hh unisim/component/cxx/processor/arm/register_field.hh unisim/component/cxx/processor/arm/isa/decode.hh unisim/component/cxx/processor/arm/models.hh unisim/component/cxx/processor/arm/exception.hh unisim/util/identifier/identifier.hh unisim/util/symbolic/symbolic.hh unisim/util/symbolic/binsec/binsec.hh   top_thumb.isa  top_arm32.isa   
EXTRA_DIST =  m4/endian.m4 m4/ax_cflags_warn_all.m4 
sharedir = $(prefix)/share/unisim-armsec-1.0.9
dist_share_DATA = COPYING README INSTALL AUTHORS NEWS ChangeLog 
nobase_dist_share_DATA = 

BUILT_SOURCES=	$(top_builddir)/top_arm32.hh	$(top_builddir)/top_arm32.tcc	$(top_builddir)/top_thumb.hh	$(top_builddir)/top_thumb.tcc
CLEANFILES=	$(top_builddir)/top_arm32.hh	$(top_builddir)/top_arm32.tcc	$(top_builddir)/top_thumb.hh	$(top_builddir)/top_thumb.tcc
$(top_builddir)/top_arm32.tcc: $(top_builddir)/top_arm32.hh
$(top_builddir)/top_arm32.hh: top_arm32.isa   unisim/component/cxx/processor/arm/isa/arm32/branch.isa unisim/component/cxx/processor/arm/isa/arm32/coprocessor.isa unisim/component/cxx/processor/arm/isa/arm32/data_processing.isa unisim/component/cxx/processor/arm/isa/arm32/exception.isa unisim/component/cxx/processor/arm/isa/arm32/hints.isa unisim/component/cxx/processor/arm/isa/arm32/load_store.isa unisim/component/cxx/processor/arm/isa/arm32/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/arm32/multiply.isa unisim/component/cxx/processor/arm/isa/arm32/neon.isa unisim/component/cxx/processor/arm/isa/arm32/ordering.isa unisim/component/cxx/processor/arm/isa/arm32/specialization.isa unisim/component/cxx/processor/arm/isa/arm32/status_register_access.isa unisim/component/cxx/processor/arm/isa/arm32/vfp.isa
	$(GENISSLIB_PATH) -o $(top_builddir)/top_arm32 -w 8 -I $(top_srcdir) $(top_srcdir)/top_arm32.isa 

$(top_builddir)/top_thumb.tcc: $(top_builddir)/top_thumb.hh
$(top_builddir)/top_thumb.hh: top_thumb.isa   unisim/component/cxx/processor/arm/isa/thumb/branch.isa unisim/component/cxx/processor/arm/isa/thumb/data_processing.isa unisim/component/cxx/processor/arm/isa/thumb/exception.isa unisim/component/cxx/processor/arm/isa/thumb/load_store.isa unisim/component/cxx/processor/arm/isa/thumb/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/thumb/multiply.isa unisim/component/cxx/processor/arm/isa/thumb/ordering.isa unisim/component/cxx/processor/arm/isa/thumb2/branch.isa unisim/component/cxx/processor/arm/isa/thumb2/coprocessor.isa unisim/component/cxx/processor/arm/isa/thumb2/data_processing.isa unisim/component/cxx/processor/arm/isa/thumb2/exception.isa unisim/component/cxx/processor/arm/isa/thumb2/hints.isa unisim/component/cxx/processor/arm/isa/thumb2/load_store.isa unisim/component/cxx/processor/arm/isa/thumb2/misc_arithmetic.isa unisim/component/cxx/processor/arm/isa/thumb2/multiply.isa unisim/component/cxx/processor/arm/isa/thumb2/neon.isa unisim/component/cxx/processor/arm/isa/thumb2/ordering.isa unisim/component/cxx/processor/arm/isa/thumb2/status_register_access.isa unisim/component/cxx/processor/arm/isa/thumb2/thumb.isa unisim/component/cxx/processor/arm/isa/thumb2/vfp.isa unisim/component/cxx/processor/arm/isa/thumb2/xscale.isa
	$(GENISSLIB_PATH) -o $(top_builddir)/top_thumb -w 8 -I $(top_srcdir) $(top_srcdir)/top_thumb.isa 
	 
