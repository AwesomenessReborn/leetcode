
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

double findMaxAverage(int* nums, int numsSize, int k) {
    double curr = 0; 
    int ws = 0; 
    int we = k - 1; 

    // init curr; 
    for (int i = 0; i < k; i++) {
        curr+= nums[i];   
    }
    double max = curr; 
    while (we < numsSize - 1) {
        curr = curr - nums[ws] + nums[we + 1];
        if (curr > max) max = curr; 
        ws++;
        we++;
    }
    return max/k; 
}


int main(int argc, char const *argv[])
{
    int num1[6] = {1,12,-5,-6,50,3};
    int num2[1] = {5};

    printf("test1: %f \n", findMaxAverage(num1, 6, 4)); 
    printf("expected 12.75000 \n"); 
    printf("\n"); 

    printf("test2: %f \n", findMaxAverage(num2, 1, 1)); 
    printf("expected 5.00000 \n"); 
    printf("\n"); 

    return 0;
}
