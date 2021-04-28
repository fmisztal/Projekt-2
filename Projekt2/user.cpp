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

User::User(const User &u)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "User(const User &u) [" << number_of_objects << "]" << endl;
    #endif

    m_name=u.name();
    m_age=u.age();
    m_pesel=u.pesel();
}

User::~User()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~User() [" << number_of_objects << "]" << endl;
    #endif
}

int User::userQuantity()
{
    return number_of_objects;
};

User& User::operator=(const User &b)
{
    m_name=b.name();
    m_age=b.age();
    m_pesel=b.pesel();
    return *this;
}

bool User::operator==(const User &b)
{
    return m_name==b.m_name && m_age==b.m_age && m_pesel==b.m_pesel;
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

ostream& operator<<(ostream &s, User &u)
{
    return s << "user: " << u.name() << " , " << u.age() << " , " << u.pesel() << endl;
}

ostream& operator<<=(ostream &s, User &u)
{
    return s << u.name() << endl << u.age() << " , " << u.pesel() << endl;
}













