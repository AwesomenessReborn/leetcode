
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {
    int* ans = malloc((numsSize - k + 1) * sizeof(int));
    int* deq = malloc(numsSize * sizeof(int));
    int dbegin = 0, dend = 0;
    int aidx = 0;

    for (int cidx = 0; cidx < numsSize; cidx++) {

        // if current value is larger than the values already in deq --> negate all other values after the current deq value, by decrementing dend pointer. 
        while (dend > dbegin && nums[deq[dend - 1]] <= nums[cidx]) {
            dend--;
        }

        // increment dend, since we are always adding a value in our deq. 
        deq[dend++] = cidx;

        // if the indexes that we store in the deq are too far away -- i.e. outside our sliding window -- we must remove them, just increment dbegin. 
        if (deq[dbegin] <= cidx - k) {
            dbegin++;
        }

        // finally we just save the first element in our deque as the maximum in our answer -- since we manage our deq to be descending order. 
        if (cidx >= k - 1) {
            ans[aidx++] = nums[deq[dbegin]];
        }
    }

    *returnSize = aidx;
    free(deq); 
    return ans;
}

// /**
//  * Note: The returned array must be malloced, assume caller calls free().
//  */
// int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

//     int* ans = malloc((numsSize-k+1)*sizeof(int)); 
//     int cidx=0; // pointer to index in nums. 
//     int aidx=0; // pointer to index in ans. 

//     int* deq = malloc((numsSize)*sizeof(int));
//     int dbegin=0, dend=0, dcurr=0;  // pointers to deq. 

//     // ! at this point, get a habit of using for loops: 

//     /**
//      * for (int cidx=0; i < numsSize; i++) {}
//      */

//     while (cidx < numsSize) { // to look at each and every single value in the input. 

//         // if here, that means that we are looking at indexes where insertion into *ans* happens. 

//         // deq insertion model: 
//         for (int i = dbegin; i < dend; i++) {
//             if (nums[deq[i]] > nums[cidx]) {
//                 // lesser --> we insert the value after the last number the current value is less than. 
//                 // we go next index --> to find the next smaller number. 
//                 // so do nothing? 

//             } else {
//                 // larger --> we remove and replace all other values after the last mentioned value. 
//                 // we found target location, remove all other values after this: 
//                 dend = i;  // to artificially delete all next values: 
//                 deq[i] = cidx;  // save the new number's index in the target location of our deq. 

//             }
//         }

//         // --> remove all deq values that are too far from current. HAPPENS ONLY TO FIRST INDEX, since we are adding one value at a time. 
//         if (deq[dbegin] - cidx >= k) dbegin++;  // adding 1 to dbegin should automatically remove the previous largest value. 

//         // we end up simply inserting the first value of deq into the ans: 
//         if (cidx >= k-1) {
//             ans[aidx++] = deq[dbegin]; 
//         }

//         cidx++; 
//     }

//     *returnSize = aidx; 
//     return ans; 
    
// }

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

int main(int argc, char const *argv[]) {
    int num1[8] = {1, 3, -1, -3, 5, 3, 6, 7};
    int num2[1] = {1};

    int k1 = 3; 
    int k2 = 1; 

    int ret1, ret2; 

    int* res1 = maxSlidingWindow(num1, 8, k1, &ret1); 
    int* res2 = maxSlidingWindow(num2, 1, k2, &ret2); 

    printf("Resulting array for num1 with k = %d: \n", k1);
    printf("expected: [3,3,5,5,6,7] \nreceived: "); 
    printArray(res1, ret1);
    printf("\n"); 

    printf("Resulting array for num2 with k = %d: \n", k2);
    printf("expected: [1] \nreceived: "); 
    printArray(res2, ret2);
    printf("\n"); 


    free(res1);
    free(res2);

    return 0;
}