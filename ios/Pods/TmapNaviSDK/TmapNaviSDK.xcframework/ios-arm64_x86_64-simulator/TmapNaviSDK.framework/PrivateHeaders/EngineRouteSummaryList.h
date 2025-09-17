//
//  EngineRouteSummaryList.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>
#import "EngineRouteSummaryCCTVInfo.h"

NS_ASSUME_NONNULL_BEGIN

// stTmapSummaryList을 나타내기 위한

@interface EngineRouteSummaryList : NSObject

@property (nonatomic) NSInteger type;
@property (nonatomic) NSInteger controlCode;
@property (nonatomic) NSInteger summaryNameOffset;
@property (nonatomic) NSInteger sectionDist;
@property (nonatomic) NSInteger sectionTime;
@property (nonatomic) NSInteger trafficCollectSpeed;
@property (nonatomic) NSInteger trafficCollectCon;
@property (nonatomic) NSInteger startVertexIdx;
@property (nonatomic) NSInteger endVertexIdx;
@property (nonatomic) NSInteger sectionWeatherCode;
@property (nonatomic) NSInteger rsdTurnCode;
@property (nonatomic) NSInteger vertexIndex;
@property (nonatomic) NSNumber* sectionStartX;
@property (nonatomic) NSNumber* sectionStartY;
@property (nonatomic) NSNumber* sectionEndX;
@property (nonatomic) NSNumber* sectionEndY;
@property (nonatomic) NSString* sectionName;
@property (nonatomic) NSInteger includedFineRoad;

@end

NS_ASSUME_NONNULL_END
