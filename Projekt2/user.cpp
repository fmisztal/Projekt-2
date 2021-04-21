#pragma once
#include "battery.h"
#include "user.h"

using namespace std;

int User::number_of_objects=0;

User::User(string name, const int age, const int pesel)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "User(string name, const int age, const int pesel) [" << number_of_objects << "]" << endl;
    #endif

    m_name=name;
    m_age=age;
    m_pesel=pesel;
}

User::~User()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~User() [" << number_of_objects << "]" << endl;
    #endif
}

string User::name() const
{
    return m_name;
}

void User::setName(const string &name)
{
    m_name = name;
}

int User::age() const
{
    return m_age;
}

void User::setAge(int age)
{
    m_age = age;
}

int User::pesel() const
{
    return m_pesel;
}

void User::setPesel(int pesel)
{
    m_pesel = pesel;
};

ostream& operator<<(ostream &s, const User &u)
{
    s << "User: " << u.name() << " , " << u.age() << " , " << u.pesel() << endl;

}












