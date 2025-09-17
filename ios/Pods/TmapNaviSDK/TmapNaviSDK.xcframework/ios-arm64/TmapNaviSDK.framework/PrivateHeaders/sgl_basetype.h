// sglbasetype.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 라이브러리에서 공통으로 사용할 타입 정의

#ifndef __SGL_BASETYPE_H
#define __SGL_BASETYPE_H

#if defined(_WIN32)
        #include "./win32/sgl_basetype_win32.h"
#elif defined(__MACOSX__)
    #include "./linux/sgl_basetype_linux.h"
    #include <dirent.h>
    #define _SGL_NEED_EXTENED_TYPE
#elif defined(_LINUX)
        #include "./linux/sgl_basetype_linux.h"
        #include <pthread.h>
    #include <dirent.h>
        #define _SGL_NEED_EXTENED_TYPE
#elif defined(__IPHONEOS__)
    #include "./linux/sgl_basetype_linux.h"
    #include <dirent.h>
#define _SGL_NEED_EXTENED_TYPE
#else
        #define _SGL_NEED_EXTENED_TYPE
#endif

#ifdef _WIN32_WCE
        #define __UNALIGNED		__unaligned
#else
#ifdef __ANDROID__
        #define __UNALIGNED		__packed
#else
        #define __UNALIGNED
#endif
#endif

#ifdef _VOLATILE_ENABLE_
#	define __VOLATILE		volatile
#else
#	define __VOLATILE
#endif

#include <limits.h>

#if UCHAR_MAX == 0xff

typedef signed char			Int8;
typedef unsigned char		UInt8;

#define SGL_MIN_INT8		SCHAR_MIN
#define SGL_MAX_INT8		SCHAR_MAX
#define SGL_MAX_UINT8		UCHAR_MAX

#else
#error This machine has no 8-bit type.
#endif // UCHAR_MAX == 0xff

#if UINT_MAX == 0xffff

typedef short			__UNALIGNED	Int16;
typedef unsigned short	__UNALIGNED	UInt16;

#define SGL_MIN_INT16		INT_MIN
#define SGL_MAX_INT16		INT_MAX
#define SGL_MAX_UINT16		UINT_MAX

#elif USHRT_MAX == 0xffff

typedef short			__UNALIGNED	Int16;
typedef unsigned short	__UNALIGNED	UInt16;

#define SGL_MIN_INT16		SHRT_MIN
#define SGL_MAX_INT16		SHRT_MAX
#define SGL_MAX_UINT16		USHRT_MAX

#else
#error This machine has no 16-bit type.
#endif // UINT_MAX == 0xffff

#if UINT_MAX == 0xfffffffful

typedef int				__UNALIGNED	Int32;
#ifndef __MACTYPES__
typedef unsigned int	__UNALIGNED	UInt32;
#endif
#define SGL_MIN_INT32		INT_MIN
#define SGL_MAX_INT32		INT_MAX
#define SGL_MAX_UINT32		UINT_MAX

#elif ULONG_MAX == 0xfffffffful

typedef long			__UNALIGNED	Int32;
typedef unsigned long	__UNALIGNED	UInt32;

#define SGL_MIN_INT32		LONG_MIN
#define SGL_MAX_INT32		LONG_MAX
#define SGL_MAX_UINT32		ULONG_MAX

#elif USHRT_MAX == 0xfffffffful

typedef short			__UNALIGNED	Int32;
typedef unsigned short	__UNALIGNED	UInt32;

#define SGL_MAX_INT32		SHRT_MAX
#define SGL_MIN_INT32		SHRT_MIN
#define SGL_MAX_UINT32		USHRT_MAX

#else
#error This machine has no 32-bit type.
#endif

#if ULONG_MAX == 0xfffffffffffffffful

#if defined(__APPLE__) && defined(__LP64__)
    typedef long long			Int64;
    typedef unsigned long long	UInt64;
#else
    typedef long				Int64;
    typedef unsigned long		UInt64;
#endif

#define _SGL_HAVE64

#elif defined(ULONG_LONG_MAX) || defined (ULLONG_MAX) || defined(ULONGLONG_MAX)		\
        || defined(__LONG_LONG_MAX__) || defined(_UI64_MAX)

#ifdef _WIN32
        typedef __int64				Int64;
        typedef unsigned __int64	UInt64;
#else
        typedef long long			Int64;
        typedef unsigned long long	UInt64;
#endif

#define _SGL_HAVE64

#else
#error This machine has no 64-bit type.
#endif


#if defined(__APPLE__) && defined(__LP64__)
typedef UInt64      UIntPtr_t;
#else
typedef UInt32		UIntPtr_t;
#endif


#ifdef _SGL_HAVE64

#define SGL_MIN_INT64		-9223372036854775808l
#define SGL_MAX_INT64		0x7fffffffffffffff
#define SGL_MAX_UINT64		0xfffffffffffffffful

#endif // _SGL_HAVE64

typedef Int8*				PInt8;
typedef UInt8*				PUInt8;
typedef Int16*				PInt16;
typedef UInt16*				PUInt16;
typedef Int32*				PInt32;
typedef UInt32*				PUInt32;
typedef Int64*				PInt64;
typedef UInt64*				PUInt64;

// Built-in type redefinition

typedef char				Char;
typedef unsigned char		UChar;
typedef short			__UNALIGNED	Short;
typedef unsigned short	__UNALIGNED	UShort;
typedef int				__UNALIGNED	Int;
typedef unsigned int	__UNALIGNED	UInt;
typedef long				Long;
typedef unsigned long		ULong;
typedef float			__VOLATILE Float;
typedef double				Double;

typedef float				Real;

typedef Char*				PChar;
typedef UChar*				PUChar;
typedef Short*				PShort;
typedef UShort*				PUShort;
typedef Int*				PInt;
typedef UInt*				PUInt;
typedef Long*				PLong;
typedef ULong*				PULong;

typedef void*				PVoid;

// BOOL type redefinition
#define	HAVE_Bool
#ifdef HAVE_Bool
        typedef int					Bool;
        typedef Bool*				PBool;
#endif

#ifdef _SGL_NEED_EXTENED_TYPE

// BYTE, WORD, DWROD type redefinition

typedef UInt8				Byte;
typedef UInt16				Word;
typedef UInt32				DWord;

typedef PUInt8				PByte;
typedef PUInt16				PWord;
typedef PUInt32				PDWord;

#ifndef _WIN32
        typedef Byte BYTE;
        typedef Word WORD;
        typedef DWord DWORD;
        typedef PByte PBYTE;
        typedef PWord PWORD;
        typedef PDWord PDWORD;
        typedef Long LONG;

        typedef Char CHAR;

        typedef signed char         INT8, *PINT8;
        typedef signed short        INT16, *PINT16;
        typedef signed int          INT32, *PINT32;
#ifndef __IPHONEOS__
        typedef unsigned char       UINT8, *PUINT8;
        typedef unsigned short      UINT16, *PUINT16;
        typedef unsigned int        UINT32, *PUINT32, UINT;
#endif
#endif

#endif // _SGL_NEED_EXTENED_TYPE

// Unicode char redefinition

#ifdef _UNICODE

typedef WChar				TChar;
typedef PWChar				PTChar;

#else

typedef Char				TChar;
typedef PChar				PTChar;

#endif // _UNICODE


#ifdef _WIN32
        typedef WIN32_FIND_DATA SGL_FIND_DATA;
        typedef HANDLE SGL_FIND_HANDLE;
#else
    typedef struct {
        struct dirent* _dirent;
        Bool _isDir;
    } SGL_FIND_DATA;

    typedef void* SGL_FIND_HANDLE;
#endif

#ifndef max
//#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
//#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

#define SGL_POINT DOUBLE_VERTEX

#endif // #define __SGL_BASETYPE_H
