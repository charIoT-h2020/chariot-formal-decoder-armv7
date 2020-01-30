ARMSEC_INCLUDE_DIR=../armsec/armsec
ARMSEC_SRC_DIR=$(ARMSEC_INCLUDE_DIR)/unisim/component/cxx/processor/arm
ARMSEC_BUILD_INCLUDE_DIR=armsec

all: check_memory

armsec_decoder.so: armsec_decoder.h armsec_decoder.cpp               \
    $(ARMSEC_SRC_DIR)/disasm.hh $(ARMSEC_SRC_DIR)/disasm.cc
	g++ -I$(ARMSEC_INCLUDE_DIR) -I$(ARMSEC_BUILD_INCLUDE_DIR) -shared \
      -O0 -g -fPIC armsec_decoder.cpp                                      \
      $(ARMSEC_SRC_DIR)/disasm.cc                                   \
      -o armsec_decoder.so

check_memory: check_memory.cc dll.cc armsec_decoder.so
	g++ -O0 -g check_memory.cc dll.cc armsec_decoder.so -ldl -o check_memory -Wl,-rpath .

