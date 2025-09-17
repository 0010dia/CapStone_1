// sgl_const.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 라이브러리에서 공통으로 사용할 상수 정의

#ifndef _SGL_CONST_H
#define _SGL_CONST_H

/////////////////////////////////////////////////////////////////////////////////////////
// 상수 정의

#ifndef TRUE
	#define TRUE                1
#endif

#ifndef FALSE
	#define FALSE               0
#endif

#ifdef __IPHONEOS__
	#define SGL_MAX_PATH			520
#else
	#define SGL_MAX_PATH			260
#endif

#endif // _SGL_CONST_H
