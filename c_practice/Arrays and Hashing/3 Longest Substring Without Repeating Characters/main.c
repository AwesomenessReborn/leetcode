
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int max = 0; 
    char* f = s;  // front pointer .
    char* cur = s;  // back pointer  --> contain window, every iteration maintain largest distance between f and b // back pointer  --> contain window, every iteration maintain largest distance between f and b

    int* hash = (int*)calloc(95, sizeof(int));  
    while (*cur != '\0') {
        if (hash[(int)*cur - 32] == 1) {
            while (*f != *cur) {
                hash[(int)*f - 32] = 0;
                f++;
            }
            f++; 
        } else {
            hash[(int)*cur - 32] = 1;
        }

        cur++;
        if (cur - f > max) max = cur - f;
    }
    free(hash); 
    
    return max; 
}

int main(int argc, char const *argv[])
{

    char* s1 = "abcabcbb"; 
    char* s2 = "bbbbb"; 
    char* s3 = "pwwkew"; 

    printf("test1: %d\n", lengthOfLongestSubstring(s1)); 
    printf("expected 3 \n"); 
    printf("\n"); 

    printf("test2: %d\n", lengthOfLongestSubstring(s2)); 
    printf("expected 1 \n"); 
    printf("\n"); 

    printf("test3: %d\n", lengthOfLongestSubstring(s3)); 
    printf("expected 3 \n"); 
    printf("\n"); 
	
	return EXIT_SUCCESS;
}
