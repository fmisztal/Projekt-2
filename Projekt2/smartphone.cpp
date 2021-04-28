#pragma once
#include "smartphone.h"
#include "phone.h"
#include "electronic_device.h"

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

    setProduction_year(s.production_year());

    m_battery.setSize(s.m_battery.size());
    m_battery.setLifespan(s.m_battery.lifespan());

    m_user.setAge(s.m_user.age());
    m_user.setPesel(s.m_user.pesel());
    m_user.setName(s.m_user.name());

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
    setProduction_year(s.production_year());

    m_battery.setSize(s.m_battery.size());
    m_battery.setLifespan(s.m_battery.lifespan());

    m_user.setAge(s.m_user.age());
    m_user.setPesel(s.m_user.pesel());
    m_user.setName(s.m_user.name());

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
    return m_battery==s.m_battery && m_user==s.m_user && m_brand==s.m_brand && m_processor==s.m_processor &&
            m_dual_sim==s.m_dual_sim && m_inches==s.m_inches && m_weight==s.m_weight && m_megapiksels==s.m_megapiksels;
}

void Smartphone::ownership()
{
    cout << "This SMARTPHONE belongs to " << m_user << endl;
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

ostream& operator<<(ostream &ost, Smartphone &s)
{ 
    ost << "-------------------------------------------------" << endl;
    ost << "Smartphone: brand- " << s.brand() << " , processor- " << s.processor() << " , dual sim- " << s.dual_sim() << endl;
    ost << "Inches- " << s.inches() << " , weight= " << s.weight() << " , megapiksels- " << s.megapiksels() << endl;
    ost << s.production_year() << endl << s.battery() << s.user();
    return ost << "-------------------------------------------------" << endl;
}

ostream& operator<<=(ostream &ost, Smartphone &s)
{
    ost << "---SMARTPHONE---" << endl;
    ost << s.brand() << endl << s.processor() << " , " << s.dual_sim() << endl << s.production_year() << endl;
    ost << s.inches() << " , " << s.weight() << " , " << s.megapiksels() << endl;
    ost <<= s.battery();
    ost <<= s.user();

    return ost;
}

istream& operator>>(istream &is, Smartphone &s)
{
    #ifdef _DEBUG
        cout << "operator>>" << endl;
    #endif

    string temp, brand, username;
    char sign;
    bool dual_sim;
    int processor, production_year, size , lifespan, age, pesel, inches, weight, megapiksels;

    getline(is, temp);
    while(temp!="---SMARTPHONE---")
    {
        getline(is, temp);
        if(temp=="")
        {
            cout << "Couldn't find this kind of object in database" << endl;
            return is;
        }
    }
    getline(is, brand);
    is >> processor >> sign >> dual_sim >> production_year;
    is >> inches >> sign >> weight >> sign >> megapiksels >> size >> sign >> lifespan;
    getline(is, temp);
    getline(is, username);
    is >> age >> sign >> pesel;

    s.setProduction_year(production_year);
    s.battery().setSize(size);
    s.battery().setLifespan(lifespan);
    s.user().setName(username);
    s.user().setAge(age);
    s.user().setPesel(pesel);

    s.setBrand(brand);
    s.setDual_sim(dual_sim);
    s.setProcessor(processor);
    s.setInches(inches);
    s.setMegapiksels(megapiksels);
    s.setWeight(weight);

    return is;
}









