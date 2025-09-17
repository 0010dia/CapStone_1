//
//  EngineRouteGuidanceTBTPosition.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsTBTPos을 나타내기 위한

@interface EngineRouteGuidanceTBTPosition : NSObject

@property (nonatomic) NSInteger groupId;
@property (nonatomic) NSInteger accDist;
@property (nonatomic) NSInteger accTime;
@property (nonatomic) NSInteger tbtIndex;
@property (nonatomic) NSInteger tbtIndexSummary;
@property (nonatomic) NSInteger tbtIndexICJCTG;
@property (nonatomic) NSInteger tbtIndexSA;
@property (nonatomic) NSInteger tbtIndexHW;
@property (nonatomic) NSInteger showHighway;
@property (nonatomic) NSInteger highwayIndex;
@property (nonatomic) NSArray<NSNumber*>* highwayPassIndex;
@property (nonatomic) NSArray<NSNumber*>* highwayPassTime;

@end

NS_ASSUME_NONNULL_END
