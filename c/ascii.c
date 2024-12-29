#include <stdio.h>                                                                                                                                                                                                                    


int main(void) {
    // char val = '';
    // printf("===== ASCII ======");
    // printf("=================");

    for (int i = 0; i < 255; i++)
    {
              
        // if ((char)i == val) {
        //     printf("Position of '%c' in ASCII table: %d\n", val, i);
        //     break; // Exit the loop once the character is found
        // }
        printf("%d | %c \n", i, i);
    }

    return 0;
}