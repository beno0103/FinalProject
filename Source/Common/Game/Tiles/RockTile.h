//
//  RockTile.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef ROCK_TILE_H
#define ROCK_TILE_H

#include "Tile.h"


class RockTile : public Tile
{
public:
	RockTile(const char* textureName = RES_TILE_ROCK);
	virtual ~RockTile();
    
    //Return the type of the tile
    const char* getType();
};

#endif
