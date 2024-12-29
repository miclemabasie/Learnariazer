#include <stdio.h>


int main(void) {

    // FILE *fp;

    // char file_content[] = "This is the file content";

    // fp = fopen("example.txt", "w");
    
    // if(fp == NULL){
    //     printf("Can't open file.");
    //     return 1;
    // }

    // fprintf(fp, "%s\n", file_content);

    // fclose(fp);

    // Opening and reading from the file

    FILE *fpo;

    char ch;

    fpo = fopen("game.txt", "r");

    while(1) {
        ch = fgetc(fpo);
        if(ch == EOF)
            break;
        printf("%c", ch);
    }

    fclose(fpo);
    return 0;
}