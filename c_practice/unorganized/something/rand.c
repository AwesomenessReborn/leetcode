
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * ( : 40 
) : 41 
[ : 91 
] : 93 
{ : 123 
} : 125 
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
{
    
}

struct ListNode {
    int value; 
    struct node* next; 
}; 

// struct node {
//     int value; 
//     struct node* next; 
// }; 
// typedef struct node node_t; 

int main(int argc, char const *argv[])
{
    /* code */
    // ListNode A1, A2, B1, B2, B3, AB1, AB2, AB3; 

    // A1.value = 4; 
    // A2.value = 1; 

    // AB1.value = 8; 
    // AB2.value = 4; 
    // AB3.value = 5; 

    // B1.value = 5; 
    // B2.value = 6; 
    // B3.value = 1; 

    // A1.next = &A2; 
    // A2.next = &AB1; 
    // AB1.next = &AB2; 
    // AB2.next = &AB3; 

    // B1.next = &B2; 
    // B2.next = &B3; 
    // B3.next = &AB1;  

    // ListNode* ans = getIntersectionNode(A1, A2); 

    int* ans = malloc(sizeof(int)); 
    ans[0] = 1; 

    printf("%d\n\n", ans[0]); 

    free(ans); 

    printf("%d\n", ans[0]); 

    return 0;
}
