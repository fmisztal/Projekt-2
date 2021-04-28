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

    setProduction_year(p.production_year());

    m_battery.setSize(p.m_battery.size());
    m_battery.setLifespan(p.m_battery.lifespan());

    m_user.setAge(p.m_user.age());
    m_user.setPesel(p.m_user.pesel());
    m_user.setName(p.m_user.name());

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
    setProduction_year(p.production_year());

    m_battery.setSize(p.m_battery.size());
    m_battery.setLifespan(p.m_battery.lifespan());

    m_user.setAge(p.m_user.age());
    m_user.setPesel(p.m_user.pesel());
    m_user.setName(p.m_user.name());

    m_brand=p.brand();
    m_processor=p.processor();
    m_dual_sim=p.dual_sim();
    return *this;
}

bool Phone::operator==(const Phone &p)
{
    return m_battery==p.m_battery && m_user==p.m_user && m_brand==p.m_brand && m_processor==p.m_processor && m_dual_sim==p.m_dual_sim;
}

void Phone::ownership()
{
    cout << "This PHONE belongs to " << m_user << endl;
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
    ost << "-------------------------------------------------" << endl;
    ost << "Phone: brand- " << p.brand() << " , processor- " << p.processor() << " , dual sim- " << p.dual_sim() << endl;
    ost << p.production_year() << endl << p.battery() << p.user();
    return ost << "-------------------------------------------------" << endl;
};

ostream& operator<<=(ostream &ost, Phone &p)
{
    ost << "---PHONE---" << endl;
    ost << p.brand() << endl << p.processor() << " , " << p.dual_sim() << endl << p.production_year() << endl;
    ost <<= p.battery();
    ost <<= p.user();

    return ost;
}

istream& operator>>(istream &is, Phone &p)
{
    #ifdef _DEBUG
        cout << "operator>>" << endl;
    #endif

    string temp, brand, username;
    char sign;
    bool dual_sim;
    int processor, production_year, size , lifespan, age, pesel;

    getline(is, temp);
    while(temp!="---PHONE---")
    {
        getline(is, temp);
        if(temp=="")
        {
            cout << "Couldn't find this kind of object in database" << endl;
            return is;
        }
    }
    getline(is, brand);
    is >> processor >> sign >> dual_sim >> production_year >> size >> sign >> lifespan;
    getline(is, temp);
    getline(is, username);
    is >> age >> sign >> pesel;

    p.setProduction_year(production_year);
    p.battery().setSize(size);
    p.battery().setLifespan(lifespan);
    p.user().setName(username);
    p.user().setAge(age);
    p.user().setPesel(pesel);

    p.setBrand(brand);
    p.setDual_sim(dual_sim);
    p.setProcessor(processor);

    return is;
}






