
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    int value; 
    struct ListNode* next; 
}; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
// struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) 
// {
//     struct ListNode* m1 = headA; 
//     struct ListNode* m2 = headB; 

//     int len1 = 0, len2 = 0; 

//     while (m1 != NULL) {
//         m1 = m1->next;
//         len1++; 
//     }

//     while (m2 != NULL) {
//         m2 = m2->next;
//         len2++; 
//     }

//     // adjust heads to same distance from end. 
//     if (len1 > len2) {
//         for (int i = 0; i < len1 - len2; i++) {
//             headA = headA->next; 
//         }
//     } else if (len2 > len1) {
//         for (int i = 0; i < len2 - len1; i++) {
//             headB = headB->next; 
//         }
//     }

//     while (headA != NULL && headB != NULL) {
//         if (headA == headB) {
//             return headA; 
//         }
//     }
//     return NULL; 
// }

struct ListNode* getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode* m1 = headA; 
    struct ListNode* m2 = headB; 

    int len1 = 0, len2 = 0; 

    // Calculate the length of the first list
    while (m1 != NULL) {
        m1 = m1->next;
        len1++; 
    }

    // Calculate the length of the second list
    while (m2 != NULL) {
        m2 = m2->next;
        len2++; 
    }

    // Reset m1 and m2 to the heads of the lists
    m1 = headA;
    m2 = headB;

    // Adjust heads to same distance from the end
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) {
            m1 = m1->next; 
        }
    } else if (len2 > len1) {
        for (int i = 0; i < len2 - len1; i++) {
            m2 = m2->next; 
        }
    }

    // Traverse both lists and find the intersection
    while (m1 != NULL && m2 != NULL) {
        if (m1 == m2) {
            return m1; 
        }
        m1 = m1->next;
        m2 = m2->next;
    }

    return NULL; 
}




// struct node {
//     int value; 
//     struct node* next; 
// }; 
// typedef struct node node_t; 

int main(int argc, char const *argv[])
{
    /* code */
    struct ListNode A1, A2, B1, B2, B3, AB1, AB2, AB3; 

    A1.value = 4; 
    A2.value = 1; 

    AB1.value = 8; 
    AB2.value = 4; 
    AB3.value = 5; 

    B1.value = 5; 
    B2.value = 6; 
    B3.value = 1; 

    A1.next = &A2; 
    A2.next = &AB1; 

    AB1.next = &AB2; 
    AB2.next = &AB3; 
    AB3.next = NULL; 

    B1.next = &B2; 
    B2.next = &B3; 
    B3.next = &AB1;  

    struct ListNode* ans = getIntersectionNode(&A1, &B1); 

    if (ans != NULL) {
        printf("Intersection at node with value: %d\n", ans->value);
    } else {
        printf("No intersection\n");
    }

    return 0;
}
