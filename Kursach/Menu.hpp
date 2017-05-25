//
//  Menu.hpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef Menu_hpp
#define Menu_hpp


#include "PrioritizedList.hpp"
class Menu
{

private:
    int selection;
    PrioritizedList p;
public:
    void getStarted();
    void createCinema();
    void createTheater();
    void saveToFile();
    void loadFromFile();
};
#endif /* Menu_hpp */
