//
//  EngineRouteGuidanceRTM.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsRTM을 나타내기 위한

@interface EngineRouteGuidanceRTM : NSObject

@property (nonatomic) NSInteger rtmCode;
@property (nonatomic) NSInteger rtmDist;
@property (nonatomic) NSNumber* rtmPosX;
@property (nonatomic) NSNumber* rtmPosY;

@end

NS_ASSUME_NONNULL_END
