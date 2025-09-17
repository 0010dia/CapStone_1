// sgl_endian.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : Endian(Byte-Order) 매크로 정의

#ifndef __SGL_ENDIAN_H
#define __SGL_ENDIAN_H

#ifndef _SGL_HOST_LITTLE_ENDIAN
	#error _SGL_HOST_LITTLE_ENDIAN is not defined.
#endif // _SGL_HOST_LITTLE_ENDIAN

// Keyword - L(Little), B(Big), H(Host)

#define SGL_L2B16(l)							\
	( (((l) >> 8) & 0xff)						\
	| (((l) << 8) & 0xff00) )

#define SGL_L2B32(l)							\
	( (((l) >> 24) & 0xff)						\
	| (((l) >> 8)  & 0xff00)					\
	| (((l) << 8)  & 0xff0000)					\
	| (((l) << 24) & 0xff000000) )

#define SGL_L2B64(l)							\
	( (((l) >> 56) & 0xff)						\
	| (((l) >> 40) & 0xff00)					\
	| (((l) >> 24) & 0xff0000)					\
	| (((l) >> 8)  & 0xff000000)				\
	| (((l) << 8)  & 0xff00000000)				\
	| (((l) << 24) & 0xff0000000000)			\
	| (((l) << 40) & 0xff000000000000)			\
	| (((l) << 56) & 0xff00000000000000) )

#define SGL_B2L16(b)			SGL_L2B16(b)
#define SGL_B2L32(b)			SGL_L2B32(b)
#define SGL_B2L64(b)			SGL_L2B64(b)

#if _SGL_HOST_LITTLE_ENDIAN
	#define SGL_L2H16(l)		(l)
	#define SGL_B2H16(b)		SGL_B2L16(b)
	#define SGL_H2L16(h)		(h)
	#define SGL_H2B16(h)		SGL_L2B16(h)

	#define SGL_L2H32(l)		(l)
	#define SGL_B2H32(b)		SGL_B2L32(b)
	#define SGL_H2L32(h)		(h)
	#define SGL_H2B32(h)		SGL_L2B32(h)

	#define SGL_L2H64(l)		(l)
	#define SGL_B2H64(b)		SGL_B2L64(b)
	#define SGL_H2L64(h)		(h)
	#define SGL_H2B64(h)		SGL_L2B64(h)
#else
	#define SGL_L2H16(l)		SGL_L2B16(l)
	#define SGL_B2H16(b)		(b)
	#define SGL_H2L16(h)		SGL_B2L16(h)
	#define SGL_H2B16(h)		(h)

	#define SGL_L2H32(l)		SGL_L2B32(l)
	#define SGL_B2H32(b)		(b)
	#define SGL_H2L32(h)		SGL_B2L32(h)
	#define SGL_H2B32(h)		(h)

	#define SGL_L2H64(l)		SGL_L2B64(l)
	#define SGL_B2H64(b)		(b)
	#define SGL_H2L64(h)		SGL_B2L64(h)
	#define SGL_H2B64(h)		(h)
#endif // _HOST_LITTLE_ENDIAN

#endif // __SGL_ENDIAN_H
