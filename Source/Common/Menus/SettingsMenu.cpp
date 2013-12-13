//
//  SettingsMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "SettingsMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

SettingsMenu::SettingsMenu() : Menu(NULL, NULL)
{
    addButton(new UIButton("Difficulty"));
    addButton(new UIButton("ScoreLimitButton"));
    addButton(new UIButton("TimeLimitButton"));
    addButton(new UIButton("ExitButton"));
}

SettingsMenu::~SettingsMenu()
{
    
}

const char* SettingsMenu::getName()
{
    return SETTINGS_MENU_SCREEN_NAME;
}

void SettingsMenu::buttonAction(UIButton* button)
{
	
    
    
    int index = getIndexForButton(button);
    if(index == 0)
    {
        
    }
    else if(index == 1)
    {
        
    }
    else if(index == 2)
    {
        
    }
    else if(index == 3)
    {
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
    else if (index == 4)
    {
        
    }
}
