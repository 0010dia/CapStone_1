//
//  RefCntObj.h
//  HttpClient
//
//  Created by hyunyong.kim@sk.com on 2015. 3. 6..
//
//

#ifndef __HttpClient__RefCntObj__
#define __HttpClient__RefCntObj__

#include <atomic>

// thread-safe version
class RefCntObj
{
public:
    RefCntObj() : m_ref(1) {

    }

    virtual ~RefCntObj() {

    }
    
    int getRefCnt() const {
        return m_ref.load();
    }

    void ref() const {
        m_ref.fetch_add(1);
    }

    void unref() const {
        if (m_ref.fetch_sub(1) == 1) {
            delete this;
        }
    }

private:
    mutable std::atomic_int m_ref;
    
    // noncopyable
private:
    RefCntObj(const RefCntObj&);
    RefCntObj& operator=(const RefCntObj&);
};

#endif /* defined(__HttpClient__RefCntObj__) */
