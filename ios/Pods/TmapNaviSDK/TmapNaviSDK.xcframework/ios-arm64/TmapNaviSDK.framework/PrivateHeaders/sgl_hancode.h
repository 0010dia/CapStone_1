// sgl_hancode.h

#ifndef __SGL_HANCODE_H
#define __SGL_HANCODE_H

UInt16 sglKsc5601ToKssm(UInt16 ksc);
UInt16 sglKssmToKsc5601(UInt16 ksm);
Bool sglKsc5601ToKssmString(Char* pszKsc, Char* pszKssm, Int nBufferSize);
Bool sglKssmToKsc5601String(Char* pszKssm, Char* pszKsc, Int nBufferSize);

#endif // __SGL_HANCODE_H
