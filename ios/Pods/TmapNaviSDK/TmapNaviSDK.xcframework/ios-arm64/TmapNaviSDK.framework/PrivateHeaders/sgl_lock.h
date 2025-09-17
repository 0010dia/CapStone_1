// sgl_lock.h

#ifndef __SGL_LOCK_H
#define __SGL_LOCK_H

#include "sgl_basetype.h"
#include "sdl_legacy.h"

class CSglFunctionLock{
public:
	CSglFunctionLock(SGL_mutex* pLock) : _pLock(pLock){
		SGL_LockMutex(_pLock);
	};
	~CSglFunctionLock(){
		SGL_UnlockMutex(_pLock);
	};
public:
	operator Bool(){ return TRUE; };
	SGL_mutex* _pLock;
};

#define SGL_SYNCBLOCK(x)	\
	if(CSglFunctionLock(x))	\
							\

#endif // __SGL_LOCK_H
