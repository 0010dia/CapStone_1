//////////////////////////////////////////////////////////////////////////
// RGServiceConfig.h

#ifndef _RGSERVICECONFIG_H_
#define _RGSERVICECONFIG_H_

#include "sgl_inc.h"
#include "rgdata_def.h"

#define 	UI_DEFAULT_SET			0				// 환경 설정 Default Value	

#define		UI_POI_CNT				15				// 표출할 POI 갯수
#define		UI_CAMERA_CNT			12				// 카메라 음성 안내 갯수
#define		UI_GUIDE_CNT			12				// 일반 음성 안내 설정 
#define		UI_ETC_GUIDE_CNT		21				// 기타 음성 안내 설정

class CRGServiceConfig
{
	NOT_COPYABLE(CRGServiceConfig)
private:
	CRGServiceConfig();
	virtual ~CRGServiceConfig();

public:
	// 경로 안내 환경값을 얻는다.
	RG_CONFIG& GetConfig();

	// 경로 안내 환경값을 설정한다.
	void SetConfig(PRG_CONFIG pConfig);

private:
	// 파일에서 경로 안내 환경값 읽는다.
	Bool FileReadDefaultConfig();

	// 경로 안내 환경값을 파일에 저장한다. (프로젝트별 기본 안내 파일을 생성시만 사용)
	Bool FileWriteDefaultConfig();

	// 명칭으로 환경값 변수를 찾아 설정한다.
	Bool SetValue(Char *szName, Byte *pValue, Int32 nSize);


	RG_CONFIG m_sData;

	DECLARE_SINGLETON(CRGServiceConfig)
};

#endif // _RGSERVICECONFIG_H_
