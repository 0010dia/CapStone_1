//
//  EngineRouteEVStationBrandInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 12/14/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// stBrandInfo을 나타내기 위한

@interface EngineRouteEVStationBrandInfo : NSObject

@property (nonatomic) NSString* brandName;
@property (nonatomic) NSString* brandCode;
@property (nonatomic) NSInteger availableSuperFastCount;
@property (nonatomic) NSInteger availableFastCount;
@property (nonatomic) NSInteger availableSlowCount;

@end

NS_ASSUME_NONNULL_END
