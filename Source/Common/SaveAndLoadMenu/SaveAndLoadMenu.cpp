//
//  MainMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "SaveAndLoadMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Level Editor/LevelEditor.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include <fstream>
#include <sstream>



SaveAndLoadMenu::SaveAndLoadMenu() : Menu(NULL, NULL)
{
	m_IsSaving = false;
	m_ReturnScreen = NULL;

    addButton(new UIButton("Level-1"));
    addButton(new UIButton("Level-2"));
    addButton(new UIButton("Level-3"));
	addButton(new UIButton("Level-4"));
    addButton(new UIButton("Level-5"));
	addButton(new UIButton("Level-6"));
	addButton(new UIButton("MenuTileExit"));
}

SaveAndLoadMenu::~SaveAndLoadMenu()
{

}

const char* SaveAndLoadMenu::getName()
{
    return SAVE_LOAD_MENU_SCREEN_NAME;
}

void SaveAndLoadMenu::isSaving(const char* returnScreen)
{
	m_ReturnScreen = returnScreen;
	m_IsSaving = true;
}

void SaveAndLoadMenu::isLoading(const char* returnScreen)
{
	m_ReturnScreen = returnScreen;
	m_IsSaving = false;
}


void SaveAndLoadMenu::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    for(int i = 0; i < m_Buttons.size(); i++)
    {
        m_Buttons.at(i)->mouseMovementEvent(positionX, positionY);
    }
}

void SaveAndLoadMenu::mouseLeftClickUpEvent(float positionX, float positionY)
{
    for(int i = 0; i < m_Buttons.size(); i++)
    {
        m_Buttons.at(i)->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void SaveAndLoadMenu::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_UP_ARROW)
    {
        if(m_SelectedIndex != -1)
        {
            //
            m_Buttons.at(m_SelectedIndex)->setIsSelected(false);
            
            //
            m_SelectedIndex--;
            if(m_SelectedIndex < 0)
            {
                m_SelectedIndex = 0;
            }
            
            //
            m_Buttons.at(m_SelectedIndex)->setIsSelected(true);
        }
    }
    else if (keyCode == KEYCODE_DOWN_ARROW)
    {
        if(m_SelectedIndex != -1)
        {
            //
            m_Buttons.at(m_SelectedIndex)->setIsSelected(false);
            
            //
            m_SelectedIndex++;
            if(m_SelectedIndex >= m_Buttons.size())
            {
                m_SelectedIndex = m_Buttons.size() - 1;
            }
            
            //
            m_Buttons.at(m_SelectedIndex)->setIsSelected(true);
        }
    }
    else
    {
        for(int i = 0; i < m_Buttons.size(); i++)
        {
            m_Buttons.at(i)->keyUpEvent(keyCode);
        }
    }
}

void SaveAndLoadMenu::buttonAction(UIButton* button)
{
    LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);

    
    int index = getIndexForButton(button);
    
    if(index == 0)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
                
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-1.txt");
                }
                else
                {
                    game->getLevel()->load("Level-1.txt");
                }
            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-1.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-1.txt");
                }
            }
            
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
    else if(index == 1)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
                
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-2.txt");
                }
                else
                {
                    game->getLevel()->load("Level-2.txt");
                }
            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-2.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-2.txt");
                }
            }
            
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
	else if(index == 2)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
                
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-3.txt");
                }
                else
                {
                    game->getLevel()->load("Level-3.txt");
                }

            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-3.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-3.txt");
                }
            }
            
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
    else if (index == 3)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
                
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-4.txt");
                }
                else
                {
                    game->getLevel()->load("Level-4.txt");
                }
            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-4.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-4.txt");
                }
            }
            
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
	else if (index == 4)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
                
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-5.txt");
                }
                else
                {
                    game->getLevel()->load("Level-5.txt");
                }
            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-5.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-5.txt");
                }
            }
            
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
	else if (index == 5)
    {
            if(strcmp(m_ReturnScreen, GAME_SCREEN_NAME) == 0)
            {
                Game* game = (Game*)ScreenManager::getInstance()->getScreenForName(GAME_SCREEN_NAME);
            
                if(m_IsSaving == true)
                {
                    game->getLevel()->save("Level-6.txt");
                }  
                else
                {
                    game->getLevel()->load("Level-6.txt");
                }
            }
            else if(strcmp(m_ReturnScreen, LEVEL_EDITOR_SCREEN_NAME) == 0)
            {
                LevelEditor* levelEditor = (LevelEditor*)ScreenManager::getInstance()->getScreenForName(LEVEL_EDITOR_SCREEN_NAME);
                if(m_IsSaving == true)
                {
                    levelEditor->getLevel()->save("Level-6.txt");
                }
                else
                {
                    levelEditor->getLevel()->load("Level-6.txt");
                }
            }
        
            ScreenManager::getInstance()->switchScreen(m_ReturnScreen);
    }
	else if (index == 6)
    {
		ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
}
