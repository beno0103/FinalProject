#include "GameConstants.h"


//Game Constants
const char* GAME_SCREEN_NAME = "Game";

//Tiles Constants
const char* TILE_GROUND_TYPE = "GroundTile";
const char* TILE_SNOW_TYPE = "SnowTile";
const char* TILE_TREE_TYPE = "TreeTile";
const char* TILE_ROCK_TYPE = "RockTile";
const char* TILE_ICE_TYPE = "IceTile";
const char* TILE_WATER_TYPE = "WaterTile";
const char* TILE_ENDPOINT_TYPE = "EndPointTile";
const char* TILE_STARTPOINT_TYPE = "StartPointTile";
const char* TILE_TOWER_TYPE = "TowerTile";

const int TILE_PADDING = 2;

//Player Constants

const int PLAYER_SIZE = 24;
const float PLAYER_SPEED = 300.0f;
const float ENEMY_SPEED = 150.0f;
const OpenGLColor PLAYER_INSIDE_COLOR = OpenGLColor(0.0f, 0.0f, 0.0f, 1.0f);
const OpenGLColor PLAYER_OUTLINE_COLOR = OpenGLColor(1.0f, 1.0f, 1.0f, 1.0f);

//Hero constants
const char* HERO_TYPE = "Hero";
const int HERO_COUNT = 5;

//Enemy constants
const char* ENEMY_TYPE = "Enemy";
const int ENEMY_COUNT = 5;

//Ammo pickup constants
const char* AMMO_PICKUP_TYPE = "AmmoPickup";

//Gold pickup constants
const char* GOLD_PICKUP_TYPE = "GoldPickup";
