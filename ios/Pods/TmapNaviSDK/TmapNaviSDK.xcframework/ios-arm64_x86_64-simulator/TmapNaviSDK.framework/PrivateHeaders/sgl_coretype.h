// sgl_coretype.h

#ifndef __SGL_CORETYPE_H
#define __SGL_CORETYPE_H

// 작성자 : 정인택
// 작성일 : 2008.06.18
// 설  명 : 타입 정의

/////////////////////////////////////////////////////////////////////////////////////////
// 3D Box

typedef struct tagSGL3D_CLIPBOX
{
	sglFixed32		xmin;
	sglFixed32		ymin;
	sglFixed32		zmin;
	sglFixed32		xmax;
	sglFixed32		ymax;
	sglFixed32		zmax;
} SGL3D_CLIPBOX, *PSGL3D_CLIPBOX;

/////////////////////////////////////////////////////////////////////////////////////////
// 벡터 타입 정의

typedef struct tagSGL_VECTOR3
{
	union
	{
		struct 
		{
			sglFixed32		x;
			sglFixed32		y;
			sglFixed32		z;
		};
		sglFixed32			v[3];
	};
} SGL_VECTOR3, *PSGL_VECTOR3;

typedef struct tagSGL_VECTOR4
{
	union
	{
		struct 
		{
			sglFixed32		x;
			sglFixed32		y;
			sglFixed32		z;
			sglFixed32		w;
		};
		sglFixed32			v[4];
	};
} SGL_VECTOR4, *PSGL_VECTOR4;


/////////////////////////////////////////////////////////////////////////////////////////
// 행렬 타입 정의

typedef struct tagSGL_MATRIX2
{
	union
	{
		struct 
		{
			sglFixed32		m11,m12;
			sglFixed32		m21,m22;
		};
	};
	sglFixed32		m[2][2];
} SGL_MATRIX2, *PSGL_MATRIX2;

typedef struct tagSGL_MATRIX3
{
	union
	{
		struct 
		{
			sglFixed32		m11,m12,m13;
			sglFixed32		m21,m22,m23;
			sglFixed32		m31,m32,m33;
		};
	};
	sglFixed32		m[3][3];
} SGL_MATRIX3, *PSGL_MATRIX3;

typedef struct tagSGL_MATRIX4
{
	union
	{
		struct 
		{
			sglFixed32		m11,m12,m13,m14;
			sglFixed32		m21,m22,m23,m24;
			sglFixed32		m31,m32,m33,m34;
			sglFixed32		m41,m42,m43,m44;
		};
	};
	sglFixed32		m[4][4];
} SGL_MATRIX4, *PSGL_MATRIX4;

#endif // __SGL_CORETYPE_H
