#ifndef __GPSDEF_H__
#define __GPSDEF_H__

#define MAX_BEFORE_SPEED_CNT	 1
#define MAX_BEFORE_HEADING_CNT	 1

#ifndef RADIAN
#define		RADIAN  0.017453288
#endif
#define KM_PER_HOUR_TO_METER  0.2777777777777778  //    Km/h  ->  m/s

#define GPS_VALIDE_SIGNAL_VALUES	50

//////////////////////////////////////////////////////////////////////////
// 구조체 정의
//////////////////////////////////////////////////////////////////////////

//======================================================================
// sentence id
//======================================================================
typedef enum
{
	NMEA_GPGLL = 0,
	NMEA_GPRMC,
	NMEA_GPGSA,
	NMEA_GPGGA,
	NMEA_GPGSV,
	NMEA_GPVTG,
	NMEA_MIGDR,			// 2011.08.23 Microinfinity DR/GPS Infomation
	NMEA_MSPOS,			// M&Service Position 정보(Nmea 포멧 대체용)
	NMEA_NOT_USE,
	NMEA_BAD,
	NMEA_CHECKSUM_BAD,
	NMEA_MAX,
} NMEA_ID;

typedef enum
{
	NMEA_UPDATE = 0,
	NMEA_KEEP_ANGLE,
	NMEA_KEEP_ANGLE_SPEED,		// Hdop, Position 업데이트
	NMEA_STANDSTILL,
} NMEA_update_mode;

typedef enum
{
	WGS84,
	BESSEL
} coord_unit;

//////////////////////////////////////////////////////////////////////////

typedef struct
{
	int             year;
	int             month;
	int             day;
	int             hour;
	int             min;
	int             sec;
    int             msec;
} NMEA_DateTime;


//////////////////////////////////////////////////////////////////////////


#define	MAX_SVINFO					12

typedef struct
{
	int		nmessage;
	int		messageid;
	int		nSV;
	int		SVid[12];
	int		elevation[12];
	int		azimuth[12];
	int		db[12];
} NMEA_GSV;

typedef struct
{
	DOUBLE_VERTEX	wp;

	int		time;
	Float	latitude;
	char	NorS;
	Float	longitude;
	char	EorW;
	int		fix;
	int		nSatellite;
	Float	hdop;
	Float	altitude;
	char	unit;
	Float	altitudeofwgs84;
	char	unit2;
	Float	dgpsupdatetime;
	int		stationid;
} NMEA_GGA;

typedef struct
{
    char	mode1;  // 'M'=Manual, forced to operate in 2D or 3D, 'A'=Automatic, 3D/2D
	int		mode2;  // 1=Fix not available, 2=2D, 3=3D
	int		usedsv[12];
	Float	pdop;
	Float	hdop;
	Float	vdop;
} NMEA_GSA;

typedef struct
{
	DOUBLE_VERTEX	wp;

	int		time;
	int		datestamp;

	char	valid;
	char	NorS;
	char	EorW;
	char	EorW2;

	Float	latitude;
	Float	longitude;
	Float	speed;
	Float	angle;
	Float	variation;
} NMEA_RMC;

typedef struct
{
	int		timeType;

	char	NorS;
	char	EorW;
	char	time[20];

	Float	latitude;
	Float	longitude;
	Float	speed;
	Float	angle;
	Float	altitude;
	Float	accuracy;
    
    Int32   gpsmode;    // 1: Phone GPS 2:DRGPS

	NMEA_DateTime	dateTime;
} stNMEA_MSPOS;

typedef struct
{
	int			nTime;			// **  UTC time					140047.000					HrMinSec
	int			nSateliteCnt;	// **  Number of satellite 
	int			nFixQuality;	// **  Fix Quality				1							0 Solution Invalid, 1 Position Fix
	int			nMode2;			// **  Mode 2					3							1 Solution Invalid, 2 GPS 2D Fix, 3 GPS 3D Fix
	DOUBLE_VERTEX	wpGPS;			// **  GPS Latitude				37.5026988		dd.ddddd	WGS84(North = +, South = -)
	char		cNorS;			// **  N/S Indicator			N							N=north or S=south
	// **  GPS Longitude			127.01113420	ddd.ddddd	WGS84(East = +, West = -)
	char		cEorW;			// **  E/W Indicator			E							E=east or W=west
	DOUBLE_VERTEX	wpDR;			// **  DR/GPS Latitude			37.5026489		dd.ddddd	WGS84(North = +, South = -)
	char		cNorS_DR;		// **  N/S Indicator			N							N=north or S=south
	// **  DR/GPS Longitude			127.01112128	ddd.ddddd	WGS84(East = +, West = -)
	char		cEorW_DR;		// **  E/W Indicator			E							E=east or W=west
	Float		fAngleGPS;		// **  GPS Course				123.08			degree
	Float		fSpeedGPS;		// **  GPS Speed				004.06			m/s
	Float		fAngleDR;		// **  DR/GPS Course			133.48			degree
	Float		fSpeedDR;		// **  DR/GPS Speed				005.13			m/s
	Float		fPDOP;			// **  PDOP						04.1						Position dilution of Precision
	Float		fHDOP;			// **  HDOP						01.6						Horizontal Dilution of Precision
	int			nGyroErrorFlag;	// **  Gyro Error Flag			0							0 : Normal -> DR/GPS Mode, 1 : Error -> GPS Mode
	int			nOdometerErrorFlag;	// **  Odometer Error Flag		0							Same to Gyro Error Flag
	Float		fDRParam1;		// **  DR Parameter 1			100.23
	Float		fMeanGyroOutput;// **  Mean Gyro Output			-04.22			deg/sec
	Float		fDRParam2;		// **  DR Parameter 2			-294.06
	int			nOdometerSF;	// **  Odometer SF				02594			pulse/Km
	int			nOdometerPulse;	// **  Odometer Pulse			014							Number of pulse in the second
} stNMEA_MIGDR;

typedef struct
{
	DOUBLE_VERTEX		wp;

	int				tvas_time;		// tvas용 시간
	int				week;           //(1:월~7:일)
	Bool			IsNight;
	int				state;          // GPS 상태
	int				extend;         // GPS 확장 기능
	int				speed;	
	int				angle;
	Float			hdop;			// HDOP

	Float			fAngle;			// 차량각도 누적 계산용
    Bool            IsDRGps;        //
} NMEA_ParsedData;


typedef struct
{
	int				total_speed;
	int				sub_speed;
} NMEA_avg;

typedef struct
{
	int				hour;
	int				min;
} NMEA_suntime;

typedef struct
{
	int		daylen;
	int		morning_twilight;
	int		sunrise;
	int		noontime;
	int		sunset;
	int		evening_twilight;
} NMEA_sun;

typedef struct
{
	NMEA_ParsedData	data;
	NMEA_DateTime	datetime;
	NMEA_sun		sun;
	NMEA_avg		avg;

	NMEA_GSV		gsv;
	NMEA_GGA		gga;
	NMEA_GSA		gsa;
	NMEA_RMC		rmc;
	stNMEA_MSPOS	mspos;
	stNMEA_MIGDR    migdr;
} NMEA;

//GPS 상태
typedef enum
{
	GPS_NONE = 0,               // 초기값
	GPS_PORT_UNAVAILABLE,       // port open 실패
	GPS_PORT_REOPEN,            // port reopen 중
	GPS_SIGNAL_NONE,            // 신호가 전혀 없음
	GPS_SIGNAL_IN_BAD,          // rmc의 valid값이 bad인 경우
	GPS_SIGNAL_IN_GOOD,         // rmc의 valid값이 good인 경우
} NeStatusGps;

typedef enum
{
	GPS_EXTRND_NONE			= 0,
	GPS_EXTRND_OBD			= 0x0001,	// OBD 사용 여부
} NeExtendGPSFlag;


//=============================================================
// 3. GPS 관련 정보에 필요한 struct define
//=============================================================

// 3.1	수신 위성 정보
typedef struct tagSVInfo
{
	Int32	nSVId;				//id
	Int32	nSVdb;				//전파간격
	Int32	nElevation;			//고도각
	Int32	nAzimuth;			//방향각
} SVINFO;


// 3.2	날짜.
typedef struct tagGpsDate
{
	Int32	y;	//년
	Int32	m;	//월
	Int32	d;	//일
} GPSDATE;


// 3.3 시간.
typedef struct tagGpsTime
{
	Int32	h;	//시
	Int32	m;	//분
	Int32	s;	//초
}GPSTIME;

// 3.4 경위도.
typedef struct tagCoordWpt
{
	Int32	d;	//도
	Int32	m;	//분
	Float	s;	//초
} COORDWPT;


// 3.5 GPS 데이터 정보
typedef struct tagGpsSatelliteInfo
{
	NeStatusGps		eGpsState;				//GPS 수신 상태
	Int32			nSVCnt;					//수신 위성 개수
	SVINFO			sSVInfo[MAX_SVINFO];	//수신 위성 정보
	GPSDATE			sDate;					//날짜
	GPSTIME			sTime;					//현재 시간
	DOUBLE_VERTEX		wp;						//현위치 좌표
	COORDWPT		wpCPX;					//현위치 X 좌표(도분초 구분)
	COORDWPT		wpCPY;					//현위치 Y 좌표
	Int32			nMode;					//측위모드
	Int32			nSpeed;					//속도
	Int32			nAngle;					//진행 방향
	double			nAltitude;				//고도
	double			dHdop;					//HDOP
} GPSSATELLITEINFO;

#if defined(_WIN32) && !defined(_WIN32_PHONE)
#define GPS_THREAD_TERMINATE_TIME 2000	// GPS 스레드 종료시 최대 대기 시간
#define GPS_LINE_MAX_SIZE			90
#define COMM_TIMEOUT_MIN 5000
#define COMM_TIMEOUT_MAX 20000
#endif
#define GPS_READ_SIZE				4096

// GPS 수신 타입
typedef enum
{
    eGpsTypeNone = 0,			// 미설정
    eGpsTypeFile,				// GPS 스레드를 생성하여 GPS 파일에서 직접 GPS 데이터(NMEA)를 읽는다.
    eGpsTypeWinWaitcomm,		// GPS 스레드를 생성하여 WaitCommEvent 함수를 이용하여 이벤트로 GPS 데이터(NMEA)를 수신한다. (시리얼 포트 사용)
    eGpsTypeWinPoling,			// GPS 스레드를 생성하여 GPS 포트에서 GPS 데이터(NMEA)를 Poling 한다. (시리얼 포트 사용)
    eGpsTypeInput,				// GPS 스레드를 생성하지 않고 외부에서 GPS 데이터(NMEA 또는 구조체)를 받는다.
}NeGpsType;

// 시리얼 포트 설정
typedef struct tagSerialPort
{
    Int32	nPort;
    Int32	nBaudrate;
    Bool	bEnableDTR;
}SERIAL_PORT, *PSERIAL_PORT;

// 아이폰 GPS 데이터
typedef struct tagIPhoneGpsData
{
    Bool			bGood;				// 퀄리티 상태(TRUE:좋음, FALSE:나쁨)
    struct NMEA_DateTimesDateTime;			// 수신 날짜, 시간
    Double			dLatitude;			// WGS84 Degree 단위 (예, 37.895231)
    Char			cLatitudeType;		// 북위 'N', 남위 'S'
    Double			dLongitude;			// WGS84 Degree 단위 (예, 126.794521)
    Char			cLongitudeType;		// 동경 'E', 서경 'W'
    Float			fSpeed;				// 이동속도 Km/h
    Float			fHeading;			// 이동방향 0~359
}IPHONE_GPSDATA, *PIPHONE_GPSDATA;

// GPS 수신 Callback 함수 포인터
typedef Bool (*LPCALL_RECEIVEGPS)(NMEA *nmea, NMEA_ID id);

#endif //__GPSDEF_H__
