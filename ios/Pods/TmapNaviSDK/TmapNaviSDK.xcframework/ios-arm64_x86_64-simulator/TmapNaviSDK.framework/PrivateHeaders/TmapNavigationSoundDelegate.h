//
//  TmapNavigationSoundDelegate.h
//
//  Created by 1001921 on 2015. 4. 3..
//

#ifndef TmapNavigationSoundDelegate_h
#define TmapNavigationSoundDelegate_h

/**
 *  Engine Sound Play 관련 Delegate
 */
@protocol TmapNavigationSoundDelegate <NSObject>

/**	Sound 채널 Open
	
    @param singleChannel 단일채널 설정
    @param maxChannel    최대 채널
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundInit:(BOOL)singleChannel
          maxChannel:(NSInteger)maxChannel;

/**	Sound 채널 Close

    @param singleChannel singleChannel 유무
 
 */
- (void) onSoundRelease:(BOOL)singleChannel;

/**	Sound 정지

    @param singleChannel singleChannel 유무
    @param channel 채널
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundStop:(BOOL)singleChannel
             channel:(NSInteger)channel;

/**	Sound 일시정지

    @param singleChannel singleChannel 유무
    @param channel 채널
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundPause:(BOOL)singleChannel
              channel:(NSInteger)channel;

/**	Sound 정지해제

    @param singleChannel singleChannel 유무
    @param channel 채널
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundResume:(BOOL)singleChannel
               channel:(NSInteger)channel;

/**	Sound 재생

    @param singleChannel singleChannel 유무
    @param channel 채널
    @param waveData 음원 Data
    @param size 음원 Data size
    @param callback callback 유무
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundPlay:(BOOL)singleChannel
             channel:(NSInteger)channel
            waveData:(Byte* _Nullable)waveData
                size:(NSInteger)size
            callback:(BOOL)callback;

- (BOOL) onSoundPlay:(NSInteger)channel
          waveScript:(NSArray<NSString*>* _Nullable)waveScript
         speakerType:(NSInteger)speakerType
           audioType:(NSInteger)audioType
            callback:(BOOL)callback
           voiceType:(NSInteger)voiceType
            distance:(NSInteger)distance
         costTimeSec:(NSInteger)costTimeSec
         isMandatory:(BOOL)isMandatory;

/**	Sound 재생 여부

    @param singleChannel singleChannel 유무
    @param channel 채널
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundIsPlaying:(BOOL)singleChannel
                  channel:(NSInteger)channel;

/**	Sound 볼륨 변경

    @param singleChannel singleChannel 유무
    @param volume  볼륨 값
 
	@return 정상 처리 여부
 */
- (BOOL) onSoundSetVolume:(BOOL)singleChannel
                   volume:(NSInteger)volume;

@end

#endif
