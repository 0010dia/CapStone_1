// sgl_vector3.h

// 작성자 : 정인택
// 작성일 : 2008.06.18
// 설  명 : Vector 연산

#ifndef __SGL_VECTOR3_H
#define __SGL_VECTOR3_H

void sglVec3Set(PSGL_VECTOR3 pv,sglFixed32 x,sglFixed32 y,sglFixed32 z);
sglFixed32 sglVec3Length(const PSGL_VECTOR3 pv);
sglFixed32 sglVec3LengthSq(const PSGL_VECTOR3 pv);
void sglVec3Normalize(PSGL_VECTOR3 pv);
void sglVec3Scale(PSGL_VECTOR3 pv,sglFixed32 s);
void sglVec3Add(PSGL_VECTOR3 pv,const PSGL_VECTOR3 pv1,const PSGL_VECTOR3 pv2);
void sglVec3Sub(PSGL_VECTOR3 pv,const PSGL_VECTOR3 pv1,const PSGL_VECTOR3 pv2);
sglFixed32 sglVec3Dot(const PSGL_VECTOR3 pv1,const PSGL_VECTOR3 pv2);
void sglVec3Cross(PSGL_VECTOR3 pv,const PSGL_VECTOR3 pv1,const PSGL_VECTOR3 pv2);

#endif // __SGL_VECTOR3_H
