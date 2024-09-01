
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int longestOnes(int* nums, int numsSize, int k) {
    int start = 0; 
    int end = 0; 
    int zcnt = 0; 
    int max = 0; 

    while (end < numsSize) {
        if (nums[end] == 0) {
            zcnt++; 
        }
        while (zcnt > k) {
            if (nums[start] == 0) {
                zcnt--; 
            }
            start++; 
        }
        max = end - start + 1 > max ? end - start + 1 : max; 
        end++; 
    }

    return max; 
}

int main(int argc, char const *argv[])
{
    int num1[11] = {1,1,1,0,0,0,1,1,1,1,0};
    int num2[19] = {0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1};
    int k1 = 2; 
    int k2 = 3; 

    printf("test1: %d \n", longestOnes(num1, 11, k1)); 
    printf("expected 6 \n"); 
    printf("\n"); 

    printf("test2: %d \n", longestOnes(num2, 19, k2)); 
    printf("expected 10 \n"); 
    printf("\n"); 

    return 0;
}
