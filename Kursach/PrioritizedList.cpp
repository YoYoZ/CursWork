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
PrioritizedList::~PrioritizedList()
{
}
PrioritizedList::PrioritizedList(): head(NULL), tail(NULL){}
//-------------------------------------------------------------------------
//Метод додавання нових елементів до черги
void PrioritizedList::push(CultPlace *cp, int priority)
{
    if(!initialized) // Перевірка, чи існує цей контейнер
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
    for(node* el = head; el != NULL; el = el->next)
    {
        CultPlace *cpToWork = el->cp; //Копіюємо елемент
        if(cpToWork->isTheater() == true) //Якщо це театр
        {
            for(int j = 0; j<cpToWork->getNumberOfEvents(); j++)
            {
                if((cpToWork->getEvents()[j]) == name) //Шукаємо у ньому елементи
                    return cpToWork;
            }
        }
    }
    return nullptr;
}


//-------------------------------------------------------------------------
//Бульбашкове сортування згідно алфавітного порядку
void PrioritizedList::sortByName(int step)
{
    if(size()!=1 || size()!=0) //Перевіряємо, що лист не пустий
        for (int i = size(); i > 0; --i) {
            node* element = head;
            node* prevElement = NULL;
            for (int j = 0; j < (i - 1) ; ++j) {
                node* curEl = element;
                node* nextEl = element->next;
                if (curEl->cp->getName() > nextEl->cp->getName()) //Порівнюємо між собою елементи
                {

                    if (prevElement == NULL) {
                        node* tmp = head;
                        node* headNext = head->next->next;
                        head = head->next;
                        head->next = tmp;
                        tmp->next = headNext;
                        element = head;
                    }
                    else {
                        node* tmp = nextEl->next;
                        prevElement->next = nextEl;
                        nextEl->next = curEl;
                        curEl->next = tmp;
                    }
                }
                prevElement = element;
                element = element->next;
            }
        }
    else
    {
        cout<<"Error! Your list is empty. Exiting.."<<endl;
        return;
    }
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
//Метод видалення елементу згідно його назви
bool PrioritizedList::removeByName(string name)
{
    for(node *el = head, *prevEl = NULL; el != NULL; el = el->next)
    {
        if (el->cp->getName() == name) { //Перевіряємо ім'я щоб видалити
            if (el == head)
                head = head->next; //Якщо перший елемент, просто видаляемо його
            else {
                node* next = el->next;
                prevEl->next = next; // Пропускаємо елемент у контейнері
            }
            return true;
        }
        prevEl = el;
    }
    return false;
}

void PrioritizedList::serialize()
{
    cout<<"Saving.."<<endl;
    fstream str;
    str.open("test.bin", ios::binary | ios::trunc | ios::out | ios::in);
    if (str.bad()) {
        cout << "Can't create file." << endl;
        return;
    }
    char sum = 0;
    str.write(&sum, sizeof(char));
    if(size()!=1 || size()!=0)
    {
        int s = size();
        str.write(reinterpret_cast<char*>(&s), sizeof(int));
        node* element = getHead();
        for (int i = 0; i<size() ; element = element->next, i++) {
            str.write(reinterpret_cast<char*>(&element->priority), sizeof(int));
            str << element->cp;
        }
    }
    str.clear();
    str.seekg(1);

    while (str.good()) {
        char tmp;
        str.read(&tmp, sizeof(char));
        sum += tmp;
    }
    str.clear();
    str.seekg(0);
    str.seekp(0);
    str.write(&sum, sizeof(char));
    str.close();
}
void PrioritizedList::deserialize()
{
    fstream is;
    is.open("test.bin", ios::binary | ios::in);
    if (is.bad()) {
        cout << "Can't open file." << endl;
        return;
    }
    char fileSum = 0;
    char calcSum = 0;
    is.read(&fileSum, sizeof(char));
    while (is.good()) {
        char tmp;
        is.read(&tmp, sizeof(char));
        calcSum += tmp;
    }
    if (fileSum != calcSum) {
        cout << "Alert! File data corruption detected. Exciting load process; now you need to re-save or recover file." << endl;
        is.close();
        return;
    }
    is.clear();
    is.seekg(1);
    clearList();
    int sizem;
    is.read(reinterpret_cast<char*>(&sizem), sizeof(int)); //Читаємо розмір об'єкту

    for (int i = 0; i < sizem; ++i) {
        int priority  = 0;
        is.read(reinterpret_cast<char*>(&priority), sizeof(priority)); //Читаємо пріорітет
        CultPlace *cp;
        is >> &cp;
        push(cp, priority); //Додаємо новий елемент
    }

}


















