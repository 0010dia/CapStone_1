#ifndef _sgl_array_2008_12_25_Yeon_h_
#define _sgl_array_2008_12_25_Yeon_h_

#include <stdio.h>

#ifdef __cplusplus

template<class Datatype>
class sglBuffer
{
public:
	sglBuffer(size_t p_size = 128, size_t step = 128) : m_nPos(0), m_nAllocSize(p_size), m_nAllocStep(step)
	{
		m_pBuffer		= (Datatype*)sgl_malloc(sizeof(Datatype)*p_size);
	}
	virtual~sglBuffer()
	{
		sgl_safefree(m_pBuffer);
	}

	inline void SetChunkSize(size_t istep)
	{
		//m_nAllocStep = sizeof(Datatype)*istep;
        m_nAllocStep = istep;
	}

	inline void SetEmpty()
	{
		m_nPos			= 0;	// 현재 위치
		m_nAllocSize	= 0;
		sgl_safefree(m_pBuffer);
	}
	inline Bool IsEmpty()
	{
		if( m_pBuffer == NULL || m_nAllocSize == 0 )
			return TRUE;
		return FALSE;
	}

	inline Bool ClearNewResize(size_t iSize)
	{
		if( iSize == 0 )
            return FALSE;
        
		if( iSize != m_nAllocSize || m_pBuffer == NULL){
			sgl_safefree(m_pBuffer);
			m_pBuffer = (Datatype*)sgl_malloc(sizeof(Datatype)*iSize);
		}
		memset(m_pBuffer, 0, sizeof(Datatype)*iSize);
		m_nAllocSize = iSize;

        return TRUE;
	}

	inline Bool Reset()
	{
        m_nPos = 0;
		if(m_pBuffer)
		{
			memset(m_pBuffer, 0, sizeof(Datatype)*m_nAllocSize);
			return TRUE;
		}
		return FALSE;
	}
    
    inline Bool ResetPosOnly()
    {
        m_nPos = 0;
        return true;
    }

	inline size_t GetSizeof() const { return sizeof(Datatype)*m_nPos; }
	inline size_t GetAllocSize() const { return m_nAllocSize; }
	inline size_t GetPos() const { return m_nPos; }
	inline void SetPos(size_t nPos){ m_nPos = nPos; }
	inline Datatype* SetPosGetBuffer(size_t nPos){ m_nPos = nPos; return &m_pBuffer[m_nPos]; }
	inline Datatype* GetPosBuffer() { return &m_pBuffer[m_nPos]; }
	inline Datatype* GetBuffer() { return m_pBuffer; }

	inline Datatype* GetAt(size_t nIndex){
		if( nIndex >= m_nAllocSize )
			return NULL;

		return &m_pBuffer[nIndex];
	}

	inline Datatype& operator [] (size_t idx){
		if( idx >= m_nAllocSize ){
			AllocStep();
		}
		return m_pBuffer[idx];
	}

	inline size_t Add(Datatype* p_item, size_t count)
	{
		size_t nReqSize		= sizeof(Datatype)*count;
		size_t nResPos		= m_nPos;
		
		// 남은 용량이 모자를때
		if( (m_nAllocSize - m_nPos) < count )
		{
			// 요구 하는 사이즈가 스텝 사이즈보다 클경우
			if( nReqSize > (sizeof(Datatype)*m_nAllocStep) ){
				AddAlloc(nReqSize);
			}
			else
			{
				// 스템 사이즈 만큼 증가
				while ( (m_nAllocSize - m_nPos) < count )
				{
					AllocStep();
				}
			}
		}
		sgl_memcpy(&m_pBuffer[m_nPos], p_item, nReqSize);
		m_nPos += count;
		return nResPos;
	}
	inline size_t GetAddCount() const {
		return m_nPos;///sizeof(Datatype);
	}
	inline size_t Get(Datatype* p_item, size_t count)
	{
		size_t nReqSize = sizeof(Datatype)*count;
		if( m_nPos < 0 )
		{
			SGL_ASSERT(0);
		}
		size_t nResPos	 = m_nPos;
		if( m_nPos + nReqSize > m_nAllocSize )
			return 0;

		sgl_memcpy(p_item, &m_pBuffer[m_nPos], nReqSize);
		m_nPos += count;
		return nResPos;
	}	

protected:
	inline size_t AddAlloc(size_t nReqSize)
	{
		size_t iNewAllocSize = m_nAllocSize + nReqSize;
		Datatype* pNew = (Datatype*)sgl_malloc(sizeof(Datatype)*iNewAllocSize);
		sgl_memset(pNew, NULL, sizeof(Datatype)*iNewAllocSize);
		sgl_memcpy(pNew, m_pBuffer, sizeof(Datatype) * m_nAllocSize);
		sgl_safefree(m_pBuffer);
		m_pBuffer = pNew;
		m_nAllocSize = iNewAllocSize;
		return m_nAllocSize;
	}

	inline size_t AllocStep()
	{
		size_t iNewAllocSize = m_nAllocSize + m_nAllocStep;
		Datatype* pNew = (Datatype*)sgl_malloc(sizeof(Datatype)*iNewAllocSize);
		sgl_memset(pNew, NULL, sizeof(Datatype)*iNewAllocSize);
		sgl_memcpy(pNew, m_pBuffer, sizeof(Datatype) * m_nAllocSize);
		sgl_safefree(m_pBuffer);
		m_pBuffer = pNew;
		m_nAllocSize = iNewAllocSize;
		return m_nAllocSize;
	}
    
//private:
//	SDL_mutex		*m_pLock;
    
protected:
	Datatype*		m_pBuffer;
	size_t			m_nPos;
	size_t			m_nAllocSize;
	size_t			m_nAllocStep;
};

template<class Datatype>
class sglArray
{
public:
	sglArray( size_t p_size = 4 ) : m_pBuffer(NULL), m_nAllocStep(p_size), m_nAllowBuffSize(0), m_nCurSize(0)
	{
		Allocate();
	}

	~sglArray()
	{
		sgl_safefree(m_pBuffer);
	}

	inline void Allocate()
	{
		if (!m_pBuffer)
		{
			m_pBuffer = (Datatype*)sgl_malloc(m_nAllocStep * sizeof(Datatype));
			m_nAllowBuffSize = m_nAllocStep;
		} 
		else 
		{
			if(m_nCurSize >= m_nAllowBuffSize) 
			{
				if (m_nCurSize >= (m_nAllowBuffSize+m_nAllocStep))
				{
					m_nAllocStep = m_nCurSize + m_nAllocStep;
				}

				m_nAllowBuffSize = m_nAllowBuffSize	+ m_nAllocStep;

				Datatype* pNew = (Datatype*)sgl_malloc(m_nAllowBuffSize * sizeof(Datatype));
				sgl_memcpy(pNew, m_pBuffer, sizeof(Datatype) * m_nCurSize);
				SGL_ASSERT(m_pBuffer != NULL);
				sgl_free(m_pBuffer); m_pBuffer = NULL;
				m_pBuffer = pNew;
			}
		}
	}

	inline void Resize( size_t p_size, size_t nAllocStep = 2048 )
	{
		if (m_nAllowBuffSize > p_size) 
			return;

		size_t nOldAllocSize = m_nAllowBuffSize;

		m_nAllocStep = nAllocStep;
		m_nAllowBuffSize = p_size + m_nAllocStep;

		Datatype* pNew = (Datatype*)sgl_malloc(m_nAllowBuffSize * sizeof(Datatype));
		sgl_memset(pNew, 0x00, m_nAllowBuffSize * sizeof(Datatype));
		sgl_memcpy(pNew, m_pBuffer, sizeof(Datatype) * nOldAllocSize);
		SGL_ASSERT(m_pBuffer != NULL);
		sgl_free(m_pBuffer); m_pBuffer = NULL;
		m_pBuffer = pNew;
	}

	inline void ClearNewResize( size_t p_size, size_t nAllocStep = 2048 )
	{
		m_nCurSize = 0;

		if (m_nAllowBuffSize > p_size) {
			sgl_memset(m_pBuffer, 0x00, sizeof(Datatype)*m_nAllowBuffSize);
			return;
		} 

		m_nAllocStep = nAllocStep;
		m_nAllowBuffSize = p_size + m_nAllocStep;

		sgl_free(m_pBuffer); m_pBuffer = NULL;

		m_pBuffer = (Datatype*)sgl_malloc(m_nAllowBuffSize * sizeof(Datatype));
		sgl_memset(m_pBuffer, 0x00, m_nAllowBuffSize * sizeof(Datatype));
	}

	inline void Reset()
	{
		m_nCurSize = 0;

		if (m_nAllowBuffSize > 0 && m_pBuffer != NULL) {
			sgl_memset(m_pBuffer, 0x00, sizeof(Datatype)*m_nAllowBuffSize);
		} 
	}

	inline void Clear( size_t p_size)
	{
		m_nCurSize = 0;

		sgl_free(m_pBuffer); 
		m_pBuffer = NULL;

		if (p_size == 0)
			return;

		m_pBuffer = (Datatype*)sgl_malloc(p_size * sizeof(Datatype));
		sgl_memset(m_pBuffer, 0x00, p_size * sizeof(Datatype));
		m_nAllowBuffSize = p_size;
	}

	// 	Datatype& operator[] ( Int32 p_index )
	// 	{
	// 		return m_pBuffer[p_index];
	// 	}

	inline void Assign( Datatype* p_item, size_t count, size_t nAllocStep = 4 )
	{
		ClearNewResize(count, nAllocStep);
		sgl_memcpy(m_pBuffer, p_item, count * sizeof(Datatype));
		m_nCurSize = count;
	}

	inline size_t New()
	{
		m_nCurSize++;
		Allocate();
		return m_nCurSize;
	}


	inline void Add( Datatype p_item )
	{
		m_nCurSize++;
		Allocate();

		m_pBuffer[m_nCurSize-1] = p_item;
	}

	inline Int32 Add( Datatype* p_item, size_t count )
	{
		size_t nPos = m_nCurSize;
		Resize(m_nCurSize+count);
		sgl_memcpy(&m_pBuffer[m_nCurSize], p_item, sizeof(Datatype) * count);
		m_nCurSize += count;
		return nPos;
	}

	inline void Insert( Datatype p_item, size_t p_index )
	{
		if (p_index > m_nCurSize)
		{
			m_nCurSize++;
			Allocate();
		}

		size_t index;

		// move everything after p_index up by one cell.
		for( index = m_nCurSize - 1; index > p_index; index-- ) {
			m_pBuffer[index] = m_pBuffer[index - 1];
		}


		// insert the item.
		m_pBuffer[p_index] = p_item;
	}

	inline void Set( Datatype p_item, size_t index )
	{
		if(index < m_nCurSize)
		{
			m_pBuffer[index] = p_item;
		}
	}

	inline void Remove( size_t p_index )
	{
		size_t index;

		// move everything after p_index down by one cell.
		for( index = p_index + 1; index < m_nCurSize; index++ )
			m_pBuffer[index - 1] = m_pBuffer[index];

		if (p_index < m_nCurSize) {
			sgl_memset(&m_pBuffer[m_nCurSize-1], 0x00, sizeof(Datatype));
			m_nCurSize--;
		}
	}

	inline Datatype& GetAt( size_t p_index )
	{
		return m_pBuffer[p_index];
	}

	inline const Datatype& GetAt( size_t p_index ) const
	{
		return m_pBuffer[p_index];
	}

	inline Datatype* GetAtPtr( size_t p_index ) const
	{
		return &m_pBuffer[p_index];
	}

	inline size_t Size() const
	{
		return m_nCurSize;
	}

	inline Datatype* GetBuffer()
	{
		return m_pBuffer;
	}

	operator Datatype* ()
	{
		return m_pBuffer;
	}


	bool WriteFile( const char* p_filename )
	{
		FILE* outfile = 0;
		size_t written = 0;

		// open the file
		outfile = sgl_fopen( p_filename, "wb" );

		// return if it couldn't be opened
		if( outfile == 0 )
			return false;

		// 데이터 크기 저장
		written = fwrite(&m_nCurSize, sizeof( Int32 ), 1, outfile );

		// write the array and close thef ile
		written = fwrite( m_pBuffer, sizeof( Datatype ), m_nCurSize, outfile );
		fclose( outfile );

		// if we didn't write the number of items we expected,
		// return failure
		if( written != m_nCurSize )
			return false;

		// return success.
		return true;
	}


	bool ReadFile( const char* p_filename )
	{
		FILE* infile = 0;
		size_t read = 0;

		// open the file
		infile = sgl_fopen( p_filename, "rb" );

		// return if it couldn't be opened
		if( infile == 0 )
			return false;

		fread( &m_nCurSize, sizeof( Int32 ), 1, infile );

		ClearNewResize(m_nCurSize);

		// read the array and close the file
		read = fread( m_pBuffer, sizeof( Datatype ), m_nCurSize, infile );
		fclose( infile );

		// if we didn't read the number of items we expected,
		// return failure
		if( read != m_nCurSize )
			return false;

		// return success
		return true;
	}

protected:
	Datatype*	m_pBuffer;

	size_t		m_nAllocStep;
	size_t		m_nAllowBuffSize;
	size_t		m_nCurSize;
};

#endif //__cplusplus
#endif //_sgl_array_2008_12_25_Yeon_h_
