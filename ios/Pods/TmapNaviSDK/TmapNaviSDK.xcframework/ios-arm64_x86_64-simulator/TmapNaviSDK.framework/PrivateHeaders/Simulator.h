//////////////////////////////////////////////////////////////////////////
// Simulator.h

#ifndef _SIMULATOR_H_
#define _SIMULATOR_H_

enum NeSimulMoveType
{
	MOVETYPE_NORMAL = 0,
	MOVETYPE_GOSTART,
	MOVETYPE_GOEND,
	MOVETYPE_GOGP,
	MOVETYPE_NEXTGP,
	MOVETYPE_PRVGP,
	MOVETYPE_POS,
	MOVETYPE_PROGRESS,
	MOVETYPE_PAUSE,	
	Num_Of_SimulMoveType
};

enum NeSimulPosType
{
	POSTYPE_NORMAL = 0,
	POSTYPE_START,
	POSTYPE_END,
	Num_of_SimulPosType
};

typedef struct stSimulateResult
{
	UInt32 		nMMLinkIndex;
	UInt32 		nMMLengthToEnd;
	UInt32 		nMMAngle;
	Int32		idxVertex;		//wp가 n-1 과 n 번째 Vertex에 존재할경우 n	(현위치 전방에 있는 Index)
	DOUBLE_VERTEX	wptMM;

	NeSimulPosType	ePosType;
} SIMULATERESULT;

class CSimulator
{
public:
	CSimulator();
	virtual ~CSimulator();

	Bool	Initialize();
	void	UnInitialize();

	Bool	InitStartSimulator();
	void	ResetData();

	Bool	MakeRouteVertexData();
	void	SetMoveSpeed(Int32 nSpeed);

	Bool	GetSimulateMatchInfo(NeSimulMoveType eMoveType, SIMULATERESULT *pstSimulResult, Int32 nIndex = -1/*GP Index or 출발점에서 거리*/);
	Bool	GoStartPosition();
	Bool	GoEndPosition();
	Bool	NextGPPosition();
	Bool	PrvGPPosition();
	Bool	GoGPPosition(Int32 nGPIndex);
	Bool	MovePosition(Int32 nDist);
	
	Int32	GetSpeed() {return m_nMoveSpeed;};

	Int32	GetPrvVertexIndex() { return m_nPrvVertexIndex;};
	Int32	GetCurrentVertexIndex() { return m_nVertexIndex;};

protected:
	Int32	GetGPIndex(Int32 nLinkIndex, Int32 nLengthToEnd);
	Int32	GetLinkIndex(Int32 nVertexIndex);
	Bool	GetMatchPoint(DOUBLE_VERTEX * pVertex, Float m, Float n, DOUBLE_VERTEX wpt1, DOUBLE_VERTEX wpt2);

	Bool	UpdateCurrentMMData();
	Int32	GetLengthToEnd(Int32 nLinkIndex, Int32 nVertexIndex);
	Int32	GetCurentMMAngle();


protected:
	stGatheringData	*		m_pRGGatherData;
	stRoutePosDetailInfo *	m_pRGPosData;

	Int32					m_nLinkIndex;			// 현재 링크의 Index
	Int32					m_nPrvVertexIndex;			// n-1 과 n 번째 존재할경우 n	(현위치 전방에 있는 Index)
	Int32					m_nVertexIndex;			// n-1 과 n 번째 존재할경우 n	(현위치 전방에 있는 Index)
	Int32					m_nGPIndex;				// n-1 과 n 번째 존재할경우 n	(현위치 전방에 있는 GP Index : 현재 안내 해야 되는 GP)
	DOUBLE_VERTEX				m_wptMM;				// 현재 매칭된 좌표.
	Int32					m_nLengthToEnd;			// 현재 위치(m_wptMM)에서 현재 링크의 끝까지의 거리

	NeSimulPosType			m_ePosType;

	SIMULATERESULT			m_stSimulResult;
	
	Int32					m_nMoveSpeed;			// 모의주행 속도
	Int32					m_nMoveDist;			// 모의주행 1회 이동 거리

	Int32					m_nStartVertexIndex;
	Int32					m_nEndVertexIndex;
};

#endif // _SIMULATOR_H_