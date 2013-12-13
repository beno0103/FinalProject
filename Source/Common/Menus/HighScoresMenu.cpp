//
//  HighScoresMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "HighScoresMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

HighScoresMenu::HighScoresMenu() : Menu(NULL, NULL)
{
    addButton(new UIButton("ExitButton"));
}

HighScoresMenu::~HighScoresMenu()
{
    
}

const char* HighScoresMenu::getName()
{
    return HIGHSCORES_MENU_SCREEN_NAME;
}

void HighScoresMenu::buttonAction(UIButton* button)
{
	
    
    
    int index = getIndexForButton(button);
    if(index == 0)
    {
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
