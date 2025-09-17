//
//  NavigationCoreInterface.h
//  NaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/03/28.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

NS_ASSUME_NONNULL_BEGIN

@class EngineRouteInfo;
@class EngineRouteGuidanceDriveInfo;
@class EngineDrawingMapMatchPosition;
@class EngineGPSTraceInfo;
@class EngineVertexTraceInfo;
@class EngineLinkTraceInfo;
@class EngineTunnelInfo;
@class EngineRouteGuidanceTBTList;
@class EngineRouteRerouteData;
@class EngineRouteRerouteRIDData;
@class EngineRouteRenderData;
@class EngineGuidanceConfig;

@protocol TileLoadable <NSObject>

@required
- (void)loadTileWithLevel:(unsigned int)level x:(unsigned int)x y:(unsigned int)y;

@end

@interface NavigationCoreInterface : NSObject

@property (nullable, strong, nonatomic) id<TileLoadable> tileLoader;
@property (nonatomic, readonly) BOOL isInitialized;

+ (NavigationCoreInterface *)sharedInstance;
- (void)initializeWithLinkStackId:(unsigned int)linkStackId
                       sdiStackId:(unsigned int)sdiStackId
                        supportDR:(BOOL)supportDR;

- (void)setMapMatchDebuggerActive:(BOOL)active;

- (void)finalize;

- (int)inputLocation:(CLLocation *)location accuracy:(CLLocationAccuracy) accuracy provider:(NSString*) provider;

- (bool)setRoadNetworkTileDataWithSucceed:(BOOL)succeed
                                    level:(unsigned int)level
                                      x:(unsigned int)x
                                      y:(unsigned int)y
                                     data:(nullable NSData *)data;

- (EngineRouteGuidanceDriveInfo *)getRouteGuidance;
- (EngineRouteGuidanceDriveInfo *)getRouteGuidanceSimulator:(unsigned int)option
                                                      speed:(unsigned int)speed
                                          distanceFromStart:(unsigned int)distanceFromStart;

- (bool)IsRoute;

- (bool)ApplySelectRouteWithnSelectRoute:(int)nSelectRoute
              skipStartDrivingTTSComment:(BOOL)skipStartDrivingTTSComment;

- (bool)selectRouteWithnSelectRoute:(int)nSelectRoute;

- (bool)cancelRoute:(BOOL) remainDestFlags;

- (bool)SetTvasDataWithData:(NSData*)data
                    options:(nullable int[])options
                    nRouteCnt:(int)nRouteCnt
                    tvasSize:(nullable int[])tvasSize
                    bIsReRoute:(BOOL)bIsReRoute
                    requestType:(int)requestType
                    destSearchDetailFlag:(int)destSearchDetailFlag
                    isRouteOptionChanged:(BOOL)isRouteOptionChanged
                    isFavoriteRouteSelected:(BOOL)isFavoriteRouteSelected
                    selectedIndex:(int)selectedIndex;

- (NSArray<EngineRouteInfo*>*) getRouteData:(NSData*)tvasData
                                  tvasCount:(int)tvasCount
                                   tvasSize:(const int[_Nonnull])tvasSize;

- (NSArray<EngineDrawingMapMatchPosition*>*) getMapMatchPositionDrawingDatas:(BOOL)isSimulation;

- (NSArray<EngineGPSTraceInfo*>* _Nullable) getGpsTraceInfo;
- (NSArray<EngineVertexTraceInfo*>*) getVertexTraceInfo;
- (NSArray<EngineLinkTraceInfo*>*) getLinkTraceInfo;
- (EngineTunnelInfo* _Nullable) getTunnelInfo;
- (CLLocation* _Nullable) getAutoDrivePosition:(int)speedKmh
                                     timestamp:(NSTimeInterval)timestamp;

- (void) initEngineSound;
- (bool)isNaviPlaying;

- (NSArray<EngineRouteGuidanceTBTList*>*) getRouteTBTList:(int)nType
                                                     nIdx:(int)nIdx
                                                     nCnt:(int)nCnt
                                                  groupID:(int)groupID;

- (EngineRouteRerouteData*) getRerouteData;
- (EngineRouteRerouteRIDData* _Nullable) getRerouteRidData;

- (NSArray<EngineRouteRenderData*>*) getRouteRenderData;

- (bool) setGuidanceConfig:(EngineGuidanceConfig*)config;
- (EngineGuidanceConfig* _Nullable)getGuidanceConfig;

/*
 TODO. 아래의 API 연결해야 함.
 
 Int32 CNaviController::GetRouteCount()
 Int32 GetTmapRouteSummaryInfo(stTmapSummaryBaseInfo *pSummaryInfo);
   */

@end

NS_ASSUME_NONNULL_END

