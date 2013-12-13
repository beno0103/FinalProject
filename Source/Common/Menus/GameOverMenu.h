//
//  GameOverMenu.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__GameOverMenu__
#define __GAM_1514_OSX_Game__GameOverMenu__

#include "Menu.h"


class GameOverMenu : public Menu
{
public:
    GameOverMenu();
    ~GameOverMenu();
    
    const char* getName();
    
private:
    void buttonAction(UIButton* button);
};


#endif /* defined(__GAM_1514_OSX_Game__GameOverMenu__) */
