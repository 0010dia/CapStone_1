//
//  EngineTunnelInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/06/23.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// stEVStationInfo을 나타내기 위한

@interface EngineTunnelInfo : NSObject

@property (nonatomic) NSNumber* startLat;
@property (nonatomic) NSNumber* startLon;
@property (nonatomic) NSNumber* endLat;
@property (nonatomic) NSNumber* endLon;
@property (nonatomic) NSInteger tunnelLength;
@property (nonatomic) BOOL isTunnel;
@property (nonatomic) NSString* tunnelId;
@property (nonatomic) NSString* tunnelName;
@property (nonatomic) NSString* roadName;

@end

NS_ASSUME_NONNULL_END
