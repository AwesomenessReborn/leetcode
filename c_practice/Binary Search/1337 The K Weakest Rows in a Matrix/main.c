// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize) {
    

    *returnSize = k; 
    int* ans = malloc(k*sizeof(int)); 
    

    return ans; 
}

int main(int argc, char const *argv[])
{
    int mat1[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 0},
        {1, 0, 0, 0}
    };
    int mat2[5][5] = {
        {1,1,0,0,0}, 
        {1,1,1,1,0}, 
        {1,0,0,0,0}, 
        {1,1,0,0,0}, 
        {1,1,1,1,1} 
    }; 


    return 0;
}
