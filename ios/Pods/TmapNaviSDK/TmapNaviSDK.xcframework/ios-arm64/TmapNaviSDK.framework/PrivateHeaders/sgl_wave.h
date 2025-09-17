#ifndef __SGL_WAVE_H_
#define __SGL_WAVE_H_

#include "sgl_base.h"
#include "sgl_soundbase.h"

//single channel
class CSglWave : public CSglSoundBase
{
public:
	CSglWave();
	virtual ~CSglWave();
public:
    LPCALL_SOUNDEVENT SoundEvent;
	Bool Init(Int32 nMaxChannel, LPCALL_SOUNDEVENT lpfnCallback);
	void Release();
	Bool Play(Int32 nChannel, Int32 nAudioType, Byte *pWave, Int32 nSize, Bool bCallback=FALSE, Int32 voice_type = 0, Int32 distance = 0, Int32 cost_time_sec = 0);
    Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, Bool bCallback, Int32 voice_type, Int32 distance, Int32 cost_time_sec, Bool isMandatory);
    void SetAudioLog(Char* pszName);
	Bool IsPlaying(Int32 nChannel);
	Bool Stop(Int32 nChannel);
	Bool Pause(Int32 nChannel);
	Bool Resume(Int32 nChannel);
	Bool SetVolume(DWord dwVolume);


};


// multi channels
class CSglWaves : public CSglSoundBase
{
public:
	CSglWaves();
	virtual ~CSglWaves();
public:
    LPCALL_SOUNDEVENT SoundEvent;
	Bool Init(Int32 nMaxChannel, LPCALL_SOUNDEVENT lpfnCallback);
	void Release();
	Bool Play(Int32 nChannel, Int32 nAudioType, Byte *pWave, Int32 nSize, Bool bCallback=FALSE, Int32 voice_type = 0, Int32 distance = 0, Int32 cost_time_sec = 0);
    Bool Play(Int32 nChannel, std::vector<std::string> &m_arWaveScript, Int32 speakerType, Int32 nAudioType, Bool bCallback, Int32 voice_type, Int32 distance, Int32 cost_time_sec, Bool isMandatory);
    void SetAudioLog(Char* pszName);
	Bool IsPlaying(Int32 nChannel);
	Bool Stop(Int32 nChannel);
	Bool Pause(Int32 nChannel);
	Bool Resume(Int32 nChannel);
	Bool SetVolume(DWord dwVolume);
    
    
};
#endif //__SGL_WAVE_H_/Volumes/Data/SKT/Sources/tmap4-iphone/Tmap4/Tmap4/Classes/Manager/Tmap4SoundManager.m
