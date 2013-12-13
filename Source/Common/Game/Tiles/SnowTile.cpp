//
//  SnowTile.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "SnowTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


SnowTile::SnowTile(const char* textureName) : Tile(TileTypeSnow, textureName, false)
{
    
}

SnowTile::~SnowTile()
{
    
}

const char* SnowTile::getType()
{
    return TILE_SNOW_TYPE;
}

float SnowTile::getTileSpeed()
{
    return 0.5f;
}
