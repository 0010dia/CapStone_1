// sgl_chkmemleack.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : Memory Leak 검사

#ifndef __SGL_CHKMEMLEAK_H
#define __SGL_CHKMEMLEAK_H

#ifndef _SGL_CHECK_MEMORYLEAK
#ifdef _WIN32
	#error _SGL_CHECK_MEMORYLEAK is not defined.
#endif
#endif // _SGL_CHECK_MEMORYLEAK

#if !defined(_USE_HEAP_DEBUG_) && defined(_DEBUG) && (_SGL_CHECK_MEMORYLEAK)

#define SGL_CML_SIGNATURE			0x12345678 

typedef struct SGL_CML_BLOCK
{
	int					nSignature;
	SGL_CML_BLOCK*		pPrev;
	SGL_CML_BLOCK*		pNext;
	char*				lpszFileName;		// Source file name
	int					nLine;				// Source line
	unsigned int		nSize;				// Alloc size
	void*				pAddress;			// Alloc memory address
#if 1	// test
	int					nType;
#endif
} SGL_CML_BLOCK, *PSGL_CML_BLOCK;

void* __cdecl _sglAllocMemory(size_t size,const char* filename,const int line);
void __cdecl _sglFreeMemory(void* ptr);
void __cdecl sglDumpMemoryLeaks();
void _sglInitCml();
void _sglExitCml();

inline
void* __cdecl operator new(size_t size,const char* filename,const int line)
{
#if 1	// test	
	void*				pMemory;
	PSGL_CML_BLOCK		pBlock;

	pMemory = _sglAllocMemory(size,filename,line);
	pBlock = (PSGL_CML_BLOCK)pMemory;
	--pBlock;
	pBlock->nType = 1;

//	sglDebugPrintA("[new] 0x08x, %d, %s, %d\n", pMemory, size, filename, line);

	return pMemory;
#else
	return _sglAllocMemory(size,filename,line);
#endif
}

inline
void* __cdecl operator new[](size_t size,const char* filename,const int line)
{
#if 1	// test	
	void*				pMemory;
	PSGL_CML_BLOCK		pBlock;

	pMemory = _sglAllocMemory(size,filename,line);
	pBlock = (PSGL_CML_BLOCK)pMemory;
	--pBlock;
	pBlock->nType = 2;

	return pMemory;
#else
	return _sglAllocMemory(size,filename,line);
#endif
}

inline
void __cdecl operator delete(void* ptr)
{
#if 1	// test
	PSGL_CML_BLOCK		pBlock = (PSGL_CML_BLOCK)ptr;

	if(ptr == NULL)
		return;

	--pBlock;
	if(pBlock->nType != 1)
	{
		sglDebugPrintA("%s(%d) : Invalid delete operator\n",
			pBlock->lpszFileName,
			pBlock->nLine);

		sglDebugPrintA("memory alloc type ------- %s -------\n",
			(pBlock->nType == 0) ? "malloc" :
			(pBlock->nType == 1) ? "new" : "new[]");		
		SGL_DBGBREAK();
	}
#endif

	_sglFreeMemory(ptr);
}

inline
void __cdecl operator delete[](void* ptr)
{
#if 1	// test
	PSGL_CML_BLOCK		pBlock = (PSGL_CML_BLOCK)ptr;

	if(ptr == NULL)
		return;

	--pBlock;
	if(pBlock->nType != 2)
	{
		sglDebugPrintA("%s(%d) : Invalid delete operator\n",
			pBlock->lpszFileName,
			pBlock->nLine);

		sglDebugPrintA("memory alloc type ------- %s -------\n",
			(pBlock->nType == 0) ? "malloc" :
			(pBlock->nType == 1) ? "new" : "new[]");		
		SGL_DBGBREAK();
	}
#endif

	_sglFreeMemory(ptr);
}

#if 1		// test
inline
void __cdecl _sglFreeMemoryTest(void* ptr)
{
	PSGL_CML_BLOCK		pBlock = (PSGL_CML_BLOCK)ptr;

	if(ptr == NULL)
		return;

	--pBlock;
	if(pBlock->nType != 0)
	{
		sglDebugPrintA("%s(%d) : Invalid delete operator\n",
			pBlock->lpszFileName,
			pBlock->nLine);

		sglDebugPrintA("memory alloc type ------- %s -------\n",
			(pBlock->nType == 0) ? "malloc" :
			(pBlock->nType == 1) ? "new" : "new[]");		
		SGL_DBGBREAK();
	}

	_sglFreeMemory(ptr);
}
#endif

#undef sgl_malloc
#undef sgl_free

#define new						new(__FILE__,__LINE__)
#define sgl_malloc(size)		_sglAllocMemory(size,__FILE__,__LINE__)

#if 1		// test
#define sgl_free				_sglFreeMemoryTest
#else
#define sgl_free				_sglFreeMemory
#endif



#define sglInitCml				_sglInitCml
#define sglExitCml				_sglExitCml

#else // defined(_DEBUG) && (_SGL_CHKMEMLEAK)

#define sglInitCml()				((void)0)
#define sglExitCml()				((void)0)
#define sglDumpMemoryLeaks()		((void)0)

#endif // defined(_DEBUG) && (_SGL_CHKMEMLEAK)

// 실행 시 초기 생성 메모리 량 체크
#if 1
	void sgl_MemoryCheckSaveFile(const char* szFile);
	void sgl_MemoryCheck(const char* szMsgName);
#endif

#endif // __SGL_CHKMEMLEAK_H
