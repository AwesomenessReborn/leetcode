
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void printIntArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* res = (int*)malloc(numsSize * sizeof(int)); 
    for (int i = 0; i < numsSize; i++) res[i] = 1; 
    
    // go through each index and multiply the moving pp; 
    int pp = 1; 
    for (int i = 1; i < numsSize; i++) {
        pp *= nums[i-1]; 
        res[i] *= pp; 
    }
    printf("prefix portion only: "); 
    printIntArray(res, numsSize); 

    int sp = 1; 
    for (int i = numsSize-2; i >= 0; i--) {
        sp *= nums[i+1]; 
        res[i] *= sp; 
    }

    *returnSize = numsSize; 
    return res; 
}

int main()
{
    int num1[4] = {1,2,3,4};
    int num2[5] = {-1,1,0,-3,3};
    int ret1, ret2; 
    int *res1, *res2; 

    printf("test1: \n"); 
    printf("result: "); 
    res1 = productExceptSelf(num1, 4, &ret1); 
    printIntArray(res1, ret1); 

    printf("test2: \n"); 
    printf("result: "); 
    res2 = productExceptSelf(num2, 5, &ret2); 
    printIntArray(res2, ret2); 

    free(res1); 
    free(res2); 

    return EXIT_SUCCESS;
}
