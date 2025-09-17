//
//  EngineMMDebuggerMMRRect.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

NS_ASSUME_NONNULL_BEGIN

// MM_VERTEX을 나타내기 위한
@class EngineMMDebuggerRectd;

@interface EngineMMDebuggerMMRRect : NSObject

@property (nonatomic) EngineMMDebuggerRectd* rect;
@property (nonatomic) NSInteger type;
@property (nonatomic) BOOL valid;

@end

NS_ASSUME_NONNULL_END
