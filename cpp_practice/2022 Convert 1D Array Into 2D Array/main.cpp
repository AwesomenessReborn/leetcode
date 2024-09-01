// https://leetcode.com/problems/convert-1d-array-into-2d-array/?envType=daily-question&envId=2024-09-01

#include <map>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <array>
#include <vector>
#include <ios>

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

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != (m*n)) return {}; 

        int idx = 0; 
        vector<vector<int>> ans(m, vector<int>(n)); 
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = original[idx++]; 
            }
        }
        return ans; 
    }
};

int main(int argc, char const *argv[])
{
    Solution sol; 
    
    vector<int> n1 = {1,2}; 
    vector<vector<int>> ans = sol.construct2DArray(n1, 1, 1); 

    cout << "yeyeyeye" << endl; 

    return 0;
}
