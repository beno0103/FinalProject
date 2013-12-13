//
//  Splash.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "Splash.h"
#include "../Constants/Constants.h"
#include "../Input/Input.h"
#include "../Screen Manager/ScreenManager.h"
#include"../UI/UIButton.h"

Splash::Splash() :
m_PressSpace(NULL)
{
    m_PressSpace = new UIButton(SPLASH_PRESS_SPACE);
}

Splash::~Splash()
{
    if(m_PressSpace != NULL)
    {
        delete m_PressSpace;
        m_PressSpace = NULL;
    }
}

const char* Splash::getName()
{
    return SPLASH_SCREEN_NAME;
}

void Splash::update(double delta)
{
    
}

void Splash::paint()
{
    m_PressSpace->paint();
}

void Splash::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_SPACE)
    {
        ScreenManager::getInstance()->switchScreen(GAME_SCREEN_NAME);
    }
}

void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
void mouseRightClickUpEvent(float positionX, float positionY);