// sglcharset.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : Character set 관련 매크로 정의

#ifndef __SGL_CHARSET_H
#define __SGL_CHARSET_H

#include "sgl_config.h"
#if defined(_WIN32)
	#include "./win32/sgl_charset_win32.h"
#elif defined(__MACOSX__)
    #include "./linux/sgl_charset_linux.h"
#elif defined(_LINUX)
	#include "./linux/sgl_charset_linux.h"
#endif

#if _SGL_SUPPORT_WIDECHARSET

#define SGL_W2A(lpw)											\
	(((lpw) == NULL) ? NULL										\
	: sglW2A(													\
		(char*)sgl_alloca((sgl_wcslen((lpw)) + 1) << 1),		\
		(const PWChar)(lpw),									\
		(sgl_wcslen((lpw)) + 1) << 1))

#define SGL_A2W(lpa)											\
	(((lpa) == NULL) ? NULL										\
	: sglA2W(													\
		(PWChar)sgl_alloca((sgl_strlen((lpa)) + 1) << 1),	\
		(const char*)(lpa),									\
		(sgl_strlen((lpa)) + 1) << 1))

#ifdef _UNICODE
	#define SGL_T2W(lp)				(PWChar)(lp)
	#define SGL_W2T(lp)				(PWChar)(lp)
	#define SGL_T2A					SGL_W2A
	#define SGL_A2T					SGL_A2W
#else
	#define SGL_T2W					SGL_A2W
	#define SGL_W2T					SGL_W2A
	#define SGL_T2A(lp)				(char*)(lp)
	#define SGL_A2T(lp)				(char*)(lp)
#endif // _UNICODE

#else
	#define SGL_A2W(lp)				(char*)(lp)
	#define SGL_W2A(lp)				(char*)(lp)
	#define SGL_A2T(lp)				(char*)(lp)
	#define SGL_T2A(lp)				(char*)(lp)

#endif // _SGL_SUPPORT_WIDECHAR

//한글 완성인지 체크한다.
inline
Bool __cdecl sglIsHangul(const WChar wzChr)
{
	if( wzChr < 0xD558 + 588 && wzChr >= 0xAC00)
		return TRUE;
	return FALSE;
}

//한글 초성인지 체크한다.
inline
Bool __cdecl sglIsHangulChosung(const WChar wzChr)
{
	if(wzChr <= 0x314E && wzChr >= 0x3131)
		return TRUE;
	return FALSE;
}

//숫자인지 체크한다.
inline
Bool __cdecl sglIsNumber(const WChar wzChr)
{
	if(wzChr <= 0x0039 && wzChr >= 0x0030)
		return TRUE;
	return FALSE;
}

//영문인지 체크한다.
inline
Bool __cdecl sglIsAlpha(const WChar wzChr)
{
	if((wzChr <= 0x005A && wzChr >= 0x0041) || (wzChr <= 0x007A && wzChr >= 0x0061))
		return TRUE;
	return FALSE;
}

inline
Bool __cdecl sglFindStringBetween(Char *szSrc, Int32 nSrcLen, Char cLeft, Char cRight, Char *szFindStr, Int32 nFindStrLen)
{
	Int32 nL = -1;
	Int32 nR = -1;

	for ( int i = 0; i < nSrcLen; ++i )
	{
		if ( szSrc[i] == cLeft )
		{
			nL = i;
			continue;
		}
		if ( nL < 0 )
			continue;
		if ( szSrc[i] == cRight )
		{
			nR = i;
			break;
		}
	}

	if ( nL > 0 && nR > 0 )
	{
		// 문자열 찾기 성공.
		Int32 nFindLength = nR-nL-1;
		if ( nFindStrLen < nFindLength )
			return FALSE;
		strncpy(szFindStr, szSrc+nL+1, nFindLength);
		szFindStr[nFindLength] = NULL;
		nFindStrLen = nFindLength;

		return TRUE;
	}

	return FALSE;
}


#endif // __SGL_CHARSET_H
