//
//  TmapNavigationAudio.h
//
//  Created by 1001921 on 2015. 3. 24..
//

#import <Foundation/Foundation.h>
#import "TmapNavigationSoundDelegate.h"

#define TmapNavigationAudioInstance [TmapNavigationAudio sharedInstance]

typedef NS_ENUM(NSInteger, GuideDbMode)
{
    GuideDbModeNone = 0, //방면음성 미사용
    GuideDbModeDefault = 1, //방면음성 일반
    GuideDbModeTts = 2 //방면음성 TTS
};

@interface TmapNavigationAudio : NSObject

@property (nonatomic, weak, setter = setSoundDelegate:) id<TmapNavigationSoundDelegate> soundDelegate;

/**	TmapNavigationAudio 객체를 반환한다.
 */
+ (TmapNavigationAudio*) sharedInstance;

///**	시나리오 음성을 출력한다.  (비동기 함수)
//
//	@param nVoiceIndex Engine에서 출력할 음성 id, RGConstant.h의 NAVI_NeVoiceScenario 참조
//	@return 음성 실행 성공 여부
// */
//- (BOOL) soundPlayScenario:(int)nVoiceIndex;

@end
