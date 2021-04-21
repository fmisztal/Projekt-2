#ifndef USER_H
#define USER_H
#include <iostream>

using namespace std;

class User{
public:
    User(string name="", const int age=0, const int pesel=0);
    ~User();

    string name() const;
    void setName(const string &name);

    int age() const;
    void setAge(int age);

    int pesel() const;
    void setPesel(int pesel);

protected:
    string m_name;
    int m_age;
    int m_pesel;
    static int number_of_objects;
};

ostream& operator<<(ostream &s, const User &u);

#endif // USER_H
