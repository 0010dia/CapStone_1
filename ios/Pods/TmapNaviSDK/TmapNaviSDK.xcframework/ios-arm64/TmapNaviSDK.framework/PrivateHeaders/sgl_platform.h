// sgl_platform.h

// 작성자 : 정인택
// 작성일 : 2008.01.07
// 설  명 : SGL(Speed Good Library) 라이브러리 common 모듈 메인 헤더

#ifndef __SGL_PLATFORM_H
#define __SGL_PLATFORM_H

#include "../src/platform/sgl_interface_platform.h"

#if defined(_WIN32) && !defined(_WIN32_PHONE)
	#include "../src/platform/win32/sgl_win32_platform.h"
#elif defined(__ANDROID__)
#elif defined(__IPHONEOS__)
#endif

#endif // __SGL_PLATFORM_H
