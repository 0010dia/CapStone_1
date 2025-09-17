//
//  EngineMMDebuggerMMRNetwork.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

NS_ASSUME_NONNULL_BEGIN

@class EngineMMDebuggerMMRLink;
@class EngineMMDebuggerRectd;

@interface EngineMMDebuggerMMRNetwork : NSObject

@property (nonatomic) NSInteger id;
@property (nonatomic) NSArray<EngineMMDebuggerMMRLink*>* links;
@property (nonatomic) NSInteger count;
@property (nonatomic) EngineMMDebuggerRectd* extent;

@end

NS_ASSUME_NONNULL_END
