//
//  IceTile.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-04.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "IceTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


IceTile::IceTile(const char* textureName) : Tile(TileTypeIce, textureName, true)
{
    
}

IceTile::~IceTile()
{
    
}

const char* IceTile::getType()
{
    return TILE_ICE_TYPE;
}

float IceTile::getTileSpeed()
{
    return 1.1f;
}

