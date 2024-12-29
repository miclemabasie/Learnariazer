#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main(){

    printf("======== GUESS A NUMBER ==========\n");
    printf("======== TYPE -1 to quit ==========\n");

    
    int secret;

    srand(time(NULL));

    secret = rand() % 100;

    int guess;
    int number_of_guesses = 0;
    do {
        printf("Enter a guess (trail: %d): ", number_of_guesses + 1);
        scanf("%d", &guess);
        number_of_guesses++;
        
        if(guess == secret) {
            printf("You won in %d trails. \n", number_of_guesses);
            break;
        }
        else if(guess < secret) {
            printf("Guess is low\n");
        }
        else if(guess > secret) {
            printf("Guess is high\n");
        }

    }while(guess != 0);
    return 0;
}