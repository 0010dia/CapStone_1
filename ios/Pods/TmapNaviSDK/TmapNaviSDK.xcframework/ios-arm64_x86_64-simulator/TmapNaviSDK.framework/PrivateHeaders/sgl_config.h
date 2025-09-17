// sgl_config.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 플랫폼 별 환경 설정 파일 정의

#ifndef __SGL_CONFIG_H
#define __SGL_CONFIG_H

#include "sgl_config_def.h"

#if defined(_WIN32)
	#include "./win32/sgl_config_win32.h"
#elif defined(__LINUX__) || defined(__ANDROID__)
	#include "./linux/sgl_config_linux.h"
#elif defined(__IPHONEOS__)
    #include "./linux/sgl_config_linux.h"
#elif defined(__OSX__)
    #include "./linux/sgl_config_linux.h"
#else
	#error Platform environment variable is not defined.
#endif

#if (!_SGL_SUPPORT_WIDECHARSET) && defined(_UNICODE)
	#error _UNICODE environment variable is not supported.
#endif

#endif // __SGL_CONFIG_H
