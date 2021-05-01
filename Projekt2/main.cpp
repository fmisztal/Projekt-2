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

void separator1(string text)
{
    SetConsoleTextAttribute(handle, FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "________________________________________________________________________________________________" << endl << endl;
    cout << text << endl << endl;
    SetConsoleTextAttribute(handle, 7);
};

void separator2(string text)
{
    SetConsoleTextAttribute(handle, FOREGROUND_GREEN | FOREGROUND_BLUE);
    cout << "________________________________________________________________________________________________" << endl << endl;
    cout << text << endl << endl;
    SetConsoleTextAttribute(handle, 7);
};

void separator3(string text)
{
    SetConsoleTextAttribute(handle, FOREGROUND_RED | FOREGROUND_INTENSITY );
    cout << "________________________________________________________________________________________________" << endl << endl;
    cout << text << endl << endl;
    SetConsoleTextAttribute(handle, 7);
};

void testHearingaid()
{
    separator1("Testing class Hearing_aid: ");

    Hearing_aid a("ABCDE",3,2);
    a.parameters[0]->setName("Par1");
    a.parameters[0]->setValue(111);
    a.parameters[1]->setName("Par2");
    a.parameters[1]->setValue(222);
    a.setProduction_year(1999);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(12);
    a.battery().setLifespan(5);

    Hearing_aid b;

    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);

    electronic_devices[0]->ownership();
    cout << endl;
    electronic_devices[0]->save();
    cout << endl;
    electronic_devices[1]->open();
    cout << endl;
    electronic_devices[0]->draw();
    cout << endl;
    electronic_devices[1]->draw();
    cout << endl;

    electronic_devices.clear();
}

void testPhone()
{
    separator2("Testing class Phone: ");

    Phone a("Samsung", 1234, true);
    a.setProduction_year(1999);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(12);
    a.battery().setLifespan(5);

    Phone b;

    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);

    electronic_devices[0]->ownership();
    cout << endl;
    electronic_devices[0]->save();
    cout << endl;
    electronic_devices[1]->open();
    cout << endl;
    electronic_devices[0]->draw();
    cout << endl;
    electronic_devices[1]->draw();
    cout << endl;

    electronic_devices.clear();
}

void testSmartphone()
{
    separator3("Testing class Smartphone: ");

    Smartphone a(1, 2, 3, "Samsung", 1234, true);
    a.setProduction_year(1999);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(12);
    a.battery().setLifespan(5);

    Smartphone b;

    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);

    electronic_devices[0]->ownership();
    cout << endl;
    electronic_devices[0]->save();
    cout << endl;
    electronic_devices[1]->open();
    cout << endl;
    electronic_devices[0]->draw();
    cout << endl;
    electronic_devices[1]->draw();
    cout << endl;

    electronic_devices.clear();
}

int main()
{
    testHearingaid();

    testPhone();

    testSmartphone();


    return 0;
}




