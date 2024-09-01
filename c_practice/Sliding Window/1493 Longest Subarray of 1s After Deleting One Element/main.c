
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int longestSubarray(int* nums, int numsSize) {
    int start = 0; 
    int end = 0; 
    int zcnt = 0; 
    int max = 0; 

    while (end < numsSize) {
        if (nums[end] == 0) {
            zcnt++; 
        }
        while (zcnt > 1) {
            if (nums[start] == 0) {
                zcnt--; 
            }
            start++; 
        }
        max = end - start + 1 > max ? end - start + 1 : max; 
        end++; 
    }
    return max-1; 
}

int main(int argc, char const *argv[])
{
    int num1[4] = {1,1,0,1};
    int num2[9] = {0,1,1,1,0,1,1,0,1};
    int num3[3] = {1,1,1};

    printf("test1: %d \n", longestSubarray(num1, 4)); 
    printf("expected 3 \n"); 
    printf("\n"); 

    printf("test2: %d \n", longestSubarray(num2, 9)); 
    printf("expected 5 \n"); 
    printf("\n"); 

    printf("test3: %d \n", longestSubarray(num3, 3)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    return 0;
}

