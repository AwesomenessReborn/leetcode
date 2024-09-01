// https://leetcode.com/problems/longest-consecutive-sequence/description/

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
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; 

        set<int> store(nums.begin(), nums.end()); 

        int longest=1; 
        auto prev = store.begin(); 
        int streak=1; 
        for (auto it = next(store.begin()); it != store.end(); ++it) {
            if (*prev + 1 == *it) {
                streak++; 
            } else {
                longest = max(longest, streak); 
                streak = 1; 
            }

            prev = it; 
        }
        longest = max(longest, streak); 

        return longest; 
    }
};

int main(int argc, char const *argv[])
{
    vector<int> n1 = {100,4,200,1,3,2}; 
    vector<int> n2 = {0,3,7,2,5,8,4,6,0,1}; 

    Solution sol; 

    cout << sol.longestConsecutive(n1) << endl; 
    cout << "actual: 4" << endl; 

    cout << sol.longestConsecutive(n2) << endl; 
    cout << "actual: 9" << endl; 

    return 0;
}
