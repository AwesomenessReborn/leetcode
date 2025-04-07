// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY

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

int getbits(int value) {
    int cnt = 0; 
    while (value > 0) {
        if (value & 0x1) cnt++; 
        value >>= 1; 
    }
    return cnt; 
}

int countPrimeSetBits(int left, int right) {
    int cnt = 0; 
    for (int i = left; i <= right; i++) {
        int c = getbits(i); 
        if (c == 2 || c == 3 || c == 5 || c == 7 || c == 11 || c == 13 || c == 17 || c == 19) cnt++; 
    }
    return cnt; 
}

int main(int argc, char const *argv[])
{
    printf("t1 -- %d\n", countPrimeSetBits(6, 10)); 
    printf("t2 -- %d\n", countPrimeSetBits(10, 15)); 

    return 0;
}
