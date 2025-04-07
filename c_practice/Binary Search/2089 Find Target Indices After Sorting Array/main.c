// https://leetcode.com/problems/find-target-indices-after-sorting-array/description/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    qsort(nums, numsSize, sizeof(int), compare); 

    int left = 0;
    int right = numsSize;

    while (left < right) {
        int mid = (left + right) / 2;

        if (nums[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }

    if (left >= numsSize) {
        *returnSize = 0; 
        return NULL; 
    }

    if (nums[left] != target) {
        *returnSize = 0; 
        return NULL; 
    } 

    int size = 1; 
    while (left + size < numsSize) {
        if (nums[left] == nums[left + size]) {
            size++; 
        } else {
            break; 
        }
    }

    *returnSize = size; 

    int* ans = malloc(size*sizeof(int));  
    for (int i = 0; i < size; i++) {
        ans[i] = left + i; 
    }

    return ans; 
}

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

int main(int argc, char const *argv[])
{
    int nums1[5] = {1,2,5,2,3}; 
    int nums2[5] = {1,2,5,2,3}; 
    int nums3[5] = {1,2,5,2,3}; 
    int nums4[100] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    int r1, r2, r3, r4; 

    int* a1 = targetIndices(nums1, 5, 2, &r1); 
    int* a2 = targetIndices(nums2, 5, 3, &r2); 
    int* a3 = targetIndices(nums3, 5, 5, &r3); 
    int* a4 = targetIndices(nums4, 100, 10, &r4); 

    printf("test1: \n"); 
    printf("result: "); 
    printArray(a1, r1); 
    printf("expected: [1, 2] \n\n"); 

    printf("test2: \n"); 
    printf("result: "); 
    printArray(a2, r2); 
    printf("expected: [3] \n\n"); 

    printf("test3: \n"); 
    printf("result: "); 
    printArray(a3, r3); 
    printf("expected: [4] \n\n"); 

    printf("test3: \n"); 
    printf("result: "); 
    printArray(a4, r4); 
    printf("expected: [] \n\n"); 

    free(a1); 
    free(a2); 
    free(a3); 
    free(a4); 

    return 0;
}

