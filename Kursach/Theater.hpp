//
//  Theater.hpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef Theater_hpp
#define Theater_hpp

#include <stdio.h>
#include "Places.hpp"

class Theater : public CultPlace
{
private:
    int antraktTime;
    int countOfDecorations;
public:
    Theater() {}
    Theater(string name_t, string adress_t, string *events_t, int foodPrice_t, int num);
    ~Theater();
    void getEventsList(string n) {};
    void findEvent(string n) {};
    void showData();
    void save(std::fstream& stream);
    void load(std::fstream& stream);
};

#endif /* Theater_hpp */
