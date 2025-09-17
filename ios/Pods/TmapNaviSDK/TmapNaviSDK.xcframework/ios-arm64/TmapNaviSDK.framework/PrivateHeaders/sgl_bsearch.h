// sgl_bsearch.h

// 작성자 : 정인택
// 작성일 : 2008.05.20
// 설  명 : bsearch 모듈

#ifndef __SGL_BSEARCH_H
#define __SGL_BSEARCH_H

void* SGLCALL sglBSearch(const void* pKey,const void* pBase,
	UInt nElementCount,UInt nElementSize,
	Int (SGLCALL *pfnCompare)(const void*,const void*));

#endif // __SGL_BSEARCH_H
