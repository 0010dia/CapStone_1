#ifndef _COORD_H_
#define _COORD_H_

#include <math.h>
#ifdef __IPHONEOS__
	#include "../../include/sgl_inc.h"    //hjkim
#else
	#include "../../include/sgl_inc.h"
#endif

#ifndef PI
#define PI ((double)3.14159265358979323846)
#endif
#ifndef M_PI
#define M_PI ((double)3.14159265358979323846)
#endif


/*
 * TM(���ֵ��� ��� FALSE_NORTH = 550000)
 */
#define	FALSE_EAST	(200000)
#define FALSE_NORTH	(500000)

#define	KATEC_EAST	(400000)
#define	KATEC_NORTH	(600000)


/*
 * BESSEL
 */
#define BESSEL_A	6377397.155
#define BESSEL_RF	299.1528128
#define BESSEL_B	(BESSEL_A - BESSEL_A / BESSEL_RF)
#define BESSEL_EE	(0.006674372231315)	// (a*a - b*b)/(a*a)

#define BA	(1.005037306048555)
#define BB	(0.005047849240300)
#define BC	(0.000010563786831)
#define BD	(0.000000020633322)


/*
 * W2B
 */
#define W2B_DELTAX	128
#define W2B_DELTAY	-481
#define W2B_DELTAZ	-664
#define W2B_DELTAA	-739.845
#define W2B_DELTAF	-0.000010037483

/*
 * WGS84
 */
#define WGS84_A		6378137.0
#define WGS84_F		(1.0 / 298.257223563)
#define WGS84_RF	298.257223563
#define WGS84_B		(WGS84_A - WGS84_A / WGS84_RF)
#define WGS84_EE	(2.0 * WGS84_F - WGS84_F * WGS84_F)

#define WA		(1.00503730604896035494)
#define WB		(0.00504784924129776918)
#define WC		(0.00001056378689647333)
#define WD		(0.00000002063334976042)

/*
 * B2W
 */
#define B2W_DELTAX	-147
#define B2W_DELTAY	506
#define B2W_DELTAZ	687


#define SCALEFACTOR_TM	1.0
#define SCALEFACTOR_UTM	0.9996

//#define PI		M_PI/*((double)3.14159265358979323846)*/

/*
#define BESSEL_a 	(6377397.155)
#define BESSEL_ee	(0.006674372231315)	// (a*a - b*b)/(a*a)

#define BESSEL_A	(1.005037306048555)
#define BESSEL_B	(0.005047849240300)
#define BESSEL_C	(0.000010563786831)
#define BESSEL_D	(0.000000020633322)
*/

#define WGS_A	(1.00503730604896035494)
#define WGS_B	(0.00504784924129776918)
#define WGS_C	(0.00001056378689647333)
#define WGS_D	(0.00000002063334976042)


#define WGS_a	6378137.		/* WGS84 semimajor(/meter) */
#define WGS_f	(1. / 299.1528128)	/* WGS84 flattening (new) */

#define WGS_b	6356752.3142
#define WGS_ee	(2. * WGS_f - WGS_f * WGS_f)	/* WGS84 square of */
                                                /* first eccentrictiy */

/*
 * MISC
 */

void detorgbl(double *pbx, double *orglongitude);
void deg2rad(double *ptx, double *pty);
void rad2deg(double *ptx, double *pty);
double Bfnxco(double lat);
double Wfnxco(double lat);

/*
 * -- UTM
 *  51 Zone: 120 - 126 --> orglongitude = 123.0;
 *  52 Zone: 126 - 132 --> orglongitude = 129.0;	[default in COREA]
 *
 * -- TM
 *  124 <= bx < 126:     orglon = 125.0 + 10.405"(��) = 125.00289; (���ο���)
 *  126 <= bx < 128:     orglon = 127.0 + 10.405"(��) = 127.00289; (�ߺο���)
 *  128 <= bx < 130:     orglon = 129.0 + 10.405"(��) = 129.00289; (���ο���)
 *
 *	orglat = 38.0;
 *
 */


/*
 * COORD CONVERSION
 */
/*
void bessel2tm(double bx, double by, double *ptx, double *pty,
	       double orglongitude, double orglatitude);
void tm2bessel(double tx, double ty, double *pbx, double *pby,
	       double orglongitude);
void bessel2utm(double bx, double by, double *pux, double *puy,
	        double orglongitude);
void utm2bessel(double ux, double uy, double *pbx, double *pby,
	        double orglongitude);
void wgs2tmII(double lon, double lat, double Orlon, double Orlat,
	      double *ptx, double *pty);
*/
#ifdef __cplusplus
extern "C" {
#endif
void bessel2wgs(double bx, double by, double *pwx, double *pwy);
void wgs2sk(double wx, double wy, double *pbx, double *pby);
void wgs2world(double wx, double wy, double *pbx, double *pby);
void wgs2bessel(double wx, double wy, double *pbx, double *pby);
void wgs2tm(double lon, double lat, double Orlong, double Orlat, 
		   double *ptx, double *pty);
void sk2bessel(unsigned short uTileX, unsigned short uTileY, unsigned short uX, unsigned short uY, double *pbx, double *pby);
void tile2sk(unsigned short tile_x, unsigned short tile_y, unsigned short x, unsigned short y, double *pbx, double *pby);
void sk2world(double x, double y, double *pbx, double *pby);

void wgs84_to_epgs3857(double x, double y, double *px, double *py);
void epgs3857_to_wgs84(double x, double y, double *px, double *py);
void sk2wgs(unsigned short tile_x, unsigned short tile_y, unsigned short x, unsigned short y, double *pbx, double *pby);
void sk2wgs2(double x, double y, double *pbx, double *pby);

void world2wgs(double wx, double wy, double *pbx, double *pby);
void worldTile2wgs(int tileX, int tileY, double x, double y, double *wgsX, double *wgsY);

#ifdef __cplusplus
}
#endif

// long tmforint(double r_maj, double r_min, double scale_fact,
//               double center_lon, double center_lat, 
//               double false_east, double false_north);
// long tmfor(double lon, double lat, double *px, double *py);
// 
// long tminvint(double r_maj, double r_min, double scale_fact, 
//               double center_lon, double center_lat, 
//               double false_east, double false_north);
// long tminv(double x, double y, double *lon, double *lat);
// 
// long utmforint(double r_maj, double r_min, double scale_fact, long zone);
// long utmfor(double lon, double lat, double *x, double *y);
// long utminvint(double r_maj, double r_min, double scale_fact, long zone);
// long utminv(double x, double y, double *lon, double *lat);

double fnxco(double lat);

// void degree2tmInBessel(double rX, double rY, double bX, double bY, double *tX, double *tY);
// void tm2degreeInBessel(double rX, double rY, double tX, double tY, double *bX, double *bY);
// void degree2utmInBessel(Int32 zone, double bX, double bY, double *uX, double *uY);
// void utm2degreeInBessel(Int32 zone, double uX, double uY, double *bX, double *bY);

double DmsToDegree(int d,int m,int s,int cs);
double DmsToDegree(unsigned int dms);
void DegreeToDms(double degree,int* pd,int* pm,int* ps,int* pcs);
unsigned int DegreeToDms(double degree);

#endif /* _COORD_H_ */
