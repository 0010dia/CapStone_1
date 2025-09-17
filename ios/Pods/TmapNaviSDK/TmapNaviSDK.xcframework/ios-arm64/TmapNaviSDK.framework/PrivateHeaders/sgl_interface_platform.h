#ifndef _sgl_interface_platform_h
#define _sgl_interface_platform_h

#include <stdio.h>
#include "sgl_base.h"
#include "sgl_begin_code.h"

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
	/* *INDENT-ON* */
#endif

/////////////////////////////////////////////////////////////
// 플래폼 지원 함수 호출
/////////////////////////////////////////////////////////////

//Native 에러코드
typedef enum
{
	NATIVE_ERROR_NOTMAPDB				= -1, //Map DB가 존재하지 않음
	NATIVE_ERROR_RESOLUTION				= -2, //화면 해상도가 맞지 않음
	NATIVE_ERROR_UNSUPPORTED_DEVICE		= -3, //지원하지 않는 단말기
}eNativeErrorCode;

//Native 메세지 코드
typedef enum
{
	NATIVE_MSG_WPCM_CONNECT			= 1,	//최초 사용자 등록(등록된 AP 연결)
	NATIVE_MSG_WPCM_DISCONNECT,				//연결 해제
	NATIVE_MSG_WPCM_EXIT,					//WPCM 종료
}eNativeMsgCode;

//폰 번호 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetPhoneNumber(char *szPhoneNumber, int nSize);
//단말기 ID 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceID(char *szDeviceID, int nSize);
//단말기 이름 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceName(char *szDeviceName, int nSize);
//네트워크 맥 어드레스 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetNetworkMacAddress(char *szNetworkMacAddress, int nSize);
//블루투스 맥 어드레스 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetBluetoothMacAddress(char *szBluetoothMacAddress, int nSize);

//단말기 루트 패스 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetRootPath(char *szPath, int nSize);

//단말기 해상도 폭 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceWidth(int *nWidth);
//단말기 해상도 높이 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetDeviceHeight(int *nHeight);

//단말기 Sound Mute 상태 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundMute(int *bMute);
//단말기 Sound 최대 볼륨값 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundMaxVolume(int *nMaxVolume);
//단말기 Sound 볼륨값 얻기
extern SGL_DECLSPEC int SGLCALL SGL_IGetSoundVolume(int *nVolume);

//단말기 Sound 볼륨값 설정
extern SGL_DECLSPEC int SGLCALL SGL_ISetSoundVolume(int nVolume, unsigned char bShowUI);

//Native Code 초기화 완료됨(이벤트 받을 준비가 끝남)
extern SGL_DECLSPEC int SGLCALL SGL_INativeInitDone();

//Native Code 에러가 발생시 알림
extern SGL_DECLSPEC int SGLCALL SGL_INativeError(eNativeErrorCode eErrorCode);

//APK 파일에 포함되어 있는 파일을 로딩한다.
extern SGL_DECLSPEC int SGLCALL SGL_ILoadAssetsFile(const char *szFileName, int *pFileDescriptor, long *pOffset, long *pLength);

//다른 Activity에 인텐트 메세지를 보낸다.
extern SGL_DECLSPEC int SGLCALL SGL_IPostMessageDevice(eNativeMsgCode eMsg);

/////////////////////////////////////////////////////////////

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif
#include "sgl_close_code.h"

#endif /* _sgl_interface_platform_h */
