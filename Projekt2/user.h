#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User{
public:
    User(string name="", const int age=0, const int pesel=0);

    string getName();
    void setName(const string &value);

    int getAge();
    void setAge(int value);

    int getPesel();
    void setPesel(int value);

protected:
    string m_name;
    int m_age;
    int m_pesel;
};


#endif // USER_H
