#ifndef VSM_LOG_H
#define VSM_LOG_H

#include <stdarg.h>

#define VSM_LOG_DEFAULT_LOGTAG  "VSM"

typedef enum {
    VSM_LOG_ERROR = 0,
    VSM_LOG_WARN = 1,
    VSM_LOG_INFO = 2,
    VSM_LOG_DEBUG = 3,
    VSM_LOG_VERBOSE = 4
} VSM_LogLevel;

typedef void (*VSM_LogHandler)(int, const char*, const char*);

void VsmLog_installLogHandler(VSM_LogHandler);

// check if build log level is defined
#if defined(BUILD_LOG_LEVEL_VERBOSE) || defined(BUILD_LOG_LEVEL_DEBUG) || defined(BUILD_LOG_LEVEL_INFO) || defined(BUILD_LOG_LEVEL_WARNING) || defined(BUILD_LOG_LEVEL_ERROR)
#define HAVE_BUILD_LOG_LEVEL
#endif

#ifndef HAVE_BUILD_LOG_LEVEL
#if defined(DEBUG) || defined(_DEBUG) || defined(__DEBUG__) || defined(_NATIVE_DEBUG_PRINT)
// if this build mode is 'debug', enable all log level by default
#define BUILD_LOG_LEVEL_VERBOSE
#else
#define BUILD_LOG_LEVEL_ERROR
#endif
#endif // HAVE_BUILD_LOG_LEVEL

#ifdef BUILD_LOG_LEVEL_VERBOSE
#define ENABLE_LOG_ERROR
#define ENABLE_LOG_WARNING
#define ENABLE_LOG_INFO
#define ENABLE_LOG_DEBUG
#define ENABLE_LOG_VERBOSE
#elif defined(BUILD_LOG_LEVEL_DEBUG)
#define ENABLE_LOG_ERROR
#define ENABLE_LOG_WARNING
#define ENABLE_LOG_INFO
#define ENABLE_LOG_DEBUG
#elif defined(BUILD_LOG_LEVEL_INFO)
#define ENABLE_LOG_ERROR
#define ENABLE_LOG_WARNING
#define ENABLE_LOG_INFO
#elif defined(BUILD_LOG_LEVEL_WARNING)
#define ENABLE_LOG_ERROR
#define ENABLE_LOG_WARNING
#elif defined(BUILD_LOG_LEVEL_ERROR)
#define ENABLE_LOG_ERROR
#endif // BUILD_LOG_LEVEL_DEBUG

void VsmLog_setEnable(Bool enable);
Bool VsmLog_getEnable(void);
void VsmLog_setLogLevel(VSM_LogLevel logLevel);
VSM_LogLevel VsmLog_getLogLevel(void);
void VsmLog_vprintf(VSM_LogLevel logLevel, const Char* tag, const Char* format, va_list args);
void VsmLog_printf(VSM_LogLevel logLevel, const Char* tag, const Char* format, ...);
void VsmLog_getCurrentTime(char* buff);

#define VA_LIST_CONTEXT(last, i) \
	{ va_list args; va_start(args, last); i; va_end(args); }

#ifdef ENABLE_LOG_ERROR
inline void vsm_log_error_t(const char* log_tag, const char* format, ...) {
	VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_ERROR, log_tag, format, args));
}
inline void vsm_log_error(const char* format, ...) {
	VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_ERROR, VSM_LOG_DEFAULT_LOGTAG, format, args));
}
#else
inline void vsm_log_error_t(const char* log_tag, const char* format, ...) {}
inline void vsm_log_error(const char* format, ...) {}
#endif

#ifdef ENABLE_LOG_WARNING
inline void vsm_log_warn_t(const char* log_tag, const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_WARN, log_tag, format, args));
}
inline void vsm_log_warn(const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_WARN, VSM_LOG_DEFAULT_LOGTAG, format, args));
}
#else
inline void vsm_log_warn_t(const char* log_tag, const char* format, ...) {}
inline void vsm_log_warn(const char* format, ...) {}
#endif

#ifdef ENABLE_LOG_INFO
inline void vsm_log_info_t(const char* log_tag, const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_INFO, log_tag, format, args));
}
inline void vsm_log_info(const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_INFO, VSM_LOG_DEFAULT_LOGTAG, format, args));
}
#else
inline void vsm_log_info_t(const char* log_tag, const char* format, ...) {}
inline void vsm_log_info(const char* format, ...) {}
#endif

#ifdef ENABLE_LOG_DEBUG
inline void vsm_log_debug_t(const char* log_tag, const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_DEBUG, log_tag, format, args));
}
inline void vsm_log_debug(const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_DEBUG, VSM_LOG_DEFAULT_LOGTAG, format, args));
}
#else
inline void vsm_log_debug_t(const char* log_tag, const char* format, ...) {}
inline void vsm_log_debug(const char* format, ...) {}
#endif

#ifdef ENABLE_LOG_VERBOSE
inline void vsm_log_verbose_t(const char* log_tag, const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_VERBOSE, log_tag, format, args));
}
inline void vsm_log_verbose(const char* format, ...) {
    VA_LIST_CONTEXT(format, VsmLog_vprintf(VSM_LOG_VERBOSE, VSM_LOG_DEFAULT_LOGTAG, format, args));
}
#else
inline void vsm_log_verbose_t(const char* log_tag, const char* format, ...) {}
inline void vsm_log_verbose(const char* format, ...) {}
#endif

#define SRC_FILENAME (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define LOG_TIME_BUFF_MAX_LENGTH    80

#ifdef ENABLE_LOG_VERBOSE
#define log_verbose(fmt, ...) 	\
    do { \
        char _timeBuff[LOG_TIME_BUFF_MAX_LENGTH]; \
        VsmLog_getCurrentTime(_timeBuff); \
        vsm_log_verbose_t(VSM_LOG_DEFAULT_LOGTAG, "[%s][%s][%s:%d] " fmt, _timeBuff, SRC_FILENAME, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while(0)
#else
#define log_verbose(fmt, ...)
#endif

#ifdef ENABLE_LOG_DEBUG
#define log_debug(fmt, ...) 	\
    do { \
        char _timeBuff[LOG_TIME_BUFF_MAX_LENGTH]; \
        VsmLog_getCurrentTime(_timeBuff); \
        vsm_log_debug_t(VSM_LOG_DEFAULT_LOGTAG, "[%s][%s][%s:%d] " fmt, _timeBuff, SRC_FILENAME, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while(0)
#else
#define log_debug(fmt, ...)
#endif

#ifdef ENABLE_LOG_INFO
#define log_info(fmt, ...) 		\
    do { \
        char _timeBuff[LOG_TIME_BUFF_MAX_LENGTH]; \
        VsmLog_getCurrentTime(_timeBuff); \
        vsm_log_info_t(VSM_LOG_DEFAULT_LOGTAG, "[%s][%s][%s:%d] " fmt, _timeBuff, SRC_FILENAME, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while(0)
#else
#define log_info(fmt, ...)
#endif

#ifdef ENABLE_LOG_WARNING
#define log_warn(fmt, ...) 		\
    do { \
        char _timeBuff[LOG_TIME_BUFF_MAX_LENGTH]; \
        VsmLog_getCurrentTime(_timeBuff); \
        vsm_log_warn_t(VSM_LOG_DEFAULT_LOGTAG, "[%s][%s][%s:%d] " fmt, _timeBuff, SRC_FILENAME, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while(0)
#else
#define log_warn(fmt, ...)
#endif

#ifdef ENABLE_LOG_ERROR
#define log_error(fmt, ...) 	\
    do { \
        char _timeBuff[LOG_TIME_BUFF_MAX_LENGTH]; \
        VsmLog_getCurrentTime(_timeBuff); \
        vsm_log_error_t(VSM_LOG_DEFAULT_LOGTAG, "[%s][%s][%s:%d] " fmt, _timeBuff, SRC_FILENAME, __FUNCTION__, __LINE__, ##__VA_ARGS__); \
    } while(0)
#else
#define log_error(fmt, ...)
#endif

#endif	// VSM_LOG_H
