#include <iostream>

using namespace std;

// Only the non-parametized constructor of the base class can be call when a class is inherited
// Note: 1ar Defualt constructor of base class, then Default constructor of derived class is called
// If the is no paramatized constructor in the derived class and we try to create an object based on it
// it returns and error
// A parametized object creation can only be initiated when the derived class has it's own parametized constructor
// An the parametize constructor of base class is never called when derived class has it's own
// It should also be noted that the Default constructor of the base class is always called regardless.

// Part 3

// how to call param constructor of the base class
// usin the syntax derive():base() this tells the compiler that we are about to execute the constructor of the base class
// using derived(int d_arg):base(d_arg) this also allows us to call the parametized constructor of the base class

class Base
{

public:
    Base()
    {
        cout << "Constructor of the base class" << endl;
    }
    Base(int x)
    {
        cout << "This is the parametized constructor of this class " << endl;
    }
};

class Derived : public Base
{
public:
    Derived() : Base()
    {
        cout << "This is the default constructor of the derived class " << endl;
    }

    Derived(int x) : Base(x)
    {
        cout << "This is parametized constructor of derived class " << endl;
    }
    // Empty class
};

int main(void)
{

    Derived d;
    Base d1(9);
    return 0;
}
