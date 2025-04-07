// https://leetcode.com/problems/remove-duplicates-from-sorted-array/solutions/5479159/c-solution/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) return 0; 

    int idx = 1; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[idx-1]) {
            nums[idx++] = nums[i]; 
        }
    }
    return idx; 
}

// TODO write tests. 
int main(int argc, char const *argv[])
{

    return 0;
}
