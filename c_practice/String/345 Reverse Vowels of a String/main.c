
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool isVowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char* reverseVowels(char* s) {
    int si = strlen(s);
    char* res = malloc((si + 1) * sizeof(char));
    strcpy(res, s);
    if (si == 1)
        return res;

    char* be = res;
    char* en = res + si - 1;

    while (be < en) {
        while (be < en && !isVowel(*be)) {
            be++;
        }
        while (be < en && !isVowel(*en)) {
            en--;
        }

        if (be < en) {
            // printf("Swapping %c at position %ld with %c at position %ld\n", *be, be - s, *en, en - s);

            char tmp = *be;
            *be = *en;
            *en = tmp;
            be++;
            en--;
        }
    }

    return res;
}


int main()
{
    char *string1 = "hello";
    char *string2 = "leetcode";

    char *ptr = string1; 

    // // printf("string: %s \n", string1); 
    // printf("%c \n", *ptr); 
    // printf("%d \n", *ptr); 
    // ptr++; 
    // printf("%c \n", *ptr); 
    // printf("%d \n", *ptr); 

    char *ans1 = reverseVowels(string1); 
    printf("result:      %s \n", ans1); 
    printf("expected:    holle \n"); 
    printf("\n"); 

    char *ans2 = reverseVowels(string2); 
    printf("result:      %s \n", ans2); 
    printf("expected:    leotcede \n"); 
    printf("\n"); 

    return EXIT_SUCCESS;
}