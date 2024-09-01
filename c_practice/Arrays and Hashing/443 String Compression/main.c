
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compress(char* chars, int charsSize) {
    if (charsSize == 1)
        return 1;
    int t = 1;
    int w_idx = 0;
    int curr = 1;
    char cc = chars[0];

    while (t < charsSize) {
        if (chars[t] != cc) {
            chars[w_idx++] = cc;
            if (curr != 1) {
                char temp[4];
                int length = snprintf(temp, sizeof(temp), "%d", curr);
                for (int i = 0; i < length; i++) {
                    chars[w_idx++] = temp[i];
                }
            }
            cc = chars[t];
            curr = 1;
        } else {
            curr++;
        }

        if (t == charsSize - 1) {
            if (curr == 1) {
                chars[w_idx++] = cc; 
            } else {
                chars[w_idx++] = cc; 
                char temp[12]; 
                int length = snprintf(temp, sizeof(temp), "%d", curr);
                for (int i = 0; i < length; i++) {
                    chars[w_idx++] = temp[i]; 
                }
            }
        }

        t++;
    }

    return w_idx;
}

int main(int argc, char const *argv[])
{
    char* c1[] = {"a","a","b","b","c","c","c"}; 
    char* c2[] = {"a"}; 
    char* c3[] = {"a","b","b","b","b","b","b","b","b","b","b","b","b"}; 
    char* c4[] = {
        "a", "b", "c"
    }; 

    // Calculate the lengths of the arrays
    int len1 = sizeof(c1) / sizeof(c1[0]);
    int len2 = sizeof(c2) / sizeof(c2[0]);
    int len3 = sizeof(c3) / sizeof(c3[0]);
    int len4 = sizeof(c4) / sizeof(c4[0]);

    // Allocate memory and copy the strings to a1, a2, and a3
    char *a1 = (char *)malloc((len1 + 1) * sizeof(char));
    char *a2 = (char *)malloc((len2 + 1) * sizeof(char));
    char *a3 = (char *)malloc((len3 + 1) * sizeof(char));
    char *a4 = (char *)malloc((len4 + 1) * sizeof(char));

    for (int i = 0; i < len1; i++) {
        a1[i] = c1[i][0];
    }
    a1[len1] = '\0';

    for (int i = 0; i < len2; i++) {
        a2[i] = c2[i][0];
    }
    a2[len2] = '\0';

    for (int i = 0; i < len3; i++) {
        a3[i] = c3[i][0];
    }
    a3[len3] = '\0';

    for (int i = 0; i < len4; i++) {
        a4[i] = c4[i][0];
    }
    a4[len4] = '\0';

    // Call the compress function
    // int r1 = compress(a1, len1); 
    // int r2 = compress(a2, len2); 
    // int r3 = compress(a3, len3); 
    int r4 = compress(a4, len4); 

    // Print the results
    // printf("test 1: return -- %d \n", r1); 
    // printf("new string %s \n", a1); 
    // printf(" \n"); 

    // printf("test 2: return -- %d \n", r2); 
    // printf("new string %s \n", a2); 
    // printf(" \n"); 

    // printf("test 3: return -- %d \n", r3); 
    // printf("new string %s \n", a3); 
    // printf(" \n"); 

    printf("test 4: return -- %d \n", r4); 
    printf("new string %s \n", a4); 
    printf(" \n"); 

    // Free the allocated memory
    free(a1);
    free(a2);
    free(a3);
    free(a4);

    return 0;
}