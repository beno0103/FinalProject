#include "Game.h"
#include "GameObject.h"
#include "Level.h"
#include "Player.h"
#include "../OpenGL/OpenGL.h"
#include "../Constants/Constants.h"
#include "../Utils/Utils.h"
#include "../Screen Manager/ScreenManager.h"
#include "../Math/GDRandom.h"
#include "../Math/GDRandomSearch.h"
#include "../UI/UIFont.h"
#include "../Level Editor/LevelEditor.h"
#include "../UI/UIButton.h"

Game::Game():
GameSpeed(1),
m_GameSideMenu(NULL),
m_TilesMenu(NULL)

{
    //Create the level object
    m_Level = new Level();
    m_Font = new UIFont("Fonts");
    
    m_GameSideMenu = new UISideMenu(this, SideMenuRight);
    m_GameSideMenu->addButton(new UIButton("1XSpeed"));
    m_GameSideMenu->addButton(new UIButton("2XSpeed"));
    m_GameSideMenu->addButton(new UIButton("5XSpeed"));
    
    //Reset everything
    reset();
}

Game::~Game()
{
    //Delete the level object
    if(m_Level != NULL)
    {
        delete m_Level;
        m_Level = NULL;
    }
    
    if(m_Font!= NULL)
    {
        delete m_Font;
        m_Font = NULL;
    }
    
    if(m_GameSideMenu != NULL)
    {
        delete m_GameSideMenu;
        m_GameSideMenu = NULL;
    }
}

void Game::update(double delta)
{
    
    if(m_Level != NULL)
    {
        m_Level->update(delta * GameSpeed);
    }
    
    if(m_GameSideMenu != NULL)
    {
        m_GameSideMenu->update(delta);
    }
}

void Game::paint()
{
    if(m_Level != NULL)
    {
        m_Level->paint();
    }
    
    if(m_Font != NULL)
    {
        m_Font->draw(100.0f, 100.0f);
    }
    
    if(m_GameSideMenu != NULL)
    {
        m_GameSideMenu->paint();
    }
}

void Game::reset()
{
    if(m_Level != NULL)
    {
        m_Level->reset();
    }
}

const char* Game::getName()
{
	return GAME_SCREEN_NAME;
}

Level* Game::getLevel()
{
    return m_Level;
}

void Game::mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY)
{
    if(m_Level != NULL)
    {
        m_Level->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
    
    if(m_GameSideMenu != NULL)
    {
        m_GameSideMenu->mouseMovementEvent(deltaX, deltaY, positionX, positionY);
    }
}

void Game::mouseLeftClickUpEvent(float positionX, float positionY)
{
    if(m_Level != NULL)
    {
        m_Level->mouseLeftClickUpEvent(positionX, positionY);
    }
    
    if(m_GameSideMenu != NULL)
    {
        m_GameSideMenu->mouseLeftClickUpEvent(positionX, positionY);
    }
}

void Game::keyUpEvent(int keyCode)
{
    if(m_Level != NULL)
    {
        m_Level->keyUpEvent(keyCode);
    }
    
    if(keyCode == KEYCODE_TAB)
    {
        if(m_GameSideMenu != NULL)
        {
            m_GameSideMenu->isShowing() == true ? m_GameSideMenu->hide() : m_GameSideMenu->show();
        }
    }
}

void Game::sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex)
{
    int index = m_GameSideMenu->getIndexForButton(button);
    if(index == 0)
    {
        GameSpeed = 1;
    }
    else if(index == 1)
    {
        GameSpeed = 2;
    }
	else if(index == 2)
    {
        GameSpeed = 5;
    }
}

void Game::sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex)
{
    if(sideMenu == m_TilesMenu)
    {
        //Un-toggled the previously selected toggle
        UIToggle* previousToggle = (UIToggle*)m_GameSideMenu->getButtonForIndex(m_SelectedTileIndex);
        if(previousToggle != NULL)
        {
            previousToggle->setIsToggled(false);
        }
        
        //Set the selected tile index
        m_SelectedTileIndex = toggle->isToggled() == true ? toggleIndex : -1;
        
        //Hide the options and tiles menus
        m_TilesMenu->hide();
		m_GameSideMenu->hide();
    }
}
