//
//  EngineRouteGuidanceViaPoint.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/03/06.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsViaPoint을 나타내기 위한

@interface EngineRouteGuidanceViaPoint : NSObject

@property (nonatomic) NSInteger viaDist;
@property (nonatomic) NSInteger viaTime;
@property (nonatomic) NSInteger viaIndex;

@end

NS_ASSUME_NONNULL_END
