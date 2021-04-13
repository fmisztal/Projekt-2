#ifndef ELECTRONIC_DEVICE_H
#define ELECTRONIC_DEVICE_H
#include "battery.h"
#include "user.h"

class Electronic_device{
public:
    Electronic_device(const int number_of_users=0, const int production_year=0);

    void operator++();
    void operator--();

    Battery &battery();
    void setBattery(Battery &battery);

    User *user();
    void setUser(User *user);

    int number_of_users();
    void setNumber_of_users(int number_of_users);

    int production_year();
    void setProduction_year(int production_year);

protected:
    Battery m_battery;
    User *m_user=nullptr;
    int m_number_of_users;
    int m_production_year;
};

#endif // ELECTRONIC_DEVICE_H
