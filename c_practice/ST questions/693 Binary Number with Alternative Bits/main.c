// https://leetcode.com/problems/binary-number-with-alternating-bits/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

bool hasAlternatingBits(int n) {
    while (n > 0) {
        if (((n & 0x1) == ((n >> 1) & 0x1))) {
            return 0; 
        }
        n >>= 1; 
    }
    return 1; 
}

int main(int argc, char const *argv[])
{
    printf("t1 -- %d\n", hasAlternatingBits(5)); 
    printf("t2 -- %d\n", hasAlternatingBits(7)); 
    printf("t3 -- %d\n", hasAlternatingBits(11)); 
    printf("t4 -- %d\n", hasAlternatingBits(6)); 

    return 0;
}
