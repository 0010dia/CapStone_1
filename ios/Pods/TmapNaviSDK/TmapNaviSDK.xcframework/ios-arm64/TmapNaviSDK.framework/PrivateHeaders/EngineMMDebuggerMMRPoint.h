//
//  EngineMMDebuggerMMRPoint.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

NS_ASSUME_NONNULL_BEGIN

@class EngineMMDebuggerVertex;

@interface EngineMMDebuggerMMRPoint : NSObject

@property (nonatomic) EngineMMDebuggerVertex* pos;
@property (nonatomic) NSNumber* angle;
@property (nonatomic) NSInteger radius;
@property (nonatomic) NSInteger type;
@property (nonatomic) BOOL valid;

@end

NS_ASSUME_NONNULL_END
