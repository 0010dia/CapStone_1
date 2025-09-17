// Interface.h
#ifndef __INTERFACE_H__
#define __INTERFACE_H__

// 작성자 : 박현재
// 작성일 : 2012/03/15
// 설  명 : 네비게이션 엔진 API


// 엔진 인터페이스 에러코드
typedef enum {
    NERROR_SUCCESS = 0,
    NERROR_NAVIMODULECREATE = -1000,
    NERROR_INIT_SGL,
    NERROR_INIT_COMMON,
    NERROR_INIT_RUL_ERR,
    NERROR_INIT_DAL_ERR,
    NERROR_INIT_MAPVIEW_ERR,
    NERROR_INIT_SEARCH_ERR,
    NERROR_INIT_ROUTE_ERR,
    NERROR_INIT_RG_ERR,
    NERROR_INIT_TVAS_ERR,
    NERROR_INIT_GPSMM_ERR,
    NERROR_FOLDER_CREATE
} NAVI_ERRCODE;

#include "interface_def.h"

#ifdef __cplusplus
extern "C" {
#endif

/** START - Modified by JungJae.Lee in SKP (2014.12.04)
 *  Comment : InitEngine Status
 */
extern BOOL NF_SglInitialize(PSGL_INIT pSglInit, Bool bAsyncDBCheck, LPCALL_NAVIUPDATE_PROC pfnProc);
/**
 *  END - Modified by JungJae.Lee in SKP (2014.12.04)
 */

// NaviModule 라이브러리 버전 정보를 얻는다.
extern float IGetVersion();
extern void NF_UnlockNaviModuleMutexLock();
extern void NF_SoundInitialize(PSGL_INIT pSglInit);
extern void NF_SoundRelease();
/// SGL를 해제 한다.
/**
    @return
**/
extern Bool NF_SglUninitialize();


/// 네비게이션을 초기화 한다.
/**
    @param pNaviInit	[IN] 초기화 변수
    @return
**/
extern Bool NF_Initialize(PNAVIMODULE_INIT pNaviInit);

/// 네비게이션 내부의 API를 Utility형태로 이용하기 위한 함수
/// 내부 API의 연결을 수행한다
extern void NF_ConnectAPIFunction();

/// 네비게이션을 해제 한다.
/**
    @return
**/
extern Bool NF_Uninitialize();

/// 네비게이션 요청 함수
/**
    @param eAPI_Function		[IN] 요청 프로토콜 타입
    @param pRequest				[IN] 요청 데이터
    @param pResult				[OUT] 결과 데이터
    @return						TRUE:성공, FALSE:실패
**/
extern Bool NF_Function(eAPI_Function eFunction, PAPI_REQUEST pRequest, PAPI_RESULT pResult);

/// 마지막 에러 코드 얻는 함수
/**
    @return						TRUE:성공, FALSE:실패
**/
extern NAVI_ERRCODE NF_GetLastErrCode();


#ifdef __cplusplus
}
#endif

#endif // __INTERFACE_H__
