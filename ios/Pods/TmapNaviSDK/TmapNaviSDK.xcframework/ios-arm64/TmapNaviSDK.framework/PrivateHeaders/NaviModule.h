// NaviModule.h
#ifndef __NAVIMODULE_H__
#define __NAVIMODULE_H__

// 작성자 : 박현재
// 작성일 : 2008/05/07
// 설  명 :
#include "LocalLinkV2.h"
#include "sgl_inc.h"
#include "interface_def.h"
#include "MapDataType.h"
#include "mapmatch_inc.h"
#include "rg_inc.h"
#include "env_inc.h"

#include "LowPassFilter.h"
#include "LinkedMap.h"
#include "flatbuffers.h"
#include "vsmRoute_generated.h"
#include "rgdata_def.h"

//정수 -> 빅엔디안 바이트 배열 변환 매크로
//2013.03.20 flintlock
#define BIGENDIAN_INT2BYTE(src, dest)	\
{										\
    dest[3] = (src & 0xff);				\
    dest[2] = ((src >> 8) & 0xff);		\
    dest[1] = ((src >> 16) & 0xff);		\
    dest[0] = ((src >> 24) & 0xff);		\
}

//빅엔디안 바이트 배열 -> 정수 변환 매크로
//2013.03.20 flintlock
#define BIGENDIAN_BYTE2INT(src)	\
    ((src[0] & 0xff) << 24)		\
    | ((src[1] & 0xff) << 16)	\
    | ((src[2] & 0xff) << 8)	\
    | (src[3] & 0xff)


#define MAX_TVAS_VERTEX_CNT         5000						//Vertex 정보 최대 수
#define MAX_TVAS_NEXT_VERTEX_CNT    100						//재탐색시 추가 Vertex 정보 최대 수

#define MAX_TVAS_LINK_CNT         1000						//Link 정보 최대 수
#define MAX_TVAS_NEXT_LINK_CNT    100						//재탐색시 Link 정보 최대 수

class CNaviModule
{
    NOT_COPYABLE(CNaviModule)
private:
    CNaviModule(void);
    virtual ~CNaviModule(void);

public:
    //////////////////////////////////////////////////////////////////////////
    // 모듈 초기화 및 해제
    //////////////////////////////////////////////////////////////////////////

    void UnLockTvasMutexLock();

    // SGL 모듈을 초기화 한다.
    Bool InitSgl(PSGL_INIT pSglInit);
    void InitSound(PSGL_INIT pSglInit);
    void ReleaseSound();

    // SGL 모듈을 해제
    void ReleaseSgl();
    // 공용 모듈 객체 생성 & 초기화 (기본)
    Bool InitCommon(PNAVIMODULE_INIT pNaviInit);
    // 공용 모듈 해제
    void ReleaseCommon();
    // 공용 모듈 해제(스레드 종료 - 최우선 순으로 호출 해야 한다.)
    void ReleaseCommonThread();

    // 경로안내 모듈 객체 생성 & 초기화
    Bool InitRg();

    // 경로안내 모듈 해제
    void ReleaseRg();

    // DAL 모듈 객체 생성 & 초기화 (기본)
    Bool InitDAL(PNAVIMODULE_INIT pNaviInit);
    // DAL 모듈 해제
    void ReleaseDAL();

    // GPS, 맵매칭 모듈 객체 생성 & 초기화
    Bool InitGpsMM(PNAVIMODULE_INIT pNaviInit, Bool bUseLocalMapMatching, Int32 linkStackId, Int32 sdiStackId, Int32 citsStackId, Bool isSupportDR);

    // GPS, 맵매칭 해제
    void ReleaseGpsMM();

    // TVAS 모듈 객체 생성 & 초기화
    Bool InitProtocol(PNAVIMODULE_INIT pNaviInit);
    // TVAS 모듈 해제
    void ReleaseTvas();


    UInt32 InitNaviModule(PNAVIMODULE_INIT pNaviInit);

    //////////////////////////////////////////////////////////////////////////
    // 공통
    //////////////////////////////////////////////////////////////////////////

    static Bool GpsCallback(NMEA *nmea, NMEA_ID id);

    //Sound 상태 변경시 호출 되는 콜백 함수
    static void SoundCallback(Int32 nChannel, NeSoundStatus eStatus);

    // Render Callback (for 2D 지도만 사용됨)
    static Bool RenderCallback(void* pParamReq, void* pParamRes, void* pMapRes);

    //
    static Bool SDICallback(Int32 nMsg, Long lParam1, Long lParam2, LPVOID lpParam);

    //UI 콜백 메세지를 보낸다.
    Bool SendMessgeCallback(Int32 nMsg, Long lParam1=0, Long lParam2=0, LPVOID lpParam=NULL);

    // 버전 정보 전달 받는다.
    Bool API_GetVersion(PAPI_GET_VERSION_REQ pRequest, PAPI_GET_VERSION_RES pResult);

    // UI 콜백함수를 설정한다.
    void SetNaviUpdateCallback(LPCALL_NAVIUPDATE_PROC pfnProc);

    Int32 m_nInitFlag;
    LPCALL_NAVIUPDATE_PROC	UpdateNavi;		//엔진에서 UI로 업데이트 보낼 콜백함수


/** START - Modified by Jungjae.Lee in SKP(2014.12.2)
 *  Comment : RemoteUpdate ￄￚﾵ￥ ￃ￟ﾰﾡ
 */
    LPCALL_MAP_STATUS		MapStatusCallback;

/**
 *  END - Modified by Jungjae.Lee in SKP(2014.12.2)
 */

    //////////////////////////////////////////////////////////////////////////
    // GPS API
    //////////////////////////////////////////////////////////////////////////

    // Nmea 데이터를 입력한다. (안드로이드 용)
    Bool API_InputGpsNmea(PAPI_INPUT_GPSNMEA_REQ pRequest, PAPI_INPUT_GPSNMEA_RES pResult);
    Bool API_InputLocation(PAPI_INPUT_LOCATION_REQ pRequest, PAPI_INPUT_GPSNMEA_RES pResult);

    // GPS가 잡히지 않을때 LBS 위치를 설정한다. (기존 맵매칭 정보는 초기화 된다. 만약 GPS가 수신되면 LBS 좌표는 무시된다.)
    Bool API_InputLbsPosition(PAPI_INPUT_LBSPOSITION_REQ pRequest, PAPI_INPUT_LBSPOSITION_RES pResult);

    // GPS 위성 정보를 얻는다.
    Bool API_GetSatelliteInfo(PAPI_GET_SATELLITEINFO_REQ pRequest, PAPI_GET_SATELLITEINFO_RES pResult);


public:
    // API : 해당 World point가 국가 영역인지 체크한다.
    Bool API_IsCountryArea(PAPI_IS_COUNTRYAREA_REQ pRequest, PAPI_IS_COUNTRYAREA_RES pResult);

    // API : 경위도 좌표를 World 좌표로 변환한다.
    Bool API_LONnLATToCoord(PAPI_LONNLAT_TOCOORD_REQ pRequest, PAPI_LONNLAT_TOCOORD_RES pResult);

    // API : World 좌표를 경위도 좌표로 변환한다.
    Bool API_CoordToLONnLAT(PAPI_COORD_TOLONNLAT_REQ pRequest, PAPI_COORD_TOLONNLAT_RES pResult);

    // API : (Tmap)경위도 좌표를 World 좌표로 변환한다.
    Bool API_TLONnLATToCoord(PAPI_TLONNLAT_TOCOORD_REQ pRequest, PAPI_TLONNLAT_TOCOORD_RES pResult); //ssh

    // API : (Tmap)World 좌표를 경위도 좌표로 변환한다.
    Bool API_TCoordToLONnLAT(PAPI_TCOORD_TOLONNLAT_REQ pRequest, PAPI_TCOORD_TOLONNLAT_RES pResult); //ssh

    // API : (Tmap) 좌표 변환 통합 함수
    Bool API_CoordTransform(PAPI_COORDTRANS_REQ pRequest, PAPI_COORDTRANS_RES pResult);

    Int32 GetCommonPOIData(stPOIInfo *pPOIInfoData, Int32 nCount, Int32 m_iSortType, Int32 m_iSearchType, Int32 m_iOilType);

    // 맵 매칭 정보를 화면에 표출한다.
    Bool API_SetMMDebugStatus(PAPI_SET_MM_DEBUG_STATUS_REQ pRequest, PAPI_SET_MM_DEBUG_STATUS_RES pResult);

    Bool API_GetMapMatchPositionDrawingDatas(PAPI_GET_POSITION_DRAWING_DATA_REQ pRequest, PAPI_GET_POSITION_DRAWING_DATA_RES pResult);
    Bool API_GetMapMatchPositionDrawingDatasCount(PAPI_GET_POSITION_DRAWING_DATA_REQ pRequest, PAPI_GET_POSITION_DRAWING_DATA_RES pResult);
    
    Bool API_SetRoadNetworkTileData(PAPI_SET_ROAD_NETWORK_TILE_REQ pRequest, PAPI_SET_ROAD_NETWORK_TILE_RES pResult);

    // API : 플로그램 종료시 렌더쓰레드가 종료 시켜야 함.
    DOUBLE_VERTEX m_wcMap;   //지도 중심좌표(우선 Map모듈에서 지원하지 않아 임시 변수로 유지한다.)
    Int32 m_nAngleMap;	//지도 각도(우선 Map모듈에서 지원하지 않아 임시 변수로 유지한다.)
    Int32 m_nLevelMap;	//지도 레벨(우선 Map모듈에서 지원하지 않아 임시 변수로 유지한다.)

    MAPADDRESS_INFO			m_mapCurrentAreaInfo;

    // Auto Zoom
//    UInt32                    m_nRouteRunState;
//    UInt32					m_uAutoZoomDelayTick;
//    NsTmapLevelConfig       m_stTmapLevelConfig;
//    int						m_nDriveAutoState;

    Int32					m_nViewLevel;
    Int32					m_nViewSubLevel;

//    // Auto Zoom 신규
//    Bool                    m_bEnableAutoZoom;
//    Int32                    m_nAutoZoomTiltMode;
//    Int32                    m_nAutoZoomLevelMode;

    // Map Config 관련
    Int32					m_nIdxSelectMapConfig;			// 선택된 주간 맵 컨피그 인덱스
    Int32					m_nIdxNightMapConfig;			// 야간 맵 컨피그 인덱스
    Int32					m_nIdxSelectSymbolConfig;		// 선택된 주간 심볼 컨피그 인덱스
    Int32					m_nIdxNightSymbolConfig;		// 야간 심볼 컨피그 인덱스
    Bool					m_bAutoNightConfig;				// 주/야간 컨피그 자동 설정
    Bool					m_bNightConfig;					// 주/야간 컨피그 설정 상태

    // 경로 변경 확인을 위한 linkID 리스트
    std::vector<UInt16>     lastComparableLinkIdList;

    char*                   lastMainRoadName[3];

    UInt8                   uReRouteType;						// 재탐색 유형 (없음(0), 정주기(1), 사용자(2), 이탈재탐색(2))
    UInt8                   uDestSearchDetailFlag;              // RC만 재계산(0: None, 1: Rc만 재계산)
    Bool                    isRouteOptionChanged;			    // 사용자 다른 경로 재탐색 클릭여부 (default : false)
    Bool                    isFavoriteRouteSelected;            // 즐겨찾는 경로 주행 여부
    Int32                   selectIndex;

    UInt8                   bNeedToPlayReRouteStartVoiceGuidance; // 경로 재탐색시 경로 안내 출력 여부 체크 Flag
    Bool                    bIsEqualsLinkIdList;                // 재탐색시 링크iD리스트 변경여부
    Bool                    bIsMainRoadChanged;                 // 재탐색시 주요도로 변경여부
    Bool                    bIsRecommandToAlternative;          // 기존경로에서 대안경로로 경로변경 여부.

    Bool                    bIsDrawGoalOppositeSide;            // 목적지 건너편 회색 경로선 draw여부.
    UInt8                   ucGoalDirection;                    // 목적지 위치 정보(0:방향성 재탐색을 다시하지 않아도 됨, 1:방향성 재탐색 요청을 해야함)
    Bool                    bIsSupportDR;                       // DR관련 지원 여부

    // 현위치의 행정 명칭을 얻는다. (시도 경계를 지났는지 체크 한다.)
    Bool GetCurrentAddressInfo(DOUBLE_VERTEX wcCurrent, MAPADDRESS_INFO *pAddressInfo);

    //////////////////////////////////////////////////////////////////////////
    // 경로탐색 모듈 관련
    //////////////////////////////////////////////////////////////////////////

    // 경로 탐색 결과 중 하나를 선택한다.
    Bool API_SelectRoute(PAPI_SELECTROUTE_REQ pRequest, PAPI_SELECTROUTE_RES pResult);

    // 경로 탐색 결과 중 하나를 선택한다.(선택되지 않는 경로는 초기화 된다.)
    Bool API_ApplySelectRoute(PAPI_APPLY_SELECTROUTE_REQ pRequest, PAPI_APPLY_SELECTROUTE_RES pResult);

    // 경로를 취소한다.
    Bool API_CancelRoute(PAPI_CANCELROUTE_REQ pRequest, PAPI_CANCELROUTE_RES pResult);

    // 경로 상태 여부를 얻는다.
    Bool API_IsRoute(PAPI_ISROUTE_REQ pRequest, PAPI_ISROUTE_RES pResult);

    // 경로 탐색중인지 여부를 얻는다.
    Bool API_GetIsRouting(PAPI_GET_ISROUTING_REQ pRequest, PAPI_GET_ISROUTING_RES pResult);

    // 재탐색을 막는다
    Bool API_BlockReroute(PAPI_BLOCKREROUTE_REQ pRequest, PAPI_BLOCKREROUTE_RES pResult);

    // 경로 요약 기본 정보를 얻는다.
    Bool API_GetRouteSummaryInfo(PAPI_GET_ROUTESUMMARY_INFO_REQ pRequest, PAPI_GET_ROUTESUMMARY_INFO_RES pResult);

    // add summary info
    // 경로 요약 기본 정보를 얻는다. (Tmap 용)
    Bool API_GetTmapRouteSummaryInfo(PAPI_GET_TMAPROUTESUMMARY_INFO_REQ pRequest, PAPI_GET_TMAPROUTESUMMARY_INFO_RES pResult);

    // 경로 요약정보 리스트를 얻는다. (전체 경로 표출용)
    Bool API_GetRouteSummaryList(PAPI_GET_ROUTESUMMARY_LIST_REQ pRequest, PAPI_GET_ROUTESUMMARY_LIST_RES pResult);

    // add summary list
    // 경로 요약정보 리스트를 얻는다. (Tmap 용)
    Bool API_GetTmapSummaryList(PAPI_GET_TMAPSUMMARY_LIST_REQ pRequest, PAPI_GET_TMAPSUMMARY_LIST_RES pResult);

    // 목적지별 소요시간/거리 정보를 얻는다.
    Bool API_GetMultiDestCostInfoList(PAPI_GET_ROUTE_DEST_COST_INFO_REQ pRequest, PAPI_GET_ROUTE_DEST_COST_INFO_RES pResult);
    // 경로 소통정보 ALL 리스트를 얻는다.
    Bool API_GetRouteTrafficAllList(PAPI_GET_ROUTETRAFFIC_ALL_LIST_REQ pRequest, PAPI_GET_ROUTETRAFFIC_ALL_LIST_RES pResult);

    // 경로 소통정보 GP 리스트를 얻는다.
    Bool API_GetRouteTrafficGpList(PAPI_GET_ROUTETRAFFIC_GP_LIST_REQ pRequest, PAPI_GET_ROUTETRAFFIC_GP_LIST_RES pResult);

    // 경로 안내 정보를 얻는다.
    Bool API_GetRouteGuidance(PAPI_GET_ROUTEGUIDANCE_REQ pRequest, PAPI_GET_ROUTEGUIDANCE_RES pResult);

    // 모의주행 안내 정보를 얻는다.
    Bool API_GetRouteGuidanceSimulator(PAPI_GET_ROUTEGUIDANCE_SIMULATOR_REQ pRequest, PAPI_GET_ROUTEGUIDANCE_SIMULATOR_RES pResult);

    // 경로 턴정보 리스트를 얻는다. (주행 중 표출용)
    Bool API_GetRouteTBTList(PAPI_GET_ROUTETBT_LIST_REQ pRequest, PAPI_GET_ROUTETBT_LIST_RES pResult);

    // TBT 정보의 전체 Count 정보를 얻는다.
    Bool API_GetAllTBTCount(PAPI_REQUEST pRequest, PAPI_GET_ALLTBTCOUNT_RES pResult);

    // 전체 TBT 정보를 Index 정보 기반으로 얻는다.
    Bool API_GetTBTDataByIndex(PAPI_GET_TBTDATABYINDEX_REQ pRequest, PAPI_GET_TBTDATABYINDEX_RES pResult);

    // 경로 안내 설정값을 얻는다.
    Bool API_GetGuidanceConfig(PAPI_GET_GUIDANCECONFIG_REQ pRequest, PAPI_GET_GUIDANCECONFIG_RES pResult);

    // 경로 안내 설정값을 세팅한다.
    Bool API_SetGuidanceConfig(PAPI_SET_GUIDANCECONFIG_REQ pRequest, PAPI_SET_GUIDANCECONFIG_RES pResult);

    // 경로 개수를 얻는다.
    Bool API_GetRouteCount(PAPI_GET_ROUTECOUNT_RES pResult);

    // TVAS data를 세팅한다.
    Bool API_SetTvasDataMemory(PAPI_SET_TVASDATA_MEMORY_REQ pRequest, PAPI_SET_TVASDATA_RES pResult);

    // TVAS data를 추가한다.
    Bool API_AddTvasDataMemory(PAPI_ADD_TVASDATA_MEMORY_REQ pRequest, PAPI_SET_TVASDATA_RES pResult);

    // TVAS 재탐색을 위한 조건 데이터를 얻는다.
    Bool API_GetTvasReRouteData(PAPI_GET_TVASREROUTEDATA_REQ pRequest, PAPI_GET_TVASREROUTEDATA_RES pResult);

    // TVAS 재탐색을 위한 RID 정보를 얻는다.
    Bool API_GetTvasReRouteRIDInfo(PAPI_GET_TVASREROUTERIDINFO_REQ pRequest, PAPI_GET_TVASREROUTERIDINFO_RES pResult);

    // TVAS 재탐색을 위한 RID 데이터를 얻는다.
    Bool API_GetTvasReRouteRIDData(PAPI_GET_TVASREROUTERIDDATA_REQ pRequest, PAPI_GET_TVASREROUTERIDDATA_RES pResult);

    // TVAS 시도경계 데이터를 얻는다.
    Bool API_GetTvasCityBoundaryData(PAPI_GET_TVASCITYBOUNDARYDATA_REQ pRequest, PAPI_GET_TVASCITYBOUNDARYDATA_RES pResult);

    // AndoDB version을 얻는다. ssh
    Bool API_GetVersionSafeDB(PAPI_GET_SAFE_VERSION_REQ pRequest, PAPI_GET_SAFE_VERSION_RES pResult);

    // notice Ando BackUPfile to engine  ssh
    Bool API_CommitSafeFile(PAPI_COMMIT_SAFE_FILE_REQ pRequest, PAPI_COMMIT_SAFE_FILE_RES pResult);

    // make Ando BackUPfile ssh
    Bool API_MakeSafeFile(PAPI_MAKE_SAFE_FILE_REQ pRequest, PAPI_MAKE_SAFE_FILE_RES pResult);

    // cctv info
    Bool API_GetCctvInfo(PAPI_GET_CCTVINFO_REQ pRequest, PAPI_GET_CCTVINFO_RES pResult);

    Bool API_GetServiceAreaInfo(PAPI_GET_SERVICEAREA_INFO_REQ pRequest, PAPI_GET_SERVICEAREA_INFO_RES pResult);
    // gas station
    Bool API_GetGasStationInfo(PAPI_GET_GASSTATION_INFO_REQ pRequest, PAPI_GET_GASSTATION_INFO_RES pResult);

    // electonic station
    Bool API_GetEVStationInfo(PAPI_GET_EVSTATION_INFO_REQ pRequest, PAPI_GET_EVSTATION_INFO_RES pResult);

    Bool API_SetEV(PAPI_SET_EV_REQ pRequest, PAPI_SET_EV_RES pResult);

    Int32 GetRouteCountByOption(UInt32 uRouteOption, UInt32 *pMultiOption, Int32 *pRouteOption, Int32 *pRouteFee, Int32 *pRouteTraffic);
    Bool IsValidePositionByRoutting(Int32 nPosInfoCnt, NsSchPosInfo *pnsPosInfo, Bool bStopPosInfoFlag, Int32 *pnErrCode);
    Bool SetTvasDataLocked(char* data, int routeCount, int tvasSize[], int options[], int selectedIndex=0, int nCurrentEnergy=0);
    Bool AddTvasDataLocked(char* data, int option, int tvasSize, int nCurrentEnergy);
    void DeleteAllCandidate();
    Bool SelectRouteLocked(Int32 nIdxSelect, Bool bApply, Bool bPlayRouteRoadSummary, Bool isNuguTTSVoiceSpeak, Bool isFirstSearch=FALSE);
    void CheckRerouteChangeMainRoad(const TVS_Data* pTvas);


    //////////////////////////////////////////////////////////////////////////
    // 맵매칭 모듈 관련
    //////////////////////////////////////////////////////////////////////////
    NcMapMatch					*m_pMapMatch;
    NcGpsDrawDataQueue			m_GpsDrawQue;

    NsGpsParsedData				m_CurParsedData;	//현재 GPS 데이터
    NsGpsDrawData				m_CurGpsDrawData;	//그려야 할 GPS 데이터
    NsMatchingData				m_MatchData;		//맵매치 데이터
    weak_ptr<LocalLinkV2>       m_localLinkV2;     // 로컬 맵매칭 데이터

    Int32						m_nGpsTrack;		// 경로 주행 좌표 수집 개수 (큐 개수 체크 위함)
    SGL_mutex*					m_pGpsTrackLock;	// 경로 주행 좌표 동기
    Int32						m_nMaxGPSQueueCount;

    NeStatusMM					m_MMStatus;			//맵매칭 상태
    Bool						m_bMapMatch;		//맵매칭 여부
    // kiwoo 12.10.31 마지막 지나간 TollID ( T map 용 )
    UInt16						m_nLastTollID;
    // 재탐색 할 때 한 번만 긁어오기 위해 마지막에 매칭 된 TVAS Link ID를 저장해 둔다.
    Int32						m_nLastMatchingTvasLinkIdx;

    Int32						m_nLastMatchingTvasRpLinkIndex;

    SGL_mutex*                  m_pTvasLock;

    Bool ReceiveGps(NMEA *nmea, NMEA_ID id);
    Bool ReceiveGps(float accuracy,
                        double altitude,
                        float bearing,
                        long elapsedRealtimeNanos,
                        DOUBLE_VERTEX wp,
                        const Char *provider,
                        float speed,
                        long long time,
                        int satellightCount,
                        int isDRGps,
                        int activityType,
                        float verticalAngle);

    void SetNight(NMEA &nmea, DOUBLE_VERTEX wp);
    void MakeGpsClockVoice(CRuntimeEnv &RuntimeEnv);
    NMEA_DateTime GetNmeaDateTime(long time, int milisecond);

    Bool MapMatch(NMEA_DateTime time, Bool bSignalGood);
    void StoreLinkInformation(TVS_Data* pTvas, NsGpsParsedData *pGpsParsedData);
    void StoreLocalMapMatchLinkInformation(NsGpsParsedData *pGpsParsedData);

    Int32 WriteRouteTrackFile(Int32 nCnt);
    Bool IsGpsGood(NMEA *pNmea);
    Int32 EncodeDay(Int32 Day);
    eHoliday_Type GetHolidayInfo(NMEA_DateTime time);
    SGL_SYSTEMTIME m_sQuitTime;	//어플리케이션 종료 시간

    // TVAS 탐색(재탐색)을 위한 GPS 데이터를 얻는다.
    Bool API_GetTvasGpsData(PAPI_GET_TVASGPSDATA_REQ pRequest, PAPI_GET_TVASGPSDATA_RES pResult);

    // TVAS 버텍스 궤적 데이터를 얻는다.
    Bool API_GetTvasVertexData(PAPI_GET_TVASVERTEXDATA_REQ pRequest, PAPI_GET_TVASVERTEXDATA_RES pResult);
    // TVAS 버텍스 궤적 데이터를 얻는다.
    Bool API_GetTvasVertexNextData(PAPI_GET_TVASVERTEXNEXTDATA_REQ pRequest, PAPI_GET_TVASVERTEXNEXTDATA_RES pResult);

    Bool API_GetTvasLinkData(API_REQUEST* pRequest, PAPI_GET_TVASLINKDATA_RES pResult);
    Bool API_GetTvasLinkNextData(API_REQUEST* pRequest, PAPI_GET_TVASLINKDATA_RES pResult);
    Bool API_GetTvasAllLinkData(API_REQUEST* pRequest, PAPI_GET_TVASLINKDATA_RES pResult);

    // TVAS 버텍스 궤적 데이터 리스트
    LinkedMap<DOUBLE_VERTEX, TVASVERTEX_DATASET> m_passedVertexMap;

    // TVAS Link 궤적 데이터 리스트
    LinkedMap<UInt32, TVAS_LINK_DATASET> m_passedLinkMap;

    // MapVersion
    Int32 mapVersion;

    // 마지막 TVAS 버텍스 인덱스
    Int32			m_nLastTvasVertexIdx;
    // 마지막 TVAS 타일 인덱스
    UInt16			m_nLastTvasTileIdx;
    // 마지막 RID
    Int32			m_nLastRID;
    // 현재 VERTEX 진입시간. TFS 통신시 사용할 시간(2003년 1월 1일 기준 gps time)
    UInt32 m_nVertexEnteringTime;

    // 경로 주행 GPS Track 좌표 파일을 얻는다.
    Bool API_GetRouteTrack(PAPI_GET_ROUTETRACK_REQ pRequest, PAPI_GET_ROUTETRACK_RES pResult);
    Bool API_SetGPSQueueCount(PAPI_SET_GPSQUEUE_COUNT_REQ pRequest, PAPI_SET_GPSQUEUE_COUNT_RES pResult);

    Bool API_GetTvasGpsDataCount(PAPI_REQUEST pRequest, PAPI_GET_TVASGPSDATACOUNT_RES pResult);
    Bool API_GetTvasGpsDataByIndex(PAPI_GET_TVASGPSDATABYIDX_REQ pRequest, PAPI_GET_TVASGPSDATABYIDX_RES pResult);

    Bool API_SetSafeDrivingDbFilePathInfo(PAPI_SET_SAFEDRIVING_FILE_REQ pRequest, PAPI_SET_SAFEDRIVING_FILE_RES pResult);
    
    Bool API_SetHolidayConfigFilePath(PAPI_SET_HOLIDAY_CONFIG_FILE_REQ pRequest, PAPI_SET_HOLIDAY_CONFIG_FILE_RES pResult);

    Bool API_GetTvasVertexArray(PAPI_GET_TVASVERTEXARRAY_REQ pRequest, PAPI_GET_TVASVERTEXARRAY_RES pResult);

    Bool API_GetRouteRenderData(PAPI_GET_ROUTERENDERDATA_REQ pRequest, PAPI_GET_ROUTERENDERDATA_RES pResult);
    Bool API_GetRouteData(PAPI_GET_ROUTER_DATA_REQ pRequest, PAPI_GET_ROUTER_DATA_RES pResult);
    Bool API_GetRouteDataDynamic(PAPI_GET_ROUTER_DATA_REQ pRequest, PAPI_GET_ROUTER_DATA_DYNAMIC_RES pResult);

    Bool API_SetMapMatchingDebuggerActive(PAPI_SET_MAPMATCHING_DEBUGGER_ACTIVE_REQ pRequest, PAPI_SET_MAPMATCHING_DEBUGGER_ACTIVE_RES pResult);

    Bool API_GetTunnelInfo(PAPI_REQUEST pRequest, PAPI_GET_TUNNEL_INFO_RES pResult);

    Bool API_GetMatchedPoint(PAPI_GET_MATCHED_POINT_REQ pRequest, PAPI_GET_MATCHED_POINT_RES pResult);
    Bool API_GetAutoDrivePosition(PAPI_GET_AUTO_DRIVE_POSITION_REQ pRequest, PAPI_GET_AUTO_DRIVE_POSITION_RES pResult);

    Bool API_GetDecodeOpusData(PAPI_DECODE_OPUS_DATA_REQ pRequest, PAPI_DECODE_OPUS_DATA_RES pResult);

    Bool API_GetTvasLinkInfo(PAPI_GET_TVAS_LINK_INFO_REQ pRequest, PAPI_GET_TVAS_LINK_INFO_RES pResult);
    Bool API_GetTvasLinkTraffic(PAPI_GET_TVAS_LINK_TRAFFIC_REQ pRequest, PAPI_GET_TVAS_LINK_TRAFFIC_RES pResult);

    Bool API_SetTtsScript(PAPI_GET_SET_TTS_SCRIPT_REQ pRequest, PAPI_GET_SET_TTS_SCRIPT_RES pResult);
    Bool API_SetTtsLanguage(PAPI_GET_SET_TTS_LANGUAGE_REQ pRequest, PAPI_GET_SET_TTS_LANGUAGE_RES pResult);

    //////////////////////////////////////////////////////////////////////////
    //경로안내
    //////////////////////////////////////////////////////////////////////////
    CRGServiceManager *					m_pRGServiceManager;

    Bool								m_bIsRoute;
    Int32								m_uSaveMutiRouteOption;
    Int32								m_nRouteGuidanceStatus; //경로 안내 시작시 맨트 할지 여부(0:초기,1:탐색,2:재탐색,3:시작안내맨트)
    UInt16								m_uLastCityBoundaryCode;
    NeCarClass							m_eCarClass;//자동차 종별(MakeRGInfo 할때 인자로 사용)

    char szSDIVer[16];
    char szLocalVer[16];

    //////////////////////////////////////////////////////////////////////////
    // Sound & TTS 관련
    //////////////////////////////////////////////////////////////////////////
    // 시나리오 음성을 출력한다.  (비동기 함수)
    Bool API_SoundPlayScenario(PAPI_SOUND_PLAYSCENARIO_REQ pRequest, PAPI_SOUND_PLAYSCENARIO_RES pResult);
    // 현재 안내 음성을 출력한다. (1회 음성 출력하면 초기화 됨) (비동기 함수)
    Bool API_SoundPlayGuidance(PAPI_SOUND_PLAYGUIDANCE_REQ pRequest, PAPI_SOUND_PLAYGUIDANCE_RES pResult);
    // 현위치 기준으로 다음 안내점까지 음성을 출력한다. (n회 음성 출력이 가능함) (비동기 함수)
    Bool API_SoundPlayNextGP(PAPI_SOUND_PLAYNEXTGP_REQ pRequest, PAPI_SOUND_PLAYNEXTGP_RES pResult);
    // 음성 출력을 중지한다. (비동기 함수)
    Bool API_SoundStop(PAPI_SOUND_STOP_REQ pRequest, PAPI_SOUND_STOP_RES pResult);
    // 음성 출력 볼륨을 설정한다.
    Bool API_SoundSetVolume(PAPI_SOUND_SETVOLUME_REQ pRequest, PAPI_SOUND_SETVOLUME_RES pResult);
    // 음성 출력 중 인지 체크 한다.
    Bool API_SoundIsPlaying(PAPI_SOUND_ISPLAYING_REQ pRequest, PAPI_SOUND_ISPLAYING_RES pResult);
    
    DECLARE_SINGLETON(CNaviModule)
private:
    Bool DAL_InitRGData();
    Bool DAL_UnInitializeRGData();
    void UpdateVertexTraceInfo(TVS_Data* pTvas, NsGpsParsedData *pGpsParsedData);
    void UpdateVertexTraceInfo(NsGpsParsedData *pGpsParsedData);
    Int32 GetTvasVertexIndex(TVS_Data* pTvas, Int32 linkIndex, Int32 vertexIndex);
    void UpdateLastTvasVertexIndex(TVS_Data* pTvas);
    void SaveTvasUpdateTime(NsGpsParsedData * pCurrentGPSData);
    void InitCheckChangReRouteData();
    void FreeLastMainRoadName();
    bool HasDuplicatedVertex(TVASVERTEX_DATASET* vertex);

    INT32 GetGPType(TVS_Data& tvasData, INT32 linkIndex, INT16 turnCode);
    Bool IsServiceLink(Int32 nTurnCode);

    bool SetGpsTraceData(TVASGPS_DATASET *pRequest, NsGpsParsedData *pGpsInfo);
    Bool CheckTvasGpsData(NsGpsParsedData* pGpsInfo, Int32 uFirstTime, Int32 uLastTime, Int32 nIndex);
    void ClearGpsTraceData();
private:
    long long lastGpsReceivedTime;
    DOUBLE_VERTEX lastGpsPosition;
    long lastSpeedInKmPerHour;
    float lastBearing;
    float lastSpeed;
    DOUBLE_VERTEX lastMatchedPoint;

    int m_nLastMin;

    LowPassFilter filter;

    UInt32 uLastTvasUpdateTime; // 마지막 Tvas update time
    UInt32 uTotalVertexPassingEstimationTime; // 현재까지의 Vertex 예상 통과시간.

    int m_nRouteOption[3];
    NeVirtualGpsType lastVirualStatus;
public:
    void clearConfiguration();
    void applyConfiguration();

private:
    Bool m_configurationChanging;

public:
    void setTileCachePolicy(Int32 cachePolicy);

private:
    std::string safeDrivingDbFilePath;
    std::string safeDrivingDbIndexFilePath;
    
    std::string holidayConfigFilePath;
    
public:
    const char* getSafeDrivingDbFilePath();
    const char* getSafeDrivingDbIndexFilePath();

public:
    UInt64 m_nRerouteStartTime;

    void GetRenderData(TVS_Data* tvasData, ROUTE_RENDER_DATA *pRenderData);
    void GetTrafficData(TVS_Data &tvasData, std::vector<stTmapTrafficItem> *pTrafficDataList);
    void GetRoadData(TVS_Data &tvasData, std::vector<stTmamRoadItem> *pRoadDataList);
    void GetRoadAccidentInfo(TVS_Data &tvasData, std::vector<stTmapRoadAccidentItem> *pRoadAccidentInfo);
    void GetGuidePoints(TVS_Data &tvasData, std::vector<stTmamGuidePoint > *pGuidePoints);

    int GetRouteSummaryList(TVS_Data &tvasData, stTmapSummaryItem *pList);
    void GetRouteSummaryList(TVS_Data &tvasData, std::vector<stTmapSummaryItem> *pList);

    void GetTmapSummaryInfo(TVS_Data &tvasData, stTmapSummaryBaseInfo *pInfo, int currentEnergy = 0);

    void
    AddWayPoint(flatbuffers::FlatBufferBuilder& builder, std::vector<flatbuffers::Offset<vsm::route::PositionInfo>> &vector, char *name, double x, double y);

    int GetGasStationInfo(TVS_Data &tvasData, stGasStationInfo *pList);
    void GetGasStationInfo(TVS_Data &tvasData, std::vector<stGasStationInfo> *pList);

    int GetEVStationInfo(TVS_Data &tvasData, stEVStationInfo *pInfo);
    void GetEVStationInfo(TVS_Data &tvasData, std::vector<stEVStationInfo> *pList);

    int GetServiceAreaInfo(TVS_Data &tvasData, stServiceAreaInfo *pInfo);
    void GetServiceAreaInfo(TVS_Data &tvasData, std::vector<stServiceAreaInfo> *pList);

    int GetTvasLinkData(TVS_Data &tvasData, TVAS_LINK_DATASET *pInfo);
    void GetTvasLinkData(TVS_Data &tvasData, std::vector<TVAS_LINK_DATASET> *pList);

    int GetThemeRoadInfo(TVS_Data &tvasData, stThemeRoadInfo *pList);
    void GetThemeRoadInfo(TVS_Data &tvasData, std::vector<stThemeRoadInfo> *pList);

    TVS_RouteData5* GetMapLinkId(TVS_RouteData5 *pRouteData, UInt16 count, int vertexIndex);

    PositionProvider getProviderType(const Char *provider);

private:
    Bool SetRouteSummary(TVS_Data &tvasData, stTmapSummaryItem* summaryList, int nIdx);
    void SetGasStationInfo(TVS_Data &tvasData, stGasStationInfo* gasStationInfo, int nIdx, DOUBLE_VERTEX* lastVertex);
    Bool SetEVStationInfo(TVS_Data &tvasData, stEVStationInfo* evStationInfo, int nIdx, int *nSetIdx, DOUBLE_VERTEX* lastVertex, int brandInfoOffset=0);
    void SetServiceAreaInfo(TVS_Data &tvasData, stServiceAreaInfo* saInfo, int nIdx);
    void SetTvasLinkData(TVS_Data &tvasData, TVAS_LINK_DATASET* linkData, int nIdx);
    void SetThemeRoadInfo(TVS_Data &tvasData, stThemeRoadInfo* themeRoadInfo, int nIdx);

    vector<NearLinkInfo> m_neighborLinkList;
    void GetNearlinkID(const stDriveInfo * pInfo);
    void GetAndoNearlinkID(const stDriveInfo * pInfo);
    Bool SearchAndoNearLink(vector<NearLinkInfo>* result, vector<NearLinkSearchInfo>* listToSearch);
    void SetNearLinkID(PAPI_GET_ROUTEGUIDANCE_RES pResult);
};

#endif // __NAVIMODULE_H__
