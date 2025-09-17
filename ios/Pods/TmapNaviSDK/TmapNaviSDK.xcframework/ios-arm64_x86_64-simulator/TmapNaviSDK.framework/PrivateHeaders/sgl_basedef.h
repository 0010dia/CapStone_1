// sgl_basedef.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 라이브러리에서 공통으로 사용할 define 정의

#ifndef __SGL_BASEDEF_H
#define __SGL_BASEDEF_H

#ifndef SGLCALL
#if defined(_WIN32)
	#define SGLCALL	__cdecl
#elif defined(__cplusplus)
	#define SGLCALL
#endif
#endif // SGLCALL

#ifdef NULL
#undef NULL
#endif

#ifdef __cplusplus
	#define NULL 	0
#else
	#define NULL 	((void *)0)
#endif

#ifndef FALSE
	#define FALSE	0
#endif
#ifndef TRUE
	#define TRUE	1
#endif

#ifndef IN
	#define IN
	#define OUT
#endif

#ifdef __cplusplus
	#define BEGIN_C_NAMING_CONVENTION				\
		extern "C"									\
		{
	#define END_C_NAMING_CONVENTION					\
		}
#else
	#define BEGIN_C_NAMING_CONVENTION
	#define END_C_NAMING_CONVENTION
#endif // _cplusplus

#if defined(_MAKE_DLL)
	#define DLLAPI	__declspec(dllexport) __stdcall
#elif defined(_USE_DLL)
	#define DLLAPI	__declspec(dllimport) __stdcall
#else
	#define DLLAPI
#endif
 
#endif // __SGL_BASEDEF_H
