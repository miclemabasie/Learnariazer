#include <iostream>

using namespace std;

// user one
struct bankuser
{
    /* data */
    // char username[10];
    int id;
    int blc;
    float pin;
    int age = 32;
};
void checkBalance(bankuser bu)
{
    cout << "The bank balance of the user with id: " << bu.id << " is:";
    cout << bu.blc << endl;
}
class BankUser
{
private:
    string username;
    int userid, pin, age;
    float balance;

public:
    void set_vars(string b_username, int b_userid, int b_pin, int b_age, float b_balance)
    {
        username = b_username;
        userid = b_age;
        pin = b_pin;
        age = b_age;
        balance = b_balance;
    }

    void get_balance()
    {
        cout << username << " Your balance is " << balance << endl;
    }
};

int main(void)
{

    BankUser bu;
    bu.set_vars("Miclem", 1, 1001, 23, 30000);

    bu.get_balance();
    // b1.get_balance();
    return 0;
}

// int main(void)
// {
//     // user one
//     bankuser user1;
//     user1.id = 2923823;
//     user1.blc = 500;
//     user1.pin = 1000;
//     user1.age = 32;
//     bankuser user2;
//     user2.id = 132342;
//     user2.age = 23;
//     user2.blc = 30000;
//     user2.pin = 3000;

//     checkBalance(user1);
//     checkBalance(user2);
//     return 0;
// }
