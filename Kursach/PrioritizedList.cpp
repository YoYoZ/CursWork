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
int PrioritizedList::size()
{
    int count = 0;
    for (node *el = elem; el != NULL; count++, el = el->next) {}    
    return count;
}
node* PrioritizedList::getHead()
{
    return elem;
}

ostream& operator <<(ostream& os, PrioritizedList& list)
{
    int size = list.size();
    os.write(reinterpret_cast<char*>(&size), sizeof(int));
    for (node* element = list.getHead(); element != NULL; element = element->next) {
        os.write(reinterpret_cast<char*>(&element->priority), sizeof(int));
        os << element->cp;
    }
    return os;
}

istream& operator >> (istream& is, PrioritizedList **list)
{
    int size;
    is.read(reinterpret_cast<char*>(&size), sizeof(int));

    for (int i = 0; i < size; ++i) {
        int priority  = 0;
        is.read(reinterpret_cast<char*>(&priority), sizeof(priority));
        CultPlace *cp;
        is >> &cp;
        if (i == 0) {
            *list = new PrioritizedList(cp, priority);
        }
        else {
            (*list)->push(cp, priority);
        }        
    }
    return is;
}






























