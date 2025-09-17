//
//  LocationData.h
//  TMFactory
//
//  Created by Jongkil.Yun on 2015. 4. 16..
//  Copyright (c) 2015년 sk planet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
// 아래의 header들 포함 시 include of non-modular header inside framework module 발생
//#import "TmapCoord.h"
//#import "CLLocation+Utils.h"
//#import "JSONModel+Tmap.h"
//#import "SGLType+Extension.h"


/*
 4.x : GPSData.m GPSService.m
 CLLocation 중심으로 재 구현함.
 */
@interface LocationData : NSObject

//status의 type이 BOOL이었음 swift에서 참조하기 위해 header를 private으로 빼고 build를 하게 되는 경우
//Type of property 'Bool' (aka 'int') in class extension does not match property type in primary class 에러 발생
@property (nonatomic, assign, readonly) int             status;         // GPS 상태 값 (1:좋음/0:나쁨)
@property (nonatomic, assign, readonly) double          latitude;       // 위도
@property (nonatomic, assign, readonly) double          longitude;      // 경도
@property (nonatomic, assign, readonly) int             skx;            // SK 좌표
@property (nonatomic, assign, readonly) int             sky;            // SK 좌표
@property (nonatomic, assign, readonly) double          worldx;         // WORLD 좌표
@property (nonatomic, assign, readonly) double          worldy;         // WORLD 좌표
@property (nonatomic, assign, readonly) double          altitude;       // 고도
@property (nonatomic, assign, readonly) NSTimeInterval  time;           // 시간 ([location.timestamp timeIntervalSince1970])
@property (nonatomic, assign, readonly) float           speed;          // 속도 (km/h)
@property (nonatomic, assign, readonly) float           heading;        // 방향각
@property (nonatomic, assign, readonly) double          relativeAltitude;       // 상대고도
@property (nonatomic, assign, readonly) NSString*       provider;       // provider


// init
- (instancetype)initWithCLLocation:(CLLocation *)location;
- (instancetype)initWithCLLocation:(CLLocation *)location relativeAltitude:(double) relativeAltitude;
- (instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;
- (instancetype)initWithSkx:(NSInteger)skx sky:(NSInteger)sky;
- (instancetype)initWithWorldx:(double)worldx worldy:(double)worldy;
- (instancetype)initWithBesselx:(CGFloat)besselx bessely:(CGFloat)bessely;

- (instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude heading:(NSInteger)heading speed:(NSInteger)speed;


// setter
- (void)setCLLocation:(CLLocation *)location;
- (void)setLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude;
- (void)setSkx:(int)skx sky:(int)sky;
- (void)setWorldx:(double)worldx worldy:(double)worldy;
- (void)setBesselx:(CGFloat)besselx bessely:(CGFloat)bessely;
- (void)setRelativeAltitude:(double)relativeAltitude;
- (void)setProvider:(NSString*)provider;

// get info
- (BOOL)isValidCoord;
- (BOOL)isKoreanCoord;
- (CLLocation *)location;

//일몰 일출
//- (BOOL)isDaytime;

// util
+ (LocationData *)locationData3WithLocationData:(LocationData *)gpsData1 locationData2:(LocationData *)gpsData2;

- (CLLocationDistance)distanceFromLocationData:(LocationData *)gpsData1 nextLocationData:(LocationData *)gpsData2;
- (CLLocationDistance)distanceFromLocationData:(LocationData *)gpsData;

- (CLLocationDistance)perpendicularDistanceWithLocationData:(LocationData *)gpsData1 LocationData2:(LocationData *)gpsData2;

- (void)updateInvalidInfoWithOldData:(LocationData *)oldData;

@end

@interface CLLocation (_Source)

@property (nonatomic) BOOL _fromLog;

@end

