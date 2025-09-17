// sgl_fixed32.h

// 작성자 : 정인택
// 작성일 : 2008.01.14
// 설  명 : Fixed Point 연산

#ifndef __SGL_FIXED32_H
#define __SGL_FIXED32_H

#if !defined (__IPHONEOS__) && !defined(__ANDROID__) && !defined(_WIN32_PHONE)
    #define _SGL_NEW_FIXED32
#endif

#ifndef _SGL_NEW_FIXED32

enum
{
	SGL_FIXED32_BASE_SHIFT = 16,
	SGL_FIXED32_ROUND_VALUE = (1 << (SGL_FIXED32_BASE_SHIFT - 1)),
	SGL_FIXED32_FRACTION_MASK = 0xFFFF
};

enum
{
	SGL_FIXED1913_BASE_SHIFT = 13,
	SGL_FIXED1913_ROUND_VALUE = (1 << (SGL_FIXED1913_BASE_SHIFT - 1)),
	SGL_FIXED1913_FRACTION_MASK = 0x1FFF
};

#ifndef _DEBUG

typedef Int32	sglFixed32, *sglPFixed32;

// Internal use macro
#define _SGL_FIXED32_VALUE(fixed)				(fixed)

#define sglFixed32UnaryMinus(a)				(-(a))
#define sglFixed32IntToFixed(a)				((a) << SGL_FIXED32_BASE_SHIFT)
#define sglFixed32RealToFixed(a)			(Int32)((a) * 65536.0f)
#define sglFixed32FixedToInt(a)				((a) >> SGL_FIXED32_BASE_SHIFT)
#define sglFixed32FixedToIntRound(a)		(((a) + SGL_FIXED32_ROUND_VALUE) >> SGL_FIXED32_BASE_SHIFT)
#define sglFixed32FixedToReal(a)			((Real)(a) / 65536.0f)
#define sglFixed32Fraction(a)				((a) & SGL_FIXED32_FRACTION_MASK)
#define sglFixed32Add(a,b)					((a) + (b))
#define sglFixed32Add3(a,b,c)				((a) + (b) + (c))
#define sglFixed32Add4(a,b,c,d)				((a) + (b) + (c) + (d))
#define sglFixed32Sub(a,b)					((a) - (b))
#define sglFixed32Mul(a,b)					(Int32)(((Int64)(a) * (Int64)(b)) >> SGL_FIXED32_BASE_SHIFT)
#define sglFixed32Mul3(a,b,c)				sglFixed32Mul(sglFixed32Mul(a,b),(c))
#define sglFixed32Mul4(a,b,c,d)				sglFixed32Mul(sglFixed32Mul(sglFixed32Mul(a,b),c),(d))
#define sglFixed32Div(a,b)					(Int32)(((Int64)(a) << SGL_FIXED32_BASE_SHIFT) / (Int64)(b))
#define sglFixed32MulDiv(a,b,c)				sglFixed32Div(sglFixed32Mul(a,b),(c))
#define sglFixed32IsEqual(a,b)				((a) == (b))
#define sglFixed32IsSmall(a,b)				((a) < (b))
#define sglFixed32IsLarge(a,b)				((a) > (b))
#define sglFixed32Cmp(a,b)					(((a) > (b)) ? 1 : (((a) < (b)) ? -1 : 0))
#define sglFixed32CmpInt(a,b)				sglFixed32Cmp((a),sglFixed32IntToFixed(b))
#define sglFixed32Abs(a)					(((a) > 0) ? (a) : -(a))

// 정수부 19-bits 소수부 13-bits 연산은 음수부는 연산 불가하며 소수점 이하 세째자리까지 정밀도가 있음 Route에만 사용함
typedef UInt32	sglFixed1913, *sglPFixed1913;

#define sglFixed1913IntToFixed(a)			((a) << SGL_FIXED1913_BASE_SHIFT)
#define sglFixed1913FixedToInt(a)			((a) >> SGL_FIXED1913_BASE_SHIFT)
#define sglFixed1913RealToFixed(a)			(Int32)((a) * 8192.0f)
#define sglFixed1913FixedToReal(a)			((Real)(a) / 8192.0f)
#define sglFixed1913FixedToIntRound(a)		(((a) + SGL_FIXED1913_ROUND_VALUE) >> SGL_FIXED1913_BASE_SHIFT)
#define sglFixed1913Fraction(a)				((a) & SGL_FIXED1913_FRACTION_MASK)
#define sglFixed1913Add(a,b)				((a) + (b))
#define sglFixed1913Sub(a,b)				((a) - (b))
#define sglFixed1913Mul(a,b)				(Int32)(((Int64)(a) * (Int64)(b)) >> SGL_FIXED1913_BASE_SHIFT)
#define sglFixed1913Div(a,b)				(Int32)(((Int64)(a) << SGL_FIXED1913_BASE_SHIFT) / (Int64)(b))
#define sglFixed1913Cmp(a,b)				(((a) > (b)) ? 1 : (((a) < (b)) ? -1 : 0))
#define sglFixed1913CmpInt(a,b)				sglFixed1913Cmp(a,sglFixed1913IntToFixed(b))

#else // _DEBUG

// Built-in Data Type과 연산 시 에러 검사를 위한 디버그 전용 타입

typedef struct tag_sglFixed32
{
	Int32		_v;			// Internal use
} sglFixed32, *sglPFixed32;

// Internal use macro
#define _SGL_FIXED32_VALUE(fixed)			(fixed._v)

/////////////////////////////////////////////////////////////////////////////////////////
// 32-bits Fixed Point 연산 함수

inline
sglFixed32 sglFixed32UnaryMinus(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = -a._v;

	return fixed;
}

inline
sglFixed32 sglFixed32IntToFixed(Int32 a)
{
	sglFixed32		fixed;

	SGL_ASSERT((a >= SGL_MIN_INT16) && (a <= SGL_MAX_INT16));

	fixed._v = (a << SGL_FIXED32_BASE_SHIFT);

	return fixed;
}

inline
sglFixed32 sglFixed32RealToFixed(Real a)
{
	sglFixed32		fixed;

	fixed._v = (Int32)((a) * 65536.0f);

	return fixed;
}

inline
Int32 sglFixed32FixedToInt(sglFixed32 a)
{
	return (a._v >> SGL_FIXED32_BASE_SHIFT);
}

inline
Int32 sglFixed32FixedToIntRound(sglFixed32 a)
{
	return ((a._v + SGL_FIXED32_ROUND_VALUE) >> SGL_FIXED32_BASE_SHIFT);
}

inline
Real sglFixed32FixedToReal(sglFixed32 a)
{
	return ((Real)a._v / 65536.0f);
}

inline
sglFixed32 sglFixed32Fraction(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = a._v & SGL_FIXED32_FRACTION_MASK;

	return fixed;
}

inline
sglFixed32 sglFixed32Add(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = a._v + b._v;

	return fixed;
}

inline
sglFixed32 sglFixed32Add3(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	sglFixed32		fixed;

	fixed._v = ((a._v) + (b._v) + (c._v));

	return fixed;
}

inline
sglFixed32 sglFixed32Add4(sglFixed32 a,sglFixed32 b,sglFixed32 c,sglFixed32 d)
{
	sglFixed32		fixed;

	fixed._v = ((a._v) + (b._v) + (c._v) + (d._v));

	return fixed;
}

inline
sglFixed32 sglFixed32Sub(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v =  a._v - b._v;

	return fixed;
}

inline
sglFixed32 sglFixed32Mul(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = (Int32)(((Int64)a._v * (Int64)b._v) >> SGL_FIXED32_BASE_SHIFT);

	return fixed;
}

inline
sglFixed32 sglFixed32Mul3(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	return sglFixed32Mul(sglFixed32Mul(a,b),c);
}

inline
sglFixed32 sglFixed32Mul4(sglFixed32 a,sglFixed32 b,sglFixed32 c,sglFixed32 d)
{
	return sglFixed32Mul(sglFixed32Mul(sglFixed32Mul(a,b),c),d);
}

inline
sglFixed32 sglFixed32Div(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = (Int32)(((Int64)a._v << SGL_FIXED32_BASE_SHIFT) / (Int64)b._v);

	return fixed;
}

inline
sglFixed32 sglFixed32MulDiv(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	return sglFixed32Div(sglFixed32Mul(a,b),c);
}

inline
Bool sglFixed32IsEqual(sglFixed32 a,sglFixed32 b)
{
	return (a._v == b._v);
}

inline
Bool sglFixed32IsSmall(sglFixed32 a,sglFixed32 b)
{
	return (a._v < b._v);
}

inline
Bool sglFixed32IsLarge(sglFixed32 a,sglFixed32 b)
{
	return (a._v > b._v);
}

inline
Int32 sglFixed32Cmp(sglFixed32 a,sglFixed32 b)
{
	return ((a._v > b._v) ? 1 : ((a._v < b._v) ? -1 : 0));
}

inline
Int32 sglFixed32CmpInt(sglFixed32 a,Int32 b)
{
	return sglFixed32Cmp(a,sglFixed32IntToFixed(b));
}

inline
sglFixed32 sglFixed32Abs(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = (a._v > 0) ? a._v : -a._v;

	return fixed;
};


/////////////////////////////////////////////////////////////////////////////////////////
// 32-bits Fixed Point 연산 함수(정수 19Byte 소수부 13Byte)
//
// 정수부 19-bits 소수부 13-bits 연산은 음수부는 연산 불가하며 소수점 이하 세째자리까지 정밀도가 있음 Route에만 사용함

typedef struct tag_sglFixed1913
{
	UInt32		_v;			// Internal use
} sglFixed1913, *sglPFixed1913;

inline
sglFixed1913 sglFixed1913IntToFixed(UInt32 a)
{
	sglFixed1913		fixed;

	fixed._v = (a << SGL_FIXED1913_BASE_SHIFT);

	return fixed;
}

inline
sglFixed1913 sglFixed1913RealToFixed(Real a)
{
	sglFixed1913		fixed;

	fixed._v = (UInt32)(((a) * 8192.0f) + 0.5f);

	return fixed;
}

inline
Int32 sglFixed1913FixedToInt(sglFixed1913 a)
{
	return (a._v >> SGL_FIXED1913_BASE_SHIFT);
}

inline
Int32 sglFixed1913FixedToIntRound(sglFixed1913 a)
{
	return ((a._v + SGL_FIXED1913_ROUND_VALUE) >> SGL_FIXED1913_BASE_SHIFT);
}

inline
Real sglFixed1913FixedToReal(sglFixed1913 a)
{
	return ((Real)a._v / 8192.0f);
}

inline
sglFixed1913 sglFixed1913Fraction(sglFixed1913 a)
{
	sglFixed1913		fixed;

	fixed._v = a._v & SGL_FIXED1913_FRACTION_MASK;

	return fixed;
}

inline
sglFixed1913 sglFixed1913Add(sglFixed1913 a,sglFixed1913 b)
{
	sglFixed1913		fixed;

	fixed._v = a._v + b._v;

	return fixed;
}

inline
sglFixed1913 sglFixed1913Sub(sglFixed1913 a,sglFixed1913 b)
{
	sglFixed1913		fixed;

	fixed._v =  a._v - b._v;

	return fixed;
}

inline
sglFixed1913 sglFixed1913Mul(sglFixed1913 a,sglFixed1913 b)
{
	sglFixed1913		fixed;

	fixed._v = (UInt32)(((Int64)a._v * (Int64)b._v) >> SGL_FIXED1913_BASE_SHIFT);

	return fixed;
}

inline
sglFixed1913 sglFixed1913Div(sglFixed1913 a,sglFixed1913 b)
{
	sglFixed1913		fixed;

	fixed._v = (UInt32)(((Int64)a._v << SGL_FIXED1913_BASE_SHIFT) / (Int64)b._v);

	return fixed;
}

inline
Int32 sglFixed1913Cmp(sglFixed1913 a,sglFixed1913 b)
{
	return ((a._v > b._v) ? 1 : ((a._v < b._v) ? -1 : 0));
}

inline
Int32 sglFixed1913CmpInt(sglFixed1913 a,UInt32 b)
{
	return sglFixed1913Cmp(a,sglFixed1913IntToFixed(b));
}

#endif // _DEBUG

#ifdef _DEBUG

extern sglFixed32	_SGL_FIXED32_PI;
extern sglFixed32	_SGL_FIXED32_PI_2;

#define SGL_FIXED32_PI			_SGL_FIXED32_PI
#define SGL_FIXED32_PI_2		_SGL_FIXED32_PI_2

#define SGL_FIXED32_ZERO		sglFixed32IntToFixed(0)
#define SGL_FIXED32_ONE			sglFixed32IntToFixed(1)
#define SGL_FIXED32_MINUSONE	sglFixed32IntToFixed(-1)

#else

#define SGL_FIXED32_PI			0x0003243F
#define SGL_FIXED32_PI_2		0x0001921F

#define SGL_FIXED32_ZERO		0
#define SGL_FIXED32_ONE			0x00010000
#define SGL_FIXED32_MINUSONE	0xFFFF0000

#endif // _DEBUG

#define SGL_FIXED32_ANGLETORADIAN(angle)	\
	sglFixed32MulDiv(angle,SGL_FIXED32_PI,sglFixed32IntToFixed(180))
#define SGL_FIXED32_RADIANTOANGLE(radian)	\
	sglFixed32MulDiv(radian,sglFixed32IntToFixed(180),SGL_FIXED32_PI)

sglFixed32 sglFixed32SinDegree(sglFixed32 fpAngle);
sglFixed32 sglFixed32CosDegree(sglFixed32 fpAngle);
sglFixed32 sglFixed32Sin(sglFixed32 fpAngle);
sglFixed32 sglFixed32Cos(sglFixed32 fpAngle);
sglFixed32 sglFixed32Sqrt(sglFixed32 fpValue);
sglFixed32 sglFixed32ASin(sglFixed32 fpValue);
sglFixed32 sglFixed32ACos(sglFixed32 fpValue);

#else // _SGL_NEW_FIXED32

enum
{
	SGL_FIXED32_BASE_SHIFT = 16,
	SGL_FIXED32_ROUND_VALUE = (1 << (SGL_FIXED32_BASE_SHIFT - 1)),
	SGL_FIXED32_FRACTION_MASK = 0xFFFF
};

#define SGL_FIXED32_FRACTION_VALUE		65536.0f

#ifndef _DEBUG

typedef Int64	sglFixed32, *sglPFixed32;

// Internal use macro
#define _SGL_FIXED32_VALUE(fixed)			(fixed)

#define sglFixed32UnaryMinus(a)				(-(a))
#define sglFixed32IntToFixed(a)				((Int64)(a) << SGL_FIXED32_BASE_SHIFT)
#define sglFixed32RealToFixed(a)			(Int64)((a) * SGL_FIXED32_FRACTION_VALUE)
#define sglFixed32FixedToInt(a)				((Int32)((a) >> SGL_FIXED32_BASE_SHIFT))
#define sglFixed32FixedToIntRound(a)		((Int32)(((a) + SGL_FIXED32_ROUND_VALUE) >> SGL_FIXED32_BASE_SHIFT))
#define sglFixed32FixedToReal(a)			((Real)(a) / SGL_FIXED32_FRACTION_VALUE)
#define sglFixed32Fraction(a)				((a) & SGL_FIXED32_FRACTION_MASK)
#define sglFixed32Add(a,b)					((a) + (b))
#define sglFixed32Add3(a,b,c)				((a) + (b) + (c))
#define sglFixed32Add4(a,b,c,d)				((a) + (b) + (c) + (d))
#define sglFixed32Sub(a,b)					((a) - (b))
#define sglFixed32Mul(a,b)																					\
	(((((a) & SGL_FIXED32_FRACTION_MASK) * ((b) & SGL_FIXED32_FRACTION_MASK)) >> SGL_FIXED32_BASE_SHIFT)	\
	+ (((a) >> SGL_FIXED32_BASE_SHIFT) * ((b) & SGL_FIXED32_FRACTION_MASK))									\
	+ (((a) & SGL_FIXED32_FRACTION_MASK) * ((b) >> SGL_FIXED32_BASE_SHIFT))									\
	+ ((((a) >> SGL_FIXED32_BASE_SHIFT) * ((b) >> SGL_FIXED32_BASE_SHIFT)) << SGL_FIXED32_BASE_SHIFT))
#define sglFixed32Mul3(a,b,c)				sglFixed32Mul(sglFixed32Mul(a,b),(c))
#define sglFixed32Mul4(a,b,c,d)				sglFixed32Mul(sglFixed32Mul(sglFixed32Mul(a,b),c),(d))
#define sglFixed32Div(a,b)					(((a) << SGL_FIXED32_BASE_SHIFT) / (b))
#define sglFixed32MulDiv(a,b,c)				sglFixed32Div(sglFixed32Mul(a,b),(c))
#define sglFixed32IsEqual(a,b)				((a) == (b))
#define sglFixed32IsSmall(a,b)				((a) < (b))
#define sglFixed32IsLarge(a,b)				((a) > (b))
#define sglFixed32Cmp(a,b)					(((a) > (b)) ? 1 : (((a) < (b)) ? -1 : 0))
#define sglFixed32CmpInt(a,b)				sglFixed32Cmp((a),sglFixed32IntToFixed(b))
#define sglFixed32Abs(a)					(((a) > 0) ? (a) : -(a))

#else

typedef struct tag_sglFixed32
{
	Int64		_v;			// Internal use
} sglFixed32, *sglPFixed32;

// Internal use macro
#define _SGL_FIXED32_VALUE(fixed)			(fixed._v)

/////////////////////////////////////////////////////////////////////////////////////////
// 64-bits Fixed Point 연산 함수

inline
sglFixed32 sglFixed32UnaryMinus(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = -a._v;

	return fixed;
}

inline
sglFixed32 sglFixed32IntToFixed(Int32 a)
{
	sglFixed32		fixed;

	fixed._v = ((Int64)a << SGL_FIXED32_BASE_SHIFT);

	return fixed;
}

inline
sglFixed32 sglFixed32RealToFixed(Real a)
{
	sglFixed32		fixed;

	fixed._v = (Int64)((a) * SGL_FIXED32_FRACTION_VALUE);

	return fixed;
}

inline
Int32 sglFixed32FixedToInt(sglFixed32 a)
{
	return (Int32)(a._v >> SGL_FIXED32_BASE_SHIFT);
}

inline
Int32 sglFixed32FixedToIntRound(sglFixed32 a)
{
	return (Int32)((a._v + SGL_FIXED32_ROUND_VALUE) >> SGL_FIXED32_BASE_SHIFT);
}

inline
Real sglFixed32FixedToReal(sglFixed32 a)
{
	return ((Real)a._v / SGL_FIXED32_FRACTION_VALUE);
}

inline
sglFixed32 sglFixed32Fraction(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = a._v & SGL_FIXED32_FRACTION_MASK;

	return fixed;
}

inline
sglFixed32 sglFixed32Add(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = a._v + b._v;

	return fixed;
}

inline
sglFixed32 sglFixed32Add3(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	sglFixed32		fixed;

	fixed._v = ((a._v) + (b._v) + (c._v));

	return fixed;
}

inline
sglFixed32 sglFixed32Add4(sglFixed32 a,sglFixed32 b,sglFixed32 c,sglFixed32 d)
{
	sglFixed32		fixed;

	fixed._v = ((a._v) + (b._v) + (c._v) + (d._v));

	return fixed;
}

inline
sglFixed32 sglFixed32Sub(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v =  a._v - b._v;

	return fixed;
}

inline
sglFixed32 sglFixed32Mul(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = ((a._v & SGL_FIXED32_FRACTION_MASK) * (b._v & SGL_FIXED32_FRACTION_MASK)) >> SGL_FIXED32_BASE_SHIFT;
	fixed._v += (a._v >> SGL_FIXED32_BASE_SHIFT) * (b._v & SGL_FIXED32_FRACTION_MASK);
	fixed._v += (a._v & SGL_FIXED32_FRACTION_MASK) * (b._v >> SGL_FIXED32_BASE_SHIFT);
	fixed._v += ((a._v >> SGL_FIXED32_BASE_SHIFT) * (b._v >> SGL_FIXED32_BASE_SHIFT)) << SGL_FIXED32_BASE_SHIFT;

	return fixed;
}

inline
sglFixed32 sglFixed32Mul3(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	return sglFixed32Mul(sglFixed32Mul(a,b),c);
}

inline
sglFixed32 sglFixed32Mul4(sglFixed32 a,sglFixed32 b,sglFixed32 c,sglFixed32 d)
{
	return sglFixed32Mul(sglFixed32Mul(sglFixed32Mul(a,b),c),d);
}

inline
sglFixed32 sglFixed32Div(sglFixed32 a,sglFixed32 b)
{
	sglFixed32		fixed;

	fixed._v = (a._v << SGL_FIXED32_BASE_SHIFT) / b._v;

	return fixed;
}


inline
sglFixed32 sglFixed32MulDiv(sglFixed32 a,sglFixed32 b,sglFixed32 c)
{
	return sglFixed32Div(sglFixed32Mul(a,b),c);
}

inline
Bool sglFixed32IsEqual(sglFixed32 a,sglFixed32 b)
{
	return (a._v == b._v);
}

inline
Bool sglFixed32IsSmall(sglFixed32 a,sglFixed32 b)
{
	return (a._v < b._v);
}

inline
Bool sglFixed32IsLarge(sglFixed32 a,sglFixed32 b)
{
	return (a._v > b._v);
}

inline
Int32 sglFixed32Cmp(sglFixed32 a,sglFixed32 b)
{
	return ((a._v > b._v) ? 1 : ((a._v < b._v) ? -1 : 0));
}

inline
Int32 sglFixed32CmpInt(sglFixed32 a,Int32 b)
{
	return sglFixed32Cmp(a,sglFixed32IntToFixed(b));
}

inline
sglFixed32 sglFixed32Abs(sglFixed32 a)
{
	sglFixed32		fixed;

	fixed._v = (a._v > 0) ? a._v : -a._v;

	return fixed;
};

#endif // _DEBUG

#ifdef _DEBUG

extern sglFixed32	_SGL_FIXED32_PI;
extern sglFixed32	_SGL_FIXED32_PI_2;

#define SGL_FIXED32_PI			_SGL_FIXED32_PI
#define SGL_FIXED32_PI_2		_SGL_FIXED32_PI_2

#define SGL_FIXED32_ZERO		sglFixed32IntToFixed(0)
#define SGL_FIXED32_ONE			sglFixed32IntToFixed(1)
#define SGL_FIXED32_MINUSONE	sglFixed32IntToFixed(-1)

#else

#define SGL_FIXED32_PI			(Int64)(0x0003243F)
#define SGL_FIXED32_PI_2		(Int64)(0x0001921F)

#define SGL_FIXED32_ZERO		(Int64)(0)
#define SGL_FIXED32_ONE			(Int64)(65536)
#define SGL_FIXED32_MINUSONE	(Int64)(-65536)

#endif // _DEBUG

#define SGL_FIXED32_ANGLETORADIAN(angle)	\
	sglFixed32MulDiv(angle,SGL_FIXED32_PI,sglFixed32IntToFixed(180))
#define SGL_FIXED32_RADIANTOANGLE(radian)	\
	sglFixed32MulDiv(radian,sglFixed32IntToFixed(180),SGL_FIXED32_PI)

sglFixed32 sglFixed32SinDegree(sglFixed32 fpAngle);
sglFixed32 sglFixed32CosDegree(sglFixed32 fpAngle);
sglFixed32 sglFixed32Sin(sglFixed32 fpAngle);
sglFixed32 sglFixed32Cos(sglFixed32 fpAngle);
sglFixed32 sglFixed32Sqrt(sglFixed32 fpValue);
sglFixed32 sglFixed32ASin(sglFixed32 fpValue);
sglFixed32 sglFixed32ACos(sglFixed32 fpValue);

#endif // _SGL_NEW_FIXED32

#endif // __SGL_FIXED32_H
