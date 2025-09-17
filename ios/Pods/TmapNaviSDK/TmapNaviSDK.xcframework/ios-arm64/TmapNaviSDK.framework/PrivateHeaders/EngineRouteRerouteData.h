//
//  EngineRouteRerouteData.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/06/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EngineRouteRerouteData : NSObject
/** 재탐색 요구조건 데이터 */
@property (nonatomic) NSData* pRouteData;
/** 재탐색 요구조건 데이터 크기 */
@property (nonatomic) NSInteger nDataSize;
/** 주변링크 정보 유무 */
@property (nonatomic) BOOL bAroundLink;
/** 이탈 지점 기존경로 RSD 회전 코드 */
@property (nonatomic) NSInteger uOldRsdCode;
/** 진입 RSD 회전 코드 */
@property (nonatomic) NSInteger uRsdCode;
/** 링크 id */
@property (nonatomic) NSInteger uLinkID;
/** 타일코드(Link) */
@property (nonatomic) NSInteger uTileCode;
/** 방향 (0:정방향, 1:역방향) */
@property (nonatomic) NSInteger uDirInfo;
/** 보간점 X 좌표(경도: 정수8자리 SK정규화좌표) */
@property (nonatomic) NSInteger uPosX;
/** 보간점 Y 좌표(위도: 정수8자리 SK정규화좌표) */
@property (nonatomic) NSInteger uPosY;
/** 최종통과 톨게이트 ID */
@property (nonatomic) NSInteger uPassedTollID;
/** 전체 톨게이트 ID list */
@property (nonatomic) NSString* tollgateIdList;

@end

NS_ASSUME_NONNULL_END
