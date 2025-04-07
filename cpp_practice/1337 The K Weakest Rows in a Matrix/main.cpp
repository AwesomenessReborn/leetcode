// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/description/

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
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<std::pair<int, int>> mat_rec; // row number --> count of soldiers. 
        for (int i = 0; i < mat.size(); i++) {
            int cnt = 0; 
            while (cnt < mat[i].size() && mat[i][cnt] == 1) cnt++; 
            mat_rec.push_back(std::make_pair(i, cnt)); 
        }

        std::sort(mat_rec.begin(), mat_rec.end(), 
            [](const std::pair<int, int>&a, const std::pair<int, int>&b) {
                if (a.second == b.second) return a.first < b.first; 
                return a.second < b.second; 
            }
        ); 
        
        vector<int> ans; 
        for (int i = 0; i < k; i++) {
            ans.push_back(mat_rec[i].first); 
        }

        return ans; 
    }
};

int main(int argc, char const *argv[])
{




    return 0;
}
