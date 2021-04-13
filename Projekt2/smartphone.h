#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "phone.h"

class Smartphone : public Phone{
public:
    Smartphone(const int inches=0, const int weight=0, const int megapiksels=0);

    int inches();
    void setInches(int inches);

    int weight();
    void setWeight(int weight);

    int megapiksels();
    void setMegapiksels(int megapiksels);

private:
    int m_megapiksels;
    int m_inches;
    int m_weight;

};

#endif // SMARTPHONE_H
