
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool increasingTriplet(int* nums, int numsSize) {
    if (numsSize <= 2) return false; 

    int s_low = INT_MAX;  // should refer to indexes. 
    int t_low = INT_MAX; 

    // while (c_idx < numsSize) {
    //     if (nums[c_idx] > nums[s_low]) {
    //         if (nums[s_low] > nums[t_low]) {
    //             return true; 
    //         } else {
    //             t_low = s_low; 
    //         }
    //     } else {
    //         if (nums[s_low] > nums[t_low]) {
    //             t_low = s_low; 
    //             s_low = c_idx; 
    //         } else {
    //             s_low = c_idx; 
    //             t_low = c_idx; 
    //         }
    //     }

    //     c_idx++; 
    // }

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] <= s_low) {
            s_low = nums[i]; 
        } else if (nums[i] <= t_low) {
            t_low = nums[i]; 
        } else {
            return true; 
        }
    }
    
    return false; 
}

int main() {
    int nums1[] = {1,2,3,4,5}; 
    int nums2[] = {5,4,3,2,1}; 
    int nums3[] = {2,1,5,0,4,6}; 

    printf("test1: %s\n", increasingTriplet(nums1, 5) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 

    printf("test2: %s\n", increasingTriplet(nums2, 5) ? "true" : "false"); 
    printf("expected false\n"); 
    printf("\n"); 

    printf("test3: %s\n", increasingTriplet(nums3, 6) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 

    return 0;
}