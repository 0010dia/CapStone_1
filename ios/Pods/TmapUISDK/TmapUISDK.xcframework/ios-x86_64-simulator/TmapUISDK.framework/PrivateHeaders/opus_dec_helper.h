#ifndef __OPUSDEC_H
#define __OPUSDEC_H

//#include "../libogg/include/ogg/ogg.h"
//#include "../libopus/include/opus_types.h"
#include "ogg.h"
#include "opus_types.h"

#ifdef __cplusplus
extern "C" {
#endif
int OpusDecodeToPCM(const opus_int16* inputBuf, const opus_int16 inputSize, opus_int16* outputBuf, int *outputBufSize);
int OpusDecodeFileToPCM(const char* inputFile, opus_int16* outputBuf, int *outputBufSize);
int OpusDecodeFileToWavFile(const char* inputFile, const char* outputFile);
#ifdef __cplusplus
}
#endif

#endif // __OPUSDEC_H
