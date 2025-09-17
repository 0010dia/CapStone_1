// sgl_time.h

#ifndef __SGL_TIME_H
#define __SGL_TIME_H


typedef struct {
	Int32 tm_sec;			/* 0 - 59 */
	Int32 tm_min;			/* 0 - 59 */
	Int32 tm_hour;		/* 0 - 23 */
	Int32 tm_mday;		/* 1 - 31 */
	Int32 tm_mon;			/* 0 - 11 */
	Int32 tm_year;		/* years since 1900 */
	Int32 tm_wday;		/* 0 - 6 sunday=0 */
	Int32 tm_yday;		/* 0 - 365 */
} _tm;

typedef struct SGL_SYSTEMTIME
{
    Word	wYear;
    Word	wMonth;
    Word	wDayOfWeek;
    Word	wDay;
    Word	wHour;
    Word	wMinute;
    Word	wSecond;
    Word	wMilliseconds;
} SGL_SYSTEMTIME, *PSGL_SYSTEMTIME;

void sglCalculateTime(unsigned long timep, _tm *tmp);
void sglCalculateTime2(unsigned long timep, _tm *tmp);
Int32 sglCalculateTimeWeek(unsigned long timep);

unsigned long sglRecalculateTime(Int32 year, Int32 month, Int32 day, Int32 hour, Int32 min, Int32 sec);
unsigned long sglRecalculateTimeUser(Int32 base_year, Int32 year, Int32 month, Int32 day, Int32 hour, Int32 min, Int32 sec);

void sglGetLocalTime(PSGL_SYSTEMTIME pSystemTime);
unsigned long sglGetLocalTimeLong();

typedef struct {
	long tv_sec;
	long tv_usec;
} SGL_TIMEVAL;

void sglGetTimeOfDay(SGL_TIMEVAL *tv);

#endif // __SGL_TIME_H
