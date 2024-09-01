// https://leetcode.com/problems/palindrome-linked-list/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct ListNode {
    int value; 
    struct ListNode* next; 
}; 

struct ListNode* reverseLinkedList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = head;
    struct ListNode* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return true; 

    struct ListNode* front = head; 
    int len1=0; 

    while (front != NULL) {
        front = front->next;
        len1++; 
    }

    struct ListNode* f2 = head;  // should be start of second list. 
    struct ListNode* follow = NULL; 
    for (int i = 0; i < len1 / 2; i++) {
        follow = f2; 
        f2 = f2->next; 
    }
    follow->next = NULL;        // to unlink both lists. 
    struct ListNode* back = reverseLinkedList(f2); 

    front = head; 

    while (front != NULL && back != NULL) {
        if (front->value != back->value) return false; 

        front = front->next; 
        back = back->next; 
    }
    
    return true; 
}

int main(int argc, char const *argv[])
{
    struct ListNode A1, A2, A3, A4, B1, B2; 

    A1.value = 1; 
    A2.value = 2; 
    A3.value = 2; 
    A4.value = 1; 

    B1.value = 1; 
    B2.value = 2; 

    A1.next = &A2; 
    A2.next = &A3; 
    A3.next = &A4; 
    A4.next = NULL; 

    B1.next = &B2; 
    B2.next = NULL; 

    printf("test 1: %s \n", isPalindrome(&A1) ? "true" : "false"); 
    printf("expected: true \n\n"); 

    printf("test 2: %s \n", isPalindrome(&A1) ? "true" : "false"); 
    printf("expected: false \n\n");

    return 0;
}
