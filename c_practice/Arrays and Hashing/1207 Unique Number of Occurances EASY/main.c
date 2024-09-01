#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool uniqueOccurrences(int* arr, int arrSize) {
    // step 1: count frequencies: 
    int* freq = calloc(2001, sizeof(int)); 
    for (int i = 0; i < arrSize; i++) {
        // printf("value %d found, adding to freq. \n", arr[i]); 
        freq[arr[i] + 1000]++; 
    }

    // step 2: hash --> if success then return true; else return false; USE ARRAY HASH
    int* pres = calloc(arrSize + 1, sizeof(int)); 
    for (int i = 0; i < 2001; i++) {
        if (freq[i] > 0) {
            if (pres[freq[i]] > 0) {
                // Frequency already seen
                printf("this frequency has been seen: \n"); 
                printf("i               = %d \n", i); 
                printf("freq[i]         = %d \n", freq[i]); 
                printf("pres[freq[i]]   = %d \n", pres[freq[i]]); 
                free(freq); 
                free(pres); 
                return false; 
            }
            pres[freq[i]]++;
        }
    }
    
    free(freq); free(pres); 
    return true; 
}

int main()
{
    int num1[6] = {1,2,2,1,1,3};
    int num2[2] = {1, 2};
    int num3[10] = {-3,0,1,-3,1,1,1,-3,10,0};

    printf("test1: %s\n", uniqueOccurrences(num1, 6) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 

    printf("test2: %s\n", uniqueOccurrences(num2, 2) ? "true" : "false"); 
    printf("expected false\n"); 
    printf("\n"); 

    printf("test3: %s\n", uniqueOccurrences(num3, 10) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 

    return EXIT_SUCCESS;
}