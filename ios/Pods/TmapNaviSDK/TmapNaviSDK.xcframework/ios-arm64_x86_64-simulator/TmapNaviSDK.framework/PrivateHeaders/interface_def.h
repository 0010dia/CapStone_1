// interface_def.h

#ifndef __INTERFACE_DEF_H__
#define __INTERFACE_DEF_H__

#include <memory>
#include "mapengine_def.h"
#include "mapmatch_def.h"
#include "rg_def.h"
#include "rgdata_def.h"
#include "env_def.h"
#include "route_def.h"
#include "MapMatchingDebuggerInterface.h"
#include <map>

//#include "interface_map.h"

#define MAX_ROUTE_COUNT		4	//경로탐색 최대 개수
#define CTL_TICKER_STRING_LEN			256  //심플맵  문자열
#define MAX_INFO_COUNT					256	 // 임시로 설정 (20120824)
#define MAX_STATION_COUNT		256 // 주유 충전소
#define MAX_MDN_STRING_LENGTH   12
#define MAX_TOLL_GATE_LIST_LENGTH   512
#define MAX_TVAS_LINK_CNT         1000						//Link 정보 최대 수
#define MAX_TVAS_NEXT_LINK_CNT    100                        //재탐색시 Link 정보 최대 수
#define MAX_TVAS_VERTEX_CNT         5000                        //Vertex 정보 최대 수
#define MAX_TVAS_NEXT_VERTEX_CNT    100                        //재탐색시 추가 Vertex 정보 최대 수
// GPS Trace
#define REROUTE_NVX_TIME -9
#define NOT_PASSED_NVX_TIME -1

//경로 요약 정보 타입
typedef enum
{
	eSummaryType_All = 0,	// 전체
	eSummaryType_Turn,		// 턴 지점
	eSummaryType_Road,		// 도로
}E_SUMMARY_TYPE;

//TBT 정보 타입
typedef enum
{
	eTBTListType_All = 0,	// 전체
	eTBTListType_ICJCTG,	// IC, JC, TG
	eTBTListType_SA,		// 휴게소
	eTBTListType_HW			// 고속도로
}E_TBTLIST_TYPE;

//경로 요약정보
typedef struct tagRouteSummaryInfo
{
	Int32					nRouteOption;		// 경로 탐색 옵션 정보.
	stSummaryBaseInfo		stRSBaseInfo;		// 경로 탐색 요약 정보.
	UInt32					nSummaryListCount;	// 경로 요약 리스트의 갯수.
}ROUTESUMMARY_INFO;

// add. summary info & list ( Tmap 경로 요약정보 )
typedef struct tagTmapRouteSummaryInfo
{
	Int32						nRouteOption;		// 경로 탐색 옵션 정보.
	stTmapSummaryBaseInfo		stTmapRSBaseInfo;		// 경로 탐색 요약 정보.
	UInt32						nSummaryListCount;	// 경로 요약 리스트의 갯수.
	UInt8						ucRoadAttribute;		// 경로 내 도로정보
}TMAPROUTESUMMARY_INFO;

//경로 소통정보
typedef struct tagRouteTraffic
{
	UInt32			uAccDist;			// 누적거리(단위 : 1m)
	UInt16			uCong;				// 혼잡도 ('0':정보없음, '1':원할, '2':서행, '3':정체, '4':지체)
    Int32			uAccTime;			// 누적시간
}ROUTETRAFFIC;

//목적지별 소요시간
typedef struct tagRouteDestCost
{
    Int32			usEIdx;				// 종료 보간점 idx
    UInt32			uAccDist;			// 누적거리(단위 : 1m)
    Int32			uAccTime;			// 누적시간
}ROUTE_DEST_COST;


enum eRouteFlagIndex
{
	eRouteFlag_Start = 0,	// 출발지
	eRouteFlag_Via1,		// 경유 1
	eRouteFlag_Via2,		// 경유 2
	eRouteFlag_Via3,		// 경유 3
	eRouteFlag_Via4,		// 경유 4
	eRouteFlag_Via5,		// 경유 5
	eRouteFlag_Dest,		// 목적지
	eRouteFlag_Max
};

typedef enum
{
	eUpdateStatus_None = 0,	// 업데이트 없음
	eUpdateStatus_DB,		// DB 업데이트 있음
}NeUpdateStatus;


typedef struct
{
	DOUBLE_VERTEX			wpt;				//좌표
	Int32				iViewLevel0;		//화면 레벨
	Int32				iViewLevel1;		//화면 레벨
	GPSDATE				sDate;				//날짜
	GPSSATELLITEINFO	stGPSInfo;			//GPS 정보
}S_POSITIONINFO;

// 모의주행 옵션
typedef enum
{
	eSimulatorStart = 0,	//모의주행 최초 시작 (초기화 한다.)
	eSimulatorFirst,		//모의주행 시작 위치로 이동
	eSimulatorPrevGP,		//모의주행 이전 GP로 이동
	eSimulatorNextStep,		//모의주행 다음 지점으로 이동(속도값에 맞게 이동)
	eSimulatorNextGP,		//모의주행 다음 GP로 이동
	eSimulatorPos,			//모의주행 특정 위치로 이동
	eSimulatorEnd			//모의주행 종료.
}E_SIMULATOR_OPTION;

//음성 또는 TTS 플레이 상태
enum NeSoundPlay
{
	eSoundPlayStart = 0,		// 음성(or TTS) 출력 시작
	eSoundPlayStop,				// 음성(or TTS) 출력 종료
	eSoundPlayContinue,			// 음성(or TTS) 출력 종료 되었으나 출력중이 채널 있음
	eSoundEngineLoading,		// TTS 엔진 로딩
	eSoundEngineUnLoading,		// TTS 엔진 언로딩
};

// 맵매칭 정보
typedef struct tagMMDataInfo
{
	NeStatusMM		eMMState;		//맵매칭 상태
	DOUBLE_VERTEX		wp;				//현위치 좌표
	Int32			nSpeed;			//속도(GPS)
	Int32			nAngle;			//진행 방향
	UInt32			lid;			//맵매칭한 링크아이디
	UInt16			linkcate;		//맵매칭한 링크 속성
	UInt16			roadcate;		//맵매칭한 도로 종별
	Int32			angle;			//맵매칭한 링크 각도: North 기준(0도) Counterclockwise
	Int32			lengthtoend;	//wp에서 맵매칭한 링크 끝점까지 남은 거리
	Int32			idxVertex;		//wp가 n-1 과 n 번째 Vertex에 존재할경우 n	(현위치 전방에 있는 Index)
	UInt8			bIsRoute;		//링크가 경로에 있는지 여부 유:1 무:0
	UInt8			state;			//맵매칭 상태
	UInt16			usKsIdx;		//KS Index
	Bool			bReverseDrive;  //역주행 ( 역주행: 1 , 정상주행: 0)
}MMDATAINFO;

typedef struct tagSmartZoomInfo
{
	Int32	nZoomLevel;
	Bool	bZoomLevel;
	Int32	nZoomDistance;
	Bool	bZoomDistance;
	Int32	nNextRgAttribute;	// 0:시설물, 1:Turn-point
	Bool	bNextRgAttribute;
	Int32	nNextRoadAttribute;	// 0:이외도로, 1:고속/도시고속도로
	Bool	bNextRoadAttribute;
	Int32	nNextRgDistance;	// 다음 스마트줌(교차로)까지의 잔여거리 ( 단위 m ), 없는 경우는 -1
	Bool	bNextRgDistance;
	Int32	nPrevRgDistance;	// 이전 스마트줌(교차로)까지의 잔여거리 ( 단위 m ), 없는 경우는 -1
	Bool	bPrevRgDistance;
	Int32	nRgSetGpsSpeed;		// GPS speed ( 단위 km/h ), 제대로 값이 안들어오는 경우 -1
	Bool	bRgSetGpsSpeed;
	Int32	nRgSetCarPosition;	// 사용자가 화면을 터치하여 지도위치가 변경된 경우는 0, 기타의 경우 1
	Bool	bRgSetCarPosition;
}SMARTZOOMINFO;

// 속도 반응 모드
struct DriveAutoConfig
{
    int mLowSpeedMax;  // 저속 40Km 이하
    int mMiddleSpeedMax; // 중속 40Km ~ 80Km
    int mHighSpeedMax; // 고속 80Km 이상

    float mLowSpeedViewLevel_P;
    float mMiddleSpeedViewLevel_P;
    float mHighSpeedViewLevel_P;

    float mLowSpeedTiltAngle_P;
    float mMiddleSpeedTiltAngle_P;
    float mHighSpeedTiltAngle_P;

    float mLowSpeedViewLevel_L; // 가로 화면일 경우.
    float mMiddleSpeedViewLevel_L;
    float mHighSpeedViewLevel_L;

    float mLowSpeedTiltAngle_L;
    float mMiddleSpeedTiltAngle_L;
    float mHighSpeedTiltAngle_L;

    // 모든 TBT에 대해...
    int mTBTDistance1; // 근 거리
    int mTBTDistance2; // 중 거리
    int mTBTDistance3; // 원 거리

    float mTBTDistance1Level;
    float mTBTDistance2Level;
    float mTBTDistance3Level;

    float mTBTDistance1TiltAngle;
    float mTBTDistance2TiltAngle;
    float mTBTDistance3TiltAngle;

    // 방향 TBT에 대해...
    int mTBTDistance1_Turn;
    int mTBTDistance2_Turn;
    int mTBTDistance3_Turn;

    float mTBTDistance1Level_Turn;
    float mTBTDistance2Level_Turn;
    float mTBTDistance3Level_Turn;

    float mTBTDistance1TiltAngle_Turn;
    float mTBTDistance2TiltAngle_Turn;
    float mTBTDistance3TiltAngle_Turn;

    int DriveAutoType;
};

//////////////////////////////////////////////////////////////////////////
// 네비게이션 엔진 업데이트 콜백 관련
//////////////////////////////////////////////////////////////////////////

// 통신 콜백 함수
typedef Int32 (*LPCALL_PROTOCOL)(Int32 nMsg, Long lParam1, Long lParam2, LPVOID lpParam);

// 통신 콜백 메세지 종류
enum eProtocolMsg{
	PM_START,				// 통신 스레드 시작								[lParam1:통신종류, lParam2:NULL, lpParam:NULL]
	PM_PROGRESS,			// 통신 진행률                                 [lParam1:통신종류, lParam2:진행률(%), lpParam:NULL]
	PM_END,                 // 통신 스레드 완료								[lParam1:탐색종류, lParam2:에러코드, lpParam:메세지 종류의 해당 결과 구조체 포인트(통신 결과 없으면 NULL)]
};

// 엔진 업데이트 콜백 함수
typedef Int32 (*LPCALL_NAVIUPDATE_PROC)(Int32 nMsg, Long lParam1, Long lParam2, LPVOID lpParam/*lpParam는 UI메세지로 전달될때 누락된다.*/);

// 엔진 업데이트 콜백 메세지 종류
enum NeTypeNaviUpdateMsg{
	NM_UPDATE_BEGIN_ = 0x01000000,	//------------------------- 엔진 콜백 메세지 시작(수정하지 마시오) 20120722 박현재
	NM_CHANGE_MMSTATE,			// 맵매칭 상태 변경	[lParam1(NeStatusMM):MM상태, lParam2:NULL, lParam3:NULL]
// 	NM_DRAW_3DSKY,				// 3D 하늘 그리기
// 	NM_DRAW_RTM,				// RTM 그리기
// 	NM_DRAW_UTUN_ONEWAY,		// 유턴, 일방통행 지도 표시 그리기(화면 좌표로 변환된 지점 종류, 좌표 목록을 받는다.)
	NM_SEARCH_SERVER,			// 서버 Search

//	NM_CHANGE_GPSSTATE,			// GPS상태 변경		[lParam1(NeStatusGps):GPS상태, lParam2:NULL, lParam3:NULL]

	NM_MAP_DRAW,				// 맵에 추가로 그린다. [lParam1:Draw 상태, lParam2:NULL, lParam3:NULL]

	NM_UPDATE_GPS,				// GPS 좌표 업데이트	[lParam1:GPS상태(NeStatusGps), lParam2:속도, lParam3:기타정보(PUPDATE_GPS)]
	NM_UPDATE_MAPMATCH,			// 맵매칭 좌표 업데이트	[lParam1:X좌표, lParam2:Y좌표, lParam3:NULL]

	NM_ENGINE_INIT,				// 엔진 초기화 완료 [lParam1:오류 코드, lParam2:NULL, lpParam:NULL]
	NM_UPDATE_VERSION,			// 서버 버전 체크 완료 [lParam1:서버업데이트상태(NeUpdateStatus), lParam2:NULL, lParam3:NULL]

	NM_BASEDDB_START,			// DB 다운로드 시작								[lParam1:전체파일사이즈, lParam2:받은파일사이즈, lpParam:NULL]
	NM_BASEDDB_PROGRESS,		// DB 다운로드 중								[lParam1:전체파일사이즈, lParam2:받은파일사이즈, lpParam:NULL]
	NM_BASEDDB_END,				// DB 다운로드 완료								[lParam1:전체파일사이즈, lParam2:받은파일사이즈, lpParam:NULL]

	NM_SOUNDPLAY_STATUS,		// 안내 음성 출력 상태 변경						[lParam1:플레이상태(NeSoundPlay), lParam2:채널(사용자채널: -1), lpParam:NULL]

	NM_AFTER_UPDATE,			// UI가 업데이트 된 후에 알림 (NaviContainer에서 화면업데이트 후, Handler의 OnNaviUpdate() 직접 호출)

	NM_UPDATE_END_ = 0x01ffffff	//------------------------- 엔진 콜백 메세지 끝(수정하지 마시오)
};

enum NM_INIT_ENGINE_ERROR{
    E_INIT_ENGINE_SUCCESS           = 0,
    E_INIT_ENGINE_FAIL_UNKNOWN      = -1,
    E_INIT_ENGINE_FAIL_SDL          = -2,
    E_INIT_ENGINE_FAIL_MAP          = -3,
};


/** START - Modified by JungJae.Lee in SKP (2014.12.04)
 *  Comment : InitEngine Status
 */

typedef int (*LPCALL_INIT_ENGINE)(int type, int lParam, int wParam);
typedef int (*LPCALL_MAP_STATUS)(int type, int lParam, int wParam);
typedef int (*LPCALL_HIT_OBJECT)(int type, int id, double x, double y, PickedObjectProperty* property, int *show_callout);
typedef int (*LPCALL_HIT_CALLOUT_POPUP)(int type, int id, double x, double y, PickedObjectProperty* property);

typedef Bool (*LPCALL_REQUEST_ROAD_NETWORK_TILE_DATA)(UInt32 level, UInt32 tileX, UInt32 tileY, void* userData);

enum eInitEngineStatus{
    IE_INIT_ENGINE_START            = 100,		// Engine Init ﾽￃ￀ￛ
    IE_INIT_ENGINE_PROGRESS,                    // Engine Init ￁￟
    IE_INIT_ENGINE_END,                         // Engine Init ﾿ￏﾷ￡
};

enum eInitEngineResult{
    IE_RESULT_SUCCESS                          = 0,
    IE_RESULT_FAIL_APP_CONF_LOAD               = -11,
    IE_RESULT_FAIL_APP_CONF_DL_TIMEOUT         = -12,
    IE_RESULT_FAIL_APP_CONF_DL_CLIENT          = -13,
    IE_RESULT_FAIL_APP_CONF_DL_SERVER          = -14,
    IE_RESULT_FAIL_APP_CONF_DL_UNKNOWN         = -15,
    IE_RESULT_FAIL_APP_CONF_PARSING            = -16,
    IE_RESULT_FAIL_APP_CONF_CHANGE             = -17,
    
    IE_RESULT_FAIL_LAYER_CONF_DL_TIMEOUT       = -21,
    IE_RESULT_FAIL_LAYER_CONF_DL_CLIENT        = -22,
    IE_RESULT_FAIL_LAYER_CONF_DL_SERVER        = -23,
    IE_RESULT_FAIL_LAYER_CONF_DL_UNKNOWN       = -24,
    IE_RESULT_FAIL_LAYER_CONF_PARSING          = -25,
    
    IE_RESULT_FAIL_RESOURCE_CONF_DL_TIMEOUT    = -31,
    IE_RESULT_FAIL_RESOURCE_CONF_DL_CLIENT     = -32,
    IE_RESULT_FAIL_RESOURCE_CONF_DL_SERVER     = -33,
    IE_RESULT_FAIL_RESOURCE_CONF_DL_UNKNOWN    = -34,
    IE_RESULT_FAIL_RESOURCE_CONF_PARSING       = -35,
    IE_RESULT_FAIL_RESOURCE_LOAD               = -36,
    
    IE_RESULT_FAIL_STYLE_CONF_DL_TIMEOUT       = -41,
    IE_RESULT_FAIL_STYLE_CONF_DL_CLIENT        = -42,
    IE_RESULT_FAIL_STYLE_CONF_DL_SERVER        = -43,
    IE_RESULT_FAIL_STYLE_CONF_DL_UNKNOWN        = -44,
    IE_RESULT_FAIL_STYLE_CONF_PARSING           = -45,
    
    IE_RESULT_FAIL_CONFIG_UNKNOWN               = -100,
    
    IE_RESULT_FAIL_NAVI_MODULE_CREATE           = -101,
    IE_RESULT_FAIL_INIT_SGL                     = -102,
    IE_RESULT_FAIL_INIT_SDL                     = -103,
    IE_RESULT_FAIL_INIT_COMMON                  = -104,
    IE_RESULT_FAIL_INIT_DAL                     = -105,
    IE_RESULT_FAIL_INIT_MAPVIEW                 = -106,
    IE_RESULT_FAIL_INIT_RG                      = -107,
    IE_RESULT_FAIL_INIT_TVAS                    = -108,
    IE_RESULT_FAIL_INIT_GPS                     = -109,
    
    IE_RESULT_FAIL_UNKNOWN                      = -200,
};

typedef int (*LPCALL_MAP_EVENT)(int type, int lParam, int wParam);

/**
 *  END - Modified by JungJae.Lee in SKP (2014.12.04)
 */

typedef int (*LPCALL_RESOURCE_LOADING)(int type, int lParam, int wParam);

enum eResourceLoadingStatus{
    RE_RESOURCE_LOADING_START            = 100,
    RE_RESOURCE_LOADING_PROGRESS,
    RE_RESOURCE_LOADING_END,
};

enum eResourceLoadingResult{
    RE_RESULT_SUCCESS           = 0,
    RE_RESULT_FAIL_LOAD         = -1,
};

typedef int (*LPCALL_MULTIPLE_TILE_DOWNLOAD_STATUS_CALLBACK)(int type, int lParam, int wParam);

enum eMultipleTileDownloadStatus {
    eMultipleTileDownloadStart            = 200,
    eMultipleTileDownloadProgress,
    eMultipleTileDownloadFinish,
    eMultipleTileDownloadFail
};

typedef int (*LPCALL_MULTIPLE_TILE_DOWNLOAD_ERROR_CALLBACK)(int errorStatus, char* errorUrl);

typedef int (*LPCALL_EMBEDDEDMAP_DOWNLOAD_STATUS_CALLBACK)(int type, const Char* currentLayerName, int currentFileProgress, int currentFileOriginal, int totalProgress, int totalOriginal, int currentIndex, int totalIndex);

enum eEmbeddedMapDownloadStatus {
    eEmbeddedMapDownloadStarted           = 300,
    eEmbeddedMapDownloadStopped,
    eEmbeddedMapDownloadProgress,
    eEmbeddedMapDownloadFinished,
    eEmbeddedMapDownloadFailed,
    eEmbeddedMapDownloadChecked
};

enum eResourceLoaderAction {
    eResoureLoaderActionBaseStarted     = 1000,
    eResoureLoaderActionBaseProgress    = 1001,
    eResoureLoaderActionBaseProgressSize= 1002,
    eResoureLoaderActionBaseCompleted   = 1003,
    eResoureLoaderActionBaseFailed      = 1004,
    eResoureLoaderActionBaseConfirm     = 1005,

    eResoureLoaderActionSubStarted      = 2000,
    eResoureLoaderActionSubProgress     = 2001,
    eResoureLoaderActionSubProgressSize = 2002,
    eResoureLoaderActionSubCompleted    = 2003,
    eResoureLoaderActionSubFailed       = 2004,
};

typedef void (*LPCALL_RESOURCE_LOADER_CALLBACK)(int action, int arg1, int arg2);

enum eUserResourceLoaderAction {
    eResoureLoaderActionUserStarted     = 3000,
    eResoureLoaderActionUserProgress    = 3001,
    eResoureLoaderActionUserProgressSize= 3002,
    eResoureLoaderActionUserCompleted   = 3003,
    eResoureLoaderActionUserFailed      = 3004
};

typedef void (*LPCALL_USER_RESOURCE_LOADER_CALLBACK)(int action, int arg1, int arg2, void* userData);

// online map update
typedef void (*LPCALL_CHECK_ONLINE_MAP_UPDATE_CALLBACK)(int action, void* userData);

// configuration change callback
typedef void (*LPCALL_CONFIGURATION_CHANGED_CALLBACK)(int action, void* userData);

// 엔진 업데이트 구조체 정의

typedef struct tagUpdateGps
{
	NeStatusGps 			eGpsState;		// GPS 상태
	DOUBLE_VERTEX				wpGps;			// GPS 좌표
	NMEA_DateTime			time;			// GPS 시간
	Int32 					nSpeed;			// GPS 속도
	Int32 					nAngle;			// GPS 각도
	Bool					IsNight;		// 주간/야간
	Bool					bOverSpeed;		// 급가속 안내
	Bool					bNotiLongidling;// 공회전 안내
}UPDATE_GPS, *PUPDATE_GPS;

// trim memory level (from Android)
#define TRIM_MEMORY_RUNNING_MODERATE    5
#define TRIM_MEMORY_RUNNING_LOW         10
#define TRIM_MEMORY_RUNNING_CRITICAL    15
#define TRIM_MEMORY_UI_HIDDEN           20
#define TRIM_MEMORY_BACKGROUND          40
#define TRIM_MEMORY_MODERATE            60
#define TRIM_MEMORY_COMPLETE            80

// 실시간 교통 정보 업데이트 callback
typedef void (*LPCALL_TRAFFIC_DATA_UPDATED)(int success, const char* version, void* userData);

// Tile Validation Check
typedef enum _eTileValidationStatus{
    eValidationStatus_Start = 0,        // Start,       0,          total,      0
    eValidationStatus_Progress,         // Progress,    current,    total,      0
    eValidationStatus_End,              // End,         count,      total,      0
    eValidationStatus_Fail,             // Fail,        Type,       0,          msg
} eTileValidationStatus;

typedef int (*LPCALL_TILE_VALIDATION_CALLBACK)(Int32 status, Int32 type, Int32 param, void* msg);

//////////////////////////////////////////////////////////////////////////
// 네비게이션 엔진 초기화 관련
//////////////////////////////////////////////////////////////////////////

// 엔진에서 사용할 모듈 선택
enum NeTypeNaviModule{
	NAVITYPE_MAPVIEW				= 0x00000001,	// 지도 (2D, 3D는 global 에 설정한다.)
	NAVITYPE_GPSMM					= 0x00000002,	// GPS, 맵매칭 사용
	NAVITYPE_RG						= 0x00000004,	// 경로 안내 (안전운전 도우미 미포함)
	NAVITYPE_SROUTE_TVAS			= 0x00000010,	// 서버 경로 안내 사용 (TVAS 3.2 이상)
	NAVITYPE_TMAP_ANDO				= 0x00000080,	// 티맵 로컬 안전운전 도우미

	//초기화 방법
	NAVITYPE_ASYNC_DBCHECK			= 0x00008000,	// 비동기로 DB 버전 체크한다.

	// 그룹핑 옵션
	NAVITYPE_TMAP_NAVIGATION		= 0x10000000,	// NAVITYPE_MAPVIEW|NAVITYPE_GPSMM|NAVITYPE_RG|NAVITYPE_RG_BASICUI|NAVITYPE_SROUTE_TVAS|NAVITYPE_TMAP_ANDO
	NAVITYPE_NETWORK_NDDS			= 0x20000000,	// NAVITYPE_SERVER_NDDS
	NAVITYPE_LOCALMM				= 0x40000000,	// 티맵 로컬 맵매칭
	NAVITYPE_GPS					= 0x80000000,	// GPS 
};

// SGL에서 사용할 모듈 선택 (NeTypeNaviModule 과 중복되면 안됨)
enum NeTypeSglModule
{
	SGLTYPE_AUDIO					= 0x00040000,	// Audio (볼륨 설정)
	SGLTYPE_GPS						= 0x00080000,	// Gps (포트 정보는 엔진 초기화 시 설정)
	SGLTYPE_NET						= 0x00100000,	// SDLNet 사용 (스트리밍 서비스)
};


//﾿ﾣ￁￸ ￃￊﾱ￢￈ﾭ ﾱﾸ￁ﾶￃﾼ
typedef struct tagNaviModuleInit
{
	Int32		nInitFlag;									// NeTypeNaviModule을 조합하여 사용할 모듈만 초기화 한다.

	// 화면 생성 정보
	Int32		nWidth;										// 생성할 지도의 너비(분할되지 않는 크기)
	Int32		nHeight;									// 생성할 지도의 높이(분할되지 않는 크기)
	PIXEL_FORMAT sPixelFormat;
	NeTypeResource eTypeResource;							// 리소스 타입(A~D)
	UInt32		nMapOptions;								// eMapDrawOptions,  


	// 단말기 정보
	Int32		nFreeMemory;								// 1:메모리 여유 있음, 2:메모리 여유없음, 3:메모리 부족

	// GPS 정보
	NeGpsType	eGpsType;									// GPS 타입
	Float		fGpsPreTime;								// GPS 좌표 이동을 미리 진행 시킨다. (단위, 초)
	SERIAL_PORT	sSerialPort;								// 시리얼 포트 설정 (GPS 타입이 eGpsTypeWinWaitcomm, eGpsTypeWinPoling 일때 만 유효함)

	// 화면 분할 정보
	Int32		nMapViewCount;								// 분할 View 개수
	VERTEX16	cpMapViewCenter[MAX_MAPVIEW_COUNT];			// 분할 View 중심 좌표
	Int32		nMapViewLevel[MAX_MAPVIEW_COUNT];			// 각 MapView별 지도 레벨
	Int32		nMapViewMode[MAX_MAPVIEW_COUNT];			// 각 MapView별 지도 모드 -> 0:진북모드, 1:진행방향모드, 2:버드뷰모드(or 3D)
	Int32		nIdxSelectMapConfig[MAX_MAPVIEW_COUNT];		// 각 View별현재 선택된 Config 파일 인덱스

	// 마지막 지도 정보
	DOUBLE_VERTEX	wpLastPosition;								// 마지막 수신된 GPS 좌표(초기화시에 해당 좌표로 지도이동한다.)
	Int32		nLastAngle;									// 마지막 지도 Angle
	SGL_SYSTEMTIME sLastTime;								// 마지막 GPS 수신 시간

	// 교차로 이미지 정보
	Bool		bCrossRoad;									// 교차로 그리기를 사용 여부
	Int32		nCrossRoadWidth;							// 교차로 이미지 너비
	Int32		nCrossRoadHeight;							// 교차로 이미지 높이
	Int32		nCrossRoadLevel;							// 교차로 이미지 레벨
	VERTEX16	cpCrossRoadCenter;							// 교차로 이미지 중심 좌표

	// 지도 및 화면 설정
	Bool		bMapViewSplit;								// 초기 지도 분할 모드
	Int32		nIdxSelectSymbolConfig;						// 초기 지도 Config 인덱스
	Bool		bBuilding;									// 건물높이 그리기

	// 맵 관련 Config  및 Symbol 파일 패스 정보
	Int32	nMapConfig;													//Map Config 파일 개수
	Int32	nIdxNightMapConfig;											//Map Config 파일중 야간 인덱스
	Char	szMapConfigName[MAX_CONFIG][MAX_CONFIG_FILENAME_LENGTH];	//Map Config 파일명 (nIdxSelectMapConfig 값을 인덱스로 사용)
	Char	szCrossConfigName[MAX_CONFIG][MAX_CONFIG_FILENAME_LENGTH];	//Cross Config 파일명 (nIdxSelectMapConfig 값을 인덱스로 사용)
	Int32	nSymbolConfig;												//Symbol Config 파일 개수
	Int32	nIdxNightSymbolConfig;										//Symbol Config 파일중 야간 인덱스
	Char	szSymbolConfigName[MAX_CONFIG][MAX_CONFIG_FILENAME_LENGTH];	//Symbol Symbol Config 파일명
	Char	szLevelConfigName[MAX_CONFIG_FILENAME_LENGTH];				//Level Config 파일명
	Char	szTpegConfigName[MAX_CONFIG_FILENAME_LENGTH];				//Tpeg Config 파일명
	Char	szEtcConfigName[MAX_CONFIG_FILENAME_LENGTH];				//Etc Config 파일명

        //Char	szRootPath[256];											//DB 파일 패스

    LPCALL_NAVIUPDATE_PROC	pfnNaviUpdate;								// 엔진 업데이트 콜백 함수
    LPCALL_NAVIUPDATE_PROC	pfnNaviHitUpdate;
    
    LPCALL_MAP_STATUS       pfnStatusEngine;
    
    LPCALL_REQUEST_ROAD_NETWORK_TILE_DATA pfnRoadNetworkTileRequest;

	MapMatchingDebuggerInterface* mapMatchingDebugger;

	void* userData;	// userData for RoadNetworkTileRequest

	Bool	bUseLocalMapMatching;										// 로컬 맵매칭 사용 여부.
    Bool    useNmea;                                                    // NMEA사용여부.
    Bool    bUseOpusCodec;
    Int32   nOutSampleRate;
	Int32   linkStackId;
	Int32   sdiStackId;
	Int32   citsStackId;
	Bool    isSupportDR;
}NAVIMODULE_INIT, *PNAVIMODULE_INIT;

//SGL 초기화 구조체
typedef struct tagSglInit
{
	Int32		nInitFlag;									// NeTypeSglModule을 조합하여 사용할 모듈만 초기화 한다.
	NeTypeResource eTypeResource;							// 리소스 타입(A~D)
	NeTypeTexComp eTypeTexComp;								// 압축텍스쳐 타입

	// 사운드 설정
	DWord		dwVolumeSingle;								// 싱글채널(Wave 파일 또는 사용자 음성 출력) 볼륨 : Win32-단말기고유값
	DWord		dwVolumeMulti;								// 멀티채널(안내 음성 출력) 볼륨 : 0~100

        Char	szAppName[32];									// Application Name
        Char	szAppConfigID[32];								// Application Config ID
        Char	szAppTagID[32];									// Application Config Tag ID

        Char	szOnlineMapPath[256];								// DB 파일 패스
        Char	szCachePath[256];								// DB 파일 패스
        Char	szOfflineMapPath[256];								// DB 파일 패스
        Char	szDataPath[256];								// DB 파일 패스
        Char    szMdn[MAX_MDN_STRING_LENGTH];                   // Mdn / "-" 제외
}SGL_INIT, *PSGL_INIT;

//TVAS 경로탐색 GPS 궤적 정보
#pragma pack(1)
typedef struct tagTvasGpsHeader
{
    UInt32	uTime;							//GPS시각 (hhmmss.sss)
    UInt8	satelliteCnt;					//위성수
    UInt8	provider;					//측위방법 (0x01:측위불량, 0x02:fused, 0x03:gps, 0x04:tunnel algorithm)
    UInt16	accuracy;					//정확도 meter
    UInt16	uCnt;							//데이터 리스트 개수
}TVASGPS_HEADER, *PTVASGPS_HEADER;

typedef struct tagTvasGpsDataset
{
    UInt32	uPosX;							//X 좌표(경도: 정수8자리 SK정규화좌표)
    UInt32	uPosY;							//Y 좌표(위도: 정수8자리 SK정규화좌표)
    UInt32	uTime;							//GPS시각 (hhmmss.sss)
    Int16	uAngle;							//각도 (진북기준, 0~359)
    Int16	uSpeed;							//속도 (Km/h)
    UInt8	satelliteCnt;					//위성수
    UInt8	provider;					//측위방법 (0x01:측위불량, 0x02:fused, 0x03:gps, 0x04:tunnel algorithm)
    Int16	accuracy;					//정확도 meter
    UInt8	uMapMatchingCode;				//맵매칭 코드 (0없음 , 1성공, 2실패, 3음영지역, 4 이탈 방지, 5 SAP, 6 tunnel algorithm)
    UInt32	uMatPosX;						//맵매칭 X 좌표(경도: 정수8자리 SK정규화좌표)
    UInt32	uMatPosY;						//맵매칭 Y 좌표(위도: 정수8자리 SK정규화좌표)
    UInt16	uMatAngle;						//각도 (진북기준, 0~359)
    /**
        Activiy type
        public static final int IN_VEHICLE = 0;
        public static final int ON_BICYCLE = 1;
        public static final int ON_FOOT = 2;
        public static final int STILL = 3;
        public static final int UNKNOWN = 4;
        public static final int TILTING = 5;
        public static final int WALKING = 7;
        public static final int RUNNING = 8;
    **/
	UInt16			activityType;			// Activity type
	double			altitude;				// 고도.
}TVASGPS_DATASET, *PTVASGPS_DATASET;

typedef struct tagTvasVertexDataset
{
    UInt32	uTileCode;						//타일 코드
    UInt32	uPosX;							//타일 내 X 좌표
    UInt32	uPosY;							//타일 내 Y 좌표
    UInt16	uDistance;						//V(n) ~ V(N+1)까지의 소요 거리
    UInt16	uTime;							//V(n) ~ V(N+1)까지의 소요 시간
}TVASVERTEX_DATASET, *PTVASVERTEX_DATASET;

inline DOUBLE_VERTEX GetVertexKey(TVASVERTEX_DATASET* vertexData)
{
	DOUBLE_VERTEX vertex;
	vertex.x = vertexData->uPosX;
	vertex.y = vertexData->uPosY;
	return vertex;
}

typedef struct tagTvasVertexDataset2
{
	UInt16	meshCode;						//SK맵 Mesh Code
	UInt32	linkId;							//SK맵 맵링크 ID
	UInt32	dir;							//SK맵 맵링크 방향성 (0:정방향, 1:역방향)
	UInt32	uTime;							//GPS시각(한국시간 2003년1월1일부터 초단위)
    UInt8   isCompareRoute;                 // 경로비교대상 (0:비대상, 1:대상)
	Double startX;
	Double startY;
	UInt32 mlinkDistance;
}TVAS_LINK_DATASET, *PTVAS_LINK_DATASET;

typedef struct tagTunnelLinkInfo
{
    std::string linkId;                     // mesh 4자리 + link 5자리 + 방향1자리
    UInt32 linkLength;
}TUNNEL_LINK_INFO;

inline UInt32 GetLinkKey(TVAS_LINK_DATASET* link)
{
	return (link->meshCode << 17) | (link->linkId << 1) | (link->dir);
}

#pragma pack()

//20120815 ssh
typedef struct tagNsTVASFilesInfo
{
    UInt32		m_nRouteOption;                  //multi-option
    Char        m_sTvasPath[SGL_MAX_PATH+1];     //TVAS file Path
} NsTVASFilesInfo;

typedef struct tagRouteRenderData {
	Char* data;
	UInt32 dataSize;
} ROUTE_RENDER_DATA;

//////////////////////////////////////////////////////////////////////////
// 네비게이션 엔진 함수 정의
//////////////////////////////////////////////////////////////////////////

typedef enum
{
	// Gps 외부 입력
	eAPI_InputGpsNmea,				// Nmea 데이터를 입력한다. (안드로이드 용)
	eAPI_InputLbsPosition,			// GPS가 잡히지 않을때 LBS 위치를 설정한다. (기존 맵매칭 정보는 초기화 된다. 만약 GPS가 수신되면 LBS 좌표는 무시된다.)
	eAPI_GetSatelliteInfo,			// GPS 위성 정보를 얻는다.
	eAPI_SetDrawGPSTrace,			// GPS 궤적을 화면에 표출한다.
	eAPI_AddDrawGPSTrace,			// GPS 궤적을 데이터를 지도에 추가 한다.
    
    eAPI_IsCountryArea,                // 해당 point가 국가 영역인지 체크한다.
    eAPI_LONnLATToCoord,            // 경위도 좌표를 World 좌표로 변환한다.
    eAPI_CoordToLONnLAT,            // World 좌표를 경위도 좌표로 변환한다.
    eAPI_TLONnLATToCoord,            // (Tmap)경위도 좌표를 World 좌표로 변환한다.
    eAPI_TCoordToLONnLAT,            // (Tmap)World 좌표를 경위도 좌표로 변환한다.
    eAPI_CoordTransform,            // (Tmap)좌표 변환 통합 함수

	// 경로 탐색 및 안내 관련
	eAPI_SelectRoute,				// 경로 탐색 결과 중 하나를 선택한다
	eAPI_ApplySelectRoute,			// 경로 탐색 결과 중 하나를 선택한다.(선택되지 않는 경로는 초기화 된다.)
	eAPI_CancelRoute,				// 경로를 취소한다.
	eAPI_IsRoute,					// 경로 상태인지 여부를 얻는다.
    eAPI_BlockReroute,              // 재탐색을 막는다.
	eAPI_GetIsRouting,				// 경로 탐색중인지 여부를 얻는다.
	eAPI_GetRouteSummaryInfo,		// 경로 요약 기본 정보를 얻는다. (다중경로)
	
	// add. summary info & list
	eAPI_GetTmapRouteSummaryInfo,		// 경로 요약정보를 얻는다. (Tmap용)
	eAPI_GetTmapSummaryList,			// 경로 요약 리스트를 얻는다. (Tmap용)
	// 삭제해야함!
	//eAPI_GetTmapRouteSummaryList,		// 경로 요약정보의 리스트를 얻는다. (전체 경로 표출용, Tmap용)

	eAPI_GetRouteSummaryList,		// 경로 요약정보 리스트를 얻는다. (전체 경로 표출용)
    eAPI_GetMultiDestCostInfoList,  // 목적지별 소요시간/거리를 얻는다.
	eAPI_GetRouteTrafficAllList,	// 경로 소통정보 전체 리스트를 얻는다.
	eAPI_GetRouteTrafficGpList,		// 경로 소통정보 GP 리스트를 얻는다.
	eAPI_GetRouteGuidance,			// 경로 안내정보를 얻는다.
	eAPI_GetRouteGuidanceSimulator,	// 모의주행 안내정보를 얻는다.
	eAPI_GetRouteTBTList,			// 경로 턴 정보 리스트를 얻는다. (주행 중 표출용)
	eAPI_GetTrafficSentence,		// 소통정보 텍스트를 얻는다.
	eAPI_GetAllTBTCount,			// TBT 전체 데이터를 받는다.
	eAPI_GetAllTBTDataByIndex,		// TBT 전체 데이터를 Index 정보를 통해 받는다.
	eAPI_GetGuidanceConfig,			// 경로 안내 설정값을 얻는다.
	eAPI_SetGuidanceConfig,			// 경로 안내 설정값을 세팅한다.
	eAPI_GetCctvInfo,				// cctv 정보를 얻는다.
	eAPI_GetServiceAreaInfo,		// 휴게소 정보를 얻는다.
	eAPI_GetGasStationInfo,			// 주유소 정보를 얻는다. (GAS2)
	eAPI_GetEVStationInfo,		// 전기 충전소 정보를 얻는다.
    eAPI_SetDrawGasStationInfo,		// 주유소 정보팝업을 출력한다.

	eAPI_GetRouteCount,				// TVAS data를 세팅한다.

	// TVAS data
	eAPI_SetTvasDataMemory,			// TVAS data를 세팅한다.
	eAPI_AddTvasDataMemory,			// TVAS data를 추가한다.
	eAPI_GetTvasReRouteData,		// TVAS 재탐색을 위한 조건 데이터를 얻는다.
	eAPI_GetTvasReRouteRIDInfo,		// TVAS 재탐색을 위한 RID 정보를 얻는다.
	eAPI_GetTvasReRouteRIDData,		// TVAS 재탐색을 위한 RID 데이터를 얻는다.
    eAPI_GetTvasCityBoundaryData,	// TVAS 시도경계 전체 데이터를 얻는다.

    // Tmap 안전운전도우미 관련 ssh
    eAPI_GetVersionSafeDB,          //AndoDB Version 정보를 얻는다.
    eAPI_CommitSafeFile,            //Commit Ando Update file. call to engine
    eAPI_MakeSafeFile,              //make update Andofile

	eAPI_GetTvasGpsData,			// TVAS 탐색(재탐색)을 위한 GPS 데이터를 얻는다.
	eAPI_GetTvasVertexData,			// TVAS 버텍스 궤적 데이터를 얻는다.
	eAPI_GetTvasVertexNextData,		// TVAS 버텍스 궤적 전방 데이터를 얻는다.
	eAPI_GetTvasLinkData,			// TVAS Link 궤적 데이터를 얻는다.
	eAPI_GetTvasLinkNextData,		// TVAS Link 궤적 전방 데이터를 얻는다.
	eAPI_GetTvasAllLinkData,		// TVAS Link 궤적 전체 데이터를 얻는다.
	eAPI_GetRouteTrack,				// 경로 주행 GPS Track 좌표 파일을 얻는다.
    eAPI_SetGPSQueueCount,			// GPS Queue 사이즈를 설정한다.
	eAPI_GetTvasGpsDataCount,		// 경로 요청 실패했을 경우 GPS 데이터를 얻을 때 사용하며 GPS 데이터의 크기를 얻는다.
	eAPI_GetTvasGpsDataByIndex,		// 경로 요청 실패했을 경우 GPS 데이터를 얻을 때 사용하며 index 정보를 기반하여 GPS 데이터를 얻는다.
    
    eAPI_SetSafeDrivingDbFilePathInfo, // 안전운전 도우미 DB의 file path정보를 설정한다.
    
    eAPI_SetHolidayConfigFilePath, // 휴일정보 Config file path를 설정한다.

	// TTS & Sound 관련
	eAPI_SoundPlayScenario,		// 시나리오 음성을 출력한다.  (비동기 함수)
	eAPI_SoundPlayGuidance,		// 현재 안내 음성을 출력한다. (1회 음성 출력하면 초기화 됨) (비동기 함수)
	eAPI_SoundPlayNextGP,		// 현위치 기준으로 다음 안내점까지 음성을 출력한다. (n회 음성 출력이 가능함) (비동기 함수)
	eAPI_SoundStop,				// 음성 출력을 중지한다. (비동기 함수)
	eAPI_SoundSetVolume,		// 음성 출력 볼륨을 설정한다.
	eAPI_SoundIsPlaying,		// 음성 출력 중 인지 체크 한다.

    eAPI_GetVersion,			// 버전 정보

	eAPI_RenderDestroy,
	eAPI_SetMMDebugStatus, 		// 맵 매칭 상태를 지도에 그린다.
    eAPI_GetMapMatchPositionDrawingDatas,
    eAPI_GetMapMatchPositionDrawingDatasCount,
    eAPI_SetRoadNetworkTileData,

    // 도로 마스터
    eAPI_SearchRoadLink,
    eAPI_QueryRoadLink,
    eAPI_DrawRoadLink,
    eAPI_CancelRoadLink,
    
    eAPI_MoveSelectedTilePosition,
    
    eAPI_StartTileValidationCheck,
    eAPI_StopTileValidationCheck,
    eAPI_HasRemainedTileValidationList,

	eAPI_InputLocation,
	eAPI_GetTvasVertexArray,
	eAPI_GetRouteRenderData,
	eAPI_GetRouteData,
	eAPI_GetRouteDataDynamic,

	eAPI_SetMapMatchingDebuggerActive,
	eAPI_GetTunnelInfo,
	eAPI_GetMatchedPoint,
	eAPI_GetAutoDrivePosition,

	eAPI_GetDecodeOpusData,

	eAPI_GetTvasLinkInfo,
	eAPI_GetTvasLinkTraffic,

	eAPI_SetTTSScript,
	eAPI_ChangeTTSLanguage,
	eAPI_SetEV,

	eAPI_FunctionMax			// API 최대 개수
}eAPI_Function;


/// API Request 기본 해더
typedef struct tagApiRequest
{
}API_REQUEST, *PAPI_REQUEST;
typedef struct tagApiResult
{
}API_RESULT, *PAPI_RESULT;

#ifdef __cplusplus

#define MAX_RESULTLIST  100			// 리스트 최대 개수
#define MAX_TRAFFICLIST	100	// 경로 소통정보 리스트 최대 개수

#define MAX_SUMMARYLIST 	3		// Tmap 경로 요약 최대 개수
#define MAX_TMAP_SUMMARY_DETAIL_COUNT 512 // T map 경로 요약 상세 정보 최대 개수
//////////////////////////////////////////////////////////////////////////
// Gps 외부 입력
//////////////////////////////////////////////////////////////////////////

/// eAPI_InputGpsNmea
typedef struct tagApiInputGpsNmeaReq : public API_REQUEST
{
	Char* szNmea;						// NMEA 텍스트
	Int32 nSize;						// NMEA 텍스트 크기
}API_INPUT_GPSNMEA_REQ, *PAPI_INPUT_GPSNMEA_REQ;

/// eAPI_InputLocation
typedef struct tagApiInputLocationReq : public API_REQUEST
{
	float accuracy;
	double altitude;
	float bearing;
	long elapsedRealtimeNanos;
	DOUBLE_VERTEX wp;
	const Char *provider;
	float speed;
	long long time;
	int satelliteCount;
	int isDRGps;
	int activityType;
	float verticalAngle;
}API_INPUT_LOCATION_REQ, *PAPI_INPUT_LOCATION_REQ;


typedef struct tagApiInputGpsNmeaRes : public API_RESULT
{
	Bool	bMatch;		// 맵매칭 여부(TRUE이면 주행, FALSE이고 bValid가 TRUE 일때만 현위치를 알수 없는 경우임)
	Bool	bValid;		// 입력값이 GPS값을 추출하기 위한 필요한 최소한의 데이터가 존재하는지 여부 (RMC 존재 여부)
}API_INPUT_GPSNMEA_RES, *PAPI_INPUT_GPSNMEA_RES;

/// eAPI_InputGpsStruct
typedef struct tagApiInputGpsStructReq : public API_REQUEST
{
	IPHONE_GPSDATA sGpsData;			// GPS 데이터
}API_INPUT_GPSSTRUCT_REQ, *PAPI_INPUT_GPSSTRUCT_REQ;
typedef struct tagApiInputGpsStructRes : public API_RESULT
{
	Bool	bMatch;		// 맵매칭 여부(TRUE이면 주행)
}API_INPUT_GPSSTRUCT_RES, *PAPI_INPUT_GPSSTRUCT_RES;

/// eAPI_InputLbsPosition
typedef struct tagApiInputLbsPositionReq : public API_REQUEST
{
	DOUBLE_VERTEX wp;	//LBS 측위로 얻은 World 좌표
	Float fAngle;	//마지막 각도(이전 GPS 수신 없을 경우 0)
}API_INPUT_LBSPOSITION_REQ, *PAPI_INPUT_LBSPOSITION_REQ;
typedef struct tagApiInputLbsPositionRes : public API_RESULT
{
}API_INPUT_LBSPOSITION_RES, *PAPI_INPUT_LBSPOSITION_RES;

/// eAPI_GetSatelliteInfo
typedef struct tagApiGetSatelliteInfoReq : public API_REQUEST
{
}API_GET_SATELLITEINFO_REQ, *PAPI_GET_SATELLITEINFO_REQ;
typedef struct tagApiGetSatelliteInfoRes : public API_RESULT
{
	GPSSATELLITEINFO	sSatellite;		// 위성 정보
}API_GET_SATELLITEINFO_RES, *PAPI_GET_SATELLITEINFO_RES;

//////////////////////////////////////////////////////////////////////////
// MapEngine 관련
//////////////////////////////////////////////////////////////////////////

struct tagApiSetDrawGpsTraceReq : public API_REQUEST
{
	Bool bDraw;
};
typedef tagApiSetDrawGpsTraceReq API_SET_DRAWGPSTRACE_REQ;
typedef tagApiSetDrawGpsTraceReq* PAPI_SET_DRAWGPSTRACE_REQ;
typedef API_RESULT API_SET_DRAWGPSTRACE_RES;
typedef API_RESULT* PAPI_SET_DRAWGPSTRACE_RES;

struct tagApiAddDrawGpsTraceReq : public API_REQUEST
{
    Char* szNmea1;  // for Phone
    Char* szNmea2;  // for Head-Unit of Car
};

typedef tagApiAddDrawGpsTraceReq API_ADD_DRAWGPSTRACE_REQ;
typedef tagApiAddDrawGpsTraceReq* PAPI_ADD_DRAWGPSTRACE_REQ;
typedef API_RESULT API_ADD_DRAWGPSTRACE_RES;
typedef API_RESULT* PAPI_ADD_DRAWGPSTRACE_RES;
/// API : Navi 정보를 출력할 View를 지정한다
class Interface_map;

/// API : 해당 World point가 국가 영역인지 체크한다.
struct tagApiIsCountryAreaReq : public API_REQUEST
{
	DOUBLE_VERTEX wpt;						// 확인 하려는 좌표
};
typedef tagApiIsCountryAreaReq API_IS_COUNTRYAREA_REQ;
typedef tagApiIsCountryAreaReq *PAPI_IS_COUNTRYAREA_REQ;

struct tagApiIsCountryAreaRes : public API_RESULT
{
};
typedef tagApiIsCountryAreaRes API_IS_COUNTRYAREA_RES;
typedef tagApiIsCountryAreaRes *PAPI_IS_COUNTRYAREA_RES;

/// API : 경위도 좌표를 World 좌표로 변환한다.
struct tagApiLONnLATToCoordReq : public API_REQUEST
{
	// 경도, 위도 10진수 표현방법 : 126도 37분 42.36초 일때 => 126*100 + 37 + 42.36/60 = 12637.7060
	Double dLongitude;					// 경도(10진수)
	Double dLatitude;					// 위도(10진수)
};
typedef tagApiLONnLATToCoordReq API_LONNLAT_TOCOORD_REQ;
typedef tagApiLONnLATToCoordReq *PAPI_LONNLAT_TOCOORD_REQ;

struct tagApiLONnLATToCoordRes : public API_RESULT
{
	DOUBLE_VERTEX wpt;						// 맵 좌표
};
typedef tagApiLONnLATToCoordRes API_LONNLAT_TOCOORD_RES;
typedef tagApiLONnLATToCoordRes *PAPI_LONNLAT_TOCOORD_RES;

/// API : World 좌표를 경위도 좌표로 변환한다.
struct tagApiCoordToLONnLATReq : public API_REQUEST
{
	NeCoordType eCoordType;				// 경위도 좌표의 종류 (COORDTYPE_WGS84/COORDTYPE_BESSEL)
	DOUBLE_VERTEX wpt;						// 맵 좌표
};
typedef tagApiCoordToLONnLATReq API_COORD_TOLONNLAT_REQ;
typedef tagApiCoordToLONnLATReq *PAPI_COORD_TOLONNLAT_REQ;

struct tagApiCoordToLONnLATRes : public API_RESULT
{
// 	경도, 위도 10진수를 도 분 초 표현방법
// 	12637.7060 일때 => Int32(12637.7060/100)도, Int32((12637.7060/100-도)*100)분, ((12637.7060/100-도)*100 - 분)*60초
// 	126도 37분 42.36초
	Double dLongitude;					// 경도(10진수)
	Double dLatitude;					// 위도(10진수)
};
typedef tagApiCoordToLONnLATRes API_COORD_TOLONNLAT_RES;
typedef tagApiCoordToLONnLATRes *PAPI_COORD_TOLONNLAT_RES;

/// API : (Tmap) 경위도 좌표를 World 좌표로 변환한다.  by ssh
struct tagApiTLONnLATToCoordReq : public API_REQUEST
{
	Double dLongitude;					// 경도(10진수)
	Double dLatitude;					// 위도(10진수)
};
typedef tagApiTLONnLATToCoordReq API_TLONNLAT_TOCOORD_REQ;
typedef tagApiTLONnLATToCoordReq *PAPI_TLONNLAT_TOCOORD_REQ;

struct tagApiTLONnLATToCoordRes : public API_RESULT
{
	DOUBLE_VERTEX wpt;						// 맵 좌표
};
typedef tagApiTLONnLATToCoordRes API_TLONNLAT_TOCOORD_RES;
typedef tagApiTLONnLATToCoordRes *PAPI_TLONNLAT_TOCOORD_RES;

/// API : (Tmap) World 좌표를 경위도 좌표로 변환한다.
struct tagApiTCoordToLONnLATReq : public API_REQUEST
{
	DOUBLE_VERTEX wpt;						// 맵 좌표
};
typedef tagApiTCoordToLONnLATReq API_TCOORD_TOLONNLAT_REQ;
typedef tagApiTCoordToLONnLATReq *PAPI_TCOORD_TOLONNLAT_REQ;

struct tagApiTCoordToLONnLATRes : public API_RESULT
{
    // 	경도, 위도 10진수를 도 분 초 표현방법
    // 	126도 37분 42.36초
	Double dLongitude;					// 경도(10진수)
	Double dLatitude;					// 위도(10진수)
};
typedef tagApiTCoordToLONnLATRes API_TCOORD_TOLONNLAT_RES;
typedef tagApiTCoordToLONnLATRes *PAPI_TCOORD_TOLONNLAT_RES;

/// API : (Tmap) 좌표 변환 통합
struct tagApiCoordTransReq : public API_REQUEST
{
    NeCoordType srcType;
	Double srcX;
	Double srcY;
};
typedef tagApiCoordTransReq API_COORDTRANS_REQ;
typedef tagApiCoordTransReq *PAPI_COORDTRANS_REQ;

struct tagApiCoordTransRes : public API_RESULT
{
    NeCoordType dstType;
	Double dstX;
	Double dstY;
};
typedef tagApiCoordTransRes API_COORDTRANS_RES;
typedef tagApiCoordTransRes *PAPI_COORDTRANS_RES;

//////////////////////////////////////////////////////////////////////////
// GPS & MapMatch 관련
//////////////////////////////////////////////////////////////////////////

/// eAPI_GetTvasGpsData
typedef struct tagApiGetTvasGpsDataReq : public API_REQUEST
{
	Bool bIsFixedCycleReroute;
}API_GET_TVASGPSDATA_REQ, *PAPI_GET_TVASGPSDATA_REQ;
typedef struct tagApiGetTvasGpsDataRes : public API_RESULT
{
	Int32 nGpsCnt;						// GPS 개수
	TVASGPS_DATASET sGpsData[210];		// GPS 데이터
}API_GET_TVASGPSDATA_RES, *PAPI_GET_TVASGPSDATA_RES;

/// eAPI_GetTvasVertexArray
typedef struct tagApiGetTvasVertexArrayReq : public API_REQUEST
{
}API_GET_TVASVERTEXARRAY_REQ, *PAPI_GET_TVASVERTEXARRAY_REQ;
typedef struct tagApiGetTvasVertexArrayRes : public API_RESULT
{
    Int32 nVtxArrayCount;
	DOUBLE_VERTEX* pVtxArrayResult;
}API_GET_TVASVERTEXARRAY_RES, *PAPI_GET_TVASVERTEXARRAY_RES;


/// eAPI_GetTvasVertexData
typedef struct tagApiGetTvasVertexDataReq : public API_REQUEST
{
}API_GET_TVASVERTEXDATA_REQ, *PAPI_GET_TVASVERTEXDATA_REQ;
typedef struct tagApiGetTvasVertexDataRes : public API_RESULT
{
    TVASVERTEX_DATASET* pArrVtxResult;		// TVAS 버텍스 데이터
    Int32 nArrVtxResult;
}API_GET_TVASVERTEXDATA_RES, *PAPI_GET_TVASVERTEXDATA_RES;

/// eAPI_GetTvasVertexNextData
typedef struct tagApiGetTvasVertexDataNextReq : public API_REQUEST
{
}API_GET_TVASVERTEXNEXTDATA_REQ, *PAPI_GET_TVASVERTEXNEXTDATA_REQ;

typedef struct tagApiGetTvasVertexNextDataRes : public API_RESULT
{
    TVASVERTEX_DATASET* pArrVtxResult;		// TVAS 버텍스 데이터
    Int32 nArrVtxResult;
}API_GET_TVASVERTEXNEXTDATA_RES, *PAPI_GET_TVASVERTEXNEXTDATA_RES;

typedef struct tagApiGetTvasLinkDataRes : public API_RESULT
{
	TVAS_LINK_DATASET* pArrLinkResult;		// TVAS link 데이터
	Int32 nArrLinkResult;
}API_GET_TVASLINKDATA_RES, *PAPI_GET_TVASLINKDATA_RES;

/// eAPI_GetRouteTrack
typedef struct tagApiGetRouteTrackReq : public API_REQUEST
{
}API_GET_ROUTETRACK_REQ, *PAPI_GET_ROUTETRACK_REQ;
typedef struct tagApiGetRouteTrackRes : public API_RESULT
{
	Char szFileName[SGL_MAX_PATH+1];	// 파일명 (ROUTE_TRACKHEADER + (X, Y)좌표 리스트)
}API_GET_ROUTETRACK_RES, *PAPI_GET_ROUTETRACK_RES;

// eAPI_SetGPSQueueCount
typedef struct tagApiSetGPSQueueCountReq : public API_REQUEST
{
    Int32 nGPSQueueCount;
}API_SET_GPSQUEUE_COUNT_REQ, *PAPI_SET_GPSQUEUE_COUNT_REQ;

// eAPI_GetTvasGpsDataCount
typedef struct tagApiGetTvasGPSDataCountRes : public API_RESULT
{
	std::vector<Int32> *vGPSDataIndex;
}API_GET_TVASGPSDATACOUNT_RES, *PAPI_GET_TVASGPSDATACOUNT_RES;

// eAPI_GetTvasGpsDataByIndex
typedef struct tagApiGetTvasGPSDataByIdxRes : public API_REQUEST
{
	Int32 nGpsIdx;
}API_GET_TVASGPSDATABYIDX_REQ, *PAPI_GET_TVASGPSDATABYIDX_REQ;
typedef struct tagApiGetTvasGPSDataByIdxReq : public API_RESULT
{
	TVASGPS_DATASET sGpsData;		// GPS 데이터
}API_GET_TVASGPSDATABYIDX_RES, *PAPI_GET_TVASGPSDATABYIDX_RES;

typedef struct tagApiSetGPSQueueCountRes : public API_RESULT
{
}API_SET_GPSQUEUE_COUNT_RES, *PAPI_SET_GPSQUEUE_COUNT_RES;

typedef struct tagAPISetSafeDrivingDbFilePathInfoReq : public API_REQUEST
{
    Char szDbFilePath[SGL_MAX_PATH+1];
    Char szDbIndexFilePath[SGL_MAX_PATH+1];
}API_SET_SAFEDRIVING_FILE_REQ, *PAPI_SET_SAFEDRIVING_FILE_REQ;
typedef struct tagAPISetSafeDrivingDbFilePathInfoRes : public API_RESULT
{
}API_SET_SAFEDRIVING_FILE_RES, *PAPI_SET_SAFEDRIVING_FILE_RES;

typedef struct tagAPISetHolidayConfigFilePathReq : public API_REQUEST
{
    Char szFilePath[SGL_MAX_PATH+1];
}API_SET_HOLIDAY_CONFIG_FILE_REQ, *PAPI_SET_HOLIDAY_CONFIG_FILE_REQ;
typedef struct tagAPISetHolidayConfigFilePathRes : public API_RESULT
{
}API_SET_HOLIDAY_CONFIG_FILE_RES, *PAPI_SET_HOLIDAY_CONFIG_FILE_RES;

//////////////////////////////////////////////////////////////////////////
// 경로 탐색/ 안내 관련
//////////////////////////////////////////////////////////////////////////

// eAPI_SelectRoute
typedef struct tagApiSelectRouteReq : public API_REQUEST
{
	Int32	nIdxSelect;						// 선택 경로 인덱스
	Bool	bPlayRouteRoadSummary;			// 경로상 도로 음성 안내 여부
}API_SELECTROUTE_REQ, *PAPI_SELECTROUTE_REQ;
typedef struct tagApiSelectRouteRes : public API_RESULT
{
}API_SELECTROUTE_RES, *PAPI_SELECTROUTE_RES;

// eAPI_ApplySelectRoute
typedef struct tagApiApplySelectRouteReq : public API_REQUEST
{
	Int32 nIdxSelect;
    Bool isNuguTTSVoiceSpeak;               // NUGU 경로안내 시작음 발성여부(true 일 경우에는 엔진에서는 재생하지 않는다.)
}API_APPLY_SELECTROUTE_REQ, *PAPI_APPLY_SELECTROUTE_REQ;
typedef struct tagApiApplySelectRouteRes : public API_RESULT
{
}API_APPLY_SELECTROUTE_RES, *PAPI_APPLY_SELECTROUTE_RES;

// eAPI_CancelRoute
typedef struct tagApiCancelRouteReq : public API_REQUEST
{
    Bool	bRemainDestFlags;
}API_CANCELROUTE_REQ, *PAPI_CANCELROUTE_REQ;
typedef struct tagApiCancelRouteRes : public API_RESULT
{
}API_CANCELROUTE_RES, *PAPI_CANCELROUTE_RES;

// eAPI_IsRoute
typedef struct tagApiIsRouteReq : public API_REQUEST
{
}API_ISROUTE_REQ, *PAPI_ISROUTE_REQ;
typedef struct tagApiIsRouteRes : public API_RESULT
{
	Bool bRoute;
}API_ISROUTE_RES, *PAPI_ISROUTE_RES;

/// API : 경로 탐색중인지 여부 확인
struct tagApiGetIsRoutingReq : public API_REQUEST
{
};
typedef tagApiGetIsRoutingReq API_GET_ISROUTING_REQ;
typedef tagApiGetIsRoutingReq* PAPI_GET_ISROUTING_REQ;

struct tagApiGetIsRoutingRes : public API_RESULT{
	Bool	bIsRouting;
};
typedef tagApiGetIsRoutingRes API_GET_ISROUTING_RES;
typedef tagApiGetIsRoutingRes* PAPI_GET_ISROUTING_RES;

/// API : 재탐색을 막음
struct tagApiBlockRerouteReq : public API_REQUEST
{
    Bool bBlockReroute;
};
typedef tagApiBlockRerouteReq API_BLOCKREROUTE_REQ;
typedef tagApiBlockRerouteReq* PAPI_BLOCKREROUTE_REQ;

struct tagApiBlockRerouteRes : public API_RESULT
{
};
typedef tagApiBlockRerouteRes API_BLOCKREROUTE_RES;
typedef tagApiBlockRerouteRes* PAPI_BLOCKREROUTE_RES;

// eAPI_GetRouteSummaryInfo
struct tagApiGetRouteSummaryInfoReq : public API_REQUEST
{
};
typedef tagApiGetRouteSummaryInfoReq   API_GET_ROUTESUMMARY_INFO_REQ;
typedef tagApiGetRouteSummaryInfoReq* PAPI_GET_ROUTESUMMARY_INFO_REQ;

struct tagApiGetRouteSummaryInfoRes : public API_RESULT
{
	Int32 nResult;		// 경로 개수
	ROUTESUMMARY_INFO sRouteSummaryInfo[MAX_ROUTE_COUNT];
};
typedef tagApiGetRouteSummaryInfoRes   API_GET_ROUTESUMMARY_INFO_RES;
typedef tagApiGetRouteSummaryInfoRes* PAPI_GET_ROUTESUMMARY_INFO_RES;

// add. summary info
// eAPI_GetTmapRouteSummaryInfo (TMAP 용, 경로요약정보)
struct tagApiGetTmapRouteSummaryInfoReq : public API_REQUEST
{
};
typedef tagApiGetTmapRouteSummaryInfoReq   API_GET_TMAPROUTESUMMARY_INFO_REQ;
typedef tagApiGetTmapRouteSummaryInfoReq* PAPI_GET_TMAPROUTESUMMARY_INFO_REQ;										  

struct tagApiGetTmapRouteSummaryInfoRes : public API_RESULT
{
	Int32 nResult;		// 경로 개수
	TMAPROUTESUMMARY_INFO sTmapRouteSummaryInfo[MAX_ROUTE_COUNT];
};
typedef tagApiGetTmapRouteSummaryInfoRes   API_GET_TMAPROUTESUMMARY_INFO_RES;
typedef tagApiGetTmapRouteSummaryInfoRes* PAPI_GET_TMAPROUTESUMMARY_INFO_RES;

//eAPI_GetCctvInfo
typedef struct tagApiGetCctvInfoReq : public API_REQUEST
{
}API_GET_CCTVINFO_REQ, *PAPI_GET_CCTVINFO_REQ;

typedef struct tagApiGetCctvInfoRes : public API_RESULT
{
	Int32	uiCCTVCnt;
	stCCTVInfo pstCCTV[MAX_INFO_COUNT];
}API_GET_CCTVINFO_RES, *PAPI_GET_CCTVINFO_RES;
//eAPI_GetServiceAreaInfo
typedef struct tagApiGetServiceAreaInfoReq : public API_REQUEST
{
}API_GET_SERVICEAREA_INFO_REQ, *PAPI_GET_SERVICEAREA_INFO_REQ;

typedef struct tagApiGetServiceAreaInfoRes : public API_RESULT
{
	Int32	uiServiceAreaCnt;
	stServiceAreaInfo pstSAInfo[MAX_INFO_COUNT];
}API_GET_SERVICEAREA_INFO_RES, *PAPI_GET_SERVICEAREA_INFO_RES;

//eAPI_GetGasStationInfo
typedef struct tagApiGetGasStationInfoReq : public API_REQUEST
{
}API_GET_GASSTATION_INFO_REQ, *PAPI_GET_GASSTATION_INFO_REQ;

typedef struct tagApiGetGasStationInfoRes : public API_RESULT
{
	Int32	uiGasStationCnt;
	stGasStationInfo pstGasStation[MAX_INFO_COUNT];
}API_GET_GASSTATION_INFO_RES, *PAPI_GET_GASSTATION_INFO_RES;

//eAPI_GetEVStationInfo
typedef struct tagApiGetEVStationInfoReq : public API_REQUEST
{
}API_GET_EVSTATION_INFO_REQ, *PAPI_GET_EVSTATION_INFO_REQ;

typedef struct tagApiGetEVStationInfoRes : public API_RESULT
{
	std::vector<stEVStationInfo> *pstEVStationInfo;
}API_GET_EVSTATION_INFO_RES, *PAPI_GET_EVSTATION_INFO_RES;

typedef struct tagApiSetEvReq : public API_REQUEST
{
	Bool isEv;
}API_SET_EV_REQ, *PAPI_SET_EV_REQ;
typedef struct tagApiSetEvRes : public API_RESULT
{
}API_SET_EV_RES, *PAPI_SET_EV_RES;

//eAPI_DrawGasStationInfo
#include <vector>
typedef struct tagApiDrawGasStationInfoReq : public API_REQUEST
{
    std::vector<UInt32> gasStationList;
    UInt32 lowestPrice;
    UInt32 oilType;
}API_DRAW_GASSTATION_INFO_REQ, *PAPI_DRAW_GASSTATION_INFO_REQ;

typedef struct tagApiDrawGasStationInfoRes : public API_RESULT
{
}API_DRAW_GASSTATION_INFO_RES, *PAPI_DRAW_GASSTATION_INFO_RES;

// eAPI_GetRouteSummaryList
typedef struct tagApiGetRouteSummaryListReq : public API_REQUEST
{
	Int32			nIdxSelect;		// 경로 인덱스
	E_SUMMARY_TYPE	eSummaryType;	// 경로 요약 정보 타입
	Int32			nIdx;			// 리스트 얻을 시작 인덱스
	Int32			nCnt;			// 리스트 얻을 개수
}API_GET_ROUTESUMMARY_LIST_REQ, *PAPI_GET_ROUTESUMMARY_LIST_REQ;

typedef struct tagApiGetRouteSummaryListRes : public API_RESULT
{
	Int32 nResult;		// 결과 개수
	Int32 nTotal;		// 해당 타입의 전체 개수
	stRGSummaryData sRouteSummary[MAX_RESULTLIST];
}API_GET_ROUTESUMMARY_LIST_RES, *PAPI_GET_ROUTESUMMARY_LIST_RES;

// add. summary list
//eAPI_GetTmapSummaryList (Tmap 용, 경로요약리스트)
typedef struct tagApiGetTmapSummaryListReq : public API_REQUEST
{
	Int32			nIdxSelect;		// 경로 인덱스
	E_SUMMARY_TYPE	eSummaryType;	// 경로 요약 정보 타입
	Int32			nIdx;			// 리스트 얻을 시작 인덱스
	Int32			nCnt;			// 리스트 얻을 개수
}API_GET_TMAPSUMMARY_LIST_REQ, *PAPI_GET_TMAPSUMMARY_LIST_REQ;

typedef struct tagApiGetTmapSummaryListRes : public API_RESULT
{
	Int32 nResult;		// 결과 개수
	Int32 nTotal;		// 해당 타입의 전체 개수
	stTmapSummaryItem sTmapSummaryList[MAX_TMAP_SUMMARY_DETAIL_COUNT];
}API_GET_TMAPSUMMARY_LIST_RES, *PAPI_GET_TMAPSUMMARY_LIST_RES;

/// eAPI_GetRouteTrafficAllList
typedef struct tagApiGetRouteTrafficAllListReq : public API_REQUEST
{
	Int32			nIdxSelect;		// 경로 인덱스 (주행 중에는 의미 없음)
}API_GET_ROUTETRAFFIC_ALL_LIST_REQ, *PAPI_GET_ROUTETRAFFIC_ALL_LIST_REQ;

typedef struct tagApiGetRouteTrafficAllListRes : public API_RESULT
{
	Int32 nTotal;                   // 전체 개수
	ROUTETRAFFIC* pTraffic;     // 소통정보
}API_GET_ROUTETRAFFIC_ALL_LIST_RES, *PAPI_GET_ROUTETRAFFIC_ALL_LIST_RES;

/// eAPI_GetMultiDestCostInfoList
typedef struct tagApiRouteDestCostInfoReq : public API_REQUEST
{
    Int32			nIdxSelect;		// 경로 인덱스 (주행 중에는 의미 없음)
}API_GET_ROUTE_DEST_COST_INFO_REQ, *PAPI_GET_ROUTE_DEST_COST_INFO_REQ;

typedef struct tagApiRouteDestCostInfoRes : public API_RESULT
{
    Int32 nTotal;                   // 전체 개수
    ROUTE_DEST_COST pDestCost[MAX_RG_POSITION_COUNT];         // 소요시간/거리 정보
}API_GET_ROUTE_DEST_COST_INFO_RES, *PAPI_GET_ROUTE_DEST_COST_INFO_RES;

/// eAPI_GetRouteTrafficGpList
typedef struct tagApiGetRouteTrafficGpListReq : public API_REQUEST
{
	Int32			nIdxSelect;		// 경로 인덱스 (주행 중에는 의미 없음)
	Int32 nIdx;						// 리스트 얻을 시작 인덱스
	Int32 nCnt;						// 리스트 얻을 개수
}API_GET_ROUTETRAFFIC_GP_LIST_REQ, *PAPI_GET_ROUTETRAFFIC_GP_LIST_REQ;

typedef struct tagApiGetRouteTrafficGpListRes : public API_RESULT
{
	Int32 nResult;							// 결과 개수
	Int32 nTotal;							// 전체 개수
	ROUTETRAFFIC sTraffic[MAX_TRAFFICLIST];	// 소통정보
}API_GET_ROUTETRAFFIC_GP_LIST_RES, *PAPI_GET_ROUTETRAFFIC_GP_LIST_RES;

// eAPI_GetRouteGuidance
typedef struct tagApiGetRouteGuidanceReq : public API_REQUEST
{
	Bool bNeutralizeDriveAutoZoom;	// 속도반응형 동작을 무력화 시킨다.
}API_GET_ROUTEGUIDANCE_REQ, *PAPI_GET_ROUTEGUIDANCE_REQ;

typedef struct tagApiGetRouteGuidanceRes : public API_RESULT
{
	stDriveInfo sDriveInfo;
    Bool bNeedUpdate;
}API_GET_ROUTEGUIDANCE_RES, *PAPI_GET_ROUTEGUIDANCE_RES;

// eAPI_GetRouteGuidanceSimulator
typedef struct tagApiGetRouteGuidanceSimulatorReq : public API_REQUEST
{
	E_SIMULATOR_OPTION eOption;		// 모의주행 안내 옵션
	Int32 nSpeed;					// 모의주행 속도 (eSimulatorNextStep 일때 이동 할 기준 속도)
	Int32 nPos;						// 모의주행 안내 지점의 거리 (eSimulatorPos 일때 출발지에서 거리m)
	Bool bNeutralizeDriveAutoZoom; 	// 속도반응형 동작을 무력화 시킴.
}API_GET_ROUTEGUIDANCE_SIMULATOR_REQ, *PAPI_GET_ROUTEGUIDANCE_SIMULATOR_REQ;

typedef struct tagApiGetRouteGuidanceSimulatorRes : public API_RESULT
{
	stDriveInfo sDriveInfo;
    Bool bNeedUpdate;
}API_GET_ROUTEGUIDANCE_SIMULATOR_RES, *PAPI_GET_ROUTEGUIDANCE_SIMULATOR_RES;

// eAPI_GetRouteTBTList
typedef struct tagApiGetRouteTBTListReq : public API_REQUEST
{
	E_TBTLIST_TYPE	eTBTListType;	// TBT 정보 타입
	Int32 nIdx;						// 리스트 얻을 시작 인덱스
	Int32 nCnt;						// 리스트 얻을 개수
}API_GET_ROUTETBT_LIST_REQ, *PAPI_GET_ROUTETBT_LIST_REQ;

typedef struct tagApiGetRouteTBTListRes : public API_RESULT
{
	Int32 nResult;					// 결과 개수
	Int32 nTotal;					// 해당 타입의 전체 개수
        OsTBTList sTBT[MAX_RESULTLIST+1]; // +1 마지막 고속도로 정보 추가
}API_GET_ROUTETBT_LIST_RES, *PAPI_GET_ROUTETBT_LIST_RES;

// eAPI_GetAllTBTCount
typedef struct tagApiGetAllTBTCountRes : public API_RESULT
{
	Int32 nCnt;	// TBT List의 전체 갯수
}API_GET_ALLTBTCOUNT_RES, *PAPI_GET_ALLTBTCOUNT_RES;

// eAPI_GetTBTDataByIndex
typedef struct tagApiGetTBTDataByIndexReq : public API_REQUEST
{
	Int32 nIndex;
}API_GET_TBTDATABYINDEX_REQ, *PAPI_GET_TBTDATABYINDEX_REQ;

// eAPI_GetTBTDataByIndex
typedef struct tagApiGetTBTDataByIndexRes : public API_RESULT
{
	OsTBTList sTBT;
}API_GET_TBTDATABYINDEX_RES, *PAPI_GET_TBTDATABYINDEX_RES;

/// eAPI_GetGuidanceConfig:
typedef struct tagApiGetGuidanceConfigReq : public API_REQUEST
{
}API_GET_GUIDANCECONFIG_REQ, *PAPI_GET_GUIDANCECONFIG_REQ;

typedef struct tagApiGetGuidanceConfigRes : public API_RESULT
{
	RG_CONFIG	sConfig;
}API_GET_GUIDANCECONFIG_RES, *PAPI_GET_GUIDANCECONFIG_RES;

/// eAPI_SetGuidanceConfig:
typedef struct tagApiSetGuidanceConfigReq : public API_REQUEST
{
	RG_CONFIG	sConfig;
}API_SET_GUIDANCECONFIG_REQ, *PAPI_SET_GUIDANCECONFIG_REQ;

typedef struct tagApiSetGuidanceConfigRes : public API_RESULT
{
}API_SET_GUIDANCECONFIG_RES, *PAPI_SET_GUIDANCECONFIG_RES;

typedef struct tagApiGetRouteCountRes : public API_RESULT
{
	Int32		nRouteCount;
}API_GET_ROUTECOINT_RES, *PAPI_GET_ROUTECOUNT_RES;

typedef struct tagApiSetTvasDataMemoryReq : public API_REQUEST
{
	char* data; 							// TVAS Data
	Bool bReRoute;							// 재탐색 여부 (경로 안내 시작 안내 할지 판단)
	UInt8 uReRouteType;						// 재탐색 유형 (없음(0), 정주기(1), 사용자(2), 이탈재탐색(3))
	UInt8 uDestSearchDetailFlag;			// RC만 재계산(0: None, 1:RC만 재계산)
	Bool isRouteOptionChanged;			// 사용자 다른 경로 재탐색 클릭여부 (default : false)
	Bool isFavoriteRouteSelected;			// 즐겨찾는 경로 주행 여부
	Int32 selectedIndex;				// 선택된 Index
	Int32 routeCount;
	Int32 options[5];
	Int32 tvasSize[5];
	Int32 nCurrentEnergy;
}API_SET_TVASDATA_MEMORY_REQ, *PAPI_SET_TVASDATA_MEMORY_REQ;

typedef struct tagApiAddTvasDataMemoryReq : public API_REQUEST
{
	char* data; 							// TVAS Data
	Int32 option;
	Int32 tvasSize;
	Int32 currentEnergy;
}API_ADD_TVASDATA_MEMORY_REQ, *PAPI_ADD_TVASDATA_MEMORY_REQ;

typedef struct tagApiSetTvasDataRes : public API_RESULT
{
	Int32		nErrCode;
}API_SET_TVASDATA_RES, *PAPI_SET_TVASDATA_RES;

typedef struct tagApiGetRouteRenderDataReq : public API_REQUEST
{
	// nothing
} API_GET_ROUTERENDERDATA_REQ, *PAPI_GET_ROUTERENDERDATA_REQ;

typedef struct tagApiGetRouteRenderDataRes : public API_RESULT
{
	UInt32 count;
	ROUTE_RENDER_DATA* renderData;
} API_GET_ROUTERENDERDATA_RES, *PAPI_GET_ROUTERENDERDATA_RES;

typedef struct tagApiGetRouteDataReq : public API_REQUEST
{
	char* data; 							// TVAS Data
	Int32 tvasSize;
	Int32 currentEnergy;
} API_GET_ROUTER_DATA_REQ, *PAPI_GET_ROUTER_DATA_REQ;

typedef struct tagApiGetRouteDataRes : public API_RESULT
{
	ROUTE_RENDER_DATA renderData;
	stTmapSummaryItem summary[MAX_TMAP_SUMMARY_DETAIL_COUNT];
	Int32 summaryListCount;
	stTmapSummaryBaseInfo tmapSummary;
	stGasStationInfo gasStationInfos[MAX_STATION_COUNT];
	Int32 gasInfoCount;
	stEVStationInfo  evStationInfos[MAX_STATION_COUNT];
	Int32 evInfoCount;
	stServiceAreaInfo serviceAreaInfos[MAX_INFO_COUNT];
	Int32 areaInfoCount;
	TVAS_LINK_DATASET linkInfos[MAX_TVAS_LINK_CNT];
	Int32 linkInfoCount;
	stThemeRoadInfo themeRoadInfo[MAX_INFO_COUNT];
	Int32 themeRoadInfoCount;
} API_GET_ROUTER_DATA_RES, *PAPI_GET_ROUTER_DATA_RES;

typedef struct tagApiGetRouteDataDynamicRes : public API_RESULT
{
	ROUTE_RENDER_DATA renderData;
	stTmapSummaryBaseInfo tmapSummary;
	std::vector<stTmapSummaryItem> *summary;
	std::vector<stGasStationInfo> *gasStationInfos;
	std::vector<stEVStationInfo> *evStationInfos;
	std::vector<stServiceAreaInfo> *serviceAreaInfos;
	std::vector<TVAS_LINK_DATASET> *linkInfos;
	std::vector<stThemeRoadInfo> *themeRoadInfo;
    std::vector<stTmapTrafficItem> *trafficInfo;
    std::vector<stTmamRoadItem> *roadInfo;
    std::vector<stTmamGuidePoint> *guidePointInfo;
    std::vector<stTmapRoadAccidentItem> *roadAccidentInfo;
} API_GET_ROUTER_DATA_DYNAMIC_RES, *PAPI_GET_ROUTER_DATA_DYNAMIC_RES;

/// eAPI_GetTvasReRouteData
typedef struct tagApiGetTvasReRouteDataReq : public API_REQUEST
{
}API_GET_TVASREROUTEDATA_REQ, *PAPI_GET_TVASREROUTEDATA_REQ;
typedef struct tagApiGetTvasReRouteDataRes : public API_RESULT
{
	//탐색 조건 데이터
	Int32		nRouteDataSize;
	Byte		byRouteData[1024];
	//주변링크 정보
	Bool		bAroundLink;
	UInt8		uOldRsdCode;				// 이탈 지점 기존경로 RSD 회전 코드
	UInt8		uRsdCode;					// 진입 RSD 회전 코드
	UInt16		uLinkID;					// 링크 id
	UInt32		uTileCode;					// 타일코드(Link)
	UInt8		uDirInfo;					// 방향 (0:정방향, 1:역방향)
	UInt32		uPosX;						// 보간점 X 좌표(경도: 정수8자리 SK정규화좌표)
	UInt32		uPosY;						// 보간점 Y 좌표(위도: 정수8자리 SK정규화좌표)
	//톨게이트 정보
	UInt16		uPassTollID;				// 최종통과 톨게이트 ID
	Char        tollIdList[MAX_TOLL_GATE_LIST_LENGTH];  // 톨게이트 전체 목록
}API_GET_TVASREROUTEDATA_RES, *PAPI_GET_TVASREROUTEDATA_RES;


/// eAPI_GetTvasReRouteRIDInfo
typedef struct tagApiGetTvasReRouteRIDInfoReq : public API_REQUEST
{
}API_GET_TVASREROUTERIDINFO_REQ, *PAPI_GET_TVASREROUTERIDINFO_REQ;
typedef struct tagApiGetTvasReRouteRIDInfoRes : public API_RESULT
{
	UInt32 nCnt;
	Int32 lastRid;
	Char mapVer[8];
	UInt32 initSrchLength;
	Char initSrchSessionID[24];

}API_GET_TVASREROUTERIDINFO_RES, *PAPI_GET_TVASREROUTERIDINFO_RES;

/// eAPI_GetTvasReRouteRIDData
typedef struct tagApiGetTvasReRouteRIDDataReq : public API_REQUEST
{
}API_GET_TVASREROUTERIDDATA_REQ, *PAPI_GET_TVASREROUTERIDDATA_REQ;
typedef struct tagApiGetTvasReRouteRIDDataRes : public API_RESULT
{
	UInt32  nCount;
	Int32  *pRidList;
	Int32  *pSecList;
}API_GET_TVASREROUTERIDDATA_RES, *PAPI_GET_TVASREROUTERIDDATA_RES;



typedef struct tagApiGetTvasCityBoundartyDataReq : public API_REQUEST
{
}API_GET_TVASCITYBOUNDARYDATA_REQ, *PAPI_GET_TVASCITYBOUNDARYDATA_REQ;
typedef struct tagApiGetTvasCityBoundartyDataRes : public API_RESULT
{
	//시도 경계 데이터
	UInt16		arrInCityCode[MAX_INFO_COUNT];	// 진출 시도 코드
	UInt16		arrOutCityCode[MAX_INFO_COUNT];	// 진입 시도 코드
	UInt32		nSize;						// 크기
}API_GET_TVASCITYBOUNDARYDATA_RES, *PAPI_GET_TVASCITYBOUNDARYDATA_RES;


/// API_GetSafeIndexPath  ssh
typedef struct tagApiSafePathReq : public API_REQUEST
{
}API_GET_SAFE_PATH_REQ, *PAPI_GET_SAFE_PATH_REQ;
typedef struct tagApiSafePathRes : public API_RESULT
{
}API_GET_SAFE_PATH_RES, *PAPI_GET_SAFE_PATH_RES;

/// API_GetVersionSafeDB  ssh
typedef struct tagApiVersionSafeDBReq : public API_REQUEST
{
}API_GET_SAFE_VERSION_REQ, *PAPI_GET_SAFE_VERSION_REQ;
typedef struct tagApiVersionSafeDBRes : public API_RESULT
{
    Int32 iVersion;
}API_GET_SAFE_VERSION_RES, *PAPI_GET_SAFE_VERSION_RES;

/// API_MakeAndoFile  ssh
typedef struct tagApiMakeSafeFileReq : public API_REQUEST
{
	Byte		*pData;         //UpdateData
    Int32		nsize;          //DataSize
}API_MAKE_SAFE_FILE_REQ, *PAPI_MAKE_SAFE_FILE_REQ;
typedef struct tagApiMakeSafeFileRes : public API_RESULT
{
}API_MAKE_SAFE_FILE_RES, *PAPI_MAKE_SAFE_FILE_RES;

/// API_CommitAndoFile  ssh
typedef struct tagApiCommitSafeFileReq : public API_REQUEST
{
}API_COMMIT_SAFE_FILE_REQ, *PAPI_COMMIT_SAFE_FILE_REQ;
typedef struct tagApiCommitSafeFileRes : public API_RESULT
{
}API_COMMIT_SAFE_FILE_RES, *PAPI_COMMIT_SAFE_FILE_RES;

//////////////////////////////////////////////////////////////////////////
// Sound 관련

// eAPI_SoundPlayScenario
typedef struct tagApiSoundPlayScenarioReq : public API_REQUEST
{
	NeVoiceScenario eVoiceScenario;
}API_SOUND_PLAYSCENARIO_REQ, *PAPI_SOUND_PLAYSCENARIO_REQ;
typedef struct tagApiSoundPlayScenarioRes : public API_RESULT
{
}API_SOUND_PLAYSCENARIO_RES, *PAPI_SOUND_PLAYSCENARIO_RES;

// eAPI_SoundPlayGuidance
typedef struct tagApiSoundPlayGuidanceReq : public API_REQUEST
{
}API_SOUND_PLAYGUIDANCE_REQ, *PAPI_SOUND_PLAYGUIDANCE_REQ;
typedef struct tagApiSoundPlayGuidanceRes : public API_RESULT
{
}API_SOUND_PLAYGUIDANCE_RES, *PAPI_SOUND_PLAYGUIDANCE_RES;

// eAPI_SoundPlayNextGP
typedef struct tagApiSoundPlayNextGPReq : public API_REQUEST
{
}API_SOUND_PLAYNEXTGP_REQ, *PAPI_SOUND_PLAYNEXTGP_REQ;
typedef struct tagApiSoundPlayNextGPRes : public API_RESULT
{
}API_SOUND_PLAYNEXTGP_RES, *PAPI_SOUND_PLAYNEXTGP_RES;

// eAPI_SoundStop
typedef struct tagApiSoundStopReq : public API_REQUEST
{
}API_SOUND_STOP_REQ, *PAPI_SOUND_STOP_REQ;
typedef struct tagApiSoundStopRes : public API_RESULT
{
}API_SOUND_STOP_RES, *PAPI_SOUND_STOP_RES;

// eAPI_SoundSetVolume
typedef struct tagApiSoundSetVolumeReq : public API_REQUEST
{
	DWord dwMultiVolume;				//  멀티채널(안내음성) 볼륨값 => Win32(단말별 고유값)
	DWord dwSingleVolume;				//  싱글채널(사용자파일) 볼륨값 => 0~100
}API_SOUND_SETVOLUME_REQ, *PAPI_SOUND_SETVOLUME_REQ;
typedef struct tagApiSoundSetVolumeRes : public API_RESULT
{
}API_SOUND_SETVOLUME_RES, *PAPI_SOUND_SETVOLUME_RES;

// eAPI_SoundIsPlaying
typedef struct tagApiSoundIsPlayingReq : public API_REQUEST
{
}API_SOUND_ISPLAYING_REQ, *PAPI_SOUND_ISPLAYING_REQ;
typedef struct tagApiSoundIsPlayingRes : public API_RESULT
{
}API_SOUND_ISPLAYING_RES, *PAPI_SOUND_ISPLAYING_RES;

// eAPI_GetVersion
typedef struct tagApiGetVersionReq : public API_REQUEST
{
}API_GET_VERSION_REQ, *PAPI_GET_VERSION_REQ;
typedef struct tagApiGetVersionRes : public API_RESULT
{
	Char szSDIVer[16];
	Char szLocalVer[16];
}API_GET_VERSION_RES, *PAPI_GET_VERSION_RES;


// eAPI_GetKeywordLocation
typedef struct tagApiGetKeywordLocationReq : public API_REQUEST
{
	Char keyword[64];						// 키워드 확인 요청 문자열
}API_GET_KEYWORD_LOCATION_REQ, *PAPI_GET_KEYWORD_LOCATION_REQ;
typedef struct tagApiGetKeywordLocationRes : public API_RESULT
{
	Int32 subcnt;    // 키워드 리스트 개수
	Int32 offset;     //  키워드 시작 offset
}API_GET_KEYWORD_LOCATION_RES, *PAPI_GET_KEYWORD_LOCATION_RES;

// eAPI_GetKeywordDataList
typedef struct tagApiGetKeywordDataListReq : public API_REQUEST
{
	Int32 subcnt;
	Int32 offset;
}API_GET_KEYWORD_DATALIST_REQ, *PAPI_GET_KEYWORD_DATALIST_REQ;
typedef struct tagApiGetKeywordDataListRes : public API_RESULT
{
	int* keywordlist;
}API_GET_KEYWORD_DATALIST_RES, *PAPI_GET_KEYWORD_DATALIST_RES;

// eAPI_ScreenCapture
struct tagApiScreenCaptureReq : public API_REQUEST
{
	const char* pszFileName;
};
typedef tagApiScreenCaptureReq API_SCREENCAPTURE_REQ;
typedef tagApiScreenCaptureReq* PAPI_SCREENCAPTURE_REQ;
typedef API_RESULT API_SCREENCAPTURE_RES;
typedef API_RESULT* PAPI_SCREENCAPTURE_RES;



struct tagApiSetMMDebugStatusReq : public API_REQUEST
{
	Bool bActivate;
};
typedef tagApiSetMMDebugStatusReq API_SET_MM_DEBUG_STATUS_REQ;
typedef tagApiSetMMDebugStatusReq* PAPI_SET_MM_DEBUG_STATUS_REQ;
typedef API_RESULT API_SET_MM_DEBUG_STATUS_RES;
typedef API_RESULT* PAPI_SET_MM_DEBUG_STATUS_RES;

// eAPI_GetResourceRect
typedef struct tagApiGetResourceRectReq : public API_REQUEST
{
	Int32 nPageId;
	Int32 nCtrlId;
}API_GETRESOURCERECT_REQ, *PAPI_GETRESOURCERECT_REQ;
typedef struct tagApiGetResourceRectRes : public API_RESULT
{
	RECT rect;
}API_GETRESOURCERECT_RES, *PAPI_GETRESOURCERECT_RES;

// eAPI_GetImageBuffer
typedef struct tagApiGetImageBufferReq : public API_REQUEST
{
	Int32 nImageId;
}API_GETIMAGEBUFFER_REQ, *PAPI_GETIMAGEBUFFER_REQ;
typedef struct tagApiGetImageBufferRes : public API_RESULT
{
	Byte *pImage;
	Int32 nImage;
}API_GETIMAGEBUFFER_RES, *PAPI_GETIMAGEBUFFER_RES;
typedef struct tagApiHitObjectReq : public API_REQUEST
{
	Float x;
	Float y;
}API_INPUT_HITOBJECT_REQ, *PAPI_INPUT_HITOBJECT_REQ;
typedef struct tagApiHitObjectRes : public API_RESULT
{
}API_INPUT_HITOBJECT_RES, *PAPI_INPUT_HITOBJECT_RES;

typedef struct tagApiSearchRoadLinkReq : public API_REQUEST
{
    const Char* roadName;
    Bool fullMatch;
    Int32 maxCount;
}API_SEARCH_ROAD_NAME_REQ, *PAPI_SEARCH_ROAD_NAME_REQ;

typedef struct tagApiSearchRoadLinkRes : public API_RESULT
{
    stRoadNameItem* items;
    Int32 count;
}API_SEARCH_ROAD_NAME_RES, *PAPI_SEARCH_ROAD_NAME_RES;

typedef struct tagApiQueryRoadLinkReq : public API_REQUEST
{
    const Char* distKind;
    const Char* distId;
}API_QUERY_ROAD_LINK_REQ, *PAPI_QUERY_ROAD_LINK_REQ;

typedef struct tagApiQueryRoadLinkRes : public API_RESULT
{
    stRoadLinkList* roadLinkList;
}API_QUERY_ROAD_LINK_RES, *PAPI_QUERY_ROAD_LINK_RES;

typedef struct tagApiDrawRoadLinkReq : public API_REQUEST
{
    const Char* distKind;
    const Char* distId;
    Bool ensureVisible;
}API_SELECT_ROAD_LINK_REQ, *PAPI_SELECT_ROAD_LINK_REQ;

typedef API_RESULT API_SELECT_ROAD_LINK_RES, *PAPI_SELECT_ROAD_LINK_RES;

typedef struct tagApiMoveSelectedTileReq : public API_REQUEST
{
    int tileX;
    int tileY;
} API_MOVE_SELECTED_TILE_REQ, *PAPI_MOVE_SELECTED_TILE_REQ;
typedef API_RESULT API_MOVE_SELECTED_TILE_RES, *PAPI_MOVE_SELECTED_TILE_RES;

typedef struct tagApiStartTileValidationCheckReq : public API_REQUEST
{
    void*   statusErrorCBFunction;
    bool    bStartAll;
}API_START_TILE_VALIDATION_CHECK_REQ, *PAPI_START_TILE_VALIDATION_CHECK_REQ;
typedef struct tagApiStartTileValidationCheckRes : public API_RESULT
{
    Bool bResult;
}API_START_TILE_VALIDATION_CHECK_RES, *PAPI_START_TILE_VALIDATION_CHECK_RES;

typedef API_REQUEST API_STOP_TILE_VALIDATION_CHECK_REQ, *PAPI_STOP_TILE_VALIDATION_CHECK_REQ;
typedef API_RESULT API_STOP_TILE_VALIDATION_CHECK_RES, *PAPI_STOP_TILE_VALIDATION_CHECK_RES;

typedef API_REQUEST API_HAS_REMAINED_TILE_VALIDATION_LIST_REQ, *PAPI_HAS_REMAINED_TILE_VALIDATION_LIST_REQ;
typedef struct tagApiHasRemainedTileValidationRes : API_RESULT
{
    int bResult;
}
API_HAS_REMAINED_TILE_VALIDATION_LIST_RES, *PAPI_HAS_REMAINED_TILE_VALIDATION_LIST_RES;

typedef struct tagApiGetPositionDrawingDatasReq : public API_REQUEST
{
    Bool isSimulation;
    MM_VERTEX** dataArray;
    int dataCount;
}API_GET_POSITION_DRAWING_DATA_REQ, *PAPI_GET_POSITION_DRAWING_DATA_REQ;

typedef struct tagApiGetPositionDrawingDatasRes : public API_RESULT
{
    MM_VERTEX* dataArray;
	int tvasId;
    int dataCount;
    int intervalMiiliseconds;
}API_GET_POSITION_DRAWING_DATA_RES, *PAPI_GET_POSITION_DRAWING_DATA_RES;

typedef struct tagApiSetRoadNetworkTileReq : public API_REQUEST
{
    Bool succeed;
	UInt32 level;
	UInt32 x;
	UInt32 y;
    const UInt8* data;
    UInt32 dataSize;
}API_SET_ROAD_NETWORK_TILE_REQ, *PAPI_SET_ROAD_NETWORK_TILE_REQ;

typedef struct tagApiSetRoadNetworkTileRes : public API_RESULT
{
}API_SET_ROAD_NETWORK_TILE_RES, *PAPI_SET_ROAD_NETWORK_TILE_RES;

typedef struct tagApiSetMapMatchingDebuggerActiveReq : public API_REQUEST
{
	Bool active;
}API_SET_MAPMATCHING_DEBUGGER_ACTIVE_REQ, *PAPI_SET_MAPMATCHING_DEBUGGER_ACTIVE_REQ;

typedef struct tagApiSetMapMatchingDebuggerActiveRes : public API_RESULT
{
}API_SET_MAPMATCHING_DEBUGGER_ACTIVE_RES, *PAPI_SET_MAPMATCHING_DEBUGGER_ACTIVE_RES;

typedef struct tagApiGetTunnelInfoRes : public API_RESULT
{
	DOUBLE_VERTEX start;
	DOUBLE_VERTEX end;
	Bool isTunnel;
	Int32 length;
	Char roadName[_TEXT_SIZE_];
	Char tunnelName[_TEXT_SIZE_];
	std::vector<TUNNEL_LINK_INFO> tunnelLinkIdList;
	Char* tunnelId;
} API_GET_TUNNEL_INFO_RES, *PAPI_GET_TUNNEL_INFO_RES;

typedef struct tagApiDecodeOpusDataReq : public API_REQUEST
{
	Byte* inputData;
	Int32 contentLength;
}API_DECODE_OPUS_DATA_REQ, *PAPI_DECODE_OPUS_DATA_REQ;

typedef struct tagApiDecodeOpusDataRes : public API_RESULT
{
	std::vector<Int16> opusResult;
	Int32 size;
}API_DECODE_OPUS_DATA_RES, *PAPI_DECODE_OPUS_DATA_RES;


typedef struct tagApiGetMatchedPointReq : public API_REQUEST
{
	DOUBLE_VERTEX point;
	Int32 distance;
} API_GET_MATCHED_POINT_REQ, *PAPI_GET_MATCHED_POINT_REQ;

typedef struct tagApiGetMatchedPointRes : public API_RESULT
{
	Int32 mesh;
	Int32 dir;
	Int32 linkId;
	Int32 vertexOffset;
    Int32 absoluteVertexIndex;
	DOUBLE_VERTEX result;
} API_GET_MATCHED_POINT_RES, *PAPI_GET_MATCHED_POINT_RES;

typedef struct tagApiGetAutoDrivePositionReq : public API_REQUEST
{
	Int32 speedInKmPerHour;
} API_GET_AUTO_DRIVE_POSITION_REQ, *PAPI_GET_AUTO_DRIVE_POSITION_REQ;

typedef struct tagApiGetAutoDrivePositionRes : public API_RESULT
{
	DOUBLE_VERTEX point;
	Int32 speedInKmPerHour;
	Int32 angle;
} API_GET_AUTO_DRIVE_POSITION_RES, *PAPI_GET_AUTO_DRIVE_POSITION_RES;

typedef struct tagApiGetTvasLinkInfoReq : public API_REQUEST
{
} API_GET_TVAS_LINK_INFO_REQ, *PAPI_GET_TVAS_LINK_INFO_REQ;

typedef struct tagApiGetTvasLinkInfoRes : public API_RESULT
{
	std::vector<TVS_LinkID> *TVS_LinkID;
} API_GET_TVAS_LINK_INFO_RES, *PAPI_GET_TVAS_LINK_INFO_RES;

typedef struct tagApiGetTvasTrafficLinkReq : public API_REQUEST
{
} API_GET_TVAS_LINK_TRAFFIC_REQ, *PAPI_GET_TVAS_LINK_TRAFFIC_REQ;

typedef struct tagApiGetTvasTrafficLinkRes : public API_RESULT
{
	std::vector<TVS_LinkTraffic2> *TVS_LinkTraffic;
} API_GET_TVAS_LINK_TRAFFIC_RES, *PAPI_GET_TVAS_LINK_TRAFFIC_RES;

typedef struct tagApiSetTtsScriptReq : public API_REQUEST
{
	std::map<E_TTS_LANGUAGE_TYPE, std::map<int,std::string>> scriptMap;
} API_GET_SET_TTS_SCRIPT_REQ, *PAPI_GET_SET_TTS_SCRIPT_REQ;

typedef struct tagApiSetTtsScriptRes : public API_RESULT
{
	int scriptCount;
} API_GET_SET_TTS_SCRIPT_RES, *PAPI_GET_SET_TTS_SCRIPT_RES;

typedef struct tagApiSetTtsLanguageReq : public API_REQUEST
{
	E_TTS_LANGUAGE_TYPE language;
} API_GET_SET_TTS_LANGUAGE_REQ, *PAPI_GET_SET_TTS_LANGUAGE_REQ;

typedef struct tagApiSetTtsLanguageRes : public API_RESULT
{
} API_GET_SET_TTS_LANGUAGE_RES, *PAPI_GET_SET_TTS_LANGUAGE_RES;

#endif //__cplusplus
#endif // __INTERFACE_DEF_H__

