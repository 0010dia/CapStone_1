//
//  CMiOS.h
//  TmapNavi
//
//  Created by hj kim on 11. 9. 19..
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifdef __APPLE__
#ifndef __CMIOS_H__
#define __CMIOS_H__

#import <stdio.h>

void getiOSDocumentsPath( /*out*/char* pszPath, int lenPath );
FILE* fopen_iOS( const char* pszPath,const  char* opt );

#endif  
#endif

