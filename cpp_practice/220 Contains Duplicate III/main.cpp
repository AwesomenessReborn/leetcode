// https://leetcode.com/problems/contains-duplicate-iii/description/

#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
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

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        std::set<int> window; 

        for (int i = 0; i < nums.size(); i++) {
            if (i > indexDiff) {
                window.erase(nums[i-indexDiff-1]); 
            }

            std::set<int>::iterator pos = window.lower_bound(nums[i] - valueDiff); 
            if (pos != window.end() && *pos <= nums[i] + valueDiff) {
                return true; 
            }

            window.insert(nums[i]); 
        }

        return false; 
    }
};

int main(int argc, char const *argv[])
{
    
    vector<int> n1 = {1,2,3,1}; 
    vector<int> n2 = {1,5,9,1,5,9}; 

    int i1=3, i2=2; 
    int v1=0, v2=3; 

    Solution sol; 

    cout << sol.containsNearbyAlmostDuplicate(n1, i1, v1) << endl; 
    cout << sol.containsNearbyAlmostDuplicate(n2, i2, v2) << endl; 

    return 0;
}
