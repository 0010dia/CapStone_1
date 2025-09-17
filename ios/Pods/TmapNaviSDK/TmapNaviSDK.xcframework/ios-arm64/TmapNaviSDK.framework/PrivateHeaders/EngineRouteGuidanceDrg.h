//
//  EngineRouteGuidanceDrg.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/18.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsDRGInfo을 나타내기 위한

@interface EngineRouteGuidanceDrg : NSObject

@property (nonatomic) NSInteger nDrgVXIdx;
@property (nonatomic) NSInteger nDrgType;
@property (nonatomic) NSInteger congestRid;

@end

NS_ASSUME_NONNULL_END
