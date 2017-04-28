//
//  PrioritizedList.hpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef PrioritizedList_hpp
#define PrioritizedList_hpp

#include <stdio.h>
#include "Places.hpp"

struct node
{
    int priority;
    CultPlace *cp;
    node *next;
    
};

class PrioritizedList
{
private:
    node *elem;
public:
    PrioritizedList(CultPlace *cp, int priority);
    void push(CultPlace *cp, int priority);
    void remove(int index);
    void removeLast();
    void removeFirst();
    node *getHighest();
    bool saveToFile(string filename);
    int size();
    static PrioritizedList* loadFromFile(string filename);
};
#endif /* PrioritizedList_hpp */
