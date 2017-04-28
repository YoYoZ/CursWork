//
//  Theater.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Theater.hpp"



Theater::Theater(string name_t, string adress_t, string *events_t, int foodPrice_t, int num) : CultPlace(name_t, adress_t, num){}

void Theater::showData() {}


void Theater::save(ostream& os)
{
    os << THEATER;
    CultPlace::save(os);
    os.write(reinterpret_cast<char*>(&antraktTime), sizeof(antraktTime));
    os.write(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations));
}

void Theater::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&antraktTime), sizeof(antraktTime));
    is.read(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations));
}

