#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

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

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

int firstBadVersion(int n) {
    int left = 1; 
    int right = n; 

    int mid; 
    int ans = 0; 
    while (left <= right) {
        mid = left + (right - left) / 2; 

        if (isBadVersion(mid)) {
            ans = mid; 
            right = mid-1; 
        } else {
            left = mid+1; 
        }
    }

    return ans; 
}

int main(int argc, char const *argv[])
{

    return 0;
}
