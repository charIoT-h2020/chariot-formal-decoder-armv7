#include "armsec_decoder.h"
#include "unisim/component/cxx/processor/arm/disasm.hh"
#include "unisim/component/cxx/processor/arm/psr.hh"
#include "unisim/util/identifier/identifier.hh"
#include "top_thumb.tcc"

#include <cassert>

#define CP15ENCODE( CRN, OPC1, CRM, OPC2 ) ((OPC1 << 12) | (CRN << 8) | (CRM << 4) | (OPC2 << 0))

// template <typename ARCH, unsigned OPSIZE> struct TypeFor {};

// template <typename ARCH> struct TypeFor<ARCH, 8> { typedef typename ARCH:: S8 S; typedef typename ARCH:: U8 U; };
// template <typename ARCH> struct TypeFor<ARCH,16> { typedef typename ARCH::S16 S; typedef typename ARCH::U16 U; };
// template <typename ARCH> struct TypeFor<ARCH,32> { typedef typename ARCH::S32 S; typedef typename ARCH::U32 U; typedef typename ARCH::F32 F; };
// template <typename ARCH> struct TypeFor<ARCH,64> { typedef typename ARCH::S64 S; typedef typename ARCH::U64 U; typedef typename ARCH::F64 F; };

template <bool test> struct StaticAssert {};
template <> struct StaticAssert<true> { static void check() {}; };

struct ScalarType
{
  enum id_t { VOID, BOOL, U8, U16, U32, U64, S8, S16, S32, S64, F32, F64 };
  static id_t IntegerType( bool is_signed, unsigned bits )
  {
    switch (bits) {
    default: throw VOID;
    case 8:  return is_signed ? S8 :  U8;
    case 16: return is_signed ? S16 : U16;
    case 32: return is_signed ? S32 : U32;
    case 64: return is_signed ? S64 : U64;
    }
    return VOID;
  }
  ScalarType( id_t id )
    : name(0), bitsize(0), is_signed(false), is_integer(false)
  {
    switch (id)
      {
      case VOID: bitsize = 0;  is_integer = false; is_signed = false; name = "VOID"; break;
      case BOOL: bitsize = 1;  is_integer = true;  is_signed = false; name = "BOOL"; break;
      case U8:   bitsize = 8;  is_integer = true;  is_signed = false; name = "U8";  break;
      case S8:   bitsize = 8;  is_integer = true;  is_signed = true;  name = "S8";  break;
      case U16:  bitsize = 16; is_integer = true;  is_signed = false; name = "U16"; break;
      case S16:  bitsize = 16; is_integer = true;  is_signed = true;  name = "S16"; break;
      case U32:  bitsize = 32; is_integer = true;  is_signed = false; name = "U32"; break;
      case S32:  bitsize = 32; is_integer = true;  is_signed = true;  name = "S32"; break;
      case U64:  bitsize = 64; is_integer = true;  is_signed = false; name = "U64"; break;
      case S64:  bitsize = 64; is_integer = true;  is_signed = true;  name = "S64"; break;
      case F32:  bitsize = 32; is_integer = false; is_signed = true;  name = "F32"; break;
      case F64:  bitsize = 64; is_integer = false; is_signed = true;  name = "F64"; break;
      }
  }
  char const* name;
  unsigned bitsize;
  bool is_signed, is_integer;
};
  

struct Processor;
class MemoryState;
class DomainValue {
  private:
   DomainElement deValue;
   struct _DomainElementFunctions* pfFunctions;
   DomainEvaluationEnvironment* peEnv;

  protected:
   friend class MemoryState;
   DomainElement& svalue() { return deValue; }
   const DomainElement& value() const { return deValue; }
   bool hasFunctionTable() const { return pfFunctions; }
   struct _DomainElementFunctions& functionTable() const { assert(pfFunctions); return *pfFunctions; }
   DomainEvaluationEnvironment* env() const { return peEnv; }

  public:
   DomainValue() : pfFunctions(nullptr), peEnv(nullptr) {}
   class Empty {};
   DomainValue(Empty, const DomainValue& ref)
      :  deValue(DomainBitElement{}), pfFunctions(ref.pfFunctions), peEnv(ref.peEnv) {}
   DomainValue(DomainElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
      :  deValue(std::move(value)), pfFunctions(functions), peEnv(env) {}
   DomainValue(Processor& processor);
   DomainValue(DomainElement&& value, Processor& processor);
   DomainValue(DomainElement&& value, const DomainValue& source)
      :  deValue(value), pfFunctions(source.pfFunctions),
         peEnv(source.peEnv)
      {  value.content = nullptr; }
   DomainValue(DomainValue&& source)
      :  deValue(source.deValue), pfFunctions(source.pfFunctions),
         peEnv(source.peEnv)
      {  source.deValue.content = nullptr; }
   DomainValue(const DomainValue& source)
      :  deValue{ nullptr }, pfFunctions(source.pfFunctions),
         peEnv(source.peEnv)
      {  if (source.deValue.content) {
            assert(pfFunctions);
            deValue = (*pfFunctions->clone)(source.deValue);
         }
      }
   DomainValue& operator=(DomainValue&& source)
      {  if (this == &source)
            return *this;
         if (deValue.content) {
            assert(pfFunctions);
            (*pfFunctions->free)(&deValue);
         }
         pfFunctions = source.pfFunctions;
         peEnv = source.peEnv;
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
         peEnv = source.peEnv;
         if (source.deValue.content) {
            assert(pfFunctions);
            deValue = (*pfFunctions->clone)(source.deValue);
         }
         return *this;
      }
   ~DomainValue()
      {  if (deValue.content && pfFunctions) (*pfFunctions->free)(&deValue); }

   void clear()
      {  if (deValue.content) {
            assert(pfFunctions);
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
};

class DomainMultiBitValue;
class DomainBitValue : public DomainValue {
  public:
   DomainBitValue() {}
   DomainBitValue(Empty empty, const DomainValue& ref)
      :  DomainValue(empty, ref) {}
   DomainBitValue(DomainBitElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
      :  DomainValue(std::move(value), functions, env) {}
   DomainBitValue(Processor& processor);
   DomainBitValue(DomainBitElement&& value, Processor& processor);
   DomainBitValue(DomainBitElement&& value, const DomainValue& source);
   explicit DomainBitValue(bool value, Processor& processor)
      :  DomainValue(processor)
      {  svalue() = (*functionTable().bit_create_constant)(value); }
   DomainBitValue(DomainBitValue&& source) = default;
   DomainBitValue(const DomainBitValue& source) = default;
   DomainBitValue& operator=(DomainBitValue&& source) = default;
   DomainBitValue& operator=(const DomainBitValue& source) = default;

   DomainBitValue& setToConstant(bool value)
      {  svalue() = (*functionTable().bit_create_constant)(value); return *this; }
   DomainBitValue& setToUndefined(bool isSymbolic)
      {  svalue() = (*functionTable().bit_create_top)(isSymbolic); return *this; }
   DomainMultiBitValue castToMultiBit(int sizeInBits, bool isSigned) const;

   DomainBitValue operator~() const
      {  return DomainBitValue((*functionTable().bit_create_unary_apply)
               (value(), DBUONegate, env()), *this);
      }
   DomainBitValue operator!() const
      {  return DomainBitValue((*functionTable().bit_create_unary_apply)
               (value(), DBUONegate, env()), *this);
      }
   DomainBitValue operator|(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_create_binary_apply)
               (value(), DBBOOr, source.value(), env()), *this);
      }
   DomainBitValue operator&(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_create_binary_apply)
               (value(), DBBOAnd, source.value(), env()), *this);
      }
   DomainBitValue operator^(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_create_binary_apply)
               (value(), DBBOExclusiveOr, source.value(), env()), *this);
      }
   DomainBitValue operator||(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_create_binary_apply)
               (value(), DBBOOr, source.value(), env()), *this);
      }
   DomainBitValue operator&&(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_create_binary_apply)
               (value(), DBBOAnd, source.value(), env()), *this);
      }

   DomainBitValue& operator|=(const DomainBitValue& source)
      {  (*functionTable().bit_binary_apply_assign)
               (&svalue(), DBBOOr, source.value(), env());
         return *this;
      }
   DomainBitValue operator&=(const DomainBitValue& source)
      {  (*functionTable().bit_binary_apply_assign)
               (&svalue(), DBBOAnd, source.value(), env());
         return *this;
      }
   DomainBitValue operator^=(const DomainBitValue& source)
      {  (*functionTable().bit_binary_apply_assign)
               (&svalue(), DBBOExclusiveOr, source.value(), env());
         return *this;
      }

   DomainBitValue operator==(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareEqual, source.value(), env()), *this);
         return *this;
      }
   DomainBitValue operator!=(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareDifferent, source.value(), env()), *this);
         return *this;
      }
   DomainBitValue operator<=(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareLessOrEqual, source.value(), env()), *this);
         return *this;
      }
   DomainBitValue operator>=(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareGreaterOrEqual, source.value(), env()), *this);
         return *this;
      }
   DomainBitValue operator<(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareLess, source.value(), env()), *this);
         return *this;
      }
   DomainBitValue operator>(const DomainBitValue& source) const
      {  return DomainBitValue((*functionTable().bit_binary_compare_domain)
               (value(), DBCOCompareGreater, source.value(), env()), *this);
         return *this;
      }

   bool isConstant(bool* value) const
      {  return (*functionTable().bit_is_constant_value)(this->value(), value); }
};

struct DomainMultiBitValue : public DomainValue {
  private:
   bool fSigned;

  public:
   DomainMultiBitValue() : fSigned(false) {}
   DomainMultiBitValue(Empty empty, const DomainValue& ref)
      :  DomainValue(empty, ref), fSigned(false) {}
   DomainMultiBitValue(DomainMultiBitElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
      :  DomainValue(std::move(value), functions, env), fSigned(false) {}
   DomainMultiBitValue(Processor& processor);
   DomainMultiBitValue(DomainMultiBitElement&& value, Processor& processor, bool isSigned);
   DomainMultiBitValue(DomainMultiBitElement&& value, const DomainValue& source, bool isSigned)
      :  DomainValue(std::move(value), source), fSigned(isSigned) {}
   explicit DomainMultiBitValue(DomainIntegerConstant value, Processor& processor, bool isSigned)
      :  DomainValue(processor), fSigned(isSigned)
      {  svalue() = (*functionTable().multibit_create_constant)(value); }
   DomainMultiBitValue(DomainMultiBitValue&& source) = default;
   DomainMultiBitValue(const DomainMultiBitValue& source) = default;
   DomainMultiBitValue& operator=(DomainMultiBitValue&& source) = default;
   DomainMultiBitValue& operator=(const DomainMultiBitValue& source) = default;

   DomainMultiBitValue& setToConstant(DomainIntegerConstant value)
      {  svalue() = (*functionTable().multibit_create_constant)(value);
         fSigned = value.isSigned;
         return *this;
      }
   DomainMultiBitValue& setToUndefined(int sizeInBits, bool isSymbolic, bool isSigned)
      {  svalue() = (*functionTable().multibit_create_top)(sizeInBits, isSymbolic);
         fSigned = isSigned;
         return *this;
      }
   DomainBitValue castBit()
      {  return DomainBitValue((*functionTable().multibit_create_cast_bit)
               (value(), env()), *this);
      }
   DomainBitValue castShiftBit(int shift)
      {  return DomainBitValue((*functionTable().multibit_create_cast_shift_bit)
               (value(), shift, env()), *this);
      }

   DomainMultiBitValue operator~() const
      {  return DomainMultiBitValue((*functionTable().multibit_create_unary_apply)
               (value(), DMBUOBitNegate, env()), *this, fSigned);
      }
   DomainMultiBitValue operator-() const
      {  return DomainMultiBitValue((*functionTable().multibit_create_unary_apply)
               (value(), DMBUOOppositeSigned, env()), *this, fSigned);
      }
   DomainMultiBitValue& operator++()
      {  (*functionTable().multibit_unary_apply_assign)
               (&svalue(), fSigned ? DMBUONextSigned : DMBUONextUnsigned, env());
         return *this;
      }
   DomainMultiBitValue& operator--()
      {  (*functionTable().multibit_unary_apply_assign)
               (&svalue(), fSigned ? DMBUOPrevSigned : DMBUOPrevUnsigned, env());
         return *this;
      }
   DomainMultiBitValue operator+(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), fSigned ? DMBBOPlusSigned : DMBBOPlusUnsigned, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator-(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), fSigned ? DMBBOMinusSigned : DMBBOMinusUnsigned, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator*(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), fSigned ? DMBBOTimesSigned : DMBBOTimesUnsigned, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator/(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), fSigned ? DMBBODivideSigned : DMBBODivideUnsigned, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator%(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), fSigned ? DMBBOModuloSigned : DMBBOModuloUnsigned, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator|(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), DMBBOBitOr, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator&(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), DMBBOBitAnd, source.value(), env()), *this, fSigned);
      }
   DomainMultiBitValue operator^(const DomainMultiBitValue& source) const
      {  return DomainMultiBitValue((*functionTable().multibit_create_binary_apply)
               (value(), DMBBOBitExclusiveOr, source.value(), env()), *this, fSigned);
      }

   DomainMultiBitValue& operator+=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), fSigned ? DMBBOPlusSigned : DMBBOPlusUnsigned, source.value(), env());
         return *this;
      }
   DomainMultiBitValue& operator-=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), fSigned ? DMBBOMinusSigned : DMBBOMinusUnsigned, source.value(), env());
         return *this;
      }
   DomainMultiBitValue& operator*=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), fSigned ? DMBBOTimesSigned : DMBBOTimesUnsigned, source.value(), env());
         return *this;
      }
   DomainMultiBitValue& operator/=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), fSigned ? DMBBODivideSigned : DMBBODivideUnsigned, source.value(), env());
         return *this;
      }
   DomainMultiBitValue& operator%=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), fSigned ? DMBBOModuloSigned : DMBBOModuloUnsigned, source.value(), env());
         return *this;
      }
   DomainMultiBitValue& operator|=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), DMBBOBitOr, source.value(), env());
         return *this;
      }
   DomainMultiBitValue operator&=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), DMBBOBitAnd, source.value(), env());
         return *this;
      }
   DomainMultiBitValue operator^=(const DomainMultiBitValue& source)
      {  (*functionTable().multibit_binary_apply_assign)
               (&svalue(), DMBBOBitExclusiveOr, source.value(), env());
         return *this;
      }

   DomainBitValue operator==(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), DMBCOCompareEqual, source.value(), env()), *this);
      }
   DomainBitValue operator!=(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), DMBCOCompareDifferent, source.value(), env()), *this);
      }
   DomainBitValue operator<=(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), fSigned ? DMBCOCompareLessOrEqualSigned : DMBCOCompareLessOrEqualUnsigned, source.value(), env()), *this);
      }
   DomainBitValue operator>=(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), fSigned ? DMBCOCompareGreaterOrEqualSigned : DMBCOCompareGreaterOrEqualUnsigned, source.value(), env()), *this);
      }
   DomainBitValue operator<(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), fSigned ? DMBCOCompareLessSigned : DMBCOCompareLessUnsigned, source.value(), env()), *this);
      }
   DomainBitValue operator>(const DomainMultiBitValue& source) const
      {  return DomainBitValue((*functionTable().multibit_binary_compare_domain)
               (value(), fSigned ? DMBCOCompareGreaterSigned : DMBCOCompareGreaterUnsigned, source.value(), env()), *this);
      }

   friend DomainMultiBitValue RotateRight(const DomainMultiBitValue& first, const DomainMultiBitValue& second)
      {  return DomainMultiBitValue((*first.functionTable().multibit_create_binary_apply)
               (first.value(), DMBBORightRotate, second.value(), first.env()), first, first.fSigned);
      }

   bool isConstant(DomainIntegerConstant* value) const
      {  return (*functionTable().multibit_is_constant_value)(this->value(), value); }
};

struct DomainMultiFloatValue : public DomainValue {
  public:
   DomainMultiFloatValue() {}
   DomainMultiFloatValue(Empty empty, const DomainValue& ref)
      :  DomainValue(empty, ref) {}
   DomainMultiFloatValue(DomainMultiFloatElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
      :  DomainValue(std::move(value), functions, env) {}
   DomainMultiFloatValue(Processor& processor);
   DomainMultiFloatValue(DomainMultiFloatElement&& value, Processor& processor);
   DomainMultiFloatValue(DomainMultiFloatElement&& value, const DomainValue& source)
      :  DomainValue(std::move(value), source) {}
   explicit DomainMultiFloatValue(DomainFloatingPointConstant value, Processor& processor)
      :  DomainValue(processor)
      {  svalue() = (*functionTable().multifloat_create_constant)(value); }
   DomainMultiFloatValue(DomainMultiFloatValue&& source) = default;
   DomainMultiFloatValue(const DomainMultiFloatValue& source) = default;
   DomainMultiFloatValue& operator=(DomainMultiFloatValue&& source) = default;
   DomainMultiFloatValue& operator=(const DomainMultiFloatValue& source) = default;

   void setToConstant(DomainFloatingPointConstant value)
      {  svalue() = (*functionTable().multifloat_create_constant)(value); }
   void setToUndefined(int sizeInBits, bool isSymbolic)
      {  svalue() = (*functionTable().multifloat_create_top)(sizeInBits, isSymbolic); }

   DomainMultiFloatValue operator-() const
      {  return DomainMultiFloatValue((*functionTable().multifloat_create_unary_apply)
               (value(), DMFUOOpposite, env()), *this);
      }
   DomainMultiFloatValue operator+(const DomainMultiFloatValue& source) const
      {  return DomainMultiFloatValue((*functionTable().multifloat_create_binary_apply)
               (value(), DMFBOPlus, source.value(), env()), *this);
      }
   DomainMultiFloatValue operator-(const DomainMultiFloatValue& source) const
      {  return DomainMultiFloatValue((*functionTable().multifloat_create_binary_apply)
               (value(), DMFBOMinus, source.value(), env()), *this);
      }
   DomainMultiFloatValue operator*(const DomainMultiFloatValue& source) const
      {  return DomainMultiFloatValue((*functionTable().multifloat_create_binary_apply)
               (value(), DMFBOTimes, source.value(), env()), *this);
      }
   DomainMultiFloatValue operator/(const DomainMultiFloatValue& source) const
      {  return DomainMultiFloatValue((*functionTable().multifloat_create_binary_apply)
               (value(), DMFBODivide, source.value(), env()), *this);
      }

   DomainMultiFloatValue& operator+=(const DomainMultiFloatValue& source)
      {  (*functionTable().multifloat_binary_apply_assign)
               (&svalue(), DMFBOPlus, source.value(), env());
         return *this;
      }
   DomainMultiFloatValue& operator-=(const DomainMultiFloatValue& source)
      {  (*functionTable().multifloat_binary_apply_assign)
               (&svalue(), DMFBOMinus, source.value(), env());
         return *this;
      }
   DomainMultiFloatValue& operator*=(const DomainMultiFloatValue& source)
      {  (*functionTable().multifloat_binary_apply_assign)
               (&svalue(), DMFBOTimes, source.value(), env());
         return *this;
      }
   DomainMultiFloatValue& operator/=(const DomainMultiFloatValue& source)
      {  (*functionTable().multifloat_binary_apply_assign)
               (&svalue(), DMFBODivide, source.value(), env());
         return *this;
      }

   DomainBitValue operator==(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareEqual, source.value(), env()), *this);
      }
   DomainBitValue operator!=(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareDifferent, source.value(), env()), *this);
      }
   DomainBitValue operator<=(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareLessOrEqual, source.value(), env()), *this);
      }
   DomainBitValue operator>=(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareGreaterOrEqual, source.value(), env()), *this);
      }
   DomainBitValue operator<(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareLess, source.value(), env()), *this);
      }
   DomainBitValue operator>(const DomainMultiFloatValue& source) const
      {  return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
               (value(), DMFCOCompareGreater, source.value(), env()), *this);
      }

   bool isConstant(DomainFloatingPointConstant* value) const
      {  return (*functionTable().multifloat_is_constant_value)(this->value(), value); }
};

class MemoryState {
  private:
   MemoryModel* pmModel;
   struct _MemoryModelFunctions* pfFunctions;
   InterpretParameters* pParameters;
   DomainEvaluationEnvironment* peDomainEnv;
   mutable unsigned uErrors; /* set of MemoryEvaluationErrorFlags */

  public:
   MemoryState()
      :  pmModel(nullptr), pfFunctions(nullptr), pParameters(nullptr),
         peDomainEnv(nullptr), uErrors(0U) {}
   MemoryState(Processor& proc);

   bool hasError() const { return uErrors; }
   const unsigned& errors() const { return uErrors; }
   void clearErrors() { uErrors = 0U; }

   void setNumberOfRegisters(int number)
      {  (*pfFunctions->set_number_of_registers)(pmModel, number); }
   void setRegisterValue(int registerIndex, DomainValue& value)
      {  (*pfFunctions->set_register_value)(pmModel, registerIndex,
            &value.svalue(), pParameters, &uErrors);
      }

   DomainBitValue getRegisterValueAsBit(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainBitValue(std::move(result), domainFunctions, peDomainEnv);
      }
   DomainMultiBitValue getRegisterValueAsMultiBit(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainMultiBitValue(std::move(result), domainFunctions, peDomainEnv);
      }
   DomainMultiFloatValue getRegisterValueAsMultiFloat(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainMultiFloatValue(std::move(result), domainFunctions, peDomainEnv);
      }

   DomainMultiBitValue loadMultiBitValue(
         DomainMultiBitValue&& indirectAddress, size_t size) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_value)
               (pmModel, &indirectAddress.svalue(), size, pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue(std::move(result), domainFunctions, peDomainEnv);
      }
   DomainMultiBitValue loadMultiBitDisjunctionValue(
         DomainMultiBitValue&& indirectAddress, size_t size) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_disjunctive_value)
               (pmModel, &indirectAddress.svalue(), size, pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue(std::move(result), domainFunctions, peDomainEnv);
      }
   DomainMultiFloatValue loadMultiFloatValue(
         DomainMultiBitValue&& indirectAddress, size_t size) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multifloat_value)
               (pmModel, &indirectAddress.svalue(), size, pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiFloatValue(std::move(result), domainFunctions, peDomainEnv);
      }

   void storeMultiBitValue(DomainMultiBitValue&& indirectAddress,
         DomainMultiBitValue&& value)
      {  (*pfFunctions->store_value)(pmModel, &indirectAddress.svalue(),
               &value.svalue(), pParameters, &uErrors);
      }
   void storeMultiFloatValue(DomainMultiBitValue&& indirectAddress,
         DomainMultiFloatValue&& value)
      {  (*pfFunctions->store_value)(pmModel, &indirectAddress.svalue(),
               &value.svalue(), pParameters, &uErrors);
      }
   void constraintStoreValue(DomainMultiBitValue&& indirectAddress,
         DomainMultiBitValue&& value, unsigned indirectRegister)
      {  (*pfFunctions->constraint_store_value)(pmModel, &indirectAddress.svalue(),
            &value.svalue(), indirectRegister, pParameters, &uErrors);
      }
   void constraintAddress(DomainMultiBitValue&& indirectAddress,
         DomainMultiBitValue&& value)
      {  (*pfFunctions->constraint_address)(pmModel, &indirectAddress.svalue(),
            &value.svalue(), pParameters, &uErrors);
      }
};

struct Processor
{
  //   =====================================================================
  //   =                           Configuration                           =
  //   =====================================================================
  struct Unimplemented {};
  struct Undefined {};
    
  struct Config
  {
    // Following a standard armv7-a configuration
    static uint32_t const model = unisim::component::cxx::processor::arm::ARMEMU;
    static bool const     insns4T = true;
    static bool const     insns5E = true;
    static bool const     insns5J = true;
    static bool const     insns5T = true;
    static bool const     insns6  = true;
    static bool const     insnsRM = false;
    static bool const     insnsT2 = true;
    static bool const     insns7  = true;
  };
    
  //   =====================================================================
  //   =                             Data Types                            =
  //   =====================================================================
  typedef DomainMultiFloatValue  F64;
  typedef DomainMultiFloatValue  F32;
  typedef DomainBitValue         BOOL;
  typedef DomainMultiBitValue    U8;
  typedef DomainMultiBitValue    U16;
  typedef DomainMultiBitValue    U32;
  typedef DomainMultiBitValue    U64;
  typedef DomainMultiBitValue    S8;
  typedef DomainMultiBitValue    S16;
  typedef DomainMultiBitValue    S32;
  typedef DomainMultiBitValue    S64;

#if 0
  typedef unisim::util::symbolic::FP                   FP;
  typedef unisim::util::symbolic::ScalarType           ScalarType;
  
  typedef unisim::util::symbolic::binsec::ActionNode   ActionNode;
  typedef unisim::util::symbolic::binsec::Store        Store;
  typedef unisim::util::symbolic::binsec::Branch       Br;

  template <typename RID>
  struct RegRead : public unisim::util::symbolic::binsec::RegRead
  {
    typedef RegRead<RID> this_type;
    typedef unisim::util::symbolic::binsec::RegRead Super;
    RegRead( RID _id, ScalarType::id_t _tp ) : Super(), tp(_tp), id(_id) {}
    virtual this_type* Mutate() const { return new this_type( *this ); }
    virtual ScalarType::id_t GetType() const { return tp; }
    virtual void GetRegName( std::ostream& sink ) const { sink << id.c_str(); }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<RegRead const&>( rhs ) ); }
    int compare( RegRead const& rhs ) const { if (int delta = int(tp) - int(rhs.tp)) return delta; if (int delta = id.cmp( rhs.id )) return delta; return Super::compare(rhs); }

    ScalarType::id_t tp;
    RID id;
  };

  template <typename RID>
  static Expr newRegRead( RID id, ScalarType::id_t tp ) { return new RegRead<RID>( id, tp ); }

  struct ForeignRegister : public unisim::util::symbolic::binsec::RegRead
  {
    typedef unisim::util::symbolic::binsec::RegRead Super;
    ForeignRegister( uint8_t _mode, unsigned _idx )
      : Super(), idx(_idx), mode(_mode)
    {
      if (mode == SYSTEM_MODE) mode = USER_MODE;
    }
    virtual ForeignRegister* Mutate() const { return new ForeignRegister( *this ); }
    virtual ScalarType::id_t GetType() const { return ScalarType::U32; }
    
    char const* mode_ident() const
    {
      switch (mode)
        {
        case USER_MODE: return "usr";
        case FIQ_MODE: return "fiq";
        case IRQ_MODE: return "irq";
        case SUPERVISOR_MODE: return "svc";
        case MONITOR_MODE: return "mon";
        case ABORT_MODE: return "abt";
        case HYPERVISOR_MODE: return "hyp";
        case UNDEFINED_MODE: return "und";
        }
      throw 0;
      return "";
    }

    virtual void GetRegName( std::ostream& sink ) const
    {
      sink << (RegID("r0") + idx).c_str() << '_' << mode_ident();
    }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<ForeignRegister const&>( rhs ) ); }
    int compare( ForeignRegister const& rhs ) const
    {
      if (int delta = int(mode) - int(rhs.mode)) return delta;
      return idx - rhs.idx;
    }
    
    unsigned idx;
    uint8_t mode;
  };
  
  template <typename RID>
  struct RegWrite : public unisim::util::symbolic::binsec::RegWrite
  {
    typedef RegWrite<RID> this_type;
    typedef unisim::util::symbolic::binsec::RegWrite Super;
    RegWrite( RID _id, Expr const& _value ) : Super(_value), id(_id) {}
    virtual this_type* Mutate() const { return new this_type( *this ); }
    virtual ScalarType::id_t GetType() const { return ScalarType::VOID; }
    virtual void GetRegName( std::ostream& sink ) const { sink << id.c_str(); }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<RegWrite const&>( rhs ) ); }
    int compare( RegWrite const& rhs ) const { if (int delta = id.cmp( rhs.id )) return delta; return Super::compare( rhs ); }
    
    RID id;
  };

  template <typename RID>
  static Expr newRegWrite( RID id, Expr const& value ) { return new RegWrite<RID>( id, value ); }
  
  struct PCWrite : public Br
  {
    PCWrite( Expr const& value, Br::type_t bt ) : Br( value, bt ) {}
    virtual PCWrite* Mutate() const { return new PCWrite( *this ); }
    virtual void GetRegName( std::ostream& sink ) const { sink << "pc"; }
    virtual ScalarType::id_t GetType() const { return ScalarType::VOID; }
  };
#endif

  struct ITCond {};
    
  struct Mode
  {
    Mode() {}
    bool     HasBR( unsigned index ) { return false; }
    bool     HasSPSR() { return false; }
    void     SetSPSR(U32 const& value) {}
    U32      GetSPSR() { throw Unimplemented(); return U32(); }
    void     Swap( Processor& ) {}
  };
    
#if 0
  typedef std::map<std::pair<uint8_t,uint32_t>,Expr> ForeignRegisters;
#endif
  
  struct CP15Reg
  {
    virtual            ~CP15Reg() {}
    virtual unsigned    RequiredPL() { return 1; }
    virtual void        Write( Processor& proc, U32 const& value ) { throw Unimplemented(); }
    virtual U32         Read( Processor& proc ) { throw Unimplemented(); return U32(); }
    virtual char const* Describe() = 0;
  };

#if 0
  struct Load : public unisim::util::symbolic::binsec::Load
  {
    Load( Expr const& addr, unsigned size, unsigned alignment, bool bigendian )
      : unisim::util::symbolic::binsec::Load(addr, size, alignment, bigendian)
    {}
  };
#endif
  //   =====================================================================
  //   =                      Construction/Destruction                     =
  //   =====================================================================
  
  struct StatusRegister
  {
    enum InstructionSet { Arm, Thumb, Jazelle, ThumbEE };
      
    StatusRegister()
      : iset(Arm)                               // Default is ARM instruction set
      , bigendian(false)                        // Default is Little Endian
      , mode(SUPERVISOR_MODE)                   // Default is SUPERVISOR_MODE
      , outitb(false)                           // Force status as if outside ITBlock
    {}

    bool IsThumb() const { return iset == Thumb; }
      
    InstructionSet iset;
    bool bigendian;
    uint8_t mode;
    bool outitb;
  };
  
  struct PSR : public StatusRegister
  {
    typedef unisim::component::cxx::processor::arm::RegisterField<31,1> NRF; /* Negative Integer Condition Flag */
    typedef unisim::component::cxx::processor::arm::RegisterField<30,1> ZRF; /* Zero     Integer Condition Flag */
    typedef unisim::component::cxx::processor::arm::RegisterField<29,1> CRF; /* Carry    Integer Condition Flag */
    typedef unisim::component::cxx::processor::arm::RegisterField<28,1> VRF; /* Overflow Integer Condition Flag */
    //typedef unisim::component::cxx::processor::arm::RegisterField<27,1> QRF; /* Cumulative saturation flag */
      
    typedef unisim::component::cxx::processor::arm::RegisterField<28,4> NZCVRF; /* Grouped Integer Condition Flags */
      
      
    typedef unisim::component::cxx::processor::arm::RegisterField<24,1> JRF; /* Jazelle execution state bit */
    typedef unisim::component::cxx::processor::arm::RegisterField< 9,1> ERF; /* Endianness execution state */
    typedef unisim::component::cxx::processor::arm::RegisterField< 5,1> TRF; /* Thumb execution state bit */
      
    typedef unisim::component::cxx::processor::arm::RegisterField< 0,5> MRF; /* Mode field */
      
    typedef unisim::component::cxx::processor::arm::RegisterField<10,6> ITHIRF;
    typedef unisim::component::cxx::processor::arm::RegisterField<25,2> ITLORF;
      
    typedef unisim::component::cxx::processor::arm::RegisterField< 0,32> ALLRF;
      
    static uint32_t const bg_mask = 0x08ff01c0; /* Q, 23-20, GE[3:0], A, I, F, are not handled for now */
      
  private:
    PSR( PSR const& );
  public:
    PSR() : proc(nullptr) {}
    void set( Processor& p, StatusRegister const& ref, MemoryState& memory)
      { // StatusRegister::operator=(ref);
        proc = &p;
        n = (memory.getRegisterValueAsBit(RegID("n").code));
        z = (memory.getRegisterValueAsBit(RegID("z").code));
        c = (memory.getRegisterValueAsBit(RegID("c").code));
        v = (memory.getRegisterValueAsBit(RegID("v").code));
        itstate = (ref.outitb
            ? std::move(U8(p).setToConstant(DomainIntegerConstant{8, false, 0U}))
            : memory.getRegisterValueAsMultiBit(RegID("itstate").code));
        bg = (memory.getRegisterValueAsMultiBit(RegID("cpsr").code));
      }
    
    bool   GetJ() const { return (iset == Jazelle) or (iset == ThumbEE); }
    bool   GetT() const { return (iset ==   Thumb) or (iset == ThumbEE); }

    template <typename RF>
    void   Set( RF const& _, U32 const& value )
    {
      StaticAssert<(RF::pos > 31) or ((RF::pos + RF::size) <= 28)>::check(); // NZCV
      StaticAssert<(RF::pos > 26) or ((RF::pos + RF::size) <= 24)>::check(); // ITLO, J
      StaticAssert<(RF::pos > 15) or ((RF::pos + RF::size) <=  9)>::check(); // ITHI, E
      StaticAssert<(RF::pos >  5) or ((RF::pos + RF::size) <=  0)>::check(); // T, MODE
        
      return _.Set( bg, value );
    }
      
    template <typename RF>
    U32    Get( RF const& _ )
    {
      StaticAssert<(RF::pos > 31) or ((RF::pos + RF::size) <= 28)>::check(); // NZCV
      StaticAssert<(RF::pos > 26) or ((RF::pos + RF::size) <= 24)>::check(); // ITLO, J
      StaticAssert<(RF::pos > 15) or ((RF::pos + RF::size) <=  9)>::check(); // ITHI, E
      StaticAssert<(RF::pos >  5) or ((RF::pos + RF::size) <=  0)>::check(); // T, MODE
        
      return _.Get( bg );
    }
      
    void   SetBits( U32 const& bits, uint32_t mask );
    U32    GetBits();
    
    void   Set( NRF const& _, BOOL&& value ) { n = value; }
    void   Set( ZRF const& _, BOOL&& value ) { z = value; }
    void   Set( CRF const& _, BOOL&& value ) { c = value; }
    void   Set( VRF const& _, BOOL&& value ) { v = value; }
    void   Set( ERF const& _, const U32& value )
       {  if (proc->Test(value != std::move(U32(value)
                .setToConstant(DomainIntegerConstant{32, false, bigendian}))))
             proc->UnpredictableInsnBehaviour();
       }
    void   Set( NZCVRF const& _, U32&& value );
      
    void   SetITState( uint8_t init_val, Processor& p )
       {  itstate = std::move(U8(p)
                .setToConstant(DomainIntegerConstant{8, false, init_val}));
       }
    BOOL   InITBlock() const
       {  return (itstate & U8(U8::Empty(), itstate).setToConstant(
                DomainIntegerConstant{8, false, 0b1111})).castBit();
       }

    U32    Get( NRF const& _ ) { return n.castToMultiBit(32, false); }
    U32    Get( ZRF const& _ ) { return z.castToMultiBit(32, false); }
    U32    Get( CRF const& _ ) { return c.castToMultiBit(32, false); }
    U32    Get( VRF const& _ ) { return v.castToMultiBit(32, false); }
      
    /* ISetState */
    U32    Get( JRF const& _ )
       {  return U32(U32::Empty(), itstate).setToConstant(
                DomainIntegerConstant{32, false, GetJ()});
       }
    U32    Get( TRF const& _ )
       {  return U32(U32::Empty(), itstate).setToConstant(
                DomainIntegerConstant{32, false, GetT()});
       }
      
    /* Endianness */
    U32    Get( ERF const& _ )
       {  return std::move(U32(U32::Empty(), itstate)
             .setToConstant(DomainIntegerConstant{32, false, bigendian}));
       }
    U32    Get( MRF const& _ )
       {  return std::move(U32(U32::Empty(), itstate)
             .setToConstant(DomainIntegerConstant{32, false, mode}));
       }

    // U32 Get( ALL const& _ ) { return (U32(BOOL(n)) << 31) | (U32(BOOL(z)) << 30) | (U32(BOOL(c)) << 29) | (U32(BOOL(v)) << 28) | bg; }
      
    Processor* proc;
    DomainBitValue n, z, c, v; /* TODO: should handle q */
    U8 itstate;
    U32 bg;
  };

private:
  Processor( Processor const& );

public:
  DomainEvaluationEnvironment    domainEnvironment;
  struct _DomainElementFunctions domainFunctions;
  InterpretParameters*           interpretParameters;
  MemoryState*                   memoryState;
  struct _MemoryModelFunctions   memoryFunctions;

  struct SRegID : public unisim::util::identifier::Identifier<SRegID>
  {
    enum Code {
      SCTLR, ACTLR,
      CTR, MPIDR,
      ID_PFR0, CCSIDR, CLIDR, CSSELR,
      CPACR, NSACR,
      TTBR0, TTBR1, TTBCR,
      DACR,
      DFSR, IFSR, DFAR, IFAR,
      ICIALLUIS, BPIALLIS,
      ICIALLU, ICIMVAU, BPIALL,
      DCIMVAC, DCISW, DCCMVAC, DCCSW, DCCMVAU, DCCIMVAC,
      TLBIALLIS, TLBIALL, TLBIASID,
      VBAR,
      CONTEXTIDR,
      DIAGCR, CFGBAR, end
    } code;

    char const* c_str() const
    {
      switch (code)
        {
        case      SCTLR: return "sctlr";
        case      ACTLR: return "actlr";
        case        CTR: return "ctr";
        case      MPIDR: return "mpidr";
        case    ID_PFR0: return "id_pfr0";
        case     CCSIDR: return "ccsidr";
        case      CLIDR: return "clidr";
        case     CSSELR: return "csselr";
        case      CPACR: return "cpacr";
        case      NSACR: return "nsacr";
        case      TTBR0: return "ttbr0";
        case      TTBR1: return "ttbr1";
        case      TTBCR: return "ttbcr";
        case       DACR: return "dacr";
        case       DFSR: return "dfsr";
        case       IFSR: return "ifsr";
        case       DFAR: return "dfar";
        case       IFAR: return "ifar";
        case  ICIALLUIS: return "icialluis";
        case   BPIALLIS: return "bpiallis";
        case    ICIALLU: return "iciallu";
        case    ICIMVAU: return "icimvau";
        case     BPIALL: return "bpiall";
        case    DCIMVAC: return "dcimvac";
        case      DCISW: return "dcisw";
        case    DCCMVAC: return "dccmvac";
        case      DCCSW: return "dccsw";
        case    DCCMVAU: return "dccmvau";
        case   DCCIMVAC: return "dccimvac";
        case  TLBIALLIS: return "tlbiallis";
        case    TLBIALL: return "tlbiall";
        case   TLBIASID: return "tlbiasid";
        case       VBAR: return "vbar";
        case CONTEXTIDR: return "contextidr";
        case     DIAGCR: return "diagcr";
        case     CFGBAR: return "cfgbar";
        case end:        break;
        }
      return "NA";
    }

    SRegID() : code(end) {}
    SRegID( Code _code ) : code(_code) {}
    SRegID( char const* _code ) : code(end) { init(_code); }
  };
  
  struct RegID : public unisim::util::identifier::Identifier<RegID>
  {
    enum Code
      {
        NA = 0,
        r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, sl, fp, ip, sp, lr,
        n, z, c, v, itstate, // q, ge0, ge1, ge2, ge3,
        cpsr, spsr,
        fpscr, fpexc,
        r8_fiq,
        r9_fiq,
        sl_fiq,
        fp_fiq,
        ip_fiq,
        sp_fiq,
        lr_fiq,
        r8_usr,
        r9_usr,
        sl_usr,
        fp_usr,
        ip_usr,
        sp_usr,
        lr_usr,
        sp_irq,
        sp_svc,
        sp_abt,
        sp_hyp,
        sp_und,
        lr_irq,
        lr_svc,
        lr_abt,
        lr_hyp,
        lr_und,
        end
      } code;

    char const* c_str() const
    {
      switch (code)
        {
        case         r0: return "r0";
        case         r1: return "r1";
        case         r2: return "r2";
        case         r3: return "r3";
        case         r4: return "r4";
        case         r5: return "r5";
        case         r6: return "r6";
        case         r7: return "r7";
        case         r8: return "r8";
        case         r9: return "r9";
        case         sl: return "sl";
        case         fp: return "fp";
        case         ip: return "ip";
        case         sp: return "sp";
        case         lr: return "lr";
        case          n: return "n";
        case          z: return "z";
        case          c: return "c";
        case          v: return "v";
        case    itstate: return "itstate";
        case       cpsr: return "cpsr";
        case       spsr: return "spsr";
        case      fpscr: return "fpscr";
        case      fpexc: return "fpexc";
        case     r8_fiq: return "r8_fiq";
        case     r9_fiq: return "r9_fiq";
        case     sl_fiq: return "sl_fiq";
        case     fp_fiq: return "fp_fiq";
        case     ip_fiq: return "ip_fiq";
        case     sp_fiq: return "sp_fiq";
        case     lr_fiq: return "lr_fiq";
        case     r8_usr: return "r8_usr";
        case     r9_usr: return "r9_usr";
        case     sl_usr: return "sl_usr";
        case     fp_usr: return "fp_usr";
        case     ip_usr: return "ip_usr";
        case     sp_usr: return "sp_usr";
        case     lr_usr: return "lr_usr";
        case     sp_irq: return "sp_irq";
        case     sp_svc: return "sp_svc";
        case     sp_abt: return "sp_abt";
        case     sp_hyp: return "sp_hyp";
        case     sp_und: return "sp_und";
        case     lr_irq: return "lr_irq";
        case     lr_svc: return "lr_svc";
        case     lr_abt: return "lr_abt";
        case     lr_hyp: return "lr_hyp";
        case     lr_und: return "lr_und";
        case         NA:
        case        end: break;
        }
      return "NA";
    }
      
    RegID() : code(end) {}
    RegID( Code _code ) : code(_code) {}
    RegID( char const* _code ) : code(end) { init( _code ); }
  };
public:
  
  enum RegisterLimits
    {
      RLStart=0,
      RLGeneralPurpose=15,
      RLSpecial=RLGeneralPurpose+SRegID::end,
      RLNeonRegs=RLSpecial+32,
      RLEnd = RLNeonRegs
    };
  Processor()
     :  is_it_assigned(false), mode(), unpredictable(false),
        domainEnvironment(), domainFunctions{}, interpretParameters(nullptr),
        memoryState(nullptr), memoryFunctions(), next_targets_queries{}, target_addresses{} {}

  void setMemoryFunctions(struct _MemoryModelFunctions& functions) { memoryFunctions = functions; }
  void setDomainFunctions(struct _DomainElementFunctions& functions) { domainFunctions = functions; }
  void setInterpretParameters(InterpretParameters& params) { interpretParameters = &params; }
  void setMemoryState(MemoryState& memory)
     {  memoryState = &memory;
        // [TODO] manage ForeignRegisters
        memory.setNumberOfRegisters(RLEnd);
     }
  
  //   =====================================================================
  //   =                 Internal Instruction Control Flow                 =
  //   =====================================================================
  
  void UnpredictableInsnBehaviour() { unpredictable = true; }
  
  template <typename OP>
  void UndefinedInstruction( OP* op ) { throw Undefined(); }
    
  bool Test( DomainBitValue const& cond )
  {
    bool result;
    if (!cond.isConstant(&result))
      throw std::logic_error( "Not a valid condition" );
    return result;
  }
  
  void FPTrap( unsigned exc )
  {
    throw Unimplemented();
  }
    
  //   =====================================================================
  //   =             General Purpose Registers access methods              =
  //   =====================================================================
    
  U32  GetGPR( uint32_t id )
    { assert(memoryState);
      return memoryState->getRegisterValueAsMultiBit(id);
    }
  
  // TODO: interworking branches are not correctly handled
  void addJumpTargetAddress(uint32_t val)
    {  if (target_addresses.addresses_length >= target_addresses.addresses_array_size) {
          int old_size = target_addresses.addresses_array_size;
          target_addresses.addresses = (*target_addresses.realloc_addresses)(
             target_addresses.addresses, old_size,
             &target_addresses.addresses_array_size,
             target_addresses.address_container);
       }
       target_addresses.addresses[target_addresses.addresses_length-1] = val;
       ++target_addresses.addresses_length;
    }
  void addCallTargetAddress(uint32_t val)
    {  addJumpTargetAddress(val); }
  void addReturnTargetAddress(uint32_t val)
    {  addJumpTargetAddress(val); }

  void SetGPR_mem( uint32_t id, U32&& value )
    { assert(memoryState);
      if (next_targets_queries) {
        if (id != 15)
          memoryState->setRegisterValue(id, value);
        else {
          DomainIntegerConstant val;
          if (value.isConstant(&val))
             addJumpTargetAddress(val.integerValue);
          else {
             // [TODO] forcer les disjonctions + énumérer
             // pour les dynamic jumps
          }
        }
      }
      else if (memoryState) // isInterpret
        memoryState->setRegisterValue(id, value);
    }
  void SetGPR_usr( uint32_t id, U32 const& value ) { /* system mode */ throw Unimplemented(); }
  U32  GetGPR_usr( uint32_t id ) { /* system mode */ throw Unimplemented(); return U32(); }
    
  enum branch_type_t { B_JMP = 0, B_CALL, B_RET, B_EXC, B_DBG, B_RFE };
  void SetNIA( U32 const& nia, branch_type_t bt )
  {
    if (next_targets_queries) {
      DomainIntegerConstant val;
      if (nia.isConstant(&val)) {
        if (bt == B_CALL)
          addCallTargetAddress(val.integerValue);
        else if (bt == B_RET)
          addReturnTargetAddress(val.integerValue);
        else
         addJumpTargetAddress(val.integerValue);
      }
      else {
         // [TODO] forcer les disjonctions + énumérer
         // pour les dynamic jumps
      }
    };
  }

#if 0
  Expr& GetForeignRegister( uint8_t foreign_mode, uint32_t idx )
  {
    Expr& result = foreign_registers[std::make_pair( foreign_mode, idx )];
    if (not result.node)
      result = new ForeignRegister( foreign_mode, idx );
    return result;
  }
    
  U32  GetBankedRegister( uint8_t foreign_mode, uint32_t idx )
  {
    if ((cpsr.mode == foreign_mode) or
        (idx < 8) or
        (idx >= 15) or
        ((foreign_mode != FIQ_MODE) and (cpsr.mode != FIQ_MODE) and (idx < 13))
        )
      return GetGPR( idx );
    return U32( GetForeignRegister( foreign_mode, idx ) );
  }
    
  void SetBankedRegister( uint8_t foreign_mode, uint32_t idx, U32 value )
  {
    if ((cpsr.mode == foreign_mode) or
        (idx < 8) or
        (idx >= 15) or
        ((foreign_mode != FIQ_MODE) and (cpsr.mode != FIQ_MODE) and (idx < 13))
        )
      return SetGPR( idx, value );
    GetForeignRegister( foreign_mode, idx ) = value.expr;
  }
#endif
    
  //   =====================================================================
  //   =              Special/System Registers access methods              =
  //   =====================================================================

  PSR& CPSR() { return cpsr; }
  
  U32  GetCPSR()                                 { return cpsr.GetBits(); }
  void SetCPSR( U32 const& bits, uint32_t mask ) { cpsr.SetBits( bits, mask ); }
    
  U32& SPSR() { throw Unimplemented(); static U32 spsr_dummy; return spsr_dummy; }
  
  ITCond itcond() const { return ITCond(); }
  bool itblock() { return Test(cpsr.InITBlock()); }
  
  void ITSetState( uint32_t cond, uint32_t mask )
  {
    cpsr.SetITState( (cond << 4) | mask, *this );
    is_it_assigned = true;
  }
  
  void ITAdvance()
  {
    if (is_it_assigned)
      is_it_assigned = false;
    else if (itblock())
      {
        U8 itstate( cpsr.itstate );
        itstate = (Test((itstate & U8(7)) != U8(0))) ? ((itstate & U8(-32)) | ((itstate << 1) & U8(31))) : U8(0);
        cpsr.itstate = itstate;
      }
  }
  
  Mode&  CurrentMode() { /* throw Unimplemented(); */ return mode; }
  Mode&  GetMode(uint8_t) { throw Unimplemented(); return mode; }
  
  virtual CP15Reg& CP15GetRegister( uint8_t crn, uint8_t opcode1, uint8_t crm, uint8_t opcode2 );
  
  U32         CP15ReadRegister( uint8_t crn, uint8_t opcode1, uint8_t crm, uint8_t opcode2 )
  { return CP15GetRegister( crn, opcode1, crm, opcode2 ).Read( *this ); }
  void        CP15WriteRegister( uint8_t crn, uint8_t opcode1, uint8_t crm, uint8_t opcode2, U32 const& value )
  { CP15GetRegister( crn, opcode1, crm, opcode2 ).Write( *this, value ); }
  char const* CP15DescribeRegister( uint8_t crn, uint8_t opcode1, uint8_t crm, uint8_t opcode2 )
  { return CP15GetRegister( crn, opcode1, crm, opcode2 ).Describe(); }

  //   ====================================================================
  //   =         Vector and Floating-point Registers access methods       =
  //   ====================================================================

#if 0
  U32 RoundTowardsZeroFPSCR() const
  {
    U32 fpscr = FPSCR;
    unisim::component::cxx::processor::arm::RMode.Set( fpscr, U32(unisim::component::cxx::processor::arm::RoundTowardsZero) );
    return fpscr;
  }
    
  U32 RoundToNearestFPSCR() const
  {
    U32 fpscr = FPSCR;
    unisim::component::cxx::processor::arm::RMode.Set( fpscr, U32(unisim::component::cxx::processor::arm::RoundToNearest) );
    return fpscr;
  }
    
  // U32 StandardValuedFPSCR() const   { return AHP.Mask( FPSCR ) | 0x03000000; }
    
  struct NeonName
  { // Convenience class for name construction
    NeonName( unsigned idx ) : begin(&buf[sizeof(buf)]) { _('\0'); do { _('0'+idx%10); idx /= 10; } while (idx); _('d'); }
    void _(char c) { *--begin = c; } operator char const* () const { return begin; } char buf[4]; char* begin;
  };
  
  struct NeonRead : public unisim::util::symbolic::binsec::RegRead
  {
    typedef NeonRead this_type;
    typedef unisim::util::symbolic::binsec::RegRead Super;
    NeonRead( unsigned _reg ) : Super(), reg(_reg) {}
    virtual this_type* Mutate() const { return new this_type( *this ); }
    virtual ScalarType::id_t GetType() const { return ScalarType::U64; }
    virtual void GetRegName( std::ostream& sink ) const { sink << 'd' << std::dec << reg; }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<NeonRead const&>( rhs ) ); }
    int compare( this_type const& rhs ) const { return int(reg) - int(rhs.reg); }
    
    unsigned reg;
  };

  struct NeonWrite : public unisim::util::symbolic::binsec::RegWrite
  {
    typedef NeonWrite this_type;
    typedef unisim::util::symbolic::binsec::RegWrite Super;
    NeonWrite( unsigned _reg, Expr const& value ) : Super(value), reg(_reg) {}
    virtual this_type* Mutate() const { return new this_type( *this ); }
    virtual ScalarType::id_t GetType() const { return ScalarType::VOID; }
    virtual void GetRegName( std::ostream& sink ) const { sink << 'd' << std::dec << reg; }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<this_type const&>( rhs ) ); }
    int compare( this_type const& rhs ) const { if (int delta = int(reg) - int(rhs.reg)) return delta; return Super::compare( rhs ); }
    
    unsigned reg;
  };

  struct NeonPartialWrite : public unisim::util::symbolic::binsec::RegWrite
  {
    typedef NeonPartialWrite this_type;
    typedef unisim::util::symbolic::binsec::RegWrite Super;
    typedef unisim::util::symbolic::binsec::Label Label;
    typedef unisim::util::symbolic::binsec::Variables Variables;
    typedef unisim::util::symbolic::binsec::GetCode GetCode;

    NeonPartialWrite( unsigned _reg, unsigned _beg, unsigned _end, Expr const& _value ) : Super(_value), reg(_reg), beg(_beg), end(_end) {}
    virtual this_type* Mutate() const { return new this_type( *this ); }
    virtual ScalarType::id_t GetType() const { return ScalarType::VOID; }
    virtual void GetRegName( std::ostream& sink ) const { sink << 'd' << std::dec << reg << '_' << beg << '_' << end; }
    virtual int GenCode( Label& label, Variables& vars, std::ostream& sink ) const
    {
      sink << 'd' << std::dec << reg << '{' << beg << ',' << end << '}' << " := " << GetCode(value, vars, label);
      return 0;
    }
    virtual int cmp( ExprNode const& rhs ) const override { return compare( dynamic_cast<this_type const&>( rhs ) ); }
    int compare( this_type const& rhs ) const
    {
      if (int delta = int(reg) - int(rhs.reg)) return delta;
      if (int delta = int(beg) - int(rhs.beg)) return delta;
      if (int delta = int(end) - int(rhs.end)) return delta;
      return Super::compare( rhs );
    }
    
    unsigned reg, beg, end;
  };
  
  static unsigned const NEONSIZE = 8;

  void
  GetNeonSinks( unsigned reg )
  {
    using unisim::util::symbolic::binsec::BitFilter;
    // using unisim::util::symbolic::make_const;
    
    { // Check for constant values
      Expr dr = unisim::util::symbolic::binsec::ASExprNode::Simplify( GetVDU(reg).expr );
      if (dr.ConstSimplify())
        {
          path->add_sink( new NeonWrite( reg, dr ) );
          return;
        }
    }

    // Check for monolithic value
    if (not neonregs[reg][NEONSIZE/2].node)
      {
        path->add_sink( new NeonWrite( reg, eneonread(reg,NEONSIZE,0) ) );
        return;
      }
    
    // Requested read is a concatenation of multiple source values
    struct _
    {
      _( Processor& _core, unsigned _reg ) : core(_core), reg(_reg) { Process( 0, NEONSIZE ); } Processor& core; unsigned reg;
      void Process( unsigned pos, unsigned size )
      {
        unsigned half = size / 2, mid = pos+half;
        if (size > 1 and core.neonregs[reg][mid].node)
          {
            Process( pos, half );
            Process( mid, half );
          }
        else
          {
            unsigned begin = pos*8, end = begin+size*8;
            Expr value( new BitFilter( core.eneonread(reg,size,pos), 64, size*8, size*8, false ) );
            core.path->add_sink( new NeonPartialWrite( reg, begin, end, value ) );
          }
      }
    } concat( *this, reg );
  }
 
  Expr eneonread( unsigned reg, unsigned size, unsigned pos )
  {
    using unisim::util::symbolic::ExprNode;
    using unisim::util::symbolic::make_const;
    
    struct
    {
      Expr ui( unsigned sz, Expr const& src ) const
      {
        switch (sz) {
        default: throw 0;
        case 1: return new unisim::util::symbolic::CastNode<uint8_t,uint64_t>( src );
        case 2: return new unisim::util::symbolic::CastNode<uint16_t,uint64_t>( src );
        case 4: return new unisim::util::symbolic::CastNode<uint32_t,uint64_t>( src );
        case 8: return new unisim::util::symbolic::CastNode<uint64_t,uint64_t>( src );
        }
        return 0;
      }
    } cast;
    
    if (not neonregs[reg][pos].node)
      {
        // requested read is in the middle of a larger value
        unsigned src = pos;
        do { src = src & (src-1); } while (not neonregs[reg][src].node);
        unsigned shift = 8*(pos - src);
        return cast.ui( size, make_operation( "Lsr", neonregs[reg][src], make_const( shift ) ) );
      }
    else if (not neonregs[reg][(pos|size)&(NEONSIZE-1)].node)
      {
        // requested read is in lower bits of a larger value
        return cast.ui( size, neonregs[reg][pos] );
      }
    else if ((size > 1) and (neonregs[reg][pos|(size >> 1)].node))
      {
        // requested read is a concatenation of multiple source values
        Expr concat = cast.ui( size, neonregs[reg][pos] );
        for (unsigned idx = 0; ++idx < size;)
          {
            if (not neonregs[reg][pos+idx].node)
              continue;
            concat = make_operation( "Or", make_operation( "Lsl", cast.ui( size, neonregs[reg][idx] ), make_const( 8*idx ) ), concat );
          }
        return concat;
      }
    
    // requested read is directly available
    return neonregs[reg][pos];
  }
  
  void eneonwrite( unsigned reg, unsigned size, unsigned pos, Expr const& xpr )
  {
    Expr nxt[NEONSIZE];
    
    for (unsigned ipos = pos, isize = size, cpos;
         cpos = (ipos^isize) & (NEONSIZE-1), (not neonregs[reg][ipos].node) or (not neonregs[reg][cpos].node);
         isize *= 2, ipos &= -isize
         )
      {
        nxt[cpos] = eneonread( reg, isize, cpos );
      }
    
    for (unsigned ipos = 0; ipos < NEONSIZE; ++ipos)
      {
        if (nxt[ipos].node)
          neonregs[reg][ipos] = nxt[ipos];
      }
    
    neonregs[reg][pos] = xpr;
    
    for (unsigned rem = 1; rem < size; ++rem)
      {
        neonregs[reg][pos+rem] = 0;
      }
  }

  U32  GetVSU( unsigned idx ) { return U32( U64( eneonread( idx / 2, 4, (idx*4) & 4 ) ) ); }
  void SetVSU( unsigned idx, U32 val ) { eneonwrite( idx / 2, 4, (idx*4) & 4, U64(val).expr ); }
  U64  GetVDU( unsigned idx ) { return U64( eneonread( idx, 8, 0 ) ); }
  void SetVDU( unsigned idx, U64 val ) { eneonwrite( idx, 8, 0, U64(val).expr ); }
  F32  GetVSR( unsigned idx ) { return F32(); }
  void SetVSR( unsigned idx, F32 val ) {}
  F64  GetVDR( unsigned idx ) { return F64(); }
  void SetVDR( unsigned idx, F64 val ) {}

  static unsigned usizeof( U8 const& )  { return  1; }
  static unsigned usizeof( U16 const& ) { return  2; }
  static unsigned usizeof( U32 const& ) { return  4; }
  static unsigned usizeof( U64 const& ) { return  8; }

  template <typename T> T ucast( T const& x ) { return x; }
  U8 ucast( S8 const& x ) { return U8(x); }
  U16 ucast( S16 const& x ) { return U16(x); }
  U32 ucast( S32 const& x ) { return U32(x); }
  U64 ucast( S64 const& x ) { return U64(x); }
  // Get|Set elements
  template <class ELEMT>
  void
  SetVDE( unsigned reg, unsigned idx, ELEMT const& value )
  {
    using unisim::util::symbolic::binsec::BitFilter;
    auto uvalue = ucast( value );
    unsigned usz = usizeof( uvalue );
    Expr neonval( new BitFilter( uvalue.expr, usz*8, usz*8, 64, false ) );
    eneonwrite( reg, usz, usz*idx, neonval );
  }

  template <class ELEMT>
  ELEMT GetVDE( unsigned reg, unsigned idx, ELEMT const& trait )
  {
    unsigned usz = usizeof( ucast(trait) );
    return ELEMT( U64( eneonread( reg, usz, usz*idx ) ) );
  }
  
  //   =====================================================================
  //   =                      Control Transfer methods                     =
  //   =====================================================================

  void BranchExchange( U32 const& target, branch_type_t branch_type ) { SetNIA( target, branch_type ); }
  void Branch( U32 const& target, branch_type_t branch_type ) { SetNIA( target, branch_type ); }
    
  void WaitForInterrupt() { throw Unimplemented(); }
  void SWI( uint32_t imm ) { throw Unimplemented(); }
  void BKPT( uint32_t imm ) { throw Unimplemented(); }
  void CallSupervisor( uint32_t imm ) { throw Unimplemented(); }
  bool IntegerZeroDivide( BOOL const& condition ) { return false; }
  
  //   =====================================================================
  //   =                       Memory access methods                       =
  //   =====================================================================
  
  U32  MemURead32( U32 const& addr ) { return U32( Expr( new Load( addr.expr, 2, 0, false ) ) ); }
  U16  MemURead16( U32 const& addr ) { return U16( Expr( new Load( addr.expr, 1, 0, false ) ) ); }
  U32  MemRead32( U32 const& addr ) { return U32( Expr( new Load( addr.expr, 2, 2, false ) ) ); }
  U16  MemRead16( U32 const& addr ) { return U16( Expr( new Load( addr.expr, 1, 1, false ) ) ); }
  U8   MemRead8( U32 const& addr ) { return U8( Expr( new Load( addr.expr, 0, 0, false ) ) ); }
  
  void MemUWrite32( U32 const& addr, U32 const& value ) { stores.insert( new Store( addr.expr, value.expr, 2, 0, false ) ); }
  void MemUWrite16( U32 const& addr, U16 const& value ) { stores.insert( new Store( addr.expr, value.expr, 1, 0, false ) ); }
  void MemWrite32( U32 const& addr, U32 const& value ) { stores.insert( new Store( addr.expr, value.expr, 2, 2, false ) ); }
  void MemWrite16( U32 const& addr, U16 const& value ) { stores.insert( new Store( addr.expr, value.expr, 1, 1, false ) ); }
  void MemWrite8( U32 const& addr, U8 const& value ) { stores.insert( new Store( addr.expr, value.expr, 0, 0, false ) ); }
#endif
    
  void SetExclusiveMonitors( U32 const& address, unsigned size ) { std::cerr << "SetExclusiveMonitors\n"; }
  bool ExclusiveMonitorsPass( U32 const& address, unsigned size ) { std::cerr << "ExclusiveMonitorsPass\n"; return true; }
  void ClearExclusiveLocal() { std::cerr << "ClearExclusiveMonitors\n"; }
  
  //   =====================================================================
  //   =                         Processor Storage                         =
  //   =====================================================================
  
  static const unsigned PC_reg = 15;
  static const unsigned LR_reg = 14;
  static const unsigned SP_reg = 13;

  /* masks for the different running modes */
  static uint32_t const USER_MODE = 0b10000;
  static uint32_t const FIQ_MODE = 0b10001;
  static uint32_t const IRQ_MODE = 0b10010;
  static uint32_t const SUPERVISOR_MODE = 0b10011;
  static uint32_t const MONITOR_MODE = 0b10110;
  static uint32_t const ABORT_MODE = 0b10111;
  static uint32_t const HYPERVISOR_MODE = 0b11010;
  static uint32_t const UNDEFINED_MODE = 0b11011;
  static uint32_t const SYSTEM_MODE = 0b11111;

  /* values of the different condition codes */
  static uint32_t const COND_EQ = 0x00;
  static uint32_t const COND_NE = 0x01;
  static uint32_t const COND_CS_HS = 0x02;
  static uint32_t const COND_CC_LO = 0x03;
  static uint32_t const COND_MI = 0x04;
  static uint32_t const COND_PL = 0x05;
  static uint32_t const COND_VS = 0x06;
  static uint32_t const COND_VC = 0x07;
  static uint32_t const COND_HI = 0x08;
  static uint32_t const COND_LS = 0x09;
  static uint32_t const COND_GE = 0x0a;
  static uint32_t const COND_LT = 0x0b;
  static uint32_t const COND_GT = 0x0c;
  static uint32_t const COND_LE = 0x0d;
  static uint32_t const COND_AL = 0x0e;
    
  /* mask for valid bits in processor control and status registers */
  static uint32_t const PSR_UNALLOC_MASK = 0x00f00000;

#if 0
  U32& SReg( SRegID reg )
  {
    if (reg.code == SRegID::end)
      throw 0;
    return sregs[reg.idx()];
  }
    

  ActionNode*      path;
  U32              reg_values[16];
  U32              next_insn_addr;
  Br::type_t       branch_type;
  U32              spsr;
  U32              sregs[SRegID::end];
  U32              FPSCR, FPEXC;
  std::set<Expr>   stores;
  ForeignRegisters foreign_registers;
  Expr             neonregs[32][NEONSIZE];
#endif
  PSR              cpsr;
  bool             is_it_assigned; /* determines wether current instruction is an IT one. */
  Mode             mode;
  bool             unpredictable;
  bool             next_targets_queries;
  TargetAddresses  target_addresses;
};

inline
DomainValue::DomainValue(Processor& processor)
   :  deValue{ nullptr }, pfFunctions(&processor.domainFunctions),
      peEnv(&processor.domainEnvironment) {}

inline
DomainValue::DomainValue(DomainElement&& value, Processor& processor)
   :  deValue(value), pfFunctions(&processor.domainFunctions),
      peEnv(&processor.domainEnvironment)
   {  value.content = nullptr; }

inline
DomainBitValue::DomainBitValue(Processor& processor)
   : DomainValue(processor) {}
   
inline
DomainBitValue::DomainBitValue(DomainBitElement&& value, Processor& processor)
   :  DomainValue(std::move(value), processor) {}
   
inline
DomainBitValue::DomainBitValue(DomainBitElement&& value,
      const DomainValue& source)
   :  DomainValue(std::move(value), source) {}

inline DomainMultiBitValue
DomainBitValue::castToMultiBit(int sizeInBits, bool isSigned) const {
   return DomainMultiBitValue((*functionTable().bit_create_cast_multibit)
         (value(), sizeInBits, env()), *this, isSigned);
}

inline
DomainMultiBitValue::DomainMultiBitValue(Processor& processor)
   : DomainValue(processor), fSigned(false) {}

inline
DomainMultiBitValue::DomainMultiBitValue(DomainMultiBitElement&& value,
      Processor& processor, bool isSigned)
   :  DomainValue(std::move(value), processor), fSigned(isSigned) {}
   
inline
DomainMultiFloatValue::DomainMultiFloatValue(Processor& processor)
   : DomainValue(processor) {}

inline
DomainMultiFloatValue::DomainMultiFloatValue(DomainMultiFloatElement&& value,
      Processor& processor)
   :  DomainValue(std::move(value), processor) {}

struct Translator
{
  Translator( uint32_t _addr, uint32_t _code )
    : addr(_addr), code(_code) {}
  
  template <class ISA>
  void
  extract( std::ostream& sink, ISA& isa )
  {
    sink << "(address . " << addr << ")\n";
  
    // Instruction decoding
    struct Instruction
    {
      typedef typename ISA::Operation Operation;
      Instruction(ISA& isa, uint32_t addr, uint32_t code)
        : operation(0), bytecount(0)
      {
        operation = isa.NCDecode( addr, ISA::mkcode( code ) );
        unsigned bitlength = operation->GetLength(); 
        if ((bitlength != 32) and ((bitlength != 16) or not ISA::is_thumb))
          { delete operation; operation = 0; }
        bytecount = bitlength/8;
      }
      ~Instruction() { delete operation; }
      Operation* operator -> () { return operation; }
      
      Operation* operation;
      unsigned   bytecount;
    };
    
    Instruction instruction( isa, addr, code );
    
    {
      uint32_t encoding = instruction->GetEncoding();
      if (instruction.bytecount == 2)
        encoding &= 0xffff;
      
      sink << "(opcode . " << encoding << ")\n(size . " << (instruction.bytecount) << ")\n";
    }
    
    // Disassemble
    sink << "(mnemonic . \"";
    Processor state;
    try { instruction->disasm( state, sink ); }
    catch (...) { sink << "(bad)"; }
    sink << "\")\n";
    
    // Get actions
    bool is_thumb = status.IsThumb();
    for (bool end = false; not end;)
      {
        // Fetch
        uint32_t insn_addr = instruction->GetAddr();
        // state.SetNIA( Processor::U32(insn_addr + instruction.bytecount), Processor::B_JMP );
        // state.reg_values[15] = Processor::U32(insn_addr + (is_thumb ? 4 : 8) );
        // Execute
        instruction->execute( state );
        if (is_thumb)
          state.ITAdvance();
        // end = state.close( reference );
      }
    coderoot->simplify();
    coderoot->commit_stats();
  }

  void translate( std::ostream& sink )
  {
    try
      {
        if      (status.iset == status.Arm)
          {
            ARMISA armisa;
            extract( sink, armisa );
          }
        else if (status.iset == status.Thumb)
          {
            THUMBISA thumbisa;
            extract( sink, thumbisa );
          }
        else
          throw 0;
      }
    catch (Processor::Undefined const&)
      {
        sink << "(undefined)\n";
        return;
      }
    catch (...)
      {
        sink << "(unimplemented)\n";
        return;
      }

    // Translate to DBA
    unisim::util::symbolic::binsec::Program program;
    program.Generate( coderoot );
    typedef unisim::util::symbolic::binsec::Program::const_iterator Iterator;
    for (Iterator itr = program.begin(), end = program.end(); itr != end; ++itr)
      sink << "(" << unisim::util::symbolic::binsec::dbx(4, addr) << ',' << itr->first << ") " << itr->second << std::endl;
  }

  Processor::StatusRegister status;
  uint32_t    addr, code;
};
  
extern "C" {

DLL_API void* create_processor()
{  return new Processor(); }

DLL_API void free_processor(void* processor)
{  delete reinterpret_cast<Processor*>(processor); }

DLL_API bool armsec_next_targets(void* processor, char* instruction_buffer,
      size_t buffer_size, uint64_t address, TargetAddresses target_addresses,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      InterpretParameters* parameters, uint64_t* result_addresses,
      int* result_length) {
   Processor* proc = reinterpret_cast<Processor*>(processor);
   proc->

}

DLL_API bool armsec_interpret(void* processor, char* instruction_buffer,
      size_t buffer_size, uint64_t address, uint64_t target_address,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      InterpretParameters* parameters) {

}

}

