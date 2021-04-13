#pragma once
#include <iostream>
#include <cstring>
#include "parameters.h"

using namespace std;

int Parameter::number_of_objects=0;

Parameter::Parameter(const string name, const int value)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Parameter(const string name, const int value) [" << number_of_objects << "]" << endl;
    #endif

    m_name=name;
    m_value=value;
};

Parameter::~Parameter()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Parameter() [" << number_of_objects << "]" << endl;
    #endif
};

int Parameter::parQuantity()
{
    return number_of_objects;
};

void Parameter::addName(string name)
{
    m_name= name;
};

void Parameter::addValue(int value)
{
    m_value=value;
};

bool Parameter::operator==(const Parameter &p)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    return m_name==p.m_name && m_value==p.m_value;
}

string Parameter::name()
{
    return m_name;
}

void Parameter::setName(const string &name)
{
    m_name = name;
}

int Parameter::value()
{
    return m_value;
}

void Parameter::setValue(int value)
{
    m_value = value;
};

ostream& operator<<(ostream &s, Parameter &p)
{
#ifdef _DEBUG
    cout << "operator<<" << endl;
#endif
    
    if(p.name()=="")
        return s << "";

    if(p.value()==0)
        return s << p.name();

    return s << p.name() << "- " << p.value();
};
