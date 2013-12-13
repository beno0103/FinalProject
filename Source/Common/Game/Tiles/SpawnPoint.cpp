//
//  SpawnPoint.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "SpawnPoint.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


SpawnPointTile::SpawnPointTile(const char* textureName) : Tile(TileTypeStartPoint, textureName, true)
{
    
}

SpawnPointTile::~SpawnPointTile()
{
    
}

const char* SpawnPointTile::getType()
{
    return TILE_STARTPOINT_TYPE;
}
