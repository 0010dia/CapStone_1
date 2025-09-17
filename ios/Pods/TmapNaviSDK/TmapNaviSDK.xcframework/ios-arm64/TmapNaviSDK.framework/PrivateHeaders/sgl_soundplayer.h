#ifndef __SGL_SOUNDPLAYER_H_
#define __SGL_SOUNDPLAYER_H_

#include <vector>
#include "sgl_base.h"
#include "sgl_soundbase.h"

class CSglSoundPlayer  
{
	NOT_COPYABLE(CSglSoundPlayer)
private:
	CSglSoundPlayer();
	virtual ~CSglSoundPlayer();

public:

	// 안드로이드 사운드 콜백 설정한다.
#ifdef __ANDROID__
	void InitAndroidCallback(PANDROID_SOUND_CALLBACK lpfnCallback);
#endif

	/// 사운드 채널을 초기화 한다. (싱글 채널(멀티 포멧) 1개와 멀티 채널(싱글 포멧) N개가 생성된다.)
	/**
		@param nChannel			[IN] 멀티 채널 개수 (최대 MAX_SOUND_CHANNEL_CNT 설정 가능)
		@param lpfnCallback		[IN] 음성 출력 상태를 받을 콜백 합수
		@return					TRUE:성공, FALSE:실패
	**/
	Bool Init(Int32 nChannel, LPCALL_SOUNDEVENT lpfnCallback=NULL);

	/// 모든 사운드 채널을 해제 한다.
	/**
		@return
	**/
	void Release();

	/// 사운드 버퍼를 재생한다.
	/**
		@param nChannel			[IN] 재생할 채널 (-1 이면 싱글 채널)
		@param pWave			[IN] 사운드 버퍼 포인트
		@param nSize			[IN] 사운드 버퍼 크기
		@param bEvent			[IN] 재생 상태 콜백 받을지 여부
		@return					TRUE:성공, FALSE:실패 (재생중 이면 실패)
	**/
	Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Bool bEvent=FALSE, Int32 voice_type = 0, Int32 distance = 0, Int32 cost_time_sec = 0, Bool isMandatory = FALSE);
	Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, UInt32 nWavId, Bool bEvent=FALSE, Int32 voice_type = 0, Int32 distance = 0, Int32 cost_time_sec = 0, Bool isMandatory = FALSE);

	void SetAudioLog(Char* pszName);

	/// 사운드 재생중 인지 체크 한다.
	/**
		@param nChannel			[IN] 체크할 채널 (-1 이면 싱글 채널)
		@return					TRUE:재생중, FALSE:유휴상태
	**/
	Bool IsPlaying(Int32 nChannel=-1);

	/// 사운드 재생을 중지 한다.
	/**
		@param nChannel			[IN] 체크할 채널 (-1 이면 싱글 채널)
		@return
	**/
	void Stop(Int32 nChannel=-1);

	/// 사운드 재생을 일시 중지 한다.
	/**
		@param nChannel			[IN] 체크할 채널 (-1 이면 싱글 채널)
		@return
	**/
	void Pause(Int32 nChannel=-1);

	/// 사운드 재생을 다시 한다.
	/**
		@param nChannel			[IN] 체크할 채널 (-1 이면 싱글 채널)
		@return
	**/
	void Resume(Int32 nChannel=-1);

	/// 사운드 재생 볼륨을 설정한다.
	/**
		@param bSingile			[IN] 채널 타입 선택 (TRUE:싱글 채널, FALSE:멀티 채널)
		@param dwVolume			[IN] 볼륨값
									 Win32 싱글채널 : 단말별 고유값
									       멀티채널 : 0~100
		@return
	**/
	Bool SetVolume(Bool bSingile, DWord dwVolume);

private:
	CSglSoundBase *m_pSoundSingile;					// 싱글 채널용 Sound 플레이 객체
	CSglSoundBase *m_pSoundMulti;					// 멀티 채널용 Sound 플레이 객체

#ifdef __ANDROID__
	ANDROID_SOUND_CALLBACK		m_AndroidCallback;
#endif

	DECLARE_SINGLETON(CSglSoundPlayer);
};

#endif //__SGL_SOUNDPLAYER_H_
