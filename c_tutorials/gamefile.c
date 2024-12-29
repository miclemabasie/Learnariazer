#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_users(int number_of_users, char **usernames[][10]);
int get_length_of_file(FILE *f);

int main(){

    printf("======== GUESS A NUMBER ==========\n");
    printf("======== TYPE -1 to quit ==========\n");

    FILE *fp;
    // fomat: secret,trials,numberofusers;
    
    int secret1;

    srand(time(NULL));
    int number_of_users = 0;
    secret1 = rand() % 50;
    // secret = 4;

    struct GameInfo
    {
        int secret;
        int guess;
        int trials;
        int number_of_users;
        int won;
        
    };

    struct GameInfo gamestate;
    gamestate.secret = secret1;
    gamestate.guess;
    gamestate.trials = 0;
    gamestate.number_of_users;
    gamestate.won = 0;
    


    int start_user_index = 0;
    int i = 1;


        // initialize gamestate object

    fp = fopen("game.txt", "r");
    if(get_length_of_file(fp) > 1)
    {
        printf("This");
        // printf("====== Loading Game State ========\n");
        struct gamefilestate;
        // FILE *fpo;

        char ch;
        char contents[5][20]; // [numberofusers,trials,secret]
        // fp = fopen("game.txt", "r");
        int i = 0;
        while(1) {
            ch = fgetc(fp);
            if(ch == EOF )
                break;
            else if(ch != ';'){
                contents[i][20] = ch;
                i++;
            }
        }

        // show the content of the file
        for (int i = 0; i < 5; i++)
        {
            if (i == 0)
                gamestate.secret = atoi(contents[i]); 
            if (i == 1)
                gamestate.guess = atoi(contents[i]); 
            if (i == 2)
                gamestate.trials = atoi(contents[i]); 
            if (i == 3)
                gamestate.number_of_users = atoi(contents[i]); 
            gamestate.won = 0;            
        }
        
        char usernames[number_of_users][10];

        for (int i = 0; i < number_of_users; i++)
        {
            sprintf(usernames[i], "User%d", i+1);

            // usernames[i][10] = username;
            printf("%s\n", usernames[i]);

        }

        char usernamesfile[number_of_users][10];

        for (int i = 0; i < number_of_users; i++)
        {
            sprintf(usernamesfile[i], "User%d", i+1);

            // usernamesfile[i][10] = username;
            printf("%s\n", usernamesfile[i]);

        }

        
        do {
            for (int i = 0; i < number_of_users; i++)
            {
                printf("%s should guess a number: (%d trials): ", usernamesfile[i], gamestate.trials + 1);
                scanf("%d", &gamestate.guess);
                if (gamestate.guess == gamestate.secret) {
                    printf("%s Won the Guess in %d trials: ", usernamesfile[i], gamestate.trials + 1);
                    gamestate.won = 1;
                    break;
                }
            }
            if(gamestate.won == 1) {
                break;
            }
            
            gamestate.trials++;
        }while(gamestate.guess != -1);

        

        fclose(fp);
            if (i == 3)
        return 0;
    }
    else {
       printf("Enter the Number of users: ");
        scanf("%d", &number_of_users);

        char usernames[number_of_users][10];

        for (int i = 0; i < number_of_users; i++)
        {
            sprintf(usernames[i], "User%d", i+1);

            // usernames[i][10] = username;
            printf("%s\n", usernames[i]);

        }

        
        do {
            for (int i = 0; i < number_of_users; i++)
            {
                printf("%s should guess a number: (%d trials): ", usernames[i], gamestate.trials + 1);
                scanf("%d", &gamestate.guess);
                if (gamestate.guess == gamestate.secret) {
                    printf("%s Won the Guess in %d trials: ", usernames[i], gamestate.trials + 1);
                    gamestate.won = 1;
                    break;
                }
            }
            if(gamestate.won == 1) {
                break;
            }
            
            gamestate.trials++;
        }while(gamestate.guess != -1);
        }
        


    
    return 0;
}

int get_length_of_file(FILE *f){
     int i;
     i=0;
     char ch;

     while( ( ch = fgetc(f) ) != EOF ) {
         printf("%c",ch);    /*This is just here to check what the file contains*/
  
         if(ch!='\0') {
             i=i+1;
         }
     }

     printf("------------------\n");
     printf("The length of the file is\n");
     printf("%d",i);  
     return i;
}