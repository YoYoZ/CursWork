//
//  Menu.cpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include "Menu.hpp"
#include <string.h>
#include <iostream>
#include "Places.hpp"
#include "Cinema.hpp"
using namespace std;

projectorType ConvertTo(string p);
void Menu::getStarted()
{
    cout<<"Hello. Please, enter your choice."<<endl;
    cout<<"#1. Create a cinema"<<endl;
    cout<<"#2. Create a theater"<<endl;
    cout<<"#3. Display all cultural places"<<endl;
    cout<<"#4. Delete specified place"<<endl;
    cout<<"#5. Save data to file"<<endl;
    cout<<"#6. Load data from file"<<endl;
    cout<<"#7. Find the scene"<<endl;
    cout<<"#8. Exit"<<endl;
    cin.getline(s, 10);
    selection = atoi(s);
    if(selection>0&&selection<9)
    {
        switch(selection)
        {
            case 1:
            {
                cout<<"Please, enter Name, Adress, projector Type and priority to Work"<<endl;
                /*string name;
                string adress;
                string projectorType;
                int priority;
                cin>>name;
                cin>>adress;
                cin>>projectorType;
                cin>>priority;
                Cinema *cn = new Cinema(name, adress, ConvertTo(projectorType));
                if(!initialized)
                {
                    p = new PrioritizedList(cn, priority);
                    initialized = true;
                }
                else
                    p->push(cn, priority);
                */
                string events[] = { "Event 1", "Event 2"};
                string norm = "test";
                Cinema *cnn = new Cinema("KISLYAKOV", "MAKS", ConvertTo(("IMAX")), 25, events, 2);
                Cinema *cn = new Cinema("KISLYAKOV 2", "MAKS 2", ConvertTo(("IMAX")),25, &norm, 2);
                p = new PrioritizedList(cn, 9);
                p->push(cnn, 9);
                p->saveToFile("data.dt");
                p = PrioritizedList::loadFromFile("data.dt");
                break;
            }
            case 2:
                cout<<"Created new theater"<<endl;
                break;
            case 3:
                cout<<"Here all all cult. places"<<endl;
                break;
            case 4:
                cout<<"Enter the name to delete"<<endl;
                break;
            case 5:
                cout<<"Saving.."<<endl;
                break;
            case 6:
                cout<<"Loading.."<<endl;
                break;
            case 7:
                cout<<"Enter ID"<<endl;
                break;
            case 8:
                cout<<"Goodbye"<<endl;
                break;
                
        }
    }
    else
    {
        cout<<"Wrong number"<<endl;
        selection = 0;
        getStarted();
    }
    
}
 projectorType ConvertTo(string p)
{
    if  (p=="IMAX")
        return projectorType::IMAX;
    else if (p=="2D")
        return projectorType::d2;
    else if (p=="3D")
        return projectorType::d3;
    else
        return projectorType::Uknown;
    
}
