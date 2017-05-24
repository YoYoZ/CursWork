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
//-------------------------------------------------------------------------
//Метод виводу у файл базової частини для похідних классів
void CultPlace::save(ostream& os)
{
    os << name << endl;
    os << adress << endl;
    os.write(reinterpret_cast<char*>(&numberOfEvents), sizeof(numberOfEvents));
    for (int i = 0; i < numberOfEvents; ++i) {
        os << events[i] << endl;
    }
}
//-------------------------------------------------------------------------
//Метод завантаження базової частини для похідних классів
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

//-------------------------------------------------------------------------
//Перевантажений оператор вводу
ostream& operator <<(ostream& os, CultPlace *place)
{
    place->save(os);
    return os;
}

//-------------------------------------------------------------------------
//Перевантажений оператор виводу
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
//-------------------------------------------------------------------------
//Метод додавання нової події
void CultPlace::addEvent(string name)
{
    numberOfEvents++;
    string *newEvents = new string[numberOfEvents];
    for(int i = 0; i<numberOfEvents-1; i++)
        newEvents[i] = events[i];
    newEvents[numberOfEvents-1] = name;
    events = newEvents;
}
//-------------------------------------------------------------------------
//Вивід усіх подій
void CultPlace::displayEvents()
{
    for (int i = 0; i<numberOfEvents; i++)
        cout << "\tEvent #"<<i+1<<" named "<<events[i]<<endl;
}
//-------------------------------------------------------------------------
//Видалення окремої події
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

string CultPlace::getAdress()
{
    return adress;
}

void CultPlace::setAdress(string adress)
{
    this->adress = adress;
}
void CultPlace::setName(string name)
{
    this->name = name;
}

