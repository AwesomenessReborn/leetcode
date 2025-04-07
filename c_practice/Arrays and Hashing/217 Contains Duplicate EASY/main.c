#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct rec_entry {
    int value; 
    UT_hash_handle hh; 
}; 

bool containsDuplicate(int *nums, int numsSize)
{
    struct rec_entry *h_table = NULL; 

    for (int i = 0; i < numsSize; i++) {
        struct rec_entry *pot; 

        HASH_FIND_INT(h_table, &nums[i], pot); 
        if (pot == NULL) { 
            pot = (struct rec_entry *)malloc(sizeof *pot);
            pot->value = nums[i]; 
            HASH_ADD_INT(h_table, value, pot); 
        } else {
            HASH_CLEAR(hh, h_table); 
            return true; 
        }
    }

    HASH_CLEAR(hh, h_table); 
    return false; 
}

int main()
{

    int num1[4] = {1, 2, 3, 1};
    int num2[4] = {1, 2, 3, 4};
    int num3[10] = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};

    printf("test1: %s \n", containsDuplicate(num1, 4) ? "true" : "false"); 
    printf("expected true\n"); 

    printf("test2: %s\n", containsDuplicate(num2, 4) ? "true" : "false"); 
    printf("expected false\n"); 

    printf("test3: %s\n", containsDuplicate(num3, 10) ? "true" : "false"); 
    printf("expected true\n"); 

    return EXIT_SUCCESS;
}
