//
//  TmapNavigationMMDebugger.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

#import <Foundation/Foundation.h>
#import "TmapNavigationMMDebuggerDelegate.h"

#define TmapNavigationMMDebuggerInstance [TmapNavigationMMDebugger sharedInstance]

@interface TmapNavigationMMDebugger : NSObject

@property (nonatomic, weak, setter = setMMDebuggerDelegate:) id<TmapNavigationMMDebuggerDelegate> mmDebuggerDelegate;

+ (TmapNavigationMMDebugger*) sharedInstance;

@end
