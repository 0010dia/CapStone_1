//
//  EngineRouteRerouteRIDData.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/06/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EngineRouteRerouteRIDData : NSObject
/** 마지막 매칭 RID  */
@property (nonatomic) NSInteger lastRid;
/** 이전경로 맵버전  */
@property (nonatomic) NSString* preMapVersion;
/** 이전경로 RID 목록 */
@property (nonatomic, nullable) NSArray<NSNumber*>* preRids;
/** 이전경로 RID의 소요시간 목록 */
@property (nonatomic, nullable) NSArray<NSNumber*>* preSecs;
/** 초기탐색 직선거리 */
@property (nonatomic) NSInteger firstSrchLength;
/** 초기탐색 SessionId */
@property (nonatomic) NSString* firstSrchSessionId;

@end

NS_ASSUME_NONNULL_END
