// RuntimeEnv.h

// �ۼ��� : ������
// �ۼ��� : 2008.02.04
// ��  �� : 

#ifndef __RUNTIMEENV_H
#define __RUNTIMEENV_H

#include "env_def.h"
#include "rg_def.h"

//#ifdef _DEBUG
//	#define DEBUGPRINT_TIME
//#endif



enum NeDebugTimeName
{
	//////////////////////////////////////////////////////////////////////////
	//Draw Time
	eUIDraw1 = 0,
	eUIDraw2,
	eUIDrawCount,
	eUIDrawTime,

	eControlDraw1,
	eControlDraw2,
	eControlDrawCount,
	eControlDrawTime,

	eControlImageDraw1,
	eControlImageDraw2,
	eControlImageDrawCount,
	eControlImageDrawTime,

	eControlButtonDraw1,
	eControlButtonDraw2,
	eControlButtonDrawCount,
	eControlButtonDrawTime,

	eControlListBoxDraw1,
	eControlListBoxDraw2,
	eControlListBoxDrawCount,
	eControlListBoxDrawTime,

	eControlTextDraw1,
	eControlTextDraw2,
	eControlTextDrawCount,
	eControlTextDrawTime,

	eControlEditBoxDraw1,
	eControlEditBoxDraw2,
	eControlEditBoxDrawCount,
	eControlEditBoxDrawTime,

	eControlAreaDraw1,
	eControlAreaDraw2,
	eControlAreaDrawCount,
	eControlAreaDrawTime,

	eControlTextViewDraw1,
	eControlTextViewDraw2,
	eControlTextViewDrawCount,
	eControlTextViewDrawTime,

	eControlGroupTabDraw1,
	eControlGroupTabDraw2,
	eControlGroupTabDrawCount,
	eControlGroupTabDrawTime,


	eControlGroupCheckDraw1,
	eControlGroupCheckDraw2,
	eControlGroupCheckDrawCount,
	eControlGroupCheckDrawTime,

	eControlGroupRadioDraw1,
	eControlGroupRadioDraw2,
	eControlGroupRadioDrawCount,
	eControlGroupRadioDrawTime,

	eControlAniDistanceDraw1,
	eControlAniDistanceDraw2,
	eControlAniDistanceDrawCount,
	eControlAniDistanceDrawTime,

	eControlCanvasDraw1,
	eControlCanvasDraw2,
	eControlCanvasDrawCount,
	eControlCanvasDrawTime,

	eControlTextBoxMDraw1,
	eControlTextBoxMDraw2,
	eControlTextBoxMDrawCount,
	eControlTextBoxMDrawTime,

	eCommonPageDraw1,
	eCommonPageDraw2,
	eCommonPageDrawCount,
	eCommonPageDrawTime,

	eResourceGetImage1,
	eResourceGetImage2,
	eResourceGetImageCount,
	eResourceGetImageTime,

	esglBltSurfaceWithAlphaMask1,
	esglBltSurfaceWithAlphaMask2,
	esglBltSurfaceWithAlphaMaskCount,
	esglBltSurfaceWithAlphaMaskTime,
	
	//////////////////////////////////////////////////////////////////////////
	//Cache Time
	eUIResourceCache1,
	eUIResourceCache2,
	eUIResourceCacheCount,
	eUIResourceCacheSize,
	eUIResourceCacheTime,

	eUIResourceFile1,
	eUIResourceFile2,
	eUIResourceFileCount,
	eUIResourceFileSize,
	eUIResourceFileTime,

	MAX_DEBUGTIME_NAME,
};
#define MAX_DEBUGTIME_CHAR	100000

#ifdef DEBUGPRINT_TIME

#define RUNTIME_SETDRAWTIME(nIdxName)														\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetDrawTime(nIdxName);															\
}

#define RUNTIME_SETDRAWTIME_PRINT(msg, nIdxName, nIdxNameOld, nIdxCount, nIdxTotalTime)		\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetDrawTimePrint(msg, nIdxName, nIdxNameOld, nIdxCount, nIdxTotalTime);			\
}

#define RUNTIME_SETUICACHE(bCache)															\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetUICache(bCache);																\
}

#define RUNTIME_SETUICACHE_PRINT(bCache, msg, nSize)										\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetUICachePrint(bCache, msg, nSize);											\
}


#define RUNTIME_SAVEFILEDEBUG()																\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SaveFileDebug();																\
}

#else
	#define RUNTIME_SETDRAWTIME 0
	#define RUNTIME_SETDRAWTIME_PRINT 0
	#define RUNTIME_SETUICACHE 0
	#define RUNTIME_SETUICACHE_PRINT 0
	#define RUNTIME_SAVEFILEDEBUG 0
#endif

#define RUNTIME_SETMEMORYSTATUS(msg)														\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetMemoryStatus(msg);															\
}

#define RUNTIME_SETRENDERSTATUS(fps, time)													\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetRenderStatus(fps, time);														\
}

#define RUNTIME_SETUIDRAWTIME(time)															\
{																							\
	CRuntimeEnv &Runtime = CRuntimeEnv::GetInstance();										\
	Runtime.SetUIDrawTime(time);															\
}


class CRuntimeEnv
{
	friend class CEnvSet;

//	NOT_INSTANCE(CRuntimeEnv)
	NOT_COPYABLE(CRuntimeEnv)

private:
	CRuntimeEnv();
	virtual ~CRuntimeEnv();

public:
	void SetDrawTime(Int32 nIdxName);
	void SetDrawTimePrint(Char *szMsg, Int32 nIdxName, Int32 nIdxNameOld, Int32 nIdxCount, Int32 nIdxTotalTime);
	void SetUICache(Bool bCache);
	void SetUICachePrint(Bool bCache, Char *szMsg, Int32 nSize);
	void SaveFileDebug();

	void SetMemoryStatus(Char *szMsg);
	void SetRenderStatus(Int32 nFPS, Int32 nRenderTime);
	void SetUIDrawTime(Int32 nDrawTime);

public:
    Bool m_bServerRoute;            // ���� Ž�� ����
    Bool m_bLocalTVAS;            // Local
	Bool m_bModule_Mapview;			// ���� (2D, 3D�� global �� �����Ѵ�.)
	Bool m_bModuleGPSMM;			// GPS, �ʸ�Ī ���
	Bool m_bModuleRG;				// ��� �ȳ� (�������� ����� ������)
	Bool m_bModuleServerRoute_T32;	// ���� ��� Ž�� ��� (TVAS 3.2)
	Bool m_bModuleTmapAndo;			// Ƽ�� ���� �������� �����

	//////////////////////////////////////////////////////////////////////////
	NMEA						m_GpsNmea;			// �ֽ� GPS NMEA ������
	eHoliday_Type				m_eHoliday_Type;	// ������ Ÿ��
	Char m_szMdn[12];								// ��ȭ��ȣ (- ����)

	//////////////////////////////////////////////////////////////////////////
	// ���� �׽�Ʈ��
	Int32 *m_pDebugItem;		// Time �ε���
	Char *m_szDebugText;		// Time ��� ���� ����
	Int32 m_nDebugTextSize;		// Time ��� ���� ����

	// Draw ����

	DWord m_dwPhysFirst;		// �ʱ� ���� ������ �޸�
	DWord m_dwVirtualFirst;		// �ʱ� ���� �� �޸�
	DWord m_dwPhysCur;			// ���� ���� ������ �޸�
	DWord m_dwVirtualCur;		// ���� ���� �� �޸�
	DWord m_dwPhysChange;		// ������ ������ �޸�
	DWord m_dwVirtualChange;	// ������ �� �޸�

	Int32 m_nRenderFPS;			// ������ �����Ӽ�
	Int32 m_nRenderTime;		// ������ �ð�
	Int32 m_nUIDrawTime;		// UI Draw �ð�

	Int32 m_nRenderCnt;			// ������ ȸ��
	Int32 m_nUIDrawCnt;			// UI Draw ȸ��

	//////////////////////////////////////////////////////////////////////////

protected:

	DECLARE_SINGLETON(CRuntimeEnv);
};

#endif // __RUNTIMEENV_H
