#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// int minDifference(int* nums, int numsSize) {
//     int smallest[3] = {0}; 
//     int largest[3] = {0}; 
    
//     for (int i = 0; i < numsSize; i++) {
//         for (int j = 0; j < 3; j++) {
//             if (nums[i] > largest[j]) largest[j] = nums[i]; 
//             if (nums[i] < smallest[j]) smallest[j] = nums[i]; 
//         }
//     }

//     int min3[3] = {0}; 

//     for (int i = 0; i < 3; i++) {
//         for (int j = 0; j < 3; j++) {
//             for (int k = 0; k < 3; k++) {
//                 if (largest[i] > smallest[k] && largest[i] - smallest[k] < min3[j]) min3[j] = largest[i] - smallest[k]; 
//             }
//         }
//     }

//     return min3[2]; 
// }

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int minDifference(int* nums, int numsSize) {
    if (numsSize <= 4) {
        return 0; 
    }
    qsort(nums, numsSize, sizeof(int), compare);

    int minDiff = INT_MAX;
    for (int i = 0; i <= 3; i++) {
        int diff = nums[numsSize - 1 - (3 - i)] - nums[i];
        if (diff < minDiff) {
            minDiff = diff;
        }
    }

    return minDiff;
}


int main(int argc, char const *argv[])
{
    int num1[4] = {5,3,2,4};
    int num2[5] = {1,5,0,10,14};

    printf("test 1: %d \n", minDifference(num1, 4)); 
    printf("expected: 0 \n\n"); 

    printf("test 2: %d \n", minDifference(num2, 5)); 
    printf("expected: 1 \n\n"); 

    return 0;
}
