//
//  EngineRouteEVStationInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>
#import "EngineRouteEVStationBrandInfo.h"

NS_ASSUME_NONNULL_BEGIN

// stEVStationInfo을 나타내기 위한

@interface EngineRouteEVStationInfo : NSObject

@property (nonatomic) NSString* name;
@property (nonatomic) NSInteger vertexIndex;
@property (nonatomic) NSInteger poiID;
@property (nonatomic) NSInteger roadCode;
@property (nonatomic) NSNumber* pointX;
@property (nonatomic) NSNumber* pointY;
@property (nonatomic) NSInteger isStationOnRoutePath;
@property (nonatomic) NSInteger isDcCHA;
@property (nonatomic) NSInteger isAC3;
@property (nonatomic) NSInteger isDcCombo;
@property (nonatomic) NSInteger isSlowCharge;
@property (nonatomic) NSInteger isTeslaSuperCharger;
@property (nonatomic) NSInteger distanceFromStartPoint;
@property (nonatomic) NSArray<EngineRouteEVStationBrandInfo*>* evStationBrandInfo;

@end

NS_ASSUME_NONNULL_END
