//
//  Enemy.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-22.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Enemy__
#define __GAM_1514_OSX_Game__Enemy__

#include "Player.h"

class Enemy : public Player
{
public:
    Enemy(Level* level);
    virtual ~Enemy();
    
    const char* getType();
    
    void update(double delta);
    void paint();
    void reset();
    
    
    
protected:
    void handlePlayerCollision(Projectile* projectile);
    void handleBoundsCollision(Player* player);
    
    Tile* m_LastKnownHeroTile;

};

#endif /* defined(__GAM_1514_OSX_Game__Enemy__) */
