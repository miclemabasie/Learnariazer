#include <stdio.h>
// implementation of bubble sort algorithm in C
void show_array(int arr[]);
void generate_array(int arr[]);
void bubble_sort(int arr[]);
void bubble_sort_swap(int arr[]); // Using function to perform swap
void swap(int arr[], int x, int y);
void bubble_sort_swap_pointer(int arr[]);

int size = 50;

int main(void)
{
    int list[size];
    generate_array(list);
    show_array(list);

    // bubble_sort(list);
    // bubble_sort_swap(list);
    bubble_sort_swap_pointer(list);

    show_array(list);
    return 0;
}

void bubble_sort(int arr[])
{
    // bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Create a temp var to swap
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void generate_array(int arr[])
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void show_array(int arr[])
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("] \n");
}

// Insertion sort using swap function
void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}

void bubble_sort_swap(int arr[])
{
    // bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Create a temp var to swap
                swap(arr, j, j + 1);
            }
        }
    }
}

void bubble_sort_swap_pointer(int arr[])
{
    // bubble sort
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Create a temp var to swap
                int temp = *(arr + j + 1);
                *(arr + j + 1) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}