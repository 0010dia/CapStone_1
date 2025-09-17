// sgl_cache.h

// 작성자 : 정인택
// 작성일 : 2008.05.20
// 설  명 : Cache 모듈

#ifndef __SGL_CACHE_H
#define __SGL_CACHE_H

typedef void (*PSGLFN_REMOVECACHEITEM)(void* pValue);

#define SGL_CACHE_HASHTABLE_SIZE			256

typedef struct SGL_CACHE_ITEM
{	
	UIntPtr_t			nKey;
	void*				pValue;
	UInt				nRefCount;
	Int					nSize;
	SGL_POSITION		freeListPos;
} SGL_CACHE_ITEM, *PSGL_CACHE_ITEM;

typedef struct tagSGL_CACHE_CONTEXT
{
	Int							nMaxSize;
	Int							nCurSize;
	Int							nCurCount;
	PSGLFN_REMOVECACHEITEM		pfnRemoveCacheItem;
	PSGL_LIST_CONTEXT			pCtxtFreeList;
 	PSGL_UINTHASHTABLE_CONTEXT	pCtxtKeyHashTable;
	PSGL_UINTHASHTABLE_CONTEXT	pCtxtValueHashTable;
} SGL_CACHE_CONTEXT, *PSGL_CACHE_CONTEXT;

PSGL_CACHE_CONTEXT sglCache_Create(
	PSGLFN_REMOVECACHEITEM pfnRemoveCacheItem,UInt nMaxSize);
void sglCache_Destroy(PSGL_CACHE_CONTEXT pContext);
UInt sglCache_GetCount(PSGL_CACHE_CONTEXT pContext);
void* sglCache_Lookup(PSGL_CACHE_CONTEXT pContext,UIntPtr_t nKey, Int *nSize = NULL);
void sglCache_ReleaseByKey(PSGL_CACHE_CONTEXT pContext,UIntPtr_t nKey);
void sglCache_ReleaseByValue(PSGL_CACHE_CONTEXT pContext,void* pValue);
Bool sglCache_Add(PSGL_CACHE_CONTEXT pContext,UIntPtr_t nKey,void* pValue,Int nSize);
void sglCache_Remove(PSGL_CACHE_CONTEXT pContext,UIntPtr_t nKey);
void sglCache_RemoveAll(PSGL_CACHE_CONTEXT pContext);

#endif // __SGL_CACHE_H
