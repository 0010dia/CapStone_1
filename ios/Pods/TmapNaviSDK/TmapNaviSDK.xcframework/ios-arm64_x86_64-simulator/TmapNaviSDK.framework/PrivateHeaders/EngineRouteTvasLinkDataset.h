//
//  EngineRouteTvasLinkDataset.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// TVAS_LINK_DATASET을 나타내기 위한

@interface EngineRouteTvasLinkDataset : NSObject

@property (nonatomic) NSInteger meshCode;
@property (nonatomic) NSInteger linkId;
@property (nonatomic) NSInteger dir;
@property (nonatomic) NSInteger time;
@property (nonatomic) NSInteger isCompareRoute; //경로비교대상 (0:비대상, 1:대상)

@end

NS_ASSUME_NONNULL_END
