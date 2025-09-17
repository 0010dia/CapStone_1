//
//  EngineLinkTraceInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// TVAS_LINK_DATASET을 나타내기 위한

@interface EngineLinkTraceInfo : NSObject

@property (nonatomic) NSInteger meshCode;                       //SK맵 Mesh Code
@property (nonatomic) NSInteger linkId;                         //SK맵 맵링크 ID
@property (nonatomic) NSInteger dir;                            //SK맵 맵링크 방향성 (0:정방향, 1:역방향)
@property (nonatomic) NSInteger uTime;                          //GPS시각(한국시간 2003년1월1일부터 초단위)

@end

NS_ASSUME_NONNULL_END
