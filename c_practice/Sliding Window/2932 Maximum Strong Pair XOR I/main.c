
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int maximumStrongPairXor(int* nums, int numsSize) {
    int max = 0; 
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (abs(nums[i] - nums[j]) <= min(nums[i], nums[j])) {
                int pot = nums[i] ^ nums[j]; 
                if (pot > max) max = pot; 
            }
        }
    }
    return max; 
}

int main(int argc, char const *argv[])
{
    int num1[5] = {1,2,3,4,5};
    int num2[2] = {10,100};
    int num3[4] = {5,6,25,30};

    printf("test1: %d \n", maximumStrongPairXor(num1, 5)); 
    printf("expected 7 \n"); 
    printf("\n"); 

    printf("test2: %d \n", maximumStrongPairXor(num2, 2)); 
    printf("expected 0 \n"); 
    printf("\n"); 

    printf("test3: %d \n", maximumStrongPairXor(num3, 4)); 
    printf("expected 7 \n"); 
    printf("\n"); 

    return 0;
}
