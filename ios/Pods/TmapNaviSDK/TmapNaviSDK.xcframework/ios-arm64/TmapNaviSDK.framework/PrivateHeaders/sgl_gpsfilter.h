#ifndef __SGL_GPSFILTER_H__
#define __SGL_GPSFILTER_H__

#include "sgl.h"

class CSglGpsFilter
{
public:
	CSglGpsFilter(void);
	~CSglGpsFilter(void);

public:
	Bool				Filtering(NMEA* pNmea, Int nNmeaCnt, UInt16 uCurrentGpsSpeed, UInt16 uAngle, Float fHdop);
	//특정 단말의 경우 터널 진입시 GPS Good 상태 이므로 필터 한다. (GGA 값이 있을때만 체크 한다.)
	void				FilterSignal(NMEA* pNmea);
	void				SetPredTime(Float fPredtime)		{	m_pred_time = fPredtime;	}
private:
	Bool				Update(NMEA_update_mode mode);
	void				UpdateHdop();
	void				UpdateAngle();
	void				UpdateSpeed();
	void				UpdateSpeed(Int32 speed);
	void				UpdatePosition();
public:
	void				UpdatePosition(const int speed, const int angle, const DOUBLE_VERTEX* wpIn, DOUBLE_VERTEX* wpOut);


private:
	inline short AngleDiff(short a, short b)
	{
		short diff;

		diff = a - b;

		if ( diff >= 180 )
			diff -= 360;
		else if( diff < -180 )
			diff += 360;  

		return diff;  
	}

	inline void AddBeforeAngle(UInt16 Heading)
	{
		int i;

		for(i = 0; i <= (MAX_BEFORE_HEADING_CNT - 1); i++)
		{
			m_uBeforeHeadingList[i + 1] = m_uBeforeHeadingList[i];
		}
		m_uBeforeHeadingList[0] = Heading;
	}

	inline void AddBeforeSpeed(UInt16 Speed)
	{
		int i;

		for(i = 0; i <= (MAX_BEFORE_SPEED_CNT - 1); i++)
		{
			m_cBeforeSpeedList[i + 1] = m_cBeforeSpeedList[i];
		}
		m_cBeforeSpeedList[0] = Speed;
	}

	inline short DiffAngleValue(int n)		
	{	
		return (AngleDiff(m_uBeforeHeadingList[n], m_uBeforeHeadingList[n+1]));	
	}

	inline short DiffAnglePrevValue(int n)	
	{	
		return (AngleDiff(m_uBeforeHeadingList[n], m_uBeforeUsedAngle));	
	}

	inline void SaveAngle(UInt16 angle)		{	m_uBeforeUsedAngle = angle;	}
	inline short DiffSpeedValue(int n)		{	return (m_cBeforeSpeedList[n] - m_cBeforeSpeedList[n+1]);	}
	inline short DiffSpeedPrevValue(int n)	{	return (m_cBeforeSpeedList[n] - m_cBeforeUsedSpeed );	}
	inline void SaveSpeed(UInt8 Speed)		{	m_cBeforeUsedSpeed = Speed;	}


	

private:
	NMEA*				m_pNmea;

	Bool				m_bInitPosition;
	Bool				m_bVaildHeading;

	int					m_nBad_HdopCount;
	int					m_nJump_SpeedCount;		// 급과속, 급감속
	int					m_nSpeed_LowCount;		// 서행

	int					m_nNmeaCnt;
	int					m_nAngle_ChangeCount;
	int					m_nAngle_Status;
	
	UInt16				m_uBeforeUsedAngle;
	UInt16				m_uBeforeHeadingList[MAX_BEFORE_HEADING_CNT + 1];

	UInt16				m_cBeforeUsedSpeed;
	UInt16				m_cBeforeSpeedList[MAX_BEFORE_SPEED_CNT + 1];
	int					m_nSpeed_StopCount;
	Float				m_pred_time;	// 초 단위

	int					m_nAngle_LowChangeCount; 
	int					m_nAngle_LowCount; 

};

#endif // __SGL_GPSFILTER_H__

