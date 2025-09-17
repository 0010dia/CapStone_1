//
//  EngineRouteThemeRoadInfo.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2022/05/13.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// stThemeRoadInfo을 나타내기 위한

@interface EngineRouteThemeRoadInfo : NSObject

@property (nonatomic) NSInteger vertexIndex;
@property (nonatomic) NSNumber* pointX;
@property (nonatomic) NSNumber* pointY;
@property (nonatomic) NSInteger type;
@property (nonatomic) NSInteger categoryType;
@property (nonatomic) NSString* themeRoadName;

@end

NS_ASSUME_NONNULL_END
