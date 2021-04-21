#pragma once
#include <iostream>
#include "battery.h"

using namespace std;

int Battery::number_of_objects=0;

Battery::Battery(const int size, const int lifespan)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Battery(const int size, const int lifespan) [" << number_of_objects << "]" << endl;
    #endif

    m_size=size;
    m_lifespan=lifespan;
};

Battery::~Battery()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Battery() [" << number_of_objects << "]" << endl;
    #endif
};

int Battery::batQuantity()
{
    return number_of_objects;
};

bool Battery::operator==(const Battery &b)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    return m_size==b.m_size && m_lifespan==b.m_lifespan;
}

ostream& operator<<(ostream &ost, const Battery &b)
{
//#ifdef _DEBUG
//    cout << "operator<<" << endl;
//#endif

    return ost << "Battery: size- " << b.size() << " , Lifespan- " << b.lifespan() << " hours" << endl;
};

/*void Battery::operator=(Battery &b)
{
    b.setSize(size());
    b.setLifespan(lifespan());
}*/

int Battery::size() const
{
    return m_size;
}

void Battery::setSize(int size)
{
    m_size = size;
    cout << m_size << endl;
}

int Battery::lifespan() const
{
    return m_lifespan;
}

void Battery::setLifespan(int lifespan)
{
    m_lifespan = lifespan;
}










