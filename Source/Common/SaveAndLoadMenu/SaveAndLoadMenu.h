//
//  MainMenu.h
//  GAM-1514 OSX Game
//
//  Created by Bradley Flood on 2013-10-07.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__SaveAndLoadMenu__
#define __GAM_1514_OSX_Game__SaveAndLoadMenu__

#include "../Menus/Menu.h"

class OpenGLTexture;

class SaveAndLoadMenu : public Menu
{
public:
    SaveAndLoadMenu();
    ~SaveAndLoadMenu();
    
    const char* getName();

	void isSaving(const char* returnScreen);
	void isLoading(const char* returnScreen);

	virtual void mouseMovementEvent(float deltaX, float deltaY, float positionX, float positionY);
    virtual void mouseLeftClickUpEvent(float positionX, float positionY);
    
    //Getter and setter functions to check to see if the level is saved and to set it.
    virtual void keyUpEvent(int keyCode);

private:
    void buttonAction(UIButton* button);

	bool m_IsSaving;
	const char* m_ReturnScreen;
};

#endif /* defined(__GAM_1514_OSX_Game__SaveAndLoadMenu__) */
