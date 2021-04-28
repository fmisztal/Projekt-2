#ifndef ELECTRONIC_DEVICE_H
#define ELECTRONIC_DEVICE_H
#include "battery.h"
#include "user.h"

class Electronic_device{
public:
    Electronic_device(const int production_year=0);
    Electronic_device(const Electronic_device &e);
    virtual ~Electronic_device();

    void operator++();
    void operator--();

    virtual void ownership()=0;

    User& user();
    void setUser(const User &user);

    int number_of_users();
    void setNumber_of_users(int number_of_users);

    int production_year() const;
    void setProduction_year(int production_year);

    Battery& battery();
    void setBattery(const Battery &b);

protected:
    Battery m_battery;
    User m_user;
    int m_production_year;
    static int number_of_objects;
};

#endif // ELECTRONIC_DEVICE_H
