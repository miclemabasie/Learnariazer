#include <stdio.h>



int main(void) {

    printf("===============Find X power N===============\n");

    float x;
    int n;

    // Get values from user
    printf("Enter X: ");
    scanf("%f", &x);
    printf("Enter N: ");
    scanf("%d", &n);

    float res = 1;

    if(n < 0) {
        printf("Result is: 1/%f^%d", x, n * -1);
    }else if(n == 0){
        printf("Result is: 0.");
    }else{
        for (int i = 0; i < n; i++)
        {
            res *= x;
        }
        printf("X power N is: %f\n", res);

    }



    return 0;
}