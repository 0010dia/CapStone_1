// sgl_cmntype.h

// ￀ￛﾼﾺ￀ￚ : ￁ﾤ￀ￎￅￃ
// ￀ￛﾼﾺ￀ￏ : 2008.01.14
// ﾼﾳ  ﾸ￭ : ﾰ￸ￅ￫ ￅﾸ￀ￔ ￁ﾤ￀ￇ

//#import "sgl_basetype.h"

#ifndef __SGL_CMNTYPE_H
#define __SGL_CMNTYPE_H

#if defined(_WIN32) && !defined(_WIN32_PHONE)
	typedef COPYDATASTRUCT	SGL_COPYDATASTRUCT, *PSGL_COPYDATASTRUCT;
#else
	typedef struct tagSGL_COPYDATASTRUCT
	{
	    UInt32 dwData;
	    UInt32 cbData;
	    void* lpData;
	} SGL_COPYDATASTRUCT, *PSGL_COPYDATASTRUCT;
#endif

#define SGL_BEFORE_START_POSITION		((SGL_POSITION)-1)

#define HAVE_VERTEX32
#define HAVE_RECT32
#define __SMOOTH_TURN_MAX_COUT_		100			// Spline result vertex max count

typedef UInt32	SGL_COLOR;
typedef void*	SGL_POSITION;

typedef struct tagSGL_SIZE
{
	SInt32		cx;
	SInt32		cy;
} SGL_SIZE, *PSGL_SIZE;

#ifdef HAVE_RECT32
typedef struct tagSGL_RECT
{
	SInt32		left;
	SInt32		top;
	SInt32		right;
	SInt32		bottom;
} SGL_RECT, *PSGL_RECT;

#ifndef _WIN32
#define RECT SGL_RECT
#endif

typedef struct tagSGL_RECT32
{
    SInt32	x;
	SInt32	y;
	SInt32	w;
	SInt32	h;
} RECT32, *PRECT32;

typedef struct tagSGL_RECT16
{
	SInt16	x;
	SInt16	y;
	SInt16	w;
	SInt16	h;
} RECT16, *PRECT16;
#endif

typedef struct tagSGL_RG3DATTR
{
	SInt32		z;
	SInt32		attr;
} RG_3DATTR, *PRG_3DATTR;

typedef struct tagFLOAT_VERTEX
{ 
	double	x;
	double	y; 
	float	z;
} VERTEXZ_F, *PVERTEXZ_F;

typedef struct tagSGL_VERTEXZ
{
	SInt32		x;
	SInt32		y;
	SInt32		z;
} VERTEXZ32, *PVERTEXZ32;

typedef struct tagSGL_VERTEXZ_ANGLE
{
	SInt32		x;
	SInt32		y;
	SInt32		z;
	SInt32		angle;
	SInt32		dist;
	SInt32		nTvasVertexIndex;
} VERTEXZ_ANGLE32, *PVERTEXZ_ANGLE32;

typedef struct tagDOUBLE_VERTEX
{ 
	double x;
	double y; 
} DOUBLE_VERTEX, *PDOUBLE_VERTEX;

#ifdef HAVE_VERTEX32
	typedef struct tagSGL_VERTEX
	{
		SInt32		x;
		SInt32		y;
	} VERTEX32, *PVERTEX32;

	typedef struct tagSGL_VERTEX16
	{
		UInt16		x;
		UInt16		y;
	} VERTEX16, *PVERTEX16;
#endif

// Spline result structor
typedef struct _tagSPLINE_RESULT
{
	VERTEX32	pSrcVertex[3];	// Spline source vertex
	VERTEX32	pDstVertex[__SMOOTH_TURN_MAX_COUT_];	// Spline result vertex
	SInt32		nDstVertex;								// Spline result vertex count
	SInt32		nCutLength_In;							// cut in length(center left)
	SInt32		nCutLength_Out;							// cut out length(center right)
	Float32		fLimitSlope;							// SGL_SPLINE_LIMIT_SLOPE
	Float32		fLimitCut;								// SGL_SPLINE_LIMIT_CUT
}SPLINE_RESULT, *PSPLINE_RESULT;

//#ifdef __cplusplus
//Bool sglIntersectPoint(const RECT32& srcRect, const VERTEX32& p);
//Bool sglIntersectPoint(const PSGL_RECT& srcRect, const SInt32& x, const SInt32& y);
//Bool sglIntersectPoint(const SDL_Rect& srcRect, const SInt32& x, const SInt32& y);
//
//Bool sglIntersectRect(PSGL_RECT pDestRect, const PSGL_RECT pRect1, const PSGL_RECT pRect2);
//Bool sglIntersectRect(const RECT32& srcRect, const RECT32& r);
//Bool sglIntersectRect(const RECT32& srcRect, const SDL_Rect& r);
//Bool sglIntersectRect(const SDL_Rect& srcRect, const SDL_Rect& r);
//#endif
#endif // __SGL_CMNTYPE_H
