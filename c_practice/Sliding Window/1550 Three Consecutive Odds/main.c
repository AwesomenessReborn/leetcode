
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool threeConsecutiveOdds(int* arr, int arrSize) {
    if (arrSize < 3) return false; 
    int ocnt = 0; 

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] % 2 == 1) {
            ocnt++; 
        } else {
            ocnt = 0; 
        }
        if (ocnt == 3) return true; 
    }
    
    return false; 
}

int main(int argc, char const *argv[])
{

    int num1[4] = {2,6,4,1};
    int num2[9] = {1,2,34,3,4,5,7,23,12};
    int num3[5] = {1,1,2,1,1}; 

    printf("test1: %s \n", threeConsecutiveOdds(num1, 4) ? "true" : "false"); 
    printf("expected false \n"); 
    printf("\n"); 

    printf("test2: %s \n", threeConsecutiveOdds(num2, 9) ? "true" : "false"); 
    printf("expected true \n"); 
    printf("\n"); 

    printf("test3: %s \n", threeConsecutiveOdds(num3, 5) ? "true" : "false"); 
    printf("expected false \n"); 
    printf("\n"); 

    return 0;
}
