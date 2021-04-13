#ifndef HEARING_AID_H
#define HEARING_AID_H
#include "battery.h"
#include "parameters.h"
#include "electronic_device.h"

using namespace std;

class Hearing_aid : public Electronic_device{
public:
    Hearing_aid(Hearing_aid &h);
    Hearing_aid(const string name="", const double amplification_x=0, const int number_of_patrameters=0);
    ~Hearing_aid();

    static int objQuantity();

    Hearing_aid& operator=(Hearing_aid &h);
    bool operator==(const Hearing_aid &h);
    void operator[](int number);
    operator string();

    Parameter *parameter();
    void setParameter(Parameter *parameter);

    string name();
    void setName(const string &name);

    int number_of_parameters();
    void setNumber_of_parameters(int number_of_parameters);

    double amplification_x();
    void setAmplification_x(double amplification_x);

protected:
    Parameter *m_parameter=nullptr;
    string m_name;
    int m_number_of_parameters;
    double m_amplification_x;

    static int number_of_objects;
};

ostream& operator<<(ostream &s, Hearing_aid &h);
void operator>>(double x, Hearing_aid &h);

#endif // HEARING_AID_H

