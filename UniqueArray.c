#include <stdio.h>
#include <string.h>
int strmatch(char string[],char substring[]) {
    int len1 = strlen(string);
    int len2 = strlen(substring);
     for (int i = 0; i <= len1 - len2; i++) {
        int j = 0;
        while(j < len2) {
            if (string[i + j] == substring[j])
                j++;
        }
        if (j == len2) {
            return i;
        }
    }
    return -1;
}

int main() {
    char string[100];
    char substring[100];

    printf("Enter the main string: ");
    fgets(string, sizeof(string), stdin);

    printf("Enter the substring to search for: ");
    fgets(substring, sizeof(substring), stdin);

    // Removing the newline character from fgets
    string[strcspn(string, "\n")] = 0;
    substring[strcspn(substring, "\n")] = 0;


    int found = strmatch(string,substring); // Initialize to -1 to indicate not found



    if (found != -1)
        printf("'%s' found at index %d in '%s'\n", substring, found, string);
    else
        printf("'%s' not found in '%s'\n", substring, string);

    return 0;
}
