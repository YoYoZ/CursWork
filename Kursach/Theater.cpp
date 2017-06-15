//
//  Theater.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Theater.hpp"
//-------------------------------------------------------------------------
//Конструктор за замовчуванням
Theater::Theater() {}
//-------------------------------------------------------------------------
//Конструктор, що заповнює дані об'єкту
Theater::Theater(string name_t, string adress_t, string *events_t, int countOfDecorations,int antractTime, int num) : CultPlace(name_t, adress_t, num, events_t), countOfDecorations(countOfDecorations), antractTime(antractTime){}

//-------------------------------------------------------------------------
//Вивід даних на єкран
void Theater::showData()
{
    cout << "===================" <<endl;
    cout << "\tData for Theater:" << endl;
    CultPlace::showData();
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
    os.write(reinterpret_cast<char*>(&antractTime), sizeof(antractTime)); //Читаємо час антракту
    os.write(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations)); //Читаємо кількість декорацій
}
//-------------------------------------------------------------------------
//Читання даних, специфічних щодо классу Театр
void Theater::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&antractTime), sizeof(antractTime)); //Записуємо час антракту
    is.read(reinterpret_cast<char*>(&countOfDecorations), sizeof(countOfDecorations)); //Записуємо кількість декорацій
}
//-------------------------------------------------------------------------
//Перевірка, чи це театр
bool Theater::isTheater()
{
    return true;
}
//-------------------------------------------------------------------------
//Запит для отримання довжини антракту
int Theater::getAntractTime() const
{
    return antractTime;
}
//-------------------------------------------------------------------------
//Запит для отримання кількості декорацій
int Theater::getCountOfDecorations() const
{
    return countOfDecorations;
}
//-------------------------------------------------------------------------
//Запит для запису нового часу антракту
void Theater::setAntractTime(int antract)
{
    antractTime = antract;
}
//-------------------------------------------------------------------------
//Запит для запису кількості декорацій
void Theater::setCountOfDecorations(int count)
{
    countOfDecorations = count;
}
