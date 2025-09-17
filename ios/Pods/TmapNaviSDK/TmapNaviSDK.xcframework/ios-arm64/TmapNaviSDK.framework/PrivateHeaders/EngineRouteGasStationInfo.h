//
//  EngineRouteGasStationInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// stGasStationInfo을 나타내기 위한

@interface EngineRouteGasStationInfo : NSObject

@property (nonatomic) NSInteger type;
@property (nonatomic) NSInteger brand;
@property (nonatomic) NSInteger facility;
@property (nonatomic) NSInteger roadCode;
@property (nonatomic) NSInteger hasPremiumOil;
@property (nonatomic) NSInteger isLowerPrice;
@property (nonatomic) NSNumber* pointX;
@property (nonatomic) NSNumber* pointY;
@property (nonatomic) NSInteger idx;
@property (nonatomic) NSString* name;
@property (nonatomic) NSInteger gasolinePrice;
@property (nonatomic) NSInteger dieselPrice;
@property (nonatomic) NSInteger kerosenePrice;
@property (nonatomic) NSInteger lpgPrice;
@property (nonatomic) NSInteger premiumGasolinePrice;
@property (nonatomic) NSInteger premiumDieselPrice;
@property (nonatomic) NSInteger premiumKerosenePrice;
@property (nonatomic) NSInteger distanceFromStartPoint;
@property (nonatomic) NSInteger poiID;
@property (nonatomic) NSInteger isPartnerCardSale;
@property (nonatomic) NSInteger isTruckStation;

@end

NS_ASSUME_NONNULL_END
