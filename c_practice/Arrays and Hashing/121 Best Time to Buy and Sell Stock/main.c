
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// terrible solution. beats only 6.13%
int maxProfit(int* prices, int pricesSize) {
    int curr_min=0, curr=1; 
    int max=0; 
    while (curr < pricesSize) {
        if (prices[curr] < prices[curr_min]) {
            curr_min = curr; // realize that there is a lower value -- there is no way a profit. 
        } else {
            int pot = prices[curr] - prices[curr_min]; 
            if (pot > max) max = pot; 
        }
        curr++; 
    }

    return max; 
}

int main(int argc, char const *argv[])
{
    int num1[6] = {7,1,5,3,6,4};
    int num2[5] = {7,6,4,3,1};

    printf("test1: %d \n", maxProfit(num1, 6)); 
    printf("expected 5 \n"); 
    printf("\n"); 

    printf("test2: %d \n", maxProfit(num2, 5)); 
    printf("expected 0 \n"); 
    printf("\n"); 
    
    return 0;
}
