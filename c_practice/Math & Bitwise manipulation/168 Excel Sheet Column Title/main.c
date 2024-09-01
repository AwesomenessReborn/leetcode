
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

char* convertToTitle(int columnNumber) {
    int tmp = columnNumber; 
    int len = 0; 

    while (tmp > 0) {
        tmp = (tmp - 1) / 26;
        len++; 
    }

    tmp = columnNumber; 
    char* ans = malloc((len+1)*sizeof(char)); 
    ans[len] = '\0'; 

    for (int i = len - 1; i >= 0; i--) {
        tmp--; // Adjust to 0-indexed
        ans[i] = tmp % 26 + 'A';
        tmp /= 26;
    }
    
    return ans; 
}

int main(int argc, char const *argv[])
{
    printf("test 1: %s\n", convertToTitle(1)); 
    printf("expceted: A\n\n"); 

    printf("test 2: %s\n", convertToTitle(28)); 
    printf("expceted: AB\n\n"); 

    printf("test 3: %s\n", convertToTitle(701)); 
    printf("expceted: ZY\n\n"); 

    return 0;
}
