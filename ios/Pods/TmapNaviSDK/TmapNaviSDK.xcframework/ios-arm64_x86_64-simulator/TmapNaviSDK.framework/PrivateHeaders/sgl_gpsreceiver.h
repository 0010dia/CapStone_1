#ifndef __SGL_GPSRECEIVER_H__
#define __SGL_GPSRECEIVER_H__

#include "sgl_base.h"
#include "sgl_common.h"
#include "gpsdef.h"

class CSglGpsParser;
class CSglGpsReceiver
{
	NOT_COPYABLE(CSglGpsReceiver)
private:
	CSglGpsReceiver();
	virtual ~CSglGpsReceiver(void);

public:

	/// GPS를 초기화 한다.
	/**
		@param eGpsType			[IN] GPS 타입
		@param fGpsPreTime		[IN] GPS 좌표 이동을 미리 진행 시킨다. (단위, 초)
		@param lpfnCallback		[IN] GPS 데이터를 받을 콜백 합수
		@param pSerialPort		[IN] 시리얼 포트 설정 (GPS 타입이 eGpsTypeWinWaitcomm, eGpsTypeWinPoling 일때 만 유효함)
		@param bThreadStart		[IN] Window 일때 GPS 스레드를 바로 시작할지 여부
		@return					TRUE:성공, FALSE:실패
	**/
	Bool Init(NeGpsType eGpsType, Float fGpsPreTime, LPCALL_RECEIVEGPS lpfnCallback, PSERIAL_PORT pSerialPort = NULL, Bool bThreadStart = FALSE);

	/// GPS 데이터를 입력 받는다. (안드로이드)
	/**
		@param szNmea			[IN] NMEA 텍스트
		@param nSize			[IN] NMEA 텍스트 크기
		@param bPosition		[OUT] 입력값이 GPS값을 추출하기 위한 필요한 최소한의 데이터가 존재하는지 여부 (이동 좌표 존재 여부)
		@return					맵매칭 여부(TRUE미면 주행)
	**/
	Bool InputGpsData(Char *szNmea, Int32 nSize, Bool &bPosition);

	/// NMEA 파싱된 데이터를 얻는다.
	/**
		@return					NMEA*
	**/
	NMEA* GetNmeaData();

#if defined(_WIN32) && !defined(_WIN32_PHONE) && !defined(__MINGW32__)
	/// GPS 시리얼 재 설정 한다.
	/**
		@param pSerialPort		[IN] 시리얼 포트 설정 (GPS 타입이 eGpsTypeWinWaitcomm, eGpsTypeWinPoling 일때 만 유효함)
		@return
	**/
	void SetSerialPort(PSERIAL_PORT pSerialPort);

	/// GPS 시리얼 포트에 데이터를 Write 한다.
	void SerialWrite(Byte *pBuf, Int32 nSize);

	/// GPS 스레드를 시작 한다.
	/**
		@return					TRUE:성공, FALSE:실패
	**/
	Bool StartThread();

	/// GPS 스레드를 종료 한다.
	void StopThread();
#endif

	void SetSaveLog(Bool bSave) {m_bSaveLog = bSave;};

private:
	NeGpsType m_eGpsType;
	Float m_fGpsPreTime;

public:
	CSglGpsParser*	m_pGPSParser;

	// GPS 데이터 Update Callback 함수
	LPCALL_RECEIVEGPS GPSUpdate;

	static Bool DataParser(Byte *pData, Int32 nSize, NMEA_ID &eNmeaID);
	
	static Bool CheckChar(Char c);

	// GPS Read 관련
	Char m_szDollerLine[GPS_READ_SIZE+1];
	Int32 m_nLen, m_nComma;

	Bool m_bSaveLog;
	FILE *m_pFile;

#if defined(_WIN32) && !defined(_WIN32_PHONE) && !defined(__MINGW32__)

public:
	// GPS 스레드
	static DWORD WINAPI ReceiveProc_File(LPVOID lParam);
	static DWORD WINAPI ReceiveProc_Waitcomm(LPVOID lParam);
	static DWORD WINAPI ReceiveProc_Poling(LPVOID lParam);


	// GPS모듈이 Open 상태인지 체크한다.
	Bool IsOpenPort();

	// GPS 시리얼 포트 핸들을 얻는다.
	HANDLE GetPortHandle();

private:
	// GPS 시리얼 포트를 연다.
	Bool OpenPort();

	// GPS 시리얼 포트를 닫는다.
	void ClosePort();

	// GPS 시리얼 포트에서 데이터를 읽는다.
	Int32 ReadGPS(PByte pBuffer, DWord dwMaxLength);

	// GPS 수신 스레드 핸들
	HANDLE m_hReceiveThread;
	//스레드 종료 시킬 플레그
	Bool m_bEndThread;

	//Com Port 핸들
	HANDLE m_hPort;
	SERIAL_PORT m_sSerialPort;


#endif

	DECLARE_SINGLETON(CSglGpsReceiver);
};


#endif // __SGL_GPSRECEIVER_H__
