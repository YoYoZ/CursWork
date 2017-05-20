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
    os.write(reinterpret_cast<char*>(&numberOfEvents), sizeof(numberOfEvents));
    for (int i = 0; i < numberOfEvents; ++i) {
        os << events[i] << endl;
    }
}

void CultPlace::load(istream& is)
{
    getline(is, name);
    getline(is, adress);
    is.read(reinterpret_cast<char*>(&numberOfEvents), sizeof(numberOfEvents));
    events = new string[numberOfEvents];
    for (int i = 0; i < numberOfEvents; ++i) {
        getline(is, events[i]);
    }
}
string CultPlace::getName()
{
    return name;
}

int CultPlace::getNumberOfEvents()
{
    return numberOfEvents;
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

string* CultPlace::getEvents()
{
    return events;
}
void CultPlace::addEvent(string name)
{
    numberOfEvents++;
    string *newEvents = new string[numberOfEvents];
    for(int i = 0; i<numberOfEvents-1; i++)
        newEvents[i] = events[i];
    newEvents[numberOfEvents-1] = name;
  //  delete[] events;
    events = newEvents;
}

void CultPlace::displayEvents()
{
    for (int i = 0; i<numberOfEvents; i++)
        cout<<"EVENT N "<<i<<"  WITH NAME "<<events[i]<<endl;
}
void CultPlace::removeEvent(string name)
{
    string *newEvents = new string[numberOfEvents - 1];
    for(int i = 0, j = 0; i < numberOfEvents; i++)
    {
        if(events[i] != name)
        {
            newEvents[j++] = events[i];
        }
    }
    delete[] events;
    events = newEvents;
    numberOfEvents--;
}


