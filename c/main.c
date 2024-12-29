#include <stdio.h>

int main(void)
{

    int x;
    char str[100];

    printf("enter a number \n");

    scanf("%d", &x);

    sprintf(str, "%d", x);

    printf("%s", str);

    // get lenght of string
    int len;
    int index = 0;
    while (str[index] != '\0')
    {
        printf("%c \n", str[index]);
        len++;
        index++;
    }

    // for (int i = 0; i < len; i++)
    // {
    //     /* code */
    // }

    printf("The length of the string is: %d", len);

    return 0;
}