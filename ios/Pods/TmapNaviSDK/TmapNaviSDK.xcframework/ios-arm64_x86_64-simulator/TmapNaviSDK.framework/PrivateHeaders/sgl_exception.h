// sgl_exception.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : 예외 클래스 정의

#ifndef __SGL_EXCEPTION_H
#define __SGL_EXCEPTION_H

#ifndef _SGL_CPLUSPLUS_EXCEPTION
	#error _SGL_CPLUSPLUS_EXCEPTION is not defined.
#endif // _SGL_CPLUSPLUS_EXCEPTION

class CSglException;

#ifdef _DEBUG
	#define _sglDbgPrintException(err)									\
	{																	\
		SGL_DBGPRINT(													\
			_T("Exception : Error = %d, File = %s, Line = %d\n"),		\
			err,__FILE__,__LINE__);										\
	}
#else
	#define _sglDbgPrintException(err)		((void)0)
#endif

#if _SGL_CPLUSPLUS_EXCEPTION
	#define SGL_THROW_EXCEPTION(err)									\
	{																	\
		_sglDbgPrintException(err);										\
		throw CSglException(err);										\
	}
#else
	#define SGL_THROW_EXCEPTION(err)									\
	{																	\
		_sglDbgPrintException(err);										\
		throw err;														\
	}
#endif // _CPLUSPLUS_EXCEPTION

#define SGL_THROW_EXCEPTION_EXPR(expr,err)								\
{																		\
	if(expr)															\
	{																	\
		SGL_THROW_EXCEPTION(err);										\
	}																	\
}

class CSglException
{
public :
	CSglException() throw();
	CSglException(int nErr) throw();
	CSglException(const CSglException& e) throw();
	CSglException& operator = (const CSglException& e) throw();
	~CSglException() throw() {}
	int error() throw() { return m_nErr; }

private :
	int		m_nErr;
};

inline
CSglException::CSglException() throw()
:	m_nErr(SGL_ERROR_UNKNOWN)
{
}

inline
CSglException::CSglException(int nErr)  throw()
:	m_nErr(nErr)
{
}

inline
CSglException::CSglException(const CSglException& e)  throw()
:	m_nErr(e.m_nErr)
{
}

inline
CSglException& CSglException::operator = (const CSglException& e)  throw()
{
	m_nErr = e.m_nErr;
	return *this;
}

#endif // __SGL_EXCEPTION_H
