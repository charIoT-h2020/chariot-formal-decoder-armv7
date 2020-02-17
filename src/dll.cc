#include "dll.h"

#ifdef __unix__
# include <dlfcn.h>
#elif _WIN32
# include <windows.h>
#else
# error \
  Unrecognized platform. Please implement functions of this file for your platform.
#endif

#include <sstream>

#include <iostream>
#include <stdexcept>
#include <cassert>

#ifdef __unix__

namespace DLL
{


Library::Library() : _lib(nullptr) {}


Library::Library(std::string const& libName)
  : _lib(nullptr)
  { _lib = dlopen(libName.c_str(), RTLD_LAZY);}


Library::~Library(void)
  { if (_lib) dlclose(_lib);}


bool Library::isOpen() const { return _lib; }

DLL::Library::operator bool() const { return _lib; }

void Library::loadSymbol(const std::string &symbol, void **fun)
{
  assert(_lib);
  *fun = dlsym(_lib, symbol.c_str());
  char* err = dlerror();
  if (err) throw std::runtime_error(err);
}

} // DLL

#elif _WIN32

namespace DLL
{

Library::Library(std::string const& libName)
  { _lib = LoadLibrary(libName.c_str()); }

Library::~Library() { FreeLibrary(_lib); }

bool Library::isOpen() const
  { return _lib; }

void Library::loadSymbol(const std::string &symbol, void **fun)
{
  *fun = reinterpret_cast<void*>(GetProcAddress(_lib, symbol.c_str()));
  if (*fun) return;
  std::stringstream ss;
  static std::string msg;
  ss << "Unable to load symbol: Error "
     << (long unsigned int) GetLastError();
  msg = ss.str();
  throw std::runtime_error(msg.c_str());
}

} // DLL

#endif
