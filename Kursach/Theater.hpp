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
    Theater() {}
    void save(ostream& os);
    void load(istream& is);
public:
    Theater(string name_t, string adress_t, string *events_t, int foodPrice_t, int num);
    void getEventsList(string n) {};
    void findEvent(string n) {};
    void showData();
    friend istream& operator >> (istream& is, CultPlace **place);
};

#endif /* Theater_hpp */
