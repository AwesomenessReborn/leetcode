#include <stdio.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
    *returnSize = candiesSize; 
    int max = candies[0]; 
    for (int i = 1; i < candiesSize; i++) {
        if (candies[i] > max) { max = candies[i]; }
    }

    bool* res = (bool*)malloc(candiesSize * sizeof(bool)); 
    for (int i = 0; i < *returnSize; i++) {
        res[i] = (candies[i]+extraCandies >= max) ? true : false; 
    }
    return res; 
}

// Main function to run the test
int main() {
    int candies1[] = {2, 3, 5, 1, 3};
    int extraCandies1 = 3;
    bool expected1[] = {true, true, true, false, true};

    int candies2[] = {4, 2, 1, 1, 2};
    int extraCandies2 = 1;
    bool expected2[] = {true, false, false, false, false};

    int candies3[] = {12, 1, 12};
    int extraCandies3 = 10;
    bool expected3[] = {true, false, true};

    struct {
        int* candies;
        int candiesSize;
        int extraCandies;
        bool* expected;
        int expectedSize;
    } testCases[] = {
        {candies1, sizeof(candies1)/sizeof(candies1[0]), extraCandies1, expected1, sizeof(expected1)/sizeof(expected1[0])},
        {candies2, sizeof(candies2)/sizeof(candies2[0]), extraCandies2, expected2, sizeof(expected2)/sizeof(expected2[0])},
        {candies3, sizeof(candies3)/sizeof(candies3[0]), extraCandies3, expected3, sizeof(expected3)/sizeof(expected3[0])}
    };

    int numberOfTestCases = sizeof(testCases) / sizeof(testCases[0]);
    int returnSize; 

    // Run the test cases
    for (int i = 0; i < numberOfTestCases; i++) {
        bool* result = kidsWithCandies(testCases[i].candies, testCases[i].candiesSize, testCases[i].extraCandies, &returnSize);
        
        printf("Test case %d: \n", i + 1);
        bool pass = true;
        if (returnSize != testCases[i].expectedSize) {
            pass = false;
        } else {
            for (int j = 0; j < returnSize; j++) {
                if (result[j] != testCases[i].expected[j]) {
                    pass = false;
                    break;
                }
            }
        }
        
        if (pass) {
            printf("PASSED\n");
        } else {
            printf("FAILED\n");
        }

        // Free the allocated memory for the result
        free(result);
    }

    return 0;
}