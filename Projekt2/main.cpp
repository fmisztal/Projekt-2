#include <iostream>
#include <fstream>
#include "electronic_device.h"
#include "Hearing_aid.h"
#include "vector"

using namespace std;

vector<Electronic_device> electronic_devices;

int main()
{
    Hearing_aid a("wdff",3,2);
    a.setProduction_year(1999);
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    a.battery().setSize(12);
    cout << a.battery().size() << endl;
    cout << a.battery().size() << endl;
    cout << a.battery().size() << endl;
    cout << a.battery().size() << endl;
    cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << endl;
    a.battery().setLifespan(5);
    a.parameters[0]->setName("cs");
    a.parameters[0]->setValue(897);
    a.parameters[1]->setName("w222");
    a.parameters[1]->setValue(111);
    a.user().setName("ADMIN");
    a.user().setAge(12);
    a.user().setPesel(123456789);

    //Hearing_aid b;
    //b=a;
    Hearing_aid c("egre",999,4);

    cout << "......" << endl;

    electronic_devices.push_back(a);
    //electronic_devices.push_back(&b);
    electronic_devices.push_back(c);

    cout << "......" << endl;

    cout << a << endl;

    /*ifstream file;
    string s;
    file.open("file.txt", ios_base::out); */
    //file >> b;

    //cout << b << endl;

    return 0;
}




