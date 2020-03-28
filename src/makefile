CPPFLAGS=
CXXFLAGS=-O0 -g3 -fPIC 
BUILD=build

ARMSRCS=armsec_decoder.cpp armsec/unisim/component/cxx/processor/arm/disasm.cc
ARMOBJS=$(patsubst %,$(BUILD)/%.o,$(basename $(ARMSRCS)))

$(ARMOBJS): CPPFLAGS+=-Iarmsec

CXXPPOBJS=$(patsubst %.cpp,$(BUILD)/%.o,$(filter %.cpp,$(ARMSRCS)))
CXXCOBJS=$(patsubst %.cc,$(BUILD)/%.o,$(filter %.cc,$(ARMSRCS)))

all: check_memory

define COMPILE
@mkdir -p `dirname $@`
$(CXX) $(CPPFLAGS) $(CXXFLAGS) -MMD -MP -o $@ -c $<
endef

$(CXXCOBJS): $(BUILD)/%.o: %.cc
	$(COMPILE)

$(CXXPPOBJS): $(BUILD)/%.o: %.cpp
	$(COMPILE)

armsec_decoder.so: $(ARMOBJS)
	g++ -Iarmsec -shared -o armsec_decoder.so $(ARMOBJS)

check_memory: check_memory.cc dll.cc armsec_decoder.so
	g++ -O0 -g check_memory.cc dll.cc armsec_decoder.so -ldl -o check_memory -Wl,-rpath .

-include armsec_decoder.d
