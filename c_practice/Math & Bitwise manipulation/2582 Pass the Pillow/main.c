#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int passThePillow(int n, int time) {
    int re = time % (2*(n-1)); 
    if (re < n) return re+1; 
    return 2*n - re - 1; 
}

int main(int argc, char const *argv[])
{
    printf("test 1: %d \n", passThePillow(4, 5)); 
    printf("expected: 2 \n\n"); 

    printf("test 2: %d \n", passThePillow(3, 2)); 
    printf("expected: 3 \n\n"); 

    printf("test 3: %d \n", passThePillow(8, 9)); 
    printf("expected: 6 \n\n"); 

    return 0;
}
