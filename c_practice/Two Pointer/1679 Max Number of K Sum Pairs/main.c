// https://leetcode.com/problems/max-number-of-k-sum-pairs/

// for this problem use Hash object instead of array hash. 

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct freq_entry {
    int value; 
    int freq; 
    UT_hash_handle hh; 
}; 

int maxOperations(int* nums, int numsSize, int k) {
    // step 1 hash the array: 
    struct freq_entry *h_table = NULL; 

    for (int i = 0; i < numsSize; i++)
    {
        struct freq_entry *s; 
        HASH_FIND_INT(h_table, &nums[i], s); 
        if (s == NULL) {
            s = (struct freq_entry *)malloc(sizeof *s); 
            s->value = nums[i]; 
            s->freq = 1; 
            HASH_ADD_INT(h_table, value, s); 
        } else {
            s->freq++; 
        }
    }

    // step 2: use 2 pointer approach towards the center. 
    struct freq_entry *entry, *tmp; 
    int oper = 0; 
    HASH_ITER(hh, h_table, entry, tmp) {
        int complement = k - entry->value;
        if (complement > entry->value) {
            struct freq_entry *s;
            HASH_FIND_INT(h_table, &complement, s);
            if (s != NULL) {
                int pairs = entry->freq < s->freq ? entry->freq : s->freq;
                oper += pairs;
                entry->freq -= pairs;
                s->freq -= pairs;
            }
        } else if (complement == entry->value) {
            int pairs = entry->freq / 2;
            oper += pairs;
            entry->freq -= pairs * 2;
        }
    }

    HASH_CLEAR(hh, h_table); 
    return oper; 
}

int main(int argc, char const *argv[])
{
    int nums1[4] = {1,2,3,4}; 
    int nums2[5] = {3,1,3,4,3}; 
    int k1 = 5; 
    int k2 = 6; 

    printf("test 1: \n"); 
    printf("output: \t\t %d \n", maxOperations(nums1, 4, k1)); 
    printf("expected: \t\t %d \n", 2); 
    printf("\n"); 

    printf("test 2: \n"); 
    printf("output: \t\t %d \n", maxOperations(nums2, 5, k2)); 
    printf("expected: \t\t %d \n", 1); 
    printf("\n"); 

    return 0;
}




// ! BAD SOLUTION:  O(n log n)
// int compare(const void* a, const void* b) {
//     return (*(int*)a - *(int*)b);
// }

// int maxOperations(int* nums, int numsSize, int k){
//     int oper = 0; 

//     qsort(nums, numsSize, sizeof(int), compare); 
//     int* f = nums; 
//     int* b = nums + numsSize - 1; 

//     while (f < b) { 
//         if (*f+*b > k) {
//             b--; 
//         } else if (*f+*b < k) {
//             f++; 
//         } else {
//             oper++; 
//             f++; b--; 
//         }
//     }

//     return oper; 
// }

