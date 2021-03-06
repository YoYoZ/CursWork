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
    Theater();
public:
    Theater(string name_t, string adress_t, string *events_t, int countOfDecorations, int antractTime, int num);
    void showData();
    friend istream& operator >> (istream& is, CultPlace **place);
    int getAntractTime() const;
    int getCountOfDecorations() const;
    void setAntractTime(int antract);
    void setCountOfDecorations(int count);
    bool isTheater();
    void save(ostream& os);
    void load(istream& is);
};

#endif /* Theater_hpp */
