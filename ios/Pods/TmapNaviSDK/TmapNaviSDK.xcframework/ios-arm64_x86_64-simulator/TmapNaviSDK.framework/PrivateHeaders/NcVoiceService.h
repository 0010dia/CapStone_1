// NcVoiceService.h

// 작성자 : 정대연
// 작성일 : 2009.10.19
// 설  명 :

#ifndef __NCVOICESERVICE_H
#define __NCVOICESERVICE_H

#include "sgl_inc.h"
#include "rgdata_inc.h"
#include "rg_def.h"

#define ALARM_CHANNEL 0        //알람 채널
#define DEFAULT_CHANNEL 1    //안내 채널
#define SDI_CHANNEL 2        //안도 채널

class NcVoiceService
{
    NOT_COPYABLE(NcVoiceService);

private:
    NcVoiceService(void);

    ~NcVoiceService(void);

private:

    // 	//MM 플레이어 객체(Wave 파일을 로딩하여 플레이, 비동기 방식)
    // 	NcWave *m_pMMPlayer;
    //SDL 플레이어 객체(Wave 스트림 플레이, 비동기 방식)
    PNS_VOICE_SVC_CONTEXT m_pInfo;
    NS_MAINROADNAME_Info m_MainRoadNameInfo[4];
    std::vector<std::string> m_arrWaveScript[NUM_SOUND_CHANNELS];

    // 속성정보
    Int m_nPrevServiceIdx;
    DOUBLE_VERTEX m_wPrevGP;

    Int m_nPrevAndoIdx;
    Int m_nPrevAndoType;
    DOUBLE_VERTEX m_wPrevAndoGP;
    Int m_nPrevPlusIdx[PLUS_GP_CNT];
    DOUBLE_VERTEX m_wPrevPlusGP[PLUS_GP_CNT];
    int m_AndoCurrentIdx;
    Char m_szOldRoadName[_TEXT_SIZE_];        // 도로 명칭

    Int m_nPrevPOIIdx;
    Bool isPlayCongestVoice;
    DOUBLE_VERTEX m_wPrevPOIGP;
    DOUBLE_VERTEX m_wPrevCongestSectionGP;


    DOUBLE_VERTEX m_wpStmGP;

    Int32 sdiBlockRemainDist;
    Bool isSeriesTunnel;

    Int32 speakerType;          // 기타 음성 발성 flag(기존 어린이 음성 삭제로 인해 추후 생성될 예외음성처리를 위해 남겨둠).
    Bool isMandatory;           // 모든 음성에 대한 필수 여부

    Int m_nPrevThemeRoadIdx;
    DOUBLE_VERTEX m_wPrevThemeRoadGp;

private:
    sglQueue<int> m_qScenarioServiceQueue;
    sglQueue<int> m_qAdScenarioService;

    PNS_VOICE_SVC_CONTEXT m_pContext;
    static Int s_SeriesLength;
    static Int s_SeriesTollLength;
    int s_SeriesEtcLength;        //터널/고가 옆도로 이어서 안내 길이
    int s_SeriesICJCLength;        //IC,JC 진출후 이어서 안내 길이

    Int32 m_nPrevCityCode;
    Bool m_bPrevGpsStatus;            // GPS 이전 상태
    Int voiceType;

    SGL_mutex *m_mutex;
private:
    void InitWaveIndex(Int nChannel);

    void PlayWaveList(Int nChannel, Int32 voice_type = VOICE_TYPE_ETC, Int32 distance = 0, Int32 cost_time_sec = 0, Int32 nAudioType = AUDIO_TYPE_DEFAULT);

    Bool AddWaveIndex(Int nChannel, UInt uWave);

    Bool AddWaveChar(Int nChannel, const Char *pszName);

    Bool AddWaveIndexChar(Int nChannel, const Char *pszName);

    Int GetServiceIndex(Int nService, Int nRemainderDist, Int nSdiType = 0);

    Bool isDynamicService(Int nServiceIdx);

    void MakeWaveNumeral(Int nChannel, Int nExpress, Int nServiceIdx, Int *iDist);

    void AddCrossNameFilterWave(Int nChannel, std::string crossName);

    void MakeWaveNameText(Int nChannel, Int nServiceIdx);


    Bool IsNameNotEmpty(Char *name);

    void MakeWaveTurn(Int nChannel, Int nServiceIdx, Int nTurnflag, Int iDist = 0);

    void MakeWaveEtc(Int nChannel, Int nServiceIdx, Int nTurnflag);

    Bool MakeWaveSeries(Int nChannel, Int nServiceIdx);

    Bool IsValidTBTInfoCheck(NS_TBT_Info tbtInfo);

    Bool IsServiceLinkType(Int voiceIdx);

    void MakeLaneService(Int nChannel, Int nServiceIdx);

    void MakeHiPassService(Int nChannel, Int nServiceIdx);

    void MakeNextRoadService(Int nChannel);

    Bool MakeWaveTunnelName(Int nChannel, Int nServiceIdx, Int nTurnflag);

    void MakeWaveTunnelSeries(Int32 tunnelGpType, Int nChannel, Int nServiceIdx, Int nTurnflag);

    void MakeWaveSa(Int nChannel, Int nServiceIdx);

    Bool MakeWaveTol(Int nChannel, Int nTurnflag);

    Bool MakeWaveUnderIn(Int nChannel, Int nServiceIdx, Int nTurnflag);

    Bool MakeWaveSkyIn(Int nChannel, Int nServiceIdx, Int nTurnflag);

    Bool isDynamicSdiService(Int nServiceIdx);

    Bool IsSdiSpeedOver();
    Bool IsSdiPlusSpeedOver(stDriveInfo *pDriveInfo);

    Bool IsDistServiceSdi(PNS_VOICE_SVC_CONTEXT pContext);

    Bool IsSdiBlockSpeedLimit(Int32 speed);

    void MakeSdiBlock_SpeedLimit(Int nChannel, Int32 speed);

    void MakeSdiSpeedBlock_MID_Voice(Int nChannel, CSglSoundPlayer &SoundPlayer);   // 4km 마다 구간단속 중 안내
    Bool MakeSdi_VoicePlay(PNS_VOICE_SVC_CONTEXT pContext, Int nChannel, Int nServiceIdx, Int32 *pAudioType = NULL);

    Bool MakeWaveSentence(Int nChannel, Int nCount, Int *pPlayList);

    int GetVoiceOrderType();

    Bool GetPrevPlusAndoGP(DOUBLE_VERTEX vtx, DOUBLE_VERTEX *pHumpVtx, Int nObject, Int nIndex);

    void SetPrevPlusAndoGP(DOUBLE_VERTEX vtx, DOUBLE_VERTEX *pHumpVtx, Int nObject, Int nIndex);

    void VoiceAndoPosSet(Int nServiceIdx);

    Char *StrToken(Char *pstrDst, Char *pstrSrc, Int32 idx, Char ctoken);

    void UserPOIService(Int nChannel);

    void CongestSectionVoiceService(Int nChannel);

    Bool MakePOIWave(Int nChannel, Int nExpress, Int nServiceIdx);

    Int GetSDIServicePlayType(PNS_VOICE_SVC_CONTEXT pContext, Int nServiceIdx);

    void MakeThemeRoadVoiceService(Int nChannel);

private:
    Bool IsValid();

    Bool IsCountryArea(DOUBLE_VERTEX *wpt)
    {
        if (wpt->x < COUNTRY_MIN_X || wpt->x > COUNTRY_MAX_X ||
            wpt->y < COUNTRY_MIN_Y || wpt->y > COUNTRY_MAX_Y)
        {
            return FALSE;
        }

        return TRUE;
    }


private:
    Bool VoiceService(Int nChannel, int type);

    void SDIService(Int nChannel, int type, stDriveInfo *pDriveInfo);

    Bool RemainderDistService(Int nChannel, Int nServiceIdx);

    void RoadNameService(Int nChannel);

    void IntroduceService(Int nChannel);

    void ScenarioQueueEmpty(Bool bStopPlay);

    void ScenarioQueueAddTail(Int nVoiceID, Bool bClear);

    void ScenarioQueueService();

    void MakeTtsVoiceText();

    Bool GetMainRoadNameWaveIndex(Int32 rpIndex, bool addWaveIndex);

    Bool RemainderService(Int nChannel, PNS_VOICE_SVC_CONTEXT pInfo, Bool bForce, Bool bReRoute, Bool bServerRP, Int32 nTime, Bool bGuideType);

    void PlayLocked(Int32 nChannel, UInt32 uID, Int32 nAudioType=AUDIO_TYPE_DEFAULT);

    void StopLocked(Int nChannel);

    Bool IsPlayLocked(Int nChannel);

    void AddressNameService(Int nChannel, char *pStr);

    void RouteGuideService(Int nChannel, Int nTime, Bool bGuideType);



    DECLARE_SINGLETON(NcVoiceService);

    // 경로안내 init index (주요도로 값 확인 / tts prepare).
    void ApplyRoute(Int32 selectRpIndex = -1);

    void SetRouteOption(int m_nRouteOption, UInt8 m_ucRoadAttribute = 0x01, UInt16 m_totalTollFee = 0);

    void SetIsFavoriteRouteSelected(Bool m_nIsFavoriteRouteSelected);

    /*
     * Turn 안내가 일정거리 이후에 발성될 예정인 경우
     * isVoiceSpeak : 음성 발성 여부 - FALSE 일 경우 TTS 엔진에 wavId만 생성한다.
     */
    void MakeRemainderDistCrossName(Int nChannel, bool isVoiceSpeak);

    void MakeNextRoadName(Int nChannel, UInt uWave, UInt oldWave);

    Bool ReRouteRoadSummary(Int uReRouteType);

    int CreateHiPassSmartTallingLaneWave(int nChannel, NS_HiPassInfo hipassInfo, NS_SmartTallingInfoInfo smartTallingInfo);

    Int32 selectRpIndex;                      // 경로안내 Rp index
    UInt8 ucRoadAttribute = 0x01;
    UInt16 totalTollFee = 0;

    int routeOption;

    Bool prevIsFavoriteRouteSelected;
    Bool isFavoriteRouteSelected;
    Bool hasEvStation;
public:
    void ScenarioService(NeVoiceScenario eVoiceScenario, Int32 nValue);

    void MakeVoiceService(stDriveInfo *pInfo);

    void Stop(Int nChannel);

    Bool IsPlay(Int nChannel);

    void InitPrevAndoGP();

    void SetMainRoadNameInfo(Int nRpIndex, NS_MAINROADNAME_Info *pInfo);

    static void SetOutputSamplingRate(Int32 samplingRate);

    void MakeStartVoice(Bool isReroute);
    void ChangeAlternativeRouteVoice(Int32 timeDiff = 0);

    void GetDecodeOpusData(Byte* inputData, Int32 contentLength, Int32 &nSize, std::vector<Int16>* opusResult);

    const char* getScript(int index);
    void SetEvStationInfo(Bool bEvStation);
private:
    static Int32 s_outputSampleRate;

};

#endif
