//
//  Enemy.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-22.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Enemy.h"
#include "Level.h"
#include "../Game/Tiles/Tile.h"
#include "Hero.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "Hero.h"


Enemy::Enemy(Level* level) : Player(level)
{
    m_Health = 1;
    m_Speed = ENEMY_SPEED;
    m_LastKnownHeroTile = NULL;
    
}

Enemy::~Enemy()
{
    
}

const char* Enemy::getType()
{
    return ENEMY_TYPE;
}

void Enemy::update(double delta)
{
    Player::update(delta);
}

void Enemy::paint()
{
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorRed());
    OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2), getWidth() / 2);
                                                                                   
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorWhite());
    OpenGLRenderer::getInstance()->drawCircle(getX() + (getWidth() / 2), getY() + (getHeight() / 2),  getWidth() / 2, false);
}

void Enemy::reset()
{
    Player::reset();
    
    Tile* nearestTile = NULL;
    float lastDistance = -1.0f;
    
    for(int i = 0; i < m_Level->getHeroes().size(); i++)
    {
        Tile* tile = m_Level->getTileForPlayer(m_Level->getHeroes().at(i));
        float x = tile->getX();
        float y = tile->getY();
        float distance = MathUtils::distance(x, y, getX(), getY());
        if(distance < lastDistance || lastDistance == -1.0f)
        {
            lastDistance = distance;
            nearestTile = tile;
        }
    }
    
    //Set the destination tile
    m_LastKnownHeroTile = nearestTile;
    
    if(m_LastKnownHeroTile != NULL)
    {
        setDestinationTile(m_LastKnownHeroTile);
    }
    
}

void Enemy::handlePlayerCollision(Projectile* projectile)
{
    //TODO: Handle hero collision with an enemy projectile
    Tile* tile = m_Level->getTileForPosition(projectile->getX(), projectile->getY());
    
    //Cycle through all the enemies and check for collision with the projectile
    for(int i = 0; i < m_Level->getHeroes().size(); i++)
    {
        Hero* hero = m_Level->getHeroes().at(i);
        Hero* enemy = m_Level->getHeroes().at(i);
        if(hero != NULL && hero->getIsActive() == true)
        {
            //Get the tile the enemy is on
            Tile* heroTile = m_Level->getTileForPlayer(hero);
            Tile* enemyTile = m_Level->getTileForPlayer(enemy);
           
            //Is the projectile on the same tile as the enemy?
            if(enemyTile == heroTile)
            {
                Log::debug("Enemy touched the hero");
               
                //Apply damage to the enemy AND set the projectile to inactive
                hero->applyDamage(1);
                projectile->setIsActive(false);
            }
        }
    }
}

void Enemy::handleBoundsCollision(Player* player)
{
//    Level* level = new Level();
//    for(int i = 0; i < level->m_Enemies.size(); i++)
//    {
//        Hero* enemy = m_Level->getHeroes().at(i);
//        
//        if(enemy->getX() == player->getX() && enemy->getY() == player->getY())
//        {
//           m_Health--;
//        }
//    }
    
    //TODO: Handle hero collision with an enemy projectile
    Tile* tile = m_Level->getTileForPosition(player->getX(), player->getY());
    
    //Cycle through all the enemies and check for collision with the projectile
    for(int i = 0; i < m_Level->getHeroes().size(); i++)
    {
        Hero* hero = m_Level->getHeroes().at(i);
        Enemy* enemy = m_Level->getEnemies().at(i);
        if(hero != NULL && hero->getIsActive() == true)
        {
            //Get the tile the enemy is on
            Tile* heroTile = m_Level->getTileForPlayer(hero);
            Tile* enemyTile = m_Level->getTileForPlayer(enemy);
            
            //Is the projectile on the same tile as the enemy?
            if(enemyTile == heroTile)
            {
                Log::debug("Enemy touched the hero");
                
                //Apply damage to the enemy AND set the projectile to inactive
                hero->applyDamage(1);
                player->setIsActive(false);
            }
        }
    }

}