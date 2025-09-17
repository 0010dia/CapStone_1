#ifndef __TVAS_PARSER_HEADER__
#define __TVAS_PARSER_HEADER__

#include "sgl_inc.h"
#include "rgdata_def.h"

class CTvasParser
{
public:
	CTvasParser(void);
	virtual ~CTvasParser(void);

	Bool Parser(Byte *pBuffer, Int32 nSize, TVS_Data *pTvasData);

	Bool Tvas2KML(Byte *pBuffer, Int32 nSize);

private:
	unsigned long GetCRC(unsigned char *p, size_t n);
	Bool SetHeader(Byte *pBuffer, Int32 nTotalSize, Int32 &nService, Int32 &nHeaderSize);
	Bool SetService(Char *szID, Byte *pBuffer, Int32 nSize);

	void MergeDA4(Int32 i, Int32 nIdxConverted);
	void MergeDA5(Int32 i, Int32 nIdxConverted);
	Bool MergeService();
	Bool MakeStringData();
	Bool MakeVertexData();
	Bool MakeVertexWGS();
	Bool MakeLinkInfo();
	Bool CheckHiPass();
	Bool CheckVertex();
    void MakeComparableLinkList();
    void MakeViaPointList();
	void CalculateTotalEnergy();
	void CalculateWayPointEnergy();


	Int32 KMLMake_SENode(Char *szKML, Int32 &nIdxTotal, Int32 &nIdxNode, Char *szName, TVS_TileCoord *pTileCoord);
	Int32 KMLMake_WPNode(Char *szKML, Int32 &nIdxTotal, Int32 &nIdxNode, Int32 nIdxWP, Int32 &nTile, Int32 nIdxVertex);
	Int32 KMLMake_Node(Char *szKML, Int32 &nIdxTotal, Int32 &nIdxNode, Char *szName, Int32 &nTile, Int32 nIdxVertex);
	Int32 KMLMake_Line(Char *szKML, Int32 &nIdxTotal, Int32 &nIdxLine, Int32 &nTile, Int32 &nIdxVertex, Int32 nVertex);



	NeTvasVersion	m_eTvasVersion;
	TVS_Data		*m_pTvasData;

	Bool m_bTG;
	Bool m_bHL;
};

#endif //__TVAS_PARSER_HEADER__
