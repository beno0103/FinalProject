//
//  EndPoint.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__EndPoint__
#define __GAM_1514_OSX_Game__EndPoint__

#include "Tile.h"


class EndPointTile : public Tile
{
public:
	EndPointTile(const char* textureName = RES_TILE_ENDPOINT);
	virtual ~EndPointTile();
    
    //Return the type of the tile
    const char* getType();
};

#endif
