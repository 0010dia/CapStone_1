// sgl_list.h

// 작성자 : 정인택
// 작성일 : 2008.05.20
// 설  명 : List 모듈

#ifndef __SGL_LISTCONTROL_H
#define __SGL_LISTCONTROL_H

typedef struct _SGL_LIST_ITEM
{
	void*					pData;
	struct _SGL_LIST_ITEM*	pPrevItem;
	struct _SGL_LIST_ITEM*	pNextItem;
} SGL_LIST_ITEM, *PSGL_LIST_ITEM;

typedef struct tagSGL_LIST_CONTEXT
{
	UInt					nItemCount;
	PSGL_LIST_ITEM			pHead;
	PSGL_LIST_ITEM			pTail;
} SGL_LIST_CONTEXT, *PSGL_LIST_CONTEXT;

PSGL_LIST_CONTEXT sglList_Create();
void sglList_Destroy(PSGL_LIST_CONTEXT pContext);
UInt sglList_GetCount(PSGL_LIST_CONTEXT pContext);
void* sglList_GetHead(PSGL_LIST_CONTEXT pContext);
void* sglList_GetTail(PSGL_LIST_CONTEXT pContext);
void* sglList_RemoveHead(PSGL_LIST_CONTEXT pContext);
void* sglList_RemoveTail(PSGL_LIST_CONTEXT pContext);
SGL_POSITION sglList_AddHead(PSGL_LIST_CONTEXT pContext,void* pData);
SGL_POSITION sglList_AddTail(PSGL_LIST_CONTEXT pContext,void* pData);
void sglList_RemoveAll(PSGL_LIST_CONTEXT pContext);
SGL_POSITION sglList_GetHeadPosition(PSGL_LIST_CONTEXT pContext);
SGL_POSITION sglList_GetTailPosition(PSGL_LIST_CONTEXT pContext);
void* sglList_GetNext(PSGL_LIST_CONTEXT pContext,SGL_POSITION* pPos);
void* sglList_GetPrev(PSGL_LIST_CONTEXT pContext,SGL_POSITION* pPos);
void sglList_SetAt(PSGL_LIST_CONTEXT pContext,SGL_POSITION pos,void* pData);
void* sglList_GetAt(PSGL_LIST_CONTEXT pContext,SGL_POSITION pos);
void sglList_RemoveAt(PSGL_LIST_CONTEXT pContext,SGL_POSITION pos);
SGL_POSITION sglList_InsertBefore(PSGL_LIST_CONTEXT pContext,SGL_POSITION pos,void* pData);
SGL_POSITION sglList_InsertAfter(PSGL_LIST_CONTEXT pContext,SGL_POSITION pos,void* pData);

#endif // __SGL_LISTCONTROL_H
