//
//  EndPoint.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-09.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "EndPoint.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


EndPointTile::EndPointTile(const char* textureName) : Tile(TileTypeEndPoint, textureName, true)
{
    
 }

EndPointTile::~EndPointTile()
{
    
}

const char* EndPointTile::getType()
{
    return TILE_ENDPOINT_TYPE;
}

