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

void Battery::addSize(int size)
{
    m_size=size;
}

void Battery::addLifespan(int lifespan)
{
    m_lifespan=lifespan;
}

bool Battery::operator==(const Battery &b)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    return m_size==b.m_size && m_lifespan==b.m_lifespan;
}

int Battery::size()
{
    return m_size;
}

void Battery::setSize(int size)
{
    m_size = size;
}

int Battery::lifespan()
{
    return m_lifespan;
}

void Battery::setLifespan(int lifespan)
{
    m_lifespan = lifespan;
};

ostream& operator<<(ostream &s, Battery &b)
{
#ifdef _DEBUG
    cout << "operator<<" << endl;
#endif

    return s << "Battery: size- " << b.size() << ", Lifespan- " << b.lifespan() << " hours" << endl;
};

Battery& Battery::operator=(Battery &b)
{
    b.setSize(size());
    b.setLifespan(lifespan());
}










