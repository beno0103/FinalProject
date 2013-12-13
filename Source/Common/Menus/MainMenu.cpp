//
//  MainMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "MainMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"
#include "../Menus/HighScoresMenu.h"

MainMenu::MainMenu() : Menu(NULL, NULL)
{
    addButton(new UIButton("StartButton"));
    addButton(new UIButton("HighScores"));
    addButton(new UIButton("Settings"));
    
    addButton(new UIButton("LevelEditorButton"));
    addButton(new UIButton("ExitButton"));  
}

MainMenu::~MainMenu()
{

}

const char* MainMenu::getName()
{
    return MAIN_MENU_SCREEN_NAME;
}

void MainMenu::buttonAction(UIButton* button)
{
    int index = getIndexForButton(button);
    if(index == 0)
    {
        SaveAndLoadMenu* saveAndLoad = (SaveAndLoadMenu*)ScreenManager::getInstance()->getScreenForName(SAVE_LOAD_MENU_SCREEN_NAME);
        saveAndLoad->isLoading(GAME_SCREEN_NAME);
        
		//isItLoaded->setIsItLoaded(true);
        ScreenManager::getInstance()->switchScreen(SAVE_LOAD_MENU_SCREEN_NAME);
        
    }
    else if(index == 1)
    {
        ScreenManager::getInstance()->switchScreen(HIGHSCORES_MENU_SCREEN_NAME);
    }
    else if(index == 2)
    {
        ScreenManager::getInstance()->switchScreen(SETTINGS_MENU_SCREEN_NAME);
    }
    else if(index == 3)
    {
        ScreenManager::getInstance()->switchScreen(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 4)
    {
        exit(1);
    }
}
