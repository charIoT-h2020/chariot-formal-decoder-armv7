#pragma once

#include <iosfwd>
#include <string>

namespace DLL
{

class Library
{
public:
#ifdef __unix__
  typedef void* type;
#elif _WIN32
  typedef HMODULE type;
#endif

  Library();
  Library(std::string const& libName);
  ~Library();

  bool isOpen() const;
  operator bool() const;

  template<typename _Func>
  inline void loadSymbol(std::string const& symbol, _Func* fun)
    { loadSymbol(symbol, reinterpret_cast<void**>(fun));}

private:
  void loadSymbol(std::string const& symbol, void** fun);
  type _lib;
};

}

