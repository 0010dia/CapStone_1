// sgl_file_native.h

#ifndef __SGL_FILE_NATIVE_H
#define __SGL_FILE_NATIVE_H

SGL_FILE_HANDLE sglCreateFile(const PTChar lpszFileName,DWord dwFlags);
void sglCloseFile(SGL_FILE_HANDLE hFile);
UInt32 sglGetFileSize(SGL_FILE_HANDLE hFile);
Bool sglSetFilePointer(SGL_FILE_HANDLE hFile,UInt32 nOffset,UInt32 nFrom);
UInt32 sglReadFile(SGL_FILE_HANDLE hFile,void* pBuffer,UInt32 nCount);
UInt32 sglWriteFile(SGL_FILE_HANDLE hFile,const void* pBuffer,UInt32 nCount);

#endif // __SGL_FILE_NATIVE_H
