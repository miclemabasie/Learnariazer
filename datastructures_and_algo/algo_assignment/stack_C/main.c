#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void show_array(int arr[], int size);
bool is_empty();
bool is_full();
int pop();
void push(int data);
int peek();

int max_size = 10;
int arr_stack[10];
int top = -1;

int main()
{

    // for (int i = 0; i < maxsize; i++){
    //   *(arr_stack +i) = i;
    //}
    push(45);
    push(4);
    push(55);
    push(978);
    push(76);
    push(76);
    push(12);
    push(445);
    push(67);
    push(17);

    printf("From pop %d \n", pop());
    printf("From peek %d \n", peek());
    printf("From is full %d \n", is_full());
    printf("From is empty %d \n", is_empty());
    show_array(arr_stack, top);

    return 0;
}

bool is_empty()
{
    if (top == -1)
        return true;
    return false;
}

bool is_full()
{
    if (top == max_size - 1)
        return true;
    return false;
}

int pop()
{
    if (!is_empty())
    {
        top--;
        return arr_stack[top + 1];
    }
    else
    {
        printf("POP -> Can't remove element, The stack is empty\n");
    }
}

void push(int data)
{
    if (!is_full())
    {
        top++;
        arr_stack[top] = data;
    }
}

int peek()
{
    if (!is_empty())
    {
        return arr_stack[top];
    }
    else
    {
        printf("The stack is empty");
    }
}

void show_array(int arr[], int size)
{
    if (size != -1)
    {
        printf("|=====|\n");
        for (int i = size; i >= 0; i--)
        {
            printf("| %d \n", arr[i]);
        }
        printf("=====\n");
    }
    else
    {
        printf("No elements on the stack!.");
    }
}