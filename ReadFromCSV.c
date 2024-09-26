#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 10000

// Function to read words from CSV file
void readWordsFromCSV(const char *filename, char *words[MAX_WORDS]) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[1024];
    int wordCount = 0;

    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, ",");
        while (token != NULL) {
            // Allocate memory for the word
            words[wordCount] = malloc(MAX_WORD_LENGTH);

            // Copy the word into the array
            strncpy(words[wordCount], token, MAX_WORD_LENGTH - 1);

            // Remove newline character if present
            if (words[wordCount][strlen(words[wordCount]) - 1] == '\n') {
                words[wordCount][strlen(words[wordCount]) - 1] = '\0';
            }

            // Move to the next token
            token = strtok(NULL, ",");

            // Increment the word count
            wordCount++;
        }
    }

    // Close the file
    fclose(file);
}

// Function to print words from the array
void printWords(char *words[MAX_WORDS]) {
    for (int i = 0; words[i] != NULL; i++) {
        printf("%s\n", words[i]);
        free(words[i]); // Free allocated memory for each word
    }
}

int main() {
    char *positiveWords[MAX_WORDS];
    char *negativeWords[MAX_WORDS];
    char *actionWords[MAX_WORDS];
    char *positiveVerbs[MAX_WORDS];
    char *negativeVerbs[MAX_WORDS];

    // Read words from CSV file
    readWordsFromCSV("Positive_words.csv", positiveWords);
    readWordsFromCSV("Negative_words.csv", negativeWords);


    // Print the words
    printf("Positive Words:\n");
    printWords(positiveWords);

    printf("\nNegative Words:\n");
    printWords(negativeWords);



    return 0;
}
