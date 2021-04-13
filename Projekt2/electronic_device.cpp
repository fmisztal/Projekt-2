#pragma once
#include "electronic_device.h"

Electronic_device::Electronic_device(const int number_of_users, const int production_year)
{
    m_number_of_users=number_of_users;
    m_production_year=production_year;

    if(number_of_users>0)
        m_user=new User[number_of_users];
    else
        m_user=0;
}

Battery& Electronic_device::battery()
{
    return m_battery;
}

void Electronic_device::setBattery( Battery &battery)
{
    m_battery = battery;
}

User *Electronic_device::user()
{
    return m_user;
}

void Electronic_device::setUser(User *user)
{
    m_user = user;
}

int Electronic_device::number_of_users()
{
    return m_number_of_users;
}

void Electronic_device::setNumber_of_users(int number_of_users)
{
    m_number_of_users = number_of_users;
}

int Electronic_device::production_year()
{
    return m_production_year;
}

void Electronic_device::setProduction_year(int production_year)
{
    m_production_year = production_year;
}


void Electronic_device::operator++()
{
    #ifdef _DEBUG
        cout << "operator++" << endl;
    #endif

    int x=m_battery.lifespan()+5;
    m_battery.setLifespan(x);
};

void Electronic_device::operator--()
{
    #ifdef _DEBUG
        cout << "operator--" << endl;
    #endif

    int x=m_battery.lifespan()-5;
    m_battery.setLifespan(x);
}






