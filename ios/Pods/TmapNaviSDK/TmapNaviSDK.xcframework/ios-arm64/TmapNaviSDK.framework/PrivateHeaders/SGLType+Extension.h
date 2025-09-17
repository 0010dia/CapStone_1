//
//  SGLType+Extension.h
//  TMFactory
//
//  Created by 1001094 on 2015. 9. 14..
//  Copyright (c) 2015년 sk planet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "sgl_cmntype_objc.h"
#import "mapmatch_def.h"


#ifdef __cplusplus
extern "C" {
#endif

// DOUBLE_VERTEX
DOUBLE_VERTEX DoubleVertexMake(double x, double y);
DOUBLE_VERTEX DoubleVertexNext(DOUBLE_VERTEX vt1, DOUBLE_VERTEX vt2);

DOUBLE_VERTEX MinDoubleVertex(DOUBLE_VERTEX *vertices, SInt32 count);
DOUBLE_VERTEX MaxDoubleVertex(DOUBLE_VERTEX *vertices, SInt32 count);
RECT32 Rect32WithDoubleVertex(DOUBLE_VERTEX v1, DOUBLE_VERTEX v2);

BOOL isKoreaVertex(DOUBLE_VERTEX vertex);
BOOL isZeroDoubleVertex(DOUBLE_VERTEX vertex);
BOOL isEqualDoubleVertex(DOUBLE_VERTEX v1, DOUBLE_VERTEX v2);

// VERTEX16
VERTEX16 Vertex16Make(UInt16 x, UInt16 y);
VERTEX16 Vertex16Zero();


// VERTEX32
VERTEX32 Vertex32Zero();
VERTEX32 Vertex32Make(SInt32 x, SInt32 y);
VERTEX32 MinVertex32(VERTEX32 *vertices, SInt32 count);
VERTEX32 MaxVertex32(VERTEX32 *vertices, SInt32 count);
VERTEX32 Vertex32Offset(VERTEX32 vt, SInt32 dx, SInt32 dy);
VERTEX32 Vertex32Next(VERTEX32 vt1, VERTEX32 vt2);
BOOL isKoreaVertex32(VERTEX32 vertex);
BOOL isZeroVertex32(VERTEX32 vertex);
BOOL isEqualVertex32(VERTEX32 v1, VERTEX32 v2);

    
// VERTEXZ32
VERTEXZ32 Vertexz32Make(SInt32 x, SInt32 y, SInt32 z);
VERTEXZ32 Vertexz32WithVertex32(VERTEX32 param);



// RECT32
RECT32 Rect32Zero();
RECT32 Rect32Make(SInt32 x, SInt32 y, SInt32 w, SInt32 h);
RECT32 Rect32WithVertex32(VERTEX32 v1, VERTEX32 v2);
RECT32 Rect32Inset(RECT32 rect, SInt32 dx, SInt32 dy);
    
    
// MM_VERTEX
MM_VERTEX MMVertexOffset(MM_VERTEX vertex, CGFloat dx, CGFloat dy);
MM_VERTEX MMVertexMake(double x, double y, float z, float angle);
MM_VERTEX MMVertexWithVertex32Angle(DOUBLE_VERTEX param, float angle);
    
#ifdef __cplusplus
}
#endif
