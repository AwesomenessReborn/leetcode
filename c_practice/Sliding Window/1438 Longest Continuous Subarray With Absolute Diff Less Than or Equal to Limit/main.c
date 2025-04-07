
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

static inline int max(int a, int b) {
    return (a < b) ? b : a;
}

int longestSubarray(int* nums, int numsSize, int limit) {
    int min=0; 
    int max=0; 
    int ans=0; 
    // every loop --> if (max-min) > prev_ans : ans = (max-min)
    // every loop make sure we move the window such that diff between min,max is less than or equal to limit. 
    // we also need to make sure we maximize this max-min value without exceeding limit. 
    int ws=0; 
    int we=0; 
    while (we < numsSize) {

        if (nums[we] > max) {

        } else if (nums[we] < min) {

        }
        
    }

    return ans; 
}


int main(int argc, char const *argv[])
{

    int num1[4] = {8,2,4,7};
    int num2[6] = {10,1,2,4,7,2};
    int num3[8] = {4,2,2,2,4,4,2,2};

    int lim1 = 4; 
    int lim2 = 5; 
    int lim3 = 0; 

    printf("test1: %d \n", longestSubarray(num1, 4, lim1)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    printf("test2: %d \n", longestSubarray(num2, 6, lim2)); 
    printf("expected 4 \n"); 
    printf("\n"); 

    printf("test3: %d \n", longestSubarray(num3, 8, lim3)); 
    printf("expected 3 \n"); 
    printf("\n"); 
    
    return 0;
}
