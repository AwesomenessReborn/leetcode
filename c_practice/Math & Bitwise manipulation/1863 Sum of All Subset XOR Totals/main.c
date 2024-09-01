// https://leetcode.com/problems/sum-of-all-subset-xor-totals/description/

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

int** getSubsets(int* nums, int numsSize, int cntSubsets, int* eachSize) {
    int cntSubsets = 1 << numsSize - 1; 
    int** ret = malloc(cntSubsets * sizeof(int*)); 

    for (int l = 0; l < numsSize; l++) { // l is the size of each subset
        int* cur = malloc(l * sizeof(int)); 

        
    }

    return ret; 
}

// use recursion: 
int subsetXORSum(int* nums, int numsSize) {
    if (numsSize == 0) return 0; 

    int* eachSize; 
    int cntSubsets; 
    int** allSubsets = getSubsets(nums, numsSize, &cntSubsets, &eachSize); 

    int sum=0; 
    for (int i = 0; i < cntSubsets; i++) {
        int cur = 0; 
        for (int j = 0; j < eachSize[i]; j++) {
            cur = cur ^ allSubsets[i][j]; 
        }
        sum += cur; 
    }

    return sum; 
}

int main(int argc, char const *argv[])
{
    int nums1[2] = {1,3}; 
    int nums2[3] = {5,1,6}; 
    int nums3[6] = {3,4,5,6,7,8}; 

    printf("test 1: %d \n", subsetXORSum(nums1, 2)); 
    printf("expected: 6\n\n"); 

    printf("test 2: %d \n", subsetXORSum(nums2, 3)); 
    printf("expected: 28\n\n"); 

    printf("test 3: %d \n", subsetXORSum(nums3, 6)); 
    printf("expected: 480 \n\n"); 
    
    return 0;
}
