#include <iostream>

using namespace std;

class Car
{

private:
    string make, model;
    int price;

public:
    Car(string in_make, string in_model, int in_price)
    {
        make = in_make;
        model = in_model;
        price = in_price;
    }

    void showcar()
    {
        cout << "Car" << endl
             << "Make: " << make << " Model: " << model << ", Price: " << price << endl;
    }

    int addCars(Car car1, Car car2)
    {
        int x = car1.price + car2.price;
        return x;
    }

    int operator+(Car car1)
    {
        int total_price = car1.price + price;
        return total_price;
    }

    bool operator!=(Car car1)
    {
        if (make != car1.make)
        {
            return false;
        }
        return true;
    }

    // pre increment
    void operator++()
    {
        cout << "Price for Car " << make << " is : " << price << endl;
        ++price;
        cout << "New price for car " << make << " is : " << price << endl;
    }

    // post increment
    void operator++(int)
    {
        cout << "Price for Car " << make << " is : " << price << endl;
        price++;
        cout << "New price for car " << make << " is : " << price << endl;
    }
};

int main(void)
{

    Car toyota("toyota", "auris", 232);
    Car isuzu("toyota", "troper-II", 300);

    cout << "Price addition" << toyota + isuzu << endl;
    bool issame = toyota != isuzu;
    cout << "Is the same: " << issame << endl;

    toyota.showcar();
    isuzu.showcar();
    ++isuzu;
    toyota++;
    // cout << toyota.addCars(isuzu, toyota) << endl;
    return 0;
}