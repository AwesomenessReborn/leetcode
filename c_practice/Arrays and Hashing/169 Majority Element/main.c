
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct ent {
    int value; 
    int freq; 
    UT_hash_handle hh; 
}; 

int majorityElement(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0]; 
    struct ent *h_table = NULL; 
    for (int i = 0; i < numsSize; i++) {
        struct ent *pot; 

        HASH_FIND_INT(h_table, &nums[i], pot); 
        if (pot != NULL) {
            pot->freq++; 
            if (pot->freq > numsSize / 2) {
                int ret = pot->value;
                struct ent *current, *tmp;
                HASH_ITER(hh, h_table, current, tmp) {
                    HASH_DEL(h_table, current);
                    free(current);
                }
                return ret;
            }
        } else {
            pot = (struct ent *)malloc(sizeof *pot);
            pot->value = nums[i]; 
            pot->freq = 1; 
            hash_add_int(h_table, value, pot); 
        }
    }
    struct ent *current, *tmp;
    HASH_ITER(hh, h_table, current, tmp) {
        HASH_DEL(h_table, current);
        free(current);
    }
    return 0; 
}

int main(int argc, char const *argv[])
{
    int nums1[3] = {3,2,3}; 
    int nums2[7] = {2,2,1,1,1,2,2}; 

    printf("test 1: %d \n", majorityElement(nums1, 3)); 
    printf("expected: 3 \n\n"); 

    printf("test 2: %d \n", majorityElement(nums2, 7)); 
    printf("expected: 2 \n\n"); 

    return 0;
}
