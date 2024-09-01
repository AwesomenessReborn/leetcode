#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char* s = "()[]{}"; 
    for (int i = 0; i < 6; i++) {
        printf("%c : %d \n", s[i], s[i]); 
    }

    // valid character ranges: i >= 97 && i < 123 || i >= 65 && i < 91
    // printf("%d \n\n", 701/26); 

    // int num2[2] = {1, 1};
    // int* b = num2; 
    
    // printf("%d\n", &b); 
    // b++; 
    // printf("%d\n", &b); 

    return 0;
}
