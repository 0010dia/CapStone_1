#ifndef __SGL_GPSPARSER_H__
#define __SGL_GPSPARSER_H__

#include "sgl.h"

#define SUNRISE_ANGLE (M_PI * 90.833 / 180.0) /* sun angle at sunrise/set */

#define DAYSEC 86400 // 段研 析舘是稽 域至 
//=======================================================================
// units
//=======================================================================

enum length_unit
{
	unit_metre,
	unit_km,
	unit_mile,
	unit_foot,
	unit_knot,
};

const int c_nUnits(5);

//-----------------------------------------------------------------------
//quality of solution
//-----------------------------------------------------------------------

enum fix_quality
{
	fix_no_hardware=0, //fix0
	fix_no_fix,			//fix1
	fix_gps_2D,			//fix2
	fix_gps_3D,			//fix3		
	fix_dgps			//fix4
};

/**
The count of satellites. Only 0-31 are GPS; above that is WAAS
*/
const int satellite_count(64);

const DWord satellite_no_direction(1);
const DWord satellite_no_signal(2);


//-----------------------------------------------------------------------
//table mapping units to metres
//-----------------------------------------------------------------------

static float g_unitTable[c_nUnits]=
{
	1.0f, 		//m
	1000.0f,		//km
	1609.344f,	//mile
	0.3048f,		//feet
	1.852f,		//knot
};

struct S_db_yymmdd
{
	Int32 yy;
	Int32 mm;
	Int32 dd;
};

// RMC 唖亀 Fix聖 是廃 汽戚斗
typedef struct tagRmcFixData
{
	Float fAngle;
	Float fDist;
	Float fSpeed;
}RMCFIX_DATA, *PRMCFIX_DATA;

#include <deque>
typedef std::deque< RMCFIX_DATA > RmcFixQueue;

/** START - Added by ramoo in MNS (2015.2.26)
** Comment : sunset, sunrise remake
**/

const double g_degree		= 57.295779513082323;
const double g_radius		= 0.017453277777777776;
const double g_sundeg		= 0.53;							// 태양반지름 각도
const double g_airrefdeg	= 0.56666666666666666667;		// 대기 굴절

const Int32	g_cgbd_w		= -7;
const Int32 g_cgbd_y		= 12;
const double g_cgbd_h		= 24.0;
const double g_cgbd			= 730531.5;

class CSglSunRiseCalc
{
public:
	CSglSunRiseCalc(){};
	virtual~CSglSunRiseCalc(){};

private:
	double m_avr_latofsun;
	double m_avr_anmlofsun;

protected:
	double CalcGetBetweenDay(Int32 year, Int32 month, Int32 day, float hour);
	double CalcGetAngle_02_Normalize(double src);
	double CalcGet_HourAngle(double latitude, double delta);
	double CalcGet_Twilight_HourAngle(double latitude, double delta);
	double CalcGet_ELofSun (double elsun);
	Int32 CalcGet_TimeValue(double decimal_hour);

public:
	void Calc_SunsetSunrise(NMEA_sun& sun, Int32 year, Int32 month, Int32 day, double longitude, double latitude);
};

/**
** END - Added by ramoo in MNS (2015.2.26)
**/

//=======================================================================
/**
@class NMEA sentence support
*/
//=======================================================================
class CSglGpsFilter;

class CSglGpsParser
{
public:
	virtual ~CSglGpsParser();
	//=======================================================================
	//=======================================================================

	CSglGpsParser();

public:
        NMEA_ID				Parsing(const char* sentence);
	NMEA*				GetNmeaData() { return &m_Nmea; }
	void				SetCoordUnit(coord_unit CoordUnit) { m_CoordUnit = CoordUnit; }
	void				SetTimeZone(Int nTimeZone) { m_TimeZone = nTimeZone; }
	Bool				SetPredTime(float fPredtime);

private:
	CSglGpsFilter*			m_pFilter;
	NMEA				m_Nmea;
	NMEA_ID				m_LastSentenceID;
	Bool				m_bSentenceID[NMEA_MAX];
	char				m_szFields[32][64];
	Int					m_nLastMin;
	Bool				m_IsNotCalcSunsetSunrise;
	Int					m_TimeZone;
	NMEA_DateTime		m_LastTime;
	Int					m_nNmeaCnt;

	Bool				m_bValidRMC;
	Int32				m_nReciveTickCount;		// 汽戚斗 閤精 獣娃

	UInt32				m_uRmcTick;		// GPS RMC 飴重 獣娃
	UInt32				m_uPosTick;		// GPS RMC 暁澗 OBD 飴重 獣娃


private:

	//析窒 析侯獣娃 域至

	/**
	@brief utc sunrise/set time for a gregorian date

	@parm day this day of month
	@parm month this month
	@parm year this year
	@parm longitude longitude to use in calculations
	@parm latitude latitude to use in calculations
	@parm sunrise return the utc sunrise in minutes
	@parm sunset return the utc sunset in minutes
	*/
	int CalcSunsetSunrise(Int y, Int m, Int day, double longit, double latit);

	// RMC 督縮戚板 坦軒(爽/醤娃 竺舛, 琶斗)
	void CompleteRmc();

	/************************************************************************
	** MSPOS - M&Service Position
	**
	**        1       2 3        4 5 6              7   8   9 10 11
	**        |       | |        | | |              |   |   | |  |
	** $MSPOS,llll.ll,a,yyyyy.yy,a,a,yyyymmddhhmmss,x.x,x.x,a,a*hh<CR><LF>
	**
	** Field Number:
	**  1) Latitude
	**  2) N or S (North or South)
	**  3) Longitude
	**  4) E or W (East or West)
	**  5) Time Type 1 or 2 ( 1:UTC[United Technologies Corporation], 2:KST[Korea Standard Time] )
	**  6) Time
	**  7) Speed over ground, knots
	**  8) Magnetic Variation, degrees
	**  9) Altitude
	** 10) Accuracy (meter)
	** 11) Checksum
	*/
	Bool				SetMSPOS();


	/************************************************************************
	** GLL - Geographic Position - Latitude/Longitude
	** Latitude, N/S, Longitude, E/W, UTC, Status
	**
	**        1       2 3        4 5         6 7
	**        |       | |        | |         | |
	** $--GLL,llll.ll,a,yyyyy.yy,a,hhmmss.ss,A*hh<CR><LF>
	**
	** Field Number: 
	**  1) Latitude
	**  2) N or S (North or South)
	**  3) Longitude
	**  4) E or W (East or West)
	**  5) Universal Time Coordinated (UTC)
	**  6) Status A - Data Valid, V - Data Invalid
	**  7) Checksum
	*/
	Bool				SetGLL();

	/************************************************************************
	** RMC - Recommended Minimum Navigation Information
	**                                                            12
	**        1         2 3       4 5        6 7   8   9    10  11|
	**        |         | |       | |        | |   |   |    |   | |
	** $--RMC,hhmmss.ss,A,llll.ll,a,yyyyy.yy,a,x.x,x.x,xxxx,x.x,a*hh<CR><LF>
	**
	** Field Number: 
	**  1) UTC Time
	**  2) Status, V = Navigation receiver warning
	**  3) Latitude
	**  4) N or S
	**  5) Longitude
	**  6) E or W
	**  7) Speed over ground, knots
	**  8) Track made good, degrees true
	**  9) Date, ddmmyy
	** 10) Magnetic Variation, degrees
	** 11) E or W
	** 12) Checksum
	*/
	Bool				SetRMC(stNMEA_MSPOS *pMsPos=NULL);

	/************************************************************************
	** GSA - GPS DOP and Active Satellites
	**
	**        1 2 3  4  5  6  7  8  9  10 11 12 13 14 15  16  17  18
	**        | | |  |  |  |  |  |  |  |  |  |  |  |  |   |   |   |
	** $--GSA,a,x,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx,xx,x.x,x.x,x.x*hh<CR><LF>
	**
	** Field Number: 
	**  1) Operating Mode, A = Automatic, M = Manual
	**  2) Fix Mode, 1 = Fix not available, 2 = 2D, 3 = 3D
	**  3) Satellite PRN #1
	**  4) Satellite PRN #2
	**  5) Satellite PRN #3
	**  6) Satellite PRN #4
	**  7) Satellite PRN #5
	**  8) Satellite PRN #6
	**  9) Satellite PRN #7
	** 10) Satellite PRN #8
	** 11) Satellite PRN #9
	** 12) Satellite PRN #10
	** 13) Satellite PRN #11
	** 14) Satellite PRN #12
	** 15) PDOP
	** 16) HDOP
	** 17) VDOP
	** 18) Checksum
	*/
	Bool				SetGSA();

	/************************************************************************
	** GGA - Global Positioning System Fix Data
	** Time, Position and fix related data fora GPS receiver.
	**
	**                                                      11
	**        1         2       3 4        5 6 7  8   9  10 |  12 13  14   15
	**        |         |       | |        | | |  |   |   | |   | |   |    |
	** $--GGA,hhmmss.ss,llll.ll,a,yyyyy.yy,a,x,xx,x.x,x.x,M,x.x,M,x.x,xxxx*hh<CR><LF>
	**
	** Field Number: 
	**  1) Universal Time Coordinated (UTC)
	**  2) Latitude
	**  3) N or S (North or South)
	**  4) Longitude
	**  5) E or W (East or West)
	**  6) GPS Quality Indicator,
	**     0 - fix not available,
	**     1 - GPS fix,
	**     2 - Differential GPS fix
	**  7) Number of satellites in view, 00 - 12
	**  8) Horizontal Dilution of precision
	**  9) Antenna Altitude above/below mean-sea-level (geoid) 
	** 10) Units of antenna altitude, meters
	** 11) Geoidal separation, the difference between the WGS-84 earth
	**     ellipsoid and mean-sea-level (geoid), "-" means mean-sea-level
	**     below ellipsoid
	** 12) Units of geoidal separation, meters
	** 13) Age of differential GPS data, time in seconds since last SC104
	**     type 1 or 9 update, null field when DGPS is not used
	** 14) Differential reference station ID, 0000-1023
	** 15) Checksum
	*/
	Bool				SetGGA();

	/************************************************************************
	** GSV - TRANSIT Position - Latitude/Longitude
	** Location and time of TRANSIT fix at waypoint
	**
	**        1 2 3  4  5  6   7  8  9  10  11 12 13 14  15 16 17 18  19  20
	**        | | |  |  |  |   |  |  |  |   |  |  |  |   |  |  |  |   |   |
	** $--GSV,x,x,xx,xx,xx,xxx,xx,xx,xx,xxx,xx,xx,xx,xxx,xx,xx,xx,xxx,xx,*hh<CR><LF>
	**
	**  1) Total number of messages, 1-3
	**  2) Message Number, 1-3
	**  3) Total number of satellites in view
	**  4) Satellite Number #1
	**  5) Elevation #1
	**  6) Azimuth, Degrees True #1
	**  7) SNR #1, NULL when not tracking
	**  8) Satellite Number #2
	**  9) Elevation #2
	** 10) Azimuth, Degrees True #2
	** 11) SNR #2, NULL when not tracking
	** 12) Satellite Number #3
	** 13) Elevation #3
	** 14) Azimuth, Degrees True #3
	** 15) SNR #3, NULL when not tracking
	** 16) Satellite Number #4
	** 17) Elevation #4
	** 18) Azimuth, Degrees True #4
	** 19) SNR #4, NULL when not tracking
	** 20) Checksum
	*/  
	Bool				SetGSV();

	/*
	** VTG - Track made good and Ground speed
	**
	**        1   2 3   4 5	 6 7   8 9
	**        |   | |   | |	 | |   | |
	** $--VTG,x.x,T,x.x,M,x.x,N,x.x,K*hh<CR><LF>
	**
	** Field Number: 
	**  1) Track Degrees
	**  2) T = True
	**  3) Track Degrees
	**  4) M = Magnetic
	**  5) Speed Knots
	**  6) N = Knots
	**  7) Speed Kilometers Per Hour
	**  8) K = Kilometers Per Hour
	**  9) Checksum
	*/
	Bool				SetVTG();

	/*
	ex) $MIGDR,140047.000,06,1,3,37.5026988,N,127.01113420,E,37.5026489,N,127.01112128,E,123.08,004.06,133.48,005.13,04.1,01.6,0,0,100.23,-04.22,-294.06,02594,014*4B
	
	**  Name					Example			Unit		Description
	**  --------------------------------------------------------------------------------------------------------------
	**  Message ID				$MIGDR
	**  UTC time				140047.000					HrMinSec
	**  Number of satellite 
	**  Fix Quality				1							0 Solution Invalid, 1 Position Fix
	**  Mode 2					3							1 Solution Invalid, 2 GPS 2D Fix, 3 GPS 3D Fix
	**  GPS Latitude			37.5026988		dd.ddddd	WGS84(North = +, South = -)
	**  N/S Indicator			N							N=north or S=south
	**  GPS Longitude			127.01113420	ddd.ddddd	WGS84(East = +, West = -)
	**  E/W Indicator			E							E=east or W=west
	**  DR/GPS Latitude			37.5026489		dd.ddddd	WGS84(North = +, South = -)
	**  N/S Indicator			N							N=north or S=south
	**  DR/GPS Longitude		127.01112128	ddd.ddddd	WGS84(East = +, West = -)
	**  E/W Indicator			E							E=east or W=west
	**  GPS Course				123.08			degree
	**  GPS Speed				004.06			m/s
	**  DR/GPS Course			133.48			degree
	**  DR/GPS Speed			005.13			m/s
	**  PDOP					04.1						Position dilution of Precision
	**  HDOP					01.6						Horizontal Dilution of Precision
	**  Gyro Error Flag			0							0 : Normal -> DR/GPS Mode, 1 : Error -> GPS Mode
	**  Odometer Error Flag		0							Same to Gyro Error Flag
	**  DR Parameter 1			100.23
	**  Mean Gyro Output		-04.22			deg/sec
	**  DR Parameter 2			-294.06
	**  Odometer SF				02594			pulse/Km
	**  Odometer Pulse			014							Number of pulse in the second
	**  Check Sum				*4B
	**  <CR> <LF>											End of message termination
	*/
	Bool				SetMIGDR();


private:
	void				SetRmcInfo(NMEA_ID nID);
	void				SetAvgInfo();

	void				SaveLatLong(double lat, char NorS, double ltd, char EorW);
	void				SaveVector(float direction, float speed, length_unit unit);
	Bool				SaveTime(int hms, int dmy, int gmt);
	Bool				SaveTime(NMEA_DateTime *pDataTime);

	void				SaveGgaLatLong(double lat, char NorS, double ltd, char EorW);
    Bool                IsGpsVerryGood();

protected:
	Int16				m_nAvgMaxMinutes;

private:
	Bool				m_bAvg;
	Int16				m_nSec;
	Int16				m_nMinutes;
	Int16				m_nAvgMax;
	Int16				m_arAvgSec[60]; // 置悦 60段税 紗亀 汽戚斗
	Int16				m_arAvgMinutes[60]; // 1獣娃 紗亀 汽戚斗. 廃鯵澗 1歳税 汝液紗亀

private:
	coord_unit			m_CoordUnit;
	Bool				b_GpsInfoFlag;

	float				m_fPredtime;
    
protected:
        inline bool NMEA_SetFields(const char *sentence)
	{
		if (!checksum(sentence))
			return false;

		memset(m_szFields, 0x00, sizeof(char)*32*64);

		int i = 0, j = 0;
                char c; const char *p = sentence;

		while ((c = *p++) != '*') {
		
			if( c == NULL )
				return false;

			if (c == ',') {
				if(i >= 32)
					return false;
				j = 0;
				i++;
			} else {
				if(j >= 64)
					return false;
				m_szFields[i][j++] = c;
			}
		}

		return true;
	}

        inline bool checksum(const char *sentence)
	{
		UInt8 sum = '\0';
                char c; const char *p = sentence; char csum[3];

		while (*p != NULL && (c = *p++) != '*')
			sum ^= c;

		snprintf(csum, sizeof(csum), "%02X", sum);
		return (strncmp(csum, p, 2) == 0);
	}

	inline int AtoI(const char * str)
	{
		if(str == NULL) {
			return 0;
		}
		return atoi(str);
	}

	inline float AtoF(const char * str)
	{
		if(str == NULL) {
			return 0;
		}
		return (float)atof(str);
	}

	inline long STRtoL(const char * str)
	{
		char * pch;
		if(str == NULL) {
			return 0;
		}
		return strtol(str , &pch, 16);
	}

	inline char AtoA(const char * str)
	{
		if (str == NULL) {
			return 'X';
		}
		return *str;
	}
};

#endif // __SGL_GPSPARSER_H__
