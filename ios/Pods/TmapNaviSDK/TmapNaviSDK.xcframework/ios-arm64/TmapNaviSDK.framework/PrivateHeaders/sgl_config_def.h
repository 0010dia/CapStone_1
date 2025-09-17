// sgl_config_def.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 플랫폼 별 환경 설정 파일 정의

#ifndef __SGL_CONFIG_DEF_H
#define __SGL_CONFIG_DEF_H

#if defined(_WIN32) || defined(WIN32)
	#undef WIN32
	#undef _WIN32	
	#define WIN32
	#define _WIN32
#elif defined(_LINUX) || defined(LINUX)
	#undef LINUX
	#undef _LINUX	
	#define LINUX
	#define _LINUX
#elif defined (__APPLE__)
    #undef __APPLE__
    #define __APPLE__
#elif defined(__MACOSX__)
    #undef __MACOSX__
    #define __MACOSX__
#else
	#error Platform environment variable is not defined.
#endif

#endif // __SGL_CONFIG_DEF_H
