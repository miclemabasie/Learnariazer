#include <stdio.h>
#include <stdbool.h>
/*
    enqueue() -> Add item to the queue
    dequeue() -> Remove an item from the queue
    peek() -> Gets the element at teh front of the queue
    isfull() -> check if the queue is full
    isempty() -> Checks if the queue is empty
*/

void enqueue(int data);
int peek();
void dequeue();
bool is_full();
bool is_empty();
void show_queue();
int front = -1;
int max = 10;
int rear = -1;
int queue[10];

int main()
{
    show_queue();

    enqueue(34);
    enqueue(3);
    enqueue(8);
    enqueue(45);
    enqueue(778);
    enqueue(123);
    enqueue(89);
    enqueue(34);
    enqueue(23);
    enqueue(81);
    show_queue();
    dequeue();
    dequeue();
    dequeue();
    enqueue(100);
    show_queue();

    printf("This is the peek value: %d\n", peek());

    return 0;
}

int peek()
{

    if (!is_empty())
    {
        printf("From peek: front is: %d\n", front);
        return queue[front];
    }
    printf("Array is empty!");
    return -1;
}

void dequeue()
{

    // includes
    // check if max

    if (!is_empty())
    {
        // shit array one step infront

        for (int i = 0; i < rear; i++)
        {
            queue[i] = queue[i + 1];
        }
        rear--;
    }
}

void enqueue(int data)
{
    // printf("this is max: %d and this is rear: %d", max, rear);
    if (!is_full())
    {
        rear++;
        if (front == -1)
        {
            front++;
        }
        queue[rear] = data;
    }
    else
    {
        printf("!Enqueue => Queue is full.\n");
    }
}

bool is_full()
{
    if (rear >= max - 1)
    {
        return true;
    }
    return false;
}

bool is_empty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

void show_queue()
{
    if (!is_empty())
    {
        // loop until rear
        printf("|=>");
        for (int i = rear; i >= 0; i--)
        {
            printf("%d  ", queue[i]);
        }
        printf("\n\n");
    }
    else
    {
        printf("Queue is empty at the moment.\n");
    }
    printf("=========End of show=============\n\n");
}