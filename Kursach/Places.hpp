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
    CultPlace(string name, string adress);
    virtual void getEventsList(string name);
    virtual void findEvent(string name);
};

class Cinema : private CultPlace
{
protected:
    int ticketPrice;
public:
    void showData();
    
};

class Theater : private CultPlace
{
protected:
    int foodPrice;
public:
    void showData();
};


#endif /* Places_hpp */
