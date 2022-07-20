/**
 * Simple Word Count Utility
 * Author: Andres Rivera
 * 
 * It prints out the number of characters, words, and lines in a given file(s)
 * or from standard input.  It will also print out a total for each count if
 * it is given more than 1 file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define LINE_INDEX 0
#define WORD_INDEX 1
#define CHAR_INDEX 2

void get_count(int count[], FILE *stream);

int main(int argc, char *argv[]){
    // count[0]=line count, count[1]=word count, count[2]=char count
    int count[] = {0, 0, 0};

    if(argc == 1){ // Count from standard input
        get_count(count, stdin);
        printf("%d | %d | %d\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX]);
    }
    else{ // Count from >=1 file
        FILE *file;
        int total[] = {0, 0, 0}; //total[0]=line total, total[1]=word total, total[2]=char total
        for(int i = 1; i < argc; i++){
            if((file = fopen(argv[i], "r")) == NULL){
                perror("Failed to open file");
                exit(1);
            }
            get_count(count, file);
            printf("%d | %d | %d\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX]);
            if(fclose(file) == EOF){
                perror("Failed to close file stream");
                exit(1);
            }
            total[LINE_INDEX] += count[LINE_INDEX];
            total[WORD_INDEX] += count[WORD_INDEX];
            total[CHAR_INDEX] += count[CHAR_INDEX];
            memset(count, 0, sizeof(count));
        }
        if(argc > 2){
            printf("%d | %d | %d | %s\n", total[LINE_INDEX], total[WORD_INDEX], total[CHAR_INDEX], "TOTAL");
        }
    }
    /*
    switch(argc){
        case 1: // Count from standard input
            get_count(count, stdin);
            printf("%d | %d | %d\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX]);
            //print_count(count);
            break;

        case 2: // Count from 1 file
            if((file = fopen(argv[1], "r")) == NULL){
                perror("Failed to open file");
                exit(1);
            }
            get_count(count, file);
            printf("%d | %d | %d\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX]);
            if(fclose(file) == EOF){
                perror("Failed to close file stream");
                exit(1);
            }
            break;

        default: // Count from >1 file

            break;
            // TODO: Implement code for handling >1 file
    }
    */
    return 0;
}

/**
 * 
 *
 * @param count: 
 * @param stream:
 */
void get_count(int count[], FILE *stream){
    int current_char = -1;
    bool in_word = false;

    while((current_char = fgetc(stream)) != EOF){
        if(isspace(current_char)){
            if(current_char == '\n'){
                count[LINE_INDEX]++;
            }
            if(in_word){
                count[WORD_INDEX]++;
                in_word = false;
            }
        }
        else{
            in_word = true;
        }
        count[CHAR_INDEX]++;
    }
    if(in_word){
        count[WORD_INDEX]++;
    }
}

/*
void print_count(int count[]){
    printf("%-5s | %-5s | %-5s | %*s\n", -
}
*/
