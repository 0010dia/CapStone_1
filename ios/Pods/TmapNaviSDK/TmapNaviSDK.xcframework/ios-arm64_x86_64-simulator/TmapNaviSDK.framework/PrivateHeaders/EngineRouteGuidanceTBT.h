//
//  EngineRouteGuidanceTBT.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// OsTBT을 나타내기 위한

@interface EngineRouteGuidanceTBT : NSObject

@property (nonatomic) NSNumber* tbtPointX;
@property (nonatomic) NSNumber* tbtPointY;
@property (nonatomic) NSInteger tbtDist;
@property (nonatomic) NSInteger tbtTime;
@property (nonatomic) NSInteger tbtTurnType;
@property (nonatomic) NSInteger tollFee;
@property (nonatomic) NSInteger svcLinkDist;
@property (nonatomic) NSInteger nextRoadWidth;
@property (nonatomic) NSString* roadName;
@property (nonatomic) NSString* crossName;
@property (nonatomic) NSString* nearDirName;
@property (nonatomic) NSString* midDirName;
@property (nonatomic) NSString* farDirName;
@property (nonatomic) NSString* tbtMainText;
@property (nonatomic) NSString* pointName;

@end

NS_ASSUME_NONNULL_END
