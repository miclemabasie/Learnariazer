#include <stdio.h>

void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void generate_array(int arr[], int size);
void show_array(int arr[], int size, char message[]);
void merge2(int arr[], int low, int mid, int high);

int main(void)
{
    int size = 5;
    int list[] = {23, 21, 4, 1, 42};
    // generate_array(list, size);
    show_array(list, size, "befor sorting");
    merge_sort(list, 0, size - 1);
    show_array(list, size, "after sorting");
    return 0;
}

void merge_sort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Find the mid point of the list

        int mid = left + (right - left) / 2;
        // recursively call the mergesort function with a new part of the list
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Call the merge function to merge the individual arrays
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right)
{
    // Based on the left, mid and right
    // calculate the size of the sub arrays
    // int left_size = mid - left + 1;
    // int right_size = right - mid;
    int left_size = mid - left + 1;
    int right_size = right - mid;
    show_array(arr, 5, "this is the main array");

    // initialize the arrays based on the sizes calculated above
    int left_arr[left_size];
    int right_arr[right_size];
    // int left_arr[left_size], right_arr[right_size];
    // [1, 2, 3, 4, 5, 6, 7, 8]
    // Copy the content of the arr in to the sub left and rigth arrays
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[left + i];
    }

    for (int j = 0; j < right_size; j++)
    {
        right_arr[j] = arr[mid + j + 1];
    }

    show_array(left_arr, left_size, "Left array");
    show_array(right_arr, right_size, "right array");

    // We now have a splited array [1, 2, 3,4], [5, 6, 7, 8]
    // Copy the contents of the temporal arrays into the main array in a sorted manner
    int left_index = 0;
    int right_index = 0;
    int arr_index = left;
    int i = 0, j = 0, k = left;

    while (i < left_size && j < right_size)
    {
        // Check the currently smaller value with respect to indexes of both arrays
        if (left_arr[i] <= right_arr[j])
        {
            // *(arr + arr_index) = left_arr[i];
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            // *(arr + k) = right_arr[j];
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }
    // // Merge the temporary arrays back into arr[low..high]
    // while (i < left_size && j < right_size)
    // {
    //     if (left_arr[i] <= right_arr[j])
    //     {
    //         arr[k] = left_arr[i];
    //         i++;
    //     }
    //     else
    //     {
    //         arr[k] = right_arr[j];
    //         j++;
    //     }
    //     k++;
    // }

    show_array(arr, 5, "this is the main array");

    // Copy the left over content of any in both arrays to the main array
    // while (left_index < right_size)
    // {
    //     *(arr + arr_index) = left_arr[left_index];
    //     arr_index++;
    //     left_index++;
    // }

    // while (right_index < right_size)
    // {
    //     *(arr + arr_index) = right_arr[right_index];
    //     arr_index++;
    //     right_index++;
    // }

    // Copy remaining elements of left_arr
    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right_arr
    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}

// void generate_array(int arr[], int size)
// {
//     for (int i = size, j = 0; i > 0; i--, j++)
//     {
//         arr[j] = i;
//     }
// }

void generate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void show_array(int arr[], int size, char message[])
{
    printf("%s \n", message);
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("]\n");
}

// -----------------------------------------------
void merge2(int arr[], int low, int mid, int high)
{
    // Create temporary arrays
    int left_size = mid - low + 1;
    int right_size = high - mid;
    int left_arr[left_size], right_arr[right_size];

    // Copy data to temporary arrays
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[low + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    // Merge the temporary arrays back into arr[low..high]
    int i = 0, j = 0, k = low;
    while (i < left_size && j < right_size)
    {
        if (left_arr[i] <= right_arr[j])
        {
            arr[k] = left_arr[i];
            i++;
        }
        else
        {
            arr[k] = right_arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left_arr
    while (i < left_size)
    {
        arr[k] = left_arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right_arr
    while (j < right_size)
    {
        arr[k] = right_arr[j];
        j++;
        k++;
    }
}