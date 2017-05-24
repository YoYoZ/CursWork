//
//  Menu.hpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp

#include <stdio.h>
#include "PrioritizedList.hpp"
class Menu
{

private:
    int selection;
    bool initialized = false;
    char s[10];
    PrioritizedList p;
public:
    void getStarted();
};
#endif /* Menu_hpp */
