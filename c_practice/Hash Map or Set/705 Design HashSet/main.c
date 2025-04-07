
struct element {
    int val;
    struct element* next;
};

typedef struct {
    struct element* data[1000]; 
} MyHashSet;

MyHashSet* myHashSetCreate() {
    MyHashSet* set = (MyHashSet*)malloc(sizeof(MyHashSet));
    for (int i = 0; i < 1000; i++) {
        set->data[i] = NULL;
    }
    return set;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    int index = key % 1000;  
    struct element* ptr = obj->data[index]; 
    while (ptr != NULL) {
        if (ptr->val == key) return; 
        ptr = ptr->next; 
    }

    struct element* newElement = (struct element*)malloc(sizeof(struct element)); 

    // ptr = (struct element*)malloc(sizeof(struct element)); 
    // ptr->val = key; 
    // ptr->next = NULL; 

    newElement->val = key; 
    newElement->next = obj->data[index]; 
    obj->data[index] = newElement;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    int index = key % 1000; 
    struct element* cur = obj->data[index]; 
    struct element* prev = NULL;  

    while (cur != NULL) {
        if (cur->val == key) {
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

bool myHashSetContains(MyHashSet* obj, int key) {
    int index = key % 1000;  
    struct element* pot = obj->data[index]; 
    while (pot != NULL) {
        if (pot->val == key) return true;
        pot = pot->next; 
    }
    return false; 
}

void myHashSetFree(MyHashSet* obj) {
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
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/
int main(int argc, char const *argv[])
{
    MyHashSet* obj = myHashSetCreate();
    myHashSetAdd(obj, key);
    
    myHashSetRemove(obj, key);
    
    bool param_3 = myHashSetContains(obj, key);
    
    myHashSetFree(obj);

    return 0;
}
