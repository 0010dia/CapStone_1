// sgl.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : SGL(Speedy Good Library) 라이브러리 메인 헤더

#ifndef __SGL_MINIMUM_H
#define __SGL_MINIMUM_H

#ifdef __ANDROID__
	#include <android/log.h>
#endif


#include "../src/base/sgl_config_def.h"
#include "../src/base/sgl_config.h"
#include "../src/base/sgl_basetype.h"
#include "../src/base/sgl_basedef.h"
#include "../src/base/sgl_const.h"
#include "../src/base/sgl_debug.h"
#include "../src/base/sgl_malloc.h"
#include "../src/base/sgl_endian.h"
#include "../src/base/sgl_macro.h"
#include "../src/base/sgl_error.h"
#include "../src/base/sgl_stdlib.h"
#include "../src/base/sgl_chkmemleak.h"
#include "../src/common/sgl_cmntype.h"
#include "../src/common/sgl_time.h"

#include "../src/common/sgl_array.h"

#include "../src/gps/gpsdef.h"

#include "../src/math/sgl_degmath.h"
#include "../src/math/sgl_stdmath.h"
#include "../src/sgl_init.h"

#include "../src/base/sdl_legacy.h"

#endif // __SGL_MINIMUM_H
