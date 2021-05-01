#include <iostream>
#include <fstream>
#include "electronic_device.h"
#include "phone.h"
#include "smartphone.h"
#include "Hearing_aid.h"
#include "vector"

using namespace std;

vector<Electronic_device*> electronic_devices;

int main()
{
    /*Hearing_aid a("ABCDE",3,2);
    a.parameters[0]->setName("Par1");
    a.parameters[0]->setValue(111);
    a.parameters[1]->setName("Par2");
    a.parameters[1]->setValue(222);*/

    //Phone a("Samsung", 1234, true);

    Smartphone a(1, 2, 3, "Samsung", 1234, true);

    a.setProduction_year(1999);
    a.user().setName("ADMIN");
    a.user().setAge(18);
    a.user().setPesel(123456789);
    a.battery().setSize(12);
    a.battery().setLifespan(5);

    //Hearing_aid b=a;
    //Hearing_aid c;
    //c=a;
    //Phone b=a;
    //Phone c;
    //c=a;
    Smartphone b=a;
    Smartphone c;
    c=a;

    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);
    electronic_devices.push_back(&c);

    /*cout << endl;
    electronic_devices[0]->ownership();
    cout << endl;
    electronic_devices[0]->save();
    cout << endl;
    electronic_devices[1]->open();
    cout << endl;
    electronic_devices[1]->draw();
    cout << endl;*/

    cout << endl;
    electronic_devices[0]->draw();
    cout << endl;
    electronic_devices[1]->draw();
    cout << endl;
    electronic_devices[2]->draw();
    return 0;
}




