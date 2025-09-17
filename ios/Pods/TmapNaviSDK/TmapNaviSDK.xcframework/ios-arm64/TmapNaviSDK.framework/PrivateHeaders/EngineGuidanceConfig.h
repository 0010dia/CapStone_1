//
//  EngineGuidanceConfig.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/16.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// tagRGConfig in rgdata_def.h

@interface EngineGuidanceConfig : NSObject

@property (nonatomic) NSInteger andoOverSpeedVoice; //( 0: 규정속도 초과시, 1: 규정속도+5%초과시, 2:규정속도+10%초과시 )

// 안전운전 표출
@property (nonatomic) NSArray<NSNumber*>* andoCameraType; // 카메라 항목 안내 설정 (size: ANDO_CAMERA_CNT)
@property (nonatomic) NSArray<NSNumber*>* andoEtcType; // 기타 안전운전 안내 (교통수집,일반통행,사고다발,급커브...) (size: ANDO_ETC_CNT)
@property (nonatomic) NSArray<NSNumber*>* andoDetailRouteType; // 상세 길안내 설정. (size: ANDO_DETAIL_CNT)
@property (nonatomic) NSInteger andoHighwayCameraDist; // 고속도로 안내 시작지점 (m단위)
@property (nonatomic) NSInteger andoNormalCameraDist; // 일반도로 안내 시작지점 (m단위)

// 기타 음성 시나리오
@property (nonatomic) BOOL guideGPSClock; // GPS시계 알림 기능

@end

NS_ASSUME_NONNULL_END
