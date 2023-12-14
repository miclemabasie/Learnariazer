#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{

    struct node
    {
        int data;
        struct node *link;
    };

    struct node A,
        B, C, D;
    struct node *head = NULL;

    // bottom -> top creation
    D.data = 400;
    D.link = NULL;

    C.data = 300;
    C.link = &D;

    B.data = 200;
    B.link = &C;

    A.data = 100;
    A.link = &B;
    head = &A;

    // set the addres of the first node to point to the head

    // struct node node1 = *(node1.link);
    // printf("Data: %p \n", (node1.link));
    // printf("Data: %d \n", (node2.data));
    // printf("Data: %d \n", node1.data);
    int x = 0;
    struct node node1 = *head;
    while (node1.link != NULL)
    {
        // get the next element on the list
        // struct node node1 = *(node1.link);
        x++;
        cout << " |";
        cout << node1.data << "->";
        node1 = *(node1.link);
    }
    cout << "|" << node1.data << "->";

    return 0;
}
