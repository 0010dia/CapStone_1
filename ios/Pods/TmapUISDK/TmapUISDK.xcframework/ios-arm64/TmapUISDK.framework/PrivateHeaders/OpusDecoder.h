//
//  OpusDecoder.h
//  OPUS
//
//  Created by younggi.lee on 9/12/16.
//  Copyright © 2016 SK telecom. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface OpusDecoderM : NSObject

+ (NSData *)decode:(NSData *)opusData sampleRate:(NSUInteger)sampleRate;
+ (NSData *)decode:(NSData *)opusData sampleRate:(NSUInteger)sampleRate manualGain:(float)manualGain;

@end
