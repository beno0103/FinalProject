//
//  WinMenu.cpp
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "WinMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

#include "GameOverMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

#include "GameOverMenu.h"
#include "../UI/UIButton.h"
#include "../Game/Game.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"

WinMenu::WinMenu() : Menu(NULL, NULL)
{
    addButton(new UIButton("ExitButton"));
}

WinMenu::~WinMenu()
{
    
}

const char* WinMenu::getName()
{
    return WIN_MENU_SCREEN_NAME;
}

void WinMenu::buttonAction(UIButton* button)
{
	
    
    
    int index = getIndexForButton(button);
    if(index == 0)
    {
        OpenGLRenderer::getInstance()->setForegroundColor(OpenGLColorGreen());
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
