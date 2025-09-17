#ifndef __SGL_SOUNDBASE_H_
#define __SGL_SOUNDBASE_H_

#include "sgl_base.h"
#include <vector>

#define MAX_SOUND_CHANNEL_CNT	5	// 사운드 채널 최대 개수

#define AUDIO_TYPE_DEFAULT      0
#define AUDIO_TYPE_CAMERA       1

enum NeSoundStatus
{
	eSoundStart = 0,	// 음성 출력 시작
	eSoundPause,		// 음성 일시 중지
	eSoundResume,		// 음성 다시 시작
	eSoundEnd,			// 음성 출력 완료
};

// Sound 이벤트 Callback 함수 포인터
typedef void (*LPCALL_SOUNDEVENT)(Int32 nChannel, NeSoundStatus eStatus);

// 안드로이드 Callback 함수 정의
#ifdef __ANDROID__
////////////////////////////////////////////////////////////////////
typedef Bool (*LPCALL_InitAudioTrack)();
typedef void (*LPCALL_ReleaseAudioTrack)();
typedef Bool (*LPCALL_PlayAudioTrack)(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, Int32 voice_type, Int32 distance, Int32 cost_time_sec, Bool isMandatory);
typedef Bool (*LPCALL_StopAudioTrack)(Int32 nChannel);
typedef Bool (*LPCALL_PauseAudioTrack)(Int32 nChannel);
typedef Bool (*LPCALL_ResumeAudioTrack)(Int32 nChannel);
typedef Bool (*LPCALL_IsAudioTrackPlaying)(Int32 nChannel);
typedef Bool (*LPCALL_SetAudioTrackVolume)(UInt32 volume);
typedef void (*LPCALL_SendAudioLog)(Char *pszName);

typedef struct tagAndroidSoundCallback
{
	LPCALL_InitAudioTrack		pfnInitAudioTrack;
	LPCALL_ReleaseAudioTrack	pfnReleaseAudioTrack;
	LPCALL_PlayAudioTrack		pfnPlayAudioTrack;
	LPCALL_StopAudioTrack		pfnStopAudioTrack;
	LPCALL_PauseAudioTrack		pfnPauseAudioTrack;
	LPCALL_ResumeAudioTrack		pfnResumeAudioTrack;
	LPCALL_IsAudioTrackPlaying	pfnIsAudioTrackPlaying;
	LPCALL_SetAudioTrackVolume	pfnSetAudioTrackVolume;
	LPCALL_SendAudioLog			pfnSendAudioLog;
}ANDROID_SOUND_CALLBACK, *PANDROID_SOUND_CALLBACK;
////////////////////////////////////////////////////////////////////
#endif

class CSglSoundBase
{
public:

	CSglSoundBase() {};
	virtual ~CSglSoundBase() {};

public:

	// 사운드 채널을 초기화 한다.
#ifdef __ANDROID__
	virtual void InitAndroidCallback(PANDROID_SOUND_CALLBACK lpfnCallback) {};
#endif

	// 사운드 채널을 초기화 한다.
	virtual Bool Init(Int32 nChannel, LPCALL_SOUNDEVENT lpfnCallback) = 0;

	// 모든 사운드 채널을 해제 한다.
	virtual void Release() = 0;	

	// 사운드 버퍼를 재생한다.
    virtual Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, UInt32 nWavId, Bool bCallback, Int32 voice_type, Int32 distance, Int32 cost_time_sec, Bool isMandatory) {
        (void)nWavId;
        return Play(nChannel, m_arWaveScript, speakerType, nAudioType, bCallback, voice_type, distance, cost_time_sec, isMandatory);
    }

    virtual Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, Bool bCallback, Int32 voice_type, Int32 distance, Int32 cost_time_sec, Bool isMandatory) = 0;

    // 재생할 음성 로그를 전송한다.
    virtual void SetAudioLog(Char* pszName) = 0;

    /// 사운드 재생중 인지 체크 한다.
	virtual Bool IsPlaying(Int32 nChannel) = 0;

	/// 사운드 재생을 중지 한다.
	virtual Bool Stop(Int32 nChannel) = 0;

	/// 사운드 재생을 일시 중지 한다.
	virtual Bool Pause(Int32 nChannel) = 0;

	/// 사운드 재생을 다시 한다.
	virtual Bool Resume(Int32 nChannel) = 0;

	/// 사운드 재생 볼륨을 설정한다.
	virtual Bool SetVolume(DWord dwVolume) = 0;

protected:
	Bool m_bSingleChannel;

};

#endif //__SGL_SOUNDBASE_H_
