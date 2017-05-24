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
istream& operator >>(istream& is, PrioritizedList& list);



class PrioritizedList
{
private:
    node *head;
    node *tail;
    node* get(const int i);
    void set(const int i, node& el);
    bool initialized = 0;
public:
    PrioritizedList(CultPlace *cp, int priority);
    PrioritizedList();
    void push(CultPlace *cp, int priority);
    void remove();
    void show();
    bool removeByName(string name);
    node *getHighest();
    int size();
    node* getHead();
    node* getTail();
    CultPlace* getByName(string name);
    void sortByName(int step = 0);
    void clearList();

};
#endif /* PrioritizedList_hpp */
