#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_users(int number_of_users, char **usernames[][10]);

int main(){

    printf("======== GUESS A NUMBER ==========\n");
    printf("======== TYPE -1 to quit ==========\n");

    
    int secret;

    srand(time(NULL));
    int number_of_users = 0;

    printf("Enter the Number of users: ");
    scanf("%d", &number_of_users);

    char usernames[number_of_users][10];

   for (int i = 0; i < number_of_users; i++)
    {
        sprintf(usernames[i], "User%d", i+1);

        // usernames[i][10] = username;
        printf("%s\n", usernames[i]);

    }

    secret = rand() % 50;
    // secret = 4;

    int guess;
    int trials = 0;
    int userindex;
    int won = 0;

    int start_user_index = 0;
    int i = 1;
    
    do {
        for (int i = 0; i < number_of_users; i++)
        {
            printf("%s should guess a number: (%d trials): ", usernames[i], trials + 1);
            scanf("%d", &guess);
            if (guess == secret) {
                printf("%s Won the Guess in %d trials: ", usernames[i], trials + 1);
                won = 1;
                break;
            }
        }
        if(won == 1) {
            break;
        }
        
        trials++;
    }while(guess != -1);
    return 0;
}
