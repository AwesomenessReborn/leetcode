// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

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

struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (!head) return head; 

    struct ListNode* cur = head->next; 
    struct ListNode* prev = head; 

    while (cur) {
        if (prev->val == cur->val) {
            prev->next = cur->next; 
            cur = cur->next; 
            continue; // don't change prev .
        }
        prev = prev->next; 
        cur = cur->next; 
    }

    return head; 
}

int main(int argc, char const *argv[])
{


    return 0;
}
