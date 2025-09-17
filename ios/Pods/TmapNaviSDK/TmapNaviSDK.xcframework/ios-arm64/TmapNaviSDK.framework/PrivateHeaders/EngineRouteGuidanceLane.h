//
//  EngineRouteGuidanceLane.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsLane을 나타내기 위한

@interface EngineRouteGuidanceLane : NSObject

@property (nonatomic) NSNumber* lanePointX;
@property (nonatomic) NSNumber* lanePointY;
@property (nonatomic) NSInteger laneTurnCode;
@property (nonatomic) NSInteger laneDist;
@property (nonatomic) NSInteger laneCount;
@property (nonatomic) NSArray<NSNumber*>* laneTurnInfo;
@property (nonatomic) NSArray<NSNumber*>* laneEtcInfo;
@property (nonatomic) NSArray<NSNumber*>* laneAvailable;
@property (nonatomic) BOOL lanePlay;

@end

NS_ASSUME_NONNULL_END
