#include <iostream>
#include <windows.h>
#include "Hearing_aid.h"

using namespace std;

HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);

Hearing_aid p0;

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

void objectTesting()
{
    separator1("Creating p1 and p2 with different number of parameters: ");

    Hearing_aid p1("EarMax", 2011, 2);
    p1.battery().setSize(4000);
    p1.battery().setLifespan(100);
    p1.parameter()[0].setName("LCE");
    p1.parameter()[1].setName("size");
    p1.parameter()[1].setValue(25);

    Hearing_aid p2("ITTC", 2001, 1);
    p2.battery().setSize(3000);
    p2.battery().setLifespan(50);
    p2.parameter()[0].setName("Wireless");

    separator1("Creating p3 as a copy of p2: ");

    Hearing_aid p3=p2;

    separator1("Creating dynamic object px and deleting it: ");

    Hearing_aid *px=new Hearing_aid("HearAll",1980,3);
    delete px;

    separator1("Creating and printing empty p4: ");

    Hearing_aid p4("", 0, 5);
    cout << p4;

    separator1("Checking current number of objects: ");

    cout << "Hearing_aid: " << Hearing_aid::objQuantity() << ", Battery: " << Battery::batQuantity() << ", Parameter: " << p1.parameter()->parQuantity() << endl << endl;
};

void operatorTesting()
{
    separator2("Creating p1 and p2 with different number of parameters and p3 as a copy of p1: ");

    Hearing_aid p1("EarMax", 2011, 2);
    p1.battery().setSize(4000);
    p1.battery().setLifespan(100);
    p1.parameter()[0].setName("LCE");
    p1.parameter()[1].setName("size");
    p1.parameter()[1].setValue(25);

    Hearing_aid p2("ITTC", 2001, 1);
    p2.battery().setSize(3000);
    p2.battery().setLifespan(50);
    p2.parameter()[0].setName("Wireless");

    Hearing_aid p3(p1);

    separator2("Testing operator <<: ");

    cout << p1;
    cout << p2;

    separator2("Testing operator = by creating empty p4, assigning it to p2, then to p1 and printing it: ");

    Hearing_aid p4;
    p4=p2;
    p4=p1;
    cout << p4;

    separator2("Testing operator == (if(p1==p2) -false and if(p1==p3) -true): ");

    if(p1==p2)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl << endl;

    if(p1==p3)
        cout << "EQUAL" << endl;
    else
        cout << "DIFFERENT" << endl;

    separator2("Testing operator [] on full parameter and an empty one: ");

    p2[0];
    cout << endl;
    p2[9];

    separator2("Testing operator ++ and -- ");

    cout << p1.battery().lifespan() << endl;
    ++p1;
    cout << p1.battery().lifespan() << endl;
    --p1;
    cout << p1.battery().lifespan() << endl;

    separator2("Testing operator (string): ");     //kinda useless, i didn't have any ideas for that operator

    cout << p1.amplification_x() << endl;
    string s = (string)p1 + " + ADDITIONAL TEXT";
    cout << s << endl;

    separator2("Testing operator >> (changing the year of production): ");

    cout << p1.amplification_x() << endl;
    1999.921>>p1;
    cout << p1.amplification_x() << endl;
};

int main()
{
    objectTesting();

    #ifdef _DEBUG
    operatorTesting();
    #endif

    return 0;
}




