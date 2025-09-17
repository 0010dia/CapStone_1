// sgl_common.h

// 작성자 : 강동수
// 작성일 : 2012.06.11
// 설  명 : INI 파일 제어를 위한 헤더. 

#ifndef __SGL_INI_H__
#define __SGL_INI_H__

#include "sgl.h"

class CSglIni{
public:
	CSglIni();
	~CSglIni();
private:
	FILE			*_hInifile;		/// ini file handler
	Char			*_filebuffer;	/// File Buffer
	Int32			_buffersize;
public:
	
	Int32 Ini_OpenFile(Char *inifilename);
	Int32 Ini_CacheFile();
	Int32 Ini_CacheFree();
	Int32 Ini_CloseFile();
	Int32 Ini_SaveFile(Char *inifilename, Char *buffer, Int32 buffersize);
	Int32 Ini_GetValue(Char *section, Char *key, Char *vbuf);
};



#endif

