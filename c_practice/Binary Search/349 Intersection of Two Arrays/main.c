// https://leetcode.com/problems/intersection-of-two-arrays/description/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    if (nums1Size == 0 || nums2Size == 0) return NULL; 

    qsort(nums1, nums1Size, sizeof(int), compare); 
    qsort(nums2, nums2Size, sizeof(int), compare); 

    int cnt=0, last=-1;
    int i1=0, i2=0; 
    while (i1 < nums1Size && i2 < nums2Size) {
        if (nums1[i1] < nums2[i2]) {
            i1++; 
        } else if (nums1[i1] > nums2[i2]) {
            i2++; 
        } else {
            if (nums1[i1] != last) {
                cnt++; 
                last = nums1[i1]; 
            }
            i1++; i2++; 
        }
    }

    *returnSize = cnt; 
    int* ans = malloc(*returnSize * sizeof(int)); 
    int idx=0; 
    last = -1; 
    i1=0; i2=0;  
    while (i1 < nums1Size && i2 < nums2Size) {
        if (nums1[i1] < nums2[i2]) {
            i1++; 
        } else if (nums1[i1] > nums2[i2]) {
            i2++; 
        } else {
            if (nums1[i1] != last) {
                ans[idx++] = nums1[i1]; 
                last = nums1[i1]; 
            }
            i1++; i2++; 
        }
    }

    return ans; 
}

int main(int argc, char const *argv[])
{
    int nums1a[4] = {1,2,2,1}; 
    int nums1b[2] = {2,2}; 

    int nums2a[3] = {4,9,5}; 
    int nums2b[5] = {9,4,9,8,4}; 

    int r1=0, r2=0; 

    int* a1 = intersection(nums1a, 4, nums1b, 2, &r1); 
    // int* a2 = intersection(nums2a, 3, nums2b, 5, &r2); 

    printf("test1: \n"); 
    printf("result: "); 
    printArray(a1, r1); 
    printf("expected: [2] \n\n"); 

    // printf("test2: \n"); 
    // printf("result: "); 
    // printArray(a2, r2); 
    // printf("expected: [9, 4] \n\n"); 

    if (a1 != NULL) free(a1); 
    // if (a2 != NULL) free(a2); 

    return 0;
}
