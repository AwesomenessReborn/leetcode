
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

int firstUniqChar(char* s) {
    int* hh = calloc(26, sizeof(int)); 
    
    int j = strlen(s); 
    for (int i = 0; i < j; i++) {
        hh[(int)s[i]-'a']++; 
    }
    for (int i = 0; i < j; i++) {
        if (hh[(int)s[i]-'a'] == 1) {
            free(hh); 
            return i; 
        }
    }
    free(hh); 
    return -1; 
}

int main(int argc, char const *argv[])
{

    char* s1 = "leetcode"; 
    char* s2 = "loveleetcode"; 
    char* s3 = "aabb"; 

    printf("test1: %d\n", firstUniqChar(s1)); 
    printf("expected 0 \n"); 
    printf("\n"); 

    printf("test2: %d\n", firstUniqChar(s2)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    printf("test3: %d\n", firstUniqChar(s3)); 
    printf("expected -1 \n"); 
    printf("\n"); 

    return 0;
}
