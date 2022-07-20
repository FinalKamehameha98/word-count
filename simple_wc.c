/**
 * Simple Word Count Utility
 * Author: Andres Rivera
 * 
 * It prints out the number of characters, words, and lines in a given file(s)
 * or from standard input.  It will also print out a total for each count if
 * it is given more than 1 file.
 */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define LINE_INDEX 0
#define WORD_INDEX 1
#define CHAR_INDEX 2

void get_count(int count[], FILE *stream);

int main(int argc, char *argv[]){
    //count[0] = line count, count[1] = word count, count[2] = char count
    int count[] = {0, 0, 0};

    switch(argc){
        case 1: // Count from standard input
            get_count(count, stdin);
            printf("%d | %d | %d\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX]);
            //print_count(count);
            // TODO: Implement code for handling stdin
            break;

        case 2: // Count from 1 file
            break;

        default: // Count from >1 file
            break;
            // TODO: Implement code for handling >1 file
    }
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
            if(!isblank(current_char)){
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
