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

Battery::Battery(const Battery &b)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Battery(const Battery &b) [" << number_of_objects << "]" << endl;
    #endif

    m_size=b.size();
    m_lifespan=b.lifespan();
}

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

ostream& operator<<(ostream &ost, Battery &b)
{
//#ifdef _DEBUG
//    cout << "operator<<" << endl;
//#endif

    return ost << "Battery: size- " << b.size() << " , Lifespan- " << b.lifespan() << " hours" << endl;
};

ostream& operator<<=(ostream &ost, Battery &b)
{
    return ost << b.size() << " , " << b.lifespan() << endl;
}

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
}

int Battery::lifespan() const
{
    return m_lifespan;
}

void Battery::setLifespan(int lifespan)
{
    m_lifespan = lifespan;
}










