#ifndef __RES_FORMAT_DITHER_H__
#define __RES_FORMAT_DITHER_H__

// writer : ramoo
// last update : 2012-07-12

//crossimg.idx format
typedef struct tagCrossImageIndexHeader
{
	unsigned int	nMaxIndex;			// 인덱스 총 개수
	unsigned int*	pResOffsetByIndex;	// 이미지의 offset 배열
}CROSSIMAGEINDEXHDEADER, *LPCROSSIMAGEINDEXHDEADER;

//crossimg.bdb header
typedef struct tagCrossImageDBHeader
{
	unsigned int	nMaxImageCount;		// 이미지 총 개수
//	unsigned int	nMaxSizeImage;		// 가장큰 이미지 사이즈 ? (왜?) 일단 이전에 있어서 박음
//										// 아무리 봐도 필요 없어 보여 삭제함
}CROSSIMAGEDBHDEADER, *LPCROSSIMAGEDBHDEADER;

//crossimg.bdb data
typedef struct tagCrossImageInfo
{
	unsigned int	nImageType;			// 이미지 정보 (5650, 4444, 5551)
	unsigned short	nwidth;				
	unsigned short	nheight;
	unsigned int	nOriginalSize;		// 이미지 원본	 크기
	unsigned int	nCompressSize;		// 이미지 압축된 크기
	unsigned char*	pBit;				// 압축된 이미지 버퍼
}CROSSIMAGEINFO, *LPCROSSIMAGEINFO;

#endif
