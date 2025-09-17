//
//  EngineRouteRenderData.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/12.
//

#import <Foundation/Foundation.h>

// engine의 ROUTE_RENDER_DATA을 저장하기 위한 object

NS_ASSUME_NONNULL_BEGIN

@interface EngineRouteRenderData : NSObject

@property (nonatomic) NSData* data;

@property (nonatomic) NSInteger dataSize;

@end

NS_ASSUME_NONNULL_END
