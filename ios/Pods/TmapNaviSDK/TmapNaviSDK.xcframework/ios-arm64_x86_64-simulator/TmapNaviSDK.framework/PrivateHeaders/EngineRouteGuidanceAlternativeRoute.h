//
//  EngineRouteGuidanceAlternativeRoute.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// AlternativeRoute을 나타내기 위한

@interface EngineRouteGuidanceAlternativeRoute : NSObject

@property (nonatomic) BOOL hasAlternativeRouteData;
@property (nonatomic) NSString* routeSummaryName;
@property (nonatomic) NSString* mainRoadName;
@property (nonatomic) NSString* guidePointName;
@property (nonatomic) NSInteger elapsedTime;
@property (nonatomic) NSInteger elapsedDistance;
@property (nonatomic) NSInteger priceInfo;
@property (nonatomic) BOOL isZeroPrice;
@property (nonatomic) NSNumber* startPointX;
@property (nonatomic) NSNumber* startPointY;
@property (nonatomic) NSNumber* mainRoutePointX;
@property (nonatomic) NSNumber* mainRoutePointY;
@property (nonatomic) NSArray<NSNumber*>* popupPointX;
@property (nonatomic) NSArray<NSNumber*>* popupPointY;
@property (nonatomic) NSInteger startVertexIndex;
@property (nonatomic) NSInteger alterInfoEndVertexIndex;
@property (nonatomic) NSInteger remainDistance;
@property (nonatomic) NSInteger showPrice;

@end

NS_ASSUME_NONNULL_END
