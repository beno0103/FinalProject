//
//  Hero.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-22.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Hero__
#define __GAM_1514_OSX_Game__Hero__

#include "Player.h"

class Hero : public Player
{
public:
    Hero(Level* level);
    ~Hero();
    
    const char* getType();
    
    void update(double delta);
    
    void mouseLeftClickUpEvent(float positionX, float positionY);
    void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    void keyUpEvent(int keyCode);
    
protected:
    void handlePlayerCollision(Projectile* projectile);
    void handleBoundsCollision(Projectile* projectile);
};

#endif /* defined(__GAM_1514_OSX_Game__Hero__) */
