// sgl_memory.h
#ifndef __SGL_MEMORY_H__
#define __SGL_MEMORY_H__

class CSglMemory
{
public:
	CSglMemory();
	virtual ~CSglMemory();

	//사용할 메모리를 할당 한다.
	void InitBuffer(Byte *pBuffer, Int32 nBuffer);
	void InitBuffer(Int32 nSize);

	//사용할 메모리를 해제 한다.
	void ExitBuffer();

	//메모리 블럭의 사용할 위치를 초기화 한다.
	Byte* ResetMemory();

	//메모리 블럭에서 사용할 메모리를 할당 받는다.
	//bAlignment : 기존 할당받은 메모리와 연속으로 사용할 때 FALSE, 새로운 메모리 사용할 때 TRUE
	Byte* GetMemory(Bool bAlignment, Int32 &nFreeSize);

	//메모리 블럭에 사용 메모리를 갱신한다.
	Bool UseMemory(Int32 nSize, Int32 &nFreeSize);

private:
	Bool	m_bAlloc;		// 메모리를 직접 할당 했는지 여부
	Byte	*m_pBuffer;		//	블럭및 구조체 생성시 동적으로 사용할 메모리 블럭
	Int32	m_nBufferSize;	//	메모리 블럭 크기
	Int32	m_nBufferPos;	//현재까지 사용중인 메모리 블럭 위치
};

#endif // __SGL_MEMORY_H__
