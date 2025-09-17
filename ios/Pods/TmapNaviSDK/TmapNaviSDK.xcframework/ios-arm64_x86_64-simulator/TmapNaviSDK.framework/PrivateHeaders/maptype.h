/** \file maptype.h 
 * \brief Tile Identity Data Type
 *
 * 지도는 8 8 4 8 8 4로 자른 tile을 사용한다.
 *	top(실제존재 X) - [256도 x 256도]를 관리한다.
 *	level 6 - 32도 단위 [8 x 8]
 *	level 5 - 4 도 단위 [64 x 64]
 *	level 4 - 1 도 단위 [256 x 256]
 *	level 3 - 1/8 도 단위 [(256 x 8) x (256 x 8)]
 *	level 2 - 1/64 도 단위 [(256 x 64) x (256 x 64)]
 *	level 1 - 1/256 도 단위 [(256 x 256) x (256 x 256)]
 * Global한 좌표는 level 1의 한 tile을 2048로 분할한 단위를 기본단위로 사용한다.
 *	기본단위 - 1 / (256 x 2048) 도
 */

#ifndef _MAPTYPE_H_
#define _MAPTYPE_H_

///////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
#include "sgl_inc.h"

////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////


///개략 : 지도의 종류가 결정된 상황에서의 tile의 식별자
class NcTileID {
public:
    NcTileID();
    NcTileID(Int8 mlevel, const DOUBLE_VERTEX& mapidx);

#ifdef USEINLINE
    inline bool operator == (const NcTileID &);
    inline const NcTileID & operator = (const NcTileID &);
#else // ! USEINLINE
    bool operator == (const NcTileID &);
    const NcTileID & operator = (const NcTileID &);
#endif // USEINLINE    

public:
    Int8		m_mlevel;	// 현 tile의 level
    DOUBLE_VERTEX	m_mapidx;	// 현 tile의 index (m_level 에서)
};

/// 개략 : tiled map의 식별자
class NcTileIdentity {
public:
    NcTileIdentity();
    NcTileIdentity(UInt8, const NcTileID&);
    NcTileIdentity(UInt8, Int8, const DOUBLE_VERTEX&);

    void init(UInt8, const NcTileID&);
    void init(UInt8, Int8, const DOUBLE_VERTEX&);

#ifdef USEINLINE
    inline bool operator == (const NcTileIdentity &);
    inline const NcTileIdentity & operator = (const NcTileIdentity &);
#else // ! USEINLINE
    bool operator == (const NcTileIdentity &);
    const NcTileIdentity & operator = (const NcTileIdentity &);
#endif // USEINLINE    
    
public:
    UInt8		m_mtype;	// 지도의 type
    NcTileID		m_id;
};

#ifdef USEINLINE
#include "tileiden.inl"
#endif // USEINLINE

#endif // _MAPTYPE_H_
