#include <stdio.h>
#include <string.h>

// Function to check if a substring exists within a string
int stringMatch(const char *str, const char *substr) {
    int len_str = strlen(str);
    int len_substr = strlen(substr);

    // Iterate through the string
    for (int i = 0; i <= len_str - len_substr; i++) {
        int j=0;

        // Check for substring match starting at index i
        while (j < len_substr && str[i + j] == substr[j]) {
            j++;
        }

        // If the inner loop reached its end, it means a match was found
        if (j == len_substr)
            return i;
    }

    // If no match was found, return -1
    return -1;
}

int main() {
    char str[100]; // Assuming a maximum length of 100 for the string
    char substr[100]; // Assuming a maximum length of 100 for the substring

    // Input main string
    printf("Enter the main string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0'; // Removing the newline character if present

    // Input substring
    printf("Enter the substring to search for:");
    fgets(substr, sizeof(substr), stdin);
    substr[strcspn(substr, "\n")] = '\0'; // Removing the newline character if present

    // Check for substring match
    int result = stringMatch(str, substr);
    if (result != -1) {
        printf("'%s' found at index %d in '%s'\n", substr, result, str);
    } else {
        printf("'%s' not found in '%s'\n", substr, str);
    }

    return 0;
}
