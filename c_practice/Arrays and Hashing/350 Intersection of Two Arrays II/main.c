
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "uthash.h"

void printArray(int* arr, int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

struct hash_entry {
    int value; 
    int freq; 
    UT_hash_handle hh; 
}; 

/**
 * Note: The returned array must be malloced, assume caller calls free().
 * this solution is also 0 <= nums1[i], nums2[i] <= 1000
 * we don't need to use a dynamic hash ds. 
 * */
// int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//     struct hash_entry *n1hash = NULL, *n2hash = NULL;

//     for (int i = 0; i < nums1Size; i++) {
//         struct hash_entry *pot;
//         HASH_FIND_INT(n1hash, &nums1[i], pot);
//         if (pot != NULL) {
//             pot->freq++;
//         } else {
//             pot = (struct hash_entry *)malloc(sizeof *pot);
//             pot->value = nums1[i];
//             pot->freq = 1;
//             HASH_ADD_INT(n1hash, value, pot);
//         }
//     }

//     for (int i = 0; i < nums2Size; i++) {
//         struct hash_entry *pot;
//         HASH_FIND_INT(n2hash, &nums2[i], pot);
//         if (pot != NULL) {
//             pot->freq++;
//         } else {
//             pot = (struct hash_entry *)malloc(sizeof *pot);
//             pot->value = nums2[i];
//             pot->freq = 1;
//             HASH_ADD_INT(n2hash, value, pot);
//         }
//     }

//     struct hash_entry *s;
//     bool usingn1;
//     if (nums1Size > nums2Size) {
//         s = n2hash;
//         usingn1 = false;
//     } else {
//         s = n1hash;
//         usingn1 = true;
//     }

//     int cnt = 0;
//     struct hash_entry *match;
//     for (struct hash_entry *iter = s; iter != NULL; iter = iter->hh.next) {
//         HASH_FIND_INT(usingn1 ? n2hash : n1hash, &iter->value, match);
//         if (match != NULL) {
//             cnt += (iter->freq < match->freq) ? iter->freq : match->freq;
//         }
//     }

//     int* ans = (int*)malloc(cnt * sizeof(int));
//     int m = 0;
//     for (struct hash_entry *iter = s; iter != NULL; iter = iter->hh.next) {
//         HASH_FIND_INT(usingn1 ? n2hash : n1hash, &iter->value, match);
//         if (match != NULL) {
//             int min_freq = (iter->freq < match->freq) ? iter->freq : match->freq;
//             for (int i = 0; i < min_freq; i++) {
//                 ans[m++] = iter->value;
//             }
//         }
//     }
//     *returnSize = cnt;

//     struct hash_entry *tmp;
//     HASH_ITER(hh, n1hash, s, tmp) {
//         HASH_DEL(n1hash, s);
//         free(s);
//     }
//     HASH_ITER(hh, n2hash, s, tmp) {
//         HASH_DEL(n2hash, s);
//         free(s);
//     }

//     return ans;
// }

static inline int min(int a, int b) {
    return (a < b) ? a : b;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool n1s = nums1Size < nums2Size ? true : false;

    int* n1hash[1001] = {0}; 
    int* n2hash[1001] = {0}; 
    for (int i = 0; i < nums1Size; i++) {
        n1hash[nums1[i]]++; 
    }
    for (int i = 0; i < nums2Size; i++) {
        n2hash[nums2[i]]++; 
    }

    int cnt = 0; 
    for (int i = 0; i < 1002; i++) {
        cnt+=min(n1hash[i], n2hash[i]); 
    }
    int* ans = malloc(cnt*sizeof(int)); 
    int t=0; 
    for (int i = 0; i < 1002; i++) {
        for (int j=min(n1hash[i], n2hash[i]); i >= 0; i--) {
            ans[t++]
        }
    }

    *returnSize = cnt; 
    return ans; 
}

/**
 * 
    if (n1s) {
        for (int i = 0; i < nums1Size; i++) {
            if (n2hash[nums1[i]] > 0) cnt++; 
        }
        ans = malloc(cnt*sizeof(int)); 
        for (int i = 0; i < nums1Size; i++) {

        }    
    } else {
        for (int i = 0; i < nums2Size; i++)
    }

 */


int main(int argc, char const *argv[])
{
    int num1a[4] = {1,2,2,1};
    int num2a[2] = {2,2};

    int num1b[3] = {4,9,5};
    int num2b[5] = {9,4,9,8,4};

    int r1, r2; 

    int* a1 = intersect(num1a, 4, num2a, 2, &r1); 
    int* a2 = intersect(num1b, 3, num2b, 5, &r2); 

    printf("test1: \n"); 
    printf("result: "); 
    printArray(a1, r1); 
    printf("expected: [2, 2] \n\n"); 

    printf("test2: \n"); 
    printf("result: "); 
    printArray(a2, r2); 
    printf("expected: [9, 4] \n\n"); 

    free(a1); 
    free(a2); 

    return 0;
}
