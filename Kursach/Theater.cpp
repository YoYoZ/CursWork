//
//  Theater.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Theater.hpp"



Theater::Theater(string name_t, string adress_t, string *events_t, int foodPrice_t, int num) : CultPlace(name_t, adress_t, num)
{
    
}

void Theater::showData()
{
    
}


void Theater::save(std::fstream& stream) {
    int type = THEATER;
    stream.write(reinterpret_cast<char*>(&type), sizeof(int));
    CultPlace::save(stream);
    stream.write(reinterpret_cast<char*>(&antraktTime), sizeof(int));
    stream.write(reinterpret_cast<char*>(&countOfDecorations), sizeof(int));
}

void Theater::load(std::fstream& stream) {
    CultPlace::load(stream);
    stream.read(reinterpret_cast<char*>(&antraktTime), sizeof(int));
    stream.read(reinterpret_cast<char*>(&countOfDecorations), sizeof(int));
}

