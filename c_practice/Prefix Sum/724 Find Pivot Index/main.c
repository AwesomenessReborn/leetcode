
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int pivotIndex(int* nums, int numsSize) {

    int totalSum = 0;
    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    int leftSum = 0;
    for (int i = 0; i < numsSize; i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

// int pivotIndex(int* nums, int numsSize) {
//     int left=0, right=numsSize-1; 
//     int leftS=0, rightS=0; 

//     while (left < right) {
//         if (leftS == rightS) {
//             leftS += nums[left++];
//             rightS += nums[right--];
//         } else if (leftS < rightS) {
//             leftS += nums[left++];
//         } else {
//             rightS += nums[right--];
//         }
//     }
//     if (left == right && leftS == rightS) return left; 
    
//     return -1; 
// }

int main(int argc, char const *argv[])
{

    int num1[6] = {1,7,3,6,5,6};
    int num2[3] = {1,2,3};
    int num3[3] = {2,1,-1};

    printf("test1: %d \n", pivotIndex(num1, 6)); 
    printf("expected 3 \n"); 
    printf("\n"); 

    printf("test2: %d \n", pivotIndex(num2, 3)); 
    printf("expected -1 \n"); 
    printf("\n"); 

    printf("test3: %d \n", pivotIndex(num3, 3)); 
    printf("expected 0 \n"); 
    printf("\n"); 

    return 0;
}
