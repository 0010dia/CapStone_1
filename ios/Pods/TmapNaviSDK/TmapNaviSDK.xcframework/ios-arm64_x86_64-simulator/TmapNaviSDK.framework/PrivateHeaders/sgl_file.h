// sgl_file.h

// 작성자 : 정인택
// 작성일 : 2008.01.15
// 설  명 : File Handling 클래스

#ifndef __SGL_FILE_H
#define __SGL_FILE_H

enum SGL_FILEMODE
{
	SGL_FILEMODE_READ =				0x00000001,
	SGL_FILEMODE_WRITE =			0x00000002,	
	SGL_FILEMODE_SHARE_READ =		0x00000010,
	SGL_FILEMODE_SHARE_WRITE =		0x00000020,
	SGL_FILEMODE_CREATE =			0x00000100,
	SGL_FILEMODE_NOTRUNCATE =		0x00000200
};

enum SGL_SEEK_POSITION
{
	SGL_SEEK_BEGIN = 0x0,
	SGL_SEEK_CURRENT = 0x1,
	SGL_SEEK_END = 0x2
};

class CSglFile
{
public :
	CSglFile();
	~CSglFile();

	Bool IsOpen() { return (m_hFile != SGL_INVALID_FILE_HANDLE); }
	Bool Open(const Char* lpszFileName,DWord dwFlags);
#ifndef _WIN32
	Bool Open(Int32 nFileDescriptor, Int32 nDefaultOffset, Int32 nSize);
#endif

	void Close();

	UInt32 GetSize();

	Bool Seek(UInt32 nOffset,UInt32 nFrom);
	UInt32 Read(void* pBuffer,UInt32 nCount);
	UInt32 Write(const void* pBuffer,UInt32 nCount);

private :
	SGL_FILE_HANDLE		m_hFile;
#ifdef _WIN32_PHONE
	Char m_szName[_MAX_PATH];
#endif
#ifndef _WIN32
	Bool				m_bAssetsFile;		//안드로이드에서 APK에 등록된 리소스 파일 인지 여부
	Int32				m_nFileDescriptor;
	Int32				m_nDefaultOffset;	//안드로이드에서 APK에 등록된 리소스 파일을 읽을때 기본 offset이 0이 아니다.
	Int32				m_nSize;			//안드로이드에서 APK에 등록된 리소스 파일을 읽을때 크기를 알수 없으므로 JAVA에서 전달 받는다.
#endif
};
#endif // __SGL_FILE_H
