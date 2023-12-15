#include <stdio.h>
#include <stdlib.h>

// function definitions
void Insert(int data);
void Print();
// Create a struct to represent the Node object

struct Node
{
    int data;
    struct Node *next;
};

// Create a node pointer, Pointing to the first node on the list
struct Node *head; // should be global

int main()
{
    head = NULL; // empty list
    printf("How many elements do you wish to insert?\n");

    int n, i, x;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the number \n");
        scanf("%d", &x);
        Insert(x);
        Print();
    }
    return 0;
}

void Insert(int data)
{
    /* Insert element at the beginning of the linkedlist */

    // Dynamically allocate memory for the new struct
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    // temp->next = NULL; // if linkedlist is empty
    temp->next = head; // covers all sceniarios
    // Reset the head to point to temp
    head = temp;
}

void Print()
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("Your list is empty!.\n");
    }
    else
    {
        printf("List is: ");
        while (temp != NULL)
        {
            printf(" %d|->", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}