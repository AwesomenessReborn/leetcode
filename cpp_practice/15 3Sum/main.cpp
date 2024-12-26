// https://leetcode.com/problems/3sum/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>

using namespace std; 

static auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

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

template <typename T>
void printDoubleArray(std::vector<std::vector<T>> values) {
    cout << "[\n"; 
    for (int i = 0; i < values.size(); i++) {
        cout << "\t"; 
        printArray(values[i]); 
        if (i != values.size()-1) cout << ", "
    }
    cout << "]"
}


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans; 
        std::sort(nums.begin(), nums.end()); 

        int pot, l_val, r_val, left, right, n = nums.size(); 
        for (int i = 0; i < n-2; i++) {
            if (nums[i] > 0) break; 
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            left = i+1; 
            right = n-1; 
            pot = nums[i]; 

            while (left < right) {
                l_val = nums[left]; 
                r_val = nums[right]; 
                
                if (0 == l_val + r_val + pot) {
                    ans.push_back({pot, l_val, r_val}); 
                    while (left < right && nums[right] == r_val) right--; 
                    while (left < right && nums[left] == l_val) left++; 
                } else if (l_val + r_val + pot > 0) {
                    while (left < right && nums[right] == r_val) right--; 
                } else {
                    while (left < right && nums[left] == l_val) left++; 
                }
            }
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {-1,0,1,2,-1,-4}; 
    vector<int> n2 = {0,1,1}; 
    vector<int> n3 = {0,0,0}; 

    Solution s; 

    printDoubleArray(s.threeSum(n1)); 
    printDoubleArray(s.threeSum(n2)); 
    printDoubleArray(s.threeSum(n3)); 

    return 0;
}
