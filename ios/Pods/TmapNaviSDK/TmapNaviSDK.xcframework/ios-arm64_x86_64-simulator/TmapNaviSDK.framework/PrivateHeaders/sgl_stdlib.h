// sgl_stdlib.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : Standard lib 재정의

#ifndef _SGL_STDLIB_H
#define _SGL_STDLIB_H

#if defined(_WIN32)
	#include "./win32/sgl_stdlib_win32.h"
#elif defined(__MACOSX__)
    #include "./linux/sgl_stdlib_linux.h"
#elif defined(_LINUX)
	#include "./linux/sgl_stdlib_linux.h"
#endif

// Memory manipulation routines

#define sgl_memcpy					memcpy
#define sgl_memmove					memmove
#define sgl_memcmp					memcmp
#define sgl_memset					memset
#define sgl_memzero(dest,size)		memset(dest,0,size)

// String manipulation routines

#define sgl_strlen					strlen
#define sgl_strcpy					strcpy
#define sgl_strncpy					strncpy
#define sgl_strlcpy                 strlcpy
#define sgl_strcmp					strcmp
#define sgl_strncmp					strncmp
#define sgl_strcat					strcat
#define sgl_strncat					strncat
#define sgl_strchr					strchr
#define sgl_strrchr					strrchr
#define sgl_strstr					strstr
#define sgl_sprintf					sprintf
#define sgl_snprintf                                    snprintf

#define sgl_atoi					atoi
#define sgl_atof					atof

#if defined(_WIN32) && !defined(_WIN32_WCE)
#define sgl_strlwr					strlwr
#else
#define sgl_strlwr					SDL_strlwr
#endif

// Unicode string routines redefinition

#ifdef _UNICODE

#define sgl_tcslen					sgl_wcslen
#define sgl_tcscpy					sgl_wcscpy
#define sgl_tcsncpy					sgl_wcsncpy
#define sgl_tcscmp					sgl_wcscmp
#define sgl_tcsncmp					sgl_wcsncmp
#define sgl_tcscat					sgl_wcscat
#define sgl_tcsncat					sgl_wcsncat
#define sgl_tcschr					sgl_wcschr
#define sgl_tcsrchr					sgl_wcsrchr
#define sgl_tcsstr					sgl_wcsstr
#define sgl_stprintf				sgl_swprintf

#define sgl_ttoi					sgl_wtoi
#define sgl_ttof					sgl_wtof

#else

#define sgl_tcslen					sgl_strlen
#define sgl_tcscpy					sgl_strcpy
#define sgl_tcsncpy					sgl_strncpy
#define sgl_tcscmp					sgl_strcmp
#define sgl_tcsncmp					sgl_strncmp
#define sgl_tcscat					sgl_strcat
#define sgl_tcsncat					sgl_strncat
#define sgl_tcschr					sgl_strchr
#define sgl_tcsrchr					sgl_strrchr
#define sgl_tcsstr					sgl_strstr
#define sgl_stprintf				sgl_sprintf

#define sgl_ttoi					sgl_atoi
#define sgl_ttof					sgl_atof

#endif // _UNICODE

// time function

#define sgl_time					time
#define sgl_localtime				localtime

#if defined(_WIN32) && !defined(_WIN32_PHONE)
	#define sgl_sleep(t)			Sleep(t)
#else
	#define sgl_sleep(t)			SDL_Delay(t)
#endif // _WIN32

// locale

#define sgl_setlocale				setlocale


// 2011.02.18 kdk
// 파일 write 체크 위해 추가.
//static char g_szSdCardPath[SGL_MAX_PATH] = {0,};
//void setSdCardPath(char* szPath)	{	sgl_strcpy(g_szSdCardPath, szPath);	}
//char* getSdCardPath()				{	return g_szSdCardPath;	}


//    #ifdef __IPHONEOS__  //hjkim
//        #define sgl_fopen					fopen_iOS
//    #else
        #define sgl_fopen					fopen
//    #endif
	#define sgl_fwrite					fwrite
	#define sgl_fclose					fclose


#endif // _SGL_STDLIB_H
