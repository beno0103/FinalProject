//
//  SpawnPoint.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__SpawnPoint__
#define __GAM_1514_OSX_Game__SpawnPoint__

#include "Tile.h"


class SpawnPointTile : public Tile
{
public:
	SpawnPointTile(const char* textureName = RES_TILE_STARTPOINT);
	virtual ~SpawnPointTile();
    
    //Return the type of the tile
    const char* getType();
};

#endif /* defined(__GAM_1514_OSX_Game__SpawnPoint__) */
