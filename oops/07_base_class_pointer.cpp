#include <iostream>

using namespace std;

class Base
{

public:
    // Create a virtual function to ensure that the function which is called is that of the derived class
    // virtual void give()
    // {
    //     cout << "Give gum from base" << endl;
    // }

    // // Create a pure virtual function so that no instance of the class Base can ever be created
    virtual void give() = 0;
};

class Boy : public Base
{
public:
    void give()
    {
        cout << "Give gum to boy" << endl;
    }
};

class Girl : public Base
{
public:
    void give()
    {
        cout << "Give gum to girl" << endl;
    }
};
int main(void)
{
    // We can not achieve the following 2 lines because the Base class has been set to abstract
    // due to the presence of of a virtual pure function inside the class
    // Base base;
    // base.give();

    // This is a base class pointer
    Base *ptr = new Boy;
    Base *ptrg = new Girl;
    ptr->give();
    ptrg->give();
    return 0;
}