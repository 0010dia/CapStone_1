// sgl_debug.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 디버그 매크로 정의

#ifndef __SGL_DEBUG_H
#define __SGL_DEBUG_H

#ifndef _SGL_DEBUG_ROUTINES
	#error _SGL_DEBUG_ROUTINES is not defined.
#endif // _SGL_DEBUG_ROUTINES

#if defined(_WIN32)
	#include "./win32/sgl_debug_win32.h"
#else
	#include "./linux/sgl_debug_linux.h"
#endif

#if defined(__IPHONEOS__) || defined(__OSX__)
    #include <assert.h>
#endif

#include "vsm_log.h"

#if defined(_DEBUG) || defined(__DEBUG__) || defined(_NATIVE_DEBUG_PRINT)
    #if defined(_SGL_DEBUG_ROUTINES)

#if defined(WIN32) && defined(_UNICODE)
        #define SGL_DBGPRINT(...)           ((void)0)
#else
        #define SGL_DBGPRINT                vsm_log_debug
#endif
        #define SGL_DBGPRINT_EX             ((void)0)

        #define SGL_SETDBGPRINTID           ((void)0)
        #define SGL_GETDBGPRINTID           ((void)0)

        #ifdef _WIN32_PHONE
            #define SGL_DBGBREAK()          ((void)0)
        #elif defined(WIN32)
            #define SGL_DBGBREAK()          ((void)0) //sglDebugBreak
        #else
            #define SGL_DBGBREAK()          sglDebugBreak()
        #endif

		#ifdef __ANDROID__
			// Android debug build에서 Assert log 출력 추가(2012-12-21) : flintlock
			#define SGL_ASSERT(expr)	if(!(expr)) { vsm_log_debug("ASSERT:%s(%d)[%s]", __FILE__, __LINE__,#expr); }
		#else
			#define SGL_ASSERT(expr)		\
			{								\
				if(!(expr))					\
					SGL_DBGBREAK();			\
			}
		#endif
        #define SGL_GL_ASSERT(error)    \
        {                               \
            int error_code = error;   \
            if(error_code!=GL_NO_ERROR) \
            {                           \
                SDL_GL_ErrorLogPrint(error_code, __FILE__, __LINE__); \
            }                           \
        }                               
    #endif
#else // _DEBUG

    #ifdef _WIN32
        #define SGL_DBGPRINT			((void)0)
        #define SGL_DBGPRINT_EX			((void)0)
        #define SGL_DBGBREAK()			((void)0)
        #define SGL_ASSERT(x)			((void)0)
        #define SGL_SETDBGPRINTID(x)	((void)0)
        #define SGL_GETDBGPRINTID()		((void)0)
        #define SGL_GL_ASSERT(x)        ((void)0)
    #else
        #define SGL_DBGPRINT(...)		((void)0)
        #define SGL_DBGPRINT_EX			((void)1)
        #define SGL_DBGBREAK()			((void)0)
		#define SGL_ASSERT(x)			((void)0)
        #define SGL_SETDBGPRINTID(x)	((void)0)
        #define SGL_GETDBGPRINTID()		((void)0)
        #define SGL_GL_ASSERT(x)        ((void)0)
    #endif

#endif // _DEBUG



#endif // __SGL_DEBUG_H
