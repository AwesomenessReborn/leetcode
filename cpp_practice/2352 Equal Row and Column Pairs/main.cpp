// https://leetcode.com/problems/equal-row-and-column-pairs/?envType=study-plan-v2&envId=leetcode-75

#include <bitset>
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

/**
 * 
 */
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int cnt=0; 
        int c = grid.size(); 

        std::map<std::vector<int>, int> pairs; 

        for (int i = 0; i < c; i++) {
            pairs[grid[i]]++; 
        }

        for (int i = 0; i < c; i++) {
            vector<int> tmp; 
            for (int j = 0; j < grid.size(); j++) {
                tmp.push_back(grid[j][i]); 
            }
            if (pairs.count(tmp)) {
                cnt+=pairs[tmp]; 
            } 
        }

        return cnt; 
    }
};

int main(int argc, char const *argv[])
{

    Solution sol; 

    vector<vector<int>> n1 = {
        {3, 1, 2, 2},
        {1, 4, 4, 5},
        {2, 4, 2, 2},
        {2, 4, 2, 2}
    }; 
    cout << "------------ " << endl; 

    cout << sol.equalPairs(n1) << endl; 

    return 0;
}
