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
    head = new node();
    tail = head;
    head->cp = cp;
    head->next = tail;
    head->priority = priority;
    
}
void PrioritizedList::push(CultPlace *cp, int priority)
{
    node *blk = new node();
    blk->cp = cp;
    blk->priority = priority;
    tail ->next = blk;
    tail = blk;

}

void PrioritizedList::remove()
{
    node *tmp = head;
    head = head->next;
    delete tmp;
}

node* PrioritizedList::getHighest()
{
    node *block = head;
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
    for (node *el = head; el != NULL; count++, el = el->next) {}
    return count;
}
node* PrioritizedList::getHead()
{
    return head;
}

CultPlace * PrioritizedList::getByName(string name)
{
    for(int i = 0; i<size(); i++)
    {
        CultPlace *cpToWork = get(i)->cp;
        for(int j = 0; j<cpToWork->getNumberOfEvents(); j++)
        {
            if((cpToWork->getEvents()[j]) == name)
                return ((get(i))->cp);
        }
        
    }
    return nullptr;
}



void PrioritizedList::sortByName(int step)
{

    for (int i = size(); i > 0; --i) {
        for (int j = 0; j < (i - 1) ; ++j) {
            if (get(j)->cp->getName() > get(j + 1)->cp->getName())
            {
                node* el = get(j);
                set(j, *(el->next));
                set(j + 1, *el);
                delete el;
            }
        }
    }
    tail = get(size() - 1);
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

node* PrioritizedList::get(const int i ) {
    node* el = head;
    if (i >= size())
        return NULL;
    
    int count = 0;
    while (count != i) {
        count++;
        el = el->next;
    }
    
    return el;
}

void PrioritizedList::set(const int i, node& elem) {
    int count = 0;
    node* oldNext = NULL;
    
    if (i >= size())
        return;
    
    node* copy = new node();
    *copy = elem;
    
    if (i == 0) {
        oldNext = head->next;
        head = copy;
        head->next = oldNext;
        return;
    }
    
    for (node *el = head; el != NULL; count++, el = el->next)
    {
        if(count == (i - 1)) {
            if (count != (size() - 1) )
                oldNext = el->next->next;
            el->next = copy;
            el->next->next = oldNext;
            return;
         }
    }

}























