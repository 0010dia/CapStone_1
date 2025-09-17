//
//  OpusDecoderHelper.h
//  SGL
//
//  Created by 1002459 on 2016. 4. 22..
//
//

#ifndef OpusDecoderHelper_h
#define OpusDecoderHelper_h

#include <vector>
#include "../libogg/include/ogg/ogg.h"
#include "../libopus/include/opus_types.h"

class OpusDecoderHelper {
public:
    OpusDecoderHelper();
    ~OpusDecoderHelper();

    int decode(int sampleRate, const opus_int16* inputBuf, const opus_int32 inputSize,
               std::vector<Int16>* outputBuf);
    
};
#endif /* OpusDecoderHelper_h */
