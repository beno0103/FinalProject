//
//  TreeTile.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-11.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "TreeTile.h"
#include "../../OpenGL/OpenGL.h"
#include "../../Constants/Constants.h"


TreeTile::TreeTile(const char* textureName) : Tile(TileTypeTree, textureName, false)
{
    
}

TreeTile::~TreeTile()
{
    
}

const char* TreeTile::getType()
{
    return TILE_TREE_TYPE;
}

