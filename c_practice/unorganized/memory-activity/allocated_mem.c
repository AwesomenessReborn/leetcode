#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Define the array size
    int array_size = 3;

    // Allocate memory for the array of char pointers
    char **test_b = (char **)malloc(array_size * sizeof(char *));
    if (test_b == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Define the strings to be stored
    const char *strings[] = {"dog", "racecar", "car"};

    // Allocate memory for each string and copy the strings into the allocated memory
    for (int i = 0; i < array_size; i++) {
        test_b[i] = (char *)malloc((strlen(strings[i]) + 1) * sizeof(char));
        if (test_b[i] == NULL) {
            fprintf(stderr, "Memory allocation failed for string %d\n", i);
            // Free previously allocated memory before exiting
            for (int j = 0; j < i; j++) {
                free(test_b[j]);
            }
            free(test_b);
            return 1;
        }
        strcpy(test_b[i], strings[i]);
    }

    // Use the array (e.g., print the strings)
    for (int i = 0; i < array_size; i++) {
        printf("%s\n", test_b[i]);
    }

    // Free the allocated memory
    for (int i = 0; i < array_size; i++) {
        free(test_b[i]);
    }
    free(test_b);

    return 0;
}
