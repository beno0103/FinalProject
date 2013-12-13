//
//  LevelEditor.cpp
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-25.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#include "LevelEditor.h"
#include "../Menus/Menu.h"
#include "../SaveAndLoadMenu/SaveAndLoadMenu.h"
#include "../Constants/Constants.h"
#include "../Game/Level.h"
#include "../Screen Manager/ScreenManager.h"
#include "../UI/UIButton.h"
#include "../UI/UIToggle.h"


LevelEditor::LevelEditor() :
    m_TilesMenu(NULL),
	m_TilesMenuOtherSide(NULL),
    m_Level(NULL),
    m_IsMouseDown(false),
    m_SelectedTileIndex(-1)
{
    //Create the Tiles menu items
    m_TilesMenu = new UISideMenu(this, SideMenuRight);
	m_TilesMenuOtherSide = new UISideMenu(this, SideMenuLeft);
    m_TilesMenu->addButton(new UIToggle("MenuTileGround"));
    m_TilesMenu->addButton(new UIToggle("MenuTileIce"));
    m_TilesMenu->addButton(new UIToggle("MenuTileWater"));
    m_TilesMenu->addButton(new UIToggle("MenuTileTree"));
    m_TilesMenu->addButton(new UIToggle("MenuTileSnow"));
    m_TilesMenu->addButton(new UIToggle("StartPointTile"));
    m_TilesMenu->addButton(new UIToggle("EndPointTile"));
    
	m_TilesMenuOtherSide->addButton(new UIButton("MenuTileClear"));
	m_TilesMenuOtherSide->addButton(new UIButton("MenuTileLoad"));
	m_TilesMenuOtherSide->addButton(new UIButton("MenuTileSave"));
	m_TilesMenuOtherSide->addButton(new UIButton("MenuTileExit"));
    
    
    //Create the level object
    m_Level = new Level(true);
    
    //Reset everything
    reset();
}

LevelEditor::~LevelEditor()
{
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
    if(m_TilesMenu != NULL)
    {
        delete m_TilesMenu;
        m_TilesMenu = NULL;
    }

	if(m_TilesMenuOtherSide != NULL)
    {
        delete m_TilesMenuOtherSide;
        m_TilesMenuOtherSide = NULL;
    }
}

const char* LevelEditor::getName()
{
    return LEVEL_EDITOR_SCREEN_NAME;
}

void LevelEditor::update(double delta)
{
    if(m_Level != NULL)
    {
        m_Level->update(delta);
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->update(delta);
    }

	if(m_TilesMenuOtherSide != NULL)
    {
        m_TilesMenuOtherSide->update(delta);
    }
}

void LevelEditor::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }

    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->paint();
    }

	if(m_TilesMenuOtherSide != NULL)
    {
        m_TilesMenuOtherSide->paint();
    }
}

void LevelEditor::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

Level* LevelEditor::getLevel()
{
    return m_Level;
}

void LevelEditor::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{    
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }

	if(m_TilesMenuOtherSide != NULL)
    {
        m_TilesMenuOtherSide->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
    
    if(m_Level != NULL)
    {        
        if(m_SelectedTileIndex != -1 && m_IsMouseDown == true)
        {
            TileType types[] = {TileTypeGround, TileTypeIce, TileTypeWater, TileTypeTree, TileTypeSnow, TileTypeStartPoint, TileTypeEndPoint};
            TileType type = types[m_SelectedTileIndex];
            
            m_Level->setTileTypeAtPosition(type, positionX, positionY);
        }
    }
}

void LevelEditor::mouseLeftClickDownEvent(float positionX, float positionY)
{
    //Set the mouse down flag
    m_IsMouseDown = true;
}

void LevelEditor::mouseLeftClickUpEvent(float positionX, float positionY)
{
    //Set the mouse up flag
    m_IsMouseDown = false;
    
    //Safety check the level pointer, then set the new tile type in the index
    if(m_Level != NULL)
    {
        if(m_SelectedTileIndex != -1 && m_TilesMenu->isShowing() == false)
        {
            TileType types[] = {TileTypeGround, TileTypeIce, TileTypeWater, TileTypeTree, TileTypeSnow, TileTypeStartPoint, TileTypeEndPoint};
            TileType type = types[m_SelectedTileIndex];

            m_Level->setTileTypeAtPosition(type, positionX, positionY);
        }
    }
    
    //Notify the tiles menu of the mouse event
    if(m_TilesMenu != NULL)
    {
        m_TilesMenu->mouseLeftClickUpEvent(positionX, positionY);
    }

	if(m_TilesMenuOtherSide != NULL)
    {
        m_TilesMenuOtherSide->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void LevelEditor::keyUpEvent(int keyCode)
{
    if(keyCode == KEYCODE_TAB)
    {
        if(m_TilesMenu != NULL)
        {
            m_TilesMenu->isShowing() == true ? m_TilesMenu->hide() : m_TilesMenu->show();
			m_TilesMenuOtherSide->isShowing() == true ? m_TilesMenuOtherSide->hide() : m_TilesMenuOtherSide->show();
        }
    }
    else if(keyCode == KEYCODE_S) //Temp, Only for ICA 12, remove during options menu implementation
    {
        if(m_Level != NULL)
        {
            m_Level->save("Level-1.txt");
        }
    }
    else if(keyCode == KEYCODE_L) //Temp, Only for ICA 12, remove during options menu implementation
    {
        if(m_Level != NULL)
        {
            m_Level->load("Level-1.txt");
        }
    }
    else if(keyCode == KEYCODE_T)
    {
        if(m_Level != NULL)
        {
            m_Level->setPickupTypeAtIndex(PickupTypeAmmo, 101);
        }
    }
    else if(keyCode == KEYCODE_Y)
    {
		if(m_Level != NULL)
		{
			m_Level->setPickupTypeAtIndex(PickupTypeUnknown, 101);
		}
    }
    else
    {
        if(m_Level != NULL)
        {
            m_Level->keyUpEvent(keyCode);
        }
    }
}

void LevelEditor::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
    SaveAndLoadMenu* isItSaved = (SaveAndLoadMenu*)ScreenManager::getInstance()->getScreenForName(SAVE_LOAD_MENU_SCREEN_NAME);
	SaveAndLoadMenu* isItLoaded = (SaveAndLoadMenu*)ScreenManager::getInstance()->getScreenForName(SAVE_LOAD_MENU_SCREEN_NAME);
    
	int index = m_TilesMenuOtherSide->getIndexForButton(button);
    if(index == 0)
    {
        m_Level->load(NULL);
    }
    else if(index == 1)
    {
        //This is loading
        ScreenManager::getInstance()->switchScreen(SAVE_LOAD_MENU_SCREEN_NAME);
		isItLoaded->isLoading(LEVEL_EDITOR_SCREEN_NAME);
    }
	else if(index == 2)
    {
        //This is saving the level
        ScreenManager::getInstance()->switchScreen(SAVE_LOAD_MENU_SCREEN_NAME);
		isItSaved->isSaving(LEVEL_EDITOR_SCREEN_NAME);
    }
    else if (index == 3)
    {
        ScreenManager::getInstance()->switchScreen(MAIN_MENU_SCREEN_NAME);
    }
}

void LevelEditor::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TilesMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_TilesMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
    
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TilesMenu->hide();
		m_TilesMenuOtherSide->hide();
    }
}


