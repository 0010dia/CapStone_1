// sgl_init.h

// 작성자 : 정인택
// 작성일 : 2008.01.17
// 설  명 :

#ifndef __SGL_INIT_H
#define __SGL_INIT_H


#include "sgl_begin_code.h"
/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
	/* *INDENT-ON* */
#endif


#define SGL_VIRTUALMEMORY_INIT		0x00000001
#define SGL_VIDEO_INIT				0x00000002
#define SGL_AUDIO_INIT				0x00000004
#define SGL_FONT_INIT				0x00000008
#define SGL_TTFFONT_INIT			0x00000010
#define SGL_GPS_INIT				0x00000020
#define SGL_TTS_INIT				0x00000040
#define SGL_NET_INIT				0x00000080

typedef struct tagSGL_MODULEDESC
{
	DWord			dwFlags;
//	PChar			lpszRootPath;
	PChar			lpszFontPath;
	PChar			lpszTTFFontPath;
} SGL_MODULEDESC, *PSGL_MODULEDESC;

extern SGL_DECLSPEC Bool SGLCALL sglInitModule(PSGL_MODULEDESC pDesc);
extern SGL_DECLSPEC void SGLCALL sglExitModule();


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#include "sgl_close_code.h"

#endif // __SGL_INIT_H


