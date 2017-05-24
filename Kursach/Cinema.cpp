//
//  Cinema.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Cinema.hpp"

Cinema::Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num) : CultPlace(name, adress, num, events)
{
    this->p = p;
    this->countOfHalls = countOfHalls;
}

void Cinema::showData()
{
    cout << "===================" <<endl;
    cout << "\tData for Cinema:" << endl;
    cout << "Name:\t" << this->name << endl;
    cout << "Address:\t" << this->adress << endl;
    cout << "Projector type:\t" << ConvertTo(p) <<endl;
    cout << "Count of halls:\t" << countOfHalls <<endl;
    cout << "Events:" <<endl;
    this->displayEvents();
    cout << "===================" <<endl;
}
//-------------------------------------------------------------------------
//Збереження даних, специфічніх щодо классу Кіно
void Cinema::save(ostream& os)
{
    os << CINEMA;
    CultPlace::save(os);
    os.write(reinterpret_cast<char*>(&p), sizeof(projectorType));
    os.write(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls));
}
//-------------------------------------------------------------------------
//Читання даних, специфічніх щодо классу Кіно
void Cinema::load(istream& is)
{
    CultPlace::load(is);
    is.read(reinterpret_cast<char*>(&p), sizeof(projectorType));
    is.read(reinterpret_cast<char*>(&countOfHalls), sizeof(countOfHalls));
}
//-------------------------------------------------------------------------
//Перевантажена функція, що переводить з типу даних enum до string
string Cinema::ConvertTo(projectorType p)
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

string Cinema::getProjectorType()
{
    return ConvertTo(p);
}

int Cinema::getCountOfHalls()
{
    return countOfHalls;
}
void Cinema::setCountOfHalls(int count)
{
    this->countOfHalls = count;
}
void Cinema::setProjectorType(string type)
{
    p = ConvertTo(type);
}
