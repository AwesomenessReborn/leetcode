
#include <iostream>
#include <array>
#include <vector>
#include <set>

using namespace std; 

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans; 
        ans.reserve(nums.size()); 
        for (int i = 0; i < nums.size(); i++) {
            ans.push_back(nums[nums[i]]); 
        }
        return ans; 
    }
};

template <typename T>
void printArray(std::vector<T> values) {
    std::cout << "["; 
    for (int i = 0; i < values.size(); i++) {
        std::cout << values[i]; 
        if (values.size() - 1 > i) {
            std::cout << ", "; 
        }
    }
    std::cout << "]" << std::endl; 
}

int main(int argc, char const *argv[])
{
    Solution sol; 

    vector<int> nums1 = {0,2,1,5,3,4}; 
    vector<int> nums2 = {5,0,1,2,3,4}; 

        // int prev=nums[idx]-1; 
        // while (idx < nums.size()) {
        //     if (nums[idx] == prev+1) {
        //         idx++; 
                
        //     } else {
        //         // range is done: 

        //     }
        //     prev = nums[idx++]; 
        // }
    cout << "TEST1: before" << endl; 
    printArray(nums1); 
    cout << "after" << endl; 
    printArray(sol.buildArray(nums1)); 
    cout << "\n"; 

    cout << "TEST2: before" << endl; 
    printArray(nums2); 
    cout << "after" << endl; 
    printArray(sol.buildArray(nums2)); 
    cout << "\n"; 
    
    return 0;
}
