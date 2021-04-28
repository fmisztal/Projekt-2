#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "phone.h"

class Smartphone : public Phone{
public:
    Smartphone(const int inches=0, const int weight=0, const int megapiksels=0, const string brand="", const int processor=0, const bool dual_sim=false);
    Smartphone(const Smartphone &s);
    ~Smartphone();

    Smartphone& operator=(const Smartphone &s);
    bool operator==(const Smartphone &s);

    int inches() const;
    void setInches(int inches);

    int weight() const;
    void setWeight(int weight);

    int megapiksels() const;
    void setMegapiksels(int megapiksels);

private:
    int m_megapiksels;
    int m_inches;
    int m_weight;
    static int number_of_objects;
};

ostream& operator<<(ostream &ost, Smartphone &s);
ostream& operator<<=(ostream &ost, Smartphone &s);

#endif // SMARTPHONE_H
