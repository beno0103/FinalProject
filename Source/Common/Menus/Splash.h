//
//  Splash.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__Splash__
#define __GAM_1514_OSX_Game__Splash__

#include <iostream>

#include "Screen.h"

#include "../Screen Manager/Screen.h"

class UIButton;

class Splash : public Screen
{
public:
    Splash();
    ~Splash();
    
    const char* getName();
    
    void update(double delta);
    void paint();
    
    virtual void keyUpEvent(int keyCode);
    
    void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    void mouseRightClickUpEvent(float positionX, float positionY);
    
private:
    UIButton* m_PressSpace;
    
};

#endif /* defined(__GAM_1514_OSX_Game__Splash__) */
