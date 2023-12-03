#include <stdio.h>
int main()
{
    int LA[6] = {1, 3, 5, 7, 8};
    int item = 10, k = 3, n = 6;
    int i = 0, j = n;
    printf("The original array elements are :\n");
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }
    n = n + 1;
    while (j >= k)
    {
        LA[j + 1] = LA[j];
        printf("This is j: %d", j);
        j = j - 1;
    }
    // LA[k] = item;
    // printf("The array elements after insertion :\n");
    // for (i = 0; i < n; i++)
    // {
    //     printf("LA[%d] = %d \n", i, LA[i]);
    // }

    return 0;
}

// -fno-stack-protector // Run the program with following command
/// objdump -D a.out // Disasembly

/*
The compiler, (in this case gcc) adds protection variables (called canaries) which have known values. An input string of size greater than 10 causes corruption of this variable resulting in SIGABRT to terminate the program.
j >= k)
To get some insight, you can try disabling this protection of gcc using option  -fno-stack-protector  while compiling. In that case you will get a different error, most likely a segmentation fault as you are trying to access an illegal memory location. Note that -fstack-protector should always be turned on for release builds as it is a security feature.

You can get some information about the point of overflow by running the program with a debugger. Valgrind doesn't work well with stack-related errors, but like a debugger, it may help you pin-point the location and reason for the crash.
*/