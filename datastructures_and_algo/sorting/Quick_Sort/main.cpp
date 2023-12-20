#include <iostream>
void swap(int arr[], int x, int y);
void quick_sort(int arr[], int start, int end);
int partition(int arr[], int start, int end);

using namespace std;

int main(void)
{
    int size = 8;
    int list[8] = {7, 2, 1, 6, 8, 5, 3, 4};
    printf("List before sorting!");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", list[i]);
    }

    quick_sort(list, 0, size - 1);

    cout << "List after sorting!" << endl;
    for (int i = 0; i < size; i++)
    {
        // printf("%d ", list[i]);
        cout << list[i] << " ";
    }

    return 0;
}

void quick_sort(int arr[], int start, int end)
{
    if (start < end)
    {
        // partition and return the index of the pivot
        int p1 = partition(arr, start, end);
        cout << "This is point " << p1 << endl;

        quick_sort(arr, start, p1 - 1);
        quick_sort(arr, p1 + 1, end);
    }
}

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int p_index = start;
    int i = start;
    for (i; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr, i, p_index);
            p_index++;
        }
    }
    swap(arr, i, p_index);

    return p_index;
}

void swap(int arr[], int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
}