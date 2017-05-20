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
    Cinema() {}
    void save(ostream& os);
    void load(istream& is);
public:
    Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num);
    void getEventsList(string n);
    void findEvent(string n);
    void showData();
    friend istream& operator >> (istream& is, CultPlace **place);

};
#endif /* Cinema_hpp */

