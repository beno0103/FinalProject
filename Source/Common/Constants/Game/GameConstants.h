#ifndef GAME_CONSTANTS_H
#define GAME_CONSTANTS_H

#include "../../OpenGL/OpenGLColor.h"

//Game Constants
extern const char* GAME_SCREEN_NAME;

//Tile Constants
extern const char* TILE_GROUND_TYPE;
extern const char* TILE_SNOW_TYPE;
extern const char* TILE_TREE_TYPE;
extern const char* TILE_ROCK_TYPE;
extern const char* TILE_ICE_TYPE;
extern const char* TILE_WATER_TYPE;
extern const int TILE_PADDING;
extern const char* TILE_ENDPOINT_TYPE;
extern const char* TILE_STARTPOINT_TYPE;
extern const char* TILE_TOWER_TYPE;

//Player Constants

extern const int PLAYER_SIZE;
extern const float PLAYER_SPEED;
extern const float ENEMY_SPEED;
extern const OpenGLColor PLAYER_INSIDE_COLOR;
extern const OpenGLColor PLAYER_OUTLINE_COLOR;

//Hero constants
extern const char* HERO_TYPE;
extern const int HERO_COUNT;

//Enemy Constants
extern const char* ENEMY_TYPE;
extern const int ENEMY_COUNT;

//Pickup COnstants
extern const char* AMMO_PICKUP_TYPE;
extern const char* GOLD_PICKUP_TYPE;


#endif 