#ifndef PHONE_H
#define PHONE_H
#include "electronic_device.h"

class Phone : public Electronic_device{
public:
    Phone(string brand="", const int processor=0, const bool dual_sim=true);

    string brand() const;
    void setBrand(const string &brand);

    int processor() const;
    void setProcessor(int processor);

    bool dual_sim() const;
    void setDual_sim(bool dual_sim);

protected:
    string m_brand;
    int m_processor;
    bool m_dual_sim;

};

#endif // PHONE_H
