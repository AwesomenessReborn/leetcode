

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// MATH solution. 
int numWaterBottles(int numBottles, int numExchange) {
    if (numBottles < numExchange) return numBottles; 
    return numBottles + ((numBottles-1)/(numExchange-1)); 
}

int main(int argc, char const *argv[])
{

    printf("test 1: %d \n", numWaterBottles(9, 3)); 
    printf("expected: 13 \n\n"); 

    printf("test 2: %d \n", numWaterBottles(15, 4)); 
    printf("expected: 19 \n\n"); 

    // printf("test 3: %d \n", numWaterBottles(8, 9)); 
    // printf("expected: 6 \n\n"); 

    return 0;
}