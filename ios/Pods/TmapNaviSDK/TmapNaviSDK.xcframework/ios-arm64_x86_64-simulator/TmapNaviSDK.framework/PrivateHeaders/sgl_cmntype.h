// sgl_cmntype.h

// 작성자 : 정인택
// 작성일 : 2008.01.14
// 설  명 : 공통 타입 정의

#ifndef __SGL_CMNTYPE_H
#define __SGL_CMNTYPE_H

#include <stdio.h>
#include <stdlib.h>
#include "common_struct.h"

#ifdef USE_SYSTEM_ZLIB
#include "zlib.h"
#else
#include "../zlib/zlib.h"
#endif

#if defined(_WIN32) && !defined(_WIN32_PHONE)
	typedef COPYDATASTRUCT	SGL_COPYDATASTRUCT, *PSGL_COPYDATASTRUCT;
#else
	typedef struct tagSGL_COPYDATASTRUCT
	{
	    DWord dwData;
	    DWord cbData;
	    void* lpData;
	} SGL_COPYDATASTRUCT, *PSGL_COPYDATASTRUCT;
#endif

#define SGL_BEFORE_START_POSITION		((SGL_POSITION)-1)

#define HAVE_RECT32
#define __SMOOTH_TURN_MAX_COUT_		100			// Spline result vertex max count

typedef UInt32	SGL_COLOR;
typedef void*	SGL_POSITION;

typedef struct tagSGL_RANGE16 
{	
	UInt16	start;
	UInt16	end;
}SGL_RANGE16, *PSGL_RANGE16;

typedef struct tagSGL_RANGE
{	
	Int32		nstart;
	Int32		nend;
}SGL_RANGE, *PSGL_RANGE;

typedef struct tagSGL_SIZE
{
	Int32		cx;
	Int32		cy;
} SGL_SIZE, *PSGL_SIZE;

#ifdef HAVE_RECT32
typedef struct tagSGL_RECT
{
	double		left;
    double		top;
    double		right;
    double		bottom;
} SGL_RECT, *PSGL_RECT;

#ifndef _WIN32
#define RECT SGL_RECT
#endif

typedef struct tagSGL_RECTF
{
	float		left;
	float		top;
	float		right;
	float		bottom;
}SGL_RECTF, *PSGL_RECTF;


typedef struct tagSGL_RECT16
{
	Int16	x;
	Int16	y;
	Int16	w;
	Int16	h;
} RECT16, *PRECT16;
#endif

typedef struct tagSGL_RG3DATTR
{
	Int32		z;
	Int32		attr;
} RG_3DATTR, *PRG_3DATTR;

typedef struct tagSGL_VERTEXZ_ANGLE
{
	double		x;
	double		y;
	double		z;
	Int32		angle;
	Int32		dist;
	Int32		nTvasVertexIndex;
} VERTEXZ_ANGLE32, *PVERTEXZ_ANGLE32;

static bool operator==(const DOUBLE_VERTEX& a1, const DOUBLE_VERTEX& a2)
{
	return (a1.x == a2.x && a1.y == a2.y);
}

static bool operator<(const DOUBLE_VERTEX& a1, const DOUBLE_VERTEX& a2)
{
	if (a1.x > a2.x)
	{
		return false;
	}
	else if (a1.x < a2.x)
	{
		return true;
	}
	else
	{
		if (a1.y > a2.y)
		{
			return false;
		}
		else if (a1.y < a2.y)
		{
			return true;
		}
	}
	return false;
}

// Spline result structor
typedef struct _tagSPLINE_RESULT
{
	DOUBLE_VERTEX	pSrcVertex[3];	// Spline source vertex
	DOUBLE_VERTEX	pDstVertex[__SMOOTH_TURN_MAX_COUT_];	// Spline result vertex
	Int32		nDstVertex;								// Spline result vertex count
	Int32		nCutLength_In;							// cut in length(center left)
	Int32		nCutLength_Out;							// cut out length(center right)
	Float		fLimitSlope;							// SGL_SPLINE_LIMIT_SLOPE
	Float		fLimitCut;								// SGL_SPLINE_LIMIT_CUT
}SPLINE_RESULT, *PSPLINE_RESULT;

#ifdef __cplusplus
Bool sglIntersectPoint(const RECT32& srcRect, const DOUBLE_VERTEX& p);
Bool sglIntersectPoint(const PSGL_RECT& srcRect, const Double& x, const Double& y);
Bool sglIntersectPointInRotatedRect(VERTEXFLOAT2* srcRect, float x, float y);

Bool sglIntersectRect(PSGL_RECT pDestRect, const PSGL_RECT pRect1, const PSGL_RECT pRect2);
Bool sglIntersectRect(const RECT32& srcRect, const RECT32& r);
Bool sglIntersectRectInRotatedRect(VERTEXFLOAT2* srcRect, SGL_RECTF* pRect);

Int32 sglInside(const DOUBLE_VERTEX &wp, const Int32 &nCount, const DOUBLE_VERTEX *pwp);
#endif	//__cplusplus

#endif // __SGL_CMNTYPE_H
