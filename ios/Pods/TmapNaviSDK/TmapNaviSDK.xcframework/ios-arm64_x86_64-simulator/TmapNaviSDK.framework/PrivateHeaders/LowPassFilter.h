//
// Created by Sangjin Yun on 2016. 11. 2..
//

#ifndef GIT_ANDROID_TMAP_MAIN_LOWPASSFILTER_H
#define GIT_ANDROID_TMAP_MAIN_LOWPASSFILTER_H

#include "sgl_inc.h"
#include "rgdata_inc.h"

#define MAX_DATA_COUNT 10

class LowPassFilter {
public:
    LowPassFilter();

    void addLocation(DOUBLE_VERTEX wp, float accuracy, long long time, int activityType);
    DOUBLE_VERTEX& getNewLocation();
    Bool getBearingAndVelocity(float& bearing, float& velocity, long long& timeDiff);
    Bool correction(DOUBLE_VERTEX wp, Int32 angle);

private:
    void setData(float x, float y, long long time);

    DOUBLE_VERTEX lastWp[MAX_DATA_COUNT]; // 10초동안 평균속도를 구한다.
    long long timeStamp[MAX_DATA_COUNT]; // 10초동안 평균속도를 구한다.
    float angle;
    float velocityKmPerHour;

    int locationCount;
    int tailIndex;
    int headIndex;

    int lastBearing;
    float lastVelocity;
};


#endif //GIT_ANDROID_TMAP_MAIN_LOWPASSFILTER_H
