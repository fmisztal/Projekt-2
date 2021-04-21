#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>

using namespace std;

class Battery{
public:
    Battery(const int size=0, const int lifespan=0);
    ~Battery();

    static int batQuantity();

    //void operator=(Battery &b);
    bool operator==(const Battery &b);

    int size() const;
    void setSize(int size);

    int lifespan() const;
    void setLifespan(int lifespan);

protected:
    int m_size;
    int m_lifespan;
    static int number_of_objects;
};

ostream& operator<<(ostream &ost, const Battery &b);

#endif // BATTERY_H
