//
//  RockTile.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "RockTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


RockTile::RockTile(const char* textureName) : Tile(TileTypeRock, textureName, false)
{
    
}

RockTile::~RockTile()
{
    
}

const char* RockTile::getType()
{
    return TILE_ROCK_TYPE;
}

