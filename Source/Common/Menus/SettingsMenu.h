//
//  SettingsMenu.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__SettingsMenu__
#define __GAM_1514_OSX_Game__SettingsMenu__

#include "Menu.h"


class SettingsMenu : public Menu
{
public:
    SettingsMenu();
    ~SettingsMenu();
    
    const char* getName();
    
private:
    void buttonAction(UIButton* button);
};


#endif /* defined(__GAM_1514_OSX_Game__SettingsMenu__) */
