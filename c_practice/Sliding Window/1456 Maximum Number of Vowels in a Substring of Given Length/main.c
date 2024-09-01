
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include <string.h>

#include "vowel.h"

int maxVowels(char* s, int k) {
    int curr = 0; 
    for (int i = 0; i < k-1; i++) {
        if (isVowel(s[i])) curr++; 
    }

    int max = curr; 
    for (int we=k-1; s[we] != '\0'; we++) {
        if (isVowel(s[we])) curr++;
        if (isVowel(s[we - k])) curr--;
        if (curr > max) max = curr;
        if (curr == k) return k; 
    }
    return max; 
}

bool isVowel(char let) {
    return let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u'; 
}

int main(int argc, char const *argv[])
{
    char* s1 = "abciiidef"; 
    char* s2 = "aeiou"; 
    char* s3 = "leetcode"; 

    printf("test1: %d \n", maxVowels(s1, 3)); 
    printf("expected 3 \n"); 
    printf("\n"); 

    printf("test2: %d \n", maxVowels(s2, 2)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    printf("test3: %d \n", maxVowels(s3, 3)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    return 0;
}
