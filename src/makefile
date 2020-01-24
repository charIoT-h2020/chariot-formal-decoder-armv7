ARMSEC_INCLUDE_DIR=../armsec/armsec
ARMSEC_SRC_DIR=$(ARMSEC_INCLUDE_DIR)/unisim/component/cxx/processor/arm
ARMSEC_BUILD_INCLUDE_DIR=../armsec/build_release/armsec
ARMSEC_BUILD_DIR=../armsec/build_release/armsec/unisim/component/cxx/processor/arm

armsec_decoder.so: armsec_decoder.h armsec_decoder.cpp               \
    $(ARMSEC_SRC_DIR)/disasm.hh $(ARMSEC_SRC_DIR)/disasm.cc
	clang++ -I$(ARMSEC_INCLUDE_DIR) -I$(ARMSEC_BUILD_INCLUDE_DIR) -shared \
      -fPIC armsec_decoder.cpp                                      \
      $(ARMSEC_SRC_DIR)/disasm.cc                                   \
      -o armsec_decoder.so
