// https://leetcode.com/problems/remove-duplicate-letters/

#include <stdio.h>
#include <stdlib.h>
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

// TODO need to revise -- it needs to output lexographically ordered, 
// this is wrong solution, it simply reorderes. 
char* removeDuplicateLetters(char* s) {
    int LEN = strlen(s); 
    char* res = (char*)malloc((LEN+1)*sizeof(char)); 

    int pt = 0; 
    int* chash = (int*)calloc(26, sizeof(int)); 

    for (int i = 0; i < LEN; i++) {
        if (chash[s[i]-'a']) {
            continue;
        }
        res[pt++] = s[i]; 
        chash[s[i]-'a'] = 1; 
    }

    free(chash); 
    res[pt++] = '\0'; 

    return res; 
}

int main(int argc, char const *argv[])
{
    char* s1 = "bcabc"; 
    char* s2 = "cbacdcbc"; 

    char* r1 = removeDuplicateLetters(s1); 
    char* r2 = removeDuplicateLetters(s2); 

    printf("%s", r1); 
    printf("\n"); 
    printf("%s", r2); 
    printf("\n"); 

    free(r1); 
    free(r2); 

    return 0;
}
