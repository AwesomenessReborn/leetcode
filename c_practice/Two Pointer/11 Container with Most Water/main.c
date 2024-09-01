// https://leetcode.com/problems/container-with-most-water/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int imin(int a, int b) {
    return a > b ? b : a; 
}

int maxArea(int* height, int heightSize) {
    int* f = height; 
    int* b = height + heightSize - 1; 

    int max = 0; 
    while (f < b) {
        int ar = (b-f)*imin(*f, *b); 
        if (ar > max) max = ar; 

        if (*(f) > *(b)) {
            b--; 
        } else {
            f++; 
        }
    }
    
    return max; 
}

int main(int argc, char const *argv[])
{
    int h1[9] = {
        1,8,6,2,5,4,8,3,7
    }; 
    int h2[2] = {
        1,1
    }; 

    printf("test 1: \n"); 
    printf("output: \t\t %d \n", maxArea(h1, 9)); 
    printf("expected: \t\t %d \n", 49); 
    printf("\n"); 

    printf("test 2: \n"); 
    printf("output: \t\t %d \n", maxArea(h2, 2)); 
    printf("expected: \t\t %d \n", 1); 
    printf("\n"); 

    return 0;
}
