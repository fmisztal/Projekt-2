#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>

using namespace std;

class Battery{
public:
    Battery(const int size=0, const int lifespan=0);
    ~Battery();

    void addSize(int size);
    void addLifespan(int lifespan);
    static int batQuantity();

    Battery& operator=(Battery &b);
    bool operator==(const Battery &b);

    int size();
    void setSize(int size);

    int lifespan();
    void setLifespan(int lifespan);

protected:
    int m_size;
    int m_lifespan;
    static int number_of_objects;
};

ostream& operator<<(ostream &s, Battery &b);

#endif // BATTERY_H
