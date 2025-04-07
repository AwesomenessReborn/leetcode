
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int getLucky(char* s, int k) {
    int len = strlen(s); 
    char* sum = "\0"; 

    
    for (int i = 0; i < len; i++) {
        printf("adding %d \n", (s[i] - 'a' + 1)); 

    }

    // final: 


    return sum; 
}

int main(int argc, char const *argv[])
{
    char* s1 = "iiii"; 
    char* s2 = "leetcode"; 

    printf("test 1: %d \n", getLucky(s1, 1)); 
    printf("test 2: %d \n", getLucky(s2, 2)); 

    return 0;
}
