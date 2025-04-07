// https://leetcode.com/problems/search-insert-position/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// recursive approach -- good, but not ideal in C
// int helper(int* nums, int numsSize, int target, int beginIndex) {
//     if (numsSize == 0) return beginIndex; 

//     int mid = beginIndex + numsSize / 2; 

//     if (nums[mid] == target) return mid; 
//     if (nums[mid] > target) return helper(nums, mid - beginIndex, target, beginIndex); 
//     else return helper(nums, numsSize - (mid - beginIndex + 1), target, mid+1); 
// }

// int searchInsert(int* nums, int numsSize, int target) {
//     return helper(nums, numsSize, target, 0); 
// }

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0; 
    int right = numsSize - 1; 

    while (left <= right) {
        int mid = left + (right - left) / 2; 
        
        if (nums[mid] == target) return mid; 
        if (nums[mid] > target) {
            right = mid - 1; 
        } else {
            left = mid + 1; 
        }
    }

    return left; 
}

int main(int argc, char const *argv[])
{
    int num1[4] = {1,3,5,6};
    int num2[4] = {1,3,5,6};
    int num3[4] = {1,3,5,6};

    printf("test1: %d \n", searchInsert(num1, 4, 5)); 
    printf("expected 2 \n\n"); 

    printf("test2: %d \n", searchInsert(num2, 4, 2)); 
    printf("expected 1 \n\n"); 

    printf("test3: %d \n", searchInsert(num3, 4, 7)); 
    printf("expected 4 \n\n"); 




    return 0;
}
