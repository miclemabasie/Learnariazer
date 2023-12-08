#include <stdio.h>
// implementation of selection sort algorithm in C
void show_array(int arr[]);
void generate_array(int arr[]);
void selection_sort(int arr[]);
void selection_sort_swap(int arr[]);
void swap(int arr[], int x, int y);
void selection_sort_swap(int arr[]);

int size = 50;

int main(void)
{
    int list[size];
    generate_array(list);
    show_array(list);

    // selection_sort(list);
    selection_sort_swap(list);

    show_array(list);
    return 0;
}

void selection_sort(int arr[])
{
    // selection sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                // Create a temp var to swap
                int temp = arr[i];
                arr[i] = arr[j];
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

void selection_sort_swap(int arr[])
{
    // selection sort
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[i])
            {
                swap(arr, i, j);
            }
        }
    }
}