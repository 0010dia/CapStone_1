// sgl_config_linux_h

// 작성자 : 정인택
// 작성일 : 2008.05.02
// 설  명 : linux 환경 설정

#ifndef __SGL_CONFIG_LINUX_H
#define __SGL_CONFIG_LINUX_H

#include <stdio.h>
#include <stdlib.h>
#if defined(__LINUX__) && !defined(__QNXNTO__)
#include <bsd/stdlib.h>
#endif
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#ifndef __TMAP_MODE__
#include <netinet/in.h>
#include <arpa/inet.h>
#endif
#include <netdb.h>
//#include <wchar.h>
#include <time.h>

// C++ Exception or SEH(Structure Exception Handling)
#define _SGL_CPLUSPLUS_EXCEPTION		1

// Dedug Routine
#define _SGL_DEBUG_ROUTINES				0

// Host Endian Type(1 - Little-Endian, 0 - Big-Endian)
#define _SGL_HOST_LITTLE_ENDIAN			1

// Unaligned keyword 정의
#ifdef __ANDROID__
#define _SGL_DEFINE_UNALIGNED			0
#define _SGL_UNALIGNED_FAULT			1
#else
#define _SGL_DEFINE_UNALIGNED			0
#define _SGL_UNALIGNED_FAULT			0
#endif

// Wide Char 지원
#define _SGL_SUPPORT_WIDECHARSET		0

// Memory Leak 검사
#ifdef __ANDROID__
#define _SGL_CHECK_MEMORYLEAK			1
#endif

// DirectDraw 사용
#define _SGL_VIDEO_DIRECTDRAW			0

// Win-DIB 사용
#define _SGL_VIDEO_WINDIB				0

#define __cdecl

// Rendering Interface 설정

// OpenGLES를 사용함.
#define _SGL_RENDER_OPENGLES			1
// OpenGL을 사용함.
#define _SGL_RENDER_OPENGL				0
// DirextX를 사용함.
#define _SGL_RENDER_DIRECTX				0

#endif // __SGL_CONFIG_LINUX_H
