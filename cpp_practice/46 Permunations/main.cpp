// https://leetcode.com/problems/permutations/description/

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

class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp) {
        if ((int)tmp.size() == (int) nums.size()) {
            ans.push_back(tmp); 
            return; 
        }
        for (auto x : nums) {
            if (find(tmp.begin(), tmp.end(), x) == tmp.end()) {
                tmp.push_back(x); 
                backtrack(nums, ans, tmp); 
                tmp.pop_back(); 
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans; 
        vector<int> tmp; 
        backtrack(nums, ans, tmp); 
        return ans; 
    }
};

int main(int argc, char const *argv[])
{



    return 0;
}
