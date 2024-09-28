// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * 
 * binary search to the target, then have to check for neighboring cells. 
 * 
 * or implement, left binary serch, then right binary search. In case all the values are the same. 
 * 
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* ans = (int*)malloc(2 * sizeof(int)); 
    if (!numsSize) {
        ans[0] = -1; 
        ans[1] = -1; 

        *returnSize = 2; 
        return ans; 
    }
    int left = 0; 
    int right = numsSize; 
    while (left < right) {
        int mid = left + (right-left)/2; 

        if (nums[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }
    if (left >= 0 && left < numsSize) {
        if (nums[left] != target) {
            ans[0] = -1; 
            ans[1] = -1; 

            *returnSize = 2; 
            return ans; 
        }
    }
    if (left >= numsSize || left < 0) {
        ans[0] = -1; 
        ans[1] = -1; 

        *returnSize = 2; 
        return ans; 
    }
    
    ans[0] = left; 

    left = 0; 
    right = numsSize; 
    while (left < right) {
        int mid = left + (right-left)/2; 
        if (nums[mid] > target) {
            right = mid; 
        } else {
            left = mid + 1; 
        }
    }
    ans[1] = right-1; 

    *returnSize = 2; 
    return ans; 
}

int main(int argc, char const *argv[])
{
    int n1[] = {
        5,7,7,8,8,10
    }; 
    int n2[] = {
        5,7,7,8,8,10
    }; 
    int n3[] = {
        
    }; 
    int n4[] = {2, 2}; 
    
    int rs1, rs2, rs3, rs4; 

    int* r1 = searchRange(n1, 6, 8, &rs1); 
    int* r2 = searchRange(n2, 6, 6, &rs2); 
    int* r3 = searchRange(n3, 0, 0, &rs3); 
    int* r4 = searchRange(n4, 2, 3, &rs4); 

    printf("t1\n"); 
    printArray(r1, rs1); 
    printf("\n"); 

    printf("t2\n"); 
    printArray(r2, rs2); 
    printf("\n"); 

    printf("t3\n"); 
    printArray(r3, rs3); 
    printf("\n"); 

    printf("t4\n"); 
    printArray(r4, rs4); 
    printf("\n"); 

    free(r1); 
    free(r2); 
    free(r3); 
    free(r4); 

    return 0;
}
