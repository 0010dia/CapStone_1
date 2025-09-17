// SglInterface.h
#ifndef __SGL_INTERFACE_H__
#define __SGL_INTERFACE_H__

#include "sgl_inc.h"
#include "sgl_soundbase.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

// SGL 라이브러리 버전 정보를 얻는다.
//extern float IGetVersion();

#ifdef __ANDROID__
extern void InitSoundCallback(PANDROID_SOUND_CALLBACK pSoundCallback);
#endif

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
}
#endif

#endif // __SGL_INTERFACE_H__
