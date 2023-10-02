#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100 // Maximum number of words in the string
#define MAX_WORD_LENGTH 50 // Maximum length of each word

char** fig_splitz(const char* entry, int* tally) 
{
    char** lex = (char**)malloc(MAX_WORDS * sizeof(char*));
    if (lex == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    const char* present = entry;
    *tally = 0;

    while (*present != '\0' && *tally < MAX_WORDS)
{
        // Skip leading spaces
        while (*present == ' ') 
{
            present++;
        }

        if (*present == '\0') 
{
            break; // No more words
        }

        const char* wordbeg = present;
        // Find the end of the current word
        while (*present != ' ' && *present != '\0') {
            present++;
        }

        size_t wordsize = present - wordbeg;
        lex[*tally] = (char*)malloc((wordsize + 1) * sizeof(char));
        if (lex[*tally] == NULL) {
            perror("Memory allocation error");
            // Clean up previously allocated memory
            for (int i = 0; i < *tally; i++) {
                free(lex[i]);
            }
            free(lex);
            exit(EXIT_FAILURE);
        }

        strncpy(lex[*tally], wordbeg, wordsize);
        lex[*tally][wordsize] = '\0';
        (*tally)++;
    }

    return lex;
}
