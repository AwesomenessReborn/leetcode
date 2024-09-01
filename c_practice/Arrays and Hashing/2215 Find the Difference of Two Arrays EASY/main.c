
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct rec_entry {
    int value; 
    UT_hash_handle hh; 
}; 

void printResult(int** result, int returnSize, int* returnColumnSizes) {
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j < returnColumnSizes[i] - 1) {
                printf(",");
            }
        }
        printf("]");
        if (i < returnSize - 1) {
            printf(",");
        }
    }
    printf("\n");
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findDifference(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize, int **returnColumnSizes)
{
    // STEP 1: HASH both arrays using regular array: 
    int* hash1 = calloc(2001, sizeof(int)); 
    int* hash2 = calloc(2001, sizeof(int)); 
    for (int i = 0; i < nums1Size; i++) {
        hash1[nums1[i] + 1000] = 1; // mark 1 to indicate presense. 
    }
    for (int i = 0; i < nums2Size; i++) {
        hash2[nums2[i] + 1000] = 1; // mark 1 to indicate presense. 
    }

    int* u1 = malloc(nums1Size * sizeof(int)); 
    int u1size = 0; 
    for (int i = 0; i < nums1Size; i++) {
        if (hash1[nums1[i] + 1000] == 1 && hash2[nums1[i] + 1000] == 0) {
            u1[u1size++] = nums1[i]; 
            hash1[nums1[i] + 1000] = 2; // mark as addition complete. 
        }
    }

    int* u2 = malloc(nums2Size * sizeof(int)); 
    int u2size = 0; 
    for (int i = 0; i < nums2Size; i++) {
        if (hash2[nums2[i] + 1000] == 1 && hash1[nums2[i] + 1000] == 0) {
            u2[u2size++] = nums2[i]; 
            hash2[nums2[i] + 1000] = 2; // mark as addition complete. 
        }
    }

    int** ans = malloc(2 * sizeof(int*)); 
    *returnSize = 2; 
    *returnColumnSizes = malloc(2 * sizeof(int)); 
    (*returnColumnSizes)[0] = u1size; 
    (*returnColumnSizes)[1] = u2size; 
    ans[0] = u1; 
    ans[1] = u2; 
    free(hash1); 
    free(hash2); 

    return ans; 
}

int main()
{
    /**
     * TEST1
     * input: nums1 = [1,2,3], nums2 = [2,4,6]
     * output: [[1,3],[4,6]]
     *
     * TEST2
     * input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
     * output: [[3],[]]
     */

    // Test case 1
    int nums1_1[] = {1, 2, 3};
    int nums2_1[] = {2, 4, 6};
    int returnSize1;
    int* returnColumnSizes1;
    int** result1 = findDifference(nums1_1, 3, nums2_1, 3, &returnSize1, &returnColumnSizes1);
    printf("Test 1 Result: ");
    printResult(result1, returnSize1, returnColumnSizes1);
    // Free memory
    free(result1[0]);
    free(result1[1]);
    free(result1);
    free(returnColumnSizes1);

    // Test case 2
    int nums1_2[] = {1, 2, 3, 3};
    int nums2_2[] = {1, 1, 2, 2};
    int returnSize2;
    int* returnColumnSizes2;
    int** result2 = findDifference(nums1_2, 4, nums2_2, 4, &returnSize2, &returnColumnSizes2);
    printf("Test 2 Result: ");
    printResult(result2, returnSize2, returnColumnSizes2);
    // Free memory
    free(result2[0]);
    free(result2[1]);
    free(result2);
    free(returnColumnSizes2);

    return EXIT_SUCCESS;
}


// FOLLOWING IS HASH IMPLEMENTATION FROM USAGE OF uthash.h --> unsuccessful -- minor error. 
    // // STEP 1: hash both arrays: 
    // struct rec_entry *h_table1 = NULL; 
    // for (size_t i = 0; i < nums1Size; i++)
    // {
    //     struct rec_entry *ent; 
    //     HASH_FIND_INT(h_table1, &nums1[i], ent); 
    //     if (!ent) {
    //         ent = (struct rec_entry *)malloc(sizeof *ent); 
    //         ent->value = nums1[i]; 
    //         HASH_ADD_INT(h_table1, value, ent); 
    //     }
    // }
    // struct rec_entry *h_table2 = NULL; 
    // for (size_t j = 0; j < nums2Size; j++)
    // {
    //     struct rec_entry *ent; 
    //     HASH_FIND_INT(h_table2, &nums2[j], ent); 
    //     if (!ent) {
    //         ent = (struct rec_entry *)malloc(sizeof *ent); 
    //         ent->value = nums2[j]; 
    //         HASH_ADD_INT(h_table2, value, ent); 
    //     }
    // }

    // // STEP 2: run through each array and populate the result 
    // //          for which have been found in the opposite array or not. 
    // int* u2 = malloc(nums2Size * sizeof(int)); 
    // int u2size = 0; 
    // // for (size_t i = 0; i < nums2Size; i++) {
    // //     struct rec_entry *pot; 
    // //     HASH_FIND_INT(h_table1, &nums2[i], pot); 
    // //     if (!pot) { 
    // //         u2[u2size++] = nums2[i]; 
    // //     }
    // // }
    // // ! instead using hash iteration: 
    // struct rec_entry *s; 
    // for (s = h_table2; s != NULL; s->hh.next) {
    //     struct rec_entry *pot; 
    //     HASH_FIND_INT(h_table1, &s->value, pot); 
    //     if (!pot) {
    //         u2[u2size++] = s->value; 
    //     }
    // }

    // int* u1 = malloc(nums1Size * sizeof(int)); 
    // int u1size = 0; 
    // // for (size_t j = 0; j < nums1Size; j++) {
    // //     struct rec_entry *pot; 
    // //     HASH_FIND_INT(h_table2, &nums1[j], pot); 
    // //     if (!pot) { 
    // //         u1[u1size++] = nums1[j]; 
    // //     }
    // // }
    // // ! instead using hash iteration: 
    // for (s = h_table1; s != NULL; s->hh.next) {
    //     struct rec_entry *pot; 
    //     HASH_FIND_INT(h_table2, &s->value, pot); 
    //     if (!pot) {
    //         u1[u1size++] = s->value; 
    //     }
    // }

    // int** ans = malloc(2 * sizeof(int*)); 
    // *returnSize = 2; 
    // *returnColumnSizes = malloc(2 * sizeof(int)); 
    // (*returnColumnSizes)[0] = u1size; 
    // (*returnColumnSizes)[1] = u2size; 
    // ans[0] = u1; 
    // ans[1] = u2; 
    // HASH_CLEAR(hh, h_table1); 
    // HASH_CLEAR(hh, h_table2); 

    // return ans; 