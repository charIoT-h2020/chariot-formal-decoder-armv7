#include "./unisim/component/cxx/processor/mips/isa/mipsel.hh"
#line 63 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"

#include <unisim/component/cxx/processor/mips/isa/disasm.hh>
#include <iostream>
#line 7 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
namespace unisim { namespace component { namespace cxx { namespace processor { namespace mips { namespace isa {
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::Operation(CodeType _code, uint32_t _addr, const char *_name)
:
encoding(_code),
addr(_addr),
name(_name)
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 32 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 35 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 40 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::~Operation()
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 48 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 51 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 55 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 59 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 63 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 66 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		this->disasm(std::cerr << "0x" << std::hex << this->GetAddr() << ": ");
		std::cerr << std::endl;
		struct Unimplemented {};
		throw Unimplemented();
	}
#line 76 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 81 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 84 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 88 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 92 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 96 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 99 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "Unknown Mipsel instruction";
	}
#line 106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSync : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 119 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSync(CodeType code, uint32_t addr);
	uint8_t stype;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 128 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 135 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 144 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 147 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 155 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 158 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSll : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSll(CodeType code, uint32_t addr);
	uint8_t imm;
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 186 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC0(CodeType code, uint32_t addr);
	uint32_t imm;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 236 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC1(CodeType code, uint32_t addr);
	uint32_t imm;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlbr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlbr(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 299 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlbwi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlbwi(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 312 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 319 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 330 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlbwr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 335 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlbwr(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 350 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 361 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlbp : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlbp(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 374 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 389 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpEret : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpEret(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 420 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 423 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpWait : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 428 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpWait(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 436 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSync_p : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 459 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSync_p(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpPause : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpPause(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 505 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAdd_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAdd_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 536 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 550 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAdd_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 555 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAdd_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 570 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 573 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 581 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSub_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 589 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSub_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 600 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 615 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 618 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSub_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 623 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSub_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 638 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 649 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 652 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMul_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMul_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 686 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMul_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMul_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 702 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 706 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 709 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 720 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDiv_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDiv_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDiv_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDiv_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 770 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 785 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSqrt_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSqrt_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 803 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 810 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSqrt_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSqrt_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 836 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAbs_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAbs_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 869 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 873 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 876 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAbs_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAbs_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 902 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 906 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 920 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMov_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMov_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 935 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 939 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 942 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMov_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 958 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMov_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 972 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 986 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpNeg_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpNeg_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1008 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpNeg_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpNeg_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1034 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1049 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1052 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRound_l_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRound_l_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1074 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRound_l_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRound_l_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTrunc_l_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1123 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTrunc_l_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1148 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTrunc_l_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1156 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTrunc_l_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1184 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCeil_l_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCeil_l_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCeil_l_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCeil_l_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1236 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1239 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1247 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpFloor_l_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpFloor_l_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1280 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1283 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpFloor_l_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpFloor_l_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRound_w_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRound_w_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1335 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1338 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1349 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRound_w_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRound_w_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1368 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTrunc_w_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTrunc_w_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTrunc_w_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1420 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTrunc_w_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1430 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1434 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1448 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCeil_w_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCeil_w_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1478 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCeil_w_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1486 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCeil_w_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1500 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1503 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpFloor_w_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpFloor_w_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1533 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1536 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1544 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpFloor_w_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpFloor_w_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1562 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1569 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1577 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_d_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1585 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_d_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1599 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1602 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1610 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_s_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1618 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_s_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1635 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_w_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_w_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1661 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1676 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_w_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1684 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_w_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1698 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1709 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1712 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_l_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_l_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1727 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1734 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1742 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1745 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_l_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1750 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_l_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1760 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1778 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC_s(CodeType code, uint32_t addr);
	uint8_t cond;
	uint8_t cc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1802 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1810 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1813 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC_d(CodeType code, uint32_t addr);
	uint8_t cond;
	uint8_t cc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1830 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1834 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1848 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCabs_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCabs_s(CodeType code, uint32_t addr);
	uint8_t cond;
	uint8_t cc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1869 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1872 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1880 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1883 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCabs_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1888 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCabs_d(CodeType code, uint32_t addr);
	uint8_t cond;
	uint8_t cc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1900 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1918 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovf_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1923 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovf_s(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t cc;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1938 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1941 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1949 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovf_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovf_d(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t cc;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 1968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 1972 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 1975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 1983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1986 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovt_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 1991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovt_s(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t cc;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovt_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovt_d(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t cc;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2036 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2040 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovz_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovz_s(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2074 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2077 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2088 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovz_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovz_d(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2108 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2119 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovn_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2127 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovn_s(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2138 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2142 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2153 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2156 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovn_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2161 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovn_d(CodeType code, uint32_t addr);
	uint8_t fd;
	uint8_t fs;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2172 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2176 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2205 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2212 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2220 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2228 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2242 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2256 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip1_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2261 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip1_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2278 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip1_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2294 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip1_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2308 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2311 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2319 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2341 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2352 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2355 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2360 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2374 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2377 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2385 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2388 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt1_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt1_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2403 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2410 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2418 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt1_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2426 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt1_d(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2436 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip2_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2459 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip2_s(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2477 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRecip2_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRecip2_d(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2508 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt2_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2527 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt2_s(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2553 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRsqrt2_d : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2561 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRsqrt2_d(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2576 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCvt_ps_s : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCvt_ps_s(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2606 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2610 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2624 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovf : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovf(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t cc;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2640 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2655 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2658 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovt : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2663 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovt(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t cc;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2674 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2681 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2689 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2692 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovz : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2697 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovz(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2708 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2712 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2723 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2726 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMovn : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMovn(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2742 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2749 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2760 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLsa : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLsa(CodeType code, uint32_t addr);
	uint8_t i;
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2781 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2784 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2792 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRorv : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRorv(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2811 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2815 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRor : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2834 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRor(CodeType code, uint32_t addr);
	uint8_t sa;
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2852 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2860 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMflhxu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2868 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMflhxu(CodeType code, uint32_t addr);
	uint8_t rc;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtlhx : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2900 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtlhx(CodeType code, uint32_t addr);
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2916 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2924 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2927 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJr_hb : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJr_hb(CodeType code, uint32_t addr);
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2941 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2948 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJalr_hb : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2964 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJalr_hb(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 2974 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 2978 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 2981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 2989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMultp : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 2997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMultp(CodeType code, uint32_t addr);
	uint8_t rb;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3014 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3022 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAclr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3030 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAclr(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t imm;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3048 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAset : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAset(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t imm;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBposge32 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3098 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBposge32(CodeType code, uint32_t addr);
	int32_t offset;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpRdhwr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3130 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpRdhwr(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3144 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3147 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3152 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3156 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpClz : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpClz(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3186 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDi(CodeType code, uint32_t addr);
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3236 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpExt : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpExt(CodeType code, uint32_t addr);
	uint8_t lsb;
	uint8_t msbd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpIns : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3276 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpIns(CodeType code, uint32_t addr);
	uint8_t lsb;
	uint8_t msb;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3292 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3303 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3306 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMaddu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3311 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMaddu(CodeType code, uint32_t addr);
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3328 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMul : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMul(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3355 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSeb : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSeb(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3388 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3403 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3406 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSeh : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3411 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSeh(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3428 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3436 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3439 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJ : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJ(CodeType code, uint32_t addr);
	uint32_t target;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3469 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3472 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3480 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3483 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJal : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJal(CodeType code, uint32_t addr);
	uint32_t target;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3497 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3524 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3527 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpNop : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpNop(CodeType code, uint32_t addr);
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3540 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3544 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3570 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSrl : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSrl(CodeType code, uint32_t addr);
	uint8_t imm;
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3586 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3598 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3602 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3605 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3616 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSra : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSra(CodeType code, uint32_t addr);
	uint8_t imm;
	uint8_t rd;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3639 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3648 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3662 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSllv : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSllv(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3697 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3708 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSrlv : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3713 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSrlv(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSrav : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSrav(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3770 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3789 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJr(CodeType code, uint32_t addr);
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3830 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3841 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3844 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJalr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJalr(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3878 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3886 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSyscall : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3894 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSyscall(CodeType code, uint32_t addr);
	uint32_t imm;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3910 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3919 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 3922 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3930 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3933 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBreak : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3938 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBreak(CodeType code, uint32_t addr);
	uint16_t imm2;
	uint16_t imm1;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3948 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 3963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3966 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMfhi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 3971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMfhi(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 3985 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 3988 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 3993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 3997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4000 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4008 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMthi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMthi(CodeType code, uint32_t addr);
	uint8_t ra;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4026 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4030 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4033 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMflo : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4061 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMflo(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t ra;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4078 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4098 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtlo : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtlo(CodeType code, uint32_t addr);
	uint8_t ra;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4116 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4120 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4123 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4128 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4135 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMult : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMult(CodeType code, uint32_t addr);
	uint8_t ra;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4162 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4169 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMultu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4197 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMultu(CodeType code, uint32_t addr);
	uint8_t ra;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4208 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4212 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4220 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4224 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4227 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDiv : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDiv(CodeType code, uint32_t addr);
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDivu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4276 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDivu(CodeType code, uint32_t addr);
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAdd : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAdd(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4350 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAddu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4355 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAddu(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4385 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSub : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSub(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4427 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4430 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSubu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSubu(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4450 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4458 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4462 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4473 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4476 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAnd : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAnd(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4492 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4499 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4508 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpOr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4527 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpOr(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4550 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4554 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4568 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpXor : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4573 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpXor(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4588 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4591 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4600 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4603 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpNor : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4619 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpNor(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4630 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4642 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4649 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4660 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBltz : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBltz(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t l;
	uint8_t al;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4677 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4681 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4684 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4689 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4704 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBgez : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4712 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBgez(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t l;
	uint8_t al;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBlez : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBlez(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t rs;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4770 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4789 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBgtz : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBgtz(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t rs;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4816 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4820 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4823 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4828 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBeq : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBeq(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t rt;
	uint8_t rs;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4870 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBne : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4898 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBne(CodeType code, uint32_t addr);
	int32_t offset;
	uint8_t rt;
	uint8_t rs;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4910 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4922 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 4926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 4929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTge : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTge(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4960 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 4971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4974 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTgeu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 4979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTgeu(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 4990 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 4994 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 4997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5008 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlt : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlt(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTltu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5047 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTltu(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5058 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5062 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5073 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5076 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTeq : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5081 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTeq(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5092 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5099 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5110 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTne : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTne(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5130 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5141 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5144 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTgei : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5149 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTgei(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5177 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTgeiu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTgeiu(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5210 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTlti : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTlti(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5240 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTltiu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5248 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTltiu(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5258 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5262 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5276 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTeqi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTeqi(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5291 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5306 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpTnei : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpTnei(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5324 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5328 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5342 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAddi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAddi(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5365 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5376 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAddiu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAddiu(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5408 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5411 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5422 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSlt : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5427 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSlt(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5438 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5442 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5450 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5468 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSlti : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5473 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSlti(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5484 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5491 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5500 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5503 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSltu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSltu(CodeType code, uint32_t addr);
	uint8_t rd;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5549 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5560 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSltiu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSltiu(CodeType code, uint32_t addr);
	int16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5576 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5588 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5592 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5603 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5606 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpAndi : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpAndi(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5622 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5626 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5638 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5649 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5652 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpOri : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpOri(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5680 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5684 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5695 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5698 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpXori : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5703 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpXori(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5718 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5726 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5730 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5741 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5744 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLui : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5749 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLui(CodeType code, uint32_t addr);
	uint16_t imm;
	uint8_t rt;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5763 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5766 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5778 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5789 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLb : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5794 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLb(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5812 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5824 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLbu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLbu(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5855 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5858 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5870 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5878 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLh : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5886 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLh(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5897 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5916 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5924 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5927 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLhu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLhu(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5947 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 5959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 5962 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 5970 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5973 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLw : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 5978 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLw(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 5989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 5993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 5996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6008 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwu : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwu(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6047 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6062 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSb : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSb(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6081 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6088 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6097 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6108 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSh : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6116 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSh(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6127 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6131 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6134 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6139 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSw : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6162 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSw(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6177 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6180 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6185 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6200 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLl : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6208 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLl(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6219 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6226 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6231 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6249 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSc : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSc(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6277 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 6281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 6284 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6292 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMfc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6300 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMfc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6310 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6328 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmfc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmfc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6350 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6361 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCfc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCfc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6376 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6380 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6383 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6391 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6394 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6413 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6424 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6427 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmtc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmtc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6442 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6449 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCtc0 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCtc0(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc0f : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc0f(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6508 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6512 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6515 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6523 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6526 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc0t : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc0t(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6541 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6548 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMfc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6564 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMfc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6574 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6578 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6581 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6589 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6592 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmfc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmfc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6622 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCfc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6630 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCfc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6640 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6655 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6658 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6663 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6673 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6677 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6680 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6688 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmtc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmtc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6706 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6710 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6713 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCtc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCtc1(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6739 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc1f : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6762 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc1f(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6790 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc1t : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc1t(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6812 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6820 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6823 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6828 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC2(CodeType code, uint32_t addr);
	uint32_t imm;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6841 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6844 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6852 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6855 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMfc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6860 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMfc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6870 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6888 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmfc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmfc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6910 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6918 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCfc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCfc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6936 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6954 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 6969 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 6973 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 6976 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 6984 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmtc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 6992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmtc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCtc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCtc2(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7050 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc2f : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7058 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc2f(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7068 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7072 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7086 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc2t : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7091 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc2t(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7105 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7108 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7116 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7119 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpC3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7124 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpC3(CodeType code, uint32_t addr);
	uint32_t imm;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7148 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMfc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7156 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMfc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7184 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmfc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmfc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCfc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCfc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7236 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7239 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7247 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpMtc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpMtc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7280 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7283 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpDmtc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpDmtc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCtc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCtc3(CodeType code, uint32_t addr);
	uint8_t rc;
	uint8_t rb;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7335 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7338 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7349 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc3f : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc3f(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7368 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpBc3t : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpBc3t(CodeType code, uint32_t addr);
	uint16_t offset;
	uint8_t l;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpJalx : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7420 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpJalx(CodeType code, uint32_t addr);
	uint32_t target;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7436 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7447 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwl : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwl(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 7479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 7482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwr(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 7525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 7528 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7536 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSwl : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7544 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSwl(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7555 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7562 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 7571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 7574 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7585 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSwr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSwr(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7605 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7608 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
	virtual
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH&
#line 7617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	core
#line 7620 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7631 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSdl : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSdl(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7662 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSdr : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7670 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSdr(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7681 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7688 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7699 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpCache : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7704 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpCache(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7719 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7722 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7730 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7738 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwc1(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7749 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7753 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwc2(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7790 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7798 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLwc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7806 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLwc3(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7824 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLld : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLld(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7855 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7858 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7869 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLdc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLdc1(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7900 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLdc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7908 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLdc2(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7919 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7923 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpLdc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7942 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpLdc3(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7960 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 7968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSwc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 7976 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSwc1(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 7987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 7991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 7994 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSwc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8010 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSwc2(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8036 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSwc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8044 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSwc3(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8055 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8062 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8073 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpScd : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8078 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpScd(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8089 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSdc1 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8112 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSdc1(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8123 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8127 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8130 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8138 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8141 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSdc2 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSdc2(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8161 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8172 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
class OpSdc3 : public Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8180 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
{
public:
	OpSdc3(CodeType code, uint32_t addr);
	int16_t offset;
	uint8_t rt;
	uint8_t rs;
	virtual
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	void
#line 8191 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	std::ostream&
#line 8195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	sink
#line 8198 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) const;
private:
};

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8213 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSync<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8224 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 75 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sync"; if (stype) sink << '\t' << PrintHex(stype); }
#line 8229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8234 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSync<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 8249 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 8252 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 78 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		if (stype) throw "nope";
	}
#line 8259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSync(CodeType code, uint32_t addr)
{
	return new OpSync<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSll<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8297 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 113 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sll\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintHex(imm); }
#line 8309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSll<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 8329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 8332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 115 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rt) << imm); }
#line 8337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSll(CodeType code, uint32_t addr)
{
	return new OpSll<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 600 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "c" << unsigned(0) << "\t" << PrintHex(imm); }
#line 8387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC0(CodeType code, uint32_t addr)
{
	return new OpC0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 628 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "c" << unsigned(1) << "\t" << PrintHex(imm); }
#line 8437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC1(CodeType code, uint32_t addr)
{
	return new OpC1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlbr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 38 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "tlbr"; }
#line 8487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlbr(CodeType code, uint32_t addr)
{
	return new OpTlbr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlbwi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 41 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "tlbwi"; }
#line 8537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlbwi(CodeType code, uint32_t addr)
{
	return new OpTlbwi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8564 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlbwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 44 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "tlbwr"; }
#line 8587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlbwr(CodeType code, uint32_t addr)
{
	return new OpTlbwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlbp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 47 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "tlbp"; }
#line 8637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlbp(CodeType code, uint32_t addr)
{
	return new OpTlbp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpEret<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 50 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "eret"; }
#line 8687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpEret(CodeType code, uint32_t addr)
{
	return new OpEret<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpWait<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 53 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "wait"; }
#line 8737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpWait(CodeType code, uint32_t addr)
{
	return new OpWait<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSync_p<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 57 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "sync.p"; }
#line 8787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSync_p(CodeType code, uint32_t addr)
{
	return new OpSync_p<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpPause<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 60 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	{ sink << "pause"; }
#line 8837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpPause(CodeType code, uint32_t addr)
{
	return new OpPause<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAdd_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 37 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "add.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 8887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAdd_s(CodeType code, uint32_t addr)
{
	return new OpAdd_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAdd_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 40 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "add.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 8937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8946 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAdd_d(CodeType code, uint32_t addr)
{
	return new OpAdd_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 8957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8964 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 8971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSub_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 8979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 8982 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 43 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "sub.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 8987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 8993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 8996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSub_s(CodeType code, uint32_t addr)
{
	return new OpSub_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9014 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSub_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 46 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "sub.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 9037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSub_d(CodeType code, uint32_t addr)
{
	return new OpSub_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMul_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 49 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "mul.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 9087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMul_s(CodeType code, uint32_t addr)
{
	return new OpMul_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMul_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 52 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "mul.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 9137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMul_d(CodeType code, uint32_t addr)
{
	return new OpMul_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDiv_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 55 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "div.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 9187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDiv_s(CodeType code, uint32_t addr)
{
	return new OpDiv_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDiv_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 58 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "div.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 9237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDiv_d(CodeType code, uint32_t addr)
{
	return new OpDiv_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9264 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 61 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "sqrt.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSqrt_s(CodeType code, uint32_t addr)
{
	return new OpSqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 64 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "sqrt.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSqrt_d(CodeType code, uint32_t addr)
{
	return new OpSqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAbs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 67 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "abs.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAbs_s(CodeType code, uint32_t addr)
{
	return new OpAbs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAbs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 70 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "abs.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAbs_d(CodeType code, uint32_t addr)
{
	return new OpAbs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMov_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 73 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "mov.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMov_s(CodeType code, uint32_t addr)
{
	return new OpMov_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMov_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 76 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "mov.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMov_d(CodeType code, uint32_t addr)
{
	return new OpMov_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9564 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNeg_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 79 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "neg.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpNeg_s(CodeType code, uint32_t addr)
{
	return new OpNeg_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNeg_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 82 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "neg.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpNeg_d(CodeType code, uint32_t addr)
{
	return new OpNeg_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRound_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 85 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "round.l.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRound_l_s(CodeType code, uint32_t addr)
{
	return new OpRound_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRound_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 88 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "round.l.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRound_l_d(CodeType code, uint32_t addr)
{
	return new OpRound_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTrunc_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 91 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "trunc.l.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTrunc_l_s(CodeType code, uint32_t addr)
{
	return new OpTrunc_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTrunc_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 94 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "trunc.l.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTrunc_l_d(CodeType code, uint32_t addr)
{
	return new OpTrunc_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCeil_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 97 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "ceil.l.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCeil_l_s(CodeType code, uint32_t addr)
{
	return new OpCeil_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCeil_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 100 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "ceil.l.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9946 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCeil_l_d(CodeType code, uint32_t addr)
{
	return new OpCeil_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 9957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9964 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 9971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpFloor_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 9979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 9982 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 103 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "floor.l.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 9987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 9993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 9996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpFloor_l_s(CodeType code, uint32_t addr)
{
	return new OpFloor_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10014 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpFloor_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 106 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "floor.l.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpFloor_l_d(CodeType code, uint32_t addr)
{
	return new OpFloor_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRound_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 109 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "round.w.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRound_w_s(CodeType code, uint32_t addr)
{
	return new OpRound_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRound_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 112 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "round.w.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRound_w_d(CodeType code, uint32_t addr)
{
	return new OpRound_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTrunc_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 115 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "trunc.w.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTrunc_w_s(CodeType code, uint32_t addr)
{
	return new OpTrunc_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTrunc_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 118 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "trunc.w.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTrunc_w_d(CodeType code, uint32_t addr)
{
	return new OpTrunc_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10264 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCeil_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 121 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "ceil.w.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCeil_w_s(CodeType code, uint32_t addr)
{
	return new OpCeil_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCeil_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 124 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "ceil.w.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCeil_w_d(CodeType code, uint32_t addr)
{
	return new OpCeil_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpFloor_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 127 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "floor.w.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpFloor_w_s(CodeType code, uint32_t addr)
{
	return new OpFloor_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpFloor_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 130 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "floor.w.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpFloor_w_d(CodeType code, uint32_t addr)
{
	return new OpFloor_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_d_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 133 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.d.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_d_s(CodeType code, uint32_t addr)
{
	return new OpCvt_d_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_s_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 136 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.s.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_s_d(CodeType code, uint32_t addr)
{
	return new OpCvt_s_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10564 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 139 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.w.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_w_s(CodeType code, uint32_t addr)
{
	return new OpCvt_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 142 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.w.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_w_d(CodeType code, uint32_t addr)
{
	return new OpCvt_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 145 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.l.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_l_s(CodeType code, uint32_t addr)
{
	return new OpCvt_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 148 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.l.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 10737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_l_d(CodeType code, uint32_t addr)
{
	return new OpCvt_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 151 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "c." << PrintCond(cond) << ".s\t"; if (cc) sink << PrintR("$fcc",cc) << ','; sink << PrintR("$f",rb) << ',' << PrintR("$f",ra); }
#line 10787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC_s(CodeType code, uint32_t addr)
{
	return new OpC_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 154 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "c." << PrintCond(cond) << ".d\t"; if (cc) sink << PrintR("$fcc",cc) << ','; sink << PrintR("$f",rb) << ',' << PrintR("$f",ra); }
#line 10837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC_d(CodeType code, uint32_t addr)
{
	return new OpC_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCabs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 157 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cabs." << PrintCond(cond) << ".s\t" << PrintR("$fcc",cc) << ',' << PrintR("$f",rb) << ',' << PrintR("$f",ra); }
#line 10887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCabs_s(CodeType code, uint32_t addr)
{
	return new OpCabs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCabs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 160 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cabs." << PrintCond(cond) << ".d\t" << PrintR("$fcc",cc) << ',' << PrintR("$f",rb) << ',' << PrintR("$f",ra); }
#line 10937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10946 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCabs_d(CodeType code, uint32_t addr)
{
	return new OpCabs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 10957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10964 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 10971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovf_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 10979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 10982 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 164 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movf.s\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$fcc",cc); }
#line 10987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 10993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 10996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovf_s(CodeType code, uint32_t addr)
{
	return new OpMovf_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11014 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovf_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 168 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movf.d\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$fcc",cc); }
#line 11037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovf_d(CodeType code, uint32_t addr)
{
	return new OpMovf_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 172 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movt.s\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$fcc",cc); }
#line 11087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovt_s(CodeType code, uint32_t addr)
{
	return new OpMovt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 176 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movt.d\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$fcc",cc); }
#line 11137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovt_d(CodeType code, uint32_t addr)
{
	return new OpMovt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovz_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 180 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movz.s\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$",rt); }
#line 11187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovz_s(CodeType code, uint32_t addr)
{
	return new OpMovz_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovz_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 184 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movz.d\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$",rt); }
#line 11237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovz_d(CodeType code, uint32_t addr)
{
	return new OpMovz_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11264 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovn_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 188 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movn.s\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$",rt); }
#line 11287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovn_s(CodeType code, uint32_t addr)
{
	return new OpMovn_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovn_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 192 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "movn.d\t" << PrintR("$f",fd) << "," << PrintR("$f",fs) << ',' << PrintR("$",rt); }
#line 11337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovn_d(CodeType code, uint32_t addr)
{
	return new OpMovn_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 195 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip_s(CodeType code, uint32_t addr)
{
	return new OpRecip_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 198 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip_d(CodeType code, uint32_t addr)
{
	return new OpRecip_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 201 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip1.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip1_s(CodeType code, uint32_t addr)
{
	return new OpRecip1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 204 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip1.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip1_d(CodeType code, uint32_t addr)
{
	return new OpRecip1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11564 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 207 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt_s(CodeType code, uint32_t addr)
{
	return new OpRsqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 210 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt_d(CodeType code, uint32_t addr)
{
	return new OpRsqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 213 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt1.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt1_s(CodeType code, uint32_t addr)
{
	return new OpRsqrt1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 216 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt1.d\t" << PrintR("$f",rc) << "," << PrintR("$f",rb); }
#line 11737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt1_d(CodeType code, uint32_t addr)
{
	return new OpRsqrt1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11757 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 219 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip2.s\t" << PrintR("$f",rd) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 11787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip2_s(CodeType code, uint32_t addr)
{
	return new OpRecip2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRecip2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 222 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "recip2.d\t" << PrintR("$f",rd) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 11837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRecip2_d(CodeType code, uint32_t addr)
{
	return new OpRecip2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 225 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt2.s\t" << PrintR("$f",rd) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 11887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt2_s(CodeType code, uint32_t addr)
{
	return new OpRsqrt2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRsqrt2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 228 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "rsqrt2.d\t" << PrintR("$f",rd) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 11937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11946 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRsqrt2_d(CodeType code, uint32_t addr)
{
	return new OpRsqrt2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 11957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11964 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 11971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCvt_ps_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 11979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 11982 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 231 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/floating-point.isa"
	{ sink << "cvt.ps.s\t" << PrintR("$f",rc) << "," << PrintR("$f",rb) << "," << PrintR("$f",ra); }
#line 11987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 11993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 11996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCvt_ps_s(CodeType code, uint32_t addr)
{
	return new OpCvt_ps_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12014 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovf<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 3 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "movf\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintR("$fcc",cc); }
#line 12037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovf(CodeType code, uint32_t addr)
{
	return new OpMovf<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 7 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "movt\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintR("$fcc",cc); }
#line 12087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovt(CodeType code, uint32_t addr)
{
	return new OpMovt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 11 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "movz\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 12137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovz(CodeType code, uint32_t addr)
{
	return new OpMovz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMovn<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 15 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "movn\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 12187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMovn(CodeType code, uint32_t addr)
{
	return new OpMovn<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLsa<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 19 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "lsa\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt) << ',' << PrintHex(i+1); }
#line 12237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLsa(CodeType code, uint32_t addr)
{
	return new OpLsa<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12264 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRorv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 23 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "rorv\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintGPR(rs); }
#line 12287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRorv(CodeType code, uint32_t addr)
{
	return new OpRorv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 26 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "rorv\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintI(sa); }
#line 12337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12343 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12346 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRor(CodeType code, uint32_t addr)
{
	return new OpRor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMflhxu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 29 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "mflhxu\t" << PrintGPR(rc); }
#line 12387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMflhxu(CodeType code, uint32_t addr)
{
	return new OpMflhxu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtlhx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 32 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "mtlhx\t" << PrintGPR(ra); }
#line 12437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12446 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtlhx(CodeType code, uint32_t addr)
{
	return new OpMtlhx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 35 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "jr.hb\t" << PrintGPR(ra); }
#line 12487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12496 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJr_hb(CodeType code, uint32_t addr)
{
	return new OpJr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJalr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12532 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 39 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{
		sink << "jalr.hb\t";
		if (rc != 31) sink << PrintGPR(rc) << ",";
		sink << PrintGPR(ra);
	}
#line 12541 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12550 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12555 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJalr_hb(CodeType code, uint32_t addr)
{
	return new OpJalr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12561 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12568 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMultp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12586 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 46 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "multp\t" << PrintGPR(ra) << "," << PrintGPR(rb); }
#line 12591 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12600 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12605 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMultp(CodeType code, uint32_t addr)
{
	return new OpMultp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12618 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAclr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 49 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "aclr\t" << PrintHex(imm) << ',' << PrintI(offset) << '(' << PrintGPR(ra) << ')'; }
#line 12641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12650 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12655 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAclr(CodeType code, uint32_t addr)
{
	return new OpAclr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12661 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAset<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12686 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 52 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "aset\t" << PrintHex(imm) << ',' << PrintI(offset) << '(' << PrintGPR(ra) << ')'; }
#line 12691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12697 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12700 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAset(CodeType code, uint32_t addr)
{
	return new OpAset<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12711 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12718 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBposge32<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 55 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "bposge32\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 12741 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12747 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12750 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12755 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBposge32(CodeType code, uint32_t addr)
{
	return new OpBposge32<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12761 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12768 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRdhwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 58 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "rdhwr\t" << PrintGPR(rt) << ',' << PrintR("$",rd); }
#line 12791 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12803 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpRdhwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 12811 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 12814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 60 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ core.SetGPR(rt, core.GetHWR(rd)); }
#line 12819 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12828 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpRdhwr(CodeType code, uint32_t addr)
{
	return new OpRdhwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12839 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpClz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12861 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 64 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{
		sink << "clz\t" << PrintGPR(rd);
		if (rd != rt) sink << " or " << PrintGPR(rt);
		sink << ',' << PrintGPR(rs);
	}
#line 12873 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12882 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpClz(CodeType code, uint32_t addr)
{
	return new OpClz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12900 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12911 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12918 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 71 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "di"; if (rt) sink << ',' << PrintGPR(rt); }
#line 12923 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDi(CodeType code, uint32_t addr)
{
	return new OpDi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 12957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpExt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 12965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 12968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 74 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "ext\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(lsb) << ',' << PrintI(msbd+1); }
#line 12973 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 12979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12982 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 12987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpExt(CodeType code, uint32_t addr)
{
	return new OpExt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 12993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13000 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13003 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpIns<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13018 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 77 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "ins\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(lsb) << ',' << PrintI(msb-lsb+1); }
#line 13023 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpIns(CodeType code, uint32_t addr)
{
	return new OpIns<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13050 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMaddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13061 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13068 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 81 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "maddu\t" << PrintGPR(rt) << ',' << PrintGPR(rs); }
#line 13073 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMaddu(CodeType code, uint32_t addr)
{
	return new OpMaddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13103 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMul<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 85 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "mul\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 13123 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMul(CodeType code, uint32_t addr)
{
	return new OpMul<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13150 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13153 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSeb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13161 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13165 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 89 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "seb\t" << PrintGPR(rd) << ',' << PrintGPR(rt); }
#line 13173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSeb(CodeType code, uint32_t addr)
{
	return new OpSeb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13200 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSeh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13211 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 93 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/mips32r2.isa"
	{ sink << "seh\t" << PrintGPR(rd) << ',' << PrintGPR(rt); }
#line 13223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSeh(CodeType code, uint32_t addr)
{
	return new OpSeh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJ<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13261 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 84 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "j\t" << PrintHex((this->GetAddr() & (-1<<28)) | target); }
#line 13273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13278 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJ<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 87 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;

		U32 base = core.GetPC() & U32(-1<<28);
		core.Branch(base | U32(target), core.B_JMP);
	}
#line 13306 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13312 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13315 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13320 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJ(CodeType code, uint32_t addr)
{
	return new OpJ<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13326 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13340 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJal<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13348 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 96 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "jal\t" << PrintHex((this->GetAddr() & (-1<<28)) | target); }
#line 13356 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13361 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13368 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJal<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13372 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13376 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 99 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;

		core.SetGPR(31, core.GetPC() + U32(8));
		U32 base = core.GetPC() & U32(-1<<28);
		core.Branch(base | U32(target),core.B_CALL);
	}
#line 13390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJal(CodeType code, uint32_t addr)
{
	return new OpJal<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13410 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13420 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13424 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNop<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13428 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 108 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "nop"; }
#line 13440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13448 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNop<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13456 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 110 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{}
#line 13468 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13477 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpNop(CodeType code, uint32_t addr)
{
	return new OpNop<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13495 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13506 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13510 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 118 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "srl\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintHex(imm); }
#line 13518 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13523 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13526 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13541 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 120 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rt) >> imm); }
#line 13546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13555 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13560 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSrl(CodeType code, uint32_t addr)
{
	return new OpSrl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13573 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13576 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSra<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13588 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13591 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 123 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sra\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintHex(imm); }
#line 13596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13608 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSra<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13612 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13616 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13619 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 125 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, typename ARCH::U32(typename ARCH::S32(core.GetGPR(rt)) >> imm)); }
#line 13624 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13630 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13638 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSra(CodeType code, uint32_t addr)
{
	return new OpSra<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13658 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSllv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13662 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13666 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13669 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 128 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sllv\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintGPR(rs); }
#line 13674 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13686 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSllv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13697 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 131 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U8 U8;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rd, core.GetGPR(rt) << U8(core.GetGPR(rs) & U32(0xff)) );
	}
#line 13706 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13712 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13720 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSllv(CodeType code, uint32_t addr)
{
	return new OpSllv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13726 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrlv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13744 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13748 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 138 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "srlv\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintGPR(rs); }
#line 13756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13761 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13768 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrlv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 141 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U8 U8;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rd, core.GetGPR(rt) >> U8(core.GetGPR(rs) & U32(0xff)) );
	}
#line 13788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13794 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13802 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSrlv(CodeType code, uint32_t addr)
{
	return new OpSrlv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13808 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13815 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrav<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13830 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 148 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "srav\t" << PrintGPR(rd) << ',' << PrintGPR(rt) << ',' << PrintGPR(rs); }
#line 13838 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13850 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSrav<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13858 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13861 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 151 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U8 U8;
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		core.SetGPR(rd, U32(S32(core.GetGPR(rt)) >> U8(core.GetGPR(rs) & U32(0xff))) );
	}
#line 13871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13880 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSrav(CodeType code, uint32_t addr)
{
	return new OpSrav<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13891 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13898 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13905 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13916 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 159 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "jr\t" << PrintGPR(rs); }
#line 13921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13933 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 13941 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 13944 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 161 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.Branch(core.GetGPR(rs), core.B_JMP); }
#line 13949 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13958 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJr(CodeType code, uint32_t addr)
{
	return new OpJr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 13969 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 13976 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 13983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJalr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 13987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 13991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 13994 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 166 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "jalr\t";
		if (rd != 31) sink << PrintGPR(rd) << ',';
		sink << PrintGPR(rs);
	}
#line 14003 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14008 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJalr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14023 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14026 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 173 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		core.SetGPR(rd, core.GetPC() + typename ARCH::U32(8));
		core.Branch(core.GetGPR(rs), core.B_CALL);
	}
#line 14034 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14040 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14048 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJalr(CodeType code, uint32_t addr)
{
	return new OpJalr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14061 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14068 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSyscall<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14072 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14076 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 179 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "syscall"; if (imm) sink << '\t' << PrintHex(imm); }
#line 14084 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14089 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14092 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSyscall<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 181 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SysCall(imm); }
#line 14112 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSyscall(CodeType code, uint32_t addr)
{
	return new OpSyscall<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14139 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14142 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBreak<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14150 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 185 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "break";
		if (imm1 or imm2)
		sink << '\t' << PrintHex(imm1);
		if (imm2)
		sink <<  ',' << PrintHex(imm2);
	}
#line 14168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14177 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBreak(CodeType code, uint32_t addr)
{
	return new OpBreak<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14188 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14198 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14202 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfhi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14210 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14213 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 194 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mfhi\t" << PrintGPR(rd); if (ra) sink << ',' << PrintR("$ac",ra); }
#line 14218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14226 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14230 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfhi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14234 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 196 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetHI(ra)); }
#line 14246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14252 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMfhi(CodeType code, uint32_t addr)
{
	return new OpMfhi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14266 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14276 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14280 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMthi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14284 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14291 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 199 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mthi\t" << PrintGPR(rs); if (ra) sink << ',' << PrintR("$ac",ra); }
#line 14296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14308 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMthi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14312 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14319 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 201 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetHI(ra, core.GetGPR(rs)); }
#line 14324 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14330 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14338 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMthi(CodeType code, uint32_t addr)
{
	return new OpMthi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMflo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14369 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 204 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mflo\t" << PrintGPR(rd); if (ra) sink << ',' << PrintR("$ac",ra); }
#line 14374 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14386 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMflo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14394 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 206 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetLO(ra)); }
#line 14402 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14408 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14411 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMflo(CodeType code, uint32_t addr)
{
	return new OpMflo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14422 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14436 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtlo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14447 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 209 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mtlo\t" << PrintGPR(rs); if (ra) sink << ',' << PrintR("$ac",ra); }
#line 14452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14464 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtlo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14468 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14472 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 211 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetLO(ra, core.GetGPR(rs)); }
#line 14480 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14486 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14489 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14494 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtlo(CodeType code, uint32_t addr)
{
	return new OpMtlo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14500 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14510 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14514 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMult<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14518 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 214 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mult\t"; if (ra) sink << PrintR("$ac",ra) << ','; sink << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14535 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMult<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14550 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14553 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 216 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::S32 S32;
		typedef typename ARCH::S64 S64;
		typedef typename ARCH::U32 U32;

		S64 res = S64(S32(core.GetGPR(rs)))*S64(S32(core.GetGPR(rt)));
		core.SetHI(ra, U32(res >> 32));
		core.SetLO(ra, U32(res >> 0));
	}
#line 14566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMult(CodeType code, uint32_t addr)
{
	return new OpMult<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14586 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14600 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMultu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14608 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 227 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "multu\t"; if (ra) sink << PrintR("$ac",ra) << ','; sink << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14616 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14624 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMultu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14639 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 229 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::U64 U64;

		U64 res = U64(U32(core.GetGPR(rs)))*U64(U32(core.GetGPR(rt)));
		core.SetHI(ra, U32(res >> 32));
		core.SetLO(ra, U32(res >> 0));
	}
#line 14651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14657 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14660 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMultu(CodeType code, uint32_t addr)
{
	return new OpMultu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14681 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDiv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14689 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 239 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "div\t" << PrintGPR(0) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14710 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDiv(CodeType code, uint32_t addr)
{
	return new OpDiv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14735 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDivu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14739 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 243 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "divu\t" << PrintGPR(0) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14763 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDivu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 245 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetDivU( core.GetGPR(rs), core.GetGPR(rt) ); }
#line 14779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14785 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDivu(CodeType code, uint32_t addr)
{
	return new OpDivu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14806 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14813 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAdd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14824 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 248 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "add\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14838 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAdd(CodeType code, uint32_t addr)
{
	return new OpAdd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14856 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 251 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "addu\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 14879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14891 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 14899 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 14902 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 253 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rs) + core.GetGPR(rt)); }
#line 14907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14916 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAddu(CodeType code, uint32_t addr)
{
	return new OpAddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14927 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14941 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSub<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 14949 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 14952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 257 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "sub\t" << PrintGPR(rd);
		if (rt) sink << ',' << PrintGPR(rs);
		sink << ',' << PrintGPR(rt);
	}
#line 14961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14970 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSub(CodeType code, uint32_t addr)
{
	return new OpSub<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 14981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 14988 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 14995 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSubu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 14999 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15003 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 265 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "subu\t" << PrintGPR(rd);
		if (rt) sink << ',' << PrintGPR(rs);
		sink << ',' << PrintGPR(rt);
	}
#line 15015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15023 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15027 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSubu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 272 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		core.SetGPR(rd, core.GetGPR(rs) - core.GetGPR(rt));
	}
#line 15045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSubu(CodeType code, uint32_t addr)
{
	return new OpSubu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15072 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAnd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 277 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "and\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 15095 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15103 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAnd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 279 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rs) & core.GetGPR(rt)); }
#line 15123 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAnd(CodeType code, uint32_t addr)
{
	return new OpAnd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15150 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15153 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpOr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15161 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15165 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 282 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "or\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 15173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15185 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpOr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 284 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rs) | core.GetGPR(rt)); }
#line 15201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15210 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpOr(CodeType code, uint32_t addr)
{
	return new OpOr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15228 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15231 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpXor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15239 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 287 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "xor\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 15251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15256 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15263 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpXor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15271 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15274 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 289 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, core.GetGPR(rs) ^ core.GetGPR(rt)); }
#line 15279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpXor(CodeType code, uint32_t addr)
{
	return new OpXor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15299 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15306 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15321 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15324 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 292 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "nor\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 15329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15334 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15341 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpNor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15349 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15352 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 294 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rd, ~(core.GetGPR(rs) | core.GetGPR(rt))); }
#line 15357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15363 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpNor(CodeType code, uint32_t addr)
{
	return new OpNor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15377 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15384 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15391 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBltz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15402 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 297 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bltz" << (al ? "al" : "") << (l ? "l" : "") << '\t' << PrintGPR(rs) << ',' << PrintHex(this->GetAddr() + offset + 4); }
#line 15407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBltz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15423 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15427 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15430 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 300 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		if (al) core.SetGPR(31, core.GetPC() + U32(8));
		if (core.Test(S32(core.GetGPR(rs)) < S32(0)))
		core.Branch(core.GetPC() + U32(offset + 4), al ? core.B_CALL : core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15449 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBltz(CodeType code, uint32_t addr)
{
	return new OpBltz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15473 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15477 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBgez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 311 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bgez" << (al ? "al" : "") << (l ? "l" : "") << '\t' << PrintGPR(rs) << ',' << PrintHex(this->GetAddr() + offset + 4); }
#line 15493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15505 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBgez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 314 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		if (al) core.SetGPR(31, core.GetPC() + U32(8));
		if (core.Test(S32(core.GetGPR(rs)) >= S32(0)))
		core.Branch(core.GetPC() + U32(offset + 4), al ? core.B_CALL : core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15535 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBgez(CodeType code, uint32_t addr)
{
	return new OpBgez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15549 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15563 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBlez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15574 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 326 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "blez" << (l ? "l" : "") << "\t" << PrintGPR(rs) << ',' << PrintHex(this->GetAddr() + offset + 4); }
#line 15579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15591 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBlez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15599 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15602 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 329 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		if (core.Test(S32(core.GetGPR(rs)) <= S32(0)))
		core.Branch(core.GetPC() + U32(offset + 4), core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15620 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15623 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBlez(CodeType code, uint32_t addr)
{
	return new OpBlez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15648 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBgtz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15652 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 339 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bgtz" << (l ? "l" : "") << "\t" << PrintGPR(rs) << ',' << PrintHex(this->GetAddr() + offset + 4); }
#line 15664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15669 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15676 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBgtz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15680 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15684 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 342 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		if (core.Test(S32(core.GetGPR(rs)) > S32(0)))
		core.Branch(core.GetPC() + U32(offset + 4), core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15699 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15708 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15713 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBgtz(CodeType code, uint32_t addr)
{
	return new OpBgtz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15719 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15726 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15741 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15744 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 353 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "beq" << (rt ? "" : "z") << (l ? "l" : "") << "\t" << PrintGPR(rs);
		if (rt) sink << ',' << PrintGPR(rt);
		sink << ',' << PrintHex(this->GetAddr() + offset + 4);
	}
#line 15753 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15758 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15761 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15769 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15773 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 360 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		if (core.Test(core.GetGPR(rs) == core.GetGPR(rt)))
		core.Branch(core.GetPC() + U32(offset + 4), core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBeq(CodeType code, uint32_t addr)
{
	return new OpBeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15807 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 370 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		sink << "bne" << (rt ? "" : "z") << (l ? "l" : "") << "\t" << PrintGPR(rs);
		if (rt) sink << ',' << PrintGPR(rt);
		sink << ',' << PrintHex(this->GetAddr() + offset + 4);
	}
#line 15841 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 15861 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 15864 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 377 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		if (core.Test(core.GetGPR(rs) != core.GetGPR(rt)))
		core.Branch(core.GetPC() + U32(offset + 4),core.B_JMP);
		else if (l) /* Likely */
		core.CancelDelaySlot();
	}
#line 15875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBne(CodeType code, uint32_t addr)
{
	return new OpBne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15902 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15905 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTge<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15920 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 386 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tge\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 15925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15931 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15939 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTge(CodeType code, uint32_t addr)
{
	return new OpTge<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 15959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTgeu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 15967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 15970 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 389 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tgeu\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 15975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 15981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15984 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 15989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTgeu(CodeType code, uint32_t addr)
{
	return new OpTgeu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 15995 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 392 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tlt\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 16025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16034 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlt(CodeType code, uint32_t addr)
{
	return new OpTlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16052 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16055 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16063 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 395 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tltu\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 16075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16081 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16084 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16089 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTltu(CodeType code, uint32_t addr)
{
	return new OpTltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16095 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16102 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16105 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16109 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16113 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16120 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 398 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "teq\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 16125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16131 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16134 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16139 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTeq(CodeType code, uint32_t addr)
{
	return new OpTeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16152 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16155 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 401 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tne\t" << PrintGPR(rs) << ',' << PrintGPR(rt); if (imm) sink << ',' << PrintHex(imm); }
#line 16175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16184 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTne(CodeType code, uint32_t addr)
{
	return new OpTne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16202 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16205 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTgei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16213 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16220 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 404 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tgei\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16231 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16234 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16239 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTgei(CodeType code, uint32_t addr)
{
	return new OpTgei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16252 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTgeiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16263 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16270 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 407 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tgeiu\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16284 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTgeiu(CodeType code, uint32_t addr)
{
	return new OpTgeiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16320 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 410 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tlti\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16334 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTlti(CodeType code, uint32_t addr)
{
	return new OpTlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16352 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16355 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16363 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 413 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tltiu\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16384 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16389 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTltiu(CodeType code, uint32_t addr)
{
	return new OpTltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16402 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTeqi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16413 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16420 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 416 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "teqi\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16431 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16434 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16439 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTeqi(CodeType code, uint32_t addr)
{
	return new OpTeqi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16455 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16459 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpTnei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 419 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "tnei\t" << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16484 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16489 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpTnei(CodeType code, uint32_t addr)
{
	return new OpTnei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16495 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16505 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAddi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16520 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 422 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "addi\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAddi(CodeType code, uint32_t addr)
{
	return new OpAddi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16555 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAddiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16563 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16570 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 425 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "addiu\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAddiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16591 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16598 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 427 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rt, core.GetGPR(rs) + typename ARCH::U32(imm)); }
#line 16603 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16609 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16612 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAddiu(CodeType code, uint32_t addr)
{
	return new OpAddiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16623 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16630 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16648 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 430 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "slt\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 16653 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16658 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16661 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16669 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16673 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16676 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 433 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		core.SetGPR( rd, U32(S32(core.GetGPR(rs)) < S32(core.GetGPR(rt))));
	}
#line 16685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16699 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSlt(CodeType code, uint32_t addr)
{
	return new OpSlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16712 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16719 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16723 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16727 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16730 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 440 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "slti\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16735 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16747 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16755 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16758 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 443 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::S32 S32;
		core.SetGPR( rt, U32(S32(core.GetGPR(rs)) < S32(imm)));
	}
#line 16767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16773 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16781 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSlti(CodeType code, uint32_t addr)
{
	return new OpSlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16794 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16812 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 450 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sltu\t" << PrintGPR(rd) << ',' << PrintGPR(rs) << ',' << PrintGPR(rt); }
#line 16817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 452 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR( rd, typename ARCH::U32(core.GetGPR(rs) < core.GetGPR(rt))); }
#line 16845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSltu(CodeType code, uint32_t addr)
{
	return new OpSltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16872 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16883 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 455 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sltiu\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintI(imm); }
#line 16895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16900 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16911 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16918 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 457 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR( rt, typename ARCH::U32(core.GetGPR(rs) < typename ARCH::U32(imm))); }
#line 16923 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSltiu(CodeType code, uint32_t addr)
{
	return new OpSltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 16943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAndi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 16965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 16968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 460 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "andi\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintHex(imm); }
#line 16973 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 16978 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 16985 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpAndi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 16989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 16993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 16996 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 462 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rt, core.GetGPR(rs) & typename ARCH::U32(imm)); }
#line 17001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17010 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpAndi(CodeType code, uint32_t addr)
{
	return new OpAndi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpOri<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 465 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ori\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintHex(imm); }
#line 17051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17063 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpOri<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17074 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 467 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rt, core.GetGPR(rs) | typename ARCH::U32(imm)); }
#line 17079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17088 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpOri(CodeType code, uint32_t addr)
{
	return new OpOri<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17099 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17109 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17113 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpXori<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17124 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 470 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "xori\t" << PrintGPR(rt) << ',' << PrintGPR(rs) << ',' << PrintHex(imm); }
#line 17129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17134 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17141 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpXori<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17149 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17152 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 472 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rt, core.GetGPR(rs) ^ typename ARCH::U32(imm)); }
#line 17157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpXori(CodeType code, uint32_t addr)
{
	return new OpXori<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17177 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17184 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17191 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLui<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17202 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 475 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lui\t" << PrintGPR(rt) << ',' << PrintHex(imm); }
#line 17207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17212 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17219 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLui<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17227 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17230 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 477 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ core.SetGPR(rt, typename ARCH::U32(imm << 16)); }
#line 17235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17244 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17249 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLui(CodeType code, uint32_t addr)
{
	return new OpLui<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17262 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17277 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17280 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 480 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lb\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17297 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17308 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 483 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::S8 S8;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<S8>(core.GetGPR(rs) + U32(offset))));
	}
#line 17317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17323 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17326 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLb(CodeType code, uint32_t addr)
{
	return new OpLb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLbu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17355 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 490 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lbu\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17372 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLbu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17383 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 493 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U8 U8;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<U8>(core.GetGPR(rs) + U32(offset))));
	}
#line 17399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17408 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17413 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLbu(CodeType code, uint32_t addr)
{
	return new OpLbu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17426 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17441 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 500 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lh\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17449 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17461 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17469 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17472 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 503 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::S16 S16;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<S16>(core.GetGPR(rs) + U32(offset))));
	}
#line 17481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17495 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLh(CodeType code, uint32_t addr)
{
	return new OpLh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17508 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17515 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLhu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17523 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17526 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 510 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lhu\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17536 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLhu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17554 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 513 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U16 U16;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<U16>(core.GetGPR(rs) + U32(offset))));
	}
#line 17563 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17569 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17577 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLhu(CodeType code, uint32_t addr)
{
	return new OpLhu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17605 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17608 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 520 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lw\t" << PrintGPR(rt) << ',' << int(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17618 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 523 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::S32 S32;
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<S32>(core.GetGPR(rs) + U32(offset))));
	}
#line 17645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLw(CodeType code, uint32_t addr)
{
	return new OpLw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 530 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwu\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17695 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17700 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17703 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17707 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17711 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17718 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 533 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		core.SetGPR(rt, U32(core.template MemRead<U32>(core.GetGPR(rs) + U32(offset))));
	}
#line 17726 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17735 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwu(CodeType code, uint32_t addr)
{
	return new OpLwu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17753 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17760 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17768 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 539 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sb\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17781 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17784 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17792 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 542 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U8 U8;
		typedef typename ARCH::U32 U32;
		core.template MemWrite(core.GetGPR(rs) + U32(offset), U8(core.GetGPR(rt)));
	}
#line 17808 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSb(CodeType code, uint32_t addr)
{
	return new OpSb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17828 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17838 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17842 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17850 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 549 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sh\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17858 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17870 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17878 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 552 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U16 U16;
		typedef typename ARCH::U32 U32;
		core.template MemWrite(core.GetGPR(rs) + U32(offset), U16(core.GetGPR(rt)));
	}
#line 17890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17899 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSh(CodeType code, uint32_t addr)
{
	return new OpSh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17910 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17920 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17924 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17928 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 17932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 17935 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 559 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sw\t" << PrintGPR(rt) << ',' << int(offset) << '(' << PrintGPR(rs) << ')'; }
#line 17940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17948 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 17952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 17960 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 17963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 562 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		core.template MemWrite(core.GetGPR(rs) + U32(offset), U32(core.GetGPR(rt)));
	}
#line 17971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17977 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17980 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 17985 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSw(CodeType code, uint32_t addr)
{
	return new OpSw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 17991 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 17998 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 569 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ll\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 18021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18026 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18033 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 18041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 18044 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 572 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;

		U32 addr = core.GetGPR(rs) + U32(offset);

		core.AtomicBegin(addr);
		core.SetGPR(rt, core.template MemRead<U32>(core.GetGPR(rs) + U32(offset)));
	}
#line 18056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18062 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLl(CodeType code, uint32_t addr)
{
	return new OpLl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18076 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18086 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSc<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18094 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18098 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 582 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sc\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 18106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSc<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 18126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 18129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 585 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		typedef typename ARCH::BOOL BOOL;

		U32 addr = core.GetGPR(rs) + U32(offset);

		BOOL cond = core.AtomicUpdate(addr);
		if (core.Test(cond))
		core.template MemWrite(addr, U32(core.GetGPR(rt)));

		core.SetGPR(rt,U32(cond));
	}
#line 18145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSc(CodeType code, uint32_t addr)
{
	return new OpSc<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18165 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18172 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18183 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 603 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mfc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMfc0(CodeType code, uint32_t addr)
{
	return new OpMfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18240 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 606 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmfc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmfc0(CodeType code, uint32_t addr)
{
	return new OpDmfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18283 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 609 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "cfc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCfc0(CodeType code, uint32_t addr)
{
	return new OpCfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18315 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18340 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 612 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mtc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtc0(CodeType code, uint32_t addr)
{
	return new OpMtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18365 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18372 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18383 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 615 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmtc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmtc0(CodeType code, uint32_t addr)
{
	return new OpDmtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18422 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 618 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ctc" << unsigned(0) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18459 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCtc0(CodeType code, uint32_t addr)
{
	return new OpCtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18472 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc0f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18483 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 621 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(0) << "f" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 18495 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc0f(CodeType code, uint32_t addr)
{
	return new OpBc0f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18515 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc0t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18533 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18540 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 624 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(0) << "t" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 18545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18554 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc0t(CodeType code, uint32_t addr)
{
	return new OpBc0t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 631 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mfc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintR("$f",rc); }
#line 18595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18609 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMfc1(CodeType code, uint32_t addr)
{
	return new OpMfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18615 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18622 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18640 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 634 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmfc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintR("$f",rc); }
#line 18645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmfc1(CodeType code, uint32_t addr)
{
	return new OpDmfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 637 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "cfc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18695 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18704 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18709 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCfc1(CodeType code, uint32_t addr)
{
	return new OpCfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18722 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 640 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mtc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintR("$f",rc); }
#line 18745 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtc1(CodeType code, uint32_t addr)
{
	return new OpMtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18790 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 643 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmtc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintR("$f",rc); }
#line 18795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18804 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmtc1(CodeType code, uint32_t addr)
{
	return new OpDmtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18815 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 646 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ctc" << unsigned(1) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 18845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCtc1(CodeType code, uint32_t addr)
{
	return new OpCtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18872 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc1f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18883 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 649 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(1) << "f" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 18895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc1f(CodeType code, uint32_t addr)
{
	return new OpBc1f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18922 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc1t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18933 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 652 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(1) << "t" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 18945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18951 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18954 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc1t(CodeType code, uint32_t addr)
{
	return new OpBc1t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 18965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 18972 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 18979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 18983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 18987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 18990 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 656 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "c" << unsigned(2) << "\t" << PrintHex(imm); }
#line 18995 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19004 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC2(CodeType code, uint32_t addr)
{
	return new OpC2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19022 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19033 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19040 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 659 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mfc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMfc2(CodeType code, uint32_t addr)
{
	return new OpMfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19072 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19087 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 662 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmfc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19095 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19109 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmfc2(CodeType code, uint32_t addr)
{
	return new OpDmfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19125 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 665 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "cfc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCfc2(CodeType code, uint32_t addr)
{
	return new OpCfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19165 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19172 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19175 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19183 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 668 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mtc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtc2(CodeType code, uint32_t addr)
{
	return new OpMtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19240 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 671 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmtc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmtc2(CodeType code, uint32_t addr)
{
	return new OpDmtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19275 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19279 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19283 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 674 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ctc" << unsigned(2) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19301 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCtc2(CodeType code, uint32_t addr)
{
	return new OpCtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19315 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc2f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19337 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19340 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 677 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(2) << "f" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 19345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc2f(CodeType code, uint32_t addr)
{
	return new OpBc2f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19365 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19372 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19375 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc2t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19383 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 680 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(2) << "t" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 19395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc2t(CodeType code, uint32_t addr)
{
	return new OpBc2t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19422 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19429 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpC3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 684 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "c" << unsigned(3) << "\t" << PrintHex(imm); }
#line 19445 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19454 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19459 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpC3(CodeType code, uint32_t addr)
{
	return new OpC3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19472 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19483 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 687 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mfc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19495 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMfc3(CodeType code, uint32_t addr)
{
	return new OpMfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19515 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19533 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19537 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19540 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 690 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmfc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19554 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19559 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmfc3(CodeType code, uint32_t addr)
{
	return new OpDmfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 693 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "cfc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19609 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCfc3(CodeType code, uint32_t addr)
{
	return new OpCfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19615 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19622 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpMtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19640 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 696 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "mtc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpMtc3(CodeType code, uint32_t addr)
{
	return new OpMtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpDmtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 699 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "dmtc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19695 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19704 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19709 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpDmtc3(CodeType code, uint32_t addr)
{
	return new OpDmtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19715 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19722 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 702 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ctc" << unsigned(3) << "\t" << PrintGPR(rb) << ',' << PrintGPR(rc); }
#line 19745 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCtc3(CodeType code, uint32_t addr)
{
	return new OpCtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19775 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc3f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19787 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19790 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 705 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(3) << "f" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 19795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19801 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19804 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc3f(CodeType code, uint32_t addr)
{
	return new OpBc3f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19815 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpBc3t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19833 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 708 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "bc" << unsigned(3) << "t" << (l ? "l" : "") << "\t" << PrintHex(this->GetAddr() + offset + 4); }
#line 19845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19859 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpBc3t(CodeType code, uint32_t addr)
{
	return new OpBc3t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19872 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19879 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpJalx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19883 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 711 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "jalx\t" << PrintHex(target+1); }
#line 19895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpJalx(CodeType code, uint32_t addr)
{
	return new OpJalx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 19915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19922 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19933 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 19937 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 19940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 714 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwl\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 19945 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 19957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 19965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 19968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 717 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		U32 addr = core.GetGPR(rs) + U32(offset^3), aligned, shift;
		if (core.IsBigEndian())
		{ aligned = addr & U32(-4); shift = addr % U32(4); }
		else
		{ aligned = (addr + U32(3)) & U32(-4); shift = -addr % U32(4); }
		shift <<= 3;
		U32 value = core.template MemRead<U32>(aligned) << shift, mask = U32(-1) << shift;
		core.SetGPR(rt, value | (core.GetGPR(rt) & ~mask));
	}
#line 19983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 19989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 19997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwl(CodeType code, uint32_t addr)
{
	return new OpLwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20003 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20010 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20021 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 730 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwr\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20033 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20045 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20049 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 20053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 20056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 733 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		U32 addr = core.GetGPR(rs) + U32(offset), aligned, shift;
		if (core.IsBigEndian())
		{ aligned = (addr + U32(3)) & U32(-4); shift = -addr % U32(4); }
		else
		{ aligned = addr & U32(-4); shift = addr % U32(4); }
		shift <<= 3;
		U32 value = core.template MemRead<U32>(aligned) >> shift, mask = U32(-1) >> shift;
		core.SetGPR(rt, value | (core.GetGPR(rt) & ~mask));
	}
#line 20071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20077 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20080 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwr(CodeType code, uint32_t addr)
{
	return new OpLwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20091 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20098 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20105 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20109 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20113 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20116 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 747 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "swl\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 20141 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 20144 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 750 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		U32 addr = core.GetGPR(rs) + U32(offset^3), aligned, shift;
		if (core.IsBigEndian())
		{ aligned = addr & U32(-4); shift = addr % U32(4); }
		else
		{ aligned = (addr + U32(3)) & U32(-4); shift = -addr % U32(4); }
		shift <<= 3;
		U32 value = core.GetGPR(rt) >> shift, mask = U32(-1) >> shift;
		core.MemWrite(aligned, value | (core.template MemRead<U32>(aligned) & ~mask));
	}
#line 20159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20165 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSwl(CodeType code, uint32_t addr)
{
	return new OpSwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20186 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20193 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20197 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 764 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "swr\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}
template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20221 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20225 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::execute(
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH&
#line 20229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 56 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
core
#line 20232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 767 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{
		typedef typename ARCH::U32 U32;
		U32 addr = core.GetGPR(rs) + U32(offset), aligned, shift;
		if (core.IsBigEndian())
		{ aligned = (addr + U32(3)) & U32(-4); shift = -addr % U32(4); }
		else
		{ aligned = addr & U32(-4); shift = addr % U32(4); }
		shift <<= 3;
		U32 value = core.GetGPR(rt) << shift, mask = U32(-1) << shift;
		core.MemWrite(aligned, value | (core.template MemRead<U32>(aligned) & ~mask));
	}
#line 20247 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20256 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20261 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSwr(CodeType code, uint32_t addr)
{
	return new OpSwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20267 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20274 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20277 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSdl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20292 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 780 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sdl\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20297 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20303 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20306 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20311 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSdl(CodeType code, uint32_t addr)
{
	return new OpSdl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20324 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSdr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20335 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20342 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 783 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sdr\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20353 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20356 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20361 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSdr(CodeType code, uint32_t addr)
{
	return new OpSdr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20374 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20377 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpCache<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20385 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20389 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 786 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "cache\t" << PrintHex(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20403 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20406 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20411 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpCache(CodeType code, uint32_t addr)
{
	return new OpCache<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20424 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20427 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20431 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20439 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20442 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 789 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwc1\t" << PrintR("$f",rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20447 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20456 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20461 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwc1(CodeType code, uint32_t addr)
{
	return new OpLwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20477 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20489 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20492 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 792 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwc2\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20497 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20503 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20506 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwc2(CodeType code, uint32_t addr)
{
	return new OpLwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20517 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20524 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20527 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20535 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 795 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lwc3\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20553 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20561 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLwc3(CodeType code, uint32_t addr)
{
	return new OpLwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20574 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20577 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20581 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLld<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20585 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20589 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20592 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 798 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "lld\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20603 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20606 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLld(CodeType code, uint32_t addr)
{
	return new OpLld<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20624 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20627 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20631 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20635 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20639 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20642 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 801 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ldc1\t" << PrintR("$f",rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20653 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20661 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLdc1(CodeType code, uint32_t addr)
{
	return new OpLdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20674 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20677 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20681 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20689 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20692 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 804 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ldc2\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20697 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20703 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20706 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20711 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLdc2(CodeType code, uint32_t addr)
{
	return new OpLdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20727 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpLdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20735 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20739 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20742 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 807 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "ld\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20747 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20753 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20761 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpLdc3(CodeType code, uint32_t addr)
{
	return new OpLdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20781 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20785 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20789 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20792 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 810 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "swc1\t" << PrintR("$f",rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20803 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20806 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20811 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSwc1(CodeType code, uint32_t addr)
{
	return new OpSwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20824 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20827 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20831 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20839 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20842 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 813 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "swc2\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20847 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20856 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20861 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSwc2(CodeType code, uint32_t addr)
{
	return new OpSwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 816 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "swc3\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20897 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20906 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20911 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSwc3(CodeType code, uint32_t addr)
{
	return new OpSwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20924 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20927 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20931 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpScd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20935 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20939 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20942 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 819 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "scd\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20947 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpScd(CodeType code, uint32_t addr)
{
	return new OpScd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 20967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 20974 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20977 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 20981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 20985 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 20989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 20992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 822 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sdc1\t" << PrintR("$f",rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 20997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21003 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSdc1(CodeType code, uint32_t addr)
{
	return new OpSdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 21017 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21027 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 21031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 21039 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 21042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 825 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sdc2\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 21047 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21061 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSdc2(CodeType code, uint32_t addr)
{
	return new OpSdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 21067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21074 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21077 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
void
#line 21081 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
OpSdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::disasm(
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
std::ostream&
#line 21089 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 52 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
sink
#line 21092 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
) const
{
#line 828 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	{ sink << "sd\t" << PrintGPR(rt) << ',' << PrintI(offset) << '(' << PrintGPR(rs) << ')'; }
#line 21097 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21103 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
static Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21111 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *DecodeOpSdc3(CodeType code, uint32_t addr)
{
	return new OpSdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 21117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21124 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21127 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSync<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSync(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21136 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sync")
{
	stype = uint8_t((code >> 6) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21148 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSll<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21153 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSll(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sll")
{
	imm = uint8_t((code >> 6) & 0x1f);
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21171 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21176 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21180 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c0")
{
	imm = uint32_t(code & 0x1ffffff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21189 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21197 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c1")
{
	imm = uint32_t(code & 0x1ffffff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21210 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21213 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlbr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlbr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlbr")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21230 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlbwi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlbwi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21242 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlbwi")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21253 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlbwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21258 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlbwr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21262 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlbwr")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21270 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlbp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21278 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlbp(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlbp")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21293 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpEret<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpEret(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "eret")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21310 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpWait<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21318 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpWait(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "wait")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21330 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSync_p<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21338 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSync_p(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21342 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sync_p")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21350 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21353 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpPause<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpPause(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "pause")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAdd_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAdd_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "add_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21393 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAdd_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21401 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAdd_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "add_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSub_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21424 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSub_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21428 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sub_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21439 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21442 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSub_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21447 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSub_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sub_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21462 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMul_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMul_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mul_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMul_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMul_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21497 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mul_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21508 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDiv_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDiv_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21520 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "div_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDiv_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDiv_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "div_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21554 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21562 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSqrt_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sqrt_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21576 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSqrt_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21588 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sqrt_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21598 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAbs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21606 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAbs_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21610 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "abs_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21620 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21623 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAbs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAbs_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "abs_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21642 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMov_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21650 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMov_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21654 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mov_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMov_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21672 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMov_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21676 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mov_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21686 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21689 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpNeg_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpNeg_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21698 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "neg_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21708 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21711 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpNeg_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21716 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpNeg_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21720 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "neg_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21730 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRound_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21738 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRound_l_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21742 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "round_l_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21752 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21755 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRound_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21760 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRound_l_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "round_l_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTrunc_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTrunc_l_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "trunc_l_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTrunc_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21804 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTrunc_l_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21808 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "trunc_l_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCeil_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCeil_l_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21830 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ceil_l_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCeil_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21848 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCeil_l_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21852 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ceil_l_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21862 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpFloor_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21870 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpFloor_l_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21874 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "floor_l_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpFloor_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpFloor_l_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21896 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "floor_l_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21906 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRound_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21914 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRound_w_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21918 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "round_w_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21928 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21931 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRound_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21936 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRound_w_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "round_w_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTrunc_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21958 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTrunc_w_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21962 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "trunc_w_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21972 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTrunc_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21980 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTrunc_w_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21984 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "trunc_w_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 21994 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 21997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCeil_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCeil_w_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ceil_w_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCeil_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCeil_w_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ceil_w_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpFloor_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpFloor_w_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22050 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "floor_w_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22060 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22063 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpFloor_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22068 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpFloor_w_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22072 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "floor_w_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_d_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22090 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_d_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22094 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_d_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_s_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22112 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_s_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22116 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_s_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22134 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_w_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22138 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_w_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22148 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22156 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_w_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22160 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_w_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_l_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_l_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22200 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_l_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22204 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_l_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22217 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22222 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22226 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c_s")
{
	cond = uint8_t(code & 0xf);
	cc = uint8_t((code >> 8) & 0x7);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c_d")
{
	cond = uint8_t(code & 0xf);
	cc = uint8_t((code >> 8) & 0x7);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22262 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCabs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22270 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCabs_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22274 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cabs_s")
{
	cond = uint8_t(code & 0xf);
	cc = uint8_t((code >> 8) & 0x7);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22289 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCabs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22294 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCabs_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cabs_d")
{
	cond = uint8_t(code & 0xf);
	cc = uint8_t((code >> 8) & 0x7);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22310 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovf_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22318 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovf_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movf_s")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22333 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovf_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22341 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovf_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movf_d")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22356 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovt_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22368 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movt_s")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22379 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovt_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22391 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movt_d")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22402 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovz_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22410 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovz_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22414 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movz_s")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22428 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovz_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovz_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22437 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movz_d")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22448 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22451 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovn_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22456 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovn_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movn_s")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22474 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovn_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovn_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22483 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movn_d")
{
	fd = uint8_t((code >> 6) & 0x1f);
	fs = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22494 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22497 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22506 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22519 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22524 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22528 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22541 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22546 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip1_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22550 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip1_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22560 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22563 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22568 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip1_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22572 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip1_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22582 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22585 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22594 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22604 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22607 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22612 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22616 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22626 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt1_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22638 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt1_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22648 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt1_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22660 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt1_d")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22670 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22673 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip2_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip2_s")
{
	rd = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22693 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRecip2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRecip2_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "recip2_d")
{
	rd = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22716 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22719 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt2_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt2_s")
{
	rd = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22739 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22742 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRsqrt2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22747 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRsqrt2_d(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rsqrt2_d")
{
	rd = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22762 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCvt_ps_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22770 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCvt_ps_s(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cvt_ps_s")
{
	rc = uint8_t((code >> 6) & 0x1f);
	rb = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22785 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovf<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22793 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovf(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movf")
{
	rd = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22808 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22811 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22816 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovt(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22820 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movt")
{
	rd = uint8_t((code >> 11) & 0x1f);
	cc = uint8_t((code >> 18) & 0x7);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22831 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22834 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22839 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovz(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movz")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMovn<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22862 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMovn(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "movn")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22880 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLsa<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLsa(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lsa")
{
	i = uint8_t((code >> 6) & 0x3);
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22901 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22904 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRorv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRorv(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22913 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rorv")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22924 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22927 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRor(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22936 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ror")
{
	sa = uint8_t((code >> 6) & 0x1f);
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22947 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22950 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMflhxu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMflhxu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22959 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mflhxu")
{
	rc = uint8_t((code >> 11) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22968 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtlhx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22976 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtlhx(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22980 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtlhx")
{
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 22989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 22997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJr_hb(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jr_hb")
{
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23010 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJalr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23018 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJalr_hb(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23022 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jalr_hb")
{
	rc = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23035 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMultp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23040 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMultp(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23044 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "multp")
{
	rb = uint8_t((code >> 16) & 0x1f);
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23054 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23057 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAclr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23062 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAclr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23066 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "aclr")
{
	offset = ((int16_t)((code & 0xfff) << 4) >> 4);
	imm = uint8_t((code >> 12) & 0x7);
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23077 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23080 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAset<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAset(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23089 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "aset")
{
	offset = ((int16_t)((code & 0xfff) << 4) >> 4);
	imm = uint8_t((code >> 12) & 0x7);
	ra = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23103 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBposge32<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23108 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBposge32(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23112 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bposge32")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23121 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23124 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpRdhwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpRdhwr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "rdhwr")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpClz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpClz(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23155 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "clz")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23166 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23169 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "di")
{
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23190 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpExt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpExt(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ext")
{
	lsb = uint8_t((code >> 6) & 0x1f);
	msbd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23211 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpIns<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23219 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpIns(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ins")
{
	lsb = uint8_t((code >> 6) & 0x1f);
	msb = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMaddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23243 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMaddu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23247 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "maddu")
{
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23257 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMul<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23265 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMul(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mul")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23280 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23283 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSeb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23288 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSeb(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23292 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "seb")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23302 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSeh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23310 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSeh(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "seh")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23324 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJ<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJ(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "j")
{
	target = uint32_t(code & 0x3ffffff) << 2;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23348 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJal<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23353 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJal(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23357 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jal")
{
	target = uint32_t(code & 0x3ffffff) << 2;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23366 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23369 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpNop<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23374 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpNop(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "nop")
{
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23386 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23389 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSrl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23394 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSrl(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23398 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "srl")
{
	imm = uint8_t((code >> 6) & 0x1f);
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23409 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSra<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSra(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sra")
{
	imm = uint8_t((code >> 6) & 0x1f);
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23432 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSllv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSllv(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sllv")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23455 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23458 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSrlv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23463 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSrlv(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "srlv")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23478 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23481 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSrav<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23486 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSrav(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23490 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "srav")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jr")
{
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJalr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJalr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jalr")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23544 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSyscall<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSyscall(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "syscall")
{
	imm = uint32_t((code >> 6) & 0xfffff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23568 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBreak<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23573 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBreak(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23577 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "break")
{
	imm2 = uint16_t((code >> 6) & 0x3ff);
	imm1 = uint16_t((code >> 16) & 0x3ff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMfhi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23595 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMfhi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23599 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mfhi")
{
	rd = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 21) & 0x3);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23609 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23612 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMthi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23617 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMthi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mthi")
{
	ra = uint8_t((code >> 11) & 0x3);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23631 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23634 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMflo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23639 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMflo(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23643 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mflo")
{
	rd = uint8_t((code >> 11) & 0x1f);
	ra = uint8_t((code >> 21) & 0x3);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23653 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtlo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23661 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtlo(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtlo")
{
	ra = uint8_t((code >> 11) & 0x3);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23675 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMult<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMult(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mult")
{
	ra = uint8_t((code >> 11) & 0x3);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23698 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMultu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23706 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMultu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23710 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "multu")
{
	ra = uint8_t((code >> 11) & 0x3);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23721 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23724 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDiv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23729 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDiv(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "div")
{
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23743 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDivu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDivu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23755 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "divu")
{
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23765 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23768 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAdd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23773 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAdd(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "add")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23788 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23791 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23796 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAddu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "addu")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23811 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23814 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSub<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23819 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSub(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23823 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sub")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23834 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23837 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSubu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23842 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSubu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "subu")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23860 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAnd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAnd(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23869 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "and")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23880 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23883 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpOr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23888 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpOr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23892 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "or")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23906 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpXor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23911 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpXor(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23915 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "xor")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpNor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpNor(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23938 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "nor")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23949 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBltz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBltz(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bltz")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	l = uint8_t((code >> 17) & 0x1);
	al = uint8_t((code >> 20) & 0x1);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23973 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23976 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBgez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBgez(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 23985 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bgez")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	l = uint8_t((code >> 17) & 0x1);
	al = uint8_t((code >> 20) & 0x1);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 23997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24000 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBlez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBlez(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "blez")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	rs = uint8_t((code >> 21) & 0x1f);
	l = uint8_t((code >> 30) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24023 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBgtz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBgtz(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bgtz")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	rs = uint8_t((code >> 21) & 0x1f);
	l = uint8_t((code >> 30) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBeq(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24055 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "beq")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
	l = uint8_t((code >> 30) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24067 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBne(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bne")
{
	offset = ((int32_t)((code & 0xffff) << 16) >> 16) << 2;
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
	l = uint8_t((code >> 30) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24091 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24094 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTge<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24099 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTge(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24103 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tge")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24114 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24117 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTgeu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTgeu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24126 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tgeu")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlt(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24149 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlt")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24160 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24168 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTltu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24172 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tltu")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24183 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24186 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24191 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTeq(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "teq")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTne(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tne")
{
	imm = uint16_t((code >> 6) & 0x3ff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24229 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTgei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTgei(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tgei")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTgeiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTgeiu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24263 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tgeiu")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24276 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTlti(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tlti")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24298 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24303 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTltiu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tltiu")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24320 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTeqi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24325 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTeqi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "teqi")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24342 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpTnei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24347 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpTnei(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "tnei")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24361 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24364 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAddi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24369 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAddi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "addi")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24384 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24387 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAddiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAddiu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24396 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "addiu")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24410 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24415 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSlt(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24419 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "slt")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24430 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24433 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24438 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSlti(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24442 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "slti")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24456 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24461 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSltu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sltu")
{
	rd = uint8_t((code >> 11) & 0x1f);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24476 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24484 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSltiu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sltiu")
{
	imm = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24499 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpAndi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpAndi(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "andi")
{
	imm = uint16_t(code & 0xffff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24522 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpOri<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpOri(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ori")
{
	imm = uint16_t(code & 0xffff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24548 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpXori<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24553 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpXori(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "xori")
{
	imm = uint16_t(code & 0xffff);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24568 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24571 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLui<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24576 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLui(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24580 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lui")
{
	imm = uint16_t(code & 0xffff);
	rt = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24590 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24598 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLb(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24602 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lb")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24616 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLbu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24621 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLbu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24625 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lbu")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24639 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24644 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLh(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24648 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lh")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24662 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLhu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24667 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLhu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24671 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lhu")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24685 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24690 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLw(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24694 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lw")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24708 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24713 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwu(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24717 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwu")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSb(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sb")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSh(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24763 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sh")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSw(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sw")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24805 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLl(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ll")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24820 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24823 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSc<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24828 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSc(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24832 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sc")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24846 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24851 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMfc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24855 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mfc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24865 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24868 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24873 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmfc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24877 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmfc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24887 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24895 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCfc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24899 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cfc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24912 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24931 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24939 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmtc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmtc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCtc0(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ctc0")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24978 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc0f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc0f(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 24987 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc0f")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 24997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25000 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc0t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25005 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc0t(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc0t")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25022 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25027 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMfc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25031 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mfc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25041 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25044 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25049 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmfc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25053 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmfc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25063 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25066 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25071 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCfc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25075 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cfc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25085 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25088 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25097 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25107 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25110 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmtc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25119 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmtc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25129 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25132 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCtc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25141 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ctc1")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc1f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25159 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc1f(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc1f")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25176 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc1t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25181 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc1t(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25185 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc1t")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25195 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25198 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25207 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c2")
{
	imm = uint32_t(code & 0x1ffffff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25216 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25219 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25224 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMfc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25228 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mfc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25238 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmfc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmfc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25263 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCfc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cfc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25285 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25294 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25307 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25312 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmtc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25316 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmtc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25326 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25329 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25334 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCtc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25338 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ctc2")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25348 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25351 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc2f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25356 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc2f(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25360 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc2f")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25370 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc2t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25378 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc2t(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25382 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc2t")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25392 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpC3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25400 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpC3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "c3")
{
	imm = uint32_t(code & 0x1ffffff);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25413 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMfc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mfc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25438 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmfc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25447 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmfc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25460 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25465 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCfc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25469 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cfc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25482 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpMtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25487 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpMtc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25491 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "mtc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25501 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25504 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpDmtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25509 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpDmtc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25513 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "dmtc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25523 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25526 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25531 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCtc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25535 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ctc3")
{
	rc = uint8_t((code >> 11) & 0x1f);
	rb = uint8_t((code >> 16) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25545 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25548 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc3f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25553 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc3f(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc3f")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25567 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25570 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpBc3t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpBc3t(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "bc3t")
{
	offset = uint16_t(code & 0x3fff) << 2;
	l = uint8_t((code >> 17) & 0x1);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25589 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25592 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpJalx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpJalx(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "jalx")
{
	target = uint32_t(code & 0x3ffffff) << 2;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25610 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25613 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25618 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwl(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25622 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwl")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25636 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25645 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwr")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSwl(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "swl")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25679 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSwr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "swr")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25702 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSdl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25710 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSdl(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sdl")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25725 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSdr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25733 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSdr(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sdr")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25748 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25751 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpCache<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25756 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpCache(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25760 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "cache")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25771 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25774 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25779 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25783 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwc1")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25794 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25797 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25802 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25806 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwc2")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25820 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25825 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLwc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25829 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lwc3")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25843 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLld<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25848 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLld(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25852 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "lld")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLdc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ldc1")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25886 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25894 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLdc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25898 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ldc2")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25909 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25912 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpLdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpLdc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "ldc3")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25932 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25935 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25940 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSwc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25944 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "swc1")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25955 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25958 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25963 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSwc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25967 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "swc2")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 25978 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25981 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25986 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSwc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 25990 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "swc3")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26004 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpScd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26009 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpScd(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26013 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "scd")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26027 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26032 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSdc1(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26036 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sdc1")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26047 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26050 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26055 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSdc2(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26059 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sdc2")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26073 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
OpSdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26078 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::OpSdc3(CodeType code, uint32_t addr) : Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>(code, addr, "sdc3")
{
	offset = ((int16_t)((code & 0xffff) << 0) >> 0);
	rt = uint8_t((code >> 16) & 0x1f);
	rs = uint8_t((code >> 21) & 0x1f);
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26093 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26096 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::DecodeMapPage(uint32_t key)
{
	this->key = key;
	memset(operation, 0, sizeof(operation));
	next = 0;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26112 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26120 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::~DecodeMapPage()
{
	unsigned int idx;
	for(idx = 0; idx < NUM_OPERATIONS_PER_PAGE; idx++)
	delete operation[idx];
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26131 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26134 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26139 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::DecodeTableEntry(CodeType opcode, CodeType opcode_mask, Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26143 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *(*decode)(CodeType, uint32_t))
{
	this->opcode = opcode;
	this->opcode_mask = opcode_mask;
	this->decode = decode;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 26154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26157 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 26162 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::Decoder()
: mru_page( 0 )
{
	memset(decode_hash_table, 0, sizeof(decode_hash_table));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26170 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xfc000000UL, 0xfc000000UL, DecodeOpSdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26179 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xf8000000UL, 0xfc000000UL, DecodeOpSdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26183 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26188 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xf4000000UL, 0xfc000000UL, DecodeOpSdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26192 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26197 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xf0000000UL, 0xfc000000UL, DecodeOpScd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26201 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26206 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xec000000UL, 0xfc000000UL, DecodeOpSwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26210 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26215 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xe8000000UL, 0xfc000000UL, DecodeOpSwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26219 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26224 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xe4000000UL, 0xfc000000UL, DecodeOpSwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26228 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26233 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xdc000000UL, 0xfc000000UL, DecodeOpLdc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26237 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26242 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xd8000000UL, 0xfc000000UL, DecodeOpLdc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26246 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26251 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xd4000000UL, 0xfc000000UL, DecodeOpLdc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26255 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26260 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xd0000000UL, 0xfc000000UL, DecodeOpLld<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26264 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xcc000000UL, 0xfc000000UL, DecodeOpLwc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26273 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26278 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xc8000000UL, 0xfc000000UL, DecodeOpLwc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26282 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26287 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xc4000000UL, 0xfc000000UL, DecodeOpLwc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26291 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26296 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xbc000000UL, 0xfc000000UL, DecodeOpCache<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26300 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26305 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xb4000000UL, 0xfc000000UL, DecodeOpSdr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26309 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26314 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xb0000000UL, 0xfc000000UL, DecodeOpSdl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26318 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26323 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xb8000000UL, 0xfc000000UL, DecodeOpSwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26332 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xa8000000UL, 0xfc000000UL, DecodeOpSwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26336 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26341 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x98000000UL, 0xfc000000UL, DecodeOpLwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26345 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26350 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x88000000UL, 0xfc000000UL, DecodeOpLwl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26354 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26359 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x74000000UL, 0xfc000000UL, DecodeOpJalx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26363 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26368 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4d010000UL, 0xfffdc000UL, DecodeOpBc3t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26372 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26377 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4d000000UL, 0xfffdc000UL, DecodeOpBc3f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26386 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4cc00000UL, 0xffe007ffUL, DecodeOpCtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26390 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26395 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4ca00000UL, 0xffe007ffUL, DecodeOpDmtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26399 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26404 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4c800000UL, 0xffe007ffUL, DecodeOpMtc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26408 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26413 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4c400000UL, 0xffe007ffUL, DecodeOpCfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26417 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26422 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4c200000UL, 0xffe007ffUL, DecodeOpDmfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26426 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26431 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4c000000UL, 0xffe007ffUL, DecodeOpMfc3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26435 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26440 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4e000000UL, 0xfe000000UL, DecodeOpC3<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26444 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26449 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x49010000UL, 0xfffdc000UL, DecodeOpBc2t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26453 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26458 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x49000000UL, 0xfffdc000UL, DecodeOpBc2f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26462 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26467 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48c00000UL, 0xffe007ffUL, DecodeOpCtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26471 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26476 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48a00000UL, 0xffe007ffUL, DecodeOpDmtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26480 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26485 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48800000UL, 0xffe007ffUL, DecodeOpMtc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26489 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26494 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48400000UL, 0xffe007ffUL, DecodeOpCfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26498 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26503 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48200000UL, 0xffe007ffUL, DecodeOpDmfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26507 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26512 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x48000000UL, 0xffe007ffUL, DecodeOpMfc2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26516 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26521 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4a000000UL, 0xfe000000UL, DecodeOpC2<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26525 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26530 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x45010000UL, 0xfffdc000UL, DecodeOpBc1t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26534 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26539 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x45000000UL, 0xfffdc000UL, DecodeOpBc1f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26543 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26548 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44c00000UL, 0xffe007ffUL, DecodeOpCtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26552 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26557 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44a00000UL, 0xffe007ffUL, DecodeOpDmtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26561 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26566 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44800000UL, 0xffe007ffUL, DecodeOpMtc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26570 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26575 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44400000UL, 0xffe007ffUL, DecodeOpCfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26579 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26584 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44200000UL, 0xffe007ffUL, DecodeOpDmfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26588 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26593 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x44000000UL, 0xffe007ffUL, DecodeOpMfc1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26597 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26602 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x41010000UL, 0xfffdc000UL, DecodeOpBc0t<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26606 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26611 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x41000000UL, 0xfffdc000UL, DecodeOpBc0f<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26615 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26620 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40c00000UL, 0xffe007ffUL, DecodeOpCtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26624 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26629 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40a00000UL, 0xffe007ffUL, DecodeOpDmtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26633 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26638 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40800000UL, 0xffe007ffUL, DecodeOpMtc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26642 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26647 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40400000UL, 0xffe007ffUL, DecodeOpCfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26651 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26656 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40200000UL, 0xffe007ffUL, DecodeOpDmfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26660 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26665 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40000000UL, 0xffe007ffUL, DecodeOpMfc0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26669 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26674 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xe0000000UL, 0xfc000000UL, DecodeOpSc<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26678 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26683 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xc0000000UL, 0xfc000000UL, DecodeOpLl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26687 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26692 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xac000000UL, 0xfc000000UL, DecodeOpSw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26696 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26701 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xa4000000UL, 0xfc000000UL, DecodeOpSh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26705 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26710 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xa0000000UL, 0xfc000000UL, DecodeOpSb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26714 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26719 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x9c000000UL, 0xfc000000UL, DecodeOpLwu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26723 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26728 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x8c000000UL, 0xfc000000UL, DecodeOpLw<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26732 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26737 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x94000000UL, 0xfc000000UL, DecodeOpLhu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26741 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26746 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x84000000UL, 0xfc000000UL, DecodeOpLh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26750 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26755 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x90000000UL, 0xfc000000UL, DecodeOpLbu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26759 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26764 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x80000000UL, 0xfc000000UL, DecodeOpLb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26768 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26773 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x3c000000UL, 0xffe00000UL, DecodeOpLui<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26777 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26782 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x38000000UL, 0xfc000000UL, DecodeOpXori<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26786 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26791 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x34000000UL, 0xfc000000UL, DecodeOpOri<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26795 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26800 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x30000000UL, 0xfc000000UL, DecodeOpAndi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26804 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26809 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x2c000000UL, 0xfc000000UL, DecodeOpSltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26813 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26818 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x2bUL, 0xfc0007ffUL, DecodeOpSltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26822 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26827 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x28000000UL, 0xfc000000UL, DecodeOpSlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26831 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26836 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x2aUL, 0xfc0007ffUL, DecodeOpSlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26840 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26845 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x24000000UL, 0xfc000000UL, DecodeOpAddiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26849 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26854 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x20000000UL, 0xfc000000UL, DecodeOpAddi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26858 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26863 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40e0000UL, 0xfc1f0000UL, DecodeOpTnei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26867 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26872 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40c0000UL, 0xfc1f0000UL, DecodeOpTeqi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26876 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26881 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40b0000UL, 0xfc1f0000UL, DecodeOpTltiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26885 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26890 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40a0000UL, 0xfc1f0000UL, DecodeOpTlti<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26894 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26899 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4090000UL, 0xfc1f0000UL, DecodeOpTgeiu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26903 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26908 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4080000UL, 0xfc1f0000UL, DecodeOpTgei<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26912 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26917 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x36UL, 0xfc00003fUL, DecodeOpTne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26921 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26926 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x34UL, 0xfc00003fUL, DecodeOpTeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26930 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26935 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x33UL, 0xfc00003fUL, DecodeOpTltu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26939 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26944 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x32UL, 0xfc00003fUL, DecodeOpTlt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26948 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26953 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x31UL, 0xfc00003fUL, DecodeOpTgeu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26957 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26962 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x30UL, 0xfc00003fUL, DecodeOpTge<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26966 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26971 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x14000000UL, 0xbc000000UL, DecodeOpBne<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26975 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26980 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x10000000UL, 0xbc000000UL, DecodeOpBeq<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26984 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26989 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x1c000000UL, 0xbc1f0000UL, DecodeOpBgtz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26993 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 26998 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x18000000UL, 0xbc1f0000UL, DecodeOpBlez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27002 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27007 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4010000UL, 0xfc0d0000UL, DecodeOpBgez<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27011 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27016 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4000000UL, 0xfc0d0000UL, DecodeOpBltz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27020 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27025 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x27UL, 0xfc0007ffUL, DecodeOpNor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27029 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27034 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x26UL, 0xfc0007ffUL, DecodeOpXor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27038 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27043 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x25UL, 0xfc0007ffUL, DecodeOpOr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27047 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27052 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x24UL, 0xfc0007ffUL, DecodeOpAnd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27056 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27061 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x23UL, 0xfc0007ffUL, DecodeOpSubu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27065 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27070 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x22UL, 0xfc0007ffUL, DecodeOpSub<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27074 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27079 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x21UL, 0xfc0007ffUL, DecodeOpAddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27083 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27088 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x20UL, 0xfc0007ffUL, DecodeOpAdd<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27092 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27097 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x1bUL, 0xfc00ffffUL, DecodeOpDivu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27101 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27106 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x1aUL, 0xfc00ffffUL, DecodeOpDiv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27110 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27115 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x19UL, 0xfc00e7ffUL, DecodeOpMultu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27119 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27124 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x18UL, 0xfc00e7ffUL, DecodeOpMult<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27128 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27133 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x13UL, 0xfc1fe7ffUL, DecodeOpMtlo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27137 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27142 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x12UL, 0xff9f07ffUL, DecodeOpMflo<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27146 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27151 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x11UL, 0xfc1fe7ffUL, DecodeOpMthi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27155 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27160 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x10UL, 0xff9f07ffUL, DecodeOpMfhi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27164 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27169 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xdUL, 0xfc00003fUL, DecodeOpBreak<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27173 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27178 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xcUL, 0xfc00003fUL, DecodeOpSyscall<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27187 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x9UL, 0xfc1f07ffUL, DecodeOpJalr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27191 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27196 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x8UL, 0xfc1fffffUL, DecodeOpJr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27200 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27205 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7UL, 0xfc0007ffUL, DecodeOpSrav<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27214 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x6UL, 0xfc0007ffUL, DecodeOpSrlv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27218 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27223 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4UL, 0xfc0007ffUL, DecodeOpSllv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27227 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x3UL, 0xffe0003fUL, DecodeOpSra<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27236 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27241 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x2UL, 0xffe0003fUL, DecodeOpSrl<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27245 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x0UL, 0xffffffffUL, DecodeOpNop<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27254 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27259 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xc000000UL, 0xfc000000UL, DecodeOpJal<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27263 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27268 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x8000000UL, 0xfc000000UL, DecodeOpJ<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27277 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7c000620UL, 0xffe007ffUL, DecodeOpSeh<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27281 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7c000420UL, 0xffe007ffUL, DecodeOpSeb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27290 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27295 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x70000002UL, 0xfc0007ffUL, DecodeOpMul<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27299 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27304 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x70000001UL, 0xfc00ffffUL, DecodeOpMaddu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27308 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27313 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7c000004UL, 0xfc00003fUL, DecodeOpIns<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27317 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7c000000UL, 0xfc00003fUL, DecodeOpExt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27326 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x41606000UL, 0xffe0ffffUL, DecodeOpDi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27335 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27340 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x70000020UL, 0xfc0007ffUL, DecodeOpClz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27344 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27349 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x7c00003bUL, 0xffe007ffUL, DecodeOpRdhwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27353 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27358 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x41c0000UL, 0xffff0000UL, DecodeOpBposge32<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27362 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27367 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4078000UL, 0xfc1f8000UL, DecodeOpAset<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27371 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27376 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4070000UL, 0xfc1f8000UL, DecodeOpAclr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27380 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27385 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x459UL, 0xfc00ffffUL, DecodeOpMultp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27389 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27394 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x409UL, 0xfc1f07ffUL, DecodeOpJalr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27398 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27403 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x408UL, 0xfc1fffffUL, DecodeOpJr_hb<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27407 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27412 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x53UL, 0xfc1fffffUL, DecodeOpMtlhx<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27416 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27421 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x52UL, 0xffff07ffUL, DecodeOpMflhxu<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27425 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27430 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x200002UL, 0xffe0003fUL, DecodeOpRor<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27434 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27439 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46UL, 0xfc0007ffUL, DecodeOpRorv<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27443 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27448 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x5UL, 0xfc00073fUL, DecodeOpLsa<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27452 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27457 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xbUL, 0xfc0007ffUL, DecodeOpMovn<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27461 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27466 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xaUL, 0xfc0007ffUL, DecodeOpMovz<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27470 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27475 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x10001UL, 0xfc0307ffUL, DecodeOpMovt<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27479 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27484 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x1UL, 0xfc0307ffUL, DecodeOpMovf<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27488 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27493 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000026UL, 0xffe0003fUL, DecodeOpCvt_ps_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27497 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27502 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620001fUL, 0xffe0003fUL, DecodeOpRsqrt2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27506 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27511 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600001fUL, 0xffe0003fUL, DecodeOpRsqrt2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27515 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27520 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620001cUL, 0xffe0003fUL, DecodeOpRecip2_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27524 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27529 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600001cUL, 0xffe0003fUL, DecodeOpRecip2_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27533 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27538 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620001eUL, 0xffff003fUL, DecodeOpRsqrt1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27542 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27547 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600001eUL, 0xffff003fUL, DecodeOpRsqrt1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27551 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27556 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200016UL, 0xffff003fUL, DecodeOpRsqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27560 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27565 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000016UL, 0xffff003fUL, DecodeOpRsqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27569 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27574 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620001dUL, 0xffff003fUL, DecodeOpRecip1_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27578 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27583 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600001dUL, 0xffff003fUL, DecodeOpRecip1_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27587 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27592 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200015UL, 0xffff003fUL, DecodeOpRecip_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27596 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27601 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000015UL, 0xffff003fUL, DecodeOpRecip_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27605 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27610 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200013UL, 0xffe0003fUL, DecodeOpMovn_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27614 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27619 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000013UL, 0xffe0003fUL, DecodeOpMovn_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27623 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27628 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200012UL, 0xffe0003fUL, DecodeOpMovz_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27632 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27637 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000012UL, 0xffe0003fUL, DecodeOpMovz_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27641 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27646 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46210011UL, 0xffe3003fUL, DecodeOpMovt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27650 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27655 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46010011UL, 0xffe3003fUL, DecodeOpMovt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27659 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27664 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200011UL, 0xffe3003fUL, DecodeOpMovf_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27668 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27673 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000011UL, 0xffe3003fUL, DecodeOpMovf_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27677 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27682 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200070UL, 0xffe000f0UL, DecodeOpCabs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27686 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27691 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000070UL, 0xffe000f0UL, DecodeOpCabs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27695 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27700 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200030UL, 0xffe000f0UL, DecodeOpC_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27704 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27709 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000030UL, 0xffe000f0UL, DecodeOpC_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27713 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27718 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200025UL, 0xffff003fUL, DecodeOpCvt_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27722 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27727 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000025UL, 0xffff003fUL, DecodeOpCvt_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27731 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27736 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200024UL, 0xffff003fUL, DecodeOpCvt_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27740 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27745 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000024UL, 0xffff003fUL, DecodeOpCvt_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27749 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27754 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200020UL, 0xffff003fUL, DecodeOpCvt_s_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27758 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27763 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000021UL, 0xffff003fUL, DecodeOpCvt_d_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27767 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27772 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000fUL, 0xffff003fUL, DecodeOpFloor_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27776 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27781 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000fUL, 0xffff003fUL, DecodeOpFloor_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27785 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27790 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000eUL, 0xffff003fUL, DecodeOpCeil_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27794 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27799 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000eUL, 0xffff003fUL, DecodeOpCeil_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27803 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27808 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000dUL, 0xffff003fUL, DecodeOpTrunc_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27812 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27817 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000dUL, 0xffff003fUL, DecodeOpTrunc_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27821 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27826 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000cUL, 0xffff003fUL, DecodeOpRound_w_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27830 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27835 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000cUL, 0xffff003fUL, DecodeOpRound_w_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27839 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27844 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000bUL, 0xffff003fUL, DecodeOpFloor_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27848 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27853 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000bUL, 0xffff003fUL, DecodeOpFloor_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27857 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27862 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4620000aUL, 0xffff003fUL, DecodeOpCeil_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27866 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27871 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x4600000aUL, 0xffff003fUL, DecodeOpCeil_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27875 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27880 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200009UL, 0xffff003fUL, DecodeOpTrunc_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27884 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27889 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000009UL, 0xffff003fUL, DecodeOpTrunc_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27893 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27898 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200008UL, 0xffff003fUL, DecodeOpRound_l_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27902 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27907 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000008UL, 0xffff003fUL, DecodeOpRound_l_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27911 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27916 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200007UL, 0xffff003fUL, DecodeOpNeg_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27920 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27925 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000007UL, 0xffff003fUL, DecodeOpNeg_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27929 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27934 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200006UL, 0xffff003fUL, DecodeOpMov_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27938 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27943 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000006UL, 0xffff003fUL, DecodeOpMov_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27947 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27952 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200005UL, 0xffff003fUL, DecodeOpAbs_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27956 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27961 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000005UL, 0xffff003fUL, DecodeOpAbs_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27965 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27970 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200004UL, 0xffff003fUL, DecodeOpSqrt_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27974 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27979 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000004UL, 0xffff003fUL, DecodeOpSqrt_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27983 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27988 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200003UL, 0xffe0003fUL, DecodeOpDiv_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27992 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 27997 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000003UL, 0xffe0003fUL, DecodeOpDiv_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28001 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28006 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200002UL, 0xffe0003fUL, DecodeOpMul_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28010 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28015 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000002UL, 0xffe0003fUL, DecodeOpMul_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28019 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28024 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200001UL, 0xffe0003fUL, DecodeOpSub_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28028 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28033 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000001UL, 0xffe0003fUL, DecodeOpSub_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28037 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28042 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46200000UL, 0xffe0003fUL, DecodeOpAdd_d<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28046 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28051 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000000UL, 0xffe0003fUL, DecodeOpAdd_s<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28055 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28060 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x140UL, 0xffffffffUL, DecodeOpPause<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28064 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	if(
#line 55 "/home/ylhuillier/Documents/Shared/Chariot/chariot-formal-decoder-armv7/mipselsec/mipselsec/./unisim/component/cxx/processor/mips/isa/special.isa"
	false
#line 28069 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	) decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28073 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x40fUL, 0xffffffffUL, DecodeOpSync_p<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28077 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28082 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000020UL, 0xffffffffUL, DecodeOpWait<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28086 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28091 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000018UL, 0xffffffffUL, DecodeOpEret<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28095 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28100 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000008UL, 0xffffffffUL, DecodeOpTlbp<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28104 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28109 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000006UL, 0xffffffffUL, DecodeOpTlbwr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28113 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28118 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000002UL, 0xffffffffUL, DecodeOpTlbwi<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28122 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28127 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000001UL, 0xffffffffUL, DecodeOpTlbr<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28131 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28136 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x46000000UL, 0xfe000000UL, DecodeOpC1<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28140 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28145 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x42000000UL, 0xfe000000UL, DecodeOpC0<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28149 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28154 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0x0UL, 0xffe0003fUL, DecodeOpSll<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28158 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
	decode_table.push_back(DecodeTableEntry<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28163 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(0xfUL, 0xfffff83fUL, DecodeOpSync<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28167 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>));
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28174 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28177 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28182 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::~Decoder()
{
	InvalidateDecodingCache();
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28191 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28194 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28199 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28203 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::NCDecode(uint32_t addr, CodeType code)
{
	Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28209 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	> *operation;
	unsigned int count = decode_table.size();
	unsigned int idx;
	for(idx = 0; idx < count; idx++)
	{
		if((code & decode_table[idx].opcode_mask) == decode_table[idx].opcode)
		{
			operation = decode_table[idx].decode(code, addr);
			return operation;
		}
	}
	operation = new Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28224 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	>(code, addr, "???");
	return operation;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28232 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28235 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
void Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28240 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::InvalidateDecodingCache()
{
	uint32_t index;
	mru_page = 0;
	for(index = 0; index < NUM_DECODE_HASH_TABLE_ENTRIES; index++)
	{
		DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
		ARCH
#line 28250 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
		> *page, *next_page;
		page = decode_hash_table[index];
		if(page)
		{
			do
			{
				next_page = page->next;
				delete page;
				page = next_page;
			} while(page);
			decode_hash_table[index] = 0;
		}
	}
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28269 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28272 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
void Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28277 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::InvalidateDecodingCacheEntry(uint32_t addr)
{
	uint32_t page_key = addr / 4 / NUM_OPERATIONS_PER_PAGE;
	if(mru_page && mru_page->key == page_key) mru_page = 0;
	uint32_t index = page_key % NUM_DECODE_HASH_TABLE_ENTRIES; // hash the key
	DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28286 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	> *prev, *cur;
	cur = decode_hash_table[index];
	if(cur)
	{
		if(cur->key == page_key)
		{
			decode_hash_table[index] = cur->next;
			delete cur;
			return;
		}
		prev = cur;
		cur = cur->next;
		if(cur)
		{
			do
			{
				if(cur->key == page_key)
				{
					prev->next = cur->next;
					cur->next = 0;
					delete cur;
					return;
				}
				prev = cur;
			} while((cur = cur->next) != 0);
		}
	}
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28319 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28322 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
inline DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28327 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28331 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::FindPage(uint32_t page_key)
{
	if(mru_page && mru_page->key == page_key) return mru_page;
	uint32_t index = page_key % NUM_DECODE_HASH_TABLE_ENTRIES; // hash the key
	DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28339 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	> *prev, *cur;
	cur = decode_hash_table[index];
	if(cur)
	{
		if(cur->key == page_key)
		{
			mru_page = cur;
			return cur;
		}
		prev = cur;
		cur = cur->next;
		if(cur)
		{
			do
			{
				if(cur->key == page_key)
				{
					prev->next = cur->next;
					cur->next= decode_hash_table[index];
					decode_hash_table[index] = cur;
					mru_page = cur;
					return cur;
				}
				prev = cur;
			} while((cur = cur->next) != 0);
		}
	}
	return 0;
}

template <
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
typename
#line 28373 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28376 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>
Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28381 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
> *Decoder<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
ARCH
#line 28385 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
>::Decode(uint32_t addr, CodeType insn)
{
	Operation<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28391 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	> *operation;
	uint32_t page_key = addr / 4 / NUM_OPERATIONS_PER_PAGE;
	DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
	ARCH
#line 28397 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
	> *page;
	page = FindPage(page_key);
	if(!page)
	{
		page = new DecodeMapPage<
#line 45 "./unisim/component/cxx/processor/mips/isa/mipsel.isa"
		ARCH
#line 28405 "./unisim/component/cxx/processor/mips/isa/mipsel.tcc"
		> (page_key);
		uint32_t index = page_key % NUM_DECODE_HASH_TABLE_ENTRIES; // hash the key
		page->next = decode_hash_table[index];
		decode_hash_table[index] = page;
		mru_page = page;
	}
	operation = page->operation[(addr / 4) & (NUM_OPERATIONS_PER_PAGE - 1)];
	if(operation)
	{
		if(operation->GetEncoding() == insn && operation->GetAddr() == addr)
		return operation;
		delete operation;
	}
	operation = NCDecode(addr, insn);
	page->operation[(addr / 4) & (NUM_OPERATIONS_PER_PAGE - 1)] = operation;
	return operation;
}

} } } } } }
