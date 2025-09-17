// sgl_unicode.h

#ifndef __SGL_UNICODE_H
#define __SGL_UNICODE_H

#define MAX_WCHAR_UNICODE_CONVERSION_LENGTH 4

Int32 sglKsc5601ToUcs2(Int32 ksc);
UInt16 sglUcs2ToKsc5601(UInt16 ucs);
Bool sglMultiByteToWideChar(const char* pszMb,Int32* pszWc,Int nWcBufferSize);
Bool sglWideCharToMultiByte(WChar* pszWc,char* pszMb,Int nMbBufferSize);
Bool sglMultiByteToUtf8(const char* pszMb, UChar* pszWc, Int nWcBufferSize);

#endif // __SGL_UNICODE_H
