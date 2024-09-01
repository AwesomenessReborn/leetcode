
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// char* reverseWords(char* s) {
//     int si = strlen(s);
//     char* res = malloc((si + 1) * sizeof(char));
    
//     int wr = 0; 
//     char* p1 = s + si - 1; 
//     char* p2 = s + si - 1; 
//     char* be = s; 
//     printf("end: %c \n", *p1); 
//     printf("begin: %c \n", *be); 

//     while (si - wr > 0) {
//         while (p1 >= be && *p1 == ' ') {
//             p1--; 
//         }
//         if (p1 < be) break; 

//         p2 = p1; 
//         while (*(p2) != ' ' && p2 >= be) {
//             p2--; 
//         }
//         p2++; 

//         printf("writing word: %c to %c \n", *p2, *p1); 
//         while (p2 <= p1) {
//             res[wr++] = *p2++; 
//         }

//         if (p1 > be) {
//             res[wr++] = ' '; 
//         }

//         p1 = p2 - 2; 
//     } 
//     res[wr] = '\0'; 

//     return res; 
// }

// This is adjusted solution (the same thing as above, but using indexes instead of pointers)
char* reverseWords(char* s) {
    int len = strlen(s);
    char* res = (char*)malloc((len + 1) * sizeof(char));

    int wr = 0; 
    int end = len - 1; 
    while (end >= 0) {
        while (end >= 0 && s[end] == ' ') {
            end--;
        }

        if (end < 0) {
            break;
        }

        int start = end;
        while (start >= 0 && s[start] != ' ') {
            start--;
        }

        for (int i = start + 1; i <= end; i++) {
            res[wr++] = s[i];
        }

        if (start > 0) {
            res[wr++] = ' ';
        }

        end = start - 1;
    }

    res[wr] = '\0';

    if (wr > 0 && res[wr - 1] == ' ') {
        res[wr - 1] = '\0';
    }

    return res;
}

int main()
{
    char *string1 = "the sky is blue";
    char *string2 = "  hello world  ";
    char *string3 = "a good   example"; 

    char *ans1 = reverseWords(string1); 
    printf("result:      %s \n", ans1); 
    printf("expected:    blue is sky the \n"); 
    printf("\n"); 

    char *ans2 = reverseWords(string2); 
    printf("result:      %s \n", ans2); 
    printf("expected:    world hello \n"); 
    printf("\n"); 

    char *ans3 = reverseWords(string3); 
    printf("result:      %s \n", ans3); 
    printf("expected:    example good a \n"); 
    printf("\n"); 

    return EXIT_SUCCESS;
}