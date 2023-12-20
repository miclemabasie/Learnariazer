#include <stdio.h>

void generate_array(int arr[]);
void show_array(int arr[]);
void insertion_sort(int arr[]);

int size = 10;

int main(void)
{
    int list[size];
    generate_array(list);
    show_array(list);
    insertion_sort(list);
    show_array(list);
    return 0;
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

void insertion_sort(int arr[])
{
    for (int i = 1; i < size; i++)
    {
        int current = arr[i];
        int j = i - 1;
        // loop through the other part of the list -> (sorted part of the list)
        // until we meet a number greater than current
        // Less than (incase of ascending order)
        while (j >= 0 && current < arr[j])
        {
            // printf("[ ");
            // for (int i = 0; i < size; i++)
            // {
            //     printf("%d ", arr[i]);
            // }
            // printf("]\n");
            arr[j + 1] = arr[j];
            j--;
        }
        // Fit the number into the last posion j + 1
        arr[j + 1] = current;
    }
}

/*

Algorithm
The steps to implement the insertion sort algorithm are described below:

1. We assume that the array is empty and on inserting one element into it will not affect the sorting order of the array. Thus, the first element is already sorted.

2. We run a loop from the second element to the last element in the array. In each iteration, the current element is compared with the previous elements, and its correct position is searched.

3. If the current element is greater than or equal to the previous element then we simply move toward the next iteration. If the current element is smaller than previous elements all the elements greater than the current are shifted one position to the right and the current element is placed at its correct position.

4. Step 3 is repeated for each element in the array.

*/
