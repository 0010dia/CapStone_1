#ifndef COORD_PROJ4TRANSFORM_H
#define COORD_PROJ4TRANSFORM_H

// This code is from PROJ4. https://github.com/OSGeo/PROJ/tree/4.9.2-maintenance
//
// Original copyright notice:
/******************************************************************************
 * Project:  PROJ.4
 * Purpose:  Perform overall coordinate system to coordinate system
 *           transformations (pj_transform() function) including reprojection
 *           and datum shifting.
 * Author:   Frank Warmerdam, warmerdam@pobox.com
 *
 ******************************************************************************
 * Copyright (c) 2000, Frank Warmerdam
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *****************************************************************************/
#include <array>
#include <cmath>

#define Dx_BF (context->datumParams[0])
#define Dy_BF (context->datumParams[1])
#define Dz_BF (context->datumParams[2])
#define Rx_BF (context->datumParams[3])
#define Ry_BF (context->datumParams[4])
#define Rz_BF (context->datumParams[5])
#define M_BF  (context->datumParams[6])

class Proj4Transform
{
private:
    static constexpr double kPI = 3.14159265358979323e0;
    static constexpr double kPI_over_2 = (kPI / 2.0e0);

    static constexpr double kRadianToDegree = 57.29577951308232;
    static constexpr double kDegreeToRadian = .0174532925199432958;

    /* SEC_TO_RAD = Pi/180/3600 */
    static constexpr double kSecondToRadian = 4.84813681109535993589914102357e-6;

    enum {
        Datum3Param = 3,
        Datum7Param = 7
    };

    struct ProjContext {
        static ProjContext* create(double a, double es, const std::array<double, 7>& datumParams) {
            double b;

            if (es == 0.0) {
                b = a;
            } else {
                b = a * sqrt(1 - es);
            }

            if (a <= 0.0) {
                return nullptr;
            }
            if (b <= 0.0) {
                return nullptr;
            }
            if (a < b) {
                return nullptr;
            }

            auto context = new ProjContext;

            context->a = a;
            context->es = es;
            context->b = b;
            context->a2 = a * a;
            context->b2 = b * b;
            context->e2 = (context->a2 - context->b2) / context->a2;
            context->ep2 = (context->a2 - context->b2) / context->b2;

            context->datumParams = datumParams;

            if (context->datumParams[3] != 0.0 ||
                    context->datumParams[4] != 0.0 ||
                    context->datumParams[5] != 0.0 ||
                    context->datumParams[6] != 0.0) {
                context->datumType = Datum7Param;

                /* transform from arc seconds to radians */
                context->datumParams[3] *= kSecondToRadian;
                context->datumParams[4] *= kSecondToRadian;
                context->datumParams[5] *= kSecondToRadian;
                /* transform from parts per million to scaling factor */
                context->datumParams[6] =
                        (context->datumParams[6]/1000000.0) + 1;
            } else {
                context->datumType = Datum3Param;
            }

            return context;
        }

        double a;
        double es;
        double b;
        double a2;
        double b2;
        double e2;
        double ep2;

        int datumType;
        std::array<double, 7> datumParams;
    };

public:
    Proj4Transform() {
        // +proj=longlat +ellps=bessel +no_defs +towgs84=-115.80,474.99,674.11,1.16,-2.31,-1.63,6.43
        m_EPSG4162 = ProjContext::create(6377397.155,
                                         calculateEccentricitySquared(299.1528128),
                                         {-115.80, 474.99, 674.11, 1.16, -2.31, -1.63, 6.43});

        // wgs84
        m_EPSG4326 = ProjContext::create(6378137.0,
                                         calculateEccentricitySquared(298.257223563),
                                         {0, 0, 0, 0, 0, 0, 0});
    }

    ~Proj4Transform() {
        delete m_EPSG4162;
        delete m_EPSG4326;
    }

    bool wgs2bessel(double lon, double lat, double* lon_out, double* lat_out) {
        double x;
        double y;
        double z;

        if (!transform(m_EPSG4326, m_EPSG4162, lon * kDegreeToRadian, lat * kDegreeToRadian, 0,
                &x, &y, &z)) {
            return false;
        }

        *lon_out = x * kRadianToDegree;
        *lat_out = y * kRadianToDegree;

        return true;
    }

    bool bessel2wgs(double lon, double lat, double* lon_out, double* lat_out) {
        double x;
        double y;
        double z;

        if (!transform(m_EPSG4162, m_EPSG4326, lon * kDegreeToRadian, lat * kDegreeToRadian, 0,
                &x, &y, &z)) {
            return false;
        }

        *lon_out = x * kRadianToDegree;
        *lat_out = y * kRadianToDegree;

        return true;
    }

    static Proj4Transform& getInstance() {
        static Proj4Transform instance;

        return instance;
    }

private:
    ProjContext* m_EPSG4162;
    ProjContext* m_EPSG4326;

private:
    double calculateEccentricitySquared(double rf) {
        double es;

        es = 1. / rf;
        es = es * (2. - es);

        return es;
    }

    bool transform(const ProjContext *src,
                   const ProjContext *dst,
                   double x, double y, double z,
                   double* out_x, double* out_y, double* out_z) {

        double X;
        double Y;
        double Z;

        if (!geodeticToGeocentric(src, y, x, z, &X, &Y, &Z)) {
            return false;
        }

        geocentricToWgs84(src, &X, &Y, &Z);

        geocentricFromWgs84(dst, &X, &Y, &Z);

        return geocentricToGeodetic(dst, X, Y, Z, out_y, out_x, out_z);
    }

    bool geodeticToGeocentric(const ProjContext *context,
                              double Latitude,
                              double Longitude,
                              double Height,
                              double *X,
                              double *Y,
                              double *Z) {

        double Rn;            /*  Earth radius at location  */
        double Sin_Lat;       /*  sin(Latitude)  */
        double Sin2_Lat;      /*  Square of sin(Latitude)  */
        double Cos_Lat;       /*  cos(Latitude)  */

        /*
        ** Don't blow up if Latitude is just a little out of the value
        ** range as it may just be a rounding issue.  Also removed longitude
        ** test, it should be wrapped by cos() and sin().  NFW for PROJ.4, Sep/2001.
        */
        if( Latitude < -kPI_over_2 && Latitude > -1.001 * kPI_over_2 )
            Latitude = -kPI_over_2;
        else if( Latitude > kPI_over_2 && Latitude < 1.001 * kPI_over_2 )
            Latitude = kPI_over_2;
        else if ((Latitude < -kPI_over_2) || (Latitude > kPI_over_2))
        { /* Latitude out of range */
            return false;
        }

        if (Longitude > kPI)
            Longitude -= (2*kPI);
        Sin_Lat = sin(Latitude);
        Cos_Lat = cos(Latitude);
        Sin2_Lat = Sin_Lat * Sin_Lat;
        Rn = context->a / (sqrt(1.0e0 - context->e2 * Sin2_Lat));
        *X = (Rn + Height) * Cos_Lat * cos(Longitude);
        *Y = (Rn + Height) * Cos_Lat * sin(Longitude);
        *Z = ((Rn * (1 - context->e2)) + Height) * Sin_Lat;

        return true;
    }

    bool geocentricToGeodetic(const ProjContext *context,
                              double X,
                              double Y,
                              double Z,
                              double *Latitude,
                              double *Longitude,
                              double *Height) {

        constexpr double genau = 1.E-12;
        constexpr double genau2 = genau*genau;
        constexpr int maxiter = 30;

        double P;        /* distance between semi-minor axis and location */
        double RR;       /* distance between center and location */
        double CT;       /* sin of geocentric latitude */
        double ST;       /* cos of geocentric latitude */
        double RX;
        double RK;
        double RN;       /* Earth radius at location */
        double CPHI0;    /* cos of start or old geodetic latitude in iterations */
        double SPHI0;    /* sin of start or old geodetic latitude in iterations */
        double CPHI;     /* cos of searched geodetic latitude */
        double SPHI;     /* sin of searched geodetic latitude */
        double SDPHI;    /* end-criterium: addition-theorem of sin(Latitude(iter)-Latitude(iter-1)) */
        int iter;        /* # of continous iteration, max. 30 is always enough (s.a.) */

        P = sqrt(X*X+Y*Y);
        RR = sqrt(X*X+Y*Y+Z*Z);

/*	special cases for latitude and longitude */
        if (P/context->a < genau) {

/*  special case, if P=0. (X=0., Y=0.) */
            *Longitude = 0.;

/*  if (X,Y,Z)=(0.,0.,0.) then Height becomes semi-minor axis
 *  of ellipsoid (=center of mass), Latitude becomes PI/2 */
            if (RR/context->a < genau) {
                *Latitude = kPI_over_2;
                *Height   = -context->b;
                return true;

            }
        }
        else {
/*  ellipsoidal (geodetic) longitude
 *  interval: -PI < Longitude <= +PI */
            *Longitude=atan2(Y,X);
        }

/* --------------------------------------------------------------
 * Following iterative algorithm was developped by
 * "Institut für Erdmessung", University of Hannover, July 1988.
 * Internet: www.ife.uni-hannover.de
 * Iterative computation of CPHI,SPHI and Height.
 * Iteration of CPHI and SPHI to 10**-12 radian resp.
 * 2*10**-7 arcsec.
 * --------------------------------------------------------------
 */
        CT = Z/RR;
        ST = P/RR;
        RX = 1.0/sqrt(1.0-context->e2*(2.0-context->e2)*ST*ST);
        CPHI0 = ST*(1.0-context->e2)*RX;
        SPHI0 = CT*RX;
        iter = 0;

/* loop to find sin(Latitude) resp. Latitude
 * until |sin(Latitude(iter)-Latitude(iter-1))| < genau */
        do
        {
            iter++;
            RN = context->a/sqrt(1.0-context->e2*SPHI0*SPHI0);

/*  ellipsoidal (geodetic) height */
            *Height = P*CPHI0+Z*SPHI0-RN*(1.0-context->e2*SPHI0*SPHI0);

            RK = context->e2*RN/(RN+*Height);
            RX = 1.0/sqrt(1.0-RK*(2.0-RK)*ST*ST);
            CPHI = ST*(1.0-RK)*RX;
            SPHI = CT*RX;
            SDPHI = SPHI*CPHI0-CPHI*SPHI0;
            CPHI0 = CPHI;
            SPHI0 = SPHI;
        }
        while (SDPHI*SDPHI > genau2 && iter < maxiter);

/*	ellipsoidal (geodetic) latitude */
        *Latitude=atan(SPHI/fabs(CPHI));

        return true;
    }

    void geocentricToWgs84(const ProjContext *context,
                           double* x, double* y, double* z) {
        if (context->datumType == Datum3Param) {
            if (*x == HUGE_VAL) {
                return;
            }

            *x = *x + Dx_BF;
            *y = *y + Dy_BF;
            *z = *z + Dz_BF;
        } else if (context->datumType == Datum7Param) {
            double x_out, y_out, z_out;

            if (*x == HUGE_VAL) {
                return;
            }

            x_out = M_BF*(       (*x) - Rz_BF*(*y) + Ry_BF*(*z)) + Dx_BF;
            y_out = M_BF*( Rz_BF*(*x) +       (*y) - Rx_BF*(*z)) + Dy_BF;
            z_out = M_BF*(-Ry_BF*(*x) + Rx_BF*(*y) +       (*z)) + Dz_BF;

            *x = x_out;
            *y = y_out;
            *z = z_out;
        }
    }

    void geocentricFromWgs84(const ProjContext *context,
                             double* x, double* y, double* z) {
        if (context->datumType == Datum3Param) {
            if (*x == HUGE_VAL) {
                return;
            }

            *x = *x - Dx_BF;
            *y = *y - Dy_BF;
            *z = *z - Dz_BF;
        } else if (context->datumType == Datum7Param) {
            double x_tmp, y_tmp, z_tmp;

            if (*x == HUGE_VAL) {
                return;
            }

            x_tmp = ((*x) - Dx_BF) / M_BF;
            y_tmp = ((*y) - Dy_BF) / M_BF;
            z_tmp = ((*z) - Dz_BF) / M_BF;

            *x =        x_tmp + Rz_BF*y_tmp - Ry_BF*z_tmp;
            *y = -Rz_BF*x_tmp +       y_tmp + Rx_BF*z_tmp;
            *z =  Ry_BF*x_tmp - Rx_BF*y_tmp +       z_tmp;
        }
    }
};

#endif
