// sgl_newdel.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 전역 new, delete 연산자 재정의

#ifndef __SGL_NEWDEL_H
#define __SGL_NEWDEL_H

#if !(defined(_DEBUG) && (_SGL_CHECK_MEMORYLEAK))

inline
void* __cdecl operator new(size_t size)
{
	return _sgl_malloc(size);
}

inline
void* __cdecl operator new[](size_t size)
{
	return _sgl_malloc(size);
}

inline
void __cdecl operator delete(void* ptr)
{
	_sgl_free(ptr);
}

inline
void __cdecl operator delete[](void* ptr)
{
	_sgl_free(ptr);
}

#endif // !(defined(_DEBUG) && (_SGL_CHECK_MEMORYLEAK))

#endif // __SGL_NEWDEL_H
