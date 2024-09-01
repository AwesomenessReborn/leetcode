
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int longestPalindrome(char* s) {
    int sl = strlen(s); 
    if (1 == sl) return 1; 

    int* hash = (int*)calloc(58, sizeof(int)); 
    for (int i = 0; i < sl; i++) {
        hash[(int)s[i]-65]++; 
    }

    int l = 0; 
    bool o = false; 
    for (int i = 0; i < 58; i++) {
        if (hash[i] % 2 == 1) {
            l += hash[i]-1; 
            o = true; 
        } else {
            l += hash[i]; 
        }
    }
    free(hash); 
    
    if (o) l++; 
    return l; 
}

int main() {
    char *test_1 = "abccccdd"; 
    char *test_2 = "a"; 

    // for (int i = 65; i < 123; i++) {
    //     printf("character %c -- integer value: %d \n", (char)i, i); 
    // }

    printf("test1: %d\n", longestPalindrome(test_1)); 
    printf("expected 7 \n"); 
    printf("\n"); 

    printf("test2: %d\n", longestPalindrome(test_2)); 
    printf("expected 1 \n"); 
    printf("\n"); 
	
	return EXIT_SUCCESS;
}