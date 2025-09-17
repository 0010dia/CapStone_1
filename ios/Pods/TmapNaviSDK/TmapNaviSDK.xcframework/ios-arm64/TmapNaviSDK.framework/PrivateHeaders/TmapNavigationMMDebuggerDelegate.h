//
//  TmapNavigationMMDebuggerDelegate.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

#ifndef TmapNavigationMMDebuggerDelegate_h
#define TmapNavigationMMDebuggerDelegate_h

#import "EngineMMDebuggerMMRPoint.h"
#import "EngineMMDebuggerMMRRect.h"
#import "EngineMMDebuggerMMRLink.h"
#import "EngineMMDebuggerMMRNetwork.h"

/**
 *  MapMatch debugging을 위한 Delegate
 */
@protocol TmapNavigationMMDebuggerDelegate <NSObject>

- (void) addMMData:(EngineMMDebuggerMMRPoint*)gps
          mmPoint:(EngineMMDebuggerMMRPoint*)mm;

- (void) clearMMData;

- (void) addNetworkData:(EngineMMDebuggerMMRNetwork*)network;

- (void) removeNetworkData:(NSInteger)id;

- (void) updateLinkType:(NSInteger)networkId
                 linkId:(NSInteger)linkId
                   type:(NSInteger)type;

- (void) addRectData:(EngineMMDebuggerMMRRect*)rect;

- (void) clearRectData;

@end
#endif /* TmapNavigationMMDebuggerDelegate_h */
