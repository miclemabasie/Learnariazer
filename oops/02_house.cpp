#include <iostream>

using namespace std;

class House
{
private:
    // Member variables
    int len, wid;

    // Member functions
public:
    void setSize(int inlen, int inwid)
    {
        len = inlen;
        wid = inwid;
    }

    int calculateArea()
    {
        cout << "Area of house is " << len * wid << endl;
        return len * wid;
    }
};

int main(void)
{
    House house;
    house.setSize(500, 89);
    house.calculateArea();
    return 0;
}