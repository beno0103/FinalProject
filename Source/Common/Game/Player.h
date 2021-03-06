//
//  Player.h
//  GAM-1532 OSX Game
//
//  Created by Bradley Flood on 2013-03-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "PathFinder.h"

#include "Projectile.h"

#include <vector>

class Level;
class Tile;
class Pickup;

class Player : public GameObject, public PathFinderListener, public ProjectileListener
{
public:
	Player(Level* level);
	virtual ~Player();

    //Update, paint and reset methods
	void update(double delta);
	void paint();
    void reset();
  
    //Implementing GameObject's pure virtual method
    //Keep GameObject's pure virtual method, we dont need to reclare it pure virtual, but
    //it makes it easier for inheriting classes to know that player is abstract
    virtual const char* getType() = 0;
  
    //Setter methods for the current and destination tiles
	void setCurrentTile(Tile* tile);
	void setDestinationTile(Tile* tile);
    int getHealth();
    
    //Projectile Methods
    void fireProjectile(float x, float y);
    void applyDamage(int damage);
    void goldTotal(int goldStack);
    

protected:
    //Projectile listener methods
    virtual void handlePlayerCollision(Projectile* projectile) = 0;
    virtual void handleBoundsCollision(Projectile* projectile);
    
    //Pickup method
    virtual void handlePickup(Pickup* pickup);
    
    //PathFinder listener method
    void pathFinderFinishedSearching(PathFinder* pathFinder, bool pathWasFound);
    
    //Pathfinder methods
    PathFinder* getPathFinder();
    void findPath();
    
    
    //Animation methods
    float animate(float current, float target, double delta, float speed);
	void startAnimating();
	void stopAnimating();
    bool isAnimating();
    
    //Friend class level so that it can access the protected members
    friend class Level;

    //Now the member variables are protected and can be accessed by the 
    //Member variables
    Level* m_Level;
    PathFinder* m_PathFinder;
	Tile* m_CurrentTile;
	Tile* m_DestinationTile;
	bool m_CanAnimate;
    bool m_AbortAnimation;
	int m_AnimationPathNodeIndex;
    int m_Ammo;
    int m_Gold;
    int m_Health;
    std::vector<Projectile*> m_Projectiles;
    float m_NumberOfPlayers;
    float m_Speed;
};

#endif