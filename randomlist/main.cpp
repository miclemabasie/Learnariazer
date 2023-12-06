#include <iostream>

using namespace std;

int main()
{
    string names[] = {"name1", "namem", "name3", "miclem", "abasie", "this"};
    int N = 3;

    string x;

    for (int i = 0; i < 3; i++)
    {
        int index = rand() % N;
        cout << index << "  " << endl;
        cout << names[index] << endl;
    }

    return 0;
}