#pragma once
#include "battery.h"
#include "user.h"

using namespace std;

User::User(string name, const int age, const int pesel)
{
    m_name=name;
    m_age=age;
    m_pesel=pesel;
};

string User::getName()
{
    return m_name;
}

void User::setName(const string &value)
{
    m_name = value;
}

int User::getAge()
{
    return m_age;
}

void User::setAge(int value)
{
    m_age = value;
}

int User::getPesel()
{
    return m_pesel;
}

void User::setPesel(int value)
{
    m_pesel = value;
}
