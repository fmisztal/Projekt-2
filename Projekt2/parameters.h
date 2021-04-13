#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <iostream>
#include <cstring>

using namespace std;

class Parameter{
public:
    Parameter(const string name="", const int value=0);
    ~Parameter();

    void addName(string name);
    void addValue(int value);
    static int parQuantity();

    bool operator==(const Parameter &p);

    string name();
    void setName(const string &name);

    int value();
    void setValue(int value);

protected:
    string m_name;
    int m_value;
    static int number_of_objects;
};

ostream& operator<<(ostream &s, Parameter &p);

#endif // PARAMETERS_H
