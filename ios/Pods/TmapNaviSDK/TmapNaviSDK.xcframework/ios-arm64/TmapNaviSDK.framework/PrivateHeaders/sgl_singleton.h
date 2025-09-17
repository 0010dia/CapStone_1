// sgl_singleton.h

// 작성자 : 정인택
// 작성일 : 2007.12.27
// 설  명 : Singleton 디자인 패턴 매크로 정의

#ifndef __SGL_SINGLETON_H
#define __SGL_SINGLETON_H

#define DECLARE_SINGLETON(class_name)								\
protected :															\
	static class_name*	m_pInstance;								\
public :															\
	static Bool IsInstance()                                        \
    {                                                               \
        if(m_pInstance == NULL)                                     \
            vsm_log_debug("%s is not created", #class_name);        \
        return m_pInstance != NULL;                                 \
    }                                                               \
	static class_name& GetInstance();								\
	static Bool CreateInstance();									\
	static void DestroyInstance();

#define IMPLEMENT_SINGLETON(class_name)								\
	class_name*	class_name::m_pInstance = NULL;						\
	class_name& class_name::GetInstance()							\
	{																\
		SGL_ASSERT(m_pInstance != NULL);							\
		return *m_pInstance;										\
	}																\
																	\
	Bool class_name::CreateInstance()								\
	{																\
		if(m_pInstance == NULL)										\
			m_pInstance = new class_name;							\
		return (m_pInstance != NULL);								\
	}																\
																	\
	void class_name::DestroyInstance()								\
	{																\
		if(m_pInstance)												\
			delete m_pInstance;										\
		m_pInstance = NULL;											\
	}

#define DECLARE_SINGLETON_INSTANCE(class_name)						\
protected :															\
	class class_name##Instance										\
	{																\
	public :														\
		class_name##Instance()										\
		{															\
			if(!class_name::CreateInstance())						\
				SGL_THROW_EXCEPTION(SFL_ERROR_OUTOFMEMORY);			\
		}															\
		~class_name##Instance()										\
		{															\
			class_name::DestroyInstance();							\
		}															\
	};																\
	static class_name##Instance		m_singletonInstance;

#define IMPLEMENT_SINGLETON_INSTANCE(class_name)					\
	class_name::class_name##Instance								\
	class_name::m_singletonInstance;

#endif // __SGL_SINGLETON_H
