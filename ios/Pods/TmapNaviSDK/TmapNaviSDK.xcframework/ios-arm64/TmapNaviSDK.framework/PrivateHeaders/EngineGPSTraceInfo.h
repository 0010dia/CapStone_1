//
//  EngineGPSTraceInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// TVASGPS_DATASET을 나타내기 위한

@interface EngineGPSTraceInfo : NSObject

@property (nonatomic) NSInteger uPosX;                            //X 좌표(경도: 정수8자리 SK정규화좌표)
@property (nonatomic) NSInteger uPosY;                            //Y 좌표(위도: 정수8자리 SK정규화좌표)
@property (nonatomic) NSInteger uTime;                            //GPS시각 (hhmmss.sss)
@property (nonatomic) NSInteger uAngle;                            //각도 (진북기준, 0~359)
@property (nonatomic) NSInteger uSpeed;                            //속도 (Km/h)
@property (nonatomic) NSInteger satelliteCnt;                    //위성수
@property (nonatomic) NSInteger provider;                    //측위방법 (0x01:측위불량, 0x02:fused, 0x03:gps, 0x04:tunnel algorithm)
@property (nonatomic) NSInteger accuracy;                    //정확도 meter
@property (nonatomic) NSInteger uMapMatchingCode;                //맵매칭 코드 (0없음 , 1성공, 2실패, 3음영지역, 4 이탈 방지, 5 SAP, 6 tunnel algorithm)
@property (nonatomic) NSInteger uMatPosX;                        //맵매칭 X 좌표(경도: 정수8자리 SK정규화좌표)
@property (nonatomic) NSInteger uMatPosY;                        //맵매칭 Y 좌표(위도: 정수8자리 SK정규화좌표)
@property (nonatomic) NSInteger uMatAngle;                        //각도 (진북기준, 0~359)
    /**
        Activiy type
        public static final int IN_VEHICLE = 0;
        public static final int ON_BICYCLE = 1;
        public static final int ON_FOOT = 2;
        public static final int STILL = 3;
        public static final int UNKNOWN = 4;
        public static final int TILTING = 5;
        public static final int WALKING = 7;
        public static final int RUNNING = 8;
    **/
@property (nonatomic) NSInteger activityType;            // Activity type
@property (nonatomic, copy) NSNumber* altitude;                // 고도.

@end

NS_ASSUME_NONNULL_END
