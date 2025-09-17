#ifndef MMRendererType_h
#define MMRendererType_h

#include "../include/common_struct.h"

struct Rectd
{
    double    x;
    double    y;
    double    w;
    double    h;
};

struct MMR_Point
{
    DOUBLE_VERTEX pos;
    float angle;
    unsigned int radius;
    unsigned int type;    // color type [0-4]
    bool valid;
};

struct MMR_Rect
{
    Rectd rect;
    unsigned int type;    // color type [0-4]
    bool valid;
};

struct MMR_Link
{
    unsigned int id;
    DOUBLE_VERTEX* vertices;
    unsigned int count;
    Rectd extent;
    unsigned int type;    // color type [0-4]
};

struct MMR_Network
{
    unsigned int id;
    MMR_Link* links;
    unsigned int count;
    Rectd extent;
};

#endif // MMRendererType_h
