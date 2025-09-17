//
//  CoordinateUtils.h
//  TMFactory
//
//  Created by younggi.lee on 1/14/16.
//  Copyright © 2016 sk planet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CLLocation+Utils.h"
#import "LocationData.h"
#import "sgl_cmntype_objc.h"
//#include "sgl_basedef.h"


// from define_inc.h
// NOFP 실수 연산 안하게 처리
#define __NOFP__
#define NOFP_DEG	10000.0f
#define T2IDEN		100000

#define WORLDCOORD_3DX 94371840 //WORLDCOORD_3DX
#define WORLDCOORD_3DY 47185920 //WORLDCOORD_3DY

#ifdef __GOOD_JEJU__
    #define	BASE_POS_X	66339840
    #define	BASE_POS_Y	17561733
#else
    #ifdef _ENNAVI_3D_MODE_
        #define	BASE_POS_X	66573602
        #define	BASE_POS_Y	19695617
    #else
        #define	BASE_POS_X	66571920
        #define	BASE_POS_Y	19691179
    #endif
#endif

#ifdef __GOOD_JEJU__
    #define KOREA_MIN_X		66001469
    #define KOREA_MIN_Y		17309670
    #define KOREA_MAX_X		66633459
    #define KOREA_MAX_Y		17829467
#else
    #define KOREA_MIN_X		65048762
    #define KOREA_MIN_Y		15300000
    #define KOREA_MAX_X		69206016
    #define KOREA_MAX_Y		21271814
#endif



@interface SGLDegMathUtils : NSObject

@end


/**
 * CoordinateUtils
 *
 * Discussion:
 *    CLLocation+Utils 에 정의된 함수들을 이용 및 기존 CoordBase 필요 함수들을 옮겨와서 수행하던 연산을 대체
 *
 * TODO:
 *    VERTEX32 타입을 CGPoint 타입으로 변환 요함 
 **/
@interface CoordinateUtils : NSObject

/**
 * degreeF
 * degNormalize
 *
 * Discussion:
 **/
+ (CLLocationDirection)degreeF:(float)fAngle;
+ (SInt32)degNormalize:(SInt32)angle;

/**
 * GetMeterPerWorldXForStartY
 * GetMeterPerWorldYForStartY
 *
 * Discussion:
 **/
+ (SInt32)GetMeterPerWorldXForStartY:(int)StartY endY:(int)EndY;
+ (SInt32)GetMeterPerWorldYForStartY:(int)StartY endY:(int)EndY;

/**
 * distanceFromData:to
 * distanceFromLocation:to
 * distanceFromVertex:to
 *
 * Discussion:
 *    from 위치부터 to 위치까지의 거리
 **/
+ (CLLocationDistance)distanceFromData:(LocationData *)fromData to:(LocationData *)toData;
+ (CLLocationDistance)distanceFromLocation:(CLLocation *)fromLocation to:(CLLocation *)toLocation;
+ (CLLocationDistance)distanceFromVertex:(DOUBLE_VERTEX)fromVertex to:(DOUBLE_VERTEX)toVertex;

/**
 * angleFromData:to
 * angleFromLocation:to
 * angleFromVertex:to
 *
 * Discussion:
 *    from 위치부터 to 위치로의 방향각
 **/
+ (CLLocationDirection)angleFromData:(LocationData *)fromData to:(LocationData *)toData;
+ (CLLocationDirection)angleFromLocation:(CLLocation *)fromLocation to:(CLLocation *)toLocation;
+ (CLLocationDirection)angleFromVertex:(DOUBLE_VERTEX)fromVertex to:(DOUBLE_VERTEX)toVertex;

/**
 * diffenceFromAngle:to
 *
 * Discussion:
 *    두 방향각의 차이
 **/
+ (CLLocationDirection)diffenceFromAngle:(CLLocationDirection)fromAngle to:(CLLocationDirection)toAngle;

/**
 * getRadiusMBRfromVertex:radius:outMinPoint:outMaxPoint
 * getRadiusMBRfromLocation:radius:outMinPoint:outMaxPoint
 *
 * Discussion:
 *    한 점으로부터 일정 반경(radius) 만큼 떨어진 구역(원)의 xy최소좌표, xy최대좌표
 **/
+ (void)getRadiusMBRfromVertex:(DOUBLE_VERTEX)centerPoint radius:(NSUInteger)radius outMinPoint:(DOUBLE_VERTEX *)outMinPoint outMaxPoint:(DOUBLE_VERTEX *)outMaxPoint;

/**
 * radianToDegree
 *
 * Discussion:
 * radian 각을 degree 각으로 변환
 **/
+ (double)radianToDegree:(double)radian;

/**
 * degreeToRadian
 *
 * Discussion:
 * degree 각을 radian 각으로 변환
 **/
+ (double)degreeToRadian:(double)degree;

/**
 * distanceFromData:toLineOfStart:lineOfEnd
 * distanceFromLocation:toLineOfStart:lineOfEnd
 * distanceFromVertex:toLineOfStart:lineOfEnd
 *
 * Discussion:
 *    한 점으로부터 선분(시작점부터 끝점을 잇는 선분) 까지의 거리
 **/
+ (CLLocationDistance)distanceFromVertex:(DOUBLE_VERTEX *)from toLineOfStart:(DOUBLE_VERTEX *)lineStart lineOfEnd:(DOUBLE_VERTEX *)lineEnd outPerpendicular:(DOUBLE_VERTEX *)perpendicular result:(CGFloat *)result;
+ (CLLocationDistance)distanceFromVertex3D:(VERTEXZ_F *)from toLineOfStart:(VERTEXZ_F *)lineStart lineOfEnd:(VERTEXZ_F *)lineEnd outPerpendicular:(VERTEXZ_F *)perpendicular result:(CGFloat *)result;

/**
 * IsKoreaArea
 *
 * Discussion:
 **/
+ (BOOL)IsKoreaArea:(DOUBLE_VERTEX *)wpt;
+ (BOOL)IsKoreaArea:(double )x y:(double )y;


/**
 *
 * Discussion:
 * MapMatching 용 interpolation angle
 **/
+ (NSArray *)anglesBetweenAngle0:(double)angle0 angle1:(double)angle1 count:(NSInteger)count;
+ (float)angleDiffWithAngle0:(double)angle0 angle1:(double)angle1;



@end
