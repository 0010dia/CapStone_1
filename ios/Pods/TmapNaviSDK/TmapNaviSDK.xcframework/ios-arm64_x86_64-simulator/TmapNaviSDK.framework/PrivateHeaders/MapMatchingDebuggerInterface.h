#ifndef MapMatchingDebuggerInterface_H
#define MapMatchingDebuggerInterface_H

#include "MapMatchingDebugType.h"

class MapMatchingDebuggerInterface
{
public:
    virtual ~MapMatchingDebuggerInterface() {}

    virtual void AddMMData(const MMR_Point &gps, const MMR_Point &matchedPoint) = 0;
    virtual void ClearMMData() = 0;

    virtual void AddNetworkData(const MMR_Network &network) = 0;
    virtual void RemoveNetworkData(unsigned int id) = 0;
    virtual void UpdateLinkType(const unsigned int network_id, const unsigned int link_id, const unsigned int type) = 0;

    virtual void AddRectData(const MMR_Rect &rect) = 0;
    virtual void ClearRectData() = 0;
};

#endif
