//
//  EngineRouteServiceAreaInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>
#import "EngineRouteEVStationInfo.h"

NS_ASSUME_NONNULL_BEGIN

// stServiceAreaInfo을 나타내기 위한

@interface EngineRouteServiceAreaInfo : NSObject

@property (nonatomic) NSString* name;
@property (nonatomic) NSInteger poiID;
@property (nonatomic) NSInteger startVertexIndex;
@property (nonatomic) NSNumber* startPointX;
@property (nonatomic) NSNumber* startPointY;
@property (nonatomic) NSNumber* endPointX;
@property (nonatomic) NSNumber* endPointY;
@property (nonatomic) NSInteger oilFlag;
@property (nonatomic) NSArray<NSNumber*>* oilCompany;
@property (nonatomic) NSArray<NSNumber*>* oilPrice;
@property (nonatomic) NSInteger premiumOilAvailable;
@property (nonatomic) NSInteger isPartnerCardSale;
@property (nonatomic) NSArray<EngineRouteEVStationInfo*>* evStationInfo;

@end

NS_ASSUME_NONNULL_END
