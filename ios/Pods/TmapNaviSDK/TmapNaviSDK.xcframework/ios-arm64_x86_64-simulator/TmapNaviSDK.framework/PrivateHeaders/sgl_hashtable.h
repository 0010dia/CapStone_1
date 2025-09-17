// sgl_hashtable.h

// 작성자 : 정인택
// 작성일 : 2008.05.20
// 설  명 : Hash Table 모듈

#ifndef __SGL_HASHTABLE_H
#define __SGL_HASHTABLE_H

typedef UInt (*PSGLFN_GETHASHCODE)(const void* pKey);
typedef Bool (*PSGLFN_COMPAREHASHITEM)(const void* pKey1,const void* pKey2);

typedef struct _SGL_HASH_ITEM
{	
	void*						pKey;
	void*						pData;
	struct _SGL_HASH_ITEM*		pNextItem;
} SGL_HASH_ITEM, *PSGL_HASH_ITEM;

typedef struct tagSGL_HASHTABLE_CONTEXT
{	
	UInt						nHashTableSize;
	UInt						nHashKeySize;
	UInt						nItemCount;
	PSGL_HASH_ITEM*				ppHashTable;
	PSGLFN_GETHASHCODE			pfnGetHashCode;
	PSGLFN_COMPAREHASHITEM		pfnCompare;
} SGL_HASHTABLE_CONTEXT, *PSGL_HASHTABLE_CONTEXT;

PSGL_HASHTABLE_CONTEXT sglHashTable_Create(
	UInt nHashTableSize,UInt nHashKeySize,
	PSGLFN_GETHASHCODE pfnGetHashCode,PSGLFN_COMPAREHASHITEM pfnCompare);
void sglHashTable_Destroy(PSGL_HASHTABLE_CONTEXT pContext);
UInt sglHashTable_GetHashTableSize(PSGL_HASHTABLE_CONTEXT pContext);
UInt sglHashTable_GetCount(PSGL_HASHTABLE_CONTEXT pContext);
void* sglHashTable_Lookup(PSGL_HASHTABLE_CONTEXT pContext,const void* pKey);
Bool sglHashTable_Insert(PSGL_HASHTABLE_CONTEXT pContext,const void* pKey,void* pData);
void sglHashTable_Remove(PSGL_HASHTABLE_CONTEXT pContext,const void* pKey);
void sglHashTable_RemoveAll(PSGL_HASHTABLE_CONTEXT pContext);
SGL_POSITION sglHashTable_GetStartPosition(PSGL_HASHTABLE_CONTEXT pContext);
void* sglHashTable_GetNext(PSGL_HASHTABLE_CONTEXT pContext,SGL_POSITION* pPos);

#endif // __SGL_HASHTABLE_H
