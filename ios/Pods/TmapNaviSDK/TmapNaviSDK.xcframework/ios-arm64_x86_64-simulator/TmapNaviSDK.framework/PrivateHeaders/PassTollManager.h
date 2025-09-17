// PassTollManager.h
//////////////////////////////////////////////////////////////////////////

#ifndef _PASSTOLLMANAGER_H_
#define _PASSTOLLMANAGER_H_

#define MAX_SAVE_TOLL_COUNT			50
#define MAX_SAVE_TOLL_EXTEND_COUNT	10

typedef struct _tagPassTollGateInfo
{
	Int32				m_nTollType;	
	Int32				m_nRoadCate;
	Int32				m_nTollID;
	Int32				m_nExtTollCount;
	Int32				m_nExtendTollID[MAX_SAVE_TOLL_EXTEND_COUNT];
} PASSTOLLGATEINFO, *PPASSTOLLGATEINFO;

typedef struct _tagSaveTollInfo
{
	Int32				m_nSaveTime;

	Int32				m_nTollListCount;
	PASSTOLLGATEINFO	m_stPassTollList[MAX_SAVE_TOLL_COUNT];
} SAVETOLLINFO, *PSAVETOLLINFO;

class CRGMapManager;
class CPassTollManager
{
	NOT_COPYABLE(CPassTollManager)
private:
	CPassTollManager();
	~CPassTollManager();

public:

	Bool Initialize();
	void UnInitialize();

public:
	Bool SavePassTollGateInfo(Long nTime, UInt8 nMMState, UInt32 nMMLinkID);

	Bool RemoveAllTollGateData();


	Int32 GetTollData(PASSTOLLGATEINFO ** ppTollInfo);

protected:
	Bool IsSaveTollInfo();
	Bool AddTollInfo(Int32 nSaveTime, Int32 nTollID, Int32 nRoadCate, Bool bExtend);

	Bool SaveTollData();
	Bool LoadTollData();

protected:
	CSglFile			*m_pPassTollFile;
	SAVETOLLINFO		*m_pstSaveTollInfo;

	Int32				m_nAddPssTollIndex;
	DECLARE_SINGLETON(CPassTollManager)
};

#endif // _PASSTOLLMANAGER_H_
