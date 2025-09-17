//
//  EngineRouteSummaryBaseInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/12.
//

#import <Foundation/Foundation.h>
#import "EngineRoutePositionInfo.h"

NS_ASSUME_NONNULL_BEGIN

// tagTmapSummaryBaseInfo을 나타내기 위한

@interface EngineRouteSummaryBaseInfo : NSObject

@property (nonatomic) NSInteger tvasId;
@property (nonatomic) NSInteger num;
@property (nonatomic) NSInteger routeOption;
@property (nonatomic) NSInteger routeType;
@property (nonatomic) NSInteger indexType;
@property (nonatomic) NSInteger dataType;
@property (nonatomic) NSString* indexId;
@property (nonatomic) NSString* trafficTime;
@property (nonatomic) NSInteger tollFee;
@property (nonatomic) NSInteger weatherCode;
@property (nonatomic) NSInteger predictCode;
@property (nonatomic) NSString* predictTime;
@property (nonatomic) NSInteger totalDist;
@property (nonatomic) NSInteger totalTime;
@property (nonatomic) NSInteger taxiFee;
@property (nonatomic) NSNumber* minX;
@property (nonatomic) NSNumber* minY;
@property (nonatomic) NSNumber* maxX;
@property (nonatomic) NSNumber* maxY;
@property (nonatomic) NSString* startPosName;
@property (nonatomic) NSString* endPosName;
@property (nonatomic) NSNumber* co2Generation;
@property (nonatomic) NSNumber* fuelReduction;
@property (nonatomic) NSInteger totalCCTVCount;
@property (nonatomic) NSArray<EngineRoutePositionInfo*> *posInfo;
@property (nonatomic) NSArray<EngineRoutePositionInfo*> *pointInRoutePathInfo;
@property (nonatomic) NSArray<NSString*> *roadNames;
@property (nonatomic) NSInteger roadAttribute;
@property (nonatomic) NSInteger mainRoadPosCount;
@property (nonatomic) NSArray<EngineRoutePositionInfo*> *mainRoadPos;
@property (nonatomic) BOOL mainRoadChanged;
@property (nonatomic) NSInteger goalDirection;
@property (nonatomic) NSString* themeRoadId;
@property (nonatomic) NSString* themeRoadName;

@end

NS_ASSUME_NONNULL_END
