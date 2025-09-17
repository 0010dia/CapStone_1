// sgl_runtimeenv.h

#ifndef __SGL_RUNTIMEENV_H
#define __SGL_RUNTIMEENV_H

#include "sgl.h"

class CSglRuntimeEnv
{
	NOT_COPYABLE(CSglRuntimeEnv)

private:
	CSglRuntimeEnv();
	virtual ~CSglRuntimeEnv();

public:

protected:

	DECLARE_SINGLETON(CSglRuntimeEnv);
};

#endif // __SGL_RUNTIMEENV_H
