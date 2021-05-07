#include <iostream>
#include <fstream>
#include <windows.h>
#include "electronic_device.h"
#include "phone.h"
#include "smartphone.h"
#include "Hearing_aid.h"
#include "vector"

using namespace std;

vector<Electronic_device*> electronic_devices;

HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);

void separator(string text, int i)
{
    if(i==1){SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED);}
    if(i==2){SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE);}
    if(i==3){SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY);}

    cout << text;

    SetConsoleTextAttribute(handle, 7);
};

void testing(int i)
{
    separator("Virtual method \"ownership\": \n",i);
    electronic_devices[0]->ownership();
    cout << endl;

    separator("Saving the object to the database: \n",i);
    electronic_devices[0]->save();
    cout << endl << endl;

    separator("Reading the object from the database: \n",i);
    electronic_devices[3]->open();
    cout << endl << endl;

    separator("Drawing new object: \n",i);
    electronic_devices[3]->draw();
    cout << endl << endl;

    separator("Deleting vector: \n",i);
    electronic_devices.clear();
}

void testHearing_aid()
{
    Hearing_aid a("HerzMedical",3,2);
    a.parameters[0]->setName("Model");
    a.parameters[0]->setValue(13151);
    a.parameters[1]->setName("Number of overlays");
    a.parameters[1]->setValue(3);
    a.setProduction_year(2010);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(800);
    a.battery().setLifespan(100);
    Hearing_aid b(a);
    Hearing_aid c;
    Hearing_aid d;
    c=a;
    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);
    electronic_devices.push_back(&c);
    electronic_devices.push_back(&d);
    system("PAUSE");
    system("cls");

    testing(1);
}

void testPhone()
{
    Phone a("Nokia", 4, true);
    a.setProduction_year(2010);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(1200);
    a.battery().setLifespan(70);
    Phone b(a);
    Phone c;
    Phone d;
    c=a;
    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);
    electronic_devices.push_back(&c);
    electronic_devices.push_back(&d);
    system("PAUSE");
    system("cls");

    testing(2);
}

void testSmartphone()
{
    Smartphone a(5, 400, 20, "Samsung", 8, true);
    a.setProduction_year(2019);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(2500);
    a.battery().setLifespan(50);
    Smartphone b(a);
    Smartphone c;
    Smartphone d;
    c=a;
    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);
    electronic_devices.push_back(&c);
    electronic_devices.push_back(&d);
    system("PAUSE");
    system("cls");

    testing(3);
}

void menu()
{
    char choice;
    string exit="no";
    do
    {
        cout << "Choose the class you want to test: " << endl;
        separator("H - Hearing_aid \n",1);
        separator("P - Phone \n",2);
        separator("S - Smartphone \n",3);
        cout << "0 - Exit " << endl << endl;
        cin >> choice;
        switch(choice)
        {
        case 'H':
            testHearing_aid();
        break;

        case 'P':
            testPhone();
        break;

        case 'S':
            testSmartphone();
        break;

        case'0':
            return;
        break;

        default:
        {
            system("cls");
            continue;
        }
        break;
        }
        system("PAUSE");
        system("cls");
    }while(exit=="no");
}

int main()
{
    menu();
    return 0;
}




