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
#include "armsec_decoder.h"

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

class MemoryState {
  private:
   static MemoryModelFunctions functions;

  public:
   MemoryModelFunctions* getFunctions() const { return &functions; }
   bool loadDomain(const char* domainFile) { return true; }
   void write(std::ostream& out) const {}
};

MemoryModelFunctions MemoryState::functions={};

class MemoryInterpretParameters {

};

class Processor {
  private:
   void* pvContent;

   static uint64_t* reallocAddresses(uint64_t* old_addresses, int old_size,
         int* new_size, void* address_container)
      {  auto* container = reinterpret_cast<std::vector<uint64_t>*>(address_container);
         assert(container->size() == (size_t) old_size
               && *old_addresses == (*container)[0]);
         if (old_size < 6)
            *new_size = 6;
         else
            *new_size = old_size*3/2;
         container->insert(container->end(), (*new_size-old_size), 0);
         *old_addresses == (*container)[0];
      }

  public:
   Processor(void* content) : pvContent(content) {}
   Processor(Processor&& source) : pvContent(source.pvContent)
      {  source.pvContent = nullptr; }
   ~Processor() { free_processor(pvContent); }

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
         bool isValid = armsec_next_targets(this, nextInstruction, length, address,
               argument, reinterpret_cast<MemoryModel*>(&memory), memory.getFunctions(),
               reinterpret_cast<InterpretParameters*>(&parameters));
         assert(isValid);
         return std::move(result);
      }

   void interpret(char* instruction, int length, uint64_t address,
         uint64_t targetAddress, MemoryState& memoryState, MemoryInterpretParameters& parameters)
      {  bool isValid = armsec_interpret(this, instruction, length, address, targetAddress,
               reinterpret_cast<MemoryModel*>(&memoryState), memoryState.getFunctions(),
               reinterpret_cast<InterpretParameters*>(&parameters));
         assert(isValid);
      }
};

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
   bool ok = memoryState.loadDomain(processArgument.hasDomain() ? processArgument.getDomain() : "domsec.so");
   if (!ok) {
      std::cerr << "unable to find domain file "
         << (processArgument.hasDomain() ? processArgument.getDomain() : "domsec.so") << std::endl;
      return 1;
   }

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
   MemoryInterpretParameters parameters;
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
