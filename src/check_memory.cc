/////////////////////////////////
//
// Application : armsec
// Unit      : main program
// File      : check_memory.cc
// Description :
//   unit test for the connection between domsec & armsec
//

#include <iostream>
#include <cassert>
#include <cstring>
#include <sstream>
#include <fstream>
#include <vector>
#include <memory>
#include <map>
#include "armsec_decoder.h"
#include "dll.h"

class ProcessArgument {
  private:
   const char* szInputFile = nullptr;
   const char* szAddress = nullptr;
   const char* szMemoryFile = nullptr;
   const char* szArch = nullptr;
   const char* szDomain = nullptr;
   bool fHasEchoedMessage = false;

  public:
   ProcessArgument() = default;
   ProcessArgument(int argc, char** argv)
      {  int arg = argc-2;
         while (arg >= 0)
            fHasEchoedMessage = !process(argv + (argc - arg - 1), arg) && fHasEchoedMessage;
      }

   bool process(char** argument, int& currentArgument);
   void printUsage(std::ostream& out) const
      {  if (fHasEchoedMessage)
            return;
         out << "usage of check_memory:\n"
             << "\tcheck_memory [options] binary_file address memory.json\n"
             << "\n"
             << "where option can be:\n"
             << "\t-arch armsec.so \tto provide the instruction set\n"
             << "\t-dom domsec.so \tto provide the domain library\n";
         out.flush();
      }

   bool isValid() const { return szInputFile && szAddress; }
   bool hasEchoedMessage() const { return fHasEchoedMessage; }

   const char* getInputFile() const { return szInputFile; }
   uint64_t getAddress() const
      {  std::istringstream in(szAddress);
         uint64_t res = 0;
         in >> std::hex >> res;
         return res;
      }
   const char* getMemoryFile() const { return szMemoryFile; }
   bool hasArch() const { return szArch; }
   bool hasDomain() const { return szDomain; }
   const char* getArch() const { return szArch; }
   const char* getDomain() const { return szDomain; }
};

bool
ProcessArgument::process(char** argument, int& currentArgument) {
   if (argument[0][0] == '-') {
      switch (argument[0][1]) {
         case 'a':
            if (strcmp(&argument[0][1], "arch") == 0) {
               if (currentArgument == 0 || szArch) {
                  printUsage(std::cout);
                  return false;
               };
               currentArgument -= 2;
               szArch = argument[1];
            }
            else {
               printUsage(std::cout);
               fHasEchoedMessage = true;
               --currentArgument;
            }
            return true;
         case 'd':
            if (strcmp(&argument[0][1], "dom") == 0) {
               if (currentArgument == 0 || szDomain) {
                  printUsage(std::cout);
                  return false;
               };
               currentArgument -= 2;
               szDomain = argument[1];
            }
            else {
               printUsage(std::cout);
               fHasEchoedMessage = true;
               --currentArgument;
            }
            return true;
         default:
            printUsage(std::cout);
            --currentArgument;
            return false;
      };
   }
   else {
      if (szInputFile) {
         if (szAddress) {
            if (szMemoryFile) {
               printUsage(std::cout);
               --currentArgument;
               return false;
            }
            szMemoryFile = argument[0];
            --currentArgument;
         }
         else {
            szAddress = argument[0];
            --currentArgument;
         }
      }
      else {
         szInputFile = argument[0];
         --currentArgument;
      }
   }
   return true;
}

class DomainValue {
  private:
   DomainElement deValue;
   struct _DomainElementFunctions* pfFunctions;

  protected:
   friend class MemoryState;
   DomainElement& svalue() { return deValue; }
   bool hasFunctionTable() const { return pfFunctions; }
   struct _DomainElementFunctions& functionTable() const { assert(pfFunctions); return *pfFunctions; }

  public:
   const DomainElement& value() const { return deValue; }

  public:
   DomainValue() : deValue{}, pfFunctions(nullptr) {}
   DomainValue(DomainElement&& value, struct _DomainElementFunctions* functions)
      :  deValue(std::move(value)), pfFunctions(functions) {}
   DomainValue(DomainValue&& source)
      :  deValue(source.deValue), pfFunctions(source.pfFunctions)
      {  source.deValue.content = nullptr; }
   DomainValue(const DomainValue& source)
      :  deValue{ nullptr }, pfFunctions(source.pfFunctions)
      {  if (source.deValue.content) {
            assert(pfFunctions);
            deValue = (*pfFunctions->clone)(source.deValue);
         }
      }
   DomainValue& operator=(DomainValue&& source)
      {  if (this == &source)
            return *this;
         if (deValue.content)
         {
            assert(pfFunctions);
            (*pfFunctions->free)(&deValue);
         }
         pfFunctions = source.pfFunctions;
         deValue = source.deValue;
         source.deValue.content = nullptr;
         return *this;
      }
   DomainValue& operator=(const DomainValue& source)
      {  if (this == &source)
            return *this;
         if (deValue.content)
            (*pfFunctions->free)(&deValue);
         pfFunctions = source.pfFunctions;
         if (source.deValue.content)
         {
            assert(pfFunctions);
            deValue = (*pfFunctions->clone)(source.deValue);
         }
         return *this;
      }
   ~DomainValue()
      { if (deValue.content && pfFunctions) (*pfFunctions->free)(&deValue); }

   void clear()
      {  if (deValue.content)
         {  assert(pfFunctions);
            (*pfFunctions->free)(&deValue);
         }
      }
   bool isValid() const { return deValue.content; }
   DomainType getType() const
      {  assert(pfFunctions);
         return (*pfFunctions->get_type)(deValue);
      } 
   ZeroResult queryZeroResult() const
      {  assert(pfFunctions);
         return (*pfFunctions->query_zero_result)(deValue);
      } 
   int getSizeInBits() const
      {  assert(pfFunctions);
         return (*pfFunctions->get_size_in_bits)(deValue);
      } 
   DomainElement extractElement()
      {  auto res = deValue;
         deValue = DomainElement{};
         return res;
      }

   static char* increase_buffer_size(char* buffer, int old_length, int new_length, void* awriter)
      {  std::vector<char>* writer = reinterpret_cast<std::vector<char>*>(awriter);
         assert(writer->size() == old_length);
         writer->insert(writer->end(), new_length-old_length, '\0');
         return &(*writer)[0];
      }
   friend std::ostream& operator<<(std::ostream& out, const DomainValue& value)
      {  if (value.deValue.content && value.pfFunctions) {
            std::vector<char> buffer;
            buffer.insert(buffer.begin(), 20, '\0');
            int buffer_size = 20;
            int length = 0;
            (*value.pfFunctions->write)(value.deValue, &buffer[0], buffer_size, &length, &buffer,
                  &increase_buffer_size);
            out << &buffer[0];
         }
         else
            out << "...";
         return out;
      }
};

class MemoryInterpretParameters {

};

class Processor;
class MemoryState {
  private:
   static MemoryModelFunctions functions;
   std::shared_ptr<DLL::Library> dlDomainLibrary;
   int uRegisterNumber = 0;
   std::map<int, DomainValue> mvRegisters;
   struct _DomainElementFunctions domainFunctions;

   /* call-back functions */
   static void set_number_of_registers(MemoryModel* amemory, int numbers)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         memory->uRegisterNumber = numbers;
      }
   static void set_register_value(MemoryModel* amemory, int registerIndex,
         DomainElement* avalue, InterpretParameters* parameters,
         unsigned* error /* set of MemoryEvaluationErrorFlags */)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue value(std::move(*avalue), &memory->domainFunctions);
         std::cout << "write at register r" << registerIndex << ": value = " << value << '\n';
         memory->mvRegisters[registerIndex] = std::move(value);
      }
   static DomainElement get_register_value(MemoryModel* amemory,
         int registerIndex, InterpretParameters* parameters,
         unsigned* error /* set of MemoryEvaluationErrorFlags */,
         DomainElementFunctions** elementFunctions)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue result = memory->mvRegisters[registerIndex];
         if (result.isValid())
            std::cout << "load at register r" << registerIndex << ": value = " << result << '\n';
         else {
            result = DomainValue(memory->domainFunctions.multibit_create_top(32, true /* isSymbolic */), &memory->domainFunctions);
            std::cout << "load at register r" << registerIndex << ": unknown value = "
                      << result << "\n";
         }
         if (elementFunctions)
            *elementFunctions = &memory->domainFunctions;
         return result.extractElement();
      }

   static DomainElement load_multibit_value(MemoryModel* amemory,
         DomainElement indirect_address, size_t size, InterpretParameters* parameters,
         unsigned* error, DomainElementFunctions** elementFunctions)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue address((*memory->domainFunctions.clone)(indirect_address), &memory->domainFunctions);
         DomainValue result(memory->domainFunctions.multibit_create_top(size, true /* isSymbolic */), &memory->domainFunctions);
         std::cout << "load in memory at address " << address << ": unknown value = "
                      << result << "\n";
         if (elementFunctions)
            *elementFunctions = &memory->domainFunctions;
         return result.extractElement();
      }
   static DomainElement load_multibit_disjunctive_value(MemoryModel* amemory,
         DomainElement indirect_address, size_t size, InterpretParameters* parameters,
         unsigned* error, DomainElementFunctions** elementFunctions)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue address((*memory->domainFunctions.clone)(indirect_address), &memory->domainFunctions);
         DomainValue result(memory->domainFunctions.multibit_create_top(size, true /* isSymbolic */), &memory->domainFunctions);
         std::cout << "load in memory at address " << address << ": unknown value = "
                      << result << "\n";
         if (elementFunctions)
            *elementFunctions = &memory->domainFunctions;
         return result.extractElement();
      }
   static DomainElement load_multifloat_value(MemoryModel* amemory,
         DomainElement indirect_address, size_t size, InterpretParameters* parameters,
         unsigned* error, DomainElementFunctions** elementFunctions)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue address((*memory->domainFunctions.clone)(indirect_address), &memory->domainFunctions);
         DomainValue result(memory->domainFunctions.multifloat_create_top(size, true /* isSymbolic */), &memory->domainFunctions);
         std::cout << "load in memory at address " << address << ": unknown value = "
                      << result << "\n";
         if (elementFunctions)
            *elementFunctions = &memory->domainFunctions;
         return result.extractElement();
      }
   static void store_value(MemoryModel* amemory, DomainElement indirect_address,
         DomainElement avalue, InterpretParameters* parameters, unsigned* error)
      {  MemoryState* memory = reinterpret_cast<MemoryState*>(amemory);
         DomainValue value((*memory->domainFunctions.clone)(avalue), &memory->domainFunctions);
         DomainValue address((*memory->domainFunctions.clone)(indirect_address), &memory->domainFunctions);
         std::cout << "write in memory at address " << address << ": value = " << value << "\n";
      }

  public:
   MemoryState() = default;
   MemoryState(const MemoryState&) = default;

   MemoryModelFunctions* getFunctions() const { return &functions; }
   bool loadDomain(const char* domainFile);
   void write(std::ostream& out) const { out << "end of memory description\n"; }
   const struct _DomainElementFunctions* getDomainFunctions() const { return &domainFunctions; }
   void initializeMemory(Processor& proc, MemoryInterpretParameters& parameters);
};

bool
MemoryState::loadDomain(const char* domainFile)
{  dlDomainLibrary.reset(new DLL::Library(domainFile));
   dlDomainLibrary->loadSymbol("domain_get_type", &domainFunctions.get_type);
   dlDomainLibrary->loadSymbol("domain_query_zero_result", &domainFunctions.query_zero_result);
   dlDomainLibrary->loadSymbol("domain_get_size_in_bits", &domainFunctions.get_size_in_bits);
   dlDomainLibrary->loadSymbol("domain_free", &domainFunctions.free);
   dlDomainLibrary->loadSymbol("domain_clone", &domainFunctions.clone);

   dlDomainLibrary->loadSymbol("domain_bit_create_constant", &domainFunctions.bit_create_constant);
   dlDomainLibrary->loadSymbol("domain_bit_create_top", &domainFunctions.bit_create_top);
   dlDomainLibrary->loadSymbol("domain_bit_create_cast_multibit", &domainFunctions.bit_create_cast_multibit);
   dlDomainLibrary->loadSymbol("domain_bit_unary_apply_assign", &domainFunctions.bit_unary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_bit_create_unary_apply", &domainFunctions.bit_create_unary_apply);
   dlDomainLibrary->loadSymbol("domain_bit_binary_apply_assign", &domainFunctions.bit_binary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_bit_create_binary_apply", &domainFunctions.bit_create_binary_apply);
   dlDomainLibrary->loadSymbol("domain_bit_binary_compare", &domainFunctions.bit_binary_compare);
   dlDomainLibrary->loadSymbol("domain_bit_binary_compare_domain", &domainFunctions.bit_binary_compare_domain);
   dlDomainLibrary->loadSymbol("domain_bit_guard_assign", &domainFunctions.bit_guard_assign);
   dlDomainLibrary->loadSymbol("domain_bit_query_boolean", &domainFunctions.bit_query_boolean);
   dlDomainLibrary->loadSymbol("domain_bit_cast_multibit_constraint", &domainFunctions.bit_cast_multibit_constraint);
   dlDomainLibrary->loadSymbol("domain_bit_unary_constraint", &domainFunctions.bit_unary_constraint);
   dlDomainLibrary->loadSymbol("domain_bit_binary_constraint", &domainFunctions.bit_binary_constraint);
   dlDomainLibrary->loadSymbol("domain_bit_compare_constraint", &domainFunctions.bit_compare_constraint);
   dlDomainLibrary->loadSymbol("domain_bit_is_constant_value", &domainFunctions.bit_is_constant_value);

   dlDomainLibrary->loadSymbol("domain_multibit_create_constant", &domainFunctions.multibit_create_constant);
   dlDomainLibrary->loadSymbol("domain_multibit_create_top", &domainFunctions.multibit_create_top);
   dlDomainLibrary->loadSymbol("domain_multibit_create_interval_and_absorb", &domainFunctions.multibit_create_interval_and_absorb);
   dlDomainLibrary->loadSymbol("domain_multibit_create_cast_bit", &domainFunctions.multibit_create_cast_bit);
   dlDomainLibrary->loadSymbol("domain_multibit_create_cast_shift_bit", &domainFunctions.multibit_create_cast_shift_bit);
   dlDomainLibrary->loadSymbol("domain_multibit_create_cast_multibit", &domainFunctions.multibit_create_cast_multibit);
   dlDomainLibrary->loadSymbol("domain_multibit_create_cast_multifloat", &domainFunctions.multibit_create_cast_multifloat);
   dlDomainLibrary->loadSymbol("domain_multibit_create_cast_multifloat_ptr", &domainFunctions.multibit_create_cast_multifloat_ptr);
   dlDomainLibrary->loadSymbol("domain_multibit_unary_apply_assign", &domainFunctions.multibit_unary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_create_unary_apply", &domainFunctions.multibit_create_unary_apply);
   dlDomainLibrary->loadSymbol("domain_multibit_extend_apply_assign", &domainFunctions.multibit_extend_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_create_extend_apply", &domainFunctions.multibit_create_extend_apply);
   dlDomainLibrary->loadSymbol("domain_multibit_reduce_apply_assign", &domainFunctions.multibit_reduce_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_create_reduce_apply", &domainFunctions.multibit_create_reduce_apply);
   dlDomainLibrary->loadSymbol("domain_multibit_bitset_apply_assign", &domainFunctions.multibit_bitset_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_create_bitset_apply", &domainFunctions.multibit_create_bitset_apply);
   dlDomainLibrary->loadSymbol("domain_multibit_binary_apply_assign", &domainFunctions.multibit_binary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_create_binary_apply", &domainFunctions.multibit_create_binary_apply);
   dlDomainLibrary->loadSymbol("domain_multibit_binary_compare", &domainFunctions.multibit_binary_compare);
   dlDomainLibrary->loadSymbol("domain_multibit_binary_compare_domain", &domainFunctions.multibit_binary_compare_domain);
   dlDomainLibrary->loadSymbol("domain_multibit_guard_assign", &domainFunctions.multibit_guard_assign);
   dlDomainLibrary->loadSymbol("domain_multibit_query_boolean", &domainFunctions.multibit_query_boolean);
   dlDomainLibrary->loadSymbol("domain_multibit_cast_bit_constraint", &domainFunctions.multibit_cast_bit_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_cast_shift_bit_constraint", &domainFunctions.multibit_cast_shift_bit_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_cast_multifloat_constraint", &domainFunctions.multibit_cast_multifloat_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_cast_multifloat_ptr_constraint", &domainFunctions.multibit_cast_multifloat_ptr_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_unary_constraint", &domainFunctions.multibit_unary_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_extend_constraint", &domainFunctions.multibit_extend_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_reduce_constraint", &domainFunctions.multibit_reduce_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_bitset_constraint", &domainFunctions.multibit_bitset_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_binary_constraint", &domainFunctions.multibit_binary_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_compare_constraint", &domainFunctions.multibit_compare_constraint);
   dlDomainLibrary->loadSymbol("domain_multibit_is_constant_value", &domainFunctions.multibit_is_constant_value);

   dlDomainLibrary->loadSymbol("domain_multifloat_create_constant", &domainFunctions.multifloat_create_constant);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_top", &domainFunctions.multifloat_create_top);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_interval_and_absorb", &domainFunctions.multifloat_create_interval_and_absorb);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_cast_multibit", &domainFunctions.multifloat_create_cast_multibit);
   dlDomainLibrary->loadSymbol("domain_multifloat_query_to_multibit", &domainFunctions.multifloat_query_to_multibit);
   dlDomainLibrary->loadSymbol("domain_multifloat_cast_multifloat_assign", &domainFunctions.multifloat_cast_multifloat_assign);
   dlDomainLibrary->loadSymbol("domain_multifloat_cast_multifloat", &domainFunctions.multifloat_cast_multifloat);
   dlDomainLibrary->loadSymbol("domain_multifloat_unary_apply_assign", &domainFunctions.multifloat_unary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_unary_apply", &domainFunctions.multifloat_create_unary_apply);
   dlDomainLibrary->loadSymbol("domain_multifloat_flush_to_zero", &domainFunctions.multifloat_flush_to_zero);
   dlDomainLibrary->loadSymbol("domain_multifloat_binary_apply_assign", &domainFunctions.multifloat_binary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_binary_apply", &domainFunctions.multifloat_create_binary_apply);
   dlDomainLibrary->loadSymbol("domain_multifloat_binary_compare", &domainFunctions.multifloat_binary_compare);
   dlDomainLibrary->loadSymbol("domain_multifloat_binary_compare_domain", &domainFunctions.multifloat_binary_compare_domain);
   dlDomainLibrary->loadSymbol("domain_multifloat_binary_full_compare_domain", &domainFunctions.multifloat_binary_full_compare_domain);
   dlDomainLibrary->loadSymbol("domain_multifloat_guard_assign", &domainFunctions.multifloat_guard_assign);
   dlDomainLibrary->loadSymbol("domain_multifloat_ternary_apply_assign", &domainFunctions.multifloat_ternary_apply_assign);
   dlDomainLibrary->loadSymbol("domain_multifloat_ternary_query", &domainFunctions.multifloat_ternary_query);
   dlDomainLibrary->loadSymbol("domain_multifloat_create_ternary_apply", &domainFunctions.multifloat_create_ternary_apply);
   dlDomainLibrary->loadSymbol("domain_multifloat_cast_multibit_constraint", &domainFunctions.multifloat_cast_multibit_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_query_to_multibit_constraint", &domainFunctions.multifloat_query_to_multibit_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_cast_multifloat_constraint", &domainFunctions.multifloat_cast_multifloat_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_unary_constraint", &domainFunctions.multifloat_unary_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_binary_constraint", &domainFunctions.multifloat_binary_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_compare_constraint", &domainFunctions.multifloat_compare_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_ternary_constraint", &domainFunctions.multifloat_ternary_constraint);
   dlDomainLibrary->loadSymbol("domain_multifloat_is_constant_value", &domainFunctions.multifloat_is_constant_value);
   dlDomainLibrary->loadSymbol("domain_write", &domainFunctions.write);
   dlDomainLibrary->loadSymbol("domain_merge", &domainFunctions.merge);
   dlDomainLibrary->loadSymbol("domain_intersect", &domainFunctions.intersect);
   dlDomainLibrary->loadSymbol("domain_contain", &domainFunctions.contain);
   dlDomainLibrary->loadSymbol("domain_create_disjunction_and_absorb", &domainFunctions.create_disjunction_and_absorb);
   dlDomainLibrary->loadSymbol("domain_disjunction_absorb", &domainFunctions.disjunction_absorb);
   dlDomainLibrary->loadSymbol("domain_specialize", &domainFunctions.specialize);
   return true;
}

MemoryModelFunctions MemoryState::functions={
   &MemoryState::set_number_of_registers,
   &MemoryState::set_register_value,
   &MemoryState::get_register_value,
   &MemoryState::load_multibit_value,
   &MemoryState::load_multibit_disjunctive_value,
   &MemoryState::load_multifloat_value,
   &MemoryState::store_value,
   nullptr /* &MemoryState::constraint_store_value */,
   nullptr /* &MemoryState::constraint_address */
};

class Processor {
  private:
   struct _Processor* pvContent;
   friend class MemoryState;

   static uint64_t* reallocAddresses(uint64_t* old_addresses, int old_size,
         int* new_size, void* address_container)
      {  auto* container = reinterpret_cast<std::vector<uint64_t>*>(address_container);
         assert(container->size() == (size_t) old_size
               && old_addresses == &(*container)[0]);
         if (old_size < 6)
            *new_size = 6;
         else
            *new_size = old_size*3/2;
         container->insert(container->end(), (*new_size-old_size), 0);
         return &(*container)[0];
      }

  public:
   Processor(struct _Processor* content) : pvContent(content) {}
   Processor(Processor&& source) : pvContent(source.pvContent)
      {  source.pvContent = nullptr; }
   ~Processor() { free_processor(pvContent); }

   void setDomainFunctions(struct _DomainElementFunctions* functions)
      {  set_domain_functions(pvContent, functions); }
   std::vector<uint64_t> nextTargets(char* nextInstruction, int length, uint64_t address,
         const MemoryState& memoryState, MemoryInterpretParameters& parameters)
      {  std::vector<uint64_t> result;
         result.push_back(0);
         result.push_back(0);
         TargetAddresses argument;
         argument.addresses = &result[0];
         argument.addresses_array_size = 2;
         argument.addresses_length = 0;
         argument.realloc_addresses = &reallocAddresses;
         argument.address_container = &result;
         MemoryState memory(memoryState);
         bool isValid = processor_next_targets(pvContent, nextInstruction, length, address,
               &argument, reinterpret_cast<MemoryModel*>(&memory), memory.getFunctions(),
               reinterpret_cast<InterpretParameters*>(&parameters));
         assert(isValid);
         result.resize(argument.addresses_length);
         return std::move(result);
      }

   void interpret(char* instruction, int length, uint64_t address,
         uint64_t targetAddress, MemoryState& memoryState, MemoryInterpretParameters& parameters)
      {  bool isValid = processor_interpret(pvContent, instruction, length, address, targetAddress,
               reinterpret_cast<MemoryModel*>(&memoryState), memoryState.getFunctions(),
               reinterpret_cast<InterpretParameters*>(&parameters));
         assert(isValid);
      }
};

inline void
MemoryState::initializeMemory(Processor& proc, MemoryInterpretParameters& parameters)
   {  initialize_memory(proc.pvContent, reinterpret_cast<MemoryModel*>(this), &functions,
         reinterpret_cast<InterpretParameters*>(&parameters));
   }

int main(int argc, char** argv) {
   ProcessArgument processArgument(argc, argv);
   if (argc == 1) {
      processArgument.printUsage(std::cout);
      return 0;
   };
   if (!processArgument.isValid()) {
      if (!processArgument.hasEchoedMessage())
         processArgument.printUsage(std::cout);
      return 0;
   };

   Processor processor(create_processor());
   MemoryState memoryState;
   MemoryInterpretParameters parameters;
   bool ok = memoryState.loadDomain(processArgument.hasDomain() ? processArgument.getDomain() : "domsec.so");
   if (!ok) {
      std::cerr << "unable to find domain file "
         << (processArgument.hasDomain() ? processArgument.getDomain() : "domsec.so") << std::endl;
      return 1;
   }
   processor.setDomainFunctions(const_cast<struct _DomainElementFunctions*>(memoryState.getDomainFunctions()));
   memoryState.initializeMemory(processor, parameters);

   std::ifstream binaryFile(processArgument.getInputFile(), std::ifstream::binary);
   if (!binaryFile.good()) {
      std::cerr << "unable to find binary file " << processArgument.getInputFile() << std::endl;
      return 1;
   }
   binaryFile.seekg(processArgument.getAddress(), binaryFile.beg);
   if (!binaryFile.good()) {
      std::cerr << "unable to find binary file " << processArgument.getInputFile() << std::endl;
      return 1;
   }
   char instructionBuffer[1000];
   int length = binaryFile.readsome(instructionBuffer, 1000);
   if (length <= 0) {
      std::cerr << "invalid address 0x" << std::hex << processArgument.getAddress()
         << std::dec << " in binary file " << processArgument.getInputFile() << std::endl;
      return 1;
   }
   char* instruction = instructionBuffer;
   int instructionBufferSize = length;
   int countInstructions = 0;
   char* nextInstruction = instructionBuffer;
   uint64_t address = processArgument.getAddress();
   std::vector<uint64_t> targets;
   while (length > 0 && (targets = processor.nextTargets(nextInstruction,
               length, address, memoryState, parameters)).size() == 1) {
      processor.interpret(instruction, length, address, targets[0], memoryState, parameters);
      length -= (nextInstruction-instruction);
      address += (nextInstruction-instruction);
      instruction = nextInstruction;
      targets.clear();
      if (address != targets[0])
         break;
   }
   std::cout << "Before:\n";
   memoryState.write(std::cout);
   std::cout << "After:\n";
   if (length > 0 && targets.size() > 1) {
      for (int index = 0; index < targets.size()-1; ++index) {
         MemoryState memory(memoryState);
         processor.interpret(instruction, length, address, targets[index], memory, parameters);
         memory.write(std::cout);
      }
      processor.interpret(instruction, length, address, targets[targets.size()-1], memoryState, parameters);
      memoryState.write(std::cout);
   }
   std::cout.flush();
   return 0;
}
