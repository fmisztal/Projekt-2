#pragma once
#include <iostream>
#include <cstring>
#include "Hearing_aid.h"
#include "electronic_device.h"

using namespace std;

int Hearing_aid::number_of_objects=0;

Hearing_aid::Hearing_aid(const string name, const double amplification_x, const int number_of_parameters)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Hearing_aid(const string name, const int production_year, const int number_of_parameters) [" << number_of_objects << "]" << endl;
    #endif

    m_name=name;
    m_amplification_x=amplification_x;
    m_number_of_parameters=number_of_parameters;

    if(number_of_parameters>0)
        m_parameter=new Parameter[number_of_parameters];
    else
        m_parameter=0;
};

Hearing_aid::Hearing_aid(Hearing_aid &h)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Hearing_aid(const Hearing_aid &h) [" << number_of_objects << "]" << endl;
    #endif

    m_name=h.m_name;
    m_amplification_x=h.m_amplification_x;
    m_number_of_parameters=h.m_number_of_parameters;

    if(h.m_parameter)
    {
        m_parameter=new Parameter[m_number_of_parameters];
        for(int i=0; i<m_number_of_parameters; i++)
            m_parameter[i]=h.m_parameter[i];    
        setBattery(h.battery());
    }
    else
        m_parameter = nullptr;
};

Hearing_aid::~Hearing_aid()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Hearing_aid() [" << number_of_objects << "]" << endl;
    #endif

    if (m_parameter != nullptr)
        delete[] m_parameter;
};

int Hearing_aid::objQuantity()
{
    return number_of_objects;
};

Hearing_aid& Hearing_aid::operator=(Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator=" << endl;
    #endif

    m_name=h.m_name;
    m_amplification_x=h.m_amplification_x;
    m_number_of_parameters=h.m_number_of_parameters;

    if(m_parameter)
        delete[] m_parameter;

    if(h.m_parameter)
    {
        m_parameter=new Parameter[m_number_of_parameters];
        for(int i=0; i<m_number_of_parameters; i++)
            m_parameter[i]=h.m_parameter[i];
    }
    else
        m_parameter=0;

    setBattery(h.battery());
    return *this;
};

bool Hearing_aid::operator==(const Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    if(m_battery==h.m_battery && m_name==h.m_name && m_amplification_x==h.m_amplification_x)
        if(m_number_of_parameters==h.m_number_of_parameters)
        {
            int x=0;
            for(int i=0; i<m_number_of_parameters; i++)
                if(m_parameter[i]==h.m_parameter[i])
                    x++;
            if(x==m_number_of_parameters)
                return true;
        }
    return false;
};

ostream& operator<<(ostream &s, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator<<" << endl;
    #endif

    s << "-----------------------------------------" << endl;
    s  << "Name: " << h.name() << ", Amplification x: " << h.amplification_x() << endl;
    s << h.battery() << "Others: ";
    for(int i=0; i<h.number_of_parameters(); i++)
    {
        if(i!=0)
            cout << ", ";
        cout << h.parameter()[i];
    }
    s << endl << "-----------------------------------------" << endl;
    return s;
};

Hearing_aid::operator string()
{
    #ifdef _DEBUG
        cout << "operator string()" << endl;
    #endif

    return "Current sound amplification: " + to_string(m_amplification_x);
};

void Hearing_aid::operator[](int number)
{
    #ifdef _DEBUG
        cout << "operator[]" << endl;
    #endif

    if(number>=m_number_of_parameters)
    {
        cout << "No such parameter" << endl;
        return;
    }
    cout << m_parameter[number] << endl;
    return;
};

Parameter *Hearing_aid::parameter()
{
    return m_parameter;
}

void Hearing_aid::setParameter(Parameter *parameter)
{
    m_parameter = parameter;
}

string Hearing_aid::name()
{
    return m_name;
}

void Hearing_aid::setName(const string &name)
{
    m_name = name;
}

int Hearing_aid::number_of_parameters()
{
    return m_number_of_parameters;
}

void Hearing_aid::setNumber_of_parameters(int number_of_parameters)
{
    m_number_of_parameters = number_of_parameters;
}

double Hearing_aid::amplification_x()
{
    return m_amplification_x;
}

void Hearing_aid::setAmplification_x(double amplification_x)
{
    m_amplification_x = amplification_x;
}

void operator>>(double x, Hearing_aid &h)
{
#ifdef _DEBUG
    cout << "operator>>" << endl;
#endif

    h.setAmplification_x(x);
};



