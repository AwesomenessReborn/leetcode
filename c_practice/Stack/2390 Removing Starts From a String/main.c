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

char* removeStars(char* s) {
    int n = strlen(s); 

    // char ans[n]; 
    char* ans = (char*)malloc((n+1)*sizeof(char)); 
    int apoint = 0; 
    int idx = 0;            // idx to iterate input string. 

    while (idx < n) {
        if (s[idx] == '*') {
            ans[apoint] = ' '; 
            apoint--; 

            idx++; 
            continue;
        }
        ans[apoint++] = s[idx++]; 
    }
    ans[apoint] = '\0'; 

    strcpy(s, ans); 
    free(ans); 

    return s; 
}

int main(int argc, char const *argv[])
{
    char str1[] = "leet**cod*e";
    char str2[] = "erase*****";

    char* a1 = removeStars(str1); 
    char* a2 = removeStars(str2); 

    printf("%s \n", a1); 
    printf("%s \n", a2); 

    return 0;
}
