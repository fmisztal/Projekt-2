#pragma once
#include "phone.h"
#include "electronic_device.h"

int Phone::number_of_objects=0;

Phone::Phone(string brand, const int processor, const bool dual_sim)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Phone(string brand, const int processor, const bool dual_sim) [" << number_of_objects << "]" << endl;
    #endif

    m_brand=brand;
    m_processor=processor;
    m_dual_sim=dual_sim;
}

Phone::Phone(const Phone &p)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Phone(const Phone &p) [" << number_of_objects << "]" << endl;
    #endif

    m_brand=p.brand();
    m_processor=p.processor();
    m_dual_sim=p.dual_sim();
}

Phone::~Phone()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Phone() [" << number_of_objects << "]" << endl;
    #endif
}

int Phone::phoneQuantity()
{
    return number_of_objects;
};

Phone& Phone::operator=(const Phone &p)
{
    m_brand=p.brand();
    m_processor=p.processor();
    m_dual_sim=p.dual_sim();
    return *this;
}

bool Phone::operator==(const Phone &p)
{
    return m_brand==p.m_brand && m_processor==p.m_processor && m_dual_sim==p.m_dual_sim;
}

string Phone::brand() const
{
    return m_brand;
}

void Phone::setBrand(const string &brand)
{
    m_brand = brand;
}

int Phone::processor() const
{
    return m_processor;
}

void Phone::setProcessor(int processor)
{
    m_processor = processor;
}

bool Phone::dual_sim() const
{
    return m_dual_sim;
}

void Phone::setDual_sim(bool dual_sim)
{
    m_dual_sim = dual_sim;
}

ostream& operator<<(ostream &ost, Phone &p)
{
    return ost << "Phone: brand- " << p.brand() << " , processor- " << p.processor() << " , dual sim- " << p.dual_sim() << endl;
};

ostream& operator<<=(ostream &ost, Phone &p)
{
    return ost << p.brand() << endl << p.processor() << endl << p.dual_sim() << endl;
}







