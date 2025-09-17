//////////////////////////////////////////////////////////////////////////
// TvasData.h

#ifndef _TVASDATA_H_
#define _TVASDATA_H_

#include "sgl_inc.h"
#include "rgdata_def.h"

class CTvasData
{
	NOT_COPYABLE(CTvasData)
private:
	CTvasData();
	virtual ~CTvasData();

public:
	/// TVAS 파일을 설정한다.
	/**
		@param nSlot			[IN] 설정할 슬롯(0 ~ MAX_RGSERVICE_SLOT-1)
		@param szFileName		[IN] TVAS 파일명 (BD Root 다음 부터 패스)
		@param eVersion			[IN] TVAS 버전
		@return					TRUE:성공, FALSE:실패
	**/
        Bool Open(Int32 nSlot, const Char *szFilePath, NeTvasVersion eVersion);
		Bool Open(Int32 nSlot, const Char *data, Int length);

		int GetNewSlot();
	// TVAS 데이터를 얻는다.
	/**
		@param nSlot			[IN] 설정할 슬롯(0 ~ MAX_RGSERVICE_SLOT-1, 경로가 설정되어 있으면 -1)
		@return					파싱 된 TVS_Data (실패시 NULL)
	**/
	TVS_Data* GetData(Int32 nSlot=-1);
    TVS_Data* GetAlternativeRouteData();

	// TVAS 데이터를 선택한다.
	/**
		@param nSlot			[IN] 설정할 슬롯(0 ~ MAX_RGSERVICE_SLOT-1)
		@param bDeleteBackSlot	[IN] 나머지 슬롯 초기화 할지 여부
		@return					TRUE:성공, FALSE:실패
	**/
	Bool SelectData(Int32 nSlot, Bool bDeleteBackSlot);

	// TVAS 데이터를 초기화 한다.
	void EmptyData();

	// 재 탐색용 탐색 조건 데이터를 얻는다. (마지막 선택한 경로의 탐색 조건 데이터)
	/**
		@param pData			[OUT] 탐색 조건 데이터
		@param pData			[IN] 버퍼 크기
								[OUT] 탐색 조건 데이터 크기
		@return					TRUE:성공, FALSE:실패
	**/
	Bool GetReRouteData(Byte *pData, Int32 &nSize);

private:
    void EmptySlot(Int32 nSlot);

	TVS_Data	m_sData[MAX_RGSERVICE_SLOT];	// 파싱된 TVAS 데이터
	Byte		*m_pBuffer[MAX_RGSERVICE_SLOT];	// TVAS 데이터 원본
	Int32		m_nSize[MAX_RGSERVICE_SLOT];	// TVAS 데이터 원본 크기

	Int32		m_nSelectIndex;					// 선택된 데이터(경로 최종 선택시 설정)
	Int32		lastSlotNumber;

	DECLARE_SINGLETON(CTvasData)
};

#endif // _TVASDATA_H_