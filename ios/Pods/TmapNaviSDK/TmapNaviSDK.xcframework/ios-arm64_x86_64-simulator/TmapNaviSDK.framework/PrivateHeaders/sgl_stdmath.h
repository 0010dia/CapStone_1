// sgl_stdmath.h

#ifndef __SGL_STDMATH_H
#define __SGL_STDMATH_H

#define SGL_PI							3.1415926536f
#define SGL_ANGLETORADIAN(angle)		(((angle) * SGL_PI) / 180.0f)
#define SGL_RADIANTOANGLE(radian)		(((radian) * 180.0f) / SGL_PI)

#define sgl_sin			sin
#define sgl_cos			cos
#define sgl_tan			tan
#define sgl_asin		asin
#define sgl_acos		acos
#define sgl_atan		atan
#define sgl_atan2		atan2
#define sgl_sqrt		sqrt
#define sgl_fastsqrt	fast_sqrt
#define sgl_isqrt		fast_isqrt

UInt32 fast_sqrt(const UInt32 val);
unsigned long fast_isqrt(unsigned long _n);

# define SqrtBit(k) \
t = s + (1UL << (k - 1)); t <<= k + 1; if (_n >= t) {_n -= t; s |= 1UL << k;}
#endif // __SGL_STDMATH_H
