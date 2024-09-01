#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int findPermutationDifference(char* s, char* t) {
    int res=0; 
    int* s_hash = malloc(26 * sizeof(int));  

    for (size_t i = 0; s[i] != '\0'; i++) {
        s_hash[(int)s[i]-97] = i; 
    }

    for (size_t i = 0; t[i] != '\0'; i++) {
        res += abs(i - s_hash[(int)t[i]-97]); 
    }

    free(s_hash); 
    return res; 
}

int main(int argc, char const *argv[])
{
    char *s1 = "abc"; 
    char *s2 = "abcde"; 

    char *t1 = "bac"; 
    char *t2 = "edbac"; 

    printf("test 1: \n"); 
    printf("result: \t %d \n", findPermutationDifference(s1, t1)); 
    printf("expcted: \t 2 \n"); 

    printf("test 2: \n"); 
    printf("result: \t %d \n", findPermutationDifference(s2, t2)); 
    printf("expcted: \t 12 \n"); 

    return 0;
}
