//
//  EngineRoutePositionInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/12.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EngineRoutePositionInfo : NSObject

@property (nonatomic) double x;
@property (nonatomic) double y;
@property (nonatomic) NSString * positionName;

@end

NS_ASSUME_NONNULL_END
