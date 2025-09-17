// sgl_matrix4.h

// 작성자 : 정인택
// 작성일 : 2008.06.19
// 설  명 : 행렬 연산

#ifndef __SGL_MATRIX4_H
#define __SGL_MATRIX4_H

void sglMatrix4Set(
	PSGL_MATRIX4 pm,
	sglFixed32 m11,sglFixed32 m12,sglFixed32 m13,sglFixed32 m14,
	sglFixed32 m21,sglFixed32 m22,sglFixed32 m23,sglFixed32 m24,
	sglFixed32 m31,sglFixed32 m32,sglFixed32 m33,sglFixed32 m34,
	sglFixed32 m41,sglFixed32 m42,sglFixed32 m43,sglFixed32 m44);
sglFixed32 sglMatrix4Determinant(const PSGL_MATRIX4 pm);
void sglMatrix4Identity(PSGL_MATRIX4 pm);
void sglMatrix4Scale(PSGL_MATRIX4 pm,sglFixed32 sx,sglFixed32 sy,sglFixed32 sz);
void sglMatrix4Add(PSGL_MATRIX4 pm,const PSGL_MATRIX4 pm1,const PSGL_MATRIX4 pm2);
void sglMatrix4Sub(PSGL_MATRIX4 pm,const PSGL_MATRIX4 pm1,const PSGL_MATRIX4 pm2);
void sglMatrix4Mul(PSGL_MATRIX4 pm,const PSGL_MATRIX4 pm1,const PSGL_MATRIX4 pm2);
void sglMatrix4Transpose(PSGL_MATRIX4 pm,const PSGL_MATRIX4 pm1);
Bool sglMatrix4Inverse(PSGL_MATRIX4 pm,const PSGL_MATRIX4 pm1);
void sglMatrix4RotationX(PSGL_MATRIX4 pm,sglFixed32 angle);
void sglMatrix4RotationY(PSGL_MATRIX4 pm,sglFixed32 angle);
void sglMatrix4RotationZ(PSGL_MATRIX4 pm,sglFixed32 angle);

#endif // __SGL_MATRIX4_H
