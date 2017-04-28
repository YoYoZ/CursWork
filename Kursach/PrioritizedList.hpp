//
//  PrioritizedList.hpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#ifndef PrioritizedList_hpp
#define PrioritizedList_hpp

#include "Places.hpp"

struct node
{
    int priority;
    CultPlace *cp;
    node *next;    
};

class PrioritizedList;

ostream& operator <<(ostream& os, PrioritizedList& list);
istream& operator >>(istream& is, PrioritizedList **list);



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
    int size();
    node* getHead();
};
#endif /* PrioritizedList_hpp */
