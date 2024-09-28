// https://leetcode.com/problems/two-sum/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "uthash.h"

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

struct rec_entry {
    int value; // key
    int index; 
    UT_hash_handle hh; 
}; 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = malloc(2*sizeof(int)); 
    struct rec_entry *h_table = NULL; 

    for (size_t i = 0; i < numsSize; i++) {
        struct rec_entry *pot;
        HASH_FIND_INT(h_table, &nums[i], pot);
        if (pot == NULL) {
            pot = (struct rec_entry *)malloc(sizeof(*pot));
            pot->value = nums[i];
            pot->index = i;
            HASH_ADD_INT(h_table, value, pot);
        }
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        struct rec_entry *pot;
        HASH_FIND_INT(h_table, &complement, pot);
        if (pot && pot->index != i) {
            ans[0] = pot->index;
            ans[1] = i;
            *returnSize = 2;
            HASH_CLEAR(hh, h_table);              
            return ans;
        }
    }

    *returnSize = 0;
    free(ans);
    HASH_CLEAR(hh, h_table);  // Clear the hash table
    return NULL;
}

// TODO write tests. 
int main(int argc, char const *argv[])
{

    return 0;
}
