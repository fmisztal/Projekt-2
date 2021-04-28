#pragma once
#include "smartphone.h"

int Smartphone::number_of_objects=0;

Smartphone::Smartphone(const int inches, const int weight, const int megapiksels, const string brand, const int processor, const bool dual_sim)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Smartphone(const int inches, const int weight, const int megapiksels) [" << number_of_objects << "]" << endl;
    #endif

    m_inches=inches;
    m_weight=weight;
    m_megapiksels=megapiksels;
    m_brand=brand;
    m_processor=processor;
    m_dual_sim=dual_sim;
}

Smartphone::Smartphone(const Smartphone &s)
{
    number_of_objects++;

    #ifdef _DEBUG
        cout << "Smartphone(const Smartphone &s) [" << number_of_objects << "]" << endl;
    #endif

    m_inches=inches();
    m_weight=weight();
    m_megapiksels=megapiksels();
    m_brand=s.brand();
    m_processor=s.processor();
    m_dual_sim=s.dual_sim();
}

Smartphone::~Smartphone()
{
    number_of_objects--;

    #ifdef _DEBUG
        cout << "~Smartphone() [" << number_of_objects << "]" << endl;
    #endif
}

Smartphone& Smartphone::operator=(const Smartphone &s)
{
    m_inches=s.inches();
    m_weight=s.weight();
    m_megapiksels=s.megapiksels();
    m_brand=s.brand();
    m_processor=s.processor();
    m_dual_sim=s.dual_sim();
    return *this;
}

bool Smartphone::operator==(const Smartphone &s)
{
    return m_inches==s.m_inches && m_weight==s.m_weight && m_megapiksels==s.m_megapiksels && m_brand==s.m_brand && m_processor==s.m_processor && m_dual_sim==s.m_dual_sim;
}

int Smartphone::inches() const
{
    return m_inches;
}

void Smartphone::setInches(int inches)
{
    m_inches = inches;
}

int Smartphone::weight() const
{
    return m_weight;
}

void Smartphone::setWeight(int weight)
{
    m_weight = weight;
}

int Smartphone::megapiksels() const
{
    return m_megapiksels;
}

void Smartphone::setMegapiksels(int megapiksels)
{
    m_megapiksels = megapiksels;
}

ostream& operator<<(ostream ost, Smartphone &s)
{
    ost << "Smartphone: brand- " << s.brand() << " , processor- " << s.processor() << " , dual sim- " << s.dual_sim() << endl;
    return ost << "Inches- " << s.inches() << " , weight= " << s.weight() << " , megapiksels- " << s.megapiksels();
}

ostream& operator<<=(ostream &ost, Smartphone &s)
{
    ost << s.brand() << endl << s.processor() << endl << s.dual_sim() << endl;
    return ost << s.inches() << endl << s.weight() << endl << s.megapiksels();
}





