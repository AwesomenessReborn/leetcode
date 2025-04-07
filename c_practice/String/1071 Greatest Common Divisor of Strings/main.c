#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// char* gcdOfStrings(char* str1, char* str2) {
//     char* res = (char*)malloc(((sizeof(str1) > sizeof(str2)) ? sizeof(str1) : sizeof(str2))*sizeof(char)); 
//     char* p1 = (char*)malloc(strlen(str1)); 
//     char* p2 = (char*)malloc(strlen(str2)); 
//     int i = 1; 
//     while (1) {
//         strncpy(p1, str1, i); 
//         strncpy(p2, str2, i); 
//         if (strncmp(p1, p2, i)) {
//             // they are not the same. 
//             return res; 
//         }
//         i++; 
//     }

//     return res; 
// }

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char* concat1 = (char*)malloc(len1 + len2 + 1);
    char* concat2 = (char*)malloc(len1 + len2 + 1);
    strcpy(concat1, str1);
    strcat(concat1, str2);
    strcpy(concat2, str2);
    strcat(concat2, str1);

    if (strcmp(concat1, concat2) != 0) {
        free(concat1);
        free(concat2);
        return "";
    }

    free(concat1);
    free(concat2);

    int gcdLen = gcd(len1, len2);

    char* res = (char*)malloc(gcdLen + 1);
    strncpy(res, str1, gcdLen);
    res[gcdLen] = '\0';

    return res;
}

int main()
{
    char *string1_1 = "ABCABC";
    char *string1_2 = "ABC";

    char *string2_1 = "ABABAB";
    char *string2_2 = "ABAB";

    char *string3_1 = "LEET";
    char *string3_2 = "CODE";

    char *ans1 = gcdOfStrings(string1_1, string1_2); 
    printf("result:     %s \n", ans1); 
    printf("expected:   ABC \n");
    printf("\n"); 
    char *ans2 = gcdOfStrings(string2_1, string2_2); 
    printf("result:      %s \n", ans2); 
    printf("expected:   AB \n");
    printf("\n"); 
    char *ans3 = gcdOfStrings(string3_1, string3_2); 
    printf("result:      %s \n", ans3); 
    printf("expected:   \n");
    printf("\n"); 

    return EXIT_SUCCESS;
}