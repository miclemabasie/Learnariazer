#include <iostream>

using namespace std;

void withrawal(float new_balance, float &oldpointer)
{
    oldpointer = oldpointer - new_balance;
    printf("New balance after update in withrawal function %f\n", oldpointer);
}
int main(void)
{
    float balance = 100.0;
    string name;
    int pin;

    withrawal(43, balance);

    printf("%f balance after withrawal\n", balance);

    return 0;
}
