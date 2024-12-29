#include <stdio.h>



int main(void){

    int x, y;
    printf("Enter X value (1 or 0)\n");
    scanf("%d", &x);

    printf("Enter Y value (1 or 0)\n");
    scanf("%d", &y);

    if(x > 1 | x < 0 | y > 1 | y < 0) {
        printf("invalid input...");
        return 0;
    }

    printf("The XOR operation of X and Y is: %d\n", x || y);
    return 0;
}