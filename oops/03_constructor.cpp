#include <iostream>
#include <raylib.h>
#include <string>

using namespace std;

class House
{
private:
    int len, wid;

public:
    // Using a constructor
    House(int x, int y)
    {
        len = x;
        wid = y;
    }

    void calculateArea()
    {
        cout << len * wid << " is the area of the house." << endl;
    }
};

class Person
{
private:
    string name;
    int age;
    float h;

public:
    // NON-PARAMETIZED CONSTRUCTOR
    Person()
    {
        name = "Null";
        age = 0;
        h = 0;
    }
    // PARAMETIZED CONSTRUCTOR
    Person(string username, int userage, float userhieght)
    {
        name = username;
        age = userage;
        h = userhieght;
    }

    // CONSTRUCTOR OVERLOADING
    // Person(string username = "Null", int userage = 0, float userhieght = 0.0f)
    // {
    //     name = username;
    //     age = userage;
    //     h = userhieght;
    // }

    // COPY CONSTRUCTOR
    Person(Person &person)
    {
        name = person.name;
        age = person.age;
        h = person.h;
    }

    void showPerson()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Hieght: " << h << endl;
        cout << "======================================" << endl;
    }
};

int main(void)
{
    // non-parametized constructor
    Person miclem;

    // parametized constructor
    Person abasie("Abasie", 23, 6.7);

    // copy constructor
    Person ngoh(abasie);

    miclem.showPerson();
    abasie.showPerson();
    ngoh.showPerson();
    return 0;
}