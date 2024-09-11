// https://leetcode.com/problems/single-element-in-a-sorted-array/description/?envType=problem-list-v2&envId=eppgvb8s

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <iterator> 
#include <vector>
#include <ios>
#include <limits>
#include <sstream> 
#include <string> 

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         int left = 0; 
//         int right = nums.size()-1; 

//         while (left <= right) {
//             int mid = (left + right) / 2; 

//             if (nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]) {
//                 return nums[mid]; 
//             }

//             if (nums[mid] == nums[mid-1]) {
//                 right = mid+1; 
//                 continue;
//             } else {
//                 left = mid; 
//             }
//         }
//         return -1; 
//     }

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;                           // setup @ first
        int right = nums.size() - 1;            // setup @ last

        while (left < right) {
            int mid = left + (right - left) / 2;  // always middle element

            if (mid % 2 == 1) {
                mid--; 
            }

            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;             // ! adjust according to ignoring middle element
            } else {
                right = mid;
            }
        }
        
        return nums[left];  
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
