//
//  IceTile.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-04.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__IceTile__
#define __GAM_1514_OSX_Game__IceTile__

#include "Tile.h"


class IceTile : public Tile
{
public:
	IceTile(const char* textureName = RES_TILE_ICE);
	virtual ~IceTile();
    
    //Return the type of the tile
    const char* getType();
    
    float getTileSpeed();
};

#endif
