//
//  Player.cpp
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Player.h"
#include "Level.h"
#include "PathNode.h"
#include "Tiles/Tile.h"

#include "Pickups/Pickup.h"
#include "Pickups/AmmoPickup.h"
#include "Pickups/GoldPickup.h"

#include "../Utils/Utils.h"
#include "../Math/GDRandom.h"

#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include <stdlib.h>
#include <algorithm>
#include <math.h>

Player::Player(Level* aLevel)
{
    m_Level = aLevel;
    
    //Create a PathFinder Object
    m_PathFinder = new PathFinder(aLevel, this);
    
    //Initialize the current and destination tiles to NULL
    m_CurrentTile = NULL;
    m_DestinationTile = NULL;
    
    //Initialize the animation member variables
    m_CanAnimate = false;
    m_AbortAnimation = false;
    m_AnimationPathNodeIndex = -1;
    
    //Set the player speed
    m_Speed = PLAYER_SPEED;
    
    //Initialize the ammo and the health
    m_Ammo = 100;
    m_Health = 3;
    
    //Set the number of players
    m_NumberOfPlayers = 5;
    
    //m_Speed = PLAYER_SPEED;
    
    //Initialize the player's size
    setSize(PLAYER_SIZE, PLAYER_SIZE);
}

Player::~Player()
{
    if(m_PathFinder != NULL)
    {
        delete m_PathFinder;
        m_PathFinder = NULL;
    }
    
    //Set the current and desination tiles to NULL
	m_CurrentTile = NULL;
	m_DestinationTile = NULL;
}

void Player::update(double aDelta)
{
    //Update the projectiles
    for(int i = 0; i < m_Projectiles.size(); i++)
    {
        if(m_Projectiles.at(i)->getIsActive() == true)
        {
            m_Projectiles.at(i)->update(aDelta);
        }
    }
    
    //remove ay 'inactive' projectiles for the projectiles vector
    int index = 0;
    while(index != m_Projectiles.size())
    {
        if(m_Projectiles.at(index)->getIsActive() == false)
        {
            Log::debug("Deleting projectile");
            
            //Dele the projectile and remove it from the vector
            delete m_Projectiles.at(index);
            m_Projectiles.erase(m_Projectiles.begin() + index);
        }
        else
        {
            index++;
        }
    }
    
    
    //Update the path finder
    if(m_PathFinder->isSearchingPath() == true)
    {
        m_PathFinder->update(aDelta);
    }
    
    //Handle player animation
    if(isAnimating() == true && m_AnimationPathNodeIndex > -1)
    {
        PathNode* pathNode = m_PathFinder->getPathNodeAtIndex(m_AnimationPathNodeIndex);
        Tile* tile = pathNode != NULL ? pathNode->getTile() : NULL;
        
        //Safety check that tile isnt NULL
        if(tile != NULL)
        {
            //Calculate the center of the file
            float centerX = tile->getX() + (tile->getWidth() - getWidth()) / 2.0f;
            float centerY = tile->getY() + (tile->getHeight() - getHeight()) / 2.0f;
            
            //Get the speed for the tile the player is on
            Tile* playerTile = m_Level->getTileForPosition(getX(), getY());
            float speed = playerTile->getTileSpeed();
            
            //Next calculate how much the player should animate this update() call,
            //use the animate() method to help calculate
            float playerX = animate(getX(), centerX, aDelta, speed);
            float playerY = animate(getY(), centerY, aDelta, speed);
            setPosition(playerX, playerY);
            
            //Has the player reach the center of the tile?
            if(playerX == centerX && playerY == centerY)
            {
                m_AnimationPathNodeIndex++;
                
                //Set the current tile's path flag to false
                m_CurrentTile->setIsPath(false);
                
                //Set the new current tile
                setCurrentTile(tile);
                
                //Does the tile have a pickup on it
                if(tile->getPickup() != NULL)
                {
                    handlePickup(tile->getPickup());
                    
                    //Set the tile's pick to NULL, since it was picked up
                    tile->setPickup(NULL);
                }
                
                //Are we done animating completely?
                if(m_AnimationPathNodeIndex >= m_PathFinder->getPathSize())
                {
                    stopAnimating();
                    m_CurrentTile->setIsPath(false);
                }
                
                //Is the abort animation flag set?
                if(m_AbortAnimation == true)
                {
                    //Reset the flag to false
                    m_AbortAnimation = false;
                    
                    //Begin searching for a new path
                    findPath();
                }
            }
        }
        else
        {
            //Is the abort animation flag set?
            if(m_AbortAnimation == true)
            {
                //Reset the flag to false
                m_AbortAnimation = false;
                
                //Begin searching for a new path
                findPath();
            }
        }
    }
}

void Player::paint()
{
    //Cycle through and paint all the 'active' projectiles
    for(int i = 0; i < m_Projectiles.size(); i++)
    {
        if(m_Projectiles.at(i)->getIsActive() == true)
        {
            m_Projectiles.at(i)->paint();
        }
    }
        OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_INSIDE_COLOR);
        OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2);
        OpenGLRenderer::getInstance()->setForegroundColor(PLAYER_OUTLINE_COLOR);
        OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2, false);
}

void Player::reset()
{
    //Stops any animations that are going on
    stopAnimating();
    
    //Reset the path finder
    m_PathFinder->reset();
    
    //Set the destination tile to NULL
    m_DestinationTile = NULL;
    
    //Set the player's state to 'active'
    setIsActive(true);
    m_Health = 3;
}

void Player::fireProjectile(float x, float y)
{
    //Safety check that there is some ammo left
    if(m_Ammo > 0)
    {
        m_Ammo--;
        
        //Create a new projectile object
        Projectile* projectile = new Projectile(this, 1, 250.0f);
        projectile->setPosition(getX() + (getWidth() / 2.0f), getY() + (getHeight() / 2.0f));
        projectile->setTarget(x, y);
        m_Projectiles.push_back(projectile);
        
        Log::debug("Fired projectile, %i ammo left", m_Ammo);
    }
    else
    {
        Log::debug("Can't fire projectile, no ammo left");
    }
}

void Player::applyDamage(int damage)  
{
    m_Health -= damage;
    
    if(m_Health <= 0)
    {
        m_Health = 0;
        setIsActive(false);
        
        Log::debug("Player is dead");

        int index = m_Level->getTileIndexForPlayer(this);
        
        GDRandom random;
        random.randomizeSeed();
        int value = random.random(10);
        if(value <= 4)
        {
            m_Level->setPickupTypeAtIndex(PickupTypeAmmo, index);
        }
        else
        {
            m_Level->setPickupTypeAtIndex(PickupTypeGold, index);
        }


		//Im sure this isnt supposed to be here, but the game ends when the player dies.
		//exit(1);
    }
    else
    {
        Log::debug("Player is hit, %i health remaining", m_Health);
    }
}

void Player::goldTotal(int goldStack)
{
    m_Gold += goldStack;

    Log::debug("Gold accumulated:", m_Gold);
}

void Player::setCurrentTile(Tile* tile)
{
	//Set the current tile pointer
	m_CurrentTile = tile;
    
	//Center the player's position on the tile
	setPosition(tile->getX() + ((tile->getWidth() - getWidth()) / 2), tile->getY() + ((tile->getHeight() - getHeight()) / 2));
}

void Player::setDestinationTile(Tile* tile)
{
	//Set the destination tile pointer
	m_DestinationTile = tile;
    
    //Start pathfinding
    if(isAnimating() == false)
    {
        findPath();
    }
    else
    {
        m_AbortAnimation = true;
    }
}

void Player::handlePickup(Pickup* pickup)
{
    switch(pickup->getPickupType())
    {
        case PickupTypeAmmo:
            m_Ammo += ((AmmoPickup*)pickup)->getAmmoCount();
            break;
            
        case PickupTypeGold:
            m_Gold += ((GoldPickup*)pickup)->getGoldCount();
            break;
            
        default:
            break;
    }
}

void Player::handleBoundsCollision(Projectile* projectile)
{
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    if(tile == NULL)
    {
        //If the tile object is NULL, it means the projectile is no longer in the level
        projectile->setIsActive(false);
        Log::debug("Projectile went off screen");
    }
}

void Player::handlePlayerCollision(Projectile* projectile)
{
    Log::debug("Player didn't override handlePlayerCollision.");
}

void Player::pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound)
{
    if(pathFinder == m_PathFinder)
    {
        if(pathWasFound == true)
        {
            
            startAnimating();
        }
        else
        {
            m_PathFinder->reset();
        }
    }
}

PathFinder* Player::getPathFinder()
{
    return m_PathFinder;
}

void Player::findPath()
{
    m_PathFinder->reset();
    m_PathFinder->findPath(m_CurrentTile, m_DestinationTile);
}

float Player::animate(float aCurrent, float aTarget, double aDelta, float speed)
{
    float speedModifier = 1;
    if(m_CurrentTile->getTileType() == TileTypeIce)
    {
        speedModifier = 10;
    }
    
    float increment = aDelta * m_Speed * speedModifier * (aTarget < aCurrent ? -1 : 1) * speed;
    if(fabs(increment) > fabs(aTarget - aCurrent))
    {
        return aTarget;
    }
    else
    {
        aCurrent += increment;
    }
    return aCurrent;
}

void Player::startAnimating()
{
	m_CanAnimate = true;
	m_AnimationPathNodeIndex = 0;
}

void Player::stopAnimating()
{
	m_CanAnimate = false;
	m_AnimationPathNodeIndex = -1;
}

bool Player::isAnimating()
{
    return m_CanAnimate;
}

int Player::getHealth()
{
    return m_Health;
}
