//
//  EngineRouteGuidanceDriveInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/17.
//

#import <Foundation/Foundation.h>
#import "EngineRouteGuidancePosition.h"
#import "EngineRouteGuidanceLane.h"
#import "EngineRouteGuidanceSDI.h"
#import "EngineRouteGuidanceRTM.h"
#import "EngineRouteGuidancePOI.h"
#import "EngineRouteGuidanceTBT.h"
#import "EngineRouteGuidanceTBTList.h"
#import "EngineRouteGuidanceTBTPosition.h"
#import "EngineRouteGuidanceAlternativeRoute.h"
#import "EngineRouteGuidanceDrg.h"
#import "EngineRouteGuidanceViaPoint.h"

NS_ASSUME_NONNULL_BEGIN

// stDriveInfo을 나타내기 위한

@interface EngineRouteGuidanceDriveInfo : NSObject

@property (nonatomic) NSInteger rgStatus;
@property (nonatomic) NSInteger virtualGps;
@property (nonatomic) BOOL isPossiblePeriodicRerouteArea;
@property (nonatomic) EngineRouteGuidancePosition* currentPosition;
@property (nonatomic) NSNumber* linkStartPointX;
@property (nonatomic) NSNumber* linkStartPointY;
@property (nonatomic) NSNumber* linkEndPointX;
@property (nonatomic) NSNumber* linkEndPointY;
@property (nonatomic) BOOL isLaneAvailable;
@property (nonatomic) EngineRouteGuidanceLane* lane;
@property (nonatomic) BOOL is1stLaneAvailable;
@property (nonatomic) EngineRouteGuidanceLane* lane1st;
@property (nonatomic) BOOL is2ndLaneAvailable;
@property (nonatomic) EngineRouteGuidanceLane* lane2nd;
@property (nonatomic) BOOL isSDIAvailable;
@property (nonatomic) NSInteger sdiCount;
@property (nonatomic) NSInteger linkFacil;
@property (nonatomic) NSInteger nextLinkFacil;
@property (nonatomic) NSArray<EngineRouteGuidanceSDI*>* sdiList;
@property (nonatomic) BOOL isSpeedBumpAvailable;
@property (nonatomic) NSArray<EngineRouteGuidanceSDI*>* speedBumpList;
@property (nonatomic) BOOL isRTMAvailable;
@property (nonatomic) EngineRouteGuidanceRTM* rtm;
@property (nonatomic) BOOL isPOIAvailable;
@property (nonatomic) BOOL isPOIButtonAvailable;
@property (nonatomic) EngineRouteGuidancePOI* poi;
@property (nonatomic) NSInteger totalDist;
@property (nonatomic) NSInteger totalTime;
@property (nonatomic) BOOL aroundGoPos;
@property (nonatomic) NSInteger goPosCode;
@property (nonatomic) NSString* goPosName;
@property (nonatomic) NSInteger goPosDist;
@property (nonatomic) NSInteger goPosTime;
@property (nonatomic) NSArray<EngineRouteGuidanceViaPoint*>* remainViaPoints;
@property (nonatomic) EngineRouteGuidanceTBT* guidePoint1st;
@property (nonatomic) EngineRouteGuidanceTBT* guidePoint2nd;
@property (nonatomic) NSArray<EngineRouteGuidanceTBT*>* remainGuidePoints;
@property (nonatomic) BOOL isExtcImageAvailable;
@property (nonatomic) NSInteger extcImageCode;
@property (nonatomic) NSInteger extcVoiceCode;
@property (nonatomic) BOOL hasNVX;
@property (nonatomic) BOOL isDirImageAvailable;
@property (nonatomic) NSInteger dirImageCode;
@property (nonatomic) NSInteger dirImageShowDist;
@property (nonatomic) NSString* imageBaseUrl;
@property (nonatomic) NSString* imageDayUrl;
@property (nonatomic) NSString* imageNightUrl;
@property (nonatomic) EngineRouteGuidanceTBTPosition* tbtListPos;
@property (nonatomic) NSInteger tbtListCount;
@property (nonatomic) NSInteger crossProgressBarLevel;
@property (nonatomic) NSInteger rgViaCount;
@property (nonatomic) NSInteger virtualPass;
@property (nonatomic) NSArray<NSNumber*>* hiPassList;
@property (nonatomic) EngineRouteGuidanceDrg* drgInfo;
@property (nonatomic) BOOL frontTrafficGuide;
@property (nonatomic) BOOL hasVmsInfo;
@property (nonatomic) NSInteger vmsId;
@property (nonatomic) NSInteger meshId;
@property (nonatomic) NSInteger linkId;
@property (nonatomic) NSInteger linkDirection;
@property (nonatomic) NSInteger currentLinkAngle;
@property (nonatomic) NSInteger nextLinkAngle;
@property (nonatomic) NSInteger mapVersion;
@property (nonatomic) EngineRouteGuidanceAlternativeRoute* alternativeRoute;
@property (nonatomic) BOOL isInServiceArea;
@property (nonatomic) NSInteger remainedLengthToEnd;
@property (nonatomic) NSInteger linkLenth;
@property (nonatomic) NSInteger currentRid;
@property (nonatomic) NSInteger goalOppositeVertex;
@property (nonatomic) NSInteger remainTollFee;
@property (nonatomic) NSInteger isChangeRecommandRoute;

@end

NS_ASSUME_NONNULL_END
