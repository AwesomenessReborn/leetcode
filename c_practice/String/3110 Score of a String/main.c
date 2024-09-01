
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int scoreOfString(char* s) {
    int x = 1; 
    int a = 0; 
    while (s[x] != '\0') {
        a += abs((int)s[x-1] - (int)s[x++]); 
    }
    return a; 
}

int main()
{
    char *string1 = "hello";

    char *string2 = "zaz";

    int ans1 = scoreOfString(string1); 
    printf("%d \n", ans1); 
    printf("\n"); 
    int ans2 = scoreOfString(string2); 
    printf("%d \n", ans2); 
    printf("\n"); 

    return EXIT_SUCCESS;
}