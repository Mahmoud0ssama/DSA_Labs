#ifndef EMP_H
#define EMP_H

#include <string>
using namespace std;

class emp
{
public:
    int ID;
    string Name;
    int Age;

    emp() {}

    emp(int id, string name, int age)
    {
        ID = id;
        Name = name;
        Age = age;
    }
};

#endif
