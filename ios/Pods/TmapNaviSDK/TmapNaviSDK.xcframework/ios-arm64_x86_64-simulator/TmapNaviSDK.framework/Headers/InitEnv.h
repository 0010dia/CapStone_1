// InitEnv.h

// 작성자 : 정인택
// 작성일 : 2008.02.04
// 설  명 : 

#ifndef __INITENV_H
#define __INITENV_H

#include <sgl_inc.h>

Bool InstanceEnv(const Char* lpszAppName, const Char* lpszOnlineMapPath, const Char* lpszCachePath,
                 const Char* lpszOfflineMapPath, const Char* lpszDataPath, const Char* lpszMdn = NULL);
void DestroyEnv();

#endif // __INITENV_H
