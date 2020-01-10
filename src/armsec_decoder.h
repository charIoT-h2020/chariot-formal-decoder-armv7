/////////////////////////////////
//
// Library   : Static Analysis
// Unit      : armsec
// File      : armsec_decoder.h
// Copyright : CEA LIST - 2020
//
// Description :
//   Definition of a generic C Interface to manipulate abstract domains
//   = interval, disjunctions, ...
//

#pragma once

#include "memsec_callback.h"

#if defined(_WIN32)
#define DLL_CDECL __cdecl
#else
#define DLL_CDECL 
#endif

#if defined(_WIN32) && defined(_USRDLL)
#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // DLL_EXPORTS
#else
#define DLL_API
#endif // _USRDLL

#ifdef _MSC_VER
#pragma pack(push,4)
#endif

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(_MSC_VER) && !defined(__cplusplus)
#define inline __inline
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SAL_VERSION

#define _In_ 
#define _Out_ 
#define _Inout_ 
#define _In_opt_ 

#endif

typedef struct _InterpretParameters InterpretParameters;
typedef struct _MemoryModel MemoryModel;
typedef struct _MemoryModelFunctions MemoryModelFunctions;

typedef struct _TargetAddresses {
   uint64_t* addresses;
   int addresses_array_size;

   uint64_t* (*realloc_addresses)(uint64_t* old_addresses, int old_size,
         int* new_size, void* address_container);
   void* address_container;
} TargetAddresses;

DLL_API bool armsec_next_targets(char* instruction_buffer, size_t buffer_size,
      uint64_t address, TargetAddresses target_addresses,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      InterpretParameters* parameters,
      uint64_t* result_addresses, int* result_length);

DLL_API bool armsec_interpret(char* instruction_buffer, size_t buffer_size,
      uint64_t address, uint64_t target_address,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      InterpretParameters* parameters);

#ifdef __cplusplus
}
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif


