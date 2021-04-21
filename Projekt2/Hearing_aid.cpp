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

    /*if(number_of_parameters>0)
        m_parameter=new Parameter[number_of_parameters];
    else
        m_parameter=0;*/
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
    battery().setSize(h.battery().size());
    battery().setLifespan(h.battery().lifespan());
    setUser(h.user());

    for(int i=0; i<m_number_of_parameters; i++)
        parameters.push_back(h.parameters[i]);

    /*if(h.m_parameter)
    {
        m_parameter=new Parameter[m_number_of_parameters];
        for(int i=0; i<m_number_of_parameters; i++)
            m_parameter[i]=h.m_parameter[i];    
        setBattery(h.battery());
    }
    else
        m_parameter = nullptr;*/
};

Hearing_aid::~Hearing_aid()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Hearing_aid() [" << number_of_objects << "]" << endl;
    #endif

    parameters.clear();

    /*if (m_parameter != nullptr)
        delete[] m_parameter;*/
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
    battery().setSize(h.battery().size());
    battery().setLifespan(h.battery().lifespan());
    setUser(h.user());

    if(number_of_parameters()!=0)
        parameters.clear();
    if(h.number_of_parameters()!=0)
    {
        //Parameter *a = new Parameter;
        for(int i=0; i<number_of_parameters(); i++)
        {
            //a=h.parameters[i];
            parameters.push_back(h.parameters[i]);
        }
    }


    /*if(m_parameter)
        delete[] m_parameter;

    if(h.m_parameter)
    {
        m_parameter=new Parameter[m_number_of_parameters];
        for(int i=0; i<m_number_of_parameters; i++)
            m_parameter[i]=h.m_parameter[i];
    }
    else
        m_parameter=0;*/

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
                if(parameters[i]==h.parameters[i])
                    x++;
            if(x==m_number_of_parameters)
                return true;
        }
    return false;
};

ostream& operator<<(ostream &os, const Hearing_aid &h)
{
    #ifdef _DEBUG
        cout << "operator<<" << endl;
    #endif

    os << "-----------------------------------------" << endl;
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
    os << "-----------------------------------------" << endl;
    return os;
};

istream& operator>>(istream &is, Hearing_aid &h)
{
#ifdef _DEBUG
    cout << "operator>>" << endl;
#endif
    string temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
    string name, user_name, par_name, par_name2;
    double amplification;
    int production_year, bat_size, bat_lifespan, number_of_parameters, par_value, par_value2;
    is >> temp1 >> temp2 >> name >> temp4 >> temp5 >> amplification >> temp7 >> temp8 >> temp9 >> production_year;
    //cout << " 1: " << temp1 << endl << " 2: " << temp2 << " 3: " << name << " 4: " << temp4 << " 5: " << temp5 << " 6: " << amplification
    //     << " 7: " << temp7 << " 8: " << temp8 << " 9: " << temp9 << production_year << endl;
    is >> temp1 >> temp2 >> bat_size >> temp3 >> temp4 >> bat_lifespan >> temp6;
    //cout << bat_size << " " << bat_lifespan << endl;

    is >> temp1 >> temp2 >> temp3 >> number_of_parameters >> temp4;
    cout << number_of_parameters << " : ";

    //is >> temp1 >> temp2 >> temp3 >> temp4 >> temp5 >> temp6 >> temp7;
    //cout << temp1 << temp2 << temp3 << temp4 << temp5 << temp6 << temp7;
    for(int i=0; i<number_of_parameters; i++)
    {
        if(i==0)
        {
            is >> par_name >> temp1 >> par_value;
            cout << " 0: " << par_name << temp1 << par_value << " .. ";
        }
        if(i==1)
        {
            is >> par_name >> temp1 >> par_value;
            cout << " 1: " << par_name << temp1 << par_value << " .. ";
        }
        //h.parameters[i]->setName(par_name);
        //h.parameters[i]->setValue(par_value);
    }
    cout << endl;

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

/*Parameter *Hearing_aid::parameter()
{
    return m_parameter;
}

void Hearing_aid::setParameter(Parameter *parameter)
{
    m_parameter = parameter;
}*/

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
    cout << "operator>>" << endl;
#endif

    h.setAmplification_x(x);
};











