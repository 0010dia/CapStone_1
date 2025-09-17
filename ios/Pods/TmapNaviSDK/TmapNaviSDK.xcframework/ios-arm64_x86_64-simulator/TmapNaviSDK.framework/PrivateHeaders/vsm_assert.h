#ifndef VSMASSERT_H
#define VSMASSERT_H

#include "vsm_log.h"

#if(GDB_DEBUG == 1)
#define VSM_ASSERT(a) do { \
                            if(!(a)) { \
                                vsm_log_error("VSM_ASSERT(%s:%s:%d) ", __FILE__,__FUNCTION__,__LINE__);\
                                int* p = NULL; \
                                (*p) = 0; \
                            } \
                    } while(0) ;
#else
#define VSM_ASSERT(a) do { \
                            if(!(a)) \
                                vsm_log_error("VSM_ASSERT(%s:%s:%d) ", __FILE__,__FUNCTION__,__LINE__);\
                        } while(0) ;
#endif

#endif
