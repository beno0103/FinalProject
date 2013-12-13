//
//  SnowTile.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef SNOW_TILE_H
#define SNOW_TILE_H

#include "Tile.h"


class SnowTile : public Tile
{
public:
	SnowTile(const char* textureName = RES_TILE_SNOW);
	virtual ~SnowTile();
    
    //Return the type of the tile
    const char* getType();
    float getTileSpeed();
};

#endif

