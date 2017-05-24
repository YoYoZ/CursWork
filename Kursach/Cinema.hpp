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
    string ConvertTo(projectorType p);
public:
    Cinema(string name, string adress, projectorType p, int countOfHalls, string *events, int num);
    void showData();
    friend istream& operator >> (istream& is, CultPlace **place);
    string getProjectorType();
    int getCountOfHalls();
    void setProjectorType(string type);
    void setCountOfHalls(int count);
    static projectorType ConvertTo(string p);

};
#endif /* Cinema_hpp */

