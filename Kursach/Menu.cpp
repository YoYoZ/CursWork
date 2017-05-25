//
//  Menu.cpp
//  Kursach
//
//  Created by Anton Solyarik on 21.03.17.
//  Copyright © 2017 Anton Solyarik. All rights reserved.
//

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Menu.hpp"
#include "Places.hpp"
#include "Cinema.hpp"
#include "Theater.hpp"
using namespace std;

int filterInt (istream& is);

projectorType ConvertTo(string p);
void Menu::getStarted()
{
    cout<<"Hello. Please, enter your choice."<<endl;
    cout<<"#1. Create a cinema"<<endl;
    cout<<"#2. Create a theater"<<endl;
    cout<<"#3. Display all cultural places"<<endl;
    cout<<"#4. Sort places"<<endl;
    cout<<"#5. Delete specified place"<<endl;
    cout<<"#6. Save data to file"<<endl;
    cout<<"#7. Load data from file"<<endl;
    cout<<"#8. Find the scene"<<endl;
    cout<<"#9. Exit"<<endl;
    int selection = filterInt(cin);

    if(selection>0&&selection<10)
    {
        switch(selection)
        {
            case 1:
                createCinema();
                break;
            case 2:
                createTheater();
                break;
            case 3:
                cout<<"Here all all cult. places:"<<endl;
                p.show();
                break;
            case 4:
            {
                p.sortByName();
                cout<<"Elements are now sorted"<<endl;
                break;
            }
            case 5:
            {
                cout<<"Enter the name to delete:"<<endl;
                string toDelete;
                cin>>toDelete;
                if(p.removeByName(toDelete))
                    cout<<"Completed successfully"<<endl;
                else
                    cout<<"Error. Perfaps you made an typo error?"<<endl;
                break;
            }
            case 6:
                saveToFile();
                break;
            case 7:
                loadFromFile();
                break;
            case 8:
            {
                cout<<"Enter ID"<<endl;
                string in;
                cin>>in;
                CultPlace *cp = p.getByName(in);
                if(cp !=nullptr)
                {
                cout<<"It is in a place:"<<endl;
                cp->showData();
                }
                else
                    cout<<"Event not found. Perhaps you made a mistake?"<<endl;
                break;
            }
            case 9:
                cout<<"Goodbye"<<endl;
                return;
                
        }
    }
    else
    {
        cout<<"Wrong number"<<endl;
        selection = 0;
        getStarted();
    }
       cout << "Press any key to continue" << endl;
    cin.ignore();
 
    getStarted();
    
}

void Menu::createCinema()
{
    cout<<"Please, enter name, adress, projector type, priority of place and count of halls of this cinema:"<<endl;
    string name;
    string adress;
    string projectorType;
    int priority;
    int countOfHalls;
    int numEvents = 0;
    cout << "Enter name: ";
    cin>>name;
    cout << "Enter adress: ";
    cin>>adress;
    cout << "Enter projector type: ";
    cin>>projectorType;
    cout << "Enter priority: ";
    priority = filterInt(cin);
    cout << "Enter count of Halls: ";
    countOfHalls = filterInt(cin);
    cout << "Now, please, type how many events do you need for this place."<<endl;
    cout << "Num events: ";
    numEvents = filterInt(cin);
    string *Events = new string[numEvents];
    if(numEvents!=0)
    {
        cout<<"Type by one events: "<<endl;
        for(int i =  0; i<numEvents; i++) {
            cout << "Type " << (i + 1) << " event: ";
            cin>>Events[i];
        }
        
    }
    Cinema *cn = new Cinema(name, adress, Cinema::ConvertTo(projectorType),countOfHalls, Events, numEvents);
    p.push(cn, priority);

}

void Menu::createTheater()
{
    cout<<"Please, enter name, adress, count of decoration, antract time and priority to work of this theater:"<<endl;
    string name;
    string adress;
    int countOfDecorations;
    int priority;
    int antractTime;
    int numEvents;
    cout<<"Enter name:";
    cin>>name;
    cout<<"Enter adress: ";
    cin>>adress;
    cout<<"Enter count of decorations: ";
    countOfDecorations = filterInt(cin);
    cout<<"Enter antract time: ";
    antractTime = filterInt(cin);
    cout<<"Enter priority: ";
    priority = filterInt(cin);
    cout<<"Now, please, type how many events do you need for this place."<<endl;
    numEvents = filterInt(cin);
    string *Events = new string[numEvents];
    if(numEvents!=0)
    {
        cout<<"Type by one events: "<<endl;
        for(int i =  0; i<numEvents; i++) {
            cout << "Type " << (i + 1) << " event: ";
            cin>>Events[i];
        }
        
    }
    Theater *th = new Theater(name, adress, Events,countOfDecorations, antractTime, numEvents);
    p.push(th, priority);
}

void Menu::saveToFile()
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
    str << p;
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

void Menu::loadFromFile()
{
    cout<<"Loading.."<<endl;
    fstream str;
    str.open("test.bin", ios::binary | ios::in);
    if (str.bad()) {
        cout << "Can't open file." << endl;
        return;
    }
    char fileSum = 0;
    char calcSum = 0;
    str.read(&fileSum, sizeof(char));
    while (str.good()) {
        char tmp;
        str.read(&tmp, sizeof(char));
        calcSum += tmp;
    }
    if (fileSum != calcSum) {
        cout << "Alert! File data corruption detected. Exciting load process; now you need to re-save or recover file." << endl;
        str.close();
        return;
    }
    str.clear();
    str.seekg(1);
    p.clearList();
    str >> p;

}
int filterInt (istream& is) {
    stringstream convertor;
    string tmp;
    int result = 0;
    while (true) {
        is >> tmp;
        convertor << tmp;
        convertor >> result;
        if (!convertor.fail() && result > 0)
            return result;
        else
        {
            convertor.clear();
            convertor.seekg(ios::beg);
            convertor.seekp(ios::beg);
            tmp = "";
            cout << "error in symbols; Please, retype."<<endl;
        }
    }
    
}
