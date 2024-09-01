
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int maxSatisfied(int* customers, int customersSize, int* grumpy, int grumpySize, int minutes) {
    int max_r=0, curr_r=0; 
    int sum=0; 
    // init: 
    for (int i = 0; i < customersSize; i++) {
        if (i < minutes) {
            curr_r += grumpy[i] ? customers[i] : 0;
        }
        sum += !grumpy[i] ? customers[i] : 0;
    }
    max_r = curr_r; 

    // slide: 
    for (int i = minutes; i < customersSize; i++) {
        // this window should have the powerup, so calculate recovered customers & sum of already customers separately. 
        curr_r = curr_r + (grumpy[i] ? customers[i] : 0) - (grumpy[i-minutes] ? customers[i-minutes] : 0); 
        if (curr_r > max_r) {
            max_r = curr_r;
        }
    }
    return sum+max_r; 
}

int main(int argc, char const *argv[])
{
    int customers1[8] = {1,0,1,2,1,1,7,5};
    int customers2[1] = {1};

    int grumpy1[8] = {0,1,0,1,0,1,0,1};
    int grumpy2[1] = {0};

    printf("test1: %d \n", maxSatisfied(customers1, 8, grumpy1, 8, 3)); 
    printf("expected 16 \n"); 
    printf("\n"); 

    printf("test2: %d \n", maxSatisfied(customers2, 1, grumpy2, 1, 1)); 
    printf("expected 1 \n"); 
    printf("\n"); 

    return 0;
}
