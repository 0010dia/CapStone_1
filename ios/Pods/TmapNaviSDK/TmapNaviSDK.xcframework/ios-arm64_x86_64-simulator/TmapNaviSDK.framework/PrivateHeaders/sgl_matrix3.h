// sgl_matrix3.h

// 작성자 : 정인택
// 작성일 : 2008.06.19
// 설  명 : 행렬 연산

#ifndef __SGL_MATRIX3_H
#define __SGL_MATRIX3_H

#define SGL_MATRIX3_DETERMINANT(pm)												\
	sglFixed32Add3(																\
		sglFixed32Mul(pm->m11,sglFixed32Sub(									\
			sglFixed32Mul(pm->m22,pm->m33),sglFixed32Mul(pm->m23,pm->m32))),	\
		sglFixed32Mul(pm->m12,sglFixed32Sub(									\
			sglFixed32Mul(pm->m23,pm->m31),sglFixed32Mul(pm->m12,pm->m23))),	\
		sglFixed32Mul(pm->m13,sglFixed32Sub(									\
			sglFixed32Mul(pm->m21,pm->m32),sglFixed32Mul(pm->m22,pm->m31))))

void sglMatrix3Set(
	PSGL_MATRIX3 pm,
	sglFixed32 m11,sglFixed32 m12,sglFixed32 m13,
	sglFixed32 m21,sglFixed32 m22,sglFixed32 m23,
	sglFixed32 m31,sglFixed32 m32,sglFixed32 m33);
sglFixed32 sglMatrix3Determinant(const PSGL_MATRIX3 pm);
void sglMatrix3Identity(PSGL_MATRIX3 pm);
void sglMatrix3Scale(PSGL_MATRIX3 pm,sglFixed32 sx,sglFixed32 sy,sglFixed32 sz);
void sglMatrix3Add(PSGL_MATRIX3 pm,const PSGL_MATRIX3 pm1,const PSGL_MATRIX3 pm2);
void sglMatrix3Sub(PSGL_MATRIX3 pm,const PSGL_MATRIX3 pm1,const PSGL_MATRIX3 pm2);
void sglMatrix3Mul(PSGL_MATRIX3 pm,const PSGL_MATRIX3 pm1,const PSGL_MATRIX3 pm2);
void sglMatrix3Transpose(PSGL_MATRIX3 pm,const PSGL_MATRIX3 pm1);
Bool sglMatrix3Inverse(PSGL_MATRIX3 pm,const PSGL_MATRIX3 pm1);
void sglMatrix3RotationX(PSGL_MATRIX3 pm,sglFixed32 angle);
void sglMatrix3RotationY(PSGL_MATRIX3 pm,sglFixed32 angle);
void sglMatrix3RotationZ(PSGL_MATRIX3 pm,sglFixed32 angle);

#endif // __SGL_MATRIX3_H
