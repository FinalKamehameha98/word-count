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
#define COUNT_SIZE 3

int main(int argc, char *argv[]){
    //int count[COUNT_SIZE];
    //memset(count, 0, sizeof(count));
    switch(argc){
        case 1: // Count from standard input
            printf("Standard Input Case\n");
            //get_count(count, stdin);
            // TODO: Implement code for handling stdin
            break;

        case 2: // Count from 1 file
            printf("One File Case\n");
            //FILE *file = fopen(argv[1], "r");
            //get_count(count, file);
            // TODO: Implement code for handling 1 file
            //fclose(file);
            break;

        default: // Count from >1 file
            printf("Many Files Case\n");
            //int total[COUNT_SIZE];
            //memset(total, 0, sizeof(total));
            //for(int i = 0; i < COUNT_SIZE){
            //    get_count(

            //}
            // TODO: Implement code for handling >1 file
    }
}

/**
 * 
 * @param stream: 
 */
void get_count(int count[], FILE *stream){
    //TODO: Implement code to read file and print count
}

