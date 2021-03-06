//
//  LevelConstants.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef LEVEL_CONSTANTS_H
#define LEVEL_CONSTANTS_H

//Global enum for the Level's tile types,
//add additional tile types in this enum
enum TileType
{
  TileTypeGround = 1, //(0000 0001)
  TileTypeIce = 2,    //(0000 0010)
  TileTypeWater = 4,  //(0000 0100)
  TileTypeRock = 8,   //(0000 1000)
  TileTypeTree = 16,
  TileTypeSnow = 32,
  TileTypeStartPoint = 64,
  TileTypeEndPoint = 128,
    
  //This count value MUST now be manually updated when a new tile type is added
  TileTypeCount = 8
    ,
  TileTypeUnknown = -1
};

enum PickupType
{
    PickupTypeAmmo = 256, //(0100 0000)
    PickupTypeGold = 512, //(1000 0000)
    
    //This count value MUST now be manually updated when a new pickup type is added
    PickupTypeCount = 1,
    PickupTypeUnknown = -1
};

//Level editor screen name
extern const char* LEVEL_EDITOR_SCREEN_NAME;

//Empty Level Constants
extern const int EMPTY_LEVEL_TILE_SIZE;
extern const int EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX;
extern const float GAME_SPEED;

#endif
