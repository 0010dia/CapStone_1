// sgl_sysutil.h

#ifndef __SGL_SYSUTIL_H
#define __SGL_SYSUTIL_H

#include "sgl_base.h"

Bool sglIsExistFile(const PChar pszPath);
Bool sglDeleteFile(const PChar pszPath);
Bool sglDeleteAllFile(const PChar pszPath);
Bool sglCreateDirectory(const PChar pszPath);
Bool sglCreateDirectoryIncludeParent(const PChar pPath);
Bool sglRemoveDirectory(const PChar pszPath);
Bool sglRemoveDirectoryFilesOnly(const PChar pszPath, bool bRecursive=FALSE);
void sglMessageBox(PChar pszText, PChar pszCaption);
Bool sglMoveFile(const PChar lpszExist, const PChar lpszNew);
Bool sglRenameFile(const PChar lpszExist, const PChar lpszNew);
Bool sglCopyFile(const PChar lpszExist, const PChar lpszNew, Bool bFailIfExist);
Bool sglFindFirstFile(const PChar lpszPath, const PChar lpszWildcard, SGL_FIND_HANDLE *hFind, SGL_FIND_DATA *lpFindFileData);
Bool sglFindNextFile(SGL_FIND_HANDLE hFind, const PChar lpszWildcard, SGL_FIND_DATA *lpFindFileData);
void sglFindFileName(SGL_FIND_DATA *lpFindFileData, PChar szFileName, Int32 nFileNameLen);
Bool sglIsDir(SGL_FIND_DATA *lpFindFileData);
void sglFindClose(SGL_FIND_HANDLE hFind);
UInt32 sglGetFSize(const PChar pszPath);

#endif // __SGL_SYSUTIL_H
