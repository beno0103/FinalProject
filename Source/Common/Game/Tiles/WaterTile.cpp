//
//  WaterTile.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-04.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WaterTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


WaterTile::WaterTile(const char* textureName) : Tile(TileTypeWater, textureName, false)
{
    
}

WaterTile::~WaterTile()
{
    
}

const char* WaterTile::getType()
{
    return TILE_WATER_TYPE;
}

