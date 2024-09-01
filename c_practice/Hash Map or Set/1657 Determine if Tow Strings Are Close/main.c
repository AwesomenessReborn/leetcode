
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

struct freq_ent
{
    int freq; // key 
    int freq_f; 
    UT_hash_handle hh; 
};

// keep track of two things: 
// 1. create char hash; 
// 2. create freq hash; 
bool closeStrings(char* word1, char* word2) {
    int size1 = strlen(word1);
    int size2 = strlen(word2);
    if (size1 != size2) return false;

    int* h1 = calloc(26, sizeof(int));
    int* h2 = calloc(26, sizeof(int));
    struct freq_ent *f1 = NULL;
    struct freq_ent *f2 = NULL;

    for (int i = size1 - 1; i >= 0; i--) {
        h1[word1[i] - 'a']++;
    }
    for (int i = size2 - 1; i >= 0; i--) {
        h2[word2[i] - 'a']++;
    }

    bool total = true;

    for (size_t i = 0; i < 26; i++) {
        if ((h1[i] > 0 && h2[i] == 0) || (h1[i] == 0 && h2[i] > 0)) {
            total = false;
        }

        if (h1[i] > 0) {
            struct freq_ent *s;
            HASH_FIND_INT(f1, &h1[i], s);
            if (s == NULL) {
                s = (struct freq_ent *)malloc(sizeof(*s));
                s->freq = h1[i];
                s->freq_f = 1;
                HASH_ADD_INT(f1, freq, s);
            } else {
                s->freq_f++;
            }
        }

        if (h2[i] > 0) {
            struct freq_ent *s;
            HASH_FIND_INT(f2, &h2[i], s);
            if (s == NULL) {
                s = (struct freq_ent *)malloc(sizeof(*s));
                s->freq = h2[i];
                s->freq_f = 1;
                HASH_ADD_INT(f2, freq, s);
            } else {
                s->freq_f++;
            }
        }
    }

    if (!total) {
        HASH_CLEAR(hh, f1);
        HASH_CLEAR(hh, f2);
        free(h1);
        free(h2);
        return false;
    }

    struct freq_ent *s1, *s2;
    for (s1 = f1; s1 != NULL; s1 = s1->hh.next) {
        HASH_FIND_INT(f2, &s1->freq, s2);
        if (s2 == NULL || s1->freq_f != s2->freq_f) {
            HASH_CLEAR(hh, f1);
            HASH_CLEAR(hh, f2);
            free(h1);
            free(h2);
            return false;
        }
    }

    HASH_CLEAR(hh, f1);
    HASH_CLEAR(hh, f2);
    free(h1);
    free(h2);
    return true;
}
int main(int argc, char const *argv[])
{
    char *s1 = "abc"; 
    char *t1 = "bac"; 

    char *s2 = "a"; 
    char *t2 = "aa"; 

    char *s3 = "cabbba"; 
    char *t3 = "abbccc"; 

    char *s4 = "abbbzcf"; 
    char *t4 = "babzzcz"; 

    printf("test 1: \n"); 
    printf("result: \t %s \n", closeStrings(s1, t1) ? "true" : "false"); 
    printf("expcted: \t true \n"); 

    printf("test 2: \n"); 
    printf("result: \t %s \n", closeStrings(s2, t2) ? "true" : "false"); 
    printf("expcted: \t false \n"); 

    printf("test 3: \n"); 
    printf("result: \t %s \n", closeStrings(s3, t3) ? "true" : "false"); 
    printf("expcted: \t true \n"); 

    printf("test 4: \n"); 
    printf("result: \t %s \n", closeStrings(s4, t4) ? "true" : "false"); 
    printf("expcted: \t false \n"); 

    return 0;
}
