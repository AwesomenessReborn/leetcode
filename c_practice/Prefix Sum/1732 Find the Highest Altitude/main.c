

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int largestAltitude(int* gain, int gainSize) {
    int max=0, curr=0; 
    for (int i = 0; i < gainSize; i++) {
        curr += gain[i]; 
        if (max < curr) max = curr; 
    }
    return max; 
}

int main(int argc, char const *argv[])
{
    int num1[5] = {-5,1,5,0,-7};
    int num2[7] = {-4,-3,-2,-1,4,3,2};

    printf("test1: %d \n", largestAltitude(num1, 5)); 
    printf("expected 1 \n"); 
    printf("\n"); 

    printf("test2: %d \n", largestAltitude(num2, 7)); 
    printf("expected 0 \n"); 
    printf("\n"); 

    return 0;
}
