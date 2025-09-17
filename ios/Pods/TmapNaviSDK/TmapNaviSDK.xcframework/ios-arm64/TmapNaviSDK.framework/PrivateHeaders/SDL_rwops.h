/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2012 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/

/**
 *  \file SDL_rwops.h
 *  
 *  This file provides a general interface for SDL to read and write
 *  data streams.  It can easily be extended to files, memory, etc.
 */

#ifndef _SDL_rwops_h
#define _SDL_rwops_h

#include <stddef.h>
#include "../base/sgl_basetype.h"
#include "../include/sgl_begin_code.h"

#ifndef HAVE_STDIO_H
#define HAVE_STDIO_H 1
#endif

#ifdef HAVE_STDIO_H
#include <stdio.h>
#endif

/* By default SDL uses the C calling convention */
#ifndef SDLCALL
#if defined(__WIN32__) && !defined(__GNUC__)
#define SDLCALL __cdecl
#else
#define SDLCALL
#endif
#endif /* SDLCALL */

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
extern "C" {
/* *INDENT-ON* */
#endif

/**
 * This is the read/write operation structure -- very basic.
 */
typedef struct SDL_RWops
{
    /**
     *  Seek to \c offset relative to \c whence, one of stdio's whence values:
     *  RW_SEEK_SET, RW_SEEK_CUR, RW_SEEK_END
     *  
     *  \return the final offset in the data stream.
     */
    long (SDLCALL * seek) (struct SDL_RWops * context, long offset,
                           int whence);

    /**
     *  Read up to \c maxnum objects each of size \c size from the data
     *  stream to the area pointed at by \c ptr.
     *  
     *  \return the number of objects read, or 0 at error or end of file.
     */
    size_t(SDLCALL * read) (struct SDL_RWops * context, void *ptr,
                            size_t size, size_t maxnum);

    /**
     *  Write exactly \c num objects each of size \c size from the area
     *  pointed at by \c ptr to data stream.
     *  
     *  \return the number of objects written, or 0 at error or end of file.
     */
    size_t(SDLCALL * write) (struct SDL_RWops * context, const void *ptr,
                             size_t size, size_t num);

    /**
     *  Close and free an allocated SDL_RWops structure.
     *  
     *  \return 0 if successful or -1 on write error when flushing data.
     */
    int (SDLCALL * close) (struct SDL_RWops * context);

    UInt32 type;
    union
    {
#if defined(ANDROID)
        struct
        {
            void *fileNameRef;
            void *inputStreamRef;
            void *readableByteChannelRef;
            void *readMethod;
            long position;
            int size;
        } androidio;
#elif defined(__WIN32__)
        struct
        {
            bool append;
            void *h;
            struct
            {
                void *data;
                size_t size;
                size_t left;
            } buffer;
        } windowsio;
#endif

#ifdef HAVE_STDIO_H
        struct
        {
            bool autoclose;
            FILE *fp;
        } stdio;
#endif
        struct
        {
            UInt8 *base;
            UInt8 *here;
            UInt8 *stop;
        } mem;
        struct
        {
            void *data1;
        } unknown;
    } hidden;

} SDL_RWops;


/**
 *  \name RWFrom functions
 *  
 *  Functions to create SDL_RWops structures from various data streams.
 */
/*@{*/

extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_RWFromFile(const char *file,
                                                  const char *mode);

#ifdef HAVE_STDIO_H
extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_RWFromFP(FILE * fp,
                                                bool autoclose);
#else
extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_RWFromFP(void * fp,
                                                Bool autoclose);
#endif

extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_RWFromMem(void *mem, int size);
extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_RWFromConstMem(const void *mem,
                                                      int size);

/*@}*//*RWFrom functions*/


extern SGL_DECLSPEC SDL_RWops *SDLCALL SDL_AllocRW(void);
extern SGL_DECLSPEC void SDLCALL SDL_FreeRW(SDL_RWops * area);

#define RW_SEEK_SET	0       /**< Seek from the beginning of data */
#define RW_SEEK_CUR	1       /**< Seek relative to current read point */
#define RW_SEEK_END	2       /**< Seek relative to the end of data */

/**
 *  \name Read/write macros
 *  
 *  Macros to easily read and write from an SDL_RWops structure.
 */
/*@{*/
#define SDL_RWseek(ctx, offset, whence)	(ctx)->seek(ctx, offset, whence)
#define SDL_RWtell(ctx)			(ctx)->seek(ctx, 0, RW_SEEK_CUR)
#define SDL_RWread(ctx, ptr, size, n)	(ctx)->read(ctx, ptr, size, n)
#define SDL_RWwrite(ctx, ptr, size, n)	(ctx)->write(ctx, ptr, size, n)
#define SDL_RWclose(ctx)		(ctx)->close(ctx)
/*@}*//*Read/write macros*/


/** 
 *  \name Read endian functions
 *  
 *  Read an item of the specified endianness and return in native format.
 */
/*@{*/
extern SGL_DECLSPEC UInt16 SDLCALL SDL_ReadLE16(SDL_RWops * src);
extern SGL_DECLSPEC UInt16 SDLCALL SDL_ReadBE16(SDL_RWops * src);
extern SGL_DECLSPEC UInt32 SDLCALL SDL_ReadLE32(SDL_RWops * src);
extern SGL_DECLSPEC UInt32 SDLCALL SDL_ReadBE32(SDL_RWops * src);
extern SGL_DECLSPEC UInt64 SDLCALL SDL_ReadLE64(SDL_RWops * src);
extern SGL_DECLSPEC UInt64 SDLCALL SDL_ReadBE64(SDL_RWops * src);
/*@}*//*Read endian functions*/

/** 
 *  \name Write endian functions
 *  
 *  Write an item of native format to the specified endianness.
 */
/*@{*/
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteLE16(SDL_RWops * dst, UInt16 value);
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteBE16(SDL_RWops * dst, UInt16 value);
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteLE32(SDL_RWops * dst, UInt32 value);
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteBE32(SDL_RWops * dst, UInt32 value);
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteLE64(SDL_RWops * dst, UInt64 value);
extern SGL_DECLSPEC size_t SDLCALL SDL_WriteBE64(SDL_RWops * dst, UInt64 value);
/*@}*//*Write endian functions*/


/* Ends C function definitions when using C++ */
#ifdef __cplusplus
/* *INDENT-OFF* */
}
/* *INDENT-ON* */
#endif

#endif /* _SDL_rwops_h */

/* vi: set ts=4 sw=4 expandtab: */
