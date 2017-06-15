//
//  Cinema.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Cinema.hpp"
//-------------------------------------------------------------------------
//Конструктор за замовчуванням
Cinema::Cinema(){}

//-------------------------------------------------------------------------
//Конструктор для створення єкземпляру об'єкта
Cinema::Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num) : CultPlace(name, adress, num, events), p(p), countOfHalls(countOfHalls) {}

//-------------------------------------------------------------------------
//Вивід на єкран
void Cinema::showData()
{
    cout << "===================" <<endl;
    cout << "\tData for Cinema:" << endl;
    CultPlace::showData();
    cout << "Projector type:\t" << ConvertTo(p) <<endl;
    cout << "Count of halls:\t" << countOfHalls <<endl;
    cout << "Events:" <<endl;
    this->displayEvents();
    cout << "===================" <<endl;
}

//-------------------------------------------------------------------------
//Перевірка, чи це театр
bool Cinema::isTheater()
{
    return false;
}
//-------------------------------------------------------------------------
//Збереження даних, специфічніх щодо классу Кіно
void Cinema::save(ostream& os)
{
    os << CINEMA;
    CultPlace::save(os);
    os.write(reinterpret_cast<char*>(&p), sizeof(projectorType)); //Читаємо тип проектору
    os.write(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls)); //Читаємо кількість залів
}
//-------------------------------------------------------------------------
//Читання даних, специфічніх щодо классу Кіно
void Cinema::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&p), sizeof(projectorType)); //Записуємо тип проектору
    is.read(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls)); // Записуємо кількість залів
}
//-------------------------------------------------------------------------
//Перевантажена функція, що переводить з типу даних enum до string
string Cinema::ConvertTo(projectorType p) const
{
    if  (p==projectorType::IMAX)
        return "IMAX";
    else if (p==projectorType::d2)
        return "2D";
    else if (p==projectorType::d3)
        return "3D";
    else
        return "Uknown";
    
}
//-------------------------------------------------------------------------
//Перевантажена функція, що переводить з типу даних string до enum 
projectorType Cinema::ConvertTo(string p)
{
    if  (p=="IMAX")
        return projectorType::IMAX;
    else if (p=="2D")
        return projectorType::d2;
    else if (p=="3D")
        return projectorType::d3;
    else
        return projectorType::Uknown;
    
}
//-------------------------------------------------------------------------
//Запит для отримання типу проектору
string Cinema::getProjectorType() const
{
    return ConvertTo(p);
}
//-------------------------------------------------------------------------
//запит для отримання кількості залів
int Cinema::getCountOfHalls() const
{
    return countOfHalls;
}
//-------------------------------------------------------------------------
//Запит для встановлення нової кількості залів
void Cinema::setCountOfHalls(int count)
{
    this->countOfHalls = count;
}
//-------------------------------------------------------------------------
//запит для встановлення нового типу проектору
void Cinema::setProjectorType(string type)
{
    p = ConvertTo(type);
}
