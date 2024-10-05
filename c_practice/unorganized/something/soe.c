#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

void InsertionSortInterleaved(int* numbers, int numbersSize, int startIndex, int gap) {
   for (int i = startIndex + gap; i < numbersSize; i += gap) {
      int j = i;
      while (j - gap >= startIndex && numbers[j] < numbers[j - gap]) {
         int temp = numbers[j];
         numbers[j] = numbers[j - gap];
         numbers[j - gap] = temp;
         j -= gap;
      }
   }
}

int main(int argc, char const *argv[])
{

    // int array[] = {
    //     1, 2, 3, 4, 5
    // }; 

    // int *s = array; 

    // printf("value: %d , address: %p\n", *s, (void*)s); 
    // s++; 
    // printf("value: %d , address: %p\n", *s, (void*)s); 
    // s++; 
    // printf("value: %d , address: %p\n", *s, (void*)s); 
    // s++; 
    // int* something= malloc(5 *sizeof(int)); 

    // for (size_t i = 0; i < 5; i++)
    // {
    //     printf("%d \n", something[i]); 
    // }

    // use this range: [32, 127) for printable characters: 
    // shift: +32. 
    // count: 95
    // for (int i = 97; i < 123; i++) {
    //     printf("index: %d \t char: %c \n", i, i); 
    // }

    // for (int i = 65; i < 91; i++) {
    //     printf("index: %d \t char: %c \n", i, i); 
    // }
    // problem 168: 
    // need to map A -- 65 to 1
    // need to map Z -- 90 to 26
    // printf("%d\n", (int)"1"); 


    // for (int i = 48; i < 58; i++) {
    //     printf("index: %d \t char: %c \t digit match %d \n", i, i, i - 48); 
    // }
    // char* s = "()[]{}"; 
    // for (int i = 0; i < 6; i++) {
    //     printf("%c : %d \n", s[i], s[i]); 
    // }

    // int inp[] = {
    //     85, 28, 74, 53, 17, 95
    // }; 
    // InsertionSortInterleaved(inp, 6, 0, 4); 
    // printArray(inp, 6); 

    // InsertionSortInterleaved(inp, 6, 0, 2); 
    // printArray(inp, 6); 

    // InsertionSortInterleaved(inp, 6, 0, 1); 
    // printArray(inp, 6); 

    // valid character ranges: i >= 97 && i < 123 || i >= 65 && i < 91
    // printf("%d \n\n", 701/26); 

    // int num2[2] = {1, 1};
    // int* b = num2; 
    
    // printf("%d\n", &b); 
    // b++; 
    // printf("%d\n", &b); 

    uint8_t n = 250; 
    uint8_t nn = n+30; 
    printf("%d\n", nn); 

    return 0;
}
