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
#include <iostream>
#include <fstream>
#include <sstream>
struct node
{
    int priority;
    CultPlace *cp;
    node *next;    
};

class PrioritizedList
{
private:
    node *head;
    node *tail;
    bool initialized = false;
public:
    PrioritizedList(CultPlace *cp, int priority);
    PrioritizedList();
    ~PrioritizedList();
    void push(CultPlace *cp, int priority);
    void remove();
    void show();
    bool removeByName(string name);
    void serialize();
    void deserialize();
    node *getHighest();
    int size();
    node* getHead();
    node* getTail();
    CultPlace* getByName(string name);
    void sortByName(int step = 0);
    void clearList();

};
#endif /* PrioritizedList_hpp */
