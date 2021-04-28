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

    for(int i=0; i<number_of_parameters; i++)
    {
        Parameter *a = new Parameter;
        parameters.push_back(a);
    }
};

Hearing_aid::Hearing_aid(const Hearing_aid &h)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Hearing_aid(const Hearing_aid &h) [" << number_of_objects << "]" << endl;
    #endif

    m_name=h.m_name;
    m_amplification_x=h.m_amplification_x;
    m_number_of_parameters=h.m_number_of_parameters;

    setProduction_year(h.production_year());

    m_battery.setSize(h.m_battery.size());
    m_battery.setLifespan(h.m_battery.lifespan());

    m_user.setAge(h.m_user.age());
    m_user.setPesel(h.m_user.pesel());
    m_user.setName(h.m_user.name());

    for(int i=0; i<m_number_of_parameters; i++)
    {
        Parameter *temp = new Parameter;
        temp->setName(h.parameters[i]->name());
        temp->setValue(h.parameters[i]->value());
        parameters.push_back(temp);
    }
};

Hearing_aid::~Hearing_aid()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Hearing_aid() [" << number_of_objects << "]" << endl;
    #endif

    parameters.clear();
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

    setProduction_year(h.production_year());
    //battery().setSize(h.battery().size());
    //battery().setLifespan(h.battery().lifespan());
    //battery()=h.battery();
    setBattery(h.battery());
    setUser(h.user());

    if(number_of_parameters()!=0)
        parameters.clear();
    if(h.number_of_parameters()!=0)
    {
        for(int i=0; i<number_of_parameters(); i++)
        {
            Parameter *temp = new Parameter;
            temp->setName(h.parameters[i]->name());
            temp->setValue(h.parameters[i]->value());
            parameters.push_back(temp);
        }
    }

    return *this;
};

bool Hearing_aid::operator==(const Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator==" << endl;
    #endif

    if(m_battery==h.m_battery && m_user==h.m_user && m_production_year==h.m_production_year && m_name==h.m_name && m_amplification_x==h.m_amplification_x)
        if(m_number_of_parameters==h.m_number_of_parameters)
        {
            int x=0;
            for(int i=0; i<m_number_of_parameters; i++)
                if(parameters[i]==h.parameters[i])
                    x++;
            if(x==m_number_of_parameters)
                return true;
        }
    return false;
};

void Hearing_aid::ownership()
{
    cout << "This HEARING AID belongs to " << m_user << endl;
}

ostream& operator<<(ostream &os, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator<<" << endl;
    #endif

    os << "-------------------------------------------------" << endl;
    os  << "Name: " << h.name() << " , Amplification: " << h.amplification_x() << " , Production year: " << h.production_year() << endl;
    os << h.battery();
    if(h.number_of_parameters()!=0)
    {
        os << "Number of parameters- " << h.number_of_parameters() << " : ";
        for(int i=0; i<h.number_of_parameters(); i++)
        {
            if(i!=0 && i<h.number_of_parameters())
                os << " , ";
            os << *(h.parameters[i]);
        }
        os << endl;
    }
    os << h.user();
    os << "-------------------------------------------------" << endl;
    return os;
};

ostream& operator<<=(ostream &os, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator<<=" << endl;
    #endif

    os << "---HEARING_AID---" << endl;
    os << h.name() << endl;
    os << h.amplification_x() << " , " << h.production_year() << endl;
    os <<= h.battery();
    if(h.number_of_parameters()!=0)
    {
        os << h.number_of_parameters() << endl;
        for(int i=0; i<h.number_of_parameters(); i++)
            os <<= *(h.parameters[i]);
    }
    os <<= h.user();
    return os;
}

istream& operator>>(istream &is, Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator>>" << endl;
    #endif

    string temp, name, par_name, username;
    char sign;
    int amplification, production_year, size , lifespan, number_of_parameters, par_value, age, pesel;

    getline(is, temp);
    while(temp!="---HEARING_AID---")
    {
        getline(is, temp);
        if(temp=="")
        {
            cout << "Couldn't find this kind of object in database" << endl;
            return is;
        }
    }
    getline(is, name);
    h.setName(name);
    is >> amplification >> sign >> production_year >> size >> sign >> lifespan >> number_of_parameters;
    h.setAmplification_x(amplification);
    h.setProduction_year(production_year);
    h.battery().setSize(size);
    h.battery().setLifespan(lifespan);
    h.setNumber_of_parameters(number_of_parameters);

    getline(is, temp);
    h.parameters.clear();
    for(int i=0; i<number_of_parameters; i++)
    {
        getline(is, par_name);
        is >> par_value;
        getline(is, temp);
        Parameter *temporary = new Parameter;
        temporary->setName(par_name);
        temporary->setValue(par_value);
        h.parameters.push_back(temporary);
    }
    getline(is, username);
    is >> age >> sign >> pesel;
    h.user().setName(username);
    h.user().setAge(age);
    h.user().setPesel(pesel);

    return is;
}

Hearing_aid::operator string()
{
    #ifdef _DEBUG
        cout << "operator string()" << endl;
    #endif

    return "Current sound amplification: " + to_string(m_amplification_x);
};

/*void Hearing_aid::operator[](int number)
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
};*/

string Hearing_aid::name() const
{
    return m_name;
}

void Hearing_aid::setName(const string &name)
{
    m_name = name;
}

int Hearing_aid::number_of_parameters() const
{
    return m_number_of_parameters;
}

void Hearing_aid::setNumber_of_parameters(int number_of_parameters)
{
    m_number_of_parameters = number_of_parameters;
}

double Hearing_aid::amplification_x() const
{
    return m_amplification_x;
}

void Hearing_aid::setAmplification_x(double amplification_x)
{
    m_amplification_x = amplification_x;
}

void operator|=(double x, Hearing_aid &h)
{
#ifdef _DEBUG
    cout << "operator|=" << endl;
#endif

    h.setAmplification_x(x);
};











