// sgl_malloc.h

// �ۼ��� : ������
// �ۼ��� : 2007.12.27
// ��  �� : �޸� ��� �Լ� ����

#ifndef __SGL_MALLOC_H
#define __SGL_MALLOC_H

#ifdef _USE_HEAP_DEBUG_
#include "HeapTracker.h"
#endif

#include <stdlib.h>

// _sgl routine is used of internal
// sgl_chkmemleak.h ���Ͽ��� ����

#define _sgl_malloc				malloc
#define _sgl_calloc             calloc
#define _sgl_realloc            realloc
#define _sgl_free				free

// �޸� �Ҵ� ���� �Լ�

#define sgl_malloc				_sgl_malloc
#define sgl_calloc              _sgl_calloc
#define sgl_realloc             _sgl_realloc
#define sgl_free                _sgl_free

// ���û� �޸� �Ҵ� �Լ�.(Ư���� ���ܿ��� ����ؼ��� �ȵȴ�.)

#define sgl_alloca				alloca		

#ifndef DeleteAndNull
#define DeleteAndNull(p);        if (p) { delete p; p = NULL; } 
#define DeleteArrayAndNull(p);    if (p) { delete[] p; p = NULL; } 
#endif

#define sgl_safefree(p)			if (p) { sgl_free(p);	p = NULL; }
#define sgl_safedelete(p)		if (p) { delete p;		p = NULL; }
#define sgl_safedelete_array(p)	if (p) { delete [] p;	p = NULL; }


#ifdef _USE_HEAP_DEBUG_
#undef sgl_malloc
#undef sgl_calloc
#undef sgl_realloc
#undef sgl_free
#undef sgl_safefree

#define sgl_malloc(size)		HeapTracker_malloc(size, __FILE__, __LINE__, HEAPTRACKER_ALLOC_TYPE_MALLOC, HeapTracker_getReturnAddress(0))
#define sgl_calloc(num, size)   HeapTracker_calloc(num, size, __FILE__, __LINE__, HEAPTRACKER_ALLOC_TYPE_MALLOC, HeapTracker_getReturnAddress(0))
#define sgl_realloc(p, size)    HeapTracker_realloc(p, size, __FILE__, __LINE__, HEAPTRACKER_ALLOC_TYPE_MALLOC, HeapTracker_getReturnAddress(0))
#define sgl_free(p)				HeapTracker_free(p, __FILE__, __LINE__, HEAPTRACKER_ALLOC_TYPE_MALLOC)
#define sgl_safefree(p)			if (p) { HeapTracker_free(p, __FILE__, __LINE__, HEAPTRACKER_ALLOC_TYPE_MALLOC); p = NULL; }
#endif  // _USE_HEAP_DEBUG_

#endif // __SGL_MALLOC_H

