#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1000

// Function to count occurrences of a word in the text
int countOccurrences(char *searchWord, char *text) {
    int count = 0;
    char *wordLoc = text;

    // Loop through the text to find occurrences of the word
    while ((wordLoc = strstr(wordLoc, searchWord)) != NULL) {
        // Check if the word is at the beginning or after a non-alphabetic character
        if (wordLoc == text || !isalpha(*(wordLoc - 1))) {
            count++;
        }
        wordLoc += strlen(searchWord);
    }

    return count;
}

// Function to perform sentiment analysis
int analyzeSentiment(char *text) {
    // Positive and negative words lists
    char *positiveWords[] = {
        // Positive words list
        "good", "happy", "excellent", "positive", "great", "awesome",
    "fantastic", "superb", "amazing", "did well", "wonderful", "joyful", "pleasurable",
    "satisfying", "terrific", "outstanding", "delightful", "uplifting",
    "glorious", "lovely", "magnificent", "splendid", "phenomenal", "fabulous",
    "remarkable", "grateful", "enjoyable", "thrilling", "spectacular",
    "beautiful", "vibrant", "joyous", "fantabulous", "exuberant", "ecstatic",
    "cheerful", "blissful", "euphoric", "radiant", "positive", "optimistic",
    "stellar", "heartwarming", "captivating", "exhilarating", "lively", "delicious",
    "invigorating", "inspiring", "refreshing", "empowering", "dynamic",
    "splendiferous", "festive", "serene", "buoyant", "effervescent", "triumphant", "delicious",
     "joy", "proud", "succeeded", "excelled", "achieved", "innovated", "improved", "grew",
    "thrived", "advanced", "progressed", "inspired", "motivated", "uplifted",
    "enriched", "enhanced", "celebrated", "empowered", "fostered", "accomplished",
    "fulfilled", "created", "positivized", "radiated", "prospered", "blossomed",
    "bloomed", "triumphed", "surpassed", "overcame", "shone", "contributed",
    "sparked", "ignited", "revitalized", "ascended", "exceeded", "outperformed",
    "transformed", "went upward", "amplified", "conquered", "mastered", "thrived",
    "radiated", "breathed", "vitalized", "went upswing", "optimized", "was victorious"
    };

    char *negativeWords[] = {
        // Negative words list
        "bad", "sad", "poor", "negative", "terrible", "awful",
    "horrible", "unpleasant", "disappointing", "dreadful", "miserable",
    "grim", "unfavorable", "lousy", "inferior", "subpar", "displeasing",
    "disgusting", "repulsive", "abysmal", "dismal", "deplorable", "atrocious",
    "detestable", "abhorrent", "odious", "noxious", "repugnant",
    "repellent", "revolting", "vile", "noxious", "offensive", "unpleasant",
    "distasteful", "disgustful", "heartbreaking", "gloomy", "dismaying", "desolate",
    "unfortunate", "tragic", "woeful", "melancholy", "mournful", "depressing",
    "demoralizing", "discouraging", "wearying", "exhausting", "draining",
    "disheartening", "dispiriting", "dreary", "lamentable", "forlorn", "grief-stricken", "unbearable",
    "ruined", "frustrating", "regretted", "failed", "struggled", "declined", "regressed", "stagnated", "deteriorated",
    "suffered", "declined", "worsened", "degenerated", "backslid", "slumped",
    "fell", "collapsed", "crumbled", "retreated", "floundered", "faltered",
    "depleted", "diminished", "dwindled", "shrunk", "decayed", "weakened",
    "decayed", "languished", "wilted", "atrophied", "disappointed", "frustrated",
    "defeated", "overwhelmed", "undermined", "obstructed", "hampered", "hindered",
    "confounded", "stifled", "oppressed", "discouraged", "dismayed", "disheartened",
    "sapped", "exhausted", "drained", "dejected", "regret", "demoralized", "tormented", "in pain", "got hurt", "unhappy"
    };

    int positiveCount = 0;
    int negativeCount = 0;

    // Convert the entire text to lowercase for case-insensitive comparison
    for (int i = 0; text[i]; i++) {
        text[i] = tolower(text[i]);
    }

    // Count occurrences of positive words
    for (int i = 0; i < sizeof(positiveWords) / sizeof(positiveWords[0]); i++) {
        positiveCount += countOccurrences(positiveWords[i], text);
    }

    // Count occurrences of negative words
    for (int i = 0; i < sizeof(negativeWords) / sizeof(negativeWords[0]); i++) {
        negativeCount += countOccurrences(negativeWords[i], text);
    }

    // Determine sentiment based on word counts
    if (positiveCount > negativeCount) {
        return 1; // Positive sentiment
    } else if (negativeCount > positiveCount) {
        return -1; // Negative sentiment
    } else {
        return 0; // Neutral sentiment
    }
}

// Main function
int main() {
    // Input text for sentiment analysis
    char text[MAX_INPUT_SIZE];
    printf("Enter the text for sentiment analysis: ");

    // Read user input
    if (fgets(text, sizeof(text), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    text[strcspn(text, "\n")] = '\0';


    // Check for empty input
    if (text[0] == '\0') {
        printf("Error: Please enter some text for sentiment analysis.\n");
        return 1;
    }

    // Check for input consisting only of whitespace characters
    for (int i = 0; text[i]; i++) {
        if (!isspace((unsigned char)text[i])) {
            break; // Non-whitespace character found
        } else if (text[i + 1] == '\0') {
            printf("Whitespace Error: Please enter some text for sentiment analysis.\n");
            return 1;
        }

    }

    // Perform sentiment analysis
    int sentiment = analyzeSentiment(text);

    // Display the result
    if (sentiment == 1) {
        printf("Positive sentiment\n");
    } else if (sentiment == -1) {
        printf("Negative sentiment\n");
    } else {
        printf("Neutral sentiment\n");
    }

    return 0;
}
