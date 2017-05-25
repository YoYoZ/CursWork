//
//  PrioritizedList.cpp
//  Kursach
//
//  Created by Anton Solyarik on 19.04.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "PrioritizedList.hpp"
//-------------------------------------------------------------------------
//Конструктор для ініціалізації одразу при створенні классу
PrioritizedList::PrioritizedList(CultPlace *cp, int priority): PrioritizedList()
{
    head = new node();
    tail = head;
    head->cp = cp;
    head->next = tail;
    head->priority = priority;
    
}
PrioritizedList::PrioritizedList(): head(NULL), tail(NULL){}
//-------------------------------------------------------------------------
//Метод додавання нових елементів до черги
void PrioritizedList::push(CultPlace *cp, int priority)
{
    if(!initialized)
    {
        head = new node();
        head->cp = cp;
        head->next = NULL;
        head->priority = priority;
        tail = head;
        initialized = true;
    } else
    {
        node *blk = new node();
        blk->cp = cp;
        blk->priority = priority;
        blk->next = NULL;
        tail ->next = blk;
        tail = blk;
    }
}
//-------------------------------------------------------------------------
//Метод виведення усіх об'єктів поєлементно
void PrioritizedList::show()
{
    node *el = head;
    if(initialized)
        for (int i = 0; i<size(); i++)
    {
        cout << "Here is element #" << i+1 << ": " << endl;
        el->cp->showData();
        el = el->next;
    }
}
//-------------------------------------------------------------------------
//Метод, що видаляє верхній елемент з черги
void PrioritizedList::remove()
{
    node *tmp = head;
    head = head->next;
    delete tmp;
}
//-------------------------------------------------------------------------
//Метод, що повертає об'єкт з найбільшим пріорітетом
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
//-------------------------------------------------------------------------
//Метод, що обраховує розмір усієї черги; повертає саме розмір, рахуючи з 1
int PrioritizedList::size()
{
    int count = 0;
    if (initialized)
    {
        for (node *el = head; el!=NULL; el = el->next){
            count++;
        }
    }
    return count;
}
//-------------------------------------------------------------------------
//Повертає перший елемент черги
node* PrioritizedList::getHead()
{
    return head;
}
//-------------------------------------------------------------------------
//Повертає останній елемент черги
node* PrioritizedList::getTail()
{
    return tail;
}
//-------------------------------------------------------------------------
//Повертає елемент, що має у собі шукану (передану) подію (або ж пустий покажчик, якщо єлемент не існує)
CultPlace * PrioritizedList::getByName(string name)
{
    for(int i = 0; i<size()-1; i++)
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


//-------------------------------------------------------------------------
//Бульбашкове сортування згідно алфавітного порядку
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
//-------------------------------------------------------------------------
//Перевантажений оператор виводу
ostream& operator <<(ostream& os, PrioritizedList& list)
{
    if(list.size()!=1)
    {
    int size = list.size();
    os.write(reinterpret_cast<char*>(&size), sizeof(int));
    node* element = list.getHead();
    for (int i = 0; i<size ; element = element->next, i++) {
        os.write(reinterpret_cast<char*>(&element->priority), sizeof(int));
        os << element->cp;
    }
    }
    return os;
}
//-------------------------------------------------------------------------
//Перевантажений оператор вводу
istream& operator >> (istream& is, PrioritizedList& list)
{
    int sizem;
    is.read(reinterpret_cast<char*>(&sizem), sizeof(int));

    for (int i = 0; i < sizem; ++i) {
        int priority  = 0;
        is.read(reinterpret_cast<char*>(&priority), sizeof(priority));
        CultPlace *cp;
        is >> &cp;
            list.push(cp, priority);
    }
    return is;
}
//-------------------------------------------------------------------------
//Метод очищення усього списку
void PrioritizedList::clearList()
{
    int size = this->size();
    node *tmp = head;
    node *el = head;
    for(int i = 0; i<size; i++)
    {
        tmp = el;
        el = el->next;
        delete tmp;
    }
    head = NULL;
    tail = NULL;
    initialized = false;
}
//-------------------------------------------------------------------------
//Метод пошуку елементу по його номеру
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
//-------------------------------------------------------------------------
//Метод присвоєння нового значення елементу по його номеру
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

//-------------------------------------------------------------------------
//Метод видалення елементу згідно його назви
bool PrioritizedList::removeByName(string name)
{
    int size = this->size();
    for( int i = 0; i < size-1; i++)
    {
        node* element = get(i);
        if (element->cp->getName() == name) {
            if (i == 0)
                head = head->next;
            else if (i + 1 == size) {
                tail = get(i - 1);
            }
            else {
                node* prev = get(i - 1);
                node* next = get(i + 1);
                prev->next = next;
            }
            return true;
        }
    }
    return false;
}




















