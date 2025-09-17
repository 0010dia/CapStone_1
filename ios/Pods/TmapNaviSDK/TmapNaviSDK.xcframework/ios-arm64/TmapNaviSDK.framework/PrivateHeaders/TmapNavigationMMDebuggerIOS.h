//
//  TmapNavigationMMDebuggerIOS.h
//  TmapNaviSDK
//
//  Created by 김종일/서비스클라이언트개발 on 2023/01/03.
//

#ifndef TmapNavigationMMDebuggerIOS_h
#define TmapNavigationMMDebuggerIOS_h

#import <Foundation/Foundation.h>
#import "MapMatchingDebuggerInterface.h"
#import "EngineMMDebuggerRectd.h"
#import "EngineMMDebuggerVertex.h"
#import "EngineMMDebuggerMMRPoint.h"
#import "EngineMMDebuggerMMRRect.h"
#import "EngineMMDebuggerMMRLink.h"

class TmapNavigationMMDebuggerIOS : public MapMatchingDebuggerInterface {
private:
    TmapNavigationMMDebuggerIOS() {}
    ~TmapNavigationMMDebuggerIOS() {}
    EngineMMDebuggerVertex* convertVertex(const DOUBLE_VERTEX &vtx);
    EngineMMDebuggerRectd* convertRectD(const Rectd &rect);
    EngineMMDebuggerMMRPoint* convertMMR_Point(const MMR_Point &point);
    EngineMMDebuggerMMRLink* convertMMR_Link(const MMR_Link &link);
    
public:
    static TmapNavigationMMDebuggerIOS& getInstance() {
        static TmapNavigationMMDebuggerIOS _instance;
        return _instance;
    }
    
    virtual void AddMMData(const MMR_Point &gps, const MMR_Point &mm);
    virtual void ClearMMData();

    virtual void AddNetworkData(const MMR_Network &network);
    virtual void RemoveNetworkData(UInt32 id);
    virtual void UpdateLinkType(const UInt32 network_id, const UInt32 link_id, const UInt32 type);

    virtual void AddRectData(const MMR_Rect &rect);
    virtual void ClearRectData();

};


#endif /* TmapNavigationMMDebuggerIOS_h */
