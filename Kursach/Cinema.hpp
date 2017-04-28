//
//  Cinema.hpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef Cinema_hpp
#define Cinema_hpp

#include <stdio.h>
#include "Places.hpp"



enum projectorType
{
    IMAX, d3, d2, Uknown
};

class Cinema : public CultPlace
{
private:
    projectorType p;
    int countOfHalls;
    
public:
    Cinema() {}
    Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num);
    ~Cinema();
    void ShowData();
    void getEventsList(string n);
    void findEvent(string n);
    void showData();
    void save(std::fstream& stream);
    void load(std::fstream& stream);
};
#endif /* Cinema_hpp */

