#include "armsec_decoder.h"
#include "unisim/component/cxx/processor/arm/disasm.hh"
#include "unisim/component/cxx/processor/arm/psr.hh"
#include "unisim/util/identifier/identifier.hh"
#include "unisim/util/likely/likely.hh"
#include <functional>
#include "top_thumb.tcc"

#include <cassert>

#define CP15ENCODE( CRN, OPC1, CRM, OPC2 ) ((OPC1 << 12) | (CRN << 8) | (CRM << 4) | (OPC2 << 0))

enum REG_ID { R0=0, R15=15,CPSR_ID} ;

template <bool test> struct StaticAssert {};
template <> struct StaticAssert<true> { static void check() {}; };

template <class T, class U>  struct CmpTypes { static bool const same = false; };
template <class T>  struct CmpTypes<T,T> { static bool const same = true; };

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
class DomainValue
{
private:
  DomainElement deValue;
  struct _DomainElementFunctions* pfFunctions;
  DomainEvaluationEnvironment* peEnv;

protected:
  friend class MemoryState;
  DomainElement& svalue() { return deValue; }
  bool hasFunctionTable() const { return pfFunctions; }
  struct _DomainElementFunctions& functionTable() const { assert(pfFunctions); return *pfFunctions; }
  DomainEvaluationEnvironment* env() const { return peEnv; }

public:
  const DomainElement& value() const { return deValue; }

public:
  DomainValue() : pfFunctions(nullptr), peEnv(nullptr) {}
  class Empty {};
  DomainValue(Empty, const DomainValue& ref)
    : deValue(DomainBitElement{}), pfFunctions(ref.pfFunctions), peEnv(ref.peEnv) {}
  DomainValue(DomainElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
    : deValue(std::move(value)), pfFunctions(functions), peEnv(env) {}
  DomainValue(Processor& processor);
  DomainValue(DomainElement&& value, Processor& processor);
  DomainValue(DomainElement&& value, const DomainValue& source)
    : deValue(value), pfFunctions(source.pfFunctions), peEnv(source.peEnv)
    { value.content = nullptr; }
  DomainValue(DomainValue&& source)
    : deValue(source.deValue), pfFunctions(source.pfFunctions), peEnv(source.peEnv)
    { source.deValue.content = nullptr; }
  DomainValue(const DomainValue& source)
    : deValue{ nullptr }, pfFunctions(source.pfFunctions), peEnv(source.peEnv)
    {
      if (source.deValue.content) {
        assert(pfFunctions);
        deValue = (*pfFunctions->clone)(source.deValue);
      }
    }
  DomainValue& operator=(DomainValue&& source)
    {
      if (this == &source)
        return *this;
      if (deValue.content)
      {
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
    {
      if (this == &source)
        return *this;
      if (deValue.content)
        (*pfFunctions->free)(&deValue);
      pfFunctions = source.pfFunctions;
      peEnv = source.peEnv;
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
    {
      if (deValue.content)
      {
        assert(pfFunctions);
        (*pfFunctions->free)(&deValue);
      }
    }
  bool isValid() const { return deValue.content; }
  DomainType getType() const
    {
      assert(pfFunctions);
      return (*pfFunctions->get_type)(deValue);
    } 
  ZeroResult queryZeroResult() const
    {
      assert(pfFunctions);
      return (*pfFunctions->query_zero_result)(deValue);
    } 
  int getSizeInBits() const
    {
      assert(pfFunctions);
      return (*pfFunctions->get_size_in_bits)(deValue);
    } 
};

// extern DomainValue getRootDomainValue();

//class DomainMultiBitValue;
class DomainBitValue : public DomainValue
{
private:
  typedef DomainValue inherited;
  bool fConstant;

protected:
  DomainBitValue(Empty empty, const DomainValue& ref)
    : DomainValue(empty, ref), fConstant(false) {}

public:
  DomainBitValue() : fConstant(false) {}
  DomainBitValue(DomainBitElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
    : DomainValue(std::move(value), functions, env), fConstant(false) {}
  DomainBitValue(Processor& processor);
  DomainBitValue(DomainBitElement&& value, Processor& processor);
  DomainBitValue(DomainBitElement&& value, const DomainValue& source);
  explicit DomainBitValue(bool value, Processor& processor)
    : DomainValue(processor), fConstant(false)
    { svalue() = (*functionTable().bit_create_constant)(value); }
  explicit DomainBitValue( bool value )
    : DomainValue(), fConstant(value) {}

  DomainBitValue(DomainBitValue&& source) = default;
  DomainBitValue(const DomainBitValue& source) = default;
  DomainBitValue& operator=(DomainBitValue&& source) = default;
  DomainBitValue& operator=(const DomainBitValue& source) = default;

  DomainBitValue& setToConstant(bool value)
    {
      if (inherited::hasFunctionTable())
        svalue() = (*functionTable().bit_create_constant)(value);
      else
        fConstant = value;
      return *this;
    }

  DomainBitValue& setToUndefined(bool isSymbolic)
    { svalue() = (*functionTable().bit_create_top)(isSymbolic); return *this; }

  DomainBitValue applyUnary(DomainBitUnaryOperation operation,
      std::function<bool(bool)> constantFunction) const
    {
      if (inherited::isValid())
        return DomainBitValue((*functionTable().bit_create_unary_apply)
            (value(), operation, env()), *this);
      else
        return DomainBitValue(constantFunction(fConstant));
    }
  DomainBitValue applyBinary(DomainBitBinaryOperation operation,
      const DomainBitValue& source,
      std::function<bool(bool, bool)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return DomainBitValue((*functionTable().bit_create_binary_apply)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainBitValue alt(Empty(), *this);
        alt.setToConstant(source.fConstant);
        return applyBinary(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        DomainBitValue alt(Empty(), source);
        alt.setToConstant(fConstant);
        alt.applyBinaryAssign(operation, source, constantFunction);
        return std::move(alt);
      }
      else
        return DomainBitValue(constantFunction(fConstant, source.fConstant));
    }
  DomainBitValue applyCompare(DomainBitCompareOperation operation,
      const DomainBitValue& source,
      std::function<bool(bool, bool)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return DomainBitValue((*functionTable().bit_binary_compare_domain)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainBitValue alt(Empty(), *this);
        alt.setToConstant(source.fConstant);
        return applyCompare(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        DomainBitValue alt(Empty(), source);
        alt.setToConstant(fConstant);
        return alt.applyCompare(operation, source, constantFunction);
      }
      else
        return DomainBitValue(constantFunction(fConstant, source.fConstant));
    }
  DomainBitValue& applyBinaryAssign(DomainBitBinaryOperation operation,
      const DomainBitValue& source,
      std::function<bool(bool, bool)> constantFunction)
    {
      if (inherited::isValid() && source.inherited::isValid())
        (*functionTable().bit_binary_apply_assign)
            (&svalue(), operation, source.value(), env());
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainBitValue alt(Empty(), *this);
        alt.setToConstant(source.fConstant);
        applyBinaryAssign(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        bool thisConstant = fConstant;
        operator=(DomainBitValue(Empty(), source));
        setToConstant(thisConstant);
        applyBinaryAssign(operation, source, constantFunction);
      }
      else
        fConstant = constantFunction(fConstant, source.fConstant);
      return *this;
    }

  DomainBitValue operator~() const
    { return applyUnary(DBUONegate, [](bool val) { return ~val; }); }
  DomainBitValue operator!() const
    { return applyUnary(DBUONegate, [](bool val) { return !val; }); }
  DomainBitValue operator|(const DomainBitValue& source) const
    { return applyBinary(DBBOOr, source,
          [](bool fst, bool snd) { return fst | snd; });
    }
  DomainBitValue operator&(const DomainBitValue& source) const
    { return applyBinary(DBBOAnd, source,
          [](bool fst, bool snd) { return fst & snd; });
    }
  DomainBitValue operator^(const DomainBitValue& source) const
    { return applyBinary(DBBOExclusiveOr, source,
          [](bool fst, bool snd) { return fst ^ snd; });
    }
  DomainBitValue operator||(const DomainBitValue& source) const
    { return applyBinary(DBBOOr, source,
          [](bool fst, bool snd) { return fst || snd; });
    }
  DomainBitValue operator&&(const DomainBitValue& source) const
    { return applyBinary(DBBOOr, source,
          [](bool fst, bool snd) { return fst && snd; });
    }
  DomainBitValue& operator|=(const DomainBitValue& source)
    { return applyBinaryAssign(DBBOOr, source,
          [](bool fst, bool snd) { return fst | snd; });
    }
  DomainBitValue& operator&=(const DomainBitValue& source)
    { return applyBinaryAssign(DBBOAnd, source,
          [](bool fst, bool snd) { return fst & snd; });
    }
  DomainBitValue operator^=(const DomainBitValue& source)
    { return applyBinaryAssign(DBBOExclusiveOr, source,
          [](bool fst, bool snd) { return fst ^ snd; });
    }

  DomainBitValue operator==(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareEqual, source,
          [](bool fst, bool snd) { return fst == snd; });
    }
  DomainBitValue operator!=(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareDifferent, source,
          [](bool fst, bool snd) { return fst != snd; });
    }
  DomainBitValue operator<=(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareLessOrEqual, source,
          [](bool fst, bool snd) { return fst <= snd; });
    }
  DomainBitValue operator>=(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareGreaterOrEqual, source,
          [](bool fst, bool snd) { return fst >= snd; });
    }
  DomainBitValue operator<(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareLess, source,
          [](bool fst, bool snd) { return fst < snd; });
    }
  DomainBitValue operator>(const DomainBitValue& source) const
    { return applyCompare(DBCOCompareGreater, source,
          [](bool fst, bool snd) { return fst > snd; });
    }

  bool isConstant(bool* value) const
    {
      if (inherited::isValid())
        return (*functionTable().bit_is_constant_value)(this->value(), value);
      else
      {
        if (value)
          *value = fConstant;
        return true;
      }
    }
};

template <typename VALUE_TYPE>
class DomainMultiFloatValue;

template <typename VALUE_TYPE>
class DomainMultiBitValue : public DomainValue
{
private:
  typedef DomainMultiBitValue<VALUE_TYPE> this_type;
  typedef DomainValue inherited;
  VALUE_TYPE uConstant;
  template <typename SRC_VALUE_TYPE>
  friend class DomainMultiBitValue;

public:
  typedef VALUE_TYPE value_type;
  
  DomainMultiBitValue() : uConstant(0) {}

  explicit DomainMultiBitValue( value_type value ) : uConstant(value) {}
  DomainMultiBitValue( DomainMultiBitValue&& other ) = default;
  DomainMultiBitValue( Empty empty, const DomainValue& other )
    : inherited(empty, other), uConstant(0) {}
  DomainMultiBitValue( const DomainMultiBitValue& other ) = default;
  DomainMultiBitValue& operator=( DomainMultiBitValue&& other ) = default;
  DomainMultiBitValue& operator=( const DomainMultiBitValue& other ) = default;
  explicit DomainMultiBitValue( const DomainBitValue& other )
    : DomainValue(Empty(), other)
    {
      if (inherited::hasFunctionTable())
        svalue() = (*functionTable().bit_create_cast_multibit)(other.value(),8*sizeof(VALUE_TYPE),env());
      else {
        bool res;
        other.isConstant(&res);
        uConstant = res;
      }
    }
  DomainMultiBitValue(DomainElement&& element, Processor& proc)
    : DomainValue(std::move(element), proc) {}
  DomainMultiBitValue(DomainElement&& element, DomainValue const& value)
    : DomainValue(std::move(element), value) {}
  DomainMultiBitValue(DomainElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
    : DomainValue(std::move(value), functions, env) {}

  template <typename SRC_VALUE_TYPE>
  explicit DomainMultiBitValue( DomainMultiBitValue<SRC_VALUE_TYPE> const& other )
    {
      if (CmpTypes<SRC_VALUE_TYPE,VALUE_TYPE>::same) {
        inherited::operator= ( other );
      } else {
        inherited::operator= ( this_type(Empty(), other) );
        if (inherited::hasFunctionTable())
          svalue() = (*functionTable().multibit_create_cast_multibit)(other.value(),8*sizeof(SRC_VALUE_TYPE),8*sizeof(VALUE_TYPE),std::numeric_limits<SRC_VALUE_TYPE>::is_signed);
        else
          uConstant = other.uConstant;
      }
    }

private:
  bool isSigned() const { return std::numeric_limits<VALUE_TYPE>::is_signed; }

public:
  DomainElement& svalue() { return DomainValue::svalue(); }
  const DomainElement& value() const { return DomainValue::value(); }

public:
  DomainMultiBitValue& setToConstant(VALUE_TYPE value)
    {
      if (inherited::hasFunctionTable())
        svalue() = (*functionTable().multibit_create_constant)(DomainIntegerConstant{8*sizeof(VALUE_TYPE), std::numeric_limits<VALUE_TYPE>::is_signed, uint64_t(value)});
      else
        uConstant = value;
      return *this;
    }
  DomainMultiBitValue& setToUndefined(int sizeInBits, bool isSymbolic)
    {
      svalue() = (*functionTable().multibit_create_top)(sizeInBits, isSymbolic);
      return *this;
    }
  operator DomainBitValue() const
    {
      if (inherited::isValid())
        return DomainBitValue((*functionTable().multibit_create_cast_bit)
            (value(), env()), *this);
      else
        return DomainBitValue((bool) uConstant);
    }
  DomainBitValue castShiftBit(int shift)
    {
      if (inherited::isValid())
        return DomainBitValue((*functionTable().multibit_create_cast_shift_bit)
            (value(), shift, env()), *this);
      else
        return DomainBitValue((bool) (uConstant & ((VALUE_TYPE) 1 << shift)));
    }
  template <class ResultType, int size>
  DomainMultiFloatValue<ResultType> castToMultiFloat() const
    {
      if (inherited::isValid())
        return DomainMultiFloatValue<ResultType>((*functionTable().multibit_create_cast_multifloat)(value(), size, 
            std::numeric_limits<VALUE_TYPE>::is_signed, env()), *this);
      else
        return DomainMultiFloatValue<ResultType>((ResultType) uConstant);
    }

  void reduce(int first, int last)
    {
      if (inherited::isValid())
        (*functionTable().multibit_reduce_apply_assign)(&svalue(),
            DomainMultiBitReduceOperation{first, last}, env());
      else
        uConstant = (uConstant >> first) & ~(~((VALUE_TYPE) 0) << (last-first+1));
    }
  void extendWithZero(int new_size)
    {
      if (inherited::isValid())
        (*functionTable().multibit_extend_apply_assign)(&svalue(),
            DomainMultiBitExtendOperation{DMBEOExtendWithZero, new_size}, env());
    }
  template <typename IntType>
  void bitset(int first, int last, const DomainMultiBitValue<IntType>& source)
    {
      if (inherited::isValid() && source.inherited::isValid())
        (*functionTable().multibit_bitset_apply_assign)(&svalue(),
            DomainMultiBitSetOperation{first, last}, source.value(), env());
      else if (inherited::isValid())
        { // !source.inherited::isValid()
          DomainMultiBitValue<IntType> alt(Empty(), *this);
          alt.setToConstant(source.uConstant);
          bitset(first, last, alt);
        }
      else if (source.inherited::isValid())
        {
          VALUE_TYPE constant = uConstant;
          this->operator=(DomainMultiBitValue<VALUE_TYPE>(Empty(), source));
          setToConstant(constant);
          bitset(first, last, source);
        }
      else
        {
          VALUE_TYPE mask = (~((VALUE_TYPE) 0) << first);
          if ((size_t) (last+1) < sizeof(VALUE_TYPE)*8)
            mask &= ~(~((VALUE_TYPE) 0) << (last+1));
          uConstant &= ~mask;
          uConstant |= ((VALUE_TYPE) source.uConstant) << first;
        }
    }
  this_type applyUnary(DomainMultiBitUnaryOperation operation,
      std::function<VALUE_TYPE(VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid())
        return DomainMultiBitValue((*functionTable().multibit_create_unary_apply)
            (value(), operation, env()), *this);
      else
        return DomainMultiBitValue(constantFunction(uConstant));
    }
  this_type applyUnary(DomainMultiBitUnaryOperation signedOperation,
      DomainMultiBitUnaryOperation unsignedOperation,
      std::function<VALUE_TYPE(VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid())
        return DomainMultiBitValue((*functionTable().multibit_create_unary_apply)
            (value(), isSigned() ? signedOperation : unsignedOperation, env()), *this);
      else
        return DomainMultiBitValue(constantFunction(uConstant));
    }
  this_type& applyUnaryAssign(DomainMultiBitUnaryOperation signedOperation,
      DomainMultiBitUnaryOperation unsignedOperation,
      std::function<void(VALUE_TYPE&)> constantFunction)
    {
      if (inherited::isValid())
        (*functionTable().multibit_unary_apply_assign)
            (&svalue(), isSigned() ? signedOperation : unsignedOperation, env());
      else
        constantFunction(uConstant);
      return *this;
    }
    
  template <typename IntType>
  this_type applyBinary(DomainMultiBitBinaryOperation signedOperation,
      DomainMultiBitBinaryOperation unsignedOperation,
      const DomainMultiBitValue<IntType>& source,
      std::function<VALUE_TYPE(VALUE_TYPE, IntType)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return this_type((*functionTable().multibit_create_binary_apply)
            (value(), isSigned() ? signedOperation : unsignedOperation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainMultiBitValue<IntType> alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        return applyBinary(signedOperation, unsignedOperation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(uConstant);
        alt.applyBinaryAssign(signedOperation, unsignedOperation, source, constantFunction);
        return std::move(alt);
      }
      else
        return this_type(constantFunction(uConstant, source.uConstant));
    }
  template <typename IntType>
  this_type applyBinary(DomainMultiBitBinaryOperation operation,
      const DomainMultiBitValue<IntType>& source,
      std::function<VALUE_TYPE(VALUE_TYPE, IntType)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return this_type((*functionTable().multibit_create_binary_apply)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainMultiBitValue<IntType> alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        return applyBinary(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(uConstant);
        alt.applyBinaryAssign(operation, source, constantFunction);
        return std::move(alt);
      }
      else
        return this_type(constantFunction(uConstant, source.uConstant));
    }
  DomainBitValue applyCompare(DomainMultiBitCompareOperation signedOperation,
      DomainMultiBitCompareOperation unsignedOperation,
      const this_type& source,
      std::function<bool(VALUE_TYPE, VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return DomainBitValue((*functionTable().multibit_binary_compare_domain)
            (value(), isSigned() ? signedOperation : unsignedOperation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        this_type alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        return applyCompare(signedOperation, unsignedOperation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(uConstant);
        return alt.applyCompare(signedOperation, unsignedOperation, source, constantFunction);
      }
      else
        return DomainBitValue(constantFunction(uConstant, source.uConstant));
    }
  DomainBitValue applyCompare(DomainMultiBitCompareOperation operation,
      const this_type& source,
      std::function<bool(VALUE_TYPE, VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return DomainBitValue((*functionTable().multibit_binary_compare_domain)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        this_type alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        return applyCompare(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(uConstant);
        return alt.applyCompare(operation, source, constantFunction);
      }
      else
        return DomainBitValue(constantFunction(uConstant, source.uConstant));
    }
  template <typename IntType>
  this_type& applyBinaryAssign(DomainMultiBitBinaryOperation signedOperation,
      DomainMultiBitBinaryOperation unsignedOperation,
      const DomainMultiBitValue<IntType>& source,
      std::function<VALUE_TYPE(VALUE_TYPE, IntType)> constantFunction)
    {
      if (inherited::isValid() && source.inherited::isValid())
        (*functionTable().multibit_binary_apply_assign)
            (&svalue(), isSigned() ? signedOperation : unsignedOperation, source.value(), env());
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainMultiBitValue<IntType> alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        applyBinaryAssign(signedOperation, unsignedOperation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        VALUE_TYPE thisConstant = uConstant;
        operator=(this_type(Empty(), source));
        setToConstant(thisConstant);
        applyBinaryAssign(signedOperation, unsignedOperation, source, constantFunction);
      }
      else
        uConstant = constantFunction(uConstant, source.uConstant);
      return *this;
    }
  template <typename IntType>
  this_type& applyBinaryAssign(DomainMultiBitBinaryOperation operation,
      const DomainMultiBitValue<IntType>& source,
      std::function<VALUE_TYPE(VALUE_TYPE, IntType)> constantFunction)
    {
      if (inherited::isValid() && source.inherited::isValid())
        (*functionTable().multibit_binary_apply_assign)
            (&svalue(), operation, source.value(), env());
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainMultiBitValue<IntType> alt(Empty(), *this);
        alt.setToConstant(source.uConstant);
        applyBinaryAssign(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        VALUE_TYPE thisConstant = uConstant;
        operator=(this_type(Empty(), source));
        setToConstant(thisConstant);
        applyBinaryAssign(operation, source, constantFunction);
      }
      else
        uConstant = constantFunction(uConstant, source.uConstant);
      return *this;
    }

  DomainMultiBitValue operator~() const
    { return applyUnary(DMBUOBitNegate, [](VALUE_TYPE val) { return ~val; }); }
  DomainMultiBitValue operator-() const
    { return applyUnary(DMBUOOppositeSigned, [](VALUE_TYPE val) { return -val; }); }
  DomainMultiBitValue& operator++()
    { return applyUnaryAssign(DMBUONextSigned, DMBUONextUnsigned,
        [](VALUE_TYPE& val) { ++val; });
    }
  DomainMultiBitValue& operator--()
    { return applyUnaryAssign(DMBUOPrevSigned, DMBUOPrevUnsigned,
        [](VALUE_TYPE& val) { --val; });
    }
  DomainMultiBitValue operator+(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst + snd; };
      return applyBinary(DMBBOPlusSigned, DMBBOPlusUnsigned, source, fun);
    }
  DomainMultiBitValue operator-(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst - snd; };
      return applyBinary(DMBBOMinusSigned, DMBBOMinusUnsigned, source, fun);
    }
  DomainMultiBitValue operator*(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst * snd; };
      return applyBinary(DMBBOTimesSigned, DMBBOTimesUnsigned, source, fun);
    }
  DomainMultiBitValue operator/(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst / snd; };
      return applyBinary(DMBBODivideSigned, DMBBODivideUnsigned, source, fun);
    }
  DomainMultiBitValue operator%(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst % snd; };
      return applyBinary(DMBBOModuloSigned, DMBBOModuloUnsigned, source, fun);
    }
  DomainMultiBitValue operator|(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst | snd; };
      return applyBinary(DMBBOBitOr, source, fun);
    }
  DomainMultiBitValue operator&(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst & snd; };
      return applyBinary(DMBBOBitAnd, source, fun);
    }
  DomainMultiBitValue operator^(const DomainMultiBitValue& source) const
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst ^ snd; };
      return applyBinary(DMBBOBitExclusiveOr, source, fun);
    }

  DomainMultiBitValue& operator+=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst + snd; };
      return applyBinaryAssign(DMBBOPlusSigned, DMBBOPlusUnsigned, source, fun);
    }
  DomainMultiBitValue& operator-=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst - snd; };
      return applyBinaryAssign(DMBBOMinusSigned, DMBBOMinusUnsigned, source, fun);
    }
  DomainMultiBitValue& operator*=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst * snd; };
      return applyBinaryAssign(DMBBOTimesSigned, DMBBOTimesUnsigned, source, fun);
    }
  DomainMultiBitValue& operator/=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst / snd; };
      return applyBinaryAssign(DMBBODivideSigned, DMBBODivideUnsigned, source, fun);
    }
  DomainMultiBitValue& operator%=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst % snd; };
      return applyBinaryAssign(DMBBOModuloSigned, DMBBOModuloUnsigned, source, fun);
    }
  DomainMultiBitValue& operator|=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst | snd; };
      return applyBinaryAssign(DMBBOBitOr, source, fun);
    }
  DomainMultiBitValue& operator&=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst & snd; };
      return applyBinaryAssign(DMBBOBitAnd, source, fun);
    }
  DomainMultiBitValue& operator^=(const DomainMultiBitValue& source)
    { std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> fun
        = [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst ^ snd; };
      return applyBinaryAssign(DMBBOBitExclusiveOr, source, fun);
    }

  template <typename SHT>
  DomainMultiBitValue operator << (SHT sht) const
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst << snd; };
      return applyBinary(DMBBOLeftShift, DomainMultiBitValue<SHT>(sht), fun);
    }
  template <typename SHT>
  DomainMultiBitValue operator << (const DomainMultiBitValue<SHT>& sht) const
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst << snd; };
      return applyBinary(DMBBOLeftShift, sht, fun);
    }
  template <typename SHT>
  DomainMultiBitValue& operator <<= (SHT sht)
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst << snd; };
      return applyBinaryAssign(DMBBOLeftShift, DomainMultiBitValue<SHT>(sht), fun);
    }
  template <typename SHT>
  DomainMultiBitValue operator >> (SHT sht) const
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst >> snd; };
      return applyBinary(DMBBOArithmeticRightShift, DMBBOLogicalRightShift,
        DomainMultiBitValue<SHT>(sht), fun);
    }
  template <typename SHT>
  DomainMultiBitValue operator >> (const DomainMultiBitValue<SHT>& sht) const
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst >> snd; };
      return applyBinary(DMBBOArithmeticRightShift, DMBBOLogicalRightShift,
        sht, fun);
    }
  template <typename SHT>
  DomainMultiBitValue& operator >>= (SHT sht)
    { std::function<VALUE_TYPE(VALUE_TYPE, SHT)> fun
        = [](VALUE_TYPE fst, SHT snd) { return fst >> snd; };
      return applyBinaryAssign(DMBBOArithmeticRightShift, DMBBOLogicalRightShift,
        DomainMultiBitValue<SHT>(sht), fun);
    }

  DomainBitValue operator==(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareEqual, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst == snd; });
    }
  DomainBitValue operator!=(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareDifferent, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst != snd; });
    }
  DomainBitValue operator<=(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareLessOrEqualSigned, DMBCOCompareLessOrEqualUnsigned,
        source, [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst <= snd; });
    }
  DomainBitValue operator>=(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareGreaterOrEqualSigned, DMBCOCompareGreaterOrEqualUnsigned,
        source, [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst >= snd; });
    }
  DomainBitValue operator<(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareLessSigned, DMBCOCompareLessUnsigned,
        source, [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst < snd; });
    }
  DomainBitValue operator>(const DomainMultiBitValue& source) const
    { return applyCompare(DMBCOCompareGreaterSigned, DMBCOCompareGreaterUnsigned,
        source, [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst > snd; });
    }

  template <typename TypeVal>
  friend this_type RotateRight(const this_type& first, TypeVal second)
    { std::function<VALUE_TYPE(VALUE_TYPE, int32_t)> fun
        = [](VALUE_TYPE fst, int32_t snd)
        { return unisim::util::arithmetic::RotateRight(fst, snd); };
      return first.applyBinary(DMBBORightRotate,
        DomainMultiBitValue<int32_t>(second), fun);
    }
  friend this_type BitScanReverse(const this_type& first)
    { return first.applyUnary(DMBUOBitScanReverse,
        [](VALUE_TYPE fst)
          { return unisim::util::arithmetic::BitScanReverse(fst); });
    }
  friend this_type RotateRight(const this_type& first, const DomainMultiBitValue<int32_t>& second)
    { return first.applyBinary(DMBBORightRotate, second,
        [](VALUE_TYPE fst, int32_t snd)
          { return unisim::util::arithmetic::RotateRight(fst, snd); });
    }
  friend this_type ByteSwap(const this_type& first)
    {
      if (first.inherited::isValid())
      { DomainMultiBitValue result = first;
        for (int index = 0; index < sizeof(VALUE_TYPE)/2; ++index) {
          DomainMultiBitValue first_source(first), last_source(first);
          first_source.reduce(index*8+0, index*8+7);
          last_source.reduce((sizeof(VALUE_TYPE)-index-1)*8+0, (sizeof(VALUE_TYPE)-index)*8-1);
          result.bitset(index*8+0, index*8+7, last_source);
          result.bitset((sizeof(VALUE_TYPE)-index-1)*8+0, (sizeof(VALUE_TYPE)-index)*8-1, first_source);
        }
        return result;
      }
      else
        return DomainMultiBitValue(unisim::util::endian::ByteSwap(first.uConstant));
    }
  bool isConstant(VALUE_TYPE* value) const
    {
      if (inherited::isValid()) {
        DomainIntegerConstant res;
        res.sizeInBits = sizeof(VALUE_TYPE);
        res.isSigned = isSigned();
        bool result = (*functionTable().multibit_is_constant_value)(this->value(), &res);
        if (result && value)
           *value = (VALUE_TYPE) res.integerValue;
        return result;
      }
      else
      {
        if (value)
          *value = uConstant;
        return true;
      }
    }
};

template <typename VALUE_TYPE>
struct DomainMultiFloatValue : public DomainValue {
  private:
   typedef DomainMultiFloatValue<VALUE_TYPE> thisType;
   VALUE_TYPE vtConstant;

  public:
   DomainMultiFloatValue() : vtConstant(0.0) {}
   DomainMultiFloatValue(VALUE_TYPE val) : vtConstant(val) {}
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

   template <class ResultType, int size>
   DomainMultiFloatValue<ResultType> castToMultiFloat() const
      {  return DomainMultiFloatValue<ResultType>((*functionTable().multifloat_cast_multifloat)(value(), size, env()), *this); }
   template <class ResultType, int size>
   DomainMultiBitValue<ResultType> castToMultiBit() const
      {  return DomainMultiBitValue<ResultType>((*functionTable().multifloat_create_cast_multibit)(value(), size, env()), *this); }

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

   DomainMultiBitValue<int32_t> compare(const DomainMultiFloatValue& source) const
      {  return DomainMultiBitValue<int32_t>((*functionTable().multifloat_binary_full_compare_domain)
               (value(), source.value(), env()), *this);
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
   void setToNaN();
   void setQuietBit();
   DomainBitValue setFlushToZero();
   DomainBitValue queryIsSNaN() const;
   DomainBitValue queryIsQNaN() const;

   void multAssignAndAdd(const thisType& op1, const thisType& op2)
      {  (*functionTable().multifloat_ternary_apply_assign)
               (&svalue(), DMFTOMultAdd, op1.value(), op2.value(), env());
      }
   DomainBitValue queryIsInvalidMulAddNode(const thisType& op1, const thisType& op2) const
      {  return DomainBitValue((*functionTable().multifloat_ternary_query)
               (value(), DMFTQIsInvalid, op1.value(), op2.value(), env()), *this);
      }
   void negateAssign()
      {  (*functionTable().multifloat_unary_apply_assign)(&svalue(), DMFUOOpposite, env()); }
   void absAssign()
      {  (*functionTable().multifloat_unary_apply_assign)(&svalue(), DMFUOAbs, env()); }
   void sqrtAssign()
      {  (*functionTable().multifloat_unary_apply_assign)(&svalue(), DMFUOSqrt, env()); }
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
   void setRegisterValue(int registerIndex, DomainValue&& value)
      {  (*pfFunctions->set_register_value)(pmModel, registerIndex,
            &value.svalue(), pParameters, &uErrors);
      }

   DomainElement getRegisterValueAsElement(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr;
         return (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
      }
   DomainBitValue getRegisterValueAsBit(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainBitValue(std::move(result), domainFunctions, peDomainEnv);
      }
   template <typename TypeInt>
   DomainMultiBitValue<TypeInt> getRegisterValueAsMultiBit(int registerIndex) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainMultiBitValue<TypeInt>(std::move(result), domainFunctions, peDomainEnv);
      }
   // DomainMultiFloatValue getRegisterValueAsMultiFloat(int registerIndex) const
   //    {  DomainElementFunctions* domainFunctions = nullptr; 
   //       DomainElement result = (*pfFunctions->get_register_value)
   //             (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
   //       return DomainMultiFloatValue(std::move(result), domainFunctions, peDomainEnv);
   //    }

   template <class IntType>
   DomainMultiBitValue<IntType> loadMultiBitValue(
         const DomainMultiBitValue<uint32_t>& indirectAddress) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_value)
               (pmModel, indirectAddress.value(), sizeof(IntType), pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue<IntType>(std::move(result), domainFunctions, peDomainEnv);
      }
   template <class IntType>
   DomainMultiBitValue<IntType> loadMultiBitDisjunctionValue(
         DomainMultiBitValue<uint32_t>&& indirectAddress) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_disjunctive_value)
               (pmModel, indirectAddress.value(), sizeof(IntType), pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue<IntType>(std::move(result), domainFunctions, peDomainEnv);
      }
   template <class FloatType>
   DomainMultiFloatValue<FloatType> loadMultiFloatValue(
         DomainMultiBitValue<uint32_t>&& indirectAddress) const
      {  DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multifloat_value)
               (pmModel, indirectAddress.value(), sizeof(FloatType), pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiFloatValue<FloatType>(std::move(result), domainFunctions, peDomainEnv);
      }

   template <class IntType>
   void storeMultiBitValue(const DomainMultiBitValue<uint32_t>& indirectAddress,
         const DomainMultiBitValue<IntType>& value)
      {  (*pfFunctions->store_value)(pmModel, indirectAddress.value(),
               value.value(), pParameters, &uErrors);
      }
   template <class FloatType>
   void storeMultiFloatValue(const DomainMultiBitValue<uint32_t>& indirectAddress,
         const DomainMultiFloatValue<FloatType>& value)
      {  (*pfFunctions->store_value)(pmModel, indirectAddress.value(),
               value.value(), pParameters, &uErrors);
      }
   template <class IntType>
   void constraintStoreValue(const DomainMultiBitValue<uint32_t>& indirectAddress,
         const DomainMultiBitValue<IntType>& value, unsigned indirectRegister)
      {  (*pfFunctions->constraint_store_value)(pmModel, indirectAddress.value(),
            value.value(), indirectRegister, pParameters, &uErrors);
      }
   template <class IntType>
   void constraintAddress(const DomainMultiBitValue<uint32_t>& indirectAddress,
         const DomainMultiBitValue<IntType>& value)
      {  (*pfFunctions->constraint_address)(pmModel, indirectAddress.value(),
            value.value(), pParameters, &uErrors);
      }
};

struct FP
{
  template <typename FLOAT>
  static void SetDefaultNan( FLOAT& result )
    { result.setToNaN(); }
  template <typename FLOAT>
  static void SetQuietBit( FLOAT& result )
    { result.setQuietBit(); }
  
  template <typename FLOAT> static DomainBitValue
  FlushToZero( FLOAT& op, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { return op.setFlushToZero(); }

  template <typename FLOAT> static
  DomainMultiBitValue<int32_t> Compare( FLOAT op1, FLOAT op2, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { return op1.compare(op2); }

  template <typename FLOAT> static DomainBitValue IsSNaN( FLOAT const& op )
    { return op.queryIsSNaN(); }
  template <typename FLOAT> static DomainBitValue IsQNaN( FLOAT const& op )
    { return op.queryIsQNaN(); }
  
  template <typename FLOAT, class ARCH> static
  void Add( FLOAT& acc, FLOAT const& op2, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc += op2; }
  template <typename FLOAT, class ARCH> static
  void Sub( FLOAT& acc, FLOAT const& op2, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc -= op2; }
  template <typename FLOAT, class ARCH> static
  void Div( FLOAT& acc, FLOAT const& op2, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc /= op2; }

  template <typename FLOAT, class ARCH> static
  void Mul( FLOAT& acc, FLOAT const& op2, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc *= op2; }

  template <typename FLOAT, class ARCH> static
  void MulAdd( FLOAT& acc, FLOAT const& op1, FLOAT const& op2, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc.multAssignAndAdd(op1, op2); }
  template <typename SOFTDBL> static DomainBitValue
  IsInvalidMulAdd( SOFTDBL const& acc, SOFTDBL const& op1, SOFTDBL const& op2, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { return acc.queryIsInvalidMulAddNode(op1, op2); }
  template <typename FLOAT> static void Neg( FLOAT& acc )
    { acc.negateAssign(); }
  template <typename FLOAT> static void Abs( FLOAT& acc )
    { acc.absAssign(); }
  template <typename FLOAT, class ARCH> static void Sqrt( FLOAT& acc, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { acc.sqrtAssign(); }

  template <class ARCH>
  static void FtoF(DomainMultiFloatValue<double>& dst, DomainMultiFloatValue<float>& src, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { dst = src.castToMultiFloat<double, 64>(); }
  template <class ARCH>
  static void FtoF(DomainMultiFloatValue<float>& dst, DomainMultiFloatValue<double>& src, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { dst = src.castToMultiFloat<float, 32>(); }

  template <typename intT, typename fpT, class ARCH> static
  void FtoI( DomainMultiBitValue<intT>& dst, DomainMultiFloatValue<fpT> const& src, int fracbits, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { dst = src.template castToMultiBit<intT, sizeof(intT)>(); /* [TODO] fracbits? */ }
  template <typename fpT, typename intT, class ARCH> static
  void ItoF( DomainMultiFloatValue<fpT>& dst, DomainMultiBitValue<intT> const& src, int fracbits, ARCH& arch, DomainMultiBitValue<uint32_t> const& fpscr_val )
    { dst = src.template castToMultiFloat<fpT, sizeof(fpT)>(); /* [TODO] fracbits? */ }
};


struct Processor
{
  //   =====================================================================
  //   =                           Configuration                           =
  //   =====================================================================
  struct Unimplemented {};
  struct Undefined {};
  typedef ::FP FP;
    
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
  typedef DomainMultiFloatValue<double>  F64;
  typedef DomainMultiFloatValue<float> F32;
  typedef DomainBitValue         BOOL;
  typedef DomainMultiBitValue<uint8_t>  U8;
  typedef DomainMultiBitValue<uint16_t> U16;
  typedef DomainMultiBitValue<uint32_t> U32;
  typedef DomainMultiBitValue<uint64_t> U64;
  typedef DomainMultiBitValue<int8_t>  S8;
  typedef DomainMultiBitValue<int16_t> S16;
  typedef DomainMultiBitValue<int32_t> S32;
  typedef DomainMultiBitValue<int64_t> S64;

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
    
  struct CP15Reg
  {
    virtual            ~CP15Reg() {}
    virtual unsigned    RequiredPL() { return 1; }
    virtual void        Write( Processor& proc, U32 const& value ) { throw Unimplemented(); }
    virtual U32         Read( Processor& proc ) { throw Unimplemented(); return U32(); }
    virtual char const* Describe() = 0;
  };

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
  
  struct _FPSCR;
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
    PSR( Processor& p, StatusRegister const& ref)
      : StatusRegister(ref)
      , proc(p)
    {}

    bool   GetJ() const { return (iset == Jazelle) or (iset == ThumbEE); }
    bool   GetT() const { return (iset ==   Thumb) or (iset == ThumbEE); }

    template <typename RF>
    void   Set( RF const& _, const _FPSCR& value )
    { Set(_, value.operator U32()); }
    template <typename RF>
    void   Set( RF const& _, const DomainBitValue& value )
    { Set(_, U32(value)); }
    template <typename RF>
    void   Set( RF const& _, const U32& value )
    {
      // StaticAssert<(RF::pos > 31) or ((RF::pos + RF::size) <= 28)>::check(); // NZCV
      StaticAssert<(RF::pos > 24) or ((RF::pos + RF::size) <= 24)>::check(); // J
      StaticAssert<(RF::pos >  9) or ((RF::pos + RF::size) <=  9)>::check(); // ITHI, E
      StaticAssert<(RF::pos >  5) or ((RF::pos + RF::size) <=  0)>::check(); // T, MODE

      U32 reg = GetBits();
      _.Set( reg, value );
      SetBits( reg, -1 );
    }
      
    template <typename RF>
    U32    Get( RF const& _ )
    {
      //  StaticAssert<(RF::pos > 31) or ((RF::pos + RF::size) <= 28)>::check(); // NZCV
      StaticAssert<(RF::pos > 24) or ((RF::pos + RF::size) <= 24)>::check(); // ITLO, J
      StaticAssert<(RF::pos >  9) or ((RF::pos + RF::size) <=  9)>::check(); // ITHI, E
      StaticAssert<(RF::pos >  5) or ((RF::pos + RF::size) <=  0)>::check(); // T, MODE
        
      return _.Get( GetBits() );
    }
      
    void   SetBits( U32 const& bits, uint32_t mask );
    U32    GetBits() { return U32(proc.memoryState->getRegisterValueAsElement(CPSR_ID), proc); }
    BOOL   n() const { return proc.memoryState->getRegisterValueAsBit(RegID("n").code); }
    BOOL   z() const { return proc.memoryState->getRegisterValueAsBit(RegID("z").code); }
    BOOL   c() const { return proc.memoryState->getRegisterValueAsBit(RegID("c").code); }
    BOOL   v() const { return proc.memoryState->getRegisterValueAsBit(RegID("v").code); }
    U8     GetITState() const
      { return outitb ? U8(0) : U8(proc.memoryState->getRegisterValueAsElement(RegID("itstate").code), proc); }
    
    void   Set( ERF const& _, const U32& value ) { if (proc.Test(value != U32(bigendian))) proc.UnpredictableInsnBehaviour(); }
    void   SetITState( uint8_t init_val, Processor& p )
       {  this->Set(ITLORF(), U32(init_val));
         this->Set(ITHIRF(), U32(init_val>>2));
       }
    void   SetITState( U8&& init_val )
       {  this->Set(ITLORF(), U32(init_val));
         this->Set(ITHIRF(), U32(init_val>>2));
       }
    BOOL   InITBlock()   {  return (((Get( ITHIRF() ) << 2) | Get( ITLORF() )) & U32(0b1111)) != U32(0); }

    U32    Get( JRF const& _ ) { return U32(GetJ()); }
    U32    Get( TRF const& _ ) { return U32(GetT()); }
      
    /* Endianness */
    U32    Get( ERF const& _ ) { return U32(bigendian); }
    U32    Get( MRF const& _ ) { return U32(mode); }
      
    Processor& proc;
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
      RLStartSpecial=RLGeneralPurpose,
      RLSpecial=RLGeneralPurpose+SRegID::end,
      RLStartNeonRegs=RLSpecial,
      RLNeonRegs=RLSpecial+32,
      RLStartForeign=RLNeonRegs,
      RLEnd = RLNeonRegs
    };
  Processor()
     :  cpsr(*this, StatusRegister()), FPSCR(*this), FPEXC(*this), is_it_assigned(false),
        mode(), unpredictable(false),
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
      return U32(memoryState->getRegisterValueAsElement(id), *this);
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
          memoryState->setRegisterValue(id, std::move(value));
        else {
          uint32_t val;
          if (value.isConstant(&val))
             addJumpTargetAddress(val);
          else {
             // [TODO] forcer les disjonctions + énumérer
             // pour les dynamic jumps
          }
        }
      }
      else if (memoryState) // isInterpret
        memoryState->setRegisterValue(id, std::move(value));
    }
  enum branch_type_t { B_JMP = 0, B_CALL, B_RET, B_EXC, B_DBG, B_RFE };
  void SetGPR( uint32_t id, const U32& value ) {
    if (id != 15)
      memoryState->setRegisterValue(id, U32(value));
    else
      SetNIA( value, B_JMP );
  }
  void SetGPR_usr( uint32_t id, U32 const& value ) { /* system mode */ throw Unimplemented(); }
  U32  GetGPR_usr( uint32_t id ) { /* system mode */ throw Unimplemented(); return U32(); }
    
  U32  GetNIA() { return U32(target_addresses.addresses[0]); }
  void SetNIA( U32 const& nia, branch_type_t bt )
  {
    if (next_targets_queries) {
      uint32_t val;
      if (nia.isConstant(&val)) {
        if (bt == B_CALL)
          addCallTargetAddress(val);
        else if (bt == B_RET)
          addReturnTargetAddress(val);
        else
         addJumpTargetAddress(val);
      }
      else {
         // [TODO] forcer les disjonctions + énumérer
         // pour les dynamic jumps
      }
    };
  }


  struct RegisterAccess {
    RegisterAccess(int registerIndex, Processor& aproc) : proc(&aproc) {}
    RegisterAccess(uint32_t aval) : val(aval), proc(nullptr) {}
    RegisterAccess(const U32& aval) : val(aval), proc(nullptr) {}
    RegisterAccess(const RegisterAccess& source) = default;
    RegisterAccess& operator=(const RegisterAccess& source) = default;

    RegisterAccess& operator=(const U32& source)
      {  if (proc)
            proc->memoryState->setRegisterValue(RegID("fpscr").code, U32(source));
         else
            val = source;
         return *this;
      }
    operator U32() const
      {  return proc ? proc->memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpscr").code) : val; }

  private:
    U32 val;
    int registerIndex;
    Processor* proc;
  };

  RegisterAccess GetForeignRegister( uint8_t foreign_mode, uint32_t idx )
    { return RegisterAccess(RLStartForeign + idx, *this); }
  U32  GetBankedRegister( uint8_t foreign_mode, uint32_t idx )
  {
    if ((cpsr.mode == foreign_mode) or
        (idx < 8) or
        (idx >= 15) or
        ((foreign_mode != FIQ_MODE) and (cpsr.mode != FIQ_MODE) and (idx < 13))
        )
      return RegisterAccess( idx, *this );
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
    GetForeignRegister( foreign_mode, idx ) = value;
  }
    
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
        U8 itstate( cpsr.GetITState() );
        itstate = (Test((itstate & U8(7)) != U8(0))) ? ((itstate & U8(-32)) | ((itstate << 1) & U8(31))) : U8(0);
        cpsr.SetITState(std::move(itstate));
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

  U32 RoundTowardsZeroFPSCR() const
  {
    U32 fpscr = memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpscr").code);
    unisim::component::cxx::processor::arm::RMode.Set( fpscr, U32(unisim::component::cxx::processor::arm::RoundTowardsZero) );
    return fpscr;
  }
    
  U32 RoundToNearestFPSCR() const
  {
    U32 fpscr = memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpscr").code);
    unisim::component::cxx::processor::arm::RMode.Set( fpscr, U32(unisim::component::cxx::processor::arm::RoundToNearest) );
    return fpscr;
  }
    
  U64 eneonread( unsigned reg, unsigned size, unsigned pos )
  {
    U64 res = memoryState->getRegisterValueAsMultiBit<uint64_t>(RLStartNeonRegs + reg);
    if (pos > 0 || size < 64) {
       res.reduce(pos, pos+size-1);
       res.extendWithZero(64);
    }
    return res;
  }

  void eneonwrite( unsigned reg, unsigned size, unsigned pos, const U64& xpr )
  {
    if (pos > 0 || size < 64) {
       U64 res = memoryState->getRegisterValueAsMultiBit<uint64_t>(RLStartNeonRegs + reg);
       U64 source = xpr;
       source.reduce(0, size-1);
       res.bitset(pos, pos+size-1, source);
       memoryState->setRegisterValue(RLStartNeonRegs + reg, DomainValue(res));
    }
    else
       memoryState->setRegisterValue(RLStartNeonRegs + reg, DomainValue(xpr));
  }

  U32  GetVSU( unsigned idx ) { return U32( eneonread( idx / 2, 4, (idx*4) & 4 ) ); }
  void SetVSU( unsigned idx, U32 val ) { eneonwrite( idx / 2, 4, (idx*4) & 4, U64(val) ); }
  U64  GetVDU( unsigned idx ) { return eneonread( idx, 8, 0 ); }
  void SetVDU( unsigned idx, U64 val ) { eneonwrite( idx, 8, 0, U64(val) ); }
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
  
  U32  MemURead32( U32 const& addr )
    { return memoryState->loadMultiBitValue<uint32_t>(addr); }
  U16  MemURead16( U32 const& addr )
    { return memoryState->loadMultiBitValue<uint16_t>(addr); }
  U32  MemRead32( U32 const& addr )
    { return memoryState->loadMultiBitValue<uint32_t>(addr); }
  U16  MemRead16( U32 const& addr )
    { return memoryState->loadMultiBitValue<uint16_t>(addr); }
  U8  MemRead8( U32 const& addr )
    { return memoryState->loadMultiBitValue<uint8_t>(addr); }
  
  void MemUWrite32( U32 const& addr, U32 const& value )
    { return memoryState->storeMultiBitValue<uint32_t>(addr, value); }
  void MemUWrite16( U32 const& addr, U16 const& value )
    { return memoryState->storeMultiBitValue<uint16_t>(addr, value); }
  void MemWrite32( U32 const& addr, U32 const& value )
    { return memoryState->storeMultiBitValue<uint32_t>(addr, value); }
  void MemWrite16( U32 const& addr, U16 const& value )
    { return memoryState->storeMultiBitValue<uint16_t>(addr, value); }
  void MemWrite8( U32 const& addr, U8 const& value )
    { return memoryState->storeMultiBitValue<uint8_t>(addr, value); }
    
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

  PSR              cpsr;
  struct _FPSCR {
    _FPSCR(Processor& aproc) : proc(&aproc) {}
    _FPSCR(uint32_t aval) : val(aval), proc(nullptr) {}
    _FPSCR(const U32& aval) : val(aval), proc(nullptr) {}
    _FPSCR(const _FPSCR& source) = default;
    _FPSCR& operator=(const _FPSCR& source) = default;

    _FPSCR& operator=(const U32& source)
      {  if (proc)
            proc->memoryState->setRegisterValue(RegID("fpscr").code, U32(source));
         else
            val = source;
         return *this;
      }
    operator U32() const
      {  return proc ? proc->memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpscr").code) : val; }
    operator BOOL() const
      {  return proc ? BOOL(proc->memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpscr").code)) : val.operator BOOL(); }
    template <typename TypeOperand>
    U32 operator&(const TypeOperand& source) const { return this->operator U32() & source; }
    template <typename TypeOperand>
    U32 operator<<(const TypeOperand& source) const { return this->operator U32() << source; }
    template <typename TypeOperand>
    U32 operator>>(const TypeOperand& source) const { return this->operator U32() >> source; }
    U32 operator~() const { return ~this->operator U32(); }

  private:
    U32 val;
    Processor* proc;
  }                FPSCR;
  struct _FPEXC {
    _FPEXC(Processor& aproc) : proc(&aproc) {}
    _FPEXC(uint32_t aval) : val(aval), proc(nullptr) {}
    _FPEXC(const U32& aval) : val(aval), proc(nullptr) {}
    _FPEXC(const _FPEXC& source) = default;
    _FPEXC& operator=(const _FPEXC& source) = default;

    _FPEXC& operator=(const U32& source)
      {  if (proc)
            proc->memoryState->setRegisterValue(RegID("fpexc").code, U32(source));
         else
            val = source;
         return *this;
      }
    operator U32() const
      {  return proc ? proc->memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpexc").code) : val; }
    operator BOOL() const
      {  return proc ? BOOL(proc->memoryState->getRegisterValueAsMultiBit<uint32_t>(RegID("fpexc").code)) : val.operator BOOL(); }
    template <typename TypeOperand>
    U32 operator&(const TypeOperand& source) const { return this->operator U32() & source; }
    template <typename TypeOperand>
    U32 operator<<(const TypeOperand& source) const { return this->operator U32() << source; }
    template <typename TypeOperand>
    U32 operator>>(const TypeOperand& source) const { return this->operator U32() >> source; }
    U32 operator~() const { return ~this->operator U32(); }

  private:
    U32 val;
    Processor* proc;
  }                FPEXC;
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

// inline DomainMultiBitValue
// DomainBitValue::castToMultiBit(int sizeInBits, bool isSigned) const {
//    return DomainMultiBitValue((*functionTable().bit_create_cast_multibit)
//          (value(), sizeInBits, env()), *this, isSigned);
// }

// inline
// DomainMultiBitValue::DomainMultiBitValue(Processor& processor)
//    : DomainValue(processor), fSigned(false) {}

// inline
// DomainMultiBitValue::DomainMultiBitValue(DomainMultiBitElement&& value,
//       Processor& processor, bool isSigned)
//    :  DomainValue(std::move(value), processor), fSigned(isSigned) {}
   
template < typename FLOAT >
inline
DomainMultiFloatValue<FLOAT>::DomainMultiFloatValue(Processor& processor)
   : DomainValue(processor) {}

template < typename FLOAT >
inline
DomainMultiFloatValue<FLOAT>::DomainMultiFloatValue(DomainMultiFloatElement&& value,
      Processor& processor)
   :  DomainValue(std::move(value), processor) {}

bool CheckCondition( Processor& state, unsigned cond )
{
  auto& cpsr = state.CPSR();
  Processor::BOOL N = cpsr.n(), Z = cpsr.z(), C = cpsr.c(), V = cpsr.v(), result(false);
  
  switch (cond) {
  case  0: result =                   Z; break; // eq; equal
  case  1: result =               not Z; break; // ne; not equal
  case  2: result =                   C; break; // cs/hs; unsigned higher or same
  case  3: result =               not C; break; // cc/lo; unsigned lower
  case  4: result =                   N; break; // mi; negative
  case  5: result =               not N; break; // pl; positive or zero
  case  6: result =                   V; break; // vs; overflow set
  case  7: result =               not V; break; // vc; overflow clear
  case  8: result =    not (not C or Z); break; // hi; unsigned higher
  case  9: result =        (not C or Z); break; // ls; unsigned lower or same
  case 10: result =       not (N xor V); break; // ge; signed greater than or equal
  case 11: result =           (N xor V); break; // lt; signed less than
  case 12: result = not(Z or (N xor V)); break; // gt; signed greater than
  case 13: result =    (Z or (N xor V)); break; // le; signed less than or equal
  case 14: return true;                         // al; always
  default:                                      // nv; never (illegal)
    throw std::logic_error( "bad condition" );
  }

  return state.Test(result);
}

bool CheckCondition( Processor& state, Processor::ITCond const& cond )
{
  typedef Processor::BOOL BOOL;
  typedef Processor::U8   U8;
  auto& cpsr = state.CPSR();
  BOOL N = cpsr.n(), Z = cpsr.z(), C = cpsr.c(), V = cpsr.v();
  U8 cc = (cpsr.GetITState() >> 4);
  return state.Test(
    ((cpsr.GetITState() & U8(0b1111)) == U8(0)) or // unconditional
    ((cc == U8(0)) and (Z)) or // eq; equal
    ((cc == U8(1)) and (not Z)) or // ne; not equal
    ((cc == U8(2)) and (C)) or // cs/hs; unsigned higher or same
    ((cc == U8(3)) and (not C)) or // cc/lo; unsigned lower
    ((cc == U8(4)) and (N)) or // mi; negative
    ((cc == U8(5)) and (not N)) or // pl; positive or zero
    ((cc == U8(6)) and (V)) or // vs; overflow set
    ((cc == U8(7)) and (not V)) or // vc; overflow clear
    ((cc == U8(8)) and (not (not C or Z))) or // hi; unsigned higher
    ((cc == U8(9)) and ((not C or Z))) or // ls; unsigned lower or same
    ((cc == U8(10)) and (not (N xor V))) or // ge; signed greater than or equal
    ((cc == U8(11)) and ((N xor V))) or // lt; signed less than
    ((cc == U8(12)) and (not(Z or (N xor V)))) or // gt; signed greater than
    ((cc == U8(13)) and ((Z or (N xor V)))) or // le; signed less than or equal
    ((cc == U8(14)) and DomainBitValue(true)));
}


struct THUMBISA : public unisim::component::cxx::processor::arm::isa::thumb::Decoder<Processor>
{
  typedef unisim::component::cxx::processor::arm::isa::thumb::CodeType CodeType;
  typedef unisim::component::cxx::processor::arm::isa::thumb::Operation<Processor> Operation;
  static CodeType mkcode( uint32_t code ) { return CodeType( code ); }
  static bool const is_thumb = true;
};

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
  }

  void translate( std::ostream& sink )
  {
    try
      {
        if      (status.iset == status.Arm)
          {
            assert(false);
            // ARMISA armisa;
            // extract( sink, armisa );
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

}

DLL_API bool armsec_interpret(void* processor, char* instruction_buffer,
      size_t buffer_size, uint64_t address, uint64_t target_address,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      InterpretParameters* parameters) {

}

}

