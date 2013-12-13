//
//  GameOverMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "GameOverMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

GameOverMenu::GameOverMenu() : Menu(NULL, NULL)
{
    addButton(new UIButton("ExitButton"));
}

GameOverMenu::~GameOverMenu()
{
    
}

const char* GameOverMenu::getName()
{
    return GAMEOVER_MENU_SCREEN_NAME;
}

void GameOverMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
        OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorRed());
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
    else if(index == 1)
    {
        
    }
    else if(index == 2)
    {
        
    }
    else if(index == 3)
    {
        
    }
    else if (index == 4)
    {
        
    }
}
