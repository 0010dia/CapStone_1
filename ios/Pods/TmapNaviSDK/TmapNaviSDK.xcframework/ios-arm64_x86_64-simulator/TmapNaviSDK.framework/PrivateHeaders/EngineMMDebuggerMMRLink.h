//
//  EngineMMDebuggerMMRLink.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

NS_ASSUME_NONNULL_BEGIN

// MM_VERTEX을 나타내기 위한
@class EngineMMDebuggerVertex;
@class EngineMMDebuggerRectd;

@interface EngineMMDebuggerMMRLink : NSObject

@property (nonatomic) NSInteger id;
@property (nonatomic) NSArray<EngineMMDebuggerVertex*>* vertices;
@property (nonatomic) NSInteger count;
@property (nonatomic) EngineMMDebuggerRectd* extent;
@property (nonatomic) NSInteger type;

@end

NS_ASSUME_NONNULL_END
