
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

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

/**
 * fancy -- made to only select the leftmost element. 
 * https://en.wikipedia.org/wiki/Binary_search#:~:text=The%20procedure%20may%20return%20any%20index%20whose%20element,if%20there%20are%20duplicate%20elements%20in%20the%20array.
 */
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            left = mid + 1; 
        } else {
            right = mid; 
        }
    }

    return arr[left] == target ? left : -1; // Target not found
}

int main(int argc, char const *argv[])
{
    int arr[] = {2, 4, 10, 10, 10, 12, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, size, sizeof(int), compare); 
    int target = 12;

    int result = binarySearch(arr, size, target);

    printArray(arr, size); 
    printf("target index: %d \n\n", result); 

    return 0;
}
