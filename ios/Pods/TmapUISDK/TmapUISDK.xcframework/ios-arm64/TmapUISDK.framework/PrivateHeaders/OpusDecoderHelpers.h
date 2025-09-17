//
//  OpusDecoderHelper.h
//  SGL
//
//  Created by 1002459 on 2016. 4. 22..
//
//

#ifndef OpusDecoderHelpers_h
#define OpusDecoderHelpers_h

#include <vector>
#include "../libogg/include/ogg/ogg.h"
#include "../libopus/include/opus_types.h"

class OpusDecoderHelpers {
public:
    OpusDecoderHelpers();
    ~OpusDecoderHelpers();

    int decode(int sampleRate, const opus_int16* inputBuf, const opus_int32 inputSize, float manual_gain,
               std::vector<opus_int16>* outputBuf);
    
private:
    opus_int16* m_pcmBuf;

};
#endif /* OpusDecoderHelper_h */
