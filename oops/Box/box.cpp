#include <iostream>


using namespace std;


class Box {

    public:
    int X, Y;
    public:
    Box() {
        X=0;Y=0;
    }

    Box(int x, int y) {
        X = x; Y = y;
    }

    Box(Box &b){
        X = b.Y; Y = b.Y;
    }

    public:
    int area() {
        return X * Y;
    }

    int operator+(Box b) {
        X += b.X;
        Y += b.Y;

        return X * Y;
    }
};


int main() {


    Box b(1, 12);
    Box b1(7, 10);
    // cout << b.Y;
    cout << b.area() << endl;
    cout << b1.area() << endl;
    cout << b1 + b << endl;
    cout << b1.area() << endl;
    return 0;
}


