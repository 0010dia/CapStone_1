

#ifndef	_OPUS_DECODE_H
#define	_OPUS_DECODE_H

#ifdef __cplusplus
extern "C" {
#endif
    unsigned char *opus_decode_to_wav(unsigned char*opusBytes, long opusBytesSize, long *decodedBytesSize, int sampleRate, float manualGain);
    
#ifdef __cplusplus
}  /* extern "C" */
#endif

#endif	/* OPUS_H */
