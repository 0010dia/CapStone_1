
#ifndef SDL_LEGACY_H
#define SDL_LEGACY_H

#include <stdio.h>
#ifdef __IPHONEOS__
#include <sys/time.h>
#else
#include <time.h>
#endif
#include <stdlib.h>
#include "sgl_basetype.h"

#ifdef HAVE_CTYPE_H
#define SDL_isdigit(X)  isdigit(X)
#define SDL_isspace(X)  isspace(X)
#define SDL_toupper(X)  toupper(X)
#define SDL_tolower(X)  tolower(X)
#else
#define SDL_isdigit(X)  (((X) >= '0') && ((X) <= '9'))
#define SDL_isspace(X)  (((X) == ' ') || ((X) == '\t') || ((X) == '\r') || ((X) == '\n'))
#define SDL_toupper(X)  (((X) >= 'a') && ((X) <= 'z') ? ('A'+((X)-'a')) : (X))
#define SDL_tolower(X)  (((X) >= 'A') && ((X) <= 'Z') ? ('a'+((X)-'A')) : (X))
#endif

typedef struct tagSDL_mutex
{
    pthread_mutex_t id;
} SDL_mutex;

SDL_mutex *SDL_CreateMutex(void);
void SDL_DestroyMutex(SDL_mutex * mutex);
void SDL_LockMutex(SDL_mutex* mutext);
void SDL_TryLockMutex(SDL_mutex* mutext);
void SDL_UnlockMutex(SDL_mutex* mutext);

/* The first ticks value of the application */
#ifdef HAVE_CLOCK_GETTIME
static struct timespec start;
#else
static struct timeval start;
#endif /* HAVE_CLOCK_GETTIME */

void SDL_StartTicks(void);
UInt32 SDL_GetTicks(void);
void SDL_Delay(UInt32 ms);

#define SGL_mutex                                SDL_mutex
#define SGL_CreateMutex                            SDL_CreateMutex
#define SGL_DestroyMutex(c)                        SDL_DestroyMutex(c)
#define SGL_LockMutex(c)                        SDL_LockMutex(c)
#define SDL_TryLockMutex(c)                        SDL_TryLockMutex(c)
#define SGL_UnlockMutex(c)                        SDL_UnlockMutex(c)

#endif /* SDL_LEGACY_H */
