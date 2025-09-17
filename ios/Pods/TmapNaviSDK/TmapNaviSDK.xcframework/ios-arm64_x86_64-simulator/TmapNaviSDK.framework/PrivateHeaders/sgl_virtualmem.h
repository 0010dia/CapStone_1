// sgl_virtualmem.h

#ifndef __SGL_VIRTUALMEM_H
#define __SGL_VIRTUALMEM_H

#if defined(_WIN32) && !defined(WIN32_VSM)

#	define SGL_PAGE_SIZE		4096
#	define SGL_INITVM_SIZE		SGL_MB(60)

#	if defined(__GNUC__)

#		define sgl_vmalloc			sgl_malloc
#		define sgl_vmfree			sgl_free

#	else //defined(__GNUC__)

#		if defined(__WM6__) || defined(_WIN32_PHONE)

#			define sgl_vmalloc			sgl_malloc
#			define sgl_vmfree			sgl_free

#		else

#			define sgl_vmalloc			sglCommitVm

#			ifdef __Lite__
#				define sgl_vmfree			((void)0)
#			else
#				define sgl_vmfree			__noop
#			endif

#		endif

#	endif //defined(__GNUC__)

#	ifdef _WIN32_PHONE
#		define sglInitVm()			(1)
	#	define sglExitVm()		((void)0)
#	else
		Bool sglInitVm();
		void sglExitVm();
		void* sglCommitVm(DWord dwSize);
#	endif

#else

#	define sglInitVm()			(1)
#	define sglExitVm()		((void)0)
#	define sgl_vmalloc			sgl_malloc
#	define sgl_vmfree			sgl_free

#endif

#endif // __SGL_VIRTUALMEM_H
