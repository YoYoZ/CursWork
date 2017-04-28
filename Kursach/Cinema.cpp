//
//  Cinema.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Cinema.hpp"

Cinema::Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num) : CultPlace(name, adress, num)
{
    this->p = p;
    this->countOfHalls = countOfHalls;
}

void Cinema::showData() {}
void Cinema::getEventsList(string n){}
void Cinema::findEvent(string n){}

void Cinema::save(ostream& os)
{
    os << CINEMA;
    CultPlace::save(os);
    os.write(reinterpret_cast<char*>(&p), sizeof(projectorType));
    os.write(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls));
}

void Cinema::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&p), sizeof(projectorType));
    is.read(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls));
}
