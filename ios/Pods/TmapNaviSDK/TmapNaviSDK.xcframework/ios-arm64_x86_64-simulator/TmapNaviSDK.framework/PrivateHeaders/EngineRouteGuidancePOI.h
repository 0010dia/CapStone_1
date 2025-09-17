//
//  EngineRouteGuidancePOI.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsPOI을 나타내기 위한

@interface EngineRouteGuidancePOI : NSObject

@property (nonatomic) NSInteger stationID;
@property (nonatomic) NSInteger polecate;
@property (nonatomic) NSInteger jcomp;
@property (nonatomic) NSInteger poiCode;
@property (nonatomic) NSInteger poiPrice;
@property (nonatomic) NSInteger poiDistance;
@property (nonatomic) NSNumber* poiPosX;
@property (nonatomic) NSNumber* poiPosY;

@end

NS_ASSUME_NONNULL_END
