//
//  Places.cpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Places.hpp"
#include "Cinema.hpp"
#include "Theater.hpp"

void CultPlace::save(ostream& os)
{
    os << name << endl;
    os << adress << endl; 
}

void CultPlace::load(istream& is)
{
    getline(is, name);
    getline(is, adress);
}

ostream& operator <<(ostream& os, CultPlace *place)
{
    place->save(os);
    return os;
}

istream& operator >> (istream& is, CultPlace **place)
{
    PlaceTypes type;
    is >> &type;
    switch (type) {
        case CINEMA:
            *place = new Cinema();
            break;
        case THEATER:
            *place = new Theater();
            break;
        default:
            *place = NULL;
            break;
    }
    if (*place != NULL)
        (*place)->load(is);
    return is;
}

ostream& operator <<(ostream& os, PlaceTypes type) {
    os.write(reinterpret_cast<char*>(&type), sizeof(PlaceTypes));
    return os;
}

istream& operator >>(istream& is, PlaceTypes* type) {
    is.read(reinterpret_cast<char*>(type), sizeof(PlaceTypes));
    return is;
}




