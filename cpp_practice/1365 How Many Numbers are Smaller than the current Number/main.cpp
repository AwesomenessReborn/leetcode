// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/

#include <map>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

static auto _ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

template <typename T>
void printArray(std::vector<T> values)
{
    std::cout << "[";
    for (int i = 0; i < values.size(); i++)
    {
        std::cout << values[i];
        if (values.size() - 1 > i)
        {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}


// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         vector<int> sorted = nums;
//         sort(sorted.begin(), sorted.end());
        
//         unordered_map<int, int> countMap;
//         for (int i = 0; i < sorted.size(); i++) {
//             // Only store the first occurrence index of each number
//             if (countMap.find(sorted[i]) == countMap.end()) {
//                 countMap[sorted[i]] = i;
//             }
//         }
        
//         vector<int> result;
//         for (int num : nums) {
//             result.push_back(countMap[num]);
//         }
        
//         return result;
//     }
// };

// alternative approach -- due to input limitations: 

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        std::array<int, 101> counter = {0}; 

        for (int value : nums) {
            counter[value]++; 
        }
        for (int i = 1; i < 101; i++) {
            counter[i] = counter[i] + counter[i-1]; 
        }
        vector<int> result(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                result[i] = 0; 
            } else {
                result[i] = counter[nums[i] - 1]; 
            }
        }

        return result; 
    }
};


int main(int argc, char const *argv[])
{
    vector<int> n1 = {8,1,2,2,3}; 
    vector<int> n2 = {6,5,4,8}; 
    vector<int> n3 = {7,7,7,7}; 

    Solution sol; 

    printArray(sol.smallerNumbersThanCurrent(n1)); 
    printArray(sol.smallerNumbersThanCurrent(n2)); 
    printArray(sol.smallerNumbersThanCurrent(n3)); 

    return 0;
}
