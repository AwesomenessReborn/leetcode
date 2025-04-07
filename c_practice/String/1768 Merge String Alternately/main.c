
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2) {
    int w1 = strlen(word1); 
    int w2 = strlen(word2); 
    char* res = (char*)malloc((w1 + w2 + 1)*sizeof(char)); 

    int x = 0; 
    int res_idx = 0; 
    while(1) {
        printf("x: %d res_idx: %d \n", x, res_idx); 
        if (x == w1) { 
            printf("reached word1 end first @ res_index: %d \n", res_idx); 
            while(x < w2) {
                printf("adding character word2[x]: %c \n", word2[x]); 
                res[res_idx++] = word2[x++]; 
            }
            res[res_idx] = '\0'; 
            break; 
        }
        if (x == w2) { 
            printf("reached word2 end first @ index: %d \n", res_idx); 
            while(x < w1) {
                res[res_idx++] = word1[x++]; 
            }
            res[res_idx] = '\0'; 
            break; 
        }
        printf("adding character: %c \n", word1[x]); 
        res[res_idx++] = word1[x]; 
        printf("adding character: %c \n", word2[x]); 
        res[res_idx++] = word2[x]; 
        x++; 
    }
    return res; 
}

int main()
{
    char *string1_1 = "abc";
    char *string1_2 = "pqr";

    char *string2_1 = "ab";
    char *string2_2 = "pqrs";

    char *string3_1 = "abcd";
    char *string3_2 = "pq";

    char *ans1 = mergeAlternately(string1_1, string1_2); 
    printf("%s \n", ans1); 
    printf("\n"); 
    char *ans2 = mergeAlternately(string2_1, string2_2); 
    printf("%s \n", ans2); 
    printf("\n"); 
    char *ans3 = mergeAlternately(string3_1, string3_2); 
    printf("%s \n", ans3); 
    printf("\n"); 

    return EXIT_SUCCESS;
}