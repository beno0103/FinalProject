//
//  AmmoPickup.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-11-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__GoldPickup__
#define __GAM_1514_OSX_Game__GoldPickup__

#include "Pickup.h"

class GoldPickup : public Pickup
{
public: GoldPickup(int goldCount);
    ~GoldPickup();
    
    void paint();
    
    const char* getType();
    
    int getGoldCount();
    
private:
    int m_GoldCount;
};

#endif /* defined(__GAM_1514_OSX_Game__GoldPickup__) */
