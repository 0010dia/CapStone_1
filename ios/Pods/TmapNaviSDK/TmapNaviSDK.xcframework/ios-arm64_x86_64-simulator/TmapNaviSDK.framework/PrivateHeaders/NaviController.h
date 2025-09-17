/**
 * T map 4.0 Navi Engine Controller header
 * @author flintlock
 *
 */
#ifndef __NAVICONTROLLER_H__
#define __NAVICONTROLLER_H__

#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <map>

#include "navimodule_inc.h"
#include "NaviDocument.h"
#include "MapMatchingDebuggerInterface.h"

// 로그 필터링(레벨)
enum TMAP4LOG_DEF
{
    TMAP4LOG_NOTUSED = 0,   // 로그 사용하지 않음
    TMAP4LOG_UNIQUE,        // 1회성 함수(생성,소멸)
    TMAP4LOG_SELDOM,        // 거의 호출되지 않음
    TMAP4LOG_SOMETIMES,     // 가끔 호출됨
    TMAP4LOG_OFTEN,         // 자주 호출됨(디버그에 문제됨)
    TMAP4LOG_ALWAYS           // 항상 호출됨(디버그에 방해됨)
};

// Enable - Function Log
#define __DEBUG_FUNCTION__
#define Tmap4LogLevel TMAP4LOG_SOMETIMES

inline
void __cdecl sglDebugPrintTmap4(int nLevel, const TChar *format, ...)
{
    if (nLevel > Tmap4LogLevel)
    {
        return;
    }

#if defined(WIN32) && defined(UNICODE)
    // TODO: Not Implemented
#else
    va_list args;
    va_start(args, format);
    VsmLog_vprintf(VSM_LOG_DEBUG,
                   VSM_LOG_DEFAULT_LOGTAG,
                   format,
                   args);
    va_end(args);
#endif
}

#ifdef DEBUG
#define __DEBUG__
#endif

#ifdef __DEBUG__
#ifdef __DEBUG_FUNCTION__

// NaviController
#define ta_navicall(nLevel, ...) \
                {sglDebugPrintTmap4(nLevel,_T("*** Call CNaviController::%s("),__FUNCTION__);\
                sglDebugPrintTmap4(nLevel,__VA_ARGS__);\
                sglDebugPrintTmap4(nLevel,_T(")"));};

#else
#define ta_navicall(nLevel,...) ((void)0)
#endif

#define ta_call(...) SGL_DBGPRINT(__VA_ARGS__)

#define ta_error(...) \
            {SGL_DBGPRINT(_T("\n\n*** [ERROR] Function:%s (file:%s, line:%d)\n*** "),__FUNCTION__,__FILE__,__LINE__);\
            SGL_DBGPRINT(__VA_ARGS__);\
            SGL_DBGPRINT(_T("\n\n"));};

#else
#define ta_call(...)     ((void)0)
#define ta_error(...)    ((void)0)
#define ta_navicall(...) ((void)0)
#endif


#define INaviController CNaviController::getInstance()

enum NAVICTRL_ERROR
{
    E_NAVICTRL_SUCCESS = 0,
    E_NAVICTRL_UNKNOWN_ERR = -1,
    E_NAVICTRL_CREATE_ERR = -2,
    E_NAVICTRL_INITSDL_ERR = -3,
    E_NAVICTRL_INITSGL_ERR = -4,
    E_NAVICTRL_INITENGINE_ERR = -5,
    E_NAVICTRL_INITPIXELFORMAT_ERR = -6,
    E_NAVICTRL_INITDOC_ERR = -7
};

enum NMEA_RESULT
{
    NEEDLESS = 0,
    NOT_VALID = 1,
    VALID = 2
};

enum MAPVIEW_LEVEL_TYPE
{
    ZOOM_OUT = 1,
    ZOOM_IN,
    ZOOM_CUSTOM
};

enum BIRDVIEW_ANGLE_TYPE
{
    BIRDVIEW_ANGLE_DOWN = 1,
    BIRDVIEW_ANGLE_UP,
    BIRDVIEW_ANGLE_CUSTOM
};

// NaviEngine﾿ﾡﾼﾭ Java﾿ﾡ ￄ￝ﾹ￩
typedef int (*LPCALL_JavaCallback)(int type, int lParam, int wParam);

#define INaviController CNaviController::getInstance()

class CNaviController
{
    friend class CNaviControllerPrivate;

    /** START - Modified by JungJae.Lee in SKP (2014.12.04)
     *  Comment : InitEngine Status
     */
private:
    static CNaviController *s_pNaviController;

public:
    struct InitParam
    {
        InitParam()
                : appName(NULL), appConfigId(NULL), appTagId(NULL), useCDN(FALSE), screenWidth(480), screenHeight(800), initCallback(NULL), roadNetworkRequestCallback(NULL), userData(NULL)
        {
        }

        const Char *appName;
        const Char *appConfigId;
        const Char *appTagId;

        struct UrlParam
        {
            UrlParam()
                    : protocol(NULL), host(NULL), portNumber(-1), pathPrefix(NULL)
            {
            }

            const Char *protocol;
            const Char *host;
            Int32 portNumber;
            const Char *pathPrefix;
        };

        struct PathParam
        {
            PathParam()
                    : onlineMapPath(NULL), offlineMapPath(NULL), cachePath(NULL), dataPath(NULL)
            {
            }

            const Char *onlineMapPath;
            const Char *offlineMapPath;
            const Char *cachePath;
            const Char *dataPath;
        };

        UrlParam url;
        Bool useCDN;
        PathParam dataPath;

        struct SSLParam
        {
            SSLParam()
                    : sslVerifyPeer(TRUE), sslVerifyHost(TRUE), caCertFile(NULL)
            {
            }

            // verifies the authenticity of the peer's certificate
            Bool sslVerifyPeer;

            // verifies that the server cert is for the server it is known as.
            Bool sslVerifyHost;

            // a zero terminated string naming a file holding one or more certificates to verify the peer with
            const Char *caCertFile;
        };

        SSLParam sslOptions;

        Int32 screenWidth;
        Int32 screenHeight;

        // callbacks
        LPCALL_INIT_ENGINE initCallback;
        LPCALL_REQUEST_ROAD_NETWORK_TILE_DATA roadNetworkRequestCallback;
        void *userData; // for roadNetworkRequestCallback

        // for NaviModule
        struct NavigationParam
        {
            NavigationParam()
                    : mdn(NULL), useLocalMapMatch(FALSE), useOpusCodec(TRUE), outSampleRate(24000), mapMatchingDebugger(NULL)
            {
            }

            MapMatchingDebuggerInterface *mapMatchingDebugger;
            const Char *mdn;
            Bool useLocalMapMatch;
            Bool useOpusCodec;
            Int32 outSampleRate;    // valid only if opus codec is enabled
            Int32 linkStackId;
            Int32 sdiStackId;
            Int32 citsStackId;
            Bool isSupportDR;
        };

        NavigationParam naviParam;
    };

    Bool GetTunnelInfo(DOUBLE_VERTEX &start, DOUBLE_VERTEX &end, Bool &isTunnel, Int32 &length, Char *roadName, Char *tunnelName, Char *tunnelId, std::vector<TUNNEL_LINK_INFO> &linkInfoList);

    Bool GetMatchedPoint(DOUBLE_VERTEX source, Int32 distance, Int32 &linkId, Int32 &vertexOffset, DOUBLE_VERTEX &result, Int32 &mesh, Int32 &dir, Int32 &absoluteVertexIndex);

    Bool GetAutoDrivePosition(Int32 speedInKmPerHour, DOUBLE_VERTEX &position, Int32 &newSpeed, Int32 &angle);

public:
    static CNaviController *createInstance();

    static CNaviController *getInstance();

    static void releaseInstance();

    Int32 InitEngine(const InitParam &param);

    void setNeedUpdate();
    /**
     *  END - Modified by JungJae.Lee in SKP (2014.12.04)
     */

private:
    CNaviController();

    virtual ~CNaviController();

public:
    void SetJavaCallback(LPCALL_JavaCallback pfnCallback);

    void UnlockNaviControllerMutexLock();

    Int32 InitEngineSound();

    void ReleaseEngineSound();

    static Int32 NaviCallback(Int32 msg, Long lParam1, Long lParam2, LPVOID lpParam);

    Bool GetSatelliteInfo(GPSSATELLITEINFO *pSatellite);

    Int32 InputGPSData(Char *nmeaData, int nmeaSize);

    Int32 InputLocationData(float accuracy,
                            double altitude,
                            float bearing,
                            long elapsedRealtimeNanos,
                            double latitude,
                            double longitude,
                            const Char *provider,
                            float speed,
                            long long time,
                            int satellite,
                            float gyroVerticalAngle,
                            int activityType,
                            bool isDRGps);

    void InputLbsPosition(Int32 wX, Int32 wY, Float fAngle);

    Bool GetGpsCurrentPosition(Int32 *wX, Int32 *wY);

    Bool GetGpsCurrentPosition(double *wX, double *wY);

    Int32 GetGpsCurrentAngle();

    Int32 GetGpsCurrentSpeed();

    Bool IsGPSNightNow();

    Bool SetNotMatchedFirstPosition(Int32 worldX, Int32 worldY);

    Bool GetRouteGuidance(stDriveInfo *pDriveInfo);

    Bool GetRouteGuidanceSimulator(Int32 eOption, Int32 speed, Int32 pos, stDriveInfo *pDriveInfo);

    Int32 GetVersionSafeDB();

    bool GetPathSafeDB(Char *sdiDBPath);

    bool GetPathSafeIndex(Char *sdiIndexPath);

    Bool CommitSafeFile();

    Bool MakeSafeFile(Byte *pData, Int32 isize);

    Int32 GetRouteCount();

    Int32 SetTvasData(char *data, Int32 *options, Int32 nRouteCnt, Int32 *tvasSize, Bool bIsReRoute, Int32 requestType = 1, Int32 destSearchDetailFlag = 0, Bool isRouteOptionChanged = FALSE, Bool isFavoriteRouteSelected = FALSE, int selectedIndex = 0, int currentEnergy = 0);

    Int32 AddTvasData(char *data, Int32 options, Int32 tvasSize, Int32 currentEnergy);

    Int32 GetTvasGpsData(TVASGPS_DATASET *pGPSData, Bool bIsFixedCycleReroute);

    TVASVERTEX_DATASET *GetTvasVertexData(Int32 *nSize);

    Bool GetTvasVertexNextData(Int32 *nSize, TVASVERTEX_DATASET *pData);

    Bool GetTvasLinkData(Int32 *nSize, TVAS_LINK_DATASET **pData);

    Bool GetTvasLinkNextData(Int32 *nSize, TVAS_LINK_DATASET *pData);

    TVAS_LINK_DATASET *GetTvasAllLinkData(Int32 *nSize);

    Bool GetTvasReRouteData(Int32 *nDataSize, Byte *pRouteData,
                            Byte *uOldRsdCode, Byte *uRsdCode, UInt16 *uLinkID, Int32 *uTileCode, Byte *uDirInfo, Int32 *uPosX, Int32 *uPosY,
                            UInt16 *uPassedTollID, Char *tollIdList = 0);

    Bool GetTvasReRouteRIDInfo(unsigned int *puCnt, int *puLastRid, Char *pzMapVer, unsigned int *puInitSrchLength, Char *pzInitSrchSessionID);

    Bool GetTvasReRouteRIDData(unsigned int nCnt, int *pRidList, int *pSecList);

    DOUBLE_VERTEX *GetTvasVertexArray(Int32 *nSize);

    Bool GetRouteRenderData(unsigned int *count, ROUTE_RENDER_DATA **renderData);

    static void ReleaseRouteRenderData(unsigned int count, ROUTE_RENDER_DATA *renderData);

    static void ReleaseRouteRenderSingleData(ROUTE_RENDER_DATA *renderData);

    Int32 GetTvasCityBoundaryData(UInt16 *pInCityCode, UInt16 *pOutCityCode);

    Bool SoundPlayScenario(Int32 eVoiceIndx);

    Bool SelectRoute(Int32 nSelectRoute);

    Bool ApplySelectRoute(Int32 nSelectRoute, bool isNuguTTSVoiceSpeak);

    Bool CancelRoute(bool remainDestFlags);

    Int32 GetCctvInfo(stCCTVInfo *pCCTVInfo);

    Int32 GetServiceAreaInfo(stServiceAreaInfo *pSAInfo);

    Int32 GetGasStationInfo(stGasStationInfo *pGasInfo);

    Int32 GetEVStationInfo(std::vector<stEVStationInfo> &evStationInfo);

    Int32 GetTmapRouteSummaryInfo(stTmapSummaryBaseInfo *pSummaryInfo);

    Bool GetTmapSummaryList(Int32 nRouteIndex, stTmapSummaryItem *pSummaryList, Int32 *nListCount);

    Bool GetRouteTrafficGpList(Int32 nRouteIndex, Int32 nIdx, Int32 nCnt, Int32 *nResult, Int32 *nTotal, ROUTETRAFFIC *sTraffic);

    Bool GetRouteTBTList(Int32 nType, Int32 nIdx, Int32 nCnt, Int32 *nResult, Int32 *nTotal, OsTBTList *sTBT);

    Bool GetAllTBTCount(Int32 *nCnt);

    Bool GetTBTDataByIndex(Int32 nIndex, OsTBTList *sTBT);

    Bool SetGuidanceConfig(RG_CONFIG sConfig);

    Bool GetGuidanceConfig(RG_CONFIG *sConfig);

    Bool GetRouteTrafficAllList(Int32 nRouteIndex, ROUTETRAFFIC **pRouteTrafficList, Int32 *pListcount);

    void ReleaseRouteTrafficAllList(ROUTETRAFFIC *pRouteTrafficList);

    Bool GetMultiDestCostInfoList(Int32 nRouteIndex, ROUTE_DEST_COST *pRouteDestCostInfo, Int32 &routeDestCostInfoListSize);

    Int16 *GetCrossImageBuffer(UInt16 uImageCode, Bool bIsNight, Int32 *nSize, Int32 *pWidth, Int32 *pHeight);

    Int16 *GetDirImageBuffer(UInt16 uImageCode, Int32 *nSize, Int32 *pWidth, Int32 *pHeight);

    Bool LONnLATToCoord(Double longitude, Double latitude, Int32 *wpX, Int32 *wpY);

    Bool CoordToLONnLAT(Int32 Type, Int32 wpX, Int32 wpY, Double *longitude, Double *latitude);

    Bool TLONnLATToCoord(Double longitude, Double latitude, Int32 *wpX, Int32 *wpY);

    Bool TCoordToLONnLAT(Int32 wpX, Int32 wpY, Double *longitude, Double *latitude);

    Bool CoordTransform(Int32 srcType, Double srcX, Double srcY, Int32 dstType, Double *dstX, Double *dstY);

    Bool IsRoute();

    Bool BlockReroute(Bool bBlock);

    Bool GetRouteTrack(char *szFileName);

    Bool SetGPSQueueCount(Int32 nCount);

    Bool GetTvasGpsDataCount(std::vector<Int32> &vGPSDataIndex);

    Bool GetTvasGpsDataByIndex(Int32 nIndex, TVASGPS_DATASET *pGPSData);

    Bool SetSafeDrivingDbFilePathInfo(const Char *dbFilePath, const Char *dbIndexFielPath);

    Bool SetHolidayConfigFilePath(const Char *filePath);

    Bool SetNddsInit(void *data);

public:
    // 도로마스터
    Bool SearchRoadLink(const Char *roadName, Bool fullMatch, Int32 maxCount, stRoadNameItem **items, Int32 *count);

    void ReleaseRoadNameItems(stRoadNameItem *items);

    Bool QueryRoadLink(const Char *distKind, const Char *distId, stRoadLinkList **ppRoadLinkList);

    void ReleaseRoadLinkList(stRoadLinkList *list);

    Bool DrawRoadLink(const Char *distKind, const Char *distId, Bool ensureVisible = TRUE);

    Bool CancelRoadLink();

    std::vector<std::string> GetPositionMarkPathList() const;

    Bool GetMapMatchPositionDrawingDatas(Bool isSimulation, MM_VERTEX **dataArray, int &dataCount, int &intervalMiiliseconds, int &tvasId);

    Bool GetMapMatchPositionDrawingDatasCount(Bool isSimulation, int &dataCount, int &intervalMiiliseconds);

    Bool GetMapMatchPositionDrawingDatasWithAllocBuffer(Bool isSimulation, MM_VERTEX **dataArray, int dataCount, int &intervalMiiliseconds, int &tvasId);

    Bool SetRoadNetworkTileData(Bool succeed, unsigned int level, unsigned int x, unsigned int y, const UInt8 *data, unsigned int dataSize);

    Bool SetMapMatchingDebuggerActive(Bool active);

    void GetDecodeOpusByte(Byte *inputData, Int32 contentLength, Int32 &nSize, std::vector<Int16> *opusResult);

    Bool GetRouteData(char *data, Int32 tvasSize, ROUTE_RENDER_DATA *renderData,
                      stTmapSummaryItem *summary, int *summaryCount,
                      stTmapSummaryBaseInfo *pstTmapSummary,
                      stGasStationInfo *gasStationInfos, int *gasInfoCount,
                      stEVStationInfo *evStationInfos, int *evInfoCount,
                      stServiceAreaInfo *serviceAreaInfos, int *areaInfoCount,
                      TVAS_LINK_DATASET *linkInfos, int *linkInfoCount,
                      stThemeRoadInfo *themeRoadInfo,
                      int *themeRoadInfoCount);

    Bool GetRouteData(char *data, Int32 tvasSize, ROUTE_RENDER_DATA *renderData,
                      std::vector<stTmapSummaryItem> &summary,
                      stTmapSummaryBaseInfo *pstTmapSummary,
                      std::vector<stGasStationInfo> &gasStationInfos,
                      std::vector<stEVStationInfo> &evStationInfos,
                      std::vector<stServiceAreaInfo> &serviceAreaInfos,
                      std::vector<TVAS_LINK_DATASET> &linkInfos,
                      std::vector<stThemeRoadInfo> &themeRoadInfo,
                      std::vector<stTmapTrafficItem> &linkTrafficInfo,
                      std::vector<stTmamRoadItem> &roadInfo,
                      std::vector<stTmamGuidePoint> &guidePointInfo,
                      std::vector<stTmapRoadAccidentItem> &roadAccidentInfo,
                      int currentEnergy = 0);

    Bool GetTvasLinkInfo(std::vector<TVS_LinkID> &TVS_LinkID);

    Bool GetTvasLinkTraffic(std::vector<TVS_LinkTraffic2> &TVS_LinkTraffic);

    Bool SetTTSScript(std::map<E_TTS_LANGUAGE_TYPE, std::map<int, std::string>> scriptMap, int &scriptCount);

    Bool SetTTSLanguage(E_TTS_LANGUAGE_TYPE language);

    Bool SetElectricVehicle(Bool isEv);

private:
    struct NavParameter;
    NavParameter *m_navParameter;

    struct RouteInfo;
    RouteInfo *m_routeInfo;

    void InitSound(const NavParameter *navParam, Int32 resValue);

    Int32 InitNaviEngine(const NavParameter *navParam);

    Bool InitSgl(const NavParameter *navParam, Int32 resValue, Bool bAsyncDBCheck);

    Bool CreateSingleton(PNAVIMODULE_INIT sInit);

    Bool DestroySingleton();

private:
    LPCALL_JavaCallback JavaCallback;

};

#endif // __NAVICONTROLLER_H__
