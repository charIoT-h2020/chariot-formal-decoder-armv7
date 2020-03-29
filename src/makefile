CPPFLAGS=-I.
CXXFLAGS=-O2 -g3 -fPIC 
BUILD=build

ARMSRCS=armsec_decoder.cpp armsec/unisim/component/cxx/processor/arm/disasm.cc
ARMOBJS=$(patsubst %,$(BUILD)/%.o,$(basename $(ARMSRCS)))

MIPSRCS=mipsec_decoder.cpp
MIPOBJS=$(patsubst %,$(BUILD)/%.o,$(basename $(MIPSRCS)))

$(ARMOBJS): CPPFLAGS+=-Iarmsec
$(MIPOBJS): CPPFLAGS+=-Imipselsec

CXXPPOBJS=$(patsubst %.cpp,$(BUILD)/%.o,$(filter %.cpp,$(ARMSRCS) $(MIPSRCS)))
CXXCOBJS=$(patsubst %.cc,$(BUILD)/%.o,$(filter %.cc,$(ARMSRCS) $(MIPSRCS)))

to_remove: mipsec_decoder.so

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
	g++ -shared -o $@ $(ARMOBJS)

mipsec_decoder.so: $(MIPOBJS)
	g++ -shared -o $@ $(ARMOBJS)

check_memory: check_memory.cc dll.cc armsec_decoder.so
	g++ -O0 -g check_memory.cc dll.cc armsec_decoder.so -ldl -o check_memory -Wl,-rpath .

clean:
	rm -Rf build armsec_decoder.so

-include armsec_decoder.d
