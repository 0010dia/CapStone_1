//
//  EngineRouteGuidancePosition.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsPosition을 나타내기 위한

@interface EngineRouteGuidancePosition : NSObject

@property (nonatomic) NSInteger posMMIndex;
@property (nonatomic) NSNumber* posPointX;
@property (nonatomic) NSNumber* posPointY;
@property (nonatomic) NSInteger currentLane;
@property (nonatomic) NSInteger posSpeed;
@property (nonatomic) NSInteger posAngle;
@property (nonatomic) NSInteger roadCate;
@property (nonatomic) NSInteger linkfacil;
@property (nonatomic) NSInteger linkcate;
@property (nonatomic) NSInteger roadLimitSpeed;
@property (nonatomic) NSInteger linkIdx;
@property (nonatomic) NSString* posRoadName;
@property (nonatomic) NSString* posAddrName;
@property (nonatomic) NSString* nextRoadName;
@property (nonatomic) NSInteger outCityCode;
@property (nonatomic) NSInteger inCityCode;

@end

NS_ASSUME_NONNULL_END
