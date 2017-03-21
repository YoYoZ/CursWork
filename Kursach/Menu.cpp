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
using namespace std;

void Menu::getStarted()
{
    char s[10];
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
                cout<<"Created new cinema"<<endl;
                break;
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
