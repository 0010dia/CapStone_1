//
//  EngineVertexTraceInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// TVASVERTEX_DATASET을 나타내기 위한

@interface EngineVertexTraceInfo : NSObject

@property (nonatomic) NSInteger uTileCode;                      //타일 코드
@property (nonatomic) NSInteger uPosX;                          //타일 내 X 좌표
@property (nonatomic) NSInteger uPosY;                          //타일 내 Y 좌표
@property (nonatomic) NSInteger uDistance;                      //V(n) ~ V(N+1)까지의 소요 거리
@property (nonatomic) NSInteger uTime;                          //V(n) ~ V(N+1)까지의 소요 시간

@end

NS_ASSUME_NONNULL_END
