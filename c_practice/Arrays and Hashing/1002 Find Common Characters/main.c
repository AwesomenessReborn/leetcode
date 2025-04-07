
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** commonChars(char ** words, int wordsSize, int* returnSize){
    // cycle though all words: 
    // hash frequency
    // at the end, try to see which character has the frequency of wordsSize 
        // ! need to only add each letter once per word. 
        // that should give which characters should be in commonChars()

    int* t_hash = (int*)calloc(26, sizeof(int)); 
    int* c_hash; 

    for (int i = 0; i < 26; i++) {
        t_hash[i] = 99999999; 
    }

    for (int i = 0; i < wordsSize; i++) {
        c_hash = (int*)calloc(26, sizeof(int)); 
        char *let = words[i];   // ptr to each letter
        while (*let != '\0') {
            // printf("letter %d found, incrememting... \n", (int)(*let - 'a'));
            c_hash[*let - 'a']++; 
            let++; 
        }
        for (int j = 0; j < 26; j++) {
            t_hash[j] = t_hash[j] < c_hash[j] ? t_hash[j] : c_hash[j]; 
        }
        free(c_hash); 
    }
    // debug: 
    for (int i = 0; i < 26; i++) {
        printf("letter %c was found %d times \n", (char)(i+97), t_hash[i]); 
    }

    *returnSize = 0; 
    for (int i = 0; i < 26; i++) {
        (*returnSize)+=t_hash[i]; 
    }
    char ** res = (char**)malloc(*returnSize * sizeof(char*)); 

    int t = 0; 
    for (int i = 0; i < 26; i++) {
        if (t_hash[i] < 99999999 && t_hash[i] > 0) {
            for (int j = 0; j < t_hash[i]; j++) {
                res[t] = (char*)malloc(2 * sizeof(char)); // Allocate space for character and null terminator
                res[t][0] = 'a' + i; 
                res[t][1] = '\0';
                t++; 
            }
        }
    }
    free(t_hash); 
    return res; 
}

void printCStringArray(char **array, int size) {
    printf("["); 
    for (int i = 0; i < size; i++) {
        printf("%s", array[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]"); 
    printf("\n");
}

int main() {
    // Define the input words
    char *word1[] = {"bella", "label", "roller"};
    char *word2[] = {"cool", "lock", "cook"};

    // Calculate the sizes of the input arrays
    int s1 = sizeof(word1) / sizeof(word1[0]);
    int s2 = sizeof(word2) / sizeof(word2[0]);

    // Print the input arrays
    printCStringArray(word1, s1);
    printCStringArray(word2, s2);

    // Declare return size variables
    int resSize1, resSize2;

    // Get the common characters
    char **res1 = commonChars(word1, s1, &resSize1);
    printf("------------------------------------------------------------ \n"); 
    char **res2 = commonChars(word2, s2, &resSize2);

    // Print the result arrays
    printCStringArray(res1, resSize1);
    printCStringArray(res2, resSize2);

    // Free the allocated memory if commonChars allocates memory
    // Assuming commonChars allocates memory dynamically, free it after use
    for (int i = 0; i < resSize1; i++) free(res1[i]);
    for (int i = 0; i < resSize2; i++) free(res2[i]);
    free(res1);
    free(res2);

    return 0;
}