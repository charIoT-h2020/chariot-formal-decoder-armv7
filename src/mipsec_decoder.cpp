#include <mipsec_decoder.h>
#include <unisim/component/cxx/processor/mips/isa/disasm.hh>
#include <unisim/component/cxx/processor/mips/isa/mipsel.tcc>
#include <unisim/util/identifier/identifier.hh>
#include <unisim/util/likely/likely.hh>
#include <unisim/util/arithmetic/arithmetic.hh>
#include <unisim/util/endian/endian.hh>
#include <functional>
#include <limits>
#include <cmath>
#include <cassert>

enum REG_ID { R0=0, R15=15,CPSR_ID} ;

template <bool test> struct StaticAssert {};
template <> struct StaticAssert<true> { static void check() {}; };

template <class T, class U>  struct CmpTypes { static bool const same = false; };
template <class T>  struct CmpTypes<T,T> { static bool const same = true; };

class PathExplorer {
private:
  uint64_t auChoice[2] = {}; // could be unsigned: only 3 bits are useful for armv7
  unsigned uCurrentStackPosition = 0;
  unsigned uLastZeroBit = 0;
  unsigned uLastIncBit = 0;
  bool uLastResult = false;
  bool uLastLogCases = false;
 
  void clearHigh(int bitPosition)
    { assert(0 <= bitPosition && bitPosition<=2*8*sizeof(uint64_t));
      if (bitPosition%(8*sizeof(uint64_t)) > 0)
        auChoice[bitPosition/(8*sizeof(uint64_t))]
            &= ~(~((uint64_t) 0) << (bitPosition%(8*sizeof(uint64_t))));
      for (int index = (bitPosition+8*sizeof(uint64_t)-1)/(8*sizeof(uint64_t)); index < 2; ++index)
        auChoice[index] = 0;
    }

public:
  unsigned& currentStackPosition() { return uCurrentStackPosition; }
  unsigned& lastZeroBit() { return uLastZeroBit; }
  unsigned& lastIncBit() { return uLastIncBit; }
  bool& lastResult() { return uLastResult; }
  bool& lastLogCases() { return uLastLogCases; }

  bool cbitArray(int bitPosition) const
    { assert(0 <= bitPosition && bitPosition<2*8*sizeof(uint64_t));
      return auChoice[bitPosition/(8*sizeof(uint64_t))]
            & (((uint64_t) 1) << (bitPosition%(8*sizeof(uint64_t))));
    }
  void setFalseBitArray(int bitPosition)
    { assert(0 <= bitPosition && bitPosition<2*8*sizeof(uint64_t));
      auChoice[bitPosition/(8*sizeof(uint64_t))]
           &= ~(((uint64_t) 1) << (bitPosition%(8*sizeof(uint64_t))));
    }
  void setTrueBitArray(int bitPosition)
    { assert(0 <= bitPosition && bitPosition<2*8*sizeof(uint64_t));
      auChoice[bitPosition/(8*sizeof(uint64_t))]
           |= (((uint64_t) 1) << (bitPosition%(8*sizeof(uint64_t))));
    }
  int log_base_2() const
    { // bsr instruction
      int result = 0;
      if (auChoice[1]) {
        uint64_t val = auChoice[1];
        result = 8*sizeof(uint64_t)+1;
        while (val >>= 1)
          ++result;
      }
      else if (auChoice[0]) {
        uint64_t val = auChoice[0];
        result = 1;
        while (val >>= 1)
          ++result;
      }
      return result;
    }

public:
  PathExplorer() = default;
  PathExplorer(const PathExplorer&) = default;
  PathExplorer& operator=(const PathExplorer&) = default;

  bool close()
    { if (uLastLogCases /* > 0 */) {
        assert(uCurrentStackPosition >= (int) uLastLogCases);
        if (uLastResult == 0) { // pop from last branch/conversion
          assert(uLastZeroBit == 0 || uLastIncBit < uLastZeroBit);
          clearHigh(uLastZeroBit);
          if (uLastZeroBit > 0) {
            while (cbitArray(uLastIncBit)) {
              setFalseBitArray(uLastIncBit);
              ++uLastIncBit;
            };
            assert(uLastIncBit < uLastZeroBit);
            setTrueBitArray(uLastIncBit);
          };
        }
        else /* if (uLastLogCases <= ...)  */ // branch
          setTrueBitArray(uCurrentStackPosition-1);
      };
      uCurrentStackPosition = 0;
      uLastResult = uLastLogCases = false;
      uLastZeroBit = uLastIncBit = 0;
      return auChoice[0] == 0 && auChoice[1] == 0;
    }
};

class DecisionVector {
  private:
   std::vector<int> vuEarlyDecisions;
   std::vector<std::pair<int, uint64_t> > vuLastInstructionDecisions;

  public:
   DecisionVector() = default;
   DecisionVector(const DecisionVector&) = default;

   void addNewTarget(uint64_t target)
      {  vuLastInstructionDecisions.push_back(std::make_pair(
               (int) vuLastInstructionDecisions.size(), target));
      }
   void resetLastTarget(uint64_t target)
      {  vuLastInstructionDecisions.back().second = target; }
   void setToNextInstruction()
      {  if (!vuLastInstructionDecisions.empty()) {
            vuEarlyDecisions.push_back((int) vuLastInstructionDecisions.size());
            vuLastInstructionDecisions.clear();
         }
      }
   void setToLastInstruction()
      {  if (!vuLastInstructionDecisions.empty())
            vuEarlyDecisions.push_back((int) vuLastInstructionDecisions.size());
      }
   void filter(uint64_t target)
      {  for (int index = vuLastInstructionDecisions.size()-1; index >= 0; --index) {
            if (vuLastInstructionDecisions[index].second != target)
               vuLastInstructionDecisions.erase(vuLastInstructionDecisions.begin() + index);
         }
      }
   bool isEmpty() const { return vuEarlyDecisions.empty(); }
   bool isOnLast() const { return vuEarlyDecisions.size() == 1; }
   uint64_t getLastTarget() const
      {  assert(vuEarlyDecisions.size() == 1);
         return !vuLastInstructionDecisions.empty()
            ? vuLastInstructionDecisions.back().second : 0;
      }
   void advance()
      {  assert(vuEarlyDecisions.size() >= 1);
         vuEarlyDecisions.erase(vuEarlyDecisions.begin());
         if (vuEarlyDecisions.empty())
            vuLastInstructionDecisions.clear();
      }
   bool doesNeedSeveralExecution() const
      {  assert(vuEarlyDecisions.size() >= 1);
         return vuEarlyDecisions.front() > 1;
      }
   bool acceptTarget(uint64_t target) const
      {  return vuLastInstructionDecisions.back().second == target; }
};

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
  DomainValue() : deValue{ nullptr }, pfFunctions(nullptr), peEnv(nullptr) {}
  class Empty {};
  DomainValue(Empty, const DomainValue& ref)
    : deValue{ nullptr }, pfFunctions(ref.pfFunctions), peEnv(ref.peEnv) {}
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
  bool is_top() const
    {
      assert(pfFunctions);
      return (*pfFunctions->is_top)(deValue);
    }
  friend char* debugPrint(const DomainValue* value);
};

static char*
increase_vector_char_buffer_size(char* buffer, int old_length, int new_length, void* awriter)
{  std::vector<char>* writer = reinterpret_cast<std::vector<char>*>(awriter);
   assert(&(*writer)[0] == buffer && writer->size() == old_length);
   writer->insert(writer->end(), new_length-old_length, '\0');
   return &(*writer)[0];
}

char* debugPrint(const DomainValue* value)
{  static std::vector<char> buffer;
   buffer.clear();
   if (!value || !value->deValue.content || !value->pfFunctions) {
      buffer.insert(buffer.begin(), 3, '.');
      buffer.push_back('\0');
   }
   else {
      buffer.insert(buffer.begin(), 40, '\0');
      int buffer_size = 40;
      int length = 0;
      (*value->pfFunctions->write)(value->deValue, &buffer[0], buffer_size, &length, &buffer,
            &increase_vector_char_buffer_size);
      buffer.resize(length+1);
   }
   return &buffer[0];
}

// extern DomainValue getRootDomainValue();

template <typename TypeInt>
class DomainMultiBitValue;
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

  template <typename TypeResult, int size>
  DomainMultiBitValue<TypeResult> castToMultiBit() const;

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
  template <typename SRC_VALUE_TYPE>
  friend class DomainMultiFloatValue;

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
          svalue() = (*functionTable().multibit_create_cast_multibit)(other.value(),8*sizeof(VALUE_TYPE), std::numeric_limits<VALUE_TYPE>::is_signed, env());
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
      if (inherited::isValid()) // [TODO] do not assume it is the first bit
        return DomainBitValue((*functionTable().multibit_create_cast_shift_bit)
            (value(), 0, env()), *this);
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
  typedef DomainMultiFloatValue<VALUE_TYPE> this_type;
  typedef DomainValue inherited;
  VALUE_TYPE vtConstant;
  template <typename SRC_VALUE_TYPE>
  friend class DomainMultiBitValue;
  template <typename SRC_VALUE_TYPE>
  friend class DomainMultiFloatValue;

public:
  DomainMultiFloatValue() : vtConstant(0.0) {}
  DomainMultiFloatValue(VALUE_TYPE val) : vtConstant(val) {}
  DomainMultiFloatValue(Empty empty, const DomainValue& ref)
    : DomainValue(empty, ref), vtConstant(0.0) {}
  DomainMultiFloatValue(DomainMultiFloatElement&& value, struct _DomainElementFunctions* functions, DomainEvaluationEnvironment* env)
    : DomainValue(std::move(value), functions, env), vtConstant(0.0) {}
  DomainMultiFloatValue(Processor& processor);

  DomainMultiFloatValue(DomainMultiFloatElement&& value, Processor& processor);
  DomainMultiFloatValue(DomainMultiFloatElement&& value, const DomainValue& source)
    : DomainValue(std::move(value), source) {}
  explicit DomainMultiFloatValue(DomainFloatingPointConstant value, Processor& processor)
    : DomainValue(processor)
    { svalue() = (*functionTable().multifloat_create_constant)(value); }
  DomainMultiFloatValue(DomainMultiFloatValue&& source) = default;
  DomainMultiFloatValue(const DomainMultiFloatValue& source) = default;
  DomainMultiFloatValue& operator=(DomainMultiFloatValue&& source) = default;
  DomainMultiFloatValue& operator=(const DomainMultiFloatValue& source) = default;

  template <class ResultType, int size>
  DomainMultiFloatValue<ResultType> castToMultiFloat() const
    {
      if (inherited::isValid())
        return DomainMultiFloatValue<ResultType>((*functionTable().multifloat_cast_multifloat)(value(), size, env()), *this);
      else
        return DomainMultiFloatValue<ResultType>((ResultType) vtConstant);
    }
  template <class ResultType, int size>
  DomainMultiBitValue<ResultType> castToMultiBit() const
    {
      if (inherited::isValid())
        return DomainMultiBitValue<ResultType>((*functionTable().multifloat_create_cast_multibit)(value(), size, env()), *this);
      else
        return DomainMultiBitValue<ResultType>((ResultType) vtConstant);
    }

  void setToConstant(VALUE_TYPE value)
    {
      if (inherited::hasFunctionTable())
        svalue() = (*functionTable().multifloat_create_constant)(
              DomainFloatingPointConstant{sizeof(value), value});
      else
        vtConstant = value;
    }
  void setToUndefined(int sizeInBits, bool isSymbolic)
    { svalue() = (*functionTable().multifloat_create_top)(sizeInBits, isSymbolic); }

  this_type applyUnary(DomainMultiFloatUnaryOperation operation,
      std::function<VALUE_TYPE(VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid())
        return DomainMultiFloatValue((*functionTable().multifloat_create_unary_apply)
            (value(), operation, env()), *this);
      else
        return DomainMultiFloatValue(constantFunction(vtConstant));
    }
  this_type& applyUnaryAssign(DomainMultiFloatUnaryOperation operation,
      std::function<void(VALUE_TYPE&)> constantFunction)
    {
      if (inherited::isValid())
        (*functionTable().multifloat_unary_apply_assign)
            (&svalue(), operation, env());
      else
        constantFunction(vtConstant);
      return *this;
    }
  this_type applyBinary(DomainMultiFloatBinaryOperation operation,
      const DomainMultiFloatValue& source,
      std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return this_type((*functionTable().multifloat_create_binary_apply)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        this_type alt(Empty(), *this);
        alt.setToConstant(source.vtConstant);
        return applyBinary(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(vtConstant);
        alt.applyBinaryAssign(operation, source, constantFunction);
        return std::move(alt);
      }
      else
        return this_type(constantFunction(vtConstant, source.vtConstant));
    }
  DomainBitValue applyCompare(DomainMultiFloatCompareOperation operation,
      const this_type& source,
      std::function<bool(VALUE_TYPE, VALUE_TYPE)> constantFunction) const
    {
      if (inherited::isValid() && source.inherited::isValid())
        return DomainBitValue((*functionTable().multifloat_binary_compare_domain)
            (value(), operation, source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        this_type alt(Empty(), *this);
        alt.setToConstant(source.vtConstant);
        return applyCompare(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(vtConstant);
        return alt.applyCompare(operation, source, constantFunction);
      }
      else
        return DomainBitValue(constantFunction(vtConstant, source.vtConstant));
    }
  this_type& applyBinaryAssign(DomainMultiFloatBinaryOperation operation,
      const DomainMultiFloatValue& source,
      std::function<VALUE_TYPE(VALUE_TYPE, VALUE_TYPE)> constantFunction)
    {
      if (inherited::isValid() && source.inherited::isValid())
        (*functionTable().multifloat_binary_apply_assign)
            (&svalue(), operation, source.value(), env());
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        DomainMultiFloatValue alt(Empty(), *this);
        alt.setToConstant(source.vtConstant);
        applyBinaryAssign(operation, alt, constantFunction);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        VALUE_TYPE thisConstant = vtConstant;
        operator=(this_type(Empty(), source));
        setToConstant(thisConstant);
        applyBinaryAssign(operation, source, constantFunction);
      }
      else
        vtConstant = constantFunction(vtConstant, source.vtConstant);
      return *this;
    }

  DomainMultiFloatValue operator-() const
    { return applyUnary(DMFUOOpposite, [](VALUE_TYPE val) { return -val; }); }
  DomainMultiFloatValue operator+(const DomainMultiFloatValue& source) const
    { return applyBinary(DMFBOPlus, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst + snd; });
    }
  DomainMultiFloatValue operator-(const DomainMultiFloatValue& source) const
    { return applyBinary(DMFBOMinus, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst - snd; });
    }
  DomainMultiFloatValue operator*(const DomainMultiFloatValue& source) const
    { return applyBinary(DMFBOTimes, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst * snd; });
    }
  DomainMultiFloatValue operator/(const DomainMultiFloatValue& source) const
    { return applyBinary(DMFBODivide, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst / snd; });
    }

  DomainMultiFloatValue& operator+=(const DomainMultiFloatValue& source)
    { return applyBinaryAssign(DMFBOPlus, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst + snd; });
    }
  DomainMultiFloatValue& operator-=(const DomainMultiFloatValue& source)
    { return applyBinaryAssign(DMFBOMinus, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst - snd; });
    }
  DomainMultiFloatValue& operator*=(const DomainMultiFloatValue& source)
    { return applyBinaryAssign(DMFBOTimes, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst * snd; });
    }
  DomainMultiFloatValue& operator/=(const DomainMultiFloatValue& source)
    { return applyBinaryAssign(DMFBODivide, source,
          [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst / snd; });
    }

  DomainMultiBitValue<int32_t> compare(const DomainMultiFloatValue& source) const
    {
      if (inherited::isValid() && source.inherited::isValid())
       return DomainMultiBitValue<int32_t>((*functionTable().multifloat_binary_full_compare_domain)
          (value(), source.value(), env()), *this);
      else if (inherited::isValid()) // !source.inherited::isValid()
      {
        this_type alt(Empty(), *this);
        alt.setToConstant(source.vtConstant);
        return compare(alt);
      }
      else if (source.inherited::isValid()) // !inherited::isValid()
      {
        this_type alt(Empty(), source);
        alt.setToConstant(vtConstant);
        return alt.compare(source);
      }
      else
        return DomainMultiBitValue<int32_t>((vtConstant < source.vtConstant)
            ? -1 : ((vtConstant > source.vtConstant) ? +1 : 0)); // also NaN
    }
  DomainBitValue operator==(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareEqual, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst == snd; });
    }
  DomainBitValue operator!=(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareDifferent, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst != snd; });
    }
  DomainBitValue operator<=(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareLessOrEqual, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst <= snd; });
    }
  DomainBitValue operator>=(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareGreaterOrEqual, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst >= snd; });
    }
  DomainBitValue operator<(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareLess, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst < snd; });
    }
  DomainBitValue operator>(const DomainMultiFloatValue& source) const
    { return applyCompare(DMFCOCompareGreater, source,
        [](VALUE_TYPE fst, VALUE_TYPE snd) { return fst > snd; });
    }

  bool isConstant(VALUE_TYPE* value) const
    {
      if (inherited::isValid()) {
        DomainFloatingPointConstant res;
        res.sizeInBits = sizeof(VALUE_TYPE);
        bool result = (*functionTable().multifloat_is_constant_value)(this->value(), &res);
        if (result && value)
           *value = (VALUE_TYPE) res.floatValue;
        return result;
      }
      else
      {
        if (value)
          *value = vtConstant;
        return true;
      }
    }

  void setToNaN()
    { (*functionTable().multifloat_unary_apply_assign)(&svalue(), DMFUOSetToNaN, env()); }
  void setQuietBit()
    { (*functionTable().multifloat_unary_apply_assign)(&svalue(), DMFUOSetQuietBit, env()); }
  DomainBitValue setFlushToZero()
    { return DomainBitValue((*functionTable().multifloat_flush_to_zero)(&svalue(), env()), *this); }
  DomainBitValue queryIsSNaN() const
    { DomainMultiBitValue<char> res((*functionTable().multifloat_query_to_multibit)(value(),
             DMFIOIsSNaN, env()), *this);
      return DomainBitValue(res);
    }
  DomainBitValue queryIsQNaN() const
    { DomainMultiBitValue<char> res((*functionTable().multifloat_query_to_multibit)(value(),
             DMFIOIsQNaN, env()), *this);
      return DomainBitValue(res);
    }

  // used with arguments coming from Processor
  void multAssignAndAdd(const this_type& op1, const this_type& op2)
    {  (*functionTable().multifloat_ternary_apply_assign)
          (&svalue(), DMFTOMultAdd, op1.value(), op2.value(), env());
    }
  // used with arguments coming from Processor
  DomainBitValue queryIsInvalidMulAddNode(const this_type& op1, const this_type& op2) const
    {  return DomainBitValue((*functionTable().multifloat_ternary_query)
          (value(), DMFTQIsInvalid, op1.value(), op2.value(), env()), *this);
    }
  void negateAssign()
    { applyUnary(DMFUOOpposite, [](VALUE_TYPE val) { return -val; }); }
  void absAssign()
    { applyUnary(DMFUOAbs, [](VALUE_TYPE val) { return std::abs(val); }); }
  void sqrtAssign()
    { applyUnary(DMFUOSqrt, [](VALUE_TYPE val) { return std::sqrt(val); }); }
};

class MemoryStateOwner;
class MemoryState {
  private:
   MemoryModel* pmModel;
   struct _MemoryModelFunctions* pfFunctions;
   InterpretParameters* pParameters;
   DomainEvaluationEnvironment* peDomainEnv;
   mutable unsigned uErrors; /* set of MemoryEvaluationErrorFlags */
   friend class MemoryStateOwner;

  public:
   MemoryState()
      :  pmModel(nullptr), pfFunctions(nullptr), pParameters(nullptr),
         peDomainEnv(nullptr), uErrors(0U) {}
   MemoryState(MemoryModel* model, struct _MemoryModelFunctions* functions,
         InterpretParameters* parameters)
      :  pmModel(model), pfFunctions(functions), pParameters(parameters),
         peDomainEnv(nullptr), uErrors(0U) {}
   MemoryState(Processor& proc);
   void assign(const MemoryStateOwner& source);

   bool hasError() const { return uErrors; }
   const unsigned& errors() const { return uErrors; }
   void clearErrors() { uErrors = 0U; }
   void mergeWith(MemoryStateOwner& source);

   void setNumberOfRegisters(int number)
      {  (*pfFunctions->set_number_of_registers)(pmModel, number); }
   void setEvaluationEnvironment(DomainEvaluationEnvironment& domainEnvironment)
      {  peDomainEnv = &domainEnvironment; }
   template <typename TypeInt>
   void setRegisterValue(int registerIndex, DomainMultiBitValue<TypeInt>&& value, struct _DomainElementFunctions& functionTable)
      {  if (!((DomainValue&) value).isValid()) {
            TypeInt val;
            value.isConstant(&val);
            value = DomainMultiBitValue<TypeInt>((*functionTable.multibit_create_constant)(
                  DomainIntegerConstant{8*sizeof(TypeInt),
                  std::numeric_limits<TypeInt>::is_signed, (uint64_t) val}),
                  &functionTable, peDomainEnv);
         }
         (*pfFunctions->set_register_value)(pmModel, registerIndex,
            &value.svalue(), pParameters, &uErrors);
         value.svalue() = DomainElement{};
      }

   void initializeMipsMemory(struct _DomainElementFunctions& functions)
      {  
        auto bg = DomainMultiBitValue<uint32_t>(0x13 /* SUPERVISOR_MODE */ | ((0x60 >> 6) << 10) | ((0x60 & 0x3) << 25) );
        setRegisterValue(CPSR_ID, std::move(bg), functions);
      }

   DomainElement getRegisterValueAsElement(int registerIndex) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr;
         return (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
      }
   DomainBitValue getRegisterValueAsBit(int registerIndex) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         DomainMultiBitValue<char> res(std::move(result), domainFunctions, peDomainEnv); 
         return DomainBitValue(std::move(res));
      }
   template <typename TypeInt>
   DomainMultiBitValue<TypeInt> getRegisterValueAsMultiBit(int registerIndex) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->get_register_value)
               (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
         return DomainMultiBitValue<TypeInt>(std::move(result), domainFunctions, peDomainEnv);
      }
   // DomainMultiFloatValue getRegisterValueAsMultiFloat(int registerIndex) const
   //    {  struct _DomainElementFunctions* domainFunctions = nullptr; 
   //       DomainElement result = (*pfFunctions->get_register_value)
   //             (pmModel, registerIndex, pParameters, &uErrors, &domainFunctions);
   //       return DomainMultiFloatValue(std::move(result), domainFunctions, peDomainEnv);
   //    }

   template <class IntType>
   DomainMultiBitValue<IntType> loadMultiBitValue(
         const DomainMultiBitValue<uint32_t>& indirectAddress) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_value)
               (pmModel, indirectAddress.value(), sizeof(IntType), pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue<IntType>(std::move(result), domainFunctions, peDomainEnv);
      }
   template <class IntType>
   DomainMultiBitValue<IntType> loadMultiBitDisjunctionValue(
         DomainMultiBitValue<uint32_t>&& indirectAddress) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr; 
         DomainElement result = (*pfFunctions->load_multibit_disjunctive_value)
               (pmModel, indirectAddress.value(), sizeof(IntType), pParameters, &uErrors,
                &domainFunctions);
         return DomainMultiBitValue<IntType>(std::move(result), domainFunctions, peDomainEnv);
      }
   template <class FloatType>
   DomainMultiFloatValue<FloatType> loadMultiFloatValue(
         DomainMultiBitValue<uint32_t>&& indirectAddress) const
      {  struct _DomainElementFunctions* domainFunctions = nullptr; 
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

class MemoryStateOwner {
  private:
   MemoryModel* pmModel;
   struct _MemoryModelFunctions* pfFunctions;
   friend class MemoryState;

  public:
   MemoryStateOwner(const MemoryState& source)
      :  pmModel(nullptr), pfFunctions(source.pfFunctions)
      {  if (source.pmModel)
            pmModel = (*pfFunctions->clone)(source.pmModel);
      }
   ~MemoryStateOwner()
      {  if (pmModel) {
            (*pfFunctions->free)(pmModel);
            pmModel = nullptr;
         }
      }
   void swap(MemoryState& source)
      {  if (pmModel && source.pmModel)
            (*pfFunctions->swap)(pmModel, source.pmModel);
      }
   void mergeWith(MemoryState& source)
      {  if (pmModel && source.pmModel)
            (*pfFunctions->merge)(pmModel, source.pmModel);
      }
};

inline void
MemoryState::assign(const MemoryStateOwner& source) {
   if (pmModel && source.pmModel)
      (*pfFunctions->assign)(pmModel, source.pmModel);
}

inline void
MemoryState::mergeWith(MemoryStateOwner& source) {
   if (pmModel && source.pmModel)
      (*pfFunctions->merge)(pmModel, source.pmModel);
}

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

  enum branch_type_t { B_JMP = 0, B_CALL, B_RET, B_EXC, B_DBG, B_RFE };
  
  struct RegID : public unisim::util::identifier::Identifier<RegID>
  {
    enum Code
      {
       NA = 0, at, v0, v1, a0, a1, a2, a3,
       t0, t1, t2, t3, t4, t5, t6, t7,
       s0, s1, s2, s3, s4, s5, s6, s7,
       t8, t9, k0, k1, gp, sp, fp, ra,
       npc, hi, lo,
       end
      } code;

    char const* c_str() const
    {
      switch (code)
        {
        case at:  return "at";
        case v0:  return "v0";
        case v1:  return "v1";
        case a0:  return "a0";
        case a1:  return "a1";
        case a2:  return "a2";
        case a3:  return "a3";
        case t0:  return "t0";
        case t1:  return "t1";
        case t2:  return "t2";
        case t3:  return "t3";
        case t4:  return "t4";
        case t5:  return "t5";
        case t6:  return "t6";
        case t7:  return "t7";
        case s0:  return "s0";
        case s1:  return "s1";
        case s2:  return "s2";
        case s3:  return "s3";
        case s4:  return "s4";
        case s5:  return "s5";
        case s6:  return "s6";
        case s7:  return "s7";
        case t8:  return "t8";
        case t9:  return "t9";
        case k0:  return "k0";
        case k1:  return "k1";
        case gp:  return "gp";
        case sp:  return "sp";
        case fp:  return "fp";
        case ra:  return "ra";
        case npc: return "npc";
        case lo:  return "lo";
        case hi:  return "hi";
        case NA:
        case end: break;
        }
      return "NA";
    }
      
    RegID() : code(end) {}
    RegID( Code _code ) : code(_code) {}
    RegID( char const* _code ) : code(end) { init( _code ); }
  };

  bool IsBigEndian() const { return false; }

private:
  Processor( Processor const& );

public:
  DomainEvaluationEnvironment    domainEnvironment;
  struct _DomainElementFunctions domainFunctions;
  InterpretParameters*           interpretParameters;
  MemoryState*                   memoryState;
  std::unique_ptr<MemoryStateOwner>   mergedMemoryState;
  std::unique_ptr<MemoryStateOwner>   sourceMemoryState;
  struct _MemoryModelFunctions   memoryFunctions;

  
  enum RegisterLimits
    {
     RLStart=0,
     RLGeneralPurpose=15,
     RLStartSpecial=RLGeneralPurpose,
     RLSpecial=RLGeneralPurpose+RegID::end,
     RLStartNeonRegs=RLSpecial,
     RLNeonRegs=RLSpecial+32,
     RLStartForeign=RLNeonRegs,
     RLEnd = RLNeonRegs
    };
  Processor()
    :  domainEnvironment(), domainFunctions{}, interpretParameters(nullptr),
       memoryState(nullptr), memoryFunctions(), next_targets_queries{}, target_addresses{}
  {}

  void setMemoryFunctions(struct _MemoryModelFunctions& functions) { memoryFunctions = functions; }
  void setDomainFunctions(struct _DomainElementFunctions& functions) { domainFunctions = functions; }
  void setVerbose() { is_verbose = true; }
  struct _DomainElementFunctions& getDomainFunctions() { return domainFunctions; }
  void setInterpretParameters(InterpretParameters& params) { interpretParameters = &params; }
  void setMemoryState(MemoryState& memory)
  {  memoryState = &memory;
    // [TODO] manage ForeignRegisters
    memory.setNumberOfRegisters(RLEnd);
    memory.setEvaluationEnvironment(domainEnvironment);
  }
  
  bool close()
  { bool result = path.close();
    doesFollow = !result;
    bool doesAcceptResult = true;
    if (!next_targets_queries) {
      if (decisionVector && decisionVector->isOnLast())
        doesAcceptResult = decisionVector->acceptTarget(current_target);
    }
    else
      has_set_target = false;
    if (result) {
      if (mergedMemoryState.get()) {
        if (doesAcceptResult)
          memoryState->mergeWith(*mergedMemoryState);
        else
          mergedMemoryState->swap(*memoryState);
        mergedMemoryState.reset();
      }
      else
        assert(doesAcceptResult);
      if (decisionVector && !next_targets_queries)
        decisionVector->advance();
    }
    else {
      if (doesAcceptResult) {
        if (mergedMemoryState.get())
          mergedMemoryState->mergeWith(*memoryState);
        else
          mergedMemoryState.reset(new MemoryStateOwner(*memoryState));
      };
      assert(sourceMemoryState.get()); // interpret follow same path than next_targets
      memoryState->assign(*sourceMemoryState);
    };
    return result;
  }

  //   =====================================================================
  //   =                 Internal Instruction Control Flow                 =
  //   =====================================================================
  
  bool Test( DomainBitValue const& cond, bool* multipleTarget=nullptr )
  {
    bool result;
    if (cond.isConstant(&result))
      return result;
    if (multipleTarget) {
      result = *multipleTarget;
      *multipleTarget = true;
      return result;
    }

    if (doesFollow) {
      doesFollow = (path.currentStackPosition() < (int) path.log_base_2() - 1);
      if (doesFollow) {
        result = !path.cbitArray(path.currentStackPosition());
        if (result) {
          path.lastIncBit() = path.currentStackPosition();
          path.lastZeroBit() = path.currentStackPosition()+1;
        }
      }
      else {
        assert(path.cbitArray(path.currentStackPosition()));
        path.lastLogCases() = 1;
        path.lastResult() = 0; /* false */
        // path.setFalseBitArray(path.currentStackPosition());
        result = false;
      };
    }
    else {
      path.lastLogCases() = 1;
      path.lastResult() = 1; /* true */
      path.lastIncBit() = path.currentStackPosition();
      path.lastZeroBit() = path.currentStackPosition()+1;
      // path.setTrueBitArray(path.currentStackPosition());
      result = true;
    };
    ++path.currentStackPosition();
    return result;
  }
  
  //   =====================================================================
  //   =             General Purpose Registers access methods              =
  //   =====================================================================
    
  void addJumpTargetAddress(uint32_t val)
  {  if (has_set_target) {
      --target_addresses.addresses_length;
      if (decisionVector)
        decisionVector->resetLastTarget(val);
    }
    else {
      if (target_addresses.addresses_length >= target_addresses.addresses_array_size) {
        int old_size = target_addresses.addresses_array_size;
        target_addresses.addresses = (*target_addresses.realloc_addresses)(
                                                                           target_addresses.addresses, old_size,
                                                                           &target_addresses.addresses_array_size,
                                                                           target_addresses.address_container);
      };
      if (decisionVector)
        decisionVector->addNewTarget(val);
    }
    target_addresses.addresses[target_addresses.addresses_length] = val;
    ++target_addresses.addresses_length;
    has_set_target = true;
  }
  void addCallTargetAddress(uint32_t val)
  {  addJumpTargetAddress(val); }
  void addReturnTargetAddress(uint32_t val)
  {  addJumpTargetAddress(val); }

  struct RegisterAccess {
    RegisterAccess(int registerIndex, Processor& aproc) : proc(&aproc) {}
    RegisterAccess(uint32_t aval) : val(aval), proc(nullptr) {}
    RegisterAccess(const U32& aval) : val(aval), proc(nullptr) {}
    RegisterAccess(const RegisterAccess& source) = default;
    RegisterAccess& operator=(const RegisterAccess& source) = default;

    RegisterAccess& operator=(const U32& source)
    {  if (proc)
        proc->memoryState->setRegisterValue(RegID("fpscr").code, U32(source),
                                            proc->domainFunctions);
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

  
  //   =====================================================================
  //   =                       Memory access methods                       =
  //   =====================================================================
  
  //   =====================================================================
  //   =                         Processor Storage                         =
  //   =====================================================================
  
  PathExplorer     path;
  bool             doesFollow = false;
  bool             is_it_assigned; /* determines wether current instruction is an IT one. */
  bool             unpredictable;
  bool             next_targets_queries;
  bool             has_set_target = false;
  TargetAddresses  target_addresses;
  DecisionVector*  decisionVector = nullptr;
  bool             is_verbose = false;
  uint64_t         current_target = 0;
  U32              insn_addrs[3];
  branch_type_t    branch_type = B_JMP;

  void execute(unisim::component::cxx::processor::mips::isa::Operation<Processor>* insn)
  {
    // Fetch
    uint32_t insn_addr = insn->GetAddr();
    insn_addrs[0] = U32(insn_addr);
    insn_addrs[1] = GetU32("npc"); /*delay slot*/
    insn_addrs[2] = insn_addrs[1] + U32(4);
    insn->execute( *this );
  }

  struct TODO {};

  void SetU32( RegID id, U32 const& value )
  {
    assert(memoryState);
    memoryState->setRegisterValue(id.code + 0/*offset to RegID*/, U32(value), domainFunctions);
  }
  U32  GetU32( RegID id )
  {
    assert(memoryState);
    return U32(memoryState->getRegisterValueAsElement(id.code + 0/* offset to RegID*/), *this);
  }
  
  void SetGPR( unsigned idx, const U32& value ) { if (idx) SetU32(RegID("at") + (idx-1), value); }
  void SetDivU(U32 rs, U32 rt) { SetLO(0, rs / rt); SetHI(0, rs % rt); }
  void SetHI(unsigned ra, U32 value) { if (ra) throw "nope"; SetU32("hi", value); }
  void SetLO(unsigned ra, U32 value) { if (ra) throw "nope"; SetU32("lo", value); }
  
  U32  GetGPR( unsigned idx ) { if (idx) return GetU32(RegID("at") + (idx-1)); return U32(0); }
  U32  GetHI(unsigned ra) { if (ra) throw "nope"; return GetU32("hi"); }
  U32  GetLO(unsigned ra) { if (ra) throw "nope"; return GetU32("lo"); }

  U32  GetHWR(unsigned idx) { throw Unimplemented(); return U32(); }
  
  //   =====================================================================
  //   =                      Control Transfer methods                     =
  //   =====================================================================

  U32  GetPC() { return insn_addrs[0]; }
  void process_branches()
  {
    // Principle is to look at insn_addrs[2] to tell where instruction
    // did branched.  Beware that if delay slot is canceled,
    // insn_addrs[1] will no longer contains initial delay slot but
    // insn_addrs[2].  May be should use a special state for that
    // (some kind of is_delay_slot_canceled_p boolean status).

    U32 const& nia = insn_addrs[2];
    
    if (next_targets_queries) {
      uint32_t val;
      if (nia.isConstant(&val)) {
        if (branch_type == B_CALL)
          addCallTargetAddress(val);
        else if (branch_type == B_RET)
          addReturnTargetAddress(val);
        else
          addJumpTargetAddress(val);
      }
      else {
        // [TODO] forcer les disjonctions + énumérer
        // pour les dynamic jumps
      }
      current_target = val;
    }
    else if (decisionVector) {
      uint32_t val;
      if (nia.isConstant(&val))
        current_target = val;
    }
  }

  void Branch( U32 const& target, branch_type_t _branch_type ) { insn_addrs[2] = target; branch_type = _branch_type; }
  void CancelDelaySlot() { insn_addrs[1] = insn_addrs[2]; insn_addrs[2] += U32(4); }
    
  void SysCall( unsigned imm ) { throw Unimplemented(); }
  
  //   =====================================================================
  //   =                       Memory access methods                       =
  //   =====================================================================
  U32 MemLoad( U32 const&, U32 const& addr ) { throw TODO(); return U32(); }
  U16 MemLoad( U16 const&, U32 const& addr ) { throw TODO(); return U16(); }
  U8  MemLoad( U8  const&, U32 const& addr ) { throw TODO(); return  U8(); }
  S32 MemLoad( S32 const&, U32 const& addr ) { throw TODO(); return S32(); }
  S16 MemLoad( S16 const&, U32 const& addr ) { throw TODO(); return S16(); }
  S8  MemLoad( S8  const&, U32 const& addr ) { throw TODO(); return  S8(); }
  template <class T> T MemRead( U32 const& addr ) { return MemLoad( T(), addr ); }
  
  void MemStore( U32 const& addr, U32 const& value ) { throw TODO(); }
  void MemStore( U32 const& addr, U16 const& value ) { throw TODO(); }
  void MemStore( U32 const& addr, U8  const& value ) { throw TODO(); }
  template <typename U> void MemWrite( U32 const& addr, U value ) { return MemStore( addr, value ); }
    
  void AtomicBegin(U32 const&) { }
  BOOL AtomicUpdate(U32 const&) { return BOOL(true); }
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

template <class ResultType, int size>
inline DomainMultiBitValue<ResultType>
DomainBitValue::castToMultiBit() const {
   if (DomainValue::isValid())
      return DomainMultiBitValue<char>((*functionTable().bit_create_cast_multibit)
            (value(), size, env()), *this);
   else
      return DomainMultiBitValue<char>(fConstant);
}

struct MIPSISA : public unisim::component::cxx::processor::mips::isa::Decoder<Processor>
{
  typedef unisim::component::cxx::processor::mips::isa::CodeType CodeType;
  typedef unisim::component::cxx::processor::mips::isa::Operation<Processor> Operation;
  static CodeType mkcode( uint32_t code ) { return CodeType( code ); }
};

struct Translator
{
  Translator( uint32_t _addr, uint32_t _code )
    : addr(_addr), code(_code) {}
  
  template <class ISA>
  void
  extract( ISA& isa , Processor& state)
  {
    // Instruction decoding
    struct Instruction
    {
      typedef typename ISA::Operation Operation;
      Instruction(ISA& isa, uint32_t addr, uint32_t code)
        : operation(0)
      {
        operation = isa.NCDecode( addr, ISA::mkcode( code ) );
        unsigned bitlength = operation->GetLength(); 
        if (bitlength != 32) { delete operation; operation = 0; }
      }
      ~Instruction() { delete operation; }
      Operation* operator -> () { return operation; }
      Operation* get() { return operation; }
      
      Operation* operation;
    };
    
    Instruction instruction( isa, addr, code );
    
    // Get actions
    if (state.is_verbose) {
      std::cout << "\texecute instruction 0x" << std::hex << instruction->GetAddr() << std::dec << ':';
      instruction->disasm(std::cout);
      std::cout << '\n';
    };
    uint32_t next_addr = addr;
    if (!state.next_targets_queries && state.decisionVector) {
       if (!state.decisionVector->isOnLast())
          next_addr += 4;
       else
          next_addr = state.decisionVector->getLastTarget();
    }

    for (bool end = false; not end;)
      {
        state.execute(instruction.get());
        // state.process_branches();
        // Either process branches here or in close() which is called next.
        end = state.close();
      }
    if (!state.next_targets_queries)
       addr = next_addr;
    if (state.unpredictable) {
      if (state.is_verbose)
        std::cout << "\t\twarning: unpredicable instruction\n";
      state.unpredictable = false;
    }
  }

  void next_targets(Processor& proc, TargetAddresses& targets, DecisionVector& decisionVector)
  {
    try
      {
        MIPSISA mipsisa;
        proc.next_targets_queries = true;
        proc.target_addresses = targets;
        proc.decisionVector = &decisionVector;
        proc.sourceMemoryState.reset(new MemoryStateOwner(*proc.memoryState));
        extract( mipsisa, proc );
        targets = proc.target_addresses;
        proc.next_targets_queries = false;
        // remove duplicates
        for (int i = 0; i < targets.addresses_length-1; ++i) {
          for (int j = i+1; j < targets.addresses_length; ++j) {
            if (targets.addresses[i] == targets.addresses[j]) {
              if (j < targets.addresses_length-1)
                memmove(&targets.addresses[j], &targets.addresses[j+1],
                        sizeof(uint64_t)*(targets.addresses_length-j-1));
              --j;
              --targets.addresses_length;
            }
          }
        };
        proc.target_addresses = { nullptr, 0, 0, nullptr, nullptr};
        proc.decisionVector = nullptr;
        proc.sourceMemoryState.reset();
      }
    catch (Processor::Undefined const&)
      {
        throw;
      }
    catch (...)
      {
        throw;
      }
  }
  void interpret(Processor& proc, DecisionVector& decisionVector)
  {
    try
      {
        MIPSISA mipsisa;
        proc.decisionVector = &decisionVector;
        if (decisionVector.doesNeedSeveralExecution())
          proc.sourceMemoryState.reset(new MemoryStateOwner(*proc.memoryState));
        extract( mipsisa, proc );
        proc.sourceMemoryState.reset();
        proc.decisionVector = nullptr;
      }
    catch (Processor::Undefined const&)
      {
        throw;
      }
    catch (...)
      {
        throw;
      }
  }

  uint32_t    addr, code;
};
  
extern "C" {

struct _Processor* mips_create_processor()
{  debugPrint((DomainValue*) nullptr);
   return reinterpret_cast<struct _Processor*>(new Processor());
}

void mips_set_domain_functions(struct _Processor* aprocessor, struct _DomainElementFunctions* functionTable)
{  auto* processor = reinterpret_cast<Processor*>(aprocessor);
   processor->setDomainFunctions(*functionTable);
}

struct _DomainElementFunctions* mips_get_domain_functions(
      struct _Processor* aprocessor)
{  auto* processor = reinterpret_cast<Processor*>(aprocessor);
   return &processor->getDomainFunctions();
}

void mips_initialize_memory(struct _Processor* aprocessor, MemoryModel* memory,
      MemoryModelFunctions* memory_functions, InterpretParameters* parameters)
{  auto* processor = reinterpret_cast<Processor*>(aprocessor);
   MemoryState memoryState(memory, memory_functions, parameters);
   memoryState.initializeMipsMemory(processor->getDomainFunctions());
}

void mips_set_verbose(struct _Processor* processor)
{  if (processor) reinterpret_cast<Processor*>(processor)->setVerbose(); }

void mips_free_processor(struct _Processor* processor)
{  delete reinterpret_cast<Processor*>(processor); }

int mips_get_registers_number(struct _Processor* processor)
{  return Processor::RLEnd; }

int mips_get_register_index(struct _Processor* processor,
      const char* name)
{  int code = Processor::RegID(name).code;
   if (code == Processor::RegID::end) // {
      // code = Processor::SRegID(name).code;
      // if (code == Processor::SRegID::end)
         return -1;
   //    return Processor::RegID::end + code;
   // }
   return code;
}
  
const char* mips_get_register_name(struct _Processor* processor,
      int register_index)
{  if (register_index < 0)
      return nullptr;
   // if (register_index >= Processor::RegID::end)
   //    return Processor::SRegID((Processor::SRegID::Code)
   //          (register_index-Processor::RegID::end)).c_str();
   return Processor::RegID((Processor::RegID::Code) register_index).c_str();
}
  
struct _DecisionVector* mips_create_decision_vector(struct _Processor* processor)
{  return reinterpret_cast<struct _DecisionVector*>(new DecisionVector()); }

struct _DecisionVector* mips_clone_decision_vector(struct _DecisionVector* decision_vector)
{  return reinterpret_cast<struct _DecisionVector*>(new DecisionVector(
         *reinterpret_cast<DecisionVector*>(decision_vector)));
}

void mips_free_decision_vector(struct _DecisionVector* decision_vector)
{  delete reinterpret_cast<DecisionVector*>(decision_vector); }

void mips_filter_decision_vector(struct _DecisionVector* decision_vector,
      uint64_t target)
{  auto* decisionVector = reinterpret_cast<DecisionVector*>(decision_vector);
   decisionVector->setToLastInstruction();
   decisionVector->filter(target);
}

bool mips_next_targets(struct _Processor* processor, char* instruction_buffer,
      size_t buffer_size, uint64_t address, TargetAddresses* target_addresses,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      struct _DecisionVector* decision_vector, InterpretParameters* parameters) {
  Processor* proc = reinterpret_cast<Processor*>(processor);
  proc->setMemoryFunctions(*memory_functions);
  MemoryState memoryState(memory, memory_functions, parameters);
  proc->setMemoryState(memoryState);
  proc->setInterpretParameters(*parameters);

  uint32_t code;
  memcpy(&code, instruction_buffer, sizeof(code));
  unisim::util::endian::ByteSwap(code);

  Translator actset( address, code );
  DecisionVector* decisionVector = reinterpret_cast<DecisionVector*>(decision_vector);
  decisionVector->setToNextInstruction();
  actset.next_targets(*proc, *target_addresses, *decisionVector);
  return true;
}

bool mips_interpret(struct _Processor* processor, char* instruction_buffer,
      size_t buffer_size, uint64_t* address, uint64_t target_address,
      MemoryModel* memory, MemoryModelFunctions* memory_functions,
      struct _DecisionVector* decision_vector, InterpretParameters* parameters) {
  Processor* proc = reinterpret_cast<Processor*>(processor);
  proc->setMemoryFunctions(*memory_functions);
  MemoryState memoryState(memory, memory_functions, parameters);
  proc->setMemoryState(memoryState);
  proc->setInterpretParameters(*parameters);

  uint32_t code;
  memcpy(&code, instruction_buffer, sizeof(code));
  unisim::util::endian::ByteSwap(code);

  Translator actset( *address, code );
  DecisionVector* decisionVector = reinterpret_cast<DecisionVector*>(decision_vector);
  actset.interpret(*proc, *decisionVector);
  *address = actset.addr;
  return decisionVector->isEmpty();
}

  DLL_API uint64_t init_processor_functions(struct _ProcessorFunctions* functions)
  {
    functions->create_processor = &mips_create_processor;
    functions->set_domain_functions = &mips_set_domain_functions;
    functions->get_domain_functions = &mips_get_domain_functions;
    functions->initialize_memory = &mips_initialize_memory;
    functions->set_verbose = &mips_set_verbose;
    functions->free_processor = &mips_free_processor;
    functions->get_registers_number = &mips_get_registers_number;
    functions->get_register_index = &mips_get_register_index;
    functions->get_register_name = &mips_get_register_name;
    functions->create_decision_vector = &mips_create_decision_vector;
    functions->clone_decision_vector = &mips_clone_decision_vector;
    functions->free_decision_vector = &mips_free_decision_vector;
    functions->filter_decision_vector = &mips_filter_decision_vector;
    functions->processor_next_targets = &mips_next_targets;
    functions->processor_interpret = &mips_interpret;

    return 1;
  }
  
}
