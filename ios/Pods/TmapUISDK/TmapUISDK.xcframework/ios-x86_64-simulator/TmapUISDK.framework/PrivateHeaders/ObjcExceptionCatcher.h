//
//  ObjcExceptionCatcher.h
//  Tmap
//
//  Created by es.kim on 2022/03/25.
//  Copyright © 2022 TMAP MOBILITY. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ObjcExceptionCatcher : NSObject

+ (NSError * _Nullable)try:(void(^_Nonnull)(void))tryBlock;

@end

NS_ASSUME_NONNULL_END
