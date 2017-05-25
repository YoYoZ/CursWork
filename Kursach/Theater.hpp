//
//  Theater.hpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef Theater_hpp
#define Theater_hpp

#include "Places.hpp"

class Theater : public CultPlace
{
private:
    int antractTime;
    int countOfDecorations;
    Theater() {}
    void save(ostream& os);
    void load(istream& is);
public:
    Theater(string name_t, string adress_t, string *events_t, int countOfDecorations, int antractTime, int num);
    void showData();
    friend istream& operator >> (istream& is, CultPlace **place);
    int getAntractTime();
    int getCountOfDecorations();
    void setAntractTime(int antract);
    void setCountOfDecorations(int count);
};

#endif /* Theater_hpp */
