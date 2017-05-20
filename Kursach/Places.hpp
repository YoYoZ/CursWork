//
//  Places.hpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//
#include <string>
#include <stdio.h>
#ifndef Places_hpp
#define Places_hpp

#include <fstream>
using namespace std;

enum PlaceTypes {
    CINEMA = 1, THEATER
};

class CultPlace
{
protected:
    string name;
    string adress;
    string *events;
    int numberOfEvents;
public:
    CultPlace() {}
    CultPlace(string name, string adress, int num)
    {
        this->name = name;
        this->adress = adress;
        this->numberOfEvents = num;
    }
    ~CultPlace();
    virtual void getEventsList(string) = 0;
    virtual void findEvent(string) = 0;
    virtual void showData() = 0;
    virtual void save(std::fstream& stream);
    virtual void load(std::fstream& stream);
    static CultPlace* loadObject(std::fstream& stream);
    
};



#endif /* Places_hpp */
