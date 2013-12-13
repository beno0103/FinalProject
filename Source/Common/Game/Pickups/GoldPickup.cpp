//
//  GoldPickup.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-06.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GoldPickup.h"

GoldPickup::GoldPickup(int goldCount) : Pickup(PickupTypeGold),
m_GoldCount(goldCount)
{
    //TODO: The size should b that of the texture, you use for the ammo pickup (or any pickup)
    setSize(24.0f, 24.0f);
}

GoldPickup::~GoldPickup()
{
    
}

void GoldPickup::paint()
{
    OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorYellow());
    OpenGLRenderer::getInstance()->drawRectangle(getX(), getY(), getWidth(), getHeight());
}

const char* GoldPickup::getType()
{
    return GOLD_PICKUP_TYPE;
}

int GoldPickup::getGoldCount()
{
    return m_GoldCount;
}