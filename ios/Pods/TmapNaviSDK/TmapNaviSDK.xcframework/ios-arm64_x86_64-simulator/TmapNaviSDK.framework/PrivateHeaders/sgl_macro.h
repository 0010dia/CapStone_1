// sgl_macro.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 라이브러리에서 공통으로 사용할 매크로 정의

#ifndef __SGL_MACRO_H
#define __SGL_MACRO_H

/////////////////////////////////////////////////////////////////////////////////////////
// 기본 매크로 정의

#ifndef _SGL_DEFINE_UNALIGNED
	#error _SGL_DEFINE_UNALIGNED is not defined.
#endif // _SGL_DEFINE_UNALIGNED

#if _SGL_DEFINE_UNALIGNED
	#define SGL_UNALIGNED		__unaligned
#else
#ifdef __ANDROID__
	#define SGL_UNALIGNED		__packed
#else
	#define SGL_UNALIGNED
#endif
#endif // _SGL_DEFINE_UNALIGNED

#ifndef _T
#ifdef _UNICODE
	#define _T(x)				L##x
#else
	#define _T(x)				x
#endif // _UNICODE
#endif // _T

#define SGL_UNUSED(a)			(a)

/////////////////////////////////////////////////////////////////////////////////////////
// 매크로 함수 정의

#define SGL_MAX(a,b)			(((a) > (b)) ? (a) : (b))
#define SGL_MIN(a,b)			(((a) < (b)) ? (a) : (b))
#define SGL_ABS(a)				(((a) > 0) ? (a) : -(a))
#define SGL_SWAP(a,b)			\
{								\
	((a) ^= (b));				\
	((b) ^= (a));				\
	((a) ^= (b));				\
}

// align <- 2^k
#define SGL_ALIGNUP(len,align)							\
	(((len) + ((align) - 1)) & ~((align) - 1))

#define SGL_UNARYMINUS(op)		(-(op))

#define SGL_ROTL32(v,b)			(((v) << (b)) | ((v) >> (32-(b))))
#define SGL_ROTR32(v,b)			(((v) >> (b)) | ((v) << (32-(b))))

#define SGL_ROTL64(v,b)			(((v) << (b)) | ((v) >> (64-(b))))
#define SGL_ROTR64(v,b)			(((v) >> (b)) | ((v) << (64-(b))))

#define SGL_BITS2BYTES(b)		(((b) + 7) >> 3)

#define SGL_KB(s)				((s) << 10)
#define SGL_MB(s)				((s) << 20)
#define SGL_GB(s)				((s) << 30)

#define SGL_HIBYTE(w)			(((w) >> 8) & 0xFF)
#define SGL_LOBYTE(w)			((w) & 0xFF)
#define SGL_HIWORD(w)			(((w) >> 16) & 0xFFFF)
#define SGL_LOWORD(w)			((w) & 0xFFFF)

/////////////////////////////////////////////////////////////////////////////////////////
// Unaligned access macro

#if _SGL_UNALIGNED_FAULT

#define SGL_UNALIGNED_READ16(Value,PtrMemory)		sgl_memcpy(&Value,PtrMemory,sizeof(UInt16))
#define SGL_UNALIGNED_WRITE16(PtrMemory,Value)		sgl_memcpy(PtrMemory,&Value,sizeof(UInt16))
#define SGL_UNALIGNED_READ32(Value,PtrMemory)		sgl_memcpy(&Value,PtrMemory,sizeof(UInt32))
#define SGL_UNALIGNED_WRITE32(PtrMemory,Value)		sgl_memcpy(PtrMemory,&Value,sizeof(UInt32))

#else

#define SGL_UNALIGNED_READ16(Value,PtrMemory)		Value = *(UInt16 SGL_UNALIGNED*)PtrMemory
#define SGL_UNALIGNED_WRITE16(PtrMemory,Value)		*(UInt16 SGL_UNALIGNED*)PtrMemory = Value
#define SGL_UNALIGNED_READ32(Value,PtrMemory)		Value = *(UInt32 SGL_UNALIGNED*)PtrMemory
#define SGL_UNALIGNED_WRITE32(PtrMemory,Value)		*(UInt32 SGL_UNALIGNED*)PtrMemory = Value

#endif // _SGL_UNALIGNED_FAULT

#endif // __SGL_MACRO_H
