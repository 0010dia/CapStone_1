// sgl_vector4.h

// 작성자 : 정인택
// 작성일 : 2008.06.18
// 설  명 : Vector 연산

#ifndef __SGL_VECTOR4_H
#define __SGL_VECTOR4_H

void sglVec4Set(PSGL_VECTOR4 pv,sglFixed32 x,sglFixed32 y,sglFixed32 z,sglFixed32 w);
sglFixed32 sglVec4Length(const PSGL_VECTOR4 pv);
sglFixed32 sglVec4LengthSq(const PSGL_VECTOR4 pv);
void sglVec4Normalize(PSGL_VECTOR4 pv);
void sglVec4Scale(PSGL_VECTOR4 pv,sglFixed32 s);
void sglVec4Add(PSGL_VECTOR4 pv,const PSGL_VECTOR4 pv1,const PSGL_VECTOR4 pv2);
void sglVec4Sub(PSGL_VECTOR4 pv,const PSGL_VECTOR4 pv1,const PSGL_VECTOR4 pv2);
sglFixed32 sglVec4Dot(const PSGL_VECTOR4 pv1,const PSGL_VECTOR4 pv2);
void sglVec4Cross(PSGL_VECTOR4 pv,
	const PSGL_VECTOR4 pv1,const PSGL_VECTOR4 pv2,const PSGL_VECTOR4 pv3);

#endif // __SGL_VECTOR4_H
