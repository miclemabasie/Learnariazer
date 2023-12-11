#include <stdio.h>

void merge_sort(int arr[], int low, int high, int aux_list[]);
void merge(int arr[], int left, int mid, int right, int list[]);
int size = 10;

// void merge_sort(int arr[], int left, int right, int aux_list[])
// {
//     int l = right - left;
//     if (l > 2)
//     {
//         // find the midpoint of the array
//         printf("This is the left %d and this is the right %d \n ", left, right);
//         int midIndex = (int)l / 2;
//         printf("This is the midindex %d and this is l %d\n", midIndex, l);

//         // // calling mergesort on the left half of the array
//         // merge_sort(arr, left, midIndex, aux_list);

//         // // Calling mergesort on the right half of the array
//         // merge_sort(arr, midIndex, right, aux_list);

//         // merge(arr, left, midIndex, right, aux_list);
//     }
// }

void merge_sort(int arr[], int low, int high, int aux_list[])

{
    if (low < high)
    {
        // Find the middle point

        int mid = low + (high - low) / 2;

        // Sort first and second halves
        merge_sort(arr, low, mid, aux_list);
        merge_sort(arr, mid + 1, high, aux_list);

        // Merge the sorted halves
        merge(arr, low, mid, high, aux_list);
    }
}

void merge(int arr[], int left, int mid, int right, int list[])
{
    // construct two new arrays based on the left, mid and right provided
    // Calculate array sizes
    int left_size = mid - left + 1;
    int right_size = right - mid;

    // initialize arrays with respective sizes
    int left_arr[left_size];
    int right_arr[right_size];

    // constructing of arrays using forloops
    // int i, j, k;
    // for (i = 0; i < left_size; i++)
    // {
    //     left_arr[i] = arr[i];
    // }
    // for (j = mid; j < right_size; j++)
    // {
    //     right_arr[j] = arr[j];
    // }

    // Copy data to temporary arrays
    for (int i = 0; i < left_size; i++)
    {
        left_arr[i] = arr[left + i];
    }
    for (int i = 0; i < right_size; i++)
    {
        right_arr[i] = arr[mid + 1 + i];
    }

    printf("Printing right half array\n [");
    for (int x = 0; x < right_size; x++)
    {
        printf("%d  ", right_arr[x]);
    }
    printf("\n");

    printf("Printing left half array\n [");
    for (int y = 0; y < left_size; y++)
    {
        printf("%d  ", left_arr[y]);
    }
    printf("\n");

    // initialize indexes for the different arrays
    int left_index = 0;
    int right_index = 0;
    int result_arr_index = 0;
    while (left_index < left_size && right_index < right_size)
    {
        if (left_arr[left_index] < right_arr[right_index])
        {
            *(list + result_arr_index) = left_arr[left_index];
            result_arr_index++;
            left_index++;
        }
        else
        {
            *(list + result_arr_index) = right_arr[right_index];
            result_arr_index++;
            right_index++;
        }
    }

    // Fill up the remaining elements on the either sides of the the
    // right and left list, just in case;
    while (left_index < left_size)
    {
        *(list + result_arr_index) = left_arr[left_index];
        result_arr_index++;
        left_index++;
    }
    while (right_index < right_size)
    {
        *(list + result_arr_index) = right_arr[right_index];
        result_arr_index++;
        right_index++;
    }
}

void generate_list(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
    }
}

void show_list(int arr[], int size)
{
    printf("[ ");
    for (int j = 0; j < size; j++)
    {
        printf("%d  ", arr[j]);
    }
    printf("]\n");
}

int main(void)
{
    int aux_list[5];
    int list[5] = {34, 23, 5, 23};
    // generate_list(list, 5);
    show_list(list, 5);
    merge_sort(list, 0, 5 - 1, aux_list);
    show_list(aux_list, 5);
    return 0;
}
