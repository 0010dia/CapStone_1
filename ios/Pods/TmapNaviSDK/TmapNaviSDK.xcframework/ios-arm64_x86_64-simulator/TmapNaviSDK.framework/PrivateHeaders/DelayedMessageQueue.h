//
//  DelayedMessageQueue.h
//  MapEngine
//
//  Created by hyunyong.kim@sk.com on 2015. 4. 13..
//
//

#ifndef MapEngine_DelayedMessageQueue_h
#define MapEngine_DelayedMessageQueue_h

#include <chrono>
#include <condition_variable>
#include <mutex>
#include "sgl_base.h"
#include "RefCntObj.h"

class DelayedMessageQueue;
class AtomicSpinLock;

class DelayedMessage {
public:
    using Clock = std::chrono::steady_clock;

    DelayedMessage() : what(0), wParam(0), lParam(0), obj(NULL), next(NULL) { }
    virtual ~DelayedMessage() {
        if (obj) {
            obj->unref();
        }
    }
    
    Int32 what;
    std::chrono::time_point<Clock> when;
    Int32 wParam;
    Long lParam;
    RefCntObj* obj;
    
protected:
    virtual void recycled() {
        what = 0;
        wParam = 0;
        lParam = 0;
        if (obj) {
            obj->unref();
            obj = NULL;
        }
    }

    DelayedMessage* next;

    friend class DelayedMessageQueue;
};

class DelayedMessageQueue {
public:
    DelayedMessageQueue();
    virtual ~DelayedMessageQueue();
    
    DelayedMessage* next();
    Bool sendEmptyMessage(Int32 what) { return sendMessage(what, 0, 0); }
    Bool sendMessage(Int32 what, Int32 wParam, Long lParam) { return sendMessageDelayed(what, wParam, lParam, 0); }
    Bool sendMessageDelayed(Int32 what, Int32 wParam, Long lParam, UInt32 delay);
    Bool sendMessage(Int32 what, RefCntObj* obj) { return sendMessageDelayed(what, obj, 0); }
    Bool sendMessageDelayed(Int32 what, RefCntObj* obj, UInt32 delay);
    Bool sendMessageAtFront(Int32 what, Int32 wParam, Long lParam);
    Bool sendMessageAtFront(Int32 what, RefCntObj* obj);
    Bool removeMessages(Int32 what);
    Bool removeMessages(Int32 what, RefCntObj* obj);
    void recycleMessage(DelayedMessage* p);
    void quit();

protected:
    virtual DelayedMessage* newMessage() { return new DelayedMessage(); }
    
private:
    Bool enqueueMessage(DelayedMessage* msg, std::chrono::time_point<DelayedMessage::Clock> when);
    DelayedMessage* obtainMessage();
    void removeFutureMessagesLocked();
    void removeAllMessagesLocked();
    
private:
    bool        m_closed;
    bool        m_blocked;
    DelayedMessage* m_messages;
    DelayedMessage* m_pool;
    AtomicSpinLock* m_poolLock;
    int         m_poolSize;

    std::mutex  m_lock;
    std::condition_variable m_cond;
};

#endif
