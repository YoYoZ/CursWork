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
using namespace std;

class CultPlace
{
protected:
    string name;
    string adress;
    string *events;
public:
    CultPlace(string name, string adress)
    {
        this->name = name;
        this->adress = adress;
    }
    virtual void getEventsList(string name);
    virtual void findEvent(string name);
};

class Cinema : private CultPlace
{
protected:
    int ticketPrice;
public:
    Cinema(string *events_t, int ticketPrice_t)
    {
        ticketPrice = ticketPrice_t;
    }
    ~Cinema();
    void showData();
    
};

class Theater : private CultPlace
{
protected:
    int foodPrice;
public:
    Theater(string name_t, string adress_t, string *events_t, int foodPrice_t);
    ~Theater();
    void showData();
};


#endif /* Places_hpp */
