// sgl_uinthashtable.h

// 작성자 : 정인택
// 작성일 : 2008.05.20
// 설  명 : Hash Table 모듈

#ifndef __SGL_UINTHASHTABLE_H
#define __SGL_UINTHASHTABLE_H

typedef UIntPtr_t (*PSGLFN_GETUINTHASHCODE)(UIntPtr_t nKey);

typedef struct _SGL_UINTHASH_ITEM
{	
	UIntPtr_t					nKey;
	void*						pData;
	struct _SGL_UINTHASH_ITEM*	pNextItem;
} SGL_UINTHASH_ITEM, *PSGL_UINTHASH_ITEM;

typedef struct tagSGL_UINTHASHTABLE_CONTEXT
{	
	UInt						nHashTableSize;
	UInt						nItemCount;
	PSGL_UINTHASH_ITEM*			ppHashTable;
	PSGLFN_GETUINTHASHCODE		pfnGetHashCode;
} SGL_UINTHASHTABLE_CONTEXT, *PSGL_UINTHASHTABLE_CONTEXT;

PSGL_UINTHASHTABLE_CONTEXT sglUIntHashTable_Create(
	UInt nHashTableSize,PSGLFN_GETUINTHASHCODE pfnGetHashCode);
void sglUIntHashTable_Destroy(PSGL_UINTHASHTABLE_CONTEXT pContext);
UInt sglUIntHashTable_GetHashTableSize(PSGL_UINTHASHTABLE_CONTEXT pContext);
UInt sglUIntHashTable_GetCount(PSGL_UINTHASHTABLE_CONTEXT pContext);
void* sglUIntHashTable_Lookup(PSGL_UINTHASHTABLE_CONTEXT pContext,UIntPtr_t nKey);
Bool sglUIntHashTable_Insert(PSGL_UINTHASHTABLE_CONTEXT pContext,UIntPtr_t nKey,void* pData);
void sglUIntHashTable_Remove(PSGL_UINTHASHTABLE_CONTEXT pContext,UIntPtr_t nKey);
void sglUIntHashTable_RemoveAll(PSGL_UINTHASHTABLE_CONTEXT pContext);
SGL_POSITION sglUIntHashTable_GetStartPosition(PSGL_UINTHASHTABLE_CONTEXT pContext);
void* sglUIntHashTable_GetNext(PSGL_UINTHASHTABLE_CONTEXT pContext,SGL_POSITION* pPos);

#endif // __SGL_UINTHASHTABLE_H
