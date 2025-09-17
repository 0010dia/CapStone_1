//
//  EngineDrawingMapMatchPosition.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// MM_VERTEX을 나타내기 위한

@interface EngineDrawingMapMatchPosition : NSObject

@property (nonatomic) NSInteger tvasId;
@property (nonatomic) NSInteger nIdx;
@property (nonatomic) NSNumber* x;
@property (nonatomic) NSNumber* y;
@property (nonatomic) NSNumber* z;
@property (nonatomic) NSNumber* angle;
@property (nonatomic) NSNumber* accuracy;
@property (nonatomic) NSInteger intervalMiiliseconds;

@end

NS_ASSUME_NONNULL_END
