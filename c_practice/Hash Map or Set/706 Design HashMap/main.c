
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct element {
    int key;
    int value; 
    struct element* next;
};

typedef struct {
    struct element* data[1000]; 
} MyHashMap;


MyHashMap* myHashMapCreate() {
    MyHashMap* set = (MyHashMap*)malloc(sizeof(MyHashMap));
    for (int i = 0; i < 1000; i++) {
        set->data[i] = NULL;
    }
    return set;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    int index = key % 1000;  
    struct element* ptr = obj->data[index]; 
    while (ptr != NULL) {
        if (ptr->key == key) {
            ptr->value = value; 
            return; 
        }
        ptr = ptr->next; 
    }

    struct element* newElement = (struct element*)malloc(sizeof(struct element)); 

    newElement->key = key; 
    newElement->value = value; 
    newElement->next = obj->data[index]; 
    obj->data[index] = newElement;
}

int myHashMapGet(MyHashMap* obj, int key) {
    int index = key % 1000; 
    struct element* target = obj->data[index]; 
    while (target != NULL) {
        if (target->key == key) {
            return target->value; 
        }
        target = target->next; 
    }
    return -1; 
}

void myHashMapRemove(MyHashMap* obj, int key) {
    int index = key % 1000; 
    struct element* cur = obj->data[index]; 
    struct element* prev = NULL;  

    while (cur != NULL) {
        if (cur->key == key) {
            if (prev == NULL) {
                obj->data[index] = cur->next; 
            } else {
                prev->next = cur->next; 
            }
            free(cur); 
            return; 
        }
        prev = cur; 
        cur = cur->next; 
    }
}

void myHashMapFree(MyHashMap* obj) {
    for (int i = 0; i < 1000; i++) {
        struct element* cur = obj->data[i]; 
        while (cur != NULL) {
            struct element* tmp = cur; 
            cur = cur->next; 
            free(tmp); 
        }
    }
    free(obj); 
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 
 * int param_2 = myHashMapGet(obj, key);
 
 * myHashMapRemove(obj, key);
 
 * myHashMapFree(obj);
*/


int main(int argc, char const *argv[])
{
    MyHashMap* obj = myHashMapCreate();
    myHashMapPut(obj, 1, 1);
    myHashMapPut(obj, 2, 2);
    
    printf("first get: %d \n", myHashMapGet(obj, 1)); 
    printf("expected: 1\n"); 
    printf("second get: %d \n", myHashMapGet(obj, 3)); 
    printf("expected: -1\n"); 
    
    myHashMapPut(obj, 2, 1);
    
    printf("third get: %d \n", myHashMapGet(obj, 2)); 
    printf("expected: 1\n"); 

    myHashMapRemove(obj, 2);
    
    printf("fourth get: %d \n", myHashMapGet(obj, 2)); 
    printf("expected: -1\n"); 
    
    myHashMapFree(obj);
    return 0;
}
