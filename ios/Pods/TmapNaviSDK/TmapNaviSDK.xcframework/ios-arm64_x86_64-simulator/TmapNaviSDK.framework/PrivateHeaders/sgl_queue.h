#ifndef _sgl_queue_2012_07_30_Yeon_h_
#define _sgl_queue_2012_07_30_Yeon_h_

#include <stdio.h>

template<class Datatype>
class sglQueue
{
public:
	sglQueue()
	{
		//동기화 객체 생성
		if ((m_pLock = SDL_CreateMutex()) == NULL)
		{
			SGL_ASSERT(0);
		}

		m_pBuffer = NULL;
	}

	~sglQueue()
	{
		if( m_pBuffer != NULL )
			sgl_free(m_pBuffer);

		m_pBuffer = NULL;

		if(m_pLock)
		{
			SGL_DestroyMutex(m_pLock);
			m_pLock = NULL;
		}
	}

	inline void SetSize( int p_size = 16 )
	{
		m_nMaxSize = p_size;
		m_nCount = 0;
		m_nHeadIndex = 0;
		m_nTailIndex = 1;

		m_pBuffer = (Datatype*)sgl_malloc(m_nMaxSize * sizeof(Datatype));
		sgl_memset(m_pBuffer, 0x00, sizeof(Datatype)*m_nMaxSize);
	}


	inline void Clear()
	{
		sgl_memset(m_pBuffer, 0x00, sizeof(Datatype)*m_nMaxSize);
		m_nCount = 0;
		m_nHeadIndex = 0;
		m_nTailIndex = 1;
	}


	inline void AddTail(Datatype *pDataAdded)
	{
		SGL_ASSERT(m_pBuffer != NULL);

		SDL_LockMutex(m_pLock);

		m_nTailIndex = m_nHeadIndex % m_nMaxSize;
		m_pBuffer[m_nTailIndex] = *pDataAdded;

		++m_nHeadIndex;

		if (m_nHeadIndex == m_nMaxSize)
			m_nHeadIndex = 0;

		if (m_nCount < m_nMaxSize)
			++m_nCount;

		SDL_UnlockMutex(m_pLock);
	}

	inline Bool GetTail(Int32 iIdx, Datatype *pData)
	{
		if (iIdx < 0 || m_nCount <= iIdx)
		{
			return FALSE;
		}

		Int32 iIdxInQue = (m_nMaxSize + m_nTailIndex -iIdx) % m_nMaxSize;
		*pData = m_pBuffer[iIdxInQue];

		return TRUE;
	}

	inline Datatype* GetTailPtr(Int32 iIdx)
	{
		if (iIdx < 0 || m_nCount <= iIdx)
			return NULL;

		Int32 iIdxInQue = (m_nMaxSize + m_nTailIndex -iIdx) % m_nMaxSize;

		return &m_pBuffer[iIdxInQue];
	}

	inline void RemoveTail()
	{
		if (m_nCount > 0) {
			--m_nCount;
		} else {
			return;
		}
	}

	inline Int32 GetCount()		
	{	
		return m_nCount;	
	}

	inline Int32 GetMaxSize()
	{
		return m_nMaxSize;	
	}

private:
	SDL_mutex		*m_pLock;

protected:
	Datatype		*m_pBuffer;

	Int32			m_nMaxSize;
	Int32			m_nCount;
	Int32			m_nHeadIndex;
	Int32			m_nTailIndex;
};


#endif //_sgl_queue_2012_07_30_Yeon_h_
