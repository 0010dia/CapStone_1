// sgl_pathenv.h

#ifndef __SGL_PATHENV_H
#define __SGL_PATHENV_H

#include "sgl.h"

typedef struct tagSglPath
{
	Char		szPath[SGL_MAX_PATH];			// DB파일 상대경로
	Int32		nCacheSize;			// 캐쉬 크기
	Int32		nCacheBlockSize;	// 캐쉬 블럭 크기
}SGL_PATH, *PSGL_PATH;

class CSglPathEnv
{
public:
	CSglPathEnv();
	~CSglPathEnv();

public:

	/// 파일 패스 슬롯을 초기화 한다.
	/**
		@param szRootPath	[IN] Root 패스
		@param nPath		[IN] 파일 패스 개수
		@param pPath		[IN] 파일 패스 데이터
		@return
	**/
	void InitPath(PChar szRootPath, Int32 nPath, PSGL_PATH pPath);

	/// Root 패스를 얻는다. (DB 패스)
	/**
		@return		Root 패스
	**/
	PChar GetRootPath();
	PTChar GetRootPathT();

	/// 패스를 얻는다.
	/**
		@param nIdxFile			[IN] 파일 인덱스(슬롯별 인덱스 0 부터 사용)
		@param szPath			[IN] 풀 패스가 저장될 버퍼
		@param pCacheSize		[OUT] 파일의 캐쉬를 사용할 전체 크기 (NULL 이면 값을 설정하지 않는다.)
		@param pCacheBlockSize	[OUT] 파일의 캐쉬 블럭 1개 크기 (NULL 이면 값을 설정하지 않는다.)
		@return					szPath 를 리턴값으로 한다. (실패시 NULL)
	**/
	Char* GetPath(Int32 nIdxFile, PChar szPath, Int32 *pCacheSize=NULL, Int32 *pCacheBlockSize=NULL);
	TChar* GetPathT(Int32 nIdxFile, PTChar szPath, Int32 *pCacheSize=NULL, Int32 *pCacheBlockSize=NULL);

private:	
	Char			m_szRootPath[SGL_MAX_PATH];	// 메인 DB 패스
	Int32			m_nPath;
	PSGL_PATH		m_pPath;
};

#endif // __SGL_PATHENV_H
