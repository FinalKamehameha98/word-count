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
void print_count(int count[], const char *filename);

int main(int argc, char *argv[]){
    // count[0]=line count, count[1]=word count, count[2]=char count
    int count[] = {0, 0, 0};

    if(argc == 1){ // Get count from standard input
        get_count(count, stdin);
        print_count(count, "stdin");
    }
    else{ // Get count from >=1 file
        FILE *file;
        int total[] = {0, 0, 0}; //total[0]=line total, total[1]=word total, total[2]=char total
        
        for(int i = 1; i < argc; i++){ // Count every file on the command line
            if((file = fopen(argv[i], "r")) == NULL){
                perror("Failed to open file");
                exit(1);
            }
            get_count(count, file);
            print_count(count, argv[i]);
            if(fclose(file) == EOF){
                perror("Failed to close file stream");
                exit(1);
            }
            total[LINE_INDEX] += count[LINE_INDEX];
            total[WORD_INDEX] += count[WORD_INDEX];
            total[CHAR_INDEX] += count[CHAR_INDEX];
            memset(count, 0, sizeof(count));
        }
        if(argc > 2){ // Only print total for >1 file
            print_count(total, "Total");
        }
    }
    return 0;
}

/**
 * Counts the number of lines, words, and characters from a given data stream
 *
 * @param count Array counter to hold line, word, and character counts
 * @param stream: Data stream representing a file or standard input
 */
void get_count(int count[], FILE *stream){
    int current_char = -1;
    bool in_word = false;

    // Read every character from file/stdin until EOF
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

/**
 * Prints out the counts for a given file (or stdin) in a table-like format
 *
 * @param count Array counter that holds line, word, and character counts
 * @param filename Name of the file that was counted
 */
void print_count(int count[], const char *filename){
    printf("%-10d | %-10d | %-10d | %-10s\n", count[LINE_INDEX], count[WORD_INDEX], count[CHAR_INDEX], filename);
}

