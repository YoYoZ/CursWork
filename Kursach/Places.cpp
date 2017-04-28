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


void CultPlace::save(std::fstream& stream) {
    stream << name << endl;
    stream << adress << endl;
    
#warning Do something with *events.
}

CultPlace* CultPlace::loadObject(std::fstream& stream) {
    int type = 0;
    stream.read(reinterpret_cast<char*>(&type), sizeof(int));
    CultPlace *place = NULL;
    switch (type) {
        case CINEMA:
            place = new Cinema();
            break;
        case THEATER:
            place = new Theater();
            break;
    }
    place->load(stream);
    return place;
}

void CultPlace::load(std::fstream& stream) {
    getline(stream, name);
    getline(stream, adress);
}
