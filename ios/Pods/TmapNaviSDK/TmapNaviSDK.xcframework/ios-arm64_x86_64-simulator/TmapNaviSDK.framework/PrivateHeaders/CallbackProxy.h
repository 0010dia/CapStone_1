//
//  CallbackProxy.h
//  NaviModule
//
//  Created by hyunyong.kim@sk.com on 2015. 6. 8..
//
//

#ifndef __NaviModule__CallbackProxy__
#define __NaviModule__CallbackProxy__

#include "interface_def.h"

class CallbackProxy
{
public:
    virtual ~CallbackProxy() {}
    
    // callbacks
    virtual void onRemoteUpdateStart() = 0;
    virtual void onRemoteUpdateProgress() = 0;
    virtual void onRemoteUpdateDone() = 0;
    virtual void onRemoteUpdateError(eInitEngineResult error) = 0;

    virtual void onResourceLoadingStart() = 0;
    virtual void onResourceLoadingProgress() = 0;
    virtual void onResourceLoadingDone() = 0;
    virtual void onResourceLoadingError(eResourceLoadingResult error) = 0;
    
    virtual void onLoadBaseResourcesStarted() = 0;
    virtual void onLoadBaseResourcesProgress(UInt32 count, UInt32 total) = 0;
    virtual void onLoadBaseResourcesProgressSize(UInt32 downloadedSize, UInt32 totalSize) = 0;
    virtual void onLoadBaseResourcesCompleted() = 0;
    virtual void onLoadBaseResourcesFailed(Int32 error) = 0;
    virtual void onLoadBaseResourcesConfirm(UInt32 total, UInt32 totalSize) = 0;
    
    virtual void onLoadSubResourcesStarted() = 0;
    virtual void onLoadSubResourcesProgress(UInt32 count, UInt32 total) = 0;
    virtual void onLoadSubResourcesProgressSize(UInt32 downloadedSize, UInt32 totalSize) = 0;
    virtual void onLoadSubResourcesCompleted() = 0;
    virtual void onLoadSubResourcesFailed(Int32 error) = 0;
};

#endif /* defined(__NaviModule__CallbackProxy__) */
