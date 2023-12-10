#include <stdio.h>

int main(void)
{
    int arr[3] = {1, 2, 3};
    *(arr + 2) = 43;
    printf("%d", *(arr + 2));
    return 0;
}