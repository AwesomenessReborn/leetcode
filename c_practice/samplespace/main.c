
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

// _Bool is alternative for bool before C99 standard
_Bool isEven(int value) {
    return value % 2 == 0; 
}

inline int32_t fixed_multiply(int32_t a, int32_t b) {
    return (int32_t)(((int64_t)a * b) >> 16); 
}

_Bool checker(int value, _Bool (*func)(int)) {
    return func(value); 
}

int main(int argc, char const *argv[])
{

    // int num = 0xabcdef; 
    // printf("%d\n", num);     // Output: "0x2a"

    _Bool (*fptr)(int); 

    fptr = &isEven; 

    printf("%d\n", checker(0x12, isEven)); 

    return 0;
}
