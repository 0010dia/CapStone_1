//////////////////////////////////////////////////////////////////////////
// RGServiceManager.h

#ifndef _RGSERVICEMANAGER_H_
#define _RGSERVICEMANAGER_H_

#include "LocalLinkV2.h"
#include "rg_def.h"
#include "mapengine_def.h"
#include "../guide/NcVoiceService.h"
#include "../guide/NcVoiceScript.h"

#define	MAXVERTEXLINK 10

class CRGMapManager;
class CSafeDriveInfomation;
class CRGPlayer;
class CSimulator;
class NcSDIManager;
class Tpeg;

typedef struct stSlotRouttingInfo
{
	UInt32		nRouteOption;
} SLOTROUTTINGINFO;

class CRGServiceManager
{
public:
	CRGServiceManager();
	virtual ~CRGServiceManager();

	Bool								Initialize();
	void								UnInitialize();

public:
	// nRGStatus => 0:GPS Bad, 1:RG 시작, 2:RG 진행중
    const stDriveInfo *	const			GetDriveInfo(const NsMatchingData * pMMData, Bool bSimulator=FALSE, Int32 nRGStatus=2, MAPADDRESS_INFO *pMapAddressInfo=NULL, AlternativeRoute* pAlternativeRoute=NULL);
	const stDriveInfo *	const			GetAndoDriveInfo(const NsMatchingData * pMMData, weak_ptr<LocalLinkV2> pLocalLinkV2, Int32 nRGStatus=2);
	Bool								InitBackSlotData();
	Bool								ServiceDataCollect(NsRouteReqLogic *pstRouteInData, NsRouteResLogic *pstRouteOutData);

	Int32                               GetVersionInfo();
    void                                SendBackupFile();
    void                                MakeAndoFile(Byte *pData, Int32 iSize);
	void								VoiceScenarioPlay(NeVoiceScenario eVoiceScenario, Int32 nValue=0);
/*
 * kiwoo 13.02.27
 * 맵 매칭 후보링크 시작 index 얻
 */
	//Int32								GetStartLinkIdx();
public:
	const Int32							GetCollectDataCount();							// 수집경로 데이터 갯수.
	const stGatheringData*	const		GetCollectData(Int32 nBackSlotIndex);			// 수집경로 데이터 가져가기
	const stRoutePosDetailInfo * const 	GetCollectPosInfo(Int32 nBackSlotIndex);		// 수집경로 지점정보 가져가기

	Bool								IsValideServiceData();							// 안내 경로가 유효한지 여부.
	Bool								IsRGService();									// 경로 안내를 하는지 여부(안내 경로가 설정되어 있더라도 안내를 시작하지 않았으면 경로가 없는 것으로 함)
	const stGatheringData* const 		GetServiceData();								// 안내경로 데이터 가져가기
	const stRoutePosDetailInfo * const 	GetServicePosInfo();							// 안내경로 지점정보 가져가기


	const Bool							ApplyServiceData(Int32 nBackSlotIndex, Bool bDeleteBackSlot, Bool isFirstSearch);			// 경로 선택

	void								CancelRGService();								// 경로 안내 취소
	void 								SetElectricVehicle(Bool bEV);
protected:
	Int32								GetCollectDataSlotIndex();						// 수집할수 있는 Slot 번호 얻기

	void								DebugPrintRPInOutData(NsRouteReqLogic *pstRouteInData, NsRouteResLogic *pstRouteOutData);

	//////////////////////////////////////////////////////////////////////////
	// 모의 주행 관련
public:
	const stDriveInfo *	const			StartSimulator(Int32 nSpeed);
	Bool								EndSimulator();
	const stDriveInfo * const			GetSimulatorCurrent();
	const stDriveInfo *	const			GetSimulatorService(Int32 nSpeed);
	const stDriveInfo *	const			GetSimulatorServiceGP(Int32 nIndex);
	const stDriveInfo *	const			GetSimulatorServicePrvGP();
	const stDriveInfo *	const			GetSimulatorServiceNextGP();
	const stDriveInfo *	const			GetSimulatorServicePos(Int32 nPos);

// 	MM_DrawData* GetVirtualMatchData() { return m_pMMData; }

	Bool GetVirtualMatchData(Int32 nTick, MM_VERTEX* pWp, Int32& nMultiBridge) 
	{
		Bool bResult = FALSE;
		if( m_nMapMatchTick == 0 )
			return bResult;

		SDL_LockMutex(m_pMutex_MMData);
		Int32 nMatchIndex = (nTick - m_nMapMatchTick) / DEFAULT_DEVIDE_MS;
		if( nMatchIndex > -1 && nMatchIndex < m_MMData_Temp.count )
		{
			pWp->angle	= m_MMData_Temp.pWp[nMatchIndex].angle;
			pWp->nIdx	= m_MMData_Temp.pWp[nMatchIndex].nIdx;
			pWp->x		= m_MMData_Temp.pWp[nMatchIndex].x;
			pWp->y		= m_MMData_Temp.pWp[nMatchIndex].y;
			pWp->z		= m_MMData_Temp.pWp[nMatchIndex].z;
			nMultiBridge= m_MMData_Temp.nMultiBridge;
			if((pWp->x != 0) && (pWp->y != 0))
				bResult		= TRUE;
			// 			SGL_DBGPRINT(_T("MMIndex[%d], %f,%f,%f,%f\r\n"),
			// 				nMatchIndex, pWp->x, pWp->y, pWp->z, pWp->angle);
		}
		else
		{
//			SGL_DBGPRINT(_T("Index Over ============= MMIndex[%d]\r\n"), nMatchIndex);
			pWp->angle	= m_MMData_Temp.pWp[m_MMData_Temp.count-1].angle;
			pWp->nIdx	= m_MMData_Temp.pWp[m_MMData_Temp.count-1].nIdx;
			pWp->x		= m_MMData_Temp.pWp[m_MMData_Temp.count-1].x;
			pWp->y		= m_MMData_Temp.pWp[m_MMData_Temp.count-1].y;
			pWp->z		= m_MMData_Temp.pWp[m_MMData_Temp.count-1].z;
			nMultiBridge= m_MMData_Temp.nMultiBridge;
			if((pWp->x != 0) && (pWp->y != 0))
				bResult		= TRUE;
		}
		SDL_UnlockMutex(m_pMutex_MMData);
		return bResult; 
	}
    
    MM_DrawData* GetVirtualMatchDataArray() {
        return &m_MMData_Temp;
    }

private:
	Bool					MakeVirtualMatchData();
	void calculateLinkAngle(Int16 linkId, stDriveInfo& stDriveInfo);

protected:
	CRGPlayer				*m_pRGPlayer;
	CSimulator				*m_pRGSimulator;

	Int32					m_nCollectSlotCount;
	Bool					m_bValideRGServiceData;
	Bool					m_bRGService;

	NsMatchingData			m_matchData;
	NsMatchingData			m_prevMatchData;

	MM_DrawData*			m_pMMData;

	MM_DrawData				m_MMData_Temp;
	Int32					m_nMapMatchTick;
	SDL_mutex*				m_pMutex_MMData;

	Bool					m_bElectricVehicle;
    // MCL
public:
    void clearConfiguration();
    void applyConfiguration();
};

#endif // _RGSERVICEMANAGER_H_
