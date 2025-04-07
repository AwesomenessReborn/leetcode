/**
 * https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char* s, char* t) {
    char* sp = s; 
    char* tp = t; 
    while (*tp != '\0') {
        // iterate through t -- using tp
        if (*tp == *sp) *sp++; 
        tp++; 
    }
    return *sp == '\0';
}

int main(int argc, char const *argv[])
{

    char* s1 = "abc"; 
    char* t1 = "ahbgdc"; 
    char* s2 = "axc"; 
    char* t2 = "ahbgdc"; 

    printf("test1: %s \n", isSubsequence(s1, t1) ? "true" : "false"); 
    printf("expected true\n"); 
    printf("test2: %s\n", isSubsequence(s2, t2) ? "true" : "false"); 
    printf("expected false\n"); 

    return EXIT_SUCCESS;
}
