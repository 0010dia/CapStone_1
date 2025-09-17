/**
 * T map 4.0 Navi Engine Document header
 * @author flintlock
 *
 */
#ifndef __NAVIDOCUMENT_H__
#define __NAVIDOCUMENT_H__

#include "navimodule_inc.h"


class CNaviDocument
{
	NOT_COPYABLE(CNaviDocument)

private:
	CNaviDocument();
	virtual ~CNaviDocument();

public:
	void InitDocument(PNAVIMODULE_INIT sInit);
	//////////////////////////////////////////////////////////////////////////
	// 임시코드
	//////////////////////////////////////////////////////////////////////////
	Int32					m_nMapViewType;


	//////////////////////////////////////////////////////////////////////////
	// 맵관련
	//////////////////////////////////////////////////////////////////////////
	DOUBLE_VERTEX 				m_wcMap;						// 주행 좌표
	Int32					m_nAngleMap;					// 주행 각도

	DOUBLE_VERTEX 				m_wcMove;						// 이동 좌표
	Int32 					m_nAngleMove;					// 이동 각도

	Int32 					m_nLevel;						// 맵 레벨
	Int32 					m_nSubLevel;					// 맵 서브 레벨
    Float                   m_fTiltAngle;                   // TiltAngle

	Int32					m_nBirdViewAngle;				// 버드뷰 각도

	Int32					m_nMapViewCount;				// 맵 Count

	Int32					m_nMapScaleWidth;				// 지도 스케일 구하는 기준 넓이
	Int32					m_nPreMapViewType;				// 이전 맵 뷰 모드
    Int32                   m_nPreMapMoveType;              // 이전 맵 무브 모드

	//////////////////////////////////////////////////////////////////////////
	// GPS 관련
	//////////////////////////////////////////////////////////////////////////
	Int32 					m_nGpsState;					// GPS 상태
	Int32 					m_nGpsSpeed;					// GPS 속도


	//////////////////////////////////////////////////////////////////////////
	// 설정 관련
	//////////////////////////////////////////////////////////////////////////
	Bool					m_bSafetyMode;					// SAFETY MODE
	Bool					m_bChangedUI;					// UI 화면 변경


	//////////////////////////////////////////////////////////////////////////
	// 경로관련
	//////////////////////////////////////////////////////////////////////////
	UInt32					m_uRouteTotalDiatance;			// 현재 경로 전체 길이


	//////////////////////////////////////////////////////////////////////////
	// UI 페이지간 데이터 전달 관련
	//////////////////////////////////////////////////////////////////////////
	Int32 					m_nUI_Value[10];				// UI간 데이터 전달 ( 한 Depth 간 사용 추천 : 사용 후 -1 로 초기화 )
	
    Bool                    IsGetMapTabMode();
    Bool                    SetMapTabMode(Bool bMapTabMode);
    
private:
	Int32					m_nSetRouteSpot;
	Int32					m_nLeveScal[14];				// 지도 레벨 스케일
    Bool                    m_bIsMapTabMode;

public:
	void SetUIRouteSpot(Int32 Idx)	{ m_nSetRouteSpot = Idx;  }		// -1:일반, 0:출발지, 1~3:경유지, 4:목적지
	Int32 GetUIRouteSpot()			{ return m_nSetRouteSpot; }

	void SetUIValueInit();

	Int32 GetMapLevelScal(Int32 nLevel);

	DECLARE_SINGLETON(CNaviDocument)
};
#endif // __NAVIDOCUMENT_H__
