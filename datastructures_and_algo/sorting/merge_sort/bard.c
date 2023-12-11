#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
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

void

mergeSort(int arr[], int low, int high)

{
    if (low < high)
    {
        // [1, 2, 3 ,4 ,5, 6]
        // Find the middle point

        int mid = low + (high - low) / 2;

        // Sort first and second halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main()
{
    // Test data
    int arr[] = {6, 5, 3, 1, 8, 7, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Un-Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array
    mergeSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}