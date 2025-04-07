#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct rec_entry {
    int value; 
    UT_hash_handle hh; 
}; 

/**
 * Implements uses hashmap. 
*/
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (numsSize == 0 || k <= 0) return false; 

    struct rec_entry *h_table = NULL; 

    if (k >= numsSize) {
        k = numsSize - 1; 
    }

    printf("------- STAGE 1 -------- \n"); 

    for (int i = 0; i <= k; i++) {
        struct rec_entry *pot; 
        printf("populating h_table. index: %d \n", i); 

        HASH_FIND_INT(h_table, &nums[i], pot); 
        if (pot != NULL) {
            // Free all entries before returning
            struct rec_entry *current, *tmp;
            HASH_ITER(hh, h_table, current, tmp) {
                HASH_DEL(h_table, current);
                free(current);
            }
            return true; 
        }
        pot = (struct rec_entry *)malloc(sizeof *pot);
        pot->value = nums[i]; 
        printf("ADDING INT: to h_table value: %d \n", pot->value); 
        HASH_ADD_INT(h_table, value, pot); 
    }
    printf("------- STAGE 2 -------- \n"); 
    int rem = 0; 
    int add = k + 1; 

    while (add < numsSize) {
        printf("begin with rem=%d and add=%d: \n", rem, add); 
        printf("----------------------------- \n"); 
        // TODO perform shift first. 
        struct rec_entry *prev; 

        HASH_FIND_INT(h_table, &nums[rem], prev); 
        // NOTE you actually don't need to remove each prev k value, if a common is found 
        // --> simply update the index value in the hashmap, and update the hash to include address. 

        // then if condition, instead just check if (i-j >= [next->index])
        if (prev != NULL) {
            // remove prev value from h_table. TODO need to find value instead of this
            printf("removing [index %d value %d] from h_table \n", rem, prev->value); 
            HASH_DEL(h_table, prev); 
            free(prev); 
        }

        struct rec_entry *next; 
        // add new but check if already in h_table. 
        printf("trying to add [index %d value %d] to HASH. \n", add, nums[add]); 
        HASH_FIND_INT(h_table, &nums[add], next); 
        if (next != NULL) {
            printf("found the target, [index=%d val=%d] \n", add, next->value); 
            struct rec_entry *current, *tmp;
            HASH_ITER(hh, h_table, current, tmp) {
                HASH_DEL(h_table, current);
                free(current);
            }
            return true; 
        }
        next = (struct rec_entry *)malloc(sizeof *next); 
        next->value = nums[add]; 
        HASH_ADD_INT(h_table, value, next); 

        rem++; 
        add++; 
    }

    // Free all remaining entries before returning
    struct rec_entry *current, *tmp;
    HASH_ITER(hh, h_table, current, tmp) {
        HASH_DEL(h_table, current);
        free(current);
    }

    return false; 
}

// int main()
{
    int num1[4] = {1,2,3,1};
    int num2[4] = {1,0,1,1};
    int num3[6] = {1,2,3,1,2,3};
    int num4[1] = {1}; 
    int k1 = 3; 
    int k2 = 1; 
    int k3 = 2; 
    int k4 = 1; 

    printf("test1: %s \n", containsNearbyDuplicate(num1, 4, k1) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 
    printf("\n"); 
    printf("test2: %s\n", containsNearbyDuplicate(num2, 4, k2) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 
    printf("\n"); 
    printf("test3: %s\n", containsNearbyDuplicate(num3, 6, k3) ? "true" : "false"); 
    printf("expected false\n"); 
    printf("\n"); 
    printf("\n"); 
    printf("test4: %s\n", containsNearbyDuplicate(num4, 1, k4) ? "true" : "false"); 
    printf("expected false\n"); 

    return EXIT_SUCCESS;
}





// ! inefficient solution. 
// bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = i; j <= i+k && j < numsSize; j++) {
//             if (i != j && nums[i] == nums[j]) { return true; } 
//         }
//     }
//     return false; 
// }
