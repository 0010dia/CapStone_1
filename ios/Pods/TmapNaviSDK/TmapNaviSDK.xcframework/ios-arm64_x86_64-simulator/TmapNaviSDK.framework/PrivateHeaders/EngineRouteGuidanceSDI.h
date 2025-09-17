//
//  EngineRouteGuidanceSDI.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsSDI을 나타내기 위한

@interface EngineRouteGuidanceSDI : NSObject

@property (nonatomic) NSNumber* currentPosX;
@property (nonatomic) NSNumber* currentPosY;
@property (nonatomic) NSInteger sdiType;
@property (nonatomic) NSInteger sdiSection;
@property (nonatomic) NSNumber* sdiPointX;
@property (nonatomic) NSNumber* sdiPointY;
@property (nonatomic) NSInteger sdiDist;
@property (nonatomic) NSInteger sdiId;
@property (nonatomic) BOOL target;
@property (nonatomic) NSNumber* vec32TargetwptX;
@property (nonatomic) NSNumber* vec32TargetwptY;
@property (nonatomic) NSInteger sdiSpeedLimit;
@property (nonatomic) BOOL sdiBlockSection;
@property (nonatomic) NSNumber* sdiBlockEndPointX;
@property (nonatomic) NSNumber* sdiBlockEndPointY;
@property (nonatomic) NSInteger sdiBlockDist;
@property (nonatomic) NSInteger sdiBlockSpeed;
@property (nonatomic) NSInteger sdiBlockAverageSpeed;
@property (nonatomic) NSInteger sdiBlockTime;
@property (nonatomic) NSInteger sdiBlockType;
@property (nonatomic) NSInteger speedbumpPlayList;
@property (nonatomic) NSInteger speedbumpObjectCount;
@property (nonatomic) BOOL isChangeableSpeedType;
@property (nonatomic) BOOL isLimitSpeedSignChanged;
@property (nonatomic) BOOL isInSchoolZone;
@property (nonatomic) NSInteger drivingBuslane;
@property (nonatomic) NSInteger truckLimit;

@end

NS_ASSUME_NONNULL_END
