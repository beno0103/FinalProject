//
//  Level.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Level.h"
#include "Player.h"
#include "Hero.h"
#include "Enemy.h"
#include "PathFinder.h"
#include "../Math/GDRandom.h"
#include "Tiles/Tile.h"
#include "Tiles/GroundTile.h"
#include "Tiles/IceTile.h"
#include "Tiles/WaterTile.h"
#include "Tiles/SnowTile.h"
#include "Tiles/RockTile.h"
#include "Tiles/TreeTile.h"
#include "Tiles/EndPoint.h"
#include "Tiles/SpawnPoint.h"

#include "Pickups/Pickup.h"
#include "Pickups/AmmoPickup.h"
#include "Pickups/GoldPickup.h"

#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Utils/Utils.h"
#include "../UI/UIFont.h"
#include <stdlib.h>
#include <fstream>
#include <sstream>


Level::Level(bool isEditingLevel) :
    m_HorizontalTiles(0),
    m_VerticalTiles(0),
    m_TileSize(EMPTY_LEVEL_TILE_SIZE),
    m_PlayerStartingTileIndex(EMPTY_LEVEL_STARTING_PLAYER_TILE_INDEX),
    m_Hero(NULL),
    m_Tiles(NULL),
    m_SelectedTileIndex(-1),
    m_PaintTileScoring(false),
    m_PaintTileIndexes(false)
{
    //m_myHealthPrint = new UIFont("Fonts");
    
    //Create the player object
    if(isEditingLevel == false)
    {
        //Create the hero object
        for(int i = 0; i < 1; i++)
        {
            Hero* hero = new Hero(this);
            m_Hero.push_back(hero);
        }
        
        for(int i = 0; i < 1; i++)
        { 
            Enemy* enemy = new Enemy(this);
            m_Enemies.push_back(enemy);
        }
        
        //Add specific tile indexes to your spawn pointd vrvtor, these are going to be
        //Where the players spawn.
        m_Spawnpoints.push_back(2); // put in for loop
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
        m_Spawnpoints.push_back(2);
  

        
        //You must have at least the same number of spawn points as you do enemies + heroes, 10 enemies +1 hero
        //= 11 spawn points.
        
    }
    
    //Calculate the number of horizontal and vertical tiles
    m_HorizontalTiles = ScreenManager::getInstance()->getScreenWidth() / m_TileSize;
    m_VerticalTiles = ScreenManager::getInstance()->getScreenHeight() / m_TileSize;
    
    //Allocate the tiles array, the inheriting class will populate this array with Tile objects
	m_Tiles = new Tile*[m_HorizontalTiles * m_VerticalTiles];
    
    //Initialize all the tiles to NULL
    for(int i = 0; i < m_HorizontalTiles * m_VerticalTiles; i++)
    {
        m_Tiles[i] = NULL;
    }
    
    //Load an empty level
    load(NULL);
}

Level::~Level()
{
    //Delete the player object
    for(int i = 0; i < m_Hero.size(); i++)
    {
        delete m_Hero.at(i);
        m_Enemies.at(i) = NULL;
    }
    
    for(int i = 0; i < m_Enemies.size(); i++)
    {
        delete m_Enemies.at(i);
        m_Enemies.at(i) = NULL;
    }
    
    m_Enemies.clear();
    
    //Clear the spawn points vector
    m_Spawnpoints.clear();
    
    //Delete the tiles array, the inheriting class
    //must delete the object in this array itselfƒ
	if(m_Tiles != NULL)
	{
        //Cycle through and delete all the tile objects in the array
        for(int i = 0; i < getNumberOfTiles(); i++)
        {
            if(m_Tiles[i] != NULL)
            {
                delete m_Tiles[i];
                m_Tiles[i] = NULL;
            }
        }
        
		delete[] m_Tiles;
		m_Tiles = NULL;
	}
}

void Level::update(double aDelta)
{
    //std::stringstream ss;
   //ss << "My Health " << m_Hero.at(0)->getHealth();
    //std::string s = ss.str();
    
    //char* cstr = new char[s.length() + 1];
    //strcpy(cstr, s.c_str());
    
    //m_myHealthPrint->setText(cstr);
    
    //m_myHealthPrint->setText("My health: ");
    
	//Update all the game tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->update(aDelta);
		}
	}
    
	//Update the Hero
    for(int i = 0; i < m_Hero.size(); i++)
    {
        if(m_Hero.at(i)->getIsActive() == true)
        {
            m_Hero.at(i)->update(aDelta);
        }
    }
    
    //Update the enemy object
    for(int i = 0; i < m_Enemies.size(); i++)
    {
        if(m_Enemies.at(i)->getIsActive() == true)
        {
                m_Enemies.at(i)->update(aDelta);
        }
    }
    
//    m_Delay--;
//    if(m_Delay == 0)
//    {
//        m_Delay = 30;
//    }
//    
//    if(m_Delay == 30 && m_Enemies.size() < 30)
//    {
//        m_EnemyAmount ++;
//        Enemy* enemy = new Enemy(this);
//        m_Enemies.push_back(enemy);
//        m_Enemies.at(m_EnemyAmount)->setCurrentTile(getTileForIndex(2));
//        m_Enemies.at(m_EnemyAmount)->m_Speed = ENEMY_SPEED;
//    }
}

void Level::paint()
{
	//Cycle through and paint all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
        //Safety check the tile
		if(m_Tiles[i] != NULL)
		{
            //Paint the tile
            m_Tiles[i]->paint();
            
            //If the paint tile indexes flag is set to true,
            //draw the index number on the tiles
            if(m_PaintTileIndexes == true)
            {
                m_Tiles[i]->paintIndex(i);
            }
		}
	}
    
    //Paint the spawn points
    for(int i = 0; i < m_Spawnpoints.size(); i++)
    {
        Tile* tile = getTileForIndex(m_Spawnpoints.at(i));
        float x = tile->getX() + (tile->getWidth() / 2.0f);
        float y = tile->getY() + (tile->getHeight() / 2.0f);
        OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorBlue());
        OpenGLRenderer::getInstance()->drawCircle(x, y, tile->getWidth() / 2.0f - 4.0f, false);
    }
    
    for(int i = 0; i < m_Hero.size(); i++)
    {
        if(m_Hero.at(i)->getIsActive() == true)
        {
            m_Hero.at(i)->paint();
        }
    }
    
    for(int i = 0; i < m_Enemies.size(); i++)
    {
        if(m_Enemies.at(i)->getIsActive() == true)
        {
            m_Enemies.at(i)->paint();
        }
    }
    
    //if(m_myHealthPrint != NULL)
    //{
        //m_myHealthPrint->draw(100.0f, 100.0f);
    //}
}

void Level::reset()
{
	//Cycle through and reset all the tiles
	for(int i = 0; i < getNumberOfTiles(); i++)
	{
		if(m_Tiles[i] != NULL)
		{
			m_Tiles[i]->reset();
		}
	}
    
    //Make a Player* vector to hold the hero and enemies for reset()
    std::vector<Player*> players;
    
    for(int i = 0; i < m_Hero.size(); i++)
    {
        players.push_back(m_Hero.at(i));
    }
    
    for(int i = 0; i < m_Enemies.size(); i++)
    {
        players.push_back(m_Enemies.at(i));
    }
    
    //Random number generator for the spawn indexes
    GDRandom random;
    random.randomizeSeed();
    int tileIndex = -1;
    std::vector<int> usedTileIndexes;
    
    //Cycle through the Player objects
    for(int i = 0; i < players.size(); i++)
    {
        //Set tileIndex to -1
        tileIndex = -1;
        
        while(tileIndex == -1)
        {
            tileIndex = random.random(m_Spawnpoints.size());
            
            //Safety check that it is a walkable tile
            if(getTileForIndex(tileIndex)->isWalkableTile() == false)
            {
                tileIndex = -1;
            }
            else
            {
                //Cycle through and ensure the index hasn't already bee used
                for(int j = 0; j < usedTileIndexes.size(); j++)
                {
                    if(usedTileIndexes.at(j) == tileIndex)
                    {
                        tileIndex = -1;
                        break;
                    }
                }
                
                //Safety check that tileIndex isnt -1
                if(tileIndex != -1)
                {
                    int index = m_Spawnpoints.at(tileIndex);
                    players.at(i)->setCurrentTile(getTileForIndex(index));
                    m_Hero.at(0)->setCurrentTile(getTileForIndex(12));
                    players.at(i)->reset();
                    usedTileIndexes.push_back(tileIndex);
                }
            }
        }
    }
}

void Level::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    for(int i = 0; i < m_Hero.size(); i++)
    {
        m_Hero.at(i)->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
}

void Level::mouseLeftClickUpEvent(float aPositionX, float aPositionY)
{
	for(int i = 0; i < m_Hero.size(); i++)
    {
        m_Hero.at(i)->mouseLeftClickUpEvent(aPositionX, aPositionY);
    }
}

void Level::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_R)
    {
        reset();
    }
    else if(keyCode == KEYCODE_S)
    {
        togglePaintTileScoring();
    }
    else if(keyCode == KEYCODE_I)
    {
        togglePaintTileIndexes();
    }
    else if(keyCode == KEYCODE_C)
    {
        load(NULL);
    }
    else if(keyCode == KEYCODE_D)
    {
        for(int i = 0; i < m_Hero.size(); i++)
        {
            m_Hero.at(i)->getPathFinder()->togglePathFindingDelay();
        }
    }
    else if(keyCode == KEYCODE_I)
    {
        togglePaintTileIndexes();
    }
    else
    {
        for(int i = 0; i < m_Hero.size(); i++)
        {
            m_Hero.at(i)->keyUpEvent(keyCode);
        }
    }
    
}

void Level::load(const char* levelName)
{
    //If the level name isn't NULL load the level from the filesystem,
    //if it is NULL load an empty level with just ground tiles
    if(levelName != NULL)
    {
        //TODO: save the level
        std::ifstream inputStream;
        
        inputStream.open(levelName, std::ifstream::in | std::ifstream::binary);
        
        if(inputStream.is_open() == true)
        {
            inputStream.seekg(0, inputStream.end);
            long long bufferSize = inputStream.tellg();
            
            inputStream.seekg(0, inputStream.beg);
            
            int* buffer = new int [bufferSize];
            
            inputStream.read((char*)buffer, (int)bufferSize);
            
            inputStream.close();
            
            for(int i = 0; i < bufferSize; i++)
            {
                PickupType pickupType = PickupTypeUnknown;
                
                //Check to see if the buffer[i] contains the AmmoPickup bit
                if((buffer[i] &  PickupTypeAmmo) > 0)
                {
                    //It does
                    pickupType = PickupTypeAmmo;
                    
                    //Clear the AmmoPickup bit
                    buffer[i] &= ~PickupTypeAmmo;
                }
                
                //Set the tile type
                setTileTypeAtIndex((TileType)buffer[i], i);
                
                //Set the pickup type
                setPickupTypeAtIndex(pickupType, i);
            }
            
            for(int j = 0; j < bufferSize; j++)
            {
                PickupType pickupType = PickupTypeUnknown;
                
                //Check to see if the buffer[i] contains the AmmoPickup bit
                if((buffer[j] &  PickupTypeGold) > 0)
                {
                    //It does
                    pickupType = PickupTypeGold;
                    
                    //Clear the AmmoPickup bit
                    buffer[j] &= ~PickupTypeGold;
                }
                
                //Set the tile type
                setTileTypeAtIndex((TileType)buffer[j], j);
                
                //Set the pickup type
                setPickupTypeAtIndex(pickupType, j);
            }
            
            delete[] buffer;
            buffer = NULL;
        }
        
    }
    else
    {
        GDRandom rand;
        rand.randomizeSeed();
        
        for(int i = 0; i < getNumberOfTiles(); i++)
        {
            TileType tileType = TileTypeGround;
            setTileTypeAtIndex(tileType, i);
        }
    }
    
    //The level is loaded, reset everything
    reset();
}

void Level::save(const char* levelName)
{
    //TODO: save the level
	//Check the pickup video at 23:45
    
    int bufferSize = getNumberOfTiles();
    int* buffer = new int[bufferSize];
    
    for(int i = 0; i <bufferSize; i++)
    {
        buffer[i] = (int)getTileTypeForIndex(i);
        
        
        //Save the tile's pickup if there is one
        if(m_Tiles[i]->getPickup() != NULL && m_Tiles[i]->getPickup()->getPickupType() != PickupTypeUnknown)
        {
            buffer[i] |= m_Tiles[i]->getPickup()->getPickupType();
        }
        
    }
    
    std::ofstream outputStream;
    outputStream.open(levelName, std::ofstream::out | std::ofstream::binary);
    
    if(outputStream.is_open() == true)
    {
        outputStream.write((char*)buffer, bufferSize * sizeof(int));
        outputStream.close();
    }
    
    delete[] buffer;
    buffer = NULL;
}

TileType Level::getTileTypeForIndex(int index)
{
    if(index >= 0 && index < getNumberOfTiles())
    {
        return m_Tiles[index]->getTileType();
    }
    return TileTypeUnknown;
}

unsigned int Level::getNumberOfTiles()
{
    return getNumberOfHorizontalTiles() * getNumberOfVerticalTiles();
}

unsigned int Level::getNumberOfHorizontalTiles()
{
	return m_HorizontalTiles;
}

unsigned int Level::getNumberOfVerticalTiles()
{
	return m_VerticalTiles;
}

bool Level::validateTileCoordinates(int aCoordinatesX, int aCoordinatesY)
{
    if(aCoordinatesX < 0 || aCoordinatesY < 0 || aCoordinatesX >= getNumberOfHorizontalTiles() || aCoordinatesY >= getNumberOfVerticalTiles())
	{
        return false;
    }
    return true;
}

int Level::getTileCoordinateForPosition(int aPosition)
{
	return (aPosition / m_TileSize);
}

int Level::getTileIndexForPosition(int aPositionX, int aPositionY)
{
	int coordinatesX = getTileCoordinateForPosition(aPositionX);
	int coordinatesY = getTileCoordinateForPosition(aPositionY);
	return getTileIndexForCoordinates(coordinatesX, coordinatesY);
}

int Level::getTileIndexForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	//Validate the coordinates, then calculate the array index
	if(validateTileCoordinates(aCoordinatesX, aCoordinatesY) == true)
	{
		return aCoordinatesX + (aCoordinatesY * getNumberOfHorizontalTiles());
	}
    
	return -1;
}

int Level::getTileIndexForTile(Tile* aTile)
{
	return getTileIndexForPosition(aTile->getX(), aTile->getY());
}

int Level::getTileIndexForPlayer(Player* player)
{
    return getTileIndexForPosition(player->getX(), player->getY());
}

Tile* Level::getTileForPosition(int aPositionX, int aPositionY)
{
	return getTileForIndex(getTileIndexForPosition(aPositionX, aPositionY));
}

Tile* Level::getTileForCoordinates(int aCoordinatesX, int aCoordinatesY)
{
	return getTileForIndex(getTileIndexForCoordinates(aCoordinatesX, aCoordinatesY));
}

Tile* Level::getTileForIndex(int aIndex)
{
    //Safety check the index bounds
	if(aIndex >= 0 && aIndex < getNumberOfTiles())
	{
		return m_Tiles[aIndex];
	}
    
    //If we got here, it means the index passed in was out of bounds
	return NULL;
}

PickupType Level::getPickupTypeForIndex(int index)
{
    if(index >= 0 && index < getNumberOfTiles())
    {
        if(m_Tiles[index]->getPickup() != NULL)
        {
            return m_Tiles[index]->getPickup()->getPickupType();
        }
    }
    return PickupTypeUnknown;
}

Tile* Level::getTileForPlayer(Player* player)
{
    return getTileForPosition(player->getX(), player->getY());
}

void Level::setTileTypeAtPosition(TileType tileType, int positionX, int positionY)
{
    setTileTypeAtIndex(tileType, getTileIndexForPosition(positionX, positionY));
}

void Level::setTileTypeAtCoordinates(TileType tileType, int coordinatesX, int coordinatesY)
{
    setTileTypeAtIndex(tileType, getTileIndexForCoordinates(coordinatesX, coordinatesY));
}

void Level::setTileTypeAtIndex(TileType tileType, int index)
{
    //Safety check the index
    if(index >= 0 && index < getNumberOfTiles())
	{
        //Don't replace the tile if its the same type of tile that already exists
        if(m_Tiles[index] != NULL && m_Tiles[index]->getTileType() == tileType)
        {
            return;
        }
    
        //Delete the tile at the index, if one exists
        if(m_Tiles[index] != NULL)
        {
            delete m_Tiles[index];
            m_Tiles[index] = NULL;
        }
        //****************************************************
        //NON-WALKABLE TILES ARE FALSE!
        //****************************************************
        //Create the new tile based on the TileType
        switch (tileType)
        {

            case TileTypeGround:
                m_Tiles[index] = new GroundTile();
                break;
                
            case TileTypeIce:
                m_Tiles[index] = new IceTile();
                break;
                
            case TileTypeWater:
                m_Tiles[index] = new WaterTile();
                break;
                
            case TileTypeRock:
                m_Tiles[index] = new RockTile();
                break;
                
            case TileTypeTree:
                m_Tiles[index] = new TreeTile();
                break;
                
            case TileTypeSnow:
                m_Tiles[index] = new SnowTile();
                break;
                
            case TileTypeStartPoint:
                m_Tiles[index] = new SpawnPointTile();
                break;
            
            case TileTypeEndPoint:
                m_Tiles[index] = new EndPointTile();
                break;

            case TileTypeUnknown:
            default:
                m_Tiles[index] = NULL;
                break;
        }
        
        //Calculate the coordinates and set the tile position and size
        int coordinateX = (index % getNumberOfHorizontalTiles());
        int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());
        m_Tiles[index]->setPosition(coordinateX  * m_TileSize, coordinateY * m_TileSize);
        m_Tiles[index]->setSize(m_TileSize, m_TileSize);
	}
}

void Level::setPickupTypeAtPosition(PickupType pickupType, int positionX, int positionY)
{
    setPickupTypeAtIndex(pickupType, getTileIndexForPosition(positionX, positionY));
}

void Level::setPickupTypeAtCoordinates(PickupType pickupType, int coordinateX, int coordinateY)
{
    setPickupTypeAtIndex(pickupType, getTileIndexForCoordinates(coordinateX, coordinateY));
}

void Level::setPickupTypeAtIndex(PickupType pickupType, int index)
{
    //Safety check the index
    if(index >= 0 && index < getNumberOfTiles())
    {
        //Don't replace the tile if a pickup of the same type already exists there
        if(m_Tiles[index] != NULL && m_Tiles[index]->getPickup() != NULL)
        {
            if(m_Tiles[index]->getPickup()->getPickupType() == pickupType)
            {
                return;
            }
        }
        
        //Delete the pickup at the index if one exists already
        if(m_Tiles[index] != NULL)
        {
            if(m_Tiles[index]->getPickup() != NULL)
            {
                m_Tiles[index]->setPickup(NULL);
            }
                //Create a new pickup object based on the PickupType
                switch(pickupType)
                {
                    case PickupTypeAmmo:
                    {
                        GDRandom random;
                        random.randomizeSeed();
                        
                        int min = 5;
                        int max = 30;
                        int ammo = min + random.random(max-min);
                        
                        m_Tiles[index]->setPickup(new AmmoPickup(ammo));
                        break;
                    }
                        
                    case PickupTypeGold:
                    {
                        m_Tiles[index]->setPickup(new GoldPickup(10));
                        break;
                    }
                        //TODO: Make sure to add future pickups here for object creation
                        
                    case PickupTypeUnknown:
                    default:
                        break;
                }
            
            //Set the pickups position and size
            if(m_Tiles[index]->getPickup() != NULL)
            {
                int coordinateX = (index % getNumberOfHorizontalTiles());
                int coordinateY = ((index - coordinateX) / getNumberOfHorizontalTiles());
                
                Pickup* pickup = m_Tiles[index]->getPickup();
                float x = (coordinateX * m_TileSize) + (m_TileSize - pickup->getWidth()) / 2.0f;
                float y = (coordinateY * m_TileSize) + (m_TileSize - pickup->getHeight()) / 2.0f;
                pickup->setPosition(x, y);
            }
        }
        
        
    }
}

void Level::togglePaintTileScoring()
{
    m_PaintTileScoring = !m_PaintTileScoring;
}

void Level::togglePaintTileIndexes()
{
    m_PaintTileIndexes = !m_PaintTileIndexes;
}

void Level::setSelectedTileIndex(int aSelectedIndex)
{
	//Deselect the previously selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(false);
	}
    
	//Set the new tile index
	m_SelectedTileIndex = aSelectedIndex;
    
	//Selected the newly selected tile
	if(m_SelectedTileIndex >= 0 && m_SelectedTileIndex < getNumberOfTiles())
	{
		m_Tiles[m_SelectedTileIndex]->setIsSelected(true);
	}
}

int Level::getSelectedTileIndex()
{
    return m_SelectedTileIndex;
}

std::vector<Hero*> Level::getHeroes()
{
    return m_Hero;
}

std::vector<Enemy*> Level::getEnemies()
{
    return m_Enemies;
}
