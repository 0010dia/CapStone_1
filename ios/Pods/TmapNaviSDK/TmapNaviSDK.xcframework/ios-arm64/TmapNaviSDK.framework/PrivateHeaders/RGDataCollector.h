//////////////////////////////////////////////////////////////////////////
// RGDataCollector.h
//
// RouteGuide를 위한 초기 데이터 수집을 처리한다.
//
//////////////////////////////////////////////////////////////////////////

#ifndef _RGDATACOLLECTOR_H_
#define _RGDATACOLLECTOR_H_

#include "rg_def.h"
#include "networkdb_def.h"
#include "route_def.h"

#define MAX_PATH_COUNT	6

#define	LINKINFO_GRAW_ALLOC_COUNT			10
#define	GPINFO_GRAW_ALLOC_COUNT				10
#define	LANEINFO_GRAW_ALLOC_COUNT			10
#define	SDIINFO_GRAW_ALLOC_COUNT			10
#define CONGEST_SECTION_GRAW_ALLOC_COUNT    10
#define	ROADINFO_GRAW_ALLOC_COUNT			10
#define	SAINFO_GRAW_ALLOC_COUNT				10
#define	TOLLINFO_GRAW_ALLOC_COUNT			10
#define	CROSSNAMEINFO_GRAW_ALLOC_COUNT		10
#define	DIRNAMEINFO_GRAW_ALLOC_COUNT		10
#define	VERTEXINFO_GRAW_ALLOC_COUNT			100
#define RTMINFO_GRAW_ALLOC_COUNT			10
#define POIINFO_GRAW_ALLOC_COUNT			10

enum TypeGatherData
{
	GATHERTYPE_LINKINFO			= 0,
	GATHERTYPE_GPINFO,
	GATHERTYPE_LANEINFO,
	GATHERTYPE_SDIINFO,
	GATHERTYPE_CONGEST_SECTION,
	GATHERTYPE_ROADINFO,
	GATHERTYPE_SAINFO,
	GATHERTYPE_TOLLINFO,
	GATHERTYPE_CROSSNAMEINFO,
	GATHERTYPE_DIRNAMEINFO,
	GATHERTYPE_VERTEXINFO,
	GATHERTYPE_RTMINFO,
	GATHERTYPE_POIINFO,
	Num_Of_GatherType
};

class CRGMapManager;
class NcRegulationMap;
class Tpeg;
class CRGDataCollector
{
NOT_COPYABLE(CRGDataCollector)

private:
	CRGDataCollector(void);
	~CRGDataCollector(void);

public:
	BOOL		Initialize();

	void		UnInitialize();

	//////////////////////////////////////////////////////////////////////////
	// TPEG 관련
public:
	Bool		RTMDataCollect(GPSDATE *psDate, GPSTIME *psTime, stGatheringData *pCurrentSlot);

protected:
	Bool		UpdateRtmInfo(GPSDATE *psDate, GPSTIME *psTime, stGatheringData *pCurrentSlot);
	Bool		GetRTMMatchLinkInfo(Int32 nLinkIndex, stRTMGatheringData *pstRTMInfo);
	static int	CompareRTMInfoByLinkIndex(const void *arg1, const void *arg2 );

	//////////////////////////////////////////////////////////////////////////
	// RG ServiceData 관련
public:
	Bool		ServiceDataCollect(NsRouteReqLogic *pstRouteInData, NsRouteResLogic *pstRouteOutData, stGatheringData *pCurrentSlot, stRoutePosDetailInfo *pCurrentPos, stRouteViaDetailInfo *pCurrentVia, TVS_Data *pCurrentTvas);
	static Bool		IsServiceLink(Int32 nTurnCode);
	static Bool		IsRotaryTurn(Int32 nTurnCode);

protected:
	Bool		CollectLinkListInfo(NsRouteReqLogic *pstRouteInData, NsRouteResLogic *pstRouteOutData);
	static int	CompareLinkIDByLinkAttr(const void *arg1, const void *arg2 );
	static int	CompareLinkIndexByLinkAttr(const void *arg1, const void *arg2 );
	static int	CompareDistanceByRoadInfo(const void *arg1, const void *arg2 );
	static int	CompareLinkIndexByRoadInfo(const void *arg1, const void *arg2 );

    Bool ConvertSmartTallingMaskToArray(const UInt16 inputMask,vector<UInt8> &arry);

	Bool		AddPosition(UInt32 nLinkIdx, UInt32 nLinkID, UInt32 nLength, UInt32 nLinkTime, DOUBLE_VERTEX wpPos, Char * pPosName, Int32 nRPRCount, Int32 nRPRIndex);
	Int32		AddGPPosition(UInt32 nLinkIdx, UInt32 nCheckPosIdx);

	Bool		ViaAttachOnVertex(UInt32 nLinkIdx, UInt32 nLinkID, UInt32 nLength, UInt32 nLinkTime, DOUBLE_VERTEX wpPos, Char * pPosName, Int32 nRPRCount, Int32 nRPRIndex);
	Bool		GetViaVertexInfo(stRouteViaInfo * pstRoutePos, Int32 nVertexCount, DOUBLE_VERTEX* pVertex, Int32 nLinkLength, Int32 nLinkTime);
	Bool		GetViaPathOnLink(NsRouteReqLogic *pstRouteInData, NsRouteResLogic *pstRouteOutData);

	Bool		CollectVertexData(UInt32 nLinkIndex, UInt32 nLinkID, UInt8 nLinkDir, Int32& nMultiBridge);

	Int32		CollectRoadInfo(UInt32 nLinkIndex, UInt32 nRoadNameOffset, UInt8 roadCate);

	Int32		FindSameRoadInfo(Char * pszRoadName, UInt8 roadCate);

	Bool		CollectLaneInfo(UInt32 nLinkIndex, UInt32 nLaneInfoOffset, UInt32 nTurnType, Int32 nStartLinkIndex);
	Bool		IsSameLaneInfo(Int32 nLinkIndex, OsLaneInfo * pstLaneData, Int32 nLaneCount);

	Bool		CollectSDIInfo(UInt32 nLinkIndex, UInt32 nSDIInfoOffset, UInt16 nSDICount);

	Bool		CollectCongestSection(UInt32 nLinkIndex);           // TC정보 수집

	Bool		CollectPOIInfo(UInt32 nLinkIndex, UInt32 nPOIInfoOffset, Int32 nStartLinkIndex);

	UInt32		GetHighWayGroupID(UInt32 nLinkIndex, Int32 nPrvGroupID, Int32 nCurRoadCate, Int32 nNextRoadCate, Int32 nPrvRoadCate);

	Bool		GetCrossImageData(UInt32 nCrossImgOffset, UInt32 nNextLinkID, Int32 *pnTurnCode, UInt8 *pnViewFlag, UInt8 *pnVoiceCode, UInt16 *pnCrossImgCode);

	Int32		CollectSAInfo(UInt32 nLinkIndex);
	Int32		CollectTollInfo(UInt32 nLinkIndex);

	Int32		CollectGPData(UInt16 nLinkIndex, Int32 nGPType, Int32 nTurnCode, Int32 nRoadInfoIndex, UInt8 nViewFlag, UInt8 nVoiceCode, UInt16 nCrossImgCode, UInt16 nDirImgCode, UInt32 nCrossImgIndex);
	void		SetGPData(UInt16 nSetIndexInfo, Int32 nGPType, Int32 nTurnCode, Int32 nLinkIndex, Int32 nRoadInfoIndex, UInt8 nViewFlag, UInt8 nVoiceCode, UInt16 nCrossImgCode, UInt16 nDirImgCode, UInt32 nCrossImgIndex);
	Bool		CollectGPTextData(UInt16 nLinkIndex, UInt16 nRGServiceIndex = 0xffff);

	void		CollectEVStationInfo();
	Bool		CollectGasStationInfo();
	Bool		CollectCCTVInfo();
	Bool		CollectTmapSummaryList(StUDateTime * pUDateTime, Int32 nCurrentEnergy);

	Bool		CollectRouteSummary(StUDateTime * pUDateTime);
	static int	CompareVertexIndexBySummaryInfo(const void *arg1, const void *arg2 );

	UInt32		CalRouteFee(StUDateTime * pUDateTime);
	Bool		MargeTollList(StUDateTime * pUDateTime, UInt32 nStartTollID, DsTollItem *pstTollList, Int32 *pnTollCount);

	Bool		IsTollFeeFreeByTimeMap(UInt32 nTimeMapIndex, StUDateTime * pUDateTime);
	Char		*GetTurnCodeText(UInt32 nServiceLinkIndex);
	Bool		MakeSummaryText(Int32 nLinkIndex, UInt32 nServiceLinkIndex, Char *pszSummaryText, Int32 nSummaryTextLen);

	Int32		CollectTBTList();
	Bool		CollectTBTInfo(Int32 nIndex, OsTBTList *pstTbtList, Int32 nCount);
	RG_TBT_TYPE GetTbtType(Int32 nGPType);
	Bool		MakeTBTMainText(Int32 nLinkIndex, Int32 nGPIndex, Char *pszText, Int32 nTextLen);
	Bool		GetFindCrossNameByNext(Int32 nRouteIndex, Char * pszNextCrossName, Int32 *pnFindLinkIndex);
	//////////////////////////////////////////////////////////////////////////
	//
	Bool		GetPositionInfo(stRoutePosInfo * pstRoutePos, Int32 nVertexCount, DOUBLE_VERTEX* pVertex, Int32 nLinkLength, Int32 nLinkTime);
	UInt32		GetTotalDistance();
	UInt32		GetTotalTime();
	Int32		GetGPInAngle(Int32 nGPIndex);
	UInt32		GetGPDistance(Int32 nGPIndex);
	UInt32		GetLinkVertexIndex(Int32 nLinkIndex, Bool bEndIndex);
	UInt32		GetGPVertexIndex(Int32 nGPIndex);
	DOUBLE_VERTEX	GetGPVertex(Int32 nGPIndex);
	Char*		GetGPCrossName(const Int32 nGPIndex);
	Char*		GetGPTollName(const Int32 nGPIndex);
	Bool		GetSAInfo(const Int32 nGPIndex, stServiceAreaInfo *pstSAInfo);

	Int32		GetTurnCode(const OsLinkAttribute * pCurAttri, UInt32 nNextLinkID);

	Int32		MakeRotaryTurnType(UInt32 nInLinkIndex, UInt32 nOutLinkIndex);

	Int32		GetGuidePointType(UInt32 nLinkID, UInt32 nNextLinkID, Int32 nTurnCode, Bool bCrossImage, OsLinkAttribute * pCurAttri);
	Bool		IsTollGate(UInt32 nLinkIdx);
	Int32		GetPositonCode(Int32 nPositionIndex, Int32 nRPRCount);

	Bool		CheckMemLinkInof(Int32 nAllocCount = 1);						// LinkListInfo Mem 체크 & 메모리 할당
	Bool		CheckMemRGServiceLink(Int32 nAllocCount = 1);					// 경로 안내 데이터 Mem 체크 & 메모리 할당
	Bool		CheckMemLaneInfo(Int32 nAllocCount = 1);						// 차선 상세 정보 Mem 체크 & 메모리 할당
	Bool		CheckMemSDIInfo(Int32 nAllocCount = 1);							// SDI 상세 정보 Mem 체크 & 메모리 할당
	Bool		CheckMemCongestSection(Int32 nAllocCount = 1);                  // 정체구간 Mem 체크 & 메모리 할당
	Bool		CheckMemRoadInfo(Int32 nAllocCount = 1);						// 도로정보 Mem 체크 & 메모리 할당.
	Bool		CheckMemSAInfo(Int32 nAllocCount = 1);							// 휴게소 정보 Mem 체크 & 메모리 할당.
	Bool		CheckMemTollInfo(Int32 nAllocCount = 1);						// 톨게이트 정보 Mem 체크 & 메모리 할당.
	Bool		CheckMemCrossName(Int32 nAllocCount = 1);						// 교차로 정보 Mem 체크 & 메모리 할당.
	Bool		CheckMemDirName(Int32 nAllocCount = 1);							// 방면 정보 Mem 체크 & 메모리 할당.
	Bool		CheckMemVertex(Int32 nAllocCount = 1);							// pVetexPoint의 Mem 체크 & 메모리 할당
	Bool		CheckMemRTMInfo(Int32 nAllocCount = 1);							// RTM 정보의 Mem 체크 & 메모리 할당
	Bool		CheckMemPOIInfo(Int32 nAllocCount = 1);							// POI 정보의 Mem 체크 & 메모리 할당

	Int32		GetAllocCount(Int32 nAllocCount, TypeGatherData nMemType);

	char*		Token(Char *pstrDst, Char *pstrSrc, Int32 idx, Char ctoken);

	Int32		GetRGShapeTurnType(Int nTurnCode);

public:
	// TVAS 위험구간 타입을 엔진 형태로 변경 한다.
	static SDI_Type	ConvertTvasSDICode(UInt8 src);
	// Tmap 로컬 위험구간 타입을 엔진 형태로 변경 한다.
	static SDI_Type ConvertSafeSDICode(UInt8 src);

	static Int32 GetGuideDistance(UInt32 nType, UInt8 uRoadCate);
	static Byte ConvertGasStationFlagFromTvas(UInt16 usInfo);

protected:
	stGatheringData			*m_pCurrentSlot;
	stRoutePosDetailInfo	*m_pCurrentPos;
	TVS_Data				*m_pCurrentTvas;

	stRouteViaDetailInfo *  m_pViaRoutePos;

	Int32					m_nAllocRTMData;
	Int32					m_nRTMCount;
	MBC_RTMBody	*			m_pTPEGRTMData;
	char				   *g_pstrRTMDatilData;

	Int32					m_nPOIMaxCount;
	DsPOIInfo				*m_psPOIData;

	Tpeg			*m_pTPEG;

DECLARE_SINGLETON(CRGDataCollector)
};

#endif // _RGDATACOLLECTOR_H_
