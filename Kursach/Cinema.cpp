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
void Cinema::showData()
{
    
}
 void Cinema::getEventsList(string n)
{
    
}
void Cinema::findEvent(string n)
{
    
}
Cinema::~Cinema()
{}

void Cinema::save(std::fstream& stream) {
    int type = CINEMA;
    stream.write(reinterpret_cast<char*>(&type), sizeof(int));
    CultPlace::save(stream);
    stream.write(reinterpret_cast<char*>(&p), sizeof(projectorType));
    stream.write(reinterpret_cast<char*>(&countOfHalls), sizeof(int));
   
}

void Cinema::load(std::fstream& stream) {
    CultPlace::load(stream);
    stream.read(reinterpret_cast<char*>(&p), sizeof(projectorType));
    stream.read(reinterpret_cast<char*>(&countOfHalls), sizeof(int));
}
