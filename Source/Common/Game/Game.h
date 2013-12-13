#ifndef GAME_H
#define GAME_H

#include <vector>
#include "../Screen Manager/Screen.h"
#include "../UI/UISideMenu.h"

class GameObject;
class Level;
class UIFont;
class UISideMenu;

class Game : public Screen, public UISideMenuListener
{
public:
  Game();
  ~Game();

  //Game lifecycle methods
  void update(double delta);
  void paint();
  void reset();

  //Screen name, must be implemented, it's a pure
  //virtual method in the Screen class
  const char* getName();
  
  Level* getLevel();

private:
  //Mouse Events
  void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
  void mouseLeftClickUpEvent(float positionX, float positionY);
  void keyUpEvent(int keyCode);
    
  void sideMenuButtonAction(UISideMenu* sideMenu, UIButton* button, int buttonIndex);
  void sideMenuToggleAction(UISideMenu* sideMenu, UIToggle* toggle, int toggleIndex);
  short GameSpeed;
    
  //Level pointer
  Level* m_Level;
    
  int m_SelectedTileIndex;
    
  UISideMenu* m_GameSideMenu;
  UISideMenu* m_TilesMenu;
    
  //Temp font pointer
  UIFont* m_Font;
};

#endif