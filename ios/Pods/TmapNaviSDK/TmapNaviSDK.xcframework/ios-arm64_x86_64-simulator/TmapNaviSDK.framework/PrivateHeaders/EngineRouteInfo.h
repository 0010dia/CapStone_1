//
//  EngineRouteInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/12.
//

#import <Foundation/Foundation.h>
#import "EngineRouteRenderData.h"
#import "EngineRouteSummaryBaseInfo.h"
#import "EngineRouteEVStationInfo.h"
#import "EngineRouteGasStationInfo.h"
#import "EngineRouteServiceAreaInfo.h"
#import "EngineRouteSummaryList.h"
#import "EngineRouteThemeRoadInfo.h"
#import "EngineRouteTvasLinkDataset.h"

NS_ASSUME_NONNULL_BEGIN

@interface EngineRouteInfo : NSObject

@property (nonatomic) EngineRouteRenderData* routeRenderData;
@property (nonatomic) EngineRouteSummaryBaseInfo* routeSummaryBaseInfo;
@property (nonatomic) NSArray<EngineRouteEVStationInfo*>* routeEVStationInfo;
@property (nonatomic) NSArray<EngineRouteGasStationInfo*>* routeGasStationInfo;
@property (nonatomic) NSArray<EngineRouteServiceAreaInfo*>* routeServiceAreaInfo;
@property (nonatomic) NSArray<EngineRouteSummaryList*>* routeSummaryList;
@property (nonatomic) NSArray<EngineRouteThemeRoadInfo*>* routeThemeRoadInfo;
@property (nonatomic) NSArray<EngineRouteTvasLinkDataset*>* routeTvasLinkDataset;

@end

NS_ASSUME_NONNULL_END
