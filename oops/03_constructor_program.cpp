#include <iostream>
#include <string>

using namespace std;

class Phone
{
private:
    string name, processor;
    int ram, battery;

public:
    Phone(string p_name = "Null", string p_processor = "Null", int p_ram = 0, int p_battery = 0)
    {
        name = p_name;
        processor = p_processor;
        ram = p_ram;
        battery = p_battery;
    }

    Phone(Phone &phone)
    {
        name = phone.name;
        processor = phone.processor;
        ram = phone.ram;
        battery = phone.battery;
    }

    void showPhone()
    {
        cout << "Name: " << name << endl;
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << endl;
        cout << "Battery: " << battery << endl;
        cout << "==================================" << endl;
    }
};

int main(void)
{
    Phone unknown, pixel("Google Pixel 4a", "snapDragon", 6, 5000), pixel2(pixel);

    unknown.showPhone();
    pixel.showPhone();
    pixel2.showPhone();

    return 0;
}
