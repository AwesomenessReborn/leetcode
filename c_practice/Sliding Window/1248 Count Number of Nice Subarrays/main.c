
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int numberOfSubarrays(int* nums, int numsSize, int k){
    int o_cnt=0, m=0; 
    int ws=0, we=0; 
    int cnt=0; 

    while (we < numsSize) {
        if (nums[we] % 2 == 1) o_cnt++; 

        while (o_cnt > k) {
            if (nums[ws] % 2 == 1) {
                o_cnt--; 
            }
            ws++; 
            m=ws; 
        }
        if (o_cnt == k) {
            while (nums[m] % 2 == 0) {
                m++; 
            }
            cnt += (m-ws) + 1; 
        }
        we++; 
    }

    return cnt; 
}

int main(int argc, char const *argv[])
{
    int num1[5] = {1,1,2,1,1};
    int num2[3] = {2,4,6};
    int num3[10] = {2,2,2,1,2,2,1,2,2,2};

    int k1=3; 
    int k2=1; 
    int k3=2; 

    printf("test1: %d \n", numberOfSubarrays(num1, 5, k1)); 
    printf("expected 2 \n"); 
    printf("\n"); 

    printf("test2: %d \n", numberOfSubarrays(num2, 3, k2)); 
    printf("expected 0 \n"); 
    printf("\n"); 

    printf("test3: %d \n", numberOfSubarrays(num3, 10, k3)); 
    printf("expected 16 \n"); 
    printf("\n"); 

    return 0;
}