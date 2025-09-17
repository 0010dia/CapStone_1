//
//  EngineRouteGuidanceTBTList.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>
#import "EngineRouteEVStationInfo.h"

NS_ASSUME_NONNULL_BEGIN

// OsTBTList을 나타내기 위한

@interface EngineRouteGuidanceTBTList : NSObject

@property (nonatomic) NSInteger linkIndex;
@property (nonatomic) NSInteger groupId;
@property (nonatomic) BOOL isHighway;
@property (nonatomic) NSInteger tbtType;
@property (nonatomic) NSInteger turnCode;
@property (nonatomic) NSString* tbtMainText;
@property (nonatomic) NSInteger accDist;
@property (nonatomic) NSInteger accTime;
@property (nonatomic) NSInteger tollFee;
@property (nonatomic) NSInteger oilFlag;
@property (nonatomic) NSArray<NSNumber*>* oilCompany;
@property (nonatomic) NSArray<NSNumber*>* oilPrice;
@property (nonatomic) NSInteger premiumOilAvailable;
@property (nonatomic) NSInteger isPartnerCardSale;
@property (nonatomic) NSArray<EngineRouteEVStationInfo*>* evStationInfoList;
@property (nonatomic) NSInteger rcType;
@property (nonatomic) NSInteger congestion;
@property (nonatomic) BOOL isHighwayExit;
@property (nonatomic) NSInteger groupHighwayDist;
@property (nonatomic) NSInteger accGroupHighwayDist;

@end

NS_ASSUME_NONNULL_END
