//
//  Places.hpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//
#ifndef Places_hpp
#define Places_hpp

#include <string>
#include <iostream>

using namespace std;

enum PlaceTypes {
    CINEMA = 1, THEATER
};

class CultPlace;

ostream& operator <<(ostream& os, CultPlace *place);
istream& operator >>(istream& is, CultPlace **place);
ostream& operator <<(ostream& os, PlaceTypes type);
istream& operator >>(istream& is, PlaceTypes* type);

class CultPlace
{
protected:
    string name;
    string adress;
    string *events;
    int numberOfEvents;
    CultPlace() {}
    virtual void save(ostream& os);
    virtual void load(istream& is);
public:
    CultPlace(string name, string adress, int num, string* events)
    {
        this->name = name;
        this->adress = adress;
        this->numberOfEvents = num;
        this->events = events;
    }
    ~CultPlace();
    virtual void showData() = 0;
    void addEvent(string name);
    void removeEvent(string name);
    void displayEvents();
    friend ostream& operator <<(ostream& os, CultPlace *place);
    friend istream& operator >> (istream& os, CultPlace **place);
    string getName();
    string getAdress();
    string* getEvents();
    int getNumberOfEvents();
    void setName(string name);
    void setAdress(string adress);
};



#endif /* Places_hpp */
