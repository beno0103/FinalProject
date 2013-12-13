//
//  HighScoresMenu.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__HighScoresMenu__
#define __GAM_1514_OSX_Game__HighScoresMenu__

#include "Menu.h"


class HighScoresMenu : public Menu
{
public:
    HighScoresMenu();
    ~HighScoresMenu();
    
    const char* getName();
    
private:
    void buttonAction(UIButton* button);
};

#endif /* defined(__GAM_1514_OSX_Game__HighScoresMenu__) */
