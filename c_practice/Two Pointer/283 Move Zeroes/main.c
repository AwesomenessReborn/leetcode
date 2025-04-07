
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// could be good 
// ! BUT IMMEDIATELY IS BAD -- if the first value is 0, then n-1 writes have to be made. 
// void moveZeroes(int* nums, int numsSize) {
//     if (numsSize <= 1) return;     
//     int r = 0; 
//     int wr = 0; 
//     while (r < numsSize) {
//         if (nums[r] != 0) {
//             if (r != wr) nums[wr] = nums[r]; 
//             wr++; 
//         } 
//         r++; 
//     }
//     while (wr < numsSize) {
//         nums[wr++] = 0; 
//     }    
// }

// 1 pointer from front
// 1 pointer from back
// if pointer from front reads a zero -- make a swap with last value: 
void moveZeroes(int* nums, int numsSize) {
    int b = 0; 

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[b++] = nums[i];
        }
    }

    for (int i = b; i < numsSize; i++) {
        nums[i] = 0; 
    }
}

int main(int argc, char const *argv[]) {


    int n1[5] = {
        0,1,0,3,12
    }; 
    int n2[1] = {0}; 

    printArray(n1, 5); 
    printArray(n2, 1); 

    moveZeroes(n1, 5); 
    moveZeroes(n2, 1); 

    printArray(n1, 5); 
    printArray(n2, 1); 

}