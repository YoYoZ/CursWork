//
//  Theater.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Theater.hpp"



Theater::Theater(string name_t, string adress_t, string *events_t, int countOfDecorations,int antractTime, int num) : CultPlace(name_t, adress_t, num, events_t)
{
    this->countOfDecorations = countOfDecorations;
    this->antractTime = antractTime;
}

void Theater::showData()
{
    cout << "===================" <<endl;
    cout << "\tData for Theater:" << endl;
    cout << "Name:\t" << this->name << endl;
    cout << "Address:\t" << this->adress << endl;
    cout << "Antract Time:\t" << antractTime <<endl;
    cout << "Count of decorations:\t" << countOfDecorations <<endl;
    cout << "Events:" <<endl;
    this->displayEvents();
    cout << "===================" <<endl;

}

//-------------------------------------------------------------------------
//Збереження даних, специфічніх щодо классу Театр
void Theater::save(ostream& os)
{
    os << THEATER;
    CultPlace::save(os);
    os.write(reinterpret_cast<char*>(&antractTime), sizeof(antractTime));
    os.write(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations));
}
//-------------------------------------------------------------------------
//Читання даних, специфічних щодо классу Театр
void Theater::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&antractTime), sizeof(antractTime));
    is.read(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations));
}

int Theater::getAntractTime()
{
    return antractTime;
}
int Theater::getCountOfDecorations()
{
    return countOfDecorations;
}

void Theater::setAntractTime(int antract)
{
    antractTime = antract;
}

void Theater::setCountOfDecorations(int count)
{
    countOfDecorations = count;
}
