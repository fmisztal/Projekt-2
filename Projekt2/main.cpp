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
    cout <<  endl;

    /*Hearing_aid a("wdff",3,2);
    a.setProduction_year(1999);
    a.battery().setSize(12);
    a.battery().setLifespan(5);
    a.parameters[0]->setName("cs");
    a.parameters[0]->setValue(897);
    a.parameters[1]->setName("w222");
    a.parameters[1]->setValue(111);
    a.user().setName("ADMIN");
    a.user().setAge(12);
    a.user().setPesel(123456789);

    cout <<  endl;

    Hearing_aid b;
    b=a;

    cout <<  endl;

    cout << a << endl << b << endl;

    a.parameters[0]->setName("erdsfdsff");
    a.parameters[0]->setValue(420);
    a.parameters[1]->setName("xxxxx");
    a.parameters[1]->setValue(2137);

    a.battery().setSize(99999999);
    a.battery().setLifespan(999999999);

    cout << a << endl << b << endl;

    cout << endl;

    Hearing_aid c("egre",999,4);

    cout << "......" << endl;

    electronic_devices.push_back(&a);
    electronic_devices.push_back(&b);
    electronic_devices.push_back(&c);

    cout << "......" << endl;

    cout << b << endl << endl;

    ofstream ofs;
    ofs.open("file.txt", ios_base::out);
    ofs <<= b;
    ofs <<= a;
    ofs.close();

    ifstream ifs;
    ifs.open("file.txt", ios_base::in);
    ifs >> c;
    ifs.close();

    cout << c << endl;*/



    Smartphone a(1, 2, 3, "Samsung", 1234, true);
    cout << a << endl;

    cout << endl << endl;

    return 0;
}




