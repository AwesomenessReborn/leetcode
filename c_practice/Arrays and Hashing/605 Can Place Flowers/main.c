#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n) {
    if (flowerbedSize == 1) {
        if (flowerbed[0] == 0)  {
            return n == 1 || n == 0; 
        }
        return n == 0; 
    }
    if (flowerbed[0] == 0 && flowerbed[1] == 0) {
        flowerbed[0] = 1; n--; 
    }
    for (int i = 1; i < flowerbedSize - 1; i++) {
        if (flowerbed[i] == 1) continue; 

        if (flowerbed[i-1] == 0 && flowerbed [i + 1] == 0) {
            flowerbed[i] = 1; 
            n--; 
        }
    }
    if (flowerbed[flowerbedSize - 2] == 0 && flowerbed[flowerbedSize - 1] == 0) {
        flowerbed[flowerbedSize - 1] = 1; n--; 
    }
    // printf("result n: %d \n", n); 
    return n <= 0; 
}


int main()
{
    int num1[5] = {1,0,0,0,1};
    int num2[5] = {1,0,0,0,1};
    int num3[5] = {0,0,1,0,1}; 
    int num4[1] = {0}; 

    // printf("test1: %s\n", canPlaceFlowers(num1, 5, 1) ? "true" : "false"); 
    // printf("expected true\n"); 
    // printf("\n"); 

    // printf("test2: %s\n", canPlaceFlowers(num2, 5, 2) ? "true" : "false"); 
    // printf("expected false\n"); 
    // printf("\n"); 

    // printf("test3: %s\n", canPlaceFlowers(num3, 5, 1) ? "true" : "false"); 
    // printf("expected true\n"); 
    // printf("\n"); 

    printf("test4: %s\n", canPlaceFlowers(num4, 1, 0) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("\n"); 

    return EXIT_SUCCESS;
}