#include <iostream>

using namespace std;

class Rectangle
{
public:
    int length;
    int breath;

    void show()
    {

        cout << length << endl;
        cout << breath << endl;
    }

    int area()
    {
        return length * breath;
    }
};

class Cubiod : public Rectangle
{
public:
    int height;

    void display()
    {
        cout << height << endl;
    }

    int volume()
    {
        return area() * height;
    }
};

int main(void)
{
    Rectangle rec;
    rec.length = 10;
    rec.breath = 5;
    rec.show();
    cout << rec.area() << endl;

    printf("====================================== \n");
    // Creating a cubiod
    Cubiod c;
    c.length = 10;
    c.breath = 2;
    c.display();
    c.height = 5;
    c.show();
    cout << "Printing area of cube " << c.area() << endl;
    cout << "Printing volume of cube" << c.volume() << endl;
    return 0;
}