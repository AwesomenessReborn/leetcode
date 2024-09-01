// https://leetcode.com/problems/summary-ranges/description/

#include <map>
#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <ios>
#include <map>
#include <unordered_map>

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

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans; 
        if (nums.size() == 0) return ans; 
        if (nums.size() == 1) {
            ans.push_back(std::to_string(nums[0])); 
            return ans; 
        }

        int start = 0;
        for (int i = 1; i <= nums.size(); ++i) {
            if (i == nums.size() || nums[i] != nums[i - 1] + 1) {
                if (i - 1 == start) {
                    ans.push_back(std::to_string(nums[start]));
                } else {
                    ans.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[i - 1]));
                }
                start = i;
            }
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {0,1,2,4,5,7}; 
    vector<int> n2 = {0,2,3,4,6,8,9}; 
    Solution sol; 

    cout << "test 1: " << endl;  
    printArray(sol.summaryRanges(n1)); 
    cout << endl; 

    cout << "test 2: " << endl;  
    printArray(sol.summaryRanges(n2)); 
    cout << endl; 

    return 0;
}
