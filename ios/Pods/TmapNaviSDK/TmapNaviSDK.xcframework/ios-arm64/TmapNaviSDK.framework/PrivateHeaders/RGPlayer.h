// RGPlayer.h

#ifndef __RGPLAYER_H__
#define __RGPLAYER_H__

#include "LocalLinkV2.h"
#include "mapmatch_def.h"

#define CROSS_SURFACE_ANGLE	50

class CRGMapManager;
class CSafeDriveInfomation;
class NcSDIManager;
class CSafeDrive;
class NcRegulationMap;
class Tpeg;
class CRGPlayer
{
public:
	CRGPlayer();
	virtual ~CRGPlayer();

public:
	Bool Initialize();
	void UnInitialize();

	Bool InitRGService(Bool bStartRGService);
	Bool GetDriveInfo(const NsMatchingData * pMMData, Bool bSimulator, AlternativeRoute* pAlternativeRoute);
	Bool GetAndoDriveInfo(const NsMatchingData * pMMData, weak_ptr<LocalLinkV2> pLocalLinkV2);

	TVS_Data *m_pTvasData;
	void SetTvasData(TVS_Data *pTvasData) {m_pTvasData = pTvasData;}
    
    Int32   GetSafeVersionInfo();   //ssh
    void    SendSafeBackupFile();
    void    MakeSafeFile(void* pData,Int32 iSize);
/*
 * kiwoo 13.02.27
 * Map Mapching 후보링크의 시작 index를 설정한다.
 */
  //  Int32 	GetCurPosStartLinkIdx();

	Bool	GetDRGInfo(Int32 currentVXIdx, DOUBLE_VERTEX *pWpPos, OsDRGInfo *pInfo);

	Bool 	MakeThemeRoadVoice(Int32 vpPosMMIndex, DOUBLE_VERTEX *pWpPos, stDriveInfo *pstInfo);

	CSafeDriveInfomation	*m_pSafeDriveInfomation;

protected:
	void PostMessageToSystem(Int32 nRouteIndex, Int32 nGPIndex, UInt32 nMMLinkLengthToEnd);

	//////////////////////////////////////////////////////////////////////////
	// 탐색된 경로 위에 현위치가 존재하는지를 판단한다.
	RG_CUR_STATUS CalRouteOnPosition(const NsMatchingData* szMMData, Int32 * pnRouteOnIndex);

	Bool	GetCurrentRGData();
	Bool 	FindCurrentGPIndex(Int32 nRouteOnIndex, UInt32 nLinkLengthToEnd, Int32 *pnGPIndex, Int32 *pnHiwayIndex);

	Bool    GetEvGoalInfo(Int32 nRouteOnIndex, UInt32 nMMLinkLenthToEnd, stDriveInfo *pstInfo);
	Bool	GetGoalInfo(Int32 nRouteOnIndex, const NsMatchingData* szMMData, Int32 nGPIndex, UInt32 nMMLinkLenthToEnd, stDriveInfo *pstInfo);
	Bool	GetGPInfo(Int32 nRouteOnIndex, Int32 nGPIndex, UInt32 nMMLinkLenthToEnd, stDriveInfo *pstInfo);
    Bool    GetRemainGPInfo(Int32 nRouteOnIndex, Int32 nGPIndex, UInt32 nMMLinkLenthToEnd, stDriveInfo *pstInfo);
	Bool	GetExtCrossInfo(Int32 nGPIndex, stDriveInfo *pstInfo, UInt32 nMMLinkLenthToEnd);
	Int32	GetExtCrossImageShowDistance(Int16 nExtImageCode, Int32 nRoadcate);
	Bool	GetDirInfo(Int32 nGPIndex, stDriveInfo *pstInfo);
	Int32	GetDirImageShowDistance(Int16 nDirImageCode, Int32 nRoadcate);
	Bool	GetTBTInfo(Int32 nRouteIndex, Int32 nGPIndex, UInt32 nMMLinkLengthToEnd, OsTBT *pstTBT, Bool *pbExtcImage, UInt16 *pnExtcImageCode);
    void    MakeTBTMainText(Int32 nRouteIndex, Int32 nGPIndex, stDriveInfo *pstInfo, OsTBT *pstTbtInfo, const char* pszGoPosName);
	Bool	GetFindCrossNameByNext(Int32 nRouteIndex, Char * pszNextCrossName, Int32 nNextCrossNameLen, Int32 *pnFindLinkIndex = NULL);

	Bool	IsPeriodicReRouteArea(Int32 nRouteIndex, Int32 nGPIndex, stDriveInfo *pstInfo);

// 	Bool	GetHiwayInfo(Int32 nRouteOnIndex, UInt32 nMMLinkLengthToEnd, Int32 nCurrentTime, stDriveInfo *pstInfo, const Int32 *pPrvPassTime);
 	Bool	GetTBTListInfo(Int32 nRouteOnIndex, Int32 nGPIndex, Int32 nHiwayIndex, UInt32 nMMLinkLengthToEnd, Int32 nCurrentTime, stDriveInfo *pstInfo, const Int32 *pPrvPassTime);

	void	MakeCongestSectionVoice(Int32 nRouteIndex, NsMatchingData *pMMData, stDriveInfo *pstInfo);

//	Bool	GetSDIInfo(NsMatchingData * pMMData, stDriveInfo *stInfo, Bool bIsRouteOn);
	void	MakeVoiceInfo(Int32 nGPIndex, Int32 nRouteOnIndex, stDriveInfo *pstInfo);
    void    MakeTBTTunnelVoiceInfo(Int32 tunnelGpType, Int32 nGPIndex, Int32 nNextTBTGPIndex, NS_VOICE_SVC_CONTEXT &stVoicePlayInfo);
	Bool	MakeNextSAVoideInfo(Int32 nGPIndex, Int32 nRouteIndex, stDriveInfo *pstInfo);
	void	MakeAndoVoiceInfo(stDriveInfo *pstInfo);
	void	MakeSdiVoiceInfo(stDriveInfo *pstInfo, OsSDI *pStSDI);

	//////////////////////////////////////////////////////////////////////////
	//
	Bool	GetLaneInfo(Int32 nRouteIndex, UInt32 nLinkID, UInt32 nMMLinkLengthToEnd, OsLane *pstLane);
    Bool	GetLaneInfoEX(Int32 nRouteIndex, UInt32 nLinkID, UInt32 nMMLinkLengthToEnd, OsLane *pstLane);

    // 현위치부터 목적지까지 남은 차선정보 반환
    Bool	GetAheadLaneInfo(Int32 nRouteIndex, UInt32 nLinkID, UInt32 nMMLinkLengthToEnd, vector<OsLane> &laneInfoList);

	Bool	GetRTMInfo(Int32 nRouteIndex, UInt32 nLinkLengthToEnd, OsRTM * pRTMInfo);
	Int32	GetRoadLimitSpeed(Int32 nRouteIndex, UInt32 nMMLinkID);
	Bool	GetRoadName(Int32 nRouteIndex, UInt32 nMMLinkID, Char* pszCurrentRoadName, Int32 nCurrentRoadNameLen);
	Bool	GetNextRoadName(Int32 nGPIndex, Char* pszNextRoadName, Int32 nNextRoadNameLen);
	Int32 	GetNextRoadWidth(Int32 nGPIndex);

	Bool    GetPOIInfo(Int32 nRouteIndex, UInt32 nLinkLengthToEnd, OsPOI * pPOIInfo);

	Bool	GetEcoDriveInfo();
	Bool	GetCityPass();

	UInt32	GetGPDistance(Int32 nRouteIndex, Int32 nGPIndex, UInt32 nMMLinkLengthToEnd);
	UInt32	GetGPTime(Int32 nRouteIndex, Int32 nGPIndex, UInt32 nMMLinkLengthToEnd);
	UInt32	GetCurrentPosDistance(Int32 nRouteIndex, UInt32 nMMLinkLengthToEnd);
	UInt32	GetCurrentPosTime(Int32 nRouteIndex, UInt32 nMMLinkLengthToEnd);
	Float	GetPositionRatioByLink(Int32 nRouteIndex, UInt32 nRatioLength);
	Bool	IsRotaryTurn(Int32 nTurnCode);
	Int32	GetCrossProgressBarInfo(Int32 nTBTDist);

	Bool 	IsServiceSDI(Int32 nSDIType);

	Bool    CopyValidString(Char* source, Char* target, Int32 nSizeTarget);

	void SetVmsInfo(stDriveInfo& stDriveInfo);
	void SetLinkInfo(stDriveInfo& stDriveInfo, NsMatchingData& szMMData);
	void SetNearPoint(const NsMatchingData* pMMData);
	bool SetNearPoint(UInt16 usStartIdx, UInt16 usEndIdx, const NsMatchingData* pMMData, int &linkLength);
	void SetNearLinkID(const NsMatchingData* pMMData);

protected:
	Bool					m_bRGService;
	stGatheringData			*m_pGatherData;
	stRoutePosDetailInfo	*m_pPosInfo;
	Int32					m_nCurrentViaPos;

	Bool					m_bAroundNextGoPos;

	stRouteViaDetailInfo	*m_pVirtualViaInfo;
	Int32					m_nRGVirtualViaPos;

	Bool					m_bChangeLink;
	Bool					m_bChangeGP;

	Int32					m_nPrvLinkIndex;
	Int32					m_nPrvLinkID;
	Int32					m_nPrvAllGPIndex;					// 전체 GP에 대한 현재 Index
	Int32					m_nPrvTBTGPIndex;					// 전체 GP 중 TBT 표출 가능 데이터에 대한 Index
	Int32					m_nPrvHiwayGPIndex;					// 전체 GP 중 Hiway 데이터에 대한 Index
	Int32					m_nICPassIndex;

	stDriveInfo				m_stDriveInfo;

	Int32					m_iDaPos;

	UInt32					m_nPosAccDist;



	//////////////////////////////////////////////////////////////////////////
	// PostMessageTooSystem 에서 사용되는 변수
	Bool					m_bPostMessageToSysByToll[2];		// 1Km 와 500m에서 멘시지 전달에 대한 Flag

	// 강제 재탐색시 이전 값을 확인하여 이중 탐색 일어나지 않도록 처리.
	UInt8					m_nLastDrgType;
	DOUBLE_VERTEX				m_lastDrgVertex;
	UInt16					m_lastFrontDist;

	DOUBLE_VERTEX m_lastPosition;
	Int32 lastVmsIndex;

    // MCL
public:
    void clearConfiguration();
    void applyConfiguration();

private:
    SGL_mutex* m_safeDriveLock;
};
#endif // __RGPLAYER_H__
