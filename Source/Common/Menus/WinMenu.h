//
//  WinMenu.h
//  GAM-1514 OSX Game
//
//  Created by Amedee Benoitrevert on 2013-12-13.
//  Copyright (c) 2013 Algonquin College. All rights reserved.
//

#ifndef __GAM_1514_OSX_Game__WinMenu__
#define __GAM_1514_OSX_Game__WinMenu__


#include "Menu.h"


class WinMenu : public Menu
{
public:
    WinMenu();
    ~WinMenu();
    
    const char* getName();
    
private:
    void buttonAction(UIButton* button);
};

#endif /* defined(__GAM_1514_OSX_Game__WinMenu__) */
