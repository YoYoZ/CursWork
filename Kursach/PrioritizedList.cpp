//
//  PrioritizedList.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "PrioritizedList.hpp"
PrioritizedList::PrioritizedList(CultPlace *cp, int priority)
{
    elem = new node();
    elem->cp = cp;
    elem->next = NULL;
    elem->priority = priority;
    
}
void PrioritizedList::push(CultPlace *cp, int priority)
{
    node *block = elem;
    while (block->next!=NULL)
    {
        block = block->next;
    }
    node *n = new node();
    n->cp = cp;
    n->priority = priority;
    block->next = n;
}

void PrioritizedList::remove(int index)
{
    int step = 0;
    node *block = elem;
    while (index!=step)
    {
        block = block->next;
        step++;
    }
        node *temp = block->next;
        block->next = block->next->next;
        delete temp;
    
}
void PrioritizedList::removeLast()
{
    node *block = elem;
    while (block->next!=NULL)
    {
        block = block->next;
    }
    delete block;
}
void PrioritizedList::removeFirst()
{
    node *temp = elem;
    elem = elem->next;
    delete temp;
}
node* PrioritizedList::getHighest()
{
    node *block = elem;
    node *highestPrior = nullptr;
    while (block->next!=NULL)
    {
        block = block->next;
        if((block->priority)>highestPrior->priority)
            highestPrior=block;
    }
    return highestPrior;
}

bool PrioritizedList::saveToFile(string filename) {
    fstream ostream;
    ostream.open(filename, ios::binary | ios::trunc | ios::out);
    if (ostream.bad())
        return false;
    int s = size();
    ostream.write(reinterpret_cast<char*>(&s), sizeof(int));
    node *el = elem;
    for (;el != NULL; el = el->next) {
        ostream.write(reinterpret_cast<char*>(&(el->priority)), sizeof(int));
        el->cp->save(ostream);
    }
    ostream.close();
    return true;
}

int PrioritizedList::size() {
    int count = 0;
    node *el = elem;
    while (el != NULL) {
        count++;
        el = el->next;
    }
    
    return count;
}

PrioritizedList* PrioritizedList::loadFromFile(string filename) {
    PrioritizedList *list = NULL;
    int size = 0;
    fstream istream;
    istream.open(filename, ios::binary | ios::in);
    if (istream.bad())
        return NULL;
    
    istream.read(reinterpret_cast<char*>(&size), sizeof(int));
    for (int i = 0; i < size; ++i) {
        int priority  = 0;
        istream.read(reinterpret_cast<char*>(&priority), sizeof(int));
        CultPlace *cp = CultPlace::loadObject(istream);
        if (list == NULL) {
            list = new PrioritizedList(cp, priority);
        }
        else {
            list->push(cp, priority);
        }
        
    }
    istream.close();
    return list;
}






























