//
//  TmapCoord.h
//  Tmap4
//
//  Created by LeeSoonWoo on 2014. 10. 28..
//

#import <Foundation/Foundation.h>

/**
 *  T map 에서 사용하는 좌표계 변환 클래스
 *
 */
@interface _TmapCoord : NSObject

/**
 *  SK 좌표를 WGS84(GPS) 좌표로 변환
 */
+ (BOOL)skToWgs84:(int *)skCoord wgsCoord:(double *)wgsCoord;
+ (BOOL)skToWgs84:(int)skX andY:(int)skY latitude:(double *)lat longitude:(double *)lon;

/**
 *  WGS84(GPS) 좌표를 SK 좌표로 변환
 */
+ (BOOL)wgs84ToSK:(double *)wgsCoord skCoord:(int *)skCoord;
+ (BOOL)wgs84ToSK:(double)longitude andLatitude:(double)latitude skCoordX:(int *)skX skCoordY:(int *)skY;

/**
 *  월드좌표를 WGS84(GPS) 좌표로 변환
 */
+ (BOOL)worldToWgs84:(double *)worldCoord wgsCoord:(double *)wgsCoord;
+ (BOOL)worldToWgs84:(double)worldX andWorldY:(double)worldY longitude:(double *)lon latitude:(double *)lat;

/**
 *  WGS84(GPS) 좌표를 월드좌표로 변환
 */
+ (BOOL)wgs84ToWorld:(double *)wgsCoord worldCoord:(double *)worldCoord;
+ (BOOL)wgs84ToWorld:(double)longitude andLatitude:(double)latitude worldCoordX:(double *)worldX worldYCoordY:(double *)worldY;

/**
 *  월드좌표를 SK 좌표로 변환
 */
+ (BOOL)worldToSK:(double *)worldCoord skCoord:(int *)skCoord;
+ (BOOL)worldToSK:(double)worldX andWorldY:(double)worldY skCoordX:(int *)skX skCoordY:(int *)skY;
+ (BOOL)worldToSK8Digits:(double *)worldCoord skCoord:(UInt32 *)skCoord;
+ (BOOL)worldToSK8Digits:(double)worldX andWorldY:(double)worldY skCoordX:(UInt32 *)skX skCoordY:(UInt32 *)skY;

/**
 *  SK 좌표를 월드좌표로 변환
 */
+ (BOOL)skToWorld:(int *)skCoord worldCoord:(double *)worldCoord;
+ (BOOL)skToWorld:(int)skX andSKY:(int)skY worldCoordX:(double *)worldX worldCoordY:(double *)worldY;


/**
 *  SK 좌표를 bessel 좌표로 변환
 */
+ (BOOL)skToBessel:(unsigned short)tile_x andTileY:(unsigned short)tile_y skX:(unsigned short)x skY:(unsigned short)y outX:(double *)pbX outY:(double *)pbY;

@end
