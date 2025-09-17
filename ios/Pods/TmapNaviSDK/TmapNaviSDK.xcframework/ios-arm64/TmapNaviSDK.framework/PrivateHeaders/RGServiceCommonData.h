// RGServiceCommonData.h

#ifndef	_RGSERVICECOMMONDATA_H_
#define _RGSERVICECOMMONDATA_H_

#include "rgdata_def.h"
#include "NcServiceList.h"

class CRGServiceCommonData
{
 	NOT_COPYABLE(CRGServiceCommonData)

private:
	CRGServiceCommonData();
	~CRGServiceCommonData();

public:
	Bool					IsRGService() {	return (m_bValidServiceSlot && !m_bReferenceServiceSlot);};
	stGatheringData	*		GetRGServiceData();
	stRoutePosDetailInfo *	GetRGPosInfo();

	stGatheringData	*		GetBackRGSlotData(const Int32 nSlot);
	stRoutePosDetailInfo *	GetBackRGPosInfo(const Int32 nSlot);

	stRouteViaDetailInfo *	GetRGViaInfo();

	Bool					IsValidServiceSlot();

	Bool					AllocateBackSlotLinkList(const Int32 nSlot, const Int32 nAllocSize);

	void					FreeServiceSlot();
	void					FreeBackDataSlot(const Int32 nSlot);
	void					FreeBackDataSlotAll();
	void					CopyToServiceSlot(const Int32 nSlot, Bool bReference);

	void					ReSetServiceSlot();
	void					ReSetBackDataAll();
	void					ReSetBackData(const Int32 nSlot);


	//////////////////////////////////////////////////////////////////////////
	// Data Access Interface 
	UInt32	const GetLinkID(const UInt32 nLinkIndex);

	Int32	const GetTotalRouteDistance();
	Int32	const GetTotalRouteTime();

	Int32	const GetGPDistance(const Int32 nGPIndex);
	Int32	const GetGPTime(const Int32 nGPIndex);

	Int32	const GetGPToGPDistance(const Int32 nSGPIndex, const Int32 nEGPIndex);
	Int32	const GetLinkToLinkDistance(const Int32 nSLinkIndex, const Int32 nELinkIndex);
	Int32	const GetLinkToLinkTime(const Int32 nSLinkIndex, const Int32 nELinkIndex);
	Int32	const GetLinkDistance(const Int32 nRouteIndex);
	Int32	const GetLinkTime(const Int32 nRouteIndex);
	Int32  const GetAccLinkDistance(const Int32 nRouteIndex);
	Int32	const GetAccLinkTime(const Int32 nRouteIndex);

	Bool const GetPositionDivideInfo(const Int32 nPosIndex, Bool bFront, Int32 &nDist, Int32 &nTime);
	NeGoPosType	const GetPositionCode(const Int32 nPosIndex);
	Char*	const GetPositionName(const Int32 nPosIndex);
	Bool	const GetPositionVertex(const Int32 nPosIndex, DOUBLE_VERTEX *pwp);
	Char*	const GetGPCrossName(const Int32 nGPIndex);
	Char*	const GetGPNearDirName(const Int32 nGPIndex);
	Char*	const GetGPMidDirName(const Int32 nGPIndex);
	Char*	const GetGPFarDirName(const Int32 nGPIndex);
	Char*	const GetGPRoadName(const Int32 nGPIndex);
	Char*	const GetGPSAName(const Int32 nGPIndex);
	Char*	const GetGPTollName(const Int32 nGPIndex);

	UInt16	const GetGPExtcVoiceCode(const Int32 nGPIndex);
	
	Bool	const GetHipassInfo(const Int32 nGPIndex, Int32 nTurnType, Int32 *pHipassCount, UInt8 *pHiPassData);
    Bool	const GetSmartTallingLaneInfo(const Int32 nGPIndex, Int32 nTurnType, vector<UInt8> &smartTallingLane, vector<UInt8> &smartTallingMultiLane);

	Bool	GetLinkAttribute(const Int32 nRouteIndex, OsLinkAttribute *pLinkAttri);

	UInt16	const GetMaxLimitSpeed(const Int32 nRouteIndex);
	UInt8	const GetLinkCate(const Int32 nRouteIndex);
    Int32	const GetTbtTunnelLinkIndex(const Int32 nGPIndex, const Int32 nNextTBTGPIndex, bool isGetNextRoadLinkIndex);
	UInt8	const GetRoadCate(const Int32 nRouteIndex);
	Char *	const GetRoadName(const Int32 nRouteIndex);
	Char *  const GetNextRoadName(const Int32 nGPIndex);
	Char *	const GetNextCrossName(const Int32 nGPIndex, Int32 &nNextGPIndex);
	Bool	const GetLaneInfo(const Int32 nRouteIndex, stLaneInfo * pLaneInfo, Bool bMatchGP);
    Bool	const GetVoiceExtCode(const Int32 nRouteIndex, UInt8 &voiceCode);

    // 현위치부터 목적지까지 남은 차선정보 반환
    Bool	const GetAheadLaneInfo(const Int32 nRouteIndex, vector<stLaneInfo> &laneInfoList, Bool bMatchGP);
	stSDIInfo *	const GetSDIInfo(const Int32 nRouteIndex,Int32 &nSDIInfo);
    stCongestSection *	const GetCongestSection(const Int32 nRouteIndex,Int32 &nCongestSection);    // 정체 구간을 받는다.
	Bool	const GetSDIInfo(const Int32 nSDIIndex, stSDIInfo * pSDIInfo);
	Int32	const FindSDIInfo(const DOUBLE_VERTEX &wp, Int32 nFilterType, stSDIInfo *pSDIInfo);
	Bool	const CheckSDIVertex(const Int32 nSDIIndex, DOUBLE_VERTEX &wp);

	Bool	GetSAInfo(const Int32 nGPIndex, stServiceAreaInfo *pstSAInfo);
	Bool	GetNextSAInfo(const Int32 nGPIndex, Int32 *pnNextSADist, Char *pszNextSAName, Int32 nNextSANameLen);

	Int32	FindNextGPIndex(const Int32 nGPIndex, UInt32 nMaskFlag, Bool bSkipTunnel = FALSE, Bool bSkipSA = FALSE);
	Int32	FindPrvGPIndex(const Int32 nGPIndex, UInt32 nMaskFlag, Bool bSkipTunnel = FALSE, Bool bSkipSA = FALSE);


	DOUBLE_VERTEX *	const GetVertexByPosition(const Int32 nPosIndex);
	DOUBLE_VERTEX *	const GetVertexByGP(const Int32 nGPIndex);
	DOUBLE_VERTEX *	const GetVertexByLink(const Int32 nRouteIndex, const Bool bEnd);


	Int32		GetServiceVertexInfo(DOUBLE_VERTEX ** ppVertex);
	Int32		const GetServiceStartVertexIndex();						// 출발지점이 n 과 n+1사이에 있을경우 n+1의 인덱스
	Int32		const GetServiceEndVertexIndex();						// 목적지점이 n 과 n+1사이에 있을경우 n의 인덱스
	Int32		const GetServiceStartVertexIndex(Int32 nGPIndex);
	Int32		const GetServiceEndVertexIndex(Int32 nGPIndex);

	Int32		GetBackVertexInfo(Int32 nSlot, DOUBLE_VERTEX * pVertex);
	Int32		const GetBackStartVertexIndex(const Int32 nSlot);		// 출발지점이 n 과 n+1사이에 있을경우 n+1의 인덱스
	Int32		const GetBackEndVertexIndex(const Int32 nSlot);			// 목적지점이 n 과 n+1사이에 있을경우 n의 인덱스
	Int32 		const GetCurPosEndLinkIdx();
	inline Bool	IsEndGPIndex(Int32 nGPIndex)		{return (m_stServiceSlot.nRGServiceLinkCount-1 <= nGPIndex);};
	inline Bool IsEndLinkIndex(Int32 nLinkIndex)	{return (m_stServiceSlot.nTotalLinkCount-1 <= nLinkIndex);};
	inline Int32 GetTotalLinkCnt()	{return m_stServiceSlot.nTotalLinkCount;};
    Int32 GetNearestLaneIndex(const Int32 nRouteIndex);
    OsTBTList* GetCurrentTBTList();                                     // 현재 TBT list를 받는다.

protected:
	stGatheringData			m_stServiceSlot;
	stRoutePosDetailInfo	m_stServicePosInfo;

	stGatheringData			m_stBackRGSlotData[MAX_RGSERVICE_SLOT];
	stRoutePosDetailInfo	m_stBackRoutePosInfo[MAX_RGSERVICE_SLOT];

	Bool					m_bValidServiceSlot;
	Bool					m_bReferenceServiceSlot;		// 참조 슬롯 여부(TRUE면 메모리 해제 하면 안됨)

	stRouteViaDetailInfo	m_stServiceViaInfo;

	//////////////////////////////////////////////////////////////////////////
	// DriveInfo
public:
	const stDriveInfo *		GetDriveInfo() {return  &m_stDriveInfo;};
	Bool					UpdateDriveInfo(const stDriveInfo * const pstDriveInfo);

public:
	stDriveInfo				m_stDriveInfo;
	DOUBLE_VERTEX				m_wptLastPosition;


	DECLARE_SINGLETON(CRGServiceCommonData)
};


#endif //_RGSERVICECOMMONDATA_H_
